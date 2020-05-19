/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00003.H $         */
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

#ifndef __PROC_REG00003_H_
#define __PROC_REG00003_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]

//>> PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]

//>> PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]

//>> PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]

//>> PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]

//>> PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]


//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
