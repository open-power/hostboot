/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_iohs_firmask_save_restore.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

/// @file p10_io_iohs_firmask_save_restore.C
/// @brief HWP which saves off IOHS and PAUC FIR masks into attributes
///        and restores them at a later time.
//-----------------------------------------------------------------------------
// *HWP HW  Owner        : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HW  Backup Owner :
// *HWP FW Owner         : Nick Bofferding <bofferdng@us.ibm.com>
// *HWP Team             : IO
// *HWP Level            : 3
// *HWP Consumed by      : HB
// EKB-Mirror-To: hostboot
//-----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
//
// This procedure will provide a way to save and restore IOHS and PAUC FIR
// masks that have to do with cross node bus traffic. During an MPIPL, Hostboot
// will not know about other cross-node IOHS peers and so must mask off IOHS
// peer related FIRs (including some PAUC FIRs) until HBRT when Hostboot is
// aware of the IOHS peer targets.
//
// Procedure Prereq:
//   - PAUC and IOHS SCOM inits are called prior to saving off FIR masks
//   - The save API must be called prior to calling the restore API
// @endverbatim
//-----------------------------------------------------------------------------

/*
During an MPIPL in a multi-node system, Hostboot is unable to detect other
nodes. Because of this Hostboot is unable to set the PEER_TARGET attr
for IOHS targets as their PEERs are on different nodes. Once the system
reaches runtime HBRT will have the information to fill in PEER_TARGET
attributes on the IOHS targets. During the period while Hostboot doesn't
know the IOHS PEER_TARGETs it must mask off additional FIRs so that PRD
doesn't attempt to access the IOHS's peer during a fail. This HWP will
provide a way to save off the FIR masks during MPIPL time, and will apply
additional masks required for the rest of the MPIPL. In addition, this HWP
will provide a way to reapply the original masks after HBRT has filled
in the information for all IOHSes peer targets.
*/

//------------------------------------------------------------------------------
//  Defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <p10_io_iohs_firmask_save_restore.H>
#include <p10_scom_pauc_e.H>
#include <p10_scom_iohs_9.H>
#include <p10_scom_iohs_2.H>
#include <fapi2.H>

// FIRs to save and restore
//
// PowerBus Transaction Layer FIR0 Mask Register
// 10011803 = PB.PTLSCOM10.PB_PTL_FIR_MASK_REG (base register; applies to all
// PAUC)
// 10011804 = PB.PTLSCOM10.PB_PTL_FIR_MASK_REG_WO_AND
// 10011805 = PB.PTLSCOM10.PB_PTL_FIR_MASK_REG_WO_OR
//
//       Register:Bit           IOHS Child (Even unit/Odd unit)
//       ======================================================
//       DOB01_ERR_MASK:7       Even
//       DOB23_ERR_MASK:11      Odd
//       PARSER00_ATTN_MASK:18  Even
//       PARSER01_ATTN_MASK:19  Even
//       PARSER02_ATTN_MASK:20  Odd
//       PARSER03_ATTN_MASK:21  Odd
//       DIB01_ERR_MASK:26      Even
//       DIB23_ERR_MASK:27      Odd
//
// PowerBus DLP FIR Mask Register
// 18011003 = DLP0.DLP.DLP_FIR_MASK_REG (base register; applies to all IOHS)
// 18011004 = DLP0.DLP.DLP_FIR_MASK_REG_WO_AND
// 18011005 = DLP0.DLP.DLP_FIR_MASK_REG_WO_OR
//
//       Register:Bit
//       ===========================================
//       FIR_LINK0_NO_SPARE_MASK:42
//       FIR_LINK1_NO_SPARE_MASK:43
//       FIR_LINK0_SPARE_DONE_MASK:44
//       FIR_LINK1_SPARE_DONE_MASK:45
//       FIR_LINK0_TOO_MANY_CRC_ERRORS_MASK:46
//       FIR_LINK1_TOO_MANY_CRC_ERRORS_MASK:47
//       FIR_LINK0_CORRECTABLE_ARRAY_ERROR_MASK:52
//       FIR_LINK1_CORRECTABLE_ARRAY_ERROR_MASK:53
//       FIR_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK:54
//       FIR_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK:55
//       FIR_LINK0_TRAINING_FAILED_MASK:56
//       FIR_LINK1_TRAINING_FAILED_MASK:57
//       FIR_LINK0_UNRECOVERABLE_ERROR_MASK:58
//       FIR_LINK1_UNRECOVERABLE_ERROR_MASK:59

