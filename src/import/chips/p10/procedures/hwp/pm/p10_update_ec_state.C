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
#include <multicast_group_defs.H>
#include <p10_perv_sbe_cmn.H>
#include <p10_hang_pulse_mc_setup_tables.H>

#ifdef __HOSTBOOT_MODULE
    #include <util/misc.H>                   // Util::isSimicsRunning
#endif

using namespace scomt;
using namespace proc;
using namespace c;
using namespace eq;


#define CL2_START_POSITION 5
#define L3_START_POSITION 9
#define MMA_START_POSITION 15
// -----------------------------------------------------------------------------
//  Function prototypes
// -----------------------------------------------------------------------------
static fapi2::ReturnCode update_ec_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode verify_ec_hw_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode clear_atomic_lock(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    const uint32_t i_lockId);

fapi2::ReturnCode clear_spwu_done(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target);
fapi2::ReturnCode set_atomic_lock(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    uint32_t& o_lockId);

fapi2::ReturnCode powerdown_deconfigured_cl2_l3(
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

    // Set up multicast groups, MCGROUP_GOOD_CORES gets all EQs that
    // are good according to ATTR_PG
    FAPI_TRY(p10_perv_sbe_cmn_setup_multicast_groups(i_target,
             SELECT_EX_MC_GROUPS),
             "Error from p10_perv_sbe_cmn_setup_multicast_groups");


    FAPI_TRY(verify_ec_hw_state(i_target));


fapi_try_exit:
    FAPI_INF("< p10_update_ec_state");

    return fapi2::current_err;
} // END p10_update_ec_state

fapi2::ReturnCode verify_ec_hw_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    do
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
            // RTC 249759: temporarily enable deconfigured cores/L3 to check for PFET state
            FAPI_TRY(powerdown_deconfigured_cl2_l3(l_core, l_core_unit_pos));

        }
    }
    while(0);

fapi_try_exit:
    FAPI_INF("<< verify_hw_state...");
    return fapi2::current_err;

}


//-----------------------------------------------------------------------------
/// @brief Check for cache only cores
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
inline
fapi2::ReturnCode check_cache_only(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    bool& o_cache_only)
{
    using namespace scomt::eq;
    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_data64;

    fapi2::ATTR_ECO_MODE_Type l_attr_eco_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE, i_core_target, l_attr_eco_mode));

    if (l_attr_eco_mode)
    {
        FAPI_DBG("cache only core detected");
        o_cache_only = true;

        fapi2::ATTR_CHIP_UNIT_POS_Type l_core_num = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               i_core_target,
                               l_core_num));

        // Tell the QMEs about this cache only core
        auto l_eq_target = i_core_target.getParent<fapi2::TARGET_TYPE_EQ>();
        l_data64.flush<0>().setBit(28 + (l_core_num % 4));
        FAPI_TRY(fapi2::putScom(l_eq_target, QME_SCRB_WO_OR, l_data64));
        FAPI_DBG("Write QME Scratach B OR with 0x%16llX", l_data64);

        // Tell the OCC about this cache only core
        auto l_proc_target = i_core_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        l_data64.flush<0>().setBit(l_core_num);
        FAPI_TRY(fapi2::putScom(l_proc_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG6_WO_OR, l_data64));
        FAPI_DBG("Write OCC Flag6 OR with 0x%16llX", l_data64);
    }

fapi_try_exit:
    FAPI_DBG("< check_cache_only...");
    return fapi2::current_err;
}



