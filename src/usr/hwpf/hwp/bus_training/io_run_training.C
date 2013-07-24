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
// $Id: io_run_training.C,v 1.40 2013/06/20 06:16:29 varkeykv Exp $
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
    uint32_t rc_ecmd = 0;
    uint8_t chip_unit = 0;
    uint8_t link_fir_unmask_data = 0x8F;
    ecmdDataBufferBase data(64);
    FAPI_INF("io_run_training:In the Clear FIR MASK register function ");

    do
    {
        // initialize mask to all 1s
        rc_ecmd |= data.invert();

        // set FIR mask appropriately based on interface type / link being trained
    	if ((i_chip_interface == FIR_CP_FABRIC_X0) ||
    	    (i_chip_interface == FIR_CP_FABRIC_A0) ||
            (i_chip_interface == FIR_CP_IOMC0_P0))
        {
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS,
                               &i_target,
                               chip_unit);
            if (!rc.ok())
            {
                FAPI_ERR("Error retreiving MCS chiplet number!");
                break;
            }

            // swizzle to DMI number
            if (i_chip_interface == FIR_CP_IOMC0_P0)
            {
                chip_unit = chip_unit % 4;
                if (chip_unit == 3)
                {
                    chip_unit = 2;
                }
                else if (chip_unit == 2)
                {
                    chip_unit = 3;
                }
            }
        }
        else if (i_chip_interface == FIR_CEN_DMI)
        {
            chip_unit = 0;
    	}

        rc_ecmd |= data.insert(link_fir_unmask_data,
                               8+(8*chip_unit),
                               8);

        // check buffer manipulation return codes
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%X setting up FIR mask data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // use FIR AND mask register to un-mask selected bits
        rc = fapiPutScom(i_target, fir_clear_mask_reg_addr[i_chip_interface], data);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing FIR mask register (=%08X)!",
                     fir_clear_mask_reg_addr[i_chip_interface]);
            break;
        }

    } while(0);

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
	rc=clear_fir_mask_reg(slave_target,fir_slave_interface);
        if(rc) return rc;
	rc=clear_fir_mask_reg(master_target,fir_master_interface);
        return(rc);
}

// //HW249235 --For DLL workaround
// This function will check DLL status on slave and slave side . If any DLL has failed it will update to the next valid
// DLL value . 3,4,5,6 are valid values that we are given to select.
// This will continue until we run out of valid DLL reg selects or when the DLL cal passes