//-----------------------------------------------------------------------------
//  Definitions
//-----------------------------------------------------------------------------

/**
*        @brief This function reads the FIR mask registers for IOHS (and
*               associated PAUC) targets that are involved in cross-node
*               communication, and saves these values into attributes for
*               later restoration.
*
*        @param[in] i_target_chip   Processor targeted for the IOHS/PAUC FIR
*            mask save operation
*        @param[in] i_iohs_targets  Vector holding the processor's functional
*            child IOHS targets
*
*        @retval ReturnCode
*/
fapi2::ReturnCode p10_io_iohs_firmask_save(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOHS>> i_iohs_targets);

/**
*        @brief This function reads IOHS (and associated PAUC) attributes
*               containing previously saved FIR mask values and writes them to
*               the appropriate FIR mask registers, skipping a given restore
*               operation if an attribute reports a value of 0.
*
*        @param[in] i_target_chip   Processor targets for the IOHS/PAUC FIR
*               mask restore operation
*        @param[in] i_iohs_targets  Vector holding the processor's functional
*               child IOHS targets
*
*        @retval    ReturnCode
*/
fapi2::ReturnCode p10_io_iohs_firmask_restore(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&        i_target_chip,
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOHS>> i_iohs_targets);


fapi2::ReturnCode p10_io_iohs_firmask_save_restore(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const p10iofirmasksaverestore::OP_TYPE             i_op)
{
    FAPI_DBG("p10_io_iohs_firmask_save_restore: Entering...");

    const auto l_iohs_func_vector =
        i_target_chip.getChildren<fapi2::TARGET_TYPE_IOHS>(fapi2::TARGET_STATE_FUNCTIONAL);

    if(i_op == p10iofirmasksaverestore::SAVE)
    {
        FAPI_TRY(p10_io_iohs_firmask_save(i_target_chip, l_iohs_func_vector));
    }
    else
    {
        FAPI_TRY(p10_io_iohs_firmask_restore(i_target_chip, l_iohs_func_vector));
    }

fapi_try_exit:
    FAPI_DBG("p10_io_iohs_firmask_save_restore: Exiting...");
    return fapi2::current_err;
}

