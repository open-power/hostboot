/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_funcs.C $                    */
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
// $Id: io_funcs.C,v 1.19 2014/02/11 05:46:59 varkeykv Exp $
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
			}
		    }
		 }
		 else{
		     rc=training_function_status(master_target  ,  master_interface,master_group,   slave_target  ,  slave_interface,slave_group);
			if(!rc.ok()){
			    FAPI_ERR("io_run_training : Failed Training");
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
				       FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_FAIL_WIRETEST_RC);
                                       wire_test_status =  FAILED ;
                                       rx_wderf_failed[WIRE_TEST]=true;
                                      // Run First FAILED Data Capture for Wire Test for FAILED bus
                                       dump_ffdc_wiretest(master_chip_target, master_chip_interface , master_group, slave_chip_target ,  slave_chip_interface,slave_group);
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
                                            FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_FAIL_DESKEW_RC);
                                            desckew_status =  FAILED ;
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
                                             FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_FAIL_EYE_OPT_RC);
                                             rx_wderf_failed[EYE_OPT]=true;
                                             eye_opt_status =  FAILED ;
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
					      FAPI_SET_HWP_ERROR(rc,   IO_RUN_TRAINING_FAIL_REPAIR_RC);
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
                                             FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_FAIL_FUNC_MODE_RC);
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
			    FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_WIRETEST_TIMEOUT_RC);
			    }
			    else if (desckew_selected && desckew_status == RUNNING)
			    {
			    FAPI_ERR("io_run_training: deskew timeout");
			    FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_DESKEW_TIMEOUT_RC);
			    }
			    else if (repair_selected && repair_status == RUNNING)
			    {
			    FAPI_ERR("io_run_training: repair timeout");
			    FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_REPAIR_TIMEOUT_RC);
			    }
			    else if (eye_opt_selected && eye_opt_status == RUNNING)
			    {
			    FAPI_ERR("io_run_training: eyeopt timeout");
			    FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_EYE_OPT_TIMEOUT_RC);
			    }
			    else
			    {
			    FAPI_ERR("io_run_training: func timeout");
			    FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_FUNC_MODE_TIMEOUT_RC);
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
ReturnCode  edi_training::dump_ffdc_wiretest(const Target&  master_chip_target, io_interface_t  master_chip_interface ,uint32_t master_group, const Target& slave_chip_target ,
											 io_interface_t slave_chip_interface,uint32_t slave_group)
{
   ReturnCode rc;

    ecmdDataBufferBase  master_lane_bad_vec_0_15_data(16);
    ecmdDataBufferBase  master_lane_bad_vec_16_31_data(16);
    ecmdDataBufferBase  slave_lane_bad_vec_0_15_data(16);
    ecmdDataBufferBase  slave_lane_bad_vec_16_31_data(16);
    
    ecmdDataBufferBase  master_lane_bad_data(16);
    
    FAPI_DBG("dump_ffdc_wiretest function entered \n");

    // DO MASTER HERE
    // Read  rx_lane_bad_vec_0_15_pg  &  rx_lane_bad_vec_16_32_pg
    if(master_chip_interface==CP_FABRIC_X0)
    {
	 rc=GCR_read(master_chip_target ,  master_chip_interface, ei4_rx_lane_bad_vec_0_15_pg,  master_group,0,  master_lane_bad_vec_0_15_data);
    }
    else
    {
	 rc=GCR_read(master_chip_target ,  master_chip_interface, rx_lane_bad_vec_0_15_pg,  master_group,0,  master_lane_bad_vec_0_15_data);
    }
    if (rc)
    {
	 FAPI_ERR("io_run_training : Error Reading rx_lane_bad_vec_0_15"); 
    }
    //avoiding else on purpose.. I want to try reading the second registe if first one on master fails
    if(master_chip_interface==CP_FABRIC_X0)
    {
	 rc=GCR_read(master_chip_target , master_chip_interface,  ei4_rx_lane_bad_vec_16_31_pg, master_group,0,  master_lane_bad_vec_16_31_data);
    }
    else
    {
	 rc=GCR_read(master_chip_target , master_chip_interface,  rx_lane_bad_vec_16_31_pg, master_group,0,  master_lane_bad_vec_16_31_data);
    }
    if (rc) {
        FAPI_ERR("io_run_training : Error Reading rx_lane_bad_vec_16_31");
    }
    // Not doing the else here on purpose.. if read on master fails .. we want to try reading slave side 
    
    // DO SLAVE HERE
    if(slave_chip_interface==CP_FABRIC_X0)
    {
	rc=GCR_read(slave_chip_target , slave_chip_interface, ei4_rx_lane_bad_vec_0_15_pg, slave_group,0, slave_lane_bad_vec_0_15_data);
    }
    else
    {
	rc=GCR_read(slave_chip_target , slave_chip_interface, rx_lane_bad_vec_0_15_pg, slave_group,0, slave_lane_bad_vec_0_15_data);
    }
    if (rc)
    {
        FAPI_ERR("io_run_training : Error Reading rx_lane_bad_vec_0_15 on slave chip");
        
    }
    if(slave_chip_interface==CP_FABRIC_X0)
    {
	rc=GCR_read(slave_chip_target , slave_chip_interface, ei4_rx_lane_bad_vec_16_31_pg, slave_group,0, slave_lane_bad_vec_16_31_data);
    }
    else
    {
	rc=GCR_read(slave_chip_target , slave_chip_interface, rx_lane_bad_vec_16_31_pg, slave_group,0, slave_lane_bad_vec_16_31_data);
    }
    if (rc) {
        FAPI_ERR("io_run_training : Error Reading rx_lane_bad_vec_16_31 on slave chip");
    }
    return(rc);
}



}
