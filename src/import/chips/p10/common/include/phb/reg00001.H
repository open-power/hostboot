/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00001.H $          */
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

#ifndef __PHB_REG00001_H_
#define __PHB_REG00001_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


//>> PREP_[REGS_PBAIBTXCCR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PBAIBTXCCR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_PBAIBTXCCR_REG]

//>> GET_[REGS_PBAIBTXCCR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PBAIBTXCCR_REG;
#endif
    return fapi2::getScom(i_target, REGS_PBAIBTXCCR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_PBAIBTXCCR_REG]

//>> PUT_[REGS_PBAIBTXCCR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return fapi2::putScom(i_target, REGS_PBAIBTXCCR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_PBAIBTXCCR_REG]


//>> SET_[REGS_PBAIBTXCCR_REG_0_CCA]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_0_CCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_0_CCA,
           REGS_PBAIBTXCCR_REG_0_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_0_CCA]

//>> SET_[REGS_PBAIBTXCCR_REG_0_CCA]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_0_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_0_CCA,
           REGS_PBAIBTXCCR_REG_0_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_0_CCA]

//>> GET_[REGS_PBAIBTXCCR_REG_0_CCA]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_0_CCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_0_CCA,
           REGS_PBAIBTXCCR_REG_0_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBAIBTXCCR_REG_0_CCA]

//>> SET_[REGS_PBAIBTXCCR_REG_0_CCR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_0_CCR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_0_CCR,
           REGS_PBAIBTXCCR_REG_0_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_0_CCR]

//>> SET_[REGS_PBAIBTXCCR_REG_0_CCR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_0_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_0_CCR,
           REGS_PBAIBTXCCR_REG_0_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_0_CCR]

//>> GET_[REGS_PBAIBTXCCR_REG_0_CCR]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_0_CCR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_0_CCR,
           REGS_PBAIBTXCCR_REG_0_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBAIBTXCCR_REG_0_CCR]

//>> SET_[REGS_PBAIBTXCCR_REG_1_CCA]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_1_CCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_1_CCA,
           REGS_PBAIBTXCCR_REG_1_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_1_CCA]

//>> SET_[REGS_PBAIBTXCCR_REG_1_CCA]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_1_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_1_CCA,
           REGS_PBAIBTXCCR_REG_1_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_1_CCA]

//>> GET_[REGS_PBAIBTXCCR_REG_1_CCA]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_1_CCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_1_CCA,
           REGS_PBAIBTXCCR_REG_1_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBAIBTXCCR_REG_1_CCA]

//>> SET_[REGS_PBAIBTXCCR_REG_1_CCR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_1_CCR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_1_CCR,
           REGS_PBAIBTXCCR_REG_1_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_1_CCR]

//>> SET_[REGS_PBAIBTXCCR_REG_1_CCR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_1_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_1_CCR,
           REGS_PBAIBTXCCR_REG_1_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_1_CCR]

//>> GET_[REGS_PBAIBTXCCR_REG_1_CCR]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_1_CCR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_1_CCR,
           REGS_PBAIBTXCCR_REG_1_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBAIBTXCCR_REG_1_CCR]

//>> SET_[REGS_PBAIBTXCCR_REG_2_CCA]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_2_CCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_2_CCA,
           REGS_PBAIBTXCCR_REG_2_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_2_CCA]

//>> SET_[REGS_PBAIBTXCCR_REG_2_CCA]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_2_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_2_CCA,
           REGS_PBAIBTXCCR_REG_2_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_2_CCA]

//>> GET_[REGS_PBAIBTXCCR_REG_2_CCA]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_2_CCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_2_CCA,
           REGS_PBAIBTXCCR_REG_2_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBAIBTXCCR_REG_2_CCA]

//>> SET_[REGS_PBAIBTXCCR_REG_2_CCR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_2_CCR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_2_CCR,
           REGS_PBAIBTXCCR_REG_2_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_2_CCR]

//>> SET_[REGS_PBAIBTXCCR_REG_2_CCR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_2_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_2_CCR,
           REGS_PBAIBTXCCR_REG_2_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_2_CCR]

//>> GET_[REGS_PBAIBTXCCR_REG_2_CCR]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_2_CCR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_2_CCR,
           REGS_PBAIBTXCCR_REG_2_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBAIBTXCCR_REG_2_CCR]

//>> SET_[REGS_PBAIBTXCCR_REG_3_CCA]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_3_CCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_3_CCA,
           REGS_PBAIBTXCCR_REG_3_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_3_CCA]

//>> SET_[REGS_PBAIBTXCCR_REG_3_CCA]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_3_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_3_CCA,
           REGS_PBAIBTXCCR_REG_3_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_3_CCA]

//>> GET_[REGS_PBAIBTXCCR_REG_3_CCA]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_3_CCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_3_CCA,
           REGS_PBAIBTXCCR_REG_3_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBAIBTXCCR_REG_3_CCA]

//>> SET_[REGS_PBAIBTXCCR_REG_3_CCR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_3_CCR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_3_CCR,
           REGS_PBAIBTXCCR_REG_3_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_3_CCR]

//>> SET_[REGS_PBAIBTXCCR_REG_3_CCR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_3_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_3_CCR,
           REGS_PBAIBTXCCR_REG_3_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBAIBTXCCR_REG_3_CCR]

//>> GET_[REGS_PBAIBTXCCR_REG_3_CCR]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_3_CCR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_3_CCR,
           REGS_PBAIBTXCCR_REG_3_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBAIBTXCCR_REG_3_CCR]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
