/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/dram_training.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
/* [+] Google Inc.                                                        */
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
#include    <map>

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
#include "platform_vddr.H"
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
    IStepError l_StepError;

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              ENTER_MRK"call_host_disable_vddr");

    // This function has Compile-time binding for desired platform
    l_err = platform_disable_vddr();

    if(l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR 0x%.8X: call_host_disable_vddr returns error",
                  l_err->reasonCode());
        // Create IStep error log and cross reference to error that occurred
        l_StepError.addErrorDetails( l_err );

        errlCommit( l_err, HWPF_COMP_ID );

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"call_host_disable_vddr");

    return l_StepError.getErrorHandle();
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

            //Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails(l_err);

            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: cen_mem_pll_initf HWP( )" );
        }
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

            //Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails(l_err);

            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: mem_pll_setup HWP( )" );
        }
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

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"call_mem_startclocks entry" );

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

            //Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS :  cen_mem_startclocks HWP( )" );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mem_startclocks exit" );

    return l_StepError.getErrorHandle();
}



//
//  Wrapper function to call host_enable_vddr
//
void*    call_host_enable_vddr( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            ENTER_MRK"call_host_enable_vddr" );

    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    // This fuction has compile-time binding for different platforms
    l_err = platform_enable_vddr();

    if( l_err )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR 0x%.8X: call_host_enable_vddr returns error",
                  l_err->reasonCode());

        l_StepError.addErrorDetails( l_err );

        // Create IStep error log and cross reference to error that occurred
        l_StepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"call_host_enable_vddr" );

    return l_StepError.getErrorHandle();
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

                // Create IStep error log and cross reference to error that
                // occurred
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  mss_scominit HWP( )" );
            }
        }
        if (!l_stepError.isNull())
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
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_draminit_mc HWP( )" );
        }

    } // End; memBuf loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_mc exit" );

    return l_stepError.getErrorHandle();
}

//
//  support functions for mss_dimm_power_test wrapper
//
typedef bool (*mss_dimm_power_test_helper_t) (TARGETING::Target*, bool &);

// helper function to set the change bit for present non-functional targets
bool mss_dimm_power_test_set (TARGETING::Target* i_target,
                                bool &o_keepChecking)
{
    bool l_changed = false;
    o_keepChecking = true;

    if ((!i_target->getAttr<ATTR_HWAS_STATE>().functional) &&
                (i_target->getAttr<ATTR_HWAS_STATE>().present))
    {
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "===== membuf %.8x non func change flag set",
                          get_huid(i_target));

        update_hwas_changed_mask( i_target,
                                HWAS_CHANGED_BIT_DIMM_POWER_TEST);

        l_changed = true;
    }
    return l_changed;
}

// helper function to check if change bit set, stop checking if found
bool mss_dimm_power_test_check (TARGETING::Target* i_target,
                                bool &o_keepChecking)
{
    bool l_changed = false;
    o_keepChecking = true;

    ATTR_HWAS_STATE_CHANGED_FLAG_type hwChangeFlag;
    hwChangeFlag=i_target->getAttr<ATTR_HWAS_STATE_CHANGED_FLAG>();

    if(HWAS_CHANGED_BIT_DIMM_POWER_TEST & hwChangeFlag)
    {
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "===== membuf %.8x change flag set",
                          get_huid(i_target));
        l_changed = true;
        o_keepChecking = false;
    }
    return l_changed;
};

// helpfer function to clear any set change bits
bool mss_dimm_power_test_clear (TARGETING::Target* i_target,
                                bool &o_keepChecking)
{
    bool l_changed = false;
    o_keepChecking = true;

    ATTR_HWAS_STATE_CHANGED_FLAG_type hwChangeFlag;
    hwChangeFlag=i_target->getAttr<ATTR_HWAS_STATE_CHANGED_FLAG>();

    if(HWAS_CHANGED_BIT_DIMM_POWER_TEST & hwChangeFlag)
    {
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "===== membuf %.8x clear set change bit",
                          get_huid(i_target));

        clear_hwas_changed_bit( i_target,
                                HWAS_CHANGED_BIT_DIMM_POWER_TEST);

        l_changed = true;
    }
    return l_changed;
};

//  Process change bits on Membuf, MBA, and associated DIMMs
//  i_membufTargetList - list of membufs to transverse
//  i_cmd - mss_dimm_power_test_cmds

