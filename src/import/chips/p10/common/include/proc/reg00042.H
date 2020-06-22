/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00042.H $         */
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

#ifndef __PROC_REG00042_H_
#define __PROC_REG00042_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_XSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]

//>> PREP_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR]

//>> PUT_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR]

//>> PREP_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR]

//>> PUT_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR]


//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RFGSHIFT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_RZRTMP_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_SHIFT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXEI_TRANSMIT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXINS_OVERRUN]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_1_PSIRXBFF_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_DATAO_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXBFF_RFC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_DATA_BUFF_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_RCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRXLC_UE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRXLC_CE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRXLC_DATA_GXST1_PCK_2N]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_2_PSIRFACC_RCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RFSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_3_PSIRFACC_RDL_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_4_PSIRFACC_RXSC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_RLINK_STATE_LT_02]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_PSIRFACC_C_RXDATA_RDY_ERR]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_RX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_ERROR_REG_0_ERRACK_RISE]

//>> PREP_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR]

//>> PUT_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR]

//>> PREP_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR]

//>> PUT_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR]


//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_TZRTMP_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_SHIFT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXEI_TRANSMIT_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_PARITY]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXINS_UNDERRUN]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_DATA_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_1_PSITXBFF_TDO_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXBFF_TFC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_BUFF_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TDO_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_TCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_2_PSITXLC_UE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_RF]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_UE_GX_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_0_PSITXLC_CE_GX_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST2_PCK_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSITXLC_DATA_GXST3_PCK_2N]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TADDR_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TCTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_CMD_CTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RSP_CTRL_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TFSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_FSM_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_4_PSIRFACC_TXSC_PCK]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]

//>> SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]

//>> GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_ERROR_REG_RW_WCLEAR, TP_TPBR_PSI_WRAP_TX_ERROR_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_ERROR_REG_3_PSIRFACC_TDL_RETRY_ERR]

//>> PREP_[PSI_MAC_SCOM_REGS_TX_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PSI_MAC_SCOM_REGS_TX_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PSI_MAC_SCOM_REGS_TX_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PSI_MAC_SCOM_REGS_TX_MODE]

//>> GET_[PSI_MAC_SCOM_REGS_TX_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PSI_MAC_SCOM_REGS_TX_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PSI_MAC_SCOM_REGS_TX_MODE;
#endif
    return fapi2::getScom(i_target, PSI_MAC_SCOM_REGS_TX_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_MODE]

//>> PUT_[PSI_MAC_SCOM_REGS_TX_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PSI_MAC_SCOM_REGS_TX_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return fapi2::putScom(i_target, PSI_MAC_SCOM_REGS_TX_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PSI_MAC_SCOM_REGS_TX_MODE]


//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]

//>> CLEAR_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]

//>> GET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]

//>> GET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]
static inline bool GET_PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_TEST_MODE]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC]

//>> GET_[PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_MODE_MAIN_EN_ENC]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC]

//>> GET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_MODE_PC_EN_ENC]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL,
           PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL,
           PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL]

//>> GET_[PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL,
           PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_MODE_SLEWCTL]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC]

//>> GET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTNL_ENC]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC]

//>> SET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC]

//>> GET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC,
           PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_MODE_PVTPL_ENC]

//>> PREP_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1]

//>> PUT_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1]


//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_49]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_50]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_51]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_52]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_53]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_54]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_55]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_56]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_57]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_58]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_59]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_60]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_61]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_62]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_63]

//>> PREP_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW]

//>> PUT_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW]

//>> PREP_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND]

//>> PUT_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND]

//>> PREP_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR]

//>> PUT_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR]


//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_00]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_01]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_02]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_03]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_04]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_05]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_06]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_07]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_08]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_09]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_10]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_11]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_12]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_13]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_14]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_15]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_16]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_17]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_18]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_19]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_20]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_21]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_22]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_23]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_24]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_25]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_26]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_27]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_28]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_29]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_30]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_31]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_32]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_33]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_34]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_35]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_36]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_37]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_38]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_39]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_40]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_41]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_42]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_43]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_44]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_45]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_46]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_47]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_48]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_49]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_50]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_51]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_52]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_53]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_54]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_55]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_56]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_57]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_58]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_59]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_60]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_61]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_62]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_MASK_RW, TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN1_N1_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_MASK_63]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
