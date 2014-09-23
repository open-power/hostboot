/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/attn_rt.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

#include "common/attntrace.H"
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
        #define ATTN_FUNC "ATTN_RT::enableAttns() "
        int rc = 0;

        ATTN_ERR(ATTN_FUNC"not implemented yet!");

        return rc;

        #undef ATTN_FUNC
    }

    /** Disable chip attentions
     *
     *  @return 0 on success else return code
     */
    int disableAttns(void)
    {
        #define ATTN_FUNC "ATTN_RT::disableAttns() "
        int rc = 0;

        ATTN_ERR(ATTN_FUNC"not implemented yet!");

        return rc;

        #undef ATTN_FUNC
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
        #define ATTN_FUNC "ATTN_RT::handleAttns() "
        int rc = 0;

        ATTN_ERR(ATTN_FUNC"not implemented yet!");

        return rc;

        #undef ATTN_FUNC
    }

    // register runtime interfaces
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

