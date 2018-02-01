/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_memthrottles.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2018                        */
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
#include "htmgt_memthrottles.H"
#include "htmgt_utility.H"
#include <htmgt/htmgt_reasoncodes.H>
#include <errl/errlmanager.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include "htmgt_cfgdata.H"


// Hardware Procedures:
#include <p9_mss_utils_to_throttle.H>
#include <p9_mss_bulk_pwr_throttles.H>

// See src/include/usr/targeting/common/utilFilter.H for handy target utilities

using namespace TARGETING;



//for unit testing
//#define TRACUCOMP(args...)  TMGT_INF(args)
#define TRACUCOMP(args...)

namespace HTMGT
{
    uint32_t G_mem_power_max_throttles = 0;
    uint32_t G_mem_power_min_throttles = 0;

/**
 * Run hardware procedure to determine throttle/numerator/number of commands
 * based on the specified utilization
 *
 * @param[in] i_utilization - Minimum utilization value required (in %)
 * @param[in] i_watt_target - power target required for bulk_pwr_throttles
 */
errlHndl_t call_utils_to_throttle(
         std::vector <fapi2::Target<fapi2::TARGET_TYPE_MCS>> i_fapi_target_list,
                                  const uint32_t i_util,
                                  const uint32_t i_watt_target = 0)
{
    errlHndl_t err = NULL;
    // Convert to 1/100 % units for the HWP
    const uint32_t util_hundredth_percent = i_util * 100;
    uint32_t utilization[TMGT_MAX_MCA_PER_MCS] = {
        util_hundredth_percent, util_hundredth_percent };
    uint32_t l_watt_targets[TMGT_MAX_MCA_PER_MCS][TMGT_MAX_DIMM_PER_MCA] =
        {i_watt_target, i_watt_target, i_watt_target, i_watt_target};
    TMGT_INF("call_utils_to_throttle: utilization: %d, watt_target: %d",
             i_util, i_watt_target);

    // Update input attributes for specified targets
    for(const auto & l_fapi_target : i_fapi_target_list)
    {
        FAPI_ATTR_SET(fapi2::ATTR_MSS_DATABUS_UTIL, l_fapi_target, utilization);
        if (i_watt_target)
        {
            FAPI_ATTR_SET(fapi2::ATTR_MSS_MEM_WATT_TARGET,
                          l_fapi_target, l_watt_targets);
        }
    }

    // p9_mss_utils_to_throttle() - Sets number commands allowed within a
    //                              given port databus utilization
    // inputs: ATTR_MSS_DATABUS_UTIL
    // outputs: ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
    //          ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT, and
    //          ATTR_MSS_PORT_MAXPOWER
    TMGT_INF("call_utils_to_throttle: Calling HWP:p9_mss_utils_to_throttle"
             "(POWER) for %d MCS Targets", i_fapi_target_list.size());
    {
        FAPI_INVOKE_HWP(err, p9_mss_utils_to_throttle, i_fapi_target_list);
    }

    if (NULL != err)
    {
        TMGT_ERR("call_utils_to_throttle: HWP:p9_mss_utils_to_throttle failed"
                 " with rc=0x%04X", err->reasonCode());
    }

    return err;

} // end call_utils_to_throttle()



/**
 * Calculate throttles for over-temperture
 *
 * @param[in] i_fapi_target_list - list of FAPI MCS targets
 * @param[in] i_utilization - Minimum utilization value required
 */
errlHndl_t memPowerThrottleOT(
       std::vector < fapi2::Target< fapi2::TARGET_TYPE_MCS>> i_fapi_target_list,
                                   const uint8_t i_utilization)
{
    errlHndl_t err = NULL;

    TMGT_INF("memPowerThrottleOT: Calculating throttles for util: %d",
             i_utilization);

    err = call_utils_to_throttle(i_fapi_target_list, i_utilization);
    if (NULL == err)
    {
        uint32_t ot_mem_power = 0;
        for(const auto & mcs_fapi_target : i_fapi_target_list)
        {
            // Read HWP outputs:
            ATTR_OT_MIN_N_PER_MBA_type l_slot = {0};
            ATTR_OT_MEM_POWER_type l_power = {0};
            FAPI_ATTR_GET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
                          mcs_fapi_target, l_slot);
            FAPI_ATTR_GET(fapi2::ATTR_MSS_PORT_MAXPOWER,
                          mcs_fapi_target, l_power);
            ot_mem_power += l_power[0] + l_power[1];

            // Update MCS data (to be sent to OCC)
            TARGETING::Target * mcs_target =
                reinterpret_cast<TARGETING::Target *>(mcs_fapi_target.get());
            ConstTargetHandle_t proc_target = getParentChip(mcs_target);
            assert(proc_target != nullptr);
            const uint8_t occ_instance =
                proc_target->getAttr<TARGETING::ATTR_POSITION>();
            uint8_t mcs_unit = 0xFF;
            mcs_target->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(mcs_unit);
            mcs_target->setAttr<ATTR_OT_MIN_N_PER_MBA>(l_slot);
            mcs_target->setAttr<ATTR_OT_MEM_POWER>(l_power);
            TMGT_INF("memPowerThrottleOT: MIN: OCC%d/MCS%d - "
                     "N/slot: %d/%d, Power: %d/%dcW",
                     occ_instance, mcs_unit, l_slot[0], l_slot[1],
                     l_power[0], l_power[1]);
        }
        TMGT_INF("memPowerThrottleOT: Total Minimum Memory"
                 " Power: %dW", ot_mem_power/100);
    }
    else
    {
        TMGT_ERR("memPowerThrottleOT: Failed to calculate over-temp"
                 " memory throttles, rc=0x%04X",
                 err->reasonCode());
    }

