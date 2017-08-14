/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_volt.C $                      */
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
/**
 *  @file call_mss_volt.C
 *  Contains the wrapper for istep 7.2
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <initservice/initserviceif.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <attributetraits.H>

#include    <config.h>
#include    <util/align.H>
#include    <util/algorithm.H>

//Fapi Support
#include    <fapi2.H>
#include    <target_types.H>
#include    <plat_hwp_invoker.H>
#include    <attributeenums.H>
#include    <istepHelperFuncs.H>

// HWP
#include    <p9_mss_volt.H>
#include    <p9c_mss_volt.H>

namespace   ISTEP_07
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;



void* call_mss_volt( void *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_err = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt entry" );

    // Check that VPP, DDR3 VDDR, and DDR4 VDDR _EFF_CONFIG attributes are set
    bool unused = false;
    set_eff_config_attrs_helper(DEFAULT, unused);

    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "call_mss_volt: %d membuf targets", l_membufTargetList.size());

    if (l_membufTargetList.size() > 0)
    {
        std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> > l_membufFapiTargetsList;

        for(auto & l_membuf_target : l_membufTargetList)
        {
            fapi2::Target <fapi2::TARGET_TYPE_MEMBUF_CHIP>
                        l_membuf_fapi_target (l_membuf_target);

            l_membufFapiTargetsList.push_back( l_membuf_fapi_target );
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Calling p9c_mss_volt on list of membuf targets");

        // p9c_mss_volt.C (vector of centaurs)
        FAPI_INVOKE_HWP(l_err, p9c_mss_volt, l_membufFapiTargetsList);

        // process return code
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  p9c_mss_volt HWP() failed",
                    l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails(l_err);

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  p9c_mss_volt HWP");
        }
    }
    else
    {
        TARGETING::TargetHandleList l_mcsTargetList;
        getAllChiplets(l_mcsTargetList, TYPE_MCS);

        std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> > l_mcsFapiTargetsList;
        for(auto & l_mcs_target : l_mcsTargetList)
        {
            fapi2::Target <fapi2::TARGET_TYPE_MCS>
                l_mcs_fapi_target (l_mcs_target);

            l_mcsFapiTargetsList.push_back( l_mcs_fapi_target );
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Calling p9_mss_volt on list of mcs targets");

        FAPI_INVOKE_HWP(l_err, p9_mss_volt, l_mcsFapiTargetsList);

        // process return code
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  p9_mss_volt HWP() failed",
                l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails(l_err);

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            // No need to compute dynamic values if mss_volt failed

            // Calculate Dynamic Offset voltages for each domain
            TARGETING::Target* pSysTarget = NULL;
            TARGETING::targetService().getTopLevelTarget(pSysTarget);
            assert(
            (pSysTarget != NULL),
            "call_mss_volt: Code bug!  System target was NULL.");

            // only calculate if system supports dynamic voltage
            if (pSysTarget->getAttr< TARGETING::ATTR_SUPPORTS_DYNAMIC_MEM_VOLT >() == 1)
            {
                l_err = computeDynamicMemoryVoltage<
                        TARGETING::ATTR_MSS_VDD_PROGRAM,
                        TARGETING::ATTR_VDD_ID>();
                if(l_err)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                    "VDD domain",
                    l_err->reasonCode());
                    l_StepError.addErrorDetails(l_err);
                    errlCommit(l_err,HWPF_COMP_ID);
                }

                l_err = computeDynamicMemoryVoltage<
                        TARGETING::ATTR_MSS_AVDD_PROGRAM,
                        TARGETING::ATTR_AVDD_ID>();
                if(l_err)
                {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                    "AVDD domain",
                    l_err->reasonCode());
                    l_StepError.addErrorDetails(l_err);
                    errlCommit(l_err,HWPF_COMP_ID);
                }

                l_err = computeDynamicMemoryVoltage<
                        TARGETING::ATTR_MSS_VCS_PROGRAM,
                        TARGETING::ATTR_VCS_ID>();
                if(l_err)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                    "VCS domain",
                    l_err->reasonCode());
                    l_StepError.addErrorDetails(l_err);
                    errlCommit(l_err,HWPF_COMP_ID);
                }

                l_err = computeDynamicMemoryVoltage<
                        TARGETING::ATTR_MSS_VPP_PROGRAM,
                        TARGETING::ATTR_VPP_ID>();
                if(l_err)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                    "VPP domain",
                    l_err->reasonCode());
                    l_StepError.addErrorDetails(l_err);
                    errlCommit(l_err,HWPF_COMP_ID);
                }

                l_err = computeDynamicMemoryVoltage<
                        TARGETING::ATTR_MSS_VDDR_PROGRAM,
                        TARGETING::ATTR_VDDR_ID>();
                if(l_err)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                    "VDDR domain",
                    l_err->reasonCode());
                l_StepError.addErrorDetails(l_err);
                errlCommit(l_err,HWPF_COMP_ID);
                }
            }
        }
    }
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt exit" );

    return l_StepError.getErrorHandle();
}


};
