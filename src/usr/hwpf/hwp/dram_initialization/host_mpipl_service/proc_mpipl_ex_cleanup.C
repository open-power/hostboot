/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/host_mpipl_service/proc_mpipl_ex_cleanup.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: proc_mpipl_ex_cleanup.C,v 1.4 2013/02/02 21:02:23 belldi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_mpipl_ex_cleanup.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_mpipl_ex_cleanup.C
// *! DESCRIPTION : Undo step that prepared fast-winkled cores for scanning and set up deep winkle mode
// *!
// *! OWNER  NAME : Dion Bell                Email: belldi@us.ibm.com
// *! BACKUP NAME : Dion Bell                Email: belldi@us.ibm.com
// *!
// *! 
// *! 
// *! 
// *! Additional Note(s):
// *! 
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_mpipl_ex_cleanup.H"

extern "C"
{

  //------------------------------------------------------------------------------
  // name: proc_mpipl_ex_cleanup
  //------------------------------------------------------------------------------
  // purpose: 
  // Undo step that prepared fast-winkled cores for scanning and set up deep winkle mode
  // SCOM regs:
  // 1) GP3 Register (NA in PERV CPLT) 
  //
  // Murano (6 regs)
  // 00000000140F0014 (PCB2)
  // 00000000150F0014 (PCB2)
  // 00000000160F0014 (PCB2)
  // 000000001C0F0014 (PCB2)
  // 000000001D0F0014 (PCB2)
  // 000000001E0F0014 (PCB2)
  //
  //
  // Venice (12 regs)
  // 00000000110F0014 (PCB2)
  // 00000000120F0014 (PCB2)
  // 00000000130F0014 (PCB2)
  // 00000000140F0014 (PCB2)
  // 00000000150F0014 (PCB2)
  // 00000000160F0014 (PCB2)
  // 00000000190F0014 (PCB2)
  // 000000001A0F0014 (PCB2)
  // 000000001B0F0014 (PCB2)
  // 000000001C0F0014 (PCB2)
  // 000000001D0F0014 (PCB2)
  // 000000001E0F0014 (PCB2)
  //
  // bit 27 (TP_LVLTRANS_FENCE): Electrical winkel fence. Mainly used by power management.
  //
  // 2) PowerManagement GP0 reg
  //
  // Murano (6 regs)
  // 00000000140F0102(PCB2)
  // 00000000150F0102(PCB2)
  // 00000000160F0102(PCB2)
  // 000000001C0F0102(PCB2)
  // 000000001D0F0102(PCB2)
  // 000000001E0F0102(PCB2)
  //
  // Venice (12 regs)
  // 00000000110F0102(PCB2)
  // 00000000120F0102(PCB2)
  // 00000000130F0102(PCB2)
  // 00000000140F0102(PCB2)
  // 00000000150F0102(PCB2)
  // 00000000160F0102(PCB2)
  // 00000000190F0102(PCB2)
  // 000000001A0F0102(PCB2)
  // 000000001B0F0102(PCB2)
  // 000000001C0F0102(PCB2)
  // 000000001D0F0102(PCB2)
  // 000000001E0F0102(PCB2)
  //
  // bit 22 (TP_TC_PERVASIVE_ECO_FENCE): Pervasive ECO fence
  //
  // bit 39 (PM_SLV_WINKLE_FENCE): Fence off the powered off chiplet in winkle. - Logical fence/hold for pcb_slave and pcb_slave_pm. For electrical fence see bit 23.
  //
  // 3) PowerManagement GP1 
  // 
  // Murano (6 regs)
  // 0x00000000140F0105 (PCB2)
  // 0x00000000150F0105 (PCB2)
  // 0x00000000160F0105 (PCB2)
  // 0x000000001C0F0105 (PCB2)
  // 0x000000001D0F0105 (PCB2)
  // 0x000000001E0F0105 (PCB2)
  //
  // Venice (12 regs)
  // 0x00000000110F0105 (PCB2)
  // 0x00000000120F0105 (PCB2)
  // 0x00000000130F0105 (PCB2)
  // 0x00000000140F0105 (PCB2)
  // 0x00000000150F0105 (PCB2)
  // 0x00000000160F0105 (PCB2)
  // 0x00000000190F0105 (PCB2)
  // 0x000000001A0F0105 (PCB2)
  // 0x000000001B0F0105 (PCB2)
  // 0x000000001C0F0105 (PCB2)
  // 0x000000001D0F0105 (PCB2)
  // 0x000000001E0F0105 (PCB2)
  //
  // Bit 5: WINKLE_POWER_OFF_SEL: Winkle Power Off Select:
  // Selects which voltage level to place the Core and ECO domain PFETs upon Winkle entry. 0 = Vret (Fast Winkle Mode), 1 = Voff (Deep Winkle Mode). Depending on the setting of pmicr_latency_en, this bit is controlled with a PCB-write (0) or by the PMICR in the core (1).
  //
  // Bit 15: PMICR_LATENCY_EN: Selects how the sleep/winkle latency (which is deep/fast) is controlled. If asserted the PMICR controls the winkle/sleep_power_off_sel in PMGP1, otherwise those bits are controlled via SCOM by OCC.

  // parameters: 
  // 'i_target' is chip target
  //
  // returns:    
  // FAPI_RC_SUCCESS (success, EX chiplets entered fast winkle)
  //  
  // getscom/putscom/getattribute fapi errors
  // fapi error assigned from eCMD function failure
  //
  //------------------------------------------------------------------------------
  fapi::ReturnCode proc_mpipl_ex_cleanup(const fapi::Target & i_target) {
    const char *procedureName = "proc_mpipl_ex_cleanup";
    fapi::ReturnCode rc; //fapi return code
    uint32_t rc_ecmd;    //ecmd return code value
    const uint32_t data_size = 64; //Size of data buffer
    ecmdDataBufferBase fsi_data(data_size); //64-bit data buffer
    uint8_t attr_chip_unit_pos; //EX chiplet's unit offset within chip with respect to similar EX units
    const uint64_t EX_OFFSET_MULT = 0x01000000; //Multiplier used to calculate offset for respective EX chiplet
    uint64_t EX_GP3_REG_0x1X0F0014; //Addr of GP3 reg PCB2 for respective EX chiplet
    const uint64_t EX_GP3_REG_PCB2_ADDR = 0x00000000100F0014; //Addr of GP3 reg PCB2 (minus offset for EX chiplet)
    const uint32_t EX_GP3_REG_PCB2_BIT_POS27 = 27; //Bit 27 of GP3 reg PCB2
    uint64_t EX_PMGP0_REG_0x1X0F0102; //Addr of PM GP0 reg PCB2 for respective EX chiplet
    const uint64_t EX_PMGP0_REG_PCB2_ADDR = 0x00000000100F0102; //Addr of PM GP0 reg PCB2 (minus offset for EX chiplet)
    const uint32_t EX_PMGP0_REG_PCB2_BIT_POS22 = 22; //Bit 22 of PM GP0 reg PCB2
    const uint32_t EX_PMGP0_REG_PCB2_BIT_POS39 = 39; //Bit 39 of PM GP0 reg PCB2
    uint64_t EX_PMGP1_REG_0x1X0F0103; //Variable address, PM GP1 reg PCB for respective EX chiplet
    const uint64_t EX_PMGP1_REG_PCB_ADDR = 0x00000000100F0103; //PM GP1 reg PCB addr (minus offset for EX chiplet)
    uint64_t EX_PMGP1_REG_0x1X0F0104; //Variable address, PM GP1 reg PCB1 for respective EX chiplet
    const uint64_t EX_PMGP1_REG_PCB1_ADDR = 0x00000000100F0104; //PM GP1 reg PCB1 addr (minus offset for EX chiplet)
    uint64_t EX_PMGP1_REG_0x1X0F0105; //Variable address, PM GP1 reg PCB2 for respective EX chiplet
    const uint64_t EX_PMGP1_REG_PCB2_ADDR = 0x00000000100F0105; //PM GP1 reg PCB2 addr (minus offset for EX chiplet)
    const uint32_t EX_PMGP1_REG_PCB2_BIT_POS5 = 5; //Bit 5 (WINKLE_POWER_OFF_SEL) of PM GP1 reg PCB2
    const uint32_t EX_PMGP1_REG_PCB2_BIT_POS15 = 15; //Bit 15 (PMICR_LATENCY_EN) of PM GP1 reg PCB2

    fapi::TargetType l_chiplet_type = fapi::TARGET_TYPE_EX_CHIPLET; //Type of chiplet is EX chiplet
    fapi::TargetState l_chiplet_state = fapi::TARGET_STATE_FUNCTIONAL; //State of chiplet is functional
    std::vector<fapi::Target> v_ex_chiplets; //Vector of EX chiplets
    std::vector<fapi::Target>::iterator entry_pos; //Position of entry
    std::vector<fapi::Target>::iterator end_pos; //End of vector
    
    rc = fapiGetChildChiplets(i_target, l_chiplet_type, v_ex_chiplets, l_chiplet_state); //Get vector of EX chiplets
    entry_pos = v_ex_chiplets.begin(); //first element of vector
    end_pos = v_ex_chiplets.end(); //end of vector
    
    //Parse thru EX chiplets and prepare fast-winkled cores for scanning
    while(entry_pos != end_pos ) {
      // Get EX chiplet number
      rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*entry_pos), attr_chip_unit_pos); 
      if (rc) { 
        FAPI_ERR("%s: fapiGetAttribute error (ATTR_CHIP_UNIT_POS)", procedureName);  
        return rc;
      }
      FAPI_DBG("EX chiplet pos = 0x%02X", attr_chip_unit_pos);
      
      EX_GP3_REG_0x1X0F0014 = EX_GP3_REG_PCB2_ADDR + (EX_OFFSET_MULT * attr_chip_unit_pos); //Addr of GP3 reg (PCB2) for respective EX chiplet
      FAPI_DBG("GP3 reg (PCB2), addr=0x%08llX", EX_GP3_REG_0x1X0F0014);
      
      EX_PMGP0_REG_0x1X0F0102 = EX_PMGP0_REG_PCB2_ADDR + (EX_OFFSET_MULT * attr_chip_unit_pos); //Addr of PM GP0 reg (PCB2) for respective EX chiplet
      FAPI_DBG("PM GP0 reg (PCB2), addr=0x%08llX", EX_PMGP0_REG_0x1X0F0102 );
      
      EX_PMGP1_REG_0x1X0F0103 = EX_PMGP1_REG_PCB_ADDR + (EX_OFFSET_MULT * attr_chip_unit_pos); //Addr of PM GP1 reg (PCB) for respective EX chiplet
      FAPI_DBG("PM GP1 reg (PCB), addr=0x%08llX", EX_PMGP1_REG_0x1X0F0103);
      
      EX_PMGP1_REG_0x1X0F0104 = EX_PMGP1_REG_PCB1_ADDR + (EX_OFFSET_MULT * attr_chip_unit_pos); //Addr of PM GP1 reg (PCB1) for respective EX chiplet
      FAPI_DBG("PM GP1 reg (PCB1), addr=0x%08llX", EX_PMGP1_REG_0x1X0F0104);
      
      EX_PMGP1_REG_0x1X0F0105 = EX_PMGP1_REG_PCB2_ADDR + (EX_OFFSET_MULT * attr_chip_unit_pos); //Addr of PM GP1 reg (PCB2) for respective EX chiplet
      FAPI_DBG("PM GP1 reg (PCB2), addr=0x%08llX", EX_PMGP1_REG_0x1X0F0105);
      

      //Undo step that prepared fast-winkled cores for scanning
      //
      //1) Drop PB Electrical Fence (EX_GP3_OR_0x100F0014(27)=1)
      rc_ecmd = fsi_data.flushTo0();
      if(rc_ecmd) {
        FAPI_ERR("%s: Error (%u): Could not flush ecmdDataBufferBase to 0's", procedureName, rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
      }

      FAPI_DBG("Asserting bit 27 of ecmdDataBufferBase that stores value of GP3 reg (addr: 0x%08llX)", EX_GP3_REG_0x1X0F0014);
      rc_ecmd = fsi_data.setBit(EX_GP3_REG_PCB2_BIT_POS27);
      if(rc_ecmd) {
        FAPI_ERR("%s: Error (%u): Could not assert bit 27 of ecmdDataBufferBase that stores value of GP3 reg (addr: 0x%08llX)", procedureName, rc_ecmd, EX_GP3_REG_0x1X0F0014);
        rc.setEcmdError(rc_ecmd);
        return rc;
      }
      
      FAPI_DBG("ecmdDataBufferBase storing value of GP3 reg (addr: 0x%08llX), val=0x%016llX", EX_GP3_REG_0x1X0F0014, fsi_data.getDoubleWord((uint32_t) 0));
      rc = fapiPutScom( i_target, EX_GP3_REG_0x1X0F0014, fsi_data );
      if (rc) {
        FAPI_ERR("%s: fapiPutScom error (addr: 0x%08llX)", procedureName, EX_GP3_REG_0x1X0F0014);
        return rc;
      }
      
      //2) Drop logical Pervasive/PCBS-PM fence (EX_PMGP0_OR_0x100F0102(39)=1)  
      rc_ecmd = fsi_data.flushTo0();
      if(rc_ecmd) {
        FAPI_ERR("%s: Error (%u): Could not flush ecmdDataBufferBase to 0's", procedureName, rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
      }

      FAPI_DBG("Asserting bit 39 of ecmdDataBufferBase that stores value of PM GP0 reg (addr: 0x%08llX)", EX_PMGP0_REG_0x1X0F0102 );
      rc_ecmd = fsi_data.setBit(EX_PMGP0_REG_PCB2_BIT_POS39);
      if(rc_ecmd) {
        FAPI_ERR("%s: Error (%u): Could not assert bit 39 of ecmdDataBufferBase that stores value of PM GP0 reg (addr: 0x%08llX)", procedureName, rc_ecmd, EX_PMGP0_REG_0x1X0F0102);
        rc.setEcmdError(rc_ecmd);
        return rc;
      }
      
      FAPI_DBG("ecmdDataBufferBase storing value of PM GP0 reg (addr: 0x%08llX), val=0x%016llX", EX_PMGP0_REG_0x1X0F0102, fsi_data.getDoubleWord((uint32_t) 0));
      rc = fapiPutScom( i_target, EX_PMGP0_REG_0x1X0F0102, fsi_data );
      if (rc) {
        FAPI_ERR("%s: fapiPutScom error (addr: 0x%08llX)", procedureName, EX_PMGP0_REG_0x1X0F0102);
        return rc;
      }
      
      //3) Drop Pervasive Extended Cache Option (ECO) fence (EX_PMGP0_OR_0x100F0102(22)=1)
      rc_ecmd = fsi_data.flushTo0();
      if(rc_ecmd) {
        FAPI_ERR("%s: Error (%u): Could not flush ecmdDataBufferBase to 0's", procedureName, rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
      }
      
      FAPI_DBG("Asserting bit 22 of ecmdDataBufferBase that stores value of PM GP0 reg (addr: 0x%08llX)", EX_PMGP0_REG_0x1X0F0102 );
      rc_ecmd = fsi_data.setBit(EX_PMGP0_REG_PCB2_BIT_POS22);
      if(rc_ecmd) {
        FAPI_ERR("%s: Error (%u): Could not assert bit 22 of ecmdDataBufferBase that stores value of PM GP0 reg (addr: 0x%08llX)", procedureName, rc_ecmd, EX_PMGP0_REG_0x1X0F0102);
        rc.setEcmdError(rc_ecmd);
        return rc;
      }
      
      FAPI_DBG("ecmdDataBufferBase storing value of PM GP0 reg (addr: 0x%08llX), val=0x%016llX", EX_PMGP0_REG_0x1X0F0102, fsi_data.getDoubleWord((uint32_t) 0));
      rc = fapiPutScom( i_target, EX_PMGP0_REG_0x1X0F0102, fsi_data );
      if (rc) {
        FAPI_ERR("%s: fapiPutScom error (addr: 0x%08llX)", procedureName, EX_PMGP0_REG_0x1X0F0102);
        return rc;
      }
      


      // Check bit 15 (PMICR_LATENCY_EN) of PM GP1 reg is 0, so bit 5 (WINKLE_POWER_OFF_SEL) of PM GP1 reg is controlled via SCOM write
      //
      FAPI_DBG("Checking bit 15 (PMICR_LATENCY_EN) of PM GP1 reg (addr: 0x%08llX) is 0", EX_PMGP1_REG_0x1X0F0103);
      rc = fapiGetScom(i_target, EX_PMGP1_REG_0x1X0F0103, fsi_data);
      if (rc) {
        FAPI_ERR("%s: fapiGetScom error (addr: 0x%08llX)", procedureName, EX_PMGP1_REG_0x1X0F0103);
        return rc;
      }
      FAPI_DBG("PM GP1 reg (addr: 0x%08llX), val=0x%016llX", EX_PMGP1_REG_0x1X0F0103, fsi_data.getDoubleWord((uint32_t) 0));
      
      //Check whether bit 15 (PMICR_LATENCY_EN) of PowerManagement GP1 reg is 1
      if( fsi_data.getBit(EX_PMGP1_REG_PCB2_BIT_POS15) ) {
        FAPI_DBG("Bit pos %u (PMICR_LATENCY_EN) of PM GP1 reg (addr: 0x%08llX) is 1", EX_PMGP1_REG_PCB2_BIT_POS15, EX_PMGP1_REG_0x1X0F0103);
        FAPI_DBG("Clearing bit pos %u (PMICR_LATENCY_EN) of PM GP1 reg (addr: 0x%08llX)", EX_PMGP1_REG_PCB2_BIT_POS15, EX_PMGP1_REG_0x1X0F0103);
      
        //Clear bit 15 (PMICR_LATENCY_EN) of PM GP1 reg
        rc_ecmd = fsi_data.flushTo1();
        if(rc_ecmd) {
          FAPI_ERR("%s: Error (%u): Could not flush ecmdDataBufferBase to 1's", procedureName, rc_ecmd);
          rc.setEcmdError(rc_ecmd);
          return rc;
        }
        rc_ecmd = fsi_data.clearBit(EX_PMGP1_REG_PCB2_BIT_POS15);
        if(rc_ecmd) {
	  FAPI_ERR("%s: Could not clear bit pos %u of PM GP1 reg (addr: 0x%08llX)", procedureName, EX_PMGP1_REG_PCB2_BIT_POS15, EX_PMGP1_REG_0x1X0F0104);
          rc.setEcmdError(rc_ecmd);
          return rc;
        }

        //Write data to PM GP1 reg
        rc = fapiPutScom(i_target, EX_PMGP1_REG_0x1X0F0104, fsi_data);
        if (rc) {
          FAPI_ERR("%s: fapiPutScom error (addr: 0x%08llX)", procedureName, EX_PMGP1_REG_0x1X0F0104);
          return rc;
        }
      }
      
      // Assert bit 5 (WINKLE_POWER_OFF_SEL) of PM GP1 reg 
      rc_ecmd = fsi_data.flushTo0();
      if(rc_ecmd) {
        FAPI_ERR("%s: Error (%u): Could not flush ecmdDataBufferBase to 0's", procedureName, rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
      }
      rc_ecmd = fsi_data.setBit(EX_PMGP1_REG_PCB2_BIT_POS5);
      if(rc_ecmd) {
        FAPI_ERR("%s: Could not assert bit pos %u of PM GP1 reg (addr: 0x%08llX)", procedureName, EX_PMGP1_REG_PCB2_BIT_POS5, EX_PMGP1_REG_0x1X0F0105);
        rc.setEcmdError(rc_ecmd);
        return rc;
      }
      rc = fapiPutScom(i_target, EX_PMGP1_REG_0x1X0F0105, fsi_data);
      if (rc) {
        FAPI_ERR("%s: fapiPutScom error (addr: 0x%08llX)", procedureName, EX_PMGP1_REG_0x1X0F0105);
        return rc;
      }
    
      entry_pos++; //Point to next EX chiplet
    }

    //Exiting fapi function
    FAPI_DBG("Exiting fapi function: %s", procedureName);
    
    return rc;
  }
  
  
    
} // extern "C"
