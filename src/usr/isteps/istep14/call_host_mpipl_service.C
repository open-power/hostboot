/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_host_mpipl_service.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 *  @file call_host_mpipl_service.C
 *
 *  @details Run MPIPL (Memory Preserving IPLs) Chip Cleanup on a set of targets
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

// Trace/Initservice
#include <trace/interface.H>             // TRACFCOMP
#include <initservice/isteps_trace.H>    // ISTEPS_TRACE::g_trac_isteps_trace
#include <initservice/initserviceif.H>   // INITSERVICE::spBaseServicesEnabled

// Error logging
#include <errl/errlentry.H>              // errlHndl_t
#include <isteps/hwpisteperror.H>        // IStepError, getErrorHandle

// Runtime Support
#include <runtime/runtime.H>             // RUNTIME::useRelocatedPayloadAddr

// Misc
#include <dump/dumpif.H>                 // DUMP::copyArchitectedRegs

/******************************************************************************/
// namespace shortcuts
/******************************************************************************/
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{

// Forward declare these methods
void runDumpCalls();
void sendDumpMboxMsg(const DUMP::DUMP_MSG_TYPE i_msgType);

/**
 * @brief Call DUMP methods
 *
 * @return return nullptr, currently no error is returned
 */
void* call_host_mpipl_service (void *)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"call_host_mpipl_service" );

    runDumpCalls();

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"call_host_mpipl_service, returning");

    return nullptr;
}  // call_host_mpipl_service

/**
 * @brief Wrapper to run the DUMP::doDumpCollect and associated code
 *
 * @details This method calls the DUMP::doDumpCollect method and informs the FSP
 *          the start of this call and the ending of the call (success or fail).
 *
 * @note An error in this method does not need to be propagated up to caller.
 *       Failure or success of this method has no consequence to the caller,
 *       only need to log error via the errlCommit method.
 */
void runDumpCalls()
{
    errlHndl_t l_err(nullptr);
    bool l_dumpCallFailed(false);

    // Use relocated payload base to get MDST, MDDT, MDRT details
    RUNTIME::useRelocatedPayloadAddr(true);

    do
    {
        // In non-FSP based system SBE collects architected register
        // data. Copy architected register data from Reserved Memory
        // to hypervisor memory.
        if ( !INITSERVICE::spBaseServicesEnabled() )
        {
            l_err = DUMP::copyArchitectedRegs();

            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                           "ERROR: DUMP::copyArchitectedRegs failed"
                           TRACE_ERR_FMT,
                           TRACE_ERR_ARGS(l_err) );

                l_dumpCallFailed = true;

                // Commit the error and break
                errlCommit( l_err, HWPF_COMP_ID );

                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                           "SUCCESS: DUMP::copyArchitectedRegs" );
            }
        }

        // Send a Start Mbox Msg to FSP
        sendDumpMboxMsg(DUMP::DUMP_MSG_START_MSG_TYPE);

        // Call the dump collect, regardless the pass/fail status of Mbox Msg.
        l_err = DUMP::doDumpCollect();

        // Got a Dump Collect error. Commit the dumpCollect
        // errorlog and then send an dump Error mbox message
        // and FSP will decide what to do.
        // We do not want dump Collect failures to terminate the
        // istep.
        if (l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                       "ERROR: DUMP::doDumpCollect failed"
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(l_err) );

            l_dumpCallFailed = true;

            // Commit the error and break
            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                       "SUCCESS: DUMP::doDumpCollect" );
        }
    } while(0);

    // Send Mbox Msg based on the success/failure of dump call
    if (!l_dumpCallFailed)
    {
        // Dump call succeeded: Send an End Mbox Msg to FSP
        sendDumpMboxMsg(DUMP::DUMP_MSG_END_MSG_TYPE);
    }
    else
    {
        // Dump call failed: Send an Error Mbox Msg to FSP
        sendDumpMboxMsg(DUMP::DUMP_MSG_ERROR_MSG_TYPE);
    }

    RUNTIME::useRelocatedPayloadAddr(false);

    // Wipe out our cache of the NACA/SPIRA pointers
    RUNTIME::rediscover_hdat();
} // runDumpCalls

/**
 * @brief Helper function to send a DUMP message to FSP
 *
 * @note An error in this method does not need to be propagated up to caller.
 *
 * @param[in] i_msgType - DUMP type message to send to FSP
 */
void sendDumpMboxMsg(const DUMP::DUMP_MSG_TYPE i_msgType)
{
    errlHndl_t l_err = DUMP::sendMboxMsg(i_msgType);

    if (l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                   "ERROR: DUMP::sendMboxMsg(0x%.08x) failed"
                    TRACE_ERR_FMT,
                    i_msgType,
                    TRACE_ERR_ARGS(l_err) );

        // Commit error and continue on ...
        errlCommit( l_err, HWPF_COMP_ID );
    }
} // sendDumpMboxMsg


};  // end namespace ISTEP_14
