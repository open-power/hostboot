/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_training/mss_ddr_phy_reset/mss_ddr_phy_reset.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
// $Id: mss_ddr_phy_reset.C,v 1.7 2012/05/31 18:27:54 mfred Exp $
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

fapi::ReturnCode mss_ddr_phy_reset(const fapi::Target & i_target)
{
    // Target is centaur.mba

    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    uint32_t poll_count = 0;
    uint32_t done_polling = 0;
    ecmdDataBufferBase i_data, j_data, k_data, l_data;


    FAPI_INF("********* mss_ddr_phy_reset start *********");
    do
    { 

        rc_ecmd |= i_data.setBitLength(64);
        rc_ecmd |= j_data.setBitLength(64);
        rc_ecmd |= k_data.setBitLength(64);
        rc_ecmd |= l_data.setBitLength(64);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting ecmd data buffer bit length.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }



        //
        // Here are the specific instructions from section 14.7.3 of the Centaur Chip Specification:
        //
        // Run cen_ddr_phy_reset.C prepares the DDR PLLs. These PLLs were previously configured via scan init, but have
        // been held in reset. At this point the PLL GP bit is deasserted to take the PLLs out of reset.
        // Note - this is done in the cen_startclocks.C procedure.
        //
        // The cen_ddr_phy_reset.C now resets the DDR PHY logic. This process will NOT destroy any configuration values
        // previously loaded via the init file. The intent is for the initialized phase rotator configuration to remain valid after the
        // soft reset completes. If this assumption fails to hold true, it will require replacing this step with a PHY hard reset,
        // and then using inband configuration writes to restore all the DDR Configuration Registers.
        //
        // The following steps must be performed as part of the PHY reset procedure.
  
  
  
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
        // 4. Write 0x0008 to PC IO PVT N/P FET driver control registers to assert ZCTL reset
        //    and reset the internal impedance controller.(SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 4: Write 0x0008 to PC IO PVT N/P FET driver control registers to assert ZCTL reset.\n");
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
        // 5. Write 0x0000 to PC IO PVT N/P FET driver control registers to deassert ZCTL reset
        //                                                (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 5: Write 0x0000 to PC IO PVT N/P FET driver control registers to deassert ZCTL reset.\n");
        rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000000000ull);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x0000 into PC_IO_PVT_FET_CONTROL regs.",  rc_ecmd);
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
        // 6. Write 0x4000 into the PC Resets Registers. This deasserts the PLL_RESET and leaves the SYSCLK_RESET bit active
        //                                                (SCOM Addr: 0x8000C00E0301143F, 0x8001C00E0301143F, 0x8000C00E0301183F, 0x8001C00E0301183F)
        FAPI_DBG("Step 6: Write 0x4000 into the PC Resets Regs. This deasserts the PLL_RESET and leaves the SYSCLK_RESET bit active.\n");
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
        // 7. Wait at least 1 millisecond to allow the PLLs to lock. Otherwise, poll the PC DP18 PLL Lock Status
        //    and the PC AD32S PLL Lock Status to determine if all PLLs have locked.
        //    PC DP18 PLL Lock Status should be 0xF800:  (SCOM Addr: 0x8000C0000301143F, 0x8001C0000301143F, 0x8000C0000301183F, 0x8001C0000301183F)
        //    PC AD32S PLL Lock Status should be 0xC000: (SCOM Addr: 0x8000C0010301143F, 0x8001C0010301143F, 0x8000C0010301183F, 0x8001C0010301183F)
        FAPI_DBG("Step 7: Poll until DP18 and AD32S PLLs have locked....\n");
        do
        {
            rc = fapiDelay(DELAY_1US, DELAY_20000SIMCYCLES); // wait 20000 simcycles (in sim mode) OR 1 usec (in hw mode)
            if (rc)
            {
                FAPI_ERR("Error executing fapiDelay of 1us or 20000simcycles.");
                break;
            }
            done_polling = 1;
            rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0_0x8000C0000301143F, i_data);
            if (rc)
            {
                FAPI_ERR("Error reading DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0 register.");
                break;
            }
            if ( i_data.getHalfWord(3) != DP18_PLL_EXP_LOCK_STATUS ) done_polling = 0;
            rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1_0x8001C0000301143F, j_data);
            if (rc)
            {
                FAPI_ERR("Error reading DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1 register.");
                break;
            }
            if ( j_data.getHalfWord(3) != DP18_PLL_EXP_LOCK_STATUS ) done_polling = 0;
            rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0_0x8000C0010301143F, k_data);
            if (rc)
            {
                FAPI_ERR("Error reading DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0 register.");
                break;
            }
            if ( k_data.getHalfWord(3) != AD32S_PLL_EXP_LOCK_STATUS ) done_polling = 0;
            rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1_0x8001C0010301143F, l_data);
            if (rc)
            {
                FAPI_ERR("Error reading DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1 register.");
                break;
            }
            if ( l_data.getHalfWord(3) != AD32S_PLL_EXP_LOCK_STATUS ) done_polling = 0;
            poll_count++;
        } while ((done_polling == 0) && (poll_count < MAX_POLL_LOOPS)); // Poll until PLLs are locked.
        if (rc) break;    // Go to end of proc if error found inside polling loop.
  
        if (poll_count == MAX_POLL_LOOPS)
        {
            if ( i_data.getHalfWord(3) != DP18_PLL_EXP_LOCK_STATUS )
            {
                FAPI_ERR("DP18  0x0C000 PLL failed to lock!   Lock Status = %04X",i_data.getHalfWord(3));
                FAPI_SET_HWP_ERROR(rc, RC_MSS_DP18_0_PLL_FAILED_TO_LOCK);
                break;
            }
            if ( j_data.getHalfWord(3) != DP18_PLL_EXP_LOCK_STATUS )
            {
                FAPI_ERR("DP18  0x1C000 PLL failed to lock!   Lock Status = %04X",j_data.getHalfWord(3));
                FAPI_SET_HWP_ERROR(rc, RC_MSS_DP18_1_PLL_FAILED_TO_LOCK);
                break;
            }
            if ( k_data.getHalfWord(3) != AD32S_PLL_EXP_LOCK_STATUS )
            {
                FAPI_ERR("AD32S 0x0C001 PLL failed to lock!   Lock Status = %04X",k_data.getHalfWord(3));
                FAPI_SET_HWP_ERROR(rc, RC_MSS_AD32S_0_PLL_FAILED_TO_LOCK);
                break;
            }
            if ( l_data.getHalfWord(3) != AD32S_PLL_EXP_LOCK_STATUS )
            {
                FAPI_ERR("AD32S 0x1C001 PLL failed to lock!   Lock Status = %04X",l_data.getHalfWord(3));
                FAPI_SET_HWP_ERROR(rc, RC_MSS_AD32S_1_PLL_FAILED_TO_LOCK);
                break;
            }
        }
        else
        {
            FAPI_INF("DP18 and AD32S PLLs are now locked.");
        }
  
  
  
        //
        // 8.Write '8024'x into the ADR SysClk Phase Rotator Control Registers and into the DP18 SysClk Phase Rotator Control Registers.
        //   This takes the dphy_nclk/SysClk alignment circuit out of reset and puts the dphy_nclk/SysClk alignment circuit into the Continuous Update Mode.
        //           ADR SysClk PR Control Registers  :  (SCOM Addr: 0x800080320301143F, 0x800084320301143F, 0x800180320301143F, 0x800184320301143F,
        //                                                           0x800080320301183F, 0x800084320301183F, 0x800180320301183F, 0x800184320301183F)
        //          DP18 SysClk PR Control Registers  :  (SCOM Addr: 0x800000070301143F, 0x800004070301143F, 0x800008070301143F, 0x80000C070301143F, 0x800010070301143F,
        //                                                           0x800000070301183F, 0x800004070301183F, 0x800008070301183F, 0x80000C070301183F, 0x800010070301183F,
        //                                                           0x800100070301143F, 0x800104070301143F, 0x800108070301143F, 0x80010C070301143F, 0x800110070301143F,
        //                                                           0x800100070301183F, 0x800104070301183F, 0x800108070301183F, 0x80010C070301183F, 0x800110070301183F)
        FAPI_DBG("Step 8: Write '8024'x into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs.\n");
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
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4 register.");
            break;
        }
  
  
  
        //
        // 9.Wait at least 5932 memory clock cycles to allow the clock alignment circuit to perform initial alignment.
        FAPI_DBG("Step 9: Wait at least 5932 memory clock cycles to allow the clock alignment circuit to perform initial alignment.\n");
        rc = fapiDelay(DELAY_100US, DELAY_2000000SIMCYCLES); // wait 2000000 simcycles (in sim mode) OR 100 usec (in hw mode)
        if (rc)
        {
            FAPI_ERR("Error executing fapiDelay of 100us or 2000000simcycles.");
            break;
        }

  
  
        //
        // 10.Write 0x0000 into the PC Resets Register. This deasserts the SysClk Reset
        //                                                (SCOM Addr: 0x8000C00E0301143F, 0x8001C00E0301143F, 0x8000C00E0301183F, 0x8001C00E0301183F)
        FAPI_DBG("Step 10: Write 0x0000 into the PC Resets Register. This deasserts the SysClk Reset.\n");
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
        // 11.Write '8020'x into the ADR SysClk Phase Rotator Control Registers and into the DP18 SysClk Phase Rotator Control Registers.
        //    This takes the dphy_nclk/SysClk alignment circuit out of Continuous Update Mode.
        //           ADR SysClk PR Control Registers  :  (SCOM Addr: 0x800080320301143F, 0x800084320301143F, 0x800180320301143F, 0x800184320301143F,
        //                                                           0x800080320301183F, 0x800084320301183F, 0x800180320301183F, 0x800184320301183F)
        //          DP18 SysClk PR Control Registers  :  (SCOM Addr: 0x800000070301143F, 0x800004070301143F, 0x800008070301143F, 0x80000C070301143F, 0x800010070301143F,
        //                                                           0x800000070301183F, 0x800004070301183F, 0x800008070301183F, 0x80000C070301183F, 0x800010070301183F,
        //                                                           0x800100070301143F, 0x800104070301143F, 0x800108070301143F, 0x80010C070301143F, 0x800110070301143F,
        //                                                           0x800100070301183F, 0x800104070301183F, 0x800108070301183F, 0x80010C070301183F, 0x800110070301183F)
        FAPI_DBG("Step 11: Write '8020'x into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs.\n");
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
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4 register.");
            break;
        }
        rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301143F, i_data);
        if (rc)
        {
            FAPI_ERR("Error writing DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4 register.");
            break;
        }


  
        //
        // 12.Wait at least 32 memory clock cycles.
        FAPI_DBG("Step 12: Wait at least 32 memory clock cycles.\n");
        rc = fapiDelay(DELAY_100NS, DELAY_2000SIMCYCLES); // wait 2000 simcycles (in sim mode) OR 100 nS (in hw mode)
        if (rc)
        {
            FAPI_ERR("Error executing fapiDelay of 100ns or 2000simcycles.");
            break;
        }

  
  
        //
        // 13.Write 0x0010 to PC IO PVT N/P FET driver control register to enable internal ZQ calibration.
        //    This step takes approximately 2112 (64 * 33) memory clock cycles.
        //                                                (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 13: Write 0x0010 to PC IO PVT N/P FET driver control register to enable internal ZQ calibration.\n");
        rc_ecmd |= i_data.setDoubleWord(0, 0x0000000000000010ull);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write 0x0010 into the PC_IO_PVT_FET_CONTROL registers.",  rc_ecmd);
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




    } while(0);

    FAPI_INF("********* mss_ddr_phy_reset complete *********");
    return rc;
}

} //end extern C





/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: mss_ddr_phy_reset.C,v $
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

