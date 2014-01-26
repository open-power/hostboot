/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_ddr_phy_reset/mss_ddr_phy_reset.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_ddr_phy_reset.C,v 1.27 2014/01/16 20:54:48 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_ddr_phy_reset.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_ddr_phy_reset
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! SCREEN      : memory_screen
// #! ADDITIONAL COMMENTS :
//
// The purpose of this procedure is to do a soft reset of the DDR PHY logic
// and to get the Centaur chip ready for DRAM initializaion.
// See sepecific instructions below.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------

#include <fapi.H>
#include <cen_scom_addresses.H>
#include <mss_ddr_phy_reset.H>
#include <mss_termination_control.H>
#include <mss_unmask_errors.H>
#include <dimmBadDqBitmapFuncs.H>

//  Constants
const uint64_t  DELAY_100NS             = 100;      // general purpose 100 ns delay for HW mode   (2000 sim cycles if simclk = 20ghz)
const uint64_t  DELAY_1US               = 1000;     // general purpose 1 usec delay for HW mode   (20000 sim cycles if simclk = 20ghz)
const uint64_t  DELAY_100US             = 100000;   // general purpose 100 usec delay for HW mode (2000000 sim cycles if simclk = 20ghz)
const uint64_t  DELAY_2000SIMCYCLES     = 2000;     // general purpose 2000 sim cycle delay for sim mode     (100 ns if simclk = 20Ghz)
const uint64_t  DELAY_20000SIMCYCLES    = 20000;    // general purpose 20000 sim cycle delay for sim mode    (1 usec if simclk = 20Ghz)
const uint64_t  DELAY_2000000SIMCYCLES  = 2000000;  // general purpose 2000000 sim cycle delay for sim mode  (100 usec if simclk = 20Ghz)

const uint16_t  DP18_PLL_EXP_LOCK_STATUS  = 0xF800; // DP18 PLL lock status that is expected at the conclusion of this procedure.
const uint16_t  AD32S_PLL_EXP_LOCK_STATUS = 0xC000; // AD32S PLL lock status that is expected at the conclusion of this procedure.
const uint16_t  MAX_POLL_LOOPS            = 10;     // Loop 10 times during PLL lock polling


