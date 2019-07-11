/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_putsram.C $      */
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

///
/// @file p10_putsram.C
/// @brief Write data to SRAM of PPEs (IO, QME, PCI, or OCC).
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, SBE, Cronus
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_putsram.H>
#include <p10_getputsram_utils.H>
#include <p10_putsram_io_ppe.H>
#include <multicast_group_defs.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
/// NOTE: doxygen in header
fapi2::ReturnCode p10_putsram(const fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                              const uint32_t i_pervChipletId,
                              const bool i_multicast,
                              const uint8_t i_mode,
                              const uint64_t i_offset,
                              const uint32_t i_bytes,
                              uint8_t* i_data)
{
    FAPI_DBG("Start");
    FAPI_DBG("p10_putsram: PervChipletId 0x%.8X, Multicast %d, i_offset %p, i_bytes %u.",
             i_pervChipletId, i_multicast, i_offset, i_bytes);

    if ( (i_pervChipletId >= PAU0_PERV_CHIPLET_ID) && (i_pervChipletId <= PAU3_PERV_CHIPLET_ID) )
    {
        auto l_target_mcast = i_target.getMulticast<fapi2::TARGET_TYPE_PAUC>(fapi2::MCGROUP_GOOD_PAU);

        std::vector<fapi2::Target<fapi2::TARGET_TYPE_PAUC>> l_paucChiplets =
                    (i_multicast) ?
                    (l_target_mcast.getChildren<fapi2::TARGET_TYPE_PAUC>()) :
                    (i_target.getChildren<fapi2::TARGET_TYPE_PAUC>());

        for (const auto& l_target_ucast : l_paucChiplets)
        {
            // Found a functional PAUC target for either unitcast or multicast.
            // If unicast, make sure this PAUC's chipletID matches the input chiplet ID
            // Else (multicast), write to this functional PAUC target as input chiplet ID is irrelevant.
            if ( (l_target_ucast.getChipletNumber() == i_pervChipletId) ||
                 (i_multicast == true) )
            {
                fapi2::Target < fapi2::TARGET_TYPE_PAUC | fapi2::TARGET_TYPE_MULTICAST > l_target;

                if (i_multicast)
                {
                    l_target = l_target_mcast;
                }
                else
                {
                    l_target = l_target_ucast;
                }

                FAPI_EXEC_HWP(fapi2::current_err,
                              p10_putsram_io_ppe,
                              l_target,
                              i_offset,
                              i_bytes,
                              i_data);
                goto fapi_try_exit;
            }

        }
    }
    else if ( (i_pervChipletId >= EQ0_PERV_CHIPLET_ID) && (i_pervChipletId <= EQ7_PERV_CHIPLET_ID) )
    {
        // Call QME PPE SRAM write HWP here
    }
    else if ( (i_pervChipletId >= PCI0_PERV_CHIPLET_ID) && (i_pervChipletId <= PCI1_PERV_CHIPLET_ID) )
    {
        // Call PCI PPE SRAM write HWP here
    }
    else
    {
        // Call OCC SRAM write HWP here
    }

    // Unable to find a valid target for the putsram call
    FAPI_ASSERT(false,
                fapi2::P10_PUTSRAM_TARGET_NOT_FUNCTIONAL_ERROR()
                .set_PROC_TARGET(i_target)
                .set_PERV_CHIPLET_ID(i_pervChipletId)
                .set_MULTICAST(i_multicast)
                .set_MODE(i_mode)
                .set_OFFSET(i_offset)
                .set_BYTES(i_bytes),
                "Requested pervasive chiplet ID not functional on target chip");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
