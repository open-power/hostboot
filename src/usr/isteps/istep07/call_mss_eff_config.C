/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_eff_config.C $                */
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
 *  @file call_mss_eff_config.C
 *  Contains the wrapper for mss_eff_config istep
 */

/******************************************************************************/
// Includes
/******************************************************************************/

// STD
#include    <stdint.h>
#include    <stdlib.h>
#include    <map>

// Generated
#include    <attributeenums.H>
#include    <config.h>

// Errors and Tracing Support
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <initservice/isteps_trace.H>
#include    <errl/errlentry.H>
#include    <errl/errludtarget.H>
#include    <isteps/hwpisteperror.H>
#include    <hbotcompid.H>

// Pnor Support
#include    <pnor/pnorif.H>

// Targeting Support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/util.H>
#include    <targeting/targplatutil.H>

// Fapi Support
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

// HWPs
#include    <p10_mss_eff_config.H>
#include    <exp_mss_eff_config_thermal.H>
#include    <p10_mss_eff_grouping.H>

// SMF Support
#include    <secureboot/smf.H>
#include    <secureboot/smf_utils.H>


#include    <nvram/nvram_interface.H>

// isSimicsRunning
#include    <util/misc.H>

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

/**
 * @brief Call p10_mss_eff_grouping HWP on each proc target
 * @param io_istepErr - updated with any HWP errors
 */
void call_mss_eff_grouping(IStepError & io_istepErr)
{
    errlHndl_t l_err = nullptr;

    TargetHandleList l_procsList;
    getAllChips(l_procsList, TYPE_PROC);

    for (const auto & l_cpu_target : l_procsList)
    {
        //  print call to hwp and write HUID of the target(s)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p10_mss_eff_grouping HWP cpu target HUID %.8X",
            get_huid(l_cpu_target));

        // cast OUR type of target to a FAPI type of target.
        const fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_cpu_target
            (l_cpu_target);

        FAPI_INVOKE_HWP(l_err, p10_mss_eff_grouping, l_fapi_cpu_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "ERROR in p10_mss_eff_grouping HWP on target %.8x. "
               TRACE_ERR_FMT,
               get_huid(l_cpu_target),
               TRACE_ERR_ARGS(l_err));

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_cpu_target).addToLog(l_err);
            io_istepErr.addErrorDetails(l_err);
            errlCommit(l_err, ISTEP_COMP_ID);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SUCCESS :  p10_mss_eff_grouping HWP on target %.8x",
                get_huid(l_cpu_target));
        }
    }   // end processor list processing
}

/**
 * @brief Common function to distribute SMF Memory among procs
 *        This will just handle any errors internally, they should not
 *        affect the istep
 */
void distributeSmfMemory()
{
    errlHndl_t l_err = nullptr;

#ifndef CONFIG_FSP_BUILD
    uint64_t l_smfMemAmt = 0;
    const char* l_smfMemAmtStr = nullptr;

    l_err = NVRAM::nvramRead(NVRAM::SMF_MEM_AMT_KEY, l_smfMemAmtStr);
    if(l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK"NVRAM read failed. Will not attempt to distribute any SMF memory.");
        // Do not propagate the error - we don't care if NVRAM read fails
        delete l_err;
        l_err = nullptr;
    }
    else
    {
        // l_smfMemAmtStr will be nullptr if the SMF_MEM_AMT_KEY doesn't exist
        if(l_smfMemAmtStr)
        {
            l_smfMemAmt = strtoul(l_smfMemAmtStr, nullptr, 16);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK"Distributing 0x%.16llx SMF memory among the procs on the system", l_smfMemAmt);
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK"SMF_MEM_AMT_KEY was not found in NVRAM; 0 SMF memory will be distributed.");
        }
    }

    UTIL::assertGetToplevelTarget()->setAttr<ATTR_SMF_MEM_AMT_REQUESTED>(l_smfMemAmt);
#endif

    // The default for ATTR_SMF_MEM_AMT_REQUESTED is 0. For FSP, that means that
    // the following call will disable SMF_CONFIG.
    l_err = SECUREBOOT::SMF::distributeSmfMem();
    if(l_err)
    {
        // Do not propagate or break on error - distributeSmfMem will
        // not return unrecoverable errors.
        errlCommit(l_err, ISTEP_COMP_ID);
    }
}

