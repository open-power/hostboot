//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/dram_training/mss_ddr_phy_reset/mss_ddr_phy_reset.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
// $Id: mss_ddr_phy_reset.C,v 1.4 2012/02/22 18:36:36 mfred Exp $
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

uint64_t  delay_1ns               = 1;        // general purpose 1 ns delay for HW mode        (20 sim cycles if simclk - 20ghz)
uint64_t  delay_10ns              = 10;       // general purpose 10 ns delay for HW mode       (200 sim cycles if simclk - 20ghz)
uint64_t  delay_100ns             = 100;      // general purpose 100 ns delay for HW mode      (2000 sim cycles if simclk - 20ghz)
uint64_t  delay_1us               = 1000;     // general purpose 1 usec delay for HW mode      (20000 sim cycles if simclk - 20ghz)
uint64_t  delay_10us              = 10000;    // general purpose 10 usec delay for HW mode     (200000 sim cycles if simclk - 20ghz)
uint64_t  delay_100us             = 100000;   // general purpose 100 usec delay for HW mode    (2000000 sim cycles if simclk - 20ghz)
uint64_t  delay_1ms               = 1000000;  // general purpose 1 ms delay for HW mode        (20000000 sim cycles if simclk - 20ghz)
uint64_t  delay_20simcycles       = 20;       // general purpose 20 sim cycle delay for sim mode       (1 ns if simclk = 20Ghz)
uint64_t  delay_200simcycles      = 200;      // general purpose 200 sim cycle delay for sim mode      (10 ns if simclk = 20Ghz)
uint64_t  delay_2000simcycles     = 2000;     // general purpose 2000 sim cycle delay for sim mode     (100 ns if simclk = 20Ghz)
uint64_t  delay_20000simcycles    = 20000;    // general purpose 20000 sim cycle delay for sim mode    (1 usec if simclk = 20Ghz)
uint64_t  delay_200000simcycles   = 200000;   // general purpose 200000 sim cycle delay for sim mode   (10 usec if simclk = 20Ghz)
uint64_t  delay_2000000simcycles  = 2000000;  // general purpose 2000000 sim cycle delay for sim mode  (100 usec if simclk = 20Ghz)
uint64_t  delay_20000000simcycles = 20000000; // general purpose 20000000 sim cycle delay for sim mode (1 ms if simclk = 20Ghz)