ReturnCode check_dll_status_and_modify(const Target &master_target, io_interface_t master_interface,const Target &slave_target,
                                       io_interface_t slave_interface,bool dll_master_array[16],
                                       bool dll_slave_array[16],bool &dll_workaround_done,bool &dll_workaround_fail)
{
     ReturnCode rc;
     uint32_t rc_ecmd=0;
     ecmdDataBufferBase dll_reg(16),set_bits(16),clear_bits(16),temp_bits(16);
     const uint16_t dll_vals[]={2,3,4,5,6,7};
     uint16_t bits=0;
     uint16_t dll_value=0;
     bool found_dll_master=false;
     bool found_dll_slave=false;
     bool found_dll_master_groups=false;
     bool found_dll_slave_groups=false;
     //bool dump_ffdc=false;
     
     bits=ei4_rx_dll_vreg_ref_sel_clear;
     rc_ecmd=clear_bits.insert(bits,0,16);
     
     if(rc_ecmd)
     {
           FAPI_ERR("Failed buffer intialization in DLL workaround function \n");
           rc.setEcmdError(rc_ecmd);
     }
     
     FAPI_INF("DLL WORKAROUND CODE executing");
     // First we will populate current DLL values into std::vector
      for (int current_group = 0 ; current_group < 4; current_group++){
            // slave side operations
          rc = GCR_read( slave_target, slave_interface,  ei4_rx_dll_analog_tweaks_pg, current_group,  0,   dll_reg);
          rc_ecmd|=dll_reg.extract( &dll_value,   4, 3 );
          if(rc_ecmd)
          {
                FAPI_ERR("Failed buffer intialization in DLL workaround function \n");
                rc.setEcmdError(rc_ecmd);
          }
          
          FAPI_DBG("Extracted DLL value is %d",dll_value);
          dll_value=dll_value>>13;
          FAPI_DBG("DLL value for %d clock group is %d on slave side",current_group,dll_value);
          if(rc){return rc;}
          
          if(dll_value>=dll_vals[0] && dll_value<=dll_vals[5]){
                dll_slave_array[current_group*6+(dll_value-dll_vals[0])]=true;
          }
          else{
               FAPI_ERR("DLL Vreg Cal sel value out of bounds for workaround !!");
          }
          
          rc = GCR_read( slave_target, slave_interface, ei4_rx_dll_cal_cntl_pg, current_group,  0,   dll_reg);
          if(rc){return rc;}
          if(dll_reg.isBitSet(1) || dll_reg.isBitSet(2) || dll_reg.isBitSet(9) || dll_reg.isBitSet(10)){
               // Some DLL error is present , lets push this Clock group ref cal value to the next untried value
               FAPI_DBG("DLL error detected on clock group %d on slave target",current_group);

                 rc=GCR_write(slave_target, slave_interface,  ei4_rx_dll_cal_cntl_pg, current_group,0,   temp_bits, temp_bits,1,1);
                  rc=GCR_write(master_target, master_interface,  ei4_rx_dll_cal_cntl_pg, current_group,0,   temp_bits, temp_bits,1,1);
               for(int dll_valid=0;dll_valid<6;++dll_valid){
                    if(dll_slave_array[current_group*6 + dll_valid]==false){
                         // Now set the DLL vref cal sel reg value to the next valid untried value
                         dll_value=dll_vals[dll_valid];
                         FAPI_DBG("DLL value to be written is %d dll_valid=%d current_group=%d",dll_value,dll_valid,current_group);
                         rc=GCR_read(slave_target , slave_interface,  ei4_rx_dll_analog_tweaks_pg,  current_group,0, set_bits);
                         rc_ecmd=set_bits.insert(dll_value,4,3,13);
                         if(rc_ecmd)
                         {
                               FAPI_ERR("Failed buffer insertion in DLL workaround function \n");
                               rc.setEcmdError(rc_ecmd);
                         }
                         rc=GCR_write(slave_target, slave_interface,  ei4_rx_dll_analog_tweaks_pg, current_group,0,   set_bits, clear_bits);
                         found_dll_slave=true;
                         dll_slave_array[current_group*6 + dll_valid]=true;
                         break;
                    }
               }
               if(found_dll_slave==false){
                    FAPI_ERR("No valid DLL reg value left to search.. DLL cal on slave of this channel has failed ");
                    // Now do FFDC call outs
                    //dump_ffdc=true;
                    dll_workaround_fail=true;
               }
          }
          else{
               FAPI_DBG("NO DLL error detected on clock group %d on slave target",current_group);
          }
  
     if(!found_dll_slave){  // If slave has DLL failure , Master status is invalid - John G 
          // master SIDE operations 
          // Push current DLL value into the std::vector
          dll_reg.flushTo0();
          rc = GCR_read( master_target, master_interface,  ei4_rx_dll_analog_tweaks_pg, current_group,  0,   dll_reg);
          rc_ecmd|=dll_reg.extract( &dll_value,   4, 3 );
          if(rc_ecmd)
          {
                FAPI_ERR("Failed buffer intialization in DLL workaround function \n");
                rc.setEcmdError(rc_ecmd);
          }
          
          FAPI_DBG("Extracted DLL value is %d",dll_value);
          dll_value=dll_value>>13;
          FAPI_DBG("DLL value for %d clock group is %d on master side",current_group,dll_value);
          if(rc){return rc;}
          if(dll_value>=dll_vals[0] && dll_value<=dll_vals[5]){
                dll_master_array[current_group*6+(dll_value-dll_vals[0])]=true;
          }
          else{
               FAPI_ERR("DLL Vreg Cal sel value out of bounds for workaround !!");
          }
          rc = GCR_read( master_target, master_interface, ei4_rx_dll_cal_cntl_pg, current_group,  0,   dll_reg);
          if(rc){return rc;}
          if(dll_reg.isBitSet(1) || dll_reg.isBitSet(2) || dll_reg.isBitSet(9) || dll_reg.isBitSet(10)){
               // Some DLL error is present , lets push this Clock group to the next untried value
               FAPI_DBG("DLL error detected on clock group %d on master target",current_group);
                 rc=GCR_write(slave_target, slave_interface,  ei4_rx_dll_cal_cntl_pg, current_group,0,   temp_bits, temp_bits,1,1);
                rc=GCR_write(master_target, master_interface,  ei4_rx_dll_cal_cntl_pg, current_group,0,   temp_bits, temp_bits,1,1);
                
               for(int dll_valid=0;dll_valid<6;++dll_valid){
                    if(dll_master_array[current_group*6 + dll_valid]==false){
                         // Now set the DLL vref cal sel reg value to the next valid untried value
                         dll_value=dll_vals[dll_valid];
                         FAPI_DBG("DLL value to be written is %d",dll_value);
                         rc=GCR_read(master_target , master_interface,  ei4_rx_dll_analog_tweaks_pg,  current_group,0, set_bits);
                         rc_ecmd=set_bits.insert(dll_value,4,3,13);
                         if(rc_ecmd)
                         {
                               FAPI_ERR("Failed buffer insertion in DLL workaround function \n");
                               rc.setEcmdError(rc_ecmd);
                         }
                         rc=GCR_write(master_target, master_interface,  ei4_rx_dll_analog_tweaks_pg, current_group,0,   set_bits, clear_bits);
                         found_dll_master=true;
                         dll_master_array[current_group*6 + dll_valid]=true;
                         break;
                    }
               }
               if(found_dll_master==false){
                    FAPI_ERR("No valid DLL reg value left to search.. DLL cal on master of this channel has failed ");
                    //dump_ffdc=true;
               }
          }
          else{
               FAPI_DBG("NO DLL error detected on clock group %d on master target",current_group);
          }
          
     }
                if(found_dll_master){
               found_dll_master_groups=true;
          }
          if(found_dll_slave){
               found_dll_slave_groups=true;
          }
      }
     
     if(found_dll_master_groups || found_dll_slave_groups ) {
          // at least one clock group on a slave or slave had a DLL fail and valid values to try so we will ask wrapper to continue the
          // workaround invocations
          FAPI_DBG("One setting failed on master or slave ");
          dll_workaround_done=false;
     }
     else{
          // No DLL fail or no Vreg sel values left to try out so we are done 
          dll_workaround_done=true;
          FAPI_DBG("DLL Workaround done in checker function");
          //if(dump_ffdc){
          //     rc=edi_training::dump_dll_ffdc(master_target,master_interface,slave_target,slave_interface);
          //}
     }

     
     return rc;
}

