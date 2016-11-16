/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_common_funcs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
///
/// @file cen_common_funcs.C
/// @brief Common functions for centaur fapi2 procedures.
///
/// @author Peng Fei GOU <shgoupf@cn.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 2
// *HWP Consumed by: HB
//

#include <cen_common_funcs.H>

bool is_multicast_write(const uint64_t i_chiplet_id)
{
    return ((i_chiplet_id & MULTI_CAST_PATTERN) == MULTI_CAST_COMPARE);
}

uint64_t get_multicast_read_or(const uint64_t i_chiplet_id)
{
    return (i_chiplet_id & MULTI_CAST_READ_OP);
}

uint64_t get_multicast_read_and(const uint64_t i_chiplet_id)
{
    return (i_chiplet_id & MULTI_CAST_WAIT_WR);
}

uint64_t get_scom_addr(const uint64_t i_chiplet_id, const uint64_t i_generic_addr)
{
    // chiplet id should be put to bit 32:39 of a uint64_t.
    // For example:
    // chiplet_id   = 0x00000000_00000001;
    // generic_addr = 0x00000000_00030030;
    // scom_addr    = 0x00000000_01030030;
    return ((i_chiplet_id << 24) | i_generic_addr);
}

fapi2::ReturnCode
cen_scan0_module(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                 const uint64_t i_chiplet_id, const uint64_t i_clk_region_data,
                 const uint64_t i_clk_scansel_data)
{

    fapi2::buffer<uint64_t> l_opcg_cntl0_data = 0;
    fapi2::buffer<uint64_t> l_gp1_data = 0;
    fapi2::buffer<uint64_t> l_clk_region_data = i_clk_region_data;
    fapi2::buffer<uint64_t> l_clk_scansel_data = i_clk_scansel_data;
    uint64_t l_clk_region_addr = get_scom_addr(i_chiplet_id, CEN_GENERIC_CLK_REGION);
    uint64_t l_clk_scansel_addr = get_scom_addr(i_chiplet_id, CEN_GENERIC_CLK_SCANSEL);
    uint64_t l_opcg_cntl0_addr = get_scom_addr(i_chiplet_id, CEN_GENERIC_OPCG_CNTL0);
    uint64_t l_gp1_addr_multi_cast = 0;
    uint64_t l_multicast_read_and = i_chiplet_id;
    bool l_poll_succeed = false;

    FAPI_INF("Start");
    FAPI_DBG("Setting up Clock Regions and Scan Selects");
    FAPI_TRY(fapi2::putScom(i_target, l_clk_region_addr, l_clk_region_data));
    FAPI_TRY(fapi2::putScom(i_target, l_clk_scansel_addr, l_clk_scansel_data));

    FAPI_DBG("Clear OPCG_CNTL0 REG BIT(0)");
    FAPI_TRY(fapi2::getScom(i_target, l_opcg_cntl0_addr, l_opcg_cntl0_data));
    l_opcg_cntl0_data.clearBit<0>();
    FAPI_TRY(fapi2::putScom(i_target, l_opcg_cntl0_addr, l_opcg_cntl0_data));

    // If chiplet_id is a multicast write group,
    // set l_multicast_read_and to the matching AND-combine
    // read group, otherwise simply set l_multicast_read_and = i_chiplet_id.
    if (is_multicast_write(i_chiplet_id))
    {
        FAPI_DBG("*INFO* This is a multicast SCAN0 *INFO* ");
        FAPI_DBG("Setting OPCG_CNTL0 run BIT(2) for scan0 to start, also set scan ratio to 16:1, set INOP alignment to 4:1");
        l_multicast_read_and = get_multicast_read_and(i_chiplet_id);

        l_opcg_cntl0_data.setBit<2>().setBit<5, 4>().setBit<12, 2>();
    }
    else   //cen_osm_start
    {
        FAPI_DBG("Setting OPCG_CNTL0 run BIT(2) for scan0 to start");
        l_opcg_cntl0_data.setBit<2>();
    }

    FAPI_TRY(fapi2::putScom(i_target, l_opcg_cntl0_addr, l_opcg_cntl0_data));

    //cen_osm_poll
    FAPI_DBG("Start polling for SCAN0 complete ...");

    l_gp1_addr_multi_cast = get_scom_addr(l_multicast_read_and, CEN_GENERIC_GP1);

    for (uint32_t i = 0; i < MAX_FLUSH_LOOPS; i++)
    {
        FAPI_TRY(fapi2::getScom(i_target, l_gp1_addr_multi_cast, l_gp1_data));

        FAPI_DBG( "Polling... OPCG done bit (15)." );

        if (l_gp1_data.getBit<15>())
        {
            l_poll_succeed = true;
            break;
        }

        FAPI_TRY(fapi2::delay(NANO_FLUSH_DELAY, SIM_FLUSH_DELAY));
    }

    FAPI_ASSERT(l_poll_succeed,
                fapi2::CEN_COMMON_SCAN0_POLL_OPCG_DONE_TIMEOUT().
                set_TARGET(i_target),
                "ERROR: Gave up waiting for OPCG done bit(15)='1'.");

    FAPI_DBG("SCAN0 completed, clear Clock Regions and Scan Selects");
    l_clk_region_data.flush<0>();  //clear to all-zero
    FAPI_TRY(fapi2::putScom(i_target, l_clk_region_addr, l_clk_region_data));
    l_clk_scansel_data.flush<0>();    //clear to all-zero
    FAPI_TRY(fapi2::putScom(i_target, l_clk_scansel_addr, l_clk_scansel_data))

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

fapi2::ReturnCode
cen_arrayinit_module(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                     const uint64_t i_chiplet_id, const uint64_t i_clock_region)
{
    FAPI_INF("Start");
    fapi2::buffer<uint64_t> l_gp0_data = 0;
    fapi2::buffer<uint64_t> l_gp1_data = 0;
    fapi2::buffer<uint64_t> l_opcg_cntl0_data = 0;
    fapi2::buffer<uint64_t> l_opcg_cntl2_data = 0;
    uint64_t l_gp0_addr_and = get_scom_addr(i_chiplet_id, CEN_GENERIC_GP0_AND);
    uint64_t l_gp0_addr_or = get_scom_addr(i_chiplet_id, CEN_GENERIC_GP0_OR);
    uint64_t l_gp1_addr_multi_cast = 0;
    uint64_t l_clk_region_addr = get_scom_addr(i_chiplet_id, CEN_GENERIC_CLK_REGION);
    uint64_t l_opcg_cntl0_addr = get_scom_addr(i_chiplet_id, CEN_GENERIC_OPCG_CNTL0);
    uint64_t l_opcg_cntl0_addr_multi_cast = 0;
    uint64_t l_opcg_cntl2_addr = get_scom_addr(i_chiplet_id, CEN_GENERIC_OPCG_CNTL2);
    uint64_t l_opcg_cntl2_addr_multi_cast = 0;
    uint64_t l_multicast_read_or = i_chiplet_id;
    uint64_t l_multicast_read_and = i_chiplet_id;
    bool l_poll_succeed = false;

    // If chiplet_id is a multicast write group,
    // set l_multicast_read_or to the matching OR-combine
    // read group, otherwise simply set l_multicast_read_or = i_chiplet_id.
    // If chiplet_id is a multicast write group,
    // set l_multicast_read_and to the matching AND-combine
    // read group, otherwise simply set l_multicast_read_and = i_chiplet_id.
    if (is_multicast_write(i_chiplet_id))
    {
        FAPI_DBG("*INFO* This is a multicast ARRAY INIT *INFO*");
        l_multicast_read_or = get_multicast_read_or(i_chiplet_id);
        l_multicast_read_and = get_multicast_read_and(i_chiplet_id);
    }

    FAPI_DBG("Drop Pervasive Fence");
    l_gp0_data.setBit<63>().invert();
    FAPI_TRY(fapi2::putScom(i_target, l_gp0_addr_and, l_gp0_data));

    FAPI_DBG("Setup ABISTMUX_SEL, ABIST mode and ABIST mode2");
    l_gp0_data = 0;
    l_gp0_data.setBit<0>().setBit<11>().setBit<13>();
    FAPI_TRY(fapi2::putScom(i_target, l_gp0_addr_or, l_gp0_data));

    FAPI_DBG("Setup all Clock Domains and Clock Types");
    FAPI_TRY(fapi2::putScom(i_target, l_clk_region_addr, i_clock_region));

    FAPI_DBG("Setup loopcount and run-N mode");
    l_opcg_cntl0_addr_multi_cast = get_scom_addr(l_multicast_read_or, CEN_GENERIC_OPCG_CNTL0);
    FAPI_TRY(fapi2::getScom(i_target, l_opcg_cntl0_addr_multi_cast, l_opcg_cntl0_data));
    // And with mask bit(0:20), starting from bit 0, totally 21 bits.
    l_opcg_cntl0_data &= fapi2::buffer<uint64_t>().setBit<0, 21>();
    l_opcg_cntl0_data |= 0x80000000000412D0;
    FAPI_TRY(fapi2::putScom(i_target, l_opcg_cntl0_addr, l_opcg_cntl0_data));

    FAPI_DBG("Setup IDLE count and OPCG engine start ABIST");
    l_opcg_cntl2_addr_multi_cast = get_scom_addr(l_multicast_read_or, CEN_GENERIC_OPCG_CNTL2);
    FAPI_TRY(fapi2::getScom(i_target, l_opcg_cntl2_addr_multi_cast, l_opcg_cntl2_data));
    // And with mask bit(36:63), starting from bit 36, totally 28 bits.
    l_opcg_cntl2_data &= fapi2::buffer<uint64_t>().setBit<36, 28>();
    l_opcg_cntl2_data |= 0x00000000F0007200;
    FAPI_TRY(fapi2::putScom(i_target, l_opcg_cntl2_addr, l_opcg_cntl2_data));

    FAPI_DBG("Issue Clock Start: Write OPCG CTL0 Register");
    FAPI_TRY(fapi2::getScom(i_target, l_opcg_cntl0_addr_multi_cast, l_opcg_cntl0_data));
    l_opcg_cntl0_data |= fapi2::buffer<uint64_t>().setBit<1>();
    FAPI_TRY(fapi2::putScom(i_target, l_opcg_cntl0_addr, l_opcg_cntl0_data));

    FAPI_DBG("Poll for OPCG done bit");
    l_gp1_addr_multi_cast = get_scom_addr(l_multicast_read_and, CEN_GENERIC_GP1);

    for (uint32_t i = 0; i < MAX_FLUSH_LOOPS; i++)
    {
        FAPI_TRY(fapi2::getScom(i_target, l_gp1_addr_multi_cast, l_gp1_data));

        FAPI_DBG( "Polling... OPCG done bit (15)." );

        if (l_gp1_data.getBit<15>())
        {
            l_poll_succeed = true;
            break;
        }

        FAPI_TRY(fapi2::delay(NANO_FLUSH_DELAY, SIM_FLUSH_DELAY));
    }

    FAPI_ASSERT(l_poll_succeed,
                fapi2::CEN_COMMON_ARRAYINIT_POLL_OPCG_DONE_TIMEOUT().
                set_TARGET(i_target),
                "Centaur arrayinit module timed out polling for OPCG done!");

    FAPI_DBG("OPCG done, clear Run-N mode");
    l_opcg_cntl0_addr_multi_cast = get_scom_addr(l_multicast_read_and, CEN_GENERIC_OPCG_CNTL0);
    FAPI_TRY(fapi2::getScom(i_target, l_opcg_cntl0_addr_multi_cast, l_opcg_cntl0_data));
    l_opcg_cntl0_data &= 0x7FFFF80000000000;
    FAPI_TRY(fapi2::putScom(i_target, l_opcg_cntl0_addr, l_opcg_cntl0_data));

    FAPI_DBG("Clear ABISTMUX_SEL, ABIST mode, ABIST mode2 and set Pervasive Fence");
    l_gp0_data = 0;
    l_gp0_data.setBit<0>().setBit<11>().setBit<13>().invert();
    FAPI_TRY(fapi2::putScom(i_target, l_gp0_addr_and, l_gp0_data));
    l_gp0_data = 0;
    l_gp0_data.setBit<63>();
    FAPI_TRY(fapi2::putScom(i_target, l_gp0_addr_or, l_gp0_data));

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}

fapi2::ReturnCode
cen_repair_loader(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                  const uint64_t i_repair_cmd_validation_entry, const uint64_t i_repair_cmd_star_addr)
{
    fapi2::buffer<uint64_t> l_ecid_part1            ;
    fapi2::buffer<uint64_t> l_repair_status         ;
    fapi2::buffer<uint64_t> l_repair_ecc_trap       ;
    fapi2::buffer<uint64_t> l_repair_cmd_valid      = i_repair_cmd_validation_entry << 52;
    fapi2::buffer<uint64_t> l_repair_cmd_start_addr =
        ((i_repair_cmd_star_addr & 0xFFF) << 48) | 0x2000000000000000;

    uint64_t                temp_data_64;
    uint32_t                poll_cnt = MAX_REPAIR_POLL_LOOPS;

    FAPI_TRY(fapi2::getScom(i_target, CEN_OTPROM0_ECID_PART1_REGISTER_RO, l_ecid_part1));
    FAPI_TRY(l_ecid_part1.extract(temp_data_64, 0, 64));

    if (temp_data_64 != 0)
    {
        FAPI_DBG("Reading Status Register to verify engine is idle...");
        FAPI_TRY(fapi2::getScom(i_target, CEN_RLDCOMP_RLDLOG_STATUS_REGISTER_ROX, l_repair_status));
        FAPI_TRY(l_repair_status.extract(temp_data_64, 0, 64));

        FAPI_ASSERT(temp_data_64 != 0,
                    fapi2::CEN_COMMON_REPAIR_LOADER_BUSY().
                    set_TARGET(i_target),
                    "ERROR: Repair loader reports busy, but engine should be idle!");

        FAPI_DBG("Writing Command Validation Register");
        FAPI_TRY(fapi2::putScom(i_target, CEN_RLDCOMP_RLDLOG_CMDVAL_REGISTER, l_repair_cmd_valid));

        FAPI_DBG("Writing Command Register to start engine");
        FAPI_TRY(fapi2::putScom(i_target, CEN_RLDCOMP_RLDLOG_COMMAND_REGISTER, l_repair_cmd_start_addr));

        FAPI_DBG("Polling repair loader Status Register...");

        do
        {
            FAPI_TRY(fapi2::delay(NANO_FLUSH_DELAY, SIM_FLUSH_DELAY));
            FAPI_TRY(fapi2::getScom(i_target, CEN_RLDCOMP_RLDLOG_STATUS_REGISTER_ROX, l_repair_status));
            temp_data_64 = l_repair_status & REPAIR_STATUS_POLL_MASK;
            poll_cnt--;
        }
        while(((temp_data_64 == REPAIR_STATUS_POLL_BUSY1)
               || (temp_data_64 == REPAIR_STATUS_POLL_BUSY2))
              && (poll_cnt > 0));

        FAPI_ASSERT(poll_cnt > 0,
                    fapi2::CEN_COMMON_REPAIR_LOADER_TIMEOUT().
                    set_TARGET(i_target),
                    "Centaur repair loader timed out!");

        FAPI_INF("Checking repair loader status...");
        FAPI_INF("  BUSY             = 0b%d", l_repair_status.getBit<0>());
        FAPI_INF("  REPAIR DONE      = 0b%d", l_repair_status.getBit<2>());
        FAPI_INF("  PIB PARITY CHECK = 0b%d", l_repair_status.getBit<5>());
        FAPI_INF("  FSM ERROR        = 0b%d", l_repair_status.getBit<6>());
        FAPI_INF("  ECC ERROR        = 0b%d", l_repair_status.getBit<7>());
        FAPI_INF("  FSM STATE        = 0x%04llX", l_repair_status.getBit<8, 14>());

        FAPI_TRY(l_repair_status.extract(temp_data_64, 0, 64));

        temp_data_64 = l_repair_status & REPAIR_STATUS_CHECK_MASK;
        FAPI_ASSERT(temp_data_64 == REPAIR_STATUS_CHECK_EXP,
                    fapi2::CEN_COMMON_MISMATCH_IN_EXPECTED_REPAIR_LOADER_STATUS().
                    set_TARGET(i_target),
                    "Mismatch in expected repair loader status!"
                    " Expected: 0x%016llX, actual: 0x%016llX",
                    REPAIR_STATUS_CHECK_EXP, temp_data_64);

        FAPI_TRY(fapi2::getScom(i_target, CEN_RLDCOMP_RLDLOG_ECCTRAP_REGISTER_ROX, l_repair_ecc_trap));
        FAPI_INF("Checking ECC Trap Register status...");
        FAPI_INF("  CE NUMBER              = 0x%01llX", l_repair_ecc_trap.getBit<0, 4>());
        FAPI_INF("  UE NUMBER              = 0x%01llX", l_repair_ecc_trap.getBit<4, 4>());
        FAPI_INF("  FIRST ERR SYNDROME     = 0x%02llX", l_repair_ecc_trap.getBit<9, 7>());
        FAPI_INF("  ECC DATA CORRECTION EN = 0b%d"    , l_repair_ecc_trap.getBit<18>());
        FAPI_INF("  ADDRESS CHECKING EN    = 0b%d"    , l_repair_ecc_trap.getBit<19>());
        FAPI_INF("  FIRST ERR ADDRESS      = 0x%03llX", l_repair_ecc_trap.getBit<22, 10>());

        FAPI_TRY(l_repair_ecc_trap.extract(temp_data_64, 0, 64));

        temp_data_64 &= REPAIR_ECC_TRAP_MASK;
        FAPI_ASSERT(temp_data_64 == REPAIR_ECC_TRAP_EXP,
                    fapi2::CEN_COMMON_ECC_TRAP_REG_ERROR().
                    set_TARGET(i_target),
                    "ECC trap register reported error!"
                    " Expected: 0x%016llX, actual: 0x%016llX",
                    REPAIR_ECC_TRAP_EXP, temp_data_64);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


fapi2::ReturnCode
cen_startclocks_module(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                       const uint64_t i_chiplet_id)
{
    uint64_t l_gp3_and_addr     = get_scom_addr(i_chiplet_id, CEN_GENERIC_GP3_AND    );
    uint64_t l_gp3_or_addr      = get_scom_addr(i_chiplet_id, CEN_GENERIC_GP3_OR     );
    uint64_t l_gp0_and_addr     = get_scom_addr(i_chiplet_id, CEN_GENERIC_GP0_AND    );
    uint64_t l_gp0_or_addr      = get_scom_addr(i_chiplet_id, CEN_GENERIC_GP0_OR     );
    uint64_t l_clk_region_addr  = get_scom_addr(i_chiplet_id, CEN_GENERIC_CLK_REGION );
    uint64_t l_clk_scansel_addr = get_scom_addr(i_chiplet_id, CEN_GENERIC_CLK_SCANSEL);
    uint64_t l_clk_status_addr  = get_scom_addr(i_chiplet_id, CEN_GENERIC_CLK_STATUS );
    uint64_t temp_data_64 = 0;

    fapi2::buffer<uint64_t> reg_data_64;
    fapi2::buffer<uint32_t> reg_data_32;

    FAPI_DBG("Start clocks... ");
    FAPI_DBG("GP3 Reg: Clear bit(18) to drop chiplet fences.");
    reg_data_64.flush<1>().clearBit<18>();
    FAPI_TRY(fapi2::putScom(i_target, l_gp3_and_addr, reg_data_64),
             "Error from putScom (GP3_AND) ");

    FAPI_DBG("GP3 Reg: Set bit(28) to enable EDRAM.");
    reg_data_64.flush<0>().setBit<28>();
    FAPI_TRY(fapi2::putScom(i_target, l_gp3_or_addr, reg_data_64),
             "Error from putScom (GP3_OR) ");

    FAPI_DBG("GP0 Reg: clear bit(63) to drop perv fences.");
    FAPI_DBG("GP0 Reg: clear bits(0:1) to reset abstclk_muxsel, synclk_muxsel.");
    reg_data_64.flush<1>().clearBit<0, 2>().clearBit<63>();
    FAPI_TRY(fapi2::putScom(i_target, l_gp0_and_addr, reg_data_64),
             "Error from putScom (GP0_AND) ");

    if (i_chiplet_id == SCAN_CHIPLET_MEM)
    {
        FAPI_DBG("Writing GP0 OR mask to set abist_mode_dc (bit 11) ...");
        reg_data_64.flush<0>().setBit<11>();
        FAPI_TRY(fapi2::putScom(i_target, l_gp0_or_addr, reg_data_64),
                 "Error from putScom (GP0_OR) ");
    }

    FAPI_DBG("Clear Scan Region Reg prior to clock start.");
    reg_data_64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, l_clk_scansel_addr, reg_data_64),
             "Error from putScom (CLK_SCANSEL) ");

    FAPI_DBG("Clock start cmd for array and nsl tholds.");
    reg_data_64 = STRT_CLK_REGION_NSL;
    FAPI_TRY(fapi2::putScom(i_target, l_clk_region_addr, reg_data_64),
             "Error from putScom (CLK_REGION) ");

    FAPI_DBG("Clock start cmd for sl tholds.");
    reg_data_64 = STRT_CLK_REGION_SL;
    FAPI_TRY(fapi2::putScom(i_target, l_clk_region_addr, reg_data_64),
             "Error from putScom (CLK_REGION) ");

    reg_data_64.flush<0>();
    FAPI_DBG("Check status of THOLDs. ");
    FAPI_TRY(fapi2::getScom(i_target, l_clk_status_addr, reg_data_64),
             "Error from getScom (CLK_STATUS) ");

    FAPI_TRY(reg_data_64.extract(temp_data_64, 0, 64));
    FAPI_ASSERT((temp_data_64 == EXPECTED_CLK_STATUS),
                fapi2::CEN_COMMON_STARTCLOCKS_CLK_THOLDS_CHECK_ERR().
                set_TARGET(i_target).
                set_CHIPLET(i_chiplet_id).
                set_ACTUAL(temp_data_64),
                "Tholds aren't low after clock start, status: 0x%016llX!",
                temp_data_64);

    if (i_chiplet_id == SCAN_CHIPLET_NEST)
    {
        FAPI_DBG("GP0 Reg: clear bit(19) to clear edram_fence.");
        reg_data_64.flush<1>().clearBit<19>();
        FAPI_TRY(fapi2::putScom(i_target, l_gp0_and_addr, reg_data_64),
                 "Error from putScom (GP0_AND) ");
    }

    FAPI_DBG("GP0 Reg: clear bit(3) to clear force_align.");
    reg_data_64.flush<1>().clearBit<3>();
    FAPI_TRY(fapi2::putScom(i_target, l_gp0_and_addr, reg_data_64),
             "Error from putScom (GP0_AND) ");

    FAPI_DBG("GP0 Reg: clear bit(2) to clear flushmode_inhibit.");
    reg_data_64.flush<1>().clearBit<2>();
    FAPI_TRY(fapi2::putScom(i_target, l_gp0_and_addr, reg_data_64),
             "Error from putScom (GP0_AND) ");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

