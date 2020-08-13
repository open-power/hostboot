/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00004.H $          */
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

#ifndef __MCC_REG00004_H_
#define __MCC_REG00004_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> PREP_[DSTL_DSTLCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DSTL_DSTLCFG]

//>> GET_[DSTL_DSTLCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLCFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLCFG;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DSTL_DSTLCFG]

//>> PUT_[DSTL_DSTLCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLCFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DSTL_DSTLCFG]


//>> SET_[DSTL_DSTLCFG_TMPL0_ONLY]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL0_ONLY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_TMPL0_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL0_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL0_ONLY]

//>> SET_[DSTL_DSTLCFG_TMPL0_ONLY]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL0_ONLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_TMPL0_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL0_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL0_ONLY]

//>> SET_[DSTL_DSTLCFG_TMPL0_ONLY]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL0_ONLY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_TMPL0_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL0_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL0_ONLY]

//>> CLEAR_[DSTL_DSTLCFG_TMPL0_ONLY]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_TMPL0_ONLY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_TMPL0_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL0_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_TMPL0_ONLY]

//>> GET_[DSTL_DSTLCFG_TMPL0_ONLY]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_TMPL0_ONLY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_TMPL0_ONLY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL0_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_TMPL0_ONLY]

//>> GET_[DSTL_DSTLCFG_TMPL0_ONLY]
static inline bool GET_DSTL_DSTLCFG_TMPL0_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_TMPL0_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL0_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_TMPL0_ONLY]

//>> SET_[DSTL_DSTLCFG_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_1]

//>> SET_[DSTL_DSTLCFG_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_1]

//>> SET_[DSTL_DSTLCFG_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_1]

//>> CLEAR_[DSTL_DSTLCFG_RESERVED_1]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_RESERVED_1]

//>> GET_[DSTL_DSTLCFG_RESERVED_1]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESERVED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_1]

//>> GET_[DSTL_DSTLCFG_RESERVED_1]
static inline bool GET_DSTL_DSTLCFG_RESERVED_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_1]

//>> SET_[DSTL_DSTLCFG_TMPL7_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL7_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_TMPL7_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL7_ENABLE]

//>> SET_[DSTL_DSTLCFG_TMPL7_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL7_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_TMPL7_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL7_ENABLE]

//>> SET_[DSTL_DSTLCFG_TMPL7_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL7_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_TMPL7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL7_ENABLE]

//>> CLEAR_[DSTL_DSTLCFG_TMPL7_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_TMPL7_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_TMPL7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_TMPL7_ENABLE]

//>> GET_[DSTL_DSTLCFG_TMPL7_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_TMPL7_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_TMPL7_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_TMPL7_ENABLE]

//>> GET_[DSTL_DSTLCFG_TMPL7_ENABLE]
static inline bool GET_DSTL_DSTLCFG_TMPL7_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_TMPL7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_TMPL7_ENABLE]

//>> SET_[DSTL_DSTLCFG_TMPL1_DIS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL1_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_TMPL1_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL1_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL1_DIS]

//>> SET_[DSTL_DSTLCFG_TMPL1_DIS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL1_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_TMPL1_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL1_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL1_DIS]

//>> SET_[DSTL_DSTLCFG_TMPL1_DIS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL1_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_TMPL1_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL1_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL1_DIS]

//>> CLEAR_[DSTL_DSTLCFG_TMPL1_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_TMPL1_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_TMPL1_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL1_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_TMPL1_DIS]

//>> GET_[DSTL_DSTLCFG_TMPL1_DIS]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_TMPL1_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_TMPL1_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL1_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_TMPL1_DIS]

//>> GET_[DSTL_DSTLCFG_TMPL1_DIS]
static inline bool GET_DSTL_DSTLCFG_TMPL1_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_TMPL1_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL1_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_TMPL1_DIS]

//>> SET_[DSTL_DSTLCFG_FAST_RD_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_FAST_RD_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_FAST_RD_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_FAST_RD_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_FAST_RD_DISABLE]

//>> SET_[DSTL_DSTLCFG_FAST_RD_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_FAST_RD_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_FAST_RD_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_FAST_RD_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_FAST_RD_DISABLE]

//>> SET_[DSTL_DSTLCFG_FAST_RD_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_FAST_RD_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_FAST_RD_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_FAST_RD_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_FAST_RD_DISABLE]

