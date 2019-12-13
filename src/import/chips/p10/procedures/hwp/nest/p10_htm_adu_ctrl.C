/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_htm_adu_ctrl.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// ----------------------------------------------------------------------------
/// @file  p10_htm_adu_ctrl.C
///
/// @brief Provides ADU control functions that help with HTM collection actions.
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Owner    : Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_htm_adu_ctrl.H>
#include <fapi2_mem_access.H>
#include <p10_putmemproc.H>

///
/// See doxygen in p10_htm_adu_ctrl.H
///
fapi2::ReturnCode aduNHTMControl(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_addr)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    uint32_t l_mem_flags = fapi2::SBE_MEM_ACCESS_FLAGS_SWITCH_MODE
                           | fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC;
    uint32_t l_bytes = 2; // Want a TSIZE of 2 for these htm ctrl commands
    uint8_t l_data[2] = {0, 0}; // give a pointer to real data to prevent any undefined behavior

    FAPI_DBG("Debug data: Target: mem_flags: 0x%08llx, addr: 0x%016llx", l_mem_flags, i_addr);

    FAPI_DBG("Attempting to put pMisc command");
    FAPI_EXEC_HWP(l_rc,
                  p10_putmemproc,
                  i_target,
                  i_addr,
                  l_bytes,
                  l_data,
                  l_mem_flags);


    FAPI_DBG("Exiting");
    return l_rc;
}
