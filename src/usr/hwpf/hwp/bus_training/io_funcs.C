/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_funcs.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: io_funcs.C,v 1.25 2014/03/20 08:36:49 varkeykv Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : IO_funcs.C
// *! TITLE                : 
// *! DESCRIPTION          : IO training common functions
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
//  1.14   |jaswamin|01/28/12| Changed fatal errors to warning prints to allow training to continue
//   1.0   |varkeykv|01/19/12| Initial check in to solve linker problems in host
//			       boot..moved in from io_run_training
//------------------------------------------------------------------------------
#include "io_funcs.H"


extern "C"
{
    using namespace fapi;
    

/****************************************************************************************/
/* edi_training.C   - functions of edi_training class                                */
/****************************************************************************************/

//! Wrapper to Run W,D,E,R , F based on bus_status (selected on);
ReturnCode  edi_training::run_training(const Target& master_target,  io_interface_t master_interface,uint32_t master_group, const Target&  slave_target,  io_interface_t  slave_interface,uint32_t slave_group) {
    ReturnCode rc;
    // bool master_chip_found=false; -- maybe for fabric ...need to test later
	
	FAPI_DBG("io_run_training: Starting training on SLAVE side");

	// Set the slave rx_start_wderf
        rc=run_training_functions(slave_target,slave_interface,slave_group);
	if (!rc.ok())  {
		 FAPI_ERR("io_run_training: Failed starting slave side training");
	}
        else{
            FAPI_DBG("io_run_training: Starting training on MASTER side\n");
            // Set the master  rx_start_wderf
            rc=run_training_functions(master_target,  master_interface,master_group);
            if (!rc.ok())  {
                    FAPI_ERR("io_run_training: Failed starting master side training");
            }
            else{
                 // Get training function  status for Master Chip  (poll on the master chip's rx_wderf_done)
		 if(master_interface==CP_FABRIC_X0){
		    for (int current_group = 0 ; current_group < 4; current_group++)
		    {
		    rc=training_function_status(master_target  ,  master_interface,current_group,   slave_target  ,  slave_interface,current_group);
			if(!rc.ok()){
			    FAPI_ERR("io_run_training : Failed Training");
			    return rc;
			}
		    }
		 }
		 else{
		     rc=training_function_status(master_target  ,  master_interface,master_group,   slave_target  ,  slave_interface,slave_group);
			if(!rc.ok()){
			    FAPI_ERR("io_run_training : Failed Training");
			    return rc;
			}
		    }
		 }
        }
    return(rc);
}


//  Run selected training function(s)
ReturnCode  edi_training::run_training_functions(const Target& target, io_interface_t interface,uint32_t current_group) {
    ReturnCode rc;
	uint32_t rc_ecmd=0;
	uint16_t bits=0;
	ecmdDataBufferBase set_bits, clear_bits,status_data;
	rc_ecmd|=set_bits.setBitLength(16);
	rc_ecmd|=clear_bits.setBitLength(16);
	rc_ecmd|=set_bits.flushTo0();
	rc_ecmd|=clear_bits.flushTo0();
	
	if(rc_ecmd)
	{
		FAPI_ERR("io_run_training:Data Buffer initiatlization failed !!\n");
		rc.setEcmdError(rc_ecmd); 
	}
	else
	{// Successful databuffer initialization ..we can proceed 
		if (wire_test_status==SELECTED)
                {
			bits=rx_start_wiretest;
			if(endpoints_set==1)
			{
				wire_test_status = RUNNING;
			}
			rx_wderf_start[WIRE_TEST]=1;
		}
		if (desckew_status==SELECTED)
                {
			bits|=rx_start_deskew;
			rx_wderf_start[DESKEW]=1;
			if(endpoints_set==1)
			{
				desckew_status = RUNNING;
			}
		}
		if (eye_opt_status==SELECTED)
                {
			bits|=rx_start_eye_opt;
			rx_wderf_start[EYE_OPT]=1;
			if(endpoints_set==1)
			{
				eye_opt_status= RUNNING;
			}
		}
		if (repair_status==SELECTED)
                {
			bits|=rx_start_repair;
			rx_wderf_start[REPAIR]=1;
			if(endpoints_set==1)
			{
				repair_status = RUNNING;
			}
		}
		if (functional_status==SELECTED)
                {
			bits|=rx_start_func_mode;
			rx_wderf_start[FUNCTIONAL]=1;
			if(endpoints_set==1)
			{
				functional_status = RUNNING;
			}
		}
		endpoints_set++; // Count number of endpoints we have set for training... when its 2 then we set the status to RUNNING
	
		// No need to do group wise loops , since for every end point there will be a separate thread of training code run 
		// Set Start Bits for group
		// Group address is set to 0 , since according to Discussion with Dean ,this code will run once per group.
		rc_ecmd|=set_bits.insert(bits,0,16);

		if(rc_ecmd)
		{
			FAPI_ERR("io_run_training:Data Buffer insertion failed !!\n");
                        rc.setEcmdError(rc_ecmd);
		}
		else
		{

			if(interface==CP_FABRIC_X0)
			{
	      		       FAPI_DBG("io_run_training:Setting Training start bit via broadcast on interface %d group=%d\n",interface,current_group);
   			       rc=GCR_write(target ,  interface,  ei4_rx_training_start_pg, 15,0,   set_bits, clear_bits,1,1);
			}
			else
			{
  	           FAPI_DBG("io_run_training:Setting Training start bit on interface %d group=%d\n",interface,current_group);
			   rc=GCR_write(target ,  interface,  rx_training_start_pg, current_group,0,   set_bits, clear_bits);
			}
			if (rc) {
				 FAPI_ERR("io_run_training: Failed to write training start bits \n");
			}
		}
	}
    return(rc);
 }


// Checks Status of Training Functions on Master Chip and also captures failure data on failure
ReturnCode  edi_training::training_function_status(const Target&  master_chip_target, io_interface_t  master_chip_interface ,uint32_t master_group,  const Target& slave_chip_target ,
												   io_interface_t slave_chip_interface,uint32_t slave_group)
{
    ReturnCode rc;
    uint32_t rc_ecmd=0;
    ecmdDataBufferBase    status_data;
    rc_ecmd|=status_data.setBitLength(16);
    rc_ecmd|=status_data.flushTo0();
    
    	//Reference variables matching error XML
	const fapi::Target& MASTER_TARGET = master_chip_target;
	const fapi::Target& SLAVE_TARGET = slave_chip_target;
	const io_interface_t& MASTER_CHIP_INTERFACE = master_chip_interface;
	const uint32_t& MASTER_GROUP = master_group;
	const io_interface_t& SLAVE_CHIP_INTERFACE = slave_chip_interface;
	const uint32_t& SLAVE_GROUP = slave_group;
    
    if(rc_ecmd)
    {
          FAPI_ERR("io_run_training: Failed buffer intialization in training_function_status\n");
          rc.setEcmdError(rc_ecmd);
    }
    else
    {
        uint64_t  curr_cyc = 0;         // start time
        uint64_t end_cycle=max_poll_cycles ;
	
	uint64_t &FFDC_NUM_CYCLES=curr_cyc;
        int state,fail_bit;
    
        while ( curr_cyc < end_cycle )
            {
                    // Reads Status Register for interface
		    if(master_chip_interface==CP_FABRIC_X0)
			{
			  rc=GCR_read(master_chip_target , master_chip_interface,  ei4_rx_training_status_pg,  master_group,0,  status_data);
			}
		    else
		    {
			rc=GCR_read(master_chip_target , master_chip_interface,  rx_training_status_pg,  master_group,0,  status_data);
		    }
                    if (rc) {
                      FAPI_DBG("io_run_training:Failed reading training status on master chip\n");
                      return(rc);
                    }
    
                    if (wire_test_status== RUNNING )
                    {
                            state=WIRE_TEST;
                            fail_bit=rx_wiretest_failed;
			    //Done bit does not get set on FAIL ..Update as per Mike Spears/Pete
                            if( status_data.isBitSet(state) || (status_data.getHalfWord(0) & fail_bit) )
                            {
                                    rx_wderf_done[WIRE_TEST]=true;
                                    if (status_data.getHalfWord(0) & fail_bit)
                                    {
                                       FAPI_ERR("io_run_training: the wiretest training state reported a fail  \n");
				      // FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_FAIL_WIRETEST_RC);
                                       wire_test_status =  FAILED ;
                                       rx_wderf_failed[WIRE_TEST]=true;
                                      // Run First FAILED Data Capture for Wire Test for FAILED bus
                                       rc=dump_ffdc_wiretest(master_chip_target, master_chip_interface , master_group, slave_chip_target ,  slave_chip_interface,slave_group);
				       break;
				    
                                    }
                                    else
                                    {
                                       FAPI_DBG("io_run_training:   the wiretest training function completed successfully  \n") ;
                                       wire_test_status =  SUCCESSFULL ;
                                    }
                            }
                     }
                    
                    if (desckew_status == RUNNING )
                    {
                            state=DESKEW;
                            fail_bit=rx_deskew_failed;
			    //Done bit does not get set on FAIL ..Update as per Mike Spears/Pete
                            if( status_data.isBitSet(state)|| (status_data.getHalfWord(0) & fail_bit))
                            {
                                    rx_wderf_done[DESKEW]=1;
                                    if (status_data.getHalfWord(0) & fail_bit || (status_data.getHalfWord(0) & fail_bit) )
                                    {
                                            rx_wderf_failed[DESKEW]=true;
                                            FAPI_ERR("io_run_training : deskew training state reported a fail  \n");
                                            //FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_FAIL_DESKEW_RC);
                                            desckew_status =  FAILED ;
					    rc=dump_ffdc_deskew(master_chip_target, master_chip_interface , master_group, slave_chip_target ,  slave_chip_interface,slave_group);
					    break;
                                    }
                                    else
                                    {
                                            FAPI_DBG("io_run_training:    deskew  training function completed successfully  \n") ;
                                            desckew_status =   SUCCESSFULL ;
                                    }
                            }
                    }
                    
                    if (eye_opt_status == RUNNING )
                    {
                            state=EYE_OPT;
                            fail_bit=rx_eye_opt_failed;
			     //Done bit does not get set on FAIL ..Update as per Mike Spears/Pete
                            if( status_data.isBitSet(state) || (status_data.getHalfWord(0) & fail_bit) )
                            {
                                    rx_wderf_done[EYE_OPT]=1;
                                    if (status_data.getHalfWord(0) & fail_bit)
                                    {
                                             FAPI_ERR("io_run_training : eye_opt_ training state reported a fail\n");
                                             //FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_FAIL_EYE_OPT_RC);
                                             rx_wderf_failed[EYE_OPT]=true;
                                             eye_opt_status =  FAILED ;
					    rc=dump_ffdc_eyeopt(master_chip_target, master_chip_interface , master_group, slave_chip_target ,  slave_chip_interface,slave_group);
					     break;
                                    }
                                    else
                                    {
                                             FAPI_DBG("io_run_training:    eye_opt_ training function completed successfully  \n") ;
                                             eye_opt_status =   SUCCESSFULL ;
                                    }
                            }
                    }
                    
                    if (repair_status == RUNNING )
                    {
                            state=REPAIR;
                            fail_bit=rx_repair_failed;
			     //Done bit does not get set on FAIL ..Update as per Mike Spears/Pete
                            if( status_data.isBitSet(state) || (status_data.getHalfWord(0) & fail_bit) )
                            {
                                    rx_wderf_done[REPAIR]=1;
                                    if (status_data.getHalfWord(0) & fail_bit)
                                    {
                                             FAPI_DBG("io_run_training: static repair encountered an error    \n");
					      //FAPI_SET_HWP_ERROR(rc,   IO_RUN_TRAINING_FAIL_REPAIR_RC);
					     rc=dump_ffdc_repair(master_chip_target, master_chip_interface , master_group, slave_chip_target ,  slave_chip_interface,slave_group);
                                             rx_wderf_failed[REPAIR]=true;
                                             repair_status =  FAILED ;
					     break;
                                    }
                                    else
                                    {
                                             FAPI_DBG("io_run_training:   the rx_repair function completed successfully  \n") ;
                                             repair_status =  SUCCESSFULL ;
                                    }
                            }
                    }
                    
                    
                    if (functional_status == RUNNING)
                    {
			FAPI_DBG("functional status is Running!!");
                            state=FUNCTIONAL;
                            fail_bit=rx_func_mode_failed;
			     //Done bit does not get set on FAIL ..Update as per Mike Spears/Pete
                            if( status_data.isBitSet(state ) || (status_data.getHalfWord(0) & fail_bit))
                            {
                                    rx_wderf_done[FUNCTIONAL]=1;
                                    if (status_data.getHalfWord(0) & fail_bit)
                                    {
                                             FAPI_DBG("io_run_training:   rx_func_mode_failed    \n");
                                             rx_wderf_failed[FUNCTIONAL]=true;
                                             //FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_FAIL_FUNC_MODE_RC);
					      rc=dump_ffdc_func(master_chip_target, master_chip_interface , master_group, slave_chip_target ,  slave_chip_interface,slave_group);
                                             functional_status =   FAILED ;
					     break;
                                    }
                                    else
                                    {
                                             FAPI_DBG("io_run_training:   rx_func_mode_function completed successfully  \n") ;
                                             functional_status =  SUCCESSFULL  ;
                                    }
                       }
                    }
                    
                    
                    if ((wire_test_selected && wire_test_status== RUNNING)  ||  (desckew_selected && desckew_status == RUNNING)   ||
                       (repair_selected &&  repair_status == RUNNING )     ||  (eye_opt_selected && eye_opt_status == RUNNING)   ||
                       (functional_selected &&  functional_status ==   RUNNING ) )
                    {
                        // Training still running  ,  continue checking status
                        curr_cyc++;
                        FAPI_DBG("\n\t io_run_training: Cycles into polling = %lld\n", curr_cyc);
                        FAPI_DBG("\n\t io_run_training: Cycles remaining in polling = %lld\n", end_cycle - curr_cyc );
			// Updated Loop count and per delay call count to acheive max of 100ms theoretical delay as per Mike Spear
			// This is 1ms poll call..Loop counter =100 .. a total of ~100ms
                        rc=fapiDelay(1000000,increment_poll_cycles);
                        if(!rc.ok())
                        {
                               FAPI_ERR("io_run_training : Unexpected error in fapiDelay routine\n");
                               return(rc);
                        }
                    }
                    else
                    {
                     // Training Completed Exit cuurent  Loop
                     break;
                    }
                    
                    if ( curr_cyc >= end_cycle )
                    {
                            dump_ffdc_wiretest(master_chip_target, master_chip_interface ,master_group,  slave_chip_target ,  slave_chip_interface,slave_group);
			     
			    if (wire_test_selected && wire_test_status== RUNNING)
			    {
			    FAPI_ERR("io_run_training: wiretest timeout");
			    FAPI_SET_HWP_ERROR(rc, IO_FUNCS_WIRETEST_TIMEOUT_RC);
			    }
			    else if (desckew_selected && desckew_status == RUNNING)
			    {
			    FAPI_ERR("io_run_training: deskew timeout");
			    FAPI_SET_HWP_ERROR(rc, IO_FUNCS_DESKEW_TIMEOUT_RC);
			    }
			    else if (repair_selected && repair_status == RUNNING)
			    {
			    FAPI_ERR("io_run_training: repair timeout");
			    FAPI_SET_HWP_ERROR(rc, IO_FUNCS_REPAIR_TIMEOUT_RC);
			    }
			    else if (eye_opt_selected && eye_opt_status == RUNNING)
			    {
			    FAPI_ERR("io_run_training: eyeopt timeout");
			    FAPI_SET_HWP_ERROR(rc, IO_FUNCS_EYEOPT_TIMEOUT_RC);
			    }
			    else
			    {
			    FAPI_ERR("io_run_training: func timeout");
			    FAPI_SET_HWP_ERROR(rc, IO_FUNCS_FUNC_MODE_TIMEOUT_RC);
			    }
			    break;
                    }
            }   // polling loop
    }
    return(rc);
}

// Determines if target is a master...currently not used , but could be used in Fabric(EI4) but i assume PLAT code will know which side is master and which is slave 
ReturnCode edi_training::isChipMaster(const Target&  chip_target, io_interface_t chip_interface,uint32_t current_group, bool   & masterchip_found ) {
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



// First Fail Data Capture (wire_test)
// FFDC functions have not been tested in detail ..
// Will need to tie this into the eRepair/PRD conversation that we are having with Zane
  // DUMP ALL THESE
  //      rx_lane_disabled_vec_0_15_pg,
  //      rx_lane_disabled_vec_16_31_pg,
  //      rx_lane_swapped_vec_0_15_pg,
  //      rx_lane_swapped_vec_16_31_pg,
  //      rx_init_state_pg,
  //      rx_wiretest_state_pg,
  //      rx_wiretest_laneinfo_pg,
  //	rx_wt_status_pl
          //rx_main_init_state
          //rx_wtl_state
          //rx_wtm_state
          //rx_wtr_state
          //rx_wtr_bad_lane_count
          //rx_wt_lane_bad_code ( per lane - can we?)
          //rx_wtr_bad_lane_count
          //rx_wiretest_failed
          //rx_wt_clk_bad_lane_code?
          //rx_wt_clk_lane_inverted?
	  //rx_wt_clk_status_pg
ReturnCode  edi_training::dump_ffdc_wiretest(const Target&  master_chip_target, io_interface_t  master_chip_interface ,uint32_t master_group, const Target& slave_chip_target ,
											 io_interface_t slave_chip_interface,uint32_t slave_group)
{
    ReturnCode rc;
    ReturnCode lane_rc; // for logging per lane FFDC
    
	const io_interface_t& MASTER_CHIP_INTERFACE = master_chip_interface;
	const uint32_t& MASTER_GROUP = master_group;
	const io_interface_t& SLAVE_CHIP_INTERFACE = slave_chip_interface;
	const uint32_t& SLAVE_GROUP = slave_group;
    
    const fapi::Target &MASTER_TARGET=master_chip_target;
    const fapi::Target &SLAVE_TARGET=slave_chip_target;
    
    
    //FFDC Buffers
    ecmdDataBufferBase MASTER_RX_LANE_BAD_0_15_PG(16);
    ecmdDataBufferBase MASTER_RX_LANE_BAD_16_31_PG(16);
    ecmdDataBufferBase MASTER_RX_LANE_DISABLED_VEC_0_15_PG(16);
    ecmdDataBufferBase MASTER_RX_LANE_DISABLED_VEC_16_31_PG(16);
    ecmdDataBufferBase MASTER_RX_LANE_SWAPPED_VEC_0_15_PG(16);
    ecmdDataBufferBase MASTER_RX_LANE_SWAPPED_VEC_16_31_PG(16);
    ecmdDataBufferBase MASTER_RX_INIT_STATE_PG(16);
    ecmdDataBufferBase MASTER_RX_WIRETEST_STATE_PG(16);
    ecmdDataBufferBase MASTER_RX_WIRETEST_LANEINFO_PG(16);
    ecmdDataBufferBase MASTER_RX_TRAINING_STATUS_PG(16);
    ecmdDataBufferBase MASTER_RX_WT_CLK_STATUS_PG(16);
    
     ecmdDataBufferBase SLAVE_RX_LANE_BAD_0_15_PG(16);
    ecmdDataBufferBase SLAVE_RX_LANE_BAD_16_31_PG(16);
    ecmdDataBufferBase SLAVE_RX_LANE_DISABLED_VEC_0_15_PG(16);
    ecmdDataBufferBase SLAVE_RX_LANE_DISABLED_VEC_16_31_PG(16);
    ecmdDataBufferBase SLAVE_RX_LANE_SWAPPED_VEC_0_15_PG(16);
    ecmdDataBufferBase SLAVE_RX_LANE_SWAPPED_VEC_16_31_PG(16);
    ecmdDataBufferBase SLAVE_RX_INIT_STATE_PG(16);
    ecmdDataBufferBase SLAVE_RX_WIRETEST_STATE_PG(16);
    ecmdDataBufferBase SLAVE_RX_WIRETEST_LANEINFO_PG(16);
    ecmdDataBufferBase SLAVE_RX_TRAINING_STATUS_PG(16);
    ecmdDataBufferBase SLAVE_RX_WT_CLK_STATUS_PG(16);
    
    //These are for per-lane FFDC captures
    ecmdDataBufferBase RX_WT_STATUS_PL(16);
    
    const uint32_t NUM_PG_REGS=11;
  //  const uint32_t NUM_PL_REGS=0;
    
    const GCR_sub_registers pg_reg_list[NUM_PG_REGS]={rx_lane_bad_vec_0_15_pg,rx_lane_bad_vec_16_31_pg,rx_lane_disabled_vec_0_15_pg, rx_lane_disabled_vec_16_31_pg,rx_lane_swapped_vec_0_15_pg,
    rx_lane_swapped_vec_16_31_pg,rx_init_state_pg,rx_wiretest_state_pg,rx_wiretest_laneinfo_pg,rx_training_status_pg,rx_wt_clk_status_pg};
    
   // const GCR_sub_registers pl_reg_list[NUM_PL_REGS]={};
    
    ecmdDataBufferBase *MASTER_BUFFERS[NUM_PG_REGS]= { &MASTER_RX_LANE_BAD_0_15_PG,
					    &MASTER_RX_LANE_BAD_16_31_PG,
					    &MASTER_RX_LANE_DISABLED_VEC_0_15_PG,
					    &MASTER_RX_LANE_DISABLED_VEC_16_31_PG,
					    &MASTER_RX_LANE_SWAPPED_VEC_0_15_PG,
					    &MASTER_RX_LANE_SWAPPED_VEC_16_31_PG,
					    &MASTER_RX_INIT_STATE_PG,
					    &MASTER_RX_WIRETEST_STATE_PG,
					    &MASTER_RX_WIRETEST_LANEINFO_PG,
					    &MASTER_RX_TRAINING_STATUS_PG,
					    &MASTER_RX_WT_CLK_STATUS_PG
					};
     
  ecmdDataBufferBase *SLAVE_BUFFERS[NUM_PG_REGS]= { &SLAVE_RX_LANE_BAD_0_15_PG,
					    &SLAVE_RX_LANE_BAD_16_31_PG,
					    &SLAVE_RX_LANE_DISABLED_VEC_0_15_PG,
					    &SLAVE_RX_LANE_DISABLED_VEC_16_31_PG,
					    &SLAVE_RX_LANE_SWAPPED_VEC_0_15_PG,
					    &SLAVE_RX_LANE_SWAPPED_VEC_16_31_PG,
					    &SLAVE_RX_INIT_STATE_PG,
					    &SLAVE_RX_WIRETEST_STATE_PG,
					    &SLAVE_RX_WIRETEST_LANEINFO_PG,
					    &SLAVE_RX_TRAINING_STATUS_PG,
					    &SLAVE_RX_WT_CLK_STATUS_PG
					};
    FAPI_DBG("dump_ffdc_wiretest function entered \n");
    
    

    // Capture MASTER Side registers 

    uint32_t rx_lane_end=num_rxlanes_per_group[master_chip_interface];
    
	for(uint32_t reg_num=0;reg_num<NUM_PG_REGS;++reg_num){
	    FAPI_DBG("Reading register name %s on MASTER side",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    rc=GCR_read(master_chip_target ,  master_chip_interface, pg_reg_list[reg_num],  master_group,0,  *MASTER_BUFFERS[reg_num]);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pg_reg_list[reg_num]]); 
	    }
	    // Not doing the else here on purpose.. if read on one reg fails , we want to try next and maybe the slave side if all fails
	    
	}
	
	for(uint32_t reg_num=0;reg_num<NUM_PG_REGS;++reg_num){
	    FAPI_DBG("Reading register name %s on SLAVE side",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    rc=GCR_read(slave_chip_target ,  slave_chip_interface, pg_reg_list[reg_num],  slave_group,0,  *SLAVE_BUFFERS[reg_num]);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    }
	    // Not doing the else here on purpose.. if read on one reg fails , we want to try next and maybe the slave side if all fails
	}
	
        FAPI_SET_HWP_ERROR(lane_rc,IO_FUNCS_WIRETEST_FAIL_RC);
	
	//Lets do per-lane registers now , will Log and continue instead of wasting buffers and making it complex
	for(uint32_t lane=0;lane<rx_lane_end;++lane){
	    FAPI_DBG("Reading per lane register RX_WT_STATUS_PL on lane %d",lane);
	    rc=GCR_read(master_chip_target ,  master_chip_interface, rx_wt_status_pl,  master_group,lane, RX_WT_STATUS_PL);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading RX_WT_STATUS_PL"); 
	    }
	    else{
	    // we will continue to try other lanes data
	    const fapi::Target & CHIP_TARGET= master_chip_target;
	     uint32_t &LANEID=lane;
		//as per Andrea to save log space 
		FAPI_ADD_INFO_TO_HWP_ERROR(lane_rc,IO_FUNCS_WIRETEST_FAIL_LANE_MASTER_DATA_RC);
	    }
	}
	

    // Capture SLAVE Side registers 
     rx_lane_end=num_rxlanes_per_group[slave_chip_interface];
    

	
		//Lets do per-lane registers now , will Log and continue instead of wasting buffers and making it complex
	for(uint32_t lane=0;lane<rx_lane_end;++lane){
	    FAPI_DBG("Reading per lane register RX_WT_STATUS_PL on lane %d",lane);
	     rc=GCR_read(slave_chip_target ,  slave_chip_interface, rx_wt_status_pl,  slave_group,lane,  RX_WT_STATUS_PL);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading RX_WT_STATUS_PL"); 
	    }
	    else{
	     const fapi::Target & CHIP_TARGET= slave_chip_target;
	     uint32_t &LANEID=lane;
		//as per Andrea to save log space 
		FAPI_ADD_INFO_TO_HWP_ERROR(lane_rc,IO_FUNCS_WIRETEST_FAIL_LANE_SLAVE_DATA_RC);
	    }
	}

    return(lane_rc);
}


   //rx_rxdsm_state
   //   rx_deskew_failed --> rx_training_status_pg 
   //    rx_bad_block_lock --> rx_deskew_stat_pl
   //     rx_bad_skew  --> rx_deskew_stat_pl
   //     rx_bad_deskew --> rx_deskew_stat_pl
   //     rx_some_skew_valid --> rx_stat_pl
   //     rx_some_block_locked --> rx_stat_pl
   //     rx_skew_value  --> rx_stat_pl
   //     rx_vref --> rx_vref_pl 
   //     rx_fifo_l2u_dly --> rx_fifo_stat_pl 
   //     rx_phaserot_val -->  rx_prot_status_pl

