/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_extract_sbe_rc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file  p9_extract_sbe_rc.H
///
/// @brief Check for errors on the SBE, OTPROM, PIBMEM & SEEPROM
//------------------------------------------------------------------------------
// *HWP HW Owner        : Soma BhanuTej <soma.bhanu@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : FSP:HB
//------------------------------------------------------------------------------


#ifndef _P9_EXTRACT_SBE_RC_H_
#define _P9_EXTRACT_SBE_RC_H_


#include <fapi2.H>

namespace P9_EXTRACT_SBE_RC
{
enum RETURN_ACTION
{
    RESTART_SBE        = 1, // Trigger external HRESET to reset SBE
    RESTART_CBS        = 2, // Trigger Warm ipl where we don't switch off VSB just toggle start_cbs from FSP
    REIPL_BKP_SEEPROM  = 3, // Run IPL by selecting backup seeprom
    RE_IPL             = 4, // Reload/update of SEEPROM required or deconfig the chip
    NO_RECOVERY_ACTION = 5, // No recovery action possible to correct this error
    PPE_RUNNING        = 6  // Return action when PPE is in Running state
};
};

typedef fapi2::ReturnCode (*p9_extract_sbe_rc_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        P9_EXTRACT_SBE_RC::RETURN_ACTION&, bool, bool);

/// @brief called on all chips(master and slaves) to look for any correctable errors on the SBE, OTPROM, PIBMEM & SEEPROM, the soft_error flag tells the procedure not to generate error if no HW issue.
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PROC_CHIP target
/// @param[out]    o_return_action    Returns the action to be taken on an error
/// @param[in]     i_set_sdb          To program the chip to set SDB
/// @param[in]     i_unsecure_mode    To get debug info in a unsecure mode
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p9_extract_sbe_rc(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
                                        P9_EXTRACT_SBE_RC::RETURN_ACTION& o_return_action,
                                        bool i_set_sdb = false,
                                        bool i_unsecure_mode = false);
}

#endif
