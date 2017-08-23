/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_cen_stopclocks.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
//
/// @file cen_stopclocks.C
/// @brief Stop Centaur chip clocks (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 3
// *HWP Consumed by: FSP
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fld.H>
#include <p9c_cen_stopclocks.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// Global bit definitions for all CLK_REGIONS
const uint8_t TP_CLK_STAT_NET_SL  = 3;
const uint8_t TP_CLK_STAT_NET_NSL = 4;
const uint8_t TP_CLK_STAT_NET_ARY = 5;
const uint8_t TP_CLK_STAT_PIB_SL  = 6;
const uint8_t TP_CLK_STAT_PIB_NSL = 7;
const uint8_t TP_CLK_STAT_PIB_ARY = 8;

// Clock Region Register clock stop data patterns
const uint64_t CLK_REGION_STOP_ALL             = 0x8FE00E0000000000ull;
const uint64_t CLK_REGION_STOP_ALL_BUT_REFRESH = 0x8FC00E0000000000ull;

// Clock Status Register data patterns
// Bits 24,25,26 should be OFF if refresh clocks are active
const uint64_t EXPECTED_CLOCK_STATUS           = 0xFFFFFF1FFFFFFFFFull;
const uint64_t EXPECTED_CLOCK_STATUS_W_REFRESH = 0xFFFFFFFFFFFFFFFFull;

// Expected CLK_STAT after execution of stopclocks
const uint32_t FSI_SHIFT_SET_PULSE_LENGTH = 0x0000000F;

// chiplet IDs
const uint8_t TP_CHIPLET_ID = 0x01;
const uint8_t NEST_CHIPLET_ID = 0x02;
const uint8_t MEM_CHIPLET_ID = 0x03;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Form fully qualified SCOM address given chiplet ID and
///        address offset
///
/// @param[in] i_addr SCOM address offset relative to chiplet base address space
/// @param[in] i_chiplet_id Byte indicating chiplet ID (TP, NEST, or MEM)
/// @param[out] o_addr Fully qualified SCOM address
///
/// @return void
///
void
cen_stopclocks_addr_xlate(const uint32_t i_addr,
                          const uint8_t i_chiplet_id,
                          uint32_t& o_addr)
{
    o_addr = i_addr;
    o_addr &= 0x00FFFFFF;
    o_addr |= (i_chiplet_id << 24);
}


///
/// @brief Stop vital clocks
///
/// @param[in] i_target Reference to Centaur chip target
///
/// @return void
///
void
cen_vitl_stopclocks(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    fapi2::buffer<uint32_t> l_fsi_gp3 = 0;

    // set the length of the FSI shifter set pulse
    FAPI_DBG("Set length of the FSI shifter set pulse");
    (void) fapi2::putCfamRegister(i_target,
                                  CEN_FSI_SHIFT_SHIFT_CONTROL_REGISTER_2,
                                  FSI_SHIFT_SET_PULSE_LENGTH);

    // disable VITL clocks (PERV GP3, RMW)
    FAPI_DBG("Disable VITL clocks in PERV GP3");
    (void) fapi2::getCfamRegister(i_target, CEN_PERV_GP3, l_fsi_gp3);
    l_fsi_gp3.setBit<CEN_PERV_GP3_TP_CHIPLET_VTL_CLKOFF_DC>();
    (void) fapi2::putCfamRegister(i_target, CEN_PERV_GP3, l_fsi_gp3);

    // set FSI fence 4/5
    FAPI_DBG("Setting FSI fences 4 and 5 in PERV GP3");
    l_fsi_gp3.setBit<CEN_FSIGP3_FENCE4_DC>()
    .setBit<CEN_FSIGP3_FENCE5_DC>();
    (void) fapi2::putCfamRegister(i_target, CEN_PERV_GP3, l_fsi_gp3);

    return;
}


