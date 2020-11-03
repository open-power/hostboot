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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
