/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/host_mpipl_service/proc_mpipl_ex_cleanup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: proc_mpipl_ex_cleanup.C,v 1.6 2013/08/20 17:31:41 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_mpipl_ex_cleanup.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
#include "p8_scom_addresses.H"

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
  // bit 27 (TP_LVLTRANS_FENCE): Electrical winkel fence. Mainly used by power management.
  //
  // 2) PowerManagement GP0 reg
  //
  // bit 22 (TP_TC_PERVASIVE_ECO_FENCE): Pervasive ECO fence
  //
  // bit 39 (PM_SLV_WINKLE_FENCE): Fence off the powered off chiplet in winkle. - Logical fence/hold for pcb_slave and pcb_slave_pm. For electrical fence see bit 23.
  //
  // 3) PowerManagement GP1
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
    const char          *procedureName = "proc_mpipl_ex_cleanup";
    fapi::ReturnCode    rc; //fapi return code
    uint32_t            rc_ecmd = 0;    //ecmd return code value
    ecmdDataBufferBase  fsi_data(64); //64-bit data buffer
    uint8_t             attr_chip_unit_pos; //EX chiplet's unit offset within chip with respect to similar EX units
    const uint64_t      EX_OFFSET_MULT = 0x01000000; //Multiplier used to calculate offset for respective EX chiplet

    uint64_t            address;   // Varible for computed addresses
    uint64_t            offset;
    char                reg_name[32];  // Character array for register names


    // Relevant PMGP0 bits
//    const uint32_t      PM_DISABLE = 0;
    const uint32_t      BLOCK_REG_WKUP_SOURCE = 53;


    // Relevant PMGP1 bits  
    const uint32_t      WINKLE_POWER_OFF_SEL = 5;

    std::vector<fapi::Target> v_ex_chiplets; //Vector of EX chiplets


    do
    {
        //Entering fapi function
        FAPI_INF("Entering %s", procedureName);

        //Get vector of EX chiplets
        rc = fapiGetChildChiplets(  i_target, 
                                    fapi::TARGET_TYPE_EX_CHIPLET, 
                                    v_ex_chiplets, 
                                    fapi::TARGET_STATE_FUNCTIONAL); 
        if (rc) 
        {
             FAPI_ERR("%s: fapiGetChildChiplets error", procedureName);
             break;
        }

        FAPI_INF("Processing target %s", i_target.toEcmdString());
        
        //Parse thru EX chiplets and prepare fast-winkled cores for deep operations
        //Loop thru EX chiplets in vector
        for (uint32_t counter = 0; counter < v_ex_chiplets.size(); counter++)
        {

            // Get EX chiplet number
            rc = FAPI_ATTR_GET( ATTR_CHIP_UNIT_POS,
                                &(v_ex_chiplets[counter]),
                                attr_chip_unit_pos);
            if (rc)
            {
                FAPI_ERR("%s: fapiGetAttribute error (ATTR_CHIP_UNIT_POS)", procedureName);
                break;
            }
            FAPI_INF("EX chiplet pos = 0x%02X", attr_chip_unit_pos);


            // Calculate the address offset based on chiplet number
            offset = EX_OFFSET_MULT * attr_chip_unit_pos;
                        
            // -----------------------------------------------------------------
            FAPI_DBG("\tOriginal register contents");
            address = EX_GP3_0x100F0012 + offset;
            strcpy(reg_name, "GP3");
            rc = fapiGetScom( i_target, address, fsi_data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                break;
            }
            FAPI_DBG("\t%s (addr: 0x%08llX), val=0x%016llX", reg_name, address, fsi_data.getDoubleWord(0));
            
            address = EX_PMGP0_0x100F0100 + offset;
            strcpy(reg_name, "PMGP0");
            rc = fapiGetScom( i_target, address, fsi_data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                break;
            }
            FAPI_DBG("\t%s (addr: 0x%08llX), val=0x%016llX", reg_name, address, fsi_data.getDoubleWord(0));

            address = EX_PMGP1_0x100F0103 + offset;
            strcpy(reg_name, "PMGP1");
            rc = fapiGetScom( i_target, address, fsi_data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                break;
            }
            FAPI_DBG("\t%s (addr: 0x%08llX), val=0x%016llX", reg_name, address, fsi_data.getDoubleWord(0));
            // -----------------------------------------------------------------

            // Clean up configuration remnants of the fast-winkle configuration
            // that  was used to flush the chiplets after checkstop.  EX chiplets
            // will have been through SBE EX Init with certain step skippled due 
            // to MPIPL.
            
            FAPI_INF("Re-establish Deep Winkle mode default");
            address = EX_PMGP1_OR_0x100F0105 + offset;
            strcpy(reg_name, "PMGP1 OR");

            rc_ecmd |= fsi_data.flushTo0();
            rc_ecmd |= fsi_data.setBit(WINKLE_POWER_OFF_SEL);
            if(rc_ecmd)
            {
                FAPI_ERR("ecmdDatatBuffer error preparing %s reg (addr: 0x%08llX) with rc %x", reg_name, address, rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, address, fsi_data);
            if (rc)
            {
                FAPI_ERR("fapiPutScom error (addr: 0x%08llX)", address);
                break;
            }

            FAPI_INF("Clear block wakeup sources to PM logic.  PM is NOT re-enabled");
            // (eg clear Block Interrrupt Sources)
            address = EX_PMGP0_AND_0x100F0101 + offset;
            strcpy(reg_name, "PMGP0 AND");

            rc_ecmd |= fsi_data.flushTo1();
//            rc_ecmd |= fsi_data.clearBit(PM_DISABLE);
            rc_ecmd |= fsi_data.clearBit(BLOCK_REG_WKUP_SOURCE);
            if(rc_ecmd)
            {
                FAPI_ERR("ecmdDatatBuffer error preparing %s reg (addr: 0x%08llX)", reg_name, address);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, address, fsi_data);
            if (rc)
            {
                 FAPI_ERR("fapiPutScom error (addr: 0x%08llX)", address);
                break;
            }
            
            // -----------------------------------------------------------------
            FAPI_DBG("\tUpdated register contents");
            address = EX_GP3_0x100F0012 + offset;
            strcpy(reg_name, "GP3");
            rc = fapiGetScom( i_target, address, fsi_data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                break;
            }
            FAPI_DBG("\t%s (addr: 0x%08llX), val=0x%016llX", reg_name, address, fsi_data.getDoubleWord(0));
            
            address = EX_PMGP0_0x100F0100 + offset;
            strcpy(reg_name, "PMGP0");
            rc = fapiGetScom( i_target, address, fsi_data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                break;
            }
            FAPI_DBG("\t%s (addr: 0x%08llX), val=0x%016llX", reg_name, address, fsi_data.getDoubleWord(0));

            address = EX_PMGP1_0x100F0103 + offset;
            strcpy(reg_name, "PMGP1");
            rc = fapiGetScom( i_target, address, fsi_data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                break;
            }
            FAPI_DBG("\t%s (addr: 0x%08llX), val=0x%016llX", reg_name, address, fsi_data.getDoubleWord(0));
            // -----------------------------------------------------------------
        } // chiplet loop

        // Error exit from above loop
        // Not really needed as outer while(0) is next but here for consistent structure
        if (!rc.ok())
        {
            break;
        }
    } while (0);

    //Exiting fapi function
    FAPI_INF("Exiting %s", procedureName);

    return rc;
  }

} // extern "C"