    return err;

} // end memPowerThrottleOT()



/**
 * Run the p9_mss_bulk_pwr_throttles hardware procedure
 * to calculate memory throttling numerator values.
 *
 * @param[in] i_fapi_target_list - list of FAPI MCS targets
 * @param[in] i_wattTarget - the power target for the MCS
 * @param[in] i_utilization - the utilization desired
 */
errlHndl_t call_bulk_pwr_throttles(
      std::vector < fapi2::Target< fapi2::TARGET_TYPE_MCS>> i_fapi_target_list,
                       const uint32_t i_wattTarget,
                       const uint8_t i_utilization)
{
    errlHndl_t err = NULL;

    //Set the values the procedures need
    err = call_utils_to_throttle(i_fapi_target_list,
                                 i_utilization, i_wattTarget);
    if (NULL == err)
    {
        TMGT_INF("call_bulk_pwr_throttles: Calling HWP:p9_mss_bulk_pwr_"
                 "throttles(POWER) for MCS Targets");
        FAPI_INVOKE_HWP(err, p9_mss_bulk_pwr_throttles, i_fapi_target_list,
                        mss::throttle_type::POWER);
        if (NULL != err)
        {
            TMGT_ERR("call_bulk_pwr_throttles: p9_mss_bulk_pwr_throttles "
                     "failed with rc=0x%04X", err->reasonCode());
        }
    }
    else
    {
        TMGT_ERR("call_bulk_pwr_throttles: call_utils_to_throttle failed with"
                 " rc=0x%04X", err->reasonCode());
    }

    return err;

} // end call_bulk_pwr_throttles()


/**
 * Calculate throttles for when system has redundant power (N+1 mode)
 *
 * @param[in] i_fapi_target_list - list of FAPI MCS targets
 * @param[in] i_utilization - Minimum utilization value required
 * @param[in] i_efficiency - the regulator efficiency
 */
