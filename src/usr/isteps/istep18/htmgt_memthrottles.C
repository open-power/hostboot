/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/htmgt_memthrottles.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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

#ifndef CONFIG_FSP_BUILD

#include "htmgt/htmgt.H"
#include "htmgt/htmgt_reasoncodes.H"
#include <errl/errlmanager.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <initservice/isteps_trace.H>
#include <chips/common/utils/chipids.H>

// Memory Hardware Procedures:
#include <p10_mss_utils_to_throttle.H>
#include <exp_bulk_pwr_throttles.H>
#include <ody_bulk_pwr_throttles.H>

// See src/include/usr/targeting/common/utilFilter.H for handy target utilities

using namespace TARGETING;

/**
 * Uses system attributes:
 *   ATTR_REGULATOR_EFFICIENCY_FACTOR    - Power supply efficiency
 *   ATTR_N_MAX_MEM_POWER_WATTS          - DDR4 Max memory power for N
 *   ATTR_N_PLUS_ONE_MAX_MEM_POWER_WATTS - DDR4 Max memory power for N+1
 *   ATTR_DDR5_N_MAX_MEM_POWER_WATTS          - DDR5 Max memory power for N
 *   ATTR_DDR5_N_PLUS_ONE_MAX_MEM_POWER_WATTS - DDR5 Max memory power for N+1

 *
 * Calculates the memory throttling numerator values/power for:
 * - OT  : System in over-temperature condition
 * - N+1 : System has redundant power
 * - N   : System is in oversubscription (lost redundant power supplies)
 *
 * Writes throttles to attributes under the corresponding OCMB (for HTMGT/OCC use)
 *   ATTR_N_PLUS_ONE_N_PER_SLOT - Redundant throttles per slot
 *   ATTR_N_PLUS_ONE_N_PER_PORT - Redundant throttles per port
 *   ATTR_N_PLUS_ONE_MEM_POWER  - Redundant memory power
 *   ATTR_OVERSUB_N_PER_SLOT    - Oversubscription throttles per slot
 *   ATTR_OVERSUB_N_PER_PORT    - Oversubscription throttles per port
 *   ATTR_OVERSUB_MEM_POWER     - Oversubscription memory power
 */
errlHndl_t calcMemThrottles();


#undef TMGT_INF
#undef TMGT_ERR
#define TMGT_INF( _fmt_, _args_...)  TRACFCOMP(HTMGT::g_trac_htmgt_mem, _fmt_, ##_args_ )
#define TMGT_ERR( _fmt_, _args_...)  TRACFCOMP(HTMGT::g_trac_htmgt_mem, ERR_MRK _fmt_, ##_args_ )

namespace HTMGT
{
    trace_desc_t* g_trac_htmgt_mem = nullptr;
    uint8_t g_max_ports_per_ocmb = 0;

// Function: isOdysseyChip
//
// function to determine and return true if OCMB is an Odyssey Chip.
//
bool isOdysseyChip( TARGETING::Target * i_ocmb_target )
{
    static bool l_odyssey_config = false;
    static bool l_known_config = false;

    // if never determined if this system is an Explorer or Odyssey system
    if(l_known_config == false)
    {
        const uint32_t chipId = i_ocmb_target->getAttr<ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::ODYSSEY_16)
        {
            l_odyssey_config = true;
        }
        l_known_config = true;
    }

    return l_odyssey_config;
}

/**
 * Function: call_utils_to_throttle()
 *
 *  Call hardware procedure to determine memory throttles
 *  (number of commands, N) and the max power consumed at that
 *  throttle given the specified utilization (in %).
 *  If i_util is 0, the HWP will use the safe mode throttles.
 *
 *  There are 2 N throttle values that are used: N/port & N/slot
 *
 * @param[in] i_utilization - Minimum utilization value required (in %)
 */