//>> CLEAR_[DSTL_DSTLCFG_FAST_RD_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_FAST_RD_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_FAST_RD_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_FAST_RD_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_FAST_RD_DISABLE]

//>> GET_[DSTL_DSTLCFG_FAST_RD_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_FAST_RD_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_FAST_RD_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_FAST_RD_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_FAST_RD_DISABLE]

//>> GET_[DSTL_DSTLCFG_FAST_RD_DISABLE]
static inline bool GET_DSTL_DSTLCFG_FAST_RD_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_FAST_RD_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_FAST_RD_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_FAST_RD_DISABLE]

//>> SET_[DSTL_DSTLCFG_RESERVED_5]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_5]

//>> SET_[DSTL_DSTLCFG_RESERVED_5]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_5]

//>> SET_[DSTL_DSTLCFG_RESERVED_5]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_RESERVED_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_5]

//>> CLEAR_[DSTL_DSTLCFG_RESERVED_5]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_RESERVED_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_RESERVED_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_RESERVED_5]

//>> GET_[DSTL_DSTLCFG_RESERVED_5]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESERVED_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESERVED_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_5]

//>> GET_[DSTL_DSTLCFG_RESERVED_5]
static inline bool GET_DSTL_DSTLCFG_RESERVED_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_RESERVED_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_5]

//>> SET_[DSTL_DSTLCFG_TMPL4_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL4_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_TMPL4_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL4_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL4_DISABLE]

//>> SET_[DSTL_DSTLCFG_TMPL4_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL4_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_TMPL4_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL4_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL4_DISABLE]

//>> SET_[DSTL_DSTLCFG_TMPL4_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TMPL4_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_TMPL4_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL4_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TMPL4_DISABLE]

//>> CLEAR_[DSTL_DSTLCFG_TMPL4_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_TMPL4_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_TMPL4_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL4_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_TMPL4_DISABLE]

//>> GET_[DSTL_DSTLCFG_TMPL4_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_TMPL4_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_TMPL4_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL4_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_TMPL4_DISABLE]

//>> GET_[DSTL_DSTLCFG_TMPL4_DISABLE]
static inline bool GET_DSTL_DSTLCFG_TMPL4_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_TMPL4_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_TMPL4_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_TMPL4_DISABLE]

//>> SET_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]

//>> SET_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]

//>> SET_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]

//>> CLEAR_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]

//>> GET_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]

//>> GET_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]
static inline bool GET_DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS]

//>> SET_[DSTL_DSTLCFG_READ_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_READ_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_READ_THRESHOLD,
           DSTL_DSTLCFG_READ_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_READ_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_READ_THRESHOLD]

//>> SET_[DSTL_DSTLCFG_READ_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_READ_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_READ_THRESHOLD,
           DSTL_DSTLCFG_READ_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_READ_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_READ_THRESHOLD]

//>> GET_[DSTL_DSTLCFG_READ_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_READ_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_READ_THRESHOLD,
           DSTL_DSTLCFG_READ_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_READ_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_READ_THRESHOLD]

//>> SET_[DSTL_DSTLCFG_RESERVED_12_15]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_12_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_12_15,
           DSTL_DSTLCFG_RESERVED_12_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_12_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_12_15]

//>> SET_[DSTL_DSTLCFG_RESERVED_12_15]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_12_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_12_15,
           DSTL_DSTLCFG_RESERVED_12_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_12_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_12_15]

//>> GET_[DSTL_DSTLCFG_RESERVED_12_15]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESERVED_12_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESERVED_12_15,
           DSTL_DSTLCFG_RESERVED_12_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_12_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_12_15]

//>> SET_[DSTL_DSTLCFG_WR_TMP4_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_WR_TMP4_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_WR_TMP4_THRESHOLD,
           DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_WR_TMP4_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_WR_TMP4_THRESHOLD]

//>> SET_[DSTL_DSTLCFG_WR_TMP4_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_WR_TMP4_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_WR_TMP4_THRESHOLD,
           DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_WR_TMP4_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_WR_TMP4_THRESHOLD]

//>> GET_[DSTL_DSTLCFG_WR_TMP4_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_WR_TMP4_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_WR_TMP4_THRESHOLD,
           DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_WR_TMP4_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_WR_TMP4_THRESHOLD]

