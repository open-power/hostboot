/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/mc_config/mc_config.C $
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

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_collect_dimm_spd entry" );
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_collect_dimm_spd exit" );

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

    for (size_t i = 0; i < l_membufTargetList.size(); i++ )
    {
        TARGETING::ATTR_VMEM_ID_type l_VmemID =
                            l_membufTargetList[i]->getAttr<ATTR_VMEM_ID>();
        l_VmemList.push_back(l_VmemID);     
    }

    std::sort(l_VmemList.begin(), l_VmemList.end());

    std::vector<TARGETING::ATTR_VMEM_ID_type>::iterator objItr;
    objItr=std::unique(l_VmemList.begin(), l_VmemList.end());
    l_VmemList.erase(objItr,l_VmemList.end());


    //for each unique VmemId filter it out of the list of membuf targets
    //to create a subsetlist of membufs with just that vmemid
    for(size_t i = 0; i < l_VmemList.size(); i++)
    {

        //  declare a vector of fapi targets to pass to mss_volt
        std::vector<fapi::Target> l_membufFapiTargets;

        for (size_t j = 0; j < l_membufTargetList.size(); j++)
        {
            if (l_membufTargetList[j]->getAttr<ATTR_VMEM_ID>()==l_VmemList[i])
            {
                //  make a local copy of the target for ease of use
                const TARGETING::Target*  l_membuf_target = 
                                            l_membufTargetList[j];
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  add to fapi::Target vector vmem_id=0x%08X...",
                    l_membuf_target->getAttr<ATTR_VMEM_ID>());

                EntityPath l_path;
                l_path  =   l_membuf_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
    
                fapi::Target l_membuf_fapi_target(
                        TARGET_TYPE_MEMBUF_CHIP,
                        reinterpret_cast<void *>
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

            /*@
            * @errortype
            * @reasoncode       ISTEP_MC_CONFIG_FAILED
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         ISTEP_MSS_VOLT
            * @userdata1        bytes 0-1: plid identifying first error
            *                   bytes 2-3: reason code of first error
            * @userdata2        bytes 0-1: total number of elogs included
            *                   bytes 2-3: N/A
            * @devdesc          call to mss_volt has failed
            *
            */
            l_StepError.addErrorDetails(ISTEP_MC_CONFIG_FAILED,
                                    ISTEP_MSS_VOLT,
                                    l_err );

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

    for ( size_t i = 0; i < l_membufTargetList.size(); i++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_membuf_target = l_membufTargetList[i];

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_freq HWP( %d )", i );
        EntityPath l_path;
        l_path  =   l_membuf_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        //  call the HWP with each target   ( if parallel, spin off a task )
        // $$const fapi::Target l_fapi_membuf_target(
        fapi::Target l_fapi_membuf_target(
                TARGET_TYPE_MEMBUF_CHIP,
                reinterpret_cast<void *>
        (const_cast<TARGETING::Target*>(l_membuf_target)) );

        FAPI_INVOKE_HWP(l_err, mss_freq, l_fapi_membuf_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR 0x%.8X:  mss_freq HWP( %d ) ",
                     l_err->reasonCode(),
                     i );

            ErrlUserDetailsTarget myDetails(l_membuf_target);

            // capture the target data in the elog
            myDetails.addToLog(l_err );

            /*@
             * @errortype
             * @reasoncode  ISTEP_MC_CONFIG_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_MSS_FREQ
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to mss_freq has failed
             *
             */
            l_StepError.addErrorDetails(ISTEP_MC_CONFIG_FAILED,
                                        ISTEP_MSS_FREQ,
                                        l_err );

            errlCommit( l_err, HWPF_COMP_ID );

            break; // break out memBuf loop
         }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  mss_freq HWP( %d )", i );
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

    for ( size_t i = 0; i < l_procsList.size(); i++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_cpu_target = l_procsList[i];

        //  print call to hwp and dump physical path of the target(s)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_eff_grouping HWP( cpu %d )", i );
        //  dump physical path to targets
        EntityPath l_path;
        l_path  =   l_cpu_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_cpu_target(
                TARGET_TYPE_PROC_CHIP,
                reinterpret_cast<void *>
        (const_cast<TARGETING::Target*>(l_cpu_target)) );

        TARGETING::TargetHandleList l_membufsList;
        getAffinityChips(l_membufsList, l_cpu_target, TYPE_MEMBUF);
        std::vector<fapi::Target> l_associated_centaurs;

        size_t j = 0;
        for ( ; j < l_membufsList.size(); j++ )
        {
            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapi_centaur_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                   (const_cast<TARGETING::Target*>(l_membufsList[j])) );

            EntityPath l_path;
            l_path  =   l_membufsList[j]->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            l_associated_centaurs.push_back(l_fapi_centaur_target);
        }

        FAPI_INVOKE_HWP(l_err, mss_eff_grouping,
                        l_fapi_cpu_target, l_associated_centaurs);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR 0x%.8X:  mss_eff_grouping HWP( cpu %d centaur %d ) ",
                        l_err->reasonCode(), i, j );

            ErrlUserDetailsTarget myDetails(l_cpu_target);

            // capture the target data in the elog
            myDetails.addToLog(l_err );

            break; // break out mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SUCCESS :  mss_eff_grouping HWP( cpu %d )", i );
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

    for ( TARGETING::TargetHandleList::iterator l_iter = l_procs.begin();
          l_iter != l_procs.end(); ++l_iter )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_target = *l_iter;

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_target( TARGET_TYPE_PROC_CHIP,
                    reinterpret_cast<void *>
                    (const_cast<TARGETING::Target*>(l_target)) );

        l_fapi_procs.push_back(l_fapi_target);
    }

    FAPI_INVOKE_HWP(l_err, opt_memmap, l_fapi_procs);

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

    for ( size_t i = 0; i < l_mbaTargetList.size(); i++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[i];

        //  print call to hwp and dump physical path of the target(s)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_eff_config HWP( mba %d )", i );
        //  dump physical path to targets
        EntityPath l_path;
        l_path  =   l_mba_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();


        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_mba_target(
                TARGET_TYPE_MBA_CHIPLET,
                reinterpret_cast<void *>
        (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_eff_config, l_fapi_mba_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  mss_eff_config HWP( mba %d ) ",
                    l_err->reasonCode(), i );

            ErrlUserDetailsTarget myDetails(l_mba_target);

            // capture the target data in the elog
            myDetails.addToLog( l_err );

            break; // break out mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  mss_eff_config HWP( mba %d )", i );
        }
    }   // endfor

    TARGETING::TargetHandleList l_procs;
    getAllChips(l_procs, TYPE_PROC);

    for (TARGETING::TargetHandleList::iterator l_iter = l_procs.begin();
         l_iter != l_procs.end() && !l_err; ++l_iter)
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
        /*@
         * @errortype
         * @reasoncode  ISTEP_MC_CONFIG_FAILED
         * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid    ISTEP_MSS_EFF_CONFIG
         * @userdata1   bytes 0-1: plid identifying first error
         *              bytes 2-3: reason code of first error
         * @userdata2   bytes 0-1: total number of elogs included
         *              bytes 2-3: N/A
         * @devdesc     call to mss_eff_grouping has failed
         *
         */
        l_StepError.addErrorDetails(ISTEP_MC_CONFIG_FAILED,
                                    ISTEP_MSS_EFF_CONFIG,
                                    l_err );

        errlCommit( l_err, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config exit" );

    return l_StepError.getErrorHandle();
}


};   // end namespace
