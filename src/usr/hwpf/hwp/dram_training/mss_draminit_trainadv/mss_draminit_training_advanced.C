/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_draminit_training_advanced.C $ */
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
// $Id: mss_draminit_training_advanced.C,v 1.39 2013/10/17 12:59:04 sasethur Exp $
/* File is created by SARAVANAN SETHURAMAN on Thur 29 Sept 2011. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE :mss_draminit_training_advanced.C
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME : Saravanan Sethuraman          email ID:saravanans@in.ibm.com
// *! BACKUP NAME: Mark D Bellows	 	 email ID:bellows@us.ibm.com
// #! ADDITIONAL COMMENTS :
//
// General purpose funcs

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.1    | sasethur |30-Sep-11| Initial draft.
//  1.2    | sasethur |18-Nov-11| Changed function names 
//  1.3    | sasethur |01-Dec-11| Added details on Vref shmoo, reg addresses
//  1.4    | sasethur |29-Jan-12| Updated wr&rd vref, removed ecmd workarounds
//  1.5    | sasethur |13-Feb-12| Updated register naming conventions
//  1.6    | sasethur |08-Mar-12| Changed rc_num, multiple changes to drv_imp, Vref funcs
//  1.7    | sasethur |23-Mar-12| Added Receiver Impedance shmoo & changes to mcbist call
//  1.8    | sasethur |30-Mar-12| Removed port from start_mcb, added 15,20,48 receiver imp settings
//  1.9    | sasethur |03-Apr-12| Fixed warning messages
//  1.13   | bellows  |16-Jul-12| Added in Id tag
//  1.14   | bellows  |18-Jul-12| Disabled some checking code
//  1.15   | gollub   |05-Sep-12| Calling mss_unmask_draminit_training_advanced_errors after mss_draminit_training_advanced_cloned
//  1.16   | sasethur |15-Oct-12| Fixed FW review comments and modified function based on new attributes, added slew function
//  1.17   | sasethur |17-Oct-12| Updated index bound checks
//  1.18   | sasethur |17-Oct-12| Removed Hardcoding of Shmoo parameter value
//  1.19   | sasethur |26-Oct-12| Updated fapi::ReturnCode, const Target& and removed fapi::RC_SUCCSESS as per FW comments
//  1.20   | bellows  |13-Nov-12| Updated for new SI attributes
//  1.21   | sasethur |11-Nov-12| Updated for new SI attribute change, fw review comments
//  1.22   | sasethur |07-Dec-12| Updated for FW review comments - multiple changes
//  1.23   | sasethur |14-Dec-12| Updated for FW review comments 
//  1.24   | sasethur |17-Jan-13| Updated for mss_mcbist_common.C include file 
//  1.25   | abhijsau |31-Jan-13| Removed  mss_mcbist_common.C include file , needs to be included while compiling 
//  1.26   | abhijsau |06-Mar-13| Fixed fw comment 
//  1.27   | sasethur |09-Apr-13| Updated for port in parallel and pass shmoo param
//  1.28   | sasethur |22-Apr-13| Fixed fw comment 
//  1.29   | sasethur |23-Apr-13| Fixed fw comment 
//  1.30   | sasethur |24-Apr-13| Fixed fw comment 
//  1.31   | sasethur |10-May-13| Added user input for test type, pattern from wrapper 
//  1.32   | sasethur |04-Jun-13| Fixed for PortD cnfg, vref print for min setup, hold, fixed rdvref print, added set/reset mcbist attr
//  1.33   | sasethur |12-Jun-13| Updated mcbist setup attribute 
//  1.34   | sasethur |20-Jun-13| Fixed read_vref print, setup attribute
//  1.35   | sasethur |08-Aug-13| Fixed fw comment
//  1.36   | sasethur |23-Aug-13| Ability to run MCBIST is enabled.
//  1.37   | sasethur |04-Sep-13| Fixed fw review comment
//  1.38   | bellows  |19-SEP-13| fixed possible buffer overrun found by stradale
//  1.39   | abhijsau |17-OCT-13| fixed a logical bug 

// This procedure Schmoo's DRV_IMP, SLEW, VREF (DDR, CEN), RCV_IMP based on attribute from effective config procedure
// DQ & DQS Driver impedance, Slew rate, WR_Vref shmoo would call only write_eye shmoo for margin calculation
// DQ & DQS VREF (rd_vref), RCV_IMP shmoo would call rd_eye for margin calculation
// Internal Vref controlled by this function & external vref platform to provide function we return value

// Not supported
// DDR4, DIMM Types
//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------

#include <fapi.H>

//----------------------------------------------------------------------
//Centaur functions
//----------------------------------------------------------------------
#include <mss_termination_control.H>
#include "mss_mcbist.H"
#include <mss_shmoo_common.H>
#include <mss_generic_shmoo.H>
#include <mss_draminit_training_advanced.H>
#include <mss_unmask_errors.H>

const uint32_t MASK = 1;
const uint32_t MAX_DIMM =2;

enum shmoo_param
{
    PARAM_NONE = 0x00,
    DELAY_REG = 0x01,
    DRV_IMP = 0x02, 
    SLEW_RATE = 0x04,
    WR_VREF = 0x08,
    RD_VREF = 0x10,
    RCV_IMP = 0x20 
};


extern "C" 
{

using namespace fapi;

fapi::ReturnCode mss_draminit_training_advanced_cloned(const fapi::Target & i_target_mba);

fapi::ReturnCode drv_imped_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
			shmoo_type_t i_shmoo_type_valid); 

fapi::ReturnCode slew_rate_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
			shmoo_type_t i_shmoo_type_valid); 

fapi::ReturnCode wr_vref_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
			shmoo_type_t i_shmoo_type_valid);

fapi::ReturnCode rd_vref_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
			shmoo_type_t i_shmoo_type_valid); 

fapi::ReturnCode rcv_imp_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
			shmoo_type_t i_shmoo_type_valid);

fapi::ReturnCode delay_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
		    shmoo_type_t i_shmoo_type_valid, 
		    uint32_t *o_left_margin, uint32_t *o_right_margin,
		     uint32_t i_shmoo_param);

void find_best_margin(shmoo_param i_shmoo_param_valid,uint32_t i_left[], 
			uint32_t i_right[], const uint8_t l_max, 
			uint32_t i_param_nom, uint8_t& o_index);

fapi::ReturnCode set_attribute(const fapi::Target & i_target_mba);

fapi::ReturnCode reset_attribute(const fapi::Target & i_target_mba);


//-----------------------------------------------------------------------------------
//Function name: mss_draminit_training_advanced()
//Description: This function varies driver impedance, receiver impedance, slew, wr & rd vref
//based on attribute definition and runs either mcbist/delay shmoo based on attribute
//Also calls unmask function mss_unmask_draminit_training_advanced_errors() 
//Input : const fapi::Target MBA, i_pattern = pattern selection during mcbist @ lab, 
//	l_test type  = test type selection during mcbist @ lab 
//	Default vlaues are Zero
//-----------------------------------------------------------------------------------

fapi::ReturnCode mss_draminit_training_advanced(const fapi::Target & i_target_mba)
{
    // const fapi::Target is centaur.mba
    fapi::ReturnCode rc;
    //FAPI_INF(" pattern bit is %d and test_type_bit is %d");   
    rc = mss_draminit_training_advanced_cloned(i_target_mba);
    if (rc) 
    {
	FAPI_ERR("Advanced DRAM Init training procedure is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
    }
    
    // If mss_unmask_draminit_training_advanced_errors gets it's own bad rc,
    // it will commit the passed in rc (if non-zero), and return it's own bad rc.
    // Else if mss_unmask_draminit_training_advanced_errors runs clean, 
    // it will just return the passed in rc.
    
    rc = mss_unmask_draminit_training_advanced_errors(i_target_mba, rc);
    if (rc) 
    {
	FAPI_ERR("Unmask Function is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
	return rc;
    }
    return rc;
  }

}
//end of extern C

//-----------------------------------------------------------------------------------
// Function name: mss_draminit_training_advanced_cloned()
// Description: This function varies driver impedance, receiver impedance, slew, wr & rd vref
// based on attribute definition and runs either mcbist/delay shmoo based on attribute
// Input : const fapi::Target MBA
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//-----------------------------------------------------------------------------------
fapi::ReturnCode mss_draminit_training_advanced_cloned(const fapi::Target & i_target_mba)
{
    //const fapi::Target is centaur.mba
    fapi::ReturnCode rc;

    const char* procedure_name = "mss_draminit_training_advanced";

    FAPI_INF("+++++++ Executing %s +++++++", procedure_name);
	
    // Define attribute variables
    uint32_t l_attr_mss_freq_u32 = 0;
    uint32_t l_attr_mss_volt_u32 = 0;  
    uint8_t l_num_drops_per_port_u8 = 2;
    uint8_t l_num_ranks_per_dimm_u8array[MAX_PORT][MAX_DIMM] = {{0}};
    //nuint8_t l_actual_dimm_size_u8 = 0;
    uint8_t l_port = 0;
    uint8_t l_dimm_type_u8 = 0; //default is set to CDIMM
    uint32_t l_left_margin=0;  
    uint32_t l_right_margin=0;  
    uint32_t l_shmoo_param=0; 
     
    // Define local variables
    uint8_t l_shmoo_type_valid_t=0;
    uint8_t l_shmoo_param_valid_t=0;
        	
    //const fapi::Target is centaur
    fapi::Target l_target_centaur;
    rc = fapiGetParentChip(i_target_mba, l_target_centaur); 
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_u32); 
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_attr_mss_volt_u32); 
    if(rc) return rc;
    
    //const fapi::Target is centaur.mba   
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target_mba, l_dimm_type_u8); 
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target_mba, l_num_drops_per_port_u8); 
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm_u8array); 
    if(rc) return rc;
    
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    FAPI_INF("freq = %d on %s.", l_attr_mss_freq_u32, l_target_centaur.toEcmdString());
    FAPI_INF("volt = %d on %s.", l_attr_mss_volt_u32, l_target_centaur.toEcmdString());
    FAPI_INF("dimm_type = %d on %s.", l_dimm_type_u8, i_target_mba.toEcmdString());
    FAPI_INF("num_drops_per_port = %d on %s.", l_num_drops_per_port_u8, i_target_mba.toEcmdString());
    FAPI_INF("num_ranks_per_dimm = [%02d][%02d][%02d][%02d] on %s.", l_num_ranks_per_dimm_u8array[0][0],l_num_ranks_per_dimm_u8array[0][1], l_num_ranks_per_dimm_u8array[1][0],l_num_ranks_per_dimm_u8array[1][1], i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

   // if ( l_num_drops_per_port_u8 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL ) 
   // {
   //    l_actual_dimm_size_u8 = 2;
   // }
   // else 
   // {
   //    l_actual_dimm_size_u8 = 1;
   // }
       
    rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, l_shmoo_type_valid_t);  
    if(rc) return rc; 
    rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_PARAM_VALID, &i_target_mba, l_shmoo_param_valid_t); 
    if(rc) return rc;
   
    shmoo_type_t l_shmoo_type_valid;
    shmoo_param l_shmoo_param_valid;

    l_shmoo_type_valid=(shmoo_type_t)l_shmoo_type_valid_t;
    l_shmoo_param_valid=(shmoo_param)l_shmoo_param_valid_t;
    
    FAPI_INF("+++++++++++++++++++++++++ Read Schmoo Attributes ++++++++++++++++++++++++++");
    FAPI_INF("Schmoo param valid = 0x%x on %s", l_shmoo_param_valid, i_target_mba.toEcmdString());
    FAPI_INF("Schmoo test valid = 0x%x on %s", l_shmoo_type_valid, i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    //Check for Shmoo Parameter, if anyof them is enabled then go into the loop else the procedure exit 

    	    if (( l_num_ranks_per_dimm_u8array[0][0] > 0 ) || (l_num_ranks_per_dimm_u8array[0][1] > 0) || ( l_num_ranks_per_dimm_u8array[1][0] > 0 ) || (l_num_ranks_per_dimm_u8array[1][1] > 0))
            {
    		if((l_shmoo_param_valid != PARAM_NONE) || (l_shmoo_type_valid != TEST_NONE)) 
    		{
    		    if((l_shmoo_param_valid & DRV_IMP) != 0)
    		    { 
    			rc = drv_imped_shmoo(i_target_mba, l_port, l_shmoo_type_valid); 
    			if (rc)
    			{
    			    FAPI_ERR("Driver Impedance Schmoo function is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
    			    return rc;
    			}
    		    }
    		    if((l_shmoo_param_valid & SLEW_RATE) !=0) 
        	    {
    			rc = slew_rate_shmoo(i_target_mba, l_port, l_shmoo_type_valid);
    			if (rc)
    			{
    			    FAPI_ERR("Slew Rate Schmoo Function is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
    			    return rc;
    			}
    		    }
    		    if((l_shmoo_param_valid & WR_VREF) != 0) 
	   		    {
    			rc = wr_vref_shmoo(i_target_mba, l_port, l_shmoo_type_valid);
    			if (rc)
   				{
     			    FAPI_ERR("Write Vref Schmoo Function is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
    			    return rc;
    			}
    		    }
    		    if((l_shmoo_param_valid & RD_VREF) !=0)
    		    {
    			rc = rd_vref_shmoo(i_target_mba, l_port, l_shmoo_type_valid);
    			if (rc)
    			{
    			    FAPI_ERR("Read Vref Schmoo Function is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
    			    return rc;
    			}
		    }
    		    if ((l_shmoo_param_valid & RCV_IMP) !=0)
    		    {	
    			rc = rcv_imp_shmoo(i_target_mba, l_port, l_shmoo_type_valid);
    			if (rc)
    			{
    			    FAPI_ERR("Receiver Impedance Schmoo Function is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
    			    return rc;
    			}
    		    }
    		    if (((l_shmoo_param_valid == PARAM_NONE)))
    		    {
    			rc = delay_shmoo(i_target_mba, l_port, l_shmoo_type_valid, &l_left_margin, &l_right_margin, l_shmoo_param); 
    			if (rc)
    			{
    			    FAPI_ERR("Delay Schmoo Function is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
    			    return rc;
    			}
    		    }
		}
    }
return rc;
}



//-------------------------------------------------------------------------------
// Function name: drv_imped_shmoo()
// This function varies the driver impedance in the nominal mode
// for both dq/dqs & adr/cmd signals - DQ_DQS<24,30,34,40>,CMD_CNTL<15,20,30,40>
// if there is any mcbist failure, that will be reported to put_bad_bits function
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//-------------------------------------------------------------------------------

fapi::ReturnCode drv_imped_shmoo(const fapi::Target & i_target_mba,
			   uint8_t i_port,
			   shmoo_type_t i_shmoo_type_valid)
{
    fapi::ReturnCode rc;
    uint8_t l_drv_imp_dq_dqs[MAX_PORT] = {0};
    uint8_t l_drv_imp_dq_dqs_nom[MAX_PORT] = {0};
    //uint8_t l_drv_imp_dq_dqs_new[MAX_PORT] = {0};
    uint8_t index=0;
    uint8_t l_slew_rate_dq_dqs[MAX_PORT] = {0};
    uint8_t l_slew_rate_dq_dqs_schmoo[MAX_PORT] = {0};
    uint32_t l_drv_imp_dq_dqs_schmoo[MAX_PORT] = {0};
    uint8_t l_drv_imp_dq_dqs_nom_fc = 0;
    uint8_t l_drv_imp_dq_dqs_in = 0;
    //Temporary 
    i_shmoo_type_valid = WR_EYE;  //Hard coded, since no other schmoo is applicable for this parameter
    uint32_t l_left_margin_drv_imp_array[MAX_DRV_IMP] = {0};
    uint32_t l_right_margin_drv_imp_array[MAX_DRV_IMP] = {0};
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint8_t count = 0;
    uint8_t shmoo_param_count = 0;
    uint8_t l_slew_type = 0; // Hard coded since this procedure will touch only DQ_DQS and not address
       	
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, l_drv_imp_dq_dqs_nom); 
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, l_slew_rate_dq_dqs); 
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, &i_target_mba, l_drv_imp_dq_dqs_schmoo);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO, &i_target_mba, l_slew_rate_dq_dqs_schmoo);
    if (rc) return rc;
	
    FAPI_INF("+++++++++++++++++Read DRIVER IMP Attributes values++++++++++++++++");
    FAPI_INF("CEN_DRV_IMP_DQ_DQS[%d]  = [%02d] Ohms, on %s", i_port, l_drv_imp_dq_dqs_nom[i_port], i_target_mba.toEcmdString());
    FAPI_INF("CEN_DRV_IMP_DQ_DQS_SCHMOO[0]  = [0x%x], CEN_DRV_IMP_DQ_DQS_SCHMOO[1]  = [0x%x] on %s", l_drv_imp_dq_dqs_schmoo[0],l_drv_imp_dq_dqs_schmoo[1], i_target_mba.toEcmdString());
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS[0] = [%02d]V/ns , CEN_SLEW_RATE_DQ_DQS[1] = [%02d]V/ns on %s", l_slew_rate_dq_dqs[0],l_slew_rate_dq_dqs[1], i_target_mba.toEcmdString());
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS_SCHMOO[0] = [0x%x], CEN_SLEW_RATE_DQ_DQS_SCHMOO[1] = [0x%x] on %s", l_slew_rate_dq_dqs_schmoo[0],l_slew_rate_dq_dqs_schmoo[1], i_target_mba.toEcmdString());
    FAPI_INF("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    
    if(l_drv_imp_dq_dqs_schmoo[i_port] == 0) //Check for any of the bits enabled in the shmoo
    {
	FAPI_INF("DRIVER IMP Shmoo set to FAST Mode and won't do anything");
    }
    else
    {   
	for(index = 0; index< MAX_DRV_IMP; index+=1)   
	{
        if (l_drv_imp_dq_dqs_schmoo[i_port] & MASK) 
	    {
	        l_drv_imp_dq_dqs[i_port] = drv_imp_array[index];
		FAPI_INF("Current Driver Impedance Value = %d Ohms", drv_imp_array[index]);
		FAPI_INF("Configuring Driver Impedance Registers:");
		rc = config_drv_imp(i_target_mba, i_port, l_drv_imp_dq_dqs[i_port]); 
		if (rc) return rc;
		l_drv_imp_dq_dqs_in = l_drv_imp_dq_dqs[i_port];
		FAPI_INF("Configuring Slew Rate Registers:");
	        rc = config_slew_rate(i_target_mba, i_port, l_slew_type, l_drv_imp_dq_dqs[i_port], l_slew_rate_dq_dqs[i_port]); 
		if (rc) return rc;
		FAPI_INF("Calling Shmoo for finding Timing Margin:");
		if (shmoo_param_count) 
		{
			rc = set_attribute(i_target_mba); if(rc) return rc;
		}
		rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid, 
				 &l_left_margin, &l_right_margin, l_drv_imp_dq_dqs_in);  
		if (rc) return rc;
		l_left_margin_drv_imp_array[index]= l_left_margin;
	        l_right_margin_drv_imp_array[index]= l_right_margin;
		 shmoo_param_count++;
	    }
	    else
	    {
		l_left_margin_drv_imp_array[index]= 0;
	        l_right_margin_drv_imp_array[index]= 0;
	    }
	    l_drv_imp_dq_dqs_schmoo[i_port] = (l_drv_imp_dq_dqs_schmoo[i_port] >> 1);
	}
        l_drv_imp_dq_dqs_nom_fc = l_drv_imp_dq_dqs_nom[i_port];
	find_best_margin(DRV_IMP, l_left_margin_drv_imp_array,
			      l_right_margin_drv_imp_array, MAX_DRV_IMP, l_drv_imp_dq_dqs_nom_fc, count);
	
	if (count >= MAX_DRV_IMP)
        {
                FAPI_ERR("Driver Imp new input(%d) out of bounds, (>= %d)",
                            count, MAX_DRV_IMP);
                FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
                return rc;
        }
	else
	{
	   
	  /* if(i_port == 0)
	   {
	   l_drv_imp_dq_dqs_new[0] = drv_imp_array[count];
	   l_drv_imp_dq_dqs_new[1] = l_drv_imp_dq_dqs_nom[1];  // This can be removed once the get/set attribute takes care of this
	   }
	   else
	   {
	   l_drv_imp_dq_dqs_new[1] = drv_imp_array[count];
	   l_drv_imp_dq_dqs_new[0] = l_drv_imp_dq_dqs_nom[0];
	   }*/
 
	  // if (l_drv_imp_dq_dqs_new[i_port] != l_drv_imp_dq_dqs_nom[i_port])
	  // {
	        //FAPI_INF("Better Margin found on %d Ohms on %s", l_drv_imp_dq_dqs_new[i_port], i_target_mba.toEcmdString());
	       // rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, l_drv_imp_dq_dqs_new); 
	       // if (rc) return rc;
	        //FAPI_INF("Configuring New Driver Impedance Value to Registers:");
	        //rc = config_drv_imp(i_target_mba, i_port, l_drv_imp_dq_dqs_new[i_port]);
	        //if (rc) return rc;
	        //rc = config_slew_rate(i_target_mba, i_port, l_slew_type, l_drv_imp_dq_dqs_new[i_port], l_slew_rate_dq_dqs[i_port]); 
		//if (rc) return rc;
	   // }
	   // else
	   // {
	        //FAPI_INF("Nominal value will not be changed - Restoring the original values!");	
	        FAPI_INF("Restoring the nominal values!");	
	        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, l_drv_imp_dq_dqs_nom); 
	        if (rc) return rc;
	        rc = config_drv_imp(i_target_mba, i_port, l_drv_imp_dq_dqs_nom[i_port]);
	        if (rc) return rc;
	        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, l_slew_rate_dq_dqs); 
	        if (rc) return rc;
	        rc = config_slew_rate(i_target_mba, i_port, l_slew_type, l_drv_imp_dq_dqs_nom[i_port], l_slew_rate_dq_dqs[i_port]); 
		if (rc) return rc;
	   // } 
	}
    FAPI_INF("Restoring mcbist setup attribute...");
	rc = reset_attribute(i_target_mba); if (rc) return rc;
	FAPI_INF("++++ Driver impedance shmoo function executed successfully ++++");
    }