errlHndl_t memPowerThrottleRedPower(
         std::vector <fapi2::Target<fapi2::TARGET_TYPE_MCS>> i_fapi_target_list,
                              const uint8_t i_utilization,
                              const uint8_t i_efficiency)
{
    errlHndl_t err = NULL;
    Target* sys = NULL;
    uint32_t power = 0;
    uint32_t wattTarget = 0;
    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);

    //Get the max redundant (N+1) power allocated to memory
    power = sys->getAttr<ATTR_OPEN_POWER_N_PLUS_ONE_MAX_MEM_POWER_WATTS>();
    power *= 100; // convert to centiWatts

    //Account for the regulator efficiency (percentage), if supplied
    if (i_efficiency != 0)
    {
        power = (power * i_efficiency) / 100;
    }

    //Find the Watt target for each present DIMM
    TargetHandleList dimm_list;
    getAllLogicalCards(dimm_list, TYPE_DIMM, false);
    if (dimm_list.size())
    {
        wattTarget = power / dimm_list.size();
    }

    TMGT_INF("memPowerThrottleRedPower: N+1 power: %dW / %dcW per DIMM "
             "(%d DIMMs)", power/100, wattTarget, dimm_list.size());

    //Calculate the throttles
    err = call_bulk_pwr_throttles(i_fapi_target_list,
                                  wattTarget,
                                  i_utilization);
    if (NULL == err)
    {
        uint32_t tot_mem_power_cw = 0;
        for(auto & mcs_fapi_target : i_fapi_target_list)
        {
            // Read HWP output parms:
            ATTR_N_PLUS_ONE_N_PER_MBA_type l_slot = {0};
            ATTR_N_PLUS_ONE_N_PER_CHIP_type l_port = {0};
            ATTR_N_PLUS_ONE_MEM_POWER_type l_power = {0};
            FAPI_ATTR_GET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
                          mcs_fapi_target, l_slot);
            FAPI_ATTR_GET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT,
                          mcs_fapi_target, l_port);
            FAPI_ATTR_GET(fapi2::ATTR_MSS_PORT_MAXPOWER,
                          mcs_fapi_target, l_power);
            // Calculate memory power at min throttles
            tot_mem_power_cw += l_power[0] + l_power[1];

            // Update MCS data (to be sent to OCC)
            TARGETING::Target * mcs_target =
                reinterpret_cast<TARGETING::Target *>(mcs_fapi_target.get());
            ConstTargetHandle_t proc_target = getParentChip(mcs_target);
            assert(proc_target != nullptr);
            const uint8_t occ_instance =
                proc_target->getAttr<TARGETING::ATTR_POSITION>();
            uint8_t mcs_unit = 0xFF;
            mcs_target->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(mcs_unit);
            mcs_target->setAttr<ATTR_N_PLUS_ONE_N_PER_MBA>(l_slot);
            mcs_target->setAttr<ATTR_N_PLUS_ONE_N_PER_CHIP>(l_port);
            mcs_target->setAttr<ATTR_N_PLUS_ONE_MEM_POWER>(l_power);

            TMGT_INF("memPowerThrottleRedPower: NOMINAL: OCC%d/MCS%d - "
                     "N/slot: %d/%d, N/port: %d/%d, Power: %d/%dcW",
                     occ_instance, mcs_unit, l_slot[0], l_slot[1],
                     l_port[0], l_port[1], l_power[0], l_power[1]);
        }
        // Convert memory power to Watts
        G_mem_power_min_throttles = tot_mem_power_cw / 100;
        TMGT_INF("memPowerThrottleRedPower: Total Redundant Memory Power: %dW",
                 G_mem_power_min_throttles);
    }
    else
    {
        TMGT_ERR("memPowerThrottleRedPower: Failed to calculate redundant "
                 "power memory throttles, rc=0x%04X",
                 err->reasonCode());
    }

    return err;

} // end memPowerThrottleRedPower()



/**
 * Run hardware procedures to calculate the throttles for power capping
 *
 * @param[in] i_fapi_target_list - list of FAPI MCS targets
 * @param[in] i_utilization - Minimum utilization value required
 */
