/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_pcie_slot_power/proc_pcie_slot_power.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: proc_pcie_slot_power.C,v 1.3 2014/07/28 21:40:12 ricmata Exp $
//$Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pcie_slot_power.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
//------------------------------------------------------------------------------
// *! TITLE       : proc_pcie_slot_power.C
// *! DESCRIPTION : Disable/Enable slot power on hot-plug controlled slots.
// *!
// *! OWNER NAME  : Rick Mata         Email: ricmata@us.ibm.com
// *! BACKUP NAME : Rick Mata	      Email: ricmata@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Version     Date        Owner       Description
//------------------------------------------------------------------------------
//    1.0       7/22/14     ricmata     Initial release: Brazos support only.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include "proc_pcie_slot_power.H"


extern "C" 
{

  //---------------------------//
  // Function protoptypes      //
  //---------------------------//

  /**
  * @brief Issues i2c write command of 1-Byte length.
  *
  * @param[in] i_target		Reference to chip target.
  * @param[in] i_i2c_sel_dev	The i2c slave address to the hotplug controller.
  * @param[in] i_i2c_addr	The Register offset to load into the FIFO.
  * @param[in] i_i2c_data 	The Register data to load into the FIFO.
  *
  * @return ReturnCode
  *
  *
  */
  fapi::ReturnCode proc_perv_i2cms_write(const fapi::Target &i_target, const uint8_t i_i2c_sel_dev, const uint8_t i_i2c_addr, const uint8_t i_i2c_data);


  /**
  * @brief Issues i2c read command of 1-Byte length.
  *
  * @param[in] i_target		Reference to chip target.
  * @param[in] i_i2c_sel_dev	The i2c slave address to the hotplug controller.
  * @param[in] i_i2c_addr	The Register offset to load into the FIFO.
  * @param[in] 0_i2c_data 	The Register data to read from the FIFO.
  *
  * @return ReturnCode
  *
  *
  */
  fapi::ReturnCode proc_perv_i2cms_read(const fapi::Target &i_target, const uint8_t i_i2c_sel_dev, const uint8_t i_i2c_addr, uint8_t *o_i2c_data);


  /**
  * @brief Checks P8 I2C Master Status register for command complete and errors.
  *
  * @param[in] i_target		Reference to chip target
  *
  * @return ReturnCode
  *
  *
  */
  fapi::ReturnCode check_not_ready_bits(const fapi::Target &i_target);


  /**
  * @brief Checks P8 I2C Master Status register for the FIFO to be flushed.
  *
  * @param[in] i_target		Reference to chip target
  *
  * @return ReturnCode
  *
  *
  */
  fapi::ReturnCode check_fifo_entry_bits(const fapi::Target &i_target);


//------------------------------------------------------------------------------
//
// Function definitions
//------------------------------------------------------------------------------


  //------------------------------------------------------------------------------
  // name: proc_pcie_slot_power
  //------------------------------------------------------------------------------
  // purpose: 
  // Enables/Disables slot power to hot-plug controlled pcie slots.
  //      
  // parameters: 
  // 'i_target' is reference to chip target.
  // 'i_enable_slot_power' TRUE to enable slot power, else FALSE to disable slot power.
  //
  //
  // returns:
  // FAPI_RC_SUCCESS (success)
  //
  // getscom/putscom fapi errors
  // fapi error assigned from eCMD function failure
  //
  // RC_UNKNOWN_PCIE_SLOT_POWER_RC
  // ekb/eclipz/chips/p8/working/procedures/xml/error_info/proc_pcie_slot_power_errors.xml
  //------------------------------------------------------------------------------
  fapi::ReturnCode proc_pcie_slot_power(const fapi::Target &i_target, const bool i_enable_slot_power) {

    fapi::ReturnCode rc; //fapi return code value
    ecmdDataBufferBase fsi_data(64);
    //const uint8_t led9551_reg_pgood = 0x00; // Register to read pgood state on LED9551 Controller.
    const int MAX_PORTS = 2; // Max number of ports for LED9551 Controller.
    const uint8_t ary_led9551_reg_en[MAX_PORTS] = {0x05, 0x06}; // Port target on LED9551 register to enable and disable power.
    const uint8_t led9551_data_slot_off = 0x54;	//Data to disable power on LED9551 controller.
    const uint8_t led9551_data_slot_on = 0x55; 	//Data to enable power on LED9551 controller.
    const uint8_t led9551_dev_addr = 0xC4; 	//I2C address to target i2c device.
    //uint8_t pgood_data;	//Data contents to store the read for the PGOOD register access.
    //uint64_t nano_sec_delay = 250000000; //(250000000 ns = 250 ms) to wait
    //uint64_t sim_cyc_delay = 2500000; //2,500,000 simulation cycles to wait

    // mark function entry
    FAPI_INF("proc_pcie_slot_power: Start");

    fapi::ATTR_NAME_Type chip_type;
    rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME, &i_target, chip_type);
    if (rc)  {
      FAPI_ERR("fapiGetAttribute (Privildged) of ATTR_NAME failed");
      return rc;
    }

    if (chip_type == fapi::ENUM_ATTR_NAME_VENICE) { // This is a Venice-based system, Brazos.
      FAPI_INF("%s: ATTR_NAME retrieve is %x", i_target.toEcmdString(), chip_type);

      for (int counter = 0; counter < MAX_PORTS; counter++) {
        //DISABLE_SLOT_POWER
        if(!i_enable_slot_power) {
          rc = proc_perv_i2cms_write(i_target, led9551_dev_addr, ary_led9551_reg_en[counter], led9551_data_slot_off);
          if (rc) {
            FAPI_ERR("Error occurred while disabling slot power on I2C addr=%X, target=%s", led9551_dev_addr, i_target.toEcmdString());
            return rc;
          }
          FAPI_INF("Disabled slot power on I2C addr=%X, target=%s", led9551_dev_addr, i_target.toEcmdString());
        }
        
        //ENABLE_SLOT_POWER
        else { // (i_enable_slot_power)
          rc = proc_perv_i2cms_write(i_target, led9551_dev_addr, ary_led9551_reg_en[counter], led9551_data_slot_on);
          if (rc) {
            FAPI_ERR("Error occurred while enabling slot power on I2C addr=%X, target=%s", led9551_dev_addr, i_target.toEcmdString());
            return rc;
          }
          FAPI_INF("Enabled slot power on I2C addr=%X, target=%s", led9551_dev_addr, i_target.toEcmdString());
        }
      }


/*      //Removing this section as we decussed in a broader meeting that we don't need to check for PGOOD. We will let PHYP or Sapphire do the checking.
      //Wait before checking PGOOD state.
      rc = fapiDelay(nano_sec_delay, sim_cyc_delay);
      if (rc) {
        FAPI_ERR("%s: fapiDelay error");
        return rc;
      }
      
      //Read PGOOD State
      rc = proc_perv_i2cms_read(i_target, led9551_dev_addr, led9551_reg_pgood, &pgood_data);
      if (rc) {
        FAPI_ERR("Error occurred while reading pgood register on I2C addr=%X, target=%s", led9551_dev_addr, i_target.toEcmdString());
        return rc;
      }
      FAPI_INF("PGOOD register read on I2C addr=%X, value=%x, target=%s", led9551_dev_addr, pgood_data, i_target.toEcmdString());
*/
    }
    else {
      FAPI_INF("%s: This chip type is not supported. ATTR_NAME retrieve is %x", i_target.toEcmdString(), chip_type);
    }

    // mark function entry
    FAPI_INF("proc_pcie_slot_power: End");
    return rc;
  }



  //------------------------------------------------------------------------------
  // name: proc_perv_i2cms_write
  //------------------------------------------------------------------------------
  // purpose: 
  // Set up of P8 I2C Master engine for I2C write operations.
  //      
  // parameters: 
  // 'i_target' is reference to chip target
  // 'i_i2c_sel_dev' is reference to i2c device target
  // 'i_i2c_addr' is reference to the address entered into the FIFO
  // 'i_i2c_data' is reference to data for write operation
  //
  // returns:
  //
  // (Note: refer to file eclipz/chips/p8/working/procedures/xml/error_info/proc_pcie_slot_power_errors.xml)
  // 
  // getscom/putscom fapi errors
  // fapi error assigned from eCMD function failure
  // 
  //------------------------------------------------------------------------------
  fapi::ReturnCode proc_perv_i2cms_write(const fapi::Target &i_target, const uint8_t i_i2c_sel_dev, const uint8_t i_i2c_addr, const uint8_t i_i2c_data) {

    fapi::ReturnCode rc; //fapi return code value
    uint32_t rc_ecmd;    //ecmd return code value
    const uint32_t data_size = 64; //Size of data buffer
    ecmdDataBufferBase fsi_data(data_size);

    // mark function entry
    FAPI_INF("proc_perv_i2cms_write: Start");

    //1. Check I2C Status for I2C errors or complete bit not set
    FAPI_DBG("Checking I2C Status on target=%s (addr: 0x%08llX) for at least 1 error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
    rc = check_not_ready_bits(i_target);
    if(rc) {
      FAPI_ERR("Error occurred while checking target=%s P8 I2C regster (addr: 0x%08llX) for a error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
      return rc;
    }

    //2. Initialize I2C Mode register
    rc_ecmd = fsi_data.insertFromRight(I2C_MODE_DATA, 0, 32);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) setting first word on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    FAPI_DBG("Load I2C Mode register target=%s, value=0x%016llX", i_target.toEcmdString(), fsi_data.getDoubleWord(0));
    rc = fapiPutScom(i_target, I2CMS_MODE_0x000A0026, fsi_data);
    if (rc) {
      FAPI_ERR("fapiPutScom error (addr: 0x%08llX), target=%s", I2CMS_MODE_0x000A0026, i_target.toEcmdString());
      return rc;
    }

    //3. Initialize I2C Command register
    rc_ecmd = fsi_data.setWord(0, I2C_CMD_DATA_2B);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) setting first word on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    rc_ecmd = fsi_data.insertFromRight(i_i2c_sel_dev, 8, 8);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) inserting data on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    rc_ecmd = fsi_data.clearBit(15);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) setting bit on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    FAPI_DBG("Load I2C Command register target=%s, value=0x%016llX", i_target.toEcmdString(), fsi_data.getDoubleWord(0));
    rc = fapiPutScom(i_target, I2CMS_COMMAND_0x000A0025, fsi_data);
    if (rc) {
      FAPI_ERR("fapiPutScom error (addr: 0x%08llX), target=%s", I2CMS_COMMAND_0x000A0025, i_target.toEcmdString());
      return rc;
    }

    //4. Write address offset into the I2C FIFO
    rc_ecmd = fsi_data.insertFromRight(i_i2c_addr, 0, 8);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) inserting data on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    FAPI_DBG("Write the I2C FIFO with the address to slave device on target=%s, value=0x%016llX", i_target.toEcmdString(), fsi_data.getDoubleWord(0));
    rc = fapiPutScom(i_target, I2CMS_FIFO1_READ_0x000A0024, fsi_data );
    if (rc) {
      FAPI_ERR("fapiPutScom error (addr: 0x%08llX), target=%s", I2CMS_FIFO1_READ_0x000A0024, i_target.toEcmdString());
      return rc;
    }

    //5. Poll for the FIFO Entry count in the status to ensure all data was checked in.

    FAPI_DBG("Checking I2C Status on target=%s (addr: 0x%08llX) for at least 1 error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
    rc = check_fifo_entry_bits(i_target);
    if(rc) {
      FAPI_ERR("Error occurred while checking target=%s P8 I2C regster (addr: 0x%08llX) for a error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
      return rc;
    }

    //6. Write data into the I2C FIFO 
    rc_ecmd = fsi_data.insertFromRight(i_i2c_data, 0, 8);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) inserting data on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    FAPI_DBG("Write the I2C FIFO with data to slave device on target=%s, value=0x%016llX", i_target.toEcmdString(), fsi_data.getDoubleWord(0));
    rc = fapiPutScom(i_target, I2CMS_FIFO1_READ_0x000A0024, fsi_data);
    if (rc) {
      FAPI_ERR("fapiPutScom error (addr: 0x%08llX), target=%s", I2CMS_FIFO1_READ_0x000A0024, i_target.toEcmdString());
      return rc;
    }

     //TODO: Step 7. is not required for 1-byte length transfers. Instead, will go straight to check for complete bit and errors. Leaving it here for possible future enhancements.
    //7. Repeat 5. and 6. above until all data is transferred. 

    //8. Poll for complete bit to be set and check for errors.
    FAPI_DBG("Checking I2C Status on target=%s (addr: 0x%08llX) for at least 1 error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
    rc = check_not_ready_bits(i_target);
    if(rc) {
      FAPI_ERR("Error occurred while checking target=%s P8 I2C regster (addr: 0x%08llX) for a error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
      return rc;
    }

    // mark function entry
    FAPI_INF("proc_perv_i2cms_write: End");
    return rc;
  }


  //------------------------------------------------------------------------------
  // name: proc_perv_i2cms_read
  //------------------------------------------------------------------------------
  // purpose: 
  // Set up of P8 I2C Master engine for I2C write operations.
  //      
  // parameters: 
  // 'i_target' is reference to chip target
  // 'i_i2c_sel_dev' is reference to i2c device target
  // 'i_i2c_addr' is reference to the address entered into the FIFO
  // 'o_i2c_data' is reference to the data read from the FIFO
  //
  // returns:
  //
  // (Note: refer to file eclipz/chips/p8/working/procedures/xml/error_info/proc_pcie_slot_power_errors.xml)
  // 
  // getscom/putscom fapi errors
  // fapi error assigned from eCMD function failure
  // 
  //------------------------------------------------------------------------------
  fapi::ReturnCode proc_perv_i2cms_read(const fapi::Target &i_target, const uint8_t i_i2c_sel_dev, const uint8_t i_i2c_addr, uint8_t  *o_i2c_data) {

    fapi::ReturnCode rc; //fapi return code value
    uint32_t rc_ecmd;    //ecmd return code value
    const uint32_t data_size = 64; //Size of data buffer
    ecmdDataBufferBase fsi_data(data_size);

    // mark function entry
    FAPI_INF("proc_perv_i2cms_read: Start");

    //1. Check I2C Status for I2C errors or complete bit not set
    FAPI_DBG("Checking I2C Status on target=%s (addr: 0x%08llX) for at least 1 error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
    rc = check_not_ready_bits(i_target);
    if(rc) {
      FAPI_ERR("Error occurred while checking target=%s P8 I2C regster (addr: 0x%08llX) for a error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
      return rc;
    }

    //2. Initialize I2C Mode register
    rc_ecmd = fsi_data.insertFromRight(I2C_MODE_DATA, 0, 32);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) inserting data on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    FAPI_DBG("Load I2C Mode register target=%s, value=0x%016llX", i_target.toEcmdString(), fsi_data.getDoubleWord(0));
    rc = fapiPutScom(i_target, I2CMS_MODE_0x000A0026, fsi_data);
    if (rc) {
      FAPI_ERR("fapiPutScom error (addr: 0x%08llX), target=%s", I2CMS_MODE_0x000A0026, i_target.toEcmdString());
      return rc;
    }

    //3. Initialize I2C Command register
    rc_ecmd = fsi_data.setWord(0, I2C_CMD_DATA_1B);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) setting first word on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    rc_ecmd = fsi_data.insertFromRight(i_i2c_sel_dev, 8, 8);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) inserting data on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    rc_ecmd = fsi_data.clearBit(15);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) clearing bit on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    FAPI_DBG("Load I2C Command register target=%s, value=0x%016llX", i_target.toEcmdString(), fsi_data.getDoubleWord(0));
    rc = fapiPutScom(i_target, I2CMS_COMMAND_0x000A0025, fsi_data);
    if (rc) {
      FAPI_ERR("fapiPutScom error (addr: 0x%08llX), target=%s", I2CMS_COMMAND_0x000A0025, i_target.toEcmdString());
      return rc;
    }

    //4. Write address offset into the I2C FIFO
    rc_ecmd = fsi_data.insertFromRight(i_i2c_addr, 0, 8);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) inserting data on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    FAPI_DBG("Write the I2C FIFO with the address to slave device on target=%s, value=0x%016llX", i_target.toEcmdString(), fsi_data.getDoubleWord(0));
    rc = fapiPutScom(i_target, I2CMS_FIFO1_READ_0x000A0024, fsi_data );
    if (rc) {
      FAPI_ERR("fapiPutScom error (addr: 0x%08llX), target=%s", I2CMS_FIFO1_READ_0x000A0024, i_target.toEcmdString());
      return rc;
    }

    //5. Poll for complete bit to be set and check for errors.
    FAPI_DBG("Checking I2C Status on target=%s (addr: 0x%08llX) for at least 1 error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
    rc = check_not_ready_bits(i_target);
    if(rc) {
      FAPI_ERR("Error occurred while checking target=%s P8 I2C regster (addr: 0x%08llX) for a error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
      return rc;
    }
    
    //6. Initialize I2C Command register
    rc_ecmd = fsi_data.setWord(0, I2C_CMD_DATA_1B);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) setting first word on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    rc_ecmd = fsi_data.insertFromRight(i_i2c_sel_dev, 8, 8);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) inserting data on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    rc_ecmd = fsi_data.setBit(15);
    if(rc_ecmd) {
      FAPI_ERR("Error (%u) setting bit on %s", rc_ecmd, i_target.toEcmdString());
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    FAPI_DBG("Load I2C Command register target=%s, value=0x%016llX", i_target.toEcmdString(), fsi_data.getDoubleWord(0));
    rc = fapiPutScom(i_target, I2CMS_COMMAND_0x000A0025, fsi_data);
    if (rc) {
      FAPI_ERR("fapiPutScom error (addr: 0x%08llX), target=%s", I2CMS_COMMAND_0x000A0025, i_target.toEcmdString());
      return rc;
    }

    //7. Read data from the I2C FIFO
    FAPI_DBG("Read I2C data from the FIFO");
    rc = fapiGetScom(i_target, I2CMS_FIFO1_READ_0x000A0024, fsi_data );
    if (rc) {
      FAPI_ERR("fapiGetScom error (addr: 0x%08llX), target=%s", I2CMS_FIFO1_READ_0x000A0024, i_target.toEcmdString());
      return rc;
    }
    FAPI_DBG("Read data from the I2C FIFO to slave device on target=%s, value=0x%X", i_target.toEcmdString(), fsi_data.getByte(0));
    *o_i2c_data = fsi_data.getByte(0);

    //8. Poll status register's FIFO_ENTRY_COUNT to know if entire FIFO has been read.
    FAPI_DBG("Checking I2C Status on target=%s (addr: 0x%08llX)", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
    rc = check_fifo_entry_bits(i_target);
    if(rc) {
      FAPI_ERR("Error occurred while checking target=%s P8 I2C regster (addr: 0x%08llX) for a error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
      return rc;
    }

    //TODO: Step 9. is not required for 1-byte length transfers. Instead, will go straight to check for complete bit and errors. Leaving it here for possible future enhancements.

    //9. Repeat 7. and 8. above until all data is read from the FIFO.
    
    //10. Poll for complete bit and check for any errors. 
    FAPI_DBG("Checking I2C Status on target=%s (addr: 0x%08llX)", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
    rc = check_not_ready_bits(i_target);
    if(rc) {
      FAPI_ERR("Error occurred while checking target=%s P8 I2C regster (addr: 0x%08llX) for a error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
      return rc;
    }

  // mark function entry
  FAPI_INF("proc_perv_i2cms_read: End");
  return rc;
  }

    
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  // name: check_not_ready_bits
  //------------------------------------------------------------------------------
  // purpose: 
  // Checks P8 I2C Status register for complete bit and errors.
  //      
  // Bits that indicate P8 I2C Master engine is not ready for operation.
  // bit 0	Invalid Command.
  // bit 1	Local Bus Parity Error.
  // bit 2	Back End Overrun Error.
  // bit 3	Back End Access Error.
  // bit 4	Arbitration Lost Error.
  // bit 5	NACK Recieved Error.
  // bit 6	Data Request.     
  // bit 8	Stop Error.
  //
  // parameters: 
  // 'i_target' is reference to chip target
  //
  // returns:
  //
  // (Note: refer to file eclipz/chips/p8/working/procedures/xml/error_info/proc_pcie_slot_power_errors.xml)
  // 
  // getscom/putscom fapi errors
  // fapi error assigned from eCMD function failure
  // 
  //------------------------------------------------------------------------------
  fapi::ReturnCode check_not_ready_bits(const fapi::Target &i_target) {

    fapi::ReturnCode rc;
    const uint32_t data_size = 64; //Size of data buffer
    ecmdDataBufferBase fsi_data(data_size);
    const int MAX_NUM_NOT_RDY_BITS = 8; //Maximum number of bits that indicate P8 I2C Master engine is not ready.
    const uint32_t ARY_NOT_RDY_BITS[MAX_NUM_NOT_RDY_BITS] = {0, 1, 2, 3, 4, 5, 6, 8}; //Array of bits that indicate P8 I2C Master engine is not ready.
    uint64_t nano_sec_delay = 1000000; //(1000000 ns = 1 ms ) to wait
    uint64_t sim_cyc_delay = 10000; //10,000 simulation cycles to wait
    int poll_counter; //Number of iterations while polling
    const int MAX_NUM_POLLS = 100; //Maximum number of iterations (So, 1ms * 100 = 100ms before timeout)

    // mark function entry
    FAPI_INF("check_not_ready_bits: Start");

    //1. Read I2C Status register and poll for complete bit to be set then check for errors.
    rc = fapiGetScom(i_target, I2CMS_STATUS_0x000A002B, fsi_data);
    if (rc) {
      FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", I2CMS_STATUS_0x000A002B);
      return rc;
    }
    poll_counter = 0;
    while (!fsi_data.isBitSet(7)) {
      poll_counter++;

      //Exceed max number of polls
      if(poll_counter > MAX_NUM_POLLS) {
        FAPI_ERR("Exceeded max number of polls (%d) for target=%s", MAX_NUM_POLLS, i_target.toEcmdString());
        const fapi::Target & CHIP_TARGET = i_target;
        const uint64_t & ADDRESS_VAL = I2CMS_STATUS_0x000A002B;
        ecmdDataBufferBase & DATA_REG = fsi_data;
        FAPI_SET_HWP_ERROR(rc, RC_I2C_COMPLETE_BIT_TIMEOUT_RC);
        return rc;
      }
      FAPI_DBG("target=%s, Poll Iter: %d", i_target.toEcmdString(), poll_counter);

      //Wait before checking again
      rc = fapiDelay(nano_sec_delay, sim_cyc_delay);
      if (rc) {
        FAPI_ERR("fapiDelay error");
        return rc;
      }

      //Get data from I2C Status register
      FAPI_DBG("Checking I2C Status on target=%s (addr: 0x%08llX) for at least 1 error bit", i_target.toEcmdString(), I2CMS_STATUS_0x000A002B);
      rc = fapiGetScom(i_target, I2CMS_STATUS_0x000A002B, fsi_data);
      if (rc) {
        FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", I2CMS_STATUS_0x000A002B);
        return rc;
      }
    }

    //2. Check P8 I2C Master engine is ready for new operation.
    for(int counter = 0; counter < MAX_NUM_NOT_RDY_BITS; counter++) {
      if( fsi_data.isBitSet(ARY_NOT_RDY_BITS[counter] )) {
        FAPI_ERR("Error in bit pos %u of I2CMS_STATUS_0x000A002B, (addr: 0x%08llX) ",ARY_NOT_RDY_BITS[counter], I2CMS_STATUS_0x000A002B);
        const fapi::Target & CHIP_TARGET = i_target;
        const uint64_t & ADDRESS_VAL = I2CMS_STATUS_0x000A002B;
        ecmdDataBufferBase & DATA_REG = fsi_data;
        FAPI_SET_HWP_ERROR(rc, RC_I2C_ERROR_BIT_PRESENT_RC);
        return rc;
      }
    }

    // mark function exit
    FAPI_INF("check_not_ready_bits: End");
    return rc;
  }


  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  // name: check_fifo_entry_bits
  //------------------------------------------------------------------------------
  // purpose: 
  // Checks P8 I2C Status register for FIFO entry to read 00 indicating FIFO has been flushed..
  //      
  // Bits that indicate P8 I2C Master engine is not ready for operation.
  // bit[28:31] - FIFO Entry Count
  //
  // parameters: 
  // 'i_target' is reference to chip target
  //
  // returns:
  //
  // (Note: refer to file eclipz/chips/p8/working/procedures/xml/error_info/proc_pcie_slot_power_errors.xml)
  // 
  // getscom/putscom fapi errors
  // fapi error assigned from eCMD function failure
  // 
  //------------------------------------------------------------------------------
  fapi::ReturnCode check_fifo_entry_bits(const fapi::Target &i_target) {

    fapi::ReturnCode rc;
    const uint32_t data_size = 64; //Size of data buffer
    ecmdDataBufferBase fsi_data(data_size);
    uint64_t nano_sec_delay = 1000000; //(1000000 ns = 1 ms ) to wait
    uint64_t sim_cyc_delay = 10000; //10,000 simulation cycles to wait
    int poll_counter; //Number of iterations while polling
    const int MAX_NUM_POLLS = 100; //Maximum number of iterations (So, 1ms * 100 = 100ms before timeout)

    // mark function entry
    FAPI_INF("check_fifo_entry_bits: Start");

    //Read I2C Status register and poll for FIFO entry count to reach 00.
    rc = fapiGetScom(i_target, I2CMS_STATUS_0x000A002B, fsi_data);
    if (rc) {
      FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", I2CMS_STATUS_0x000A002B);
      return rc;
    }
    poll_counter = 0;
    while (!fsi_data.isBitClear(28, 4)) {
      poll_counter++;

      //Exceed max number of polls
      if(poll_counter > MAX_NUM_POLLS) {
        FAPI_ERR("Exceeded max number of polls (%d) for target=%s", MAX_NUM_POLLS, i_target.toEcmdString());
        const fapi::Target & CHIP_TARGET = i_target;
        const uint64_t & ADDRESS_VAL = I2CMS_STATUS_0x000A002B;
        ecmdDataBufferBase & DATA_REG = fsi_data;
        FAPI_SET_HWP_ERROR(rc, RC_I2C_FIFO_INCOMPLETE_RC);
        return rc;
      }
      FAPI_DBG("target=%s, Poll Iter: %d", i_target.toEcmdString(), poll_counter);


      //Wait before checking again
      rc = fapiDelay(nano_sec_delay, sim_cyc_delay);
      if (rc) {
        FAPI_ERR("fapiDelay error");
        return rc;
      }

      //Get data from I2C Status register
      rc = fapiGetScom(i_target, I2CMS_STATUS_0x000A002B, fsi_data);
      if (rc) {
        FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", I2CMS_STATUS_0x000A002B);
        return rc;
      }
    }

    // mark function exit
    FAPI_INF("check_fifio_entry_bits: End");
    return rc;
  }

} // extern "C"
