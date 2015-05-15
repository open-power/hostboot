/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrPlatOverride.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#include <runtime/rt_targeting.H>
#include <targeting/common/commontargeting.H>
#include <targeting/attrPlatOverride.H>
#include <hwpf/plat/fapiPlatAttrOverrideSync.H>
#include <targeting/common/trace.H>
#include <errl/errlmanager.H>

using namespace TARGETING;

namespace RT_TARG
{

int apply_attr_override(uint8_t* i_data,
                        size_t i_size )
{
    int rc = 0;
    errlHndl_t l_errl = NULL;

    TRACFCOMP(g_trac_targeting, "enter apply_attr_override");

    // Clear fapi and targeting attribute override tanks. The tanks are
    // expected to be empty. The passed overrides are added, not updated
    // in place.
    AttributeTank * l_pAttributeTank =
                    &fapi::theAttrOverrideSync().iv_overrideTank;
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
    else
    {
        TRACFCOMP(g_trac_targeting, "apply_attr_override succeed");
    }
    return rc;
}

//------------------------------------------------------------------------

struct registerTargRT
{
    registerTargRT()
    {
        runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
        rt_intf->apply_attr_override = &apply_attr_override;
    }
};

registerTargRT g_registerTargRT;

} // end of namespace


