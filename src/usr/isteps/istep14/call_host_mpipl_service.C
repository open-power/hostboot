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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>

#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <targeting/targplatutil.H>

#include <runtime/runtime.H>

#include <p9_mpipl_chip_cleanup.H>
#include <fapi2/plat_hwp_invoker.H>

#include <vfs/vfs.H>
#include <dump/dumpif.H>


#ifdef CONFIG_DRTM
#include <secureboot/drtm.H>
#endif

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{
void* call_host_mpipl_service (void *io_pArgs)
{

    IStepError l_StepError;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_host_mpipl_service entry" );

    if (!TARGETING::UTIL::isCurrentMasterNode())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_host_mpipl_service cannot run on slave node, skipping");
    }
    else
    {
        errlHndl_t l_err = NULL;
        // call proc_mpipl_chip_cleanup.C
        TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC );

        //  ---------------------------------------------------------------
        //  run proc_mpipl_chip_cleanup.C on all proc chips
        //  ---------------------------------------------------------------
        for (const auto & l_pProcTarget : l_procTargetList)
        {
            //  write HUID of target
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "target HUID %.8X", TARGETING::get_huid(l_pProcTarget));

            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_pProcTarget((const_cast<TARGETING::Target*> (l_pProcTarget)) );

            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP(l_err, p9_mpipl_chip_cleanup, l_fapi_pProcTarget );

            if ( l_err )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR : returned from p9_mpipl_chip_cleanup" );

                // capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(l_pProcTarget).addToLog(l_err);

                // since we are doing an mpipl break out, the mpipl has failed
                break;
            }

        }

#ifdef CONFIG_DRTM

        if(!l_err)
        {
            do {

            bool drtmMpipl = false;
            SECUREBOOT::DRTM::isDrtmMpipl(drtmMpipl);
            if(drtmMpipl)
            {
                l_err = SECUREBOOT::DRTM::validateDrtmPayload();
                if(l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                        "call_host_mpipl_service: Failed in call to "
                        "validateDrtmPayload()");
                    break;
                }

                l_err = SECUREBOOT::DRTM::completeDrtm();
                if(l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                        "call_host_mpipl_service: Failed in call to "
                        "completeDrtm()" );
                    break;
                }
            }

            } while(0);
        }

#endif

        // No error on the procedure.. proceed to collect the dump.
        if (!l_err)
        {

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : proc_mpipl_ex_cleanup" );

            // currently according to Adriana, the dump calls should only cause
            // an istep failure when the dump collect portion of this step
            // fails..  We will not fail the istep on any mbox message failures.
            // instead we will simply commit the errorlog and continue.

            errlHndl_t l_errMsg = NULL;

            // Use relocated payload base to get MDST, MDDT, MDRT details
            RUNTIME::useRelocatedPayloadAddr(true);

            do
            {
                //Fips950 firmware release should not be supporting MPIPL data
                //collection for OPAL based systems.Hence the below code is 
                //disabled.
#if 0
                //SBE collects architected register data for below combination
                //of systems.Hence Copy architected register data from Reserved
                //Memory to hypervisor memory.
                //
                //1) FSP - OPAL
                //2) BMC - OPAL
                //3) BMC - PHYP

    
                //Copy Architected register data if sys is **NOT** (FSP + PHYP)
                //combination.
                if( !(is_phyp_load() && INITSERVICE::spBaseServicesEnabled()) )
                {
                    l_err = DUMP::copyArchitectedRegs();
                    if (l_err)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR : returned from DUMP::copyArchitectedRegs()");
                        break;
                    }
                }
#endif
                // send the start message
                l_errMsg = DUMP::sendMboxMsg(DUMP::DUMP_MSG_START_MSG_TYPE);

                // If error, commit and send error message.
                if (l_errMsg)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR : returned from DUMP::sendMboxMsg - dump start" );

                    errlCommit( l_errMsg, HWPF_COMP_ID );

                    // don't break in this case because we not want to fail
                    // the istep on the dump collect so we will continue
                    // after we log the errhandle that we can't send a
                    // message.
                }

                //Fips950 firmware release should not be supporting MPIPL data
                //collection for OPAL based systems.Hence the below code is 
                //disabled for OPAL
                if(is_phyp_load()) 
                {
                    // Call the dump collect
                    l_err = DUMP::doDumpCollect();

                    // Got a Dump Collect error.. Commit the dumpCollect
                    // errorlog and then send an dump Error mbox message
                    // and FSP will decide what to do.
                    // We do not want dump Collect failures to terminate the
                    // istep.
                    if (l_err)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                "ERROR : returned from DUMP::HbDumpCopySrcToDest");

                        break;
                    }
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

             RUNTIME::useRelocatedPayloadAddr(false);
             // Wipe out our cache of the NACA/SPIRA pointers
             RUNTIME::rediscover_hdat();
        }

        // If got an error in the procedure or collection of the dump kill the
        // istep
        if( l_err )
        {
            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_mpipl_service exit" );

    return l_StepError.getErrorHandle();
}

};
