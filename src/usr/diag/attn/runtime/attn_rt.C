/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/attn_rt.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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

#include "runtime/attnsvc.H"
#include "common/attntrace.H"
#include "common/attnmem.H"
#include "common/attnbits.H"
#include <runtime/interface.h>
#include <targeting/runtime/rt_targeting.H>
#include <targeting/translateTarget.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errno.h>
#include <prdf/common/prdfMain_common.H>
#include <util/runtime/rt_fwreq_helper.H>

#include <p10_io_iohs_firmask_save_restore.H>
#include <fapi2/target.H>              // fapi2::Target
#include <fapi2/plat_hwp_invoker.H>    // FAPI_INVOKE_HWP

using namespace std;
using namespace TARGETING;
namespace  TU = TARGETING::UTIL;
namespace  T = TARGETING;
using namespace ATTN;
using namespace PRDF;
extern trace_desc_t* g_trac_hbrt;

namespace ATTN_RT
{
    /** Enable chip attentions
     *
     *  @return 0 on success else return code
     */
    int enableAttns(void)
    {
        TRACFCOMP(g_trac_hbrt, ENTER_MRK" enable_attns");
        ATTN_SLOW(ENTER_MRK"ATTN_RT::enableAttns");

        int rc = 0;
        errlHndl_t err = NULL;

        do
        {
            // Restore FIR mask values that were stored in attributes during
            // host_discover_targets in an MPIPL. Now that HBRT is active, IOHS
            // peer targets are known so it is okay to re-enable the FIRs that
            // Hostboot masked off earlier in an MPIPL.  This steps is not
            // needed after a normal IPL since the FIRs are only unmasked after
            // istep 18, and PRD is not watching for problems on the inter-node
            // buses until after HBRT starts.
            if(TU::assertGetToplevelTarget()->getAttr<T::ATTR_IS_MPIPL_HB>())
            {
                // Get a list of all the functional processors in the system
                T::TargetHandleList l_targetList;
                getAllChips(l_targetList, T::TYPE_PROC);

                // Loop through all processor chip targets
                for (const auto & l_target: l_targetList)
                {
                    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapi2Target(l_target);

                    FAPI_INVOKE_HWP(err,
                                    p10_io_iohs_firmask_save_restore,
                                    l_fapi2Target, p10iofirmasksaverestore::RESTORE);
                    if(err)
                    {
                        // Commit error but don't fail, we lose debug capabilities
                        // but this should not fail the boot
                        errlCommit(err, FAPI2_COMP_ID);
                    }
                }
            }

            err = initialize();
            if (err)
            {
                ATTN_ERR( "ATTN_RT::enableAttns: Failed to initialize PRD" );

                // Ensure the error log is visible.
                if ( err->sev() < ERRORLOG::ERRL_SEV_PREDICTIVE )
                    err->setSev( ERRORLOG::ERRL_SEV_PREDICTIVE );

                rc = ERRL_GETRC_SAFE(err);
                errlCommit( err, ATTN_COMP_ID );
                break;
            }

            err = Service::getGlobalInstance()->enableAttns();
            if(err)
            {
                rc = ERRL_GETRC_SAFE(err);
                errlCommit( err, ATTN_COMP_ID );
            }
        }while(0);

        ATTN_SLOW(EXIT_MRK"ATTN_RT::enableAttns rc: %d", rc);

        TRACFCOMP(g_trac_hbrt, EXIT_MRK" enable_attns: rc=0x%X",rc);
        return rc;
    }

    /** Disable chip attentions
     *
     *  @return 0 on success else return code
     */
    int disableAttns(void)
    {
        TRACFCOMP(g_trac_hbrt, ENTER_MRK" disable_attns");
        ATTN_SLOW(ENTER_MRK"ATTN_RT::disableAttns");

        int rc = 0;
        errlHndl_t err = NULL;
        err = Service::getGlobalInstance()->disableAttns();
        if(err)
        {
            rc = ERRL_GETRC_SAFE(err);
            errlCommit( err, ATTN_COMP_ID );
        }

        ATTN_SLOW(EXIT_MRK"ATTN_RT::disableAttns rc: %d", rc);

        TRACFCOMP(g_trac_hbrt, EXIT_MRK" disable_attns: rc=0x%X",rc);
        return rc;
    }

