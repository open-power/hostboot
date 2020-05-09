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


//>> PREP_[PHB5_SCOM_UV_SEC_INCL_CMP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PHB5_SCOM_UV_SEC_INCL_CMP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHB5_SCOM_UV_SEC_INCL_CMP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PHB5_SCOM_UV_SEC_INCL_CMP]

//>> GET_[PHB5_SCOM_UV_SEC_INCL_CMP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PHB5_SCOM_UV_SEC_INCL_CMP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHB5_SCOM_UV_SEC_INCL_CMP;
#endif
    return fapi2::getScom(i_target, PHB5_SCOM_UV_SEC_INCL_CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PHB5_SCOM_UV_SEC_INCL_CMP]

//>> PUT_[PHB5_SCOM_UV_SEC_INCL_CMP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PHB5_SCOM_UV_SEC_INCL_CMP(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_INCL_CMP));
#endif
    return fapi2::putScom(i_target, PHB5_SCOM_UV_SEC_INCL_CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PHB5_SCOM_UV_SEC_INCL_CMP]


//>> SET_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.insertFromRight<PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]

//>> SET_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.insertFromRight<PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]

//>> SET_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.setBit<PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]

//>> CLEAR_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.clearBit<PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]

//>> GET_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_INCL_CMP));
#endif
    return i_data.extractToRight<PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]

//>> GET_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]
static inline bool GET_PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_INCL_CMP));
#endif
    return i_data.getBit<PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE]

//>> SET_[PHB5_SCOM_UV_SEC_INCL_CMP_VALUE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_INCL_CMP_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.insertFromRight<PHB5_SCOM_UV_SEC_INCL_CMP_VALUE,
           PHB5_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_INCL_CMP_VALUE]

//>> SET_[PHB5_SCOM_UV_SEC_INCL_CMP_VALUE]
static inline fapi2::buffer<uint64_t>& SET_PHB5_SCOM_UV_SEC_INCL_CMP_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_INCL_CMP));
#endif
    return o_data.insertFromRight<PHB5_SCOM_UV_SEC_INCL_CMP_VALUE,
           PHB5_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PHB5_SCOM_UV_SEC_INCL_CMP_VALUE]

//>> GET_[PHB5_SCOM_UV_SEC_INCL_CMP_VALUE]
static inline fapi2::buffer<uint64_t>& GET_PHB5_SCOM_UV_SEC_INCL_CMP_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHB5_SCOM_UV_SEC_INCL_CMP));
#endif
    return i_data.extractToRight<PHB5_SCOM_UV_SEC_INCL_CMP_VALUE,
           PHB5_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access PHB5_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PHB5_SCOM_UV_SEC_INCL_CMP_VALUE]

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

//>> PREP_[REGS_PBCQMODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PBCQMODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PBCQMODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_PBCQMODE_REG]

//>> GET_[REGS_PBCQMODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PBCQMODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PBCQMODE_REG;
#endif
    return fapi2::getScom(i_target, REGS_PBCQMODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_PBCQMODE_REG]

//>> PUT_[REGS_PBCQMODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PBCQMODE_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return fapi2::putScom(i_target, REGS_PBCQMODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_PBCQMODE_REG]


//>> SET_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]

//>> SET_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]

//>> SET_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.setBit<REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]

//>> CLEAR_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.clearBit<REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]

//>> GET_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.extractToRight<REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]

//>> GET_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]
static inline bool GET_REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.getBit<REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PE_PEER2PEER_MODDE]

//>> SET_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PBCQMODE_UNUSED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PBCQMODE_UNUSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBCQMODE_REG_PBCQMODE_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]

//>> SET_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PBCQMODE_UNUSED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PBCQMODE_UNUSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBCQMODE_REG_PBCQMODE_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]

//>> SET_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PBCQMODE_UNUSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.setBit<REGS_PBCQMODE_REG_PBCQMODE_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_PBCQMODE_REG_PBCQMODE_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]

//>> CLEAR_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PBCQMODE_REG_PBCQMODE_UNUSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.clearBit<REGS_PBCQMODE_REG_PBCQMODE_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_PBCQMODE_REG_PBCQMODE_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]

//>> GET_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBCQMODE_REG_PBCQMODE_UNUSED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.extractToRight<REGS_PBCQMODE_REG_PBCQMODE_UNUSED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBCQMODE_REG_PBCQMODE_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]

//>> GET_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]
static inline bool GET_REGS_PBCQMODE_REG_PBCQMODE_UNUSED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.getBit<REGS_PBCQMODE_REG_PBCQMODE_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_PBCQMODE_REG_PBCQMODE_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PBCQMODE_UNUSED]

//>> SET_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]

//>> SET_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]

//>> SET_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.setBit<REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]

//>> CLEAR_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.clearBit<REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]

//>> GET_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.extractToRight<REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]

//>> GET_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]
static inline bool GET_REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.getBit<REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PE_PB_CQ_REGS_CS_ENABLE_SMF]

//>> SET_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]

//>> SET_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]

//>> SET_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.setBit<REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]

//>> CLEAR_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.clearBit<REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]

//>> GET_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.extractToRight<REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]

//>> GET_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]
static inline bool GET_REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.getBit<REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PE_ATOMIC_LITTLE_ENDIAN]

//>> SET_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]

//>> SET_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]

//>> SET_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.setBit<REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]

//>> CLEAR_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.clearBit<REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]

//>> GET_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.extractToRight<REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]

//>> GET_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]
static inline bool GET_REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.getBit<REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PE_RDP2P_DMA_MODE]

//>> SET_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]

//>> SET_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.insertFromRight<REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]

//>> SET_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]
static inline fapi2::buffer<uint64_t>& SET_REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.setBit<REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]

//>> CLEAR_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return o_data.clearBit<REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]

//>> GET_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]
static inline fapi2::buffer<uint64_t>& GET_REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.extractToRight<REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]

//>> GET_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]
static inline bool GET_REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBCQMODE_REG));
#endif
    return i_data.getBit<REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PBCQMODE_REG_PE_LDP2P_DMA_MODE]

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