extern "C" {


using namespace fapi;

// prototypes of functions called in phy reset
ReturnCode mss_deassert_force_mclk_low (const Target& i_target); 
ReturnCode mss_ddr_phy_reset_cloned(const fapi::Target & i_target);
ReturnCode mss_ddr_phy_flush(const fapi::Target & i_target);

fapi::ReturnCode mss_ddr_phy_reset(const fapi::Target & i_target)
{
    // Target is centaur.mba

    fapi::ReturnCode rc;

    rc = mss_ddr_phy_reset_cloned(i_target);
    if (rc) {
        FAPI_ERR(" mss_ddr_phy_reset_cloned failed!  rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
    }
    else	// reset successful
    {
        rc = mss_slew_cal(i_target);
        if (rc) {
            FAPI_ERR(" mss_slew_cal failed!  rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
        }
        else	// slew cal successful
        {
            rc = mss_ddr_phy_flush(i_target);
            if (rc) {
                FAPI_ERR(" mss_ddr_phy_flush failed!  rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            }
        }
    }	// should exit early if any functions has a bad return code

    // If mss_unmask_ddrphy_errors gets it's own bad rc,
    // it will commit the passed in rc (if non-zero), and return it's own bad rc.
    // Else if mss_unmask_ddrphy_errors runs clean,
    // it will just return the passed in rc.
    rc = mss_unmask_ddrphy_errors(i_target, rc);

    return rc;
}

fapi::ReturnCode mss_ddr_phy_reset_cloned(const fapi::Target & i_target)
{
    // Target is centaur.mba

    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    uint32_t poll_count = 0;
    uint32_t done_polling = 0;
    uint8_t is_simulation = 0;
    ecmdDataBufferBase i_data(64);
    ecmdDataBufferBase dp_p0_lock_data(64);
    ecmdDataBufferBase dp_p1_lock_data(64);
    ecmdDataBufferBase ad_p0_lock_data(64);
    ecmdDataBufferBase ad_p1_lock_data(64);
    uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE]; // 10 byte array of bad bits
    uint8_t valid_dimms  = 0;
    uint8_t valid_dimm[2][2];
    uint8_t num_mranks_per_dimm[2][2];
    uint8_t l_port       = 0;
    uint8_t l_dimm       = 0;
    uint8_t l_rank       = 0;
    bool new_error        = false;
    bool P0_DP0_reg_error = false;
    bool P0_DP1_reg_error = false;
    bool P0_DP2_reg_error = false;
    bool P0_DP3_reg_error = false;
    bool P0_DP4_reg_error = false;
    bool P1_DP0_reg_error = false;
    bool P1_DP1_reg_error = false;
    bool P1_DP2_reg_error = false;
    bool P1_DP3_reg_error = false;
    bool P1_DP4_reg_error = false;
    fapi::Target l_centaurTarget;
    uint8_t      continue_on_dp18_pll_lock_failure = 0;


    FAPI_INF("********* mss_ddr_phy_reset start *********");
    do
    { 

        //
        // Here are the specific instructions from section 14.7.3 of the Centaur Chip Specification:
        //
        // Run cen_ddr_phy_reset.C prepares the DDR PLLs. These PLLs were previously configured via scan init, but have
        // been held in reset. At this point the PLL GP bit is deasserted to take the PLLs out of reset.
        //
        // The cen_ddr_phy_reset.C now resets the DDR PHY logic. This process will NOT destroy any configuration values
        // previously loaded via the init file. The intent is for the initialized phase rotator configuration to remain valid after the
        // soft reset completes. If this assumption fails to hold true, it will require replacing this step with a PHY hard reset,
        // and then using inband configuration writes to restore all the DDR Configuration Registers.
        //
        // The following steps must be performed as part of the PHY reset procedure.
  

         // PLL Lock cannot happen if mclk low is asserted
        // this procedure was moved from draminit to:
        // Deassert Force_mclk_low signal
        // see CQ 216395 (HW217109)
        rc = mss_deassert_force_mclk_low(i_target);
        if (rc)
        {
            FAPI_ERR(" deassert_force_mclk_low Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            break;
        }


        //
        // 1. Drive all control signals to the PHY to their inactive state, idle state, or inactive value.
        //    (Note: The chip should already be in this state.)
        FAPI_DBG("Step 1: All control signals to the PHYs should already be set to their inactive state, idle state, or inactive values.\n");
  
  
  
        //
        // 2. For DD0: Assert dfi_reset_all (GP4 bit 5 = "1") for at least 32 memory clock cycles. This signal DOES
        //    erradicate all DDR configuration register initialization, thereby requiring the DDR registers to be reprogrammed
        //    via SCOM after the PHY reset sequence completes.
        //    For DD1: Set mcbist_ddr_dfi_reset_recover ="1" (CCS_MODEQ(25) SCOM Addr: 0x030106A7 & 0x03010EA7)
        //    for at least 32 memory clock cycles. This signal does NOT reset the configuration registers
        //    within the PHY.
        FAPI_DBG("Step 2: MBA CCS_MODEQ(25), Setting mcbist_ddr_dfi_reset_recover = 1 for DDR PHY soft reset.\n");
        rc = fapiGetScom( i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, i_data);
        if (rc)
        {
            FAPI_ERR("Error reading CCS_MODEQ register.");
            break;
        }
        rc_ecmd |= i_data.setBit(25);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to set bit 25 of CCS_MODEQ register.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing CCS_MODEQ register .");
            break;
        }
        rc = fapiDelay(DELAY_100NS, DELAY_2000SIMCYCLES); // wait 2000 simcycles (in sim mode) OR 100 nS (in hw mode)
        if (rc)
        {
            FAPI_ERR("Error executing fapiDelay of 100ns or 2000simcycles.");
            break;
        }



        //
        // 3. For DD0: Deassert dfi_reset_all (GP4 bit 5 = "0")
        //    For DD1: Deassert mcbist_ddr_dfi_reset_recover = "0" (CCS_MODEQ(25) SCOM Addr: 0x030106A7 0x03010EA7)
        FAPI_DBG("Step 3: MBA CCS_MODEQ(25), Setting mcbist_ddr_dfi_reset_recover = 0 to release soft reset.\n");
        rc = fapiGetScom( i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, i_data);
        if (rc)
        {
            FAPI_ERR("Error reading CCS_MODEQ register .");
            break;
        }
        rc_ecmd |= i_data.clearBit(25);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear bit 25 of CCS_MODEQ register.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing CCS_MODEQ register.");
            break;
        }
  
  
  
        //
        // 4. Write 0x0010 to PC IO PVT N/P FET driver control registers to assert ZCTL reset and enable the internal impedance controller.
        //    (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 4: Write 0x0010 to PC IO PVT N/P FET driver control registers to assert ZCTL reset.\n");
        rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000000010ull);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x0010 into PC_IO_PVT_FET_CONTROL regs.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0_0x8000C0140301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1_0x8001C0140301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1 register.");
            break;
        }



        //
        // 5. Write 0x0018 to PC IO PVT N/P FET driver control registers to deassert ZCTL reset while impedance controller is still enabled.
        //    (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 5: Write 0x0018 to PC IO PVT N/P FET driver control registers to deassert ZCTL reset.\n");
        rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000000018ull);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x0018 into PC_IO_PVT_FET_CONTROL regs.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0_0x8000C0140301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1_0x8001C0140301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1 register.");
            break;
        }



        //
        // 6. Write 0x0008 to PC IO PVT N/P FET driver control registers to deassert the impedance controller.
        //    (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 6: Write 0x0008 to PC IO PVT N/P FET driver control registers to deassert the impedance controller.\n");
        rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000000008ull);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x0008 into PC_IO_PVT_FET_CONTROL regs.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0_0x8000C0140301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1_0x8001C0140301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1 register.");
            break;
        }



        //
        // 7. Write 0x4000 into the PC Resets Registers. This deasserts the PLL_RESET and leaves the SYSCLK_RESET bit active
        //                                                (SCOM Addr: 0x8000C00E0301143F, 0x8001C00E0301143F, 0x8000C00E0301183F, 0x8001C00E0301183F)
        FAPI_DBG("Step 7: Write 0x4000 into the PC Resets Regs. This deasserts the PLL_RESET and leaves the SYSCLK_RESET bit active.\n");
        rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000004000ull);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x4000 into PC_RESETS registers.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_RESETS_P0_0x8000C00E0301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_RESETS_P0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_RESETS_P1_0x8001C00E0301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_RESETS_P1 register.");
            break;
        }



        //
        // 8. Wait at least 1 millisecond to allow the PLLs to lock. Otherwise, poll the PC DP18 PLL Lock Status
        //    and the PC AD32S PLL Lock Status to determine if all PLLs have locked.
        //    PC DP18 PLL Lock Status should be 0xF800:  (SCOM Addr: 0x8000C0000301143F, 0x8001C0000301143F, 0x8000C0000301183F, 0x8001C0000301183F)
        //    PC AD32S PLL Lock Status should be 0xC000: (SCOM Addr: 0x8000C0010301143F, 0x8001C0010301143F, 0x8000C0010301183F, 0x8001C0010301183F)
        //------------------------
        // 8a - Poll for lock bits
        FAPI_DBG("Step 8: Poll until DP18 and AD32S PLLs have locked....\n");
        do
        {
            rc = fapiDelay(DELAY_1US, DELAY_20000SIMCYCLES); // wait 20000 simcycles (in sim mode) OR 1 usec (in hw mode)
            if (rc)
            {
                FAPI_ERR("Error executing fapiDelay of 1us or 20000simcycles.");
                break;
            }
            done_polling = 1;
            rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0_0x8000C0000301143F, dp_p0_lock_data);
            if (rc)
            {
                FAPI_ERR("Error reading DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0 register.");
                break;
            }
            if ( dp_p0_lock_data.getHalfWord(3) != DP18_PLL_EXP_LOCK_STATUS ) done_polling = 0;
            rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1_0x8001C0000301143F, dp_p1_lock_data);
            if (rc)
            {
                FAPI_ERR("Error reading DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1 register.");
                break;
            }
            if ( dp_p1_lock_data.getHalfWord(3) != DP18_PLL_EXP_LOCK_STATUS ) done_polling = 0;
            rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0_0x8000C0010301143F, ad_p0_lock_data);
            if (rc)
            {
                FAPI_ERR("Error reading DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0 register.");
                break;
            }
            if ( ad_p0_lock_data.getHalfWord(3) != AD32S_PLL_EXP_LOCK_STATUS ) done_polling = 0;
            rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1_0x8001C0010301143F, ad_p1_lock_data);
            if (rc)
            {
                FAPI_ERR("Error reading DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1 register.");
                break;
            }
            if ( ad_p1_lock_data.getHalfWord(3) != AD32S_PLL_EXP_LOCK_STATUS ) done_polling = 0;
            poll_count++;
        } while ((done_polling == 0) && (poll_count < MAX_POLL_LOOPS)); // Poll until PLLs are locked.
        if (rc) break;    // Go to end of proc if error found inside polling loop.
  

        if (poll_count == MAX_POLL_LOOPS)
        {

            //-------------------------------
            // Check to see if we should continue even if the DP18 PLL lock fails
            rc = fapiGetParentChip(i_target, l_centaurTarget);
            if (rc)
            {
                FAPI_ERR("Error getting Centaur parent target from the input MBA");
                break;
            }
            rc = FAPI_ATTR_GET( ATTR_CENTAUR_EC_MSS_CONTINUE_ON_DP18_PLL_LOCK_FAIL, &l_centaurTarget, continue_on_dp18_pll_lock_failure);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_CENTAUR_EC_MSS_CONTINUE_ON_DP18_PLL_LOCK_FAIL.");
                break;
            }
            FAPI_DBG("Got attribute ATTR_CENTAUR_EC_MSS_CONTINUE_ON_DP18_PLL_LOCK_FAIL:  value=%X.\n", continue_on_dp18_pll_lock_failure);

            //-------------------------------
            // 8b - Check Port 0 DP lock bits
            if ( dp_p0_lock_data.getHalfWord(3) != DP18_PLL_EXP_LOCK_STATUS )
            {
                if ( dp_p0_lock_data.isBitClear(48) ) { FAPI_INF("Port 0 DP 0 PLL failed to lock!");}
                if ( dp_p0_lock_data.isBitClear(49) ) { FAPI_INF("Port 0 DP 1 PLL failed to lock!");}
                if ( dp_p0_lock_data.isBitClear(50) ) { FAPI_INF("Port 0 DP 2 PLL failed to lock!");}
                if ( dp_p0_lock_data.isBitClear(51) ) { FAPI_INF("Port 0 DP 3 PLL failed to lock!");}
                if ( dp_p0_lock_data.isBitClear(52) ) { FAPI_INF("Port 0 DP 4 PLL failed to lock!");}
                if (!continue_on_dp18_pll_lock_failure)
                {
                    FAPI_ERR("One or more DP18 port 0 (0x0C000) PLL failed to lock!   Lock Status = %04X",dp_p0_lock_data.getHalfWord(3));
                    FAPI_ERR("DP18 PLL lock failed and this chip does not have the known DP18 lock bug.");
                    const uint16_t & EXPECTED_STATUS = DP18_PLL_EXP_LOCK_STATUS;
                    const uint16_t ACTUAL_STATUS = dp_p0_lock_data.getHalfWord(3);
                    const fapi::Target & MBA_IN_ERROR = i_target;
                    FAPI_SET_HWP_ERROR(rc, RC_MSS_DP18_0_PLL_FAILED_TO_LOCK);
                    break;
                }
                // for DD1 parts that have the DP18 lock bug - keep going to initialize any other channels that might be good.
                FAPI_INF("One or more DP18 port 0 (0x0C000) PLL failed to lock!   Lock Status = %04X",dp_p0_lock_data.getHalfWord(3));
                FAPI_INF("Continuing anyway to initialize any other channels that might be good...");
            }
            //-------------------------------
            // 8c - Check Port 1 DP lock bits
            if ( dp_p1_lock_data.getHalfWord(3) != DP18_PLL_EXP_LOCK_STATUS )
            {
                if ( dp_p1_lock_data.isBitClear(48) ) { FAPI_INF("Port 1 DP 0 PLL failed to lock!");}
                if ( dp_p1_lock_data.isBitClear(49) ) { FAPI_INF("Port 1 DP 1 PLL failed to lock!");}
                if ( dp_p1_lock_data.isBitClear(50) ) { FAPI_INF("Port 1 DP 2 PLL failed to lock!");}
                if ( dp_p1_lock_data.isBitClear(51) ) { FAPI_INF("Port 1 DP 3 PLL failed to lock!");}
                if ( dp_p1_lock_data.isBitClear(52) ) { FAPI_INF("Port 1 DP 4 PLL failed to lock!");}
                if (!continue_on_dp18_pll_lock_failure)
                {
                    FAPI_ERR("One or more DP18 port 1 (0x1C000) PLL failed to lock!   Lock Status = %04X",dp_p1_lock_data.getHalfWord(3));
                    FAPI_ERR("DP18 PLL lock failed and this chip does not have the known DP18 lock bug.");
                    const uint16_t & EXPECTED_STATUS = DP18_PLL_EXP_LOCK_STATUS;
                    const uint16_t ACTUAL_STATUS = dp_p1_lock_data.getHalfWord(3);
                    const fapi::Target & MBA_IN_ERROR = i_target;
                    FAPI_SET_HWP_ERROR(rc, RC_MSS_DP18_1_PLL_FAILED_TO_LOCK);
                    break;
                }
                // for DD1 parts that have the DP18 lock bug - keep going to initialize any other channels that might be good.
                FAPI_INF("One or more DP18 port 1 (0x1C000) PLL failed to lock!   Lock Status = %04X",dp_p1_lock_data.getHalfWord(3));
                FAPI_INF("Continuing anyway to initialize any other channels that might be good...");
            }
            //-------------------------------
            // 8d - Check Port 0 AD lock bits
            if ( ad_p0_lock_data.getHalfWord(3) != AD32S_PLL_EXP_LOCK_STATUS )
            {
                FAPI_ERR("One or more AD32S port 0 (0x0C001) PLL failed to lock!   Lock Status = %04X",ad_p0_lock_data.getHalfWord(3));
                const uint16_t & EXPECTED_STATUS = AD32S_PLL_EXP_LOCK_STATUS;
                const uint16_t ACTUAL_STATUS = ad_p0_lock_data.getHalfWord(3);
                const fapi::Target & MBA_IN_ERROR = i_target;
                FAPI_SET_HWP_ERROR(rc, RC_MSS_AD32S_0_PLL_FAILED_TO_LOCK);
                break;
            }
            //-------------------------------
            // 8e - Check Port 1 AD lock bits
            if ( ad_p1_lock_data.getHalfWord(3) != AD32S_PLL_EXP_LOCK_STATUS )
            {
                FAPI_ERR("One or more AD32S port 1 (0x1C001) PLL failed to lock!   Lock Status = %04X",ad_p1_lock_data.getHalfWord(3));
                const uint16_t & EXPECTED_STATUS = AD32S_PLL_EXP_LOCK_STATUS;
                const uint16_t ACTUAL_STATUS = ad_p1_lock_data.getHalfWord(3);
                const fapi::Target & MBA_IN_ERROR = i_target;
                FAPI_SET_HWP_ERROR(rc, RC_MSS_AD32S_1_PLL_FAILED_TO_LOCK);
                break;
            }
        }
        else
        {
            FAPI_INF("AD32S PLLs are now locked.  DP18 PLLs should also be locked.");
        }



        //
        // 9.Write '8024'x into the ADR SysClk Phase Rotator Control Registers and into the DP18 SysClk Phase Rotator Control Registers.
        //   This takes the dphy_nclk/SysClk alignment circuit out of reset and puts the dphy_nclk/SysClk alignment circuit into the Continuous Update Mode.
        //           ADR SysClk PR Control Registers  :  (SCOM Addr: 0x800080320301143F, 0x800084320301143F, 0x800180320301143F, 0x800184320301143F,
        //                                                           0x800080320301183F, 0x800084320301183F, 0x800180320301183F, 0x800184320301183F)
        //          DP18 SysClk PR Control Registers  :  (SCOM Addr: 0x800000070301143F, 0x800004070301143F, 0x800008070301143F, 0x80000C070301143F, 0x800010070301143F,
        //                                                           0x800000070301183F, 0x800004070301183F, 0x800008070301183F, 0x80000C070301183F, 0x800010070301183F,
        //                                                           0x800100070301143F, 0x800104070301143F, 0x800108070301143F, 0x80010C070301143F, 0x800110070301143F,
        //                                                           0x800100070301183F, 0x800104070301183F, 0x800108070301183F, 0x80010C070301183F, 0x800110070301183F)
        FAPI_DBG("Step 9: Write '8024'x into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs.\n");
        rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000008024ull);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x8024 into Phase Rotator Registers.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0_0x800080320301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0_0x800180320301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1_0x800084320301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1_0x800184320301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1 register.");
            break;
        }



        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0_0x800000070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0 register.");
            P0_DP0_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0 register.");
            P1_DP0_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1 register.");
            P0_DP1_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1 register.");
            P1_DP1_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2 register.");
            P0_DP2_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2 register.");
            P1_DP2_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3 register.");
            P0_DP3_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3 register.");
            P1_DP3_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4 register.");
            P0_DP4_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4 register.");
            P1_DP4_reg_error = true;
        }



        //
        // 10.Wait at least 5932 memory clock cycles to allow the clock alignment circuit to perform initial alignment.
        FAPI_DBG("Step 10: Wait at least 5932 memory clock cycles to allow the clock alignment circuit to perform initial alignment.\n");
        rc = fapiDelay(DELAY_100US, DELAY_2000000SIMCYCLES); // wait 2000000 simcycles (in sim mode) OR 100 usec (in hw mode)
        if (rc)
        {
            FAPI_ERR("Error executing fapiDelay of 100us or 2000000simcycles.");
            break;
        }



        //
        // 11.Write 0x0000 into the PC Resets Register. This deasserts the SysClk Reset
        //                                                (SCOM Addr: 0x8000C00E0301143F, 0x8001C00E0301143F, 0x8000C00E0301183F, 0x8001C00E0301183F)
        FAPI_DBG("Step 11: Write 0x0000 into the PC Resets Register. This deasserts the SysClk Reset.\n");
        rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000000000ull);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x0000 into the PC Resets registers.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_RESETS_P0_0x8000C00E0301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_RESETS_P0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_RESETS_P1_0x8001C00E0301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_RESETS_P1 register.");
            break;
        }



        //
        // 12.Write '8020'x into the ADR SysClk Phase Rotator Control Registers and into the DP18 SysClk Phase Rotator Control Registers.
        //    This takes the dphy_nclk/SysClk alignment circuit out of Continuous Update Mode.
        //           ADR SysClk PR Control Registers  :  (SCOM Addr: 0x800080320301143F, 0x800084320301143F, 0x800180320301143F, 0x800184320301143F,
        //                                                           0x800080320301183F, 0x800084320301183F, 0x800180320301183F, 0x800184320301183F)
        //          DP18 SysClk PR Control Registers  :  (SCOM Addr: 0x800000070301143F, 0x800004070301143F, 0x800008070301143F, 0x80000C070301143F, 0x800010070301143F,
        //                                                           0x800000070301183F, 0x800004070301183F, 0x800008070301183F, 0x80000C070301183F, 0x800010070301183F,
        //                                                           0x800100070301143F, 0x800104070301143F, 0x800108070301143F, 0x80010C070301143F, 0x800110070301143F,
        //                                                           0x800100070301183F, 0x800104070301183F, 0x800108070301183F, 0x80010C070301183F, 0x800110070301183F)
        FAPI_DBG("Step 12: Write '8020'x into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs.\n");
        rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000008020ull);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x8020 into the Phase Rotator registers.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0_0x800080320301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0_0x800180320301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1_0x800084320301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1_0x800184320301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1 register.");
            break;
        }



        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0_0x800000070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0 register.");
            P0_DP0_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0 register.");
            P1_DP0_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1 register.");
            P0_DP1_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1 register.");
            P1_DP1_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2 register.");
            P0_DP2_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2 register.");
            P1_DP2_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3 register.");
            P0_DP3_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3 register.");
            P1_DP3_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4 register.");
            P0_DP4_reg_error = true;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4 register.");
            P1_DP4_reg_error = true;
        }



        // Work-around required to get alignment in simulation
        // Read the ATTR_IS_SIMULATION attribute
        rc = FAPI_ATTR_GET( ATTR_IS_SIMULATION, NULL, is_simulation);
        if (rc)
        {
            FAPI_ERR("Failed to get attribute: ATTR_IS_SIMULATION.");
            break;
        }
        if (is_simulation)
        {
            FAPI_DBG("Step 12.1 (SIM ONLY): Write '8000'x into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs.\n");
            rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000008000ull);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x8020 into the Phase Rotator registers.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0_0x800080320301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0 register.");
                break;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0_0x800180320301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0 register.");
                break;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1_0x800084320301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1 register.");
                break;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1_0x800184320301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1 register.");
                break;
            }



            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0_0x800000070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0 register.");
                P0_DP0_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0 register.");
                P1_DP0_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1 register.");
                P0_DP1_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1 register.");
                P1_DP1_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2 register.");
                P0_DP2_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2 register.");
                P1_DP2_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3 register.");
                P0_DP3_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3 register.");
                P1_DP3_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4 register.");
                P0_DP4_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4 register.");
                P1_DP4_reg_error = true;
            }


            FAPI_DBG("Step 12.2 (SIM ONLY): Write '8080'x into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs.\n");
            rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000008080ull);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x8020 into the Phase Rotator registers.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0_0x800080320301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0 register.");
                break;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0_0x800180320301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0 register.");
                break;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1_0x800084320301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1 register.");
                break;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1_0x800184320301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1 register.");
                break;
            }



            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0_0x800000070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0 register.");
                P0_DP0_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0 register.");
                P1_DP0_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1 register.");
                P0_DP1_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1 register.");
                P1_DP1_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2 register.");
                P0_DP2_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2 register.");
                P1_DP2_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3 register.");
                P0_DP3_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3 register.");
                P1_DP3_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4 register.");
                P0_DP4_reg_error = true;
            }
            rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4 register.");
                P1_DP4_reg_error = true;
            }
        }


        //
        // 13.Wait at least 32 memory clock cycles.
        FAPI_DBG("Step 13: Wait at least 32 memory clock cycles.\n");
        rc = fapiDelay(DELAY_100NS, DELAY_2000SIMCYCLES); // wait 2000 simcycles (in sim mode) OR 100 nS (in hw mode)
        if (rc)
        {
            FAPI_ERR("Error executing fapiDelay of 100ns or 2000simcycles.");
            break;
        }



        //
        // 14.Write 0x0018 to PC IO PVT N/P FET driver control register to enable internal ZQ calibration.
        //    This step takes approximately 2112 (64 * 33) memory clock cycles.
        //                                                (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 14: Write 0x0018 to PC IO PVT N/P FET driver control register to enable internal ZQ calibration.\n");
        rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000000018ull);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x0018 into the PC_IO_PVT_FET_CONTROL registers.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0_0x8000C0140301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1_0x8001C0140301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1 register.");
            break;
        }





        //
        // Now do some error checking and mark bad channels
        // Check to see if there were any register access problems on DP registers, or corresponding PLLs that did not lock.
        // If so, mark the DP pairs as bad.

        // Loop through only valid (functional) dimms.
        // For each valid dimm, loop through all the ranks belonging to that dimm.
        // If there was either a register access error, or if the PLL did not lock, then mark the DP pair as bad.
        // Do this by setting the dqBitmap attribute for all dimms and ranks associated with that PLL or register.
        // Read the dqBitmap first, so that you do not clear values that may already be set.
        // (Some DP channels may already be marked as bad.)

	// Find out which dimms are functional
        rc = FAPI_ATTR_GET(ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR,	&i_target, valid_dimms);
        if (rc)
        {
            FAPI_ERR("Failed to get attribute: ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR");
            break;
        }
        valid_dimm[0][0] = (valid_dimms & 0x80);
        valid_dimm[0][1] = (valid_dimms & 0x40);
        valid_dimm[1][0] = (valid_dimms & 0x08);
        valid_dimm[1][1] = (valid_dimms & 0x04);

        // Find out how many ranks are on each dimm
        rc = FAPI_ATTR_GET( ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target, num_mranks_per_dimm);
        if (rc)
        {
            FAPI_ERR("Failed to get attribute: ATTR_EFF_NUM_RANKS_PER_DIMM.");
            break;
        }


        // Loop through each PORT (0,1)
        for(l_port=0; l_port<1; l_port++ )
        {
            // Loop through each DIMM:(0,1)
            for(l_dimm=0; l_dimm<DIMM_DQ_MAX_MBAPORT_DIMMS; l_dimm++ )
            {
                if (valid_dimm[l_port][l_dimm])
                {
                    // Ok, this DIMM is functional. So loop through the RANKs of this dimm.
                    for(l_rank=0; l_rank<num_mranks_per_dimm[l_port][l_dimm]; l_rank++ )
                    {
                        // Get the bad DQ Bitmap for l_port, l_dimm, l_rank
                        rc = dimmGetBadDqBitmap(i_target,
                                                l_port,
                                                l_dimm,
                                                l_rank,
                                                l_dqBitmap);
                        if (rc)
                        {
                            FAPI_ERR("Error from dimmGetBadDqBitmap");
                            break;
                        }
            
                        // Mark the bad bits for each register that had problems or PLL that did not lock
                        new_error = false;
                        if ( l_port == 0 )
                        {
                            if (( P0_DP0_reg_error ) || ( dp_p0_lock_data.isBitClear(48) )) { l_dqBitmap[0] = 0xff; l_dqBitmap[1] = 0xff; new_error = true; }
                            if (( P0_DP1_reg_error ) || ( dp_p0_lock_data.isBitClear(49) )) { l_dqBitmap[2] = 0xff; l_dqBitmap[3] = 0xff; new_error = true; }
                            if (( P0_DP2_reg_error ) || ( dp_p0_lock_data.isBitClear(50) )) { l_dqBitmap[4] = 0xff; l_dqBitmap[5] = 0xff; new_error = true; }
                            if (( P0_DP3_reg_error ) || ( dp_p0_lock_data.isBitClear(51) )) { l_dqBitmap[6] = 0xff; l_dqBitmap[7] = 0xff; new_error = true; }
                            if (( P0_DP4_reg_error ) || ( dp_p0_lock_data.isBitClear(52) )) { l_dqBitmap[8] = 0xff; l_dqBitmap[9] = 0xff; new_error = true; }
                        } else {
                            if (( P1_DP0_reg_error ) || ( dp_p1_lock_data.isBitClear(48) )) { l_dqBitmap[0] = 0xff; l_dqBitmap[1] = 0xff; new_error = true; }
                            if (( P1_DP1_reg_error ) || ( dp_p1_lock_data.isBitClear(49) )) { l_dqBitmap[2] = 0xff; l_dqBitmap[3] = 0xff; new_error = true; }
                            if (( P1_DP2_reg_error ) || ( dp_p1_lock_data.isBitClear(50) )) { l_dqBitmap[4] = 0xff; l_dqBitmap[5] = 0xff; new_error = true; }
                            if (( P1_DP3_reg_error ) || ( dp_p1_lock_data.isBitClear(51) )) { l_dqBitmap[6] = 0xff; l_dqBitmap[7] = 0xff; new_error = true; }
                            if (( P1_DP4_reg_error ) || ( dp_p1_lock_data.isBitClear(52) )) { l_dqBitmap[8] = 0xff; l_dqBitmap[9] = 0xff; new_error = true; }
                        }
            
                        // If there are new errors, write back the bad DQ Bitmap for l_port, l_dimm, l_rank
                        if ( new_error )
                        {
                            rc = dimmSetBadDqBitmap(i_target,
                                                    l_port,
                                                    l_dimm,
                                                    l_rank,
                                                    l_dqBitmap);
                            if (rc)
                            {
                                FAPI_ERR("Error from dimmPutBadDqBitmap");
                                break;
                            }
                        }
                    }  // End of loop over RANKs
                    if (rc) break;    // Go to end of proc if error found inside loop.
                }
            }  // End of loop over DIMMs
            if (rc) break;    // Go to end of proc if error found inside loop.
        }  // End of loop over PORTs


    } while(0);

    FAPI_INF("********* mss_ddr_phy_reset complete *********");

    return rc;
}


