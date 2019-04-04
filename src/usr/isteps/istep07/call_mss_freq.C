/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_freq.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
 *  @file call_mss_freq.C
 *  Contains the wrapper for istep 7.3
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <util/utilmbox_scratch.H>


// SBE
#include    <sbeif.H>

// HWP
#include    <p9_mss_freq.H>
#include    <p9_mss_freq_system.H>
#include    <p9c_mss_freq.H>

#ifdef CONFIG_AXONE
#include    <p9a_mss_freq.H>
#include    <p9a_mss_freq_system.H>
#endif

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//
//  Wrapper function to call mss_freq
//
void*    call_mss_freq( void *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_err = NULL;

    #ifdef CONFIG_SECUREBOOT
    bool l_isMemdLoaded = false;
    #endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq entry" );

    do
    {
        #ifdef CONFIG_SECUREBOOT
        // Load MEMD so that vpd_supported_freqs can use it.
        l_err = loadSecureSection(PNOR::MEMD);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK "Failed in call to loadSecureSection for section "
                "PNOR:MEMD");

            // Create istep error and link it to PLID of original error
            l_StepError.addErrorDetails(l_err);
            errlCommit(l_err, ISTEP_COMP_ID);
            break;
        }
        else
        {
            l_isMemdLoaded = true;
        }
        #endif

        ATTR_MODEL_type l_procModel = TARGETING::targetService().getProcessorModel();

        if(l_procModel == TARGETING::MODEL_CUMULUS)
        {
            TARGETING::TargetHandleList l_membufTargetList;
            getAllChips(l_membufTargetList, TYPE_MEMBUF);

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq: %d membufs found",
                    l_membufTargetList.size());

            for (const auto & l_membuf_target : l_membufTargetList)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "p9c_mss_freq HWP target HUID %.8x",
                    TARGETING::get_huid(l_membuf_target));

                //  call the HWP with each target
                fapi2::Target <fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapi_membuf_target
                        (l_membuf_target);

                FAPI_INVOKE_HWP(l_err, p9c_mss_freq, l_fapi_membuf_target);

                //  process return code.
                if ( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X:  p9c_mss_freq HWP on target HUID %.8x",
                        l_err->reasonCode(), TARGETING::get_huid(l_membuf_target) );

                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_membuf_target).addToLog( l_err );

                    // Create IStep error log and cross reference to error that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, ISTEP_COMP_ID );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "SUCCESS :  p9c_mss_freq HWP");
                }
            } // end membuf loop
        }
        else if (l_procModel == TARGETING::MODEL_NIMBUS)
        {
            TARGETING::TargetHandleList l_mcsTargetList;
            getAllChiplets(l_mcsTargetList, TYPE_MCS);

            for (const auto & l_mcs_target : l_mcsTargetList)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "p9_mss_freq HWP target HUID %.8x",
                    TARGETING::get_huid(l_mcs_target));

                //  call the HWP with each target   ( if parallel, spin off a task )
                fapi2::Target <fapi2::TARGET_TYPE_MCS> l_fapi_mcs_target
                    (l_mcs_target);

                FAPI_INVOKE_HWP(l_err, p9_mss_freq, l_fapi_mcs_target);

                //  process return code.
                if ( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  p9_mss_freq HWP on target HUID %.8x",
                    l_err->reasonCode(), TARGETING::get_huid(l_mcs_target) );

                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_mcs_target).addToLog( l_err );

                    // Create IStep error log and cross reference to error that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, ISTEP_COMP_ID );

                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS :  p9_mss_freq HWP");
                }
            } // End mcs loop
        }
#ifdef CONFIG_AXONE
        else if(l_procModel == TARGETING::MODEL_AXONE)
        {
            TARGETING::TargetHandleList l_memportTargetList;
            getAllChiplets(l_memportTargetList, TYPE_MEM_PORT);

            for (const auto & l_memport_target : l_memportTargetList)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "p9a_mss_freq HWP target HUID %.8x",
                    TARGETING::get_huid(l_memport_target));

                //  call the HWP with each target   ( if parallel, spin off a task )
                fapi2::Target <fapi2::TARGET_TYPE_MEM_PORT> l_fapi_memport_target
                    (l_memport_target);

                FAPI_INVOKE_HWP(l_err, p9a_mss_freq, l_fapi_memport_target);

                //  process return code.
                if ( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  p9a_mss_freq HWP on target HUID %.8x",
                    l_err->reasonCode(), TARGETING::get_huid(l_memport_target) );

                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_memport_target).addToLog( l_err );

                    // Create IStep error log and cross reference to error that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error, but continue to next mem_port
                    errlCommit( l_err, ISTEP_COMP_ID );

                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS :  p9a_mss_freq HWP");
                }
            }

            if(l_StepError.getErrorHandle() != NULL)
            {
                // If we have encountered an error, bail out now
                break;
            }
        }
