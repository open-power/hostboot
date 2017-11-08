/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/attn_rt.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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
#include <runtime/rt_targeting.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errno.h>
#include <prdf/common/prdfMain_common.H>

using namespace std;
using namespace TARGETING;
using namespace ATTN;
using namespace PRDF;

namespace ATTN_RT
{
    /** Enable chip attentions
     *
     *  @return 0 on success else return code
     */
    int enableAttns(void)
    {
        ATTN_SLOW(ENTER_MRK"ATTN_RT::enableAttns");

        int rc = 0;
        errlHndl_t err = NULL;

        do
        {
            err = initialize();
            if ( nullptr != err )
            {
                ATTN_ERR( "ATTN_RT::enableAttns: Failed to initialize PRD" );

                // Ensure the error log is visible.
                if ( err->sev() < ERRORLOG::ERRL_SEV_PREDICTIVE )
                    err->setSev( ERRORLOG::ERRL_SEV_PREDICTIVE );

                errlCommit(err, ATTN_COMP_ID);
                rc = -1;
                break;
            }

            err = Singleton<Service>::instance().enableAttns();
            if(err)
            {
                errlCommit(err, ATTN_COMP_ID);
                rc = -1;
            }
        }while(0);

        ATTN_SLOW(EXIT_MRK"ATTN_RT::enableAttns rc: %d", rc);

        return rc;
    }

    /** Disable chip attentions
     *
     *  @return 0 on success else return code
     */
    int disableAttns(void)
    {
        ATTN_SLOW(ENTER_MRK"ATTN_RT::disableAttns");

        int rc = 0;
        errlHndl_t err = NULL;
        err = Singleton<Service>::instance().disableAttns();
        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
            rc = -1;
        }

        ATTN_SLOW(EXIT_MRK"ATTN_RT::disableAttns rc: %d", rc);

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
                rc = EINVAL;
                break;
            }

            err = Singleton<Service>::instance().handleAttentions(proc);
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
            errlCommit( err, ATTN_COMP_ID );
            if(0 == rc)
            {
                rc = -1;
            }
        }


        attentions.clear();
        ATTN_SLOW(EXIT_MRK"ATTN_RT::handleAttns rc: %d", rc);

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
        uint64_t  l_ipollEvents = 0;

        // Host side should allow 'Recov', 'UnitCs' and 'HostInt'
        // SP side should allow 'Chkstop', 'Recov', 'Special'
        // and maybe the mystery bit (route to SP).
        l_ipollEvents = IPOLL_RECOVERABLE    | IPOLL_UNIT_CS       |
                        IPOLL_HOST_ATTN      | IPOLL_SP_CHECK_STOP |
                        IPOLL_SP_RECOVERABLE | IPOLL_SP_SPECIAL    |
                        IPOLL_ROUTE_TO_SP ;

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

            rt_intf->enable_attns      = &enableAttns;
            rt_intf->disable_attns     = &disableAttns;
            rt_intf->handle_attns      = &handleAttns;
            rt_intf->get_ipoll_events  = &getIpollEvents;
        }
    };

    registerAttn g_registerAttn;
}