/// @brief Update the CCSR for configured cores and necessary registers for cache only cores
///
/// @param[in]     i_target   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode update_ec_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("> update_ec_config...");

    uint8_t l_present_core_unit_pos;
    uint8_t l_functional_core_unit_pos;
    fapi2::buffer<uint64_t> l_data64 = 0;
    fapi2::buffer<uint64_t> l_core_config = 0;
    fapi2::buffer<uint64_t> l_pg_config = 0;
    fapi2::buffer<uint64_t> l_eco_config = 0;
    uint8_t l_core_not_func = 0;

    auto l_core_present_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_PRESENT);

    auto l_core_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_INF("  Number of present cores = %d; Number of functional cores = %d",
             l_core_present_vector.size(),
             l_core_functional_vector.size());

    // For each present core,set region partial good and OCC CCSR bits
    for (auto core_present_it : l_core_present_vector)
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                core_present_it,
                                l_present_core_unit_pos));

        FAPI_INF("  Checking if present EC %d is functional",
                 l_present_core_unit_pos);

        for (auto core_functional_it : l_core_functional_vector)
        {
            l_core_not_func = 0;
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

                //Update the pg bits
                l_pg_config.flush<0>().setBit((l_present_core_unit_pos % 4) + CL2_START_POSITION); //ecl2
                l_pg_config.setBit((l_present_core_unit_pos % 4) + L3_START_POSITION); //l3
                l_pg_config.setBit((l_present_core_unit_pos % 4) + MMA_START_POSITION); //mma
                auto l_eq = core_functional_it.getParent<fapi2::TARGET_TYPE_EQ>();

                //setting Region Partial Good bits
                FAPI_TRY(fapi2::putScom(l_eq, CPLT_CTRL2_WO_OR, l_pg_config));

                // Clear Power Gate/DFT fence
                FAPI_TRY(fapi2::putScom(l_eq, CPLT_CTRL5_WO_CLEAR, l_pg_config));

                // Determine if an ECO core is indicated
                fapi2::ATTR_ECO_MODE_Type l_attr_eco_mode;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE, core_functional_it, l_attr_eco_mode));

                if (l_attr_eco_mode)
                {
                    l_eco_config.setBit(l_present_core_unit_pos);

                    // Tell the QME about this cache only core
                    l_data64.flush<0>().setBit(28 + (l_present_core_unit_pos % 4));
                    FAPI_TRY(fapi2::putScom(l_eq, QME_SCRB_WO_OR, l_data64));
                }

                break;
            }  // Current core
            else
            {
                l_core_not_func = 1;
            }
        } // Functional core loop

        if ( l_core_not_func )
        {
            //Update the pg bits
            l_pg_config.flush<0>().setBit((l_present_core_unit_pos % 4) + CL2_START_POSITION); //ecl2
            l_pg_config.setBit((l_present_core_unit_pos % 4) + L3_START_POSITION); //l3
            l_pg_config.setBit((l_present_core_unit_pos % 4) + MMA_START_POSITION); //mma
            auto l_eq = core_present_it.getParent<fapi2::TARGET_TYPE_EQ>();

            //setting Region Partial Good bits
            FAPI_TRY(fapi2::putScom(l_eq, CPLT_CTRL2_WO_CLEAR, l_pg_config));
        }

    }  // Present core loop

    // Write the recalculated OCC CCSR and Flag6 for ECO cores

    l_data64.flush<1>();
    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR, l_data64));
    FAPI_INF("  Writing OCC CCSR:  0x%16llX", l_core_config)
    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_CCSR_RW, l_core_config));

    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG6_WO_CLEAR, l_data64));
    FAPI_INF("  Writing OCC Flag 6 with ECO configuration:  0x%16llX", l_eco_config);
    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG6_WO_OR, l_eco_config));

fapi_try_exit:
    FAPI_INF("<< update_ec_config...");
    return fapi2::current_err;

}


