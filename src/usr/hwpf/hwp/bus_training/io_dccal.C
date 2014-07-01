/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_dccal.C $                    */
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
// $Id: io_dccal.C,v 1.35 2014/03/20 08:37:35 varkeykv Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME             : io_dccal.C
// *! TITLE                : 
// *! DESCRIPTION          : Impedance & offset calibration
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Varghese, Varkey         Email: varkey.kv@in.ibm.com
// *! BACKUP NAME          : Swaminathan, Janani      Email: jaswamin@in.ibm.com      
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.31  |jaswamin|02/17/14| Fixed the order of scoms for the pll workaround
//   1.22  |jaswamin|09/19/13| Removed unused variables 
//   1.19  |thomsen |04/12/12| Added delay after starting zcal and offset cancellation to work around a GCR parity error bug (HW242564)
//   1.18  |jaswamin|01/26/12| Commented out offset cal for X and A bus
//   1.0   |varkeykv|09/27/11|Initial check in . Have to modify targets once bus target is defined and available.Not tested in any way other than in unit SIM IOTK
//   1.1   |varkeykv |17/11/11|Code cleanup . Fixed header files. Changed fAPI API
//------------------------------------------------------------------------------

#include <fapi.H>
#include "proc_a_x_pci_dmi_pll_utils.H"
#include "io_dccal.H"
#include "gcr_funcs.H"
#include <p8_scom_addresses.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------