ReturnCode  edi_training::dump_ffdc_deskew(const Target&  master_chip_target, io_interface_t  master_chip_interface ,uint32_t master_group, const Target& slave_chip_target ,
											 io_interface_t slave_chip_interface,uint32_t slave_group)
{
    ReturnCode rc;
    ReturnCode lane_rc; // for logging per lane FFDC
    
    const fapi::Target &MASTER_TARGET=master_chip_target;
    const fapi::Target &SLAVE_TARGET=slave_chip_target;
    	const io_interface_t& MASTER_CHIP_INTERFACE = master_chip_interface;
	const uint32_t& MASTER_GROUP = master_group;
	const io_interface_t& SLAVE_CHIP_INTERFACE = slave_chip_interface;
	const uint32_t& SLAVE_GROUP = slave_group;
    
    
    //FFDC Buffers;
    ecmdDataBufferBase MASTER_RX_INIT_STATE_PG(16);
    ecmdDataBufferBase MASTER_RX_TRAINING_STATUS_PG(16);
    ecmdDataBufferBase MASTER_RX_DESKEW_STATE_PG(16);
      ecmdDataBufferBase MASTER_RX_LANE_BAD_0_15_PG(16);
    ecmdDataBufferBase MASTER_RX_LANE_BAD_16_31_PG(16);
    
    ecmdDataBufferBase SLAVE_RX_INIT_STATE_PG(16);
    ecmdDataBufferBase SLAVE_RX_TRAINING_STATUS_PG(16);
    ecmdDataBufferBase SLAVE_RX_DESKEW_STATE_PG(16);
      ecmdDataBufferBase SLAVE_RX_LANE_BAD_0_15_PG(16);
    ecmdDataBufferBase SLAVE_RX_LANE_BAD_16_31_PG(16);

    
    //These are for per-lane FFDC captures
    ecmdDataBufferBase RX_DESKEW_STAT_PL(16);
    ecmdDataBufferBase RX_STAT_PL(16);
    ecmdDataBufferBase RX_FIFO_STAT_PL(16);
    ecmdDataBufferBase RX_PROT_STATUS_PL(16);
    
    //EI4 only
        ecmdDataBufferBase RX_VREF_PL(16);
    
    const uint32_t NUM_PG_REGS=5;
    const uint32_t NUM_PL_REGS=5;
    
    const GCR_sub_registers pg_reg_list[NUM_PG_REGS]={rx_init_state_pg,rx_training_status_pg,rx_deskew_state_pg,rx_lane_bad_vec_0_15_pg,rx_lane_bad_vec_16_31_pg};
    
    const GCR_sub_registers pl_reg_list[NUM_PL_REGS]={rx_deskew_stat_pl,rx_stat_pl,rx_fifo_stat_pl,rx_prot_status_pl,ei4_rx_vref_pl};
    
    ecmdDataBufferBase *MASTER_BUFFERS[NUM_PG_REGS+NUM_PL_REGS]= {  &MASTER_RX_INIT_STATE_PG,
					    &MASTER_RX_TRAINING_STATUS_PG,
					    &MASTER_RX_DESKEW_STATE_PG,&MASTER_RX_LANE_BAD_0_15_PG,&MASTER_RX_LANE_BAD_16_31_PG,
					    &RX_DESKEW_STAT_PL,
					    &RX_STAT_PL,
					    &RX_FIFO_STAT_PL,
					    &RX_PROT_STATUS_PL,
					        &RX_VREF_PL
					};
     
    ecmdDataBufferBase *SLAVE_BUFFERS[NUM_PG_REGS+NUM_PL_REGS]= {  &SLAVE_RX_INIT_STATE_PG,
				       &SLAVE_RX_TRAINING_STATUS_PG,
				       & SLAVE_RX_DESKEW_STATE_PG,&SLAVE_RX_LANE_BAD_0_15_PG,&SLAVE_RX_LANE_BAD_16_31_PG,
					    &RX_DESKEW_STAT_PL,
					    &RX_STAT_PL,
					    &RX_FIFO_STAT_PL,
					    &RX_PROT_STATUS_PL,
					     &RX_VREF_PL
				   };


    FAPI_DBG("dump_ffdc_deskew function entered \n");

    // Capture MASTER Side registers 

    uint32_t rx_lane_end=num_rxlanes_per_group[master_chip_interface];
    
	for(uint32_t reg_num=0;reg_num<NUM_PG_REGS;++reg_num){
	    FAPI_DBG("Reading register name %s on MASTER side",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    rc=GCR_read(master_chip_target ,  master_chip_interface, pg_reg_list[reg_num],  master_group,0,  *MASTER_BUFFERS[reg_num]);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pg_reg_list[reg_num]]); 
	    }
	    // Not doing the else here on purpose.. if read on one reg fails , we want to try next and maybe the slave side if all fails
	}
	
	    
  	for(uint32_t reg_num=0;reg_num<NUM_PG_REGS;++reg_num){
	    FAPI_DBG("Reading register name %s on SLAVE side",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    rc=GCR_read(slave_chip_target ,  slave_chip_interface, pg_reg_list[reg_num],  slave_group,0,  *SLAVE_BUFFERS[reg_num]);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pg_reg_list[reg_num]]); 
	    }
	    // Not doing the else here on purpose.. if read on one reg fails , we want to try next and maybe the slave side if all fails
	}
	
        FAPI_SET_HWP_ERROR(lane_rc,IO_FUNCS_DESKEW_FAIL_RC);
	//Lets do per-lane registers now , will Log and continue instead of wasting buffers and making it complex
	for(uint32_t lane=0;lane<rx_lane_end;++lane){
	    for(uint32_t lane_reg_num=0;lane_reg_num<NUM_PL_REGS;++lane_reg_num){
		if(master_chip_interface!=CP_FABRIC_X0 && pl_reg_list[lane_reg_num] ==ei4_rx_vref_pl ){
		    continue; // VREF PL valid only for X bus 
		}
		FAPI_DBG("Reading per lane register %s on lane %d",GCR_sub_reg_names[pl_reg_list[lane_reg_num]],lane);
		rc=GCR_read(master_chip_target ,  master_chip_interface, pl_reg_list[lane_reg_num],  master_group,lane, *MASTER_BUFFERS[NUM_PG_REGS+lane_reg_num]);
		if (rc)
		{
		     FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pl_reg_list[lane_reg_num]]); 
		}
		else{
	    	// we will continue to try other lanes data
		const fapi::Target & CHIP_TARGET= master_chip_target;
		 uint32_t &LANEID=lane;
		 FAPI_SET_HWP_ERROR(lane_rc,IO_FUNCS_DESKEW_FAIL_LANE_MASTER_DATA_RC);
		   //as per Andrea to save log space 
		   FAPI_ADD_INFO_TO_HWP_ERROR(lane_rc,IO_FUNCS_DESKEW_FAIL_LANE_MASTER_DATA_RC);
		}
	     }
	}
	

    // Capture SLAVE Side registers 
     rx_lane_end=num_rxlanes_per_group[slave_chip_interface];

	//Lets do per-lane registers now , will Log and continue instead of wasting buffers and making it complex
	for(uint32_t lane=0;lane<rx_lane_end;++lane){
	    for(uint32_t lane_reg_num=0;lane_reg_num<NUM_PL_REGS;++lane_reg_num){
		 if(slave_chip_interface!=CP_FABRIC_X0 && pl_reg_list[lane_reg_num] ==ei4_rx_vref_pl ){
		    continue; // VREF PL valid only for X bus 
		}
		FAPI_DBG("Reading per lane register %s on lane %d",GCR_sub_reg_names[pl_reg_list[lane_reg_num]],lane);
		rc=GCR_read(slave_chip_target ,  slave_chip_interface, pl_reg_list[lane_reg_num],  slave_group,lane, *SLAVE_BUFFERS[NUM_PG_REGS+lane_reg_num]);
		if (rc)
		{
		     FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pl_reg_list[lane_reg_num]]); 
		}
		else{
		    		// we will continue to try other lanes data
		const fapi::Target & CHIP_TARGET= slave_chip_target;
		 uint32_t &LANEID=lane;
		   //as per Andrea to save log space 
		   FAPI_ADD_INFO_TO_HWP_ERROR(lane_rc,IO_FUNCS_DESKEW_FAIL_LANE_SLAVE_DATA_RC);
		}
	     }
	}



    return(lane_rc);
}


