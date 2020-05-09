/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00013.H $          */
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

#ifndef __PHB_REG00013_H_
#define __PHB_REG00013_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


//>> PREP_[REGS_PE_DFREEZE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PE_DFREEZE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PE_DFREEZE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_PE_DFREEZE_REG]

//>> GET_[REGS_PE_DFREEZE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PE_DFREEZE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PE_DFREEZE_REG;
#endif
    return fapi2::getScom(i_target, REGS_PE_DFREEZE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_PE_DFREEZE_REG]

//>> PUT_[REGS_PE_DFREEZE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PE_DFREEZE_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PE_DFREEZE_REG));
#endif
    return fapi2::putScom(i_target, REGS_PE_DFREEZE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_PE_DFREEZE_REG]


//>> SET_[REGS_PE_DFREEZE_REG_PE_DFREEZE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PE_DFREEZE_REG_PE_DFREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_DFREEZE_REG));
#endif
    return o_data.insertFromRight<REGS_PE_DFREEZE_REG_PE_DFREEZE,
           REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PE_DFREEZE_REG_PE_DFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PE_DFREEZE_REG_PE_DFREEZE]

//>> SET_[REGS_PE_DFREEZE_REG_PE_DFREEZE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PE_DFREEZE_REG_PE_DFREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_DFREEZE_REG));
#endif
    return o_data.insertFromRight<REGS_PE_DFREEZE_REG_PE_DFREEZE,
           REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PE_DFREEZE_REG_PE_DFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PE_DFREEZE_REG_PE_DFREEZE]

//>> GET_[REGS_PE_DFREEZE_REG_PE_DFREEZE]
static inline fapi2::buffer<uint64_t>& GET_REGS_PE_DFREEZE_REG_PE_DFREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_DFREEZE_REG));
#endif
    return i_data.extractToRight<REGS_PE_DFREEZE_REG_PE_DFREEZE,
           REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PE_DFREEZE_REG_PE_DFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PE_DFREEZE_REG_PE_DFREEZE]

//>> PREP_[REGS_PFIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PFIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_PFIR_REG_RW]

//>> GET_[REGS_PFIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PFIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_RW;
#endif
    return fapi2::getScom(i_target, REGS_PFIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_PFIR_REG_RW]

//>> PUT_[REGS_PFIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PFIR_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, REGS_PFIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_PFIR_REG_RW]

//>> PREP_[REGS_PFIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PFIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_PFIR_REG_WO_AND]

//>> GET_[REGS_PFIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PFIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, REGS_PFIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_PFIR_REG_WO_AND]

//>> PUT_[REGS_PFIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PFIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, REGS_PFIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_PFIR_REG_WO_AND]

//>> PREP_[REGS_PFIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PFIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_PFIR_REG_WO_OR]

//>> GET_[REGS_PFIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PFIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, REGS_PFIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_PFIR_REG_WO_OR]

//>> PUT_[REGS_PFIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PFIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, REGS_PFIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_PFIR_REG_WO_OR]


//>> SET_[REGS_PFIR_REG_PFIRPFIR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PFIR_REG_PFIRPFIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<REGS_PFIR_REG_PFIRPFIR,
           REGS_PFIR_REG_PFIRPFIR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PFIR_REG_PFIRPFIR]

//>> SET_[REGS_PFIR_REG_PFIRPFIR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PFIR_REG_PFIRPFIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<REGS_PFIR_REG_PFIRPFIR,
           REGS_PFIR_REG_PFIRPFIR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PFIR_REG_PFIRPFIR]

//>> GET_[REGS_PFIR_REG_PFIRPFIR]
static inline fapi2::buffer<uint64_t>& GET_REGS_PFIR_REG_PFIRPFIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return i_data.extractToRight<REGS_PFIR_REG_PFIRPFIR,
           REGS_PFIR_REG_PFIRPFIR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PFIR_REG_PFIRPFIR]

//>> PREP_[RSB_SCOM_SSR_PHB5_HVIAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_SCOM_SSR_PHB5_HVIAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB5_HVIAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RSB_SCOM_SSR_PHB5_HVIAR]

//>> GET_[RSB_SCOM_SSR_PHB5_HVIAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_SCOM_SSR_PHB5_HVIAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB5_HVIAR;
#endif
    return fapi2::getScom(i_target, RSB_SCOM_SSR_PHB5_HVIAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_HVIAR]

//>> PUT_[RSB_SCOM_SSR_PHB5_HVIAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_SCOM_SSR_PHB5_HVIAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return fapi2::putScom(i_target, RSB_SCOM_SSR_PHB5_HVIAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RSB_SCOM_SSR_PHB5_HVIAR]


//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]

//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]

//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]

//>> CLEAR_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]

//>> GET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]
static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]

//>> GET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]
static inline bool GET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD]

//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]

//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]

//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]

//>> CLEAR_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]

//>> GET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]
static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]

//>> GET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]
static inline bool GET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B]

//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]

//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]

//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]

//>> CLEAR_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]

//>> GET_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]
static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]

//>> GET_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]
static inline bool GET_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC]

//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE]

//>> SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE]
static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE]

//>> GET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE]
static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
