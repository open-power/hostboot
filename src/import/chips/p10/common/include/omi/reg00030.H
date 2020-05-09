/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00030.H $          */
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

#ifndef __OMI_REG00030_H_
#define __OMI_REG00030_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL]

//>> GET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL]

//>> PUT_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL]


//>> SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]

//>> SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]

//>> SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]

//>> CLEAR_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]

//>> GET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]

//>> GET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]
static inline bool GET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT]

//>> SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]

//>> SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]

//>> SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]

//>> CLEAR_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]

//>> GET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]

//>> GET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]
static inline bool GET_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT]

//>> PREP_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_15_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_15_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_15_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL]

//>> PUT_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_15_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL]


//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> CLEAR_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline bool GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> CLEAR_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline bool GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> CLEAR_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline bool GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> CLEAR_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline bool GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> CLEAR_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline bool GET_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> PREP_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL]

//>> PUT_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL]


//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> PREP_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL]

//>> PUT_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL]


//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL]

//>> PREP_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_23_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_23_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_23_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL]

//>> PUT_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_23_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL]


//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> CLEAR_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]
static inline bool GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> CLEAR_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]
static inline bool GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> CLEAR_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]
static inline bool GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> CLEAR_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]
static inline bool GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> CLEAR_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]
static inline bool GET_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK]

//>> PREP_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL]

//>> PUT_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL]


//>> SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]

//>> CLEAR_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]
static inline bool GET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]

//>> CLEAR_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]
static inline bool GET_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE]

//>> PREP_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_3_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_3_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_3_PLREGS_RX_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL]

//>> PUT_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_3_PLREGS_RX_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL]


//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]
static inline bool GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]
static inline bool GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]
static inline bool GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]
static inline bool GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]
static inline bool GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]

//>> SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]

//>> CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]

//>> GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]
static inline bool GET_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXCTL_DATASM_3_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL]

//>> PREP_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH]

//>> PREP_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010]

//>> PREP_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100]

//>> PREP_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]
static inline bool GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_EN_DC]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_POS]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]
static inline bool GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL7_PL_FREQ_ADJUST_DC]

//>> PREP_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]
static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]
static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]
static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]
static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]
static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]
static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B]

//>> PREP_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP]

//>> PREP_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL]

//>> PREP_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001]

//>> PREP_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011]

//>> PREP_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101]

//>> PREP_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110]

//>> PREP_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_DATA]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_DATA]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_NS_EDGE]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE]

//>> SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE]

//>> GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL2_PL_EW_EDGE]

//>> PREP_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_FILTER]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE3_PL_TERM]

//>> PREP_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL]

//>> PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001]

//>> PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011]

//>> PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101]

//>> PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111]

//>> PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E]

//>> PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101]

//>> PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111]

//>> SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111]

//>> GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111]

//>> PREP_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110]

//>> PREP_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000]

//>> PREP_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010]

//>> PREP_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001]

//>> PREP_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]
static inline bool GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC]

//>> SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC]

//>> GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC]

//>> PREP_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ]

//>> SET_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ]

//>> GET_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ]

//>> PREP_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]

//>> SET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]

//>> GET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001]

//>> PREP_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]

//>> SET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]

//>> GET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011]

//>> PREP_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]
static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_COUNT_EN]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]
static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_EXP_DATA_SEL]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_PATTERN_SEL]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]
static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_MASK_MODE]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]
static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_REQ_DL_MASK]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]
static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_UMP_SL_1UI_DONE_DL_MASK]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]

//>> CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]
static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE1_PL_ERPL_LANE_INVERT]

//>> PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000]

//>> PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010]

//>> PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100]

//>> PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110]

//>> PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101]

//>> PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111]

//>> PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]

//>> SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]

//>> GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]

//>> PREP_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL]

//>> PUT_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL]


//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]
static inline bool GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]
static inline bool GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]
static inline bool GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]
static inline bool GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]
static inline bool GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]
static inline bool GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]
static inline bool GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN]

//>> PREP_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL]

//>> PUT_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL]


//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL,
           RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL]

//>> SET_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL,
           RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL]

//>> GET_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL,
           RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL]

//>> PREP_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL]

//>> GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL]

//>> PUT_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL]


//>> SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011]

//>> SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011]

//>> GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011]

//>> PREP_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL]

//>> GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL]

//>> PUT_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL]


//>> SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101]

//>> SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101]

//>> GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101]

//>> PREP_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL]

//>> GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL]

//>> PUT_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL]


//>> SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110]

//>> SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110]

//>> GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110]

//>> PREP_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL]

//>> GET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL]

//>> PUT_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL]


//>> SET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER]

//>> SET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER]

//>> GET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER]

//>> SET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM]

//>> SET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM]

//>> GET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
