/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_extract_sbe_rc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// @file  p10_extract_sbe_rc.H
///
/// @brief Check for errors on the SBE, OTPROM, PIBMEM & SEEPROM
//------------------------------------------------------------------------------
// *HWP HW Owner        : Sandeep Korrapati <sakorrap@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Raja Das <rajadas2@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : FSP:HB
//------------------------------------------------------------------------------


#ifndef _P10_EXTRACT_SBE_RC_H_
#define _P10_EXTRACT_SBE_RC_H_
#define btos(x) ((x)?"TRUE":"FALSE")

#include <fapi2.H>
#include <p10_sbe_ext_defs.H>

namespace P10_EXTRACT_SBE_RC
{
enum RETURN_ACTION
{
    ERROR_RECOVERED    = 0, // Something happened with the SBE, we committed the errors involved
    // (as informational), attempted and successfully rebooted the SBE
    RESTART_SBE        = 1, // Trigger external HRESET to reset SBE
    RESTART_CBS        = 2, // Trigger Warm ipl where we don't switch off VSB just toggle start_cbs from FSP
    REIPL_BKP_SEEPROM  = 3, // Run IPL by selecting backup Boot seeprom
    REIPL_UPD_SEEPROM  = 4, // Reload/update of Boot SEEPROM required or deconfig the chip
    REIPL_BKP_MSEEPROM  = 5, // Run IPL by selecting backup Measurement seeprom
    REIPL_UPD_MSEEPROM  = 6, // Reload/update of Measurement SEEPROM required or deconfig the chip
    REIPL_UPD_SPI_CLK_DIV   = 7,  // Update SP code and reipl the system/chip
    NO_RECOVERY_ACTION = 8, // No recovery action possible to correct this error
    REIPL_BKP_BMSEEPROM  = 9, // Run IPL by selecting backup Measurement and  Boot seeproms
    RECONFIG_WITH_CLOCK_GARD = 10, // SBE boot failed due to failure of primary clock. HWP will gard the clock.
    // Need to do reconfig for recovering
};
};

typedef fapi2::ReturnCode (*p10_extract_sbe_rc_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        P10_EXTRACT_SBE_RC::RETURN_ACTION&, bool, bool);

/// @brief called on all chips(master and slaves) to look for any correctable errors on the SBE, OTPROM, PIBMEM & SEEPROM, the soft_error flag tells the procedure not to generate error if no HW issue.
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PROC_CHIP target
/// @param[out]    o_return_action    Returns the action to be taken on an error
/// @param[in]     i_set_sdb          To program the chip to set SDB
/// @param[in]     i_unsecure_mode    To get debug info in a unsecure mode
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p10_extract_sbe_rc(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
                                         P10_EXTRACT_SBE_RC::RETURN_ACTION& o_return_action,
                                         bool i_set_sdb = false,
                                         bool i_unsecure_mode = false);
}

#endif