extern "C" {


using namespace fapi;

int binStrToInt(char *str,uint32_t length) {
  int i = 0;
  for ( uint32_t j = 0; j <length; j++ ) {
    char c = str[j];
    if ( c == '0' ) {
      i = (i << 1);
    } else {
      i = (i << 1) | 0x1;
    }
  }
  return i;
}

uint32_t  BinaryRound(uint32_t val, uint32_t numTruncBits, uint32_t center) {
  // Round val by removing numTruncBits
  // If the truncated fraction is exactly 0.5, round
  // toward center
  uint32_t newVal = 0x0;

  uint32_t mask = 0x0;
  for (uint32_t i = 0; i < numTruncBits; i++) {
    mask = (mask << 1) + 0x1;
  }

  uint32_t half = 0x1 << (numTruncBits-1);

  if ( (val & mask) > half  ) {
    newVal = (val >> numTruncBits) + 1; // round up
  } else if ( (val & mask) < half  ) {
    newVal = (val >> numTruncBits); // round down
  } else {
    // On the boundary!  Round towards the nominal value
    if ( val < (center << numTruncBits) ) {
      newVal = (val >> numTruncBits) + 1; // round up
    } else {
      newVal = (val >> numTruncBits); // round down
    }
  }

  return newVal;
}

// Offset cal doesnt do anything in VBU/sim ...
ReturnCode run_offset_cal(const Target &target,io_interface_t master_interface,uint32_t master_group){
// Assuming I will receive a target and slave_target from the Invoker. 
    ReturnCode rc;
    uint32_t rc_ecmd=0;
    uint16_t bits = 0;
    ecmdDataBufferBase data_buffer;
	ecmdDataBufferBase rx_wt_timeout_sel_buf(16),rx_pdwn_lite_value_buf(16),rx_eo_latch_offset_done_buf(16),rx_wt_cu_pll_pgooddly_buf(16),rx_wt_cu_pll_pgooddly_buf_copy(16);
    ecmdDataBufferBase set_bits(16);
    ecmdDataBufferBase clear_bits(16);
       const fapi::Target &TARGET=target;
    //char printStr[200];
    FAPI_DBG("In the Dccal procedure");
    uint8_t ddlevel;
    
     rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_MCD_HANG_RECOVERY_BUG, &target,ddlevel);
     if(rc)
     {
      FAPI_ERR("IO_DCCAL :Error Reading DDLEVEL using MCD_HANG_RECOVERY attribute");
      return rc;
     }
     
     
     
     FAPI_DBG("DDLevel FLAG is read as %d",ddlevel);
     
    io_interface_t chip_interface=master_interface;//first we run on master chip
    uint32_t group=master_group;
    const Target *target_ptr=&target; // Assuming I am allowed to do this . 
		rc=GCR_read(*target_ptr,master_interface,rx_training_status_pg ,group,0,data_buffer);
		if (rc) 
		{
			// have to add support for field parsing
			FAPI_ERR("IO_DCCAL : GCR_read error for rx_training_status_pg");
			return rc;
		}
        FAPI_DBG("IO_DCCAL : Starting Offset Calibration on interface %d group %d",chip_interface,group);
        // read and save rx_pdwn_lite_disable
        //int read_bit=rx_pdwn_lite_disable;
        rc= GCR_read(*target_ptr,master_interface,rx_mode_pg ,group,0,rx_pdwn_lite_value_buf);if (rc) {return(rc);}
        //int rx_pdwn_lite_value=rx_wt_timeout_sel_buf.getHalfWord(0) & read_bit;
        	if (rc)
		{
			FAPI_ERR("IO_DCCAL : GCR_read error for rx_mode_pg");
			return rc;
		}
        // read and save rx_wt_timeout_sel
        //read_bit=rx_wt_timeout_sel_tap7; //find the 3 bit value of the field. need it to be all 1's to do an &
	// -- REVIEW , think this read is safe 
        rc= GCR_read(*target_ptr,master_interface,rx_timeout_sel_pg ,group,0,rx_wt_timeout_sel_buf);
			if (rc)
		{
			FAPI_ERR("IO_DCCAL : GCR_read error for rx_timeout_sel_pg");
			return rc;
		}
	
        //int rx_wt_timeout_value=rx_wt_timeout_sel_buf.getHalfWord(0) & read_bit;
        
		//read and save rx_wt_cu_pll_pgooddly
		//read_bit=rx_wt_cu_pll_pgooddly_disable; // selects 111 for the 3 bit field.need it to be all 1's to do an &
		rc= GCR_read(*target_ptr,master_interface,rx_wiretest_pll_cntl_pg,group,0,rx_wt_cu_pll_pgooddly_buf);
				if (rc)
		{
			FAPI_ERR("IO_DCCAL : GCR_read error for rx_wiretest_pll_cntl_pgrx_wiretest_pll_cntl_pg");
			return rc;
		}


		//int rx_wt_cu_pll_pgooddly_value=rx_wt_cu_pll_pgooddly_buf.getHalfWord(0) & read_bit;
		
		//read and save rx_wt_cu_pll_reset
		//read_bit=rx_wt_cu_pll_reset;
		//int rx_wt_cu_pll_reset_value=rx_wt_cu_pll_pgooddly_buf.getHalfWord(0) & read_bit;
		
		//read and save rx_wt_cu_pll_pgood
		//read_bit=rx_wt_cu_pll_pgood;
		//int rx_wt_cu_pll_pgood_value=rx_wt_cu_pll_pgooddly_buf.getHalfWord(0) & read_bit;
		
        // set power down lite disable, rx_pdwn_lite_disable
        bits=rx_pdwn_lite_disable;
		//bits=1;
		rc_ecmd|=set_bits.insert(rx_pdwn_lite_value_buf,0,16);
		//rc_ecmd|=set_bits.insert(bits,0,16);
        //rc_ecmd|=set_bits.insert(bits,2,1);
		//rc_ecmd|=set_bits.setOr(bits,0,16);
		rc_ecmd|=set_bits.setBit(2);
        bits=rx_pdwn_lite_disable_clear;
        //rc_ecmd|=clear_bits.insert(bits,0,16);
		rc_ecmd|=clear_bits.flushTo0();
        if(rc_ecmd)
        {
	  FAPI_ERR("IO_DCCAL : error power down lite disable");
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc=GCR_write(*target_ptr,chip_interface,rx_mode_pg,group,0,set_bits ,clear_bits);
	  if (rc)
	  {
		  FAPI_ERR("IO_DCCAL : GCR_write error for rx_mode_pg");
		  return rc;
	  }
		//write rx_wt_cu_pll_pgooddly to  '111'
		rc_ecmd|=set_bits.insert(rx_wt_cu_pll_pgooddly_buf,0,16);
		rc_ecmd|=set_bits.setBit(2);
		rc_ecmd|=set_bits.setBit(3);
		rc_ecmd|=set_bits.setBit(4);
		bits=rx_wt_cu_pll_pgooddly_clear;
		rc_ecmd|=clear_bits.flushTo0();
		if(rc_ecmd)
		{
			rc.setEcmdError(rc_ecmd);
            return(rc);
		}
		rc=GCR_write(*target_ptr,chip_interface,rx_wiretest_pll_cntl_pg,group,0,set_bits ,clear_bits);
				if (rc)
		{
			FAPI_ERR("IO_DCCAL : GCR_write error for rx_wiretest_pll_cntl_pg");
			return rc;
		}
        
		// write rx_wt_timeout_sel to '111'
		bits=rx_wt_timeout_sel_tap7;
		rc_ecmd|=set_bits.insert(rx_wt_timeout_sel_buf,0,16);
		//Update for DDLEVEL - as per Garys find 
		if(ddlevel==1){
		rc_ecmd|=  set_bits.setBit(9);
		rc_ecmd|=  set_bits.setBit(10);
		rc_ecmd|=  set_bits.setBit(11);
		}else{
		rc_ecmd|=    set_bits.setBit(10);
		rc_ecmd|=  set_bits.setBit(11);
		rc_ecmd|=  set_bits.setBit(12);
		}
        bits=rx_wt_timeout_sel_clear;
        //rc_ecmd|=clear_bits.insert(bits,0,16);
		rc_ecmd|=clear_bits.flushTo0();
        if(rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
	    FAPI_ERR("IO_DCCAL : error clearing bits for GCR_write rx_timeout_sel_pgrx_timeout_sel_pg");
            return(rc);
        }
	// -- REVIEW , here bits are not used , only set_bits which are now conditioanlized 
        rc=GCR_write(*target_ptr,chip_interface,rx_timeout_sel_pg,group,0,set_bits ,clear_bits);
	if (rc)
	{
	  FAPI_ERR("IO_DCCAL : GCR_write error for rx_timeout_sel_pg");
	  return rc;
	}
	    
       
		//writw rx_start_offset_cal to '1'
    	bits=rx_start_offset_cal;
        rc_ecmd|=set_bits.insert(bits,0,16);
        bits=rx_start_offset_cal_clear;
        rc_ecmd|=clear_bits.insert(bits,0,16); 
        if(rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
	    FAPI_ERR("IO_DCCAL : error setting up clear bits for GCR_write rx_training_start_pg");
            return(rc);
        }
        rc=GCR_write(*target_ptr,chip_interface,rx_training_start_pg,group,0,set_bits ,clear_bits);if (rc) {return(rc);}
	
	if (rc)
	{
		FAPI_ERR("IO_DCCAL : GCR_write error for rx_training_start_pg");
		return rc;
	}	
		//write rx_wt_cu_pll_reset to '1'
		rc= GCR_read(*target_ptr,master_interface,rx_wiretest_pll_cntl_pg,group,0,rx_wt_cu_pll_pgooddly_buf_copy);if (rc) {return(rc);}
		rc_ecmd|=set_bits.insert(rx_wt_cu_pll_pgooddly_buf_copy,0,16);
		//set_bits.setBit(0);
		rc_ecmd|=set_bits.setBit(1);
		//set_bits.setBit(2);
		//set_bits.setBit(3);
		//set_bits.setBit(4);
		bits=rx_wt_cu_pll_pgooddly_clear;
		rc_ecmd|=clear_bits.flushTo0();
		if(rc_ecmd)
		{
		  FAPI_ERR("IO_DCCAL : error setting up set_bits and clear_bits for GCR_write rx_wiretest_pll_cntl_pg");
			rc.setEcmdError(rc_ecmd);
            return(rc);
		}
		rc=GCR_write(*target_ptr,chip_interface,rx_wiretest_pll_cntl_pg,group,0,set_bits ,clear_bits);
		if(rc)
				{
			FAPI_ERR("IO_DCCAL : GCR_write error for rx_wiretest_pll_cntl_pg");
			return rc;
		}
		
		//write rx_wt_cu_pll_pgood to '1'
		rc= GCR_read(*target_ptr,master_interface,rx_wiretest_pll_cntl_pg,group,0,rx_wt_cu_pll_pgooddly_buf_copy);
		if (rc)
		{
			FAPI_ERR("IO_DCCAL : GCR_read error for rx_wiretest_pll_cntl_pg");
			return rc;
		}
		rc_ecmd|=set_bits.insert(rx_wt_cu_pll_pgooddly_buf_copy,0,16);
		rc_ecmd|=set_bits.setBit(0);
		//set_bits.setBit(1);
		//set_bits.setBit(2);
		//set_bits.setBit(3);
		//set_bits.setBit(4);
		bits=rx_wt_cu_pll_pgooddly_clear;
		rc_ecmd|=clear_bits.flushTo0();
		if(rc_ecmd)
		{
		  FAPI_ERR("IO_DCCAL : error setting up set_bits and clear_bits for GCR_write rx_wiretest_pll_cntl_pg");
			rc.setEcmdError(rc_ecmd);
            return(rc);
		}
		rc=GCR_write(*target_ptr,chip_interface,rx_wiretest_pll_cntl_pg,group,0,set_bits ,clear_bits);
		if (rc)
		{
			FAPI_ERR("IO_DCCAL : GCR_write error for rx_wiretest_pll_cntl_pg");
			return rc;
		}
		
	    fapiDelay(100000000,10000000); //Wait 100ms for zcal to complete before polling the status register
      
	    //write rx_wt_timeout_sel to '000'
      rc_ecmd|=  set_bits.insert(rx_wt_timeout_sel_buf,0,16);
		if(ddlevel==1){
		rc_ecmd|=  set_bits.clearBit(9);
		rc_ecmd|=  set_bits.clearBit(10);
		rc_ecmd|=  set_bits.clearBit(11);
		}else{
		rc_ecmd|=    set_bits.clearBit(10);
		rc_ecmd|=  set_bits.clearBit(11);
		rc_ecmd|=  set_bits.clearBit(12);
		}
        bits=rx_wt_timeout_sel_clear;
        //rc_ecmd|=clear_bits.insert(bits,0,16);
		rc_ecmd|=clear_bits.flushTo0();
        if(rc_ecmd)
        {
	  FAPI_ERR("IO_DCCAL : error setting up set_bits and clear_bits for GCR_write rx_timeout_sel_pg");
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
	//-- REVIEW here also bits var is not used but above dlevel conditions take care
        rc=GCR_write(*target_ptr,chip_interface,rx_timeout_sel_pg,group,0,set_bits ,clear_bits);
			if (rc)
		{
			FAPI_ERR("IO_DCCAL : error GCR_write rx_timeout_sel_pg");
			return rc;
		}
        // Poll for the done bit
	
        rc=GCR_read(*target_ptr,master_interface,rx_training_status_pg ,group,0,data_buffer);
		if (rc)
		{
			FAPI_ERR("IO_DCCAL : error GCR_read rx_training_status_pg");
			return rc;
		}
        
        int done_bit=rx_offset_cal_done;
        int fail_bit=rx_offset_cal_failed;
        bool fail= data_buffer.getHalfWord(0) & fail_bit;
        bool done = data_buffer.getHalfWord(0)& done_bit;
        int timeoutCnt = 0;
	//Updating timeout as per Gary/Joe's defect SW251251 to be ~1s than the 50s earlier count
	// This needs to be regressed in lab 
        while ( ( !done ) && ( timeoutCnt < 100 ) && !fail )
        {
                // wait for 80000 time units
                // Time units may be something for simulation, and something else (or nothing) for hardware
                // At any rate, this is intended to be approximately 100 us.
                rc=GCR_read(*target_ptr,chip_interface,rx_training_status_pg,group,0,data_buffer);
					if (rc)
			{
				// have to add support for field parsing
				FAPI_ERR("IO_DCCAL : error GCR_read rx_training_status_pg in polling for done bit loop");
				return rc;
			}
                fail= data_buffer.getHalfWord(0) & fail_bit;
                done = data_buffer.getHalfWord(0)& done_bit;
                fapiDelay(10000000,10000000);
                timeoutCnt++;
        }
        
        if ( fail)
        {
                FAPI_ERR("IO Offset cal error on interface %d",chip_interface);
                //Set HWP error
		io_interface_t& CHIP_INTERFACE = chip_interface;
		ecmdDataBufferBase& DATA_BUFFER = data_buffer;
		int& FAIL_BIT = fail_bit;
		const Target &TARGET = target;

                FAPI_SET_HWP_ERROR(rc,IO_DCCAL_OFFCAL_ERROR_RC);
                return rc;
        }
        // Check for errors
        else if ( timeoutCnt >=100 && !done && !fail )
        {
                FAPI_ERR("Timed out waiting for Done bit to be set");
                //Set HWP error
				int &TIMEOUTCNT=timeoutCnt;
                FAPI_SET_HWP_ERROR(rc,IO_DCCAL_OFFCAL_TIMEOUT_RC);
                return rc;
        }
        else
        {
             FAPI_DBG("IO Offset cal Completed on interface %d with timeoutcount %d",chip_interface,timeoutCnt);
        }
        
        // clear eye opt offset cal done bit, rx_eo_latch_offset_done
		rc=GCR_read(*target_ptr,chip_interface,rx_eo_step_stat_pg,group,0,set_bits);
				if (rc)
		{
			// have to add support for field parsing
			FAPI_ERR("IO_DCCAL : error GCR_read rx_eo_step_stat_pg");
			return rc;
		}
        rc_ecmd|=set_bits.clearBit(0);
        bits=rx_eo_latch_offset_done_clear;
        rc_ecmd|=clear_bits.insert(bits,0,16);
        if(rc_ecmd)
        {
	  FAPI_ERR("IO_DCCAL : error in set and clear bits for GCR_write rx_eo_step_stat_pg");
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc=GCR_write(*target_ptr,chip_interface,rx_eo_step_stat_pg,group,0,set_bits ,clear_bits);if (rc) {return(rc);}
        FAPI_DBG("Reading back 4.\n");
		rc= GCR_read(*target_ptr,master_interface,rx_eo_step_stat_pg ,group,0,data_buffer);if (rc) {return(rc);}
        // //restore rx_pdwn_lite_disable to saved value
        
        // bits=rx_pdwn_lite_value;
        // rc_ecmd|=set_bits.insert(bits,0,16);
        bits=rx_pdwn_lite_disable_clear;
        rc_ecmd|=clear_bits.insert(bits,0,16);
        // if(rc_ecmd)
        // {
            // rc.setEcmdError(rc_ecmd);
            // return(rc);
        // }
        rc=GCR_write(*target_ptr,chip_interface,rx_mode_pg,group,0,rx_pdwn_lite_value_buf ,clear_bits);if (rc) {return(rc);}
        
		
		
        // restore rx_wt_timeout_sel to saved value
        
        //bits=rx_wt_timeout_value;
		bits=rx_wt_timeout_sel_tap3;
        rc_ecmd|=set_bits.insert(rx_wt_timeout_sel_buf,0,16);
		//rc_ecmd |= set_bits.setAnd(bits,9,3);
		// if(target.getType() !=  fapi::TARGET_TYPE_MEMBUF_CHIP){
			// rc_ecmd|=set_bits.insert(bits,9,3);
		// }
		// else
		//rc_ecmd |= set_bits.clearBit(9);
        // --  bits=rx_wt_timeout_sel_clear;
        rc_ecmd|=clear_bits.flushTo0();
        if(rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc=GCR_write(*target_ptr,chip_interface,rx_timeout_sel_pg,group,0,set_bits ,clear_bits);if (rc) {return(rc);}
        
		FAPI_DBG("Reading back 5.\n");
		rc= GCR_read(*target_ptr,master_interface,rx_timeout_sel_pg ,group,0,data_buffer);if (rc) {return(rc);}
		
        
		//restore rx_wt_cu_pll_pgooddly
		//restore rx_wt_cu_pll_reset
		//restore rx_wt_cu_pll_pgood. Since they all belong to the same register field.
		bits=rx_wt_cu_pll_pgooddly_clear;
		rc_ecmd|=clear_bits.flushTo0();
		if(rc_ecmd)
		{
			rc.setEcmdError(rc_ecmd);
            return(rc);
		}
		rc=GCR_write(*target_ptr,chip_interface,rx_wiretest_pll_cntl_pg,group,0,rx_wt_cu_pll_pgooddly_buf ,clear_bits);if (rc) {return(rc);}
    
    
    return(rc);
}

ReturnCode run_zcal_debug(const Target& target,io_interface_t interface,uint32_t group)
{
    ReturnCode rc;
    ecmdDataBufferBase data_buffer(16);
    rc=GCR_read(target,interface,tx_impcal_nval_pb,group,0,data_buffer);if (rc) {return(rc);} // have to add support for field parsing
    rc=GCR_read(target,interface,tx_impcal_pval_pb,group,0,data_buffer);if (rc) {return(rc);} // have to add support for field parsing
    rc=GCR_read(target,interface,tx_impcal_p_4x_pb,group,0,data_buffer);if (rc) {return(rc);} // have to add support for field parsing
    return rc;
}

ReturnCode run_zcal(const Target& target,io_interface_t master_interface,uint32_t master_group){
    ReturnCode rc;
    const Target *target_ptr=&target; // Assuming I am allowed to do this . 
    uint32_t m=128; // MARGIN RATIO
    uint32_t k2=0; // POST CURSOR DRIVE RATIO
    bool swOverride=false;// IS SW_OVERRIDE requested
    uint16_t bits = 0;
    uint32_t rc_ecmd=0;
    ecmdDataBufferBase set_bits(16);
    ecmdDataBufferBase clear_bits(16);
    ecmdDataBufferBase data_buffer(16);
    rc_ecmd=set_bits.flushTo0();
    rc_ecmd|=clear_bits.flushTo1(); // I dont want to clear anything by default
    const fapi::Target &TARGET=target;
    const uint32_t& K2 = k2;
    const uint32_t& M = m;
    if(rc_ecmd)
    {
        rc.setEcmdError(rc_ecmd);
        return(rc);
    }
    io_interface_t chip_interface=master_interface;//first we run on master chip
    uint32_t group=master_group;
    
        const uint32_t min        = (10<<3);   // impcntl min -  - p8 - 10<<3
        const uint32_t max        = (40<<3);   // impcntl max -  - p8 - 40<<3
    
        uint32_t zcal_p = 0;
        uint32_t zcal_n = 0;
            
        uint32_t  zcal_override = 0; 
    
        if ((zcal_n>0) && (zcal_p>0) )
        {
                zcal_override = 1;
        }
    
        if ( k2 > 0x20 ) {
                    FAPI_DBG("POST CURSOR DRIVER RATIO k2 has exceeded 0.25");
                    FAPI_SET_HWP_ERROR(rc,IO_DCCAL_ZCAL_K2_EXCEEDED_RC);
                    return rc;
        }
    
        if ( m > 0x80 ) {
                    FAPI_DBG("MARGIN RATIO m has exceeded 100 percent");
                    FAPI_SET_HWP_ERROR(rc,IO_DCCAL_ZCAL_M_EXCEEDED_RC);
                    return rc;
        }

          if ( ( ! zcal_override ) && ( ! swOverride ) )
        {

                                FAPI_DBG("IO_DCCAL : Starting Impedance Calibration ");
                                //Get initial settings for debug purpose
                                run_zcal_debug(*target_ptr,chip_interface,group);
                                // Clear zcal_start. Need to first set start bit to 0 to enable rise to 1 transition.
                                rc=GCR_write(*target_ptr,chip_interface,tx_impcal_pb,group,0,set_bits,clear_bits,true);if (rc) {return(rc);}
                                bits=tx_zcal_req;
                                rc_ecmd|=set_bits.insert(bits,0,16);
                                bits=tx_zcal_req_clear;
                                rc_ecmd|=clear_bits.insert(bits,0,16);                                
                                if(rc_ecmd)
                                {
                                    rc.setEcmdError(rc_ecmd);
                                    return(rc);
                                }
                                // Skip a readback and verify 
                                rc=GCR_write(*target_ptr,chip_interface,tx_impcal_pb,group,0,set_bits,clear_bits,true);if (rc) {return(rc);}
                                fapiDelay(20000000,10000000); //Wait 20ms for zcal to complete before polling the status register
                                // Poll for the done bit
                                rc=GCR_read(*target_ptr,chip_interface,tx_impcal_pb,group,0,data_buffer);if (rc) {return(rc);} // have to add support for field parsing
                                int done_bit=tx_zcal_done;
                                int fail_bit=tx_zcal_error;
                                bool fail= data_buffer.getHalfWord(0) & fail_bit;
                                bool done = data_buffer.getHalfWord(0)& done_bit;
                                int timeoutCnt = 0;
                                while ( ( !done ) && ( timeoutCnt <150 ) ) {
                                            // wait for 80000 time units
                                            // Time units may be something for simulation, and something else (or nothing) for hardware
                                            // At any rate, this is intended to be approximately 100 us.                                                  
                                            rc=GCR_read(*target_ptr,chip_interface,tx_impcal_pb,group,0,data_buffer); if (rc) {return(rc);}// have to add support for field parsing
                                            done = data_buffer.getHalfWord(0)& done_bit;
                                            fail= data_buffer.getHalfWord(0) & fail_bit;
                                            fapiDelay(10000,10000000); //Wait around for HW 
                                            timeoutCnt++;
                                }
                                if(fail)
                                {
                                    FAPI_DBG("IO Impedance cal error on interface %d ",chip_interface);
                                     run_zcal_debug(*target_ptr,chip_interface,group);
                                    //set HWP error
				    ecmdDataBufferBase& DATA_BUFFER=data_buffer;
				    bool &FAIL=fail;
                                    FAPI_SET_HWP_ERROR(rc,IO_DCCAL_ZCAL_ERROR_RC);
                                    return(rc);
                                    
                                }
                                // Check for errors
                                else if ( timeoutCnt >= 100 &&!done && !fail )
                                {
                                            FAPI_DBG("Timed out waiting for Done bit to be set");
                                            //set HWP error
					    int &TIMEOUTCNT=timeoutCnt;
                                            FAPI_SET_HWP_ERROR(rc,IO_DCCAL_ZCAL_TIMEOUT_RC);
                                            return rc;
                                }
                                else
                                {
                                    FAPI_DBG("IO Impedance cal DONE successfully on interface %d",chip_interface);
                                }                
    
    
                    // Read the calculated values
                    // (Values are: xxxxxx yy zz, where yy are 2R and 4R values, and zz is a binary fraction)
                    rc=GCR_read(*target_ptr,chip_interface,tx_impcal_nval_pb,group,0,data_buffer);if (rc) {return(rc);} // have to add support for field parsing
                    data_buffer.extractToRight(&zcal_n,0,9); 
                    rc=GCR_read(*target_ptr,chip_interface,tx_impcal_pval_pb,group,0,data_buffer);if (rc) {return(rc);} // have to add support for field parsing
                    data_buffer.extractToRight(&zcal_p,0,9); 
    
        }
        else if ( swOverride )
        {
            /*
                   Software override might be required in case of workarounds to HW
            */
        }
    
        if ( ( (uint32_t)zcal_n < min )|| ( (uint32_t)zcal_n > max ) )
        {
                    FAPI_ERR("zcal_n value is out of impcntl range");
		    uint32_t &ZCAL_N=zcal_n;
		    const uint32_t &MIN=min;
		    const uint32_t &MAX=max;
		    
                    FAPI_SET_HWP_ERROR(rc, IO_DCCAL_ZCALN_VALUE_OUT_OF_RANGE_RC);
                    return rc;
        }
        if (   ( (uint32_t)zcal_p < min )|| ( (uint32_t)zcal_p > max ) )
        {
                    FAPI_ERR("zcal_p value is out of impcntl range");
		    uint32_t &ZCAL_P=zcal_p;
		    const uint32_t &MIN=min;
		    const uint32_t &MAX=max;
                    FAPI_SET_HWP_ERROR(rc, IO_DCCAL_ZCALP_VALUE_OUT_OF_RANGE_RC); 
                    return rc;
        }
    
        // margin = (1 -m)*zcal/2
        //  bits:                       7    10
        uint32_t margin_p = (0x80 - m) * zcal_p / 2;  // 7+2 = 9 binary decimal places // when it is 1 - something should it not be 0x01 - m?
        uint32_t margin_n = (0x80 - m) * zcal_n / 2;  // 7+2 = 9 binary decimal places
    
        // postcursor = (zcal - 2*margin)*k2
        //  bits:             7    7   10
        uint32_t post_p = (zcal_p - (margin_p<<1))*k2;  // 7+7+2 = 16 binary decimal places
        uint32_t post_n = (zcal_n - (margin_n<<1))*k2;  // 7+7+2 = 16 binary decimal places
    
        uint32_t main_p = (zcal_p - (margin_p<<1))- post_p;  // 2 binary decimal places
        uint32_t main_n = (zcal_n - (margin_n<<1))- post_n;  // 2 binary decimal places
    
    
        // Rounding
        post_p = BinaryRound(post_p, 16, 999); // round up
        post_n = BinaryRound(post_n, 16, 999); // round up
        margin_p = BinaryRound(margin_p, 9, 999); // round up
        margin_n = BinaryRound(margin_n, 9, 999); // round up
        main_p = BinaryRound(main_p, 2, 999); // round up
        main_n = BinaryRound(main_n, 2, 999); // round up
             
        FAPI_DBG("main_p value %d",main_p);
        FAPI_DBG("post_p value %d",post_p);
        FAPI_DBG("margin_p value %d",margin_p);
        FAPI_DBG("main_n value %d",main_n);
        FAPI_DBG("post_n value %d",post_n);
        FAPI_DBG("margin_n value %d",margin_n);
        
              
        rc_ecmd|=set_bits.flushTo0();
        rc_ecmd|=clear_bits.flushTo0(); // I dont want to clear anything by default
        if(rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        //N segments
        rc_ecmd|=set_bits.insert(main_p,1,7,25);
        rc_ecmd|=set_bits.insert(main_n,9,7,25);

        if(rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc=GCR_write(*target_ptr,chip_interface,tx_ffe_main_pg ,group,0,set_bits,clear_bits);if (rc) {return(rc);}
        
        rc_ecmd|=set_bits.flushTo0();
        rc_ecmd|=clear_bits.flushTo0(); // I dont want to clear anything by default
        if(rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc_ecmd|=set_bits.insert(post_p,3,5,27);
        rc_ecmd|=set_bits.insert(post_n,11,5,27);
        if(rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc=GCR_write(*target_ptr,chip_interface,tx_ffe_post_pg ,group,0,set_bits,clear_bits);if (rc) {return(rc);}
        
        rc_ecmd|=set_bits.flushTo0();
        rc_ecmd|=clear_bits.flushTo0(); // I dont want to clear anything by default
        if(rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc_ecmd|=set_bits.insert(margin_p,3,5,27);
        rc_ecmd|=set_bits.insert(margin_n,11,5,27);
        if(rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc=GCR_write(*target_ptr,chip_interface,tx_ffe_margin_pg  ,group,0,set_bits,clear_bits);if (rc) {return(rc);}
        

    return rc;
}

// Determines if target is a master ..I had assumed that PLAT wrapper code will know which side is master and which is slave 
ReturnCode isChipMaster(const Target&  chip_target, io_interface_t chip_interface,uint32_t current_group, bool   & masterchip_found ) {
    ReturnCode rc;
    ecmdDataBufferBase    mode_data(16);
    masterchip_found=false;

    // Check if rx_master_mode bit is set for chip
    // Read  rx_master_mode  for chip
    if(chip_interface==CP_FABRIC_X0)
    {
	rc=GCR_read(chip_target ,  chip_interface, ei4_rx_mode_pg,  current_group,0, mode_data);
    }
    else
    {
	rc=GCR_read(chip_target ,  chip_interface, rx_mode_pg,  current_group,0, mode_data);
    }
    if (rc) {
         FAPI_DBG("io_run_training: Error reading master mode bit\n");
    }
    // Check if  chip is master
    if (mode_data.isBitSet(0)) {
	 FAPI_DBG("This chip is a master\n");
        masterchip_found  =true;
    }
    return(rc);
}

// These functions work on a pair of targets. One is the master side of the bus interface, the other the slave side. For eg; in EDI(DMI2)PU is the master and Centaur is the slave
// In EI4 both sides have pu targets
ReturnCode io_dccal(const Target& target){
    ReturnCode rc;
    io_interface_t master_interface=CP_IOMC0_P0;
    uint32_t master_group=0;
	uint8_t pb_bndy_dmipll_data[231]={0},ab_bndy_pll_data[80]={0},tp_bndy_pll_data[80]={0};
    ecmdDataBufferBase ring_data;
    fapi::Target parent_target;
	uint32_t ring_length=0;
	uint32_t rc_ecmd=0;
const fapi::Target& TARGET = target;
    FAPI_DBG("Running IO DCCAL PROCEDURE");

    // This is a DMI/MC bus
    if (target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET)
    {
        FAPI_DBG("This is a Processor DMI bus using base DMI scom address");
        master_interface=CP_IOMC0_P0; // base scom for MC bus
        master_group=3; // Design requires us to do this as per scom map and layout

        // obtain parent chip target needed for ring manipulation
	    rc = fapiGetParentChip(target, parent_target);
        if (rc)
        {
            FAPI_ERR("Error from fapiGetParentChip");
            return(rc);
        }

        // install PLL config for dccal operation
	    rc = FAPI_ATTR_GET(ATTR_PROC_PB_BNDY_DMIPLL_LENGTH, &parent_target, ring_length);	// -- get length of scan ring
        if (rc)
        {
            FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_PB_BNDY_DMIPLL_LENGTH)");
            return(rc);
        }
	    rc = FAPI_ATTR_GET(ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA, &parent_target, pb_bndy_dmipll_data);	// -- get scan ring data
        if (rc)
        {
            FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA)");
            return(rc);
        }
	    rc_ecmd |= ring_data.setBitLength(ring_length);
	    rc_ecmd |= ring_data.insert(pb_bndy_dmipll_data, 0, ring_length, 0);		// -- put data into ecmd buffer
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc = proc_a_x_pci_dmi_pll_scan_bndy(parent_target,
                                            NEST_CHIPLET_0x02000000,
                                            PB_BNDY_DMIPLL_RING_ADDR,
                                            ring_data,
                                            true);
        if (rc)
        {
            FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
            return(rc);
        }

        // EDI/DMI needs both impedance cal and offset cal
        // Z cal doesnt require group since its a per bus feature , but to satisfy PLAT swapped translation requirements we pass group=3 on master
        rc = run_zcal(target,master_interface,master_group);
        if (rc)
        {
            FAPI_ERR("Error from run_zcal");
            return(rc);
        }
        // Offset cal requires group address
        rc = run_offset_cal(target,master_interface,master_group);
        if (rc)
        {
            FAPI_ERR("Error from run_offset_cal");
            return(rc);
        }

        // restore PLL config for functional operation
	    rc = FAPI_ATTR_GET(ATTR_PROC_PB_BNDY_DMIPLL_DATA, &parent_target, pb_bndy_dmipll_data);	// -- get scan ring data
        if (rc)
        {
            FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_PB_BNDY_DMIPLL_DATA)");
            return(rc);
        }
	    rc_ecmd |= ring_data.insert(pb_bndy_dmipll_data, 0, ring_length, 0);		// -- put data into ecmd buffer
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc = proc_a_x_pci_dmi_pll_scan_bndy(parent_target,
                                            NEST_CHIPLET_0x02000000,
                                            PB_BNDY_DMIPLL_RING_ADDR,
                                            ring_data,
                                            true);
        if (rc)
        {
            FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
            return(rc);
        }
    }
    else if (target.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP)
    {
        FAPI_DBG("This is a Centaur DMI bus using base DMI scom address");
        master_interface=CEN_DMI; // base scom for CEN
        master_group=0;

        // install PLL config for dccal operation
	    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_LENGTH, &target, ring_length);	// -- get length of scan ring
        if (rc)
        {
            FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_MEMB_TP_BNDY_PLL_LENGTH)");
            return(rc);
        }
  	    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA, &target, tp_bndy_pll_data);	// -- get scan ring data
        if (rc)
        {
            FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA)");
            return(rc);
        }
	    rc_ecmd |= ring_data.setBitLength(ring_length);
	    rc_ecmd |= ring_data.insert(tp_bndy_pll_data, 0, ring_length, 0);		// -- put data into ecmd buffer
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc = proc_a_x_pci_dmi_pll_scan_bndy(target,
                                            TP_CHIPLET_0x01000000,
                                            MEMB_TP_BNDY_PLL_RING_ADDR,
                                            ring_data,
                                            true);
        if (rc)
        {
            FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
            return(rc);
        }

        // EDI/DMI needs both impedance cal and offset cal
        // Z cal doesnt require group since its a per bus feature , but to satisfy PLAT swapped translation requirements we pass group=3 on master
        // Offset cal requires group address
        rc = run_zcal(target,master_interface,master_group);
        if (rc)
        {
            FAPI_ERR("Error from run_zcal");
            return(rc);
        }
        rc = run_offset_cal(target,master_interface,master_group);
        if (rc)
        {
            FAPI_ERR("Error from run_offset_cal");
            return(rc);
        }

        // restore PLL config for functional operation
        rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_DATA, &target, tp_bndy_pll_data);	// -- get scan ring data
        if (rc)
        {
            FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_MEMB_TP_BNDY_PLL_DATA)");
            return(rc);
        }
  	    rc_ecmd |= ring_data.insert(tp_bndy_pll_data, 0, ring_length, 0);		// -- put data into ecmd buffer
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }

        rc = proc_a_x_pci_dmi_pll_scan_bndy(target,
                                            TP_CHIPLET_0x01000000,
                                            MEMB_TP_BNDY_PLL_RING_ADDR,
                                            ring_data,
                                            true);
        if (rc)
        {
            FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
            return(rc);
        }
	}
    //This is an X Bus
    else if (target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT)
    {
        FAPI_DBG("This is a X Bus training invocation");
    }
    //This is an A Bus
    else if (target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT)
    {
        FAPI_DBG("This is an A Bus training invocation");
        master_interface=CP_FABRIC_A0; // base scom for A bus , assume translation to A1 by PLAT
        master_group=0; // Design requires us to do this as per scom map and layout

        // obtain parent chip target needed for ring manipulation
	    rc = fapiGetParentChip(target, parent_target);
        if (rc)
        {
            FAPI_ERR("Error from fapiGetParentChip");
            return(rc);
        }

        // install PLL config for dccal operation
  	    rc = FAPI_ATTR_GET(ATTR_PROC_AB_BNDY_PLL_LENGTH, &parent_target, ring_length);	// -- get length of scan ring
        if (rc)
        {
            FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_AB_BNDY_PLL_LENGTH)");
            return(rc);
        }
	    rc = FAPI_ATTR_GET(ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA, &parent_target, ab_bndy_pll_data);	// -- get scan ring data
        if (rc)
        {
            FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA)");
            return(rc);
        }
	    rc_ecmd |= ring_data.setBitLength(ring_length);
	    rc_ecmd |= ring_data.insert(ab_bndy_pll_data, 0, ring_length, 0);		// -- put data into ecmd buffer
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc = proc_a_x_pci_dmi_pll_scan_bndy(parent_target,
                                            A_BUS_CHIPLET_0x08000000,
                                            AB_BNDY_PLL_RING_ADDR,
                                            ring_data,
                                            true);
        if (rc)
        {
            FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
            return(rc);
        }

        // EDI-A bus needs both impedance cal and offset cal
	    rc = run_zcal(target,master_interface,master_group);
        if (rc)
        {
            FAPI_ERR("Error from run_zcal");
            return(rc);
        }
	    rc = run_offset_cal(target,master_interface,master_group);
        if (rc)
        {
            FAPI_ERR("Error from run_offset_cal");
            return(rc);
        }

        // restore PLL config for functional operation
	    rc = FAPI_ATTR_GET(ATTR_PROC_AB_BNDY_PLL_DATA, &parent_target, ab_bndy_pll_data);	// -- get scan ring data
        if (rc)
        {
            FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_AB_BNDY_PLL_DATA)");
            return(rc);
        }
	    rc_ecmd |= ring_data.setBitLength(ring_length);
	    rc_ecmd |= ring_data.insert(ab_bndy_pll_data, 0, ring_length, 0);		// -- put data into ecmd buffer
        if (rc_ecmd)
        {
            rc.setEcmdError(rc_ecmd);
            return(rc);
        }
        rc = proc_a_x_pci_dmi_pll_scan_bndy(parent_target,
                                            A_BUS_CHIPLET_0x08000000,
                                            AB_BNDY_PLL_RING_ADDR,
                                            ring_data,
                                            true);
        if (rc)
        {
            FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
            return(rc);
        }
    }
    else
    {
        FAPI_ERR("Invalid io_dccal HWP invocation . Target doesnt belong to DMI/X/A instances");
        FAPI_SET_HWP_ERROR(rc, IO_DCCAL_INVALID_INVOCATION_RC);
    }
    return rc;
}





} //end extern C