fapi2::ReturnCode powerdown_deconfigured_cl2_l3(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    uint8_t i_core_unit_pos)
{
    fapi2::buffer<uint64_t> l_data = 0;

    uint64_t l_cl2_pfet_sense = 0;
    uint64_t l_l3_pfet_sense = 0;
    uint8_t l_core_relative_pos  = i_core_unit_pos % 4;
    uint8_t l_core_clock_State = 0;
    uint8_t l_l3_clock_State = 0;
    fapi2::buffer<uint64_t> l_pscom_pg_config = 0;
    uint32_t l_lockId = 0;


    do
    {
        auto l_eq_target = i_core_target.getParent<fapi2::TARGET_TYPE_EQ>();
#ifdef __HOSTBOOT_MODULE

        if (! Util::isSimicsRunning())
        {
#endif
            FAPI_TRY(set_atomic_lock(i_core_target, l_lockId));

#ifdef __HOSTBOOT_MODULE
        }

#endif

        //Update the pscom enable and pg bits to temporarily allow controlling
        //of now deconfigured elements.
        l_pscom_pg_config.setBit(l_core_relative_pos + CL2_START_POSITION); //ecl2
        l_pscom_pg_config.setBit(l_core_relative_pos + L3_START_POSITION); //l3
        l_pscom_pg_config.setBit(l_core_relative_pos + MMA_START_POSITION); //mma

        FAPI_TRY(fapi2::putScom(l_eq_target, CPLT_CTRL3_WO_OR, l_pscom_pg_config));
        FAPI_TRY(fapi2::putScom(l_eq_target, CPLT_CTRL2_WO_OR, l_pscom_pg_config));

        //verify L3/core clocks are on
        FAPI_TRY(GET_CLOCK_STAT_SL(l_eq_target, l_data));

        l_core_clock_State = l_data.getBit(l_core_relative_pos + CL2_START_POSITION);
        l_l3_clock_State = l_data.getBit(l_core_relative_pos + L3_START_POSITION);
        FAPI_INF("Core position %d CL2 state  %d L3 state %d", l_core_relative_pos,
                 l_core_clock_State, l_l3_clock_State);

        if (!l_core_clock_State)
        {
            //Read the power state of core/l2
            FAPI_TRY(GET_CPMS_CL2_PFETSTAT(i_core_target, l_data));
            GET_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE(l_data, l_cl2_pfet_sense);
        }

        if (!l_l3_clock_State)
        {
            //Read the power state of L3
            FAPI_TRY(GET_CPMS_L3_PFETSTAT(i_core_target, l_data));
            GET_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(l_data, l_l3_pfet_sense);
        }

        if ( l_core_clock_State && l_l3_clock_State)
        {
            FAPI_INF("Both L3 and L2 units are powered off and clock off");
        }
        else
        {
            //There is a chance of this core is activated during istep 4, and in
            //istep 4 spwu is asserted, so we need to deassert before QME boots
            //
            //Also in core unit checkstop case,spwu can be asserted for the
            //deconfigured cores , so we need to deassert by looking at the
            //other SPWU registers

            FAPI_TRY(clear_spwu_done(i_core_target));


            //Verify core is powered on
            //If core is powered on
            //  then if core(ECl2) clocks are on
            //      then need to purge the l2 and stop the core clocks
            //  if L3 clocks are on
            //      then purge L3 and stop the l3 clocks
            //  Power off the core and L3
            if( l_cl2_pfet_sense)
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
            }

            if (l_l3_pfet_sense)
            {
                if (!l_l3_clock_State)
                {
                    FAPI_TRY(p10_hcd_chtm_purge(i_core_target));

                    FAPI_IMP("Assert CINJ_LCO_DIS_CFG via L3_MISC_L3CERRS_MODE_REG1[38]");
                    FAPI_TRY(fapi2::getScom(i_core_target, L3_MISC_L3CERRS_MODE_REG1, l_data));
                    l_data.setBit(38);
                    FAPI_TRY(fapi2::putScom(i_core_target, L3_MISC_L3CERRS_MODE_REG1, l_data));

                    FAPI_TRY(p10_hcd_l3_purge(i_core_target));
                    FAPI_TRY(p10_hcd_powerbus_purge(i_core_target));
                    FAPI_TRY(p10_hcd_cache_stopclocks(i_core_target));
                }

                FAPI_TRY(p10_hcd_cache_poweroff(i_core_target));
            }
        }

        //Restore the original values
        FAPI_TRY(fapi2::putScom(l_eq_target, CPLT_CTRL3_WO_CLEAR, l_pscom_pg_config));
        FAPI_TRY(fapi2::putScom(l_eq_target, CPLT_CTRL2_WO_CLEAR, l_pscom_pg_config));

#ifdef __HOSTBOOT_MODULE

        if (! Util::isSimicsRunning())
        {
#endif
            FAPI_TRY(clear_atomic_lock(i_core_target, l_lockId));
#ifdef __HOSTBOOT_MODULE
        }

#endif
    }
    while(0);

fapi_try_exit:
    FAPI_INF("< p10_check_core_clock_power_state...");
    return fapi2::current_err;

}


