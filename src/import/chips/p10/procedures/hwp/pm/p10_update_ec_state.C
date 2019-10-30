/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_update_ec_state.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file  p10_update_ec_state.C
/// @brief Update the core configured data in CCSR register and then deals with
///        deconfigured cores to verify the chiplet state..if it is still running then
///        will put the core to stop 11 state
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : HB,PGPE,CME,OCC
///

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include "p10_update_ec_state.H"
#include <p10_pm_util.H>
#include "p10_hcd_common.H"
#include "p10_hcd_cache_stopclocks.H"
#include "p10_hcd_core_poweroff.H"
#include "p10_hcd_l3_purge.H"
#include "p10_hcd_l2_purge.H"
#include "p10_hcd_powerbus_purge.H"
#include "p10_hcd_l2_tlbie_quiesce.H"
#include "p10_hcd_ncu_purge.H"
#include "p10_hcd_chtm_purge.H"
#include "p10_hcd_core_stopclocks.H"
#include "p10_hcd_cache_poweroff.H"
#include "p10_hcd_core_shadows_disable.H"
#include "p10_hcd_core_stopgrid.H"
#include <p10_scom_proc.H>
#include <p10_scom_c.H>
#include <p10_scom_eq.H>


using namespace scomt;
using namespace proc;
using namespace c;
using namespace eq;


// -----------------------------------------------------------------------------
//  Function prototypes
// -----------------------------------------------------------------------------
static fapi2::ReturnCode update_ec_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


fapi2::ReturnCode verify_ec_hw_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);



fapi2::ReturnCode p10_check_core_l3_clock_power_state(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    uint8_t i_core_unit_pos);

// -----------------------------------------------------------------------------
//  Constants
// -----------------------------------------------------------------------------

// See .H for documentation
fapi2::ReturnCode p10_update_ec_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    FAPI_IMP("> p10_update_ec_state");

    FAPI_TRY(update_ec_config(i_target),
             "Error update_core_config detected");
    //TODO Need to find the right way to get deconfigured target
    FAPI_TRY(verify_ec_hw_state(i_target));

fapi_try_exit:
    FAPI_INF("< p10_update_ec_state");

    return fapi2::current_err;
} // END p10_update_ec_state

fapi2::ReturnCode verify_ec_hw_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF (">>verify_hw_state");
    uint8_t l_core_unit_pos;

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE> >l_core_list;
    FAPI_TRY(getDeconfiguredTargets(i_target, l_core_list));

    for (auto l_core : l_core_list)
    {

        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                l_core,
                                l_core_unit_pos));
        FAPI_INF("Core present but non functional %d",
                 l_core_unit_pos);

        //Check the clock state and power state
        FAPI_TRY(p10_check_core_l3_clock_power_state(l_core, l_core_unit_pos));

    }

fapi_try_exit:
    FAPI_INF("< update_core_config...");
    return fapi2::current_err;

}

/// @brief Update the CCSR for cores
///
/// @param[in]     i_target   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode update_ec_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("> update_core_config...");

    uint8_t l_present_core_unit_pos;
    uint8_t l_functional_core_unit_pos;
    fapi2::buffer<uint64_t> l_core_config = 0;
    fapi2::buffer<uint64_t> l_pscom_config = 0;

    auto l_core_present_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_PRESENT);

    auto l_core_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_INF("  Number of present cores = %d; Number of functional cores = %d",
             l_core_present_vector.size(),
             l_core_functional_vector.size());

    // For each present core,  set multicast groups and the CCSR
    for (auto core_present_it : l_core_present_vector)
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                core_present_it,
                                l_present_core_unit_pos));

        FAPI_INF("  Checking if present EC %d is functional",
                 l_present_core_unit_pos);

        for (auto core_functional_it : l_core_functional_vector)
        {
            FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                    core_functional_it,
                                    l_functional_core_unit_pos));
            FAPI_DBG("  Functional EC %d",
                     l_functional_core_unit_pos);

            if (l_functional_core_unit_pos == l_present_core_unit_pos)
            {
                // Set the appropriate bit in the Core Configuration Status
                // Register buffer
                FAPI_INF("  Setting EC %d as good in value to be written to CCSR",
                         l_present_core_unit_pos);
                l_core_config.setBit(l_present_core_unit_pos);

                auto l_eq = core_functional_it.getParent<fapi2::TARGET_TYPE_EQ>();

                l_present_core_unit_pos = l_present_core_unit_pos % 4;

                //Update the pscom enable bit
                l_pscom_config.setBit(l_present_core_unit_pos + 5);

                FAPI_TRY(fapi2::putScom(l_eq, CPLT_CTRL3_WO_OR, l_pscom_config));
                break;
            }  // Current core
        } // Functional core loop
    }  // Present core loop

    // Write the recalculated OCC Core Configuration Status Register
    FAPI_INF("  Writing OCC CCSR");
    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_CCSR_RW, l_core_config));


fapi_try_exit:
    FAPI_INF("< update_core_config...");
    return fapi2::current_err;

}

#define CORE_START_POSITION 5
#define CACHE_START_POSITION 9

fapi2::ReturnCode p10_check_core_l3_clock_power_state(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    uint8_t i_core_unit_pos)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_pfet_sense = 0;
    uint8_t l_core_relative_pos  = i_core_unit_pos % 4;
    uint8_t l_l3_relative_pos    = i_core_unit_pos % 4;
    uint8_t l_core_clock_State = 0;
    uint8_t l_l3_clock_State = 0;


    do
    {
        auto l_eq_target = i_core_target.getParent<fapi2::TARGET_TYPE_EQ>();
        //Read the power state of core/l2
        FAPI_TRY(GET_CPMS_CL2_PFETSTAT(i_core_target, l_data));
        GET_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE(l_data, l_pfet_sense);

        //verify L3/core clocks are on
        FAPI_TRY(GET_CLOCK_STAT_SL(l_eq_target, l_data));
        l_core_clock_State = l_data & BIT64(l_core_relative_pos + CORE_START_POSITION);
        l_l3_clock_State   = l_data & BIT64(l_l3_relative_pos + CACHE_START_POSITION);

        //Verify core is powered on
        //If core is powered on
        //  then if core(ECl2) clocks are on
        //      then need to purge the l2 and stop the core clocks
        //  if L3 clocks are on
        //      then purge L3 and stop the l3 clocks
        //  Power off the core and L3
        if( l_pfet_sense)
        {
            if (!l_core_clock_State)
            {
                FAPI_TRY(p10_hcd_l2_purge(i_core_target));
                FAPI_TRY(p10_hcd_l2_tlbie_quiesce(i_core_target));
                FAPI_TRY(p10_hcd_ncu_purge(i_core_target));
                FAPI_TRY(p10_hcd_core_shadows_disable(i_core_target));
                FAPI_TRY(p10_hcd_core_stopclocks(i_core_target));
                FAPI_TRY(p10_hcd_core_stopgrid(i_core_target));
            }

            FAPI_TRY(p10_hcd_core_poweroff(i_core_target));

            if (!l_l3_clock_State)
            {
                FAPI_TRY(p10_hcd_chtm_purge(i_core_target));
                FAPI_TRY(p10_hcd_l3_purge(i_core_target));
                FAPI_TRY(p10_hcd_powerbus_purge(i_core_target));
                FAPI_TRY(p10_hcd_cache_stopclocks(i_core_target));
            }

            FAPI_TRY(p10_hcd_cache_poweroff(i_core_target));
        }
    }
    while(0);

fapi_try_exit:
    FAPI_INF("< p10_check_core_clock_power_state...");
    return fapi2::current_err;

}
