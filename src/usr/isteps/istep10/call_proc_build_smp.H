/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_build_smp.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
/**
 *
 * @file call_proc_build_smp.H
 *
 * Shared constants and functions for call_proc_build_smp.C
 * and call_host_secureboot_lockdown.C
 */
#ifndef __ISTEPS_CALL_PROC_BUILD_SMP_H
#define __ISTEPS_CALL_PROC_BUILD_SMP_H

/******************************************************************************/
// Includes
/******************************************************************************/
#include <p10_scom_proc.H>

using   namespace   TARGETING;

namespace ISTEP_10
{

// TP_LOCAL_FIR[33] - SBE - PPE in halted state
const uint64_t TP_LOCAL_FIR_SBE_PPE_HALTED_STATE =
    1ull << (63 - scomt::proc::TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33);

/**
 * @brief Poison the primary TPM
 *        Common function so only actually poisons once
 */
void poisonPrimaryTpm();

/**
 * @brief Force a processor delayed_deconfig callout in the error log
 * @param[in]     i_proc  processor target to callout
 * @param[in/out] io_err  error log to check/update with callout
 */
void forceProcDelayDeconfigCallout(TargetHandle_t const i_proc,
                                   errlHndl_t& io_err);

};

#endif