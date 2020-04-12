/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_ppe_common.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include <fapi2.H>


#ifndef __P10_PPE_COMMOM_H__
#define __P10_PPE_COMMOM_H__

const static uint64_t sbe_base_address = 0xE0000;

// @sakorrap: Duplcates, as these are already declared in p10_ppe_util
//
//// XSR defines
//enum PPE_XSR_DEFS
//{
//    PPE_XSR_HALTED_STATE         = 0,
//    PPE_XSR_HALT_CONDITION_START = 1,
//    PPE_XSR_HALT_CONDITION_LEN   = 3,
//    PPE_XSR_XCR_CMD_HALT         = 1,
//    PPE_XSR_WDT_HALT             = 2,
//    PPE_XSR_UMI_HALT             = 3,
//    PPE_XSR_DEBUG_HALT           = 4,
//    PPE_XSR_DBCR_HALT            = 5,
//    PPE_XSR_INPUT_HALT           = 6,
//    PPE_XSR_HW_FAILURE           = 7
//};
//
//// XCR defines
//enum PPE_XCR_DEFS
//{
//    PPE_XCR_CMD_START           = 1,
//    PPE_XCR_CMD_LEN             = 3,
//
//    PPE_XCR_CLEAR_DEBUG_STATUS  = 0,
//    PPE_XCR_HALT                = 1,
//    PPE_XCR_RESUME              = 2,
//    PPE_XCR_SINGLE_STEP         = 3,
//    PPE_XCR_TOGGLE_XSR_TRH      = 4,
//    PPE_XCR_SOFT_RESET          = 5,
//    PPE_XCR_HARD_RESET          = 6,
//    PPE_XCR_FORCE_HALT          = 7
//};

fapi2::ReturnCode backup_gprs_sprs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    fapi2::buffer<uint32_t>& l_gpr0_save,
    fapi2::buffer<uint32_t>& l_gpr1_save,
    fapi2::buffer<uint32_t>& l_gpr9_save,
    fapi2::buffer<uint64_t>& l_sprg0_save);


fapi2::ReturnCode restore_gprs_sprs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    fapi2::buffer<uint32_t> l_gpr0_save,
    fapi2::buffer<uint32_t> l_gpr1_save,
    fapi2::buffer<uint32_t> l_gpr9_save,
    fapi2::buffer<uint64_t> l_sprg0_save);


fapi2::ReturnCode LocalRegRead(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint16_t i_sbe_local_address,
    fapi2::buffer<uint64_t>& o_data);

fapi2::ReturnCode pollHaltStateDone(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address);


fapi2::ReturnCode haltDone(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_sbe_base_address);

fapi2::ReturnCode RAMReadDone(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_sbe_base_address,
    const fapi2::buffer<uint64_t> i_instruction,
    fapi2::buffer<uint32_t>& o_data);



#endif
