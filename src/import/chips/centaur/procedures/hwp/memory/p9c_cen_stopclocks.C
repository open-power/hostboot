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
/// @file p9c_cen_stopclocks.C
/// @brief Assert the tholds (stop the clocks) in the Centaur chip
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_gen_scom_addresses.H>
#include <centaur_misc_constants.H>
#include <p9c_cen_stopclocks.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
// CFAM FSI GP4 register bit/field definitions
constexpr uint8_t FSI_GP4_MEMRESET_STABILITY_BIT  = 2;
constexpr uint8_t FSI_GP4_DPHY_PLLRESET_BIT       = 4;

// PERVGP3 register bit/field definitions
constexpr uint8_t PERVGP3_VITL_CLKOFF_BIT   = 16;

// GP3 register bit/field definitions
constexpr uint8_t GP3_VITAL_THOLD_BIT       = 16;
constexpr uint8_t GP3_FENCE_EN_BIT          = 18;
constexpr uint8_t GP3_EDRAM_ENABLE_BIT      = 28;

// GP0 register bit/field definitions
constexpr uint8_t GP0_SYNCCLK_MUXSEL_BIT    = 1;
constexpr uint8_t GP0_FLUSHMODE_INHIBIT_BIT = 2;
constexpr uint8_t GP0_FORCE_ALIGN_BIT       = 3;
constexpr uint8_t GP0_SCAN_DIS_DC_B_BIT     = 6;
constexpr uint8_t GP0_ABIST_MODE_BIT        = 11;
constexpr uint8_t GP0_PERV_FENCE_BIT        = 63;

// FSIGP3 register bit/field definitions
constexpr uint8_t FSIGP3_PIB2PCB_BYPASS_BIT = 20;
constexpr uint8_t FSIGP3_FSI_FENCE4_BIT     = 25;
constexpr uint8_t FSIGP3_FSI_FENCE5_BIT     = 26;

// Global bit definitions for all CLK_REGIONS
constexpr uint8_t CLK_REGION_CLOCK_CMD_BIT      = 0;
constexpr uint8_t CLK_REGION_CLOCK_CMD_LEN      = 2;
constexpr uint8_t CLK_REGION_CLOCK_CMD_STOP     = 2;

constexpr uint8_t TP_CLK_STAT_NET_SL            = 3;
constexpr uint8_t TP_CLK_STAT_NET_NSL           = 4;
constexpr uint8_t TP_CLK_STAT_NET_ARY           = 5;
constexpr uint8_t TP_CLK_STAT_PIB_SL            = 6;
constexpr uint8_t TP_CLK_STAT_PIB_NSL           = 7;
constexpr uint8_t TP_CLK_STAT_PIB_ARY           = 8;


// Clock Region Register clock stop data patterns
constexpr uint64_t CLK_REGION_REG_DATA_TO_STOP_ALL     = 0x8FE00E0000000000ull;
constexpr uint64_t CLK_REGION_STOP_ALL_BUT_REFRESH     = 0x8FC00E0000000000ull;
constexpr uint64_t EXPECTED_CLOCK_STATUS               = 0xFFFFFFFFFFFFFFFFull;
// Bits 24,25,26 should be OFF for refresh clocks to be active.
constexpr uint64_t EXPECTED_CLOCK_STATUS_W_REFRESH     = 0xFFFFFF1FFFFFFFFFull;

// Expected CLK_STAT after execution of stopclocks
constexpr uint32_t FSI_SHIFT_SET_PULSE_LENGTH      = 0x0000000F;