///
/// @brief Stop chiplet clocks
///
/// @param[in] i_target Reference to Centaur chip target
/// @param[in] i_chiplet_id Byte indicating chiplet ID (TP, NEST, or MEM)
/// @param[in] i_stop_rfsh_clks Boolean indicating whether refresh clocks
///            should be stopped or left running
///
/// @return void
///
void
cen_chiplet_stopclocks(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                       const uint8_t i_chiplet_id,
                       const bool i_stop_rfsh_clks)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint32_t l_addr = 0;
    fapi2::buffer<uint64_t> l_gp0 = 0;
    fapi2::buffer<uint64_t> l_gp3 = 0;
    fapi2::buffer<uint32_t> l_fsi_gp3 = 0;
    fapi2::buffer<uint64_t> l_clock_status = 0;

    if (i_chiplet_id == TP_CHIPLET_ID)
    {
        // set the length of the FSI shifter set pulse
        FAPI_DBG("Set length of the FSI shifter set pulse");
        (void) fapi2::putCfamRegister(i_target,
                                      CEN_FSI_SHIFT_SHIFT_CONTROL_REGISTER_2,
                                      FSI_SHIFT_SET_PULSE_LENGTH);

        // go into PIB2PCB bypass path
        FAPI_DBG("Setting PIB2PCB bypass (FSI GP3)");
        (void) fapi2::getCfamRegister(i_target, CEN_FSIGP3, l_fsi_gp3);
        l_fsi_gp3.setBit<CEN_FSIGP3_USE_PIB2PCB_MUX_DC>();
        (void) fapi2::putCfamRegister(i_target, CEN_FSIGP3, l_fsi_gp3);
    }
    else
    {
        // check vital clock region is running before stopping the clocks
        // - if not running, stop as clock control is inaccesible
        // - else we should be able to reach the clock controller
        FAPI_DBG("Reading GP3 Register to check VITL clocks");
        cen_stopclocks_addr_xlate(CEN_PCBSLPERV_GP3_REG_PCB, i_chiplet_id, l_addr);
        l_rc = fapi2::getScom(i_target, l_addr, l_gp3);

        if (l_rc || l_gp3.getBit<CEN_PERV_GP3_TP_CHIPLET_VTL_CLKOFF_DC>())
        {
            // VITAL thold is asserted, stop here
            FAPI_DBG("VITAL clock state is unknown or  not running for this chiplet, stopping");
            goto fapi_try_exit;
        }
    }

    // set flushmode_inhibit (GP0, WOR)
    FAPI_DBG("Set flushmode_inhibit in GP0");
    cen_stopclocks_addr_xlate(CEN_GP0_PCB2, i_chiplet_id, l_addr);
    l_gp0.flush<0>()
    .setBit<CEN_GP0_TC_GPIO_FLUSHMODE_INH_DC_OUT>();
    (void) fapi2::putScom(i_target, l_addr, l_gp0);

    // set force_align (GP0, WOR)
    FAPI_DBG("Set flushmode_inhibit in GP0");
    l_gp0.flush<0>()
    .setBit<CEN_GP0_TC_GPIO_FORCEALIGN>();
    (void) fapi2::putScom(i_target, l_addr, l_gp0);

    // clear scan region register
    FAPI_DBG("Clear Scan Region control prior to clockstop");
    cen_stopclocks_addr_xlate(CEN_SCANSELQ_PCB, i_chiplet_id, l_addr);
    (void) fapi2::putScom(i_target, l_addr, 0x0ULL);

    // write clock stop command
    FAPI_DBG("Writing Clock Region Register to disable clocks");
    cen_stopclocks_addr_xlate(CEN_CLK_REGION_PCB, i_chiplet_id, l_addr);
    (void) fapi2::putScom(i_target, l_addr,
                          ((i_stop_rfsh_clks) ?
                           (CLK_REGION_STOP_ALL) :
                           (CLK_REGION_STOP_ALL_BUT_REFRESH)));

    // read clock status register to confirm clock stop
    FAPI_DBG("Reading Clock Status Register to confirm clock state");
    cen_stopclocks_addr_xlate(CEN_CLOCK_STAT_PCB, i_chiplet_id, l_addr);
    (void) fapi2::getScom(i_target, l_addr, l_clock_status);

    if (l_clock_status != ((i_stop_rfsh_clks) ?
                           (EXPECTED_CLOCK_STATUS_W_REFRESH) :
                           (EXPECTED_CLOCK_STATUS)))
    {
        FAPI_DBG("Clock status 0x%016llx was expected but read clock status 0x%016llx",
                 ((i_stop_rfsh_clks) ?
                  (EXPECTED_CLOCK_STATUS_W_REFRESH) :
                  (EXPECTED_CLOCK_STATUS)),
                 l_clock_status());
    }

    if (i_chiplet_id == MEM_CHIPLET_ID)
    {
        fapi2::buffer<uint32_t> l_fsi_gp4 = 0;

        // reset MemReset stability control (FSI GP4, RMW)
        FAPI_DBG("Reset MemReset stability control");
        (void) fapi2::getCfamRegister(i_target, CEN_FSIGP4, l_fsi_gp4);
        l_fsi_gp4.clearBit<CEN_FSIGP4_TPFSI_MEMRST_B>();
        (void) fapi2::putCfamRegister(i_target, CEN_FSIGP4, l_fsi_gp4);

        // reset D3PHY PLL Control (FSI GP4)
        (void) fapi2::getCfamRegister(i_target, CEN_FSIGP4, l_fsi_gp4);
        l_fsi_gp4.clearBit<CEN_FSIGP4_TP_CHIP_DPHY_PLLRESET_B>();
        (void) fapi2::putCfamRegister(i_target, CEN_FSIGP4, l_fsi_gp4);
    }

    if (i_chiplet_id != TP_CHIPLET_ID)
    {
        // reset abist_mode_dc (GP0, WAND)
        FAPI_DBG("Clearing abist_mode_dc in GP0");
        cen_stopclocks_addr_xlate(CEN_TCM_GP0_PCB1, i_chiplet_id, l_addr);
        l_gp0.flush<1>()
        .clearBit<CEN_TCM_GP0_TC_ABIST_MODE_DC>();
        (void) fapi2::putScom(i_target, l_addr, l_gp0);
    }

    // set synclk_muxsel and assert pervasive fence (GP0, WOR)
    FAPI_DBG("Set synclk_muxsel and perv fence in GP0");
    cen_stopclocks_addr_xlate(CEN_TCM_GP0_PCB2, i_chiplet_id, l_addr);
    l_gp0.flush<0>()
    .setBit<CEN_TCM_GP0_TC_UNIT_SYNCCLK_MUXSEL_DC>()
    .setBit<CEN_TCM_GP0_TC_FENCE_PERV_DC>();
    (void) fapi2::putScom(i_target, l_addr, l_gp0);

    // disable EDRAM (GP3, WAND)
    if (i_stop_rfsh_clks)
    {
        FAPI_DBG("Disable EDRAM");
        cen_stopclocks_addr_xlate(CEN_PCBSLMEM_GP3_REG_PCB1, i_chiplet_id, l_addr);
        l_gp3.flush<1>()
        .clearBit<CEN_PCBSLPERV_GP3_REG_L3_EDRAM_ENABLE>();
        (void) fapi2::putScom(i_target, l_addr, l_gp3);
    }

    // assert chiplet fence (GP3, WOR)
    if (i_chiplet_id != TP_CHIPLET_ID)
    {
        cen_stopclocks_addr_xlate(CEN_PCBSLMEM_GP3_REG_PCB2, i_chiplet_id, l_addr);
        l_gp3.flush<0>()
        .setBit<CEN_PCBSLPERV_GP3_REG_FENCE_EN>();
        (void) fapi2::putScom(i_target, l_addr, l_gp3);
    }

    // set scan_dis_dc_b (GP0, WOR)
    cen_stopclocks_addr_xlate(CEN_TCM_GP0_PCB2, i_chiplet_id, l_addr);
    l_gp0.flush<0>()
    .setBit<CEN_TCM_GP0_TC_GPIO_CC_SCAN_DIS_DC_B_OUT>();
    (void) fapi2::putScom(i_target, l_addr, l_gp0);

