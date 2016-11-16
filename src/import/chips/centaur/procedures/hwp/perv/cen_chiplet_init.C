/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_chiplet_init.C $ */
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
/// @file cen_chiplet_init.C
/// @brief: identify good chiplets MBA01, MBA23 (tbd)
///         define multicast groups
///         setup chiplet pervasive within the chiplets
///

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

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_chiplet_init.H>
#include <cen_common_funcs.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_chiplet_init(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_tp_mcgr1_data   = 0xE0001C0000000000;
    fapi2::buffer<uint64_t> l_tp_mcgr2_data   = 0xFC001C0000000000;
    fapi2::buffer<uint64_t> l_tp_mcgr3_data   = 0xFC001C0000000000;
    fapi2::buffer<uint64_t> l_tp_mcgr4_data   = 0xFC001C0000000000;
    fapi2::buffer<uint64_t> l_nest_mcgr1_data = 0xE0001C0000000000;
    fapi2::buffer<uint64_t> l_nest_mcgr2_data = 0xFC001C0000000000;
    fapi2::buffer<uint64_t> l_nest_mcgr3_data = 0xFC001C0000000000;
    fapi2::buffer<uint64_t> l_nest_mcgr4_data = 0xEC001C0000000000;
    fapi2::buffer<uint64_t> l_mem_mcgr1_data  = 0xE0001C0000000000;
    fapi2::buffer<uint64_t> l_mem_mcgr2_data  = 0xFC001C0000000000;
    fapi2::buffer<uint64_t> l_mem_mcgr3_data  = 0xFC001C0000000000;
    fapi2::buffer<uint64_t> l_mem_mcgr4_data  = 0xEC001C0000000000;
    fapi2::buffer<uint64_t> l_write_all_func_gp3_data = 0;
    fapi2::buffer<uint64_t> l_write_all_pcb_slave_errreg_data = ~0;
    fapi2::buffer<uint64_t> l_mem_gp0_data = 0;
    fapi2::buffer<uint64_t> l_ecid_part_1 = 0;
    fapi2::buffer<uint64_t> l_nest_clk_scansel_data = 0;
    fapi2::buffer<uint64_t> l_nest_clk_scandata0_data = 0;
    uint64_t l_nest_clk_scansel_addr = get_scom_addr(SCAN_CHIPLET_NEST, CEN_GENERIC_CLK_SCANSEL);
    uint64_t l_nest_clk_scandata0_addr = get_scom_addr(SCAN_CHIPLET_NEST, CEN_GENERIC_CLK_SCANDATA0);

    FAPI_DBG("*** Initialize good chiplets "
             "and setup multicast registers ***" );

    // Set up groups 0 and 3 multicast groups for Centaur
    // Multicast Group 0:   All functional chiplets (PRV NST MEM)
    // Multicast Group 3:   All functional chiplets, except PRV
    FAPI_DBG("Initializing multicast group0 (all) and "
             "group3 (all except PRV)");
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLPERV_MULTICAST_GROUP_1_PCB,   l_tp_mcgr1_data));
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLNEST_MULTICAST_GROUP_1_PCB, l_nest_mcgr1_data));
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLMEM_MULTICAST_GROUP_1_PCB,  l_mem_mcgr1_data));
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLNEST_MULTICAST_GROUP_4_PCB, l_nest_mcgr4_data));
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLMEM_MULTICAST_GROUP_4_PCB,  l_mem_mcgr4_data));

    FAPI_DBG("Set unused group registers to broadcast, Group 7");
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLPERV_MULTICAST_GROUP_2_PCB,   l_tp_mcgr2_data));
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLPERV_MULTICAST_GROUP_3_PCB,   l_tp_mcgr3_data));
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLPERV_MULTICAST_GROUP_4_PCB,   l_tp_mcgr4_data));
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLNEST_MULTICAST_GROUP_2_PCB, l_nest_mcgr2_data));
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLNEST_MULTICAST_GROUP_3_PCB, l_nest_mcgr3_data));
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLMEM_MULTICAST_GROUP_2_PCB,  l_mem_mcgr2_data));
    FAPI_TRY(fapi2::putScom(i_target, CEN_PCBSLMEM_MULTICAST_GROUP_3_PCB,  l_mem_mcgr3_data));

    FAPI_DBG( "Done initializing centaur multicast group0, group3" );

    //  Chiplet Init (all other pervasive endpoints within the different chiplets)
    FAPI_DBG( "Start pervasive initialization of other chiplets" );

    FAPI_DBG( "Reset GP3 for all chiplets" );
    l_write_all_func_gp3_data.setBit<1>().setBit<11>().setBit<13, 2>().setBit<18>();
    FAPI_TRY(fapi2::putScom(i_target, CEN_WRITE_ALL_FUNC_GP3,  l_write_all_func_gp3_data));

    FAPI_DBG( "Release endpoint reset for PCB" );
    l_write_all_func_gp3_data = 0;
    l_write_all_func_gp3_data.setBit<1>().invert();
    FAPI_TRY(fapi2::putScom(i_target, CEN_WRITE_ALL_FUNC_GP3_AND,  l_write_all_func_gp3_data));

    FAPI_DBG( "Partial good setting GP3(00)='1'" );
    l_write_all_func_gp3_data = 0;
    l_write_all_func_gp3_data.setBit<0>();
    FAPI_TRY(fapi2::putScom(i_target, CEN_WRITE_ALL_FUNC_GP3_OR,  l_write_all_func_gp3_data));

    FAPI_DBG( "DEBUG: clear force_to_known_2 (fencing for partial good) " );
    FAPI_TRY(fapi2::getScom(i_target, CEN_TCM_GP0_PCB, l_mem_gp0_data));
    l_mem_gp0_data.clearBit<16>();
    FAPI_TRY(fapi2::putScom(i_target, CEN_TCM_GP0_PCB, l_mem_gp0_data));

    FAPI_DBG( "PCB slave error reg reset" );
    FAPI_TRY(fapi2::putScom(i_target, CEN_WRITE_ALL_PCB_SLAVE_ERRREG, l_write_all_pcb_slave_errreg_data));

    // call cen_scan0_module( SCAN_CHIPLET_ALL, GPTR_TIME_REP )
    FAPI_TRY(cen_scan0_module(i_target, SCAN_CHIPLET_GROUP3, SCAN_ALLREGIONEXVITAL, SCAN_GPTR_TIME_REP));
    // call cen_scan0_module( SCAN_CHIPLET_ALL, ALLSCANEXPRV )
    FAPI_TRY(cen_scan0_module(i_target, SCAN_CHIPLET_GROUP3, SCAN_ALLREGIONEXVITAL, SCAN_ALLSCANEXPRV));

    //  Repair Loader (exclude TP)
    FAPI_DBG("Invoking repair loader...");

    FAPI_TRY(cen_repair_loader(i_target, REPAIR_COMMAND_VALIDATION_ENTRIES_DD2, REPAIR_COMMAND_START_ADDRESS));

    // skip load if no repairs are present
    FAPI_TRY(fapi2::getScom(i_target, CEN_OTPROM0_ECID_PART1_REGISTER_RO, l_ecid_part_1));

    if (l_ecid_part_1.getBit<0>())
    {
        FAPI_DBG("SCANNING tcn_refr_time");
        // inject header and rotate ring to position where repair loader will write data from OTPROM
        // scan 0..210
        l_nest_clk_scansel_data.setBit<10>().setBit<27>();
        FAPI_TRY(fapi2::putScom(i_target, l_nest_clk_scansel_addr, l_nest_clk_scansel_data));
        l_nest_clk_scandata0_data = 0xA5A55A5A00000000;
        FAPI_TRY(fapi2::putScom(i_target, l_nest_clk_scandata0_addr, l_nest_clk_scandata0_data));
        FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x6E, l_nest_clk_scandata0_data));
        FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x65, l_nest_clk_scandata0_data));
        // data 211..3006
        FAPI_TRY(cen_repair_loader(i_target, REPAIR_COMMAND_VALIDATION_ENTRY_TCN_REFR_TIME_DD2, REPAIR_COMMAND_START_ADDRESS));
        // scan 3007..3208
        FAPI_TRY(fapi2::putScom(i_target, l_nest_clk_scansel_addr, l_nest_clk_scansel_data));
        FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x6E, l_nest_clk_scandata0_data));
        FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x5C, l_nest_clk_scandata0_data));
        // data 3209..6004
        FAPI_TRY(cen_repair_loader(i_target, REPAIR_COMMAND_VALIDATION_ENTRY_TCN_REFR_TIME_DD2, REPAIR_COMMAND_START_ADDRESS));
        // scan 6005..6151
        // check header
        FAPI_TRY(fapi2::putScom(i_target, l_nest_clk_scansel_addr, l_nest_clk_scansel_data));
        FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x6E, l_nest_clk_scandata0_data));
        FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x25, l_nest_clk_scandata0_data));

        FAPI_ASSERT((l_nest_clk_scandata0_data == 0xA5A55A5A00000000),
                    fapi2::CEN_CHIPLET_INIT_HEADER_MISMATCH().set_TARGET(i_target),
                    "Error rotating tcn_refr_time ring -- header mismatch!"
                   );
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