extern "C" {

    /// @brief cen_stopclocks procedure:  The purpose of this procedure is to assert the tholds (stop the clocks) in the Centaur chip.
    /// @param[in] i_target                 Reference to centaur target
    /// @param[in] i_stop_mem_clks          True if MEM chiplet clocks should be stopped, else false
    /// @param[in] i_stop_nest_clks         True if NEST chiplet clocks (except for refresh clks) should be stopped, else false
    /// @param[in] i_stop_dram_refresh_clks   If (i_stop_nest_clks==true) then true if NEST chiplet refresh clocks should be stopped, else false
    /// @param[in] i_stop_tp_clks           True if PERV (TP) chiplet clocks should be stopped, else false
    /// @param[in] i_stop_vitl_clks         True if PERV VITL clocks should be stopped, else false
    /// @return ReturnCode
    fapi2::ReturnCode p9c_cen_stopclocks(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                                         const bool i_stop_mem_clks,
                                         const bool i_stop_nest_clks,
                                         const bool i_stop_dram_refresh_clks,
                                         const bool i_stop_tp_clks,
                                         const bool i_stop_vitl_clks)
    {
        bool i2_stop_mem_clks;
        bool i2_stop_nest_clks;

        fapi2::buffer<uint64_t> scom_data;
        fapi2::buffer<uint32_t> cfam_data;
        uint64_t clock_status = 0;

        FAPI_INF("********* cen_stopclocks start *********");
        // The instructions for coding this procedure came from Tobias Webel's Common POR Spreadsheet step 30.1
        // Start with instructions common to all eclipz chips

        // Set flushmode_inhibit in Chiplet GP0
        // Set force_align in Chiplet GP0
        // Write ClockControl, Scan Region Register, set all bits to zero prior clock stop
        // Write ClockControl, Clock Region Register, Clock Stop command (arrays + nsl only, not refresh clock region) MEM chiplet
        // Write ClockControl, Clock Region Register, Clock Stop command (sl + refresh clock region) MEM chiplet
        // Read Clock Status Register (MEM chiplet)
        // Write ClockControl, Clock Region Register, Clock Stop command (arrays + nsl only, not refresh clock region) NEST chiplet
        // Write ClockControl, Clock Region Register, Clock Stop command (sl + refresh clock region) NEST chiplet
        // Read Clock Status Register (NEST chiplet)
        // Reset MemReset Stablilty Control
        // Reset D3PHY PLL Control (Reset all PLLs)
        // reset abist_mode_dc for core chiplets (core recovery)
        // set synclk_muxsel (io_clk_sel)
        // assert perv fence GP0.63
        // GP3(28) disable EDRAM (just chiplets with EDRAM logic)(skip this step if refresh clock domain stays running)
        // assert fence GP3.18

        // The following instructions were added by Jeshua Smith to put each chiplet in a good state for scanning:
        // Set tc_scan_dis_dc_b to a '1' in each chiplet to allow rings to be scanned.

        // Note:  This procedure should not do multicast to do all non-perv chiplets at the same time because the user could
        //        wish to skip some of the chiplets!

        //-----------------
        //   Check options, VITL clock and PCB fabric clocks.   @@@
        //-----------------

        i2_stop_mem_clks  = i_stop_mem_clks;
        i2_stop_nest_clks = i_stop_nest_clks;

        // Before attempting to stop the clocks in any chiplet, check to see that the pervasive VITL clocks are running.
        // Do this by checking bit 16 of the PERV GP3 register.
        FAPI_DBG("Checking PERV GPP3 Register bit 16 to see if the VITL clock is ON.");
        FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_PERV_GP3, cfam_data), "Error getting PERV GP3 via CFAM");

        if (cfam_data.getBit(PERVGP3_VITL_CLKOFF_BIT))
        {
            // The Pervasive VITL clock is OFF. So we cannot talk to the chiplets.  There is nothing left to do, so just return.
            FAPI_INF("The Pervasive VITL clock is OFF.  The procedure cannot access the chiplets or check other clocks.");
            return fapi2::current_err;
        }

        // If we have gotten this far the Pervasive VITL clock must be ON.
        // Check to see if the PCB fabric clocks are running.
        // Do this by checking the PIB and NET clock regions in the TP chiplet (chiplet 01).
        // Read Clock Status Register (TP chiplet)   0x0100008
        // Bits 3-8 should be ZERO if the PIB and NET clocks are running.
        FAPI_DBG("Reading Clock Status Register in the TP chiplet to see if PIB and NET clocks are running. Bits 3-8 should be zero.");
        FAPI_TRY(fapi2::getScom( i_target, CEN_CLOCK_STAT_PCB, scom_data), "Error reading TP chiplet Clock Status Register.");

        if ( scom_data.getBit(TP_CLK_STAT_NET_SL)  ||
             scom_data.getBit(TP_CLK_STAT_NET_NSL) ||
             scom_data.getBit(TP_CLK_STAT_NET_ARY) ||
             scom_data.getBit(TP_CLK_STAT_PIB_SL)  ||
             scom_data.getBit(TP_CLK_STAT_PIB_NSL) ||
             scom_data.getBit(TP_CLK_STAT_PIB_ARY) )
        {
            // At least one of the NET or PIB clocks is NOT running.
            FAPI_INF("At least one of the NET or PIB clocks is NOT running.  May not be able to use the PCB fabric to access chiplets.");
            FAPI_INF("Procedure will not attempt to turn off clocks in the individual chiplets..");
            i2_stop_mem_clks  = false;
            i2_stop_nest_clks = false;
        }

        FAPI_INF("   Input parameters: ");
        FAPI_INF("       stop_mem_clks        = %s", i2_stop_mem_clks       ? "true" : "false");
        FAPI_INF("       stop_nest_clks       = %s", i2_stop_nest_clks      ? "true" : "false");
        FAPI_INF("       stop_dram_refresh_clks = %s", i_stop_dram_refresh_clks ? "true" : "false");
        FAPI_INF("       stop_tp_clks         = %s", i_stop_tp_clks         ? "true" : "false");
        FAPI_INF("       stop_vitl_clks       = %s", i_stop_vitl_clks       ? "true" : "false");

        if ((!i2_stop_mem_clks)  &&
            (!i2_stop_nest_clks) &&
            (!i_stop_tp_clks)    &&
            (!i_stop_vitl_clks))
        {
            FAPI_INF("Specified input options are set to skip both the NEST and MEM chiplets, so there is nothing to do.  Returning.");
            return fapi2::current_err;
        }

        //-----------------
        //   MEM Chiplet @@@ 03
        //-----------------
        if ( i2_stop_mem_clks )
        {
            // FW team requested that we check to see if the vital clock region is running before stopping the clocks.
            // If the vital clocks are not running, then other clocks are not running either, so we are done.
            // If the vital clocks are running, then we should be able to access the necessary registers to stop the other clocks.
            FAPI_DBG("Reading GP3 Register, bit 16, to see if VITAL clocks are running.");
            FAPI_TRY(fapi2::getScom( i_target, CEN_PCBSLMEM_GP3_REG_PCB, scom_data),
                     "Error reading GP3 register in attempt to verify that VITAL clocks are running.");

            if (scom_data.getBit(GP3_VITAL_THOLD_BIT))
            {
                // The VITAL thold is asserted, so no clocks are running in this chiplet.   Nothing left to do, so just return.
                FAPI_INF("The VITAL clocks are not running for this chiplet, so all other clocks should be already stopped.");
            }
            else
            {
                // Start with instructions common to eclipz chips

                // Set flushmode_inhibit in Chiplet GP0
                // multicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(2) = 0b1  (0x2000 0000 0000 0000)
                // CEN_TCM_GP0_PCB2
                FAPI_DBG("Setting flushmode_inhibit in MEM chiplet GP0 Register (bit 2).");
                scom_data.flush<0>();
                scom_data.setBit<GP0_FLUSHMODE_INHIBIT_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCM_GP0_PCB2, scom_data),
                         "Error writing GP0 registers in MEM chiplet to set flushmode inhibit (bit 2).");

                // Set force_align in Chiplet GP0
                // multicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(3) = 0b1  (0x1000 0000 0000 0000)   Cannot combine with previous step.
                // CEN_TCM_GP0_PCB2
                FAPI_DBG("Setting force_align in MEM chiplet GP0 register (bit 3).");
                scom_data.flush<0>();
                scom_data.setBit<GP0_FORCE_ALIGN_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCM_GP0_PCB2, scom_data),
                         "Error writing GP0 registers in MEM chiplet to set force_align (bit 3).");

                // Write ClockControl, Scan Region Register, set all bits to zero prior clock stop
                // multicast address 0x[xx]03 0007    Data:  0x0000 0000 0000 0000
                // CEN_TCM_SCANSELQ_PCB
                FAPI_DBG("Writing Clock Control Scan Region Register to all zeros in MEM chiplet prior clock stop.");
                scom_data.flush<0>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCM_SCANSELQ_PCB, scom_data),
                         "Error writing CC Scan Region Registers in MEM chiplet.");

                // Now do Centaur-specific instructions

                // Write ClockControl, Clock Region Register, Clock Stop command for MEM chiplet
                // 0x0303 0006 Data: 0x8FE00E0000000000
                // CEN_TCM_CLK_REGION_PCB
                FAPI_DBG("Writing Clock Control Clock Region Register in MEM chiplet to stop the clocks.");
                scom_data.insert<0, 64>(CLK_REGION_REG_DATA_TO_STOP_ALL);
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCM_CLK_REGION_PCB, scom_data),
                         "Error writing MEM chiplet CC Clock Region Register to stop the clocks.");

                // Read Clock Status Register (MEM chiplet)
                // 0x0303 0008  Data: expected value: 0xFFFF FFFF FFFF FFFF
                // CEN_TCM_CLOCK_STAT_PCB
                FAPI_DBG("Reading Clock Status Register in the MEM chiplet to see if clocks are stopped. Expected value = 0xFFFF FFFF FFFF FFFF.");
                FAPI_TRY(fapi2::getScom( i_target, CEN_TCM_CLOCK_STAT_PCB, scom_data),
                         "Error reading MEM chiplet Clock Status Register.");
                scom_data.extract<0, 64>(clock_status);
                FAPI_ASSERT(clock_status == EXPECTED_CLOCK_STATUS,
                            fapi2::CEN_MSS_UNEXPECTED_MEM_CLOCK_STATUS().
                            set_EXPECTED_STATUS(EXPECTED_CLOCK_STATUS).
                            set_ACTUAL_STATUS(clock_status).
                            set_MEMBUF_CHIP_IN_ERROR(i_target),
                            "MEM chiplet clock status 0x%016llX was expected but read clock status = 0x%016llX",
                            EXPECTED_CLOCK_STATUS, clock_status);

                FAPI_INF("Expected clock status was read in MEM chiplet after stopping the clocks: 0x%016llX ", EXPECTED_CLOCK_STATUS);

                // Reset MemReset Stablilty Control
                // CFAM 0x13  bit(02) = 0
                // CEN_FSIGP4
                FAPI_DBG("Clearing CFAM FSI GP4 Register, bit 2 to reset MemReset Stablilty Control.");
                FAPI_TRY(fapi2::getCfamRegister( i_target, CEN_FSIGP4, cfam_data), "Error reading CFAM FSI GP4 Register.");
                cfam_data.clearBit<FSI_GP4_MEMRESET_STABILITY_BIT>();
                FAPI_TRY(fapi2::putCfamRegister( i_target, CEN_FSIGP4, cfam_data) ,
                         "Error writing FSI GP4 Register to reset the MemReset Stability Control (bit2).");


                // Reset D3PHY PLL Control (Reset all D3PHY PLLs)
                // CFAM 0x13  bit(04) = 0
                // CEN_FSIGP4
                FAPI_DBG("Clearing CFAM FSI GP4 Register, bit 4 to reset D3PHY PLL Control (Reset all D3PHY PLLs).");
                FAPI_TRY(fapi2::getCfamRegister( i_target, CEN_FSIGP4, cfam_data), "Error reading CFAM FSI GP4 register.");
                cfam_data.clearBit<FSI_GP4_DPHY_PLLRESET_BIT>();
                FAPI_TRY(fapi2::putCfamRegister( i_target, CEN_FSIGP4, cfam_data),
                         "Error writing FSI GP4 register to reset the D3PHY PLLs (by clearing bit 4).");

                // Resume instructions that are common to eclipz chips.
                //
                // reset abist_mode_dc for core chiplets (core recovery)
                // Does this make sense for Centaur?   (Centaur has no cores.)
                // Multicast address: "0x[xx]00 0004  WAND codepoint" Data: bit(11) = 0b0   0xFFEF FFFF FFFF FFFF
                // CEN_TCM_GP0_PCB1
                FAPI_DBG("Clearing GP0 Register bit 11 in MEM chiplet to reset abist_mode_dc.");
                scom_data.flush<1>();
                scom_data.clearBit<GP0_ABIST_MODE_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCM_GP0_PCB1, scom_data),
                         "Error writing the GP0 registers in the MEM chiplet to reset abist mode..");

                // set synclk_muxsel (io_clk_sel)
                // Multicast address: "0x[xx]00 0005  WOR codepoint"  bit(1) = 0b1   0x4000 0000 0000 0000
                // CEN_TCM_GP0_PCB2
                // assert perv fence GP0.63
                // Multicast address: "0x[xx]00 0005  WOR codepoint"  bit(63) = 0b1  0x4000 0000 0000 0001  (Can be combined with previous step)
                // CEN_TCM_GP0_PCB2
                FAPI_DBG("Setting GP0 Register bit 1 in MEM chiplet to set synclk_muxsel (io_clk_sel).");
                FAPI_DBG("Setting GP0 Register bit 63 in MEM chiplet to assert the pervasive fence.");
                scom_data.flush<0>();
                scom_data.setBit<GP0_SYNCCLK_MUXSEL_BIT>();
                scom_data.setBit<GP0_PERV_FENCE_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCM_GP0_PCB2, scom_data),
                         "Error writing GP0 registers in MEM chiplet to set syncclk_muxsel and pervasive fence..");

                // GP3(28) disable EDRAM (just chiplets with EDRAM logic)
                // Note: This action is probably un-needed for the MEM chiplet since it does not contain any EDRAM.
                // Multicast address: "0x[xx]0F 0013  WAND codepoint"   bit(28) = 0b0   0xFFFF FFF7 FFFF FFFF
                // CEN_PCBSLMEM_GP3_REG_PCB1
                FAPI_DBG("Clearing GP3 Register bit 28 in MEM chiplet to disable any EDRAM.");
                scom_data.flush<1>();
                scom_data.clearBit<GP3_EDRAM_ENABLE_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_PCBSLMEM_GP3_REG_PCB1, scom_data),
                         "Error writing GP3 Registers in MEM chiplet to disable any EDRAM.");

                // assert fence GP3.18
                // Multicast address: "0x[xx]0F 0014  WOR codepoint"  bit(18) = 0b1   0x0000 2000 0000 0000
                // CEN_PCBSLMEM_GP3_REG_PCB2
                FAPI_DBG("Setting GP3 Regsiter bit 18 in MEM chiplet to assert the fence.");
                scom_data.flush<0>();
                scom_data.setBit<GP3_FENCE_EN_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_PCBSLMEM_GP3_REG_PCB2, scom_data),
                         "Error writing GP3 registers in MEM chiplet to assert the fence." );

                // Set scan_dis_dc_b bit in Chiplet GP0
                // unicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(6) = 0b1  (0x0200 0000 0000 0000)
                // CEN_TCM_GP0_PCB2
                FAPI_DBG("Setting MEM chiplet GP0 Register bit 6 to set scan_dis_dc_b to allow for scanning.");
                scom_data.flush<0>();
                scom_data.setBit<GP0_SCAN_DIS_DC_B_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCM_GP0_PCB2, scom_data),
                         "Error writing MEM chiplet GP0 register to set scan_dis_dc_b for scanning.");
            }  // End of stop clock operations that are done if the vital clock is running.
        }  // End of MEM chiplet code


        //-----------------
        //   NEST Chiplet @@@ 02
        //-----------------
        if ( i2_stop_nest_clks )
        {
            // FW team requested that we check to see if the vital clock region is running before stopping the clocks.
            // If the vital clocks are not running, then other clocks are not running either, so we are done.
            // If the vital clocks are running, then we should be able to access the necessary registers to stop the other clocks.
            FAPI_DBG("Reading GP3 Register, bit 16, to see if VITAL clocks are running.");
            FAPI_TRY(fapi2::getScom( i_target, CEN_PCBSLNEST_GP3_REG_PCB, scom_data),
                     "Error reading GP3 register in attempt to verify that VITAL clocks are running.");

            if (scom_data.getBit(GP3_VITAL_THOLD_BIT))
            {
                // The VITAL thold is asserted, so no clocks are running in this chiplet.   Nothing left to do, so just return.
                FAPI_INF("The VITAL clocks are not running for this chiplet, so all other clocks should be already stopped.");
            }
            else
            {
                // Start with instructions common to eclipz chips

                // Set flushmode_inhibit in Chiplet GP0
                // multicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(2) = 0b1  (0x2000 0000 0000 0000)
                // CEN_TCN_GP0_PCB2
                FAPI_DBG("Setting flushmode_inhibit in NEST chiplet GP0 Register (bit 2).");
                scom_data.flush<0>();
                scom_data.setBit<GP0_FLUSHMODE_INHIBIT_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCN_GP0_PCB2, scom_data),
                         "Error writing GP0 registers in NEST chiplet to set flushmode inhibit (bit 2).");

                // Set force_align in Chiplet GP0
                // multicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(3) = 0b1  (0x1000 0000 0000 0000)   Cannot combine with previous step.
                // CEN_TCN_GP0_PCB2
                FAPI_DBG("Setting force_align in NEST chiplet GP0 register (bit 3).");
                scom_data.flush<0>();
                scom_data.setBit<GP0_FORCE_ALIGN_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCN_GP0_PCB2, scom_data),
                         "Error writing GP0 registers in NEST chiplet to set force_align (bit 3).");

                // Write ClockControl, Scan Region Register, set all bits to zero prior clock stop
                // multicast address 0x[xx]03 0007    Data:  0x0000 0000 0000 0000
                // CEN_TCN_SCANSELQ_PCB
                FAPI_DBG("Writing Clock Control Scan Region Register to all zeros in NEST chiplet prior clock stop.");
                scom_data.flush<0>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCN_SCANSELQ_PCB, scom_data),
                         "Error writing CC Scan Region Registers in NEST chiplet.");

                // Now do Centaur-specific instructions

                // Write ClockControl, Clock Region Register, Clock Stop command for NEST chiplet
                // 0x0203 0006  Data: 0x8FE00E0000000000
                // CEN_TCN_CLK_REGION_PCB
                FAPI_DBG("Writing Clock Control Clock Region Register in NEST chiplet to stop the clocks.");

                if ( i_stop_dram_refresh_clks )
                {
                    scom_data.insert<0, 64>(CLK_REGION_REG_DATA_TO_STOP_ALL);
                }
                else
                {
                    scom_data.insert<0, 64>( CLK_REGION_STOP_ALL_BUT_REFRESH );
                }

                FAPI_TRY(fapi2::putScom( i_target, CEN_TCN_CLK_REGION_PCB, scom_data),
                         "Error writing NEST chiplet CC Clock Region Register to stop the clocks.");

                // Read Clock Status Register (NEST chiplet)
                // 0x0203 0008  Data: expected value: 0xFFFF FFFF FFFF FFFF
                // CEN_TCN_CLOCK_STAT_PCB
                if ( i_stop_dram_refresh_clks )
                {
                    FAPI_DBG("Reading Clock Status Register in the NEST chiplet to see if clocks are stopped. Expected value = 0xFFFF FFFF FFFF FFFF.");
                    FAPI_TRY(fapi2::getScom( i_target, CEN_TCN_CLOCK_STAT_PCB, scom_data),
                             "Error reading NEST chiplet Clock Status Register.");
                    scom_data.extract<0, 64>(clock_status);
                    FAPI_ASSERT(clock_status == EXPECTED_CLOCK_STATUS,
                                fapi2::CEN_MSS_UNEXPECTED_NEST_CLOCK_STATUS().
                                set_EXPECTED_STATUS(EXPECTED_CLOCK_STATUS).
                                set_ACTUAL_STATUS(clock_status).
                                set_MEMBUF_CHIP_IN_ERROR(i_target),
                                "NEST chiplet clock status 0x%016llX was expected but read clock status = 0x%016llX",
                                EXPECTED_CLOCK_STATUS, clock_status);
                    FAPI_INF("Expected clock status was read in NEST chiplet after stopping the clocks: 0x%016llX ", EXPECTED_CLOCK_STATUS);
                }
                else
                {
                    FAPI_DBG("Reading Clock Status Register in the NEST chiplet to see if clocks are stopped. Expected value = 0xFFFF FF1F FFFF FFFF.");
                    FAPI_TRY(fapi2::getScom( i_target, CEN_TCN_CLOCK_STAT_PCB, scom_data),
                             "Error reading NEST chiplet Clock Status Register.");
                    scom_data.extract<0, 64>(clock_status);
                    FAPI_ASSERT(clock_status == EXPECTED_CLOCK_STATUS_W_REFRESH,
                                fapi2::CEN_MSS_UNEXPECTED_NEST_CLOCK_STATUS().
                                set_EXPECTED_STATUS(EXPECTED_CLOCK_STATUS).
                                set_ACTUAL_STATUS(clock_status).
                                set_MEMBUF_CHIP_IN_ERROR(i_target),
                                "NEST chiplet clock status 0x%016llX was expected but read clock status = 0x%016llX",
                                EXPECTED_CLOCK_STATUS, clock_status);

                    FAPI_INF("Expected clock status was read in NEST chiplet after stopping the clocks: 0x%016llX ",
                             EXPECTED_CLOCK_STATUS_W_REFRESH);
                }


                // Resume instructions that are common to eclipz chips.


                // reset abist_mode_dc for core chiplets (core recovery)
                // Does this make sense for Centaur?   (Centaur has no cores.)
                // Multicast address: "0x[xx]00 0004  WAND codepoint" Data: bit(11) = 0b0   0xFFEF FFFF FFFF FFFF
                // CEN_TCN_GP0_PCB1
                FAPI_DBG("Clearing GP0 Register bit 11 in NEST chiplet to reset abist_mode_dc.");
                scom_data.flush<1>();
                scom_data.clearBit<GP0_ABIST_MODE_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCN_GP0_PCB1, scom_data),
                         "Error writing the GP0 registers in the NEST chiplet to reset abist mode..");

                // set synclk_muxsel (io_clk_sel)
                // Multicast address: "0x[xx]00 0005  WOR codepoint"  bit(1) = 0b1   0x4000 0000 0000 0000
                // CEN_TCN_GP0_PCB2
                // assert perv fence GP0.63
                // Multicast address: "0x[xx]00 0005  WOR codepoint"  bit(63) = 0b1  0x4000 0000 0000 0001  (Can be combined with previous step)
                // CEN_TCN_GP0_PCB2
                FAPI_DBG("Setting GP0 Register bit 1 in NEST chiplet to set synclk_muxsel (io_clk_sel).");
                FAPI_DBG("Setting GP0 Register bit 63 in NEST chiplet to assert the pervasive fence.");
                scom_data.flush<0>();
                scom_data.setBit<GP0_SYNCCLK_MUXSEL_BIT>();
                scom_data.setBit<GP0_PERV_FENCE_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCN_GP0_PCB2, scom_data),
                         "Error writing GP0 registers in NEST chiplet to set syncclk_muxsel and pervasive fence..");

                // GP3(28) disable EDRAM (just chiplets with EDRAM logic)
                // Note:  (skip this step if refresh clock domain stays running)
                // Multicast address: "0x[xx]0F 0013  WAND codepoint"   bit(28) = 0b0   0xFFFF FFF7 FFFF FFFF
                // CEN_PCBSLNEST_GP3_REG_PCB1
                if ( i_stop_dram_refresh_clks )
                {
                    FAPI_DBG("Clearing GP3 Register bit 28 in NEST chiplet to disable any EDRAM.");
                    scom_data.flush<1>();
                    scom_data.clearBit<GP3_EDRAM_ENABLE_BIT>();
                    FAPI_TRY(fapi2::putScom( i_target, CEN_PCBSLNEST_GP3_REG_PCB1, scom_data),
                             "Error writing GP3 Registers in NEST chiplet to disable any EDRAM.");
                }


                // assert fence GP3.18
                // Multicast address: "0x[xx]0F 0014  WOR codepoint"  bit(18) = 0b1   0x0000 2000 0000 0000
                // CEN_PCBSLNEST_GP3_REG_PCB2
                FAPI_DBG("Setting GP3 Regsiter bit 18 in NEST chiplet to assert the fence.");
                scom_data.flush<0>();
                scom_data.setBit<GP3_FENCE_EN_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_PCBSLNEST_GP3_REG_PCB2, scom_data),
                         "Error writing GP3 registers in NEST chiplet to assert the fence.");

                // Set scan_dis_dc_b bit in Chiplet GP0
                // unicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(6) = 0b1  (0x0200 0000 0000 0000)
                // CEN_TCN_GP0_PCB2
                FAPI_DBG("Setting NEST chiplet GP0 Register bit 6 to set scan_dis_dc_b to allow for scanning.");
                scom_data.flush<0>();
                scom_data.setBit<GP0_SCAN_DIS_DC_B_BIT>();
                FAPI_TRY(fapi2::putScom( i_target, CEN_TCN_GP0_PCB2, scom_data),
                         "Error writing NEST chiplet GP0 register to set scan_dis_dc_b for scanning.");
            }  // End of stop clock operations that are done if the vital clock is running.
        }  // End of NEST chiplet code



        //-----------------
        //   TP Chiplet @@@ 01
        //-----------------

        if (i_stop_tp_clks)
        {

            // Set the length of the FSI shifter set pulse
            // Do this in the CFAM FSI SHIFT_CONTROL_REGISTER_2.
            FAPI_DBG("Setting length of the set pulse in the FSI SHIFT_CONTROL_REGISTER_2.");
            cfam_data.insert<0, 32>(FSI_SHIFT_SET_PULSE_LENGTH); //Set cfam_data to 0x0000000F
            FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSI_SHIFT_SHIFT_CONTROL_REGISTER_2, cfam_data),
                     "Error attempting to set length of the set pulse in the FSI SHIFT_CONTROL_REGISTER_2.");

            // Go into PIB2PCB bypass path
            // Set this in CFAM GP3 register.  Read the register first to preserve other contents.
            FAPI_DBG("Setting FSI GP3 bit 20 to go into PIB2PCB bypass.");
            FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_FSIGP3, cfam_data), "Error getting FSI_GP3 via CFAM");
            cfam_data.setBit<FSIGP3_PIB2PCB_BYPASS_BIT>(); //Set bit 20 to go into PIB2PCB bypass
            FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSIGP3, cfam_data), "Error attempting to go into PIB2PCB bypass.");


            // Set flushmode_inhibit in Chiplet GP0
            // unicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(2) = 0b1  (0x2000 0000 0000 0000)
            // CEN_GP0_PCB2
            FAPI_DBG("Setting TP chiplet GP0 Register bit 2 to set flushmode_inhibit.");
            scom_data.flush<0>();
            scom_data.setBit<GP0_FLUSHMODE_INHIBIT_BIT>();
            FAPI_TRY(fapi2::putScom( i_target, CEN_GP0_PCB2, scom_data),
                     "Error writing TP chiplet GP0 register to set flushmode inhibit.");

            // Set force_align in Chiplet GP0
            // unicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(3) = 0b1  (0x1000 0000 0000 0000)   Cannot combine with previous step.
            // CEN_GP0_PCB2
            FAPI_DBG("Setting TP chiplet GP0 Register bit 3 to set force_align.");
            scom_data.flush<0>();
            scom_data.setBit<GP0_FORCE_ALIGN_BIT>();
            FAPI_TRY(fapi2::putScom( i_target, CEN_GP0_PCB2, scom_data),
                     "Error writing TP chiplet GP0 register to set force_align.");

            // Write ClockControl, Scan Region Register, set all bits to zero prior clock stop
            // unicast address 0x[xx]03 0007    Data:  0x0000 0000 0000 0000
            // CEN_SCANSELQ_PCB
            FAPI_DBG("Writing TP chiplet Clock Control Scan Region Register to all zeros prior clock stop.");
            scom_data.flush<0>();
            FAPI_TRY(fapi2::putScom( i_target, CEN_SCANSELQ_PCB, scom_data), "Error writing TP chiplet CC Scan Region Register.");
            // Write ClockControl, Clock Region Register, Clock Stop command (arrays + nsl only, not refresh clock region) TP chiplet
            // CEN_CLK_REGION_PCB
            FAPI_DBG("Writing Clock Control Clock Region Register in TP chiplet to stop the clocks.");
            scom_data.flush<1>();
            scom_data.insertFromRight(CLK_REGION_CLOCK_CMD_STOP,
                                      CLK_REGION_CLOCK_CMD_BIT,
                                      CLK_REGION_CLOCK_CMD_LEN);
            FAPI_TRY(fapi2::putScom( i_target, CEN_CLK_REGION_PCB, scom_data),
                     "Error writing TP chiplet CC Clock Region Register to stop the clocks.");

            // Read Clock Status Register (TP chiplet)
            // 0x0103 0008  Data: expected value: FFFFFFFFFFFFFFFF
            // CEN_CLOCK_STAT_PCB
            FAPI_DBG("Reading Clock Status Register in the TP chiplet to see if clocks are stopped. Expected value = 0x%016llX.",
                     EXPECTED_CLOCK_STATUS);
            scom_data.extract<0, 64>(clock_status);
            FAPI_ASSERT(clock_status == EXPECTED_CLOCK_STATUS,
                        fapi2::CEN_MSS_UNEXPECTED_TP_CLOCK_STATUS().
                        set_EXPECTED_STATUS(EXPECTED_CLOCK_STATUS).
                        set_ACTUAL_STATUS(clock_status).
                        set_MEMBUF_CHIP_IN_ERROR(i_target),
                        "TP chiplet clock status 0x%016llX was expected but read clock status = 0x%016llX.",
                        EXPECTED_CLOCK_STATUS, clock_status);
            FAPI_INF("Expected clock status was read in TP chiplet after stopping the clocks: 0x%016llX ", EXPECTED_CLOCK_STATUS);

            // Set L3 EDRAM fence in chiplet by setting bit(19) in chiplet GP0 registers  (Fence only exists in EX chiplets.)


            // Resume instructions that are common to all eclipz chips.


            // reset abist_mode_dc for core chiplets only (core recovery)


            // set synclk_muxsel (io_clk_sel)
            // Unicast address: "0x[xx]00 0005  WOR codepoint"  bit(1) = 0b1   0x4000 0000 0000 0000
            // CEN_GP0_PCB2
            // assert perv fence GP0.63
            // Unicast address: "0x[xx]00 0005  WOR codepoint"  bit(63) = 0b1  0x4000 0000 0000 0001  (Can be combined with previous step)
            // CEN_GP0_PCB2
            FAPI_DBG("Setting TP chiplet GP0 Register bit 1 to set synclk_muxsel (io_clk_sel).");
            FAPI_DBG("Setting TP chiplet GP0 Register bit 63 to assert the pervasive fence.");
            scom_data.flush<0>();
            scom_data.setBit<GP0_SYNCCLK_MUXSEL_BIT>();
            scom_data.setBit<GP0_PERV_FENCE_BIT>();
            FAPI_TRY(fapi2::putScom( i_target, CEN_GP0_PCB2, scom_data),
                     "Error writing TP chiplet GP0 register to set syncclk_muxsel and pervasive fence..");

            // GP3(28) disable EDRAM (just chiplets with EDRAM logic)


            // Instruction from Johannes Koesters   12 Sept, 2013
            // Leave this commented out for now.   Seems to cause problems if we set the fence on the TP chiplet.
            //
            // Change this to use PERV GP3 Register  (CFAM 101B)  (Normal GP3 reg N/A in TP chiplet) ?
            //// assert fence GP3.18
            //// Unicast address: "0x[xx]0F 0014  WOR codepoint"  bit(18) = 0b1   0x0000 2000 0000 0000
            //// TP_GP3_OR_0x010F0014
            //FAPI_DBG("Setting TP chiplet GP3 Regsiter bit 18 to assert the fence.");
            //scom_data.flush<0>();
            //scom_data.setBit<GP3_FENCE_EN_BIT>();
            //FAPI_TRY(fapi2::putScom( i_target, TP_GP3_OR_0x010F0014, scom_data));

            // Set scan_dis_dc_b bit in Chiplet GP0
            // unicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(6) = 0b1  (0x0200 0000 0000 0000)
            // CEN_GP0_PCB2
            FAPI_DBG("Setting TP chiplet GP0 Register bit 6 to set scan_dis_dc_b to allow for scanning.");
            scom_data.flush<0>();
            scom_data.setBit<GP0_SCAN_DIS_DC_B_BIT>();
            FAPI_TRY(fapi2::putScom( i_target, CEN_GP0_PCB2, scom_data),
                     "Error writing TP chiplet GP0 register to set scan_dis_dc_b for scanning.");
        }  // End of TP Chiplet clock section



        //-----------------
        //   VITL Clocks @@@ 00
        //-----------------

        if (i_stop_vitl_clks)
        {

            // Set the length of the FSI shifter set pulse
            // Do this in the CFAM FSI SHIFT_CONTROL_REGISTER_2.
            FAPI_DBG("Setting length of the set pulse in the FSI SHIFT_CONTROL_REGISTER_2.");
            cfam_data.insert<0, 32>(FSI_SHIFT_SET_PULSE_LENGTH); //Set cfam_data to 0x0000000F
            FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSI_SHIFT_SHIFT_CONTROL_REGISTER_2, cfam_data),
                     "Error attempting to set length of the set pulse in the FSI SHIFT_CONTROL_REGISTER_2.");


            // Disable the VITL clocks
            // Set this in PERV GP3 register.  Read the register first to preserve other contents.
            FAPI_DBG("Setting PERV GPP3 Register bit 16 to turn OFF the VITL clock.");
            FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_PERV_GP3, cfam_data), "Error getting PERV GP3 via CFAM");
            cfam_data.setBit<PERVGP3_VITL_CLKOFF_BIT>(); //Set bit 16 to turn OFF VITL clock
            FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_PERV_GP3, cfam_data),
                     "Error attempting to set PERV GP3 Reg bit 16 to stop the VITL clocks.");


            // Set Some FSI fences
            // Set this in CFAM GP3 register.  Read the register first to preserve other contents.
            FAPI_DBG("Setting FSI GP3 bits 25 and,26 to set FSI fences 4 and 5.");
            FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_FSIGP3, cfam_data), "Error getting FSI_GP3 via CFAM");
            cfam_data.setBit<FSIGP3_FSI_FENCE4_BIT>(); //Set bits 25 to set FSI fence 4
            cfam_data.setBit<FSIGP3_FSI_FENCE5_BIT>(); //Set bits 26 to set FSI fence 5
            FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSIGP3, cfam_data),
                     "Error attempting to set FSI fences in FSI GP3 register.");
        }  // End of VITL clock section


        FAPI_INF("********* cen_stopclocks complete *********");
    fapi_try_exit:
        return fapi2::current_err;
    }

} //end extern C
