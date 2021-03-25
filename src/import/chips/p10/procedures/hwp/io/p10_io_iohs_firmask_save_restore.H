/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_iohs_firmask_save_restore.H $ */
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

/// @file p10_io_iohs_firmask_save_restore.H
/// @brief HWP that allows caller to save off cross-node IOHS
///        (and associated PAUC) FIR masks into attributes for later restoration
///        and mask off cross-node errors during that time.
//-----------------------------------------------------------------------------
// *HWP HW  Owner        : Chris Steffen    <cwsteffen@us.ibm.com>
// *HWP HW  Backup Owner :
// *HWP FW Owner         : Nick Bofferding <bofferdn@us.ibm.com>
// *HWP Team             : IO
// *HWP Level            : 3
// *HWP Consumed by      : HB
// EKB-Mirror-To: hostboot
//-----------------------------------------------------------------------------

#ifndef _P10_IO_IOHS_FIRMASK_SAVE_RESTORE_H
#define _P10_IO_IOHS_FIRMASK_SAVE_RESTORE_H

//------------------------------------------------------------------------------
//  System Header Include
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  fapi2 Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
//  Definitions
//------------------------------------------------------------------------------

namespace p10iofirmasksaverestore
{

/**
* @brief Operation Type (Save or Restore)
*/
enum OP_TYPE
{
    SAVE      = 0x0,
    RESTORE   = 0x1,
};

} // namespace p10iofirmasksaverestore

typedef fapi2::ReturnCode (*p10_io_iohs_firmask_save_restore_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        const p10iofirmasksaverestore::OP_TYPE);

extern "C"
{
    /**
    *     @brief This hardware procedure takes a processor chip and an OP_TYPE
    *     enum as arguments.  IF OP_TYPE is SAVE, the procedure walks every IOHS
    *     in the processor involved in a cross-node bus connection (i.e. an IOHS
    *     whose ATTR_IOHS_CONFIG_MODE attribute is
    *     ENUM_ATTR_IOHS_CONFIG_MODE_SMPA) and saves off its DLP_FIR_MASK_REG
    *     and its parent PAUC's PB_PTL_FIR_MASK_REG register values into
    *     attributes, then masks off FIR bits in those registers to prevent
    *     escalation of various cross-node bus failures.  If OP_TYPE is RESTORE,
    *     the procedure restores attribute values back into the registers from
    *     which they came, thereby restoring the original FIR masks.
    *
    *     Hostboot must call this procedure during MPIPL time with an OP_TYPE of
    *     SAVE in order to suppress cross-node bus errors since during that
    *     time, each nodal Hostboot instance has no visibility to the others.
    *     If PRD were to handle a cross-node bus error, it would not be able to
    *     resolve the other end of the bus and make appropriate callouts.   The
    *     masking must be done as soon as Hostboot has resolved the targets in
    *     the node, i.e. in host_discover_targets.
    *
    *     At runtime after an MPIPL, HBRT must call this HWP again after
    *     initializing targeting (after which targeting has awareness of all
    *     nodes) with the RESTORE OP_TYPE in order to restore the original FIR
    *     mask values, so that PRD will once again process all the cross-node
    *     errors as appropriate. There should only be one single HWP call with
    *     the RESTORE flag for every call invoked with the SAVE flag.
    *
    *     Note: If this HWP is called with the SAVE op then after storing the
    *           FIR masks into attributes, it will mask off additional bits in
    *           the FIRs.
    *
    *     PowerBus Transaction Layer FIR0 Mask Register
    *     10011803 = PB.PTLSCOM10.PB_PTL_FIR_MASK_REG (base register; applies to
    *     all PAUC)
    *     10011804 = PB.PTLSCOM10.PB_PTL_FIR_MASK_REG_WO_AND
    *     10011805 = PB.PTLSCOM10.PB_PTL_FIR_MASK_REG_WO_OR
    *
    *       Register:Bit           IOHS Child (Even unit/Odd unit)
    *       ======================================================
    *       DOB01_ERR_MASK:7       Even
    *       DOB23_ERR_MASK:11      Odd
    *       PARSER00_ATTN_MASK:18  Even
    *       PARSER01_ATTN_MASK:19  Even
    *       PARSER02_ATTN_MASK:20  Odd
    *       PARSER03_ATTN_MASK:21  Odd
    *       DIB01_ERR_MASK:26      Even
    *       DIB23_ERR_MASK:27      Odd
    *
    *     PowerBus DLP FIR Mask Register
    *     18011003 = DLP0.DLP.DLP_FIR_MASK_REG (base register; applies to all
    *     IOHS)
    *     18011004 = DLP0.DLP.DLP_FIR_MASK_REG_WO_AND
    *     18011005 = DLP0.DLP.DLP_FIR_MASK_REG_WO_OR
    *
    *       Register:Bit
    *       ===========================================
    *       FIR_LINK0_NO_SPARE_MASK:42
    *       FIR_LINK1_NO_SPARE_MASK:43
    *       FIR_LINK0_SPARE_DONE_MASK:44
    *       FIR_LINK1_SPARE_DONE_MASK:45
    *       FIR_LINK0_TOO_MANY_CRC_ERRORS_MASK:46
    *       FIR_LINK1_TOO_MANY_CRC_ERRORS_MASK:47
    *       FIR_LINK0_CORRECTABLE_ARRAY_ERROR_MASK:52
    *       FIR_LINK1_CORRECTABLE_ARRAY_ERROR_MASK:53
    *       FIR_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK:54
    *       FIR_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK:55
    *       FIR_LINK0_TRAINING_FAILED_MASK:56
    *       FIR_LINK1_TRAINING_FAILED_MASK:57
    *       FIR_LINK0_UNRECOVERABLE_ERROR_MASK:58
    *       FIR_LINK1_UNRECOVERABLE_ERROR_MASK:59
    *
    *     @param[in] i_target_chip   Processor targeted for the FIR
    *         mask save/restore operation
    *     @param[in] i_op            OP_TYPE that caller wishes to perform
    *        (SAVE or RESTORE)
    *
    *     @retval ReturnCode
    */
    fapi2::ReturnCode p10_io_iohs_firmask_save_restore(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
            const p10iofirmasksaverestore::OP_TYPE i_op);
} //extern "C"


#endif // _P10_IO_IOHS_FIRMASK_SAVE_RESTORE_H
