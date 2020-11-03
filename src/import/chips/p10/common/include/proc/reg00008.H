/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00008.H $         */
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

#ifndef __PROC_REG00008_H_
#define __PROC_REG00008_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITASV0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITASV0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITASV0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITASV0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV0_7]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_START_JTAG_CMD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_DR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_DO_TAP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WR_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC, TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_SCOM2,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_WO_AND));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJIC_JTAG_INSTR]

//>> PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND]

//>> PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND]

//>> PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW0_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_FW1_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_QME_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_STOP_RECOVERY_NOTIFY_PRD_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_HB_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WATCHDOG_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_UE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_CE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_HALTED_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_WRITE_PROTECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_24_25_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_EXTERNAL_TRAP_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CORE_RESET_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_CHIP_RESET_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_SYSTEM_RESET_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGMSRWE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_PPC405_DBGSTOPACK_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_DB_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_PIB_ADDR_PARITY_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCB_IDC_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_PARITY_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OPIT_FSM_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_37_41_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_JTAGACC_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_ERR_38_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_UE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_ECC_CE_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405_OCI_MACHINECHECK_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRAM_SPARE_DIRECT_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SRT_OTHER_ERROR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_49_50_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE0_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE1_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE2_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_GPE3_OCISLV_ERR_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405ICU_M_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_C405DCU_M_TIMEOUT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_FAULT_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]
static inline bool GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_OCC_COMPLEX_NOTIFY_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_AND,
                           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_SPARE_59_61_MASK]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR]


//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_BYPASS]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_SPARE2]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
