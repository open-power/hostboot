/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_firmask_save_restore.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file p9_io_obus_firmask_save_restore.H
/// @brief HWP that will give user ability to save off obus firmask into attribute
///        and restore them at a later date.
///
///-----------------------------------------------------------------------------
/// *HWP HW  Owner        : Chris Steffen    <cwsteffen@us.ibm.com>
/// *HWP HW  Backup Owner :
/// *HWP FW Owner         : Christian Geddes <crgeddes@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : HB
///-----------------------------------------------------------------------------

#ifndef _P9_IO_OBUS_FIRMASK_SAVE_RESTORE_H
#define _P9_IO_OBUS_FIRMASK_SAVE_RESTORE_H


//-----------------------------------------------------------------------------
//  System Header Include
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  fapi2 Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>

//-----------------------------------------------------------------------------
//  Definitions
//-----------------------------------------------------------------------------

namespace p9iofirmasksaverestore
{

/**
* @brief Operation Type (Save or Restore)
*/
enum OP_TYPE
{
    SAVE      = 0x0,
    RESTORE   = 0x1,
};

} // namespace p9iofirmasksaverestore

typedef fapi2::ReturnCode (*p9_io_obus_firmask_save_restore_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        const p9iofirmasksaverestore::OP_TYPE);

extern "C"
{
    /**
    *     @brief This hardware procedure takes a processor chip and an OP_TYPE enum in as params.
    *     Depending on what the enum says to do this procedure will either read and store the
    *     values of PU_IOE_PB_IOO_FIR_MASK_REG on the processor and OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REGs
    *     on all of the PROC's child OBUSes, or it will write those scoms based one what we
    *     have stored away previously.
    *
    *     This HWP is expected to be called by Hostboot during IPL time with the SAVE OP_TYPE so
    *     that Hostboot can temporarily apply extra masks during IPL time. This scominit for these
    *     registers is done in istep 10.6 (proc_chiplet_scominit) so this HWP need to be called with
    *     the SAVE paramter after istep 10.6. Once we reach runtime HBRT will call this HWP again with
    *     the RESTORE OP_TYPE and the masks will be restored to their initial values. We expect the
    *     HWP to be called with the RESTORE_OP_TYPE during the HBRT initialzation after the target service
    *     has been initialized in HBRT. There should only be one single HWP call with the RESTORE flag for
    *     every call there is with the SAVE flag.
    *
    *     Note: If this HWP is called with the SAVE op then after we read and store the firmasks
    *           into attributes, we will set additional bits in the mask.
    *
    *        Firs to save and restore
    *        - 0x5013803  = PBIOOFIR MASK
    *        Bits Masked on Save :
    *            PARSER00_ATTN_MASK:28
    *            PARSER01_ATTN_MASK:29
    *            PARSER02_ATTN_MASK:30
    *            PARSER03_ATTN_MASK:31
    *            PARSER04_ATTN_MASK:32
    *            PARSER05_ATTN_MASK:33
    *            PARSER06_ATTN_MASK:34
    *            PARSER07_ATTN_MASK:35
    *            DOB01_ERR_MASK:52
    *            DOB23_ERR_MASK:53
    *            DOB45_ERR_MASK:54
    *            DOB67_ERR_MASK:55
    *            DIB01_ERR_MASK:56
    *            DIB23_ERR_MASK:57
    *            DIB45_ERR_MASK:58
    *            DIB67_ERR_MASK:59
    *        - 0x9010803  = IOOLFIR MASK ( obus 0)
    *        - 0xA010803  = IOOLFIR MASK ( obus 1)
    *        - 0xB010803  = IOOLFIR MASK ( obus 2)
    *        - 0xC010803  = IOOLFIR MASK ( obus 3)
    *        Bits Potentially Masked on Save :
    *            FIR_LINK0_NO_SPARE_MASK:42
    *            FIR_LINK1_NO_SPARE_MASK:43
    *            FIR_LINK0_SPARE_DONE_MASK:44
    *            FIR_LINK1_SPARE_DONE_MASK:45
    *            FIR_LINK0_TOO_MANY_CRC_ERRORS_MASK:46
    *            FIR_LINK1_TOO_MANY_CRC_ERRORS_MASK:47
    *            FIR_LINK0_CORRECTABLE_ARRAY_ERROR_MASK:52
    *            FIR_LINK1_CORRECTABLE_ARRAY_ERROR_MASK:53
    *            FIR_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK:54
    *            FIR_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK:55
    *            FIR_LINK0_TRAINING_FAILED_MASK:56
    *            FIR_LINK1_TRAINING_FAILED_MASK:57
    *            FIR_LINK0_UNRECOVERABLE_ERROR_MASK:58
    *            FIR_LINK1_UNRECOVERABLE_ERROR_MASK:59
    *
    *     @param[in] i_target_chip   Processor target we want to save/restore OBUS firmasks for
    *     @param[in] i_op            OP_TYPE that caller wishes to be performed (SAVE or RESTORE)
    *
    *     @retval    ReturnCode
    */
    fapi2::ReturnCode p9_io_obus_firmask_save_restore(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
            const p9iofirmasksaverestore::OP_TYPE i_op);
} //extern "C"


#endif // _P9_IO_OBUS_FIRMASK_SAVE_RESTORE_H
