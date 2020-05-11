/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00015.H $          */
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

#ifndef __PHB_REG00015_H_
#define __PHB_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


//>> PREP_[REGS_BARE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_BARE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_BARE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_BARE_REG]

//>> GET_[REGS_BARE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_BARE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_BARE_REG;
#endif
    return fapi2::getScom(i_target, REGS_BARE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_BARE_REG]

//>> PUT_[REGS_BARE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_BARE_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return fapi2::putScom(i_target, REGS_BARE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_BARE_REG]


//>> SET_[REGS_BARE_REG_MMIO_BAR0_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_MMIO_BAR0_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.insertFromRight<REGS_BARE_REG_MMIO_BAR0_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_MMIO_BAR0_EN]

//>> SET_[REGS_BARE_REG_MMIO_BAR0_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_MMIO_BAR0_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.insertFromRight<REGS_BARE_REG_MMIO_BAR0_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_MMIO_BAR0_EN]

//>> SET_[REGS_BARE_REG_MMIO_BAR0_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_MMIO_BAR0_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.setBit<REGS_BARE_REG_MMIO_BAR0_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_MMIO_BAR0_EN]

//>> CLEAR_[REGS_BARE_REG_MMIO_BAR0_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_BARE_REG_MMIO_BAR0_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.clearBit<REGS_BARE_REG_MMIO_BAR0_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_BARE_REG_MMIO_BAR0_EN]

//>> GET_[REGS_BARE_REG_MMIO_BAR0_EN]
static inline fapi2::buffer<uint64_t>& GET_REGS_BARE_REG_MMIO_BAR0_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return i_data.extractToRight<REGS_BARE_REG_MMIO_BAR0_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_BARE_REG_MMIO_BAR0_EN]

//>> GET_[REGS_BARE_REG_MMIO_BAR0_EN]
static inline bool GET_REGS_BARE_REG_MMIO_BAR0_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return i_data.getBit<REGS_BARE_REG_MMIO_BAR0_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_BARE_REG_MMIO_BAR0_EN]

//>> SET_[REGS_BARE_REG_MMIO_BAR1_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_MMIO_BAR1_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.insertFromRight<REGS_BARE_REG_MMIO_BAR1_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_MMIO_BAR1_EN]

//>> SET_[REGS_BARE_REG_MMIO_BAR1_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_MMIO_BAR1_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.insertFromRight<REGS_BARE_REG_MMIO_BAR1_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_MMIO_BAR1_EN]

//>> SET_[REGS_BARE_REG_MMIO_BAR1_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_MMIO_BAR1_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.setBit<REGS_BARE_REG_MMIO_BAR1_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_MMIO_BAR1_EN]

//>> CLEAR_[REGS_BARE_REG_MMIO_BAR1_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_BARE_REG_MMIO_BAR1_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.clearBit<REGS_BARE_REG_MMIO_BAR1_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_BARE_REG_MMIO_BAR1_EN]

//>> GET_[REGS_BARE_REG_MMIO_BAR1_EN]
static inline fapi2::buffer<uint64_t>& GET_REGS_BARE_REG_MMIO_BAR1_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return i_data.extractToRight<REGS_BARE_REG_MMIO_BAR1_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_BARE_REG_MMIO_BAR1_EN]

//>> GET_[REGS_BARE_REG_MMIO_BAR1_EN]
static inline bool GET_REGS_BARE_REG_MMIO_BAR1_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return i_data.getBit<REGS_BARE_REG_MMIO_BAR1_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_BARE_REG_MMIO_BAR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_BARE_REG_MMIO_BAR1_EN]

//>> SET_[REGS_BARE_REG_PHB_BAR_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_PHB_BAR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.insertFromRight<REGS_BARE_REG_PHB_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_PHB_BAR_EN]

//>> SET_[REGS_BARE_REG_PHB_BAR_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_PHB_BAR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.insertFromRight<REGS_BARE_REG_PHB_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_PHB_BAR_EN]

//>> SET_[REGS_BARE_REG_PHB_BAR_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_PHB_BAR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.setBit<REGS_BARE_REG_PHB_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_PHB_BAR_EN]

//>> CLEAR_[REGS_BARE_REG_PHB_BAR_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_BARE_REG_PHB_BAR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.clearBit<REGS_BARE_REG_PHB_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_BARE_REG_PHB_BAR_EN]

//>> GET_[REGS_BARE_REG_PHB_BAR_EN]
static inline fapi2::buffer<uint64_t>& GET_REGS_BARE_REG_PHB_BAR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return i_data.extractToRight<REGS_BARE_REG_PHB_BAR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_BARE_REG_PHB_BAR_EN]

//>> GET_[REGS_BARE_REG_PHB_BAR_EN]
static inline bool GET_REGS_BARE_REG_PHB_BAR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return i_data.getBit<REGS_BARE_REG_PHB_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_BARE_REG_PHB_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_BARE_REG_PHB_BAR_EN]

//>> SET_[REGS_BARE_REG_INT_BAR_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_INT_BAR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.insertFromRight<REGS_BARE_REG_INT_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_INT_BAR_EN]

//>> SET_[REGS_BARE_REG_INT_BAR_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_INT_BAR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.insertFromRight<REGS_BARE_REG_INT_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_INT_BAR_EN]

//>> SET_[REGS_BARE_REG_INT_BAR_EN]
static inline fapi2::buffer<uint64_t>& SET_REGS_BARE_REG_INT_BAR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.setBit<REGS_BARE_REG_INT_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_BARE_REG_INT_BAR_EN]