void* call_mss_eff_config (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config entry" );

    TARGETING::TargetHandleList l_membufTargetList;
    TARGETING::TargetHandleList l_mcsTargetList;
    TARGETING::TargetHandleList l_memportTargetList;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>> l_fapi_ocmb_targets;


    do {
        // Build up this list from memport parents, used in exp_mss_eff_config_thermal
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>> l_fapi2_ocmb_targets;

        // Get all functional MEM_PORT chiplets
        TargetHandleList l_memportTargetList;
        getAllChiplets(l_memportTargetList, TYPE_MEM_PORT);

        for(const auto & l_memport_target: l_memportTargetList)
        {
            // Create a FAPI target representing the MEM_PORT target
            const fapi2::Target <fapi2::TARGET_TYPE_MEM_PORT> l_fapi_memport_target
                (l_memport_target);

            // Grab parent OCMB to add to list consumed later
            const auto l_fapi2_ocmb_target =
                l_fapi_memport_target.getParent<fapi2::TARGET_TYPE_OCMB_CHIP>();
            l_fapi2_ocmb_targets.push_back(l_fapi2_ocmb_target);

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call p10_mss_eff_config HWP on MEM_PORT HUID %.8X",
                      get_huid(l_memport_target));

            FAPI_INVOKE_HWP(l_err, p10_mss_eff_config, l_fapi_memport_target);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR in p10_mss_eff_config HWP on target 0x%.08X. "
                          TRACE_ERR_FMT,
                          get_huid(l_memport_target),
                          TRACE_ERR_ARGS(l_err));

                // Ensure istep error created and has same plid as this error
                ErrlUserDetailsTarget(l_memport_target).addToLog(l_err);
                l_err->collectTrace(EEPROM_COMP_NAME);
                l_err->collectTrace(I2C_COMP_NAME);
                l_StepError.addErrorDetails(l_err);
                errlCommit(l_err, ISTEP_COMP_ID);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS :  p10_mss_eff_config HWP on target 0x%.08X",
                          get_huid(l_memport_target));
            }
        } // end mem_port list

        if(!l_StepError.isNull())
        {
            break;
        }

        if(l_fapi2_ocmb_targets.size() > 0)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call exp_mss_eff_config_thermal HWP on %d OCMB targets",
                      l_fapi2_ocmb_targets.size());

            FAPI_INVOKE_HWP(l_err, exp_mss_eff_config_thermal, l_fapi2_ocmb_targets);
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR in exp_mss_eff_config_thermal HWP. "
                          TRACE_ERR_FMT, TRACE_ERR_ARGS(l_err));

                // Ensure istep error created and has same plid as this error
                l_err->collectTrace(EEPROM_COMP_NAME);
                l_err->collectTrace(I2C_COMP_NAME);
                l_StepError.addErrorDetails(l_err);
                errlCommit(l_err, ISTEP_COMP_ID);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS :  exp_mss_eff_config_thermal HWP");
            }
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "No OCMB targets found, skipping exp_mss_eff_config_thermal HWP");
        }

        // Stack the memory on each chip
        call_mss_eff_grouping(l_StepError);
        if(!l_StepError.isNull())
        {
            break;
        }

        if(SECUREBOOT::SMF::isSmfEnabled())
        {
            // Distribute the SMF Memory (if system appropriate)
            distributeSmfMemory();
        }

        // We need to check for SMF again, since distributeSmfMemory may have
        // disabled it.
        if(SECUREBOOT::SMF::isSmfEnabled())
        {
            // SMF is still enabled, which means that the requested amount of
            // SMF memory may have changed. Rerun the mss_eff_grouping HWP
            // to update the SMF BAR/SMF memory amounts.
            call_mss_eff_grouping(l_StepError);
            if(!l_StepError.isNull())
            {
                break;
            }
        }

    } while(0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config exit" );

    // end task, returning any error logs to IStepDisp
    return l_StepError.getErrorHandle();
}

};   // end namespace
