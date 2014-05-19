/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/cen_stopclocks/cen_stopclocks.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: cen_stopclocks.C,v 1.16 2014/01/16 17:49:16 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_stopclocks.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_stopclocks
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! SCREEN      : pervasive_screen
// *! ADDITIONAL COMMENTS :
//
// The purpose of this procedure is to stop the clocks in the Centaur chip
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_scom_addresses.H>
#include <cen_stopclocks.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
// CFAM FSI GP4 register bit/field definitions
const uint8_t FSI_GP4_MEMRESET_STABILITY_BIT  = 2;
const uint8_t FSI_GP4_DPHY_PLLRESET_BIT       = 4;

// PERVGP3 register bit/field definitions
const uint8_t PERVGP3_VITL_CLKOFF_BIT   = 16;

// GP3 register bit/field definitions
const uint8_t GP3_VITAL_THOLD_BIT       = 16;
const uint8_t GP3_FENCE_EN_BIT          = 18;
const uint8_t GP3_EDRAM_ENABLE_BIT      = 28;

// GP0 register bit/field definitions
const uint8_t GP0_SYNCCLK_MUXSEL_BIT    = 1;
const uint8_t GP0_FLUSHMODE_INHIBIT_BIT = 2;
const uint8_t GP0_FORCE_ALIGN_BIT       = 3;
const uint8_t GP0_SCAN_DIS_DC_B_BIT     = 6;
const uint8_t GP0_ABIST_MODE_BIT        = 11;
const uint8_t GP0_PERV_FENCE_BIT        = 63;

// FSIGP3 register bit/field definitions
const uint8_t FSIGP3_PIB2PCB_BYPASS_BIT = 20;
const uint8_t FSIGP3_FSI_FENCE4_BIT     = 25;
const uint8_t FSIGP3_FSI_FENCE5_BIT     = 26;

// Global bit definitions for all CLK_REGIONS
const uint8_t CLK_REGION_CLOCK_CMD_BIT      = 0;
const uint8_t CLK_REGION_CLOCK_CMD_LEN      = 2;
const uint8_t CLK_REGION_CLOCK_CMD_STOP     = 2;

const uint8_t TP_CLK_STAT_NET_SL            = 3;
const uint8_t TP_CLK_STAT_NET_NSL           = 4;
const uint8_t TP_CLK_STAT_NET_ARY           = 5;
const uint8_t TP_CLK_STAT_PIB_SL            = 6;
const uint8_t TP_CLK_STAT_PIB_NSL           = 7;
const uint8_t TP_CLK_STAT_PIB_ARY           = 8;


// Clock Region Register clock stop data patterns
// const uint64_t CLK_REGION_REG_DATA_TO_STOP_NSL_ARY = 0x8FE0060000000000ull;
const uint64_t CLK_REGION_REG_DATA_TO_STOP_ALL     = 0x8FE00E0000000000ull;
// const uint64_t CLK_REGION_STOP_NSL_ARY_W_REFRESH   = 0x8FC0060000000000ull;
const uint64_t CLK_REGION_STOP_ALL_BUT_REFRESH     = 0x8FC00E0000000000ull;
const uint64_t EXPECTED_CLOCK_STATUS               = 0xFFFFFFFFFFFFFFFFull;
const uint64_t EXPECTED_CLOCK_STATUS_W_REFRESH     = 0xFFFFFF1FFFFFFFFFull;   // Bits 24,25,26 should be OFF for refresh clocks to be active.

// Expected CLK_STAT after execution of stopclocks
const uint32_t FSI_SHIFT_SET_PULSE_LENGTH      = 0x0000000F;




