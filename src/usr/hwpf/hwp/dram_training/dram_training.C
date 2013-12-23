/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/dram_training.C $              */
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
 *  @file dram_training.C
 *
 *  Support file for IStep: dram_training
 *   Step 13 DRAM Training
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

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>

#include    <hwpisteperror.H>
#include    <errl/errludtarget.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

//hb vddr support
#include    <hbVddrMsg.H>
#include <initservice/initserviceif.H>

// Run on all Centaurs/MBAs, but needs to keep this one handy in case we
// want to limit them in VPO
const uint8_t UNLIMITED_RUN = 0xFF;
const uint8_t VPO_NUM_OF_MBAS_TO_RUN = UNLIMITED_RUN;
const uint8_t VPO_NUM_OF_MEMBUF_TO_RUN = UNLIMITED_RUN;

//  --  prototype   includes    --
#include    "dram_training.H"

#include    "mem_pll_setup/cen_mem_pll_initf.H"
#include    "mem_pll_setup/cen_mem_pll_setup.H"
#include    "mem_startclocks/cen_mem_startclocks.H"
#include    "mss_scominit/mss_scominit.H"
#include    "mss_ddr_phy_reset/mss_ddr_phy_reset.H"
#include    "mss_draminit/mss_draminit.H"
#include    "mss_draminit_training/mss_draminit_training.H"
#include    "mss_draminit_trainadv/mss_draminit_training_advanced.H"
#include    "mss_draminit_mc/mss_draminit_mc.H"
#include    "mss_dimm_power_test/mss_dimm_power_test.H"
#include    "proc_throttle_sync.H"

namespace   DRAM_TRAINING
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;

//
//  Wrapper function to call host_disable_vddr
//
void*    call_host_disable_vddr( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"call_host_disable_vddr entry");

    if(INITSERVICE::spBaseServicesEnabled())
    {
        IStepError l_StepError;

        HBVddrMsg l_hbVddr;

        l_err = l_hbVddr.sendMsg(HBVddrMsg::HB_VDDR_DISABLE);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X: call_host_disable_vddr to sendMsg returns error",
                          l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  host_disable_vddr()" );
        }
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_disable_vddr"
                    "when a fsp present exit" );

        return l_StepError.getErrorHandle();
    }
    else
    {
        //This is a fsp less system.  Right now the istep
        //only works when a FSP is present.  May add code in the future for
        //Stradale which is a FSP-less system
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"call_host_disable_vddr"
                "no-op because fsp-less");
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_disable_vddr "
                "for an fsp less system exit" );

        return l_err;
    }

}

//
//  Wrapper function to call mem_pll_initf
//
void*    call_mem_pll_initf( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_initf entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCentaur = *l_membuf_iter;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running cen_mem_pll_initf HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
                 (const_cast<TARGETING::Target*>(l_pCentaur)));

        //  call cen_mem_pll_initf to do pll init
        FAPI_INVOKE_HWP(l_err, cen_mem_pll_initf, l_fapi_centaur);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: cen_mem_pll_initf HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: cen_mem_pll_initf HWP( )" );
        }
    }

    if( l_err )
    {
        // Create IStep error log and cross reference to error that occurred
        l_StepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_initf exit" );

    return l_StepError.getErrorHandle();
}


//
//  Wrapper function to call mem_pll_setup
//
void*    call_mem_pll_setup( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_setup entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCentaur = *l_membuf_iter;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mem_pll_setup HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
                 (const_cast<TARGETING::Target*>(l_pCentaur)));

        //  call cen_mem_pll_setup to verify lock
        FAPI_INVOKE_HWP(l_err, cen_mem_pll_setup, l_fapi_centaur);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: mem_pll_setup HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: mem_pll_setup HWP( )" );
        }
    }

    if( l_err )
    {
        // Create IStep error log and cross reference to error that occurred
        l_StepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_setup exit" );

    return l_StepError.getErrorHandle();
}

//
//  Wrapper function to call mem_startclocks
//
void*    call_mem_startclocks( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"call_mem_startclocks entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCentaur = *l_membuf_iter;

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running cen_mem_startclocks HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_pCentaur)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, cen_mem_startclocks, l_fapi_centaur);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: cen_mem_startclocks HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS :  cen_mem_startclocks HWP( )" );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_startclocks exit" );

    return l_StepError.getErrorHandle();
}



