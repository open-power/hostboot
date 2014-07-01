/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/host_mpipl_service/proc_mpipl_chip_cleanup.C $ */
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
// $Id: proc_mpipl_chip_cleanup.C,v 1.8 2014/03/02 23:14:49 belldi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_mpipl_chip_cleanup.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_mpipl_chip_cleanup.C
// *! DESCRIPTION : To enable MCD recovery
// *!
// *! OWNER  NAME : Dion Bell                Email: belldi@us.ibm.com
// *! BACKUP NAME : Dion Bell                Email: belldi@us.ibm.com
// *!
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
#include "proc_mpipl_chip_cleanup.H"

//------------------------------------------------------------------------------
//  eCMD Includes
//------------------------------------------------------------------------------


extern "C"
{
  //------------------------------------------------------------------------------
  // Function definitions
  //------------------------------------------------------------------------------

  //------------------------------------------------------------------------------
  // name: proc_mpipl_chip_cleanup
  //------------------------------------------------------------------------------
  // purpose: 
  // To enable MCD recovery
  //
  // Note: PHBs are left in ETU reset state after executing proc_mpipl_nest_cleanup, which runs before this procedure.  PHYP releases PHBs from ETU reset post HostBoot IPL.
  //
  // SCOM regs
  //
  // 1) MCD even recovery control register
  // 0000000002013410 (SCOM)
  // bit 0 (MCD_REC_EVEN_ENABLE): 0 to 1 transition needed to start, reset to 0 at end of request.
  // bit 5 (MCD_REC_EVEN_REQ_PEND)
  //
  //
  // 2) MCD odd recovery control register
  // 0000000002013411 (SCOM)
  // bit 0 (MCD_REC_ODD_ENABLE): 0 to 1 transition needed to start, reset to 0 at end of request.
  // bit 5 (MCD_REC_ODD_REQ_PEND)
  //
  // 3) Clear PCI Nest FIR registers
  // 02012000 (SCOM) 
  // 02012400 (SCOM) 
  // 02012800 (SCOM) 
  //
  // parameters: 
  // 'i_target' is reference to chip target
  //
  // returns:
  // FAPI_RC_SUCCESS (success, MCD recovery enabled for odd and even slices)
  //
  // RC_MCD_RECOVERY_NOT_DISABLED_RC (MCD recovery for even or odd slice is not disabled; therefore can't re-enable MCD recovery)
  // (Note: refer to file eclipz/chips/p8/working/procedures/xml/error_info/proc_mpipl_chip_cleanup_errors.xml)
  // 
  // getscom/putscom fapi errors
  // fapi error assigned from eCMD function failure
  // 
  //------------------------------------------------------------------------------
  fapi::ReturnCode proc_mpipl_chip_cleanup(const fapi::Target &i_target){
    const char *procedureName = "proc_mpipl_chip_cleanup"; //Name of this procedure
    fapi::ReturnCode rc; //fapi return code value
    uint32_t rc_ecmd = 0;    //ecmd return code value
    const uint32_t data_size = 64; //Size of data buffer
    const int MAX_MCD_DIRS = 2; //Max of 2 MCD Directories (even and odd)
    ecmdDataBufferBase fsi_data[MAX_MCD_DIRS];
    const uint64_t ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[MAX_MCD_DIRS] = {
      0x0000000002013410, //MCD even recovery control register address
      0x0000000002013411  //MCD odd recovery control register address
    };     
    const uint32_t MCD_RECOVERY_CTRL_REG_BIT_POS0 = 0; //Bit 0 of MCD even and odd recovery control regs
    const char *ARY_MCD_DIR_STRS[MAX_MCD_DIRS] = {
      "Even", //Ptr to char string "Even" for even MCD
      "Odd"   //Ptr to char string "Odd" for odd MCD
    }; 
    const int MAX_PHBS = 3;
    const uint64_t PCI_NEST_FIR_REG_ADDRS[MAX_PHBS] = {
      0x02012000,
      0x02012400,
      0x02012800
    };     
    
    do {
      //Set bit length for 64-bit buffers
      rc_ecmd = fsi_data[0].setBitLength(data_size);
      rc_ecmd |= fsi_data[1].setBitLength(data_size);
      if(rc_ecmd) {
        rc.setEcmdError(rc_ecmd);
        break;
      }
  
      //Verify MCD recovery was previously disabled for even and odd slices
      //If not, this is an error condition
      for (int counter = 0; counter < MAX_MCD_DIRS; counter++) {
        FAPI_DBG("Verifying MCD %s Recovery is disabled, target=%s", ARY_MCD_DIR_STRS[counter], i_target.toEcmdString());
        
        //Get data from MCD Even or Odd Recovery Ctrl reg
        rc = fapiGetScom(i_target, ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[counter], fsi_data[counter]);
        if (!rc.ok()) {
          FAPI_ERR("%s: fapiGetScom error (addr: 0x%08llX), target=%s", procedureName, ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[counter], i_target.toEcmdString());
          break;
        }
        
  
        //Check whether bit 0 is 0, meaning MCD recovery is disabled as expected
        if( fsi_data[counter].getBit(MCD_RECOVERY_CTRL_REG_BIT_POS0) ) {
          FAPI_ERR("%s: MCD %s Recovery not disabled as expected, target=%s", procedureName, ARY_MCD_DIR_STRS[counter], i_target.toEcmdString());
          const fapi::Target & CHIP_TARGET = i_target;
  	  const uint64_t & MCD_RECOV_CTRL_REG_ADDR = ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[counter];
          ecmdDataBufferBase & MCD_RECOV_CTRL_REG_DATA = fsi_data[counter];
          FAPI_SET_HWP_ERROR(rc, RC_MPIPL_MCD_RECOVERY_NOT_DISABLED_RC);
          break;
        }
      }
      if(!rc.ok()) {
        break;
      }
  
      //Assert bit 0 of MCD Recovery Ctrl regs to enable MCD recovery
      for (int counter = 0; counter < MAX_MCD_DIRS; counter++) {
        FAPI_DBG("Enabling MCD %s Recovery, target=%s", ARY_MCD_DIR_STRS[counter], i_target.toEcmdString());
        
        //Assert bit 0 of MCD Even or Odd Recovery Control reg to enable recovery
        rc_ecmd = fsi_data[counter].setBit(MCD_RECOVERY_CTRL_REG_BIT_POS0 );
        if(rc_ecmd) {
          FAPI_ERR("%s: Error (%u) asserting bit pos %u in ecmdDataBufferBase that stores value of MCD %s Recovery Control reg (addr: 0x%08llX), target=%s", procedureName, rc_ecmd, MCD_RECOVERY_CTRL_REG_BIT_POS0, ARY_MCD_DIR_STRS[counter], ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[counter], i_target.toEcmdString());
          rc.setEcmdError(rc_ecmd);
          break;
        }
        
        //Write data to MCD Even or Odd Recovery Control reg
        rc = fapiPutScom(i_target, ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[counter], fsi_data[counter]);
        if (!rc.ok()) {
          FAPI_ERR("%s: fapiPutScom error (addr: 0x%08llX), target=%s", procedureName, ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[counter], i_target.toEcmdString());
          break;
        }
      }
      if(!rc.ok()) {
        break;
      }
  
      // SW227429: clear PCI Nest FIR registers
      // hostboot is blindly sending EOIs in order to ensure no interrupts are pending when  PHYP starts up again
      // with ETU held in reset, these get trapped in PCI and force a freeze to occur (PCI Nest FIR(14))
      // clearing the FIR should remove the freeze condition
      rc_ecmd = fsi_data[0].flushTo0();
      if (rc_ecmd) {
        FAPI_ERR("%s: Error (%u) forming PCI Nest FIR clear data buffer, target=%s", procedureName, rc_ecmd, i_target.toEcmdString());
        rc.setEcmdError(rc_ecmd);
        break;
      }
      
      for (int counter = 0; counter < MAX_PHBS; counter++) {
        FAPI_DBG("Clearing PCI%d Nest FIR, target=%s", counter, i_target.toEcmdString());
        rc = fapiPutScom(i_target, PCI_NEST_FIR_REG_ADDRS[counter], fsi_data[0]);
        if (!rc.ok()) {
          FAPI_ERR("%s: fapiPutScom error (addr: 0x%08llX), target=%s", procedureName, PCI_NEST_FIR_REG_ADDRS[counter], i_target.toEcmdString());
          break;
        }
      }
    } while(0);

    FAPI_IMP("Exiting %s", procedureName);

    return rc;
  }



} // extern "C"
