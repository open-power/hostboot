/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/dmi_training.C $                */
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

#include    <hwpisteperror.H>
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
//  Wrapper function to call mss_getecid
//
void*    call_mss_getecid( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_StepError;
    uint8_t    l_ddr_port_status = 0;
    uint8_t    l_cache_enable = 0;
    uint8_t    l_centaur_sub_revision = 0;
    ecid_user_struct l_ecidUser;  // Do not need to be initalized by caller

    mss_get_cen_ecid_ddr_status l_mbaBadMask[2] =
       { MSS_GET_CEN_ECID_DDR_STATUS_MBA0_BAD,
         MSS_GET_CEN_ECID_DDR_STATUS_MBA1_BAD };

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_getecid entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        TARGETING::Target* l_pCentaur = *l_membuf_iter;

        // Dump current run on target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_get_cen_ecid HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_pCentaur)) );

        //  call the HWP with each fapi::Target
        //  Note:  This HWP does not actually return the entire ECID data.  It
        //  updates the attribute ATTR_MSS_ECID and returns the DDR port status
        //  which is a portion of the ECID data.
        FAPI_INVOKE_HWP(l_err, mss_get_cen_ecid,
                        l_fapi_centaur, l_ddr_port_status,
                        l_cache_enable, l_centaur_sub_revision, l_ecidUser);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: mss_get_cen_ecid HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog( l_err );

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            if (MSS_GET_CEN_ECID_DDR_STATUS_ALL_GOOD != l_ddr_port_status)
            {
                // Check the DDR port status returned by mss_get_cen_ecid to
                // see which MBA is bad.  If the MBA's state is
                // functional and the DDR port status indicates that it's bad,
                // then set the MBA to nonfunctional.  If the MBA's state is
                // nonfunctional, then do nothing since we don't want to
                // override previous settings.

                // Find the functional MBAs associated with this Centaur
                PredicateCTM l_mba_pred(CLASS_UNIT,TYPE_MBA);
                TARGETING::TargetHandleList l_mbaTargetList;
                getChildChiplets(l_mbaTargetList,
                                 l_pCentaur,
                                 TYPE_MBA);

                uint8_t l_num_func_mbas = l_mbaTargetList.size();

                for (TargetHandleList::const_iterator
                        l_mba_iter = l_mbaTargetList.begin();
                        l_mba_iter != l_mbaTargetList.end();
                        ++l_mba_iter)
                {
                    //  Make a local copy of the target for ease of use
                    TARGETING::Target*  l_pMBA = *l_mba_iter;

                    // Get the MBA chip unit position
                    ATTR_CHIP_UNIT_type l_pos =
                        l_pMBA->getAttr<ATTR_CHIP_UNIT>();

                    // Check the DDR port status to see if this MBA should be
                    // set to nonfunctional.
                    if ( l_ddr_port_status & l_mbaBadMask[l_pos] )
                    {
                        // call HWAS to deconfigure this target
                        l_err = HWAS::theDeconfigGard().deconfigureTarget(
                                    *l_pMBA, HWAS::DeconfigGard::
                                                DECONFIGURED_BY_MEMORY_CONFIG);
                        l_num_func_mbas--;

                        if (l_err)
                        {
                            // shouldn't happen, but if it does, stop trying to
                            //  deconfigure targets..
                            break;
                        }
                    }
                } // for

                if (l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "ERROR: error deconfiguring MBA or Centaur");

                    // Create IStep error log and cross ref error that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, HWPF_COMP_ID );
                }
            }

            // mss_get_cen_ecid returns if the L4 cache is enabled. This can be
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_OFF
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_ON
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_A
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_B
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_OFF
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_ON
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_HALF_A
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_HALF_B
            // The UNK values are for DD1.* Centaur chips where the fuses were
            // not blown correctly so the cache may not be in the correct state.
            //
            // Firmware does not normally support HALF enabled
            // If ON then ATTR_MSS_CACHE_ENABLE is set to ON
            // Else ATTR_MSS_CACHE_ENABLE is set to OFF and the L4 Target is
            //   deconfigured
            //
            // However, an engineer can override ATTR_MSS_CACHE_ENABLE. If they
            // override it to HALF_A or HALF_B then
            // - ATTR_MSS_CACHE_ENABLE is set to HALF_X
            // - The L4 Target is not deconfigured
            if (l_cache_enable != fapi::ENUM_ATTR_MSS_CACHE_ENABLE_ON)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: mss_get_cen_ecid returned L4 not-on (0x%02x)",
                    l_cache_enable);
                l_cache_enable = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_OFF;
            }

            // Set the ATTR_MSS_CACHE_ENABLE attribute
            l_pCentaur->setAttr<TARGETING::ATTR_MSS_CACHE_ENABLE>(
                l_cache_enable);

            // Read the ATTR_MSS_CACHE_ENABLE back to pick up any override
            uint8_t l_cache_enable_attr =
                l_pCentaur->getAttr<TARGETING::ATTR_MSS_CACHE_ENABLE>();

            if (l_cache_enable != l_cache_enable_attr)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: ATTR_MSS_CACHE_ENABLE override (0x%02x)",
                    l_cache_enable_attr);
            }

            // At this point HALF_A/HALF_B are only possible due to override
            if ((l_cache_enable_attr !=
                 fapi::ENUM_ATTR_MSS_CACHE_ENABLE_ON) &&
                (l_cache_enable_attr !=
                 fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_A) &&
                (l_cache_enable_attr !=
                 fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_B))
            {
                // Deconfigure the L4 Cache Targets (there should be 1)
                TargetHandleList l_list;
                getChildChiplets(l_list, l_pCentaur, TYPE_L4, false);

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: deconfiguring %d L4s (Centaur huid: 0x%.8X)",
                    l_list.size(), get_huid(l_pCentaur));

                for (TargetHandleList::const_iterator
                        l_l4_iter = l_list.begin();
                        l_l4_iter != l_list.end();
                        ++l_l4_iter)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_mss_getecid: deconfiguring L4 (huid: 0x%.8X)",
                        get_huid( *l_l4_iter));

                    l_err = HWAS::theDeconfigGard().
                        deconfigureTarget(**l_l4_iter ,
                                    HWAS::DeconfigGard::
                                                DECONFIGURED_BY_MEMORY_CONFIG);

                    if (l_err)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                  "ERROR: error deconfiguring Centaur L4");

                        // Create IStep error log
                        //   and cross reference error that occurred
                        l_StepError.addErrorDetails( l_err);

                        // Commit Error
                        errlCommit(l_err, HWPF_COMP_ID);
                        break;
                    }
                }
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: Centaur L4 good, not deconfiguring");
            }
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS :  mss_get_cen_ecid HWP( )" );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_getecid exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