return rc;
}

//-----------------------------------------------------------------------------------------
// Function name: slew_rate_shmoo()
// This function varies the slew rate of the data & adr signals (fast/slow)
// calls the write eye shmoo which internally calls mcbist function to see for failure
// if there is any mcbist failure, this function will report to baddqpins function
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//-----------------------------------------------------------------------------------------

fapi::ReturnCode slew_rate_shmoo(const fapi::Target & i_target_mba,
			   uint8_t i_port,
			   shmoo_type_t i_shmoo_type_valid)
{
    fapi::ReturnCode rc;
    uint8_t l_slew_rate_dq_dqs[MAX_PORT] = {0};
    uint8_t l_slew_rate_dq_dqs_nom[MAX_PORT] = {0};
    uint8_t l_slew_rate_dq_dqs_nom_fc = 0;
    uint8_t l_slew_rate_dq_dqs_in = 0;
    //uint8_t l_slew_rate_dq_dqs_new[MAX_PORT] = {0};
    uint32_t l_slew_rate_dq_dqs_schmoo[MAX_PORT] = {0};
    uint8_t l_drv_imp_dq_dqs_nom[MAX_PORT] = {0};
    i_shmoo_type_valid = WR_EYE; // Hard coded - Other shmoo type is not valid - Temporary
    
    uint8_t index = 0;
    uint8_t count = 0;
    uint8_t shmoo_param_count = 0;
    uint32_t l_left_margin_slew_array[MAX_NUM_SLEW_RATES] = {0};
    uint32_t l_right_margin_slew_array[MAX_NUM_SLEW_RATES] = {0};
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint8_t l_slew_type = 0; // Hard coded since this procedure will touch only DQ_DQS and not address
    		
    //Read Attributes - DRV IMP, SLEW, SLEW RATES values to be Schmoo'ed
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, l_drv_imp_dq_dqs_nom); 
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, l_slew_rate_dq_dqs_nom); 
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, &i_target_mba, l_slew_rate_dq_dqs_schmoo);
    if (rc) return rc;
	
    FAPI_INF("+++++++++++++++++Read Slew Shmoo Attributes values+++++++++++++++");
    FAPI_INF("CEN_DRV_IMP_DQ_DQS[0]  = [%02d] Ohms, CEN_DRV_IMP_DQ_DQS[1]  = [%02d] Ohms on %s", l_drv_imp_dq_dqs_nom[0],l_drv_imp_dq_dqs_nom[1], i_target_mba.toEcmdString());
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS[0] = [%02d]V/ns , CEN_SLEW_RATE_DQ_DQS[1] = [%02d]V/ns on %s", l_slew_rate_dq_dqs_nom[0],l_slew_rate_dq_dqs_nom[1], i_target_mba.toEcmdString());
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS_SCHMOO[0] = [0x%x], CEN_SLEW_RATE_DQ_DQS_SCHMOO[1] = [0x%x] on %s", l_slew_rate_dq_dqs_schmoo[0],l_slew_rate_dq_dqs_schmoo[1], i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    
    if(l_slew_rate_dq_dqs_schmoo == 0) //Check for any of the bits enabled in the shmoo
    {
	FAPI_INF("Slew Rate Shmoo set to FAST Mode and won't do anything");
    }
    else
    {
	for(index = 0; index < MAX_NUM_SLEW_RATES; index+=1)
	{
            if (l_slew_rate_dq_dqs_schmoo[i_port] & MASK )   
	    {
		l_slew_rate_dq_dqs[i_port] = slew_rate_array[index];
		FAPI_INF("Current Slew rate value is %d V/ns", slew_rate_array[index]);
		FAPI_INF("Configuring Slew registers:");
		rc = config_slew_rate(i_target_mba, i_port, l_slew_type, l_drv_imp_dq_dqs_nom[i_port], l_slew_rate_dq_dqs[i_port]); 
                if (rc) return rc;
		l_slew_rate_dq_dqs_in = l_slew_rate_dq_dqs[i_port];
		FAPI_INF("Calling Shmoo for finding Timing Margin:");
		if (shmoo_param_count)
		{
			rc = set_attribute(i_target_mba); if(rc) return rc;
		}
		rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid, 
				 &l_left_margin, &l_right_margin, l_slew_rate_dq_dqs_in);  
                if (rc) return rc;
		l_left_margin_slew_array[index]= l_left_margin;
		l_right_margin_slew_array[index]= l_right_margin;
		 shmoo_param_count++;
	    }
	    else
	    {
	        l_left_margin_slew_array[index]= 0;
	        l_right_margin_slew_array[index]= 0;
	    }
   	    l_slew_rate_dq_dqs_schmoo[i_port] = (l_slew_rate_dq_dqs_schmoo[i_port] >> 1);
	}
        l_slew_rate_dq_dqs_nom_fc = l_slew_rate_dq_dqs_nom[i_port];
	find_best_margin(SLEW_RATE, l_left_margin_slew_array,
			      l_right_margin_slew_array, MAX_NUM_SLEW_RATES, l_slew_rate_dq_dqs_nom_fc, count);
	if (count >= MAX_NUM_SLEW_RATES)
        {
                FAPI_ERR("Driver Imp new input(%d) out of bounds, (>= %d)",
                            count, MAX_NUM_SLEW_RATES);
                FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
                return rc;
        }
	else
	{
	   
	 /*  if(i_port == 0)
	   {
	       l_slew_rate_dq_dqs_new[0] = slew_rate_array[count];
	       l_slew_rate_dq_dqs_new[1] = l_slew_rate_dq_dqs_nom[1]; 
	   }
	   else
	   {
	       l_slew_rate_dq_dqs_new[1] = slew_rate_array[count];
	       l_slew_rate_dq_dqs_new[0] = l_slew_rate_dq_dqs_nom[0];  
	   }*/
 
				  
	   FAPI_INF("Restoring the nominal values!");	
	   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, l_drv_imp_dq_dqs_nom); 
	   if (rc) return rc;
	   rc = config_drv_imp(i_target_mba, i_port, l_drv_imp_dq_dqs_nom[i_port]);
	   if (rc) return rc;
	   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, l_slew_rate_dq_dqs_nom); 
	   if (rc) return rc;
	   rc = config_slew_rate(i_target_mba, i_port, l_slew_type, l_drv_imp_dq_dqs_nom[i_port], l_slew_rate_dq_dqs_nom[i_port]); 
   	   if (rc) return rc;
	
	   /* if (l_slew_rate_dq_dqs_new[i_port] != l_slew_rate_dq_dqs_nom[i_port])
	    {
	        FAPI_INF("Better Margin found on Slew Rate: %d V/ns on %s", l_slew_rate_dq_dqs_new[i_port], i_target_mba.toEcmdString());
	        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, l_slew_rate_dq_dqs_new); 
	        if (rc) return rc;
	        FAPI_INF("Configuring New Slew Rate Value to Registers:");
	        rc = config_slew_rate(i_target_mba, i_port, l_slew_type, l_drv_imp_dq_dqs_nom[i_port], l_slew_rate_dq_dqs_new[i_port]); 
	        if (rc) return rc;
	    }
	    else
	    {
	        FAPI_INF("Nominal value will not be changed!");	
	        FAPI_INF("Slew Rate: %d V/ns on %s", l_slew_rate_dq_dqs_nom[i_port], i_target_mba.toEcmdString());
	    } */
	}
        FAPI_INF("Restoring mcbist setup attribute...");
	rc = reset_attribute(i_target_mba); if (rc) return rc;
	FAPI_INF("++++ Slew Rate shmoo function executed successfully ++++");
    }
