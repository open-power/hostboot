/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/start_payload/start_payload.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
 *  @file start_payload.C
 *
 *  Support file for IStep: start_payload
 *   Start Payload
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <kernel/console.H>              //  printk status
#include    <sys/misc.h>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <vfs/vfs.H>
#include    <initservice/initserviceif.H>
#include    <initservice/extinitserviceif.H>
#include    <initservice/istepdispatcherif.H>
#include    <usr/cxxtest/TestSuite.H>
#include    <hwpf/istepreasoncodes.H>
#include    <errl/errludtarget.H>
#include    <sys/time.h>
#include    <sys/mmio.h>
#include    <mbox/mbox_queues.H>
#include    <mbox/mboxif.H>
#include    <i2c/i2cif.H>
#include    <hwpf/hwp/occ/occ.H>
#include    <sys/mm.h>
#include    <devicefw/userif.H>
#include    <util/misc.H>

#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>

//  targeting support
#include    <targeting/common/commontargeting.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    "p8_set_pore_bar.H"
#include    "p8_cpu_special_wakeup.H"
#include    "p8_pore_table_gen_api.H"
#include    <p8_scom_addresses.H>
#include    "proc_set_max_pstate.H"

#include    "start_payload.H"
#include    <runtime/runtime.H>
#include    <devtree/devtreeif.H>
#include    <sys/task.h>
#include    <intr/interrupt.H>
#include    <kernel/ipc.H> // for internode data areas
#include    <mbox/ipc_msg_types.H>
#include    <pnor/pnorif.H>
#include    <sys/mm.h>
#include    <algorithm>
#include    <config.h>
#include    <ipmi/ipmiwatchdog.H>
#include    <vpd/vpd_if.H>


//  Uncomment these files as they become available:
// #include    "host_start_payload/host_start_payload.H"

namespace   START_PAYLOAD
{

using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;

/**
 * @brief This function disables the special wakeup that allows scom
 *        operations on napped cores
 *
 * @return errlHndl_t error handle
 */
errlHndl_t disableSpecialWakeup();


#ifdef CONFIG_SET_NOMINAL_PSTATE
errlHndl_t setMaxPstate ( void )
{
    errlHndl_t l_errl = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Speed up to max P-state" );

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    // loop thru all the cpus
    for (TargetHandleList::const_iterator
         l_proc_iter = l_procTargetList.begin();
         l_proc_iter != l_procTargetList.end();
         ++l_proc_iter)
    {
        //  make a local copy of the CPU target
        const TARGETING::Target* l_proc_target = *l_proc_iter;

        //  trace HUID
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "target HUID %.8X", TARGETING::get_huid(l_proc_target));

        // cast OUR type of target to a FAPI type of target.
        fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                                         (const_cast<TARGETING::Target*>(
                                                         l_proc_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl,
                         proc_set_max_pstate,
                         l_fapi_proc_target);
        if ( l_errl )
        {
            // capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(l_proc_target).addToLog( l_errl );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : setMaxPstate, PLID=0x%x",
                      l_errl->plid()  );
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : setMaxPstate" );
        }
    }   // end for

    return l_errl;
}
#endif

errlHndl_t disableSpecialWakeup()
{
    errlHndl_t l_errl = NULL;

    // loop thru all proc and find all functional ex units
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);
    for (TargetHandleList::const_iterator l_procIter =
         l_procTargetList.begin();
         l_procIter != l_procTargetList.end();
         ++l_procIter)
    {
        const TARGETING::Target* l_pChipTarget = *l_procIter;

        // Get EX list under this proc
        TARGETING::TargetHandleList l_exList;
        getChildChiplets( l_exList, l_pChipTarget, TYPE_EX );

        for (TargetHandleList::const_iterator
             l_exIter = l_exList.begin();
             l_exIter != l_exList.end();
             ++l_exIter)
        {
            const TARGETING::Target * l_exTarget = *l_exIter;

            fapi::Target l_fapi_ex_target
                ( TARGET_TYPE_EX_CHIPLET,
                  (const_cast<TARGETING::Target*>(l_exTarget)) );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Running p8_cpu_special_wakeup(DISABLE) "
                      "on EX target HUID %.8X",
                      TARGETING::get_huid(l_exTarget));

            FAPI_INVOKE_HWP(l_errl,
                            p8_cpu_special_wakeup,
                            l_fapi_ex_target,
                            SPCWKUP_DISABLE,
                            HOST);

            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Disable p8_cpu_special_wakeup ERROR :"
                           " Returning errorlog, reason=0x%x",
                           l_errl->reasonCode() );

                // capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(l_exTarget).addToLog( l_errl );

                break;
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS: Disable special wakeup");
            }
        }
        if(l_errl)
        {
            break;
        }
    }

    return l_errl;
}


};   // end namespace