// FFDC AS per Rob
//
//rx_eye_opt_failed -->  rx_training_status_pg 
//rx_eye_opt_state  rx_eo_recal_pg 
//rx_ap_even_samp rx_ap_pl
//rx_ap_odd_samp rx_ap_pl
//rx_an_even_samp rx_an_pl
//rx_an_odd_samp rx_an_pl
//rx_amin_even  rx_amin_pl 
//rx_amin_odd  rx_amin_pl 
//rx_h1_even_samp1  rx_h1_even_pl
//rx_h1_even_samp0  rx_h1_even_pl
//rx_h1_odd_samp1  rx_h1_odd_pl
//rx_h1_odd_samp0 rx_h1_odd_pl
//rx_bad_eye_opt_ber rx_eye_opt_stat_pl
//rx_bad_eye_opt_width rx_eye_opt_stat_pl
//rx_bad_eye_opt_height rx_eye_opt_stat_pl
//rx_bad_eye_opt_ddc rx_eye_opt_stat_pl
//rx_eye_width rx_eye_width_status_pl 
//rx_hist_min_eye_width_valid rx_eye_width_status_pl 
//rx_hist_min_eye_width rx_eye_width_status_pl 
//rx_dcd_adjust rx_dcd_adj_pl

ReturnCode  edi_training::dump_ffdc_eyeopt(const Target&  master_chip_target, io_interface_t  master_chip_interface ,uint32_t master_group, const Target& slave_chip_target ,
											 io_interface_t slave_chip_interface,uint32_t slave_group)
{
    ReturnCode rc;
    ReturnCode lane_rc; // for logging per lane FFDC
    
    const fapi::Target &MASTER_TARGET=master_chip_target;
    const fapi::Target &SLAVE_TARGET=slave_chip_target;
    
    	const io_interface_t& MASTER_CHIP_INTERFACE = master_chip_interface;
	const uint32_t& MASTER_GROUP = master_group;
	const io_interface_t& SLAVE_CHIP_INTERFACE = slave_chip_interface;
	const uint32_t& SLAVE_GROUP = slave_group;
    
    //FFDC Buffers;
    ecmdDataBufferBase MASTER_RX_TRAINING_STATUS_PG(16);
    ecmdDataBufferBase MASTER_RX_EO_RECAL_PG(16);
      ecmdDataBufferBase MASTER_RX_LANE_BAD_0_15_PG(16);
    ecmdDataBufferBase MASTER_RX_LANE_BAD_16_31_PG(16);
    
    ecmdDataBufferBase SLAVE_RX_TRAINING_STATUS_PG(16);
    ecmdDataBufferBase SLAVE_RX_EO_RECAL_PG(16);
      ecmdDataBufferBase SLAVE_RX_LANE_BAD_0_15_PG(16);
    ecmdDataBufferBase SLAVE_RX_LANE_BAD_16_31_PG(16);

    
    //These are for per-lane FFDC captures
    ecmdDataBufferBase RX_AP_PL(16);// EDI only
    ecmdDataBufferBase RX_AN_PL(16);// EDI only
    ecmdDataBufferBase RX_AMIN_PL(16);// EDI only
    ecmdDataBufferBase RX_H1_EVEN_PL(16);// EDI only
    ecmdDataBufferBase RX_H1_ODD_PL(16);// EDI only
    ecmdDataBufferBase RX_EYE_OPT_STATE_PL(16); // both
    ecmdDataBufferBase RX_EYE_WIDTH_STATUS_PL(16); //both 
    ecmdDataBufferBase RX_DCD_ADJ_PL(16); // ei4 only
    
    const uint32_t NUM_PG_REGS=4;
    const uint32_t NUM_PL_REGS=8;
    
    const GCR_sub_registers pg_reg_list[NUM_PG_REGS]={rx_training_status_pg,rx_eo_recal_pg,rx_lane_bad_vec_0_15_pg,rx_lane_bad_vec_16_31_pg};
    
    const GCR_sub_registers pl_reg_list[NUM_PL_REGS]={rx_ap_pl,rx_an_pl,rx_amin_pl,rx_h1_even_pl,rx_h1_odd_pl,rx_eye_opt_stat_pl,rx_eye_width_status_pl,ei4_rx_dcd_adj_pl};
    
    ecmdDataBufferBase *MASTER_BUFFERS[NUM_PG_REGS+NUM_PL_REGS]= {  &MASTER_RX_TRAINING_STATUS_PG,
					    &MASTER_RX_EO_RECAL_PG,&MASTER_RX_LANE_BAD_0_15_PG,&MASTER_RX_LANE_BAD_16_31_PG,
					    &RX_AP_PL,
					    &RX_AN_PL,
					    &RX_AMIN_PL,
					    &RX_H1_EVEN_PL,
					    &RX_H1_ODD_PL,
					    &RX_EYE_OPT_STATE_PL, 
					    &RX_EYE_WIDTH_STATUS_PL, 
					    &RX_DCD_ADJ_PL
					};
     
       
    ecmdDataBufferBase *SLAVE_BUFFERS[NUM_PG_REGS+NUM_PL_REGS]= {  &SLAVE_RX_TRAINING_STATUS_PG,
					    &SLAVE_RX_EO_RECAL_PG,&SLAVE_RX_LANE_BAD_0_15_PG,&SLAVE_RX_LANE_BAD_16_31_PG,
					    &RX_AP_PL,
					    &RX_AN_PL,
					    &RX_AMIN_PL,
					    &RX_H1_EVEN_PL,
					    &RX_H1_ODD_PL,
					    &RX_EYE_OPT_STATE_PL, 
					    &RX_EYE_WIDTH_STATUS_PL, 
					    &RX_DCD_ADJ_PL
					};
     


    FAPI_DBG("dump_ffdc_eyeopt function entered \n");

    // Capture MASTER Side registers 

    uint32_t rx_lane_end=num_rxlanes_per_group[master_chip_interface];
    
	for(uint32_t reg_num=0;reg_num<NUM_PG_REGS;++reg_num){
	    FAPI_DBG("Reading register name %s on MASTER side",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    rc=GCR_read(master_chip_target ,  master_chip_interface, pg_reg_list[reg_num],  master_group,0,  *MASTER_BUFFERS[reg_num]);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pg_reg_list[reg_num]]); 
	    }
	    // Not doing the else here on purpose.. if read on one reg fails , we want to try next and maybe the slave side if all fails
	}
	
	    
  	for(uint32_t reg_num=0;reg_num<NUM_PG_REGS;++reg_num){
	    FAPI_DBG("Reading register name %s on SLAVE side",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    rc=GCR_read(slave_chip_target ,  slave_chip_interface, pg_reg_list[reg_num],  slave_group,0,  *SLAVE_BUFFERS[reg_num]);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pg_reg_list[reg_num]]); 
	    }
	    // Not doing the else here on purpose.. if read on one reg fails , we want to try next and maybe the slave side if all fails
	}
	
        FAPI_SET_HWP_ERROR(lane_rc,IO_FUNCS_EYEOPT_FAIL_RC);
	//Lets do per-lane registers now , will Log and continue instead of wasting buffers and making it complex
	for(uint32_t lane=0;lane<rx_lane_end;++lane){
	    for(uint32_t lane_reg_num=0;lane_reg_num<NUM_PL_REGS;++lane_reg_num){
		if(master_chip_interface!=CP_FABRIC_X0 && pl_reg_list[lane_reg_num] ==ei4_rx_dcd_adj_pl ){
		    continue; // DCD ADJ PL valid only for X bus 
		}
		if(master_chip_interface==CP_FABRIC_X0 && lane_reg_num<5 ){
		    continue; // Only 7,8,9 regs valid on X bus 
		}
		FAPI_DBG("Reading per lane register %s on lane %d",GCR_sub_reg_names[pl_reg_list[lane_reg_num]],lane);
		rc=GCR_read(master_chip_target ,  master_chip_interface, pl_reg_list[lane_reg_num],  master_group,lane, *MASTER_BUFFERS[NUM_PG_REGS+lane_reg_num]);
		if (rc)
		{
		     FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pl_reg_list[lane_reg_num]]); 
		}
		else{
		// we will continue to try other lanes data
		const fapi::Target & CHIP_TARGET= master_chip_target;
		 uint32_t &LANEID=lane;
		   //as per Andrea to save log space 
		   FAPI_ADD_INFO_TO_HWP_ERROR(lane_rc,IO_FUNCS_EYEOPT_FAIL_LANE_MASTER_DATA_RC);
		}
	     }
	}
	

    // Capture SLAVE Side registers 
     rx_lane_end=num_rxlanes_per_group[slave_chip_interface];

	//Lets do per-lane registers now , will Log and continue instead of wasting buffers and making it complex
	for(uint32_t lane=0;lane<rx_lane_end;++lane){
	    for(uint32_t lane_reg_num=0;lane_reg_num<NUM_PL_REGS;++lane_reg_num){
		if(slave_chip_interface!=CP_FABRIC_X0 && pl_reg_list[lane_reg_num] ==ei4_rx_dcd_adj_pl ){
		    continue; // DCD ADJ PL valid only for X bus 
		}
		if(slave_chip_interface==CP_FABRIC_X0 && lane_reg_num<5 ){
		    continue; // Only 7,8,9 regs valid on X bus 
		}
		FAPI_DBG("Reading per lane register %s on lane %d",GCR_sub_reg_names[pl_reg_list[lane_reg_num]],lane);
		rc=GCR_read(slave_chip_target ,  slave_chip_interface, pl_reg_list[lane_reg_num],  slave_group,lane, *SLAVE_BUFFERS[NUM_PG_REGS+lane_reg_num]);
		if (rc)
		{
		     FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pl_reg_list[lane_reg_num]]); 
		}
		else{
		    		// we will continue to try other lanes data
		const fapi::Target & CHIP_TARGET= slave_chip_target;
		 uint32_t &LANEID=lane;
		   //as per Andrea to save log space 
		   FAPI_ADD_INFO_TO_HWP_ERROR(lane_rc,IO_FUNCS_EYEOPT_FAIL_LANE_SLAVE_DATA_RC);
		}
	     }
	}



    return(lane_rc);
}