//
// Wrapper function to call dmi_attr_update
//
void * call_dmi_attr_update( void * io_pArgs )
{
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_dmi_attr_update entry" );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_dmi_attr_update exit" );

    return l_StepError.getErrorHandle();

}

//
//  Wrapper function to call proc_dmi_scominit
//
void*    call_proc_dmi_scominit( void *io_pArgs )
{
    errlHndl_t l_errl = NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_dmi_scominit entry" );

    // Get all functional MCS chiplets
    TARGETING::TargetHandleList l_mcsTargetList;
    getAllChiplets(l_mcsTargetList, TYPE_MCS);

    // Invoke dmi_scominit on each one
    for (TargetHandleList::const_iterator
            l_mcs_iter = l_mcsTargetList.begin();
            l_mcs_iter != l_mcsTargetList.end();
            ++l_mcs_iter)
    {
        const TARGETING::Target* l_pTarget = *l_mcs_iter;
        const fapi::Target l_fapi_target( TARGET_TYPE_MCS_CHIPLET,
                (const_cast<TARGETING::Target*>(l_pTarget)));

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_dmi_scominit HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pTarget));

        FAPI_INVOKE_HWP(l_errl, proc_dmi_scominit, l_fapi_target);
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X : proc_dmi_scominit HWP returns error",
                        l_errl->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pTarget).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "SUCCESS :  proc_dmi_scominit HWP");
        }
    }

    if( l_errl )
    {

        // Create IStep error log and cross reference error that occurred
        l_StepError.addErrorDetails( l_errl);

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_dmi_scominit exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

//
//  Wrapper function to call dmi_scominit
//
void*    call_dmi_scominit( void *io_pArgs )
{
    errlHndl_t l_errl = NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_scominit entry" );

    // Get all functional membuf chips
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    // Invoke dmi_scominit on each one
    for (TargetHandleList::iterator l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        const TARGETING::Target* l_pTarget = *l_membuf_iter;
        const fapi::Target l_fapi_target(
            TARGET_TYPE_MEMBUF_CHIP,
            reinterpret_cast<void *>
                (const_cast<TARGETING::Target*>(l_pTarget)));

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Running cen_dmi_scominit HWP on...");
        EntityPath l_path;
        l_path = l_pTarget->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        FAPI_INVOKE_HWP(l_errl, cen_dmi_scominit, l_fapi_target);
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : cen_dmi_scominit HWP returns error",
                      l_errl->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pTarget).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "SUCCESS :  dmi_scominit HWP");
        }
    }

    if( l_errl )
    {
        // Create IStep error log and cross reference error that occurred
        l_StepError.addErrorDetails( l_errl);

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_scominit exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}


