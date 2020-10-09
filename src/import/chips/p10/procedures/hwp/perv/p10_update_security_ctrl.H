/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_update_security_ctrl.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
//------------------------------------------------------------------------------
/// @file  p10_update_security_ctrl.H
///
/// @brief To set SUL(Secure Update Lock) bit to lock down SAB + SBE SEEPROM and to set TDP(TPM Deconfig Protect) Bit
///     Decision to set SUL is based on if Chip is in Secure mode(SAB bit is 1)
///     Decision to set TDP is based on an attribute : ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM
///     Decision to lock Abus mailboxes is based on the input option
///     All three bits are set if SAB bit is set or if security is forced via input option
///
//------------------------------------------------------------------------------
// *HWP HW Owner        : Santosh Balasubramanian <sbalasub@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------

#ifndef P10_UPDATE_SECURITY_CTRL_H_
#define P10_UPDATE_SECURITY_CTRL_H_


#include <fapi2.H>


typedef fapi2::ReturnCode (*p10_update_security_ctrl_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        bool );

///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     i_force_security  Forces setting of SUL and TDP (if attribute is set)
/// @param[in]     i_lock_sec_mailboxes Forces locking of Abus security mailboxes
///                (only if security is asserted on the machine).
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p10_update_security_ctrl(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
            bool i_force_security = false,
            bool i_lock_sec_mailboxes = false);
}

#endif
