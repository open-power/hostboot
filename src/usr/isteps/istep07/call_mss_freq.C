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

#ifdef CONFIG_AXONE
/**
  * @brief Look at all FREQ_OMI_MHZ attribute on all processors, make sure
  *        they are the same and return the value.
  * @param[out] o_omiFreq  the frequency of the OMI link between proc and ocmbs
  * @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
  *
  * @note returns error if all OMIs do not have matching frequency set
  */
errlHndl_t getOmiFreq(TARGETING::ATTR_FREQ_OMI_MHZ_type & o_omiFreq);
#endif

//
//  Wrapper function to call mss_freq
//
void*    call_mss_freq( void *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;

    #if (defined CONFIG_SECUREBOOT && ! defined CONFIG_AXONE)
    bool l_isMemdLoaded = false;
    #endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq entry" );

    do
    {
        #if (defined CONFIG_SECUREBOOT && ! defined CONFIG_AXONE)
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

        uint32_t l_originalNestFreq = Util::getBootNestFreq();

        // Omi Freq is only used in P9a and beyond, to limit #ifdef
        // craziness below just leave it at 0 so it never changes
        uint32_t l_originalOmiFreq = 0;
#ifdef CONFIG_AXONE
        l_err = getOmiFreq(l_originalOmiFreq);
        if(l_err)
        {
            l_StepError.addErrorDetails( l_err );
            errlCommit( l_err, ISTEP_COMP_ID );
            break;
        }
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
            TARGETING::TargetHandleList l_procTargetList;
            getAllChips(l_procTargetList, TYPE_PROC);
            for (const auto & l_proc_target : l_procTargetList)
            {
                //  call the HWP with each target ( if parallel, spin off a task )
                fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target(l_proc_target);
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "START : running p9a_mss_freq_system HWP on target 0x%.08X", TARGETING::get_huid(l_proc_target));;

                FAPI_INVOKE_HWP(l_err, p9a_mss_freq_system, l_proc_target);
                //  process return code.
                if ( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR:  p9a_mss_freq_system HWP while running on mc target 0x%.08X", TARGETING::get_huid(l_proc_target));;

                    ERRORLOG::ErrlUserDetailsTarget(l_proc_target).addToLog(l_err);

                    // Create IStep error log and cross reference to error that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error, but continue to next MC target
                    errlCommit( l_err, ISTEP_COMP_ID );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  p9a_mss_freq_system HWP on target 0x%.08X", TARGETING::get_huid(l_proc_target));;
                }
            }
        }
#endif

        if(l_StepError.getErrorHandle() != NULL)
        {
            // If we have encountered an error, bail out now
            break;
        }

        // Get latest MC_SYNC_MODE and FREQ_PB_MHZ
        uint8_t l_mcSyncMode = l_masterProc->getAttr<TARGETING::ATTR_MC_SYNC_MODE>();
        uint32_t l_newOmiFreq = 0;

        uint32_t l_newNestFreq = l_sys->getAttr<TARGETING::ATTR_FREQ_PB_MHZ>();
#ifdef CONFIG_AXONE
        l_err = getOmiFreq(l_newOmiFreq);
        if(l_err)
        {
            l_StepError.addErrorDetails( l_err );
            errlCommit( l_err, ISTEP_COMP_ID );
            break;
        }