//
//  Wrapper function to call  dmi_erepair
//
void* call_dmi_erepair( void *io_pArgs )
{
    ISTEP_ERROR::IStepError l_StepError;
    errlHndl_t l_errPtr = NULL;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_erepair entry" );

    fapi::ReturnCode l_rc;
    std::vector<uint8_t> l_endp1_txFaillanes;
    std::vector<uint8_t> l_endp1_rxFaillanes;
    std::vector<uint8_t> l_endp2_txFaillanes;
    std::vector<uint8_t> l_endp2_rxFaillanes;
    uint32_t             l_count   = 0;

    TargetHandleList           l_mcsTargetList;
    TargetHandleList           l_memTargetList;
    TargetHandleList::iterator l_mem_iter;

    // find all MCS chiplets of all procs
    getAllChiplets(l_mcsTargetList, TYPE_MCS);

    for (TargetHandleList::const_iterator
         l_mcs_iter = l_mcsTargetList.begin();
         l_mcs_iter != l_mcsTargetList.end();
         ++l_mcs_iter)
    {
        // make a local copy of the MCS target
        TARGETING::Target *l_mcs_target = *l_mcs_iter;
        ATTR_CHIP_UNIT_type l_mcsNum = l_mcs_target->getAttr<ATTR_CHIP_UNIT>();

        // find all the Centaurs that are associated with this MCS
        getChildAffinityTargets(l_memTargetList, l_mcs_target,
                       CLASS_CHIP, TYPE_MEMBUF);

        if(l_memTargetList.size() != EREPAIR_MAX_CENTAUR_PER_MCS)
        {
            continue;
        }

        // There will always be 1 Centaur associated with a MCS
        l_mem_iter = l_memTargetList.begin();

        // make a local copy of the MEMBUF target
        TARGETING::Target *l_mem_target = *l_mem_iter;
        ATTR_POSITION_type l_memNum = l_mem_target->getAttr<ATTR_POSITION>();

        // struct containing custom parameters that is fed to HWP
        // call the HWP with each target(if parallel, spin off a task)
        const fapi::Target l_fapi_endp1_target(TARGET_TYPE_MCS_CHIPLET,
                                               l_mcs_target);

        const fapi::Target l_fapi_endp2_target(TARGET_TYPE_MEMBUF_CHIP,
                                               l_mem_target);

        // Get the repair lanes from the VPD
        l_endp1_txFaillanes.clear();
        l_endp1_rxFaillanes.clear();
        l_endp2_txFaillanes.clear();
        l_endp2_rxFaillanes.clear();
        l_rc = erepairGetRestoreLanes(l_fapi_endp1_target,
                                      l_endp1_txFaillanes,
                                      l_endp1_rxFaillanes,
                                      l_fapi_endp2_target,
                                      l_endp2_txFaillanes,
                                      l_endp2_rxFaillanes);

        if(l_rc)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Unable to"
                      " retrieve DMI eRepair data from the VPD");
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_mem_target));

            // Convert fapi returnCode to Error handle
            l_errPtr = fapiRcToErrl(l_rc);

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mcs_target).addToLog(l_errPtr);
            ErrlUserDetailsTarget(l_mem_target).addToLog(l_errPtr);

           // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errPtr);

            // Commit Error
            errlCommit(l_errPtr, HWPF_COMP_ID);

            break;
        }

        if(l_endp1_txFaillanes.size() || l_endp1_rxFaillanes.size())
        {
            // call the io_restore_erepair HWP to restore eRepair
            // lanes of endp1

            TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                   "io_restore_erepair HWP on %s"
                                   " ( mcs 0x%x, mem 0x%x ) : ",
                                   l_fapi_endp1_target.toEcmdString(),
                                   l_mcsNum,
                                   l_memNum );

            FAPI_INVOKE_HWP(l_errPtr,
                            io_restore_erepair,
                            l_fapi_endp1_target,
                            l_endp1_txFaillanes,
                            l_endp1_rxFaillanes);
            if(l_errPtr)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                             "ERROR 0x%.8X : io_restore_erepair HWP"
                             "( mcs 0x%x, mem 0x%x ) ",
                             l_errPtr->reasonCode(),
                             l_mcsNum,
                             l_memNum);

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_mcs_target).addToLog(l_errPtr);

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errPtr);

                // Commit Error
                errlCommit(l_errPtr, HWPF_COMP_ID);
                break;
            }

            for(l_count = 0; l_count < l_endp1_txFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Tx lane %d, of DMI-Bus, of endpoint %s",
                          l_endp1_txFaillanes[l_count],
                          l_fapi_endp1_target.toEcmdString());
            }

            for(l_count = 0; l_count < l_endp1_rxFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Rx lane %d, of DMI-Bus, of endpoint %s",
                          l_endp1_rxFaillanes[l_count],
                          l_fapi_endp1_target.toEcmdString());
            }
        } // end of if(l_endp1_txFaillanes.size() || l_endp1_rxFaillanes.size())

        if(l_endp2_txFaillanes.size() || l_endp2_rxFaillanes.size())
        {
            // call the io_restore_erepair HWP to restore eRepair
            // lanes of endp2

            TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                   "io_restore_erepair HWP on %s"
                                   " ( mcs 0x%x, mem 0x%x ) : ",
                                   l_fapi_endp2_target.toEcmdString(),
                                   l_mcsNum,
                                   l_memNum );
            FAPI_INVOKE_HWP(l_errPtr,
                            io_restore_erepair,
                            l_fapi_endp2_target,
                            l_endp2_txFaillanes,
                            l_endp2_rxFaillanes);
            if (l_errPtr)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                             "ERROR 0x%.8X : io_restore_erepair HWP"
                              "( mcs 0x%x, mem 0x%x ) ",
                              l_errPtr->reasonCode(),
                              l_mcsNum,
                              l_memNum);

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_mem_target).addToLog(l_errPtr);

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errPtr);

                // Commit Error
                errlCommit(l_errPtr, HWPF_COMP_ID);
                break;
            }

            for(l_count = 0; l_count < l_endp2_txFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Tx lane %d, of DMI-Bus, of endpoint %s",
                          l_endp2_txFaillanes[l_count],
                          l_fapi_endp2_target.toEcmdString());
            }

            for(l_count = 0; l_count < l_endp2_rxFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Rx lane %d, of DMI-Bus, of endpoint %s",
                          l_endp2_rxFaillanes[l_count],
                          l_fapi_endp2_target.toEcmdString());
            }
        } // end of if(l_endp2_txFaillanes.size() || l_endp2_rxFaillanes.size())
    } // end for l_mcs_target

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_erepair exit" );

    return l_StepError.getErrorHandle();
}