errlHndl_t memPowerThrottlePowercap(
       std::vector < fapi2::Target< fapi2::TARGET_TYPE_MCS>> i_fapi_target_list,
                                    const uint8_t i_utilization)
{
    errlHndl_t err = NULL;

    TMGT_INF("memPowerThrottlePowercap: Calculating throttles for util: %d",
             i_utilization);

    if (i_utilization != 0)
    {
        //Calculate the throttles
        err = call_utils_to_throttle(i_fapi_target_list, i_utilization);
    }
    if (NULL == err)
    {
        uint32_t tot_mem_power_cw = 0;
        for(auto & mcs_fapi_target : i_fapi_target_list)
        {
            TARGETING::Target * mcs_target =
                reinterpret_cast<TARGETING::Target *>(mcs_fapi_target.get());
            ConstTargetHandle_t proc_target = getParentChip(mcs_target);
            assert(proc_target != nullptr);
            const uint8_t occ_instance =
                proc_target->getAttr<TARGETING::ATTR_POSITION>();
            uint8_t mcs_unit = 0xFF;
            mcs_target->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(mcs_unit);

            // Read HWP output parms (if the procedure was run):
            ATTR_POWERCAP_N_PER_MBA_type l_slot = {0xFF, 0xFF};
            ATTR_POWERCAP_N_PER_CHIP_type l_port = {0xFF, 0xFF};
            ATTR_POWERCAP_MEM_POWER_type l_power = {0};
            if (i_utilization != 0)
            {
                FAPI_ATTR_GET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
                              mcs_fapi_target, l_slot);
                FAPI_ATTR_GET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT,
                              mcs_fapi_target, l_port);
                FAPI_ATTR_GET(fapi2::ATTR_MSS_PORT_MAXPOWER,
                              mcs_fapi_target, l_power);
            }
            // else N values will be 0xFF and will be overwritten below

            // Validate pcap throttles are the lowest throttles
            ATTR_N_PLUS_ONE_N_PER_MBA_type l_slot_redun = {0};
            ATTR_N_PLUS_ONE_N_PER_CHIP_type l_port_redun = {0};
            ATTR_N_PLUS_ONE_MEM_POWER_type l_power_redun = {0};
            mcs_target->tryGetAttr<ATTR_N_PLUS_ONE_N_PER_MBA>(l_slot_redun);
            mcs_target->tryGetAttr<ATTR_N_PLUS_ONE_N_PER_CHIP>(l_port_redun);
            mcs_target->tryGetAttr<ATTR_N_PLUS_ONE_MEM_POWER>(l_power_redun);
            unsigned int mca_index;
            for (mca_index = 0; mca_index < TMGT_MAX_MCA_PER_MCS; ++mca_index)
            {
                if (l_slot[mca_index] > l_slot_redun[mca_index])
                {
                    TMGT_INF("memPowerThrottlePowercap: MCS%d/MCA%d - "
                             " redun throttle (%d) < pcap throttle (%d)",
                             mcs_unit, mca_index,
                             l_slot_redun[mca_index], l_slot[mca_index]);
                    l_slot[mca_index] = l_slot_redun[mca_index];
                    l_port[mca_index] = l_port_redun[mca_index];
                    l_power[mca_index] = l_power_redun[mca_index];
                }
            }

            // Update MCS data (to be sent to OCC)
            mcs_target->setAttr<ATTR_POWERCAP_N_PER_MBA>(l_slot);
            mcs_target->setAttr<ATTR_POWERCAP_N_PER_CHIP>(l_port);
            mcs_target->setAttr<ATTR_POWERCAP_MEM_POWER>(l_power);
            // Calculate memory power at max throttles
            tot_mem_power_cw += l_power[0] + l_power[1];

            // Trace Results
            TMGT_INF("memPowerThrottlePowercap: PCAP: OCC%d/MCS%d - "
                     "N/slot: %d/%d, N/port: %d/%d, Power: %d/%dcW",
                     occ_instance, mcs_unit, l_slot[0], l_slot[1],
                     l_port[0], l_port[1], l_power[0], l_power[1]);
        }
        // Convert memory power to Watts
        G_mem_power_max_throttles = tot_mem_power_cw / 100;
        TMGT_INF("memPowerThrottlePowercap: Total PowerCap Memory"
                 " Power: %dW (@max throttles)", G_mem_power_max_throttles);
    }
    else
    {
        TMGT_ERR("memPowerThrottlePowercap: Failed to calculate powercap "
                 "memory throttles, rc=0x%04X",
                 err->reasonCode());
    }

    return err;

} // end memPowerThrottlePowercap()


