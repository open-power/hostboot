/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00073.H $         */
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

#ifndef __PROC_REG00073_H_
#define __PROC_REG00073_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_I_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3_B_ADDRESS]

//>> PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC]

//>> PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC]


//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_TAG_ADDR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_ERR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_VALID]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_VALID]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE_PTR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_LINE2_ERR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIICAC_ICACHE_PREFETCH_PENDING]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ]


//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMAX]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMULT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN,
           TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_HIRES_FMIN]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO]


//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLK_ERROR_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCKDET_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_REFCLK_DATA_OUT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_0_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CHECK_ERROR_1_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_BYP_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_MUXSEL_CLK_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_UNLOCK_UNSTICKY_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHED]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RESET_OR_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FORCE_CLK_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_BYPASS_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SWITCHOVER_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_CLEAR_CLK_ERROR_INT_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_A]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_SET_BYPASS_B]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SNS1LTH_TPFSI_RCS_SENSE_DC_0_31]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