enum mss_dimm_power_test_cmds
{
    MSS_DIMM_POWER_TEST_SETNONFUNCTIONAL, //set change if present non-functional
                                          // return true if any are set
    MSS_DIMM_POWER_TEST_CHECK,            //check if any change bits set
                                          // return true if any set
    MSS_DIMM_POWER_TEST_CLEAR,            //clear all change bits
                                          // return true if any cleared
};
bool  mss_dimm_power_test_process_change_bits (
                        TARGETING::TargetHandleList * i_pMembufTargetList,
                        mss_dimm_power_test_cmds i_cmd)
{
    bool l_change = false;    // return value. Found any?
    bool l_keepChecking = true; // loop exit control
    mss_dimm_power_test_helper_t (l_pFunction) = &mss_dimm_power_test_check;

    bool l_functional = true; //default to functional search

    // set up function controls
    switch (i_cmd)
    {
        case MSS_DIMM_POWER_TEST_SETNONFUNCTIONAL:
            l_functional = false; // get all targets, not just functional
            l_pFunction = &mss_dimm_power_test_set;
            break;
        case MSS_DIMM_POWER_TEST_CHECK:
            l_pFunction = &mss_dimm_power_test_check;
            break;
        case MSS_DIMM_POWER_TEST_CLEAR:
            l_pFunction = &mss_dimm_power_test_clear;
            break;
    }

    // process membufs and downstream MBAs and DIMMs
    for (TargetHandleList::const_iterator
                l_membuf_iter = (*i_pMembufTargetList).begin();
                l_membuf_iter != (*i_pMembufTargetList).end();
                ++l_membuf_iter)
    {
        l_change |= (*l_pFunction) (*l_membuf_iter,l_keepChecking);
        if (!l_keepChecking) break;

        // process MBAs and downstream DIMMs
        TARGETING::TargetHandleList l_mbaTargetList;
        getChildAffinityTargets(l_mbaTargetList,*l_membuf_iter,
                            CLASS_UNIT,TYPE_MBA,
                            l_functional);
        for (TargetHandleList::const_iterator
                    l_mba_iter = l_mbaTargetList.begin();
                    l_mba_iter != l_mbaTargetList.end();
                    ++l_mba_iter)
        {
            l_change |= (*l_pFunction) (*l_mba_iter,l_keepChecking);
            if (!l_keepChecking) break;

            // process DIMMs
            TARGETING::TargetHandleList l_dimmTargetList;
            getChildAffinityTargets(l_dimmTargetList, *l_mba_iter,
                                CLASS_LOGICAL_CARD, TYPE_DIMM,
                                l_functional);
            for (TargetHandleList::const_iterator
                        l_dimm_iter = l_dimmTargetList.begin();
                        l_dimm_iter != l_dimmTargetList.end();
                        ++l_dimm_iter)
            {
                l_change |= (*l_pFunction) (*l_dimm_iter,l_keepChecking);
                if (!l_keepChecking) break;
            } // loop on DIMMS associated with MBA
            if (!l_keepChecking) break; // no need to check any further
        }  // loop on MBAs off membuf
        if (!l_keepChecking) break; // no need to check any further
    } // loop on passed mem buf list

    return l_change;
}