errlHndl_t call_utils_to_throttle(std::vector <fapi2::Target<fapi2::
                                  TARGET_TYPE_OCMB_CHIP>> i_fapi_target_list,
                                  const uint32_t i_util)
{
    errlHndl_t err = nullptr;
    // Convert to 1/100 % units for the HWP
    uint32_t util_hundredth_percent = i_util * 100;

    // Loop through all OBMC chip targets and set inputs
    for(const auto & l_fapi_target : i_fapi_target_list)
    {
        // Query the functional PORTs for this OCMB
        TARGETING::Target * ocmb_target = l_fapi_target.get();
        TargetHandleList port_list;
        getChildAffinityTargets(port_list, ocmb_target,
                                CLASS_UNIT, TYPE_MEM_PORT);
        for(const auto & l_portTarget : port_list)
        {
            // Update HWP input attribute with target utilization
            if (!l_portTarget->trySetAttr<ATTR_EXP_DATABUS_UTIL>(util_hundredth_percent))
            {
                TMGT_ERR("call_utils_to_throttle: failed to set EXP_DATABUS_UTIL");
                /*@
                 * @errortype
                 * @subsys EPUB_FIRMWARE_SP
                 * @moduleid HTMGT_MOD_MEM_UTIL_TO_THROTTLE
                 * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
                 * @userdata1 ocmb HUID
                 * @userdata2 port HUID
                 * @devdesc Failed to set utilization for throttle procedures
                 * @custdesc An internal firmware error occurred
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              HTMGT_MOD_MEM_UTIL_TO_THROTTLE,
                                              HTMGT_RC_ATTRIBUTE_ERROR,
                                              get_huid(ocmb_target),
                                              get_huid(l_portTarget),
                                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
        } // for each port
        if (err) break;
    } // for each ocmb

    if (err == nullptr)
    {
        // p10_mss_utils_to_throttle() - Determines throttle power values for a
        //                               given port databus utilization
        //
        //         inputs:  target vector of OCMB_CHIPs to set throttle/power attributues on
        //                  ATTR_EXP_DATABUS_UTIL
        //                  ATTR_EXP_MEM_WATT_TARGET (set during istep 7 by call to eff_config_thermal)
        //
        //         outputs: ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT (worst case of all slots)
        //                  ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT
        //                  ATTR_EXP_PORT_MAXPOWER
        //
        //         returns: FAPI2_RC_SUCCESS on success
        TMGT_INF("call_utils_to_throttle: Calling HWP:p10_mss_utils_to_throttle()"
                 " with utilization of %d percent", i_util);
        FAPI_INVOKE_HWP(err, p10_mss_utils_to_throttle, i_fapi_target_list);
    }

    if (err)
    {
        TMGT_ERR("call_utils_to_throttle: HWP:p10_mss_utils_to_throttle failed"
                 " with rc=0x%04X", err->reasonCode());
        err->collectTrace(FAPI_TRACE_NAME);
        err->collectTrace(FAPI_IMP_TRACE_NAME);
        // HTMGT traces added later
    }

    return err;

} // end call_utils_to_throttle()



/**
 * Calculate throttles for over-temperture
 *
 * @param[in] i_fapi_target_list - list of FAPI OCMB targets
 * @param[in] i_efficiency - the regulator efficiency (percent)
 */
errlHndl_t memPowerThrottleOT(
       std::vector < fapi2::Target< fapi2::TARGET_TYPE_OCMB_CHIP>> i_fapi_target_list,
                                   const uint8_t i_efficiency)
{
    errlHndl_t err = nullptr;
    TMGT_INF("memPowerThrottleOT: Calculating safe mode/OT throttles");

    // Passing 0 for the utilization will calculate the
    //   safe mode / over-temperature throttles.
    err = call_utils_to_throttle(i_fapi_target_list, 0);
    if (nullptr == err)
    {
        uint32_t ot_mem_power = 0;
        for(const auto & ocmb_fapi_target : i_fapi_target_list)
        {
            bool attr_failure = false;
            uint32_t l_power[2] = {0};
            uint16_t l_slot[HTMGT_MAX_SLOT_PER_OCMB_PORT] = {0};

            // Get list of functional memory ports associated with this OCMB_CHIP
            TARGETING::Target * ocmb_target = ocmb_fapi_target.get();
            TargetHandleList port_list;
            getChildAffinityTargets(port_list, ocmb_target,
                                    CLASS_UNIT, TYPE_MEM_PORT);
            for(const auto & l_portTarget : port_list)
            {
                uint8_t l_port_unit = 0xFF;
                if (!l_portTarget->tryGetAttr<ATTR_CHIP_UNIT>(l_port_unit))
                {
                    TMGT_ERR("memPowerThrottleOT: failed to read CHIP_UNIT");
                    attr_failure = true;
                }
                if (l_port_unit >= g_max_ports_per_ocmb)
                {
                    TMGT_ERR("memPowerThrottleOT: Invalid CHIP_UNIT %d for MEM_PORT",
                             l_port_unit);
                    attr_failure = true;
                    l_port_unit = 0;
                }

                if(isOdysseyChip(ocmb_target))
                {
                    // Odyssey uses the TARGET_TYPE_OCMB_CHIP
                    // Read HWP outputs:
                    if (!ocmb_target->tryGetAttr<ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_SLOT>
                        (l_slot[l_port_unit]))
                    {
                        TMGT_ERR("memPowerThrottleOT: failed to read "
                                "ODY_MEM_THROTTLED_N_COMMANDS_PER_SLOT");
                        attr_failure = true;
                    }
                }
                else
                {
                    // Read HWP outputs:
                    if (!l_portTarget->tryGetAttr<ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT>
                        (l_slot[l_port_unit]))
                    {
                        TMGT_ERR("memPowerThrottleOT: failed to read "
                                "EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT");
                        attr_failure = true;
                    }
                }

                // NOTE: Both ODY/EXP HWP write EXP_PORT_MAXPOWER
                if (!l_portTarget->tryGetAttr<ATTR_EXP_PORT_MAXPOWER>
                    (l_power[l_port_unit]))
                {
                    TMGT_ERR("memPowerThrottleOT: failed to read EXP_PORT_MAXPOWER");
                    attr_failure = true;
                }

                if (attr_failure)
                {
                    /*@
                     * @errortype
                     * @subsys EPUB_FIRMWARE_SP
                     * @moduleid HTMGT_MOD_MEM_THROTTLE_OT
                     * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
                     * @userdata1 ocmb HUID
                     * @userdata2 port HUID
                     * @devdesc Failed to read util to throttle results
                     * @custdesc An internal firmware error occurred
                     */
                    err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                  HTMGT_MOD_MEM_THROTTLE_OT,
                                                  HTMGT_RC_ATTRIBUTE_ERROR,
                                                  get_huid(ocmb_target),
                                                  get_huid(l_portTarget),
                                                  ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    err->collectTrace(FAPI_TRACE_NAME);
                    err->collectTrace(FAPI_IMP_TRACE_NAME);
                    // HTMGT traces added later
                    break;
                }
                ot_mem_power += l_power[l_port_unit];
            } // for each port
            if (err) break;

            // Update memory table (config data to be sent to OCC)
            //   The data is stored in attributes under each OCMB chip target
            TARGETING::TargetHandleList proc_targets;
            // Get functional parent proc (to get OCC instance)
            getParentAffinityTargets(proc_targets, ocmb_target, CLASS_CHIP, TYPE_PROC);
            if (proc_targets.size() > 0)
            {
                ConstTargetHandle_t proc_target = proc_targets[0];
                assert(proc_target != nullptr);
                const uint8_t occ_instance =
                    proc_target->getAttr<TARGETING::ATTR_POSITION>();

                // OCMB instance/position comes from the parents OMI target
                uint8_t l_ocmb_pos = 0xFF;
                TARGETING::Target * omi_target = getImmediateParentByAffinity(ocmb_target);
                if (omi_target != nullptr)
                {
                    // get relative OCMB per processor
                    l_ocmb_pos = omi_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                }
                else
                {
                    TMGT_ERR("memPowerThrottleOT: Unable to find OCMB's parent for HUID 0x%08X",
                             get_huid(ocmb_target));
                    attr_failure = true;
                }

                TMGT_INF("memPowerThrottleOT: MIN: OCC%d/OCMB%d - "
                         "N/slot: %3d/%3d, maxPower: %4d/%4dcW",
                         occ_instance, l_ocmb_pos, l_slot[0], l_slot[1],
                         l_power[0], l_power[1]);

                // Update memory table attributes (to send to OCC)
                if (!ocmb_target->trySetAttr<ATTR_OT_MIN_N_PER_SLOT>(l_slot))
                {
                    TMGT_ERR("memPowerThrottleOT: Failed to set OT_MIN_N_PER_SLOT");
                    attr_failure = true;
                }
                if (!ocmb_target->trySetAttr<ATTR_OT_MEM_POWER>(l_power))
                {
                    TMGT_ERR("memPowerThrottleOT: Failed to set OT_MEM_POWER");
                    attr_failure = true;
                }
            }
            else
            {
                // Grab the name of the target
                TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
                fapi2::toString(ocmb_fapi_target, l_targName, sizeof(l_targName));
                TMGT_ERR("memPowerThrottleOT: Unable to determine parent chip for OCMB %s",
                         l_targName);
                attr_failure = true;
            }

            if (attr_failure)
            {
                /*@
                 * @errortype
                 * @subsys EPUB_FIRMWARE_SP
                 * @moduleid HTMGT_MOD_MEM_THROTTLE_OT
                 * @reasoncode HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL
                 * @userdata1 ocmb HUID
                 * @devdesc Failed to save util to throttle results
                 * @custdesc An internal firmware error occurred
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              HTMGT_MOD_MEM_THROTTLE_OT,
                                              HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL,
                                              get_huid(ocmb_target), 0,
                                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                err->collectTrace(FAPI_TRACE_NAME);
                err->collectTrace(FAPI_IMP_TRACE_NAME);
                // HTMGT traces added later
                break;
            }
        } // for each ocmb

        if (0 != i_efficiency)
        {
            // Upconvert from regulator loss
            ot_mem_power /= (i_efficiency / 100.0);
        }
        // Round up to nearest Watt
        TMGT_INF("memPowerThrottleOT: Total Minimum Memory"
                 " Power: %dcW (input)", ot_mem_power);
    }

    if (err)
    {
        TMGT_ERR("memPowerThrottleOT: Failed to calculate over-temp"
                 " memory throttles, rc=0x%04X", err->reasonCode());
    }

    return err;

} // end memPowerThrottleOT()


void updateDimmPowerUtil(Target *sys)
{
    size_t numPoints = 0;

    // Read the minimum utilization (and convert from c% to percent)
    const auto minUtil = sys->getAttr<ATTR_MSS_MRW_SAFEMODE_DRAM_DATABUS_UTIL>() / 100;

    ATTR_DIMM_POWER_UTIL_type utilPoints = {0};
    const uint8_t maxUtilPoints = sizeof(utilPoints);
    if ((maxUtilPoints >= 2) && (maxUtilPoints <= (sizeof(ATTR_DIMM_POWER_type)/4)))
    {
        // Determine the utilization points to calculate DIMM Power
        ATTR_DIMM_POWER_UTIL_INTERMEDIATE_POINTS_typeStdArr utilPointsIntermediate;
        if (!sys->tryGetAttr<ATTR_DIMM_POWER_UTIL_INTERMEDIATE_POINTS>(utilPointsIntermediate))
        {
            TMGT_ERR("updateDimmPowerUtil: Failed to read DIMM_POWER_UTIL_INTERMEDIATE_POINTS");
        }
        // First point is always the minimum utilization
        utilPoints[numPoints++] = minUtil;
        // Add any valid intermediate points
        uint8_t lastPoint = minUtil;
        for (const auto & utilValue : utilPointsIntermediate)
        {
            if (numPoints == maxUtilPoints-1)
            {
                // no more room for additional points
                TMGT_ERR("updateDimmPowerUtil: no room to add any more "
                         "DIMM_POWER_UTIL_INTERMEDIATE_POINTS (%d)", maxUtilPoints);
                break;
            }
            if ((utilValue > lastPoint) && (utilValue < 100))
            {
                utilPoints[numPoints++] = utilValue;
                lastPoint = utilValue;
            }
        }
        // Last point is the max utilization (100%)
        utilPoints[numPoints++] = 100;
    }
    else
    {
        TMGT_ERR("updateDimmPowerUtil: DIMM_POWER array size (%d) does not match DIMM_POWER_UTIL "
                 "array size (%d)", sizeof(ATTR_DIMM_POWER_type)/4, maxUtilPoints);
        /*@
         * @errortype
         * @subsys EPUB_FIRMWARE_SP
         * @moduleid HTMGT_MOD_UPDATE_DIMM_POWER_UTIL
         * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
         * @userdata1 size of DIMM_POWER_UTIL
         * @userdata2 size of DIMM_POWER
         * @devdesc DIMM Power calculation array sizes mismatch
         * @custdesc An internal firmware error occurred
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                 HTMGT_MOD_UPDATE_DIMM_POWER_UTIL,
                                                 HTMGT_RC_ATTRIBUTE_ERROR,
                                                 maxUtilPoints,
                                                 sizeof(ATTR_DIMM_POWER_type)/4,
                                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        err->collectTrace(HTMGT_COMP_NAME);
        errlCommit(err, HTMGT_COMP_ID);
    }

    // Save the final utilization points for HTMGT
    if (!sys->trySetAttr<ATTR_DIMM_POWER_UTIL>(utilPoints))
    {
        TMGT_ERR("updateDimmPowerUtil: Failed to write DIMM_POWER_UTIL array (%d points)",
                 numPoints);
        /*@
         * @errortype
         * @subsys EPUB_FIRMWARE_SP
         * @moduleid HTMGT_MOD_UPDATE_DIMM_POWER_UTIL
         * @reasoncode HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL
         * @userdata1 num points
         * @userdata2 minimum utilization point
         * @devdesc Software problem, Failed to DIMM power utilization points
         * @custdesc An internal firmware error occurred
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                 HTMGT_MOD_UPDATE_DIMM_POWER_UTIL,
                                                 HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL,
                                                 numPoints,
                                                 minUtil,
                                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        err->collectTrace(HTMGT_COMP_NAME);
        errlCommit(err, HTMGT_COMP_ID);
    }
} // end updateDimmPowerUtil()

// Calculate preheat power for a single OCMB
uint32_t calculatePreheatPower(fapi2::Target< fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmbFapiTarget,
                               bool detailedTrace)
{
    uint32_t ocmb_total_power = 0;
    uint32_t l_power[HTMGT_MAX_PORT_PER_OCMB_CHIP_ODYSSEY] = {0};

    // OCMB instance/position comes from the parents OMI target
    TARGETING::Target * ocmb_target = i_ocmbFapiTarget.get();
    uint8_t l_ocmb_pos = 0xFF;
    TARGETING::Target * omi_target = getImmediateParentByAffinity(ocmb_target);
    if (omi_target != nullptr)
    {
        // get relative OCMB per processor
        l_ocmb_pos = omi_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
    }
    else
    {
        TMGT_ERR("calculatePreheatPower: Unable to find OCMB's parent for HUID 0x%08X",
                 get_huid(ocmb_target));
        // Only used for tracing (so ignore error)
    }

    // Get list of functional memory ports associated with this OCMB_CHIP
    TargetHandleList port_list;
    getChildAffinityTargets(port_list, ocmb_target, CLASS_UNIT, TYPE_MEM_PORT);
    for(const auto & l_portTarget : port_list)
    {
        auto l_port_unit = l_portTarget->getAttr<ATTR_CHIP_UNIT>();
        if (l_port_unit >= g_max_ports_per_ocmb)
        {
            TMGT_ERR("calculatePreheatPower: Invalid CHIP_UNIT %d for MEM_PORT",
                     l_port_unit);
            // skip this port
            continue;
        }

        // Read HWP output:
        l_power[l_port_unit] = l_portTarget->getAttr<ATTR_EXP_PORT_MAXPOWER>();

        // Get list of functional DIMMs associated with this MEM_PORT
        TargetHandleList dimm_list;
        getChildAffinityTargets(dimm_list, l_portTarget, CLASS_LOGICAL_CARD, TYPE_DIMM);

        bool l_foundDimm = false;
        for(const auto & l_dimmTarget : dimm_list)
        {
            // Calculate preheat power for this DIMM
            auto l_preheat = l_dimmTarget->getAttr<ATTR_PREHEAT_PERCENT>();
            if (l_preheat > 10000)
            {
                TMGT_ERR("calculatePreheatPower: Invalid PREHEAT_PERCENT (%d) for DIMM", l_preheat);
                l_preheat = 10000;
            }

            // Calculate the preheat power (PREHEAT is in c% (0.01%))
            const uint32_t l_preheatPower = l_power[l_port_unit] * l_preheat/10000.0;
            l_power[l_port_unit] = l_preheatPower;
            if (detailedTrace)
            {
                TMGT_INF("memPowerPreheat:   OCMB%d/DIMM%d HUID: 0x%08X, " // DEBUG
                         "PREHEAT: %dc%%, power: %dcW (position:%d)",
                         l_ocmb_pos, l_port_unit, get_huid(l_dimmTarget), l_preheat,
                         l_power[l_port_unit], l_dimmTarget->getAttr<TARGETING::ATTR_POSITION>());
            }
            l_foundDimm = true;
        }
        if (!l_foundDimm)
        {
            TMGT_ERR("calculatePreheatPower: Failed to find a DIMM for OCMB port %d (%d DIMMs)",
                     l_port_unit, dimm_list.size());
        }

        // Add each DIMM's power for the OCMB
        ocmb_total_power += l_power[l_port_unit];
    } // for each port

    TMGT_INF("memPowerPreheat:   OCMB%d total preheat power: %4dcW (output)",
             l_ocmb_pos, ocmb_total_power);

    return ocmb_total_power;
}

/**
 * Calculate preheat power for all OCMBs and write data to DIMM_POWER attributes
 *
 * @param[in] sys - system target
 * @param[in] i_fapi_target_list - list of FAPI OCMB targets
 */
errlHndl_t memPowerPreheat(Target *sys,
                     std::vector < fapi2::Target< fapi2::TARGET_TYPE_OCMB_CHIP>> i_fapi_target_list)
{
    errlHndl_t err = nullptr;
    TMGT_INF("memPowerPreheat: Calculating preheat power");

    size_t ocmbCount = i_fapi_target_list.size();
    ATTR_DIMM_POWER_type dimmPower[ocmbCount] = {0};
    ATTR_DIMM_POWER_UTIL_typeStdArr utilPoints;
    if (!sys->tryGetAttr<ATTR_DIMM_POWER_UTIL>(utilPoints))
    {
        TMGT_ERR("memPowerPreheat: Failed to read DIMM_POWER_UTIL");
        // array should be empty, so it will end up writing 0s for power values
    }

    // Calculate power for each utilization point
    for (size_t point = 0; point < utilPoints.size(); ++point)
    {
        const uint8_t utilValue = utilPoints[point];
        if (utilValue > 0)
        {
            err = call_utils_to_throttle(i_fapi_target_list, utilValue);
            if (nullptr == err)
            {
                size_t ocmbIndex = 0;
                TMGT_INF("memPowerPreheat: Utilization %d%%", utilValue);
                for(const auto & ocmb_fapi_target : i_fapi_target_list)
                {
                    // Save total DIMM power to ATTR_DIMM_POWER on the OCMB
                    // (only trace DIMM details on first utilization point)
                    dimmPower[ocmbIndex][point] = calculatePreheatPower(ocmb_fapi_target,
                                                                        (point == 0));
                    ++ocmbIndex;
                } // for each ocmb
            }
            else
            {
                TMGT_ERR("memPowerPreheat: Failed to calculate power at %d c%% utilization "
                         "(rc=0x%04X)", utilValue, err->reasonCode());
                // HTMGT traces added to err later
                // Stop parsing any further utilizations (since power would even be higher)
                break;
            }
        }
        else
        {
            // Ignore remaining points (power values will be 0)
            break;
        }
    } // for each utilization point

    // Write final DIMM_POWER attributes to each OCMB target
    size_t ocmbIndex = 0;
    TMGT_INF("memPowerPreheat: Setting DIMM_POWER for %d OCMBs", i_fapi_target_list.size());
    for(const auto & ocmb_fapi_target : i_fapi_target_list)
    {
        TARGETING::Target * ocmb_target = ocmb_fapi_target.get();
        TMGT_INF("memPowerPreheat: Setting DIMM_POWER for OCMB[%d]", ocmbIndex);
        ocmb_target->setAttr<ATTR_DIMM_POWER>(dimmPower[ocmbIndex]);
        ++ocmbIndex;
    }

    return err;

} // end memPowerPreheat()


/**
 * Function: call_bulk_pwr_throttles()
 *
 *  Call hardware procedure to determine memory throttles
 *  (number of commands, N) and the max power consumed at that
 *  throttle given the specified power target (in cW).
 *
 * @param[in] i_fapi_target_list - list of FAPI OCMB targets
 * @param[in] i_watt_target - the power target for the OCMB (in cW)
 */
errlHndl_t call_bulk_pwr_throttles(
      std::vector < fapi2::Target< fapi2::TARGET_TYPE_OCMB_CHIP>> i_fapi_target_list,
                       const uint32_t i_watt_target)
{
    errlHndl_t err = nullptr;
    bool isOdyssey = false;

    // Loop through all OBMC chip targets and set inputs
    for(const auto & l_fapi_target : i_fapi_target_list)
    {
        // Update input attributes for specified targets
        uint32_t l_watt_targets[HTMGT_MAX_SLOT_PER_OCMB_PORT]
            = { i_watt_target, i_watt_target };

        // Query the functional PORTs for this OCMB
        TARGETING::Target * ocmb_target = l_fapi_target.get();
        TargetHandleList port_list;
        getChildAffinityTargets(port_list, ocmb_target,
                                CLASS_UNIT, TYPE_MEM_PORT);
        isOdyssey = isOdysseyChip(ocmb_target);
        // Loop through all Memory ports targets and set inputs
        for(const auto & l_portTarget : port_list)
        {
            // Update HWP input attribute with target power
            if (!l_portTarget->trySetAttr<ATTR_EXP_MEM_WATT_TARGET>(l_watt_targets))
            {
                TMGT_ERR("call_bulk_pwr_throttles: failed to set EXP_MEM_WATT_TARGET");
                /*@
                 * @errortype
                 * @subsys EPUB_FIRMWARE_SP
                 * @moduleid HTMGT_MOD_MEM_BULK_PWR_THROTTLE
                 * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
                 * @userdata1 ocmb HUID
                 * @userdata2 port HUID
                 * @devdesc Failed to set target power for throttle procedure
                 * @custdesc An internal firmware error occurred
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              HTMGT_MOD_MEM_BULK_PWR_THROTTLE,
                                              HTMGT_RC_ATTRIBUTE_ERROR,
                                              get_huid(ocmb_target),
                                              get_huid(l_portTarget),
                                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
        } // for each port
        if (err) break;
    } // for each ocmb

    if (err == nullptr)
    {
        // exp_bulk_pwr_throttles() - Determines the throttle levels based
        //                               off of the port's power curve
        // inputs:  ATTR_EXP_MEM_WATT_TARGET
        // outputs: ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
        //          ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT, and
        //                    (equalizes the throttles to the lowest of runtime and
        //                    lowest slot-throttle value)
        //          ATTR_EXP_PORT_MAXPOWER
        //
        //         returns: FAPI2_RC_SUCCESS on success
        if (isOdyssey)
        {
            TMGT_INF("call_bulk_pwr_throttles: Calling HWP:ody_bulk_pwr_"
                     "throttles(POWER) with target of %dcW", i_watt_target);
            FAPI_INVOKE_HWP(err, ody_bulk_pwr_throttles, i_fapi_target_list,
                            mss::throttle_type::POWER);
        }
        else
        {
            TMGT_INF("call_bulk_pwr_throttles: Calling HWP:exp_bulk_pwr_"
                     "throttles(POWER) with target of %dcW", i_watt_target);
            FAPI_INVOKE_HWP(err, exp_bulk_pwr_throttles, i_fapi_target_list,
                            mss::throttle_type::POWER);
        }
    }

    if (err)
    {
        TMGT_ERR("call_bulk_pwr_throttles: exp_bulk_pwr_throttles "
                 "failed with rc=0x%04X", err->reasonCode());
        err->collectTrace(FAPI_TRACE_NAME);
        err->collectTrace(FAPI_IMP_TRACE_NAME);
        // HTMGT traces added later
    }

    return err;

} // end call_bulk_pwr_throttles()


/**
 * Function: init_bulk_power_limits()
 *
 *  Main function to initialize the power limit cap for N and N+1.
 *
 */
void init_bulk_power_limits(void)
{
    Target* sys = UTIL::assertGetToplevelTarget();

    auto Index_Config = sys->getAttrAsStdArr<ATTR_INDEX_POWER_LIMIT_CONFIG>();
    auto N_Power = sys->getAttrAsStdArr<ATTR_INDEX_N_BULK_POWER_LIMIT_WATTS>();
    auto Nplus_Power = sys->getAttrAsStdArr<ATTR_INDEX_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS>();
    auto MinPowerCap = sys->getAttrAsStdArr<ATTR_INDEX_MIN_POWER_CAP_WATTS>();

    bool useSingleEntryBulkPower = true;
    if (Index_Config[0] != 0)
    {
        // Continue Read and Search for the Power Config.

        // READ PS Config index.
        uint32_t MyConfig = 0;
        // INDEX: Byte 0,1:CCIN   Not_Used(0000), CCIN, Any(FFFF)
        //        Byte 1  :Type   Not_Used(00), 110(01),  220(02)
        //        Byte 2  :#_PS   Not_Used(00), Number of PS should be installed.
        sys->tryGetAttr<ATTR_INDEX_BULK_POWER>(MyConfig);
        if (MyConfig != 0xFFFF0000)
        {
            // Search through table of Power Limits for this Config Signature.
            uint16_t Index_Loop = 0;
            for(Index_Loop = 0; Index_Loop < Index_Config.size() ; Index_Loop++)
            {
                // If match on PS config, and N / N+1 bulk power limits != 0
                if ((Index_Config[Index_Loop] == MyConfig) &&
                    (N_Power[Index_Loop]      != 0) &&
                    (Nplus_Power[Index_Loop]  != 0) &&
                    (MinPowerCap[Index_Loop]  != 0))
                {
                    useSingleEntryBulkPower = false;

                    // Set the run time version of Bulk Power for both N and N+1.
                    if ((!sys->trySetAttr<ATTR_CURRENT_N_BULK_POWER_LIMIT_WATTS>
                                            (N_Power[Index_Loop])) ||
                        (!sys->trySetAttr<ATTR_CURRENT_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS>
                                        (Nplus_Power[Index_Loop])) ||
                        (!sys->trySetAttr<ATTR_CURRENT_MIN_POWER_CAP_WATTS>
                                        (MinPowerCap[Index_Loop])))
                    {
                        TMGT_ERR("init_bulk_power_limits: FAILED write of Config based power "
                                "limits -ATTR_CURRENT_N_BULK_POWER_LIMIT_WATTS(0x%08X) "
                                "-ATTR_CURRENT_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS(0x%08X) "
                                "-ATTR_CURRENT_MIN_POWER_CAP_WATTS(0x%08X) ",
                                    N_Power[Index_Loop], Nplus_Power[Index_Loop],
                                    MinPowerCap[Index_Loop]);

                        useSingleEntryBulkPower = true;

                        /*@
                        * @errortype
                        * @subsys EPUB_FIRMWARE_SP
                        * @moduleid HTMGT_MOD_PS_CONFIG_POWER_LIMIT
                        * @reasoncode HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL
                        * @userdata1 PS Config Searching for match.
                        * @userdata2 index trying to write.
                        * @devdesc Software problem, Failed to write bulk power limit attributes
                        * @custdesc An internal firmware error occurred
                        */
                        errlHndl_t err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                    HTMGT_MOD_PS_CONFIG_POWER_LIMIT,
                                                    HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL,
                                                    MyConfig,
                                                    Index_Loop,
                                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                        err->collectTrace(HTMGT_COMP_NAME);
                        errlCommit(err, HTMGT_COMP_ID);
                    }
                    else
                    {
                        TMGT_INF("init_bulk_power_limits: Found Bulk Power PS Config "
                                "0x%08X at index(%d)", MyConfig, Index_Loop);
                    }
                    break; // Stop on first found, Config should not have duplicates.
                }
                // else found config but one or more data fields are missing.
                else if (Index_Config[Index_Loop] == MyConfig)
                {
                    TMGT_ERR("init_bulk_power_limits: FAILED MRW check for config(0x%08X) "
                            "-ATTR_CURRENT_N_BULK_POWER_LIMIT_WATTS(0x%08X) "
                            "-ATTR_CURRENT_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS(0x%08X) "
                            "-ATTR_CURRENT_MIN_POWER_CAP_WATTS(0x%08X) ", MyConfig,
                                N_Power[Index_Loop], Nplus_Power[Index_Loop],
                                MinPowerCap[Index_Loop]);
                }
            }
            // if we hit the end of loop, and not found config post error log.
            if (Index_Loop == Index_Config.size())
            {
                TMGT_ERR("init_bulk_power_limits: Failed to find power config 0x%08X in MRW",
                         MyConfig);
                /*@
                * @errortype
                * @subsys EPUB_FIRMWARE_SP
                * @moduleid HTMGT_MOD_PS_CONFIG_POWER_LIMIT
                * @reasoncode HTMGT_RC_MISSING_DATA
                * @userdata1 Power Limits failed to find power config in MRW table.
                * @userdata2 0
                * @devdesc Power Limits failed to find power config in MRW table.
                * @custdesc Confirm power supply configuration.
                */
                errlHndl_t err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                         HTMGT_MOD_PS_CONFIG_POWER_LIMIT,
                                                         HTMGT_RC_MISSING_DATA,
                                                         MyConfig,
                                                         0,
                                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                err->collectTrace(HTMGT_COMP_NAME);

                // add Index Power Supplly config to FFDC.
                err->addFFDC(HTMGT_COMP_ID,
                             reinterpret_cast<void const*>(&Index_Config),
                             Index_Config.size() * 4, //entries are 4 bytes.
                             1,     //version
                             0);

                errlCommit(err, HTMGT_COMP_ID);
            }
        }
    }

    // If we can not use the PS Config Bulk power Limits, then use original set limits.
    if (useSingleEntryBulkPower == true)
    {
        //Get the max redundant (N) power allocated to memory
        uint32_t power1 = 0;
        power1 = sys->getAttr<ATTR_N_BULK_POWER_LIMIT_WATTS>();

        uint32_t power2 = 0;
        power2 = sys->getAttr<ATTR_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS>();

        uint32_t powerMinCap = 0;
        powerMinCap = sys->getAttr<ATTR_MIN_POWER_CAP_WATTS>();

        // Set the run time version of Bulk Power for both N and N+1.
        if ((!sys->trySetAttr<ATTR_CURRENT_N_BULK_POWER_LIMIT_WATTS>(power1)) ||
            (!sys->trySetAttr<ATTR_CURRENT_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS>(power2)) ||
            (!sys->trySetAttr<ATTR_CURRENT_MIN_POWER_CAP_WATTS>(powerMinCap)))
        {
            TMGT_ERR("init_bulk_power_limits: FAILED write of Original power limits "
                    "-ATTR_CURRENT_N_BULK_POWER_LIMIT_WATTS(0x%08X) "
                    "-ATTR_CURRENT_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS(0x%08X) "
                    "-ATTR_CURRENT_MIN_POWER_CAP_WATTS(0x%08X) ",
                        power1, power2, powerMinCap);

            /*@
            * @errortype
            * @subsys EPUB_FIRMWARE_SP
            * @moduleid HTMGT_MOD_MRW_POWER_LIMIT
            * @reasoncode HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL
            * @userdata1[00:31] N Bulk power limit
            * @userdata1[32:63] N+1 Bulk power limit
            * @userdata2[00:31] Min power cap
            * @userdata2[32:63] Reserved
            * @devdesc Software problem, Failed to write bulk power limit attributes
            * @custdesc An internal firmware error occurred
            */
            errlHndl_t err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        HTMGT_MOD_MRW_POWER_LIMIT,
                                        HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL,
                                        TWO_UINT32_TO_UINT64(power1, power2),
                                        TWO_UINT32_TO_UINT64(powerMinCap, 0x0),
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            err->collectTrace(HTMGT_COMP_NAME);
            errlCommit(err, HTMGT_COMP_ID);
        }
    }

    TMGT_INF("init_bulk_power_limits: bulk power limits N(%dW)  and  N+1(%dW) "
                    "and Min power cap(%dW)",
                    sys->getAttr<ATTR_CURRENT_N_BULK_POWER_LIMIT_WATTS>(),
                    sys->getAttr<ATTR_CURRENT_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS>(),
                    sys->getAttr<ATTR_CURRENT_MIN_POWER_CAP_WATTS>());

}

/**
 * Calculate throttles for when system has redundant power (N+1 mode)
 *
 * @param[in] i_fapi_target_list - list of FAPI OCMB targets
 * @param[in] i_efficiency - the regulator efficiency (percent)
 */
errlHndl_t memPowerThrottleRedPower(
         std::vector <fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>> i_fapi_target_list,
                              const uint8_t i_efficiency,
                              const size_t i_numDimms)
{
    errlHndl_t err = nullptr;
    Target* sys = UTIL::assertGetToplevelTarget();
    uint32_t power = 0;
    uint32_t wattTarget = 0;

    init_bulk_power_limits();

    //Get OCMB chip id to see if explorer or odyssey should be used.
    TARGETING::Target * ocmb_target = i_fapi_target_list[0].get();
    const uint32_t chipId = ocmb_target->getAttr<ATTR_CHIP_ID>();
    //Get the max redundant (N+1) power allocated to memory
    if (chipId == POWER_CHIPID::EXPLORER_16)//DDR4
    {
        power = sys->getAttr<ATTR_N_PLUS_ONE_MAX_MEM_POWER_WATTS>();
    }
    else//DDR5
    {
        power = sys->getAttr<ATTR_DDR5_N_PLUS_ONE_MAX_MEM_POWER_WATTS>();
    }
    TMGT_INF("memPowerThrottleRedPower: N_PLUS_ONE_MAX_MEM_POWER_WATTS: %dW", power);
    power *= 100; // convert to centiWatts

    //Account for the regulator efficiency (percentage), if supplied
    if (i_efficiency != 0)
    {
        power *= (i_efficiency / 100.0);
    }

    //Find the Watt target for each present DIMM
    if (i_numDimms)
    {
        wattTarget = power / i_numDimms;
    }
    TMGT_INF("memPowerThrottleRedPower: N+1 max mem power: %dW (%d present DIMMs) -> "
             "%dcW per DIMM", power/100, i_numDimms, wattTarget);

    //Calculate the throttles
    err = call_bulk_pwr_throttles(i_fapi_target_list, wattTarget);
    if (nullptr == err)
    {
        uint32_t tot_mem_power_cw = 0;
        for(auto & ocmb_fapi_target : i_fapi_target_list)
        {
            bool attr_failure = false;
            uint32_t l_power[2] = {0};
            uint16_t l_slot[HTMGT_MAX_SLOT_PER_OCMB_PORT] = {0};
            uint16_t l_port[HTMGT_MAX_SLOT_PER_OCMB_PORT] = {0};

            // Get list of functional memory ports associated with this OCMB_CHIP
            TARGETING::Target * ocmb_target = ocmb_fapi_target.get();
            TargetHandleList port_list;
            getChildAffinityTargets(port_list, ocmb_target,
                                    CLASS_UNIT, TYPE_MEM_PORT);
            for (const auto & l_portTarget : port_list)
            {
                uint8_t l_port_unit = 0xFF;
                if (!l_portTarget->tryGetAttr<ATTR_CHIP_UNIT>(l_port_unit))
                {
                    TMGT_ERR("memPowerThrottleRedPower: failed to read CHIP_UNIT");
                    attr_failure = true;
                }
                if (l_port_unit >= g_max_ports_per_ocmb)
                {
                    TMGT_ERR("memPowerThrottleRedPower: Invalid CHIP_UNIT "
                             "%d for MEM_PORT", l_port_unit);
                    attr_failure = true;
                    l_port_unit = 0;
                }

                if(isOdysseyChip(ocmb_target))
                {
                    // Read HWP outputs:
                    // Odyssey uses the TARGET_TYPE_OCMB_CHIP
                    if (!ocmb_target->tryGetAttr<ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_SLOT>
                        (l_slot[l_port_unit]))
                    {
                        TMGT_ERR("memPowerThrottleRedPower: failed to read "
                                "ODY_MEM_THROTTLED_N_COMMANDS_PER_SLOT");
                        attr_failure = true;
                    }
                    if (!ocmb_target->tryGetAttr<ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_PORT>
                        (l_port[l_port_unit]))
                    {
                        TMGT_ERR("memPowerThrottleRedPower: failed to read "
                                "ODY_MEM_THROTTLED_N_COMMANDS_PER_PORT");
                        attr_failure = true;
                    }
                }
                else
                {
                    // Read HWP outputs:
                    if (!l_portTarget->tryGetAttr<ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT>
                        (l_slot[l_port_unit]))
                    {
                        TMGT_ERR("memPowerThrottleRedPower: failed to read "
                                "EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT");
                        attr_failure = true;
                    }
                    if (!l_portTarget->tryGetAttr<ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT>
                        (l_port[l_port_unit]))
                    {
                        TMGT_ERR("memPowerThrottleRedPower: failed to read "
                                "EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT");
                        attr_failure = true;
                    }
                }
                if (!l_portTarget->tryGetAttr<ATTR_EXP_PORT_MAXPOWER>
                    (l_power[l_port_unit]))
                {
                    TMGT_ERR("memPowerThrottleRedPower: failed to read EXP_PORT_MAXPOWER");
                    attr_failure = true;
                }

                if (attr_failure)
                {
                    /*@
                     * @errortype
                     * @subsys EPUB_FIRMWARE_SP
                     * @moduleid HTMGT_MOD_MEM_THROTTLE_REDUN
                     * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
                     * @userdata1 ocmb HUID
                     * @userdata2 port HUID
                     * @devdesc Failed to read throttle procedure results
                     * @custdesc An internal firmware error occurred
                     */
                    err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                  HTMGT_MOD_MEM_THROTTLE_REDUN,
                                                  HTMGT_RC_ATTRIBUTE_ERROR,
                                                  get_huid(ocmb_target),
                                                  get_huid(l_portTarget),
                                                  ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    err->collectTrace(FAPI_TRACE_NAME);
                    err->collectTrace(FAPI_IMP_TRACE_NAME);
                    // HTMGT traces added later
                    break;
                }
            } // for each port
            if (err) break;

            // Calculate memory power at min throttles
            tot_mem_power_cw += l_power[0] + l_power[1];

            // Update memory table (config data to be sent to OCC)
            //   The data is stored in attributes under each OCMB chip target
            TARGETING::TargetHandleList proc_targets;
            // Get functional parent proc (to get OCC instance)
            getParentAffinityTargets(proc_targets, ocmb_target, CLASS_CHIP, TYPE_PROC);
            if (proc_targets.size() > 0)
            {
                ConstTargetHandle_t proc_target = proc_targets[0];
                assert(proc_target != nullptr);
                const uint8_t occ_instance =
                    proc_target->getAttr<TARGETING::ATTR_POSITION>();

                // OCMB instance/position comes from the parents OMI target
                uint8_t l_ocmb_pos = 0xFF;
                TARGETING::Target * omi_target = getImmediateParentByAffinity(ocmb_target);
                if (omi_target != nullptr)
                {
                    // get relative OCMB per processor
                    l_ocmb_pos = omi_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                }
                else
                {
                    TMGT_ERR("memPowerThrottleRedPower: Unable to find OCMB's "
                             "parent for HUID 0x%08X", get_huid(ocmb_target));
                    attr_failure = true;
                }

                TMGT_INF("memPowerThrottleRedPower: OCC%d/OCMB%d - "
                         "N/slot: %3d/%3d, N/port: %3d/%3d, Power: %4d/%4dcW",
                         occ_instance, l_ocmb_pos, l_slot[0], l_slot[1],
                         l_port[0], l_port[1], l_power[0], l_power[1]);

                // Update memory table attributes (to send to OCC)
                if (!ocmb_target->trySetAttr<ATTR_N_PLUS_ONE_N_PER_SLOT>(l_slot))
                {
                    TMGT_ERR("memPowerThrottleRedPower: Failed to set "
                             "N_PLUS_ONE_N_PER_SLOT");
                    attr_failure = true;
                }
                if (!ocmb_target->trySetAttr<ATTR_N_PLUS_ONE_N_PER_PORT>(l_port))
                {
                    TMGT_ERR("memPowerThrottleRedPower: Failed to set "
                             "N_PLUS_ONE_N_PER_PORT");
                    attr_failure = true;
                }
                if (!ocmb_target->trySetAttr<ATTR_N_PLUS_ONE_MEM_POWER>(l_power))
                {
                    TMGT_ERR("memPowerThrottleRedPower: Failed to set "
                             "N_PLUS_ONE_MEM_POWER");
                    attr_failure = true;
                }
            }
            else
            {
                // Grab the name of the target
                TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
                fapi2::toString(ocmb_fapi_target, l_targName, sizeof(l_targName));
                TMGT_ERR("memPowerThrottleRedPower: Unable to determine "
                         "parent chip for OCMB %s", l_targName);
                attr_failure = true;
            }

            if (attr_failure)
            {
                /*@
                 * @errortype
                 * @subsys EPUB_FIRMWARE_SP
                 * @moduleid HTMGT_MOD_MEM_THROTTLE_REDUN
                 * @reasoncode HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL
                 * @userdata1 ocmb HUID
                 * @devdesc Failed to save throttle procedure results
                 * @custdesc An internal firmware error occurred
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              HTMGT_MOD_MEM_THROTTLE_REDUN,
                                              HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL,
                                              get_huid(ocmb_target), 0,
                                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                err->collectTrace(FAPI_TRACE_NAME);
                err->collectTrace(FAPI_IMP_TRACE_NAME);
                // HTMGT traces added later
                break;
            }
        } // for each ocmb

        if (0 != i_efficiency)
        {
            // Upconvert from regulator loss
            tot_mem_power_cw /= (i_efficiency / 100.0);
        }
        TMGT_INF("memPowerThrottleRedPower: Total Redundant Memory Power: %dcW (input)",
                 tot_mem_power_cw);

        // Take memory power at min throttles and push to runtime.
        Target* sys = UTIL::assertGetToplevelTarget();
        if (!sys->trySetAttr<ATTR_CURRENT_MEM_POWER_MIN_THROTTLE>(tot_mem_power_cw/100))
        {
            TMGT_ERR("memPowerThrottleRedPower: Failed to set MEM_POWER_PER_SYSTEM");
        }
    }

    if (err)
    {
        TMGT_ERR("memPowerThrottleRedPower: Failed to calculate redundant "
                 "power memory throttles, rc=0x%04X",
                 err->reasonCode());
    }

    return err;

} // end memPowerThrottleRedPower()


/**
 * Calculate throttles for when system is oversubscribed (N mode)
 *
 * @param[in] i_fapi_target_list - list of FAPI OCMB targets
 * @param[in] i_efficiency - the regulator efficiency (percent)
 */
errlHndl_t memPowerThrottleOversub(
         std::vector <fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>> i_fapi_target_list,
                              const uint8_t i_efficiency,
                              const size_t i_numDimms)
{
    errlHndl_t err = nullptr;
    Target* sys = UTIL::assertGetToplevelTarget();
    uint32_t power = 0;
    uint32_t wattTarget = 0;

    //Get OCMB chip id to see if explorer or odyssey should be used.
    TARGETING::Target * ocmb_target = i_fapi_target_list[0].get();
    const uint32_t chipId = ocmb_target->getAttr<ATTR_CHIP_ID>();
    //Get the max oversubscribed (N) power allocated to memory
    if (chipId == POWER_CHIPID::EXPLORER_16)//DDR4
    {
        power = sys->getAttr<ATTR_N_MAX_MEM_POWER_WATTS>();
    }
    else//DDR5
    {
        power = sys->getAttr<ATTR_DDR5_N_MAX_MEM_POWER_WATTS>();
    }
    TMGT_INF("memPowerThrottleOversub: N_MAX_MEM_POWER_WATTS: %dW", power);
    power *= 100; // convert to centiWatts

    //Account for the regulator efficiency (percentage), if supplied
    if (i_efficiency != 0)
    {
        power *= (i_efficiency / 100.0);
    }

    //Find the Watt target for each present DIMM
    if (i_numDimms)
    {
        wattTarget = power / i_numDimms;
    }
    TMGT_INF("memPowerThrottleOversub: N power: %dW (%d present DIMMs) -> "
             "%dcW per DIMM", power/100, i_numDimms, wattTarget);

    //Calculate the throttles
    err = call_bulk_pwr_throttles(i_fapi_target_list, wattTarget);
    if (nullptr == err)
    {
        uint32_t tot_mem_power_cw = 0;
        for(auto & ocmb_fapi_target : i_fapi_target_list)
        {
            bool attr_failure = false;
            // Read HWP output parms:
            uint32_t l_power[2] = {0};
            uint16_t l_slot[HTMGT_MAX_SLOT_PER_OCMB_PORT] = {0};
            uint16_t l_port[HTMGT_MAX_SLOT_PER_OCMB_PORT] = {0};

            // Get list of functional memory ports associated with this OCMB_CHIP
            TARGETING::Target * ocmb_target = ocmb_fapi_target.get();
            TargetHandleList port_list;
            getChildAffinityTargets(port_list, ocmb_target,
                                    CLASS_UNIT, TYPE_MEM_PORT);
            for (const auto & l_portTarget : port_list)
            {
                uint8_t l_port_unit;
                if (!l_portTarget->tryGetAttr<ATTR_CHIP_UNIT>(l_port_unit))
                {
                    TMGT_ERR("memPowerThrottleOversub: failed to read CHIP_UNIT");
                    attr_failure = true;
                }
                if (l_port_unit >= g_max_ports_per_ocmb)
                {
                    TMGT_ERR("memPowerThrottleOversub: Invalid CHIP_UNIT "
                             "%d for MEM_PORT", l_port_unit);
                    attr_failure = true;
                    l_port_unit = 0;
                }

                if(isOdysseyChip(ocmb_target))
                {
                    // Odyssey uses the TARGET_TYPE_OCMB_CHIP
                    if (!ocmb_target->tryGetAttr<ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_SLOT>
                        (l_slot[l_port_unit]))
                    {
                        TMGT_ERR("memPowerThrottleOversub: failed to read "
                                "ODY_MEM_THROTTLED_N_COMMANDS_PER_SLOT");
                        attr_failure = true;
                    }
                    if (!ocmb_target->tryGetAttr<ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_PORT>
                        (l_port[l_port_unit]))
                    {
                        TMGT_ERR("memPowerThrottleOversub: failed to read "
                                "ODY_MEM_THROTTLED_N_COMMANDS_PER_PORT");
                        attr_failure = true;
                    }
                }
                else
                {
                    if (!l_portTarget->tryGetAttr<ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT>
                        (l_slot[l_port_unit]))
                    {
                        TMGT_ERR("memPowerThrottleOversub: failed to read "
                                "EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT");
                        attr_failure = true;
                    }
                    if (!l_portTarget->tryGetAttr<ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT>
                        (l_port[l_port_unit]))
                    {
                        TMGT_ERR("memPowerThrottleOversub: failed to read "
                                "EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT");
                        attr_failure = true;
                    }

                }
                if (!l_portTarget->tryGetAttr<ATTR_EXP_PORT_MAXPOWER>
                    (l_power[l_port_unit]))
                {
                    TMGT_ERR("memPowerThrottleOversub: failed to read EXP_PORT_MAXPOWER");
                    attr_failure = true;
                }

                if (attr_failure)
                {
                    /*@
                     * @errortype
                     * @subsys EPUB_FIRMWARE_SP
                     * @moduleid HTMGT_MOD_MEM_THROTTLE_OVERSUB
                     * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
                     * @userdata1 ocmb HUID
                     * @userdata2 port HUID
                     * @devdesc Failed to read throttle procedure results
                     * @custdesc An internal firmware error occurred
                     */
                    err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                  HTMGT_MOD_MEM_THROTTLE_OVERSUB,
                                                  HTMGT_RC_ATTRIBUTE_ERROR,
                                                  get_huid(ocmb_target),
                                                  get_huid(l_portTarget),
                                                  ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    err->collectTrace(FAPI_TRACE_NAME);
                    err->collectTrace(FAPI_IMP_TRACE_NAME);
                    // HTMGT traces added later
                    break;
                }
            } // for each port
            if (err) break;

            // Calculate memory power at min throttles
            tot_mem_power_cw += l_power[0] + l_power[1];

            // Update OCMB data (to be sent to OCC)
            // Get functional parent processor
            TARGETING::TargetHandleList proc_targets;
            getParentAffinityTargets (proc_targets, ocmb_target, CLASS_CHIP, TYPE_PROC);
            if (proc_targets.size() > 0)
            {
                ConstTargetHandle_t proc_target = proc_targets[0];
                assert(proc_target != nullptr);
                const uint8_t occ_instance =
                    proc_target->getAttr<TARGETING::ATTR_POSITION>();

                // OCMB instance comes from the parents OMI target
                uint8_t l_ocmb_pos = 0xFF;
                TARGETING::Target * omi_target =
                    getImmediateParentByAffinity(ocmb_target);
                if (omi_target != nullptr)
                {
                    // get relative OCMB per processor
                    l_ocmb_pos = omi_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                }
                else
                {
                    TMGT_ERR("memPowerThrottleOversub: Unable to find OCMB's "
                             "parent for HUID 0x%08X", get_huid(ocmb_target));
                    attr_failure = true;
                }

                TMGT_INF("memPowerThrottleOversub: OCC%d/OCMB%d - "
                         "N/slot: %3d/%3d, N/port: %3d/%3d, Power: %4d/%4dcW",
                         occ_instance, l_ocmb_pos, l_slot[0], l_slot[1],
                         l_port[0], l_port[1], l_power[0], l_power[1]);

                if (!ocmb_target->trySetAttr<ATTR_OVERSUB_N_PER_SLOT>(l_slot))
                {
                    TMGT_ERR("memPowerThrottleOversub: Failed to set "
                             "OVERSUB_N_PER_SLOT");
                    attr_failure = true;
                }
                if (!ocmb_target->trySetAttr<ATTR_OVERSUB_N_PER_PORT>(l_port))
                {
                    TMGT_ERR("memPowerThrottleOversub: Failed to set "
                             "OVERSUB_N_PER_PORT");
                    attr_failure = true;
                }
                if (!ocmb_target->trySetAttr<ATTR_OVERSUB_MEM_POWER>(l_power))
                {
                    TMGT_ERR("memPowerThrottleOversub: Failed to set "
                             "OVERSUB_MEM_POWER");
                    attr_failure = true;
                }
            }
            else
            {
                // Grab the name of the target
                TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
                fapi2::toString(ocmb_fapi_target, l_targName, sizeof(l_targName));
                TMGT_ERR("memPowerThrottleOversub: Unable to determine "
                         "parent chip for OCMB %s", l_targName);
                attr_failure = true;
            }

            if (attr_failure)
            {
                /*@
                 * @errortype
                 * @subsys EPUB_FIRMWARE_SP
                 * @moduleid HTMGT_MOD_MEM_THROTTLE_OVERSUB
                 * @reasoncode HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL
                 * @userdata1 ocmb HUID
                 * @devdesc Failed to save throttle procedure results
                 * @custdesc An internal firmware error occurred
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              HTMGT_MOD_MEM_THROTTLE_OVERSUB,
                                              HTMGT_RC_SAVE_TO_ATTRIBUTE_FAIL,
                                              get_huid(ocmb_target), 0,
                                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                err->collectTrace(FAPI_TRACE_NAME);
                err->collectTrace(FAPI_IMP_TRACE_NAME);
                // HTMGT traces added later
                break;
            }
        } // for each ocmb

        if (0 != i_efficiency)
        {
            // Upconvert from regulator loss
            tot_mem_power_cw /= (i_efficiency / 100.0);
        }
        TMGT_INF("memPowerThrottleOversub: Total Oversubscription Memory Power: %dcW (input)",
                 tot_mem_power_cw);
    }

    if (err)
    {
        TMGT_ERR("memPowerThrottleOversub: Failed to calculate oversubscription "
                 "memory throttles, rc=0x%04X", err->reasonCode());
    }

    return err;

} // end memPowerThrottleOversub()


// Function: calcMemThrottles
//
// Main function to intiate the memory throttle calculation
//
errlHndl_t calcMemThrottles()
{
    errlHndl_t err = nullptr;
    Target* sys = UTIL::assertGetToplevelTarget();
    unsigned int ocmb_count = 0;

    // Trace definition
    if (g_trac_htmgt_mem == nullptr)
    {
        TRAC_INIT(&g_trac_htmgt_mem, HTMGT_COMP_NAME, 4*KILOBYTE);
    }
    TMGT_INF(">>calcMemThrottles");

    const uint8_t efficiency = sys->getAttr<ATTR_REGULATOR_EFFICIENCY_FACTOR>();
    TMGT_INF("calcMemThrottles: efficiency=%d percent", efficiency);

    // Update DIMM Power Utilization points to use for preheat power calculation
    updateDimmPowerUtil(sys);

    // Create a FAPI Target list of all OCMB chips for all processors
    std::vector < fapi2::Target
        < fapi2::TARGET_TYPE_OCMB_CHIP>> l_full_fapi_target_list;

    // Get all functional processor chips
    TARGETING::TargetHandleList proc_list;
    getAllChips(proc_list, TARGETING::TYPE_PROC, true);
    errlHndl_t preheatErr = nullptr;
    for(const auto & proc_target : proc_list)
    {
        uint32_t proc_huid = get_huid(proc_target);
        ATTR_POSITION_type proc_unit = proc_target->getAttr
            <TARGETING::ATTR_POSITION>();

        // Create a FAPI Target list of OCMB chips for this processor
        std::vector < fapi2::Target
            < fapi2::TARGET_TYPE_OCMB_CHIP>> l_fapi_targets_this_proc;

        // Get functional OCMBs associated with this processor
        TargetHandleList ocmb_list;
        getChildAffinityTargets(ocmb_list, proc_target, CLASS_CHIP, TYPE_OCMB_CHIP);
        TMGT_INF("calcMemThrottles: PROC%d HUID:0x%08X / %d functional OCMB_CHIPs",
                 proc_unit, proc_huid, ocmb_list.size());
        for(const auto & ocmb_target : ocmb_list)
        {
            uint32_t ocmb_huid = get_huid(ocmb_target);
            // Determine OCMB instance (from the parents OMI target)
            uint8_t l_ocmb_pos = 0xFF;
            TARGETING::Target * omi_target = getImmediateParentByAffinity(ocmb_target);
            if (omi_target != nullptr)
            {
                // get relative OCMB per processor
                l_ocmb_pos = omi_target->getAttr<ATTR_CHIP_UNIT>();
            }
            else
            {
                TMGT_ERR("calcMemThrottles: Unable to find OCMB's parent for HUID 0x%08X",
                         ocmb_huid);
            }

            if (g_max_ports_per_ocmb == 0)
            {
                // Determine max number of ports
                const uint32_t chipId = ocmb_target->getAttr<ATTR_CHIP_ID>();
                g_max_ports_per_ocmb = HTMGT_MAX_PORT_PER_OCMB_CHIP;
                if (chipId != POWER_CHIPID::EXPLORER_16)
                {
                    g_max_ports_per_ocmb = HTMGT_MAX_PORT_PER_OCMB_CHIP_ODYSSEY;
                }
            }

            // Convert to FAPI target and add to list
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapiTarget(ocmb_target);
            l_fapi_targets_this_proc.push_back(l_fapiTarget);

            // Query the functional PORTs for this OCMB (for trace)
            TARGETING::TargetHandleList port_list;
            getChildAffinityTargetsByState(port_list, ocmb_target, CLASS_UNIT,
                                           TYPE_MEM_PORT, UTIL_FILTER_FUNCTIONAL);
            // Read the name of the target (for trace)
            TARGETING::ATTR_FAPI_NAME_type l_ocmbName = {0};
            fapi2::toString(l_fapiTarget, l_ocmbName, sizeof(l_ocmbName));
            TMGT_INF("calcMemThrottles:   OCC%d, OCMB%d HUID:0x%08X / %d"
                     " functional PORTs - %s",
                     proc_unit, l_ocmb_pos, ocmb_huid, port_list.size(), l_ocmbName);
            ++ocmb_count;
        } // for each ocmb

        if (l_fapi_targets_this_proc.size() > 0)
        {
            //Calculate Throttle settings for Over Temperature/Safe Mode
            //(must be run with OCMB chips under a single processor)
            err = memPowerThrottleOT(l_fapi_targets_this_proc, efficiency);
            if (nullptr != err) break;

            if (preheatErr == nullptr)
            {
                //Calculate Preheat Power for DIMMs
                // (must be run with OCMB chips under a single processor)
                preheatErr = memPowerPreheat(sys, l_fapi_targets_this_proc);
                if (preheatErr)
                {
                    // Collect traces at time of failure
                    preheatErr->collectTrace(HTMGT_COMP_NAME);
                    preheatErr->collectTrace("ISTEPS_TRACE");
                    preheatErr->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                }
            }

            // Add the OCMB targets under this proc to the full list of all targets
            l_full_fapi_target_list.insert(l_full_fapi_target_list.end(),
                                           l_fapi_targets_this_proc.begin(),
                                           l_fapi_targets_this_proc.end());
        }
    } // for each proc

    TMGT_INF("calcMemThrottles: Total of %d PROCs and %d functional OBMCs",
             proc_list.size(), ocmb_count);

    if (preheatErr || err)
    {
        // Not able to calculate preheat for at least one proc or overtemp calc failed,
        // disable preheat for all procs.
        TMGT_ERR("calcMemThrottles: Clearing DIMM_POWER for all OCMBs on all Procs");
        const ATTR_DIMM_POWER_type dimmPower = {0};
        for(const auto & proc_target : proc_list)
        {
            // Get functional OCMBs associated with this processor
            TargetHandleList ocmb_list;
            getChildAffinityTargets(ocmb_list, proc_target, CLASS_CHIP, TYPE_OCMB_CHIP);
            for(const auto & ocmb_target : ocmb_list)
            {
                // Clear all DIMM_POWER attributes for each OCMB target
                ocmb_target->setAttr<ATTR_DIMM_POWER>(dimmPower);
            }
        }
        if (preheatErr)
        {
            errlCommit(preheatErr, HTMGT_COMP_ID);
        }
    }

    if (nullptr == err)
    {
        TargetHandleList dimm_list;
        getClassResources(dimm_list, CLASS_LOGICAL_CARD, TYPE_DIMM, UTIL_FILTER_PRESENT);
        const size_t numDimms = dimm_list.size();

        //Calculate Throttle settings when system has redundant power (N+1)
        //Run across all OCMB chips in a node
        err = memPowerThrottleRedPower(l_full_fapi_target_list,
                                       efficiency,
                                       numDimms);
        if (nullptr == err)
        {
            //Calculate Throttle settings when system is in oversubscription (N)
            err = memPowerThrottleOversub(l_full_fapi_target_list,
                                          efficiency,
                                          numDimms);
        }
    }

    if (err)
    {
        err->collectTrace(HTMGT_COMP_NAME);
        err->collectTrace("ISTEPS_TRACE");
    }

    TMGT_INF("<<calcMemThrottles");
    return err;

}
}  // End namespace

#endif