extern "C" {


using namespace fapi;

//ReturnCode mss_ddr_phy_reset(Target i_target, bool i_parm1, uint32_t i_parm2) {
ReturnCode mss_ddr_phy_reset(Target i_target) {
  ReturnCode l_rc;
  ecmdDataBufferBase data;
  ecmdDataBufferBase mask;
  ecmdDataBufferBase i_data, j_data, k_data, l_data;
  i_data.setBitLength(64);
  j_data.setBitLength(64);
  k_data.setBitLength(64);
  l_data.setBitLength(64);
  uint32_t poll_count = 0;
  uint32_t done_polling = 0;
  uint8_t dram_gen = 0; 

  FAPI_INF("");
  FAPI_INF("********* *********************** *********");
  FAPI_INF("********* mss_ddr_phy_reset start *********");
  FAPI_INF("********* *********************** *********");

  //FAPI_INF("mss_ddr_phy_reset::My parms are:");
  //FAPI_INF("       ::i_parm1 = %d", i_parm1);
  //FAPI_INF("       ::i_parm2 = %d", i_parm2);
 
  //l_rc = fapiGetScom(i_target, 0x000F0012, data );
  //if (l_rc) {
  //  FAPI_ERR("fapiGetScom() failed."); return l_rc;
  //}
  //data.flushTo1();
  //data.clearBit(0); 
  //data.clearBit(31); 
  //l_rc = fapiPutScom(i_target, 0x000F0012, data );
  //if (l_rc) {
  //  FAPI_ERR("fapiGetScom() failed."); return l_rc;
  //}

  //
  // Here are the specific instructions from section 14.7.2 of the Centaur Chip Specification:
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
    l_rc = fapiGetScom( i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data); if ( l_rc ) return l_rc;
    data.setBit(25);
    l_rc = fapiPutScom( i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data); if ( l_rc ) return l_rc;

    fapiDelay(delay_100ns, delay_2000simcycles); // wait 2000 simcycles (in sim mode) OR 100 nS (in hw mode)



  //
  // 3. For DD0: Deassert dfi_reset_all (GP4 bit 5 = "0")
  //    For DD1: Deassert mcbist_ddr_dfi_reset_recover = "0" (CCS_MODEQ(25) SCOM Addr: 0x030106A7 0x03010EA7)
    FAPI_DBG("Step 3: MBA CCS_MODEQ(25), Setting mcbist_ddr_dfi_reset_recover = 0 to release soft reset.\n");
    l_rc = fapiGetScom( i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data); if ( l_rc ) return l_rc;
    data.clearBit(25);
    l_rc = fapiPutScom( i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data); if ( l_rc ) return l_rc;



  //
  // 4. Write 0x0008 to PC IO PVT N/P FET driver control registers to assert ZCTL reset
  //    and reset the internal impedance controller.(SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
    FAPI_DBG("Step 4: Write 0x0008 to PC IO PVT N/P FET driver control registers to assert ZCTL reset.\n");
    i_data.setHalfWord(3, 0x0008);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0_0x8000C0140301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1_0x8001C0140301143F, i_data); if ( l_rc ) return l_rc;



  //
  // 5. Write 0x0000 to PC IO PVT N/P FET driver control registers to deassert ZCTL reset
  //                                                (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
    FAPI_DBG("Step 5: Write 0x0000 to PC IO PVT N/P FET driver control registers to deassert ZCTL reset.\n");
    i_data.setHalfWord(3, 0x0000);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0_0x8000C0140301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1_0x8001C0140301143F, i_data); if ( l_rc ) return l_rc;



  //
  // 6. For DD0: 32 memory clock cycles after asserting dfi_reset_recover, program the following registers
  //    to all zeros for DDR3. Set to 0x1202 for DDR4
  // -- Set PC Configuration 0            to 0x0000 for DDR3 or 0x1202 for DDR4
  //                                                (SCOM Addr: 0x8000C00C0301143F, 0x8000C00C0301183F, 0x8001C00C0301143F, 0x8001C00C0301183F)
  // -- Set ADR PLL/VREG Configuration 0  to 0x0000 (SCOM Addr: 0x800080300301143F, 0x800084300301143F, 0x800180300301143F, 0x800184300301143F,
  //                                                            0x800080300301183F, 0x800084300301183F, 0x800180300301183F, 0x800184300301183F)
  // -- Set ADR PLL/VREG Configuration 1  to 0x0040 (SCOM Addr: 0x800080310301143F, 0x800084310301143F, 0x800180310301143F, 0x800184310301143F,
  //                                                            0x800080310301183F, 0x800084310301183F, 0x800180310301183F, 0x800184310301183F)
  // -- Set DP18 PLL/VREG Configuration 0 to 0x0000 (SCOM Addr: 0x800000760301143F, 0x800004760301143F, 0x800008760301143F, 0x80000C760301143F, 0x800010760301143F,
  //                                                            0x800000760301183F, 0x800004760301183F, 0x800008760301183F, 0x80000C760301183F, 0x800010760301183F,
  //                                                            0x800100760301143F, 0x800104760301143F, 0x800108760301143F, 0x80010C760301143F, 0x800110760301143F,
  //                                                            0x800100760301183F, 0x800104760301183F, 0x800108760301183F, 0x80010C760301183F, 0x800110760301183F)
  // -- Set DP18 PLL/VREG Configuration 1 to 0x0040 (SCOM Addr: 0x800000770301143F, 0x800004770301143F, 0x800008770301143F, 0x80000C770301143F, 0x800010770301143F,
  //                                                            0x800000770301183F, 0x800004770301183F, 0x800008770301183F, 0x80000C770301183F, 0x800010770301183F,
  //                                                            0x800100770301143F, 0x800104770301143F, 0x800108770301143F, 0x80010C770301143F, 0x800110770301143F,
  //                                                            0x800100770301183F, 0x800104770301183F, 0x800108770301183F, 0x80010C770301183F, 0x800110770301183F)
  //    For DD1; This step might be able to be skipped if the PLL registers will be scan initialized to the proper values.

    // Step 6a: selects either 0x0000 (for DDR3) or 0x1202 (for DDR4) based on the dram_generation attribute
    l_rc = FAPI_ATTR_GET( ATTR_EFF_DRAM_GEN, &i_target, dram_gen); if ( l_rc ) return l_rc;
    if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
    {
        FAPI_DBG("Step 6a: Set PC Configuration 0 to 0x1202 for DDR4.\n");
        i_data.setHalfWord(3, 0x1202);
    }
    else
    {
        FAPI_DBG("Step 6a: Set PC Configuration 0 to 0x0000 for DDR3.\n");
        i_data.setHalfWord(3, 0x0000);
    }
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_CONFIG0_P0_0x8000C00C0301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_CONFIG0_P1_0x8001C00C0301143F, i_data); if ( l_rc ) return l_rc;

    FAPI_DBG("Step 6b: Set ADR PLL/VREG Configuration 0 to 0x0000.\n");
    i_data.setHalfWord(3, 0x0000);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P0_ADR32S0_0x800080300301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P1_ADR32S0_0x800180300301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P0_ADR32S1_0x800084300301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_0_P1_ADR32S1_0x800184300301143F, i_data); if ( l_rc ) return l_rc;

    FAPI_DBG("Step 6c: Set ADR PLL/VREG Configuration 1 to 0x0040.\n");
    i_data.setHalfWord(3, 0x0040);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P0_ADR32S0_0x800080310301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P1_ADR32S0_0x800180310301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P0_ADR32S1_0x800084310301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_PLL_VREG_CONFIG_1_P1_ADR32S1_0x800184310301143F, i_data); if ( l_rc ) return l_rc;

    FAPI_DBG("Step 6d: Set DP18 PLL/VREG Configuration 0 to 0x0000.\n");
    i_data.setHalfWord(3, 0x0000);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_0_0x800000760301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_0_0x800100760301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_1_0x800004760301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_1_0x800104760301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_2_0x800008760301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_2_0x800108760301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_3_0x80000C760301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_3_0x80010C760301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG0_P0_4_0x800010760301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG0_P1_4_0x800110760301143F, i_data); if ( l_rc ) return l_rc;

    FAPI_DBG("Step 6e: Set DP18 PLL/VREG Configuration 1 to 0x0040.\n");
    i_data.setHalfWord(3, 0x0040);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_0_0x800000770301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_0_0x800100770301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_1_0x800004770301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_1_0x800104770301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_2_0x800008770301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_2_0x800108770301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_3_0x80000C770301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_3_0x80010C770301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG1_P0_4_0x800010770301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_PLL_CONFIG1_P1_4_0x800110770301143F, i_data); if ( l_rc ) return l_rc;



  //
  // 7. Wait at least 1 microsecond. This is the required PLL reset time.  (This may be skipped for DD1)
    FAPI_DBG("Step 7: PLL reset delay is not required for Centaur DD1.\n");
    // This delay should not be required for DD1
    // fapiDelay(delay_1us, delay_20000simcycles); // wait 20000 simcycles (in sim mode) OR 1 usec (in hw mode)



  //
  // 8. Write 0x4000 into the PC Resets Registers. This deasserts the PLL_RESET and leaves the SYSCLK_RESET bit active
  //                                                (SCOM Addr: 0x8000C00E0301143F, 0x8001C00E0301143F, 0x8000C00E0301183F, 0x8001C00E0301183F)
    FAPI_DBG("Step 8: Write 0x4000 into the PC Resets Registers. This deasserts the PLL_RESET and leaves the SYSCLK_RESET bit active.\n");
    i_data.setHalfWord(3, 0x4000);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_RESETS_P0_0x8000C00E0301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_RESETS_P1_0x8001C00E0301143F, i_data); if ( l_rc ) return l_rc;



  //
  // 9. Wait at least 1 millisecond to allow the PLLs to lock. Otherwise, poll the PC DP18 PLL Lock Status
  //    and the PC AD32S PLL Lock Status to determine if all PLLs have locked.
  //    PC DP18 PLL Lock Status should be 0xF800:  (SCOM Addr: 0x8000C0000301143F, 0x8001C0000301143F, 0x8000C0000301183F, 0x8001C0000301183F)
  //    PC AD32S PLL Lock Status should be 0xC000: (SCOM Addr: 0x8000C0010301143F, 0x8001C0010301143F, 0x8000C0010301183F, 0x8001C0010301183F)
    FAPI_DBG("Step 9: Poll until DP18 and AD32S PLLs have locked....\n");
    // fapiDelay(delay_1ms, delay_20000000simcycles); // wait 20000000 simcycles (in sim mode) OR 1 mS (in hw mode)
    do
    {
        fapiDelay(delay_1us, delay_20000simcycles); // wait 20000 simcycles (in sim mode) OR 1 usec (in hw mode)
        done_polling = 1;
        l_rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0_0x8000C0000301143F, i_data); if ( l_rc ) return l_rc;
        if ( i_data.getHalfWord(3) != 0xF800 ) done_polling = 0;
        l_rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1_0x8001C0000301143F, j_data); if ( l_rc ) return l_rc;
        if ( j_data.getHalfWord(3) != 0xF800 ) done_polling = 0;
        l_rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0_0x8000C0010301143F, k_data); if ( l_rc ) return l_rc;
        if ( k_data.getHalfWord(3) != 0xC000 ) done_polling = 0;
        l_rc = fapiGetScom( i_target, DPHY01_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1_0x8001C0010301143F, l_data); if ( l_rc ) return l_rc;
        if ( l_data.getHalfWord(3) != 0xC000 ) done_polling = 0;


