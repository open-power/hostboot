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

// Memory Hardware Procedures:
#include <p10_mss_utils_to_throttle.H>
#include <exp_bulk_pwr_throttles.H>

// See src/include/usr/targeting/common/utilFilter.H for handy target utilities

using namespace TARGETING;


/**
 * Uses system attributes:
 *   ATTR_REGULATOR_EFFICIENCY_FACTOR    - Power supply efficiency
 *   ATTR_N_MAX_MEM_POWER_WATTS          - Max memory power for N
 *   ATTR_N_PLUS_ONE_MAX_MEM_POWER_WATTS - Max memory power for N+1
 *   ATTR_MIN_MEM_UTILIZATION_THROTTLING - Min memory utilization
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
                if (l_port_unit >= HTMGT_MAX_PORT_PER_OCMB_CHIP)
                {
                    TMGT_ERR("memPowerThrottleOT: Invalid CHIP_UNIT %d for MEM_PORT",
                             l_port_unit);
                    attr_failure = true;
                    l_port_unit = 0;
                }

                // Read HWP outputs:
                if (!l_portTarget->tryGetAttr<ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT>
                    (l_slot[l_port_unit]))
                {
                    TMGT_ERR("memPowerThrottleOT: failed to read "
                             "EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT");
                    attr_failure = true;
                }

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
        TMGT_INF("call_bulk_pwr_throttles: Calling HWP:exp_bulk_pwr_"
                 "throttles(POWER) with target of %dcW", i_watt_target);
        FAPI_INVOKE_HWP(err, exp_bulk_pwr_throttles, i_fapi_target_list,
                        mss::throttle_type::POWER);
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
 * Calculate throttles for when system has redundant power (N+1 mode)
 *
 * @param[in] i_fapi_target_list - list of FAPI OCMB targets
 * @param[in] i_efficiency - the regulator efficiency (percent)
 */
errlHndl_t memPowerThrottleRedPower(
         std::vector <fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>> i_fapi_target_list,
                              const uint8_t i_efficiency)
{
    errlHndl_t err = nullptr;
    Target* sys = UTIL::assertGetToplevelTarget();
    uint32_t power = 0;
    uint32_t wattTarget = 0;

    //Get the max redundant (N+1) power allocated to memory
    power = sys->getAttr<ATTR_N_PLUS_ONE_MAX_MEM_POWER_WATTS>();
    power *= 100; // convert to centiWatts

    //Account for the regulator efficiency (percentage), if supplied
    if (i_efficiency != 0)
    {
        power *= (i_efficiency / 100.0);
    }

    //Find the Watt target for each present DIMM
    TargetHandleList dimm_list;
    getClassResources(dimm_list, CLASS_LOGICAL_CARD, TYPE_DIMM, UTIL_FILTER_PRESENT);
    if (dimm_list.size())
    {
        wattTarget = power / dimm_list.size();
    }
    TMGT_INF("memPowerThrottleRedPower: N+1 power: %dW (%d present DIMMs) -> "
             "%dcW per DIMM", power/100, dimm_list.size(), wattTarget);

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
                if (l_port_unit >= HTMGT_MAX_PORT_PER_OCMB_CHIP)
                {
                    TMGT_ERR("memPowerThrottleRedPower: Invalid CHIP_UNIT "
                             "%d for MEM_PORT", l_port_unit);
                    attr_failure = true;
                    l_port_unit = 0;
                }

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
                              const uint8_t i_efficiency)
{
    errlHndl_t err = nullptr;
    Target* sys = UTIL::assertGetToplevelTarget();
    uint32_t power = 0;
    uint32_t wattTarget = 0;

    //Get the max oversubscribed (N) power allocated to memory
    power = sys->getAttr<ATTR_N_MAX_MEM_POWER_WATTS>();
    power *= 100; // convert to centiWatts

    //Account for the regulator efficiency (percentage), if supplied
    if (i_efficiency != 0)
    {
        power *= (i_efficiency / 100.0);
    }

    //Find the Watt target for each present DIMM
    TargetHandleList dimm_list;
    getClassResources(dimm_list, CLASS_LOGICAL_CARD, TYPE_DIMM, UTIL_FILTER_PRESENT);
    if (dimm_list.size())
    {
        wattTarget = power / dimm_list.size();
    }
    TMGT_INF("memPowerThrottleOversub: N power: %dW (%d present DIMMs) -> "
             "%dcW per DIMM", power/100, dimm_list.size(), wattTarget);

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
                if (l_port_unit >= HTMGT_MAX_PORT_PER_OCMB_CHIP)
                {
                    TMGT_ERR("memPowerThrottleOversub: Invalid CHIP_UNIT "
                             "%d for MEM_PORT", l_port_unit);
                    attr_failure = true;
                    l_port_unit = 0;
                }
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

    // Create a FAPI Target list of all OCMB chips for all processors
    std::vector < fapi2::Target
        < fapi2::TARGET_TYPE_OCMB_CHIP>> l_full_fapi_target_list;

    // Get all functional processor chips
    TARGETING::TargetHandleList proc_list;
    getAllChips(proc_list, TARGETING::TYPE_PROC, true);
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
        TMGT_INF("calcMemThrottles: proc%d HUID:0x%08X / %d functional OCMB_CHIPs",
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
            TMGT_INF("calcMemThrottles: OCC%d, OCMB%d HUID:0x%08X / %d"
                     " functional PORTs - %s",
                     proc_unit, l_ocmb_pos, ocmb_huid, port_list.size(), l_ocmbName);
            ++ocmb_count;
        } // for each ocmb

        //Calculate Throttle settings for Over Temperature/Safe Mode
        //(must be run with OCMB chips under a single processor)
        err = memPowerThrottleOT(l_fapi_targets_this_proc, efficiency);
        if (nullptr != err) break;

        // Add the OCMB targets under this proc to the full list of all targets
        l_full_fapi_target_list.insert(l_full_fapi_target_list.end(),
                                       l_fapi_targets_this_proc.begin(),
                                       l_fapi_targets_this_proc.end());
    } // for each proc

    TMGT_INF("calcMemThrottles: Total of %d PROCs and %d functional OBMCs",
             proc_list.size(), ocmb_count);

    if (nullptr == err)
    {
        //Calculate Throttle settings when system has redundant power (N+1)
        //Run across all OCMB chips in a node
        err = memPowerThrottleRedPower(l_full_fapi_target_list,
                                       efficiency);
        if (nullptr == err)
        {
            //Calculate Throttle settings when system is in oversubscription (N)
            err = memPowerThrottleOversub(l_full_fapi_target_list,
                                          efficiency);
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