// function moved from draminit because we need mclk low not asserted for pll locking
ReturnCode mss_deassert_force_mclk_low (const Target& i_target)
{ 
    ReturnCode rc;
    uint32_t rc_num = 0;
    ecmdDataBufferBase data_buffer(64);

    FAPI_INF( "+++++++++++++++++++++ DEASSERTING FORCE MCLK LOW +++++++++++++++++++++");


    rc = fapiGetScom(i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data_buffer);
    if(rc) return rc;
    rc_num = data_buffer.setBit(63);
    rc.setEcmdError( rc_num);
    if(rc) return rc;
    rc = fapiPutScom(i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data_buffer);
    if(rc) return rc;

    return rc;
}

fapi::ReturnCode mss_ddr_phy_flush(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase i_data(64);
    ecmdDataBufferBase l_mask(64);
	
	FAPI_INF(" Performing mss_ddr_phy_flush routine");

	FAPI_INF("ADR/DP18 FLUSH: 1) set PC_POWERDOWN_1 register, powerdown enable(48), flush bit(58)");
	rc_ecmd = i_data.flushTo0();		// clear data buffer
	rc_ecmd |= i_data.setBit(48);		// set MASTER_PD_CNTL bit
	rc_ecmd |= i_data.setBit(58);		// set WR_FIFO_STAB bit

	rc_ecmd |= l_mask.flushTo0();		// clear mask buffer
	rc_ecmd |= l_mask.setBit(48);		// set MASTER_PD_CNTL bit
	rc_ecmd |= l_mask.setBit(58);		// set WR_FIFO_STAB mask bit
	if (rc_ecmd)
	{
		rc.setEcmdError(rc_ecmd);
		return rc;
	}

	rc = fapiPutScomUnderMask(i_target, DPHY01_DDRPHY_PC_POWERDOWN_1_P0_0x8000C0100301143F, i_data, l_mask);
	if(rc) return rc;

	rc = fapiPutScomUnderMask(i_target, DPHY01_DDRPHY_PC_POWERDOWN_1_P1_0x8001C0100301143F, i_data, l_mask);
	if(rc) return rc;

	rc = fapiDelay(DELAY_100NS, DELAY_2000SIMCYCLES); // wait 2000 simcycles (in sim mode) OR 100 nS (in hw mode)
	if(rc) return rc;
	
	FAPI_INF("ADR/DP18 FLUSH: 2) clear PC_POWERDOWN_1 register, powerdown enable(48), flush bit(58)");
	rc_ecmd = i_data.flushTo0();		// clear data buffer

	rc_ecmd |= l_mask.flushTo0();		// clear mask buffer
	rc_ecmd |= l_mask.setBit(48);		// set MASTER_PD_CNTL bit
	rc_ecmd |= l_mask.setBit(58);		// set WR_FIFO_STAB mask bit
	if (rc_ecmd)
	{
		rc.setEcmdError(rc_ecmd);
		return rc;
	}

	rc = fapiPutScomUnderMask(i_target, DPHY01_DDRPHY_PC_POWERDOWN_1_P0_0x8000C0100301143F, i_data, l_mask);
	if(rc) return rc;

	rc = fapiPutScomUnderMask(i_target, DPHY01_DDRPHY_PC_POWERDOWN_1_P1_0x8001C0100301143F, i_data, l_mask);
	if(rc) return rc;

	return rc;
}

} //end extern C


