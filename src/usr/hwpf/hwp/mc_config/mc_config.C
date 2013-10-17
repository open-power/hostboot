/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mc_config.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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


//  --  prototype   includes    --
//  Add any customized routines that you don't want overwritten into
//      "mc_config_custom.C" and include the prototypes here.
//  #include    "mc_config_custom.H"

#include    "mc_config.H"

//  Uncomment these files as they become available:
// #include    "host_collect_dimm_spd/host_collect_dimm_spd.H"
#include    "mss_volt/mss_volt.H"
#include    "mss_freq/mss_freq.H"
#include    "mss_eff_config/mss_eff_config.H"
#include    "mss_eff_config/mss_eff_grouping.H"
#include    "mss_eff_config/opt_memmap.H"

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

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_collect_dimm_spd entry" );
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_collect_dimm_spd exit" );

    return l_err;
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
    
                fapi::Target l_membuf_fapi_target( TARGET_TYPE_MEMBUF_CHIP,
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
            break;

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
        fapi::Target l_fapi_membuf_target( TARGET_TYPE_MEMBUF_CHIP,
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

            break; // break out memBuf loop
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
        const fapi::Target l_fapi_cpu_target( TARGET_TYPE_PROC_CHIP,
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
            const fapi::Target l_fapi_centaur_target( TARGET_TYPE_MEMBUF_CHIP,
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

errlHndl_t call_opt_memmap()
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
        const fapi::Target l_fapi_target( TARGET_TYPE_PROC_CHIP,
                    (const_cast<TARGETING::Target*>(l_target)) );

        l_fapi_procs.push_back(l_fapi_target);
    }

    bool l_initProcMemBaseAttr = false;
    FAPI_INVOKE_HWP(l_err, opt_memmap, l_fapi_procs, l_initProcMemBaseAttr);

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

    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    for (TargetHandleList::const_iterator
            l_mba_iter = l_mbaTargetList.begin();
            l_mba_iter != l_mbaTargetList.end();
            ++l_mba_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_mba_target = *l_mba_iter;

        //  print call to hwp and dump physical path of the target(s)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_eff_config HWP "
                "target HUID %.8X",
                TARGETING::get_huid(l_mba_target));

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                    (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_eff_config, l_fapi_mba_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  mss_eff_config HWP ",
                    l_err->reasonCode());

            ErrlUserDetailsTarget myDetails(l_mba_target);

            // capture the target data in the elog
            myDetails.addToLog( l_err );

            break; // break out mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  mss_eff_config HWP");
        }
    }   // endfor

    TARGETING::TargetHandleList l_procs;
    getAllChips(l_procs, TYPE_PROC);

    for (TARGETING::TargetHandleList::const_iterator
         l_iter = l_procs.begin();
         l_iter != l_procs.end() && !l_err;
         ++l_iter)
    {
        TARGETING::Target*  l_target = *l_iter;

        uint64_t l_base = 0;
        l_target->setAttr<ATTR_MEM_BASE>( l_base  );

        l_base = 0x0002000000000000;	// 512TB
        l_target->setAttr<ATTR_MIRROR_BASE>( l_base );
    }
    
    if (!l_err)
    {
        l_err = call_mss_eff_grouping();

        if (!l_err)
        {
            l_err = call_opt_memmap();

            if (!l_err)
            {
                l_err = call_mss_eff_grouping();
            }
        }
    }

    if (l_err)
    {
        // Create IStep error log and cross reference to error that occurred
        l_StepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
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
