/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/utils/stopreg/p9_cpu_reg_restore_instruction.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file   p9_cpu_reg_restore_instruction.H
/// @brief  enumerates all the opcodes used for SPR restoration.
///
// *HWP HW Owner    :  Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :  Prem Shanker Jha <premjha2@in.ibm.com>
// *HWP Team        :  PM
// *HWP Level       :  2
// *HWP Consumed by :  HB:HYP

#ifndef __REG_RESTORE_INSTRUCTION_H
#define __REG_RESTORE_INSTRUCTION_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

namespace stopImageSection
{

/**
 * @brief enumerates opcodes for few instructions.
 */
enum
{
    ORI_OPCODE        = 24,
    RFI_OPCODE        = 19,
    RFI_CONST         = 50,
    ORIS_OPCODE       = 25,
    OPCODE_31         = 31,
    XOR_CONST         = 316,
    RLDIMI_OPCODE     = 30,
    RLDIMI_CONST      = 3,
    MTSPR_CONST1      = 467,
    MTMSRD_CONST1     = 178,
    MR_INT            = 0x7c0a0378,
    BLR_INST          = 0x4e800020,
    MTSPR_BASE_OPCODE = 0x7c0003a6,
    ATTN_OPCODE       = 0x00000200,
};

} // namespace stopImageSection ends

#ifdef __cplusplus
} // extern "C"
#endif

#endif //__REG_RESTORE_INSTRUCTION_H
