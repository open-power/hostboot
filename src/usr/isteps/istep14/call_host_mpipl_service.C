/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_host_mpipl_service.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>

#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>

#include <vfs/vfs.H>
#include <dump/dumpif.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{
void* call_host_mpipl_service (void *io_pArgs)
{

    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_mpipl_service entry" );
//@TODO RTC: 134431 MPIPL Changes for P9 - Placeholder
#if 0
    errlHndl_t l_err = NULL;
    // call proc_mpipl_chip_cleanup.C
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC );

    //  ---------------------------------------------------------------
    //  run proc_mpipl_chip_cleanup.C on all proc chips
    //  ---------------------------------------------------------------
    for (TargetHandleList::const_iterator
         l_iter = l_procTargetList.begin();
         l_iter != l_procTargetList.end();
         ++l_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_pProcTarget = *l_iter;

        //  write HUID of target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_pProcTarget));

        //const fapi::Target l_fapi_pProcTarget( TARGET_TYPE_PROC_CHIP,
        //                   (const_cast<TARGETING::Target*> (l_pProcTarget)) );

        //  call the HWP with each fapi::Target
        //FAPI_INVOKE_HWP(l_err, proc_mpipl_chip_cleanup,
        //                l_fapi_pProcTarget );

        if ( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR : returned from proc_mpipl_chip_cleanup" );

            // capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_err );

            // since we are doing an mpipl break out, the mpipl has failed
            break;
        }

        //  ---------------------------------------------------------------
        //  run proc_mpipl_ex_cleanup.C on all proc chips
        //  ---------------------------------------------------------------
        //@TODO RTC:133831  call the HWP with each fapi::Target
        //FAPI_INVOKE_HWP(l_err,
        //                proc_mpipl_ex_cleanup,
        //                l_fapi_pProcTarget );

        if ( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR : returned from proc_mpipl_ex_cleanup" );

            // capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_err );

            // since we are doing an mpipl break out, the mpipl has failed
            break;
        }
    }

    //Determine if we should perform dump ops
    //Note that this is only called in MPIPL context, so don't
    //have to check MPIPL
    bool collect_dump = false;
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    TARGETING::CecIplType type;
    if(sys &&
       sys->tryGetAttr<TARGETING::ATTR_CEC_IPL_TYPE>(type) &&
       type.PostDump)
    {
        collect_dump = true;
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Ready to collect dump -- yes/no [%d]", collect_dump);

    // No error on the procedure.. proceed to collect the dump.
    if (!l_err && collect_dump)
    {

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : proc_mpipl_ex_cleanup" );

        // currently according to Adriana, the dump calls should only cause an
        // istep failure when the dump collect portion of this step fails..  We
        // will not fail the istep on any mbox message failures. instead we will
        // simply commit the errorlog and continue.

        errlHndl_t l_errMsg = NULL;

        // Dump relies upon the runtime module
        // Not declaring in istep DEP list cause if we load it
        // we want it to stay loaded
        if (  !VFS::module_is_loaded( "libruntime.so" ) )
        {
            l_err = VFS::module_load( "libruntime.so" );

            if ( l_err )
            {
                //  load module returned with errl set
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Could not load runtime module" );
            }
        }

        // If dump module successfull loaded then continue with DumpCollect and
        // messaging
        if (!l_err)
        {
            do
            {
                // send the start message
                l_errMsg = DUMP::sendMboxMsg(DUMP::DUMP_MSG_START_MSG_TYPE);

                // If error, commit and send error message.
                if (l_errMsg)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : returned from DUMP::sendMboxMsg - dump start" );

                    errlCommit( l_errMsg, HWPF_COMP_ID );

                    // don't break in this case because we not want to fail the
                    // istep on the dump collect so we will continue after we
                    // log the errhandle that we can't send a message.
                }

                // Call the dump collect
                l_err = DUMP::doDumpCollect();

                // Got a Dump Collect error.. Commit the dumpCollect
                // errorlog and then send an dump Error mbox message
                // and FSP will decide what to do.
                // We do not want dump Collect failures to terminate the istep.
                if (l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : returned from DUMP::HbDumpCopySrcToDest" );

                    break;
                }

            } while(0);

            DUMP::DUMP_MSG_TYPE msgType = DUMP::DUMP_MSG_END_MSG_TYPE;

            // Send dumpCollect success trace
            if (!l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS : doDumpCollect" );
            }
            // got an error that we need to send a ERROR message to FSP
            // and commit the errorlog from dumpCollect.
            else
            {
                msgType = DUMP::DUMP_MSG_ERROR_MSG_TYPE;

                // Commit the dumpCollect errorlog from above as
                // we dont want dump collect to kill the istep
                errlCommit( l_err, HWPF_COMP_ID );

            }

            // Send an Error mbox msg to FSP (either end or error)
            l_errMsg = DUMP::sendMboxMsg(msgType);

            if (l_errMsg)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : returned from DUMP::sendMboxMsg" );

                errlCommit( l_errMsg, HWPF_COMP_ID );
            }


            // Need to unload the runtime module regardless of whether we have
            // an error or not.
            errlHndl_t l_errUnLoad = VFS::module_unload( "libruntime.so" );

            if (l_errUnLoad)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR : returned from VFS::module_unload (libruntime.so)" );

                errlCommit( l_errUnLoad, HWPF_COMP_ID );
            }

        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : returned from VFS::module_load (libruntime.so)" );
        }
    }

    // If got an error in the procedure or collection of the dump kill the istep
    if( l_err )
    {
        // Create IStep error log and cross reference to error that occurred
        l_StepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
    }
#endif

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_mpipl_service exit" );

    return l_StepError.getErrorHandle();
}

};