/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: mss_ddr_phy_reset.C,v $
Revision 1.27  2014/01/16 20:54:48  mfred
Updates for passing more data to error handler.  From Mike Jones.

Revision 1.26  2013/09/16 20:17:57  mwuu
Cleanup of the calling functions so first fail will run unmask function.

Revision 1.25  2013/06/26 17:40:56  mwuu
Submitting Mark Fredrickson's clean up from FW review.

Revision 1.24  2013/06/19 20:07:53  mwuu
Implemented new ADR flush procedure via powerdown1 register.

Revision 1.22  2013/06/14 17:44:49  mwuu
Backed out the ADR flush workaround.

Revision 1.21  2013/06/12 23:17:19  mwuu
Removed DP18 flush section, fixed ADR toggle flush loop.

Revision 1.20  2013/06/12 20:58:17  mwuu
Fixed loop control structure for toggling the 0,1,0 in ADR block of flush FN.

Revision 1.19  2013/06/11 19:05:27  mwuu
Update to use master ranks for bad bitmap, and added flush function for ADR/DP18 workaround.

Revision 1.18  2013/03/18 19:38:48  mfred
Update to not continue if DP18 PLL fails to lock and EC is DD2.

Revision 1.17  2012/12/03 15:49:27  mfred
Fixed bug to allow exit from loops in case of error.

