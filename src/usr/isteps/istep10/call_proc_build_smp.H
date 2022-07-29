/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_build_smp.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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

/**
 * @brief XSCOM TPM measurements for the secondary chips
 *        1. Validates PCR6 security state values matches between all SBEs
 *        2. Mismatch will cause primary TPM to be poisoned,
 *           indicating we are in an invalid security state
 *        3. Extend all measurements (except PCR6) from secondary/alternate
 *           procs to TPM only if i_extendToTpm = true, but always append to log
 *
 * @param[in] i_primaryProc    - primary sentinal processor target
 * @param[in] i_secondaryProcs - secondary/alternate processor targets
 * @param[in] i_extendToTpm    - extend measurements to the TPM
 * @param[in/out] io_StepError - istep failure errors will be added to this
 */
void retrieveAndExtendSecondaryMeasurements(
                            const TargetHandle_t i_primaryProc,
                            const TargetHandleList& i_secondaryProcs,
                            const bool i_extendToTpm,
                            ISTEP_ERROR::IStepError & io_StepError );

};

#endif