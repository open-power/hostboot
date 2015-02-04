/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/slave_sbe.C $                      */
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
#include <initservice/initsvcreasoncodes.H>
#include <sys/time.h>
#include <devicefw/userif.H>
#include <i2c/i2cif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>
#include <targeting/attrsync.H>

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
#include <freqVoltageSvc.H>

const uint64_t MS_TO_WAIT_FIRST = 2500; //(2.5 s)
const uint64_t MS_TO_WAIT_OTHERS= 100; //(100 ms)

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace SLAVE_SBE
{

uint8_t getMembufsAttachedBitMask( TARGETING::Target * i_procChipHandle  );
void fenceAttachedMembufs( TARGETING::Target * i_procChipHandle  );

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

        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( l_errl );

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
    errlHndl_t l_errl = NULL;
    IStepError  l_stepError;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_config entry" );

    // execute proc_read_nest_freq.C
    // execute proc_setup_sbe_config.C

#ifdef CONFIG_HTMGT
    // Set system frequency attributes
    l_errl = FREQVOLTSVC::setSysFreq();
    if (l_errl )
    {
        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }
#endif // CONFIG_HTMGT

    // If there is no FSP, set ATTR_PROC_BOOT_VOLTAGE_VID

    if (!INITSERVICE::spBaseServicesEnabled())
    {
        l_errl = set_proc_boot_voltage_vid();
        if( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Error setting PROC_BOOT_VOLTAGE_VID: "
                        "slave_sbe.C::call_host_slave_sbe_config()");
            // Create IStep error log
            l_stepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );

        }
    }
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_config exit" );



    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

}


//******************************************************************************
// set_proc_boot_voltage_vid
//******************************************************************************
errlHndl_t set_proc_boot_voltage_vid()
{
    errlHndl_t l_errl = NULL;
    IStepError l_stepError;
    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "ENTER set_proc_boot_voltage_vid()");
    do
    {
        // Get the top level target/system target
        Target* l_pTopLevelTarget = NULL;
        targetService().getTopLevelTarget(l_pTopLevelTarget);

        // If there is no top level target, terminate
        assert(l_pTopLevelTarget, "ERROR: Top level "
                   "target not found - slave_sbe.C::set_proc_boot_voltage_vid");

        // Get all Procs
        PredicateCTM l_proc(CLASS_CHIP, TYPE_PROC);
        PredicateIsFunctional l_functional;
        PredicatePostfixExpr l_procs;

        l_procs.push(&l_proc).push(&l_functional).And();

        TargetRangeFilter l_filter( targetService().begin(),
                                    targetService().end(),
                                    &l_procs);

        ATTR_BOOT_FREQ_MHZ_type l_boot_freq_mhz =
                   l_pTopLevelTarget->getAttr<ATTR_BOOT_FREQ_MHZ>();
        for(; l_filter; ++l_filter)
        {

            l_errl = FREQVOLTSVC::runProcGetVoltage(*l_filter,
                                                    l_boot_freq_mhz);
            if( l_errl )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "ERROR: calling runProcGetVoltage for Proc "
                            "Target HUID[0x%08X]",
                            l_filter->getAttr<ATTR_HUID>());


                // Deconfig the processor
                l_errl->addHwCallout(*l_filter,
                        HWAS::SRCI_PRIORITY_LOW,
                        HWAS::DECONFIG,
                        HWAS::GARD_NULL);


                // Commit error log
                errlCommit( l_errl, HWPF_COMP_ID );
            }
        }


    }while( 0 );
    return l_errl;
}