//FFDC for repair  
//rx_rpr_state rx_static_repair_state_pg
//rx_repair_failed  rx_training_status_pg 
//rx_bad_lane1_gcrmsg rx_bad_lane_enc_gcrmsg_pg
//rx_bad_lane2_gcrmsgrx_bad_lane_enc_gcrmsg_pg

ReturnCode  edi_training::dump_ffdc_repair(const Target&  master_chip_target, io_interface_t  master_chip_interface ,uint32_t master_group, const Target& slave_chip_target ,
											 io_interface_t slave_chip_interface,uint32_t slave_group)
{
    ReturnCode rc;
    ReturnCode lane_rc; // for logging per lane FFDC
    
    const fapi::Target &MASTER_TARGET=master_chip_target;
    const fapi::Target &SLAVE_TARGET=slave_chip_target;
    	const io_interface_t& MASTER_CHIP_INTERFACE = master_chip_interface;
	const uint32_t& MASTER_GROUP = master_group;
	const io_interface_t& SLAVE_CHIP_INTERFACE = slave_chip_interface;
	const uint32_t& SLAVE_GROUP = slave_group;
    
    //FFDC Buffers;
    ecmdDataBufferBase MASTER_RX_STATIC_REPAIR_STATE_PG(16);
    ecmdDataBufferBase MASTER_RX_TRAINING_STATUS_PG(16);
    ecmdDataBufferBase MASTER_RX_BAD_LANE_ENC_GCRMSG_PG(16);
    
    ecmdDataBufferBase SLAVE_RX_STATIC_REPAIR_STATE_PG(16);
    ecmdDataBufferBase SLAVE_RX_TRAINING_STATUS_PG(16);
    ecmdDataBufferBase SLAVE_RX_BAD_LANE_ENC_GCRMSG_PG(16);


    
    const uint32_t NUM_PG_REGS=3;
    
    const GCR_sub_registers pg_reg_list[NUM_PG_REGS]={rx_static_repair_state_pg,rx_training_status_pg,rx_bad_lane_enc_gcrmsg_pg};
    
    
    ecmdDataBufferBase *MASTER_BUFFERS[NUM_PG_REGS]= {
						    &MASTER_RX_STATIC_REPAIR_STATE_PG,
						    &MASTER_RX_TRAINING_STATUS_PG,
						    &MASTER_RX_BAD_LANE_ENC_GCRMSG_PG,
					};
     
       
     ecmdDataBufferBase *SLAVE_BUFFERS[NUM_PG_REGS]= {
						    &SLAVE_RX_STATIC_REPAIR_STATE_PG,
						    &SLAVE_RX_TRAINING_STATUS_PG,
						    &SLAVE_RX_BAD_LANE_ENC_GCRMSG_PG,
					};
     
     


    FAPI_DBG("dump_ffdc_repair function entered \n");

    // Capture MASTER Side registers 


	for(uint32_t reg_num=0;reg_num<NUM_PG_REGS;++reg_num){
	    FAPI_DBG("Reading register name %s on MASTER side",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    rc=GCR_read(master_chip_target ,  master_chip_interface, pg_reg_list[reg_num],  master_group,0,  *MASTER_BUFFERS[reg_num]);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pg_reg_list[reg_num]]); 
	    }
	    // Not doing the else here on purpose.. if read on one reg fails , we want to try next and maybe the slave side if all fails
	} 

  	for(uint32_t reg_num=0;reg_num<NUM_PG_REGS;++reg_num){
	    FAPI_DBG("Reading register name %s on SLAVE side",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    rc=GCR_read(slave_chip_target ,  slave_chip_interface, pg_reg_list[reg_num],  slave_group,0,  *SLAVE_BUFFERS[reg_num]);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pg_reg_list[reg_num]]); 
	    }
	    // Not doing the else here on purpose.. if read on one reg fails , we want to try next and maybe the slave side if all fails
	}

       FAPI_SET_HWP_ERROR(rc,IO_FUNCS_REPAIR_FAIL_RC);
    return(rc);
}


