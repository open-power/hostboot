/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_perv_mod_misc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
//------------------------------------------------------------------------------
/// @file  poz_perv_mod_misc.C
/// @brief Miscellaneous module definitions
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Sreekanth Reddy (skadapal@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#include <poz_perv_mod_misc.H>
#include <poz_perv_utils.H>
#include <poz_perv_mod_misc_regs.H>
#include <target_filters.H>

using namespace fapi2;

enum POZ_PERV_MOD_MISC_Private_Constants
{
    DELAY_10us = 10000,      // unit in nano seconds
    SIM_CYCLE_DELAY = 1000, // unit in cycles
    CFAM_CBS_POLL_COUNT = 200, // Observed Number of times CBS read for CBS_INTERNAL_STATE_VECTOR
    CBS_IDLE_VALUE = 0x002, // Read the value of CBS_CS_INTERNAL_STATE_VECTOR
    CBS_IDLE_HW_NS_DELAY = 640000, // unit is nano seconds [min : 64k x (1/100MHz) = 64k x 10(-8) = 640 us
    //                       max : 64k x (1/50MHz) = 128k x 10(-8) = 1280 us]
    CBS_IDLE_SIM_CYCLE_DELAY = 750000, // unit is sim cycles,to match the poll count change ( 250000 * 30 )
    MC_GROUP_MEMBERSHIP_BITX_READ = 0x500F0001,
    PCB_RESPONDER_MCAST_GROUP_1 = 0xF0001,
    HOST_MASK_REG_IPOLL_MASK = 0xF800000000000000,
    XSTOP1_INIT_VALUE = 0x97FFE00000000000,
    PGOOD_REGIONS_STARTBIT = 4,
    PGOOD_REGIONS_LENGTH = 15,
    PGOOD_REGIONS_OFFSET = 12,

    LFIR_MASK_DEFAULT = 0x80dfffffffffffff,
    TP_LFIR_MASK_DEFAULT = 0x80c1c7fcf3fbffff,
    XSTOP_MASK_ANY_ATTN_AND_DBG = 0x3000000000000000,
    RECOV_MASK_LOCAL_XSTOP = 0x2000000000000000,
};

ReturnCode mod_cbs_start_prep(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    bool i_start_sbe,
    bool i_scan0_clockstart)
{
    ROOT_CTRL0_t ROOT_CTRL0;
    ROOT_CTRL1_t ROOT_CTRL1;
    CBS_ENVSTAT_t CBS_ENVSTAT;
    ROOT_CTRL0_COPY_t ROOT_CTRL0_COPY;
    ROOT_CTRL1_COPY_t ROOT_CTRL1_COPY;
    CBS_CS_t CBS_CS;
    SBE_FIFO_FSB_DOWNFIFO_RESET_t FSB_DOWNFIFO_RESET;
    FSI2PIB_STATUS_t FSI2PIB_STATUS;
    SB_MSG_t SB_MSG;
    SB_CS_t SB_CS;

    FAPI_INF("Drop CFAM protection 0 to ungate VDN_PRESENT");
    FAPI_TRY(ROOT_CTRL0.getCfam(i_target));
    ROOT_CTRL0.set_CFAM_PROTECTION_0(0);
    FAPI_TRY(ROOT_CTRL0.putCfam(i_target));
    // not using putCfam_CLEAR scope here since the same value needs to be written into COPY

    ROOT_CTRL0_COPY = ROOT_CTRL0;
    FAPI_TRY(ROOT_CTRL0_COPY.putCfam(i_target));

    FAPI_INF("Read FSI2PIB_STATUS register and check whether VDN power is on or not(VDD_NEST_OBSERVE).");
    FAPI_TRY(FSI2PIB_STATUS.getCfam(i_target));
    FAPI_ASSERT(FSI2PIB_STATUS.get_VDD_NEST_OBSERVE(),
                fapi2::POZ_VDN_POWER_NOT_ON()
                .set_FSI2PIB_STATUS_READ(FSI2PIB_STATUS)
                .set_PROC_TARGET(i_target),
                "ERROR: VDN power is NOT on. i.e. FSI2PIB_STATUS register bit 16 is NOT set.");

    FAPI_INF("Clear Selfboot Message Register, clear SBE start bit, reset SBE FIFO.");
    SB_MSG = 0;
    FAPI_TRY(SB_MSG.putCfam(i_target));

    FAPI_TRY(SB_CS.getCfam(i_target));
    SB_CS.set_START_RESTART_VECTOR0(0);
    SB_CS.set_START_RESTART_VECTOR1(0);
    FAPI_TRY(SB_CS.putCfam(i_target));

    FSB_DOWNFIFO_RESET = 0x80000000;
    FAPI_TRY(FSB_DOWNFIFO_RESET.putCfam(i_target));

    FAPI_INF("Read CBS_ENVSTAT register to check the status of TEST_ENABLE C4 pin");
    FAPI_TRY(CBS_ENVSTAT.getCfam(i_target));

    if (CBS_ENVSTAT.get_CBS_ENVSTAT_C4_TEST_ENABLE())
    {
        FAPI_INF("Test mode, enable TP drivers/receivers for GSD scan out");
        ROOT_CTRL1 = 0;
        ROOT_CTRL1.set_TP_RI_DC_N(1);
        ROOT_CTRL1.set_TP_DI2_DC_N(1);
        FAPI_TRY(ROOT_CTRL1.putCfam_SET(i_target));

        // Don't forget the copy reg
        FAPI_TRY(ROOT_CTRL1_COPY.getCfam(i_target));
        ROOT_CTRL1_COPY.setBit(FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_N);
        ROOT_CTRL1_COPY.setBit(FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_N);
        FAPI_TRY(ROOT_CTRL1_COPY.putCfam(i_target));
    }

    FAPI_INF("Prepare for CBS start.");
    FAPI_TRY(CBS_CS.getCfam(i_target));
    CBS_CS.set_START_BOOT_SEQUENCER(0);
    CBS_CS.set_OPTION_SKIP_SCAN0_CLOCKSTART(not i_scan0_clockstart);
    CBS_CS.set_OPTION_PREVENT_SBE_START(not i_start_sbe);
    FAPI_TRY(CBS_CS.putCfam(i_target));

fapi_try_exit:
    return current_err;
}

ReturnCode mod_cbs_start(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    bool i_start_sbe,
    bool i_scan0_clockstart)
{
    CBS_CS_t CBS_CS;
    int l_timeout = 0;

    FAPI_INF("Entering ...");

    FAPI_TRY(mod_cbs_start_prep(i_target, i_start_sbe, i_scan0_clockstart));

    FAPI_INF("Start CBS.");
    FAPI_TRY(CBS_CS.getCfam(i_target));
    CBS_CS.set_START_BOOT_SEQUENCER(1);
    FAPI_TRY(CBS_CS.putCfam(i_target));
    // Leave START_BOOT_SEQUENCER at 1 to prevent accidental restarts

    FAPI_DBG("Monitor CBS_CS INTERNAL_STATE_VECTOR to know current state of CBS state machine.");
    l_timeout = CFAM_CBS_POLL_COUNT;

    while (l_timeout != 0)
    {
        FAPI_TRY(CBS_CS.getCfam(i_target));

        if (CBS_CS.get_INTERNAL_STATE_VECTOR() == CBS_IDLE_VALUE)
        {
            break;
        }

        FAPI_TRY(fapi2::delay(CBS_IDLE_HW_NS_DELAY, CBS_IDLE_SIM_CYCLE_DELAY));
        --l_timeout;
    }

    FAPI_DBG("Loop Count :%d", l_timeout);

    // Finding the clock used for starting CBS. TODO
    //FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_REFCLOCK_SELECT, i_target_chip, l_cp_refclck_select));

    FAPI_ASSERT(l_timeout > 0,
                fapi2::POZ_CBS_NOT_IN_IDLE_STATE()
                .set_CBS_CS_READ(CBS_CS)
                .set_CBS_CS_IDLE_VALUE(CBS_IDLE_VALUE)
                .set_LOOP_COUNT(CFAM_CBS_POLL_COUNT)
                .set_HW_DELAY(CBS_IDLE_HW_NS_DELAY)
                .set_PROC_TARGET(i_target),
                //.set_CLOCK_POS(l_callout_clock),
                "ERROR: CBS HAS NOT REACHED IDLE STATE VALUE 0x002 ");

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}

ReturnCode mod_switch_pcbmux(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    mux_type i_path)
{
    ROOT_CTRL0_t ROOT_CTRL0;
    uint8_t l_oob_mux_save = 0;

    FAPI_INF("Entering ...");
    FAPI_DBG("Save OOB Mux setting.");
    FAPI_TRY(ROOT_CTRL0.getScom(i_target));
    l_oob_mux_save = ROOT_CTRL0.get_OOB_MUX();

    FAPI_DBG("Raise OOB Mux.");
    ROOT_CTRL0 = 0;
    ROOT_CTRL0.set_OOB_MUX(1);
    FAPI_TRY(ROOT_CTRL0.putScom_SET(i_target));

    FAPI_DBG("Set PCB_RESET bit in ROOT_CTRL0 register.");
    ROOT_CTRL0 = 0;
    ROOT_CTRL0.set_PCB_RESET(1);
    FAPI_TRY(ROOT_CTRL0.putScom_SET(i_target));

    FAPI_DBG("Enable the new path first to prevent glitches.");
    ROOT_CTRL0 = 0;
    FAPI_TRY(ROOT_CTRL0.setBit(i_path));
    FAPI_TRY(ROOT_CTRL0.putScom_SET(i_target));

    FAPI_DBG("Disable the old path.");
    ROOT_CTRL0 = 0;
    ROOT_CTRL0.set_FSI2PCB(1);
    ROOT_CTRL0.set_PIB2PCB(1);
    ROOT_CTRL0.set_PCB2PCB(1);
    FAPI_TRY(ROOT_CTRL0.clearBit(i_path));
    FAPI_TRY(ROOT_CTRL0.putScom_CLEAR(i_target));

    FAPI_DBG("Clear PCB_RESET.");
    ROOT_CTRL0 = 0;
    ROOT_CTRL0.set_PCB_RESET(1);
    FAPI_TRY(ROOT_CTRL0.putScom_CLEAR(i_target));

    if (l_oob_mux_save == 0)
    {
        FAPI_DBG("Restore OOB Mux setting.");
        ROOT_CTRL0 = 0;
        ROOT_CTRL0.set_OOB_MUX(1);
        FAPI_TRY(ROOT_CTRL0.putScom_CLEAR(i_target));
    }

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}

ReturnCode mod_switch_pcbmux_cfam(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    mux_type i_path)
{
    ROOT_CTRL0_t ROOT_CTRL0;
    uint8_t l_oob_mux_save = 0;

    FAPI_INF("Entering ...");
    FAPI_DBG("Save OOB Mux setting.");
    FAPI_TRY(ROOT_CTRL0.getCfam(i_target));
    l_oob_mux_save = ROOT_CTRL0.get_OOB_MUX();

    FAPI_DBG("Raise OOB Mux.");
    ROOT_CTRL0 = 0;
    ROOT_CTRL0.set_OOB_MUX(1);
    FAPI_TRY(ROOT_CTRL0.putCfam_SET(i_target));

    FAPI_DBG("Set PCB_RESET bit in ROOT_CTRL0 register.");
    ROOT_CTRL0 = 0;
    ROOT_CTRL0.set_PCB_RESET(1);
    FAPI_TRY(ROOT_CTRL0.putCfam_SET(i_target));

    FAPI_DBG("Enable the new path first to prevent glitches.");
    ROOT_CTRL0 = 0;
    FAPI_TRY(ROOT_CTRL0.setBit(i_path));
    FAPI_TRY(ROOT_CTRL0.putCfam_SET(i_target));

    FAPI_DBG("Disable the old path.");
    ROOT_CTRL0 = 0;
    ROOT_CTRL0.set_FSI2PCB(1);
    ROOT_CTRL0.set_PIB2PCB(1);
    ROOT_CTRL0.set_PCB2PCB(1);
    FAPI_TRY(ROOT_CTRL0.clearBit(i_path));
    FAPI_TRY(ROOT_CTRL0.putCfam_CLEAR(i_target));

    FAPI_DBG("Clear PCB_RESET.");
    ROOT_CTRL0 = 0;
    ROOT_CTRL0.set_PCB_RESET(1);
    FAPI_TRY(ROOT_CTRL0.putCfam_CLEAR(i_target));

    FAPI_DBG("Restore OOB Mux setting.");

    if (l_oob_mux_save == 0)
    {
        ROOT_CTRL0 = 0;
        ROOT_CTRL0.set_OOB_MUX(1);
        FAPI_TRY(ROOT_CTRL0.putCfam_CLEAR(i_target));
    }

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}

ReturnCode mod_multicast_setup(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    uint8_t i_group_id,
    uint64_t i_chiplets,
    TargetState i_pgood_policy)
{
    uint8_t l_group_id = i_group_id;
    fapi2::buffer<uint64_t> l_eligible_chiplets = 0;
    fapi2::buffer<uint64_t> l_required_group_members;
    fapi2::buffer<uint64_t> l_current_group_members;
    auto l_all_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_PERV>(i_pgood_policy);

    FAPI_INF("Entering ...");
    FAPI_ASSERT(!(i_group_id > 6),
                fapi2::POZ_INVALID_GROUP_ID()
                .set_GROUP_ID_VALUE(i_group_id)
                .set_PROC_TARGET(i_target),
                "ERROR: INVALID group id passed to module multicast setup.");

    FAPI_TRY(mod_multicast_setup_plat_remap(i_group_id, l_group_id));

    FAPI_INF("Determine required group members.");

    for (auto& targ : l_all_chiplets)
    {
        l_eligible_chiplets.setBit(targ.getChipletNumber());
    }

    l_required_group_members = l_eligible_chiplets & i_chiplets;
    FAPI_DBG("Required multicast group members : 0x%08X%08X",
             l_required_group_members >> 32, l_required_group_members & 0xFFFFFFFF);

    // MC_GROUP_MEMBERSHIP_BITX_READ = 0x500F0001
    // This performs a multicast read with the BITX merge operation.
    // It reads a register that has bit 0 tied to 1, so the return value
    // will have a 1 for each chiplet that is a member of the targeted group.
    FAPI_INF("Determine current group members");
    FAPI_TRY(fapi2::getScom(i_target, MC_GROUP_MEMBERSHIP_BITX_READ | ((uint32_t)l_group_id << 24),
                            l_current_group_members));
    FAPI_DBG("Current multicast group members : 0x%08X%08X",
             l_current_group_members >> 32, l_current_group_members & 0xFFFFFFFF);

    FAPI_INF("Update group membership where needed");

    for (int i = 0; i <= 63; i++)
    {
        const bool want = l_required_group_members.getBit(i);
        const bool have = l_current_group_members.getBit(i);

        if (want == have)
        {
            continue;
        }

        const uint64_t prev_group = have ? l_group_id : 7;
        const uint64_t new_group  = want ? l_group_id : 7;
        FAPI_TRY(fapi2::putScom(i_target, (PCB_RESPONDER_MCAST_GROUP_1 + l_group_id) | (i << 24),
                                (new_group << 58) | (prev_group << 42)));
    }

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}

ReturnCode mod_get_chiplet_by_number(
    const Target < TARGET_TYPE_PERV | TARGET_TYPE_ANY_POZ_CHIP > & i_target,
    uint8_t i_chiplet_number,
    Target < TARGET_TYPE_PERV >& o_target)
{
    auto l_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_PERV>();

    FAPI_INF("Entering ...");

    for (auto& chiplet : l_chiplets)
    {
        if (chiplet.getChipletNumber() == i_chiplet_number)
        {
            o_target = chiplet;
            return fapi2::FAPI2_RC_SUCCESS;
        }
    }

    FAPI_ASSERT(false,
                fapi2::POZ_CHIPLET_NOT_FOUND()
                .set_CHIPLET_NUMBER(i_chiplet_number)
                .set_PROC_TARGET(i_target),
                "ERROR: Provided chiplet number does not match anything in provided target.");

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}

ReturnCode mod_hangpulse_setup(const Target < TARGET_TYPE_PERV | TARGET_TYPE_MULTICAST > & i_target,
                               uint8_t i_pre_divider, const hang_pulse_t* i_hangpulse_table)
{
    HANG_PULSE_0_t HANG_PULSE_0;
    PRE_COUNTER_t PRE_COUNTER;

    FAPI_INF("Entering ...");
    FAPI_DBG("Set pre_divider value in pre_counter register.");
    PRE_COUNTER = 0;
    PRE_COUNTER.set_PRE_COUNTER(i_pre_divider);
    FAPI_TRY(PRE_COUNTER.putScom(i_target));

    while(1)
    {
        FAPI_DBG("Set frequency value for the hang pulse");
        HANG_PULSE_0 = 0;
        HANG_PULSE_0.set_HANG_PULSE_REG_0(i_hangpulse_table->value);
        HANG_PULSE_0.set_SUPPRESS_HANG_0(i_hangpulse_table->stop_on_xstop);
        FAPI_TRY(putScom(i_target, HANG_PULSE_0.addr + i_hangpulse_table->id, HANG_PULSE_0));

        if (i_hangpulse_table->last)
        {
            break;
        }

        i_hangpulse_table++;
    }

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}

ReturnCode mod_constant_hangpulse_setup(const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target, uint32_t i_base_address,
                                        const constant_hang_pulse_t i_hangpulses[4])
{
    PRE_COUNTER_t PRE_COUNTER;
    HANG_PULSE_0_t HANG_PULSE_0;

    FAPI_INF("Entering ...");

    for (int i = 0; i <= 3; i++)
    {
        PRE_COUNTER = 0;
        PRE_COUNTER.set_PRE_COUNTER(i_hangpulses[i].pre_divider);
        FAPI_TRY(putScom(i_target, i_base_address + i * 2 + 2, PRE_COUNTER));

        HANG_PULSE_0 = 0;
        HANG_PULSE_0.set_HANG_PULSE_REG_0(i_hangpulses[i].value);
        HANG_PULSE_0.set_SUPPRESS_HANG_0(i_hangpulses[i].stop_on_xstop);
        FAPI_TRY(putScom(i_target, i_base_address + i * 2 + 1, HANG_PULSE_0));
    }

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}

ReturnCode mod_poz_tp_init_common(const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target)
{
    INTR_HOST_MASK_t HOST_MASK;
    ROOT_CTRL0_t ROOT_CTRL0;
    PERV_CTRL0_t PERV_CTRL0;
    CPLT_CTRL0_t CPLT_CTRL0;
    CPLT_CTRL2_t CPLT_CTRL2;
    SB_CS_t SB_CS;

    fapi2::buffer<uint32_t> l_attr_pg;
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("Entering ...");
    fapi2::Target<fapi2::TARGET_TYPE_PERV> l_tpchiplet = get_tp_chiplet_target(i_target);

    FAPI_INF("Clear SBE start bits to be tidy");
    FAPI_TRY(SB_CS.getScom(i_target));
    SB_CS.set_START_RESTART_VECTOR0(0);
    SB_CS.set_START_RESTART_VECTOR1(0);
    FAPI_TRY(SB_CS.putScom(i_target));

    FAPI_INF("Clear CBS command to enable clock gating inside clock controller");
    ROOT_CTRL0 = 0;
    ROOT_CTRL0.set_FSI_CC_CBS_CMD(-1);
    FAPI_TRY(ROOT_CTRL0.putScom_CLEAR(i_target));

    FAPI_DBG("Set up IPOLL mask");
    HOST_MASK = HOST_MASK_REG_IPOLL_MASK;
    FAPI_TRY(HOST_MASK.putScom(i_target));

    FAPI_DBG("Transfer PERV partial good attribute into region good register (cplt_ctrl2 reg)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_tpchiplet, l_attr_pg));
    l_attr_pg.invert();
    l_data64.flush<0>();
    l_data64.insert< PGOOD_REGIONS_STARTBIT, PGOOD_REGIONS_LENGTH, PGOOD_REGIONS_OFFSET >(l_attr_pg);
    CPLT_CTRL2 = l_data64();
    FAPI_TRY(CPLT_CTRL2.putScom(l_tpchiplet));

    FAPI_DBG("Enable PERV vital clock gating");
    PERV_CTRL0 = 0;
    PERV_CTRL0.set_VITL_CG_DIS(1);
    FAPI_TRY(PERV_CTRL0.putScom_CLEAR(i_target));

    FAPI_DBG("Disable alignment pulse");
    CPLT_CTRL0.flush<0>();
    CPLT_CTRL0.set_FORCE_ALIGN(1);
    FAPI_TRY(CPLT_CTRL0.putScom_CLEAR(l_tpchiplet));

    FAPI_DBG("Unmask pervasive FIRs");
    FAPI_TRY(putScom(l_tpchiplet, EPS_MASK_RW_WCLEAR, ~TP_LFIR_MASK_DEFAULT));
    FAPI_TRY(putScom(l_tpchiplet, XSTOP_MASK_RW, XSTOP_MASK_ANY_ATTN_AND_DBG));
    FAPI_TRY(putScom(l_tpchiplet, RECOV_MASK_RW, RECOV_MASK_LOCAL_XSTOP));
    FAPI_TRY(putScom(l_tpchiplet, ATTN_MASK_RW, 0));
    FAPI_TRY(putScom(l_tpchiplet, LOCAL_XSTOP_MASK_RW, 0));

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}

ReturnCode mod_unmask_firs(const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target)
{
    auto l_chiplets_mc = i_target.getMulticast<TARGET_TYPE_PERV>(MCGROUP_GOOD_NO_TP);

    FAPI_INF("Entering ...");

    FAPI_DBG("Unmask chiplet FIRs");
    FAPI_TRY(putScom(l_chiplets_mc, EPS_MASK_RW_WCLEAR, ~LFIR_MASK_DEFAULT));
    FAPI_TRY(putScom(l_chiplets_mc, XSTOP_MASK_RW, XSTOP_MASK_ANY_ATTN_AND_DBG));
    FAPI_TRY(putScom(l_chiplets_mc, RECOV_MASK_RW, RECOV_MASK_LOCAL_XSTOP));
    FAPI_TRY(putScom(l_chiplets_mc, ATTN_MASK_RW, 0));
    FAPI_TRY(putScom(l_chiplets_mc, LOCAL_XSTOP_MASK_RW, 0));

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}

ReturnCode mod_setup_clockstop_on_xstop(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    const uint8_t i_chiplet_delays[64])
{
    XSTOP1_t XSTOP1;
    CLKSTOP_ON_XSTOP_MASK1_t EPS_CLKSTOP_ON_XSTOP_MASK1;
    fapi2::buffer<uint8_t>  l_clkstop_on_xstop;
    auto l_chiplets_mc   = i_target.getMulticast<TARGET_TYPE_PERV>(MCGROUP_GOOD_NO_TP);
    auto l_chiplets_uc   = l_chiplets_mc.getChildren<TARGET_TYPE_PERV>();

    FAPI_INF("Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCKSTOP_ON_XSTOP, i_target, l_clkstop_on_xstop));

    if (l_clkstop_on_xstop)
    {
        EPS_CLKSTOP_ON_XSTOP_MASK1.flush<1>();
        EPS_CLKSTOP_ON_XSTOP_MASK1.insert<0, 8>(l_clkstop_on_xstop);

        if (EPS_CLKSTOP_ON_XSTOP_MASK1.get_SYS_XSTOP_STAGED_ERR())
        {
            FAPI_DBG("Staged xstop is masked, leave all delays at 0 for fast stopping.");

            XSTOP1 = XSTOP1_INIT_VALUE;
            FAPI_TRY(XSTOP1.putScom(l_chiplets_mc));
        }
        else
        {
            FAPI_DBG("Staged xstop is unmasked, set up per-chiplet delays");

            for (auto& l_chiplet : l_chiplets_uc)
            {
                XSTOP1 = XSTOP1_INIT_VALUE;
                XSTOP1.set_WAIT_CYCLES(4 * (4 - i_chiplet_delays[l_chiplet.getChipletNumber()]));
                FAPI_TRY(XSTOP1.putScom(l_chiplet));
            }
        }

        FAPI_INF("Enable clockstop on checkstop");
        FAPI_TRY(EPS_CLKSTOP_ON_XSTOP_MASK1.putScom(l_chiplets_mc));
    }

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}
