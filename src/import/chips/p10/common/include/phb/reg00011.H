/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00011.H $          */
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

#ifndef __PHB_REG00011_H_
#define __PHB_REG00011_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


//>> PREP_[RSB_REGS_ACT0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_REGS_ACT0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_ACT0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RSB_REGS_ACT0_REG]

//>> GET_[RSB_REGS_ACT0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_REGS_ACT0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_ACT0_REG;
#endif
    return fapi2::getScom(i_target, RSB_REGS_ACT0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG]

//>> PUT_[RSB_REGS_ACT0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_REGS_ACT0_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return fapi2::putScom(i_target, RSB_REGS_ACT0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RSB_REGS_ACT0_REG]


//>> SET_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]

//>> SET_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]

//>> SET_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]

//>> CLEAR_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]

//>> GET_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]

//>> GET_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]
static inline bool GET_RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_COMMAND_INVALID]

//>> SET_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_ADDRESSING_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_ACCESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> CLEAR_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> GET_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> GET_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline bool GET_RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_FATAL_CLASS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_INF_CLASS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_PE_STOP_STATE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]

//>> SET_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]

//>> SET_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]

//>> CLEAR_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]

//>> GET_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]

//>> GET_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]
static inline bool GET_RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_AIB_DAT_ERR_SIGNALED]

//>> SET_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> SET_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> SET_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> CLEAR_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> GET_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> GET_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline bool GET_RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> SET_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]

//>> SET_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]

//>> SET_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]

//>> CLEAR_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]

//>> GET_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]

//>> GET_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]
static inline bool GET_RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MMIO_REQUEST_TIMEOUT]

//>> SET_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_OUT_RRB_SOURCED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_FDA_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_FDA_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_FDB_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_FDB_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_ERR_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_ERR_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_DBG_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_DBG_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_BUS_LOGIC_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_UVI_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_RSB_UVI_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_SCOM_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_SCOM_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_SCOM_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_SCOM_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_SCOM_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_SCOM_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_SCOM_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_SCOM_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_SCOM_INF_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> SET_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> SET_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> CLEAR_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> GET_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> GET_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline bool GET_RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> SET_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_IODA_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_MSI_PE_MATCH_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_MSI_ADDRESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_TVT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_TVT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_TVT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_TVT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_TVT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_TVT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_TVT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_TVT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> GET_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> GET_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> GET_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> GET_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> GET_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> GET_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> SET_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> CLEAR_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> GET_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> GET_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline bool GET_RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_BLIF_COMPLETION_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_PCT_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]

//>> SET_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]

//>> SET_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]

//>> GET_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]

//>> GET_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_TLP_POISON_SIGNALED]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_MRT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_MRT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_MRT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_MRG_MRT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_MRG_MRT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_MRG_MRT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_MRG_MRT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_MRT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_MRG_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_RESERVED01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_RESERVED01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_RESERVED01]

//>> SET_[RSB_REGS_ACT0_REG_MRG_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_RESERVED01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_RESERVED01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_RESERVED01]

//>> SET_[RSB_REGS_ACT0_REG_MRG_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_RESERVED01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_MRG_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_RESERVED01]

//>> CLEAR_[RSB_REGS_ACT0_REG_MRG_RESERVED01]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_MRG_RESERVED01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_MRG_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_MRG_RESERVED01]

//>> GET_[RSB_REGS_ACT0_REG_MRG_RESERVED01]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_MRG_RESERVED01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_MRG_RESERVED01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_RESERVED01]

//>> GET_[RSB_REGS_ACT0_REG_MRG_RESERVED01]
static inline bool GET_RSB_REGS_ACT0_REG_MRG_RESERVED01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_MRG_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_RESERVED01]

//>> SET_[RSB_REGS_ACT0_REG_MRG_RESERVED02]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_RESERVED02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_RESERVED02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_RESERVED02]

//>> SET_[RSB_REGS_ACT0_REG_MRG_RESERVED02]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_RESERVED02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_MRG_RESERVED02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_RESERVED02]

//>> SET_[RSB_REGS_ACT0_REG_MRG_RESERVED02]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_MRG_RESERVED02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_MRG_RESERVED02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_MRG_RESERVED02]

//>> CLEAR_[RSB_REGS_ACT0_REG_MRG_RESERVED02]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_MRG_RESERVED02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_MRG_RESERVED02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_MRG_RESERVED02]

//>> GET_[RSB_REGS_ACT0_REG_MRG_RESERVED02]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_MRG_RESERVED02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_MRG_RESERVED02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_RESERVED02]

//>> GET_[RSB_REGS_ACT0_REG_MRG_RESERVED02]
static inline bool GET_RSB_REGS_ACT0_REG_MRG_RESERVED02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_MRG_RESERVED02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_MRG_RESERVED02]

//>> SET_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]

//>> SET_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]

//>> SET_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]

//>> CLEAR_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]

//>> GET_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]

//>> GET_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]
static inline bool GET_RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_COMMON_FATAL_ERRORS]