    /** brief handle chip attentions
     *
     *  @param[in] i_proc - processor chip id at attention
     *                      XSCOM chip id based on devtree defn
     *  @param[in] i_ipollStatus - processor chip Ipoll status
     *  @param[in] i_ipollMask   - processor chip Ipoll mask
     *  @return 0 on success else return code
     */
    int handleAttns(uint64_t i_proc,
                    uint64_t i_ipollStatus,
                    uint64_t i_ipollMask)
    {
        TRACFCOMP(g_trac_hbrt, ENTER_MRK" handle_attns");
        ATTN_SLOW(ENTER_MRK"ATTN_RT::handleAttns RtProc: %llx"
                  ", ipollMask: %llx, ipollStatus: %llx",
                  i_proc, i_ipollMask, i_ipollStatus);

        int rc = 0;
        errlHndl_t err = NULL;
        AttentionList attentions;

        do
        {
            // Convert chipIds to HB targets
            TargetHandle_t proc = NULL;
            err = RT_TARG::getHbTarget(i_proc, proc);
            if(err)
            {
                ATTN_ERR("ATTN_RT::handleAttns getHbTarget "
                   "returned error for RtProc: %llx", i_proc);
                break;
            }

            err = Service::getGlobalInstance()->handleAttentions(proc);
            if(err)
            {
                ATTN_ERR("ATTN_RT::handleAttns service::handleAttentions "
                   "returned error for RtProc: %llx", i_proc);
                break;
            }

            // On P8,
            // For host attentions, clear gpio interrupt type register.
            // If we do not clear gpio register, ipoll status will again
            // get set and we will end up in infinite loop.

            // For P9,
            // Host attentions should be coming thru the
            // normal (IPOLL) Error status reg. Hence, we shouldn't
            // have to play with the IPR (interrupt presentation register)
            // which was involved with the gpio/gpin register where
            // centaur routed its attentions.


        } while(0);

        if(err)
        {
            if(0 == rc)
            {
                rc = ERRL_GETRC_SAFE(err);
            }
            errlCommit( err, ATTN_COMP_ID );
        }


        attentions.clear();
        ATTN_SLOW(EXIT_MRK"ATTN_RT::handleAttns rc: %d", rc);

        TRACFCOMP(g_trac_hbrt, EXIT_MRK" handle_attns: rc=0x%X",rc);
        return rc;
    }


    /** brief  getIpollEvents
     *
     * Bits that are *set* in this bitmask represent events that will be
     * allowed to flow to the HOST or Service Processor.
     *
     *  @return Value indicating which attention events should
     *          be enabled in the IPOLL mask register.
     */

    uint64_t getIpollEvents( void )
    {
        TRACFCOMP(g_trac_hbrt, ENTER_MRK" get_ipoll_events");
        uint64_t  l_ipollEvents = 0;

        // Host side should allow 'Recov', 'UnitCs' and 'HostInt'
        // SP side should allow 'Chkstop', 'Recov', 'Special'
        // and maybe the mystery bit (route to SP).
        l_ipollEvents = IPOLL_RECOVERABLE    | IPOLL_UNIT_CS       |
                        IPOLL_HOST_ATTN      | IPOLL_SP_CHECK_STOP |
                        IPOLL_SP_RECOVERABLE | IPOLL_SP_SPECIAL    |
                        IPOLL_ROUTE_TO_SP ;

        TRACFCOMP(g_trac_hbrt, EXIT_MRK" get_ipoll_events: rc=0x%X",l_ipollEvents);
        return(l_ipollEvents);

    } // end getIpollEvents


    // register runtimeInterfaces
    struct registerAttn
    {
        registerAttn()
        {
            runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
            if (NULL == rt_intf)
            {
                return;
            }

            rt_intf->enable_attns = DISABLE_MCTP_WRAPPER(enableAttns);
            rt_intf->disable_attns = DISABLE_MCTP_WRAPPER(disableAttns);
            rt_intf->handle_attns = DISABLE_MCTP_WRAPPER(handleAttns);
            rt_intf->get_ipoll_events = DISABLE_MCTP_WRAPPER(getIpollEvents);
        }
    };

    registerAttn g_registerAttn;
}