//
//  Wrapper function to call host_enable_vddr
//
void*    call_host_enable_vddr( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_enable_vddr entry" );

    errlHndl_t l_err = NULL;

    if(INITSERVICE::spBaseServicesEnabled())
    {
        IStepError l_StepError;

        HBVddrMsg l_hbVddr;

        l_err = l_hbVddr.sendMsg(HBVddrMsg::HB_VDDR_ENABLE);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                 "ERROR 0x%.8X: call_host_enable_vddr to sendMsg returns error",
                    l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  host_enable_vddr()" );
        }
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                              "call_host_enable_vddr exit" );

        return l_StepError.getErrorHandle();
    }
    else
    {
        //This is a fsp less system.  Right now the istep
        //only works when a FSP is present.  May add code in the future for
        //Stradale which is a FSP-less system
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"call_host_enable_vddr"
                "no-op because fsp-less");
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_enable_vddr "
                "for an fsp less system exit" );

        return l_err;

    }
}



//
//  Wrapper function to call mss_scominit
//
void*    call_mss_scominit( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scominit entry" );

    do
    {
        // Get all Centaur targets
        TARGETING::TargetHandleList l_membufTargetList;
        getAllChips(l_membufTargetList, TYPE_MEMBUF);

        for (TargetHandleList::const_iterator
                l_membuf_iter = l_membufTargetList.begin();
                l_membuf_iter != l_membufTargetList.end();
                ++l_membuf_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target* l_pCentaur = *l_membuf_iter;

            // Dump current run on target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running mss_scominit HWP on "
                    "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

            // Cast to a FAPI type of target.
            const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
                    (const_cast<TARGETING::Target*>(l_pCentaur)) );

            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP(l_err, mss_scominit, l_fapi_centaur);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: mss_scominit HWP returns error",
                          l_err->reasonCode());

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);

                // Create IStep error log and cross reference to error that occurred
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );

                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  mss_scominit HWP( )" );
            }
        }
        if (l_err)
        {
            break;
        }

        // Run proc throttle sync
        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        for (TARGETING::TargetHandleList::const_iterator
             l_cpuIter = l_cpuTargetList.begin();
             l_cpuIter != l_cpuTargetList.end();
             ++l_cpuIter)
        {
            const TARGETING::Target* l_pTarget = *l_cpuIter;
            fapi::Target l_fapiproc_target( TARGET_TYPE_PROC_CHIP,
                 (const_cast<TARGETING::Target*>(l_pTarget)));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running proc_throttle_sync HWP on "
                    "target HUID %.8X", TARGETING::get_huid(l_pTarget));

            // Call proc_throttle_sync
            FAPI_INVOKE_HWP( l_err, proc_throttle_sync, l_fapiproc_target );

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: proc_throttle_sync HWP returns error",
                          l_err->reasonCode());

                // Capture the target data in the elog
                ErrlUserDetailsTarget(l_pTarget).addToLog(l_err);

                // Create IStep error log and cross reference to error that occurred
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );

                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  proc_throttle_sync HWP( )" );
            }
        }

    } while (0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scominit exit" );

    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call mss_ddr_phy_reset
//
void*  call_mss_ddr_phy_reset( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_mss_ddr_phy_reset entry" );

    // Get all MBA targets
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = l_mbaTargetList.size();
    if (TARGETING::is_vpo() && (VPO_NUM_OF_MBAS_TO_RUN < l_mbaLimit))
    {
        l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for ( uint8_t l_mbaNum=0; l_mbaNum < l_mbaLimit; l_mbaNum++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[l_mbaNum];

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running call_mss_ddr_phy_reset HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mba_target));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                        (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_ddr_phy_reset, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X: mss_ddr_phy_reset HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mba_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break; // break out of mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  call_mss_ddr_phy_reset HWP( )" );
        }
    } // end l_mbaNum loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_ddr_phy_reset exit" );

    return l_stepError.getErrorHandle();
}


//
//  Wrapper function to call mss_draminit
//
void*    call_mss_draminit( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit entry" );

    // Get all MBA targets
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = l_mbaTargetList.size();
    if (TARGETING::is_vpo() && (VPO_NUM_OF_MBAS_TO_RUN < l_mbaLimit))
    {
        l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for ( uint8_t l_mbaNum=0; l_mbaNum < l_mbaLimit; l_mbaNum++ )
    {
        // Make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[l_mbaNum];

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_draminit HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mba_target));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_draminit, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : mss_draminit HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mba_target).addToLog(l_err);

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break; // Break out of mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_draminit HWP( )" );
        }

    }   // endfor   mba's

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit exit" );

    return l_stepError.getErrorHandle();
}