//>> SET_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_TCE_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_RESERVED01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_RESERVED01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_RESERVED01]

//>> SET_[RSB_REGS_ACT0_REG_TCE_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_RESERVED01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_TCE_RESERVED01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_RESERVED01]

//>> SET_[RSB_REGS_ACT0_REG_TCE_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_TCE_RESERVED01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_TCE_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_TCE_RESERVED01]

//>> CLEAR_[RSB_REGS_ACT0_REG_TCE_RESERVED01]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_TCE_RESERVED01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_TCE_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_TCE_RESERVED01]

//>> GET_[RSB_REGS_ACT0_REG_TCE_RESERVED01]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_TCE_RESERVED01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_TCE_RESERVED01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_RESERVED01]

//>> GET_[RSB_REGS_ACT0_REG_TCE_RESERVED01]
static inline bool GET_RSB_REGS_ACT0_REG_TCE_RESERVED01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_TCE_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_TCE_RESERVED01]

//>> SET_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.insertFromRight<RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> SET_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.setBit<RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> CLEAR_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return o_data.clearBit<RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.extractToRight<RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> GET_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline bool GET_RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_ACT0_REG));
#endif
    return i_data.getBit<RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_ACT0_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> PREP_[RSB_REGS_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_REGS_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RSB_REGS_MASK_REG_RW]

//>> GET_[RSB_REGS_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_REGS_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, RSB_REGS_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RW]

//>> PUT_[RSB_REGS_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_REGS_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, RSB_REGS_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RSB_REGS_MASK_REG_RW]

//>> PREP_[RSB_REGS_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_REGS_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RSB_REGS_MASK_REG_WO_AND]

//>> GET_[RSB_REGS_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_REGS_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, RSB_REGS_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_WO_AND]

//>> PUT_[RSB_REGS_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_REGS_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, RSB_REGS_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RSB_REGS_MASK_REG_WO_AND]

//>> PREP_[RSB_REGS_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_REGS_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RSB_REGS_MASK_REG_WO_OR]

//>> GET_[RSB_REGS_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_REGS_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, RSB_REGS_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_WO_OR]

//>> PUT_[RSB_REGS_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_REGS_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, RSB_REGS_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RSB_REGS_MASK_REG_WO_OR]


//>> SET_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_COMMAND_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]

//>> SET_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_COMMAND_INVALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_COMMAND_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]

//>> SET_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_AIB_COMMAND_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]

//>> CLEAR_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_AIB_COMMAND_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]

//>> GET_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_AIB_COMMAND_INVALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]

//>> GET_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]
static inline bool GET_RSB_REGS_MASK_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_AIB_COMMAND_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_COMMAND_INVALID]

//>> SET_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]

//>> GET_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]

//>> GET_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_ADDRESSING_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_AIB_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_AIB_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_AIB_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_AIB_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_ACCESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> CLEAR_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> GET_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> GET_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]
static inline bool GET_RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_FATAL_CLASS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_INF_CLASS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_PE_STOP_STATE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]

//>> SET_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]

//>> SET_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]

//>> CLEAR_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]

//>> GET_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]

//>> GET_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]
static inline bool GET_RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_AIB_DAT_ERR_SIGNALED]

//>> SET_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_OUT_COMMON_ARRAY_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_OUT_COMMON_LATCH_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_OUT_COMMON_LOGIC_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> SET_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> SET_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> GET_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> GET_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_BLIF_OUT_INTERFACE_PARITY_ERROR]

//>> SET_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> SET_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> SET_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> CLEAR_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> GET_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> GET_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]
static inline bool GET_RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE]

//>> SET_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]

//>> SET_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]

//>> SET_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]

//>> CLEAR_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]

//>> GET_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]

//>> GET_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]
static inline bool GET_RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MMIO_REQUEST_TIMEOUT]

//>> SET_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]

//>> GET_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]

//>> GET_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_OUT_RRB_SOURCED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> GET_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> GET_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_CFG_LOGIC_SIGNALED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_REG_REQUEST_ADDRESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_FDA_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_FDA_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_FDB_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_FDB_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_ERR_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_ERR_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_DBG_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_DBG_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_PCIE_REQUEST_ACCESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_BUS_LOGIC_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_UVI_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_RSB_UVI_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_SCOM_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_SCOM_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_SCOM_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_SCOM_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_SCOM_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_SCOM_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_SCOM_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_SCOM_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_SCOM_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_SCOM_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_SCOM_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_SCOM_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_SCOM_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_SCOM_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]

//>> GET_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_SCOM_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_SCOM_INF_ERROR]

//>> SET_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> SET_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> SET_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> CLEAR_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> GET_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> GET_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]
static inline bool GET_RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS]

//>> SET_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_IODA_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_MSI_PE_MATCH_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_MSI_ADDRESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_TVT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_TVT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_TVT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_TVT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_TVT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_TVT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_TVT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_TVT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> SET_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> SET_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> GET_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> GET_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]
static inline bool GET_RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_RCVD_FATAL_ERROR_MSG]

