/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_ppe_regs.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_io_ppe_regs.C
/// @brief GENERTED DO NOT EDIT - Objects for manipulating PPE SRAM registers
///
/// *HWP HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

#include <p10_io_ppe_regs.H>

p10_io_ppe_cache_proc::p10_io_ppe_cache_proc() :

    p10_io_ppe_img_regs(&p10_io_phy_ppe_scom_regs, p10_io_ppe_img_regs_start),

    p10_io_ppe_ppe_current_thread(&p10_io_ppe_img_regs, 0b000000100, 0xe000, 13),
    p10_io_ppe_ppe_debug_log_num(&p10_io_ppe_img_regs, 0b000000100, 0x1fc, 2),
    p10_io_ppe_ppe_error_lane(&p10_io_ppe_img_regs, 0b000001001, 0xf80, 7),
    p10_io_ppe_ppe_error_state(&p10_io_ppe_img_regs, 0b000001000, 0xffff, 0),
    p10_io_ppe_ppe_error_thread(&p10_io_ppe_img_regs, 0b000001001, 0x7000, 12),
    p10_io_ppe_ppe_error_valid(&p10_io_ppe_img_regs, 0b000001001, 0x8000, 15),
    p10_io_ppe_ppe_num_threads(&p10_io_ppe_img_regs, 0b000000000, 0xe000, 13),
    p10_io_ppe_ppe_tx_zcal_bist_busy(&p10_io_ppe_img_regs, 0b000000111, 0x40, 6),
    p10_io_ppe_ppe_tx_zcal_bist_busy_done_alias(&p10_io_ppe_img_regs, 0b000000111, 0x60, 5),
    p10_io_ppe_ppe_tx_zcal_bist_busy_done_fail_alias(&p10_io_ppe_img_regs, 0b000000111, 0x70, 4),
    p10_io_ppe_ppe_tx_zcal_bist_done(&p10_io_ppe_img_regs, 0b000000111, 0x20, 5),
    p10_io_ppe_ppe_tx_zcal_bist_done_fail_alias(&p10_io_ppe_img_regs, 0b000000111, 0x30, 4),
    p10_io_ppe_ppe_tx_zcal_bist_en(&p10_io_ppe_img_regs, 0b000000001, 0x4000, 14),
    p10_io_ppe_ppe_tx_zcal_bist_fail(&p10_io_ppe_img_regs, 0b000000111, 0x10, 4),
    p10_io_ppe_ppe_tx_zcal_busy(&p10_io_ppe_img_regs, 0b000000100, 0x800, 11),
    p10_io_ppe_ppe_tx_zcal_busy_done_alias(&p10_io_ppe_img_regs, 0b000000100, 0xc00, 10),
    p10_io_ppe_ppe_tx_zcal_busy_done_error_alias(&p10_io_ppe_img_regs, 0b000000100, 0xe00, 9),
    p10_io_ppe_ppe_tx_zcal_done(&p10_io_ppe_img_regs, 0b000000100, 0x400, 10),
    p10_io_ppe_ppe_tx_zcal_done_error_alias(&p10_io_ppe_img_regs, 0b000000100, 0x600, 9),
    p10_io_ppe_ppe_tx_zcal_error(&p10_io_ppe_img_regs, 0b000000100, 0x200, 9),
    p10_io_ppe_ppe_tx_zcal_n(&p10_io_ppe_img_regs, 0b000000101, 0xff80, 7),
    p10_io_ppe_ppe_tx_zcal_p(&p10_io_ppe_img_regs, 0b000000110, 0xff80, 7),
    p10_io_ppe_ppe_vio_volts(&p10_io_ppe_img_regs, 0b000000000, 0x180, 7),
    p10_io_ppe_ppe_watchdog_select_sim_mode(&p10_io_ppe_img_regs, 0b000000000, 0x1e00, 9),
    p10_io_ppe_ucontroller_test_en(&p10_io_ppe_img_regs, 0b000000001, 0x8000, 15),
    p10_io_ppe_ucontroller_test_stat(&p10_io_ppe_img_regs, 0b000000100, 0x1000, 12),
    p10_io_ppe_fw_regs
{
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_fw_regs0_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_fw_regs1_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_fw_regs2_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_fw_regs3_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_fw_regs4_start)
},
p10_io_ppe_ext_cmd_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0xffff, 0)
},
p10_io_ppe_ext_cmd_done_bist_final_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x4, 2)
},
p10_io_ppe_ext_cmd_done_dccal_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x1000, 12)
},
p10_io_ppe_ext_cmd_done_hw_reg_init_pg
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x8000, 15)
},
p10_io_ppe_ext_cmd_done_ioreset_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x4000, 14)
},
p10_io_ppe_ext_cmd_done_power_off_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x200, 9)
},
p10_io_ppe_ext_cmd_done_power_on_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x100, 8)
},
p10_io_ppe_ext_cmd_done_recal_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x8, 3)
},
p10_io_ppe_ext_cmd_done_rx_bist_tests_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x40, 6)
},
p10_io_ppe_ext_cmd_done_rx_detect_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x2000, 13)
},
p10_io_ppe_ext_cmd_done_train_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x10, 4)
},
p10_io_ppe_ext_cmd_done_tx_bist_tests_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x20, 5)
},
p10_io_ppe_ext_cmd_done_tx_ffe_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x400, 10)
},
p10_io_ppe_ext_cmd_done_tx_fifo_init_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x80, 7)
},
p10_io_ppe_ext_cmd_done_tx_zcal_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000101, 0x800, 11)
},
p10_io_ppe_ext_cmd_lanes_00_15
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000000, 0xffff, 0)
},
p10_io_ppe_ext_cmd_lanes_16_31
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000001, 0xffff, 0)
},
p10_io_ppe_ext_cmd_req
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0xffff, 0)
},
p10_io_ppe_ext_cmd_req_bist_final_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x4, 2)
},
p10_io_ppe_ext_cmd_req_dccal_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x1000, 12)
},
p10_io_ppe_ext_cmd_req_hw_reg_init_pg
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x8000, 15)
},
p10_io_ppe_ext_cmd_req_ioreset_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x4000, 14)
},
p10_io_ppe_ext_cmd_req_power_off_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x200, 9)
},
p10_io_ppe_ext_cmd_req_power_on_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x100, 8)
},
p10_io_ppe_ext_cmd_req_recal_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x8, 3)
},
p10_io_ppe_ext_cmd_req_rx_bist_tests_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x40, 6)
},
p10_io_ppe_ext_cmd_req_rx_detect_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x2000, 13)
},
p10_io_ppe_ext_cmd_req_train_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x10, 4)
},
p10_io_ppe_ext_cmd_req_tx_bist_tests_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x20, 5)
},
p10_io_ppe_ext_cmd_req_tx_ffe_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x400, 10)
},
p10_io_ppe_ext_cmd_req_tx_fifo_init_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x80, 7)
},
p10_io_ppe_ext_cmd_req_tx_zcal_pl
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000010, 0x800, 11)
},
p10_io_ppe_fw_bist_en
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000011, 0x4, 2)
},
p10_io_ppe_fw_debug
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000110, 0xffff, 0)
},
p10_io_ppe_fw_gcr_bus_id
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000011, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000011, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000011, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000011, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000011, 0xfc00, 10)
},
p10_io_ppe_fw_num_lanes
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000011, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000011, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000011, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000011, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000011, 0xf8, 3)
},
p10_io_ppe_fw_serdes_16_to_1_mode
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000011, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000011, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000011, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000011, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000011, 0x200, 9)
},
p10_io_ppe_fw_spread_en
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000011, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000011, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000011, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000011, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000011, 0x100, 8)
},
p10_io_ppe_fw_stop_thread
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000011, 0x2, 1)
},
p10_io_ppe_fw_thread_stopped
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000111, 0x8000, 15)
},
p10_io_ppe_fw_zcal_tdr_mode
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000011, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000011, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000011, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000011, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000011, 0x1, 0)
},
p10_io_ppe_mem_regs
{
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_mem_regs0_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_mem_regs1_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_mem_regs2_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_mem_regs3_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_mem_regs4_start)
},
p10_io_ppe_amp_setting_ovr_enb
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x20, 5)
},
p10_io_ppe_bist_in_hold_loop
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x4000, 14)
},
p10_io_ppe_bist_in_progress
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x8000, 15)
},
p10_io_ppe_bist_internal_error
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x200, 9)
},
p10_io_ppe_bist_other_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x800, 11)
},
p10_io_ppe_bist_overall_pass
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x400, 10)
},
p10_io_ppe_bist_rx_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x2000, 13)
},
p10_io_ppe_bist_spare_0
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x100, 8)
},
p10_io_ppe_bist_spare_1
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x80, 7)
},
p10_io_ppe_bist_tx_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x1000, 12)
},
p10_io_ppe_jump_table_used
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001111, 0x800, 11)
},
p10_io_ppe_lanes_pon_00_15
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001110, 0xffff, 0)
},
p10_io_ppe_lanes_pon_16_23
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001111, 0xff00, 8)
},
p10_io_ppe_loff_setting_ovr_enb
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x40, 6)
},
p10_io_ppe_poff_avg_a
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001010, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001010, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001010, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001010, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001010, 0xfe00, 9)
},
p10_io_ppe_poff_avg_b
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001010, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001010, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001010, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001010, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001010, 0x1fc, 2)
},
p10_io_ppe_ppe_channel_loss
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000100, 0x18, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000100, 0x18, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000100, 0x18, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000100, 0x18, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000100, 0x18, 3)
},
p10_io_ppe_ppe_ctle_peak1_disable
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0x80, 7)
},
p10_io_ppe_ppe_ctle_peak1_peak2_disable_alias
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0xc0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0xc0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0xc0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0xc0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0xc0, 6)
},
p10_io_ppe_ppe_ctle_peak2_disable
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0x40, 6)
},
p10_io_ppe_ppe_data_rate
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000100, 0x60, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000100, 0x60, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000100, 0x60, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000100, 0x60, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000100, 0x60, 5)
},
p10_io_ppe_ppe_debug_state
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110000, 0xffff, 0)
},
p10_io_ppe_ppe_debug_stopwatch_time_us
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001010, 0xffff, 0)
},
p10_io_ppe_ppe_eoff_edge_hysteresis
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001011, 0x1c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001011, 0x1c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001011, 0x1c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001011, 0x1c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001011, 0x1c00, 10)
},
p10_io_ppe_ppe_last_cal_time_us
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111000111, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111000111, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111000111, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111000111, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111000111, 0xffff, 0)
},
p10_io_ppe_ppe_lte_gain_disable
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001011, 0x4, 2)
},
p10_io_ppe_ppe_lte_gain_zero_disable_alias
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001011, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001011, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001011, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001011, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001011, 0x6, 1)
},
p10_io_ppe_ppe_lte_hysteresis
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001011, 0xe000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001011, 0xe000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001011, 0xe000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001011, 0xe000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001011, 0xe000, 13)
},
p10_io_ppe_ppe_lte_zero_disable
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001011, 0x2, 1)
},
p10_io_ppe_ppe_pr_offset_applied
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x1, 0)
},
p10_io_ppe_ppe_pr_offset_d_override
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101010, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101010, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101010, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101010, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101010, 0xf800, 11)
},
p10_io_ppe_ppe_pr_offset_e_override
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101010, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101010, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101010, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101010, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101010, 0x7c0, 6)
},
p10_io_ppe_ppe_pr_offset_pause
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101010, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101010, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101010, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101010, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101010, 0x20, 5)
},
p10_io_ppe_ppe_recal_not_run_sim_mode
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000100, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000100, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000100, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000100, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000100, 0xf00, 8)
},
p10_io_ppe_ppe_servo_status0
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110111010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110111010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110111010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110111010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110111010, 0xffff, 0)
},
p10_io_ppe_ppe_servo_status1
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110111011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110111011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110111011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110111011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110111011, 0xffff, 0)
},
p10_io_ppe_ppe_thread_lock_sim_mode
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000100, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000100, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000100, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000100, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000100, 0xf000, 12)
},
p10_io_ppe_ppe_thread_loop_count
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110001, 0xffff, 0)
},
p10_io_ppe_ppe_tx_zcal_meas_filter_depth
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010010, 0xf80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010010, 0xf80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010010, 0xf80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010010, 0xf80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010010, 0xf80, 7)
},
p10_io_ppe_ppe_tx_zcal_meas_max
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010011, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010011, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010011, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010011, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010011, 0x1fc, 2)
},
p10_io_ppe_ppe_tx_zcal_meas_min
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010011, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010011, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010011, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010011, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010011, 0xfe00, 9)
},
p10_io_ppe_ppe_tx_zcal_reset_time_us
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010010, 0xf000, 12)
},
p10_io_ppe_rx_a_bad_dfe_conv
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x80, 7)
},
p10_io_ppe_rx_a_bank_sync_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x100, 8)
},
p10_io_ppe_rx_a_ber_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x8, 3)
},
p10_io_ppe_rx_a_ctle_gain_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x8000, 15)
},
p10_io_ppe_rx_a_ctle_peak1_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x1000, 12)
},
p10_io_ppe_rx_a_ctle_peak2_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x800, 11)
},
p10_io_ppe_rx_a_ddc_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x10, 4)
},
p10_io_ppe_rx_a_ddc_hyst_left_edge
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001100, 0xf800, 11)
},
p10_io_ppe_rx_a_ddc_hyst_right_edge
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001100, 0x7c0, 6)
},
p10_io_ppe_rx_a_dfe_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x20, 5)
},
p10_io_ppe_rx_a_dfe_h1_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x40, 6)
},
p10_io_ppe_rx_a_eoff_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x2000, 13)
},
p10_io_ppe_rx_a_lane_hist_min_eye_width
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001100, 0x3f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001100, 0x3f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001100, 0x3f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001100, 0x3f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001100, 0x3f, 0)
},
p10_io_ppe_rx_a_last_eye_height
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001000, 0xfe00, 9)
},
p10_io_ppe_rx_a_latch_offset_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x4000, 14)
},
p10_io_ppe_rx_a_lte_gain_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x400, 10)
},
p10_io_ppe_rx_a_lte_zero_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x200, 9)
},
p10_io_ppe_rx_a_quad_phase_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x80, 7)
},
p10_io_ppe_rx_a_step_done_alias
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0xfff8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0xfff8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0xfff8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0xfff8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0xfff8, 3)
},
p10_io_ppe_rx_amp_gain_cnt_max
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0xf0, 4)
},
p10_io_ppe_rx_b_bank_sync_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x400, 10)
},
p10_io_ppe_rx_b_ber_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x20, 5)
},
p10_io_ppe_rx_b_ctle_gain_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x8000, 15)
},
p10_io_ppe_rx_b_ctle_peak1_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x10, 4)
},
p10_io_ppe_rx_b_ctle_peak2_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x8, 3)
},
p10_io_ppe_rx_b_ddc_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x40, 6)
},
p10_io_ppe_rx_b_ddc_hyst_left_edge
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001101, 0xf800, 11)
},
p10_io_ppe_rx_b_ddc_hyst_right_edge
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001101, 0x7c0, 6)
},
p10_io_ppe_rx_b_dfe_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x80, 7)
},
p10_io_ppe_rx_b_dfe_h1_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x100, 8)
},
p10_io_ppe_rx_b_eoff_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x2000, 13)
},
p10_io_ppe_rx_b_lane_hist_min_eye_width
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001101, 0x3f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001101, 0x3f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001101, 0x3f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001101, 0x3f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001101, 0x3f, 0)
},
p10_io_ppe_rx_b_last_eye_height
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001000, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001000, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001000, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001000, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001000, 0x1fc, 2)
},
p10_io_ppe_rx_b_latch_offset_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x4000, 14)
},
p10_io_ppe_rx_b_lte_gain_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x1000, 12)
},
p10_io_ppe_rx_b_lte_zero_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x800, 11)
},
p10_io_ppe_rx_b_quad_phase_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x200, 9)
},
p10_io_ppe_rx_b_step_done_alias
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0xfff8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0xfff8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0xfff8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0xfff8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0xfff8, 3)
},
p10_io_ppe_rx_bad_eye_opt_height
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x4000, 14)
},
p10_io_ppe_rx_bad_eye_opt_width
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x8000, 15)
},
p10_io_ppe_rx_bank_sync_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x20, 5)
},
p10_io_ppe_rx_ber_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x1, 0)
},
p10_io_ppe_rx_clr_lane_recal_cnt
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000001, 0x8000, 15)
},
p10_io_ppe_rx_cmd_init_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x200, 9)
},
p10_io_ppe_rx_ctle_gain_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x2000, 13)
},
p10_io_ppe_rx_ctle_gain_max_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100001, 0x1e0, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100001, 0x1e0, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100001, 0x1e0, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100001, 0x1e0, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100001, 0x1e0, 5)
},
p10_io_ppe_rx_ctle_gain_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100001, 0x1e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100001, 0x1e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100001, 0x1e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100001, 0x1e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100001, 0x1e, 1)
},
p10_io_ppe_rx_ctle_hysteresis
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0x600, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0x600, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0x600, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0x600, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0x600, 9)
},
p10_io_ppe_rx_ctle_mode
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0x800, 11)
},
p10_io_ppe_rx_ctle_peak1_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x200, 9)
},
p10_io_ppe_rx_ctle_peak1_max_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100100, 0xf800, 11)
},
p10_io_ppe_rx_ctle_peak1_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100100, 0x7c0, 6)
},
p10_io_ppe_rx_ctle_peak2_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x100, 8)
},
p10_io_ppe_rx_ctle_peak2_max_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101001, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101001, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101001, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101001, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101001, 0xf800, 11)
},
p10_io_ppe_rx_ctle_peak2_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101001, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101001, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101001, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101001, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101001, 0x7c0, 6)
},
p10_io_ppe_rx_ctle_quad_diff_thresh
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0x1c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0x1c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0x1c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0x1c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0x1c0, 6)
},
p10_io_ppe_rx_current_cal_lane
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110100, 0x3e00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110100, 0x3e00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110100, 0x3e00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110100, 0x3e00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110100, 0x3e00, 9)
},
p10_io_ppe_rx_dc_enable_latch_offset_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001101, 0x8000, 15)
},
p10_io_ppe_rx_dc_step_cntl_opt_alias
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001101, 0xc000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001101, 0xc000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001101, 0xc000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001101, 0xc000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001101, 0xc000, 14)
},
p10_io_ppe_rx_dccal_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x4000, 14)
},
p10_io_ppe_rx_ddc_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x2, 1)
},
p10_io_ppe_rx_ddc_hysteresis
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0x6, 1)
},
p10_io_ppe_rx_ddc_measure_limited
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x8, 3)
},
p10_io_ppe_rx_ddc_min_err_lim
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0x38, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0x38, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0x38, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0x38, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0x38, 3)
},
p10_io_ppe_rx_dfe_ap
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001001, 0xff, 0)
},
p10_io_ppe_rx_dfe_clkadj_coeff
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001011, 0x3f8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001011, 0x3f8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001011, 0x3f8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001011, 0x3f8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001011, 0x3f8, 3)
},
p10_io_ppe_rx_dfe_debug
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001001, 0xffff, 0)
},
p10_io_ppe_rx_dfe_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x4, 2)
},
p10_io_ppe_rx_dfe_full_mode
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000100, 0x80, 7)
},
p10_io_ppe_rx_dfe_full_quad
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x6, 1)
},
p10_io_ppe_rx_dfe_h1_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x8, 3)
},
p10_io_ppe_rx_dfe_max_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100110, 0xff00, 8)
},
p10_io_ppe_rx_dfe_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100111, 0xff00, 8)
},
p10_io_ppe_rx_disable_bank_pdwn
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0x8, 3)
},
p10_io_ppe_rx_enable_auto_recal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000000, 0x4000, 14)
},
p10_io_ppe_rx_enable_lane_cal_copy
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0x4, 2)
},
p10_io_ppe_rx_enable_lane_cal_lte_copy
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0x2, 1)
},
p10_io_ppe_rx_eo_converged_end_count
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0xf000, 12)
},
p10_io_ppe_rx_eo_enable_bank_sync
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x200, 9)
},
p10_io_ppe_rx_eo_enable_ctle_peak_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x2000, 13)
},
p10_io_ppe_rx_eo_enable_ddc
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x400, 10)
},
p10_io_ppe_rx_eo_enable_dfe_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x800, 11)
},
p10_io_ppe_rx_eo_enable_dfe_full_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x80, 7)
},
p10_io_ppe_rx_eo_enable_edge_offset_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x4000, 14)
},
p10_io_ppe_rx_eo_enable_lte_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x1000, 12)
},
p10_io_ppe_rx_eo_enable_quad_phase_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x100, 8)
},
p10_io_ppe_rx_eo_enable_vga_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x8000, 15)
},
p10_io_ppe_rx_eo_step_cntl_opt_alias
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0xff80, 7)
},
p10_io_ppe_rx_eo_vga_ctle_loop_not_converged
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x100, 8)
},
p10_io_ppe_rx_eoff_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x800, 11)
},
p10_io_ppe_rx_eoff_max_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100011, 0xff00, 8)
},
p10_io_ppe_rx_eoff_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100011, 0xff, 0)
},
p10_io_ppe_rx_eoff_poff_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x400, 10)
},
p10_io_ppe_rx_epoff_max_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101000, 0xff00, 8)
},
p10_io_ppe_rx_epoff_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101000, 0xff, 0)
},
p10_io_ppe_rx_eye_height_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0xfe00, 9)
},
p10_io_ppe_rx_eye_width_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100001, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100001, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100001, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100001, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100001, 0xfe00, 9)
},
p10_io_ppe_rx_fail_flag
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x8, 3)
},
p10_io_ppe_rx_h1_coef
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001110, 0xff00, 8)
},
p10_io_ppe_rx_h2_coef
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001110, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001110, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001110, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001110, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001110, 0xff, 0)
},
p10_io_ppe_rx_h3_coef
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001001, 0xff00, 8)
},
p10_io_ppe_rx_hist_min_eye_height
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110011, 0xfe, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110011, 0xfe, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110011, 0xfe, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110011, 0xfe, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110011, 0xfe, 1)
},
p10_io_ppe_rx_hist_min_eye_height_lane
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110010, 0x1f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110010, 0x1f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110010, 0x1f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110010, 0x1f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110010, 0x1f, 0)
},
p10_io_ppe_rx_hist_min_eye_height_valid
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101100, 0x80, 7)
},
p10_io_ppe_rx_hist_min_eye_width
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110011, 0xff00, 8)
},
p10_io_ppe_rx_hist_min_eye_width_lane
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101100, 0x1f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101100, 0x1f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101100, 0x1f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101100, 0x1f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101100, 0x1f00, 8)
},
p10_io_ppe_rx_hist_min_eye_width_mode
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0xc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0xc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0xc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0xc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0xc00, 10)
},
p10_io_ppe_rx_hist_min_eye_width_valid
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101100, 0x8000, 15)
},
p10_io_ppe_rx_init_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x8000, 15)
},
p10_io_ppe_rx_lane_bad
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x20, 5)
},
p10_io_ppe_rx_lane_bad_0_15
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111000101, 0xffff, 0)
},
p10_io_ppe_rx_lane_bad_16_23
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111000110, 0xff00, 8)
},
p10_io_ppe_rx_lane_busy
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x2000, 13)
},
p10_io_ppe_rx_lane_hist_min_eye_height
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001111, 0x7f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001111, 0x7f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001111, 0x7f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001111, 0x7f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001111, 0x7f, 0)
},
p10_io_ppe_rx_lane_hist_min_eye_height_bank
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001111, 0x400, 10)
},
p10_io_ppe_rx_lane_hist_min_eye_height_latch
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001111, 0x380, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001111, 0x380, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001111, 0x380, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001111, 0x380, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001111, 0x380, 7)
},
p10_io_ppe_rx_lane_hist_min_eye_height_quad
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001000, 0x3, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001000, 0x3, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001000, 0x3, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001000, 0x3, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001000, 0x3, 0)
},
p10_io_ppe_rx_lane_hist_min_eye_height_valid
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000001, 0x4000, 14)
},
p10_io_ppe_rx_lane_hist_min_eye_width_valid
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000001, 0x2000, 13)
},
p10_io_ppe_rx_lane_recal_cnt
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001011, 0xffff, 0)
},
p10_io_ppe_rx_last_init_lane
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110100, 0x1f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110100, 0x1f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110100, 0x1f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110100, 0x1f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110100, 0x1f0, 4)
},
p10_io_ppe_rx_latch_offset_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x1000, 12)
},
p10_io_ppe_rx_latchoff_max_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100010, 0xff00, 8)
},
p10_io_ppe_rx_latchoff_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100010, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100010, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100010, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100010, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100010, 0xff, 0)
},
p10_io_ppe_rx_linklayer_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x10, 4)
},
p10_io_ppe_rx_linklayer_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x40, 6)
},
p10_io_ppe_rx_lte_gain_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x80, 7)
},
p10_io_ppe_rx_lte_gain_max_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100100, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100100, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100100, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100100, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100100, 0x3e, 1)
},
p10_io_ppe_rx_lte_gain_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100101, 0xf800, 11)
},
p10_io_ppe_rx_lte_zero_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x40, 6)
},
p10_io_ppe_rx_lte_zero_max_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100101, 0x7c0, 6)
},
p10_io_ppe_rx_lte_zero_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100101, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100101, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100101, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100101, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100101, 0x3e, 1)
},
p10_io_ppe_rx_manual_servo_filter_depth
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0x300, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0x300, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0x300, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0x300, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0x300, 8)
},
p10_io_ppe_rx_min_recal_cnt
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0xf000, 12)
},
p10_io_ppe_rx_min_recal_cnt_reached
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x800, 11)
},
p10_io_ppe_rx_qpa_cdrlock_ignore
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0x100, 8)
},
p10_io_ppe_rx_qpa_hysteresis_enable
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0x200, 9)
},
p10_io_ppe_rx_qpa_pattern
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0x7c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0x7c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0x7c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0x7c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0x7c00, 10)
},
p10_io_ppe_rx_qpa_pattern_enable
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0x8000, 15)
},
p10_io_ppe_rx_quad_ph_adj_max_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100110, 0xfc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100110, 0xfc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100110, 0xfc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100110, 0xfc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100110, 0xfc, 2)
},
p10_io_ppe_rx_quad_ph_adj_min_check
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100111, 0xfc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100111, 0xfc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100111, 0xfc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100111, 0xfc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100111, 0xfc, 2)
},
p10_io_ppe_rx_quad_phase_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x10, 4)
},
p10_io_ppe_rx_rc_enable_bank_sync
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x100, 8)
},
p10_io_ppe_rx_rc_enable_ctle_peak_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x2000, 13)
},
p10_io_ppe_rx_rc_enable_ddc
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x400, 10)
},
p10_io_ppe_rx_rc_enable_dfe_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x800, 11)
},
p10_io_ppe_rx_rc_enable_edge_offset_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x4000, 14)
},
p10_io_ppe_rx_rc_enable_lte_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x1000, 12)
},
p10_io_ppe_rx_rc_enable_quad_phase_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x80, 7)
},
p10_io_ppe_rx_rc_enable_vga_cal
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x8000, 15)
},
p10_io_ppe_rx_rc_step_cntl_opt_alias
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0xff80, 7)
},
p10_io_ppe_rx_recal_abort
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000000, 0x8000, 15)
},
p10_io_ppe_rx_recal_before_init
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x400, 10)
},
p10_io_ppe_rx_recal_done
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x1000, 12)
},
p10_io_ppe_rx_recal_run_or_unused_0_15
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001100, 0xffff, 0)
},
p10_io_ppe_rx_recal_run_or_unused_16_23
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001101, 0xff00, 8)
},
p10_io_ppe_rx_step_fail_alias
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x3fff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x3fff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x3fff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x3fff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x3fff, 0)
},
p10_io_ppe_rx_vga_amax_target
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010000, 0xff, 0)
},
p10_io_ppe_rx_vga_converged
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001111, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001111, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001111, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001111, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001111, 0xf000, 12)
},
p10_io_ppe_rx_vga_debug
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111000011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111000011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111000011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111000011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111000011, 0xffff, 0)
},
p10_io_ppe_rx_vga_jump_target
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010000, 0xff00, 8)
},
p10_io_ppe_rx_vga_recal_max_target
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010001, 0xff00, 8)
},
p10_io_ppe_rx_vga_recal_min_target
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010001, 0xff, 0)
},
p10_io_ppe_tx_bist_dcc_i_max
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000001, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000001, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000001, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000001, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000001, 0x3f0, 4)
},
p10_io_ppe_tx_bist_dcc_i_min
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000001, 0xfc00, 10)
},
p10_io_ppe_tx_bist_dcc_iq_max
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001100, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001100, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001100, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001100, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001100, 0x3f0, 4)
},
p10_io_ppe_tx_bist_dcc_iq_min
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001100, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001100, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001100, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001100, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001100, 0xfc00, 10)
},
p10_io_ppe_tx_bist_dcc_q_max
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000010, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000010, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000010, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000010, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000010, 0x3f0, 4)
},
p10_io_ppe_tx_bist_dcc_q_min
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000010, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000010, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000010, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000010, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000010, 0xfc00, 10)
},
p10_io_ppe_tx_bist_fail_0_15
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111010000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111010000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111010000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111010000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111010000, 0xffff, 0)
},
p10_io_ppe_tx_bist_fail_16_23
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111010001, 0xff00, 8)
},
p10_io_ppe_tx_bist_hs_dac_thresh_max
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001111, 0xff, 0)
},
p10_io_ppe_tx_bist_hs_dac_thresh_min
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001111, 0xff00, 8)
},
p10_io_ppe_tx_dc_enable_dcc
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001101, 0x4000, 14)
},
p10_io_ppe_tx_dcc_debug
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111000100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111000100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111000100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111000100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111000100, 0xffff, 0)
},
p10_io_ppe_tx_dcc_main_min_samples
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010100, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010100, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010100, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010100, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010100, 0xff, 0)
},
p10_io_ppe_tx_ffe_margin_coef
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010101, 0x80, 7)
},
p10_io_ppe_tx_ffe_pre1_coef
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010101, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010101, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010101, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010101, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010101, 0xf00, 8)
},
p10_io_ppe_tx_ffe_pre2_coef
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010101, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010101, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010101, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010101, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010101, 0xf000, 12)
},
p10_io_ppe_tx_rc_enable_dcc
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x200, 9)
},
p10_io_ppe_tx_seg_test_1r_segs
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010100, 0x1800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010100, 0x1800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010100, 0x1800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010100, 0x1800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010100, 0x1800, 11)
},
p10_io_ppe_tx_seg_test_2r_seg
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010100, 0x2000, 13)
},
p10_io_ppe_tx_seg_test_en
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010100, 0x8000, 15)
},
p10_io_ppe_tx_seg_test_fail
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111010010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111010010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111010010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111010010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111010010, 0x8000, 15)
},
p10_io_ppe_tx_seg_test_frc_2r
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010100, 0x4000, 14)
} {}