//>> SET_[DSTL_DSTLCFG_RESERVED_20_23]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_20_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_20_23,
           DSTL_DSTLCFG_RESERVED_20_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_20_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_20_23]

//>> SET_[DSTL_DSTLCFG_RESERVED_20_23]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_20_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_20_23,
           DSTL_DSTLCFG_RESERVED_20_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_20_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_20_23]

//>> GET_[DSTL_DSTLCFG_RESERVED_20_23]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESERVED_20_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESERVED_20_23,
           DSTL_DSTLCFG_RESERVED_20_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_20_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_20_23]

//>> SET_[DSTL_DSTLCFG_WR_DBL_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_WR_DBL_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_WR_DBL_THRESHOLD,
           DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_WR_DBL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_WR_DBL_THRESHOLD]

//>> SET_[DSTL_DSTLCFG_WR_DBL_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_WR_DBL_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_WR_DBL_THRESHOLD,
           DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_WR_DBL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_WR_DBL_THRESHOLD]

//>> GET_[DSTL_DSTLCFG_WR_DBL_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_WR_DBL_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_WR_DBL_THRESHOLD,
           DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_WR_DBL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_WR_DBL_THRESHOLD]

//>> SET_[DSTL_DSTLCFG_CRITICAL_OW_DIS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CRITICAL_OW_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_CRITICAL_OW_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_CRITICAL_OW_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CRITICAL_OW_DIS]

//>> SET_[DSTL_DSTLCFG_CRITICAL_OW_DIS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CRITICAL_OW_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_CRITICAL_OW_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_CRITICAL_OW_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CRITICAL_OW_DIS]

//>> SET_[DSTL_DSTLCFG_CRITICAL_OW_DIS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CRITICAL_OW_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_CRITICAL_OW_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_CRITICAL_OW_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CRITICAL_OW_DIS]

//>> CLEAR_[DSTL_DSTLCFG_CRITICAL_OW_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_CRITICAL_OW_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_CRITICAL_OW_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_CRITICAL_OW_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_CRITICAL_OW_DIS]

//>> GET_[DSTL_DSTLCFG_CRITICAL_OW_DIS]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_CRITICAL_OW_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_CRITICAL_OW_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_CRITICAL_OW_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_CRITICAL_OW_DIS]

//>> GET_[DSTL_DSTLCFG_CRITICAL_OW_DIS]
static inline bool GET_DSTL_DSTLCFG_CRITICAL_OW_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_CRITICAL_OW_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_CRITICAL_OW_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_CRITICAL_OW_DIS]

//>> SET_[DSTL_DSTLCFG_RESERVED_29]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_29]

//>> SET_[DSTL_DSTLCFG_RESERVED_29]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_29]

//>> SET_[DSTL_DSTLCFG_RESERVED_29]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_RESERVED_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_29]

//>> CLEAR_[DSTL_DSTLCFG_RESERVED_29]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_RESERVED_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_RESERVED_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_RESERVED_29]

//>> GET_[DSTL_DSTLCFG_RESERVED_29]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESERVED_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESERVED_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_29]

//>> GET_[DSTL_DSTLCFG_RESERVED_29]
static inline bool GET_DSTL_DSTLCFG_RESERVED_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_RESERVED_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_29]

//>> SET_[DSTL_DSTLCFG_RESERVED_30]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_30]

//>> SET_[DSTL_DSTLCFG_RESERVED_30]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_30]

//>> SET_[DSTL_DSTLCFG_RESERVED_30]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_RESERVED_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_30]

//>> CLEAR_[DSTL_DSTLCFG_RESERVED_30]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_RESERVED_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_RESERVED_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_RESERVED_30]

//>> GET_[DSTL_DSTLCFG_RESERVED_30]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESERVED_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESERVED_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_30]

//>> GET_[DSTL_DSTLCFG_RESERVED_30]
static inline bool GET_DSTL_DSTLCFG_RESERVED_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_RESERVED_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_30]

//>> SET_[DSTL_DSTLCFG_RESERVED_31]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_31]

//>> SET_[DSTL_DSTLCFG_RESERVED_31]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_31]

//>> SET_[DSTL_DSTLCFG_RESERVED_31]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_RESERVED_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_31]

//>> CLEAR_[DSTL_DSTLCFG_RESERVED_31]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_RESERVED_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_RESERVED_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_RESERVED_31]

