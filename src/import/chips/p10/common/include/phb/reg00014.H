/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00014.H $          */
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

#ifndef __PHB_REG00014_H_
#define __PHB_REG00014_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


//>> PREP_[REGS_INTBAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_INTBAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_INTBAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_INTBAR_REG]

//>> GET_[REGS_INTBAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_INTBAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_INTBAR_REG;
#endif
    return fapi2::getScom(i_target, REGS_INTBAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_INTBAR_REG]

//>> PUT_[REGS_INTBAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_INTBAR_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_INTBAR_REG));
#endif
    return fapi2::putScom(i_target, REGS_INTBAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_INTBAR_REG]


//>> SET_[REGS_INTBAR_REG_PE_INT_BAR]
static inline fapi2::buffer<uint64_t>& SET_REGS_INTBAR_REG_PE_INT_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_INTBAR_REG));
#endif
    return o_data.insertFromRight<REGS_INTBAR_REG_PE_INT_BAR,
           REGS_INTBAR_REG_PE_INT_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_INTBAR_REG_PE_INT_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_INTBAR_REG_PE_INT_BAR]

//>> SET_[REGS_INTBAR_REG_PE_INT_BAR]
static inline fapi2::buffer<uint64_t>& SET_REGS_INTBAR_REG_PE_INT_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_INTBAR_REG));
#endif
    return o_data.insertFromRight<REGS_INTBAR_REG_PE_INT_BAR,
           REGS_INTBAR_REG_PE_INT_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_INTBAR_REG_PE_INT_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_INTBAR_REG_PE_INT_BAR]

//>> GET_[REGS_INTBAR_REG_PE_INT_BAR]
static inline fapi2::buffer<uint64_t>& GET_REGS_INTBAR_REG_PE_INT_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_INTBAR_REG));
#endif
    return i_data.extractToRight<REGS_INTBAR_REG_PE_INT_BAR,
           REGS_INTBAR_REG_PE_INT_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_INTBAR_REG_PE_INT_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_INTBAR_REG_PE_INT_BAR]

//>> PREP_[REGS_PHBRESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PHBRESET_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PHBRESET_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_PHBRESET_REG]

//>> GET_[REGS_PHBRESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PHBRESET_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PHBRESET_REG;
#endif
    return fapi2::getScom(i_target, REGS_PHBRESET_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_PHBRESET_REG]

//>> PUT_[REGS_PHBRESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PHBRESET_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return fapi2::putScom(i_target, REGS_PHBRESET_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_PHBRESET_REG]


//>> SET_[REGS_PHBRESET_REG_PE_ETU_RESET]
static inline fapi2::buffer<uint64_t>& SET_REGS_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return o_data.insertFromRight<REGS_PHBRESET_REG_PE_ETU_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PHBRESET_REG_PE_ETU_RESET]

//>> SET_[REGS_PHBRESET_REG_PE_ETU_RESET]
static inline fapi2::buffer<uint64_t>& SET_REGS_PHBRESET_REG_PE_ETU_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return o_data.insertFromRight<REGS_PHBRESET_REG_PE_ETU_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PHBRESET_REG_PE_ETU_RESET]

//>> SET_[REGS_PHBRESET_REG_PE_ETU_RESET]
static inline fapi2::buffer<uint64_t>& SET_REGS_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return o_data.setBit<REGS_PHBRESET_REG_PE_ETU_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PHBRESET_REG_PE_ETU_RESET]

//>> CLEAR_[REGS_PHBRESET_REG_PE_ETU_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return o_data.clearBit<REGS_PHBRESET_REG_PE_ETU_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_PHBRESET_REG_PE_ETU_RESET]

//>> GET_[REGS_PHBRESET_REG_PE_ETU_RESET]
static inline fapi2::buffer<uint64_t>& GET_REGS_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return i_data.extractToRight<REGS_PHBRESET_REG_PE_ETU_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PHBRESET_REG_PE_ETU_RESET]

//>> GET_[REGS_PHBRESET_REG_PE_ETU_RESET]
static inline bool GET_REGS_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return i_data.getBit<REGS_PHBRESET_REG_PE_ETU_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PHBRESET_REG_PE_ETU_RESET]

//>> PREP_[RSB_SCOM_SSR_PHB5_UVIAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_SCOM_SSR_PHB5_UVIAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB5_UVIAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RSB_SCOM_SSR_PHB5_UVIAR]

//>> GET_[RSB_SCOM_SSR_PHB5_UVIAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_SCOM_SSR_PHB5_UVIAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB5_UVIAR;
#endif
    return fapi2::getScom(i_target, RSB_SCOM_SSR_PHB5_UVIAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_UVIAR]

//>> PUT_[RSB_SCOM_SSR_PHB5_UVIAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_SCOM_SSR_PHB5_UVIAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return fapi2::putScom(i_target, RSB_SCOM_SSR_PHB5_UVIAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RSB_SCOM_SSR_PHB5_UVIAR]


//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]

//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]

//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]

//>> CLEAR_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]

//>> GET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]
static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]

//>> GET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]
static inline bool GET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD]

//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]

//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]

//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]

//>> CLEAR_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]

//>> GET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]
static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]

//>> GET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]
static inline bool GET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B]

//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]

//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]

//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]

//>> CLEAR_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]

//>> GET_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]
static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]

//>> GET_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]
static inline bool GET_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC]

//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE]

//>> SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE]

//>> GET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE]
static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
