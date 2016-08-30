/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/ffdc/p9_pib2pcb_mux_seq.C $ */
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
//------------------------------------------------------------------------------
/// @file  p9_pib2pcb_mux_seq.C
///
/// @brief Pib2pcb mux sequence
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner :  <>
// *HWP FW Owner        :  <>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SE:HB
//------------------------------------------------------------------------------


//## auto_generated
#include <fapi2.H>
#include "p9_pib2pcb_mux_seq.H"

#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>


fapi2::ReturnCode p9_pib2pcb_mux_seq(const fapi2::ffdc_t& i_chip,
                                     fapi2::ReturnCode& o_rc)
{
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target_chip =
        *(reinterpret_cast<const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> *>(i_chip.ptr()));

    fapi2::buffer<uint64_t>l_sl_clock_status;
    fapi2::buffer<uint64_t>l_nsl_clock_status;
    fapi2::buffer<uint64_t>l_ary_clock_status;
    fapi2::buffer<uint64_t>l_scan_region;
    fapi2::buffer<uint64_t>l_clk_region;
    fapi2::buffer<uint64_t>l_opcg_0;
    fapi2::buffer<uint64_t>l_opcg_1;
    fapi2::buffer<uint64_t>l_opcg_2;

    fapi2::ffdc_t UNIT_FFDC_DATA_SL;
    fapi2::ffdc_t UNIT_FFDC_DATA_NSL;
    fapi2::ffdc_t UNIT_FFDC_DATA_ARY;
    fapi2::ffdc_t UNIT_FFDC_DATA_SCAN_REGION;
    fapi2::ffdc_t UNIT_FFDC_DATA_CLK_REGION;
    fapi2::ffdc_t UNIT_FFDC_DATA_OPCG0;
    fapi2::ffdc_t UNIT_FFDC_DATA_OPCG1;
    fapi2::ffdc_t UNIT_FFDC_DATA_OPCG2;

    fapi2::buffer<uint32_t> l_data32_root_ctrl0;
    fapi2::buffer<uint32_t> l_data32;
    FAPI_INF("p9_pib2pcb_mux_seq: Entering ...");

    //Setting ROOT_CTRL0 register value
    fapi2::getCfamRegister(l_target_chip, PERV_ROOT_CTRL0_FSI, l_data32_root_ctrl0);
    l_data32_root_ctrl0.clearBit<PERV_ROOT_CTRL0_SET_VDD2VIO_LVL_FENCE_DC>();  //CFAM.ROOT_CTRL0.VDD2VIO_LVL_FENCE_DC = 0
    fapi2::putCfamRegister(l_target_chip, PERV_ROOT_CTRL0_FSI, l_data32_root_ctrl0);

    //Setting PERV_CTRL0 register value
    fapi2::getCfamRegister(l_target_chip, PERV_PERV_CTRL0_FSI, l_data32);
    l_data32.setBit<31>();  //CFAM.PERV_CTRL0.TP_PLLCHIPLET_FORCE_OUT_EN_DC = 1
    fapi2::putCfamRegister(l_target_chip, PERV_PERV_CTRL0_FSI, l_data32);

    //Setting ROOT_CTRL0 register value
    //CFAM.ROOT_CTRL0.TPFSI_TP_FENCE_VTLIO_DC = 0
    l_data32_root_ctrl0.clearBit<PERV_ROOT_CTRL0_SET_TPFSI_TP_FENCE_VTLIO_DC>();
    fapi2::putCfamRegister(l_target_chip, PERV_ROOT_CTRL0_FSI, l_data32_root_ctrl0);

    //Setting ROOT_CTRL0 register value
    l_data32_root_ctrl0.clearBit<PERV_ROOT_CTRL0_SET_FENCE0_DC>();  //CFAM.ROOT_CTRL0.FENCE0_DC = 0
    l_data32_root_ctrl0.clearBit<PERV_ROOT_CTRL0_SET_FENCE1_DC>();  //CFAM.ROOT_CTRL0.FENCE1_DC = 0
    l_data32_root_ctrl0.clearBit<PERV_ROOT_CTRL0_SET_FENCE2_DC>();  //CFAM.ROOT_CTRL0.FENCE2_DC = 0
    fapi2::putCfamRegister(l_target_chip, PERV_ROOT_CTRL0_FSI, l_data32_root_ctrl0);

    //Setting ROOT_CTRL0 register value
    l_data32_root_ctrl0.setBit<PERV_ROOT_CTRL0_SET_OOB_MUX>();  //CFAM.ROOT_CTRL0.OOB_MUX = 1
    fapi2::putCfamRegister(l_target_chip, PERV_ROOT_CTRL0_FSI, l_data32_root_ctrl0);

    //Setting ROOT_CTRL0 register value
    l_data32_root_ctrl0.setBit<PERV_ROOT_CTRL0_SET_PCB_RESET_DC>();  //CFAM.ROOT_CTRL0.PCB_RESET_DC = 1
    fapi2::putCfamRegister(l_target_chip, PERV_ROOT_CTRL0_FSI, l_data32_root_ctrl0);

    //Setting ROOT_CTRL0 register value
    l_data32_root_ctrl0.setBit<PERV_ROOT_CTRL0_SET_PIB2PCB_DC>();  //CFAM.ROOT_CTRL0.PIB2PCB_DC = 1
    fapi2::putCfamRegister(l_target_chip, PERV_ROOT_CTRL0_FSI, l_data32_root_ctrl0);

    //Setting ROOT_CTRL0 register value
    l_data32_root_ctrl0.clearBit<PERV_ROOT_CTRL0_SET_PCB_RESET_DC>();  //CFAM.ROOT_CTRL0.PCB_RESET_DC = 0
    fapi2::putCfamRegister(l_target_chip, PERV_ROOT_CTRL0_FSI, l_data32_root_ctrl0);

    FAPI_INF("p9_pib2pcb_mux_seq: Check for Clocks running SL");
    //Getting CLOCK_STAT_SL register value
    fapi2::getScom(l_target_chip, PERV_TP_CLOCK_STAT_SL,
                   l_sl_clock_status); //l_sl_clock_status = PERV.CLOCK_STAT_SL

    UNIT_FFDC_DATA_SL.ptr() = l_sl_clock_status.pointer();
    UNIT_FFDC_DATA_SL.size() = l_sl_clock_status.template getLength<uint8_t>();

    //Getting CLOCK_STAT_NSL register value
    fapi2::getScom(l_target_chip, PERV_TP_CLOCK_STAT_NSL,
                   l_nsl_clock_status); //l_nsl_clock_status = PERV.CLOCK_STAT_NSL

    UNIT_FFDC_DATA_NSL.ptr() =  l_nsl_clock_status.pointer();
    UNIT_FFDC_DATA_NSL.size() = l_nsl_clock_status.template getLength<uint8_t>();

    //Getting CLOCK_STAT_ARY register value
    fapi2::getScom(l_target_chip, PERV_TP_CLOCK_STAT_ARY,
                   l_ary_clock_status); //l_ary_clock_status = PERV.CLOCK_STAT_ARY

    UNIT_FFDC_DATA_ARY.ptr()  = l_ary_clock_status.pointer();
    UNIT_FFDC_DATA_ARY.size() = l_ary_clock_status.template getLength<uint8_t>();

    FAPI_INF("p9_pib2pcb_mux_seq: SL Clock status register is %#018lX, %#018lX, %#018lX,", l_sl_clock_status,
             l_nsl_clock_status, l_ary_clock_status);

    fapi2::getScom(l_target_chip, PERV_TP_SCAN_REGION_TYPE, l_scan_region);

    UNIT_FFDC_DATA_SCAN_REGION.ptr()  = l_scan_region.pointer();
    UNIT_FFDC_DATA_SCAN_REGION.size() = l_scan_region.template getLength<uint8_t>();
    FAPI_INF("p9_pib2pcb_mux_seq: Scan region and type is %#018lX", l_scan_region);

    fapi2::getScom(l_target_chip, PERV_TP_CLK_REGION, l_clk_region);

    UNIT_FFDC_DATA_CLK_REGION.ptr()  = l_clk_region.pointer();
    UNIT_FFDC_DATA_CLK_REGION.size() = l_clk_region.template getLength<uint8_t>();
    FAPI_INF("p9_pib2pcb_mux_seq: Clk region and type is %#018lX", l_clk_region);

    // Add FFDC specified by RC_RC_COLLECT_CC_STATUS_REGISTERS
    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_COLLECT_CC_STATUS_REGISTERS);

    fapi2::getScom(l_target_chip, PERV_TP_OPCG_REG0, l_opcg_0);

    UNIT_FFDC_DATA_OPCG0.ptr()  = l_opcg_0.pointer();
    UNIT_FFDC_DATA_OPCG0.size() = l_opcg_0.template getLength<uint8_t>();

    fapi2::getScom(l_target_chip, PERV_TP_OPCG_REG1, l_opcg_1);

    UNIT_FFDC_DATA_OPCG1.ptr()  = l_opcg_1.pointer();
    UNIT_FFDC_DATA_OPCG1.size() = l_opcg_1.template getLength<uint8_t>();

    fapi2::getScom(l_target_chip, PERV_TP_OPCG_REG2, l_opcg_2);

    UNIT_FFDC_DATA_OPCG2.ptr()  = l_opcg_2.pointer();
    UNIT_FFDC_DATA_OPCG2.size() = l_opcg_2.template getLength<uint8_t>();

    // Add FFDC specified by RC_OPCG_REGISTERS
    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_OPCG_REGISTERS);

    FAPI_INF("p9_pib2pcb_mux_seq: Exiting ...");

    return fapi2::FAPI2_RC_SUCCESS;
}
