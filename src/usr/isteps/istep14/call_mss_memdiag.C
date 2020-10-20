/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_mss_memdiag.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 *  @file call_mss_memdiag.C
 *
 *  @details Run Memory Diagnostics on a set of targets
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
#include <lib/shared/exp_defaults.H>      // mss::DEFAULT_MC_TYPE, needed by gen_mss_unmask.H
#include <lib/mc/exp_port.H>              // needed by gen_mss_port.H
// Using a long path to ensure that the correct file for P10 is used
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H> // mss::unmask::after_memdiags
#include <generic/memory/lib/utils/mc/gen_mss_port.H>    // mss::reset_reorder_queue_settings

// Diagnostics
#include <diag/attn/attn.H>              // ATTN::startService,stopService
#include <diag/mdia/mdia.H>              // MDIA::runStep

// Misc
#include <util/misc.H>                   // Util::isSimicsRunning
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

/**
 * @brief Helper function to run Memory Diagnostics on a list of targets.
 *
 * @param[in]  i_targetList - List of targets to run the memory diagnostics on
 * @param[out] o_iStepError - Contains an error if an error occurs,
 *                            else contains NULL
 */
void __runMemDiags( TargetHandleList i_targetList, IStepError &o_iStepError )
{
    errlHndl_t l_err(nullptr);

    do
    {
        l_err = ATTN::startService();
        if ( nullptr != l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ATTN::startService() failed" );

            // Capture error, commit and continue
            captureError(l_err, o_iStepError, HWPF_COMP_ID);

            break;
        }

        l_err = MDIA::runStep( i_targetList );
        if ( nullptr != l_err )
        {
            // Do NOT break at this point.  Still prudent to stop the service,
            // but DO capture error log
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "MDIA::runStep() failed" );

            // Capture error, commit and continue
            captureError(l_err, o_iStepError, HWPF_COMP_ID);
        }

        // Stop service regardless if MDIA::runStep passes or fails
        l_err = ATTN::stopService();
        if ( nullptr != l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ATTN::stopService() failed" );

            // Capture error, commit and continue
            captureError(l_err, o_iStepError, HWPF_COMP_ID);

            break;
        }

    } while (0);

} // __runMemDiags

/**
 * @brief Run Memory Diagnostics on a list Explorer OCMB chips
 *
 * @return nullptr if success, else a handle to an error log
 */
void* call_mss_memdiag (void*)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              ENTER_MRK"call_mss_memdiag");

    errlHndl_t l_err(nullptr);
    IStepError l_iStepError;

    do
    {
        // Get a list of all OCMB chips to run Memory Diagnostics on
        TargetHandleList l_ocmbTargetList;
        getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

        // Run Memory Diagnostics on Explorer chip list, if not in SIMICS
        if ( Util::isSimicsRunning() == false )
        {
            // Only run Memory Diagnostics (memdiags) on Explorer OCMBs
            TargetHandleList l_explorerChipList;
            for ( const auto & l_ocmbTarget : l_ocmbTargetList )
            {
                uint32_t l_chipId = l_ocmbTarget->getAttr<ATTR_CHIP_ID>();
                if ( l_chipId == POWER_CHIPID::EXPLORER_16 )
                {
                    // Explorer chip found, trace out stating so
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                         "Adding Explorer OCMB, HUID 0x%.8X, chipId 0x%.8X, to "
                         "list of explorer chips to run memory diagnostics on.",
                         TARGETING::get_huid(l_ocmbTarget),
                         l_chipId );

                    l_explorerChipList.push_back(l_ocmbTarget);
                }
                else
                {
                    // Non-Explorer chip, a NOOP operation, trace out stating so
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                         "Skipping call to run memory diagnostics on target "
                         "HUID 0x%.8X, chipId 0x%.8X is not an Explorer OCMB.",
                         TARGETING::get_huid(l_ocmbTarget),
                         l_chipId );
               }
            } // end for for ( const auto & l_ocmbTarget : l_ocmbTargetList )

            if ( l_explorerChipList.size() )
            {
                // Start Memory Diagnostics.
                __runMemDiags( l_explorerChipList, l_iStepError );
                if ( !l_iStepError.isNull() )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                               "ERROR: Call to run memory diagnostics on "
                               "list of Explorer chips failed." );
                    break;
                }
            }
            else
            {
                // Non-Explorer chip, trace out stating so
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, WARN_MRK
                           "Call to run memory diagnostics has been completely "
                           "skipped, no Explorer OCMB chips found." );
            }
        }

        // If running Memory Diagnostics returns with no error, then unmask
        // mainline FIRs.
        for ( auto & l_ocmbTarget : l_ocmbTargetList )
        {
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                             l_fapiOcmbTarget ( l_ocmbTarget );


            // Calling after_memdiags on target, trace out stating so
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                       "Running mss::unmask::after_memdiags HWP call "
                       "on OCMB target HUID 0x%.8X.",
                       TARGETING::get_huid(l_ocmbTarget));

            // Unmask mainline FIRs.
            FAPI_INVOKE_HWP( l_err,
                             mss::unmask::after_memdiags,
                             l_fapiOcmbTarget );

            if (l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                           "ERROR: mss::unmask::after_memdiags HWP call "
                           "on OCMB target HUID 0x%08x failed."
                           TRACE_ERR_FMT,
                           get_huid(l_ocmbTarget),
                           TRACE_ERR_ARGS(l_err) );
                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                           "SUCCESS: mss::unmask::after_memdiags HWP call "
                           "on OCMB target HUID 0x%08x.",
                           get_huid(l_ocmbTarget) );
            }


            // Calling reset_reorder_queue_settings on target, trace out stating so
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                       "Running mss::reset_reorder_queue_settings HWP call "
                       "on OCMB target HUID 0x%.8X.",
                       TARGETING::get_huid(l_ocmbTarget) );

            // Turn off FIFO mode to improve performance.
            FAPI_INVOKE_HWP( l_err,
                             mss::reset_reorder_queue_settings,
                             l_fapiOcmbTarget );
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                           "ERROR: mss::reset_reorder_queue_settings HWP call "
                           "on OCMB target HUID 0x%08x failed."
                           TRACE_ERR_FMT,
                           get_huid(l_ocmbTarget),
                           TRACE_ERR_ARGS(l_err) );
                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                           "SUCCESS: mss::reset_reorder_queue_settings HWP "
                           "call on OCMB target HUID 0x%08x.",
                           get_huid(l_ocmbTarget) );
            }
        } // end for ( auto & l_ocmbTarget : l_ocmbTargetList )

    } while (0);

    if ( nullptr != l_err )
    {
        // Capture error, commit and continue
        captureError( l_err, l_iStepError, HWPF_COMP_ID );
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              EXIT_MRK"call_mss_memdiag, returning %s",
                      (l_iStepError.isNull()? "success" : "failure") );

    // end task, returning any errorlogs to IStepDisp
    return l_iStepError.getErrorHandle();
} // call_mss_memdiag

};  // namespace ISTEP_14