fapi2::ReturnCode p10_io_iohs_firmask_save(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&        i_target_chip,
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOHS>> i_iohs_targets)
{
    FAPI_IMP("p10_io_iohs_firmask_save: Entering...");

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PAUC>> processedPaucs;

    // Loop through IOHS targets and save off OLL FIR mask settings
    for(const auto& l_iohsTarget : i_iohs_targets)
    {
        // If IOHS does not have SMPA role, it's not involved in cross-node
        // traffic, so continue
        fapi2::ATTR_IOHS_CONFIG_MODE_Type iohsConfigMode = fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_UNUSED;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE,
                               l_iohsTarget,
                               iohsConfigMode),
                 "Failed to get attribute ATTR_IOHS_CONFIG_MODE");

        if(iohsConfigMode != fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA)
        {
            continue;
        }

        // Determine the PAUC parent, save off the relevant FIR mask into a
        // attribute (but only one time!), then mask off just the FIR bits
        // associated with just this one IOHS (since PAUC is associated with two
        // IOHSes).  The even IOHS (as determined by chip unit position) under a
        // PAUC maps to specific FIR bits, as does the odd IOHS.
        const auto& pauc = l_iohsTarget.getParent<fapi2::TARGET_TYPE_PAUC>();

        fapi2::buffer<uint64_t> l_scomBuffer = 0;
        FAPI_TRY(fapi2::getScom(pauc,
                                scomt::pauc::PB_PTL_FIR_MASK_REG_RW,
                                l_scomBuffer),
                 "getScom of PB_PTL_FIR_MASK_REG_RW failed");

        if(std::find(processedPaucs.begin(), processedPaucs.end(), pauc) == processedPaucs.end())
        {
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAVED_PB_PTL_FIR_MASK,
                                   pauc,
                                   l_scomBuffer),
                     "failed to set attribute ATTR_SAVED_PB_PTL_FIR_MASK");
            processedPaucs.push_back(pauc);
        }

        fapi2::ATTR_CHIP_UNIT_POS_Type iohsUnitPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_iohsTarget,
                               iohsUnitPos),
                 "Failed to get attribute ATTR_CHIP_UNIT_POS");

        l_scomBuffer = 0;

        if((iohsUnitPos % 2) == 0) // Even IOHS
        {
            l_scomBuffer.setBit(scomt::pauc::PB_PTL_FIR_MASK_REG_DOB01_ERR_MASK);
            l_scomBuffer.setBit(scomt::pauc::PB_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK);
            l_scomBuffer.setBit(scomt::pauc::PB_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK);
            l_scomBuffer.setBit(scomt::pauc::PB_PTL_FIR_MASK_REG_DIB01_ERR_MASK);
        }
        else // Odd IOHS
        {
            l_scomBuffer.setBit(scomt::pauc::PB_PTL_FIR_MASK_REG_DOB23_ERR_MASK);
            l_scomBuffer.setBit(scomt::pauc::PB_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK);
            l_scomBuffer.setBit(scomt::pauc::PB_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK);
            l_scomBuffer.setBit(scomt::pauc::PB_PTL_FIR_MASK_REG_DIB23_ERR_MASK);
        }

        FAPI_TRY(fapi2::putScom(pauc,
                                scomt::pauc::PB_PTL_FIR_MASK_REG_WO_OR,
                                l_scomBuffer),
                 "putScom of PB_PTL_FIR_MASK_REG_WO_OR failed");

        // Read the IOHS target's DLP FIR mask and associated action registers.
        // Store the saved value in the ATTR_SAVED_DLP_FIR_MASK attribute, then
        // mask off any FIR bit (of the set of desired FIR bits) that the action
        // registers indicate are recoverable.
        FAPI_TRY(fapi2::getScom(l_iohsTarget,
                                scomt::iohs::DLP_FIR_MASK_REG_RW,
                                l_scomBuffer),
                 "getScom of DLP_FIR_MASK_REG_RW failed");

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAVED_DLP_FIR_MASK,
                               l_iohsTarget,
                               l_scomBuffer),
                 "failed to set attribute ATTR_SAVED_DLP_FIR_MASK");

        fapi2::buffer<uint64_t> l_action0Buffer = 0;
        fapi2::buffer<uint64_t> l_action1Buffer = 0;

        FAPI_TRY(fapi2::getScom(l_iohsTarget,
                                scomt::iohs::DLP_FIR_ACTION0_REG,
                                l_action0Buffer),
                 "getScom of DLP_FIR_ACTION0_REG failed");

        FAPI_TRY(fapi2::getScom(l_iohsTarget,
                                scomt::iohs::DLP_FIR_ACTION1_REG,
                                l_action1Buffer),
                 "getScom of DLP_FIR_ACTION1_REG failed");

        // Apply mask required for Hostboot MPIPL time.  We must mask additional
        // bits during MPIPL time because Hostboot does not know about IOHS
        // peer targets yet. When PRD attempts to handle some of these FIRs
        // it will expect the PEER_TARGET information to be there.

        // Set bits 42-47 if the action register indicates the error as
        // recoverable
        l_scomBuffer = 0;

        for(uint64_t i = scomt::iohs::DLP_FIR_MASK_REG_0_NO_SPARE_MASK;
            i <= scomt::iohs::DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK;
            i++)
        {
            if(l_action0Buffer.getBit(i) == 0 &&
               l_action1Buffer.getBit(i) == 1 )
            {
                l_scomBuffer.setBit(i);
            }
        }

        // Set bits 52-59 if the action register indicates the error as
        // recoverable
        for(uint64_t i = scomt::iohs::DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK;
            i <= scomt::iohs::DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK;
            i++)
        {
            if(l_action0Buffer.getBit(i) == 0 &&
               l_action1Buffer.getBit(i) == 1 )
            {
                l_scomBuffer.setBit(i);
            }
        }

        FAPI_TRY(fapi2::putScom(l_iohsTarget,
                                scomt::iohs::DLP_FIR_MASK_REG_WO_OR,
                                l_scomBuffer),
                 "putScom of DLP_FIR_MASK_REG_WO_OR failed");
    }

