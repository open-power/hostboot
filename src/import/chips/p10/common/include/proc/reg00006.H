/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00006.H $         */
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

#ifndef __PROC_REG00006_H_
#define __PROC_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_PTLSCOM45_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PR0123_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PR0123_ERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM45_PR0123_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PR0123_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PR0123_ERR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PR0123_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR]

//>> PUT_[PB_PTLSCOM45_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PR0123_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PR0123_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM45_PR0123_ERR]


//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> PREP_[PB_PTLSCOM45_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM45_PTL_FIR_REG_RW]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_RW]

//>> PUT_[PB_PTLSCOM45_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM45_PTL_FIR_REG_RW]

//>> PREP_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]

//>> PUT_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]

//>> PREP_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]

//>> PUT_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]


//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> PREP_[TP_TPBR_AD_ALTD_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_ALTD_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_ALTD_DATA_REG]

//>> GET_[TP_TPBR_AD_ALTD_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_ALTD_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_ALTD_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_DATA_REG]

//>> PUT_[TP_TPBR_AD_ALTD_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_ALTD_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_ALTD_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_ALTD_DATA_REG]


//>> SET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA,
           TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]

//>> SET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA,
           TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]

//>> GET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_DATA_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA,
           TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
