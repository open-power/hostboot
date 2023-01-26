/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/start_rt.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2023                        */
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
#include <targeting/common/associationmanager.H>
#include <targeting/attrrp.H>
#include <util/misc.H>
#include <targeting/common/trace.H>
#include <targeting/common/utilFilter.H>
#ifdef CONFIG_PLDM
#include <openbmc/pldm/libpldm/include/libpldm/state_set.h>
#endif

using namespace TARGETING;

namespace RT_TARG
{
    void adjustTargetingForRuntime();

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
        size_t l_numNodes = Singleton<AttrRP>::instance().getNodeCount();
        l_targetService.init(l_numNodes);

        adjustTargetingForRuntime();

        // set global that TARG is ready
        Util::setIsTargetingLoaded();

        if(l_numNodes > 1)
        {
            l_errl = TARGETING::AssociationManager::reconnectSyAndNodeTargets();
            if(l_errl)
            {
                TRACFCOMP(g_trac_targeting, "initTargeting: could not"
                          " reconnectSyAndNodeTargets");
                errlCommit(l_errl, TARG_COMP_ID);
                assert(false, "Could not reconnect system and node targets");
            }
        }

#ifdef CONFIG_PLDM
        // setup runtime variable(s) returned via PLDM sensor
        TargetHandleList l_node_list;
        getEncResources(l_node_list, TYPE_NODE, UTIL_FILTER_ALL);
        for(auto & l_node : l_node_list)
        {
            l_node->setAttr<ATTR_BOOT_PROGRESS_STATE>(PLDM_STATE_SET_BOOT_PROG_STATE_COMPLETED);
        }
#endif
    }

    // Make any adjustments needed to targeting for runtime
    void adjustTargetingForRuntime()
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

        // Also in this function we will reset any mutex attributes we find
        // on any target incase they got left in the locked state when hostboot
        // passed the payload to the hypervisor.

        TargetService& l_targetService = targetService();
        size_t   l_updatedCount = 0;
        uint32_t l_numberMutexAttrsReset = 0;
        uint8_t  l_maxNodeId = l_targetService.getNumInitializedNodes();
        for(uint8_t l_nodeId = NODE0; l_nodeId < l_maxNodeId; ++l_nodeId)
        {
            for (TargetIterator target = l_targetService.begin(l_nodeId);
                 target != l_targetService.end();
                 ++target)
            {
                const TARGETING::Target * l_target = *target;
                // Check if there any mutex attributes we need to reset on this target
                l_numberMutexAttrsReset += l_targetService.resetMutexAttributes(l_target);

                // Check if there is any PEER_TARAGET attribute to update on this target
                if(l_targetService.updatePeerTarget(l_target))
                {
                    l_updatedCount++;
                }
            }
        }
        TRACFCOMP(g_trac_targeting,
                  "adjustTargetingForRuntime: %d peer target addresses "
                  "translated on %d nodes",
                  l_updatedCount,
                  l_maxNodeId);
        TRACFCOMP(g_trac_targeting,
                  "adjustTargetingForRuntime: %d mutex attributes reset "
                  "on %d nodes",
                  l_numberMutexAttrsReset,
                  l_maxNodeId);
    }
}
