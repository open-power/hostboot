/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_getsram.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file p10_getsram.C
/// @brief Read data from IO PPE SRAM
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus, SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_getsram.H>
#include <p10_getputsram_utils.H>
#include <p10_getsram_io_ppe.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
/// NOTE: doxygen in header
fapi2::ReturnCode p10_getsram(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_pervChipletId,
    const uint8_t i_mode,
    const uint64_t i_offset,
    const uint32_t i_bytes,
    uint8_t* o_data)
{
    FAPI_DBG("Start");
    FAPI_DBG("p10_getsram: PervChipletId 0x%.8X, i_offset %p, i_bytes %u.",
             i_pervChipletId, i_offset, i_bytes);

    if ( (i_pervChipletId >= PAU0_PERV_CHIPLET_ID) && (i_pervChipletId <= PAU3_PERV_CHIPLET_ID) )
    {
        for (auto& l_pauc : i_target.getChildren<fapi2::TARGET_TYPE_PAUC>())
        {
            if (l_pauc.getChipletNumber() == i_pervChipletId)
            {
                FAPI_EXEC_HWP(fapi2::current_err,
                              p10_getsram_io_ppe,
                              l_pauc,
                              i_offset,
                              i_bytes,
                              o_data);
                goto fapi_try_exit;
            }
        }
    }
    else if ( (i_pervChipletId >= EQ0_PERV_CHIPLET_ID) && (i_pervChipletId <= EQ7_PERV_CHIPLET_ID) )
    {
        // Call QME PPE SRAM read HWP here
    }
    else if ( (i_pervChipletId >= PCI0_PERV_CHIPLET_ID) && (i_pervChipletId <= PCI1_PERV_CHIPLET_ID) )
    {
        // Call PCI PPE SRAM read HWP here
    }
    else
    {
        // Call OCC SRAM read HWP here
    }

    FAPI_ASSERT(false,
                fapi2::P10_GETSRAM_TARGET_NOT_FUNCTIONAL_ERROR()
                .set_PROC_TARGET(i_target)
                .set_PERV_CHIPLET_ID(i_pervChipletId)
                .set_MODE(i_mode)
                .set_OFFSET(i_offset)
                .set_BYTES(i_bytes),
                "Requested pervasive chiplet ID not functional on target chip");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
