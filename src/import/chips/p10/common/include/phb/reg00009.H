/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00009.H $          */
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

#ifndef __PHB_REG00009_H_
#define __PHB_REG00009_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


//>> PREP_[REGS_MMIOBAR0_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_MMIOBAR0_MASK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_MMIOBAR0_MASK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_MMIOBAR0_MASK_REG]

//>> GET_[REGS_MMIOBAR0_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_MMIOBAR0_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_MMIOBAR0_MASK_REG;
#endif
    return fapi2::getScom(i_target, REGS_MMIOBAR0_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_MMIOBAR0_MASK_REG]

//>> PUT_[REGS_MMIOBAR0_MASK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_MMIOBAR0_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR0_MASK_REG));
#endif
    return fapi2::putScom(i_target, REGS_MMIOBAR0_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_MMIOBAR0_MASK_REG]


//>> SET_[REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0]
static inline fapi2::buffer<uint64_t>& SET_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR0_MASK_REG));
#endif
    return o_data.insertFromRight<REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0,
           REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0]

//>> SET_[REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0]
static inline fapi2::buffer<uint64_t>& SET_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR0_MASK_REG));
#endif
    return o_data.insertFromRight<REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0,
           REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0]

//>> GET_[REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0]
static inline fapi2::buffer<uint64_t>& GET_REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR0_MASK_REG));
#endif
    return i_data.extractToRight<REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0,
           REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_MMIOBAR0_MASK_REG_PE_MMIO_MASK0]

//>> PREP_[REGS_PFIRACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PFIRACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIRACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_PFIRACTION0_REG]

//>> GET_[REGS_PFIRACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PFIRACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIRACTION0_REG;
#endif
    return fapi2::getScom(i_target, REGS_PFIRACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_PFIRACTION0_REG]

//>> PUT_[REGS_PFIRACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PFIRACTION0_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PFIRACTION0_REG));
#endif
    return fapi2::putScom(i_target, REGS_PFIRACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_PFIRACTION0_REG]


//>> SET_[REGS_PFIRACTION0_REG_PFIRACTION0]
static inline fapi2::buffer<uint64_t>& SET_REGS_PFIRACTION0_REG_PFIRACTION0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIRACTION0_REG));
#endif
    return o_data.insertFromRight<REGS_PFIRACTION0_REG_PFIRACTION0,
           REGS_PFIRACTION0_REG_PFIRACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PFIRACTION0_REG_PFIRACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PFIRACTION0_REG_PFIRACTION0]

//>> SET_[REGS_PFIRACTION0_REG_PFIRACTION0]
static inline fapi2::buffer<uint64_t>& SET_REGS_PFIRACTION0_REG_PFIRACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIRACTION0_REG));
#endif
    return o_data.insertFromRight<REGS_PFIRACTION0_REG_PFIRACTION0,
           REGS_PFIRACTION0_REG_PFIRACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PFIRACTION0_REG_PFIRACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PFIRACTION0_REG_PFIRACTION0]

//>> GET_[REGS_PFIRACTION0_REG_PFIRACTION0]
static inline fapi2::buffer<uint64_t>& GET_REGS_PFIRACTION0_REG_PFIRACTION0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIRACTION0_REG));
#endif
    return i_data.extractToRight<REGS_PFIRACTION0_REG_PFIRACTION0,
           REGS_PFIRACTION0_REG_PFIRACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PFIRACTION0_REG_PFIRACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PFIRACTION0_REG_PFIRACTION0]

//>> PREP_[REGS_PFIRACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PFIRACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIRACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_PFIRACTION1_REG]

//>> GET_[REGS_PFIRACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PFIRACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIRACTION1_REG;
#endif
    return fapi2::getScom(i_target, REGS_PFIRACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_PFIRACTION1_REG]

//>> PUT_[REGS_PFIRACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PFIRACTION1_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PFIRACTION1_REG));
#endif
    return fapi2::putScom(i_target, REGS_PFIRACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_PFIRACTION1_REG]


//>> SET_[REGS_PFIRACTION1_REG_PFIRACTION1]
static inline fapi2::buffer<uint64_t>& SET_REGS_PFIRACTION1_REG_PFIRACTION1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIRACTION1_REG));
#endif
    return o_data.insertFromRight<REGS_PFIRACTION1_REG_PFIRACTION1,
           REGS_PFIRACTION1_REG_PFIRACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PFIRACTION1_REG_PFIRACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PFIRACTION1_REG_PFIRACTION1]

//>> SET_[REGS_PFIRACTION1_REG_PFIRACTION1]
static inline fapi2::buffer<uint64_t>& SET_REGS_PFIRACTION1_REG_PFIRACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIRACTION1_REG));
#endif
    return o_data.insertFromRight<REGS_PFIRACTION1_REG_PFIRACTION1,
           REGS_PFIRACTION1_REG_PFIRACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PFIRACTION1_REG_PFIRACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PFIRACTION1_REG_PFIRACTION1]

//>> GET_[REGS_PFIRACTION1_REG_PFIRACTION1]
static inline fapi2::buffer<uint64_t>& GET_REGS_PFIRACTION1_REG_PFIRACTION1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIRACTION1_REG));
#endif
    return i_data.extractToRight<REGS_PFIRACTION1_REG_PFIRACTION1,
           REGS_PFIRACTION1_REG_PFIRACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PFIRACTION1_REG_PFIRACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PFIRACTION1_REG_PFIRACTION1]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
