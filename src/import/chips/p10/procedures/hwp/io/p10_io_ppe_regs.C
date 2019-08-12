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



p10_io_ppe_cache p10_io_ppe_img_regs(&p10_io_phy_ppe_scom_regs, p10_io_ppe_img_regs_start);

p10_io_ppe_sram_reg p10_io_ppe_ppe_current_thread(&p10_io_ppe_img_regs, 0b000000100, 0xe000, 13);
p10_io_ppe_sram_reg p10_io_ppe_ppe_error_lane(&p10_io_ppe_img_regs, 0b000000111, 0xf80, 7);
p10_io_ppe_sram_reg p10_io_ppe_ppe_error_state(&p10_io_ppe_img_regs, 0b000001000, 0xffff, 0);
p10_io_ppe_sram_reg p10_io_ppe_ppe_error_thread(&p10_io_ppe_img_regs, 0b000000111, 0x7000, 12);
p10_io_ppe_sram_reg p10_io_ppe_ppe_error_valid(&p10_io_ppe_img_regs, 0b000000111, 0x8000, 15);
p10_io_ppe_sram_reg p10_io_ppe_ppe_num_threads(&p10_io_ppe_img_regs, 0b000000000, 0xe000, 13);
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_busy(&p10_io_ppe_img_regs, 0b000000100, 0x800, 11);
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_busy_done_alias(&p10_io_ppe_img_regs, 0b000000100, 0xc00, 10);
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_busy_done_error_alias(&p10_io_ppe_img_regs, 0b000000100, 0xe00, 9);
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_done(&p10_io_ppe_img_regs, 0b000000100, 0x400, 10);
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_done_error_alias(&p10_io_ppe_img_regs, 0b000000100, 0x600, 9);
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_error(&p10_io_ppe_img_regs, 0b000000100, 0x200, 9);
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_n(&p10_io_ppe_img_regs, 0b000000101, 0xff80, 7);
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_p(&p10_io_ppe_img_regs, 0b000000110, 0xff80, 7);
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_req(&p10_io_ppe_img_regs, 0b000000001, 0x4000, 14);
p10_io_ppe_sram_reg p10_io_ppe_ucontroller_test_en(&p10_io_ppe_img_regs, 0b000000001, 0x8000, 15);
p10_io_ppe_sram_reg p10_io_ppe_ucontroller_test_stat(&p10_io_ppe_img_regs, 0b000000100, 0x1000, 12);

p10_io_ppe_cache p10_io_ppe_fw_regs[5] =
{
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_fw_regs0_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_fw_regs1_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_fw_regs2_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_fw_regs3_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_fw_regs4_start)
};

p10_io_ppe_sram_reg p10_io_ppe_fw_gcr_bus_id[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000001, 0xfc00, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_fw_num_lanes[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000001, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000001, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000001, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000001, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000001, 0xf8, 3)
};
p10_io_ppe_sram_reg p10_io_ppe_fw_serdes_16_to_1_mode[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000001, 0x200, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_fw_stop_thread[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000000, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_fw_thread_stopped[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[0], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[1], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[2], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[3], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_fw_regs[4], 0b000000100, 0x8000, 15)
};

p10_io_ppe_cache p10_io_ppe_mem_regs[5] =
{
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_mem_regs0_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_mem_regs1_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_mem_regs2_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_mem_regs3_start),
    p10_io_ppe_cache(&p10_io_phy_ppe_scom_regs, p10_io_ppe_mem_regs4_start)
};

