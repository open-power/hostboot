/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_run_training.C $             */
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
// $Id: io_run_training.C,v 1.32 2013/03/26 15:04:24 varkeykv Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : io_run_training.C
// *! TITLE                : 
// *! DESCRIPTION          : IO Wiretest,Deskew ,Eye Opt training procedure
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Varghese, Varkey         Email: varkey.kv@in.ibm.com
// *! BACKUP NAME          : Janani Swaminathan      Email:  jaswamin@in.ibm.com     
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//  1.27   |jaswamin|01/28/13|Changed fatal errors to warning prints to allow training to continue
//   1.0   |varkeykv|09/27/11|Initial check in . Have to modify targets once bus target is defined and available.Not tested in any way other than in unit SIM IOTK
//   1.1   |varkeykv|11/16/11|Fixed header files & dependencies
//------------------------------------------------------------------------------
#include <fapi.H>
#include "io_run_training.H"
#include "io_funcs.H"

extern "C" {
     using namespace fapi;
// For clearing the FIR mask , used by io run training 
ReturnCode clear_fir_mask_reg(const Target &i_target,fir_io_interface_t i_chip_interface){
    
    ReturnCode rc;
    uint64_t  scom_address64=0;
    ecmdDataBufferBase putscom_data64(64),temp(64);
    FAPI_INF("io_run_training:In the Clear FIR MASK register function ");
    //get the 64 bit data
    temp.setDoubleWord(0,fir_clear_mask_reg_addr[i_chip_interface]);
    scom_address64=temp.getDoubleWord(0);
    
    //do the putscom
    rc=fapiPutScom( i_target, scom_address64, putscom_data64);
    
    return(rc);
    
}

// FIR Workaround Code -- Pre Training Section - HW205368 - procedure from Rob /Pete
ReturnCode fir_workaround_pre_training(const Target& master_target,  io_interface_t master_interface,uint32_t master_group, const Target&  slave_target,  io_interface_t  slave_interface,uint32_t slave_group,
                                       ecmdDataBufferBase *slave_data_one_old,ecmdDataBufferBase *slave_data_two_old,ecmdDataBufferBase *master_data_one_old,ecmdDataBufferBase *master_data_two_old)
{
     ReturnCode rc;
     	//Start - Workaround Pre Training Section - HW205368 - procedure from Rob /Pete

	    uint8_t max_group=1;
	    
	    if(master_interface==CP_FABRIC_X0){
		max_group=4;
	    }

	    // Take backup of slave bad lane data restored by FW prior to training
	    FAPI_DBG("io_run_training: Saving Bad lane information for HW workaround ");
	    if(master_interface==CP_FABRIC_X0){
		for (int current_group = 0 ; current_group < max_group; current_group++){
			rc = GCR_read( slave_target, slave_interface, rx_lane_bad_vec_0_15_pg, current_group,  0,   slave_data_one_old[current_group]);
			if(rc){return rc;}
			rc = GCR_read( slave_target, slave_interface, rx_lane_bad_vec_16_31_pg, current_group,  0,  slave_data_two_old[current_group]);
			if(rc){return rc;}
		}
		//Take backup of master bad lane data restored by FW prior to training 
		for (int current_group = 0 ; current_group < max_group; current_group++){
			rc = GCR_read( master_target, master_interface, rx_lane_bad_vec_0_15_pg, current_group,  0,   master_data_one_old[current_group]);
			if(rc){return rc;}
			rc = GCR_read( master_target, master_interface, rx_lane_bad_vec_16_31_pg, current_group,  0,  master_data_two_old[current_group]);
			if(rc){return rc;}
		}
	    }else{
			rc = GCR_read( slave_target, slave_interface, rx_lane_bad_vec_0_15_pg, slave_group,  0,   slave_data_one_old[0]);
			if(rc){return rc;}
			rc = GCR_read( slave_target, slave_interface, rx_lane_bad_vec_16_31_pg, slave_group,  0,  slave_data_two_old[0]);
			if(rc){return rc;}
		//Take backup of master bad lane data restored by FW prior to training 
			rc = GCR_read( master_target, master_interface, rx_lane_bad_vec_0_15_pg, master_group,  0,   master_data_one_old[0]);
			if(rc){return rc;}
			rc = GCR_read( master_target, master_interface, rx_lane_bad_vec_16_31_pg, master_group,  0,  master_data_two_old[0]);
			if(rc){return rc;}
	    }
	// End - Workaround HW205368
        return(rc);
}

ReturnCode fir_workaround_post_training(const Target& master_target,  io_interface_t master_interface,uint32_t master_group, const Target&  slave_target,  io_interface_t  slave_interface,uint32_t slave_group,
                                        ecmdDataBufferBase *slave_data_one_old,ecmdDataBufferBase *slave_data_two_old,ecmdDataBufferBase *master_data_one_old,ecmdDataBufferBase *master_data_two_old)
{
     ReturnCode rc;
          //These buffers will store new bad lane info after training 
     ecmdDataBufferBase slave_data_one_new[4];
     ecmdDataBufferBase slave_data_two_new[4];
     ecmdDataBufferBase master_data_one_new[4];
     ecmdDataBufferBase master_data_two_new[4];
     fir_io_interface_t fir_master_interface=FIR_CP_IOMC0_P0;
     fir_io_interface_t fir_slave_interface=FIR_CEN_DMI;
     
     uint8_t max_group=1;
	    
     if(master_interface==CP_FABRIC_X0){
         max_group=4;
     }

	FAPI_DBG("io_run_training : Starting post training HW workaround ");
	// Start post training part of Workaround - HW205368 - procedure from Rob /Pete
	    // Read slave side bad lane data after training
	    if(master_interface==CP_FABRIC_X0){
		for (int current_group = 0 ; current_group < max_group; current_group++){
			rc = GCR_read( slave_target, slave_interface, rx_lane_bad_vec_0_15_pg, current_group,  0,   slave_data_one_new[current_group]);
			if(rc){return rc;}
			rc = GCR_read( slave_target, slave_interface, rx_lane_bad_vec_16_31_pg, current_group,  0,  slave_data_two_new[current_group]);
			if(rc){return rc;}
		}
		//Take backup of master bad lane data restored by FW prior to training 
		for (int current_group = 0 ; current_group < max_group; current_group++){
			rc = GCR_read( master_target, master_interface, rx_lane_bad_vec_0_15_pg, current_group,  0,   master_data_one_new[current_group]);
			if(rc){return rc;}
			rc = GCR_read( master_target, master_interface, rx_lane_bad_vec_16_31_pg, current_group,  0,  master_data_two_new[current_group]);
			if(rc){return rc;}
		}
	    }else{
			rc = GCR_read( slave_target, slave_interface, rx_lane_bad_vec_0_15_pg, slave_group,  0,   slave_data_one_new[0]);
			if(rc){return rc;}
			rc = GCR_read( slave_target, slave_interface, rx_lane_bad_vec_16_31_pg, slave_group,  0,  slave_data_two_new[0]);
			if(rc){return rc;}
		//Take backup of master bad lane data restored by FW prior to training 
			rc = GCR_read( master_target, master_interface, rx_lane_bad_vec_0_15_pg, master_group,  0,   master_data_one_new[0]);
			if(rc){return rc;}
			rc = GCR_read( master_target, master_interface, rx_lane_bad_vec_16_31_pg, master_group,  0,  master_data_two_new[0]);
			if(rc){return rc;}
	    }
	    // Now we will compare the old and new bad lane data and take appropriate action
	    if(master_interface==CP_FABRIC_X0)
	    {
		for (int current_group = 0 ; current_group < max_group; current_group++){
		   if(slave_data_one_new[current_group]==slave_data_one_old[current_group] && slave_data_two_new[current_group]==slave_data_two_old[current_group]  ){
		       // If old and new data is same , no need to present FIRs to PRD
		       if( !( slave_data_one_new[current_group].isBitClear(0,16) && slave_data_two_new[current_group].isBitClear(0,16) )){
			 FAPI_DBG("io_run_training : Clear invalid FIRs on the slave side ");
			// If all bad lane info is clear in new data then no need to clear ,this is a 0==0 case of both old and new empty vectors
			    io_clear_firs(slave_target);
		       }
		   }
		   if(master_data_one_new[current_group]==master_data_one_old[current_group] && master_data_two_new[current_group]==master_data_two_old[current_group]  ){
		       // If old and new data is same , no need to present FIRs to PRD
		         if( !( master_data_one_new[current_group].isBitClear(0,16) && master_data_two_new[current_group].isBitClear(0,16) )){
			    FAPI_DBG("io_run_training : Clear invalid FIRs on the master side ");
			// If all bad lane info is clear in new data then no need to clear ,this is a 0==0 case of both old and new empty vectors
			    io_clear_firs(master_target);
		       }
		   }
		}
	    }
	    else
	    {
		if(slave_data_one_new[0]==slave_data_one_old[0] && slave_data_two_new[0]==slave_data_two_old[0]  ){
		       // If old and new data is same , no need to present FIRs to PRD
		       	if( !( slave_data_one_new[0].isBitClear(0,16) && slave_data_two_new[0].isBitClear(0,16) )){
			     FAPI_DBG("io_run_training : Clear invalid FIRs on the slave side ");
			// If all bad lane info is clear in new data then no need to clear ,this is a 0==0 case of both old and new empty vectors
			    io_clear_firs(slave_target);
		       }
		   }
		   if(master_data_one_new[0]==master_data_one_old[0] && master_data_two_new[0]==master_data_two_old[0]  ){
		       // If old and new data is same , no need to present FIRs to PRD
		        if( !( master_data_one_new[0].isBitClear(0,16) && master_data_two_new[0].isBitClear(0,16) )){
			    FAPI_DBG("io_run_training : Clear invalid FIRs on the master side ");
			// If all bad lane info is clear in new data then no need to clear ,this is a 0==0 case of both old and new empty vectors
			    io_clear_firs(master_target);
		       }
		   }
	    }

	// END post training part of Workaround - HW205368 - procedure from Rob /Pete
	
	//Translate some enums in training header to fir enums 
	if(master_interface==CP_FABRIC_X0){
	    fir_master_interface=FIR_CP_FABRIC_X0;
	}
	else if(master_interface==CP_IOMC0_P0){
	    fir_master_interface= FIR_CP_IOMC0_P0;
	}
	else if(master_interface== CEN_DMI){
	    fir_master_interface=FIR_CEN_DMI;
	}
	else if(master_interface== CP_FABRIC_A0){
	    fir_master_interface=FIR_CP_FABRIC_A0;
	}
	if(slave_interface==CP_FABRIC_X0){
	    fir_slave_interface=FIR_CP_FABRIC_X0;
	}
	else if(slave_interface==CP_IOMC0_P0){
	    fir_slave_interface= FIR_CP_IOMC0_P0;
	}
	else if(slave_interface== CEN_DMI){
	    fir_slave_interface=FIR_CEN_DMI;
	}
	else if(slave_interface== CP_FABRIC_A0){
	    fir_slave_interface=FIR_CP_FABRIC_A0;
	}
	FAPI_DBG("io_run_training : Clearing FIR masks now");
	//Finally Unmask the LFIR to let PRD take action post training
	clear_fir_mask_reg(slave_target,fir_slave_interface);
	clear_fir_mask_reg(master_target,fir_master_interface);
        return(rc);
}

// These functions work on a pair of targets. One is the master side of the bus interface, the other the slave side. For eg; in EDI(DMI2)PU is the master and Centaur is the slave
// In EI4 both sides have pu targets . After the talk with Dean , my understanding is that targets are configured down upto the endpoints of a particular bus. eg; pu 0 A0 --> pu 1 A3 could be a combination on EI4
// In a EDI(DMI) bus the targets are considered to be one pu and one centaur pair . The overall code is same for EDI and EI4 and the run_training function handles both bus types ( X ,A or MC ) . 
ReturnCode io_run_training(const Target &master_target,const Target &slave_target){
     ReturnCode rc;
     io_interface_t master_interface,slave_interface;
     uint32_t master_group=0;
     uint32_t slave_group=0;
     edi_training init;
     // Workaround - HW 220654 -- Need to split WDERF into WDE + RF
     edi_training init1(SELECTED,SELECTED,SELECTED, NOT_RUNNING, NOT_RUNNING); // Run WDE first
     edi_training init2( NOT_RUNNING, NOT_RUNNING, NOT_RUNNING,SELECTED,SELECTED); // Run RF next
     bool is_master=false;
     
     //FIR workaround buffers
     //These buffers will store old bad lane info that was restored prior to training 
     ecmdDataBufferBase slave_data_one_old[4];
     ecmdDataBufferBase slave_data_two_old[4];
     ecmdDataBufferBase master_data_one_old[4];
     ecmdDataBufferBase master_data_two_old[4];

     
     // This is a DMI/MC bus 
     if( (master_target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET )&& (slave_target.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP)){
          FAPI_DBG("This is a DMI bus using base DMI scom address");
          master_interface=CP_IOMC0_P0; // base scom for MC bus
          slave_interface=CEN_DMI; // Centaur scom base
          master_group=3; // Design requires us to do this as per scom map and layout
          slave_group=0;
          fir_workaround_pre_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                      slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
          // Workaround - HW 220654 -- Need to split WDERF into WDE + RF due to sync problem
          rc=init1.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
          if(!rc.ok()){
               return rc;
          }
          rc=init2.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
          fir_workaround_post_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                       slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
     }
     //This is an X Bus
     else if( (master_target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT  )&& (slave_target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT )){
          FAPI_DBG("This is a X Bus training invocation");
          master_interface=CP_FABRIC_X0; // base scom for X bus
          slave_interface=CP_FABRIC_X0; // base scom for X bus
          master_group=0; // Design requires us to do this as per scom map and layout
          slave_group=0;
          rc=init.isChipMaster(master_target,master_interface,master_group,is_master);
          if(rc.ok()){
               if(!is_master){
                     //Swap master and slave targets !!
                     FAPI_DBG("X Bus ..target swap performed");
                     fir_workaround_pre_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                 slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
                    rc=init1.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                    if(rc) return rc;
                    rc=init2.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                    fir_workaround_post_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                 slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
	       }
               else{
                    fir_workaround_pre_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
                    rc=init1.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                    if(rc) return rc;
                    rc=init2.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                    fir_workaround_post_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                 slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
               }
          }
     }
     //This is an A Bus
     else if( (master_target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT )&& (slave_target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT)){
          FAPI_DBG("This is an A Bus training invocation");
          master_interface=CP_FABRIC_A0; // base scom for A bus , assume translation to A1 by PLAT 
          slave_interface=CP_FABRIC_A0; //base scom for A bus
          master_group=0; // Design requires us to do this as per scom map and layout
          slave_group=0;
          rc=init.isChipMaster(master_target,master_interface,master_group,is_master);
          if(rc.ok()){
               if(!is_master)
               {
                    FAPI_DBG("A Bus ..target swap performed");
                    fir_workaround_pre_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
                    rc=init1.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                    if(rc) return rc;
                    rc=init2.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                    fir_workaround_post_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                 slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
               }
               else
               {
                    fir_workaround_pre_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
                    rc=init1.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                    if(rc) return rc;
                    rc=init2.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                    fir_workaround_post_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                 slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
               }
          }
     }
     else{
          FAPI_ERR("Invalid io_run_training HWP invocation . Pair of targets dont belong to DMI/X/A instances");
          FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_INVALID_INVOCATION_RC);
     }
     return rc;
}



} // extern 
