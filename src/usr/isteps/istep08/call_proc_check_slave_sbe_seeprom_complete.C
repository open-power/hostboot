/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_check_slave_sbe_seeprom_complete.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
 *  @file call_proc_check_slave_sbe_seeprom_complete.C
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

#include <isteps/hwpisteperror.H>
#include <errl/errludtarget.H>


using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_08
{

//******************************************************************************
// call_proc_check_slave_sbe_seeprom_complete function
//******************************************************************************
void* call_proc_check_slave_sbe_seeprom_complete( void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;
    //@TODO RTC:134078
/*    IStepError  l_stepError;
    void* sbeImgPtr = NULL;
    size_t sbeImgSize = 0;
    //size_t l_wait_time = MS_TO_WAIT_OTHERS;


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_check_slave_sbe_seeprom_complete entry" );

    //If in FSPless environment -- give time for SBE to complete on first chip
*/
    /*if (!INITSERVICE::spBaseServicesEnabled())
    {
        l_wait_time = MS_TO_WAIT_FIRST;
    }*/
/*
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
        //@TODO RTC:134078
        // Invoke the HWP
        fapi::ReturnCode rc_fapi = fapi::FAPI_RC_SUCCESS;
    */    /*FAPI_EXEC_HWP(rc_fapi,
                      p9_check_slave_sbe_seeprom_complete,
                      l_fapiProcTarget,
                      sbeImgPtr,
                      l_wait_time);*/

        // check for re ipl request
  /*      if(static_cast<uint32_t>(rc_fapi) ==
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
        //l_wait_time = MS_TO_WAIT_OTHERS;
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
                "target HUID %.8X --> calling proc_getecid",
                TARGETING::get_huid(l_pProcTarget));

        fapi::Target l_fapiProcTarget( fapi::TARGET_TYPE_PROC_CHIP,
                                       l_pProcTarget    );

        //  proc_getecid should set the fuse string to 112 bits long.
        ecmdDataBufferBase  l_fuseString;
        //@TODO RTC:134078
        // Invoke the HWP
        FAPI_INVOKE_HWP(l_errl,
                        proc_getecid,
                        l_fapiProcTarget,
                        l_fuseString  );

        if (l_errl)
        {
            if (l_procTargetList->getAttr<ATTR_HWAS_STATE>().functional)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR : proc_getecid",
                        " failed, returning errorlog" );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_errl );

                // Create IStep error log and cross reference error that
                // occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit error log
                errlCommit( l_errl, HWPF_COMP_ID );
            }
            else // Not functional, proc deconfigured, don't report error
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR : proc_getecid",
                        " failed, proc target deconfigured" );

                delete l_errl;
                l_errl = NULL;
            }
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_getecid",
                      " completed ok");

        }
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "target HUID %.8X --> after proc_getecid",
                  TARGETING::get_huid(l_pProcTarget));

    }   // endfor


    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_check_slave_sbe_seeprom_complete exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
    */
        return l_errl;
}
};