ReturnCode  edi_training::dump_ffdc_func(const Target&  master_chip_target, io_interface_t  master_chip_interface ,uint32_t master_group, const Target& slave_chip_target ,
											 io_interface_t slave_chip_interface,uint32_t slave_group)
{
    ReturnCode rc;
    ReturnCode lane_rc; // for logging per lane FFDC
    
    const fapi::Target &MASTER_TARGET=master_chip_target;
    const fapi::Target &SLAVE_TARGET=slave_chip_target;
    	const io_interface_t& MASTER_CHIP_INTERFACE = master_chip_interface;
	const uint32_t& MASTER_GROUP = master_group;
	const io_interface_t& SLAVE_CHIP_INTERFACE = slave_chip_interface;
	const uint32_t& SLAVE_GROUP = slave_group;
    
    //FFDC Buffers;
    ecmdDataBufferBase MASTER_RX_FUNC_STATE_PG(16);
    ecmdDataBufferBase MASTER_RX_TRAINING_STATUS_PG(16);
    
    ecmdDataBufferBase SLAVE_RX_FUNC_STATE_PG(16);
    ecmdDataBufferBase SLAVE_RX_TRAINING_STATUS_PG(16);


    
    const uint32_t NUM_PG_REGS=2;
    
    const GCR_sub_registers pg_reg_list[NUM_PG_REGS]={rx_func_state_pg,rx_training_status_pg};
    
    
    ecmdDataBufferBase *MASTER_BUFFERS[NUM_PG_REGS]= {
						    &MASTER_RX_FUNC_STATE_PG,
						    &MASTER_RX_TRAINING_STATUS_PG,
					};
     
       
     ecmdDataBufferBase *SLAVE_BUFFERS[NUM_PG_REGS]= {
						    &SLAVE_RX_FUNC_STATE_PG,
						    &SLAVE_RX_TRAINING_STATUS_PG,
					};
     
     


    FAPI_DBG("dump_ffdc_func function entered \n");

    // Capture MASTER Side registers 


	for(uint32_t reg_num=0;reg_num<NUM_PG_REGS;++reg_num){
	    FAPI_DBG("Reading register name %s on MASTER side",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    rc=GCR_read(master_chip_target ,  master_chip_interface, pg_reg_list[reg_num],  master_group,0,  *MASTER_BUFFERS[reg_num]);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pg_reg_list[reg_num]]); 
	    }
	    // Not doing the else here on purpose.. if read on one reg fails , we want to try next and maybe the slave side if all fails
	} 

  	for(uint32_t reg_num=0;reg_num<NUM_PG_REGS;++reg_num){
	    FAPI_DBG("Reading register name %s on SLAVE side",GCR_sub_reg_names[pg_reg_list[reg_num]]);
	    rc=GCR_read(slave_chip_target ,  slave_chip_interface, pg_reg_list[reg_num],  slave_group,0,  *SLAVE_BUFFERS[reg_num]);
	    if (rc)
	    {
		 FAPI_ERR("io_run_training : Error Reading %s",GCR_sub_reg_names[pg_reg_list[reg_num]]); 
	    }
	    // Not doing the else here on purpose.. if read on one reg fails , we want to try next and maybe the slave side if all fails
	}

       FAPI_SET_HWP_ERROR(rc,IO_FUNCS_FUNC_FAIL_RC);
    return(rc);
}

}
