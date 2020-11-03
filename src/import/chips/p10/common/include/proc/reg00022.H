/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00022.H $         */
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

#ifndef __PROC_REG00022_H_
#define __PROC_REG00022_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_PTLSCOM10_FP23_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_FP23_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FP23_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM10_FP23_CFG]

//>> GET_[PB_PTLSCOM10_FP23_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_FP23_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FP23_CFG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_FP23_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG]

//>> PUT_[PB_PTLSCOM10_FP23_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_FP23_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_FP23_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM10_FP23_CFG]


//>> SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME,
           PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]

//>> SET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME,
           PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]

//>> GET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME,
           PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_23_CMD_EXP_TIME]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]

//>> SET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]

//>> GET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_2_PRS_SPARE]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_GATHERING]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT,
           PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_FMR_SPARE]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> CLEAR_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]
static inline bool GET_PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]

//>> SET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]

//>> GET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FP23_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE,
           PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_FP23_CFG_3_PRS_SPARE]

//>> PREP_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCUE_OCIBAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCUE_OCIBAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCUE_OCIBAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCUE_OCIBAR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCUE_OCIBAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR]

//>> PUT_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCUE_OCIBAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_OCIBAR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCUE_OCIBAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR]


//>> SET_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_OCIBAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR,
           TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_OCIBAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR,
           TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_OCIBAR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR,
           TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_OCIBAR_BCUE_OCIBAR_ADDR]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
