/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/attrPlatOverride_rt.C $             */
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

#include <runtime/interface.h>
#include <targeting/runtime/rt_targeting.H>
#include <targeting/common/commontargeting.H>
#include <targeting/attrPlatOverride.H>
#include <fapi2/plat_attr_override_sync.H>
#include <targeting/common/trace.H>
#include <errl/errlmanager.H>
#include <initservice/initserviceif.H>
#include <secureboot/service.H>
#include <targeting/common/targreasoncodes.H>
#include <devicefw/userif.H>
#include <util/runtime/util_rt.H>
#include <util/runtime/rt_fwreq_helper.H>
#include <sys/internode.h>


extern trace_desc_t* g_trac_hbrt;
using namespace TARGETING;

namespace RT_TARG
{

int apply_attr_override(uint8_t* i_data,
                        size_t i_size )
{
    int rc = 0;

    errlHndl_t l_errl = NULL;

    TRACFCOMP(g_trac_hbrt, ENTER_MRK" apply_attr_override");
    TRACFCOMP(g_trac_targeting, "enter apply_attr_override");

    bool l_allowOverrides = true;

    #ifdef CONFIG_SECUREBOOT
    l_allowOverrides = SECUREBOOT::allowAttrOverrides();
    #endif

    if (l_allowOverrides)
    {
        // Clear fapi and targeting attribute override tanks. The tanks are
        // expected to be empty. The passed overrides are added, not updated
        // in place.
        AttributeTank * l_pAttributeTank =
                    &fapi2::theAttrOverrideSync().iv_overrideTank;
        if ((*l_pAttributeTank).attributesExist())
        {
            TRACFCOMP(g_trac_targeting, "apply_attr_override:"
                                        " clear FAPI attribute overrides");
            (*l_pAttributeTank).clearAllAttributes();
        }
        l_pAttributeTank = &Target::theTargOverrideAttrTank();
        if ((*l_pAttributeTank).attributesExist())
        {
            TRACFCOMP(g_trac_targeting, "apply_attr_override:"
                      " clear targeting attribute overrides");
            (*l_pAttributeTank).clearAllAttributes();
        }

        // Pass attribute override blob as a pnor section
        PNOR::SectionInfo_t l_sectionInfo;
        l_sectionInfo.vaddr = (uint64_t)i_data;
        l_sectionInfo.size = i_size;
        l_sectionInfo.id = PNOR::ATTR_TMP;
        l_sectionInfo.name = "Runtime TMP";

        // Process attribute overrides
        l_errl = TARGETING::getAttrOverrides(l_sectionInfo);
        if (l_errl)
        {
            TRACFCOMP(g_trac_targeting, "apply_attr_override:"
                                        " getAttrOverrides failed");
            errlCommit(l_errl, TARG_COMP_ID);
            rc = -1;
        }
    }
    else
    {
#ifdef CONFIG_SECUREBOOT
        TRACFCOMP(g_trac_targeting, "apply_attr_override: skipping override"
            " due to SECUREBOOT enablement");

        /*@
         * @errortype
         * @moduleid     TARG_APPLY_ATTR_OVER
         * @reasoncode   TARG_RC_APPLY_ATTR_OVER_NOT_ALLOWED
         * @devdesc      PnorRP::getSectionInfo> Skipping attribute override
         *               because of secureboot enablement
         * @custdesc     Attributes overrides are not allowed in secure mode.
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        TARG_APPLY_ATTR_OVER,
                                        TARG_RC_APPLY_ATTR_OVER_NOT_ALLOWED,
                                        0,
                                        0,
                                        true /* Add HB SW Callout */);
        l_errl->collectTrace(TARG_COMP_NAME);
        errlCommit(l_errl, TARG_COMP_ID);
        rc = -1;
#endif
    }

    TRACFCOMP(g_trac_hbrt, EXIT_MRK" apply_attr_override: rc=%d");

    return rc;
}

void applyTempOverrides()
{
    TRACFCOMP(g_trac_targeting, ENTER_MRK"applyTempOverrides");
    errlHndl_t l_err = NULL;
    bool l_usingStash = false;

    for(NODE_ID l_nodeId = NODE0;
        l_nodeId < Singleton<AttrRP>::instance().getNodeCount();
        l_nodeId++)
    {
        // Get a pointer to the reserved memory where HB
        // saved the overrides during boot
        uint64_t l_overAttrSize = 0;
        uint64_t l_overAddr = hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_ATTROVER,
                                                 l_nodeId, l_overAttrSize);


        // Having no overrides is a normal thing
        if( (l_overAddr == 0) )
        {
            TRACFCOMP(g_trac_targeting, "No Overrides found" );
            TRACFCOMP(g_trac_targeting, EXIT_MRK"applyTempOverrides");
            continue;
        }
        else
        {
            TRACFCOMP(g_trac_targeting, "Overrides found at %.16llX",
                      l_overAddr );
        }

        // Use a faux PNOR Section that is associated
        //  with the data in mainstore
        PNOR::SectionInfo_t l_info;
        l_info.vaddr = l_overAddr;
        l_info.size = l_overAttrSize;
        l_info.id = PNOR::ATTR_TMP;
        l_info.name = "HBRT Overrides";

        TRACFCOMP(g_trac_targeting," HBRT: processing overrides from boot");
        l_err = TARGETING::getAttrOverrides(l_info);
        if (l_err)
        {
            TRACFCOMP(g_trac_targeting," HBRT: Failed applying overrides");
            if( l_usingStash )
            {
                // if the new RHB is in use, this will always fail
                //  so just delete the error
                delete l_err;
                l_err = nullptr;
            }
            else
            {
                errlCommit( l_err, TARG_COMP_ID );
            }
        }
    }

    TRACFCOMP(g_trac_targeting, EXIT_MRK"applyTempOverrides");
}
//------------------------------------------------------------------------

struct registerTargRT
{
    registerTargRT()
    {
        runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
        rt_intf->apply_attr_override =
                                DISABLE_MCTP_WRAPPER(apply_attr_override);

        postInitCalls_t * rt_post = getPostInitCalls();
        rt_post->callApplyTempOverrides = &applyTempOverrides;
    }
};

registerTargRT g_registerTargRT;

} // end of namespace