ReturnCode set_tx_drv_pattern(const Target &master_target, io_interface_t master_interface,uint32_t master_group,const Target &slave_target,
                              io_interface_t slave_interface,uint32_t slave_group)
{
     ReturnCode rc;
     uint32_t rc_ecmd=0;
     // For DLL shmoo workaround 
     ecmdDataBufferBase set_bits(16),clear_bits(16);
     uint16_t bits=0;
     
     FAPI_DBG("DLL workaround : Setting TX DRV pattern back to 0000 before restarting training on X bus ");
     // Clear Clk pattern
     bits=ei4_tx_drv_data_pattern_gcrmsg_clear;
     rc_ecmd=clear_bits.insert(bits,0,16);
     if(rc_ecmd)
     {
           FAPI_ERR("Failed buffer intialization in DLL workaround function \n");
           rc.setEcmdError(rc_ecmd);
     }
     rc=GCR_write(slave_target, slave_interface,ei4_tx_data_cntl_gcrmsg_pl  , 15,31,   set_bits, clear_bits,1,1);
     rc=GCR_write(master_target, master_interface,ei4_tx_data_cntl_gcrmsg_pl , 15,31,   set_bits, clear_bits,1,1);
     //Clear Data pattern 
     bits=ei4_tx_drv_clk_pattern_gcrmsg_clear;
     rc_ecmd=clear_bits.insert(bits,0,16);
     if(rc_ecmd)
     {
           FAPI_ERR("Failed buffer intialization in DLL workaround function \n");
           rc.setEcmdError(rc_ecmd);
     }
     rc=GCR_write(slave_target, slave_interface, ei4_tx_clk_cntl_gcrmsg_pg  , 15,0,   set_bits, clear_bits,1,1);
     rc=GCR_write(master_target, master_interface, ei4_tx_clk_cntl_gcrmsg_pg , 15,0,   set_bits, clear_bits,1,1);
    
     // According to John G , This reset is required as well 
     bits= ei4_rx_wt_cu_pll_reset_clear  ;
     rc_ecmd=clear_bits.insert(bits,0,16);
     set_bits.flushTo0();
     //Reset wt_cu_pll
      for (int current_group = 0 ; current_group < 4; current_group++){
          //rc = GCR_read( slave_target, slave_interface,ei4_rx_wiretest_pll_cntl_pg , current_group,  0,  set_bits);
          //set_bits.clearBit(1);
          rc=GCR_write(slave_target, slave_interface, ei4_rx_wiretest_pll_cntl_pg  , current_group,0,   set_bits, clear_bits,1,1);
          //
          //rc = GCR_read( master_target, master_interface,ei4_rx_wiretest_pll_cntl_pg , current_group,  0,  set_bits);
          //set_bits.clearBit(1);
          rc=GCR_write(master_target, master_interface, ei4_rx_wiretest_pll_cntl_pg  , current_group,0,   set_bits, clear_bits,1,1);
      }

      
     FAPI_DBG("Done Setting TX Drv pattern to 0000 and wt_cu_pll_reset to 0 for DLL workaround ");
     return rc;
}