fapi_try_exit:
    return;
}


/// See doxygen in header file
fapi2::ReturnCode
p9c_cen_stopclocks(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                   const bool i_stop_mem_clks,
                   const bool i_stop_nest_clks,
                   const bool i_stop_dram_rfrsh_clks,
                   const bool i_stop_tp_clks,
                   const bool i_stop_vitl_clks)
{
    bool l_stop_mem_clks = i_stop_mem_clks;
    bool l_stop_nest_clks = i_stop_nest_clks;
    fapi2::buffer<uint32_t> l_perv_gp3;
    fapi2::buffer<uint64_t> l_tp_clock_status;
    fapi2::ReturnCode l_rc;
    FAPI_DBG("Start");

    // before attempting to stop the clocks in any chiplet, check to see that
    // the pervasive VITL clocks are running via bit 16 of the PERV GP3 register
    FAPI_DBG("Reading PERV GP3 to see if the VITL clock is ON.");
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_PERV_GP3, l_perv_gp3),
             "Error from getCfamRegister (CEN_PERV_GP3)");

    if (l_perv_gp3.getBit<CEN_PERV_GP3_TP_CHIPLET_VTL_CLKOFF_DC>())
    {
        // the Pervasive VITL clock is OFF
        // as we will not be able to reach the other chiplets, return
        FAPI_DBG("Exiting, pervasive VITL clocks are OFF");
        goto fapi_try_exit;
    }

    // Pervasive VITL clock must be ON, check to see if the PCB fabric clocks
    // are running, via the TP chiplet PIB/NET clock regions
    FAPI_DBG("Reading TP Clock Status Register to check PIB/NET clock state");
    FAPI_TRY(fapi2::getScom(i_target, CEN_CLOCK_STAT_PCB, l_tp_clock_status),
             "Error from getScom (CEN_CLOCK_STAT_PCB)");

    // prevent attempts to touch downstream chips if at least one of the NET or
    // PIB clocks is NOT running (one in clock status indicates stopped)
    if (l_tp_clock_status.getBit<TP_CLK_STAT_NET_SL>()  ||
        l_tp_clock_status.getBit<TP_CLK_STAT_NET_NSL>() ||
        l_tp_clock_status.getBit<TP_CLK_STAT_NET_ARY>() ||
        l_tp_clock_status.getBit<TP_CLK_STAT_PIB_SL>()  ||
        l_tp_clock_status.getBit<TP_CLK_STAT_PIB_NSL>() ||
        l_tp_clock_status.getBit<TP_CLK_STAT_PIB_ARY>())
    {
        FAPI_DBG("At least one of the NET or PIB clocks is NOT running");
        FAPI_DBG("PCB fabric may be inaccessible, ignore request to turn off chiplet clocks");
        l_stop_mem_clks  = false;
        l_stop_nest_clks = false;
    }

    FAPI_DBG("Input parameters: ");
    FAPI_DBG("  stop_mem_clks        = %s", l_stop_mem_clks        ? "true" : "false");
    FAPI_DBG("  stop_nest_clks       = %s", l_stop_nest_clks       ? "true" : "false");
    FAPI_DBG("  stop_dram_rfrsh_clks = %s", i_stop_dram_rfrsh_clks ? "true" : "false");
    FAPI_DBG("  stop_tp_clks         = %s", i_stop_tp_clks         ? "true" : "false");
    FAPI_DBG("  stop_vitl_clks       = %s", i_stop_vitl_clks       ? "true" : "false");

    if (l_stop_mem_clks)
    {
        cen_chiplet_stopclocks(i_target, MEM_CHIPLET_ID, true);
    }

    if (l_stop_nest_clks)
    {
        cen_chiplet_stopclocks(i_target, NEST_CHIPLET_ID, i_stop_dram_rfrsh_clks);
    }

    if (i_stop_tp_clks)
    {
        cen_chiplet_stopclocks(i_target, TP_CHIPLET_ID, false);
    }

    if (i_stop_vitl_clks)
    {
        cen_vitl_stopclocks(i_target);
    }

fapi_try_exit:
    return fapi2::current_err;
}
