/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/slave_sbe.C $                      */
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
 *  @file slave_sbe.C
 *
 *  Support file for IStep: slave_sbe
 *   Slave SBE
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>

#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <sys/time.h>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include    <targeting/namedtarget.H>
#include    <targeting/attrsync.H>

#include <hwpisteperror.H>
#include <errl/errludtarget.H>

//  fapi support
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>

#include "proc_cen_ref_clk_enable.H"
#include "slave_sbe.H"
#include "proc_revert_sbe_mcs_setup.H"
#include "proc_check_slave_sbe_seeprom_complete.H"
#include "proc_getecid.H"
#include "proc_spless_sbe_startWA.H"
#include <sbe/sbeif.H>


using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace SLAVE_SBE
{

uint8_t getMembufsAttachedBitMask( TARGETING::Target * i_procChipHandle  );

//******************************************************************************
// call_proc_revert_sbe_mcs_setup function
//******************************************************************************
void* call_proc_revert_sbe_mcs_setup(void *io_pArgs)
{
    errlHndl_t  l_errl = NULL;
    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_revert_sbe_mcs_setup entry" );

    // Note: Even though Cronus trace shows this HWP runs on all proc,
    // this should be done only for Master chip per Dean.

    TARGETING::Target* l_pProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pProcTarget);

    fapi::Target l_fapiProcTarget(fapi::TARGET_TYPE_PROC_CHIP, l_pProcTarget);

    // Invoke the HWP
    FAPI_INVOKE_HWP(l_errl, proc_revert_sbe_mcs_setup, l_fapiProcTarget);

    if (l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : failed executing proc_revert_sbe_mcs_setup "
                  "returning error");

        // capture the target data in the elog
        ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_errl );

        /*@
         * @errortype
         * @reasoncode  ISTEP_SLAVE_SBE_FAILED
         * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid    ISTEP_PROC_REVERT_SBE_MCS_SETUP
         * @userdata1   bytes 0-1: plid identifying first error
         *              bytes 2-3: reason code of first error
         * @userdata2   bytes 0-1: total number of elogs included
         *              bytes 2-3: N/A
         * @devdesc     call to proc_revert_sbe_mcs_setup returned an error
         *
         */
        l_stepError.addErrorDetails(ISTEP_SLAVE_SBE_FAILED,
                                    ISTEP_PROC_REVERT_SBE_MCS_SETUP,
                                    l_errl );

        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "SUCCESS : proc_revert_sbe_mcs_setup completed ok");
    }

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_revert_sbe_mcs_setup exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


//******************************************************************************
// call_host_slave_sbe function
//******************************************************************************
void* call_host_slave_sbe_config(void *io_pArgs)
{
    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_config entry" );

    // execute proc_read_nest_freq.C
    // execute proc_setup_sbe_config.C

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_config exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

}

