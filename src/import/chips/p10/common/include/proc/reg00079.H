/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00079.H $         */
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

#ifndef __PROC_REG00079_H_
#define __PROC_REG00079_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SLBUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SLBUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SLBUS;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SLBUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SLBUS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SLBUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS]


//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_FORCE_LBUS_OWNERSHIP]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_REQUEST_LBUS_OWNERSHIP]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP,
           TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP,
           TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP,
           TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RELEASE_LBUS_OWNERSHIP]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_RESET_LBUS_REQUEST]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS,
           TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS,
           TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SLBUS));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS,
           TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SLBUS_LOCK_LBUS_ACCESS]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SRSIC0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SRSIC0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SRSIC0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SRSIC0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SRSIC0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SRSIC0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SRSIC0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SRSIC0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SRSIC0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SRSIC0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SRSIC0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SRSIC0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SRSIC0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SRSIC0]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_B_SNML]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SNML(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SNML;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_B_SNML]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SNML]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SNML(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SNML;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SNML, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SNML]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_B_SNML]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SNML(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SNML));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SNML, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_B_SNML]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_B_SSISM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SSISM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSISM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_B_SSISM]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSISM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SSISM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSISM;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSISM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSISM]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_B_SSISM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SSISM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSISM));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSISM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_B_SSISM]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SSTAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSTAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSTAT;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSTAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SSTAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSTAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT]


//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ANY_SLV_ERROR]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_ID_DIRTY]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_WARM_START_SYNC_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_DELIVERED_TO_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_MAIL_RECEIVED_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_BRIEFING_DATA_SYNC_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_LEFT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_REQ_SYNC_FR_RIGHT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_LBUS_REQ]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_LOCK]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_LBUS_GNT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_THIS_SIDE]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_OWNERSHIP_FF2]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_LEVEL]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_AUX_DI_REFERENCE]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSTAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR,
           TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SSTAT_CRC_ERR_CTR]

//>> PREP_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI,
                           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI]

//>> PREP_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI,
                           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI,
                           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG,
           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI,
                           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG,
           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI,
                           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG,
           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_COMPLEMENT_MASK_COMPLEMENT_MASK_REG]

//>> PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER]


//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N1]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_N2]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_A]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_LOOPCOUNT2]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_SHIFTER_FSM_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N1_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_N2_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_COUNTER_COUNT_RESERVED_B]

//>> PREP_[VAS_VA_EG_SCF_WCBSBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_WCBSBAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_WCBSBAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_EG_SCF_WCBSBAR]

//>> GET_[VAS_VA_EG_SCF_WCBSBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_WCBSBAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_WCBSBAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_WCBSBAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCBSBAR]

//>> PUT_[VAS_VA_EG_SCF_WCBSBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_WCBSBAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCBSBAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_WCBSBAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_EG_SCF_WCBSBAR]


//>> SET_[VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCBSBAR));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR,
           VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR]

//>> SET_[VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCBSBAR));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR,
           VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR]

//>> GET_[VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCBSBAR));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR,
           VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCBSBAR_WC_BS_BAR]

//>> PREP_[VAS_VA_RG_SCF_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_FIR_REG_RW]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_RW]

//>> PUT_[VAS_VA_RG_SCF_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_FIR_REG_RW]

//>> PREP_[VAS_VA_RG_SCF_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_FIR_REG_WO_AND]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WO_AND]

//>> PUT_[VAS_VA_RG_SCF_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_FIR_REG_WO_AND]

//>> PREP_[VAS_VA_RG_SCF_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_FIR_REG_WO_OR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WO_OR]

//>> PUT_[VAS_VA_RG_SCF_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_FIR_REG_WO_OR]


//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_EG_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WC_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_RG_LOGIC_HW_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_PARITY_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_RD_ADDR_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_WR_ADDR_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_CE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_OB_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_PB_MASTER_FSM_HANG]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_UE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_PARITY_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_SW_CAST_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_SMF_ACCESS_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_EG_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_IN_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WC_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_RG_ECC_SUE_ERROR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_RD_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_RD_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_HYP_WR_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_OS_WR_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_HYP_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_MMIO_NON8B_OS_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WM_WIN_NOT_OPEN_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WM_MULTIHIT_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_DISABLED_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_PG_MIG_SIZE_MISMATCH_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_NOTIFY_FAILED_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_WR_MON_NOT_DISABLED_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_VAS_REJECTED_PASTE_CMD]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_DATA_HANG_DETECTED]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_INCOMING_PB_PARITY_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_SCOM1_SAT_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_NX_LOCAL_XSTOP]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_SCOM_MMIO_ADDR_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]

//>> SET_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]

//>> GET_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]
static inline bool GET_VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_REG_RW, VAS_VA_RG_SCF_FIR_REG_WO_AND, VAS_VA_RG_SCF_FIR_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_FIR_REG_CQ_RG_FIR_TOPO_INDEX_ERR]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