fapi_try_exit:
    FAPI_IMP("p10_io_iohs_firmask_save: Exiting...");
    return fapi2::current_err;
}

fapi2::ReturnCode p10_io_iohs_firmask_restore(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOHS>> i_iohs_targets)
{
    FAPI_IMP("p10_io_iohs_firmask_restore: Entering...");

    uint64_t l_restoreValue = 0;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PAUC>> processedPaucs;

    for(const auto& l_iohsTarget : i_iohs_targets)
    {
        // Get parent PAUC
        const auto& pauc = l_iohsTarget.getParent<fapi2::TARGET_TYPE_PAUC>();

        if(std::find(processedPaucs.begin(), processedPaucs.end(), pauc) == processedPaucs.end())
        {
            // Read the previously stored IOHS's parent PAUC's FIR mask value
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAVED_PB_PTL_FIR_MASK,
                                   pauc,
                                   l_restoreValue),
                     "failed to get attribute ATTR_SAVED_PB_PTL_FIR_MASK");

            // If PB_PTL_FIR_MASK is zero that indicates the FIR mask
            // save has not been called yet so we will not restore this FIR mask
            // Note: it was decided to keep these attribute checks separate to
            // allow attribute overrides of these attributes to take effect on
            // HBRT reset
            if(l_restoreValue)
            {
                // Write the stored value back to the SCOM register
                FAPI_TRY(fapi2::putScom(pauc,
                                        scomt::pauc::PB_PTL_FIR_MASK_REG_RW,
                                        l_restoreValue),
                         "putScom of PB_PTL_FIR_MASK_REG_RW failed");

                // Need to write 0 to ATTR_SAVED_PB_PTL_FIR_MASK to ensure
                // HBRT does not re-write the PAUC FIR mask values on reboots
                // or MPIPLs
                l_restoreValue = 0;
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAVED_PB_PTL_FIR_MASK,
                                       pauc,
                                       l_restoreValue),
                         "failed to set attribute ATTR_SAVED_PB_PTL_FIR_MASK");
            }
            else
            {
                FAPI_IMP("p10_io_iohs_firmask_restore: Skipping restore of PB_PTL_FIR_MASK_REG_RW because ATTR_SAVED_PB_PTL_FIR_MASK is 0");
            }

            processedPaucs.push_back(pauc);
        }

        // Read the previously stored IOHS FIR mask value
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAVED_DLP_FIR_MASK,
                               l_iohsTarget,
                               l_restoreValue),
                 "failed to get attribute ATTR_SAVED_DLP_FIR_MASK");

        // If ATTR_SAVED_DLP_FIR_MASK is zero that indicates the FIR mask has
        // not been called yet so we will not restore this FIR mask
        // Note: it was decided to keep these attribute checks separate to allow
        // attribute overrides of these attributes to take effect on HBRT reset
        if(l_restoreValue)
        {
            // Write the stored value back to the scom register
            FAPI_TRY(fapi2::putScom(l_iohsTarget,
                                    scomt::iohs::DLP_FIR_MASK_REG_RW,
                                    l_restoreValue),
                     "putScom of DLP_FIR_MASK_REG_RW failed");

            // Need to write 0 to ATTR_SAVED_DLP_FIR_MASK to ensure
            // HBRT does not re-write the IOHS FIR mask values during reboots
            // or MPIPLs
            l_restoreValue = 0;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAVED_DLP_FIR_MASK,
                                   l_iohsTarget,
                                   l_restoreValue),
                     "failed to set attribute ATTR_SAVED_DLP_FIR_MASK");
        }
        else
        {
            FAPI_IMP("p10_io_iohs_firmask_restore: Skipping restore of DLP_FIR_MASK_REG_RW because ATTR_SAVED_DLP_FIR_MASK is 0");
        }
    }

fapi_try_exit:
    FAPI_IMP("p10_io_iohs_firmask_restore: Exiting...");
    return fapi2::current_err;
}