//>> GET_[DSTL_DSTLCFG_RESERVED_31]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESERVED_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESERVED_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_31]

//>> GET_[DSTL_DSTLCFG_RESERVED_31]
static inline bool GET_DSTL_DSTLCFG_RESERVED_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_RESERVED_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_31]

//>> SET_[DSTL_DSTLCFG_RESERVED_32]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_32]

//>> SET_[DSTL_DSTLCFG_RESERVED_32]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_32]

//>> SET_[DSTL_DSTLCFG_RESERVED_32]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_RESERVED_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_32]

//>> CLEAR_[DSTL_DSTLCFG_RESERVED_32]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_RESERVED_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_RESERVED_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_RESERVED_32]

//>> GET_[DSTL_DSTLCFG_RESERVED_32]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESERVED_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESERVED_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_32]

//>> GET_[DSTL_DSTLCFG_RESERVED_32]
static inline bool GET_DSTL_DSTLCFG_RESERVED_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_RESERVED_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_32]

//>> SET_[DSTL_DSTLCFG_RESERVED_33_43]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_33_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_33_43,
           DSTL_DSTLCFG_RESERVED_33_43_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_33_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_33_43]

//>> SET_[DSTL_DSTLCFG_RESERVED_33_43]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_33_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_33_43,
           DSTL_DSTLCFG_RESERVED_33_43_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_33_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_33_43]

//>> GET_[DSTL_DSTLCFG_RESERVED_33_43]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESERVED_33_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESERVED_33_43,
           DSTL_DSTLCFG_RESERVED_33_43_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_33_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_33_43]

//>> SET_[DSTL_DSTLCFG_WRAP_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_WRAP_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_WRAP_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_WRAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_WRAP_MODE_EN]

//>> SET_[DSTL_DSTLCFG_WRAP_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_WRAP_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_WRAP_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_WRAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_WRAP_MODE_EN]

//>> SET_[DSTL_DSTLCFG_WRAP_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_WRAP_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_WRAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_WRAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_WRAP_MODE_EN]

//>> CLEAR_[DSTL_DSTLCFG_WRAP_MODE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_WRAP_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_WRAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_WRAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_WRAP_MODE_EN]

//>> GET_[DSTL_DSTLCFG_WRAP_MODE_EN]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_WRAP_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_WRAP_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_WRAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_WRAP_MODE_EN]

//>> GET_[DSTL_DSTLCFG_WRAP_MODE_EN]
static inline bool GET_DSTL_DSTLCFG_WRAP_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_WRAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_WRAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_WRAP_MODE_EN]

//>> SET_[DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH,
           DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH]

//>> SET_[DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH,
           DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH]

//>> GET_[DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH,
           DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH]

//>> SET_[DSTL_DSTLCFG_TIMEOUT_MODE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TIMEOUT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_TIMEOUT_MODE,
           DSTL_DSTLCFG_TIMEOUT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_TIMEOUT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TIMEOUT_MODE]

//>> SET_[DSTL_DSTLCFG_TIMEOUT_MODE]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_TIMEOUT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_TIMEOUT_MODE,
           DSTL_DSTLCFG_TIMEOUT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_TIMEOUT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_TIMEOUT_MODE]

//>> GET_[DSTL_DSTLCFG_TIMEOUT_MODE]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_TIMEOUT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_TIMEOUT_MODE,
           DSTL_DSTLCFG_TIMEOUT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_TIMEOUT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_TIMEOUT_MODE]

//>> SET_[DSTL_DSTLCFG_MMIO_ADDRBIT_POS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_MMIO_ADDRBIT_POS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_MMIO_ADDRBIT_POS,
           DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_MMIO_ADDRBIT_POS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_MMIO_ADDRBIT_POS]

//>> SET_[DSTL_DSTLCFG_MMIO_ADDRBIT_POS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_MMIO_ADDRBIT_POS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_MMIO_ADDRBIT_POS,
           DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_MMIO_ADDRBIT_POS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_MMIO_ADDRBIT_POS]

//>> GET_[DSTL_DSTLCFG_MMIO_ADDRBIT_POS]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_MMIO_ADDRBIT_POS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_MMIO_ADDRBIT_POS,
           DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_MMIO_ADDRBIT_POS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_MMIO_ADDRBIT_POS]

