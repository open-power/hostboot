/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_mss_memdiag.C $                   */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <targeting/common/utilFilter.H>
#include <diag/attn/attn.H>
#include <diag/mdia/mdia.H>
#include <targeting/common/targetservice.H>

#include <plat_hwp_invoker.H>     // for FAPI_INVOKE_HWP
#include <lib/fir/memdiags_fir.H> // for mss::unmask::after_memdiags
#include <lib/mc/port.H>          // for mss::reset_reorder_queue_settings

#if defined(CONFIG_IPLTIME_CHECKSTOP_ANALYSIS) && !defined(__HOSTBOOT_RUNTIME)
  #include <isteps/pm/occCheckstop.H>
#endif

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{

// Helper function to run Memory Diagnostics on a list of targets.
errlHndl_t __runMemDiags( TargetHandleList i_trgtList )
{
    errlHndl_t errl = nullptr;

    do
    {
        errl = ATTN::startService();
        if ( nullptr != errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ATTN::startService() failed" );
            break;
        }

        errl = MDIA::runStep( i_trgtList );
        if ( nullptr != errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "MDIA::runStep() failed" );
            break;
        }

        errl = ATTN::stopService();
        if ( nullptr != errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ATTN::stopService() failed" );
            break;
        }

    } while (0);

    return errl;
}

void* call_mss_memdiag (void* io_pArgs)
{
    errlHndl_t errl = nullptr;

    IStepError l_stepError;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_mss_memdiag entry");

    TARGETING::Target* masterproc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle(masterproc);

#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
    errl = HBOCC::loadHostDataToSRAM(masterproc,
                                        PRDF::ALL_PROC_MEM_MASTER_CORE);
    assert(nullptr == errl,
           "Error returned from call to HBOCC::loadHostDataToSRAM");
#endif

    do
    {
        // Actions vary by processor type.
        ATTR_MODEL_type procType = masterproc->getAttr<ATTR_MODEL>();

        if ( MODEL_NIMBUS == procType )
        {
            TargetHandleList trgtList; getAllChiplets( trgtList, TYPE_MCBIST );

            // Start Memory Diagnostics.
            errl = __runMemDiags( trgtList );
            if ( nullptr != errl ) break;

            for ( auto & tt : trgtList )
            {
                fapi2::Target<fapi2::TARGET_TYPE_MCBIST> ft ( tt );

                // Unmask mainline FIRs.
                FAPI_INVOKE_HWP( errl, mss::unmask::after_memdiags, ft );
                if ( nullptr != errl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "mss::unmask::after_memdiags(0x%08x) failed",
                               get_huid(tt) );
                    break;
                }

                // Turn off FIFO mode to improve performance.
                FAPI_INVOKE_HWP( errl, mss::reset_reorder_queue_settings, ft );
                if ( nullptr != errl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "mss::reset_reorder_queue_settings(0x%08x) "
                               "failed", get_huid(tt) );
                    break;
                }
            }
            if ( nullptr != errl ) break;
        }
        else if ( MODEL_CUMULUS == procType )
        {
            //@FIXME SW405858 -- Remove this once the fix for this defect is in place
            //putscom pu.dmi -all 701090A 44 2 01 -ib -- enable host attentions
            uint64_t scom_data = 0;
            auto scom_size = sizeof(scom_data);
            errl = deviceRead(masterproc, &scom_data, scom_size,
                    DEVICE_SCOM_ADDRESS(0x701090A));
            if (errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_memdiags: unable to read 0x701090A");
                break;
            }

            //clear bit 44
            scom_data &= 0xFFFFFFFFFFF7FFFF;

            //set bit 45
            scom_data |= 0x0000000000040000;

            errl = deviceWrite(masterproc, &scom_data, scom_size,
                    DEVICE_SCOM_ADDRESS(0x701090A));
            if (errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_memdiags: unable to write 0x701090A");
                break;
            }

            //putscom pu.dmi 07010903 FFFF63FFFFFFFFFF -pall -call -- mask CHIFIR bits
            errl = deviceRead(masterproc, &scom_data, scom_size,
                    DEVICE_SCOM_ADDRESS(0x7010903));
            if (errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_memdiags: unable to read 0x7010903");
                break;
            }

            scom_data &= 0xFFFF63FFFFFFFFFF;
            errl = deviceWrite(masterproc, &scom_data, scom_size,
                    DEVICE_SCOM_ADDRESS(0x7010903));
            if (errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_memdiags: unable to write 0x7010903");
                break;
            }

            /**** end of FIXME *****/

            TargetHandleList trgtList; getAllChiplets( trgtList, TYPE_MBA );

            // Start Memory Diagnostics
            errl = __runMemDiags( trgtList );
            if ( nullptr != errl ) break;

            // No need to unmask or turn off FIFO. That is already contained
            // within the other Centaur HWPs.
        }

    } while (0);

    if ( nullptr != errl )
    {
        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails(errl);

        // Commit Error
        errlCommit(errl, HWPF_COMP_ID);
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_mss_memdiag exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
