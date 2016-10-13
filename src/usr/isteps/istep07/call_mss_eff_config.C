/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_eff_config.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include    <stdint.h>
#include    <map>

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

// HWP
#include    <p9_mss_eff_config.H>
#include    <p9_mss_eff_config_thermal.H>
#include    <p9_mss_eff_grouping.H>

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

errlHndl_t call_mss_eff_grouping(IStepError & io_istepErr)
{
    errlHndl_t l_err = NULL;

    TARGETING::TargetHandleList l_procsList;
    getAllChips(l_procsList, TYPE_PROC);

    for (const auto & l_cpu_target : l_procsList)
    {
        //  print call to hwp and write HUID of the target(s)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p9_mss_eff_grouping HWP cpu target HUID %.8X",
            TARGETING::get_huid(l_cpu_target));

        // cast OUR type of target to a FAPI type of target.
        const fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_cpu_target
            (l_cpu_target);

        FAPI_INVOKE_HWP(l_err, p9_mss_eff_grouping, l_fapi_cpu_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "ERROR 0x%.8X:  p9_mss_eff_grouping HWP on target %.8x",
                l_err->reasonCode(), TARGETING::get_huid(l_cpu_target));

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_cpu_target).addToLog(l_err);
            io_istepErr.addErrorDetails(l_err);
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SUCCESS :  p9_mss_eff_grouping HWP on target %.8x",
                TARGETING::get_huid(l_cpu_target));
        }
    }   // end processor list processing

    return l_err;
}


errlHndl_t call_mss_eff_mb_interleave()
{
    errlHndl_t l_err = NULL;
/* TOOD RTC: 144076 --- cumulus only ---
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (const auto & l_membuf_target : l_membufTargetList)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  Running mss_eff_mb_interleave HWP on HUID %.8X",
                TARGETING::get_huid(l_membuf_target));
        fapi::Target l_membuf_fapi_target(fapi::TARGET_TYPE_MEMBUF_CHIP,
                    (const_cast<TARGETING::Target*>(l_membuf_target)) );
        FAPI_INVOKE_HWP(l_err, mss_eff_mb_interleave, l_membuf_fapi_target);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: mss_eff_mb_interleave HWP returns error",
                      l_err->reasonCode());
            ErrlUserDetailsTarget(l_membuf_target).addToLog(l_err);
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Successfully ran mss_eff_mb_interleave HWP on HUID %.8X",
                      TARGETING::get_huid(l_membuf_target));
        }
    }
*/
    return l_err;
}


//
//  Wrapper function to call mss_eff_config
//
void*    call_mss_eff_config( void *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_err = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config entry" );

    TARGETING::Target* l_sys = NULL;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != NULL );

    // The attribute ATTR_MEM_MIRROR_PLACEMENT_POLICY should already be
    // correctly set by default for all platforms except for sapphire.
    // Don't allow mirroring on sapphire yet @todo-RTC:108314
    //
    //ATTR_PAYLOAD_IN_MIRROR_MEM_type l_mirrored =
    //    l_sys->getAttr<ATTR_PAYLOAD_IN_MIRROR_MEM>();
    //
    //if(l_mirrored && is_sapphire_load())
    //{
    //    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Mirroring is enabled");

    //    uint8_t l_mmPolicy =
    //        fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED;
    //    l_sys->
    //        setAttr<TARGETING::ATTR_MEM_MIRROR_PLACEMENT_POLICY>(l_mmPolicy);
    //}

    // Get all functional MCS chiplets
    TARGETING::TargetHandleList l_mcsTargetList;
    getAllChiplets(l_mcsTargetList, TYPE_MCS);

    // Iterate over all MCS, calling mss_eff_config and mss_eff_config_thermal
    for (const auto & l_mcs_target : l_mcsTargetList)
    {
        // Get the TARGETING::Target pointer and its HUID
        uint32_t l_huid = TARGETING::get_huid(l_mcs_target);

        // Create a FAPI target representing the MCS
        const fapi2::Target <fapi2::TARGET_TYPE_MCS> l_fapi_mcs_target
            (l_mcs_target);

        // Call the mss_eff_config HWP
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p9_mss_eff_config HWP. MCS HUID %.8X", l_huid);
        FAPI_INVOKE_HWP(l_err, p9_mss_eff_config, l_fapi_mcs_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  p9_mss_eff_config HWP ", l_err->reasonCode());

            // Ensure istep error created and has same plid as this error
            ErrlUserDetailsTarget(l_mcs_target).addToLog(l_err);
            l_StepError.addErrorDetails(l_err);
            errlCommit(l_err, HWPF_COMP_ID);
            continue;
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "SUCCESS :  p9_mss_eff_config HWP");
    } // end membuf loop

    std::map<ATTR_VDDR_ID_type,TARGETING::TargetHandleList> l_domainIdGroups;
    TARGETING::TargetHandleList l_mcbistTargetList;
    getAllChiplets(l_mcsTargetList, TYPE_MCBIST);

    // Iterate over all MCBIST, calling mss_eff_config_thermal
    for (const auto & l_mcbist_target : l_mcbistTargetList)
    {
        TARGETING::TargetHandleList l_mcsChildren;
        getChildChiplets(l_mcsChildren,l_mcbist_target, TARGETING::TYPE_MCS);

        ATTR_VDDR_ID_type l_vddr_id = l_mcbist_target->getAttr<ATTR_VDDR_ID>();
        if(l_domainIdGroups.find(l_vddr_id) == l_domainIdGroups.end())
        {
            std::pair<ATTR_VDDR_ID_type, TARGETING::TargetHandleList> tuple(l_vddr_id, l_mcsChildren);
            l_domainIdGroups.insert(tuple);
        }
        else
        {
            l_domainIdGroups[l_vddr_id].insert(l_domainIdGroups[l_vddr_id].end(), l_mcsChildren.begin(), l_mcsChildren.end());
        }
    }

    for (auto & l_tuple : l_domainIdGroups)
    {
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>> l_fapi_mcs_targs;
        for(const auto & l_mcs_target : l_tuple.second)
        {
            // Create a FAPI target representing the MCS
            const fapi2::Target <fapi2::TARGET_TYPE_MCS> l_fapi_mcs_target
            (l_mcs_target);
            l_fapi_mcs_targs.push_back(l_fapi_mcs_target);
        }
        // Call the mss_eff_config_thermal HWP
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "p9_mss_eff_config_thermal HWP. ");
        FAPI_INVOKE_HWP(l_err, p9_mss_eff_config_thermal,l_fapi_mcs_targs);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X:  p9_mss_eff_config_thermal HWP ",
                        l_err->reasonCode());

            // Ensure istep error created and has same plid as this error
            l_StepError.addErrorDetails(l_err);
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS : p9_mss_eff_config_thermal HWP");
        }
    }


    if (l_StepError.isNull())
    {
        // Stack the memory on each chip
        l_err = call_mss_eff_grouping(l_StepError);

        // TODO RTC: 144076
        //if(!l_err) //Cumulus only
        //{
        //    l_err = call_mss_eff_mb_interleave();
        //}

        if (l_err)
        {
            // Ensure istep error created and has same plid as this error
            l_StepError.addErrorDetails( l_err );
            errlCommit( l_err, HWPF_COMP_ID );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config exit" );
    return l_StepError.getErrorHandle();
}
};   // end namespace