fapi2::ReturnCode set_atomic_lock(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    uint32_t& o_lock_id)
{
    fapi2::buffer<uint64_t> l_data = 0;
    fapi2::buffer<uint64_t> l_buf = 0;
    fapi2::ReturnCode l_rc;

    auto l_eq_target = i_core_target.getParent<fapi2::TARGET_TYPE_EQ>();

    //Grab the lock
    FAPI_TRY(GET_CTRL_ATOMIC_LOCK_REG(l_eq_target, l_data));
    SET_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE(l_data);
    l_rc = PUT_CTRL_ATOMIC_LOCK_REG(l_eq_target, l_data);

    if ( l_rc) //Resource busy
    {
        for (auto i = 0  ; i < 50; i++)
        {
            fapi2::delay(10000000, 10); //10ms
            l_rc = PUT_CTRL_ATOMIC_LOCK_REG(l_eq_target, l_data);

            if (l_rc == fapi2::FAPI2_RC_SUCCESS)
            {
                break;
            }
        }

        if (l_rc)
        {
            FAPI_ASSERT(false,
                        fapi2::SET_ATOMIC_LOCK_BUSY()
                        .set_CORE_TARGET(i_core_target)
                        .set_CTRL_ATOMIC_LOCK_REG(l_data),
                        "Update ec: atomic lock access error");
        }
    }
    else if (l_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_TRY(GET_CTRL_ATOMIC_LOCK_REG(l_eq_target, l_data));
        GET_CTRL_ATOMIC_LOCK_REG_ID(l_data, l_buf);

        if (!GET_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE(l_data)  ||
            (l_buf != 0x9 && l_buf != 0x2 && l_buf != 0xE)) //hostboot Id/FSI2PIB/SBE
        {
            FAPI_ASSERT(false,
                        fapi2::SET_ATOMIC_LOCK_FAIL()
                        .set_CORE_TARGET(i_core_target)
                        .set_CTRL_ATOMIC_LOCK_REG(l_data),
                        "Update ec: couldn't grab atomic lock");
        }
    }

    o_lock_id = l_buf;

fapi_try_exit:
    FAPI_INF("< set_atomic_lock...");
    return fapi2::current_err;
}
fapi2::ReturnCode clear_atomic_lock(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    const uint32_t i_lockId)
{
    fapi2::buffer<uint64_t> l_data = 0;
    fapi2::buffer<uint64_t> l_buf = 0;
    fapi2::ReturnCode l_rc;

    auto l_eq_target = i_core_target.getParent<fapi2::TARGET_TYPE_EQ>();
    //Clear the lock
    FAPI_TRY(GET_CTRL_ATOMIC_LOCK_REG(l_eq_target, l_data));
    GET_CTRL_ATOMIC_LOCK_REG_ID(l_data, l_buf);

    if ( i_lockId == l_buf)
    {
        l_data.flush<0>();
        FAPI_TRY(PUT_CTRL_ATOMIC_LOCK_REG(l_eq_target, l_data));
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::ATOMIC_LOCK_OWNER_ID_INVALID()
                    .set_CORE_TARGET(i_core_target)
                    .set_ACTUAL_LOCK_ID(l_buf)
                    .set_EXPECTED_LOCK_ID(i_lockId),
                    ": atomic lock access error");
    }

fapi_try_exit:
    FAPI_INF("< p10_check_core_clock_power_state...");
    return fapi2::current_err;
}


fapi2::ReturnCode clear_spwu_done(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target)
{
    fapi2::buffer<uint64_t> l_data = 0;
    //There is a chance of this core is activated during istep 4, and in
    //istep 4 spwu is asserted, so we need to deassert before QME boots
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_core_target, QME_SPWU_OTR, l_data));
    FAPI_TRY(fapi2::putScom(i_core_target, QME_SPWU_HYP, l_data));
    FAPI_TRY(fapi2::putScom(i_core_target, QME_SPWU_FSP, l_data));
    FAPI_TRY(fapi2::putScom(i_core_target, QME_SPWU_OCC, l_data));


fapi_try_exit:
    FAPI_INF("< clear_spw_done...");
    return fapi2::current_err;
}
