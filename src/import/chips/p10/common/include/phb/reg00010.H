/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00010.H $          */
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

#ifndef __PHB_REG00010_H_
#define __PHB_REG00010_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


//>> PREP_[REGS_CQSTAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_CQSTAT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_CQSTAT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_CQSTAT_REG]

//>> GET_[REGS_CQSTAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_CQSTAT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_CQSTAT_REG;
#endif
    return fapi2::getScom(i_target, REGS_CQSTAT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_CQSTAT_REG]

//>> PUT_[REGS_CQSTAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_CQSTAT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return fapi2::putScom(i_target, REGS_CQSTAT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_CQSTAT_REG]


//>> SET_[REGS_CQSTAT_REG_INBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_REGS_CQSTAT_REG_INBOUND_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return o_data.insertFromRight<REGS_CQSTAT_REG_INBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_CQSTAT_REG_INBOUND_ACTIVE]

//>> SET_[REGS_CQSTAT_REG_INBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_REGS_CQSTAT_REG_INBOUND_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return o_data.insertFromRight<REGS_CQSTAT_REG_INBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_CQSTAT_REG_INBOUND_ACTIVE]

//>> SET_[REGS_CQSTAT_REG_INBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_REGS_CQSTAT_REG_INBOUND_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return o_data.setBit<REGS_CQSTAT_REG_INBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_CQSTAT_REG_INBOUND_ACTIVE]

//>> CLEAR_[REGS_CQSTAT_REG_INBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_CQSTAT_REG_INBOUND_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return o_data.clearBit<REGS_CQSTAT_REG_INBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_CQSTAT_REG_INBOUND_ACTIVE]

//>> GET_[REGS_CQSTAT_REG_INBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_REGS_CQSTAT_REG_INBOUND_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return i_data.extractToRight<REGS_CQSTAT_REG_INBOUND_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_CQSTAT_REG_INBOUND_ACTIVE]

//>> GET_[REGS_CQSTAT_REG_INBOUND_ACTIVE]
static inline bool GET_REGS_CQSTAT_REG_INBOUND_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return i_data.getBit<REGS_CQSTAT_REG_INBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_CQSTAT_REG_INBOUND_ACTIVE]

//>> SET_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return o_data.insertFromRight<REGS_CQSTAT_REG_OUTBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]

//>> SET_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return o_data.insertFromRight<REGS_CQSTAT_REG_OUTBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]

//>> SET_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return o_data.setBit<REGS_CQSTAT_REG_OUTBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]

//>> CLEAR_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return o_data.clearBit<REGS_CQSTAT_REG_OUTBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]

//>> GET_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return i_data.extractToRight<REGS_CQSTAT_REG_OUTBOUND_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]

//>> GET_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]
static inline bool GET_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CQSTAT_REG));
#endif
    return i_data.getBit<REGS_CQSTAT_REG_OUTBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_CQSTAT_REG_OUTBOUND_ACTIVE]

//>> PREP_[REGS_NFIRMASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_NFIRMASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_NFIRMASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_NFIRMASK_REG_RW]

//>> GET_[REGS_NFIRMASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_NFIRMASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_NFIRMASK_REG_RW;
#endif
    return fapi2::getScom(i_target, REGS_NFIRMASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_NFIRMASK_REG_RW]

//>> PUT_[REGS_NFIRMASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_NFIRMASK_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_NFIRMASK_REG_RW, REGS_NFIRMASK_REG_WO_AND, REGS_NFIRMASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, REGS_NFIRMASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_NFIRMASK_REG_RW]

//>> PREP_[REGS_NFIRMASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_NFIRMASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_NFIRMASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_NFIRMASK_REG_WO_AND]

//>> GET_[REGS_NFIRMASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_NFIRMASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_NFIRMASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, REGS_NFIRMASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_NFIRMASK_REG_WO_AND]

//>> PUT_[REGS_NFIRMASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_NFIRMASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_NFIRMASK_REG_RW, REGS_NFIRMASK_REG_WO_AND, REGS_NFIRMASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, REGS_NFIRMASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_NFIRMASK_REG_WO_AND]