//HW Defect HW220449 , HW HW247831
// Set rx_sls_extend_sel=001 on slave side of X bus post training
ReturnCode do_sls_fix(const Target &slave_target, io_interface_t slave_interface)
{
     ReturnCode rc;
     ecmdDataBufferBase set_bits(16),clear_bits(16);
     uint16_t bits=1;
     
     FAPI_DBG("Setting rx_extend_sel to 001 for all Xbus slaves for HW220449");
     for (int current_group = 0 ; current_group < 4; current_group++){
	  rc = GCR_read( slave_target, slave_interface,ei4_rx_spare_mode_pg, current_group,  0,  set_bits);
          set_bits.insert(bits,5,3,13); // insert rx_sls_extend_sel
          rc=GCR_write(slave_target, slave_interface, ei4_rx_spare_mode_pg , current_group,0,   set_bits, clear_bits);
     }
     return rc;
}

// To handle the MAX_SPARE_EXCEEDED FIR case which we have to handle here in our HWP instead of waiting for PRD.
ReturnCode handle_max_spare(const Target &target,io_interface_t interface,uint8_t current_group){
   ReturnCode o_rc;
   ecmdDataBufferBase error_data(16);
   uint32_t bitPos=0x2680;
   
   if(interface==CP_FABRIC_X0){
      o_rc=GCR_read(target ,  interface, ei4_rx_fir_training_pg,  current_group,0, error_data);
   }
   else{
      o_rc=GCR_read(target ,  interface, rx_fir_training_pg,  current_group,0, error_data);
   }
   if(o_rc)
           return o_rc;
   if(error_data.isBitSet(2,1)){    // can be caused by a static (pre training - bit 2) or dynamic (post training - bit 5) or recal(bit 8)
     FAPI_ERR("MAX_SPARE_EXCEEDED ON THIS BUS clock group %d",current_group);
       error_data.setAnd(bitPos,0,16);
       ecmdDataBufferBase & SPARE_ERROR_REG = error_data; //bit2 /bit 5 /bit 8of the register represents the max spare exceeded bit.To determine what caused the max spares exceeded error
       const fapi::Target & CHIP_TARGET= target;
       FAPI_SET_HWP_ERROR(o_rc,IO_FIR_MAX_SPARES_EXCEEDED_FIR_RC);
   }
   return(o_rc);
}