#endif

        //Trigger sbe update if the nest frequency changed.
        if(    (l_newNestFreq != l_originalNestFreq)
            || (l_mcSyncMode  != l_bootSyncMode)
            || (l_newOmiFreq  != l_originalOmiFreq)
          )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "The nest frequency or sync mode changed!"
                  " Original Nest: %d New Nest: %d"
                  " Original syncMode: %d New syncMode: %d"
                  " Original Omi : %d New Omi : %d"
                  , l_originalNestFreq, l_newNestFreq, l_bootSyncMode, l_mcSyncMode
                  , l_originalOmiFreq, l_newOmiFreq
                  );
            if(l_sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>() == true)
            {

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Error: SBE update detected in MPIPL");

                // It is highly unlikely nest frequency will change
                // in Axone systems but OMI freq might. Its is impossible
                // for OMI freq to change in Nimbus/Cumulus systems. So
                // we will display Nest freq in error for Nimbus/Cumulus and
                // display OMI freq for Axone.

                /*@
                * @errortype
                * @moduleid          MOD_SBE_PERFORM_UPDATE_CHECK
                * @reasoncode        RC_SBE_UPDATE_IN_MPIPL
                * @userdata1[0:31]   original mc sync mode
                * @userdata1[32:63]  new mc sync mode
                * @userdata2[0:31]   original (nest p9 | omi p9a+) frequency
                * @userdata2[32:63]  new (nest p9 | omi p9a+) frequency
                * @devdesc           SBE cannot be reset during MPIPL
                * @custdesc          Illegal action during boot
                */
                l_err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                              MOD_SBE_PERFORM_UPDATE_CHECK,
                              RC_SBE_UPDATE_IN_MPIPL,
                              TWO_UINT32_TO_UINT64(
                                  TO_UINT32(l_bootSyncMode),
                                  TO_UINT32(l_mcSyncMode)),
#ifndef CONFIG_AXONE
                              TWO_UINT32_TO_UINT64(
                                  l_originalNestFreq,
                                  l_newNestFreq));
#else
                              TWO_UINT32_TO_UINT64(
                                  l_originalOmiFreq,
                                  l_newOmiFreq));
#endif
               l_err->collectTrace("ISTEPS_TRACE");

                l_StepError.addErrorDetails( l_err );
                errlCommit( l_err, ISTEP_COMP_ID );
            }
            else
            {
                TARGETING::setFrequencyAttributes(l_sys,
                                                  l_newNestFreq);
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

    } while(0);

    #if (defined CONFIG_SECUREBOOT && ! defined CONFIG_AXONE)
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

#ifdef CONFIG_AXONE
errlHndl_t getOmiFreq(TARGETING::ATTR_FREQ_OMI_MHZ_type & o_omiFreq)
{
    errlHndl_t l_err = nullptr;
    TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC);

    assert( l_procTargetList.size() > 0, "getOmiFreq: Expected at least one functional processor");

    o_omiFreq = l_procTargetList[0]->getAttr<TARGETING::ATTR_FREQ_OMI_MHZ>();
    // Until we are told we need to support individual processor frequency
    // assert that all of the processors have the same values
    for(uint8_t i = 1; i < l_procTargetList.size(); i++)
    {

        TARGETING::ATTR_FREQ_OMI_MHZ_type l_tmpFreq =
              l_procTargetList[i]->getAttr<TARGETING::ATTR_FREQ_OMI_MHZ>();

        if(o_omiFreq != l_tmpFreq)
        {
            /*@
            * @errortype         ERRL_SEV_UNRECOVERABLE
            * @moduleid          MOD_GET_OMI_FREQ
            * @reasoncode        RC_OMI_FREQ_MISMATCH
            * @userdata1[0:31]   First OMI freq found
            * @userdata1[32:63]  Mismatched OMI freq found
            * @userdata2[0:31]   Huid of first proc found
            * @userdata2[32:63]  Huid of proc w/ mismatched OMI freq
            * @devdesc           Processor have mismatch OMI freq
            * @custdesc          Invalid processor frequency settings
            */
            l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                          MOD_GET_OMI_FREQ,
                          RC_OMI_FREQ_MISMATCH,
                          TWO_UINT32_TO_UINT64(
                              TO_UINT32(o_omiFreq),
                              TO_UINT32(l_tmpFreq)),
                          TWO_UINT32_TO_UINT64(
                              get_huid(l_procTargetList[0]),
                              get_huid(l_procTargetList[i])),
                          ErrlEntry::ADD_SW_CALLOUT);

            break;
        }
    }

    return l_err;
}
#endif

};   // end namespace
