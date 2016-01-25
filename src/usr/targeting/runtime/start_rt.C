/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/start_rt.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#include <targeting/common/commontargeting.H>
#include <targeting/common/targetservice.H>
#include <targeting/attrrp.H>
#include <targeting/common/trace.H>
#include <targeting/common/utilFilter.H>

using namespace TARGETING;

namespace RT_TARG
{
    void adjustTargeting4Runtime();

    static void initTargeting() __attribute__((constructor));
    static void initTargeting()
    {
        errlHndl_t l_errl = NULL;

        AttrRP::init(l_errl);
        if (l_errl)
        {
            errlCommit(l_errl, TARG_COMP_ID);
            assert(false);
        }

        TargetService& l_targetService = targetService();
        (void)l_targetService.init();

        adjustTargeting4Runtime();
    }

    // Make any adjustments needed to targeting for runtime
    void adjustTargeting4Runtime()
    {
        TRACDCOMP(g_trac_targeting,"adjustTargeting4Runtime");

        // Loop through all targets and fix those with ATTR_PEER_TARGETs.
        //
        // ATTR_PEER_TARGET is the only attribute using the Target_t type.
        // The value of a Target_t attribute is a Target * "pointer" to
        // another target. The value is set up by the targeting scripts at
        // build time. Targeting uses a translate function to nagivate through
        // the targeting binary. There is a runtime translation function used
        // at run time to account for the location of the targeting binary
        // being at a different spot at runtime. The Target_t * value of
        // the attribute remains pointing into where the targeting binary
        // was at IPL. Using this "old" address would seg fault at run time.
        // The value of the ATTR_PEER_TARGET attributes must be translated
        // for run time.
        // The _trySetAttr is used directly to avoid the trySetAttr template
        // error check that ATTR_PEER_TARGET is only readable, not writable.
        // adjustTargeting4Runtime has been included as a friend to allow
        // access to the private target class methods.
        const Target* l_pUnused = NULL;
        size_t l_xlateCnt = 0;
        for (TargetIterator target = targetService().begin();
                target != targetService().end();
                ++target)
        {
            const TARGETING::Target * l_target = *target;
            TARGETING::Target * l_peer =  static_cast<Target*>(NULL);
            bool l_hasPeer = l_target->tryGetAttr<ATTR_PEER_TARGET>(l_peer);
            if (l_hasPeer)
            {
                TRACDCOMP(g_trac_targeting,
                      "translate peer target for=%p %x",
                      l_target, get_huid(l_target));

                ATTR_PEER_TARGET_type l_xlated = (TARGETING::Target *)
                                   Singleton<AttrRP>::instance().
                                   AttrRP::translateAddr(l_peer,l_pUnused);
                bool l_fixed = false;
                l_fixed = l_target->_trySetAttr(ATTR_PEER_TARGET,
                                      sizeof(l_xlated),
                                      &l_xlated);
                if (l_fixed)
                {
                    TRACDCOMP(g_trac_targeting, "   to=%p", l_xlated);
                    l_xlateCnt++;
                }
                // Not good if could not be fixed. But might not be referenced.
                // A segment fault will occur if used.
                else
                {
                    TRACFCOMP(g_trac_targeting,
                        "failed to translate peer target HUID=0x%x",
                        get_huid(l_target));
                }
            }
        }
        TRACFCOMP(g_trac_targeting,
              "adjustTargeting4Runtime: %d peer target addresses translated",
               l_xlateCnt);
    }
}