return rc;	
}

//----------------------------------------------------------------------------------------------
// Function name: wr_vref_shmoo()
// This function varies the DIMM vref using PC_VREF_DRV_CNTL register in 32 steps with vref sign
// Calls mcbist/write eye shmoo function and look for failure, incase of failure
// this function reports bad DQ pins matrix to put bad bits function
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//----------------------------------------------------------------------------------------------

fapi::ReturnCode wr_vref_shmoo(const fapi::Target & i_target_mba,
			 uint8_t i_port,
			 shmoo_type_t i_shmoo_type_valid)
{
    fapi::ReturnCode rc;
    uint32_t l_wr_dram_vref[MAX_PORT] = {0};
    uint32_t l_wr_dram_vref_nom[MAX_PORT] = {0};
    //uint32_t l_wr_dram_vref_new[MAX_PORT] = {0};
    uint32_t l_wr_dram_vref_schmoo[MAX_PORT] = {0}; 
    uint32_t l_wr_dram_vref_nom_fc = 0;
    uint32_t l_wr_dram_vref_in = 0;
    i_shmoo_type_valid = WR_EYE; // Hard coded - Temporary
    
    uint8_t index = 0;
    uint8_t count = 0;
    uint8_t shmoo_param_count = 0;
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint32_t l_left_margin_wr_vref_array[MAX_WR_VREF]= {0};
    uint32_t l_right_margin_wr_vref_array[MAX_WR_VREF]= {0};
                          
    //Read the write vref attributes
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR_VREF, &i_target_mba, l_wr_dram_vref_nom); 
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR_VREF_SCHMOO, &i_target_mba, l_wr_dram_vref_schmoo);
    if (rc) return rc;
    FAPI_INF("+++++++++++++++++WRITE DRAM VREF Shmoo Attributes Values+++++++++++++++");
    FAPI_INF("DRAM_WR_VREF[0]  = %d , DRAM_WR_VREF[1]  = %d on %s", l_wr_dram_vref_nom[0], l_wr_dram_vref_nom[1],i_target_mba.toEcmdString());
    FAPI_INF("DRAM_WR_VREF_SCHMOO[0] = [%x],DRAM_WR_VREF_SCHMOO[1] = [%x] on %s", l_wr_dram_vref_schmoo[0], l_wr_dram_vref_schmoo[1],i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    
    
    if(l_wr_dram_vref_schmoo[i_port] == 0)
    {
	FAPI_INF("FAST Shmoo Mode: This function will not change any Write DRAM VREF settings");
    }
    else
    {
	for(index = 0; index < MAX_WR_VREF; index+=1)
	{
            if (l_wr_dram_vref_schmoo[i_port] & MASK) 
	    {
				FAPI_INF("Current Vref multiplier value is %d", wr_vref_array[index]);
			l_wr_dram_vref[i_port] = wr_vref_array[index];
			rc = config_wr_dram_vref(i_target_mba, i_port, l_wr_dram_vref[i_port]); 
					if (rc) return rc;
			l_wr_dram_vref_in = l_wr_dram_vref[i_port];
			//FAPI_INF(" Calling Shmoo for finding Timing Margin:");
			if (shmoo_param_count) 
			{
				rc = set_attribute(i_target_mba);
				if (rc) return rc;
			}
			rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid, 
					 &l_left_margin, &l_right_margin, l_wr_dram_vref_in);  
			if (rc) return rc;
			l_left_margin_wr_vref_array[index]= l_left_margin;
				l_right_margin_wr_vref_array[index]= l_right_margin;
			 shmoo_param_count++;
			FAPI_INF("Wr Vref = %d ; Min Setup time = %d; Min Hold time = %d", wr_vref_array[index],l_left_margin_wr_vref_array[index],  l_right_margin_wr_vref_array[index]); 
	    }
	    else
	    {
		l_left_margin_wr_vref_array[index]= 0;
	        l_right_margin_wr_vref_array[index]= 0;
	    }
	    l_wr_dram_vref_schmoo[i_port] = (l_wr_dram_vref_schmoo[i_port] >> 1);
   	    //FAPI_INF("Wr Vref = %d ; Min Setup time = %d; Min Hold time = %d", wr_vref_array[index],l_left_margin_wr_vref_array[index],  l_right_margin_wr_vref_array[index]); 
		//FAPI_INF("Configuring Vref registers_2:, index %d , max value %d, schmoo %x mask %d ", index, MAX_WR_VREF, l_wr_dram_vref_schmoo[i_port], MASK);
	}
	l_wr_dram_vref_nom_fc = l_wr_dram_vref_nom[i_port];
	find_best_margin(WR_VREF, l_left_margin_wr_vref_array,
			      l_right_margin_wr_vref_array, MAX_WR_VREF, l_wr_dram_vref_nom_fc, count);
	if (count >= MAX_WR_VREF)
        {
                FAPI_ERR("Write dram vref input(%d) out of bounds, (>= %d)",
                            count, MAX_WR_VREF);
                FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
                return rc;
        }
	else
	{
	   
	  /*  if(i_port == 0)
	    {
	        l_wr_dram_vref_new[0] = wr_vref_array_fitness[count];
                l_wr_dram_vref_new[1] = l_wr_dram_vref_nom[1];
	    }
	    else
	    {
	        l_wr_dram_vref_new[1] = wr_vref_array_fitness[count];
                l_wr_dram_vref_new[0] = l_wr_dram_vref_nom[0];
	    }
 
  	    if(l_wr_dram_vref_new[i_port] != l_wr_dram_vref_nom[i_port])
	    {
	        //FAPI_INF("Best Margin Found on Vref Multiplier : %d on %s", wr_vref_array_fitness[count], i_target_mba.toEcmdString());
	        //rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_VREF, &i_target_mba, l_wr_dram_vref_new); 
	        //if (rc) return rc;
	        //FAPI_INF("Configuring New Vref Value to registers:");
	        //rc = config_wr_dram_vref(i_target_mba, i_port, l_wr_dram_vref_new[i_port]); 
                //if (rc) return rc;	    
	    }
	    else
	    {*/
	     //   FAPI_INF("Nominal value will not be changed!- Restoring the original values!");	
	        FAPI_INF(" Restoring the nominal values!");	
	        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_VREF, &i_target_mba, l_wr_dram_vref_nom); 
	        if (rc) return rc;
	        rc = config_wr_dram_vref(i_target_mba, i_port, l_wr_dram_vref_nom[i_port]); 
                if (rc) return rc;	    
	   // }
        }
    FAPI_INF("Restoring mcbist setup attribute...");
    rc = reset_attribute(i_target_mba); if (rc) return rc;
    FAPI_INF("++++ Write DRAM Vref Shmoo function executed successfully ++++");
    }
    return rc;
}