Revision 1.16  2012/11/29 23:02:53  mfred
Fix for ZQ_CAL workaround and support for partial set of dimms.

Revision 1.15  2012/11/16 16:36:20  mfred
Update code to return an error from mss_slew_cal, if any, unless there is an error from mss_ddr_phy_reset.

Revision 1.14  2012/11/14 23:42:43  mfred
Call mss_slew_cal after the ddr_phy_reset steps.

Revision 1.13  2012/10/19 20:27:26  mfred
Added support for sub-partial-good operation when only a subset of DPs are good.

Revision 1.12  2012/09/06 15:01:46  gollub

Calling mss_unmask_ddrphy_errors after mss_ddr_phy_reser_cloned.

Revision 1.11  2012/07/27 16:43:25  bellows
CQ216395 hardware needs force mclk low in phy reset procedure

Revision 1.10  2012/07/24 17:11:02  mfred
Removed confusing comment.

Revision 1.9  2012/07/18 16:27:39  mfred
Check for ATTR_IS_SIMULATION attribute instead of use compiler switch.

Revision 1.8  2012/06/07 22:30:25  jmcgill
add sim only inits for phase rotator alignment (wrapped in SIM_ONLY ifdef for now)

Revision 1.7  2012/05/31 18:27:54  mfred
Removing some config settings that are now done in config file.  See Gary Van Huben note May 3, 2012