// These functions work on a pair of targets. One is the master side of the bus interface, the other the slave side. For eg; in EDI(DMI2)PU is the master and Centaur is the slave
// In EI4 both sides have pu targets . After the talk with Dean , my understanding is that targets are configured down upto the endpoints of a particular bus. eg; pu 0 A0 --> pu 1 A3 could be a combination on EI4
// In a EDI(DMI) bus the targets are considered to be one pu and one centaur pair . The overall code is same for EDI and EI4 and the run_training function handles both bus types ( X ,A or MC ) . 
ReturnCode io_run_training(const Target &master_target,const Target &slave_target){
     ReturnCode rc;
     io_interface_t master_interface,slave_interface;
     uint32_t master_group=0;
     uint32_t slave_group=0;
     const uint32_t max_group=4; // Num of X bus groups in one bus
     edi_training init;

     // Workaround - HW 220654 -- Need to split WDERF into WDE + RF
     edi_training init1(SELECTED,SELECTED,SELECTED, NOT_RUNNING, NOT_RUNNING); // Run WDE first
     
     // For Xbus DLL Workaround , we need Wiretest alone , then DE and RF 
     edi_training init_w(SELECTED,NOT_RUNNING, NOT_RUNNING, NOT_RUNNING, NOT_RUNNING); // Run W for Xbus
     edi_training init_de(SELECTED,SELECTED,SELECTED, NOT_RUNNING, NOT_RUNNING); // Run DE next for X bus
     // Need an object to restore object state after one wiretest run. 
     edi_training copy_w=init_w;
     // DE & RF needs to be split due to HW 220654 
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
          rc=fir_workaround_pre_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                      slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
          if(rc) return rc;
          // Workaround - HW 220654 -- Need to split WDERF into WDE + RF due to sync problem
          rc=init1.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
          if(!rc.ok()){
               return rc;
          }
          rc=init2.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
          rc=fir_workaround_post_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                       slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
          if(rc) return rc;
               rc=handle_max_spare(master_target,master_interface,master_group);
          if(rc) return rc;
               rc=handle_max_spare(slave_target,slave_interface,slave_group);
          if(rc) return rc;
          
     }
     //This is an X Bus
     else if( (master_target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT  )&& (slave_target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT )){
         FAPI_DBG("This is a X Bus training invocation");
          master_interface=CP_FABRIC_X0; // base scom for X bus
          slave_interface=CP_FABRIC_X0; // base scom for X bus
          slave_group=0; // Design requires us to do this as per scom map and layout
          master_group=0;
          uint8_t trial_count=0;
          //HW249235 --For DLL workaround 
          bool dll_master_array[24],dll_slave_array[24]; // DLL array for each clock group
          bool dll_workaround_done=false;
          bool dll_workaround_fail=false;
          
          //init Bool array
          for(int i=0;i<24;++i){
               dll_master_array[i]=false;
               dll_slave_array[i]=false;
          }
          
          rc=init.isChipMaster(master_target,master_interface,master_group,is_master);
          if(rc.ok()){
                             if(!is_master){
                     //Swap slave and slave targets !!
                     FAPI_DBG("X Bus ..target swap performed");
                     rc=fir_workaround_pre_training(slave_target,slave_interface,slave_group,slave_target,slave_interface,slave_group,
                                                 slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
                     if(rc) return rc;
                    do{
                         trial_count++;
                         FAPI_DBG("TRAINING TRIAL count=%d",trial_count);
                         rc=init_w.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                         if(rc) {
                              //HW249235 --For DLL workaround
                              FAPI_DBG("Starting DLL Workaround");
                              rc=check_dll_status_and_modify(slave_target,slave_interface,master_target,master_interface,
                                                            dll_slave_array,dll_master_array,dll_workaround_done,dll_workaround_fail);
                              if(rc) return rc;
                              // Reset tx drive pattern to 0000 before starting Wiretest again -- As per Rob /Pete
                              //Prep the targets for next round of WDE training -- Steps by Rob & Pete
                              if(!dll_workaround_done){
                                   rc=set_tx_drv_pattern(slave_target,slave_interface,slave_group,master_target,master_interface,
                                                             master_group);
                              }
                              if(rc) return rc;
                         }
                         else{
                              if(trial_count>1){
                                   FAPI_DBG("DLL workaround was successfull");
                              }
                              dll_workaround_done=true;
                         }
                         init_w=copy_w;
                    }while(!dll_workaround_done);
                    rc=init_de.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                    if(rc) return rc;
                    rc=init2.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                    rc=fir_workaround_post_training(slave_target,slave_interface,slave_group,slave_target,slave_interface,slave_group,
                                                 slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
                    if(rc) return rc;
                    //HW Defect HW220449 , HW HW247831
                    // Set rx_sls_extend_sel=001 on slave side of X bus post training
                    rc=do_sls_fix(master_target,master_interface);
                    if(rc) return rc;
	       }
               else{
                    rc=fir_workaround_pre_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                master_data_one_old,master_data_two_old,slave_data_one_old,slave_data_two_old);
                    if(rc) return rc;
                 do{
                         trial_count++;
                         FAPI_DBG("TRAINING TRIAL count=%d",trial_count);
                         rc=init_w.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                         if(rc) {
                              //HW249235 --For DLL workaround
                              FAPI_DBG("Starting DLL Workaround");
                              rc=check_dll_status_and_modify(master_target,master_interface,slave_target,slave_interface,
                                                            dll_master_array,dll_slave_array,dll_workaround_done,dll_workaround_fail);
                              if(rc) return rc;
                              // Reset tx drive pattern to 0000 before starting Wiretest again -- As per Rob /Pete
                              //Prep the targets for next round of WDE training -- Steps by Rob & Pete
                              if(!dll_workaround_done){
                                   rc=set_tx_drv_pattern(master_target,master_interface,master_group,slave_target,slave_interface,
                                    slave_group);
                              }
                              if(rc) return rc;
                         }
                         else{
                              if(trial_count>1){
                                   FAPI_DBG("DLL workaround was successfull");
                              }
                              dll_workaround_done=true;
                         }
                         init_w=copy_w;// Reset training object state to default
                    }while(!dll_workaround_done);
                    if(!dll_workaround_fail){
                         rc=init_de.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                         if(rc) {
                              
                              return rc;}
                         
                         rc=init2.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                         rc=fir_workaround_post_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                      master_data_one_old,master_data_two_old,slave_data_one_old,slave_data_two_old);
                         if(rc) return rc;
                    }
                    //HW Defect HW220449 , HW HW247831
                    // Set rx_sls_extend_sel=001 on slave side of X bus post training
                   rc=do_sls_fix(slave_target,slave_interface);
                   if(rc) return rc;
               }
               for(uint32_t current_group=0;current_group<max_group;++current_group){
                    rc=handle_max_spare(master_target,master_interface,current_group);
                    if(rc) return rc;
                    rc=handle_max_spare(slave_target,slave_interface,current_group);
                    if(rc) return rc;
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
                    rc=fir_workaround_pre_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
                    if(rc) return rc;
                    rc=init1.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                    if(rc) return rc;
                    rc=init2.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                    rc=fir_workaround_post_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                 slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
                    if(rc) return rc;
               }
               else
               {
                    rc=fir_workaround_pre_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
                    if(rc) return rc;
                    rc=init1.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                    if(rc) return rc;
                    rc=init2.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                    rc=fir_workaround_post_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group,
                                                 slave_data_one_old,slave_data_two_old,master_data_one_old,master_data_two_old);
                    if(rc) return rc;
                    
               }
               rc=handle_max_spare(master_target,master_interface,master_group);
               if(rc) return rc;
               rc=handle_max_spare(slave_target,slave_interface,slave_group);
               if(rc) return rc;
          }
     }
     else{
          FAPI_ERR("Invalid io_run_training HWP invocation . Pair of targets dont belong to DMI/X/A instances");
          FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_INVALID_INVOCATION_RC);
     }
     return rc;
}



} // extern 