//>> SET_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> SET_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> SET_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> GET_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> GET_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]
static inline bool GET_RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_RCVD_NONFATAL_ERROR_MSG]

//>> SET_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> SET_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> SET_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> GET_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> GET_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]
static inline bool GET_RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG]

//>> SET_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> CLEAR_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> GET_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> GET_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]
static inline bool GET_RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED]

//>> SET_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_BLIF_COMPLETION_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_PCT_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]

//>> SET_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]

//>> SET_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]

//>> GET_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]

//>> GET_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]
static inline bool GET_RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_TLP_POISON_SIGNALED]

//>> SET_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> SET_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> GET_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_ARB_RTT_PENUM_INVALID_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_COMMON_FATAL_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_TABLE_BAR_DISABLED_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_AIB2_TX_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_MRT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_MRT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_MRT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_MRG_MRT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_MRG_MRT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_MRG_MRT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]

//>> GET_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_MRG_MRT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_MRT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_MRG_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_RESERVED01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_RESERVED01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_RESERVED01]

//>> SET_[RSB_REGS_MASK_REG_MRG_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_RESERVED01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_RESERVED01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_RESERVED01]

//>> SET_[RSB_REGS_MASK_REG_MRG_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_RESERVED01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_MRG_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_RESERVED01]

//>> CLEAR_[RSB_REGS_MASK_REG_MRG_RESERVED01]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_MRG_RESERVED01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_MRG_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_MRG_RESERVED01]

//>> GET_[RSB_REGS_MASK_REG_MRG_RESERVED01]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_MRG_RESERVED01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_MRG_RESERVED01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_RESERVED01]

//>> GET_[RSB_REGS_MASK_REG_MRG_RESERVED01]
static inline bool GET_RSB_REGS_MASK_REG_MRG_RESERVED01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_MRG_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_RESERVED01]

//>> SET_[RSB_REGS_MASK_REG_MRG_RESERVED02]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_RESERVED02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_RESERVED02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_RESERVED02]

//>> SET_[RSB_REGS_MASK_REG_MRG_RESERVED02]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_RESERVED02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_MRG_RESERVED02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_RESERVED02]

//>> SET_[RSB_REGS_MASK_REG_MRG_RESERVED02]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_MRG_RESERVED02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_MRG_RESERVED02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_MRG_RESERVED02]

//>> CLEAR_[RSB_REGS_MASK_REG_MRG_RESERVED02]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_MRG_RESERVED02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_MRG_RESERVED02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_MRG_RESERVED02]

//>> GET_[RSB_REGS_MASK_REG_MRG_RESERVED02]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_MRG_RESERVED02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_MRG_RESERVED02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_RESERVED02]

//>> GET_[RSB_REGS_MASK_REG_MRG_RESERVED02]
static inline bool GET_RSB_REGS_MASK_REG_MRG_RESERVED02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_MRG_RESERVED02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_MRG_RESERVED02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_MRG_RESERVED02]

//>> SET_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> GET_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_IODA_PAGE_ACCESS_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> GET_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_REQUEST_TIMEOUT_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_UNEXPECTED_RESPONSE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]

//>> SET_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]

//>> SET_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]

//>> CLEAR_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]

//>> GET_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]

//>> GET_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]
static inline bool GET_RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_COMMON_FATAL_ERRORS]

//>> SET_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_ECC_CORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> GET_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_ECC_UNCORRECTABLE_ERROR]

//>> SET_[RSB_REGS_MASK_REG_TCE_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_RESERVED01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_RESERVED01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_RESERVED01]

//>> SET_[RSB_REGS_MASK_REG_TCE_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_RESERVED01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_TCE_RESERVED01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_RESERVED01]

//>> SET_[RSB_REGS_MASK_REG_TCE_RESERVED01]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_TCE_RESERVED01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_TCE_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_TCE_RESERVED01]

//>> CLEAR_[RSB_REGS_MASK_REG_TCE_RESERVED01]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_TCE_RESERVED01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_TCE_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_TCE_RESERVED01]

//>> GET_[RSB_REGS_MASK_REG_TCE_RESERVED01]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_TCE_RESERVED01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_TCE_RESERVED01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_RESERVED01]

//>> GET_[RSB_REGS_MASK_REG_TCE_RESERVED01]
static inline bool GET_RSB_REGS_MASK_REG_TCE_RESERVED01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_TCE_RESERVED01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_TCE_RESERVED01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_TCE_RESERVED01]

//>> SET_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_phb Invalid dial access RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> SET_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_phb Invalid dial access RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> SET_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.setBit<RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_phb Invalid dial access RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> CLEAR_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_phb Invalid dial access RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> GET_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_phb Invalid dial access RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]

//>> GET_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]
static inline bool GET_RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_MASK_REG_RW, RSB_REGS_MASK_REG_WO_AND, RSB_REGS_MASK_REG_WO_OR));
#endif
    return i_data.getBit<RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_phb Invalid dial access RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RSB_REGS_MASK_REG_LEM_FIR_INTERNAL_PARITY_ERROR]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
