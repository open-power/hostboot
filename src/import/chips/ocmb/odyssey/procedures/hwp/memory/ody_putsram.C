/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_putsram.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
///
/// @file ody_putsram.C
/// @brief Write data to Odyssey SRAM
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: HB, Cronus, SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_putsram.H>
#include <ody_putsram_io_ppe.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_putsram(const fapi2::Target < fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              const uint64_t i_offset,
                              const uint32_t i_bytes,
                              const uint8_t* i_data)
{
    FAPI_DBG("Start");
    FAPI_DBG("ody_putsram: i_offset [0x%.8X%.8X], i_bytes %u.",
             ((i_offset >> 32) & 0xFFFFFFFF), (i_offset & 0xFFFFFFFF), i_bytes);

    // For now, only write IO PPE SRAM
    FAPI_EXEC_HWP(fapi2::current_err,
                  ody_putsram_io_ppe,
                  i_target,
                  i_offset,
                  i_bytes,
                  i_data);

    FAPI_DBG("End");
    return fapi2::current_err;
}
