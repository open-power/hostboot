/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_mss_thermal_init.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 *  @file call_mss_thermal_init.C
 *
 *  @details Run Thermal Sensor Initialization on a set of targets
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

// Standard headers
#include <stdint.h>                      // uint32_t

// Trace
#include <trace/interface.H>             // TRACFCOMP
#include <initservice/isteps_trace.H>    // ISTEPS_TRACE::g_trac_isteps_trace

// Error logging
#include <errl/errlentry.H>              // errlHndl_t
#include <isteps/hwpisteperror.H>        // IStepError, getErrorHandle
#include <istepHelperFuncs.H>            // captureError

// Targeting support
#include <targeting/common/target.H>     // TargetHandleList, getAttr
#include <targeting/common/utilFilter.H> // getAllChips

// Fapi
#include <fapi2/target.H>                // fapi2::TARGET_TYPE_OCMB_CHIP
#include <fapi2/plat_hwp_invoker.H>      // FAPI_INVOKE_HWP

// HWP
#include <exp_mss_thermal_init.H>        // exp_mss_thermal_init
#include <p10_throttle_sync.H>           // p10_throttle_sync

// Misc
#include <chipids.H>                     // POWER_CHIPID::EXPLORER_16

/******************************************************************************/
// namespace shortcuts
/******************************************************************************/
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_14
{
// Forward declare these methods
void p10_call_mss_thermal_init(IStepError & io_iStepError);
void run_proc_throttle_sync(IStepError & io_iStepError);

/**
 * @brief Run Thermal Sensor Initialization followed by Process
 *        Throttle Synchronization on a list of targets
 *
 * @return nullptr if success, else a handle to an error log
 */
void* call_mss_thermal_init (void*)
{
    IStepError  l_iStepError;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              ENTER_MRK"call_mss_thermal_init");

    // Call HWP to thermal initialization on a list of OCMB chips
    p10_call_mss_thermal_init(l_iStepError);

    // Do not continue if the HWP call to thermal initialization encounters an
    // error. Breaking out here will facilitate in the efficiency of the
    // reconfig loop and not cause confusion for the next HWP call.
    if ( !l_iStepError.isNull() )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                   "ERROR: call_mss_thermal_init exited early because "
                   "p10_call_mss_thermal_init had failures" );
    }
    else
    {
        // If no prior error, then call HWP to processor throttle
        // synchronization on a list of PROC chips
        run_proc_throttle_sync(l_iStepError);
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"call_mss_thermal_init, returning %s",
               (l_iStepError.isNull()? "success" : "failure") );

    // end task, returning any errorlogs to IStepDisp
    return l_iStepError.getErrorHandle();
} // call_mss_thermal_init

/**
 * @brief Run Thermal Sensor Initialization on a list Explorer OCMB chips
 *
 * param[in/out] io_iStepError - Container for errors if an error occurs
 */
void p10_call_mss_thermal_init(IStepError & io_iStepError)
{
    errlHndl_t l_err(nullptr);

    // Get a list of all OCMB chips to run Thermal Sensor Initialization on
    TARGETING::TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (const auto & l_ocmbTarget : l_ocmbTargetList)
    {
        // Only run Thermal Sensor Initialization (exp_mss_thermal_init)
        // on Explorer OCMBs.
        uint32_t l_chipId = l_ocmbTarget->getAttr<TARGETING::ATTR_CHIP_ID>();
        if (l_chipId == POWER_CHIPID::EXPLORER_16)
        {
            // Convert the TARGETING::Target into a fapi2::Target by passing
            // l_ocmbTarget into the fapi2::Target constructor
            fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>
                                             l_fapiOcmbTarget ( l_ocmbTarget );

            // Calling exp_mss_thermal_init HWP on Explorer chip,
            // trace out stating so
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                       "Running exp_mss_thermal_init HWP call on Explorer "
                       "chip, target HUID 0x%.8X, chipId 0x%.8X",
                       TARGETING::get_huid(l_ocmbTarget),
                       l_chipId );

            // Call the HWP exp_mss_thermal_init call on each fapi2::Target
            FAPI_INVOKE_HWP(l_err, exp_mss_thermal_init, l_fapiOcmbTarget);

            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                           "ERROR: exp_mss_thermal_init HWP call on Explorer "
                           "chip, target HUID 0x%08x, chipId 0x%.8X failed."
                           TRACE_ERR_FMT,
                           get_huid(l_ocmbTarget),
                           l_chipId,
                           TRACE_ERR_ARGS(l_err) );

                // We don't want to fail the IPL due to problems setting
                //  up the temperature sensors on the DIMM, so just commit
                //  the log here.
                errlCommit(l_err, ISTEP_COMP_ID);
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                           "SUCCESS: exp_mss_thermal_init HWP on Explorer "
                           "chip, target HUID 0x%.8X, chipId 0x%.8X",
                           TARGETING::get_huid(l_ocmbTarget),
                           l_chipId );
            }
        } // end if (l_chipId == POWER_CHIPID::EXPLORER_16)
        else
        {
            // Non-Explorer chip, a NOOP operation, trace out stating so
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                       "Skipping call to exp_mss_thermal_init HWP on target "
                       "HUID 0x%.8X, chipId 0x%.8X is not an Explorer OCMB",
                       TARGETING::get_huid(l_ocmbTarget),
                       l_chipId );
        }
    } // end for (const auto & l_ocmbTarget : l_ocmbTargetList)
} // p10_call_mss_thermal_init


/**
 * @brief Run Processor Throttle Synchronization on all functional
 *        Processor Chip targets
 *
 * param[in/out] io_iStepError - Container for errors if an error occurs
 *
 */
void run_proc_throttle_sync(IStepError & io_iStepError)
{
    errlHndl_t  l_err(nullptr);

    // Get a list of all processors to run Throttle Synchronization on
    TARGETING::TargetHandleList l_procChips;
    getAllChips( l_procChips, TARGETING::TYPE_PROC );

    for (const auto & l_procChip: l_procChips)
    {
        // Convert the TARGETING::Target into a fapi2::Target by passing
        // l_procChip into the fapi2::Target constructor
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                           l_fapiProcTarget(l_procChip);

        // Calling p10_throttle_sync HWP on PROC chip, trace out stating so
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                   "Running p10_throttle_sync HWP on PROC target HUID 0x%.8X",
                   TARGETING::get_huid(l_procChip) );

        // Call the HWP p10_throttle_sync call on each fapi2::Target
        FAPI_INVOKE_HWP( l_err, p10_throttle_sync, l_fapiProcTarget );

        if (l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                       "ERROR: p10_throttle_sync HWP call on PROC target "
                       "HUID 0x%08x failed."
                       TRACE_ERR_FMT,
                       get_huid(l_procChip),
                       TRACE_ERR_ARGS(l_err) );

            // Capture error, commit and continue, do not break out here.
            // Continue here and consolidate all the errors that might
            // occur in a batch before bailing. This will facilitate in the
            // efficiency of the reconfig loop.
            captureError(l_err, io_iStepError, HWPF_COMP_ID, l_procChip);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                       "SUCCESS : p10_throttle_sync HWP call on "
                       "PROC target HUID 0x%08x",
                       TARGETING::get_huid(l_procChip) );
        }
    }
} // run_proc_throttle_sync

};  // namespace ISTEP_14