//
//  Wrapper function to call mss_dimm_power_test
//
void*    call_mss_dimm_power_test( void *io_pArgs )
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_dimm_power_test entry" );

    IStepError l_stepError;

    errlHndl_t l_err = NULL;
    //----------------------------------------------------------------------
    // only calculate the ISDIMM power curves if needed.
    // The version of the calculation algorithm and dependent attribute
    // values are hashed and saved to see if anything has changed.
    // If the saved version has changed, then a recalcuation is advised.
    // If hardware has changed, then recalcuation is advised.
    //----------------------------------------------------------------------
    do
    {
        uint32_t l_persistentAlgorithmVersion = ALGORITHM_RESET;
        uint32_t l_hwpAlgorithmVersion = ALGORITHM_RESET;
        bool     l_versionChange = false;
        bool     l_anyCalculationErrors = false;

        // Get saved algorithm version
        TargetHandle_t top = 0;
        targetService().getTopLevelTarget(top);

        l_persistentAlgorithmVersion =
           top->getAttr<TARGETING::ATTR_ISDIMM_POWER_CURVE_ALGORITHM_VERSION>();

        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_mss_dimm_power_test entry persistent algorithm version=%d",
              l_persistentAlgorithmVersion );

        // Get current hwp algorithm version
        std::vector<fapi::Target> l_membufFapiTargets;
        bool l_dc = false;
        FAPI_INVOKE_HWP ( l_err,
                          mss_dimm_power_test,
                          l_membufFapiTargets,  // empty list
                          RETURN_ALGORITHM_VERSION,
                          l_hwpAlgorithmVersion,
                          l_dc)   // don't care parm
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                 "ERROR 0x%.8X: call_mss_dimm_power_test HWP get version error",
                 l_err->reasonCode());
            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails(l_err);
            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);

            break; // fail istep
        }
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_dimm_power_test entry hwp algorithm version=%d",
                l_hwpAlgorithmVersion );

        // advise hwp to recalculate if stored version does not match current
        l_versionChange = l_persistentAlgorithmVersion != l_hwpAlgorithmVersion;

        //----------------------------------------------------------------------
        // Set the change bit for all present non-functional Membufs, MBA, and
        // DIMMs. In case they come back, want to be sure to recalculate
        //----------------------------------------------------------------------
        TARGETING::TargetHandleList l_membufTargetList;
        getAllChips(l_membufTargetList, TYPE_MEMBUF,false);

        mss_dimm_power_test_process_change_bits (
                              &l_membufTargetList,
                              MSS_DIMM_POWER_TEST_SETNONFUNCTIONAL);

        l_membufTargetList.clear();

        //----------------------------------------------------------------------
        // Call mss_dimm_power_test with lists of fucntional mem buffs that
        // the have the same vmem id.
        // For each group, check for hardware changes
        //----------------------------------------------------------------------
        getAllChips(l_membufTargetList, TYPE_MEMBUF,true); //just functional

        // Build a map of unique vmem ids to the list of mem buffs with that
        // vmem id.
        std::map<ATTR_VMEM_ID_type,TARGETING::TargetHandleList>
                                                    l_vmemidTargetlistMap;
        for (TargetHandleList::const_iterator
                l_membuf_iter = l_membufTargetList.begin();
                l_membuf_iter != l_membufTargetList.end();
                ++l_membuf_iter)
        {
            TARGETING::ATTR_VMEM_ID_type l_VmemID =
                            (*l_membuf_iter)->getAttr<ATTR_VMEM_ID>();

            l_vmemidTargetlistMap[l_VmemID].push_back(*l_membuf_iter);

        }

        // For the subset list of mem buffs for each unique vmem id,
        // check for hw changes on those targets (membuf, MBA,
        // DIMMs). Then call the hwp to calculate the power curve, advising
        // if the algorithm version has changed or if there are hw changes.
        std::map<ATTR_VMEM_ID_type,TARGETING::TargetHandleList>::iterator
                                                                   l_vmemidItr;
        for (l_vmemidItr = l_vmemidTargetlistMap.begin();
             l_vmemidItr != l_vmemidTargetlistMap.end();
             ++l_vmemidItr)
        {
            std::vector<fapi::Target> l_membufFapiTargets; // to pass to hwp
            TARGETING::TargetHandleList * l_pMembufSubsetList =
                       &(l_vmemidItr->second);//list of membufs for this vmem id

            // make a list of fapi targets to pass to the hwp
            for (TargetHandleList::const_iterator
                    l_membuf_iter = (*l_pMembufSubsetList).begin();
                    l_membuf_iter != (*l_pMembufSubsetList).end();
                    ++l_membuf_iter)
            {

                fapi::Target l_membuf_fapi_target
                            (fapi::TARGET_TYPE_MEMBUF_CHIP,
                            (const_cast<TARGETING::Target*>(*l_membuf_iter)) );

                l_membufFapiTargets.push_back( l_membuf_fapi_target );
            }

            // check for hw changes
            bool l_hwChange = mss_dimm_power_test_process_change_bits (
                              l_pMembufSubsetList,
                              MSS_DIMM_POWER_TEST_CHECK);

            // advise recalculation when:
            // 1) The stored algorthim and dependencies have changed
            // 2) Hardware has changed
            bool l_recalc = l_hwChange || l_versionChange;

            uint32_t l_dc = ALGORITHM_RESET;
            FAPI_INVOKE_HWP ( l_err,
                          mss_dimm_power_test,
                          l_membufFapiTargets, //list of membufs
                          CALCULATE,
                          l_dc,     // don't care about version parm
                          l_recalc);
            if ( l_err )
            {
                l_anyCalculationErrors = true; // don't update algorithm version

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X: from  mss_dimm_power_test HWP( ) ",
                    l_err->reasonCode());

                // Create IStep error log and cross reference
                // to error that occurred
                l_stepError.addErrorDetails( l_err );

                // Commit Error, and keep going
                errlCommit( l_err, HWPF_COMP_ID );
            }
            else
            {
                // success, so clear change flags if any set
                if (l_hwChange)
                {
                    mss_dimm_power_test_process_change_bits (
                              l_pMembufSubsetList,
                              MSS_DIMM_POWER_TEST_CLEAR);
                }
            }

        } // for each unique vme_id

        //----------------------------------------------------------------------
        // If there have not been any errors, update the saved
        // algorithm version.
        //----------------------------------------------------------------------

        if  (!l_anyCalculationErrors  &&
            (l_persistentAlgorithmVersion != l_hwpAlgorithmVersion) )
        {
            top->setAttr<TARGETING::ATTR_ISDIMM_POWER_CURVE_ALGORITHM_VERSION>
                       (l_hwpAlgorithmVersion);

            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_mss_dimm_power_test set persistent algorithm version=%d",
                l_hwpAlgorithmVersion );
        }

    } while (0);


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_dimm_power_test exit" );

    return l_stepError.getErrorHandle();
}

};   // end namespace
