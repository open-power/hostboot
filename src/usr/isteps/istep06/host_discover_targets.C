/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_discover_targets.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
/* [+] Google Inc.                                                        */
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
#include <sys/misc.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
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
#ifdef CONFIG_BMC_IPMI
#include <ipmi/ipmifruinv.H>
#include <ipmi/ipmisensor.H>
#endif
#include <fapi2/plat_hwp_invoker.H>
#include <fapi2/target.H>

//SBE interfacing
#include    <sbeio/sbeioif.H>
#include    <sys/misc.h>

#include <p9_cpu_special_wakeup.H>
#include <p9_query_core_access_state.H>
#include <p9_query_cache_access_state.H>
#include <p9_hcd_core_stopclocks.H>
#include <p9_hcd_cache_stopclocks.H>
#include <p9_pm_ocb_init.H>
#include <p9_pm_ocb_indir_setup_linear.H>
#include <p9_pm_ocb_indir_access.H>
#include <p9_hcd_common.H>
#include <p9_quad_power_off.H>
#include <p9_perv_scom_addresses.H>

#ifdef CONFIG_PRINT_SYSTEM_INFO
#include <stdio.h>
#include <attributetraits.H>
#endif

namespace ISTEP_06
{

#ifdef CONFIG_PRINT_SYSTEM_INFO

//Loop through list of targets and print out HUID and other key attributes if
//the target has it
void print_target_list(TARGETING::TargetHandleList i_targetList)
{

    for(auto & l_targ : i_targetList)
    {
        char * l_targetString =
        l_targ->getAttr<TARGETING::ATTR_PHYS_PATH>().toString();

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "%s", l_targetString);

        free(l_targetString);

        //Every target has a HUID so it is safe to assume this will return okay
        //from getAttr
        uint32_t l_huid =  get_huid(l_targ );

        //if output says DEAD then the attribute is not defined
        uint32_t l_isFunc = 0xDEAD;
        uint32_t l_isPres = 0xDEAD;
        uint32_t l_pos = 0xDEAD;
        uint32_t l_fapi_pos = 0xDEAD;
        uint32_t l_chip_unit = 0xDEAD;

        //The rest of these attributes may or may not exist on the target, so
        //only add them to the string if the attribute exists
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


/**
*  @brief  Walk through list of PROC chip targets and send a continueMPIPL
*          FIFO chip-op to all of the slave PROC chips
*
*  @return     errlHndl_t
*/
errlHndl_t sendContinueMpiplChipOp()
{
    errlHndl_t l_err = nullptr;

    TARGETING::TargetHandleList l_procChips;
    TARGETING::getAllChips(l_procChips, TARGETING::TYPE_PROC, true);
    TARGETING::PROC_SBE_MASTER_CHIP_ATTR l_is_master_chip = 1;

    for(const auto & l_chip : l_procChips)
    {
        l_is_master_chip = l_chip->getAttr<TARGETING::ATTR_PROC_SBE_MASTER_CHIP>();
        if(!l_is_master_chip)
        {
            l_err = SBEIO::sendContinueMpiplRequest(l_chip);

            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Failed sending continueMPIPL request on this proc = %x",
                          l_chip->getAttr<TARGETING::ATTR_HUID>());
                break;
            }
        }
    }

return l_err;
}