//
//  Wrapper function to call mss_draminit_training
//
void*    call_mss_draminit_training( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_mss_draminit_training entry" );

    // Get all MBA targets
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = l_mbaTargetList.size();
    if (TARGETING::is_vpo() && (VPO_NUM_OF_MBAS_TO_RUN < l_mbaLimit))
    {
        l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for ( uint8_t l_mbaNum=0; l_mbaNum < l_mbaLimit; l_mbaNum++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[l_mbaNum];

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_draminit_training HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mba_target));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                        (const_cast<TARGETING::Target*>(l_mba_target)) );


        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_draminit_training, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : mss_draminit_training HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mba_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break; // break out of mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_draminit_training HWP( )" );
        }

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_draminit_training exit" );

    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call mss_draminit_trainadv
//
void*    call_mss_draminit_trainadv( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_draminit_trainadv entry" );

    // Get all MBA targets
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = l_mbaTargetList.size();
    if (TARGETING::is_vpo() && (VPO_NUM_OF_MBAS_TO_RUN < l_mbaLimit))
    {
        l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for ( uint8_t l_mbaNum=0; l_mbaNum < l_mbaLimit; l_mbaNum++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[l_mbaNum];

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_draminit_training_advanced HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mba_target));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                    (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_draminit_training_advanced,
                        l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "ERROR 0x%.8X : mss_draminit_training_advanced HWP returns error",
                l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mba_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SUCCESS :  mss_draminit_training_advanced HWP( )" );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "call_mss_draminit_trainadv exit" );

    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call mss_draminit_mc
//
void*    call_mss_draminit_mc( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"call_mss_draminit_mc entry" );

    // Get all centaur targets
    TARGETING::TargetHandleList l_mBufTargetList;
    getAllChips(l_mBufTargetList, TYPE_MEMBUF);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_memBufLimit = l_mBufTargetList.size();
    if (TARGETING::is_vpo() && (VPO_NUM_OF_MEMBUF_TO_RUN < l_memBufLimit))
    {
        l_memBufLimit = VPO_NUM_OF_MEMBUF_TO_RUN;
    }

    for ( uint8_t l_mBufNum=0; l_mBufNum < l_memBufLimit; l_mBufNum++ )
    {
        const TARGETING::Target* l_membuf_target = l_mBufTargetList[l_mBufNum];

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_draminit_mc HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_membuf_target));

        // Cast to a fapi target
        fapi::Target l_fapi_membuf_target( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_membuf_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_draminit_mc, l_fapi_membuf_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : mss_draminit_mc HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_membuf_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break; // break out of memBuf loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_draminit_mc HWP( )" );
        }

    } // End memBuf loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_mc exit" );

    return l_stepError.getErrorHandle();
}
//
//  Wrapper function to call mss_dimm_power_test
//
void*    call_mss_dimm_power_test( void *io_pArgs )
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_dimm_power_test entry" );

    errlHndl_t l_err = NULL;

    // get a list of mba targets
    IStepError l_stepError;

    TARGETING::TargetHandleList l_mbaTargetList;
    TARGETING::TargetHandleList::const_iterator pRangeLimitItr;
    TARGETING::TargetHandleList::const_iterator pTargetItr;

    // Get all MBA targets
    getAllChiplets(l_mbaTargetList, TYPE_MBA, true);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = l_mbaTargetList.size();
    if (TARGETING::is_vpo() && (VPO_NUM_OF_MBAS_TO_RUN < l_mbaLimit))
    {
        // limit the range to VPO_NUM_OF_MBAS_TO_RUN
        pRangeLimitItr = l_mbaTargetList.begin() + VPO_NUM_OF_MBAS_TO_RUN;
    }
    else
    {
        // process all targets
        pRangeLimitItr = l_mbaTargetList.end();

    }
    // process each target till we reach the limit set above
    for (  TARGETING::TargetHandleList::const_iterator pTargetItr
           = l_mbaTargetList.begin();
           pTargetItr != pRangeLimitItr; pTargetItr++)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = *pTargetItr;

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_dimm_power_test HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mba_target));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                        (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_dimm_power_test, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X: mss_dimm_power_test HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mba_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  call_mss_dimm_power_test HWP( )" );
        }
    } // end l_mbaNum loop

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_dimm_power_test exit" );

    return l_stepError.getErrorHandle();
}



};   // end namespace