extern "C" {

using namespace fapi;

//------------------------------------------------------------------------------
// Function definition:  cen_stopclocks
// parameters: i_target                =>   chip target
//             i_stop_mem_clks         =>   True to stop MEM chiplet clocks                             (should default TRUE)
//             i_stop_nest_clks        =>   True to stop NEST chiplet clocks (except DRAM refresh clk)  (should default TRUE)
//             i_stop_dram_rfrsh_clks  =>   True to stop NEST chiplet DRAM refresh clocks (cache)       (should default FALSE)
//             i_stop_tp_clks          =>   True to stop PERVASIVE (TP) chiplet clocks                  (should default FALSE)
//             i_stop_vitl_clks        =>   True to stop PERVASIVE VITL clocks                          (should default FALSE)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode cen_stopclocks(const fapi::Target & i_target,
                                const bool i_stop_mem_clks,
                                const bool i_stop_nest_clks,
                                const bool i_stop_dram_rfrsh_clks,
                                const bool i_stop_tp_clks,
                                const bool i_stop_vitl_clks)
{
    // Target is centaur chip

    bool i2_stop_mem_clks;
    bool i2_stop_nest_clks;
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase scom_data(64);
    ecmdDataBufferBase cfam_data(32);

    FAPI_INF("********* cen_stopclocks start *********");
    do
    {
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
        // TODO - compare these instructions agains the P7+ procedure to see if we are missing anything.

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
        rc = fapiGetCfamRegister(i_target, CFAM_FSI_GP3_MIRROR_0x0000101B, cfam_data);
        if (rc)
        {
            FAPI_ERR("Error getting PERV GP3 via CFAM");
            break;
        }
        if (cfam_data.isBitSet(PERVGP3_VITL_CLKOFF_BIT))
        {
            // The Pervasive VITL clock is OFF. So we cannot talk to the chiplets.  There is nothing left to do, so just return.
            FAPI_INF("The Pervasive VITL clock is OFF.  The procedure cannot access the chiplets or check other clocks.");
            break;
        }

        // If we have gotten this far the Pervasive VITL clock must be ON.
        // Check to see if the PCB fabric clocks are running.
        // Do this by checking the PIB and NET clock regions in the TP chiplet (chiplet 01).
        // Read Clock Status Register (TP chiplet)   0x0100008  
        // Bits 3-8 should be ZERO if the PIB and NET clocks are running.
        FAPI_DBG("Reading Clock Status Register in the TP chiplet to see if PIB and NET clocks are running. Bits 3-8 should be zero.");
        rc = fapiGetScom( i_target, TP_CLK_STATUS_0x01030008, scom_data);
        if (rc)
        {
            FAPI_ERR("Error reading TP chiplet Clock Status Register.");
            break;
        }
        if ( scom_data.isBitSet(TP_CLK_STAT_NET_SL)  ||
             scom_data.isBitSet(TP_CLK_STAT_NET_NSL) ||
             scom_data.isBitSet(TP_CLK_STAT_NET_ARY) ||
             scom_data.isBitSet(TP_CLK_STAT_PIB_SL)  ||
             scom_data.isBitSet(TP_CLK_STAT_PIB_NSL) ||
             scom_data.isBitSet(TP_CLK_STAT_PIB_ARY) )
        {
            // At least one of the NET or PIB clocks is NOT running.
            FAPI_INF("At least one of the NET or PIB clocks is NOT running.  May not be able to use the PCB fabric to access chiplets.");
            FAPI_INF("Procedure will not attempt to turn off clocks in the individual chiplets..");
            i2_stop_mem_clks  = false;
            i2_stop_nest_clks = false;
        }

        FAPI_INF("   Input parameters: ");
        FAPI_INF("       stop_mem_clks        = %s", i2_stop_mem_clks       ? "true":"false");
        FAPI_INF("       stop_nest_clks       = %s", i2_stop_nest_clks      ? "true":"false");
        FAPI_INF("       stop_dram_rfrsh_clks = %s", i_stop_dram_rfrsh_clks ? "true":"false");
        FAPI_INF("       stop_tp_clks         = %s", i_stop_tp_clks         ? "true":"false");
        FAPI_INF("       stop_vitl_clks       = %s", i_stop_vitl_clks       ? "true":"false");

        if ((!i2_stop_mem_clks)  &&
            (!i2_stop_nest_clks) &&
            (!i_stop_tp_clks)    &&
            (!i_stop_vitl_clks))
        {
            FAPI_INF("Specified input options are set to skip both the NEST and MEM chiplets, so there is nothing to do.  Returning.");
            break;
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
            rc = fapiGetScom( i_target, MEM_GP3_0x030F0012, scom_data);
            if (rc)
            {
                FAPI_ERR("Error reading GP3 register in attempt to verify that VITAL clocks are running.");
                break;
            }
            if (scom_data.isBitSet(GP3_VITAL_THOLD_BIT))
            {
                // The VITAL thold is asserted, so no clocks are running in this chiplet.   Nothing left to do, so just return.
                FAPI_INF("The VITAL clocks are not running for this chiplet, so all other clocks should be already stopped.");
            }
            else
            {

                // Start with instructions common to eclipz chips
        
                // Set flushmode_inhibit in Chiplet GP0
                // multicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(2) = 0b1  (0x2000 0000 0000 0000)
                // MEM_GP0_OR_0x03000005
                FAPI_DBG("Setting flushmode_inhibit in MEM chiplet GP0 Register (bit 2).");
                rc_ecmd |= scom_data.flushTo0();
                rc_ecmd |= scom_data.setBit(GP0_FLUSHMODE_INHIBIT_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set flushmode_inhibit in MEM chiplet GP0 Register.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, MEM_GP0_OR_0x03000005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing GP0 registers in MEM chiplet to set flushmode inhibit (bit 2).");
                    break;
                }
        
        
                // Set force_align in Chiplet GP0
                // multicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(3) = 0b1  (0x1000 0000 0000 0000)   Cannot combine with previous step.
                // MEM_GP0_OR_0x03000005
                FAPI_DBG("Setting force_align in MEM chiplet GP0 register (bit 3).");
                rc_ecmd |= scom_data.flushTo0();
                rc_ecmd |= scom_data.setBit(GP0_FORCE_ALIGN_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to Set force_align in MEM chiplet.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, MEM_GP0_OR_0x03000005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing GP0 registers in MEM chiplet to set force_align (bit 3).");
                    break;
                }
        
        
                // Write ClockControl, Scan Region Register, set all bits to zero prior clock stop
                // multicast address 0x[xx]03 0007    Data:  0x0000 0000 0000 0000
                // MEM_CLK_SCANSEL_0x03030007
                FAPI_DBG("Writing Clock Control Scan Region Register to all zeros in MEM chiplet prior clock stop.");
                rc_ecmd |= scom_data.flushTo0();
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write CC Scan Region Register to all zeros..",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, MEM_CLK_SCANSEL_0x03030007, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing CC Scan Region Registers in MEM chiplet.");
                    break;
                }
        
        
                // Now do Centaur-specific instructions
        
        
        
                // Write ClockControl, Clock Region Register, Clock Stop command for MEM chiplet
                // 0x0303 0006 Data: 0x8FE00E0000000000
                // MEM_CLK_REGION_0x03030006
                FAPI_DBG("Writing Clock Control Clock Region Register in MEM chiplet to stop the clocks.");
                rc_ecmd |= scom_data.setDoubleWord(0, CLK_REGION_REG_DATA_TO_STOP_ALL);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set general clock stop command in MEM chiplet CC Clock Region Register.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, MEM_CLK_REGION_0x03030006, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing MEM chiplet CC Clock Region Register to stop the clocks.");
                    break;
                }
        
        
                // Read Clock Status Register (MEM chiplet)
                // 0x0303 0008  Data: expected value: 0xFFFF FFFF FFFF FFFF
                // MEM_CLK_STATUS_0x03030008
                FAPI_DBG("Reading Clock Status Register in the MEM chiplet to see if clocks are stopped. Expected value = 0xFFFF FFFF FFFF FFFF.");
                rc = fapiGetScom( i_target, MEM_CLK_STATUS_0x03030008, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error reading MEM chiplet Clock Status Register.");
                    break;
                }
                uint64_t clock_status = scom_data.getDoubleWord(0);
                if ( clock_status != EXPECTED_CLOCK_STATUS )
                {
                    FAPI_ERR("MEM chiplet clock status 0x%016llX was expected but read clock status = 0x%016llX",
                             EXPECTED_CLOCK_STATUS, clock_status);
                    const uint64_t & EXPECTED_STATUS = EXPECTED_CLOCK_STATUS;
                    const uint64_t & ACTUAL_STATUS = clock_status;
                    const fapi::Target & MEMBUF_CHIP_IN_ERROR = i_target;
                    FAPI_SET_HWP_ERROR(rc, RC_MSS_UNEXPECTED_MEM_CLOCK_STATUS);
                    break;
                }
                else
                {
                    FAPI_INF("Expected clock status was read in MEM chiplet after stopping the clocks: 0x%016llX ", EXPECTED_CLOCK_STATUS);
                }
        
        
        
                // Reset MemReset Stablilty Control
                // CFAM 0x13  bit(02) = 0
                // CFAM_FSI_GP4_0x00001013
                FAPI_DBG("Clearing CFAM FSI GP4 Register, bit 2 to reset MemReset Stablilty Control.");
                rc = fapiGetCfamRegister( i_target, CFAM_FSI_GP4_0x00001013, cfam_data);
                if (rc)
                {
                    FAPI_ERR("Error reading CFAM FSI GP4 Register.");
                    break;
                }
                rc_ecmd |= cfam_data.clearBit(FSI_GP4_MEMRESET_STABILITY_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set MemReset Stability Control (FSI GP4 bit 2).",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutCfamRegister( i_target, CFAM_FSI_GP4_0x00001013, cfam_data);
                if (rc)
                {
                    FAPI_ERR("Error writing FSI GP4 Register to reset the MemReset Stability Control (bit2).");
                    break;
                }
        
        
                // Reset D3PHY PLL Control (Reset all D3PHY PLLs)
                // CFAM 0x13  bit(04) = 0
                // CFAM_FSI_GP4_0x00001013
                FAPI_DBG("Clearing CFAM FSI GP4 Register, bit 4 to reset D3PHY PLL Control (Reset all D3PHY PLLs).");
                rc = fapiGetCfamRegister( i_target, CFAM_FSI_GP4_0x00001013, cfam_data);
                if (rc)
                {
                    FAPI_ERR("Error reading CFAM FSI GP4 register.");
                    break;
                }
                rc_ecmd |= cfam_data.clearBit(FSI_GP4_DPHY_PLLRESET_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to reset the D3PHY PLLs .",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutCfamRegister( i_target, CFAM_FSI_GP4_0x00001013, cfam_data);
                if (rc)
                {
                    FAPI_ERR("Error writing FSI GP4 register to reset the D3PHY PLLs (by clearing bit 4).");
                    break;
                }
        
        
                // Resume instructions that are common to eclipz chips.
        
        
                // reset abist_mode_dc for core chiplets (core recovery)
                // Does this make sense for Centaur?   (Centaur has no cores.)
                // Multicast address: "0x[xx]00 0004  WAND codepoint" Data: bit(11) = 0b0   0xFFEF FFFF FFFF FFFF
                // MEM_GP0_AND_0x03000004
                FAPI_DBG("Clearing GP0 Register bit 11 in MEM chiplet to reset abist_mode_dc.");
                rc_ecmd |= scom_data.flushTo1();
                rc_ecmd |= scom_data.clearBit(GP0_ABIST_MODE_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear bit 11 of the GP0 registers in the MEM chiplet.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, MEM_GP0_AND_0x03000004, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing the GP0 registers in the MEM chiplet to reset abist mode..");
                    break;
                }
        
        
                // set synclk_muxsel (io_clk_sel)
                // Multicast address: "0x[xx]00 0005  WOR codepoint"  bit(1) = 0b1   0x4000 0000 0000 0000
                // MEM_GP0_OR_0x03000005
                // assert perv fence GP0.63
                // Multicast address: "0x[xx]00 0005  WOR codepoint"  bit(63) = 0b1  0x4000 0000 0000 0001  (Can be combined with previous step)
                // MEM_GP0_OR_0x03000005
                FAPI_DBG("Setting GP0 Register bit 1 in MEM chiplet to set synclk_muxsel (io_clk_sel).");
                FAPI_DBG("Setting GP0 Register bit 63 in MEM chiplet to assert the pervasive fence.");
                rc_ecmd |= scom_data.flushTo0();
                rc_ecmd |= scom_data.setBit(GP0_SYNCCLK_MUXSEL_BIT);
                rc_ecmd |= scom_data.setBit(GP0_PERV_FENCE_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set syncclk_muxsel and pervasive fence in GP0 registers..",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, MEM_GP0_OR_0x03000005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing GP0 registers in MEM chiplet to set syncclk_muxsel and pervasive fence..");
                    break;
                }
        
        
                // GP3(28) disable EDRAM (just chiplets with EDRAM logic)
                // Note: This action is probably un-needed for the MEM chiplet since it does not contain any EDRAM.
                // Multicast address: "0x[xx]0F 0013  WAND codepoint"   bit(28) = 0b0   0xFFFF FFF7 FFFF FFFF
                // MEM_GP3_AND_0x030F0013
                FAPI_DBG("Clearing GP3 Register bit 28 in MEM chiplet to disable any EDRAM.");
                rc_ecmd |= scom_data.flushTo1();
                rc_ecmd |= scom_data.clearBit(GP3_EDRAM_ENABLE_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear GP3(bit 28), to disable EDRAM in MEM chiplet.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, MEM_GP3_AND_0x030F0013, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing GP3 Registers in MEM chiplet to disable any EDRAM.");
                    break;
                }
        
        
                // assert fence GP3.18
                // Multicast address: "0x[xx]0F 0014  WOR codepoint"  bit(18) = 0b1   0x0000 2000 0000 0000
                // MEM_GP3_OR_0x030F0014
                FAPI_DBG("Setting GP3 Regsiter bit 18 in MEM chiplet to assert the fence.");
                rc_ecmd |= scom_data.flushTo0();
                rc_ecmd |= scom_data.setBit(GP3_FENCE_EN_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set GP3(bit18) to assert the fence in the MEM chiplet.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, MEM_GP3_OR_0x030F0014, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing GP3 registers in MEM chiplet to assert the fence.");
                    break;
                }
     
                // Set scan_dis_dc_b bit in Chiplet GP0
                // unicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(6) = 0b1  (0x0200 0000 0000 0000)
                // MEM_GP0_OR_0x03000005
                FAPI_DBG("Setting MEM chiplet GP0 Register bit 6 to set scan_dis_dc_b to allow for scanning.");
                rc_ecmd |= scom_data.flushTo0();
                rc_ecmd |= scom_data.setBit(GP0_SCAN_DIS_DC_B_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set scan_dis_dc_b in MEM chiplet.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, MEM_GP0_OR_0x03000005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing MEM chiplet GP0 register to set scan_dis_dc_b for scanning.");
                    break;
                }
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
            rc = fapiGetScom( i_target, NEST_GP3_0x020F0012, scom_data);
            if (rc)
            {
                FAPI_ERR("Error reading GP3 register in attempt to verify that VITAL clocks are running.");
                break;
            }
            if (scom_data.isBitSet(GP3_VITAL_THOLD_BIT))
            {
                // The VITAL thold is asserted, so no clocks are running in this chiplet.   Nothing left to do, so just return.
                FAPI_INF("The VITAL clocks are not running for this chiplet, so all other clocks should be already stopped.");
            }
            else
            {

                // Start with instructions common to eclipz chips
       
                // Set flushmode_inhibit in Chiplet GP0
                // multicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(2) = 0b1  (0x2000 0000 0000 0000)
                // NEST_GP0_OR_0x02000005
                FAPI_DBG("Setting flushmode_inhibit in NEST chiplet GP0 Register (bit 2).");
                rc_ecmd |= scom_data.flushTo0();
                rc_ecmd |= scom_data.setBit(GP0_FLUSHMODE_INHIBIT_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set flushmode_inhibit in NEST chiplet GP0 Register.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_GP0_OR_0x02000005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing GP0 registers in NEST chiplet to set flushmode inhibit (bit 2).");
                    break;
                }
       
       
                // Set force_align in Chiplet GP0
                // multicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(3) = 0b1  (0x1000 0000 0000 0000)   Cannot combine with previous step.
                // NEST_GP0_OR_0x02000005
                FAPI_DBG("Setting force_align in NEST chiplet GP0 register (bit 3).");
                rc_ecmd |= scom_data.flushTo0();
                rc_ecmd |= scom_data.setBit(GP0_FORCE_ALIGN_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to Set force_align in NEST chiplet.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_GP0_OR_0x02000005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing GP0 registers in NEST chiplet to set force_align (bit 3).");
                    break;
                }
       
       
                // Write ClockControl, Scan Region Register, set all bits to zero prior clock stop
                // multicast address 0x[xx]03 0007    Data:  0x0000 0000 0000 0000
                // NEST_CLK_SCANSEL_0x02030007
                FAPI_DBG("Writing Clock Control Scan Region Register to all zeros in NEST chiplet prior clock stop.");
                rc_ecmd |= scom_data.flushTo0();
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write CC Scan Region Register to all zeros..",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_CLK_SCANSEL_0x02030007, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing CC Scan Region Registers in NEST chiplet.");
                    break;
                }
       
       
                // Now do Centaur-specific instructions
       
       
       
                // Write ClockControl, Clock Region Register, Clock Stop command for NEST chiplet
                // 0x0203 0006  Data: 0x8FE00E0000000000
                // NEST_CLK_REGION_0x02030006
                FAPI_DBG("Writing Clock Control Clock Region Register in NEST chiplet to stop the clocks.");
                if ( i_stop_dram_rfrsh_clks )
                {
                    rc_ecmd |= scom_data.setDoubleWord(0, CLK_REGION_REG_DATA_TO_STOP_ALL);
                }
                else
                {
                    rc_ecmd |= scom_data.setDoubleWord(0, CLK_REGION_STOP_ALL_BUT_REFRESH );
                }
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set general clock stop command in NEST chiplet CC Clock Region Register.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_CLK_REGION_0x02030006, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing NEST chiplet CC Clock Region Register to stop the clocks.");
                    break;
                }
       
       
                // Read Clock Status Register (NEST chiplet)
                // 0x0203 0008  Data: expected value: 0xFFFF FFFF FFFF FFFF
                // NEST_CLK_STATUS_0x02030008
                if ( i_stop_dram_rfrsh_clks )
                {
                    FAPI_DBG("Reading Clock Status Register in the NEST chiplet to see if clocks are stopped. Expected value = 0xFFFF FFFF FFFF FFFF.");
                    rc = fapiGetScom( i_target, NEST_CLK_STATUS_0x02030008, scom_data);
                    if (rc)
                    {
                        FAPI_ERR("Error reading NEST chiplet Clock Status Register.");
                        break;
                    }
                    uint64_t clock_status = scom_data.getDoubleWord(0);
                    if ( clock_status != EXPECTED_CLOCK_STATUS )
                    {
                        FAPI_ERR("NEST chiplet clock status 0x%016llX was expected but read clock status = 0x%016llX",
                                 EXPECTED_CLOCK_STATUS, clock_status);
                        const uint64_t & EXPECTED_STATUS = EXPECTED_CLOCK_STATUS;
                        const uint64_t & ACTUAL_STATUS = clock_status;
                        const fapi::Target & MEMBUF_CHIP_IN_ERROR = i_target;
                        FAPI_SET_HWP_ERROR(rc, RC_MSS_UNEXPECTED_NEST_CLOCK_STATUS);
                        break;
                    }
                    else
                    {
                        FAPI_INF("Expected clock status was read in NEST chiplet after stopping the clocks: 0x%016llX ", EXPECTED_CLOCK_STATUS);
                    }
                }
                else
                {
                    FAPI_DBG("Reading Clock Status Register in the NEST chiplet to see if clocks are stopped. Expected value = 0xFFFF FF1F FFFF FFFF.");
                    rc = fapiGetScom( i_target, NEST_CLK_STATUS_0x02030008, scom_data);
                    if (rc)
                    {
                        FAPI_ERR("Error reading NEST chiplet Clock Status Register.");
                        break;
                    }
                    uint64_t clock_status = scom_data.getDoubleWord(0);
                    if ( clock_status != EXPECTED_CLOCK_STATUS_W_REFRESH )
                    {
                        FAPI_ERR("NEST chiplet clock status 0x%016llX was expected but read clock status = 0x%016llX",
                                 EXPECTED_CLOCK_STATUS_W_REFRESH, clock_status);
                        const uint64_t & EXPECTED_STATUS = EXPECTED_CLOCK_STATUS_W_REFRESH;
                        const uint64_t & ACTUAL_STATUS = clock_status;
                        const fapi::Target & MEMBUF_CHIP_IN_ERROR = i_target;
                        FAPI_SET_HWP_ERROR(rc, RC_MSS_UNEXPECTED_NEST_CLOCK_STATUS);
                        break;
                    }
                    else
                    {
                        FAPI_INF("Expected clock status was read in NEST chiplet after stopping the clocks: 0x%016llX ", EXPECTED_CLOCK_STATUS_W_REFRESH);
                    }
                }
       
       
                // Resume instructions that are common to eclipz chips.
       
       
                // reset abist_mode_dc for core chiplets (core recovery)
                // Does this make sense for Centaur?   (Centaur has no cores.)
                // Multicast address: "0x[xx]00 0004  WAND codepoint" Data: bit(11) = 0b0   0xFFEF FFFF FFFF FFFF
                // NEST_GP0_AND_0x02000004
                FAPI_DBG("Clearing GP0 Register bit 11 in NEST chiplet to reset abist_mode_dc.");
                rc_ecmd |= scom_data.flushTo1();
                rc_ecmd |= scom_data.clearBit(GP0_ABIST_MODE_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear bit 11 of the GP0 registers in the NEST chiplet.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_GP0_AND_0x02000004, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing the GP0 registers in the NEST chiplet to reset abist mode..");
                    break;
                }
       
       
                // set synclk_muxsel (io_clk_sel)
                // Multicast address: "0x[xx]00 0005  WOR codepoint"  bit(1) = 0b1   0x4000 0000 0000 0000
                // NEST_GP0_OR_0x02000005
                // assert perv fence GP0.63
                // Multicast address: "0x[xx]00 0005  WOR codepoint"  bit(63) = 0b1  0x4000 0000 0000 0001  (Can be combined with previous step)
                // NEST_GP0_OR_0x02000005
                FAPI_DBG("Setting GP0 Register bit 1 in NEST chiplet to set synclk_muxsel (io_clk_sel).");
                FAPI_DBG("Setting GP0 Register bit 63 in NEST chiplet to assert the pervasive fence.");
                rc_ecmd |= scom_data.flushTo0();
                rc_ecmd |= scom_data.setBit(GP0_SYNCCLK_MUXSEL_BIT);
                rc_ecmd |= scom_data.setBit(GP0_PERV_FENCE_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set syncclk_muxsel and pervasive fence in GP0 registers..",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_GP0_OR_0x02000005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing GP0 registers in NEST chiplet to set syncclk_muxsel and pervasive fence..");
                    break;
                }
       
       
                // GP3(28) disable EDRAM (just chiplets with EDRAM logic)
                // Note:  (skip this step if refresh clock domain stays running)
                // Multicast address: "0x[xx]0F 0013  WAND codepoint"   bit(28) = 0b0   0xFFFF FFF7 FFFF FFFF
                // NEST_GP3_AND_0x020F0013
                if ( i_stop_dram_rfrsh_clks )
                {
                    FAPI_DBG("Clearing GP3 Register bit 28 in NEST chiplet to disable any EDRAM.");
                    rc_ecmd |= scom_data.flushTo1();
                    rc_ecmd |= scom_data.clearBit(GP3_EDRAM_ENABLE_BIT);
                    if (rc_ecmd)
                    {
                        FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear GP3(bit 28), to disable EDRAM in NEST chiplet.",  rc_ecmd);
                        rc.setEcmdError(rc_ecmd);
                        break;
                    }
                    rc = fapiPutScom( i_target, NEST_GP3_AND_0x020F0013, scom_data);
                    if (rc)
                    {
                        FAPI_ERR("Error writing GP3 Registers in NEST chiplet to disable any EDRAM.");
                        break;
                    }
                }
       
       
                // assert fence GP3.18
                // Multicast address: "0x[xx]0F 0014  WOR codepoint"  bit(18) = 0b1   0x0000 2000 0000 0000
                // NEST_GP3_OR_0x020F0014
                FAPI_DBG("Setting GP3 Regsiter bit 18 in NEST chiplet to assert the fence.");
                rc_ecmd |= scom_data.flushTo0();
                rc_ecmd |= scom_data.setBit(GP3_FENCE_EN_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set GP3(bit18) to assert the fence in the NEST chiplet.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_GP3_OR_0x020F0014, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing GP3 registers in NEST chiplet to assert the fence.");
                    break;
                }
     
                // Set scan_dis_dc_b bit in Chiplet GP0
                // unicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(6) = 0b1  (0x0200 0000 0000 0000)
                // NEST_GP0_OR_0x02000005
                FAPI_DBG("Setting NEST chiplet GP0 Register bit 6 to set scan_dis_dc_b to allow for scanning.");
                rc_ecmd |= scom_data.flushTo0();
                rc_ecmd |= scom_data.setBit(GP0_SCAN_DIS_DC_B_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to set scan_dis_dc_b in NEST chiplet.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_GP0_OR_0x02000005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing NEST chiplet GP0 register to set scan_dis_dc_b for scanning.");
                    break;
                }
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
            rc_ecmd |= cfam_data.setWord(0,FSI_SHIFT_SET_PULSE_LENGTH); //Set cfam_data to 0x0000000F
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase for CFAM operation", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutCfamRegister(i_target, CFAM_FSI_SHIFT_CTRL_0x00000C10, cfam_data);
            if (rc)
            {
                FAPI_ERR("Error attempting to set length of the set pulse in the FSI SHIFT_CONTROL_REGISTER_2.");
                break;
            }


            // Go into PIB2PCB bypass path
            // Set this in CFAM GP3 register.  Read the register first to preserve other contents.
            FAPI_DBG("Setting FSI GP3 bit 20 to go into PIB2PCB bypass.");
            rc = fapiGetCfamRegister(i_target, CFAM_FSI_GP3_0x00001012, cfam_data);
            if (rc)
            {
                FAPI_ERR("Error getting FSI_GP3 via CFAM");
                break;
            }
            rc_ecmd |= cfam_data.setBit(FSIGP3_PIB2PCB_BYPASS_BIT); //Set bit 20 to go into PIB2PCB bypass
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase for CFAM operation", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutCfamRegister(i_target, CFAM_FSI_GP3_0x00001012, cfam_data);
            if (rc)
            {
                FAPI_ERR("Error attempting to go into PIB2PCB bypass.");
                break;
            }


            // Set flushmode_inhibit in Chiplet GP0
            // unicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(2) = 0b1  (0x2000 0000 0000 0000)
            // TP_GP0_OR_0x01000005
            FAPI_DBG("Setting TP chiplet GP0 Register bit 2 to set flushmode_inhibit.");
            rc_ecmd |= scom_data.flushTo0();
            rc_ecmd |= scom_data.setBit(GP0_FLUSHMODE_INHIBIT_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to set flushmode_inhibit in TP chiplet.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom( i_target, TP_GP0_OR_0x01000005, scom_data);
            if (rc)
            {
                FAPI_ERR("Error writing TP chiplet GP0 register to set flushmode inhibit.");
                break;
            }

            // Set force_align in Chiplet GP0
            // unicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(3) = 0b1  (0x1000 0000 0000 0000)   Cannot combine with previous step.
            // TP_GP0_OR_0x01000005
            FAPI_DBG("Setting TP chiplet GP0 Register bit 3 to set force_align.");
            rc_ecmd |= scom_data.flushTo0();
            rc_ecmd |= scom_data.setBit(GP0_FORCE_ALIGN_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to set force_align in TP chiplet.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom( i_target, TP_GP0_OR_0x01000005, scom_data);
            if (rc)
            {
                FAPI_ERR("Error writing TP chiplet GP0 register to set force_align.");
                break;
            }

            // Write ClockControl, Scan Region Register, set all bits to zero prior clock stop
            // unicast address 0x[xx]03 0007    Data:  0x0000 0000 0000 0000
            // TP_CLK_SCANSEL_0x01030007
            FAPI_DBG("Writing TP chiplet Clock Control Scan Region Register to all zeros prior clock stop.");
            rc_ecmd |= scom_data.flushTo0();
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to write CC Scan Region Register to all zeros in TP chiplet.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom( i_target, TP_CLK_SCANSEL_0x01030007, scom_data);
            if (rc)
            {
                FAPI_ERR("Error writing TP chiplet CC Scan Region Register.");
                break;
            }

            // Write ClockControl, Clock Region Register, Clock Stop command (arrays + nsl only, not refresh clock region) TP chiplet
            // TP_CLK_REGION_0x01030006
            FAPI_DBG("Writing Clock Control Clock Region Register in TP chiplet to stop the clocks.");
            rc_ecmd |= scom_data.flushTo1();
            rc_ecmd |= scom_data.insertFromRight(CLK_REGION_CLOCK_CMD_STOP,
                                                 CLK_REGION_CLOCK_CMD_BIT,
                                                 CLK_REGION_CLOCK_CMD_LEN);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to set general clock stop command in TP chiplet CC Clock Region Register.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom( i_target, TP_CLK_REGION_0x01030006, scom_data);
            if (rc)
            {
                FAPI_ERR("Error writing TP chiplet CC Clock Region Register to stop the clocks.");
                break;
            }

            // Read Clock Status Register (TP chiplet)
            // 0x0103 0008  Data: expected value: FFFFFFFFFFFFFFFF
            // TP_CLK_STATUS_0x01030008
            FAPI_DBG("Reading Clock Status Register in the TP chiplet to see if clocks are stopped. Expected value = 0x%016llX.", EXPECTED_CLOCK_STATUS);
            rc = fapiGetScom( i_target, TP_CLK_STATUS_0x01030008, scom_data);
            if (rc)
            {
                FAPI_ERR("Error reading TP chiplet Clock Status Register.");
                break;
            }
            uint64_t clock_status = scom_data.getDoubleWord(0);
            if ( clock_status != EXPECTED_CLOCK_STATUS )
            {
                FAPI_ERR("TP chiplet clock status 0x%016llX was expected but read clock status = 0x%016llX.",
                         EXPECTED_CLOCK_STATUS, clock_status);
                const uint64_t & EXPECTED_STATUS = EXPECTED_CLOCK_STATUS;
                const uint64_t & ACTUAL_STATUS = clock_status;
                const fapi::Target & MEMBUF_CHIP_IN_ERROR = i_target;
                FAPI_SET_HWP_ERROR(rc, RC_MSS_UNEXPECTED_TP_CLOCK_STATUS);
                break;
            }
            else
            {
                FAPI_INF("Expected clock status was read in TP chiplet after stopping the clocks: 0x%016llX ", EXPECTED_CLOCK_STATUS);
            }


            // Set L3 EDRAM fence in chiplet by setting bit(19) in chiplet GP0 registers  (Fence only exists in EX chiplets.)


            // Resume instructions that are common to all eclipz chips.


            // reset abist_mode_dc for core chiplets only (core recovery)


            // set synclk_muxsel (io_clk_sel)
            // Unicast address: "0x[xx]00 0005  WOR codepoint"  bit(1) = 0b1   0x4000 0000 0000 0000
            // TP_GP0_OR_0x01000005
            // assert perv fence GP0.63
            // Unicast address: "0x[xx]00 0005  WOR codepoint"  bit(63) = 0b1  0x4000 0000 0000 0001  (Can be combined with previous step)
            // TP_GP0_OR_0x01000005
            FAPI_DBG("Setting TP chiplet GP0 Register bit 1 to set synclk_muxsel (io_clk_sel).");
            FAPI_DBG("Setting TP chiplet GP0 Register bit 63 to assert the pervasive fence.");
            rc_ecmd |= scom_data.flushTo0();
            rc_ecmd |= scom_data.setBit(GP0_SYNCCLK_MUXSEL_BIT);
            rc_ecmd |= scom_data.setBit(GP0_PERV_FENCE_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to set syncclk_muxsel and pervasive fence in TP chiplet.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom( i_target, TP_GP0_OR_0x01000005, scom_data);
            if (rc)
            {
                FAPI_ERR("Error writing TP chiplet GP0 register to set syncclk_muxsel and pervasive fence..");
                break;
            }


            // GP3(28) disable EDRAM (just chiplets with EDRAM logic)


            // Instruction from Johannes Koesters   12 Sept, 2013
            // Leave this commented out for now.   Seems to cause problems if we set the fence on the TP chiplet.
            // 
            // Change this to use PERV GP3 Register  (CFAM 101B)  (Normal GP3 reg N/A in TP chiplet) ?
            //// assert fence GP3.18
            //// Unicast address: "0x[xx]0F 0014  WOR codepoint"  bit(18) = 0b1   0x0000 2000 0000 0000
            //// TP_GP3_OR_0x010F0014
            //FAPI_DBG("Setting TP chiplet GP3 Regsiter bit 18 to assert the fence.");
            //rc_ecmd |= scom_data.flushTo0();
            //rc_ecmd |= scom_data.setBit(GP3_FENCE_EN_BIT);
            //if (rc_ecmd)
            //{
            //    FAPI_ERR("Error 0x%x setting up ecmd data buffer to assert the fence in TP chiplet.",  rc_ecmd);
            //    rc.setEcmdError(rc_ecmd);
            //    break;
            //}
            //rc = fapiPutScom( i_target, TP_GP3_OR_0x010F0014, scom_data);
            //if (rc)
            //{
            //    FAPI_ERR("Error writing TP chiplet GP3 register to assert the fence.");
            //    break;
            //}


            // Set scan_dis_dc_b bit in Chiplet GP0
            // unicast address "0x[xx]00 0005 WOR codepoint"   Data: bit(6) = 0b1  (0x0200 0000 0000 0000)
            // TP_GP0_OR_0x01000005
            FAPI_DBG("Setting TP chiplet GP0 Register bit 6 to set scan_dis_dc_b to allow for scanning.");
            rc_ecmd |= scom_data.flushTo0();
            rc_ecmd |= scom_data.setBit(GP0_SCAN_DIS_DC_B_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to set scan_dis_dc_b in TP chiplet.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom( i_target, TP_GP0_OR_0x01000005, scom_data);
            if (rc)
            {
                FAPI_ERR("Error writing TP chiplet GP0 register to set scan_dis_dc_b for scanning.");
             break;
            }
        }  // End of TP Chiplet clock section



        //-----------------
        //   VITL Clocks @@@ 00
        //-----------------

        if (i_stop_vitl_clks)
        {

            // Set the length of the FSI shifter set pulse
            // Do this in the CFAM FSI SHIFT_CONTROL_REGISTER_2.
            FAPI_DBG("Setting length of the set pulse in the FSI SHIFT_CONTROL_REGISTER_2.");
            rc_ecmd |= cfam_data.setWord(0,FSI_SHIFT_SET_PULSE_LENGTH); //Set cfam_data to 0x0000000F
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase for CFAM operation", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutCfamRegister(i_target, CFAM_FSI_SHIFT_CTRL_0x00000C10, cfam_data);
            if (rc)
            {
                FAPI_ERR("Error attempting to set length of the set pulse in the FSI SHIFT_CONTROL_REGISTER_2.");
                break;
            }


            // Disable the VITL clocks
            // Set this in PERV GP3 register.  Read the register first to preserve other contents.
            FAPI_DBG("Setting PERV GPP3 Register bit 16 to turn OFF the VITL clock.");
            rc = fapiGetCfamRegister(i_target, CFAM_FSI_GP3_MIRROR_0x0000101B, cfam_data);
            if (rc)
            {
                FAPI_ERR("Error getting PERV GP3 via CFAM");
                break;
            }
            rc_ecmd |= cfam_data.setBit(PERVGP3_VITL_CLKOFF_BIT); //Set bit 16 to turn OFF VITL clock
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase for CFAM operation", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutCfamRegister(i_target, CFAM_FSI_GP3_MIRROR_0x0000101B, cfam_data);
            if (rc)
            {
                FAPI_ERR("Error attempting to set PERV GP3 Reg bit 16 to stop the VITL clocks.");
                break;
            }


            // Set Some FSI fences
            // Set this in CFAM GP3 register.  Read the register first to preserve other contents.
            FAPI_DBG("Setting FSI GP3 bits 25 and,26 to set FSI fences 4 and 5.");
            rc = fapiGetCfamRegister(i_target, CFAM_FSI_GP3_0x00001012, cfam_data);
            if (rc)
            {
                FAPI_ERR("Error getting FSI_GP3 via CFAM");
                break;
            }
            rc_ecmd |= cfam_data.setBit(FSIGP3_FSI_FENCE4_BIT); //Set bits 25 to set FSI fence 4
            rc_ecmd |= cfam_data.setBit(FSIGP3_FSI_FENCE5_BIT); //Set bits 26 to set FSI fence 5
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase for CFAM operation", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutCfamRegister(i_target, CFAM_FSI_GP3_0x00001012, cfam_data);
            if (rc)
            {
                FAPI_ERR("Error attempting to set FSI fences in FSI GP3 register.");
                break;
            }
        }  // End of VITL clock section


    } while(0);

    FAPI_INF("********* cen_stopclocks complete *********");
    return rc;
}

} //end extern C