p10_io_ppe_sram_reg p10_io_ppe_dac_test_ppe_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110100, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110100, 0x80, 7)
};
p10_io_ppe_sram_reg p10_io_ppe_dac_test_ppe_enb[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x80, 7)
};
p10_io_ppe_sram_reg p10_io_ppe_hw_reg_init_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110100, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110100, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110100, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110100, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110100, 0x40, 6)
};
p10_io_ppe_sram_reg p10_io_ppe_hw_reg_init_req[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x40, 6)
};
p10_io_ppe_sram_reg p10_io_ppe_io_power_up_lane_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x200, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_io_power_up_lane_req[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000000, 0x200, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_io_reset_lane_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x400, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_io_reset_lane_done_0_15[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110111000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110111000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110111000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110111000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110111000, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_io_reset_lane_done_16_23[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110111001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110111001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110111001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110111001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110111001, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_io_reset_lane_req[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000000, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000000, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000000, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000000, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000000, 0x400, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_io_reset_lane_req_0_15[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101011, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_io_reset_lane_req_16_23[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101100, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101100, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101100, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101100, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101100, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_jump_table_used[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110111100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110111100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110111100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110111100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110111100, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_loff_setting_ovr_enb[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x20, 5)
};
p10_io_ppe_sram_reg p10_io_ppe_poff_avg_sm_a[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0xfe, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0xfe, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0xfe, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0xfe, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0xfe, 1)
};
p10_io_ppe_sram_reg p10_io_ppe_poff_avg_sm_b[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001010, 0x7f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001010, 0x7f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001010, 0x7f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001010, 0x7f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001010, 0x7f0, 4)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_ddc_failed_status[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001010, 0x800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_debug_state[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110000, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_debug_stopwatch_time_us[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001010, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_dft_rx_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000100, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_dft_seg_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000100, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_dft_tx_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000100, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_dft_zcal_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000100, 0x1000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_eoff_edge_hysteresis[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001011, 0x1c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001011, 0x1c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001011, 0x1c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001011, 0x1c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001011, 0x1c00, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_lte_hysteresis[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001011, 0xe000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001011, 0xe000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001011, 0xe000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001011, 0xe000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001011, 0xe000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_servo_status0[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110111010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110111010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110111010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110111010, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110111010, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_servo_status1[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110111011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110111011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110111011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110111011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110111011, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_thread_loop_count[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110001, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_meas_filter_depth[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010010, 0xf80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010010, 0xf80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010010, 0xf80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010010, 0xf80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010010, 0xf80, 7)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_meas_max[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010011, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010011, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010011, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010011, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010011, 0x1fc, 2)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_meas_min[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010011, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010011, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010011, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010011, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010011, 0xfe00, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_ppe_tx_zcal_reset_time_us[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010010, 0xf000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_bad_dfe_conv[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001010, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_bank_sync_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x200, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_ber_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x10, 4)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_ctle_gain_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_ctle_peak1_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x1000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_ctle_peak2_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001111, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_ddc_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x20, 5)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_dfe_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x40, 6)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_dfe_h1_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x80, 7)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_eoff_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_eoff_val[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001000, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001000, 0xfe00, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_h1ap_at_limit[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001010, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_latch_offset_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_lte_gain_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_lte_zero_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x400, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_a_quad_phase_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x100, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_amax_high[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000101, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_amax_low[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000101, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000101, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000101, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000101, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000101, 0xff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_amp_gain_cnt_max[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0xf0, 4)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ap110_ap010_delta_max[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001000, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001000, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001000, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001000, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001000, 0xf00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_apx111_high[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000110, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_apx111_low[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000110, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000110, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000110, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000110, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000110, 0xff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_bad_dfe_conv[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001010, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_bank_sync_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_ber_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x100, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_ctle_gain_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x8, 3)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_ctle_peak1_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x1, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_ctle_peak2_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001111, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_ddc_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x200, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_dfe_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x400, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_dfe_h1_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_eoff_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x2, 1)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_eoff_val[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001000, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001000, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001000, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001000, 0x1fc, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001000, 0x1fc, 2)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_h1ap_at_limit[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001010, 0x1000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_latch_offset_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000110, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000110, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000110, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000110, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000110, 0x4, 2)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_lte_gain_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_lte_zero_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_b_quad_phase_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000111, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000111, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000111, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000111, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000111, 0x1000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_bad_eye_opt_height[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_bad_eye_opt_width[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_bank_sync_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x20, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x20, 5)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ber_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x1, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x1, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_bist_ppe_enb[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_clr_lane_recal_cnt[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000001, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_gain_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_gain_max_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100001, 0x1e0, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100001, 0x1e0, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100001, 0x1e0, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100001, 0x1e0, 5),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100001, 0x1e0, 5)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_gain_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100001, 0x1e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100001, 0x1e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100001, 0x1e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100001, 0x1e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100001, 0x1e, 1)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_hysteresis[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0x600, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0x600, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0x600, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0x600, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0x600, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_mode[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0x800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak1_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x100, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak1_max_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100100, 0xf800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak1_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100100, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100100, 0x7c0, 6)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak2_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001111, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001111, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak2_max_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101101, 0xf800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_peak2_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101101, 0x7c0, 6)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ctle_quad_diff_thresh[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0x1c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0x1c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0x1c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0x1c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0x1c0, 6)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_current_cal_lane[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110100, 0x3e00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110100, 0x3e00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110100, 0x3e00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110100, 0x3e00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110100, 0x3e00, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dc_enable_dcc[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001101, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001101, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dc_enable_latch_offset_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001101, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001101, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dc_step_cntl_opt_alias[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001101, 0xc000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001101, 0xc000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001101, 0xc000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001101, 0xc000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001101, 0xc000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dcc_debug[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111000100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111000100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111000100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111000100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111000100, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dccal_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dccal_done_0_15[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110110, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dccal_done_16_23[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110111, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x2, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x2, 1)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_hist_left_edge[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001101, 0xf800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_hist_right_edge[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001101, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001101, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001101, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001101, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001101, 0xf8, 3)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_hysteresis[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0x6, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0x6, 1)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_last_left_edge[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001100, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001100, 0xf800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_last_right_edge[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001100, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001100, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001100, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001100, 0xf8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001100, 0xf8, 3)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_ddc_min_err_lim[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0x38, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0x38, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0x38, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0x38, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0x38, 3)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_ca_cfg[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001000, 0xc0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001000, 0xc0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001000, 0xc0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001000, 0xc0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001000, 0xc0, 6)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_converged_cnt_max[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001000, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001000, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001000, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001000, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001000, 0xf000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_debug[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001001, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x4, 2)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_h1_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x8, 3)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_max_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100110, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100110, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100110, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100110, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100110, 0xff80, 7)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_dfe_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100111, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100111, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100111, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100111, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100111, 0xff80, 7)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_disable_bank_pdwn[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0x8, 3),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0x8, 3)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_enable_auto_recal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000000, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000000, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000000, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000000, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000000, 0x800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_enable_lane_cal_copy[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0x4, 2),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0x4, 2)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_converged_end_count[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0xf000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_bank_sync[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x200, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_ctle_peak_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_ddc[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x400, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_dfe_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_edge_offset_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_lte_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x1000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_quad_phase_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x100, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_enable_vga_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_step_cntl_opt_alias[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001001, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eo_vga_ctle_loop_not_converged[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x200, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eoff_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eoff_max_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100011, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eoff_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100011, 0xff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eoff_poff_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x400, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_epoff_max_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101000, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101000, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101000, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101000, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101000, 0xfc00, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_epoff_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101000, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101000, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101000, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101000, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101000, 0x3f0, 4)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_eye_width_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100001, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100001, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100001, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100001, 0xfe00, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100001, 0xfe00, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_fail_flag[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_h1ap_cfg[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001000, 0x30, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001000, 0x30, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001000, 0x30, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001000, 0x30, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001000, 0x30, 4)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_height[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110011, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110011, 0xff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_height_lane[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110010, 0x1f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110010, 0x1f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110010, 0x1f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110010, 0x1f, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110010, 0x1f, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_height_mode[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0x300, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0x300, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0x300, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0x300, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0x300, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_height_valid[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110010, 0x80, 7)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_width[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110011, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110011, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_width_lane[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110010, 0x1f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110010, 0x1f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110010, 0x1f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110010, 0x1f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110010, 0x1f00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_width_mode[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000011, 0xc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000011, 0xc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000011, 0xc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000011, 0xc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000011, 0xc00, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_hist_min_eye_width_valid[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110110010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110110010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110110010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110110010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110110010, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_init_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lane_bad_0_15[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111000101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111000101, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lane_bad_16_23[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111000110, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111000110, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lane_busy[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lane_cal_time_us[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001110, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001110, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lane_recal_cnt[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001011, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_latch_offset_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x1000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_latchoff_max_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100010, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_latchoff_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100010, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100010, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100010, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100010, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100010, 0xff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_linklayer_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_linklayer_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001011, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001011, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001011, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001011, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001011, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lte_gain_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x80, 7)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lte_gain_max_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100100, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100100, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100100, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100100, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100100, 0x3e, 1)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lte_gain_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100101, 0xf800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100101, 0xf800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lte_zero_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x40, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x40, 6)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lte_zero_max_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100101, 0x7c0, 6),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100101, 0x7c0, 6)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_lte_zero_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100101, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100101, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100101, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100101, 0x3e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100101, 0x3e, 1)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_max_ber_check_count[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000100, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000100, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000100, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000100, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000100, 0xff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_min_eye_height[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000111, 0xff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_min_eye_width[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000111, 0x3f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000111, 0x3f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000111, 0x3f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000111, 0x3f00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000111, 0x3f00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_min_recal_cnt[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001110, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001110, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001110, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001110, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001110, 0xf000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_min_recal_cnt_reached[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_cdrlock_ignore[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0x100, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_ee_obs[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001001, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001001, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001001, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001001, 0xf00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001001, 0xf00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_hysteresis_enable[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0x200, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_ne_obs[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001001, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001001, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001001, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001001, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001001, 0xf000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_pattern[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0x7c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0x7c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0x7c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0x7c00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0x7c00, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_pattern_enable[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111100000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111100000, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_se_obs[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001001, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001001, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001001, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001001, 0xf0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001001, 0xf0, 4)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_qpa_we_obs[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000001001, 0xf, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000001001, 0xf, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000001001, 0xf, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000001001, 0xf, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000001001, 0xf, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_quad_ph_adj_max_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100110, 0x7e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100110, 0x7e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100110, 0x7e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100110, 0x7e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100110, 0x7e, 1)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_quad_ph_adj_min_check[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100111, 0x7e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100111, 0x7e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100111, 0x7e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100111, 0x7e, 1),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100111, 0x7e, 1)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_quad_phase_fail[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000101, 0x10, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000101, 0x10, 4)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_bank_sync[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x100, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_ctle_peak_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_dcc[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x200, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_ddc[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x400, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_dfe_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_edge_offset_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_lte_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x1000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_quad_phase_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x80, 7)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_rc_enable_vga_cal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_rc_step_cntl_opt_alias[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001010, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001010, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001010, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001010, 0xff80, 7),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001010, 0xff80, 7)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_recal_abort[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000000, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000000, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000000, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000000, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000000, 0x1000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_recal_done[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000100, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000100, 0x1000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_recal_req[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000000, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000000, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000000, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000000, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000000, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_recal_run_or_unused_0_15[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001100, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001100, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_recal_run_or_unused_16_23[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111001101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111001101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111001101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111001101, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111001101, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_run_dccal[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000000, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_run_dccal_0_15[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101001, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101001, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_run_dccal_16_23[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110101010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110101010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110101010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110101010, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110101010, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_run_lane[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b000000000, 0x8000, 15),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b000000000, 0x8000, 15)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_vga_amax[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110111101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110111101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110111101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110111101, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110111101, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_vga_amax_target[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010000, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010000, 0xff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_vga_converged[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111000010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111000010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111000010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111000010, 0xf000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111000010, 0xf000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_vga_debug[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111000011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111000011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111000011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111000011, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111000011, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_vga_jump_target[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010000, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010000, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_vga_recal_max_target[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010001, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_rx_vga_recal_min_target[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110010001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110010001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110010001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110010001, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110010001, 0xff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_seg_1r_ppe_enb[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x2000, 13),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x2000, 13)
};
p10_io_ppe_sram_reg p10_io_ppe_seg_2r_ppe_enb[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x1000, 12),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x1000, 12)
};
p10_io_ppe_sram_reg p10_io_ppe_seg_no2r_ppe_enb[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x800, 11),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x800, 11)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_i_max[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000001, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000001, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000001, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000001, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000001, 0x3f0, 4)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_i_min[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000001, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000001, 0xfc00, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_iq_max[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001100, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001100, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001100, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001100, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001100, 0x3f0, 4)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_iq_min[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001100, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001100, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001100, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001100, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001100, 0xfc00, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_q_max[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000010, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000010, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000010, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000010, 0x3f0, 4),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000010, 0x3f0, 4)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_dcc_q_min[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110000010, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110000010, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110000010, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110000010, 0xfc00, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110000010, 0xfc00, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_fail_0_15[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111010000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111010000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111010000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111010000, 0xffff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111010000, 0xffff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_fail_16_23[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b111010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b111010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b111010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b111010001, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b111010001, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_hs_dac_thresh_max[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001111, 0xff, 0),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001111, 0xff, 0)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_hs_dac_thresh_min[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110001111, 0xff00, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110001111, 0xff00, 8)
};
p10_io_ppe_sram_reg p10_io_ppe_tx_bist_ppe_enb[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x4000, 14),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x4000, 14)
};
p10_io_ppe_sram_reg p10_io_ppe_zcal_ovr_1r_ppe_enb[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x400, 10),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x400, 10)
};
p10_io_ppe_sram_reg p10_io_ppe_zcal_ovr_2r_ppe_enb[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x200, 9),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x200, 9)
};
p10_io_ppe_sram_reg p10_io_ppe_zcal_ovr_4r_ppe_enb[5] =
{
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[0], 0b110100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[1], 0b110100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[2], 0b110100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[3], 0b110100000, 0x100, 8),
    p10_io_ppe_sram_reg(&p10_io_ppe_mem_regs[4], 0b110100000, 0x100, 8)
};