/**
*  @brief  loop through slave quads, make sure clocks are stopped
*          (core and cache) and power them down
*
*  @return     errlHndl_t
*/
errlHndl_t powerDownSlaveQuads()
{
    TARGETING::Target* l_sys_target = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys_target);
    errlHndl_t l_err = NULL;
    const uint8_t SIZE_OF_RING_DATA_PER_EQ = 0x40;
    const uint8_t NUM_ENTRIES_IN_RING_DATA = 0x8;
    const uint32_t OCC_SRAM_RING_STASH_BAR = 0xFFF3FC00;
    uint64_t EX_0_CME_SCOM_SICR_SCOM1 = 0x1001203E;
    uint64_t CME_SCOM_SICR_PM_EXIT_C0_AND_C1_MASK = 0x0C00000000000000;

    bool l_isMasterEq = false;
    uint64_t l_ringData[8] = {0,0,0,0,0,0,0,0};
    uint32_t l_ocb_buff_length_act = 0;
    uint8_t l_quad_pos;
    uint32_t l_ringStashAddr;
    size_t   MASK_SIZE = sizeof(CME_SCOM_SICR_PM_EXIT_C0_AND_C1_MASK);

    TARGETING::TargetHandleList l_eqTargetList;
    getAllChiplets(l_eqTargetList, TARGETING::TYPE_EQ, true);

    TARGETING::TargetHandleList l_procChips;
    TARGETING::getAllChips(l_procChips, TARGETING::TYPE_PROC, true);

    uint8_t  l_isRingSaveMpipl = 0;
    FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_RING_SAVE_MPIPL, l_procChips[0], l_isRingSaveMpipl);


    //Need to know who master is so we can skip them
    uint8_t l_masterCoreId = TARGETING::getMasterCore()->getAttr<TARGETING::ATTR_CHIP_UNIT>();

    //Loop through EQs
    for(const auto & l_eq_target : l_eqTargetList)
    {
        l_isMasterEq = false;
        fapi2::Target <fapi2::TARGET_TYPE_EQ> l_fapi_eq_target (l_eq_target);
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_chip =
            l_fapi_eq_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

        TARGETING::ATTR_PROC_SBE_MASTER_CHIP_type l_is_master_chip;
        FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP, l_chip, l_is_master_chip);

        TARGETING::TargetHandleList l_coreTargetList;
        TARGETING::getChildChiplets( l_coreTargetList,
                                     l_eq_target,
                                     TARGETING::TYPE_CORE,
                                     true);
        //Check if either of the cores is master (probably could just check the first)
        if (l_is_master_chip == 1)
        {
            for(const auto & l_core_target : l_coreTargetList)
            {
                if(l_core_target->getAttr<TARGETING::ATTR_CHIP_UNIT>() == l_masterCoreId)
                {
                    l_isMasterEq = true;
                    break;
                }
            }
        }

        //If this is the master quad, we have already power cycled so we dont need this
        if(l_isMasterEq)
        {
            //deassert pm exit flag on master core (both ex targs to be safe)
            TARGETING::TargetHandleList l_exChildren;
            TARGETING::getChildChiplets( l_exChildren,
                                         l_eq_target,
                                         TARGETING::TYPE_EX,
                                         true);

            //TODO 171340 Need to rm clear of PM_EXIT bit in EX_0_CME_SCOM_SICR_SCOM1 reg during MPIPL
            for(const auto & l_ex_child : l_exChildren)
            {
                // Clear bits 4 & 5 of CME_SCOM_SICR which sets PM_EXIT for C0 and C1 respectively
                l_err = deviceWrite(l_ex_child,
                                    &CME_SCOM_SICR_PM_EXIT_C0_AND_C1_MASK,
                                    MASK_SIZE,
                                    DEVICE_SCOM_ADDRESS(EX_0_CME_SCOM_SICR_SCOM1)); //0x1001203E
                if(l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "Error clearing bits 4 and 5 of CME_SCOM_SICR on ex %d", l_ex_child->getAttr<TARGETING::ATTR_CHIP_UNIT>());
                    break;
                }
            }

            if(l_err)
            {
                //If there is an error break out of the EQ loop, something is wrong
                break;
            }
            else
            {
                //continue to next EQ
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Found and prepped master, jumping to next EQ");
                continue;
            }
        }

        //Stop Clocks on all the cores
        for(const auto & l_core_target : l_coreTargetList)
        {
            fapi2::Target <fapi2::TARGET_TYPE_CORE> l_fapi_core_target (l_core_target);
            bool l_isScomable = false;
            bool l_isScanable = false;
            //Check if the core target has clocks running
            FAPI_INVOKE_HWP(l_err,
                            p9_query_core_access_state,
                            l_fapi_core_target,
                            l_isScomable,
                            l_isScanable);
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Error reading core state for core %d", l_core_target->getAttr<TARGETING::ATTR_CHIP_UNIT>());
                //Break out of core for-loop
                break;
            }

            //If clocks are running (IE is scommable) then stop them
            if(l_isScomable)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Stopping core %d", l_core_target->getAttr<TARGETING::ATTR_CHIP_UNIT>());
                FAPI_INVOKE_HWP(l_err,
                                p9_hcd_core_stopclocks,
                                l_fapi_core_target);
                if(l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "Error stopping clocks on core %d", l_core_target->getAttr<TARGETING::ATTR_CHIP_UNIT>());
                    //Break out of core for-loop
                    break;
                }
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Core %d is not scommable according to query", l_core_target->getAttr<TARGETING::ATTR_CHIP_UNIT>());
            }
        }

        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "An error occurred while attempting to stop clocks on the core, skipping attempt to stop cache and returning error");
            //Break out of EQ for-loop
            break;
        }


        do
        {
            bool l_l2IsScomable = false;
            bool l_l2IsScanable = false;
            bool l_l3IsScomable = false;
            bool l_l3IsScanable = false;

            //Same thing with cache, need to check if any clocks are running
            FAPI_INVOKE_HWP(l_err,
                            p9_query_cache_access_state,
                            l_fapi_eq_target,
                            l_l2IsScomable,
                            l_l2IsScanable,
                            l_l3IsScomable,
                            l_l3IsScanable);

            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "Error checking cache access state for EQ %d", l_eq_target->getAttr<TARGETING::ATTR_CHIP_UNIT>());
                //Break from do-while
                break;
            }

            //If the l3 is scommable then the clocks are running and we need to stop them
            if(l_l3IsScomable)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Stopping even ex for eq %d", l_eq_target->getAttr<TARGETING::ATTR_CHIP_UNIT>());
                //Stop clocks on both EXs
                FAPI_INVOKE_HWP(l_err,
                                p9_hcd_cache_stopclocks,
                                l_fapi_eq_target,
                                p9hcd::CLK_REGION_ALL_BUT_EX_DPLL,
                                p9hcd::BOTH_EX);
                if(l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "Error stopping clocks on EVEN EX of EQ %d", l_eq_target->getAttr<TARGETING::ATTR_CHIP_UNIT>());
                    //Break from do-while
                    break;
                }
            }

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Powering down EQ %d", l_eq_target->getAttr<TARGETING::ATTR_CHIP_UNIT>());
            //Power down slave quad
            FAPI_INVOKE_HWP(l_err,
                            p9_quad_power_off,
                            l_fapi_eq_target,
                            l_ringData);
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Error powering off EQ %d", l_eq_target->getAttr<TARGETING::ATTR_CHIP_UNIT>());
                //Break from do-while
                break;
            }

            if(l_isRingSaveMpipl)
            {
                FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_fapi_eq_target, l_quad_pos);

                l_ringStashAddr = OCC_SRAM_RING_STASH_BAR + (SIZE_OF_RING_DATA_PER_EQ * l_quad_pos);

                // Setup use OCB channel 0 for placing ring data in SRAM
                FAPI_INVOKE_HWP(l_err, p9_pm_ocb_indir_setup_linear, l_chip,
                            p9ocb::OCB_CHAN0,
                            p9ocb::OCB_TYPE_LINSTR,
                            l_ringStashAddr);   // Bar

                FAPI_INVOKE_HWP(l_err, p9_pm_ocb_indir_access,
                            l_chip,
                            p9ocb::OCB_CHAN0,
                            p9ocb::OCB_PUT,
                            NUM_ENTRIES_IN_RING_DATA,
                            true,
                            l_ringStashAddr,
                            l_ocb_buff_length_act,
                            l_ringData);

                for(int x = 0; x < NUM_ENTRIES_IN_RING_DATA; x++)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "Wrote %lx to OCC SRAM addr: 0x%lx", l_ringData[x], l_ringStashAddr + (x * 8));
                }
            }

            if(l_err)
            {
                //Dont try to power down anymore EQs if we get a scom fail
                break;
            }

        }while(0);

        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Error detected while attempting to power off EQ 0x%x" , l_eq_target->getAttr<TARGETING::ATTR_CHIP_UNIT>());
            //Break out of EQ for loop
            break;
        }
    }//end EQ for-loop

    return l_err;
}

void* host_discover_targets( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_discover_targets entry" );

    errlHndl_t l_err = nullptr;
    ISTEP_ERROR::IStepError l_stepError;

    // Check whether we're in MPIPL mode
    TARGETING::Target* l_pTopLevel = nullptr;
    TARGETING::targetService().getTopLevelTarget( l_pTopLevel );
    assert(l_pTopLevel, "host_discover_targets: no TopLevelTarget");

    if (l_pTopLevel->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "host_discover_targets: MPIPL mode, targeting"
                  "information has already been loaded from memory"
                  "when the targeting service started");
        do
        {
            //Need to power down the slave quads
            l_err = powerDownSlaveQuads();
            if (l_err)
            {
                break;
            }

            //Send continue mpipl op to slave procs
            l_err = sendContinueMpiplChipOp();
            if (l_err)
            {
                break;
            }
        }while(0);

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
    if (nullptr == l_err) //discoverTargets worked
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