void calculate_system_power()
{
    Target* sys = NULL;
    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);

    TARGETING::TargetHandleList proc_list;
    // Get all processor chips (do not have to be functional)
    getAllChips(proc_list, TARGETING::TYPE_PROC, false);
    const uint8_t num_procs = proc_list.size();

    const uint16_t proc_socket_power =
        sys->getAttr<ATTR_PROC_SOCKET_POWER_WATTS>();
    TMGT_INF("calculate_system_power: proc socket power: %5dW (%d procs)",
             proc_socket_power, num_procs);
    const uint16_t misc_power =
        sys->getAttr<ATTR_MISC_SYSTEM_COMPONENTS_MAX_POWER_WATTS>();
    TMGT_INF("calculate_system_power: misc power: %5dW", misc_power);

    // Calculate Total non-GPU maximum power (Watts):
    //   Maximum system power excluding GPUs when CPUs are at maximum frequency
    //   (ultra turbo) and memory at maximum power (least throttled) plus
    //   everything else (fans...) excluding GPUs.
    uint32_t power_max = proc_socket_power * num_procs;
    TMGT_INF("calculate_system_power: power(max)  proc: %5dW, mem: %5dW",
                 power_max, G_mem_power_min_throttles);
    power_max += G_mem_power_min_throttles + misc_power;
    TMGT_INF("calculate_system_power: max proc/mem/misc power (no GPUs): %5dW",
             power_max);
    sys->setAttr<ATTR_CALCULATED_MAX_SYS_POWER_EXCLUDING_GPUS>(power_max);

    // Calculate Total Processor/Memory Power Drop (Watts):
    //   The max non-GPU power can be reduced (with proc/mem)
    //   calculates this as the CPU power at minimum frequency plus memory at
    //   minimum power (most throttled)
    const uint16_t freq_min = sys->getAttr<ATTR_MIN_FREQ_MHZ>();
    // Minimum Frequency biasing (ATTR_FREQ_BIAS_POWERSAVE) will be ignored here
    uint16_t freq_nominal, freq_turbo, freq_ultra;
    check_wof_support(freq_nominal, freq_turbo, freq_ultra);
    if (freq_turbo == 0)
    {
        freq_turbo = sys->getAttr<ATTR_FREQ_CORE_MAX>();
        // Turbo Frequency biasing (ATTR_FREQ_BIAS_TURBO) will be ignored here
        if (freq_turbo == 0)
        {
            // If no turbo point, then use nominal...
            TMGT_ERR("calculate_system_power: No turbo frequency to calculate "
                     "power drop.  Using nominal");
            freq_turbo = freq_nominal;
        }
    }
    const uint16_t mhz_per_watt = sys->getAttr<ATTR_PROC_MHZ_PER_WATT>();
    // Drop always calculated from Turbo to Min (not ultra)
    uint32_t proc_drop = ((freq_turbo - freq_min) / mhz_per_watt);
    TMGT_INF("calculate_system_power: Processor Power Drop: %dMHz / %dMHz/W"
             " = %dW / proc",
             freq_turbo - freq_min, mhz_per_watt, proc_drop);
    proc_drop *= num_procs;
    const uint32_t memory_drop =
        G_mem_power_min_throttles - G_mem_power_max_throttles;
    TMGT_INF("calculate_system_power: Memory Power Drop: %d - %d = %dW",
             G_mem_power_min_throttles, G_mem_power_max_throttles,
             G_mem_power_min_throttles - G_mem_power_max_throttles);
    const uint32_t power_drop = proc_drop + memory_drop;
    TMGT_INF("calculate_system_power: Proc/Mem Power Drop: %d + %d = %dW",
             proc_drop, memory_drop, power_drop);
    sys->setAttr<ATTR_CALCULATED_PROC_MEMORY_POWER_DROP>(power_drop);

} // end calculate_system_power()


