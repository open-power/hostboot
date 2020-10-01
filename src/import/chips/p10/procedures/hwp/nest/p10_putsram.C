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
#include <p10_qme_sram_access.H>
#include <p10_pm_ocb_indir_access.H>
#include <p10_iop_xram_utils.H>
#include <p10_write_xram.H>
#include <p10_pm_ocb_indir_setup_linear.H>
#include <p10_pm_ocb_indir_setup_circular.H>

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
    FAPI_DBG("p10_putsram: PervChipletId 0x%.8X, Multicast %d, i_mode 0x%.2X",
             i_pervChipletId, i_multicast, i_mode);
    FAPI_DBG("p10_putsram: i_offset [0x%.8X%.8X], i_bytes %u.",
             ((i_offset >> 32) & 0xFFFFFFFF), (i_offset & 0xFFFFFFFF), i_bytes);

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
        auto l_target_mcast = i_target.getMulticast<fapi2::TARGET_TYPE_EQ>(fapi2::MCGROUP_GOOD_EQ);
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets =
                    (i_multicast) ?
                    (l_target_mcast.getChildren<fapi2::TARGET_TYPE_EQ>()) :
                    (i_target.getChildren<fapi2::TARGET_TYPE_EQ>());

        for (const auto& l_target_ucast : l_eqChiplets)
        {
            // Found a functional EQ target for either unicast or multicast.
            // If unicast, make sure this EQ's chipletID matches the input chiplet ID
            // Else (multicast), write to this functional EQ target as input chiplet ID is irrelevant.
            if ( (l_target_ucast.getChipletNumber() == i_pervChipletId) ||
                 (i_multicast == true) )
            {
                fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST > l_target;

                if (i_multicast)
                {
                    l_target = l_target_mcast;
                }
                else
                {
                    l_target = l_target_ucast;
                }

                uint32_t l_bytesWritten = 0;
                FAPI_TRY(p10_qme_sram_access_bytes(
                             l_target,
                             static_cast<uint32_t>(i_offset),
                             i_bytes,
                             qmesram::PUT,
                             i_data,
                             l_bytesWritten));
                FAPI_DBG("p10_getsram: p10_qme_sram_access_bytes - Bytes written %u", l_bytesWritten);
                goto fapi_try_exit;
            }
        }
    }
    else if ( (i_pervChipletId >= PCI0_PERV_CHIPLET_ID) && (i_pervChipletId <= PCI1_PERV_CHIPLET_ID) )
    {
        // Writing IOP XRAM
        auto l_target_mcast = i_target.getMulticast<fapi2::TARGET_TYPE_PEC>(fapi2::MCGROUP_GOOD_PCI);
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_PEC>> l_pecChiplets =
                    (i_multicast) ?
                    (l_target_mcast.getChildren<fapi2::TARGET_TYPE_PEC>()) :
                    (i_target.getChildren<fapi2::TARGET_TYPE_PEC>());

        for (const auto& l_target_ucast : l_pecChiplets)
        {
            // Found a functional PEC target for either unitcast or multicast.
            // If unicast, make sure this PEC's chipletID matches the input chiplet ID
            // Else (multicast), write to this functional PEC target as input chiplet ID is irrelevant.
            if ( (l_target_ucast.getChipletNumber() == i_pervChipletId) ||
                 (i_multicast == true) )
            {
                fapi2::Target < fapi2::TARGET_TYPE_PEC | fapi2::TARGET_TYPE_MULTICAST > l_target;

                if (i_multicast)
                {
                    l_target = l_target_mcast;
                }
                else
                {
                    l_target = l_target_ucast;
                }

                // Get top number (bit 0) of i_mode
                xramIopTopNum_t l_topNum = XRAM_TOP_0;

                if (i_mode & MODE_PCIE_TOP_BIT_MASK)
                {
                    l_topNum = XRAM_TOP_1;
                }

                // Get PHY number
                xramPhyNum_t l_phyNum = XRAM_PHY_0;

                if (i_mode & MODE_PCIE_PHY_BIT_MASK)
                {
                    l_phyNum = XRAM_PHY_1;
                }

                // Call OCC SRAM write HWP here
                FAPI_EXEC_HWP(fapi2::current_err,
                              p10_write_xram,
                              l_target,
                              i_offset,
                              i_bytes,
                              l_topNum,
                              l_phyNum,
                              i_data);
                goto fapi_try_exit;
            }
        }
    }
    else
    {
        // Validate OCC mode (bits 0:1 of i_mode)
        uint8_t l_occMode = (i_mode >> MODE_OCC_ACCESS_MODE_BIT_SHIFT) & 0x3;
        FAPI_ASSERT( (l_occMode >= OCB_MODE_LOWER_LIMIT) &&
                     (l_occMode <= OCB_MODE_UPPER_LIMIT),  // Must be 1-3
                     fapi2::P10_INVALID_OCC_ACCESS_MODE_ERROR()
                     .set_PROC_TARGET(i_target)
                     .set_PERV_CHIPLET_ID(i_pervChipletId)
                     .set_OCC_MODE(l_occMode),
                     "Invalid OCC SRAM access mode (%d)", l_occMode);

        // Get OCB channel (bits 2:3 of i_mode)
        ocb::PM_OCB_CHAN_NUM l_ocbChan = getOcbChanNum(i_mode);

        // Setup Circular/Linear depending on mode
        if (l_occMode == OCB_MODE_CIRCULAR)
        {
            FAPI_EXEC_HWP(fapi2::current_err,
                          p10_pm_ocb_indir_setup_circular,
                          i_target,
                          l_ocbChan,
                          ocb::OCB_TYPE_NULL,         // ocb type
                          0,                          // ocb bar
                          0,                          // ocb_q_len
                          ocb::OCB_Q_OUFLOW_NULL,     // ocb_outflow
                          ocb::OCB_Q_ITPTYPE_NULL);   // itp_type
        }
        else
        {
            FAPI_EXEC_HWP(fapi2::current_err,
                          p10_pm_ocb_indir_setup_linear,
                          i_target,
                          l_ocbChan,
                          ocb::OCB_TYPE_LINSTR, // Linear with address inc
                          0);                   // Default to 0
        }

        // Call OCC SRAM write HWP here
        uint32_t l_bytesWritten = 0;
        FAPI_TRY(p10_pm_ocb_indir_access_bytes
                 (i_target,
                  l_ocbChan,
                  ocb::OCB_PUT,
                  i_bytes,
                  true,
                  static_cast<uint32_t>(i_offset),
                  l_bytesWritten,
                  i_data));
        FAPI_DBG("p10_getsram: p10_pm_ocb_indir_access_bytes - Bytes written %u", l_bytesWritten);
        goto fapi_try_exit;
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
