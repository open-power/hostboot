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
#include <vector>
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
#include <vpd/vpd_if.H>
#include <console/consoleif.H>
#include <ipmi/ipmifruinv.H>
#include <ipmi/ipmisensor.H>

#ifdef CONFIG_PRINT_SYSTEM_INFO
#include <stdio.h>
#include <attributetraits.H>
#endif

namespace ISTEP_06
{

#ifdef CONFIG_PRINT_SYSTEM_INFO

//Loop through list of targets and print out HUID and other key attributes if the target has it
void print_target_list(TARGETING::TargetHandleList i_targetList)
{



    for(auto & l_targ : i_targetList)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "%s", l_targ->getAttr<TARGETING::ATTR_PHYS_PATH>().toString());

        //Every target has a HUID so it is safe to assume this will return okay from getAttr
        uint32_t l_huid =  get_huid(l_targ );

        //if output says DEAD then the attribute is not defined
        uint32_t l_isFunc = 0xDEAD;
        uint32_t l_isPres = 0xDEAD;
        uint32_t l_pos = 0xDEAD;
        uint32_t l_fapi_pos = 0xDEAD;
        uint32_t l_chip_unit = 0xDEAD;

        //The rest of these attributes may or may not exist on the target, so only add them to the
        //string if the attribute exists
        TARGETING::AttributeTraits<TARGETING::ATTR_HWAS_STATE>::Type hwasState;
        if(l_targ->tryGetAttr<TARGETING::ATTR_HWAS_STATE>(hwasState))
        {
            l_isFunc = hwasState.functional;
            l_isPres = hwasState.present;
        }

        TARGETING::AttributeTraits<TARGETING::ATTR_POSITION>::Type position;
        if(l_targ->tryGetAttr<TARGETING::ATTR_POSITION>(position))
        {
            l_pos = position;
        }

        TARGETING::AttributeTraits<TARGETING::ATTR_FAPI_POS>::Type fapi_position;
        if(l_targ->tryGetAttr<TARGETING::ATTR_FAPI_POS>(fapi_position))
        {
            l_fapi_pos = fapi_position;
        }

        TARGETING::AttributeTraits<TARGETING::ATTR_CHIP_UNIT>::Type chip_unit;
        if(l_targ->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(chip_unit))
        {
            l_chip_unit = chip_unit;
        }

        //Trace out the string
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"HUID:0x%x   Functional: 0x%x   Present: 0x%x      Position: 0x%x     FAPI_POS: 0x%x     Chip Unit: 0x%x",
                                                     l_huid,      l_isFunc,          l_isPres,          l_pos,             l_fapi_pos,        l_chip_unit);

    }
}

//Debugging tool used to print out target information early on in IPL
void print_system_info(void)
{
    //Vector of target types you want to print out
    std::vector<TARGETING::AttributeTraits<TARGETING::ATTR_TYPE>::Type> types_to_print;

    //Add all the target types that you want to see in the output to this vector
    types_to_print.push_back(TARGETING::TYPE_PROC);
    types_to_print.push_back(TARGETING::TYPE_MCS);
    types_to_print.push_back(TARGETING::TYPE_MCA);
    types_to_print.push_back(TARGETING::TYPE_MCBIST);
    types_to_print.push_back(TARGETING::TYPE_DIMM);

    //Loop through each type to get a list of targets then print it out
    for(auto l_type : types_to_print)
    {
        TARGETING::PredicateCTM l_CtmFilter(TARGETING::CLASS_NA,
                                            l_type,
                                            TARGETING::MODEL_NA);

        // Apply the filter through all targets
        TARGETING::TargetRangeFilter l_targetList(TARGETING::targetService().begin(),
                                                  TARGETING::targetService().end(),
                                                  &l_CtmFilter);

        TARGETING::TargetHandleList l_allTargets;

        for ( ; l_targetList; ++l_targetList)
        {
            l_allTargets.push_back(*l_targetList);
        }

        print_target_list(l_allTargets);
    }

}
#endif

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
                  "host_discover_targets: MPIPL mode, targeting"
                  "information has already been loaded from memory"
                  "when the targeting service started");

    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "host_discover_targets: Normal IPL mode");

        l_err = HWAS::discoverTargets();
    }

#if (defined(CONFIG_MEMVPD_READ_FROM_HW)&&defined(CONFIG_MEMVPD_READ_FROM_PNOR))
    // Now that all targets have completed presence detect and vpd access,
    // invalidate PNOR::CENTAUR_VPD sections where all the targets sharing a
    // VPD_REC_NUM are invalid.
    if (NULL == l_err) //discoverTargets worked
    {
        l_err = VPD::validateSharedPnorCache();
    }
#endif

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

#ifdef CONFIG_PRINT_SYSTEM_INFO
    print_system_info();
#endif

    return l_stepError.getErrorHandle();
}

};
