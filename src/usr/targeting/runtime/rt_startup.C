/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/rt_startup.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <runtime/rt_targeting.H>
#include <runtime/interface.h>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/trace.H>
#include <targeting/common/utilFilter.H>
#include <sbeio/runtime/sbe_msg_passing.H>
#include <sbeio/sbeioreasoncodes.H>


using namespace TARGETING;

namespace RT_TARG
{

void clearPendingSbeMsgs()
{
    TRACFCOMP(g_trac_targeting, ENTER_MRK"clearPendingSbeMsgs");
    errlHndl_t l_errl = nullptr;
    do
    {
        //get runtime interfaces
        runtimeInterfaces_t* l_rt = getRuntimeInterfaces();
        if(nullptr == l_rt)
        {
            TRACFCOMP(g_trac_targeting,"clearPendingSbeMsgs: "
                    "Unable to get runtime interfaces.");
            break;
        }
        else if(not l_rt->sbe_message_passing)
        {
            TRACFCOMP(g_trac_targeting,"clearPendingSbeMsgs: "
                    "sbe_message_passing runtime interface "
                    "has not been set.");
            break;
        }

        TARGETING::TargetHandleList l_procList;
        getAllChips(l_procList, TARGETING::TYPE_PROC, true);

        if(0 == l_procList.size())
        {
            TRACFCOMP(g_trac_targeting,"clearPendingSbeMsgs: "
                    "Unable to get proc targets."
                   );
            break;
        }

        for( const auto & l_procTarget : l_procList )
        {
            // clear out the two bits for this processor target
            l_errl = SBE_MSG::process_sbe_msg_update_cfam( l_procTarget, 0x0,
                (SBE_MSG::SBE_MESSAGE_PROCESSING_IN_PROGRESS |
                SBE_MSG::SBE_MESSAGE_PROCESSING_COMPLETE) );

            if (l_errl)
            {
                TRACFCOMP(g_trac_targeting,ERR_MRK"clearPendingSbeMsgs: "
                    "Failed to clear bits for processor 0x%04X, "
                    "EID %.8X:%.4X", TARGETING::get_huid(l_procTarget),
                    ERRL_GETEID_SAFE(l_errl),
                    ERRL_GETRC_SAFE(l_errl) );
                errlCommit (l_errl, SBE_COMP_ID);
            }
        }
    }
    while(0);

    TRACFCOMP(g_trac_targeting, EXIT_MRK"clearPendingSbeMsgs");
}

    //------------------------------------------------------------------------

    struct registerRtStartup
    {
        registerRtStartup()
        {
            // Register interface for Host to call
            postInitCalls_t * rt_post = getPostInitCalls();
            rt_post->callClearPendingSbeMsgs = &clearPendingSbeMsgs;
        }
    };

    registerRtStartup g_registerRtStartup;

}; // End namespace RT_TARG