//******************************************************************************
// call_host_sbe_start function
//******************************************************************************
void* call_host_sbe_start( void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;
    IStepError  l_stepError;
    bool        l_needDelay = false;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_sbe_start entry" );

    //
    //  get the master Proc target, we want to IGNORE this one.
    //
    TARGETING::Target* l_pMasterProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    //
    //  get a list of all the procs in the system
    //
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        "host_sbe_start: %d procs in the system.",
        l_procTargetList.size() );

    // loop thru all the cpu's
    for (TargetHandleList::const_iterator
            l_proc_iter = l_procTargetList.begin();
            l_proc_iter != l_procTargetList.end();
            ++l_proc_iter)
    {
        //  make a local copy of the Processor target
        TARGETING::Target* l_pProcTarget = *l_proc_iter;

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X",
                TARGETING::get_huid(l_pProcTarget));

        fapi::Target l_fapiProcTarget( fapi::TARGET_TYPE_PROC_CHIP,
                                       l_pProcTarget    );


        if (l_pProcTarget  ==  l_pMasterProcTarget )
        {
            // we are just checking the Slave SBE's, skip the master
            continue;
        }
        else if (!INITSERVICE::spBaseServicesEnabled())
        {
            //Need to issue SBE start workaround on all slave chips
            // Invoke the HWP
            FAPI_INVOKE_HWP(l_errl,
                            proc_spless_sbe_startWA,
                            l_fapiProcTarget);

            l_needDelay = true;
        }
        else
        {
            //Eventually for secureboot will need to kick off
            //SBE here (different HWP), but for now not needed
            //so do nothing
        }

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : sbe_start",
                      "failed, returning errorlog" );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_errl );

            /*@
             * @errortype
             * @reasoncode  ISTEP_SLAVE_SBE_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_PROC_SBE_START
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to HWP to start SBE
             *              returned an error
             *
             */
            l_stepError.addErrorDetails(
                            ISTEP_SLAVE_SBE_FAILED,
                            ISTEP_PROC_SBE_START,
                            l_errl );

            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : sbe_start",
                      "completed ok");

        }
    }   // endfor

    //TODO RTC 87845  Should really move this delay to
    // check_slave_sbe_seeprom_complete to delay/poll instead
    // of one big delay here.  For now if we started the slaves
    // delay ~2.5 sec for them to complete
    if(l_needDelay)
    {
        nanosleep( 2, 500000000 ); //sleep for 2.5 seconds
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_sbe_start exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


//******************************************************************************
// call_proc_check_slave_sbe_seeprom_complete function
//******************************************************************************
void* call_proc_check_slave_sbe_seeprom_complete( void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;
    IStepError  l_stepError;
    void* sbeImgPtr = NULL;
    size_t sbeImgSize = 0;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_check_slave_sbe_seeprom_complete entry" );

    //
    //  get the master Proc target, we want to IGNORE this one.
    //
    TARGETING::Target* l_pMasterProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    //
    //  get a list of all the procs in the system
    //
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        "proc_check_slave_sbe_seeprom_complete: %d procs in the system.",
        l_procTargetList.size() );

    // loop thru all the cpu's
    for (TargetHandleList::const_iterator
            l_proc_iter = l_procTargetList.begin();
            l_proc_iter != l_procTargetList.end();
            ++l_proc_iter)
    {
        //  make a local copy of the Processor target
        TARGETING::Target* l_pProcTarget = *l_proc_iter;

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X",
                TARGETING::get_huid(l_pProcTarget));

        if ( l_pProcTarget  ==  l_pMasterProcTarget )
        {
            // we are just checking the Slave SBE's, skip the master
            continue;
        }

        l_errl = SBE::findSBEInPnor(l_pProcTarget,sbeImgPtr,sbeImgSize);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : proc_check_slave_sbe_seeprom_complete "
                  "Can't find SBE image in pnor");
        }

        fapi::Target l_fapiProcTarget( fapi::TARGET_TYPE_PROC_CHIP,
                                       l_pProcTarget    );

        // Invoke the HWP
        FAPI_INVOKE_HWP(l_errl,
                        proc_check_slave_sbe_seeprom_complete,
                        l_fapiProcTarget, sbeImgPtr);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : proc_check_slave_sbe_seeprom_complete",
                      "failed, returning errorlog" );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_errl );

            /*@
             * @errortype
             * @reasoncode  ISTEP_SLAVE_SBE_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to proc_check_slave_sbe_seeprom_complete
             *              returned an error
             *
             */
            l_stepError.addErrorDetails(
                            ISTEP_SLAVE_SBE_FAILED,
                            ISTEP_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE,
                            l_errl );

            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_check_slave_sbe_seeprom_complete",
                      "completed ok");

        }
    }   // endfor


    //  Once the sbe's are up correctly, fetch all the proc ECIDs and
    //  store them in an attribute.
    for (TargetHandleList::const_iterator
            l_proc_iter = l_procTargetList.begin();
            l_proc_iter != l_procTargetList.end();
            ++l_proc_iter)
    {
        //  make a local copy of the Processor target
        TARGETING::Target* l_pProcTarget = *l_proc_iter;

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X",
                TARGETING::get_huid(l_pProcTarget));

        fapi::Target l_fapiProcTarget( fapi::TARGET_TYPE_PROC_CHIP,
                                       l_pProcTarget    );

        //  proc_getecid should set the fuse string to 112 bits long.
        ecmdDataBufferBase  l_fuseString;

        // Invoke the HWP
        FAPI_INVOKE_HWP(l_errl,
                        proc_getecid,
                        l_fapiProcTarget,
                        l_fuseString  );

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : proc_getecid",
                      " failed, returning errorlog" );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_errl );

            /*@
             * @errortype
             * @reasoncode  ISTEP_PROC_GETECID_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_PROC_GETECID
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to proc_get_ecid failed.
             *
             */
             l_stepError.addErrorDetails( ISTEP_PROC_GETECID_FAILED,
                                          ISTEP_PROC_GETECID,
                                          l_errl );

             errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_getecid",
                      " completed ok");

        }
    }   // endfor

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_check_slave_sbe_seeprom_complete exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//******************************************************************************
// call_proc_xmit_sbe
//******************************************************************************
void* call_proc_xmit_sbe(void *io_pArgs )
{
    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_xmit_sbe entry" );

    // call proc_xmit_sbe.C

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_xmit_sbe exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//******************************************************************************
// call_proc_cen_ref_clock_enable
//******************************************************************************
void* call_proc_cen_ref_clk_enable(void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_cen_ref_clock_enable enter" );

    TARGETING::TargetHandleList functionalProcChipList;

    getAllChips(functionalProcChipList, TYPE_PROC, true);

    // loop thru the list of processors
    for (TargetHandleList::const_iterator
            l_proc_iter = functionalProcChipList.begin();
            l_proc_iter != functionalProcChipList.end();
            ++l_proc_iter)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X",
                TARGETING::get_huid( *l_proc_iter ));

        uint8_t l_membufsAttached = 0;
        // get a bit mask of present/functional dimms assocated with
        // this processor
        l_membufsAttached = getMembufsAttachedBitMask( *l_proc_iter );


        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "passing target HUID %.8X and 0x%x mask",
                TARGETING::get_huid( *l_proc_iter ), l_membufsAttached );

        if( l_membufsAttached )
        {

            fapi::Target l_fapiProcTarget( fapi::TARGET_TYPE_PROC_CHIP,
                                       *l_proc_iter );

            // Invoke the HWP passing in the proc target and
            // a bit mask indicating connected centaurs
            FAPI_INVOKE_HWP(l_errl,
                    proc_cen_ref_clk_enable,
                    l_fapiProcTarget, l_membufsAttached );

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR : proc_cen_ref_clk_enable",
                        "failed, returning errorlog" );

                // capture the target data in the elog
                ErrlUserDetailsTarget( *l_proc_iter ).addToLog( l_errl );
                /*@
                 * @errortype
                 * @reasoncode  ISTEP_SLAVE_SBE_FAILED
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    ISTEP_PROC_CEN_REF_CLK_ENABLE
                 * @userdata1   bytes 0-1: plid identifying first error
                 *              bytes 2-3: reason code of first error
                 * @userdata2   bytes 0-1: total number of elogs included
                 *              bytes 2-3: N/A
                 * @devdesc     call to proc_cen_ref_clk_enable returned an error
                 *
                 */
                l_stepError.addErrorDetails( ISTEP_SLAVE_SBE_FAILED,
                        ISTEP_PROC_CEN_REF_CLK_ENABLE,
                        l_errl );

                errlCommit( l_errl, HWPF_COMP_ID );
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS : proc_cen_ref_clk_enable",
                        "completed ok");
            }
        }
    }   // endfor

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_cen_ref_clock_enable exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//******************************************************************************
// getMembufsAttachedBitMask - helper function for hwp proc_cen_ref_clk_enable
//******************************************************************************
uint8_t getMembufsAttachedBitMask( TARGETING::Target * i_procTarget  )
{
    const uint8_t MCS_WITH_ATTACHED_CENTAUR_MASK = 0x80;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Finding functional membuf chips downstream from "
            "proc chip with HUID of 0x%08X",
            i_procTarget->getAttr<TARGETING::ATTR_HUID>());

    uint8_t l_attachedMembufs = 0;

    // Get list of functional membuf chips downstream from the given
    // proc chip
    TARGETING::TargetHandleList functionalMembufChipList;

    getChildAffinityTargets( functionalMembufChipList,
                      const_cast<TARGETING::Target*>(i_procTarget ),
                      TARGETING::CLASS_CHIP,
                      TARGETING::TYPE_MEMBUF,
                      true);

    // loop through the functional membufs
    for(TARGETING::TargetHandleList::const_iterator pTargetItr
                            = functionalMembufChipList.begin();
                            pTargetItr != functionalMembufChipList.end();
                            pTargetItr++)
    {
        // Find each functional membuf chip's upstream functional MCS
        // unit, if any, and accumulate it into the attached membuf
        // chips mask
        TARGETING::TargetHandleList functionalMcsUnitList;

        getParentAffinityTargets( functionalMcsUnitList, *pTargetItr,
                                  TARGETING::CLASS_UNIT, TARGETING::TYPE_MCS,
                                  true );

        if(functionalMcsUnitList.empty())
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Functional membuf chip with HUID of 0x%08X "
                    "is not attached to an upstream functional MCS",
                    (*pTargetItr)->getAttr<
                    TARGETING::ATTR_HUID>());
            continue;
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Found functional MCS unit with HUID of 0x%08X "
                "upstream from functional membuf chip with HUID of 0x%08X",
                ((*functionalMcsUnitList.begin())->getAttr<
                 TARGETING::ATTR_CHIP_UNIT>()),
                (*pTargetItr)->getAttr<
                TARGETING::ATTR_HUID>());
        l_attachedMembufs |=
            ((MCS_WITH_ATTACHED_CENTAUR_MASK) >>
             ((*functionalMcsUnitList.begin())->getAttr<
              TARGETING::ATTR_CHIP_UNIT>()));
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Proc chip with HUID of 0x%08X has attached membuf "
            "mask (l_attachedMembufs) of 0x%02X",
            i_procTarget->getAttr<TARGETING::ATTR_HUID>(),
            l_attachedMembufs);

    // return the bitmask
    return l_attachedMembufs;

}

}