Revision 1.6  2012/03/21 18:16:25  mfred
Remove some commented out lines.

Revision 1.5  2012/03/21 18:12:24  mfred
Made updates requested by GFW team during code review 1.

Revision 1.4  2012/02/22 18:36:36  mfred
update for PLL lock polling, and check for ddr3 vs ddr4

Revision 1.3  2012/02/14 16:34:12  mfred
Fixed code to use halfword(3) instead of halfword(0)

Revision 1.2  2012/01/31 18:42:07  mfred
Change proc to do a single MBA and DDRPHY.  Looping will be handled by the target.

Revision 1.1  2011/11/18 14:20:10  mfred
Changed name of cen_ddr_phy_reset to mss_ddr_phy_reset.

Revision 1.1  2011/10/27 22:49:36  mfred
New version of cen_ddr_phy_reset that support the extended scom addresses.

Revision 1.5  2011/04/29 16:44:06  mfred
Removed a couple of unused address variables.

Revision 1.4  2011/04/18 20:12:49  mfred
Update scom addresses in comments and fix steps 10 and 13 per info from Gary H.

Revision 1.3  2011/04/18 18:54:58  mfred
Fixed some output messages.

Revision 1.2  2011/04/12 13:22:32  mfred
Fixed some output messages.

Revision 1.1  2011/04/07 16:15:03  mfred
Initial release.


*/