//----------------------------------------------------------------------------------------------
// Function name: rd_vref_shmoo()                                                               
// Description: This function varies the Centaur IO vref in 16 steps 
// 		Calls write eye shmoo function                 
// Input param: const fapi::Target MBA, port = 0,1
// 	Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// 	Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// 	Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// 	i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//----------------------------------------------------------------------------------------------
       
fapi::ReturnCode rd_vref_shmoo(const fapi::Target & i_target_mba,
			 uint8_t i_port,
			 shmoo_type_t i_shmoo_type_valid)
{
    fapi::ReturnCode rc;
    uint32_t l_rd_cen_vref[MAX_PORT] = {0};
    uint32_t l_rd_cen_vref_nom[MAX_PORT] = {0};
    uint32_t l_rd_cen_vref_nom_fc = 0;
    uint32_t l_rd_cen_vref_in = 0;
    //uint32_t l_rd_cen_vref_new[MAX_PORT] ={0};
    uint32_t l_rd_cen_vref_schmoo[MAX_PORT] = {0};
    uint8_t index  = 0;
    uint8_t count  = 0;
    uint8_t shmoo_param_count = 0;
    i_shmoo_type_valid = RD_EYE; // Hard coded - Temporary
    
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint32_t l_left_margin_rd_vref_array[MAX_RD_VREF] = {0};
    uint32_t l_right_margin_rd_vref_array[MAX_RD_VREF] = {0};
    
    	
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RD_VREF, &i_target_mba, l_rd_cen_vref_nom);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RD_VREF_SCHMOO, &i_target_mba, l_rd_cen_vref_schmoo);
    if (rc) return rc;
    
    FAPI_INF("+++++++++++++++++CENTAUR VREF Read Shmoo Attributes values+++++++++++++++");
    FAPI_INF("CEN_RD_VREF[0]  = %d CEN_RD_VREF[1]  = %d on %s", l_rd_cen_vref_nom[0],l_rd_cen_vref_nom[1], i_target_mba.toEcmdString());
    FAPI_INF("CEN_RD_VREF_SCHMOO[0] = [%x], CEN_RD_VREF_SCHMOO[1] = [%x] on %s", l_rd_cen_vref_schmoo[0], l_rd_cen_vref_schmoo[1],i_target_mba.toEcmdString());
    FAPI_INF("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    
    if(l_rd_cen_vref_schmoo[i_port] == 0)
    {
	FAPI_INF("FAST Shmoo Mode: This function will not change any Read Centaur VREF settings");
    }
    else
    {
        for(index = 0; index< MAX_RD_VREF; index+=1)
        {
            if ((l_rd_cen_vref_schmoo[i_port] & MASK) == 1)
	    {
		l_rd_cen_vref[i_port] = rd_cen_vref_array[index];
		FAPI_INF("Current Read Vref Multiplier value is %d", rd_cen_vref_array[index]);
		FAPI_INF("Configuring Read Vref Registers:");
		rc = config_rd_cen_vref(i_target_mba, i_port, l_rd_cen_vref[i_port]); if (rc) return rc;
		l_rd_cen_vref_in = l_rd_cen_vref[i_port];
		//FAPI_INF(" Calling Shmoo function to find out Timing Margin:");
		if (shmoo_param_count) 
		{
			rc = set_attribute(i_target_mba);
                	if (rc) return rc;
		}
		rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid, &l_left_margin, &l_right_margin, l_rd_cen_vref_in);
		if (rc) return rc;
		l_left_margin_rd_vref_array[index]= l_left_margin;
	        l_right_margin_rd_vref_array[index]= l_right_margin;
		 shmoo_param_count++;
		 FAPI_INF("Read Vref = %d ; Min Setup time = %d; Min Hold time = %d", rd_cen_vref_array[index],l_left_margin_rd_vref_array[index],  l_right_margin_rd_vref_array[index]); 
	    }
	    else
	    {
		l_left_margin_rd_vref_array[index]= 0;
	        l_right_margin_rd_vref_array[index]= 0;
	    }
   	    l_rd_cen_vref_schmoo[i_port] = (l_rd_cen_vref_schmoo[i_port] >> 1);
   	    /* FAPI_INF("Read Vref = %d ; Min Setup time = %d; Min Hold time = %d", rd_cen_vref_array[index],l_left_margin_rd_vref_array[index],  l_right_margin_rd_vref_array[index]);  */
	}
	l_rd_cen_vref_nom_fc = l_rd_cen_vref_nom[i_port];
	find_best_margin(RD_VREF, l_left_margin_rd_vref_array,
                              l_right_margin_rd_vref_array, MAX_RD_VREF, l_rd_cen_vref_nom_fc, count);
	if (count >= MAX_RD_VREF)
        {
                FAPI_ERR("Read vref new input(%d) out of bounds, (>= %d)",
                            count, MAX_RD_VREF);
                FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
                return rc;
        }
	else
	{
	   
	 /* if(i_port == 0)
	    {
	        l_rd_cen_vref_new[0] = rd_cen_vref_array_fitness[count];
                l_rd_cen_vref_new[1] = l_rd_cen_vref_nom[1];
	    }
	    else
	    {
	        l_rd_cen_vref_new[1] = rd_cen_vref_array_fitness[count];
                l_rd_cen_vref_new[0] = l_rd_cen_vref_nom[0];
	    }
 
	    if(l_rd_cen_vref_new[i_port] != l_rd_cen_vref_nom[i_port])
	    {
	        //FAPI_INF("Best Margin Found on Vref : %dmv , %dmV on %s", l_rd_cen_vref_new[i_port], rd_cen_vref_array_fitness[count], i_target_mba.toEcmdString());
	        //rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RD_VREF, &i_target_mba, l_rd_cen_vref_new); 
	        //if (rc) return rc;
	        //FAPI_INF("Configuring New Read Vref Value to Registers:");
	        //rc = config_rd_cen_vref(i_target_mba, i_port, l_rd_cen_vref_new[i_port]); 
                //if (rc) return rc;
	    }
	    else
	    {*/
	       // FAPI_INF("Nominal value will not be changed!- Restoring the original values!");	
	        FAPI_INF("Restoring Nominal values!");	
	        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RD_VREF, &i_target_mba, l_rd_cen_vref_nom); 
	        if (rc) return rc;
	        rc = config_rd_cen_vref(i_target_mba, i_port, l_rd_cen_vref_nom[i_port]); 
                if (rc) return rc;
	   // }
	}
    FAPI_INF("Restoring mcbist setup attribute...");
	rc = reset_attribute(i_target_mba); if (rc) return rc;
    FAPI_INF("++++ Centaur Read Vref Shmoo function executed successfully ++++");
    }