#endif

        // PB frequency was set in istep 6 for non MC SYNC mode
        // allow it to change here
        TARGETING::Target * l_sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( l_sys );
        // TODO RTC: 207596 Get nest boot freq for OMIs
        #ifndef CONFIG_AXONE_BRING_UP
        uint32_t l_originalNest = Util::getBootNestFreq();
        #endif

        // Read MC_SYNC_MODE from SBE itself and set the attribute
        uint8_t l_bootSyncMode = 0;
        l_err = SBE::getBootMcSyncMode( l_bootSyncMode );
        if( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Failed getting the boot mc sync mode from the SBE");

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );
            break;
        }

        TARGETING::Target * l_masterProc = nullptr;
        TARGETING::targetService()
            .masterProcChipTargetHandle( l_masterProc );
        l_masterProc->setAttr<TARGETING::ATTR_MC_SYNC_MODE>(l_bootSyncMode);

        if (l_procModel == TARGETING::MODEL_NIMBUS)
        {
            TARGETING::TargetHandleList l_mcbistTargetList;
            getAllChiplets(l_mcbistTargetList, TYPE_MCBIST);
            std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCBIST> > l_fapi2_mcbistTargetList;

            for (const auto & l_mcbist_target : l_mcbistTargetList)
            {
                //  call the HWP with each target   ( if parallel, spin off a task )
                fapi2::Target <fapi2::TARGET_TYPE_MCBIST> l_fapi_mcbist_target(l_mcbist_target);
                l_fapi2_mcbistTargetList.push_back(l_fapi_mcbist_target);
            }

            if(l_fapi2_mcbistTargetList.size() > 0)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "START : running mss_freq_system HWP");

                FAPI_INVOKE_HWP(l_err, p9_mss_freq_system, l_fapi2_mcbistTargetList);

                //  process return code.
                if ( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR : p9_mss_freq_system HWP while running on mcbist targets");

                    // Create IStep error log and cross reference to error that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, ISTEP_COMP_ID );
                    break;

                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  mss_freq_system HWP");
                }
            }
        }
#ifdef CONFIG_AXONE
        else if(l_procModel == TARGETING::MODEL_AXONE)
        {
            TARGETING::TargetHandleList l_mcTargetList;
            getAllChiplets(l_mcTargetList, TYPE_MC);
            for (const auto & l_mc_target : l_mcTargetList)
            {
                //  call the HWP with each target ( if parallel, spin off a task )
                fapi2::Target <fapi2::TARGET_TYPE_MC> l_fapi_mc_target(l_mc_target);
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "START : running p9a_mss_freq_system HWP on target 0x%.08X", TARGETING::get_huid(l_mc_target));;

                FAPI_INVOKE_HWP(l_err, p9a_mss_freq_system, l_fapi_mc_target);
                //  process return code.
                if ( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR:  p9a_mss_freq_system HWP while running on mc target 0x%.08X", TARGETING::get_huid(l_mc_target));;

                    ERRORLOG::ErrlUserDetailsTarget(l_mc_target).addToLog(l_err);

                    // Create IStep error log and cross reference to error that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error, but continue to next MC target
                    errlCommit( l_err, ISTEP_COMP_ID );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  p9a_mss_freq_system HWP on target 0x%.08X", TARGETING::get_huid(l_mc_target));;
                }
            }
        }
#endif

        if(l_StepError.getErrorHandle() != NULL)
        {
            // If we have encountered an error, bail out now
            break;
        }

        // TODO RTC: 207596 Get nest boot freq for OMIs
        #ifndef CONFIG_AXONE_BRING_UP
        // Get latest MC_SYNC_MODE and FREQ_PB_MHZ
        uint8_t l_mcSyncMode = l_masterProc->getAttr<TARGETING::ATTR_MC_SYNC_MODE>();
        uint32_t l_newNest = l_sys->getAttr<TARGETING::ATTR_FREQ_PB_MHZ>();

        //Trigger sbe update if the nest frequency changed.
        if( (l_newNest != l_originalNest) || (l_mcSyncMode != l_bootSyncMode) )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "The nest frequency or sync mode changed!"
                  " Original Nest: %d New Nest: %d"
                  " Original syncMode: %d New syncMode: %d",
                  l_originalNest, l_newNest, l_bootSyncMode, l_mcSyncMode );
            if(l_sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>() == true)
            {

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Error: SBE update detected in MPIPL");

                /*@
                * @errortype
                * @moduleid          MOD_SBE_PERFORM_UPDATE_CHECK
                * @reasoncode        RC_SBE_UPDATE_IN_MPIPL
                * @userdata1[0:31]   original mc sync mode
                * @userdata1[32:63]  new mc sync mode
                * @userdata2[0:31]   original nest frequency
                * @userdata2[32:63]  new nest frequency
                * @devdesc           SBE cannot be reset during MPIPL
                * @custdesc          Illegal action during boot
                */
                l_err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                              MOD_SBE_PERFORM_UPDATE_CHECK,
                              RC_SBE_UPDATE_IN_MPIPL,
                              TWO_UINT32_TO_UINT64(
                                  TO_UINT32(l_bootSyncMode),
                                  TO_UINT32(l_mcSyncMode)),
                              TWO_UINT32_TO_UINT64(
                                  l_originalNest, l_newNest));

                l_StepError.addErrorDetails( l_err );
                errlCommit( l_err, ISTEP_COMP_ID );
            }
            else
            {
                TARGETING::setFrequencyAttributes(l_sys,
                                          l_newNest);
                l_err = SBE::updateProcessorSbeSeeproms();
                if( l_err )
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_mss_freq.C - Error calling updateProcessorSbeSeeproms");

                    // Create IStep error log and cross reference to error
                    // that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, ISTEP_COMP_ID );
                }
            }
        }
        #endif

    } while(0);

    #ifdef CONFIG_SECUREBOOT
    if(l_isMemdLoaded)
    {
        // Should not have any uncommitted errors at this point.
        assert(l_err == NULL, "call_mss_freq - unexpected uncommitted"
                                                                 "error found");

        l_err = unloadSecureSection(PNOR::MEMD);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK "Failed in call to unloadSecureSection for section "
                "PNOR:MEMD");

            // Create istep error and link it to PLID of original error
            l_StepError.addErrorDetails(l_err);
            errlCommit(l_err, ISTEP_COMP_ID);
        }
    }
    #endif

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq exit" );


    return l_StepError.getErrorHandle();
}

};   // end namespace
