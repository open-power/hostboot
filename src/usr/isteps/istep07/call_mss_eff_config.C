/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_eff_config.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
 *  Contains all the wrappers for istep07
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
#include    <targeting/attrsync.H>

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

errlHndl_t call_mss_eff_grouping()
{
    errlHndl_t l_err = NULL;
/* @TODO RTC:133830 Add the wrapper when ready
    TARGETING::TargetHandleList l_procsList;
    getAllChips(l_procsList, TYPE_PROC);

    for (TargetHandleList::const_iterator
            l_proc_iter = l_procsList.begin();
            l_proc_iter != l_procsList.end();
            ++l_proc_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_cpu_target = *l_proc_iter;

        //  print call to hwp and write HUID of the target(s)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_eff_grouping HWP cpu "
                "target HUID %.8X",
                TARGETING::get_huid(l_cpu_target));

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_cpu_target(fapi::TARGET_TYPE_PROC_CHIP,
                    (const_cast<TARGETING::Target*>(l_cpu_target)) );

        TARGETING::TargetHandleList l_membufsList;
        getChildAffinityTargets(l_membufsList, l_cpu_target,
                   CLASS_CHIP, TYPE_MEMBUF);
        std::vector<fapi::Target> l_associated_centaurs;

        for (TargetHandleList::const_iterator
                l_membuf_iter = l_membufsList.begin();
                l_membuf_iter != l_membufsList.end();
                ++l_membuf_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target* l_pTarget = *l_membuf_iter;

            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapi_centaur_target(fapi::TARGET_TYPE_MEMBUF_CHIP,
                   (const_cast<TARGETING::Target*>(l_pTarget)) );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_pTarget));

            l_associated_centaurs.push_back(l_fapi_centaur_target);
        }

        //FAPI_INVOKE_HWP(l_err, p9_mss_eff_grouping,
                        //l_fapi_cpu_target, l_associated_centaurs);
        //Remove when above HWP is working
        FAPI_INVOKE_HWP(l_err,mss_eff_grouping,
                        l_fapi_cpu_target, l_associated_centaurs);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR 0x%.8X:  mss_eff_grouping HWP",
                        l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_cpu_target).addToLog(l_err);

            break; // break out mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SUCCESS :  mss_eff_grouping HWP");
        }
    }   // endfor
*/
    return l_err;
}

errlHndl_t call_opt_memmap( bool i_initBase )
{
    errlHndl_t l_err = NULL;
/* @TODO RTC:133830 Add the wrapper when ready
    TARGETING::TargetHandleList l_procs;
    getAllChips(l_procs, TYPE_PROC);

    std::vector<fapi::Target> l_fapi_procs;

    for ( TARGETING::TargetHandleList::const_iterator
          l_iter = l_procs.begin();
          l_iter != l_procs.end();
          ++l_iter )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_target = *l_iter;

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_target(fapi::TARGET_TYPE_PROC_CHIP,
                    (const_cast<TARGETING::Target*>(l_target)) );

        l_fapi_procs.push_back(l_fapi_target);
    }

    //FAPI_INVOKE_HWP(l_err, p9_opt_memmap, l_fapi_procs, i_initBase);
    //Remove when above HWP is working
    FAPI_INVOKE_HWP(l_err,opt_memmap, l_fapi_procs,i_initBase);

    if ( l_err )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR 0x%.8X:  opt_memmap HWP", l_err->reasonCode());
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS :  opt_memmap HWP");
    }
*/
    return l_err;
}

errlHndl_t call_mss_eff_mb_interleave()
{
    errlHndl_t l_err = NULL;
/* @TODO RTC:133830 Add the wrapper when ready
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);
    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        const TARGETING::Target* l_membuf_target = *l_membuf_iter;
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

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config entry" );

    TARGETING::hdatAttrHack();
    //@TODO RTC:133830 Add the wrapper back in when ready
/*
    errlHndl_t l_err = NULL;
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

    // Get all functional MBA chiplets
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Iterate over all MBAs, calling mss_eff_config and mss_eff_config_thermal
    for (TargetHandleList::const_iterator l_mba_iter = l_mbaTargetList.begin();
            l_mba_iter != l_mbaTargetList.end(); ++l_mba_iter)
    {
        // Get the TARGETING::Target pointer and its HUID
        const TARGETING::Target* l_mba_target = *l_mba_iter;
        uint32_t l_huid = TARGETING::get_huid(l_mba_target);

        // Create a FAPI target representing the MBA
        const fapi::Target l_fapi_mba_target(fapi::TARGET_TYPE_MBA_CHIPLET,
            (const_cast<TARGETING::Target*>(l_mba_target)));

        // Call the mss_eff_config_vpd_decode HWP
        //FAPI_INVOKE_HWP(l_err,p9_mss_eff_config_vpd_decode,
        //l_fapi_mba_target);

        // Call the mss_eff_config HWP
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "=====  mss_eff_config HWP. MBA HUID %.8X", l_huid);
        //FAPI_INVOKE_HWP(l_err, p9_mss_eff_config, l_fapi_mba_target);
        //Remove when above HWP is working:
        FAPI_INVOKE_HWP(l_err, mss_eff_config, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  mss_eff_config HWP ", l_err->reasonCode());

            // Ensure istep error created and has same plid as this error
            ErrlUserDetailsTarget(l_mba_target).addToLog(l_err);
            l_StepError.addErrorDetails(l_err);
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  mss_eff_config HWP");

            // Call the mss_eff_config_thermal HWP
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_eff_config_thermal HWP. MBA HUID %.8X", l_huid);
            //FAPI_INVOKE_HWP(l_err, p9_mss_eff_config_thermal,
            //l_fapi_mba_target);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  mss_eff_config_thermal HWP ", l_err->reasonCode());

                // Ensure istep error created and has same plid as this error
                ErrlUserDetailsTarget(l_mba_target).addToLog(l_err);
                l_StepError.addErrorDetails(l_err);
                errlCommit(l_err, HWPF_COMP_ID);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_eff_config_thermal HWP");
            }
        }
    }

    if (l_StepError.isNull())
    {
        // Flush out BASE attributes to starting values
        l_err = call_opt_memmap(true);

        if (!l_err)
        {
            // Stack the memory on each chip
            l_err = call_mss_eff_grouping();

            if (!l_err)
            {
                // Move the BASES around to the real final values
                l_err = call_opt_memmap(false);

                if (!l_err)
                {
                    // Stack the memory again based on system-wide positions
                    l_err = call_mss_eff_grouping();

                      //if(!l_err) //Cumulus only
                      //{
                      //    l_err = call_mss_eff_mb_interleave();
                      //}

                }
            }
        }

        if (l_err)
        {
            // Ensure istep error created and has same plid as this error
            l_StepError.addErrorDetails( l_err );
            errlCommit( l_err, HWPF_COMP_ID );
        }
    }

    // Calling mss_eff_mb_interleave
    if (l_StepError.isNull())
    {
        l_err = call_mss_eff_mb_interleave();
        if(l_err)
        {
            l_StepError.addErrorDetails(l_err);
            errlCommit( l_err, HWPF_COMP_ID );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config exit" );
*/
    return l_StepError.getErrorHandle();
}
};   // end namespace