//>> CLEAR_[REGS_BARE_REG_INT_BAR_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_BARE_REG_INT_BAR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return o_data.clearBit<REGS_BARE_REG_INT_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_BARE_REG_INT_BAR_EN]

//>> GET_[REGS_BARE_REG_INT_BAR_EN]
static inline fapi2::buffer<uint64_t>& GET_REGS_BARE_REG_INT_BAR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return i_data.extractToRight<REGS_BARE_REG_INT_BAR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_BARE_REG_INT_BAR_EN]

//>> GET_[REGS_BARE_REG_INT_BAR_EN]
static inline bool GET_REGS_BARE_REG_INT_BAR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_BARE_REG));
#endif
    return i_data.getBit<REGS_BARE_REG_INT_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_BARE_REG_INT_BAR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_BARE_REG_INT_BAR_EN]

//>> PREP_[REGS_MMIOBAR0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_MMIOBAR0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_MMIOBAR0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_MMIOBAR0_REG]

//>> GET_[REGS_MMIOBAR0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_MMIOBAR0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_MMIOBAR0_REG;
#endif
    return fapi2::getScom(i_target, REGS_MMIOBAR0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_MMIOBAR0_REG]

//>> PUT_[REGS_MMIOBAR0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_MMIOBAR0_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR0_REG));
#endif
    return fapi2::putScom(i_target, REGS_MMIOBAR0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_MMIOBAR0_REG]


//>> SET_[REGS_MMIOBAR0_REG_PE_MMIO_BAR0]
static inline fapi2::buffer<uint64_t>& SET_REGS_MMIOBAR0_REG_PE_MMIO_BAR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR0_REG));
#endif
    return o_data.insertFromRight<REGS_MMIOBAR0_REG_PE_MMIO_BAR0,
           REGS_MMIOBAR0_REG_PE_MMIO_BAR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_MMIOBAR0_REG_PE_MMIO_BAR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_MMIOBAR0_REG_PE_MMIO_BAR0]

//>> SET_[REGS_MMIOBAR0_REG_PE_MMIO_BAR0]
static inline fapi2::buffer<uint64_t>& SET_REGS_MMIOBAR0_REG_PE_MMIO_BAR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR0_REG));
#endif
    return o_data.insertFromRight<REGS_MMIOBAR0_REG_PE_MMIO_BAR0,
           REGS_MMIOBAR0_REG_PE_MMIO_BAR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_MMIOBAR0_REG_PE_MMIO_BAR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_MMIOBAR0_REG_PE_MMIO_BAR0]

//>> GET_[REGS_MMIOBAR0_REG_PE_MMIO_BAR0]
static inline fapi2::buffer<uint64_t>& GET_REGS_MMIOBAR0_REG_PE_MMIO_BAR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR0_REG));
#endif
    return i_data.extractToRight<REGS_MMIOBAR0_REG_PE_MMIO_BAR0,
           REGS_MMIOBAR0_REG_PE_MMIO_BAR0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_MMIOBAR0_REG_PE_MMIO_BAR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_MMIOBAR0_REG_PE_MMIO_BAR0]

//>> PREP_[REGS_MMIOBAR1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_MMIOBAR1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_MMIOBAR1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_MMIOBAR1_REG]

//>> GET_[REGS_MMIOBAR1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_MMIOBAR1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_MMIOBAR1_REG;
#endif
    return fapi2::getScom(i_target, REGS_MMIOBAR1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_MMIOBAR1_REG]

//>> PUT_[REGS_MMIOBAR1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_MMIOBAR1_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR1_REG));
#endif
    return fapi2::putScom(i_target, REGS_MMIOBAR1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_MMIOBAR1_REG]


//>> SET_[REGS_MMIOBAR1_REG_PE_MMIO_BAR1]
static inline fapi2::buffer<uint64_t>& SET_REGS_MMIOBAR1_REG_PE_MMIO_BAR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR1_REG));
#endif
    return o_data.insertFromRight<REGS_MMIOBAR1_REG_PE_MMIO_BAR1,
           REGS_MMIOBAR1_REG_PE_MMIO_BAR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_MMIOBAR1_REG_PE_MMIO_BAR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_MMIOBAR1_REG_PE_MMIO_BAR1]

//>> SET_[REGS_MMIOBAR1_REG_PE_MMIO_BAR1]
static inline fapi2::buffer<uint64_t>& SET_REGS_MMIOBAR1_REG_PE_MMIO_BAR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR1_REG));
#endif
    return o_data.insertFromRight<REGS_MMIOBAR1_REG_PE_MMIO_BAR1,
           REGS_MMIOBAR1_REG_PE_MMIO_BAR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_MMIOBAR1_REG_PE_MMIO_BAR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_MMIOBAR1_REG_PE_MMIO_BAR1]

//>> GET_[REGS_MMIOBAR1_REG_PE_MMIO_BAR1]
static inline fapi2::buffer<uint64_t>& GET_REGS_MMIOBAR1_REG_PE_MMIO_BAR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR1_REG));
#endif
    return i_data.extractToRight<REGS_MMIOBAR1_REG_PE_MMIO_BAR1,
           REGS_MMIOBAR1_REG_PE_MMIO_BAR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_MMIOBAR1_REG_PE_MMIO_BAR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_MMIOBAR1_REG_PE_MMIO_BAR1]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