//      FAPI_INF("Polling Loop = %i", poll_count);
//      if ( i_data.getHalfWord(3) != 0xF800 ) FAPI_ERR("DP18  0x0C000 PLL failed to lock!   Lock Status = %04X",i_data.getHalfWord(3));
//      if ( j_data.getHalfWord(3) != 0xF800 ) FAPI_ERR("DP18  0x1C000 PLL failed to lock!   Lock Status = %04X",j_data.getHalfWord(3));
//      if ( k_data.getHalfWord(3) != 0xC000 ) FAPI_ERR("AD32S 0x0C001 PLL failed to lock!   Lock Status = %04X",k_data.getHalfWord(3));
//      if ( l_data.getHalfWord(3) != 0xC000 ) FAPI_ERR("AD32S 0x1C001 PLL failed to lock!   Lock Status = %04X",l_data.getHalfWord(3));


        poll_count++;
    } while ((done_polling == 0) && (poll_count < 10)); // Poll until PLLs are locked.

    if (poll_count == 10)
    {
        FAPI_ERR("DP18 and/or AD32S PLLs failed to lock!");
        if ( i_data.getHalfWord(3) != 0xF800 ) FAPI_ERR("DP18  0x0C000 PLL failed to lock!   Lock Status = %04X",i_data.getHalfWord(3));
        if ( j_data.getHalfWord(3) != 0xF800 ) FAPI_ERR("DP18  0x1C000 PLL failed to lock!   Lock Status = %04X",j_data.getHalfWord(3));
        if ( k_data.getHalfWord(3) != 0xC000 ) FAPI_ERR("AD32S 0x0C001 PLL failed to lock!   Lock Status = %04X",k_data.getHalfWord(3));
        if ( l_data.getHalfWord(3) != 0xC000 ) FAPI_ERR("AD32S 0x1C001 PLL failed to lock!   Lock Status = %04X",l_data.getHalfWord(3));
    }
    else
    {
        FAPI_INF("DP18 and AD32S PLLs are now locked.");
    }



  //
  // 10.Write '8024'x into the ADR SysClk Phase Rotator Control Registers and into the DP18 SysClk Phase Rotator Control Registers.
  //    This takes the dphy_nclk/SysClk alignment circuit out of reset and puts the dphy_nclk/SysClk alignment circuit into the Continuous Update Mode.
  //           ADR SysClk PR Control Registers  :  (SCOM Addr: 0x800080320301143F, 0x800084320301143F, 0x800180320301143F, 0x800184320301143F,
  //                                                           0x800080320301183F, 0x800084320301183F, 0x800180320301183F, 0x800184320301183F)
  //          DP18 SysClk PR Control Registers  :  (SCOM Addr: 0x800000070301143F, 0x800004070301143F, 0x800008070301143F, 0x80000C070301143F, 0x800010070301143F,
  //                                                           0x800000070301183F, 0x800004070301183F, 0x800008070301183F, 0x80000C070301183F, 0x800010070301183F,
  //                                                           0x800100070301143F, 0x800104070301143F, 0x800108070301143F, 0x80010C070301143F, 0x800110070301143F,
  //                                                           0x800100070301183F, 0x800104070301183F, 0x800108070301183F, 0x80010C070301183F, 0x800110070301183F)
    FAPI_DBG("Step 10: Write '8024'x into the ADR SysClk Phase Rotator Control Registers and into the DP18 SysClk Phase Rotator Control Registers.\n");
    i_data.setHalfWord(3, 0x8024);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0_0x800080320301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0_0x800180320301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1_0x800084320301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1_0x800184320301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0_0x800000070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301143F, i_data); if ( l_rc ) return l_rc;



  //
  // 11.Wait at least 5932 memory clock cycles to allow the clock alignment circuit to perform initial alignment.
    FAPI_DBG("Step 11: Wait at least 5932 memory clock cycles to allow the clock alignment circuit to perform initial alignment.\n");
    fapiDelay(delay_100us, delay_2000000simcycles); // wait 2000000 simcycles (in sim mode) OR 100 usec (in hw mode)



  //
  // 12.Write 0x0000 into the PC Resets Register. This deasserts the SysClk Reset
  //                                                (SCOM Addr: 0x8000C00E0301143F, 0x8001C00E0301143F, 0x8000C00E0301183F, 0x8001C00E0301183F)
    FAPI_DBG("Step 12: Write 0x0000 into the PC Resets Register. This deasserts the SysClk Reset.\n");
    i_data.setHalfWord(3, 0x0000);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_RESETS_P0_0x8000C00E0301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_RESETS_P1_0x8001C00E0301143F, i_data); if ( l_rc ) return l_rc;



  //
  // 13.Write '8020'x into the ADR SysClk Phase Rotator Control Registers and into the DP18 SysClk Phase Rotator Control Registers.
  //    This takes the dphy_nclk/SysClk alignment circuit out of Continuous Update Mode.
  //           ADR SysClk PR Control Registers  :  (SCOM Addr: 0x800080320301143F, 0x800084320301143F, 0x800180320301143F, 0x800184320301143F,
  //                                                           0x800080320301183F, 0x800084320301183F, 0x800180320301183F, 0x800184320301183F)
  //          DP18 SysClk PR Control Registers  :  (SCOM Addr: 0x800000070301143F, 0x800004070301143F, 0x800008070301143F, 0x80000C070301143F, 0x800010070301143F,
  //                                                           0x800000070301183F, 0x800004070301183F, 0x800008070301183F, 0x80000C070301183F, 0x800010070301183F,
  //                                                           0x800100070301143F, 0x800104070301143F, 0x800108070301143F, 0x80010C070301143F, 0x800110070301143F,
  //                                                           0x800100070301183F, 0x800104070301183F, 0x800108070301183F, 0x80010C070301183F, 0x800110070301183F)
    FAPI_DBG("Step 13: .\n");
    i_data.setHalfWord(3, 0x8020);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0_0x800080320301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0_0x800180320301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1_0x800084320301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1_0x800184320301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_0_0x800000070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_0_0x800100070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_1_0x800004070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_1_0x800104070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_2_0x800008070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_2_0x800108070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_3_0x80000C070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_3_0x80010C070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P0_4_0x800010070301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_DP18_SYSCLK_PR_P1_4_0x800110070301143F, i_data); if ( l_rc ) return l_rc;



  //
  // 14.Wait at least 32 memory clock cycles.
    FAPI_DBG("Step 14: Wait at least 32 memory clock cycles.\n");
    fapiDelay(delay_100ns, delay_2000simcycles); // wait 2000 simcycles (in sim mode) OR 100 nS (in hw mode)



  //
  // 15.For DD0, use of reset_all results in all DDR configuration informating being erradicated. Therefore, a
  //    multitude of registers needs to be reprogrammed via SCOM. The entire list is enumerated in Section 5.2
  //    Table 51 of the Neo Spec (those with a value of 2, 3 or 4 in the Notes column). The values of these registers
  //    depend on system topology, configuration, physical and environmental characteristics and are maintained in
  //    design data.
  //    For DD1, this step is skipped as those registers would've been configured via scan initialization and should
  //    still be valid due to use of reset_recover.
    FAPI_DBG("Step 15: This step can be skipped for DD1.\n");



  //
  // 16.Write 0x0010 to PC IO PVT N/P FET driver control register to enable internal ZQ calibration.
  //    This step takes approximately 2112 (64 * 33) memory clock cycles.
  //                                                (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
    FAPI_DBG("Step 16: Write 0x0010 to PC IO PVT N/P FET driver control register to enable internal ZQ calibration.\n");
    i_data.setHalfWord(3, 0x0010);
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0_0x8000C0140301143F, i_data); if ( l_rc ) return l_rc;
    l_rc = fapiPutScom( i_target, DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1_0x8001C0140301143F, i_data); if ( l_rc ) return l_rc;

  //




  FAPI_INF("");
  FAPI_INF("********* ************************** *********");
  FAPI_INF("********* mss_ddr_phy_reset complete *********");
  FAPI_INF("********* ************************** *********");
  return l_rc;
}

} //end extern C






/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: mss_ddr_phy_reset.C,v $
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