//******************************************************************************
// call_host_sbe_start function
//******************************************************************************
void* call_host_sbe_start( void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;
    IStepError  l_stepError;

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

            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit error log
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : sbe_start",
                      "completed ok");

        }
    }   // endfor

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
    size_t l_wait_time = MS_TO_WAIT_OTHERS;


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_check_slave_sbe_seeprom_complete entry" );

    //If in FSPless environment -- give time for SBE to complete on first chip
    if (!INITSERVICE::spBaseServicesEnabled())
    {
        l_wait_time = MS_TO_WAIT_FIRST;
    }

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
        fapi::ReturnCode rc_fapi = fapi::FAPI_RC_SUCCESS;
        FAPI_EXEC_HWP(rc_fapi,
                      proc_check_slave_sbe_seeprom_complete,
                      l_fapiProcTarget,
                      sbeImgPtr,
                      l_wait_time);

        // check for re ipl request
        if(static_cast<uint32_t>(rc_fapi) ==
           fapi::RC_PROC_EXTRACT_SBE_RC_ENGINE_RETRY)
        {
            l_errl = fapi::fapiRcToErrl(rc_fapi);

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_errl );

            l_errl->setSev(ERRL_SEV_INFORMATIONAL);

            errlCommit( l_errl, HWPF_COMP_ID );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : proc_extract_sbe_rc requesting reIPL:"
                      " Calling INITSERVICE::doShutdown() with "
                      "SBE_EXTRACT_RC_REQUEST_REIPL = 0x%x",
                      INITSERVICE::SBE_EXTRACT_RC_REQUEST_REIPL);

            INITSERVICE::doShutdown
                ( INITSERVICE::SBE_EXTRACT_RC_REQUEST_REIPL);
            // doShutdown does not return
        }
        else
        {
            l_errl = fapi::fapiRcToErrl(rc_fapi);
        }

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : proc_check_slave_sbe_seeprom_complete",
                      "failed, returning errorlog" );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_errl );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit error log
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_check_slave_sbe_seeprom_complete",
                      "completed ok");

        }

        //after first one default to quick check time
        l_wait_time = MS_TO_WAIT_OTHERS;
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

            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit error log
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_getecid",
                      " completed ok");

        }
    }   // endfor


    // Slave processors should now use Host I2C Access Method
    I2C::i2cSetAccessMode( I2C::I2C_SET_ACCESS_MODE_PROC_HOST );

    // Reset the Processor's I2C Masters
    l_errl = I2C::i2cResetActiveMasters(I2C::I2C_PROC_ALL);
    if (l_errl)
    {
        // Commit error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

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

        //Perform a workaround for GA1 to raise fences on centaurs
        //to prevent FSP from analyzing if HB TIs for recoverable
        //errors
        //RTC 106276
        fenceAttachedMembufs( *l_proc_iter );

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

                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit error log
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

//******************************************************************************
// fenceAttachedMembufs - helper function for hwp proc_cen_ref_clk_enable
//******************************************************************************
void fenceAttachedMembufs( TARGETING::Target * i_procTarget  )
{
     errlHndl_t  l_errl = NULL;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Fencing attached (present) membuf chips downstream from "
            "proc chip with HUID of 0x%08X",
            i_procTarget->getAttr<TARGETING::ATTR_HUID>());


    // Get list of membuf chips downstream from the given proc chip
    TARGETING::TargetHandleList MembufChipList;

    getChildAffinityTargetsByState( MembufChipList,
                      const_cast<TARGETING::Target*>(i_procTarget ),
                      TARGETING::CLASS_CHIP,
                      TARGETING::TYPE_MEMBUF,
                      TARGETING::UTIL_FILTER_PRESENT);

    // loop through the membufs
    for(TARGETING::TargetHandleList::const_iterator pTargetItr
                            = MembufChipList.begin();
                            pTargetItr != MembufChipList.end();
                            pTargetItr++)
    {
        //Get CFAM "1012" -- FSI GP3 and set bits 23-27 (various fence bits)
        //Note 1012 is ecmd addressing, real address is 0x1048 (byte)
        uint64_t l_addr = 0x1048;
        const uint32_t l_fence_bits= 0x000001F0;
        uint32_t l_data = 0;
        size_t l_size = sizeof(uint32_t);
        l_errl = deviceRead(*pTargetItr,
                         &l_data,
                         l_size,
                         DEVICE_FSI_ADDRESS(l_addr));
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
             "Failed getcfam 1012 to HUID 0x%08X, ignoring, skipping",
             (*pTargetItr)->getAttr<TARGETING::ATTR_HUID>());
            delete l_errl;
            l_errl = NULL;
            continue;
        }

        l_data |= l_fence_bits;

        l_errl = deviceWrite(*pTargetItr,
                         &l_data,
                         l_size,
                         DEVICE_FSI_ADDRESS(l_addr));
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Failed putcfam 1012 to HUID 0x%08X, ignoring, skipping",
                      (*pTargetItr)->getAttr<TARGETING::ATTR_HUID>());
            delete l_errl;
            l_errl = NULL;
            continue;
        }
    }

}

}