/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: cen_stopclocks.C,v $
Revision 1.16  2014/01/16 17:49:16  mfred
Updates for error msgs, error handling, and removing newline chars from msgs.  From Mike Jones.

Revision 1.15  2013/10/16 14:39:32  mfred
Set the FSI shifter pulse width before stopping the TP or VITL clocks.

Revision 1.14  2013/10/10 14:23:32  mfred
Updates from Gerrit review. Continue with other chiplet even if clocks are off in MEM chiplet.

Revision 1.13  2013/09/27 16:44:50  mfred
Separate option to stop the VITL clks, and checks to avoid calling options that will cause failures.

Revision 1.12  2013/03/04 17:56:33  mfred
Add some header comments for BACKUP and SCREEN.

Revision 1.11  2013/02/27 21:16:30  mfred
Make change to stop all clock regions simultaneously.

Revision 1.10  2013/01/17 21:38:55  mfred
Check vital clock before trying to stop clocks.  Assert scan_dis_dc_b after stopping clocks.

Revision 1.9  2012/10/05 20:10:43  mfred
Remove the use of multicast in case only one chiplet is selected.

Revision 1.8  2012/08/30 12:09:29  mfred
Only disable EDRAM if the refresh clock was turned OFF.

Revision 1.7  2012/08/30 11:56:08  mfred
Added input options to select chiplet and to stop refresh clock.

Revision 1.6  2012/08/27 16:53:40  mfred
Exit when unexpected clock status is seen.

Revision 1.5  2012/07/10 14:29:36  mfred
Removed some bad comments and some whitespace.

Revision 1.4  2012/06/07 19:31:19  mfred
Fixed calls to CFAM registers.  They are not scommable.

Revision 1.3  2012/05/31 14:02:06  mfred
Committing updates for cen_stopclocks.

Revision 1.2  2012/03/14 19:26:34  mfred
Replace prototype with functional code.

Revision 1.1  2012/03/07 14:22:11  mfred
Adding prototype for cen_stopclocks.

*/

