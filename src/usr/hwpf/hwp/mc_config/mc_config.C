/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mc_config.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file mc_config.C
 *
 *  Support file for IStep: mc_config
 *   Step 12 MC Config
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-03-01:1032
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    "mc_config.H"

#include    "mss_volt/mss_volt.H"
#include    "mss_freq/mss_freq.H"
#include    "mss_eff_config/mss_eff_config.H"
#include    "mss_eff_config/mss_eff_config_thermal.H"
#include    "mss_eff_config/mss_eff_grouping.H"
#include    "mss_eff_config/opt_memmap.H"
#include    "mss_attr_cleanup/mss_attr_cleanup.H"

namespace   MC_CONFIG
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;

//
//  Wrapper function to call host_collect_dimm_spd
//
void*    call_host_collect_dimm_spd( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_stepError;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_collect_dimm_spd entry" );

    // Get a list of all present Centaurs
    TargetHandleList l_presCentaurs;
    getChipResources(l_presCentaurs, TYPE_MEMBUF, UTIL_FILTER_PRESENT);
    // Associated MBA targets
    TARGETING::TargetHandleList l_mbaList;

    // Define predicate for associated MBAs
    PredicateCTM predMba(CLASS_UNIT, TYPE_MBA);
    PredicatePostfixExpr presMba;
    PredicateHwas predPres;
    predPres.present(true);
    presMba.push(&predMba).push(&predPres).And();

    for (TargetHandleList::const_iterator
            l_cenIter = l_presCentaurs.begin();
            l_cenIter != l_presCentaurs.end();
            ++l_cenIter)
    {
        //  make a local copy of the target for ease of use
        TARGETING::Target * l_pCentaur = *l_cenIter;
        // Retrieve HUID of current Centaur
        TARGETING::ATTR_HUID_type l_currCentaurHuid =
            TARGETING::get_huid(l_pCentaur);

        // Dump current run on target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_attr_cleanup HWP on "
                "target HUID %.8X", l_currCentaurHuid);

        // find all present MBAs associated with this Centaur
        TARGETING::TargetHandleList l_presMbas;
        targetService().getAssociated(l_presMbas,
                                      l_pCentaur,
                                      TargetService::CHILD,
                                      TargetService::IMMEDIATE,
                                      &presMba);

        // If not at least two MBAs found
        if (l_presMbas.size() < 2)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Not enough MBAs found for Centaur target HUID %.8X, "
              "skipping this Centaur.",
              l_currCentaurHuid);
            continue;
        }

        // Create FAPI Targets.
        const fapi::Target l_fapiCentaurTarget(TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_pCentaur)));
        const fapi::Target l_fapiMba0Target(TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_presMbas[0])));
        const fapi::Target l_fapiMba1Target(TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_presMbas[1])));
        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_attr_cleanup, l_fapiCentaurTarget,
                        l_fapiMba0Target, l_fapiMba1Target);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: mss_attr_cleanup HWP returns error",
                      l_err->reasonCode());
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);
            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails(l_err);
            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            // Success
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Successfully ran mss_attr_cleanup HWP on "
                    "CENTAUR target HUID %.8X "
                    "and associated MBAs",
                    l_currCentaurHuid);
        }
    }


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_collect_dimm_spd exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call mss_volt
//
void*   call_mss_volt( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt entry" );

    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    //get a list of unique VmemIds
    std::vector<TARGETING::ATTR_VMEM_ID_type> l_VmemList;

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        TARGETING::ATTR_VMEM_ID_type l_VmemID =
                            (*l_membuf_iter)->getAttr<ATTR_VMEM_ID>();
        l_VmemList.push_back(l_VmemID);     
    }

    std::sort(l_VmemList.begin(), l_VmemList.end());

    std::vector<TARGETING::ATTR_VMEM_ID_type>::iterator objItr;
    objItr=std::unique(l_VmemList.begin(), l_VmemList.end());
    l_VmemList.erase(objItr,l_VmemList.end());

    //for each unique VmemId filter it out of the list of membuf targets
    //to create a subsetlist of membufs with just that vmemid
    std::vector<TARGETING::ATTR_VMEM_ID_type>::iterator l_vmem_iter;
    for (l_vmem_iter = l_VmemList.begin();
            l_vmem_iter != l_VmemList.end();
            ++l_vmem_iter)
    {
        //  declare a vector of fapi targets to pass to mss_volt
        std::vector<fapi::Target> l_membufFapiTargets;

        for (TargetHandleList::const_iterator
                l_membuf_iter = l_membufTargetList.begin();
                l_membuf_iter != l_membufTargetList.end();
                ++l_membuf_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target*  l_membuf_target = *l_membuf_iter;
            if (l_membuf_target->getAttr<ATTR_VMEM_ID>()==*l_vmem_iter)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  add to fapi::Target vector vmem_id=0x%08X "
                    "target HUID %.8X",
                    l_membuf_target->getAttr<ATTR_VMEM_ID>(),
                    TARGETING::get_huid(l_membuf_target));
    
                fapi::Target l_membuf_fapi_target(fapi::TARGET_TYPE_MEMBUF_CHIP,
                        (const_cast<TARGETING::Target*>(l_membuf_target)) );

                l_membufFapiTargets.push_back( l_membuf_fapi_target );
            }
        }
        
        //now have the a list of fapi membufs with just the one VmemId
        //call the HWP on the list of fapi targets
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "=====  mss_volt HWP( vector )" );
        FAPI_INVOKE_HWP(l_err, mss_volt, l_membufFapiTargets);
            
        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  mss_volt HWP( ) ", l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_volt HWP( )" );
        }

    }   // endfor

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt exit" );
    return l_StepError.getErrorHandle();
}

//
//  Wrapper function to call mss_freq
//
void*    call_mss_freq( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq entry" );

    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_membuf_target = *l_membuf_iter;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_freq HWP "
                "target HUID %.8X",
                TARGETING::get_huid(l_membuf_target));

        //  call the HWP with each target   ( if parallel, spin off a task )
        // $$const fapi::Target l_fapi_membuf_target(
        fapi::Target l_fapi_membuf_target(fapi::TARGET_TYPE_MEMBUF_CHIP,
                    (const_cast<TARGETING::Target*>(l_membuf_target)) );

        FAPI_INVOKE_HWP(l_err, mss_freq, l_fapi_membuf_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR 0x%.8X:  mss_freq HWP ",
                     l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_membuf_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

         }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  mss_freq HWP");
        }
    } // End memBuf loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq exit" );

    return l_StepError.getErrorHandle();
}

errlHndl_t call_mss_eff_grouping()
{
    errlHndl_t l_err = NULL;

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

        FAPI_INVOKE_HWP(l_err, mss_eff_grouping,
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

    return l_err;
}

errlHndl_t call_opt_memmap( bool i_initBase )
{
    errlHndl_t l_err = NULL;

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

    FAPI_INVOKE_HWP(l_err, opt_memmap, l_fapi_procs, i_initBase);

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

    return l_err;
}

//
//  Wrapper function to call mss_eff_config
//
void*    call_mss_eff_config( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config entry" );

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

        // Call the mss_eff_config HWP
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "=====  mss_eff_config HWP. MBA HUID %.8X", l_huid);
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
            FAPI_INVOKE_HWP(l_err, mss_eff_config_thermal, l_fapi_mba_target);

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

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config exit" );

    return l_StepError.getErrorHandle();
}
//
//  Wrapper function to call mss_attr_update
//
void*    call_mss_attr_update( void *io_pArgs )
{

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_attr_update entry");
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_attr_update exit" );

    return l_StepError.getErrorHandle();
}



};   // end namespace