//>> PREP_[REGS_NFIRMASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_NFIRMASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_NFIRMASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_NFIRMASK_REG_WO_OR]

//>> GET_[REGS_NFIRMASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_NFIRMASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_NFIRMASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, REGS_NFIRMASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_NFIRMASK_REG_WO_OR]

//>> PUT_[REGS_NFIRMASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_NFIRMASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_NFIRMASK_REG_RW, REGS_NFIRMASK_REG_WO_AND, REGS_NFIRMASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, REGS_NFIRMASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_NFIRMASK_REG_WO_OR]


//>> SET_[REGS_NFIRMASK_REG_NFIRMASK]
static inline fapi2::buffer<uint64_t>& SET_REGS_NFIRMASK_REG_NFIRMASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_NFIRMASK_REG_RW, REGS_NFIRMASK_REG_WO_AND, REGS_NFIRMASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<REGS_NFIRMASK_REG_NFIRMASK,
           REGS_NFIRMASK_REG_NFIRMASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_NFIRMASK_REG_NFIRMASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_NFIRMASK_REG_NFIRMASK]

//>> SET_[REGS_NFIRMASK_REG_NFIRMASK]
static inline fapi2::buffer<uint64_t>& SET_REGS_NFIRMASK_REG_NFIRMASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_NFIRMASK_REG_RW, REGS_NFIRMASK_REG_WO_AND, REGS_NFIRMASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<REGS_NFIRMASK_REG_NFIRMASK,
           REGS_NFIRMASK_REG_NFIRMASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_NFIRMASK_REG_NFIRMASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_NFIRMASK_REG_NFIRMASK]

//>> GET_[REGS_NFIRMASK_REG_NFIRMASK]
static inline fapi2::buffer<uint64_t>& GET_REGS_NFIRMASK_REG_NFIRMASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_NFIRMASK_REG_RW, REGS_NFIRMASK_REG_WO_AND, REGS_NFIRMASK_REG_WO_OR));
#endif
    return i_data.extractToRight<REGS_NFIRMASK_REG_NFIRMASK,
           REGS_NFIRMASK_REG_NFIRMASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_NFIRMASK_REG_NFIRMASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_NFIRMASK_REG_NFIRMASK]

//>> PREP_[REGS_PHBBAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PHBBAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PHBBAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REGS_PHBBAR_REG]

//>> GET_[REGS_PHBBAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PHBBAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PHBBAR_REG;
#endif
    return fapi2::getScom(i_target, REGS_PHBBAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REGS_PHBBAR_REG]

//>> PUT_[REGS_PHBBAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PHBBAR_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PHBBAR_REG));
#endif
    return fapi2::putScom(i_target, REGS_PHBBAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REGS_PHBBAR_REG]


//>> SET_[REGS_PHBBAR_REG_PE_PHB_BAR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PHBBAR_REG_PE_PHB_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBBAR_REG));
#endif
    return o_data.insertFromRight<REGS_PHBBAR_REG_PE_PHB_BAR,
           REGS_PHBBAR_REG_PE_PHB_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access REGS_PHBBAR_REG_PE_PHB_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PHBBAR_REG_PE_PHB_BAR]

//>> SET_[REGS_PHBBAR_REG_PE_PHB_BAR]
static inline fapi2::buffer<uint64_t>& SET_REGS_PHBBAR_REG_PE_PHB_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBBAR_REG));
#endif
    return o_data.insertFromRight<REGS_PHBBAR_REG_PE_PHB_BAR,
           REGS_PHBBAR_REG_PE_PHB_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access REGS_PHBBAR_REG_PE_PHB_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[REGS_PHBBAR_REG_PE_PHB_BAR]

//>> GET_[REGS_PHBBAR_REG_PE_PHB_BAR]
static inline fapi2::buffer<uint64_t>& GET_REGS_PHBBAR_REG_PE_PHB_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBBAR_REG));
#endif
    return i_data.extractToRight<REGS_PHBBAR_REG_PE_PHB_BAR,
           REGS_PHBBAR_REG_PE_PHB_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access REGS_PHBBAR_REG_PE_PHB_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[REGS_PHBBAR_REG_PE_PHB_BAR]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
