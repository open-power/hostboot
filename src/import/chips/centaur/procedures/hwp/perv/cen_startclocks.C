/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_startclocks.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

/// @file cen_startclocks.C
/// @brief Centaur start clocks (FAPI2)
///
/// General Description:
///   - Drop fences and tholds, start nest/mem clocks
///
/// Procedure Prereq:  TP chiplet must be initialized
//
/// @author Peng Fei GOU <shgoupf@cn.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_startclocks.H>
#include <cen_common_funcs.H>
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fixes.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode
cen_startclocks(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_INF("Start");
    fapi2::buffer<uint32_t> reg_data_32 = 0;

    FAPI_DBG("Starting NEST clocks");
    FAPI_TRY(cen_startclocks_module(i_target, SCAN_CHIPLET_NEST),
             "Error from cen_startclocks_module (NEST)");

    FAPI_DBG("MBOX GP4 Reg: Set bit(2) to set MemReset Stability Control.");
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_FSIGP4, reg_data_32),
             "Error from getCfamRegister (CEN_FSIGP4)");
    reg_data_32.setBit<2>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSIGP4, reg_data_32),
             "Error from putCfamRegister (CEN_FSIGP4)");

    FAPI_DBG("MBOX GP4 Reg: Set bit(4) to release D3PHY PLL Reset Control.");
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_FSIGP4, reg_data_32),
             "Error from getCfamRegister (CEN_FSIGP4)");
    reg_data_32.setBit<4>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSIGP4, reg_data_32),
             "Error from putCfamRegister (CEN_FSIGP4)");

    FAPI_DBG("MBOX GP4 Reg: Set bits(22-23,28-30) to enable drivers and receivers.");
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_FSIGP4, reg_data_32),
             "Error from getCfamRegister (CEN_FSIGP4)");
    reg_data_32.setBit<22, 2>().setBit<28, 3>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSIGP4, reg_data_32),
             "Error from putCfamRegister (CEN_FSIGP4)");

    FAPI_DBG("Starting MEM clocks");
    FAPI_TRY(cen_startclocks_module(i_target, SCAN_CHIPLET_MEM),
             "Error from cen_startclocks_module (MEM)");

fapi_try_exit:
    FAPI_DBG("cen_startclocks End");
    return fapi2::current_err;
}

