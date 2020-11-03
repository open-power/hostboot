/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00016.H $         */
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

#ifndef __PROC_REG00016_H_
#define __PROC_REG00016_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_PTLSCOM10_FM0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_FM0123_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FM0123_ERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM10_FM0123_ERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_FM0123_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FM0123_ERR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_FM0123_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR]

//>> PUT_[PB_PTLSCOM10_FM0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_FM0123_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_FM0123_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM10_FM0123_ERR]


//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_ADDR_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_HI_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_DAT_LO_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_FRAME_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_INTERNAL_ERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_PRSP_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_TTAG_PERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_PTYERR]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FM0123_ERR_3_RTAG_MISC_PTY]

//>> PREP_[TP_TCN1_N1_CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_CPLT_CONF1_RW]

//>> GET_[TP_TCN1_N1_CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CONF1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CONF1_RW]

//>> PUT_[TP_TCN1_N1_CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CONF1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_CPLT_CONF1_RW]

//>> PREP_[TP_TCN1_N1_CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_CPLT_CONF1_WO_CLEAR]

//>> GET_[TP_TCN1_N1_CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CONF1_WO_CLEAR]

//>> PUT_[TP_TCN1_N1_CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_CPLT_CONF1_WO_CLEAR]

//>> PREP_[TP_TCN1_N1_CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_CPLT_CONF1_WO_OR]

//>> GET_[TP_TCN1_N1_CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CONF1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CONF1_WO_OR]

//>> PUT_[TP_TCN1_N1_CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CONF1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_CPLT_CONF1_WO_OR]


//>> SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC,
           TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC,
           TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]

//>> GET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC,
           TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQ_DC]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC,
           TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC,
           TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]

//>> GET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC,
           TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_EQALL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC,
           TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC,
           TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]

//>> GET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC,
           TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CONF1_C_ANES_AMUX_VSEL_ES_VDN_DC]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> CLEAR_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> GET_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> GET_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]
static inline bool GET_TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CONF1_P_N1_PSI_IOVALID_DC]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_C_LP_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_C_LP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_C_LP_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_C_LP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]

//>> SET_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_C_LP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_C_LP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]

//>> CLEAR_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_C_LP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_C_LP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]

//>> GET_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_C_LP_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_C_LP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]

//>> GET_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]
static inline bool GET_TP_TCN1_N1_CPLT_CONF1_C_LP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_C_LP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CONF1_C_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CONF1_C_LP_RESET]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