return rc;
}

//------------------------------------------------------------------------------
// Function name: rcv_imp_shmoo()
// Receiver impedance shmoo function varies 9 values
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//------------------------------------------------------------------------------
fapi::ReturnCode rcv_imp_shmoo(const fapi::Target & i_target_mba,
			 uint8_t i_port,
			 shmoo_type_t i_shmoo_type_valid)
{
    fapi::ReturnCode rc;
    uint8_t l_rcv_imp_dq_dqs[MAX_PORT] = {0};
    uint8_t l_rcv_imp_dq_dqs_nom[MAX_PORT] = {0};
    uint8_t l_rcv_imp_dq_dqs_nom_fc = 0;
    uint8_t l_rcv_imp_dq_dqs_in = 0;
    //uint8_t l_rcv_imp_dq_dqs_new[MAX_PORT] = {0};
    uint32_t l_rcv_imp_dq_dqs_schmoo[MAX_PORT] = {0};
    uint8_t index = 0;
    uint8_t count  = 0;
    uint8_t shmoo_param_count = 0;
    i_shmoo_type_valid = RD_EYE;   //Hard coded since no other shmoo is applicable - Temporary
    
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint32_t l_left_margin_rcv_imp_array[MAX_RCV_IMP] = {0};
    uint32_t l_right_margin_rcv_imp_array[MAX_RCV_IMP] = {0};
       
		
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS, &i_target_mba, l_rcv_imp_dq_dqs_nom);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO, &i_target_mba, l_rcv_imp_dq_dqs_schmoo);
    if (rc) return rc;
    
    FAPI_INF("+++++++++++++++++RECIVER IMP Read Shmoo Attributes values+++++++++++++++");
    FAPI_INF("CEN_RCV_IMP_DQ_DQS[0]  = %d , CEN_RCV_IMP_DQ_DQS[1]  = %d on %s", l_rcv_imp_dq_dqs_nom[0],l_rcv_imp_dq_dqs_nom[1], i_target_mba.toEcmdString());
    FAPI_INF("CEN_RCV_IMP_DQ_DQS_SCHMOO[0] = [%d], CEN_RCV_IMP_DQ_DQS_SCHMOO[1] = [%d], on %s", l_rcv_imp_dq_dqs_schmoo[0],l_rcv_imp_dq_dqs_schmoo[1], i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    if(l_rcv_imp_dq_dqs_schmoo[i_port] == 0)
    {
	FAPI_INF("FAST Shmoo Mode: This function will not change any Write DRAM VREF settings");
    }
    else
    {
        for(index = 0; index< MAX_RCV_IMP; index+=1)
        {
            if ((l_rcv_imp_dq_dqs_schmoo[i_port] & MASK) == 1)
            {
   	        l_rcv_imp_dq_dqs[i_port] = rcv_imp_array[index];
		FAPI_INF("Current Receiver Impedance: %d Ohms ", rcv_imp_array[index]);
		FAPI_INF("Configuring Receiver impedance registers:");
  	        rc = config_rcv_imp(i_target_mba, i_port, l_rcv_imp_dq_dqs[i_port]); if (rc) return rc;
		l_rcv_imp_dq_dqs_in = l_rcv_imp_dq_dqs[i_port];
		//FAPI_INF("Calling Shmoo function to find out timing margin:");
		if (shmoo_param_count) 
		{
			rc = set_attribute(i_target_mba);
  	                if (rc) return rc;
		}
	        rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid, 
			     &l_left_margin, &l_right_margin, l_rcv_imp_dq_dqs_in);
	        if (rc) return rc;
		l_left_margin_rcv_imp_array[index]= l_left_margin;
	        l_right_margin_rcv_imp_array[index]= l_right_margin;
		 shmoo_param_count++;
	    }
	    else
	    {
		l_left_margin_rcv_imp_array[index]= 0;
	        l_right_margin_rcv_imp_array[index]= 0;
	    }
	    l_rcv_imp_dq_dqs_schmoo[i_port] = (l_rcv_imp_dq_dqs_schmoo[i_port] >> 1);
	}
	l_rcv_imp_dq_dqs_nom_fc = l_rcv_imp_dq_dqs_nom[i_port];
	find_best_margin(RCV_IMP, l_left_margin_rcv_imp_array,
                               l_right_margin_rcv_imp_array, MAX_RCV_IMP, l_rcv_imp_dq_dqs_nom_fc, count);
	if (count >= MAX_RCV_IMP)
        {
                FAPI_ERR("Receiver Imp new input(%d) out of bounds, (>= %d)",
                            count, MAX_RCV_IMP);
                FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
                return rc;
        }
	else
	{
	   
	  /*  if(i_port == 0)
	    {
	        l_rcv_imp_dq_dqs_new[0] = rcv_imp_array[count];
	        l_rcv_imp_dq_dqs_new[1] = l_rcv_imp_dq_dqs_nom[1];  // This can be removed once the get/set attribute takes care of this
	    }
	    else
	    {
	        l_rcv_imp_dq_dqs_new[1] = rcv_imp_array[count];
	        l_rcv_imp_dq_dqs_new[0] = l_rcv_imp_dq_dqs_nom[0];
	    }*/
	   // if (l_rcv_imp_dq_dqs_new[i_port] != l_rcv_imp_dq_dqs_nom[i_port])
	   // {
	        //FAPI_INF("Better Margin found on %d on %s", l_rcv_imp_dq_dqs_new[i_port], i_target_mba.toEcmdString());
	        //rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS, &i_target_mba, l_rcv_imp_dq_dqs_new); 
	        //if (rc) return rc;
	        //rc = config_rcv_imp(i_target_mba, i_port, l_rcv_imp_dq_dqs_new[i_port]);
	        //if (rc) return rc;
	   // }
	   // else
	   // {
	     //   FAPI_INF("Nominal value will not be changed!- Restoring the original values!");	
	        FAPI_INF("Restoring the nominal values!");	
	        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS, &i_target_mba, l_rcv_imp_dq_dqs_nom); 
	        if (rc) return rc;
	        rc = config_rcv_imp(i_target_mba, i_port, l_rcv_imp_dq_dqs_nom[i_port]);
                if (rc) return rc;
	   // }
	}
    FAPI_INF("Restoring mcbist setup attribute...");
	rc = reset_attribute(i_target_mba); if (rc) return rc;
    FAPI_INF("++++ Receiver Impdeance Shmoo function executed successfully ++++");
    }