errlHndl_t calcMemThrottles()
{
    Target* sys = NULL;

    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);

    uint8_t min_utilization =
        sys->getAttr<ATTR_OPEN_POWER_MIN_MEM_UTILIZATION_THROTTLING>();
    if (min_utilization == 0)
    {
        // Use SAFEMODE utilization
        min_utilization = sys->getAttr
            <ATTR_MSS_MRW_SAFEMODE_MEM_THROTTLED_N_COMMANDS_PER_PORT>();
        TMGT_INF("MIN_MEM_UTILIZATION_THROTTLING is 0, so reading "
                 "ATTR_MSS_MRW_SAFEMODE_MEM_THROTTLED_N_COMMANDS_PER_PORT:"
                 " %d", min_utilization);
        if (min_utilization == 0)
        {
            // Use hardcoded utilization
            min_utilization = 10;
            TMGT_ERR("ATTR_MSS_MRW_SAFEMODE_MEM_THROTTLED_N_COMMANDS_PER_PORT"
                     " is 0!  Using %d", min_utilization);
        }
    }
    const uint8_t efficiency =
        sys->getAttr<ATTR_OPEN_POWER_REGULATOR_EFFICIENCY_FACTOR>();
    TMGT_INF("calcMemThrottles: Using min utilization=%d, efficiency=%d"
             " percent", min_utilization, efficiency);

    //Get all functional MCSs
    TargetHandleList mcs_list;
    getAllChiplets(mcs_list, TYPE_MCS, true);
    TMGT_INF("calcMemThrottles: found %d MCSs", mcs_list.size());

    // Create a FAPI Target list for HWP
    std::vector < fapi2::Target< fapi2::TARGET_TYPE_MCS>> l_fapi_target_list;
    for(const auto & mcs_target : mcs_list)
    {
        uint32_t mcs_huid = 0xFFFFFFFF;
        uint8_t mcs_unit = 0xFF;
        mcs_target->tryGetAttr<TARGETING::ATTR_HUID>(mcs_huid);
        mcs_target->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(mcs_unit);

        // Query the functional MCAs for this MCS
        TARGETING::TargetHandleList mca_list;
        getChildAffinityTargetsByState(mca_list, mcs_target, CLASS_UNIT,
                                       TYPE_MCA, UTIL_FILTER_FUNCTIONAL);
        uint8_t occ_instance = 0xFF;
        ConstTargetHandle_t proc_target = getParentChip(mcs_target);
        assert(proc_target != nullptr);
        occ_instance = proc_target->getAttr<TARGETING::ATTR_POSITION>();
        TMGT_INF("calcMemThrottles: OCC%d, MCS%d HUID:0x%08X has %d"
                 " functional MCAs",
                 occ_instance, mcs_unit, mcs_huid, mca_list.size());

        // Convert to FAPI target and add to list
        fapi2::Target<fapi2::TARGET_TYPE_MCS> l_fapiTarget(mcs_target);
        l_fapi_target_list.push_back(l_fapiTarget);
    }

    errlHndl_t err = NULL;
    do
    {
        //Calculate Throttle settings for Over Temperature
        err = memPowerThrottleOT(l_fapi_target_list, min_utilization);
        if (NULL != err) break;

        //Calculate Throttle settings for Nominal/Turbo
        err = memPowerThrottleRedPower(l_fapi_target_list,
                                       min_utilization, efficiency);
        if (NULL != err) break;

        //Calculate Throttle settings for Power Capping
        uint8_t pcap_min_utilization;
        if (!sys->tryGetAttr<ATTR_OPEN_POWER_MIN_MEM_UTILIZATION_POWER_CAP>
            (pcap_min_utilization))
        {
            pcap_min_utilization = 0;
        }
        err = memPowerThrottlePowercap(l_fapi_target_list,pcap_min_utilization);

    } while(0);

    calculate_system_power();

    if (err)
    {
        err->collectTrace(HTMGT_COMP_NAME);
    }

    return err;

}
}  // End namespace
