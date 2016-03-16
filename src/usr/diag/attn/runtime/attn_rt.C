/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/attn_rt.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#include <runtime/interface.h>
#include <runtime/rt_targeting.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errno.h>

using namespace std;
using namespace TARGETING;
using namespace ATTN;

namespace ATTN_RT
{
    /** Enable chip attentions
     *
     *  @return 0 on success else return code
     */
    int enableAttns(void)
    {
        // TODO RTC 134050 Post init setups are temporarily here because
        // Opal has not set up pnor or ipmi before calling rt_main.
        static bool onlyCallApplyTempOverridesOnce = false;
        if (!onlyCallApplyTempOverridesOnce)
        {
            ATTN_SLOW("ATTN_RT::enableAttns - call initialzation routines");
            postInitCalls_t* rtPost = getPostInitCalls();
            rtPost->callApplyTempOverrides();
            onlyCallApplyTempOverridesOnce = true;
        }

        ATTN_SLOW(ENTER_MRK"ATTN_RT::enableAttns");

        int rc = 0;
        errlHndl_t err = NULL;
        err = Singleton<Service>::instance().enableAttns();
        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
            rc = -1;
        }

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
        MemOps & memOps = getMemOps();
        uint64_t l_iprScomData = 0;


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

            // For host attentions, clear gpio interrupt type register.
            // If we do not clear gpio register, ipoll status will again
            // get set and we will end up in infinite loop.

            uint64_t hostMask = 0;
            IPOLL::getCheckbits(HOST_ATTN, hostMask);

            if( i_ipollMask & hostMask)
            {
                // After handling attn, check GP1 for more attns
                // as there could be additional memory units with attns.
                attentions.clear();

                err = memOps.resolve(proc, attentions);

                if(err)
                {
                    ATTN_ERR("RT GP1 Chk:memOps  returned error.HUID:0X%08X ",
                              get_huid( proc ));
                    break;
                }


                // Save the IPR if any attns still active on Centaurs
                if (!attentions.empty())
                {
                    err = getScom(proc, INTR_TYPE_LCL_ERR_STATUS_REG,
                                  l_iprScomData);

                    if(err)
                    {
                        ATTN_ERR("RT SaveIPR returned error.HUID:0X%08X ",
                                  get_huid( proc ));
                        break;
                    }

                } // end if any attentions


                // Clear the IPR (interrupt presentation register)
                err = putScom(proc, INTR_TYPE_LCL_ERR_STATUS_AND_REG, 0);

                if(err)
                {
                    ATTN_ERR("ATTN_RT::handleAttns putscom failed for "
                             "RtProc: %llx address:0x%08X", i_proc,
                              INTR_TYPE_LCL_ERR_STATUS_AND_REG);
                    break;
                }


                // Restore the IPR if any attns still active in Centaurs
                if (!attentions.empty())
                {
                    err = putScom(proc, INTR_TYPE_LCL_ERR_STATUS_OR_REG,
                                  l_iprScomData);

                    if(err)
                    {
                        ATTN_ERR("RT RestoreIPR returned error.HUID:0X%08X ",
                                  get_huid( proc ));
                        break;
                    }

                } // end if any attentions

            } // end if i_ipollMask & hostMask)

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

            rt_intf->enable_attns  = &enableAttns;
            rt_intf->disable_attns = &disableAttns;
            rt_intf->handle_attns  = &handleAttns;
        }
    };

    registerAttn g_registerAttn;
}

