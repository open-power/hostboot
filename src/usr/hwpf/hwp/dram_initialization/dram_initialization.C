/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_initialization/dram_initialization.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file dram_initialization.C
 *
 *  Support file for IStep: dram_initialization
 *   Dram Initialization
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1608
 *  *****************************************************************
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <diag/mdia/mdia.H>
#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    "dram_initialization.H"

//  Uncomment these files as they become available:
// #include    "host_startPRD_dram/host_startPRD_dram.H"
// #include    "mss_extent_setup/mss_extent_setup.H"
// #include    "mss_memdiag/mss_memdiag.H"
// #include    "mss_scrub/mss_scrub.H"
// #include    "mss_thermal_init/mss_thermal_init.H"
// #include    "proc_setup_bars/proc_setup_bars.H"
// #include    "proc_pbus_epsilon/proc_pbus_epsilon.H"
#include    "proc_exit_cache_contained/proc_exit_cache_contained.H"

//remove these once memory setup workaround is removed
#include <devicefw/driverif.H>
#include <spd/spdenums.H>

namespace   DRAM_INITIALIZATION
{

using   namespace   TARGETING;
using   namespace   fapi;



//
//  Wrapper function to call 14.1 :
//      host_startPRD_dram
//
void    call_host_startPRD_dram( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_startPRD_dram entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, host_startPRD_dram, _args_...);
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : .........." );
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : .........." );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_startPRD_dram exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.2 :
//      mss_extent_setup
//
void    call_mss_extent_setup( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_extent_setup entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, mss_extent_setup, _args_...);
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : .........." );
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : .........." );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_extent_setup exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.3 :
//      mss_memdiag
//
void    call_mss_memdiag( void    *io_pArgs )
{
    using namespace MDIA;

    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_memdiag entry" );

    PredicateIsFunctional l_isFunctional;

    // To filter MBAs
    PredicateCTM l_mbaFilter(CLASS_UNIT, TYPE_MBA);

    // Filter functional MBAs
    PredicatePostfixExpr l_functionalAndMbaFilter;
    l_functionalAndMbaFilter.push(&l_mbaFilter).push(&l_isFunctional).And();

    TargetRangeFilter    l_pMbas(
        targetService().begin(),
        targetService().end(),
        &l_functionalAndMbaFilter );

    TargetHandleList l_mbaList;

    // populate MBA TargetHandlelist
    for(;l_pMbas;++l_pMbas)
    {
        l_mbaList.push_back(*l_pMbas);
    }

    errlHndl_t l_err = runStep(l_mbaList);
    if(NULL != l_err)
    {
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "MDIA subStep failed");
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_memdiag exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.4 :
//      mss_scrub
//
void    call_mss_scrub( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_scrub entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, mss_scrub, _args_...);
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : .........." );
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : .........." );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_scrub exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.5 :
//      mss_thermal_init
//
void    call_mss_thermal_init( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_thermal_init entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, mss_thermal_init, _args_...);
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : .........." );
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : .........." );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_thermal_init exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.6 :
//      proc_setup_bars
//
void    call_proc_setup_bars( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_setup_bars entry" );

    // @@@@@    TEMPORARY SIMICS HACK for PHYP 6/1 milestone @@@@@
    //  loop through all processor targets
    //     1) loop on associated MCSs
    //          a) Get associated logical dimms, sum total size of memory
    //          b) Write memory base addr/size out to MCFGP 0x02011800 

    //Don't do this in VPO -- shouldn't be run anyway, but return as a precaution
    if( TARGETING::is_vpo() )
    {
        task_end2( l_errl );
    }

    // Get all functional processor targets
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "!!!!!!!!!WORKAROUND  Memory BAR setup!!!!!!!!!!!" );
    TARGETING::PredicateIsFunctional l_isFunctional;            //functional filter
    TARGETING::PredicateCTM l_Filter(CLASS_CHIP, TYPE_PROC);    //Proc chip filter
    TARGETING::PredicatePostfixExpr l_goodFilter;
    l_goodFilter.push(&l_Filter).push(&l_isFunctional).And();
    TARGETING::TargetRangeFilter l_Procs(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_goodFilter );

    // Create a Class/Type/Model predicate to look for units
    TARGETING::PredicateCTM l_mcsPred(CLASS_UNIT, TYPE_MCS);
    TARGETING::PredicatePostfixExpr l_mcsFilter;
    l_mcsFilter.push(&l_mcsPred).push(&l_isFunctional).And();

    // Create a Class/Type/Model predicate to look for dimm cards
    TARGETING::PredicateCTM l_dimmPred(CLASS_LOGICAL_CARD,TYPE_DIMM);
    TARGETING::PredicatePostfixExpr l_dimmFilter;
    l_dimmFilter.push(&l_dimmPred).push(&l_isFunctional).And();

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_dimmList;
    TARGETING::TargetHandleList l_mcsList;
    uint64_t base_addr = 0x0;


    for ( ; l_Procs && !l_errl; ++l_Procs )
    {
        const TARGETING::Target * l_pTarget = *l_Procs;
        l_mcsList.clear();

        //Get MCS sub units for this proc
        TARGETING::targetService().getAssociated(l_mcsList, l_pTarget,
                                                 TARGETING::TargetService::CHILD,
                                                 TARGETING::TargetService::ALL,
                                                 &l_mcsFilter);

        for (uint32_t i = 0; (i < l_mcsList.size()) && !l_errl; i++)
        {
            uint32_t mem_size = 0;
            l_dimmList.clear();

            //Get Dimms for this MCS
            TARGETING::targetService().getAssociated(l_dimmList, l_mcsList[i],
                            TARGETING::TargetService::CHILD_BY_AFFINITY,
                            TARGETING::TargetService::ALL, &l_dimmFilter);

            //Tally up the total dimm size
            for(uint32_t j=0; (j < l_dimmList.size()) && !l_errl; j++)
            {

                uint8_t dimm_den;
                size_t l_size = 0x1;
                l_errl = deviceRead(l_dimmList[j], &dimm_den, l_size,
                                   DEVICE_SPD_ADDRESS(SPD::DENSITY));
                if (l_errl)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "WORKAROUND: Memory BAR error getting dimm density");

                    break;
                }

                /*
                 Bit [3, 2, 1, 0] :
                 0000 = 256 Mb
                 0001 = 512 Mb
                 0010 = 1 Gb
                 0011 = 2 Gb
                 0100 = 4 Gb
                 0101 = 8 Gb
                 0110 = 16 Gb*/
                mem_size += (1<<dimm_den); //(smallest size is 256MB)

            }

            if(l_errl)
            {
                break;
            }

            /*check to see if total centaur siz is less than 4GB multiple
             Note that mem_size is in 256MB chunks
                   0x0000 0001 -- 256MB
                   0x0000 0010 -- 512MB
                   0x0000 0100 --   1GB
                   0x0000 1000 --   2GB
                   0x0001 0000 --   4GB
             This is a workaround HACK -- so just emit a warning
             */
            if(mem_size & 0xF)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "WARNING -- CEC memory size less than 4GB on MCS[%08X]\n",
                           TARGETING::get_huid(l_mcsList[i]));
                mem_size = 0x10;
            }
            uint64_t grp_size = (mem_size >>4)-1;

            /*build up MCFGP contents
             0          -- enable               0b1
             1:3        -- MCS/group            0x0
             4:8        -- group id             0x0
             9:10       -- HW settings          0b11
             11:23      -- Group size
                              4 GB b0000000000000
                              8 GB b0000000000001
                             16 GB b0000000000011
                             32 GB b0000000000111
                             64 GB b0000000001111
                            128 GB b0000000011111
                            256 GB b0000000111111
                            512 GB b0000001111111
                              1 TB b0000011111111
                              2 TB b0000111111111
                              4 TB b0001111111111
                              8 TB b0011111111111
             24:25      -- HW settings          0b11
             26:43      -- Base address of group (addr 14:31)
             44:63      -- Reserved             0x00000
             */
            uint64_t scom_data = 0x806000C000000000 |
              (grp_size << 40) | (base_addr << 20);
            size_t size = sizeof(scom_data);

            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "CEC memory base_addr[%lx], grp_size[%lx], scom[%lx]\n",
                       base_addr, grp_size, scom_data);

            l_errl = deviceWrite( l_mcsList[i],
                               &scom_data,
                               size,
                               DEVICE_SCOM_ADDRESS(0x02011800) );
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Failed to write MCS MCFGP scoms addr\n");
            }

            base_addr += (mem_size >>4);

        }
    }


    //Now need to scom the L3 bar on my EX to trigger Simics cache contained exit
    if(!l_errl)
    {
        TARGETING::Target* procTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle( procTarget );

        //Base scom address is 0x1001080b, need to place core id from cpuid
        //EX chiplet is bits 4:7 of scom addr, EX unit in cpuid is bits 25:28
        uint32_t scom_addr = 0x1001080b | (((task_getcpuid()) & 0x78) << 21);
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "EX L3 BAR1 addr [%08x]\n", scom_addr);

        uint64_t scom_data = 0x0; //data doesn't matter, just the write
        size_t size = sizeof(scom_data);
        l_errl = deviceWrite( procTarget,
                              &scom_data,
                              size,
                              DEVICE_SCOM_ADDRESS(scom_addr) );
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Failed to write EX %08x addr\n", scom_addr);
        }
    }

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, proc_setup_bars, _args_...);
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : .........." );
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : .........." );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_setup_bars exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.7 :
//      proc_pbus_epsilon
//
void    call_proc_pbus_epsilon( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_pbus_epsilon entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, proc_pbus_epsilon, _args_...);
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : .........." );
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : .........." );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_pbus_epsilon exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.8 :
//      proc_exit_cache_contained
//
void    call_proc_exit_cache_contained( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl,
                     proc_exit_cache_contained
                     );
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : call_proc_exit_cache_contained, errorlog PLID=0x%x",
                  l_errl->plid() );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : call_proc_exit_cache_contained" );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}


};   // end namespace