//
//  Wrapper function to call  dmi_io_dccal
//
void*    call_dmi_io_dccal( void *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;
    ISTEP_ERROR::IStepError l_StepError;

    // We are not running this analog procedure in VPO
    if (TARGETING::is_vpo())
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Skip dmi_io_dccal in VPO!");
        return l_StepError.getErrorHandle();
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_dmi_io_dccal entry" );

    TargetPairs_t l_dmi_io_dccal_targets;
    get_dmi_io_targets(l_dmi_io_dccal_targets);


    // Note:
    // Due to lab tester board environment, HW procedure writer (Varkey) has
    // requested to send in one target of a time (we used to send in
    // the MCS and MEMBUF pair in one call). Even though they don't have to be
    // in order, we should keep the pair concept here in case we need to send
    // in a pair in the future again.
    for (TargetPairs_t::const_iterator
         l_itr = l_dmi_io_dccal_targets.begin();
         l_itr != l_dmi_io_dccal_targets.end();
         ++l_itr)
    {
        const fapi::Target l_fapi_mcs_target( TARGET_TYPE_MCS_CHIPLET,
                (const_cast<TARGETING::Target*>(l_itr->first)));

        const fapi::Target l_fapi_membuf_target( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_itr->second)));

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "===== Call dmi_io_dccal HWP( mcs 0x%.8X, mem 0x%.8X) : ",
                TARGETING::get_huid(l_itr->first),
                TARGETING::get_huid(l_itr->second));

        // Call on the MCS
        FAPI_INVOKE_HWP(l_errl, dmi_io_dccal, l_fapi_mcs_target);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X :  dmi_io_dccal HWP Target MCS 0x%.8X",
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
                    "SUCCESS :  call_dmi_io_dccal HWP - Target 0x%.8X",
                    TARGETING::get_huid(l_itr->first));
        }

        // io_dccal.C is going to look for a PLL ring with a "stub"
        // mem freq -- so set to a default, then clear it (so as not
        // to mess up MSS HWP later
        // Note: io_dccal actually scans the ring in, is it really OK to use the
        // ring corresponding to a default memory frequency of 1600MHz?
        // RTC issue 92232 will resolve this
        TARGETING::Target* l_membuf_target =
            (const_cast<TARGETING::Target*>(l_itr->second));
        l_membuf_target->setAttr<TARGETING::ATTR_MSS_FREQ>(1600);

        // Call on the MEMBUF
        FAPI_INVOKE_HWP(l_errl, dmi_io_dccal, l_fapi_membuf_target);

        // Clear MSS_FREQ.  This attribute will be set in istep 12 (mss_freq) for good
        l_membuf_target->setAttr<TARGETING::ATTR_MSS_FREQ>(0);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X :  dmi_io_dccal HWP Target Membuf 0x%.8X",
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
                    "SUCCESS :  call_dmi_io_dccal HWP - Target 0x%.8X",
                    TARGETING::get_huid(l_itr->second));
        }

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_dmi_io_dccal exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}


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
        // RTC issue 92232 will resolve this workaround.
        TARGETING::Target* l_membuf_target =
            (const_cast<TARGETING::Target*>(l_itr->second));
        l_membuf_target->setAttr<TARGETING::ATTR_MSS_FREQ>(1600);

        FAPI_INVOKE_HWP(l_err, dmi_io_run_training,
                        l_fapi_master_target, l_fapi_slave_target);

        // Clear ATTR_MSS_FREQ. RTC issue 92232
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
            break; // Break out target list loop
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

                break; // break out of mem num loop
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  proc_cen_framelock HWP( mem %d ) ",
                        l_memNum );
            }

        }   // end mem

        // if there is already an error, bail out.
        if ( !l_StepError.isNull() )
        {
            break; // break out of mcs loop
        }

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

                break; // break out of mcs loop
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  proc_cen_set_inband_addr HWP");
            }
        }   // end for mcs

        l_err = l_StepError.getErrorHandle();
        if(l_err)
        {
            break;
        }

        //Now enable Inband SCOM for all membuf chips.
        TARGETING::TargetHandleList membufChips;
        getAllChips(membufChips, TYPE_MEMBUF, true);

        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);

        for(uint32_t i=0; i<membufChips.size(); i++)
        {
            // If the membuf chip supports IBSCOM AND..
            //   (Chip is >=DD20 OR IBSCOM Override is set)
            if ((membufChips[i]->getAttr<ATTR_PRIMARY_CAPABILITIES>()
                .supportsInbandScom) &&
                (// TODO: RTC 68984: Disable IBSCOM for now (membufChips[i]->getAttr<TARGETING::ATTR_EC>() >= 0x20) ||
                 (sys->getAttr<TARGETING::ATTR_IBSCOM_ENABLE_OVERRIDE>() != 0))
                )
            {
                ScomSwitches l_switches =
                  membufChips[i]->getAttr<ATTR_SCOM_SWITCHES>();

                // If Inband Scom is not already enabled.
                if ((l_switches.useInbandScom != 1) ||
                    (l_switches.useFsiScom != 0))
                {
                    l_switches.useFsiScom = 0;
                    l_switches.useInbandScom = 1;

                    // Turn off FSI scom and turn on Inband Scom.
                    membufChips[i]->setAttr<ATTR_SCOM_SWITCHES>(l_switches);

                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "Enable IBSCOM on target HUID %.8X",
                              TARGETING::get_huid(membufChips[i]));
                }
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "IBSCOM NOT enabled on target HUID %.8X",
                          TARGETING::get_huid(membufChips[i]));

            }
        }

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