//>> SET_[DSTL_DSTLCFG_RESET_CREDITS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESET_CREDITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESET_CREDITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESET_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESET_CREDITS]

//>> SET_[DSTL_DSTLCFG_RESET_CREDITS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESET_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESET_CREDITS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESET_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESET_CREDITS]

//>> SET_[DSTL_DSTLCFG_RESET_CREDITS]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESET_CREDITS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_RESET_CREDITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_RESET_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESET_CREDITS]

//>> CLEAR_[DSTL_DSTLCFG_RESET_CREDITS]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_RESET_CREDITS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_RESET_CREDITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_RESET_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_RESET_CREDITS]

//>> GET_[DSTL_DSTLCFG_RESET_CREDITS]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESET_CREDITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESET_CREDITS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESET_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESET_CREDITS]

//>> GET_[DSTL_DSTLCFG_RESET_CREDITS]
static inline bool GET_DSTL_DSTLCFG_RESET_CREDITS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_RESET_CREDITS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_RESET_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESET_CREDITS]

//>> SET_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]

//>> SET_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]

//>> SET_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]

//>> CLEAR_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]

//>> GET_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]

//>> GET_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]
static inline bool GET_DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET]

//>> SET_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]

//>> SET_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]

//>> SET_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.setBit<DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]

//>> CLEAR_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.clearBit<DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]

//>> GET_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]

//>> GET_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]
static inline bool GET_DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.getBit<DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET]

//>> SET_[DSTL_DSTLCFG_RESERVED_62_63]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_62_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_62_63,
           DSTL_DSTLCFG_RESERVED_62_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_62_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_62_63]

//>> SET_[DSTL_DSTLCFG_RESERVED_62_63]
static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLCFG_RESERVED_62_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return o_data.insertFromRight<DSTL_DSTLCFG_RESERVED_62_63,
           DSTL_DSTLCFG_RESERVED_62_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_62_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DSTL_DSTLCFG_RESERVED_62_63]

//>> GET_[DSTL_DSTLCFG_RESERVED_62_63]
static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLCFG_RESERVED_62_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLCFG));
#endif
    return i_data.extractToRight<DSTL_DSTLCFG_RESERVED_62_63,
           DSTL_DSTLCFG_RESERVED_62_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access DSTL_DSTLCFG_RESERVED_62_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DSTL_DSTLCFG_RESERVED_62_63]

//>> PREP_[ATCL_CL_CLSCOM_MCPERF4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCPERF4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCPERF4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ATCL_CL_CLSCOM_MCPERF4]

//>> GET_[ATCL_CL_CLSCOM_MCPERF4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCPERF4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCPERF4;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCPERF4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF4]

//>> PUT_[ATCL_CL_CLSCOM_MCPERF4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCPERF4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCPERF4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ATCL_CL_CLSCOM_MCPERF4]


//>> SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]

//>> GET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]

//>> GET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]

//>> GET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]

//>> GET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ]

//>> GET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF]

//>> GET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF]

//>> GET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF,
           ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31,
           ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31]

//>> SET_[ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31,
           ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31]

//>> GET_[ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF4));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31,
           ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF4_RESERVED26_31]

//>> PREP_[USTL_USTLFIRACT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_USTL_USTLFIRACT2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRACT2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[USTL_USTLFIRACT2]

//>> GET_[USTL_USTLFIRACT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_USTL_USTLFIRACT2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = USTL_USTLFIRACT2;
#endif
    return fapi2::getScom(i_target, USTL_USTLFIRACT2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[USTL_USTLFIRACT2]

//>> PUT_[USTL_USTLFIRACT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_USTL_USTLFIRACT2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT2));
#endif
    return fapi2::putScom(i_target, USTL_USTLFIRACT2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[USTL_USTLFIRACT2]


//>> SET_[USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT2));
#endif
    return o_data.insertFromRight<USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2,
           USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2]

//>> SET_[USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2]
static inline fapi2::buffer<uint64_t>& SET_USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT2));
#endif
    return o_data.insertFromRight<USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2,
           USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2]

//>> GET_[USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2]
static inline fapi2::buffer<uint64_t>& GET_USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(USTL_USTLFIRACT2));
#endif
    return i_data.extractToRight<USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2,
           USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[USTL_USTLFIRACT2_USTLFIRACT2_ACTION_2]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