return rc;  
}

//------------------------------------------------------------------------------
// Function name:delay_shmoo()
// Calls Delay shmoo function varies delay values of each dq and returns timing margin
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
// Output param: l_left_margin = Left Margin(Setup time), 
// l_right_margin = Right Margin (Hold time) in ps
//------------------------------------------------------------------------------

fapi::ReturnCode delay_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
		       shmoo_type_t i_shmoo_type_valid,
		       uint32_t *o_left_margin,
		       uint32_t *o_right_margin,
		       uint32_t i_shmoo_param)
{
    fapi::ReturnCode rc;
    //FAPI_INF(" Inside the delay shmoo " );
    //Constructor CALL: generic_shmoo::generic_shmoo(uint8_t i_port, uint32_t shmoo_mask,shmoo_algorithm_t shmoo_algorithm)
    //generic_shmoo mss_shmoo=generic_shmoo(i_port,2,SEQ_LIN);
    generic_shmoo mss_shmoo=generic_shmoo(i_port,i_shmoo_type_valid,SEQ_LIN);
    rc = mss_shmoo.run(i_target_mba, o_left_margin, o_right_margin,i_shmoo_param);
    if(rc)
    {
        FAPI_ERR("Delay Schmoo Function is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
	return rc;
    }
return rc;
}


//------------------------------------------------------------------------------
//Function name: set_attributes()
//Description: Sets the attribute used  by all functions
//------------------------------------------------------------------------------

fapi::ReturnCode set_attribute(const fapi::Target & i_target_mba)
{
   fapi::ReturnCode rc;
   uint8_t l_mcbist_setup_multiple_set = 1;  //Hard coded it wont change
   rc =  FAPI_ATTR_SET(ATTR_SCHMOO_MULTIPLE_SETUP_CALL, &i_target_mba, l_mcbist_setup_multiple_set);
   return rc;
}

//------------------------------------------------------------------------------
//Function name: reset_attributes()
//Description: Sets the attribute used  by all functions
//------------------------------------------------------------------------------

fapi::ReturnCode reset_attribute(const fapi::Target & i_target_mba)
{
   fapi::ReturnCode rc;
   uint8_t l_mcbist_setup_multiple_reset = 0; //Hard coded it wont change
   rc = FAPI_ATTR_SET(ATTR_SCHMOO_MULTIPLE_SETUP_CALL, &i_target_mba, l_mcbist_setup_multiple_reset);
   return rc;
}

//------------------------------------------------------------------------------
// Function name:find_best_margin()
// Finds better timing margin and returns the index
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// i_left[], i_right[] - timing margin arrays, i_max = Max enum value of schmoo param
// i_param_nom = selected shmoo parameter (DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// Output param: o_index (returns index)
//------------------------------------------------------------------------------


void find_best_margin(shmoo_param i_shmoo_param_valid,
			    uint32_t i_left[],
			    uint32_t i_right[],
			    const uint8_t i_max,
			    uint32_t i_param_nom,
			    uint8_t& o_index)
{
    uint32_t left_margin = 0;
    uint32_t right_margin = 0;
    uint32_t left_margin_nom = 0;
    uint32_t right_margin_nom = 0;
    uint32_t diff_margin_nom = 0;
    //uint32_t total_margin = 0;
    uint32_t diff_margin = 0;
    uint8_t index = 0;
    uint8_t index2 = 0;
   
     
    for(index = 0; index < i_max; index+=1) //send max from top function
    {
	if(i_shmoo_param_valid & DRV_IMP)
	{
	    if (drv_imp_array[index] == i_param_nom)
	    {
        	left_margin_nom = i_left[index];
	        right_margin_nom = i_right[index];
	        diff_margin_nom = (i_left[index] >= i_right[index]) ? (i_left[index] - i_right[index]) : (i_right[index] - i_left[index]);
	        //FAPI_INF("Driver impedance value (NOM): %d Ohms  Setup Margin: %d Hold Margin: %d", i_param_nom, i_left[index], i_right[index]);
	       break;
	    }
        }
        else if(i_shmoo_param_valid & SLEW_RATE)
        {
	    if (slew_rate_array[index] == i_param_nom)
	    {
        	left_margin_nom = i_left[index];
	        right_margin_nom = i_right[index];
	        diff_margin_nom = (i_left[index] >= i_right[index]) ? (i_left[index] - i_right[index]) : (i_right[index] - i_left[index]);
	        //FAPI_INF("Slew rate value (NOM): %d V/ns  Setup Margin: %d Hold Margin: %d", i_param_nom, i_left[index], i_right[index]);
	        break;
	    }
        }
        else if(i_shmoo_param_valid & WR_VREF)
        {   
	    if (wr_vref_array_fitness[index] == i_param_nom)
	    {
        	left_margin_nom = i_left[index];
	        right_margin_nom = i_right[index];
	        diff_margin_nom = (i_left[index] >= i_right[index]) ? (i_left[index] - i_right[index]) : (i_right[index] - i_left[index]);
	        //FAPI_INF("Write DRAM Vref Multiplier value (NOM): %d   Setup Margin: %d Hold Margin: %d", i_param_nom, i_left[index], i_right[index]);
	        break;
	    }
	}
        else if(i_shmoo_param_valid & RD_VREF)
        {	    
	    if (rd_cen_vref_array_fitness[index] == i_param_nom)
	    {
        	left_margin_nom = i_left[index];
	        right_margin_nom = i_right[index];
	        diff_margin_nom = (i_left[index] >= i_right[index]) ? (i_left[index] - i_right[index]) : (i_right[index] - i_left[index]);
	        //FAPI_INF("Centaur Read Vref Multiplier value (NOM): %d  Setup Margin: %d Hold Margin: %d", i_param_nom, i_left[index], i_right[index]);
	        break;
	    }
        }
        else if(i_shmoo_param_valid & RCV_IMP)
        {	    
	    if (rcv_imp_array[index] == i_param_nom)
	    {
        	left_margin_nom = i_left[index];
	        right_margin_nom = i_right[index];
	        diff_margin_nom = (i_left[index] >= i_right[index]) ? (i_left[index] - i_right[index]) : (i_right[index] - i_left[index]);
	       // FAPI_INF("Receiver Impedance value (NOM): %d Ohms  Setup Margin: %d Hold Margin: %d", i_param_nom, i_left[index], i_right[index]);
		    break;	        
	    }
        }
	    
    }
    for(index2 = 0; index2 < i_max; index2+=1)
    {
    	left_margin = i_left[index2];
	right_margin = i_right[index2];
	//total_margin = i_left[index2] + i_right[index2];
	diff_margin = (i_left[index2] >= i_right[index2]) ? (i_left[index2] - i_right[index2]) : (i_right[index2] - i_left[index2]);
	if ((left_margin > 0 && right_margin > 0))
	{
	    if((left_margin >= left_margin_nom) && (right_margin >= right_margin_nom) && (diff_margin <= diff_margin_nom))
	    {
 	        o_index = index2;
		//wont break this loop, since the purpose is to find the best parameter value & best timing margin The enum is constructed to do that
	    //  FAPI_INF("Index value %d, Min Setup Margin: %d, Min Hold Margin: %d", o_index, i_left[index2], i_right[index2]);
  	    }
	}
    }
}
