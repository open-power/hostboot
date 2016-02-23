/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_discover_targets.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#include <stdint.h>
#include <map>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/attrsync.H>
#include <targeting/namedtarget.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/entitypath.H>
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/hwasPlat.H>

namespace ISTEP_06
{

void* host_discover_targets( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_discover_targets entry" );

    errlHndl_t l_err = NULL;
    ISTEP_ERROR::IStepError l_stepError;

    // Check whether we're in MPIPL mode
    TARGETING::Target* l_pTopLevel = NULL;
    TARGETING::targetService().getTopLevelTarget( l_pTopLevel );
    assert(l_pTopLevel, "host_discover_targets: no TopLevelTarget");

    if (l_pTopLevel->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "host_discover_targets: MPIPL mode");

        // Sync attributes from Fsp
        l_err = TARGETING::syncAllAttributesFromFsp();
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "host_discover_targets: Normal IPL mode");

        l_err = HWAS::discoverTargets();
    }

    if (l_err)
    {
        // Create IStep error log and cross reference occurred error
        l_stepError.addErrorDetails( l_err );
        // Commit Error
        errlCommit (l_err, ISTEP_COMP_ID);
    }

    // Put out some helpful messages that show which targets we actually found
    std::map<TARGETING::TYPE,uint64_t> l_presData;
    for (TARGETING::TargetIterator target = TARGETING::targetService().begin();
         target != TARGETING::targetService().end();
         ++target)
    {
        if (!(target->getAttr<TARGETING::ATTR_HWAS_STATE>().present))
        {
            continue;
        }
        TARGETING::TYPE l_type = target->getAttr<TARGETING::ATTR_TYPE>();
        TARGETING::ATTR_POSITION_type l_pos = 0;
        if( target->tryGetAttr<TARGETING::ATTR_POSITION>(l_pos) )
        {
            l_presData[l_type] |= (0x8000000000000000 >> l_pos);
        }
    }
    TARGETING::EntityPath l_epath; //use EntityPath's translation functions
    for( std::map<TARGETING::TYPE,uint64_t>::iterator itr = l_presData.begin();
         itr != l_presData.end();
         ++itr )
    {
        uint8_t l_type = itr->first;
        uint64_t l_val = itr->second;
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "PRESENT> %s[%.2X]=%.8X%.8X",
                l_epath.pathElementTypeAsString(itr->first),
                                                l_type,
                                                l_val>>32, l_val&0xFFFFFFFF);
#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
        CONSOLE::displayf("HWAS", "PRESENT> %s[%.2X]=%.8X%.8X",
                l_epath.pathElementTypeAsString(itr->first),
                                                l_type,
                                                l_val>>32,
                                                l_val&0xFFFFFFFF );
#endif
    }

#ifdef CONFIG_BMC_IPMI
    // Gather + Send the base IPMI Fru Inventory data to the BMC
    IPMIFRUINV::setData();

    // send DIMM/CORE/PROC sensor status to the BMC
    SENSOR::updateBMCSensorStatus();
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "host_discover_targets exit" );

    return l_stepError.getErrorHandle();
}

};
