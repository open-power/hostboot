/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/dmi_training.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
 *  @file dmi_training.C
 *
 *  Support file for hardware procedure:
 *      DMI Training
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/**
 * @note    "" comments denote lines that should be built from the HWP
 *          tag block.  See the preliminary design in dmi_training.H
 *          Please save.
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <hwas/common/deconfigGard.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

//  --  prototype   includes    --
#include    "dmi_training.H"
#include    "proc_cen_framelock.H"
#include    "dmi_io_run_training.H"
#include    "proc_dmi_scominit.H"
#include    "cen_dmi_scominit.H"
#include    "io_post_trainadv.H"
#include    "io_pre_trainadv.H"
#include    "proc_cen_set_inband_addr.H"
#include    "mss_get_cen_ecid.H"
#include    "io_restore_erepair.H"
#include <erepairAccessorHwpFuncs.H>
#include    "dmi_io_dccal/dmi_io_dccal.H"
#include    <pbusLinkSvc.H>
#include    <ibscom/ibscomif.H>
#include    <config.h>
#include <ipmi/ipmifruinv.H>

namespace   DMI_TRAINING
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   EDI_EI_INITIALIZATION;

//*****************************************************************
// Function prototypes
//*****************************************************************
void get_dmi_io_targets(TargetPairs_t& o_dmi_io_targets);


//
//  Wrapper function to call dmi_pre_trainadv
//
void*    call_dmi_pre_trainadv( void *io_pArgs )
{
    errlHndl_t l_errl = NULL;
    ISTEP_ERROR::IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_pre_trainadv entry" );

    TargetPairs_t l_dmi_pre_trainadv_targets;
    get_dmi_io_targets(l_dmi_pre_trainadv_targets);

    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);


    // Note:
    // Due to lab tester board environment, HW procedure writer (Varkey) has
    // requested to send in one target of a time (we used to send in
    // the MCS and MEMBUF pair in one call). Even though they don't have to be
    // in order, we should keep the pair concept here in case we need to send
    // in a pair in the future again.
    for (TargetPairs_t::const_iterator
         l_itr = l_dmi_pre_trainadv_targets.begin();
         l_itr != l_dmi_pre_trainadv_targets.end();
         ++l_itr)
    {
        const fapi::Target l_fapi_mcs_target( TARGET_TYPE_MCS_CHIPLET,
                (const_cast<TARGETING::Target*>(l_itr->first)));

        const fapi::Target l_fapi_membuf_target( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_itr->second)));

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "===== Call dmi_pre_trainadv HWP( mcs 0x%.8X, mem 0x%.8X) : ",
                TARGETING::get_huid(l_itr->first),
                TARGETING::get_huid(l_itr->second));

        // Call on the MCS
        FAPI_INVOKE_HWP(l_errl, io_pre_trainadv, l_fapi_mcs_target);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X :  dmi_pre_trainadv HWP Target MCS 0x%.8X",
                      l_errl->reasonCode(), TARGETING::get_huid(l_itr->first));

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
            // We want to continue the training despite the error, so
            // no break
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  call_dmi_pre_trainadv HWP - Target 0x%.8X",
                    TARGETING::get_huid(l_itr->first));
        }

        // Call on the MEMBUF
        FAPI_INVOKE_HWP(l_errl, io_pre_trainadv, l_fapi_membuf_target);
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X :  dmi_pre_trainadv HWP Target Membuf 0x%.8X",
                    l_errl->reasonCode(), TARGETING::get_huid(l_itr->second));

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
            // We want to continue the training despite the error, so
            // no break
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  call_dmi_pre_trainadv HWP - Target 0x%.8X",
                    TARGETING::get_huid(l_itr->second));
        }

    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_dmi_pre_trainadv exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}


//
//  Wrapper function to call dmi_io_run_training
//
void*    call_dmi_io_run_training( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    ISTEP_ERROR::IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_dmi_io_run_training entry" );

    TargetPairs_t l_dmi_io_dccal_targets;
    get_dmi_io_targets(l_dmi_io_dccal_targets);

    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for (TargetPairs_t::const_iterator
         l_itr = l_dmi_io_dccal_targets.begin();
         (!l_err) && (l_itr != l_dmi_io_dccal_targets.end());
         ++l_itr)
    {
        const fapi::Target l_fapi_master_target( TARGET_TYPE_MCS_CHIPLET,
                (const_cast<TARGETING::Target*>(l_itr->first)));

        const fapi::Target l_fapi_slave_target( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_itr->second)));

       TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "===== Call dmi_io_run_training HWP(mcs 0x%x, mem 0x%x ) : ",
               TARGETING::get_huid(l_itr->first),
               TARGETING::get_huid(l_itr->second));

        // dmi_io_run_training reads ATTR_MEMB_TP_BNDY_PLL_LENGTH, the Attribute
        // Accessor (getPllRingAttr) needs to read ATTR_MSS_FREQ to find the
        // ring data to get its length, but ATTR_MSS_FREQ is not yet setup, this
        // is done by mss_freq. However, the ring length is the same for a
        // particular EC level, the frequency only selects the data. Ideally the
        // Accessor would be able to return the ring length without a frequency,
        // a workaround is to set ATTR_MSS_FREQ to a default value here
        TARGETING::Target* l_membuf_target =
            (const_cast<TARGETING::Target*>(l_itr->second));
        l_membuf_target->setAttr<TARGETING::ATTR_MSS_FREQ>(1600);

        FAPI_INVOKE_HWP(l_err, dmi_io_run_training,
                        l_fapi_master_target, l_fapi_slave_target);

        // Clear ATTR_MSS_FREQ.
        l_membuf_target->setAttr<TARGETING::ATTR_MSS_FREQ>(0);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X :  dmi_io_run_training HWP",
                      l_err->reasonCode());

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_err);

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  dmi_io_run_training HWP");
        }

    }   // end target pair list

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "call_dmi_io_run_training exit" );

    return l_StepError.getErrorHandle();
}

//
//  Wrapper function to call dmi_post_trainadv
//
void*    call_dmi_post_trainadv( void *io_pArgs )
{
    errlHndl_t l_errl = NULL;
    ISTEP_ERROR::IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_post_trainadv entry" );

    TargetPairs_t l_dmi_post_trainadv_targets;
    get_dmi_io_targets(l_dmi_post_trainadv_targets);

    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);


    // Note:
    // Due to lab tester board environment, HW procedure writer (Varkey) has
    // requested to send in one target of a time (we used to send in
    // the MCS and MEMBUF pair in one call). Even though they don't have to be
    // in order, we should keep the pair concept here in case we need to send
    // in a pair in the future again.
    for (TargetPairs_t::const_iterator
         l_itr = l_dmi_post_trainadv_targets.begin();
         l_itr != l_dmi_post_trainadv_targets.end();
         ++l_itr)
    {
        const fapi::Target l_fapi_mcs_target( TARGET_TYPE_MCS_CHIPLET,
                (const_cast<TARGETING::Target*>(l_itr->first)));

        const fapi::Target l_fapi_membuf_target( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_itr->second)));

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "===== Call dmi_post_trainadv HWP( mcs 0x%.8X, mem 0x%.8X) : ",
                TARGETING::get_huid(l_itr->first),
                TARGETING::get_huid(l_itr->second));

        // Call on the MCS
        FAPI_INVOKE_HWP(l_errl, io_post_trainadv, l_fapi_mcs_target);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X :  dmi_post_trainadv HWP Target MCS 0x%.8X",
                      l_errl->reasonCode(), TARGETING::get_huid(l_itr->first));

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
            // We want to continue the training despite the error, so
            // no break
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  call_dmi_post_trainadv HWP - Target 0x%.8X",
                    TARGETING::get_huid(l_itr->first));
        }

        // Call on the MEMBUF
        FAPI_INVOKE_HWP(l_errl, io_post_trainadv, l_fapi_membuf_target);
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR 0x%.8X :  dmi_post_trainadv HWP Target Membuf 0x%.8X",
                   l_errl->reasonCode(), TARGETING::get_huid(l_itr->second));

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
            // We want to continue the training despite the error, so
            // no break
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  call_dmi_post_trainadv HWP - Target 0x%.8X",
                    TARGETING::get_huid(l_itr->second));
        }

    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_dmi_post_trainadv exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}


//
//  Wrapper function to call  proc_cen_framelock
//
void*    call_proc_cen_framelock( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    proc_cen_framelock_args     l_args;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_proc_cen_framework entry" );

    //  get the mcs chiplets
    TARGETING::TargetHandleList l_mcsTargetList;
    getAllChiplets(l_mcsTargetList, TYPE_MCS);

    for (TargetHandleList::const_iterator
            l_mcs_iter = l_mcsTargetList.begin();
            l_mcs_iter != l_mcsTargetList.end();
            ++l_mcs_iter)
    {
        //  make a local copy of the MCS target
        TARGETING::Target*  l_mcs_target = *l_mcs_iter;

        //  find all the Centaurs that are associated with this MCS
        TARGETING::TargetHandleList l_memTargetList;
        getChildAffinityTargets(l_memTargetList, l_mcs_target,
                 CLASS_CHIP, TYPE_MEMBUF);

        for (TargetHandleList::const_iterator
                l_mem_iter = l_memTargetList.begin();
                l_mem_iter != l_memTargetList.end();
                ++l_mem_iter)
        {
            //  make a local copy of the MEMBUF target
            TARGETING::Target*  l_mem_target = *l_mem_iter;

            uint8_t l_memNum = l_mem_target->getAttr<ATTR_POSITION>();

            // fill out the args struct.
            l_args.channel_init_timeout =   CHANNEL_INIT_TIMEOUT_NO_TIMEOUT;
            l_args.frtl_auto_not_manual =   true;
            l_args.frtl_manual_pu       =   0;
            l_args.frtl_manual_mem      =   0;

            fapi::Target l_fapiMcsTarget( TARGET_TYPE_MCS_CHIPLET,
                        (const_cast<TARGETING::Target*>(l_mcs_target)));
            fapi::Target l_fapiMemTarget( TARGET_TYPE_MEMBUF_CHIP,
                        (const_cast<TARGETING::Target*>(l_mem_target)));

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "mcs HUID %.8X mem HUID %.8X",
                TARGETING::get_huid(l_mcs_target),
                TARGETING::get_huid(l_mem_target));

            FAPI_INVOKE_HWP( l_err,
                             proc_cen_framelock,
                             l_fapiMcsTarget,
                             l_fapiMemTarget,
                             l_args  );
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                 "ERROR 0x%.8X : proc_cen_framelock HWP( mem %d )",
                l_err->reasonCode(), l_memNum );

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_err);

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );

            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  proc_cen_framelock HWP( mem %d ) ",
                        l_memNum );
            }

        }   // end mem

    }   // end mcs

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_cen_framework exit" );

    return l_StepError.getErrorHandle();
}

//
//  Wrapper function to call host_startprd_dmi
//
void*    call_host_startprd_dmi( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_startPRD_dmi entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_startPRD_dmi exit" );

    return l_err;
}

//
//  Wrapper function to call host_attnlisten_cen
//
void*    call_host_attnlisten_cen( void *io_pArgs )
{

    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_attnlisten_cen entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_attnlisten_cen exit" );

    return l_err;
}

//
//  Wrapper function to call cen_set_inband_addr
//
void*    call_cen_set_inband_addr( void *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_err = NULL;;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_cen_set_inband_addr entry" );

    do{
        //  get the mcs chiplets
        TARGETING::TargetHandleList l_mcsTargetList;
        getAllChiplets(l_mcsTargetList, TYPE_MCS);

        for (TargetHandleList::const_iterator
             l_mcs_iter = l_mcsTargetList.begin();
             l_mcs_iter != l_mcsTargetList.end();
             ++l_mcs_iter)
        {
            TARGETING::Target* l_pTarget = *l_mcs_iter;
            const fapi::Target
              l_fapi_target( TARGET_TYPE_MCS_CHIPLET,
                             (const_cast<TARGETING::Target*>(l_pTarget)));

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Running cen_set_inband_addr HWP on "
                      "target HUID %.8X", TARGETING::get_huid(l_pTarget));

            FAPI_INVOKE_HWP(l_err, proc_cen_set_inband_addr, l_fapi_target);
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR 0x%.8X : proc_cen_set_inband_addr HWP",
                           l_err->reasonCode());

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_pTarget).addToLog( l_err );

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_err);

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );

            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  proc_cen_set_inband_addr HWP");
            }
        }   // end for mcs

        l_err = l_StepError.getErrorHandle();

        //Now enable Inband SCOM for all membuf chips.
        IBSCOM::enableInbandScoms();
    }while(0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_cen_set_inband_addr exit" );

    return l_err;
}

//
//  Utility function to get DMI IO target list
//  First is MCS target, Second is MEMBUF target
//
void get_dmi_io_targets(TargetPairs_t& o_dmi_io_targets)
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "get_dmi_io_targets" );

    o_dmi_io_targets.clear();
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for ( TargetHandleList::const_iterator
          l_iter = l_cpuTargetList.begin();
          l_iter != l_cpuTargetList.end();
          ++l_iter )
    {
        //  make a local copy of the CPU target
        const TARGETING::Target*  l_cpu_target = *l_iter;

        // find all MCS chiplets of the proc
        TARGETING::TargetHandleList l_mcsTargetList;
        getChildChiplets( l_mcsTargetList, l_cpu_target, TYPE_MCS );

        for ( TargetHandleList::const_iterator
              l_iterMCS = l_mcsTargetList.begin();
              l_iterMCS != l_mcsTargetList.end();
              ++l_iterMCS )
        {
            //  make a local copy of the MCS target
            const TARGETING::Target*  l_mcs_target = *l_iterMCS;

            //  find all the Centaurs that are associated with this MCS
            TARGETING::TargetHandleList l_memTargetList;
            getChildAffinityTargets(l_memTargetList, l_mcs_target,
                     CLASS_CHIP, TYPE_MEMBUF);

            for ( TargetHandleList::const_iterator
                    l_iterMemBuf = l_memTargetList.begin();
                    l_iterMemBuf != l_memTargetList.end();
                    ++l_iterMemBuf )
            {
                //  make a local copy of the MEMBUF target
                const TARGETING::Target*  l_mem_target = *l_iterMemBuf;
                o_dmi_io_targets.insert(std::pair<const TARGETING::Target*,
                  const TARGETING::Target*>(l_mcs_target, l_mem_target));

            }  //end for l_mem_target

        }   // end for l_mcs_target

    }   // end for l_cpu_target

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "get_dmi_io_targets exit" );

    return;
}

};   // end namespace

