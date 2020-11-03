/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00058.H $         */
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

#ifndef __PROC_REG00058_H_
#define __PROC_REG00058_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITASV3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITASV3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITASV3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITASV3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV3_7]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OTR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OTR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OTR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OTR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OTR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OTR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OTR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OTR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OTR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OTR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OTR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMEOUT_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_CONTROL_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_AUTO_RELOAD_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1,
           TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1,
           TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1,
           TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_SPARE_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1,
           TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1,
           TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1,
           TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR1_TIMER_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CHIP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SYSTEM_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCI_ARB_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_DISABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_TRACE_EVENT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_DBG_UNCONDITIONAL_EVENT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_EXT_INTERRUPT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CRITICAL_INTERRUPT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_PIB_SLAVE_RESET_TO_405_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_OCR_DBG_HALT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_SPARE]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR]


//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_DYNAMIC_ENCODED_DATA]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MIN_ENCODED_DATA]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_MAX_ENCODED_DATA]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_ECHAR_INVERTED_DYNAMIC_ENCODE_INJECT]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
