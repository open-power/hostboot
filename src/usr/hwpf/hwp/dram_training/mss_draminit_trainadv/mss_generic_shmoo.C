/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_generic_shmoo.C $ */
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

// $Id: mss_generic_shmoo.C,v 1.77 2013/10/21 06:05:32 sasethur Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : mss_generic_shmoo.C
// *! TITLE                : MSS Generic Shmoo Implementation 
// *! DESCRIPTION          : Memory Subsystem Generic Shmoo -- abstraction for HB
// *! CONTEXT              : To make all shmoos share a common abstraction layer
// *!
// *! OWNER  NAME          : Abhijit Saurabh          Email: abhijit.saurabh@in.ibm.com
// *! BACKUP NAME          : Siddharth Vijay      	  Email: sidvijay@in.ibm.com
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:   | Comment:
// --------|--------|---------|--------------------------------------------------
//   1.77  |abhijit	|21-oct-13| fixed the printing for tdqss min and tdqss max  
//   1.76  |abhijit	|17-oct-13| fixed the printing for dqs by 4  
//   1.74  |abhijit	|4-oct-13 | fixed fw comments 
//   1.73  |abhijit	|1-oct-13 | fixed write dqs by 8 for isdimm 
//   1.72  |abhijit	|20-sep-13| fixed printing of rd eye report as -1 for not finding left bound 
//   1.71  |abhijit	|18-sep-13| changed for mcbist call  
//   1.70  |abhijit	|12-sep-13| Fixed binary debug prints 
//   1.69  |abhijit	|12-sep-13| Fixed binary debug prints    
//   1.68  |abhijit	|11-sep-13| Added Binary Schmoo algorithm   
//   1.67  |abhijit	|4-sep-13 | fixed fw comment  
//   1.65  |abhijit	|8-aug-13 | added binary schmoo first phase and modified training call 
//   1.64  |abhijit	|17-jul-13| added rd dqs phase 2 
//   1.63  |abhijit	|19-jun-13| fixed warnings in schmoo  
//   1.61  |abhijit	|11-jun-13| added read dqs and removed prints and single mcbist setup    
//   1.59  |abhijit	|26-may-13| removed unnecessary prints   
//   1.57  |abhijit	|21-may-13| fixed DQS report printing   
//   1.56  |abhijit	|14-may-13| Updated call to setup_mcbist  
//   1.55  |abhijit	|10-may-13| fixed firmware review comments  
//   1.51  |abhijit	|10-may-13| optimized write dqs schmoo 
//   1.49  |abhijit	|8-may-13 | Changed Write dqs reporting and optimized schmoo for running faster
//   1.48  |sauchadh|7-may-13 | Added ping pong for wr_dqs shmoo       
//   1.45  |abhijit |04/25/13 | added test type SIMPLE_FIX_RF and SHMOO_STRESS  
//   1.40  |abhijit |03/22/13 | Fixed boundary checks  
//   1.38  |abhijit |03/19/13 | included spare byte and ECC and fixed printing for RD_EYE 
//   1.36  |abhijit |03/19/13 | changed mcbist call position   
//   1.35  |abhijit |03/16/13 | fixed clearing of error map regs for mba23  
//   1.32  |abhijit |03/12/13 | new parallel schmoo under dev 
//   1.27  |abhijit |01/21/13 | fixed ISDIMM mapping need some workaround 
//   1.26  |abhijit |01/21/13 | fixed fw comments  
//   1.25  |abhijit |01/21/13 | fixed the constructor definition 
//   1.21  |sasethur|01/17/13 | Updated for sanity mcbist function
//   1.20  |abhijit |01/11/13 | Updated for change in setup_mcbist function
//   1.19  |aditya  |01/07/13 | Updated for change in setup_mcbist function
//   1.18  |sasethur|14-DEC-12| Updated for change in access delay function 
//   1.16  |sasethur|14-DEC-12| Updated for Warning 
//   1.15  |abhijit |13-DEC-12| Updated for FW review comments 
//   1.14  |abhijit |06-DEC-12| Fixed more FW review comments
//   1.12  |abhijit |15-Nov-12| Fixed FW review comments
//   1.11  |abhijit |29-Oct-12| added change for ISDIMM checker DQS.
//   1.9   |abhijit |22-Oct-12| added Write and read DQS.  
//   1.8   |abhijit |15-Oct-12| Updated multiple changes 
//   1.0   |varkeykv|27-Sep-11| Initial check in
//------------------------------------------------------------------------------
#include <fapi.H>
#include "mss_generic_shmoo.H"
#include "mss_mcbist.H"
#include <mss_draminit_training.H>
// #include <mss_funcs.H>
// #include <mss_unmask_errors.H>
#include <dimmBadDqBitmapFuncs.H>
#include <mss_access_delay_reg.H>

//#define DBG 0

extern "C"
{
using namespace fapi;

// START IMPLEMENTATION OF generic_shmoo CLASS METHODS 
//! shmoo_mask - What shmoos do you want to run ... encoded as Hex 0x2,0x4,0x8,0x16
/*------------------------------------------------------------------------------
 * constructor: generic_shmoo
 * Description  :Constructor used to initialize variables and do the initial settings 
 *
 * Parameters: i_target: mba;		iv_port: 0, 1
 * ---------------------------------------------------------------------------*/
generic_shmoo:: generic_shmoo(uint8_t addr,shmoo_type_t shmoo_mask,shmoo_algorithm_t shmoo_algorithm)
{
    //this->shmoo_mask=shmoo_mask; //! Sets what Shmoos the caller wants to run
    this->algorithm=shmoo_algorithm ;
    this->iv_addr=addr ;
    
    
    //iv_MAX_RANKS=8;
    iv_MAX_BYTES=10;
    iv_DQS_ON=0;
    iv_pattern=0;
    iv_test_type=0;
    iv_dmm_type=0;
    iv_shmoo_param=0;
	iv_binary_diff=2;
	iv_vref_mul=0;
	
	for(int p=0;p<MAX_PORT;++p)
    {
    for(int i=0;i<iv_MAX_RANKS[p];++i)
    {
        valid_rank[i]=0;
    }
	}
	
	for(int p=0;p<MAX_PORT;++p)
    {
   iv_MAX_RANKS[p]=4;
	}
    
    FAPI_DBG("mss_generic_shmoo : constructor running for shmoo type %d",shmoo_mask);
    iv_shmoo_type = 0;
	SHMOO[iv_shmoo_type].static_knob.min_val=0;
    SHMOO[iv_shmoo_type].static_knob.max_val=512; 
	
	
	if(shmoo_mask & TEST_NONE)
    {
        FAPI_INF("mss_generic_shmoo : NONE selected %d",shmoo_mask);
        iv_shmoo_type = 0;
        SHMOO[0].static_knob.min_val=0;
        SHMOO[0].static_knob.max_val=512;   
    }
    
    if(shmoo_mask & WR_EYE)
    {
        FAPI_INF("mss_generic_shmoo : WR_EYE selected %d",shmoo_mask);
        iv_shmoo_type = 2;
        SHMOO[0].static_knob.min_val=0;
        SHMOO[0].static_knob.max_val=512;   
    }
    if(shmoo_mask & RD_EYE)
    {
        FAPI_INF("mss_generic_shmoo : RD_EYE selected %d",shmoo_mask);
        iv_shmoo_type = 8;
        SHMOO[2].static_knob.min_val=2;
        SHMOO[2].static_knob.max_val=128;
    }
	
     if(shmoo_mask & WRT_DQS) //preet
    {
        FAPI_INF("mss_generic_shmoo : WRT_DQS selected %d",shmoo_mask);
        iv_shmoo_type = 4;
		iv_DQS_ON = 1;
        SHMOO[1].static_knob.min_val=0;
        SHMOO[1].static_knob.max_val=512;
    }
	
    if(shmoo_mask & RD_GATE) //preet
    {
        FAPI_INF("mss_generic_shmoo : RD_GATE selected %d",shmoo_mask);
        
        iv_shmoo_type = 16;
	iv_DQS_ON = 2;
        SHMOO[3].static_knob.min_val=2;
        SHMOO[3].static_knob.max_val=128;
    }
	if(iv_DQS_ON==1){
	for(int i=0;i<MAX_PORT;++i)
    {
    for(int j=0;j<iv_MAX_RANKS[i];++j)
    {
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.nom_val,0);
		init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.right_err_cnt,0);
		init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.left_err_cnt,0);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.lb_regval,SHMOO[iv_shmoo_type].static_knob.min_val);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.rb_regval,SHMOO[iv_shmoo_type].static_knob.max_val);
		init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.lb_regval,20);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.rb_regval,300);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.total_margin,0);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.right_margin_val,0);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.left_margin_val,0);
    }
	}}else{
	// for(int i=0;i<MAX_PORT;++i)
    // {
	
	// init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[0].K.cmd_nom_val,0);
	// init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[0].K.offset,0);
	// init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[0].K.addr_nom_val,0);
	// init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[0].K.cntrl_nom_val,0);
		
        
		// init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[0].K.cmd_lb_regval,20);
        // init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[0].K.cmd_rb_regval,300);
        // init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[0].K.cmd_total_margin,0);
        // init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[0].K.cmd_right_margin_val,0);
        // init_multi_array(SHMOO[iv_shmoo_type].MBA.P[i].S[0].K.cmd_left_margin_val,0);
		// }
	}
	// if(iv_DQS_ON == 1)
	// {	for(int i=0;i<MAX_PORT;++i)
		// {
		// for(int j=0;j<iv_MAX_RANKS[i];++j) //initialize values for DQS
        // {
            // init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.nom_val,0);
            // // init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.lb_regval,SHMOO[iv_shmoo_type].static_knob.min_val);
            // // init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.rb_regval,SHMOO[iv_shmoo_type].static_knob.max_val);
			// init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.lb_regval,20);
            // init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.rb_regval,300);
            // init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.total_margin,0);
	    // init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.right_margin_val,0);
	    // init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[i].S[j].K.left_margin_val,0);
        // }
		// }
	// }
}

fapi::ReturnCode generic_shmoo::shmoo_save_rest(const fapi::Target & i_target,uint64_t i_content_array[],uint8_t i_mode)
{
    ReturnCode rc;
	uint32_t rc_num;
	uint8_t l_index = 0;
	uint64_t l_value = 0;
	uint64_t l_val_u64 = 0;
	ecmdDataBufferBase l_shmoo1ab(64);	
	uint64_t l_Databitdir[10] = {0x800000030301143full,0x800004030301143full,0x800008030301143full,0x80000c030301143full,0x800010030301143full,0x800100030301143full,0x800104030301143full,
	0x800108030301143full,0x80010c030301143full,0x800110030301143full};
	if(i_mode == 0)
	{
		FAPI_INF(" Saving DP18 data bit direction register contents");
		for(l_index = 0;l_index<MAX_BYTE;l_index++)
		{ 	
			l_value = l_Databitdir[l_index];
			rc = fapiGetScom(i_target,l_value,l_shmoo1ab); if(rc) return rc;
			rc_num =  l_shmoo1ab.setBit(57);
			rc = fapiPutScom(i_target,l_value,l_shmoo1ab); if(rc) return rc;	
			i_content_array[l_index] = l_shmoo1ab.getDoubleWord (0);
			
			
		}
	}
	
	else if(i_mode == 1)
	{
		FAPI_INF(" Restoring DP18 data bit direction register contents");	
		for(l_index = 0;l_index<MAX_BYTE;l_index++)
		{ 	
			l_val_u64 = i_content_array[l_index];
			l_value = l_Databitdir[l_index];
			rc_num  =  l_shmoo1ab.setDoubleWord(0,l_val_u64);if (rc_num){FAPI_ERR( "Error in function  shmoo_save_rest:");rc.setEcmdError(rc_num);return rc;} 
			rc = fapiPutScom(i_target,l_value,l_shmoo1ab); if(rc) return rc;				
		}	
	}
	else
	{
		FAPI_INF("Invalid value of MODE");
	}
	return rc;

}






/*------------------------------------------------------------------------------
 * Function: run
 * Description  : ! Delegator function that runs shmoo using other  functions
 *
 * Parameters: i_target: mba;		iv_port: 0, 1
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::run(const fapi::Target & i_target,uint32_t *o_right_min_margin,uint32_t *o_left_min_margin,uint32_t i_vref_mul){
    fapi::ReturnCode rc;  
    uint8_t num_ranks_per_dimm[2][2];
    uint8_t l_attr_eff_dimm_type_u8=0;
    uint8_t l_attr_schmoo_test_type_u8=0;
	uint8_t l_attr_schmoo_multiple_setup_call_u8=0;
	uint8_t l_mcbist_prnt_off = 0;
	
	 
    uint64_t i_content_array[10];
    uint8_t l_rankpgrp0[2]={0};
    uint8_t l_rankpgrp1[2]={0};
    uint8_t l_rankpgrp2[2]={0};
    uint8_t l_rankpgrp3[2]={0};
    uint8_t l_totrg_0=0;
    uint8_t l_totrg_1=0;
    uint8_t l_pp=0;
	uint8_t pass=0;
	uint8_t l_shmoo_param=0;
    
	rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_MODE, &i_target, l_shmoo_param); if(rc) return rc;
    //uint8_t l_val=2;
	iv_shmoo_param=l_shmoo_param;
	iv_vref_mul=i_vref_mul;
	
    ecmdDataBufferBase l_data_buffer1_64(64);
    uint8_t l_dram_width=0;
    
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_dram_width); if(rc) return rc;
    
    rc = FAPI_ATTR_SET(ATTR_MCBIST_PRINTING_DISABLE, &i_target, l_mcbist_prnt_off); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_per_dimm); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, l_attr_eff_dimm_type_u8); if(rc) return rc; 
    rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target, l_attr_schmoo_test_type_u8); if(rc) return rc;
	rc = FAPI_ATTR_GET(ATTR_SCHMOO_MULTIPLE_SETUP_CALL, &i_target, l_attr_schmoo_multiple_setup_call_u8); if(rc) return rc;
    
    
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &i_target, l_rankpgrp0);if(rc) return rc;
    	
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &i_target, l_rankpgrp1);if(rc) return rc;
     
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &i_target, l_rankpgrp2);if(rc) return rc;
    
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &i_target, l_rankpgrp3);if(rc) return rc;
    
    
    
    iv_MAX_RANKS[0]=num_ranks_per_dimm[0][0]+num_ranks_per_dimm[0][1];
    iv_MAX_RANKS[1]=num_ranks_per_dimm[1][0]+num_ranks_per_dimm[1][1];
	
    iv_pattern=0;
    iv_test_type=0;
    
    
    
    
    if ( l_attr_eff_dimm_type_u8 == 0 )
    {
	iv_MAX_BYTES=10;
    }
    else
    {
	
	iv_dmm_type=1;
	iv_MAX_BYTES=9;
    }
    //rc = mss_getrankpair(i_target,iv_port,0,&rank_pair,valid_rank);if(rc) return rc; 
    FAPI_DBG("mss_generic_shmoo : run() for shmoo type %d",shmoo_mask);
     // Check if all bytes/bits are in a pass condition initially .Otherwise quit
    if(l_attr_schmoo_test_type_u8 == 0){
	FAPI_INF("This procedure wont change any delay settings");
	return rc;
	}
	if(l_attr_schmoo_test_type_u8 == 1){
	rc=sanity_check(i_target); // Run MCBIST only when ATTR_EFF_SCHMOO_TEST_VALID is mcbist only 

    if(!rc.ok())
    {
    FAPI_ERR("generic_shmoo::run MSS Generic Shmoo failed initial Sanity Check. Memory not in an all pass Condition");
    return rc; 
    }
	}else if(l_attr_schmoo_test_type_u8 == 8){
	 if(l_rankpgrp0[0] !=255)
    {
    l_totrg_0++;
    }
    if(l_rankpgrp1[0] !=255)
    {
    l_totrg_0++;
    }
    if(l_rankpgrp2[0] !=255)
    {
    l_totrg_0++;
    }
    if(l_rankpgrp3[0] !=255)
    {
    l_totrg_0++;
    }
    
     if(l_rankpgrp0[1] !=255)
    {
    l_totrg_1++;
    }
    if(l_rankpgrp1[1] !=255)
    {
    l_totrg_1++;
    }
    if(l_rankpgrp2[1] !=255)
    {
    l_totrg_1++;
    }
    if(l_rankpgrp3[1] !=255)
    {
    l_totrg_1++;
    }
   if((l_totrg_0==1) || (l_totrg_1 ==1 ))
    {
    shmoo_save_rest(i_target,i_content_array,0);
    l_pp=1;
    }
    
    if(l_pp==1)
    {
    FAPI_INF("Ping pong is disabled");
    }
    else
    {
    FAPI_INF("Ping pong is enabled");	
    }
    
    if((l_pp=1) && ((l_totrg_0==1) || (l_totrg_1 ==1 )))
    {
	FAPI_INF("Rank group is not good with ping pong. Hope you have set W2W gap to 10");
    }
    
	
	iv_shmoo_type=4;
	//FAPI_INF("\n ABHIJIT IS HERE 1111  \n");
	rc=get_all_noms_dqs(i_target);if(rc) return rc;
	iv_shmoo_type=2;
	//FAPI_INF("\n ABHIJIT IS HERE 2222  \n");
	rc=get_all_noms(i_target);if(rc) return rc;
	rc=schmoo_setup_mcb(i_target);if(rc) return rc;
    //Find RIGHT BOUND OR SETUP BOUND
    rc=find_bound(i_target,RIGHT);if(rc) return rc;
	//FAPI_INF("\n ABHIJIT IS HERE 3333  \n");
    //Find LEFT BOUND OR HOLD BOUND
    rc=find_bound(i_target,LEFT);if(rc) return rc;
	iv_shmoo_type=4;
	
	if(l_dram_width == 4 ){
	rc=get_margin_dqs_by4(i_target);if(rc) return rc;
	}else{
	//FAPI_INF("\n ABHIJIT IS HERE 222  \n");
	rc=get_margin_dqs_by8(i_target);if(rc) return rc;
	}
	//FAPI_INF("\n before the call \n");
	rc=print_report_dqs(i_target);if(rc) return rc;
	rc=get_min_margin_dqs(i_target,o_right_min_margin,o_left_min_margin);if(rc) return rc;
	
    if((l_totrg_0==1) || (l_totrg_1 ==1 ))
    {
    shmoo_save_rest(i_target,i_content_array,1);
    } 
	
	
	
	
	}else if(l_attr_schmoo_test_type_u8 == 16){
	
	if(iv_shmoo_param==2){
	rc=get_all_noms_data_disable(i_target);if(rc) return rc;
	rc=get_all_noms_gate(i_target);if(rc) return rc;
	
	rc=knob_update_gate_train(i_target,RIGHT,iv_shmoo_type,pass); if(rc) return rc; 
	}
	iv_DQS_ON=1;
	rc=schmoo_setup_mcb(i_target);if(rc) return rc;
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
	iv_DQS_ON=2;
	
	rc=schmoo_setup_mcb(i_target);if(rc) return rc;
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		//sanity check 
	rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
	
	
	rc=get_all_noms_gate(i_target);if(rc) return rc; 
	if(iv_shmoo_param==2){
	rc=find_bound(i_target,LEFT);if(rc) return rc;
	rc=put_all_noms_data_disable(i_target,0);if(rc) return rc;
	}else{
	rc=find_bound(i_target,RIGHT);if(rc) return rc;
	}
	rc=print_report_gate(i_target);if(rc) return rc;
	
	} else {
	// rc=sanity_check(i_target); // Run MCBIST by  default before for every schmoo to check if memory is in good condition. 
    // if(!rc.ok())
    // {
    // FAPI_ERR("generic_shmoo::run MSS Generic Shmoo failed initial Sanity Check. Memory not in an all pass Condition");
    // return rc; 
    // }
    // If memory is OK then we continue to gather nominals and config values
    //  Now Read nominal values for all knobs configured
    // FAPI_DBG("mss_generic_shmoo : run() :read nominal values ");
	
	
    rc=get_all_noms(i_target);if(rc) return rc;
	if(l_attr_schmoo_multiple_setup_call_u8==0){
	rc=schmoo_setup_mcb(i_target);if(rc) return rc;
	}
	rc=set_all_binary(i_target,RIGHT);if(rc) return rc;
    //Find RIGHT BOUND OR SETUP BOUND
    rc=find_bound(i_target,RIGHT);if(rc) return rc;
	rc=set_all_binary(i_target,LEFT);if(rc) return rc;
    //Find LEFT BOUND OR HOLD BOUND
    rc=find_bound(i_target,LEFT);if(rc) return rc;
    //Find the margins in Ps i.e setup margin ,hold margin,Eye width 
    rc=get_margin(i_target);if(rc) return rc;
    //It is used to find the lowest of setup and hold margin
    rc=get_min_margin(i_target,o_right_min_margin,o_left_min_margin);if(rc) return rc;
    // It is used to print the schmoo report
    rc=print_report(i_target);if(rc) return rc;
	
	if(l_attr_schmoo_test_type_u8==8){
	  FAPI_INF(" Least tDQSSmin(ps)=%d ps and Least tDQSSmax=%d ps", *o_left_min_margin,*o_right_min_margin);
	  }else if(l_attr_schmoo_test_type_u8==16){
	  
	  }else{
	FAPI_INF(" Minimum hold margin=%d ps and setup margin=%d ps", *o_left_min_margin,*o_right_min_margin);
	}
    //shmoo_save_rest(i_target,i_content_array,1);
	}
	l_mcbist_prnt_off=0;
	rc = FAPI_ATTR_SET(ATTR_MCBIST_PRINTING_DISABLE, &i_target, l_mcbist_prnt_off); if(rc) return rc;
    return rc;
}
/*------------------------------------------------------------------------------
 * Function: sanity_check
 * Description  : do intial mcbist check in nominal and report spd if any bad bit found
 *
 * Parameters: i_target: mba;	
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::sanity_check(const fapi::Target & i_target){
    fapi:: ReturnCode rc;
    mcbist_mode=QUARTER_SLOW;
    //uint64_t l_time = 0x0000000000000000ull;
    uint8_t l_rank_valid = 0;
    uint8_t l_mcb_status=0;
	
	struct Subtest_info l_sub_info[30];
    
	FAPI_INF("  entering set_up mcbist now and rank %d",l_rank_valid);
	
	//rc = setup_mcbist(i_target, 0, MCBIST_2D_CUP_PAT8, CENSHMOO, UNMASK_ALL, 0,iv_pattern,iv_test_type,l_rank_valid,0,l_start,l_end,0);if(rc) return rc;  //send shmoo mode to vary the address range
	rc=schmoo_setup_mcb(i_target);if(rc) return rc;
	FAPI_INF("  starting  mcbist now");
	rc=start_mcb(i_target);if(rc) return rc;
	FAPI_INF("  polling   mcbist now");
	//rc=poll_mcb(i_target_mba,&mcb_status,l_sub_info1,0);if(rc) return rc;
	rc=poll_mcb(i_target,&l_mcb_status,l_sub_info,1);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: POLL MCBIST failed !!");  
			
        return rc;
    }
	FAPI_INF("  checking error map ");
	rc=mcb_error_map(i_target,mcbist_error_map);if(rc) return rc;
    
    
    if(l_mcb_status)
    {
        FAPI_ERR("generic_shmoo:sanity_check failed !! MCBIST failed on intial run , memory is not in good state aborting shmoo");
		 FAPI_SET_HWP_ERROR(rc,RC_MSS_MCBIST_ERROR);		
        return rc;
    }

    return rc;
}
/*------------------------------------------------------------------------------
 * Function: do_mcbist_reset
 * Description  : do mcbist reset
 *
 * Parameters: i_target: mba,iv_port 0/1 , rank 0-7 , byte 0-7, nibble 0/1, pass;	
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::do_mcbist_reset(const fapi::Target & i_target)
{
	fapi::ReturnCode rc;
    
	uint32_t rc_num =0;
	
	ecmdDataBufferBase l_data_buffer_64(64); 
	rc_num =  l_data_buffer_64.flushTo0();if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}
    //PORT - A
    rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMA1Q_0x0201166a,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMA2Q_0x0201166b,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMA3Q_0x0201166c,l_data_buffer_64); if(rc) return(rc);

    //PORT - B
    rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMB1Q_0x0201166d,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMB2Q_0x0201166e,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMB3Q_0x0201166f,l_data_buffer_64); if(rc) return(rc);
	
	// MBS 23
	rc = fapiPutScom(i_target,0x0201176a,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target,0x0201176b,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target,0x0201176c,l_data_buffer_64); if(rc) return(rc);

    //PORT - B
    rc = fapiPutScom(i_target,0x0201176d,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target,0x0201176e,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target,0x0201176f,l_data_buffer_64); if(rc) return(rc);
	
	// rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTA1Q_0x02011664,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTA2Q_0x02011665,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTB1Q_0x02011667,l_data_buffer_64); if(rc) return(rc);
	// rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTB2Q_0x02011668,l_data_buffer_64); if(rc) return(rc);
	
   return rc;
}
/*------------------------------------------------------------------------------
 * Function: do_mcbist_test
 * Description  : do mcbist check for error on particular nibble
 *
 * Parameters: i_target: mba,iv_port 0/1 , rank 0-7 , byte 0-7, nibble 0/1, pass;	
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::do_mcbist_test(const fapi::Target & i_target)
{
	fapi::ReturnCode rc;
    
	//uint32_t rc_num =0;
	uint8_t l_mcb_status=0;
	struct Subtest_info l_sub_info[30];
	//ecmdDataBufferBase l_data_buffer_64(64); 
	//rc_num =  l_data_buffer_64.flushTo0();if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}
    //PORT - A
    // rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMA1Q_0x0201166a,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMA2Q_0x0201166b,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMA3Q_0x0201166c,l_data_buffer_64); if(rc) return(rc);

    // //PORT - B
    // rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMB1Q_0x0201166d,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMB2Q_0x0201166e,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,MBS_MCBIST01_MCBEMB3Q_0x0201166f,l_data_buffer_64); if(rc) return(rc);
	
	// // MBS 23
	// rc = fapiPutScom(i_target,0x0201176a,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,0x0201176b,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,0x0201176c,l_data_buffer_64); if(rc) return(rc);

    // //PORT - B
    // rc = fapiPutScom(i_target,0x0201176d,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,0x0201176e,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,0x0201176f,l_data_buffer_64); if(rc) return(rc);
	
	// rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTA1Q_0x02011664,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTA2Q_0x02011665,l_data_buffer_64); if(rc) return(rc);
    // rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTB1Q_0x02011667,l_data_buffer_64); if(rc) return(rc);
	// rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTB2Q_0x02011668,l_data_buffer_64); if(rc) return(rc);
	
   rc = start_mcb(i_target);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: Start MCBIST failed !!");  
				
        return rc;
    }
    //rc=poll_mcb(i_target,false,&l_mcb_status);
	rc=poll_mcb(i_target,&l_mcb_status,l_sub_info,1);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: POLL MCBIST failed !!");  
			
        return rc;
    }
	//FAPI_INF("\n abhijit is here 1 \n");
    return rc;
	  
}
/*------------------------------------------------------------------------------
 * Function: check_error_map
 * Description  : used by do_mcbist_test  to check the error map for particular nibble
 *
 * Parameters: iv_port 0/1 , rank 0-7 , byte 0-7, nibble 0/1, pass;	
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::check_error_map(const fapi::Target & i_target,uint8_t port,uint8_t &pass)
{
 
 fapi::ReturnCode rc;
	uint8_t l_byte,l_rnk;
	uint8_t l_nibble;
	uint8_t l_byte_is;
	uint8_t l_nibble_is;
	uint8_t l_n=0;
	pass=1;
	uint8_t l_p=0;
    input_type l_input_type_e =  ISDIMM_DQ;
    uint8_t i_input_index_u8=0;
    uint8_t l_val =0;
	uint8_t i_rp=0;
	uint8_t rank=0;
	uint8_t l_max_byte=10;
	uint8_t l_max_nibble=20;
	
	if(iv_dmm_type==1)
		 {
		 l_max_byte=9;
		 l_max_nibble=18;
		 }
		 
	// rc=mcb_error_map(i_target,mcbist_error_map,port,i_rank);
    // if(rc)
    // {
        // FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        // return rc;
    // }
	
	 rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
    for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
    {// Byte loop
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rnk];
	
	l_n=0;
	for(l_byte=0;l_byte<l_max_byte;++l_byte)
		{	
		// if(l_byte==9){
		// if(iv_dmm_type==1)
		// {
		// continue;
		// }
		// }
		    //Nibble loop
		    for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
		    {
    if(iv_dmm_type==1)
    {
	i_input_index_u8=8*l_byte+4*l_nibble;
	//FAPI_INF("\n ISDIMM input byte=%d and nibble=%d and bit returned is %d \n",l_byte,l_nibble,l_val);
	rc=rosetta_map(i_target,l_p,l_input_type_e,i_input_index_u8,0,l_val);if(rc) return rc;
	//FAPI_INF("\n ISDIMM input byte=%d and nibble=%d and bit returned is %d \n",l_byte,l_nibble,l_val);
	l_byte_is=l_val/8;
	
	l_nibble_is=l_val%8;
	if(l_nibble_is>3){
	l_nibble_is=1;
	}else{
    l_nibble_is=0;
     }
	//FAPI_INF("\n the final byte and nibble is %d and %d  for rank=%d \n",l_byte_is,l_nibble_is,i_rank);
	if( mcbist_error_map [l_p][l_rnk][l_byte_is][l_nibble_is] == 1){
        //pass=0;
		schmoo_error_map[l_p][rank][l_n]=1;
        //FAPI_INF("We are in error and nibble is %d and rank is %d and port is %d \n",l_n,rank,l_p);
    }
    else
    {
		if(iv_shmoo_param==4){
		schmoo_error_map[l_p][rank][l_n]=0;
		}
        //pass=0;
        //FAPI_INF("We are in error2");
    }
    
    } else { 
    
 
    if( mcbist_error_map [l_p][l_rnk][l_byte][l_nibble] == 1){
        //pass=0;
		schmoo_error_map[l_p][rank][l_n]=1;
        //FAPI_INF("We are in error and nibble is %d and rank is %d and port is %d \n",l_n,rank,l_p);
    }
    else
    {
	if(iv_shmoo_param==4){
		schmoo_error_map[l_p][rank][l_n]=0;
		}
		//schmoo_error_map[l_p][rank][l_n]=0;
        //pass=0;
        //FAPI_INF("We are in error2");
    }
	}
	l_n++;
	}
	}
	}
	}
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
    {// Byte loop
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rnk];
	 for (l_n=0; l_n<l_max_nibble;l_n++){
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	 //FAPI_INF("\n the port=%d and nibble=%d and value for error map =%d \n",l_p,l_n,schmoo_error_map[l_p][rank][l_n]);
	 pass=0;
	 }
	 
	 }
	 }
	 }
    return rc;
}
//////////////// will implement later /////////////////////
/*
fapi::ReturnCode generic_shmoo::get_error_cnt(const fapi::Target & i_target,uint8_t port,uint8_t rank,uint8_t rank_pair,uint8_t bit,bound_t bound)
{
fapi::ReturnCode rc;
uint8_t l_nibble=0;
uint8_t l_start_bit=0;
uint16_t l_err_cnt_C=0;
uint8_t rc_ecmd=0;
uint8_t l_length_buffer=7;
uint8_t l_val=0;


input_type l_input_type_e =  ISDIMM_DQ;
ecmdDataBufferBase data_buffer_64(64);
ecmdDataBufferBase data_buffer_64_1(64);

if(iv_dmm_type==1)
    {
	
	//FAPI_INF("\n ISDIMM input byte=%d and nibble=%d and bit returned is %d \n",l_byte,l_nibble,l_val);
	rc=rosetta_map(i_target,port,l_input_type_e,bit,0,l_val);if(rc) return rc;
	//FAPI_INF("\n ISDIMM input byte=%d and nibble=%d and bit returned is %d \n",l_byte,l_nibble,l_val);
	l_nibble=l_val/4;
	
	}else{
	
l_nibble=bit/4;
}

if(port==0)
				{
				    if(l_nibble<9)
				    {
					rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTA1Q_0x02011664,data_buffer_64); if(rc) return rc;
					l_start_bit=l_nibble*7;
					rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
				    }
				    else
				    {
					rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTA2Q_0x02011665,data_buffer_64); if(rc) return rc;
					l_nibble=l_nibble-9;
					l_start_bit=l_nibble*7;
					rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
				    }
				}else
				{
				    if(l_nibble<9)
				    {
					rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTB1Q_0x02011667,data_buffer_64_1); if(rc) return rc;
					l_start_bit=l_nibble*7;
					rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
				    }
				    else
				    {
					rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTB2Q_0x02011668,data_buffer_64_1); if(rc) return rc;
					l_nibble=l_nibble-9;
					l_start_bit=l_nibble*7;
					rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
				    }
				}
				if(bound==RIGHT)
    {
		if(l_err_cnt_C){
		SHMOO[iv_shmoo_type].MBA.P[port].S[rank].K.right_err_cnt[bit][rank_pair]=l_err_cnt_C;	
		}
		FAPI_INF("\n THE PORT=%d Rank=%d dq=%d and error count=%d \n",port,rank,bit,SHMOO[iv_shmoo_type].MBA.P[port].S[rank].K.right_err_cnt[bit][rank_pair]);
	}else {
	if(l_err_cnt_C){
	SHMOO[iv_shmoo_type].MBA.P[port].S[rank].K.left_err_cnt[bit][rank_pair]=l_err_cnt_C;	
}	
		FAPI_INF("\n THE PORT=%d Rank=%d dq=%d and error count=%d \n",port,rank,bit,SHMOO[iv_shmoo_type].MBA.P[port].S[rank].K.left_err_cnt[bit][rank_pair]);
		}
	return rc;	
				
}				

*/

/*------------------------------------------------------------------------------
 * Function: init_multi_array
 * Description  : This function do the initialization of various schmoo parameters
 *
 * Parameters: the array address and the initial value
 * ---------------------------------------------------------------------------*/
void  generic_shmoo::init_multi_array(uint32_t (&array)[MAX_DQ][MAX_RPS],uint32_t init_val)
{
    
    uint8_t l_byte,l_nibble,l_bit,l_rp;
    uint8_t l_dq=0;
    for (l_rp=0;l_rp<MAX_RPS;++l_rp)
    {// Byte loop
		
        for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
        {   //Nibble loop
            for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
            { 
		//Bit loop
                for(l_bit=0;l_bit<MAX_BITS;++l_bit)
                {  
		    l_dq=8*l_byte+4*l_nibble+l_bit;
		    array[l_dq][l_rp]=init_val;
		}	
            }
        }
    }

}
/*------------------------------------------------------------------------------
 * Function: init_multi_array_dqs
 * Description  : This function do the initialization of various schmoo parameters
 *
 * Parameters: the array address and the initial value
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::init_multi_array_dqs(uint32_t (&array)[MAX_DQ][MAX_RPS],uint32_t init_val)
{
    fapi::ReturnCode rc;
    uint8_t l_byte,l_nibble,l_bit,l_rp;
    uint8_t l_dq=0;
    for (l_rp=0;l_rp<MAX_RPS;++l_rp)
    {// Byte loop
		
        for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
        {   //Nibble loop
            for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
            { 
		//Bit loop
                for(l_bit=0;l_bit<MAX_BITS;++l_bit)
                {  
		    l_dq=8*l_byte+4*l_nibble+l_bit;
		    array[l_dq][l_rp]=init_val;
		}	
            }
        }
    }
return rc;
}
/*------------------------------------------------------------------------------
 * Function: get_all_noms
 * Description  : This function gets the nominal values for each DQ 
 *
 * Parameters: Target:MBA 
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::get_all_noms(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    
    uint8_t l_rnk,l_byte,l_nibble,l_bit;
    uint8_t i_rnk=0;
    uint8_t i_rp=0;
    uint32_t val=0;
    uint8_t l_dq=0;
	uint8_t l_p=0;
             
    input_type_t l_input_type_e = WR_DQ;
    access_type_t l_access_type_e = READ ;
    FAPI_DBG("mss_generic_shmoo : get_all_noms : Reading in all nominal values");
    
    
             if(iv_shmoo_type == 4)
            {   
		l_input_type_e = WR_DQS;
                
            }
            else if(iv_shmoo_type == 8)
            {   
		
		l_input_type_e = RD_DQ;
                
            }
            else if(iv_shmoo_type == 3)
            {   
		
		l_input_type_e = RD_DQS;
                   
            }
            
	 for (l_p=0;l_p<MAX_PORT;l_p++){
    for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
    {// Byte loop
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		i_rnk=valid_rank[l_rnk];
		    rc = mss_getrankpair(i_target,l_p,i_rnk,&i_rp,valid_rank);if(rc) return rc; 
        for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
        {   //Nibble loop
            for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
            { 
		//Bit loop
                for(l_bit=0;l_bit<MAX_BITS;++l_bit)
                {  
		    l_dq=8*l_byte+4*l_nibble+l_bit;
		    
		    rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,i_rnk,l_input_type_e,l_dq,0,val);if(rc) return rc; 
		    SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.nom_val[l_dq][i_rp]=val;
			#ifdef DBG 
		    FAPI_INF("Nominal  Value for port=%d rank=%d  and rank pair=%d and dq=%d is  %d",l_p,i_rnk,i_rp,l_dq,val);
             #endif       
		}
	    }
	}
    }
}	
    return rc;
}
fapi::ReturnCode generic_shmoo::set_all_binary(const fapi::Target & i_target,bound_t bound)
{
    fapi::ReturnCode rc;
    
    uint8_t l_rnk,l_byte,l_nibble,l_bit;
    uint8_t i_rnk=0;
    uint8_t i_rp=0;
    
    uint8_t l_dq=0;
	uint8_t l_p=0;
	uint32_t l_max=512;
	uint32_t l_max_offset=64;
	
             
    if(iv_shmoo_type == 8)
            {   
		
		l_max=127;
                
            }
            
	 for (l_p=0;l_p<MAX_PORT;l_p++){
    for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
    {// Byte loop
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		i_rnk=valid_rank[l_rnk];
		    rc = mss_getrankpair(i_target,l_p,i_rnk,&i_rp,valid_rank);if(rc) return rc; 
        for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
        {   //Nibble loop
            for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
            { 
		//Bit loop
                for(l_bit=0;l_bit<MAX_BITS;++l_bit)
                {  
		    l_dq=8*l_byte+4*l_nibble+l_bit;
		    
		    //rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,i_rnk,l_input_type_e,l_dq,0,val);if(rc) return rc; 
			SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.last_pass[l_dq][i_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.nom_val[l_dq][i_rp];
			SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.curr_val[l_dq][i_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.nom_val[l_dq][i_rp];
			if(bound==RIGHT)
			{
			if((SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.nom_val[l_dq][i_rp]+l_max_offset)>l_max){
			SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.last_fail[l_dq][i_rp]=l_max;
				}else{
			SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.last_fail[l_dq][i_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.nom_val[l_dq][i_rp]+l_max_offset;
			//FAPI_INF("\n the last failure for right %d ",SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.last_fail[l_dq][i_rp]);
					}
					
			}else{
			if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.nom_val[l_dq][i_rp]>64){
			SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.last_fail[l_dq][i_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.nom_val[l_dq][i_rp]-l_max_offset;
			//FAPI_INF("\n the last failure for left %d ",SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.last_fail[l_dq][i_rp]);
			}else{
			SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.last_fail[l_dq][i_rp]=0;
			//FAPI_INF("\n the last failure for left %d ",SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.last_fail[l_dq][i_rp]);
			}
			}
		    //SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.nom_val[l_dq][i_rp]=val;
			
		    //FAPI_DBG("Nominal  Value for port=%d rank=%d  and rank pair=%d and dq=%d is  %d",l_p,i_rnk,i_rp,l_dq,val);
                   
		}
	    }
	}
    }
}	
    return rc;
}

fapi::ReturnCode generic_shmoo::get_all_noms_data_disable(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    
    uint8_t l_rnk,l_block;
    uint8_t i_rnk=0;
    uint8_t i_rp=0;
    uint32_t val=0;
    
	uint8_t l_p=0;
             
    input_type_t l_input_type_e = DATA_DISABLE;
    access_type_t l_access_type_e = READ ;
    FAPI_DBG("mss_generic_shmoo : get_all_noms : Reading in all nominal values");
    
    
             
            
	 for (l_p=0;l_p<MAX_PORT;l_p++){
    for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
    {// Byte loop
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		i_rnk=valid_rank[l_rnk];
		    rc = mss_getrankpair(i_target,l_p,i_rnk,&i_rp,valid_rank);if(rc) return rc; 
        for(l_block=0;l_block<5;++l_block)
        {   //DP 18 Loop
		rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,i_rnk,l_input_type_e,l_block,0,val);if(rc) return rc; 
		    SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.datadis_nom_val[l_block]=val;
			FAPI_INF("Nominal  Value for data bit disable  port=%d rank=%d  and rank pair=%d and dq=%d is  %d",l_p,i_rnk,i_rp,l_block,val);
            
		}
    }
}	
    return rc;
}

fapi::ReturnCode generic_shmoo::put_all_noms_data_disable(const fapi::Target & i_target,uint8_t flag)
{
    fapi::ReturnCode rc;
    
    uint8_t l_rnk,l_block;
    uint8_t i_rnk=0;
    uint8_t i_rp=0;
    uint32_t val=0;
    
	uint8_t l_p=0;
             
    input_type_t l_input_type_e = DATA_DISABLE;
    access_type_t l_access_type_e = WRITE ;
    FAPI_DBG("mss_generic_shmoo : get_all_noms : Reading in all nominal values");
    
    
             
            
	 for (l_p=0;l_p<MAX_PORT;l_p++){
    for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
    {// Byte loop
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		i_rnk=valid_rank[l_rnk];
		    rc = mss_getrankpair(i_target,l_p,i_rnk,&i_rp,valid_rank);if(rc) return rc; 
        for(l_block=0;l_block<5;++l_block)
        {   //DP 18 Loop
		val=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.datadis_nom_val[l_block];
		FAPI_INF("Nominal  Value for data bit disable while restoring   port=%d rank=%d  and rank pair=%d and dq=%d is  %d",l_p,i_rnk,i_rp,l_block,val);
		if(flag==1){
		
		val=0;
		FAPI_INF("\n the flushing value=%d \n",val);
		}
		rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,i_rnk,l_input_type_e,l_block,0,val);if(rc) return rc; 
		    
            
		}
    }
}	
    return rc;
}


fapi::ReturnCode generic_shmoo::get_all_noms_dqs(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    
    uint8_t l_rnk;
    //uint8_t i_rnk=0;
    uint8_t i_rp=0;
    uint32_t val=0;
    //uint8_t l_dq=0;
	uint8_t l_p=0;
    uint8_t l_max_nibble=20;
	uint8_t rank=0;
	uint8_t l_n=0;
	FAPI_INF("mss_generic_shmoo : get_all_noms_dqs : Reading in all nominal values and schmoo type=%d \n",iv_shmoo_type);
	if(iv_dmm_type==1)
		 {
		 
		 l_max_nibble=18;
		 }
		 
    input_type_t l_input_type_e = WR_DQS;
    access_type_t l_access_type_e = READ ;
    FAPI_DBG("mss_generic_shmoo : get_all_noms : Reading in all nominal values");
    
    
             if(iv_shmoo_type == 4)
            {   
		l_input_type_e = WR_DQS;
                
            }
            
			
			for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
    {// Byte loop
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rnk];
		rc = mss_getrankpair(i_target,l_p,rank,&i_rp,valid_rank);if(rc) return rc; 
	 for (l_n=0; l_n<l_max_nibble;l_n++){
	 
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_n,0,val);if(rc) return rc; 
		    SHMOO[iv_shmoo_type].MBA.P[l_p].S[rank].K.nom_val[l_n][i_rp]=val;
			#ifdef DBG 
		    FAPI_INF("Nominal  Value for port=%d rank=%d  and rank pair=%d and dqs=%d is  %d",l_p,rank,i_rp,l_n,SHMOO[iv_shmoo_type].MBA.P[l_p].S[rank].K.nom_val[l_n][i_rp]);
			#endif
	 }
	 }
	 }
			
			
            
	
	
    return rc;
}

fapi::ReturnCode generic_shmoo::get_all_noms_gate(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    
    
    uint8_t i_rnk=0;
    
    
    //uint8_t l_dq=0;
	uint8_t l_cmd=0;
	uint8_t l_p=0;
	uint8_t l_addr=0;
	uint8_t l_cntrl=0;
	uint8_t l_clk=0;
	uint32_t l_delay=0;
    
	#ifdef DEBUG
	FAPI_INF("mss_generic_shmoo : get_all_noms_gate : Reading in all nominal values and schmoo type=%d \n",iv_shmoo_type);
	#endif
		 
    input_type_t l_input_type_e = COMMAND;
    access_type_t l_access_type_e = READ ;
    FAPI_DBG("mss_generic_shmoo : get_all_noms : Reading in all nominal values");
    
    
             
            
			
			for (l_p=0;l_p<MAX_PORT;l_p++){
			FAPI_INF("\n PORT=%d \n",l_p);
	 for (l_cmd=0;l_cmd<3;l_cmd++)
			{
			l_input_type_e = COMMAND;
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cmd,1,l_delay);if(rc) return rc;
			SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd]=l_delay;
			FAPI_INF("\n Command = %d and value = %d \n",l_cmd,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd]);
			FAPI_INF("\n Command = %d and original value = %d \n",l_cmd,l_delay);
			}
			
			for (l_addr=0;l_addr<19;l_addr++)
			{
			l_input_type_e = ADDRESS;
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_addr,1,l_delay);if(rc) return rc;
			//FAPI_INF("\n Saurabh is here \n");
			 SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr]=l_delay;
			 //FAPI_INF("\n address = %d and value = %d \n",l_addr,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr]);
			}
			for (l_cntrl=0;l_cntrl<20;l_cntrl++)
			{
			l_input_type_e = CONTROL;
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cntrl,1,l_delay);if(rc) return rc;
			SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl]=l_delay;
			//FAPI_INF("\n CONTROL = %d and value = %d \n",l_cntrl,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl]);
			}
			
			for (l_clk=0;l_clk<8;l_clk++)
			{
			l_input_type_e = CLOCK;
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,1,l_input_type_e,l_clk,1,l_delay);if(rc) return rc;
			SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk]=l_delay;
			FAPI_INF("\n CLOCK = %d and value = %d \n",l_clk,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk]);
			}
            }
            
	
	
    return rc;
}



/*------------------------------------------------------------------------------
 * Function: knob_update
 * Description  : This is a key function is used to find right and left bound using new algorithm -- there is an option u can chose not to use it by setting a flag
 *
 * Parameters: Target:MBA,bound:RIGHT/LEFT,scenario:type of schmoo,iv_port:0/1,rank:0-7,byte:0-7,nibble:0/1,bit:0-3,pass,
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::knob_update(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
{	
    fapi::ReturnCode rc;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase data_buffer_64_1(64);
    
    
    
    uint8_t  l_rp=0;
    input_type_t l_input_type_e = WR_DQ;
    uint8_t l_dq=0;
    access_type_t l_access_type_e = WRITE;
	uint8_t l_n=0;
	
	uint8_t l_p=0;
    uint16_t l_delay=0;
    
	uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
	uint8_t l_SCHMOO_NIBBLES=20;
	uint8_t i_rp=0;
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
	
	rc=do_mcbist_reset(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_reset failed");
		    return rc;
		}
    //rc = mss_getrankpair(i_target,iv_port,rank,&l_rp,valid_rank);if(rc) return rc; 
	
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 schmoo_error_map[l_p][rank][l_n]=0;
	 }
	 }
	 }
	
    if(scenario == 8) {
	l_input_type_e = RD_DQ;
	l_max_limit=127;
	}
	
    
    if(bound==RIGHT)
    {
        
	if(algorithm==SEQ_LIN)
        {
		
	
	 for (l_delay=1;((pass==0));l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 
	 //rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq,bound);
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	 
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 #ifdef DBG 
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 #endif
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  //rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq);
	  //get_error_cnt(const fapi::Target & i_target,uint8_t port,uint8_t rank,uint8_t rank_pair,uint8_t bit)
	 }
	 
	 if(SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]>l_max_limit){
	 schmoo_error_map[l_p][rank][l_n]=1;
	 }
	 
	 l_dq=l_dq+4;
	  
			} 
		
		
	}
		
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		//rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq);
		rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	 }
		
	}
 	
    if(bound==LEFT)
    {
        if(algorithm==SEQ_LIN)
        {
		
		for (l_delay=1;(pass==0);l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 
	 //l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 //rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq,bound);
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 #ifdef DBG 
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	 #endif
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	 
	 }
	 if(SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp] == 0){
	 schmoo_error_map[l_p][rank][l_n] = 1;
	 }
	 
	 l_dq=l_dq+4;
	
			} 
		}
			
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		 
rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
		}
	 }
	 
	    
	}
    
    return rc;	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
fapi::ReturnCode generic_shmoo::knob_update_bin(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
{	
    fapi::ReturnCode rc;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase data_buffer_64_1(64);
    
    
    
    uint8_t  l_rp=0;
    input_type_t l_input_type_e = WR_DQ;
    uint8_t l_dq=0;
    access_type_t l_access_type_e = WRITE;
	uint8_t l_n=0;
	
	uint8_t l_p=0;
    //uint16_t l_delay=0;
    
	//uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
	uint8_t l_SCHMOO_NIBBLES=20;
	uint8_t i_rp=0;
	uint8_t l_status=1;
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
	
	rc=do_mcbist_reset(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_reset failed");
		    return rc;
		}
    //rc = mss_getrankpair(i_target,iv_port,rank,&l_rp,valid_rank);if(rc) return rc; 
	
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 schmoo_error_map[l_p][rank][l_n]=0;
	 }
	 }
	 }
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 binary_done_map[l_p][rank][l_n]=0;
	 }
	 }
	 }
	
    if(scenario == 8) {
	l_input_type_e = RD_DQ;
	//l_max_limit=127;
	}
	
    
    if(bound==RIGHT)
    {
        
	if(algorithm==SEQ_LIN)
        {
		
	
	 do{
	 
	 ////////////////////////////////////////////
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_status=0;
	 if(binary_done_map[l_p][rank][l_n]==0){
	 l_status=1;
	 }
	 }
	 }
	 }
	 ////////////////
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp];
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]=(SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]+SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp])/2;
	// FAPI_INF("\n 111111 port=%d nibble=%d rank=%d and bit=%d the last pass value %d the last fail value %d and current value %d\n",l_p,l_n,rank,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp],SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp],SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);
	rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);if(rc) return rc;
	if(SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]>SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp]){
	SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]-SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp];
	}else{
	SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp]-SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp];
	}
	if(SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]<=1){
	binary_done_map[l_p][rank][l_n]=1;
	SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp];
	//FAPI_INF("\n the right bound for port=%d rank=%d dq=%d is %d \n",l_p,rank,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);
	}
	}else{
	
	SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp];
	SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]=(SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]+SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp])/2;
	//FAPI_INF("\n 2222222 port=%d nibble=%d rank=%d and bit=%d the last pass value %d the last fail value %d and current value %d\n",l_p,l_n,rank,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp],SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp],SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);
	rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);if(rc) return rc;
	if(SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]>SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp]){
	SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]-SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp];
	}else{
	SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp]-SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp];
	}
	if(SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]<=1){
	binary_done_map[l_p][rank][l_n]=1;
	SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp];
	//FAPI_INF("\n the right bound for port=%d rank=%d dq=%d is %d \n",l_p,rank,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);
	}
	}
	 // //rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq,bound);
	 // if(schmoo_error_map[l_p][rank][l_n]==0){
	 
	 // SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 // #ifdef DBG 
	 // FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 // #endif
	 // rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  // //rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq);
	  // //get_error_cnt(const fapi::Target & i_target,uint8_t port,uint8_t rank,uint8_t rank_pair,uint8_t bit)
	 // }
	 
	 // if(SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]>l_max_limit){
	 // schmoo_error_map[l_p][rank][l_n]=1;
	 // }
	 
	  l_dq=l_dq+4;
	  
			} 
		
		
	}
		
	 }
	 rc=do_mcbist_reset(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_reset failed");
		    return rc;
		}
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		//rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq);
		rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
	//FAPI_INF("\n the status =%d \n",l_status);
	 }while(l_status==1);
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	 }
		
	}
 	
    if(bound==LEFT)
    {
        if(algorithm==SEQ_LIN)
        {
		
	
	 do{
	 
	 ////////////////////////////////////////////
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_status=0;
	 if(binary_done_map[l_p][rank][l_n]==0){
	 l_status=1;
	 }
	 }
	 }
	 }
	 ////////////////
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp];
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]=(SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]+SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp])/2;
	 //FAPI_INF("\n 111111 port=%d nibble=%d rank=%d and bit=%d the last pass value %d the last fail value %d and current value %d\n",l_p,l_n,rank,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp],SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp],SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);
	rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);if(rc) return rc;
	if(SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]>SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp]){
	SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]-SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp];
	}else{
	SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp]-SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp];
	}
	if(SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]<=1){
	binary_done_map[l_p][rank][l_n]=1;
	SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp];
	//FAPI_INF("\n the left bound for port=%d rank=%d dq=%d is %d \n",l_p,rank,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);
	}
	}else{
	
	SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp];
	SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]=(SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]+SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp])/2;
	//FAPI_INF("\n 2222222 port=%d nibble=%d rank=%d and bit=%d the last pass value %d the last fail value %d and current value %d\n",l_p,l_n,rank,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp],SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp],SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);
	rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);if(rc) return rc;
	if(SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]>SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp]){
	SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp]-SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp];
	}else{
	SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp]-SHMOO[scenario].MBA.P[l_p].S[rank].K.last_pass[l_dq][l_rp];
	}
	if(SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_diff[l_dq][l_rp]<=1){
	binary_done_map[l_p][rank][l_n]=1;
	SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.last_fail[l_dq][l_rp];
	//FAPI_INF("\n the left bound for port=%d rank=%d dq=%d is %d \n",l_p,rank,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.curr_val[l_dq][l_rp]);
	}
	}
	 // //rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq,bound);
	 // if(schmoo_error_map[l_p][rank][l_n]==0){
	 
	 // SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 // #ifdef DBG 
	 // FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 // #endif
	 // rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  // //rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq);
	  // //get_error_cnt(const fapi::Target & i_target,uint8_t port,uint8_t rank,uint8_t rank_pair,uint8_t bit)
	 // }
	 
	 // if(SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]>l_max_limit){
	 // schmoo_error_map[l_p][rank][l_n]=1;
	 // }
	 
	  l_dq=l_dq+4;
	  
			} 
		
		
	}
		
	 }
	 rc=do_mcbist_reset(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_reset failed");
		    return rc;
		}
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		//rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq);
		rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
	//FAPI_INF("\n the status =%d \n",l_status);
	 }while(l_status==1);
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	 }
	 
	    
	}
    
    return rc;	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
fapi::ReturnCode generic_shmoo::knob_update_gate(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t pass,bool &flag)
{	
    fapi::ReturnCode rc;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase data_buffer_64_1(64);
    
    
    
    uint8_t  l_rp=0;
    input_type_t l_input_type_e = COMMAND;
    
    access_type_t l_access_type_e = WRITE;
	uint8_t l_n=0;
	uint8_t l_cmd=0;
	uint8_t l_addr=0;
	uint8_t l_cntrl=0;
	uint8_t l_clk=0;
	uint8_t i_rnk=0;
	
	
	uint8_t l_p=0;
    uint32_t l_delay=0;
	//uint32_t l_delay_cac=0;
	uint32_t l_cmd_delay=0;
	uint32_t l_addr_delay=0;
	uint32_t l_cntrl_delay=0;
	uint32_t l_clk_delay=0;
    
	//uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
	uint8_t l_SCHMOO_NIBBLES=20;
	uint8_t i_rp=0;
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
	
	rc=do_mcbist_reset(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_reset failed");
		    return rc;
		}
    //rc = mss_getrankpair(i_target,iv_port,rank,&l_rp,valid_rank);if(rc) return rc; 
	
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 schmoo_error_map[l_p][rank][l_n]=0;
	 }
	 }
	 }
	
    
	
    
    if(bound==RIGHT)
    {
        
	if(algorithm==SEQ_LIN)
        {
		
	
	 for (l_delay=1;((pass==0)&&(l_delay<127));l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 
	 
	 
	 
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	 
	 
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.offset[l_n]=l_delay;
	 
	 }
			} 
		
		
	}
		
	 }
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_cmd=0;l_cmd<3;l_cmd++)
			{
			
			l_cmd_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd]+l_delay;
			
			l_input_type_e = COMMAND;
			if(l_cmd_delay<127){
			 //l_delay_cac=l_cmd_delay-SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd];
			FAPI_INF("\n port=%d command=%d nominal =%d and write_value=%d  \n",l_p,l_cmd,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd],l_cmd_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cmd,0,l_cmd_delay);if(rc) return rc;
			}
			}
			for (l_addr=0;l_addr<19;l_addr++)
			{
			
			l_addr_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr]+l_delay;
			if(l_addr_delay<127){
			l_input_type_e = ADDRESS;
			FAPI_INF("\n port=%d  address=%d nominal =%d and write_value=%d \n",l_p,l_addr,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr],l_addr_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_addr,0,l_addr_delay);if(rc) return rc;
			}
			}
			for (l_cntrl=0;l_cntrl<20;l_cntrl++)
			{
			l_cntrl_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl]+l_delay;
			if(l_cntrl_delay<127){
			l_input_type_e = CONTROL;
			FAPI_INF("\n port=%d control=%d nominal =%d and write_value=%d \n",l_p,l_cntrl,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl],l_cntrl_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cntrl,0,l_cntrl_delay);if(rc) return rc;
			}
			}
			
			for (l_clk=0;l_clk<8;l_clk++)
			{
			l_clk_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk]+l_delay;
			 
			 
			
			 
			l_input_type_e = CLOCK;
			
			FAPI_INF("\n port=%d clock=%d nominal =%d and write_value=%d \n",l_p,l_clk,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk],l_clk_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_clk,0,l_clk_delay);if(rc) return rc;
			
			}
            }
	 
	 
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		
		rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
	
	
	 }
		
		
		
	// PUT HERE NOMINAL BACK .
	
	for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_cmd=0;l_cmd<3;l_cmd++)
			{
			
			l_cmd_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd];
			
			l_input_type_e = COMMAND;
			if(l_cmd_delay<127){
			 
			// l_delay_cac=l_cmd_delay-SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd];
			
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cmd,0,l_cmd_delay);if(rc) return rc;
			}
			}
			for (l_addr=0;l_addr<19;l_addr++)
			{
			
			l_addr_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr];
			if(l_addr_delay<127){
			l_input_type_e = ADDRESS;
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_addr,0,l_addr_delay);if(rc) return rc;
			}
			}
			for (l_cntrl=0;l_cntrl<20;l_cntrl++)
			{
			l_cntrl_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl];
			if(l_cntrl_delay<127){
			l_input_type_e = CONTROL;			
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cntrl,0,l_cntrl_delay);if(rc) return rc;
			}
			}
			
			for (l_clk=0;l_clk<8;l_clk++)
			{
			l_clk_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk];	 
			l_input_type_e = CLOCK;
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_clk,0,l_clk_delay);if(rc) return rc;
			
			}
            }
	
	
	 }
		
	}
 	
    if(bound==LEFT)
    {
        if(algorithm==SEQ_LIN)
        {
		
	
	 for (l_delay=1;((pass==0)&&(l_delay<127));l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 
	 
	 
	 
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	 
	 
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.offset[l_n]=l_delay;
	 
	 }
			} 
		
		
	}
		
	 }
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_cmd=0;l_cmd<3;l_cmd++)
			{
			
			l_cmd_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd]-l_delay;
			
			l_input_type_e = COMMAND;
			if((l_cmd_delay>0)&&(l_cmd_delay<127)){
			 //l_delay_cac=l_cmd_delay-SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd];
			FAPI_INF("\n port=%d command=%d nominal =%d and write_value=%d  \n",l_p,l_cmd,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd],l_cmd_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cmd,0,l_cmd_delay);if(rc) return rc;
			}
			}
			for (l_addr=0;l_addr<19;l_addr++)
			{
			
			l_addr_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr]-l_delay;
			if((l_addr_delay>0)&&(l_addr_delay<127)){
			l_input_type_e = ADDRESS;
			FAPI_INF("\n port=%d  address=%d nominal =%d and write_value=%d \n",l_p,l_addr,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr],l_addr_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_addr,0,l_addr_delay);if(rc) return rc;
			}
			}
			for (l_cntrl=0;l_cntrl<20;l_cntrl++)
			{
			l_cntrl_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl]-l_delay;
			if((l_cntrl_delay>0)&&(l_cntrl_delay<127)){
			l_input_type_e = CONTROL;
			FAPI_INF("\n port=%d control=%d nominal =%d and write_value=%d \n",l_p,l_cntrl,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl],l_cntrl_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cntrl,0,l_cntrl_delay);if(rc) return rc;
			}
			}
			
			for (l_clk=0;l_clk<8;l_clk++)
			{
			l_clk_delay = (SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk]+127)-l_delay;
			l_input_type_e = CLOCK;
			
			FAPI_INF("\n port=%d clock=%d nominal =%d and write_value=%d \n",l_p,l_clk,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk],l_clk_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_clk,0,l_clk_delay);if(rc) return rc;
			
			}
            }
	 // put here loops for changing the delay values of CACc
	 
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}

	
	 }
		
		
		
	// PUT HERE NOMINAL BACK .
	
	for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_cmd=0;l_cmd<3;l_cmd++)
			{
			
			l_cmd_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd];
			
			l_input_type_e = COMMAND;
			if(l_cmd_delay<127){
			 
			// l_delay_cac=l_cmd_delay-SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd];
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cmd,0,l_cmd_delay);if(rc) return rc;
			}
			}
			for (l_addr=0;l_addr<19;l_addr++)
			{
			
			l_addr_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr];
			if(l_addr_delay<127){
			l_input_type_e = ADDRESS;
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_addr,0,l_addr_delay);if(rc) return rc;
			}
			}
			for (l_cntrl=0;l_cntrl<20;l_cntrl++)
			{
			l_cntrl_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl];
			if(l_cntrl_delay<127){
			l_input_type_e = CONTROL;
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cntrl,0,l_cntrl_delay);if(rc) return rc;
			}
			}
			
			for (l_clk=0;l_clk<8;l_clk++)
			{
			l_clk_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk];
			 
			l_input_type_e = CLOCK;
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_clk,0,l_clk_delay);if(rc) return rc;
			
			}
            }
	
	
	 }
	 
	    
	}
    
    return rc;	
}
fapi::ReturnCode generic_shmoo::knob_update_gate_train(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t pass)
{	
    fapi::ReturnCode rc;
	
    ecmdDataBufferBase l_data_buffer_FIR_64(64);
	ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase data_buffer_64_1(64);
    
    
    
    uint8_t  l_rp=0;
    input_type_t l_input_type_e = COMMAND;
    uint8_t l_dq=0;
    access_type_t l_access_type_e = WRITE;
	uint8_t l_n=0;
	uint8_t l_cmd=0;
	uint8_t l_addr=0;
	uint8_t l_cntrl=0;
	uint8_t l_clk=0;
	uint8_t i_rnk=0;
	uint8_t bit=0;
	uint8_t l_failed=0;
	
	uint8_t l_p=0;
    uint32_t l_delay=0;
	uint32_t l_delay_failed=0;
	
	uint32_t l_cmd_delay=0;
	uint32_t l_addr_delay=0;
	uint32_t l_cntrl_delay=0;
	uint32_t l_clk_delay=0;
    
	
    uint8_t rank=0;
	uint8_t l_rank=0;
	uint8_t l_SCHMOO_NIBBLES=20;
	uint8_t i_rp=0;
	uint32_t rc_num = 0;
	uint8_t flag=1;
	
	
	
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
	
	rc=do_mcbist_reset(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_reset failed");
		    return rc;
		}
    
	
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 schmoo_error_map[l_p][rank][l_n]=0;
	 }
	 }
	 }
	
    
	
    
    if(bound==RIGHT)
    {
        
	if(algorithm==SEQ_LIN)
        {
		
	
	 for (l_delay=1;((pass==0)&&(l_delay<127));l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 
	 
	 
	 
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	 
	 
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.offset[l_n]=l_delay;
	  }
			} 
		
		
	}
		
	 }
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 l_failed=0;
	 for (l_cmd=0;l_cmd<3;l_cmd++)
			{
			
			l_cmd_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd]+l_delay;
			
			l_input_type_e = COMMAND;
			if(l_cmd_delay==127){
			l_failed=1;
			pass=1;
			}
			if((l_cmd_delay<127)&&(l_failed==0)){
			 
			FAPI_INF("\n port=%d command=%d nominal =%d and write_value=%d  \n",l_p,l_cmd,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd],l_cmd_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cmd,0,l_cmd_delay);if(rc) return rc;
			}
			}
			for (l_addr=0;l_addr<19;l_addr++)
			{
			
			l_addr_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr]+l_delay;
			if(l_addr_delay==127){
			l_failed=1;
			pass=1;
			}
			if((l_addr_delay<127)&&(l_failed==0)){
			l_input_type_e = ADDRESS;
			
			FAPI_INF("\n port=%d  address=%d nominal =%d and write_value=%d \n",l_p,l_addr,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr],l_addr_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_addr,0,l_addr_delay);if(rc) return rc;
			}
			}
			for (l_cntrl=0;l_cntrl<20;l_cntrl++)
			{
			l_cntrl_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl]+l_delay;
			if(l_cntrl_delay==127){
			l_failed=1;
			pass=1;
			}
			if((l_cntrl_delay<127)&&(l_failed==0)){
			l_input_type_e = CONTROL;
			
			FAPI_INF("\n port=%d control=%d nominal =%d and write_value=%d \n",l_p,l_cntrl,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl],l_cntrl_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cntrl,0,l_cntrl_delay);if(rc) return rc;
			}
			}
			
			for (l_clk=0;l_clk<8;l_clk++)
			{
			l_clk_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk]+l_delay;
			 
			 
			l_input_type_e = CLOCK;
			
			FAPI_INF("\n port=%d clock=%d nominal =%d and write_value=%d \n",l_p,l_clk,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk],l_clk_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,1,l_input_type_e,l_clk,0,l_clk_delay);if(rc) return rc;
			
			}
            }
	 // call dram training here .
	 FAPI_EXEC_HWP(rc, mss_draminit_training, i_target);
	//rc = mss_draminit_training(i_target);
	if(rc){
	l_delay_failed=l_delay-1;
	pass=1;
	}
	
	l_delay_failed=l_delay-1;
	FAPI_INF("\n the value of pass=%d  and delay =%d and failed delay=%d \n",pass,l_delay,l_delay_failed);
	///////

	
}

FAPI_INF("\n EFFECTIVE RIGHT CLOCK ADJUST = %d \n",l_delay_failed);
rc_num =  data_buffer_64.flushTo0();if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}

rc=put_all_noms_data_disable(i_target,flag);if(rc) return rc;

// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_0_0x8000007c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_1_0x8000047c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_2_0x8000087c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_3_0x80000c7c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_4_0x8000107c0301143F,data_buffer_64); if(rc) return rc;

// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_0_0x8001007c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_1_0x8001047c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_2_0x8001087c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_3_0x80010c7c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_4_0x8001107c0301143F,data_buffer_64); if(rc) return rc;

// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_0_0x8000017c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_1_0x8000057c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_2_0x8000097c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_3_0x80000d7c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_4_0x8000117c0301143F,data_buffer_64); if(rc) return rc;


// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_0_0x8001017c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_1_0x8001057c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_2_0x8001097c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_3_0x80010d7c0301143F,data_buffer_64); if(rc) return rc;
// rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_4_0x8001117c0301143F,data_buffer_64); if(rc) return rc;
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_cmd=0;l_cmd<3;l_cmd++)
			{
			
			l_cmd_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cmd_nom_val[l_cmd]+l_delay_failed;
			
			l_input_type_e = COMMAND;
			if(l_cmd_delay<127){
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cmd,0,l_cmd_delay);if(rc) return rc;
			}
			}
			for (l_addr=0;l_addr<19;l_addr++)
			{
			
			l_addr_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr]+l_delay_failed;
			if(l_addr_delay<127){
			l_input_type_e = ADDRESS;
			
			//FAPI_INF("\n port=%d  address=%d nominal =%d and write_value=%d \n",l_p,l_addr,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.addr_nom_val[l_addr],l_addr_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_addr,0,l_addr_delay);if(rc) return rc;
			}
			}
			for (l_cntrl=0;l_cntrl<20;l_cntrl++)
			{
			l_cntrl_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl]+l_delay_failed;
			if(l_cntrl_delay<127){
			l_input_type_e = CONTROL;
			
			//FAPI_INF("\n port=%d control=%d nominal =%d and write_value=%d \n",l_p,l_cntrl,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.cntrl_nom_val[l_cntrl],l_cntrl_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_cntrl,0,l_cntrl_delay);if(rc) return rc;
			}
			}
			
			for (l_clk=0;l_clk<8;l_clk++)
			{
			l_clk_delay = SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk]+l_delay_failed;
			 
			 //FAPI_INF("\n clock max value reached for port=%d and value =%d \n",l_p,l_clk_delay);
			
			 
			l_input_type_e = CLOCK;
			
			//FAPI_INF("\n port=%d clock=%d nominal =%d and write_value=%d \n",l_p,l_clk,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rnk].K.clk_nom_val[l_clk],l_clk_delay);
			rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,0,l_input_type_e,l_clk,0,l_clk_delay);if(rc) return rc;
			
			}
            }
		
		
		//rc = mss_draminit_training(i_target);
		FAPI_EXEC_HWP(rc, mss_draminit_training, i_target);
		iv_shmoo_type=4;
	rc=schmoo_setup_mcb(i_target);if(rc) return rc;
	 iv_shmoo_type=16;
	 // check mcbist for the fail 
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);if(rc) return rc;
	
	
	
	
	 }
		
	}
 	
    if(bound==LEFT)
    {
        if(algorithm==SEQ_LIN)
        {
		
		for (l_delay=1;(pass==0);l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 
	 //l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 //rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq,bound);
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	 
	 }
	 if(SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp] == 0){
	 schmoo_error_map[l_p][rank][l_n] = 1;
	 }
	 
	 l_dq=l_dq+4;
	
			} 
		}
			
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		 
rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
		}
	 }
	 
	    
	}
    
    return rc;	
}
/*------------------------------------------------------------------------------
 * Function: knob_update_dqs
 * Description  : This is a key function is used to find right and left bound using new algorithm -- there is an option u can chose not to use it by setting a flag
 *
 * Parameters: Target:MBA,bound:RIGHT/LEFT,scenario:type of schmoo,iv_port:0/1,rank:0-7,byte:0-7,nibble:0/1,bit:0-3,pass,
 * --------------------------------------------------------------------------- */
fapi::ReturnCode generic_shmoo::knob_update_dqs_by4(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
{	
    fapi::ReturnCode rc;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase data_buffer_64_1(64);
    
    
    
    uint8_t  l_rp=0;
    input_type_t l_input_type_e = WR_DQ;
	input_type_t l_input_type_e_dqs = WR_DQS;
    uint8_t l_dq=0;
    access_type_t l_access_type_e = WRITE;
	uint8_t l_n=0;
	uint8_t l_dqs=4;
	
	
	uint8_t l_p=0;
    uint16_t l_delay=0;
    //uint32_t l_max=0;
	uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
	uint8_t l_SCHMOO_NIBBLES=20;
	uint8_t i_rp=0;
	
	
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
    //rc = mss_getrankpair(i_target,iv_port,rank,&l_rp,valid_rank);if(rc) return rc; 
	
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 schmoo_error_map[l_p][rank][l_n]=0;
	 }
	 }
	 }
	
    
	
    
    if(bound==RIGHT)
    {
        
	if(algorithm==SEQ_LIN)
        {
		
	
	 for (l_delay=1;((pass==0));l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
		//FAPI_INF("\n abhijit here after  port=%d rank=%d \n",l_p,rank);
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	 //FAPI_INF("\n value of nominal delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_dqs,rank,l_p,l_n,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_dqs,rank,l_p,l_n,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d bit=%d is %d ",scenario,rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	 }
	 //FAPI_INF("\n abhijit here before \n");
	 if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]>l_max_limit){
	 schmoo_error_map[l_p][rank][l_n]=1;
	 }
		
		} 
		
		
	}
		
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {

	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 //FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
			} 
		}
		}
		for(int l_bit=0;l_bit<4;l_bit++){
		for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=l_bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	}	
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }	
		
	 }
		
	}
 	
    if(bound==LEFT)
    {
        if(algorithm==SEQ_LIN)
        {
		
		for (l_delay=1;(pass==0);l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	// l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	  SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n][l_rp]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]-l_delay;
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	 }
	 if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp] == 0){
	 schmoo_error_map[l_p][rank][l_n] = 1;
	 }
	 
	 
	
			} 
		}
			
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		 
rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {

	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
			} 
		}
		}
		
		for(int l_bit=0;l_bit<4;l_bit++){
		for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=l_bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	}
	
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
	
	 }
	 
	    
	}
    
    return rc;	
}
fapi::ReturnCode generic_shmoo::knob_update_dqs_by4_isdimm(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
{	
    fapi::ReturnCode rc;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase data_buffer_64_1(64);
    
    
    
    uint8_t  l_rp=0;
    input_type_t l_input_type_e = WR_DQ;
	input_type_t l_input_type_e_dqs = WR_DQS;
    uint8_t l_dq=0;
    access_type_t l_access_type_e = WRITE;
	uint8_t l_n=0;
	uint8_t l_dqs=4;
	uint8_t l_my_dqs=0;
	
	
	uint8_t l_p=0;
    uint16_t l_delay=0;
    //uint32_t l_max=0;
	uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
	uint8_t l_SCHMOO_NIBBLES=20;
	uint8_t i_rp=0;
	
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
	uint8_t l_dqs_arr[18]={0,9,1,10,2,11,3,12,4,13,5,14,6,15,7,16,8,17};
    //rc = mss_getrankpair(i_target,iv_port,rank,&l_rp,valid_rank);if(rc) return rc; 
	
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 schmoo_error_map[l_p][rank][l_n]=0;
	 }
	 }
	 }
	
    
    
    if(bound==RIGHT)
    {
        
	if(algorithm==SEQ_LIN)
        {
		
	
	 for (l_delay=1;((pass==0));l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=0;
	 l_my_dqs=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
		//FAPI_INF("\n abhijit here after  port=%d rank=%d \n",l_p,rank);
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	 l_my_dqs=l_dqs_arr[l_n];
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	// FAPI_INF("\n value of nominal delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_dqs,rank,l_p,l_my_dqs,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_my_dqs][l_rp]);
	 SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_my_dqs][l_rp]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_my_dqs][l_rp]+l_delay;
	// FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_dqs,rank,l_p,l_my_dqs,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_my_dqs][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_my_dqs,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_my_dqs][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d bit=%d is %d ",scenario,rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	 }
	 //FAPI_INF("\n abhijit here before \n");
	 if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]>l_max_limit){
	 schmoo_error_map[l_p][rank][l_n]=1;
	 }
		
		} 
		
		
	}
		
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {

	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 //FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
			} 
		}
		}
		
		for(int l_bit=0;l_bit<4;l_bit++){
		for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=l_bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	}
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
		
		
		
	 }
		
	}
 	
    if(bound==LEFT)
    {
        if(algorithm==SEQ_LIN)
        {
		
		for (l_delay=1;(pass==0);l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=0;
	 l_my_dqs=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	 	 l_my_dqs=l_dqs_arr[l_n];
	 //l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	  SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_my_dqs][l_rp]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_my_dqs][l_rp]-l_delay;
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_my_dqs,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_my_dqs][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	 }
	 if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp] == 0){
	 schmoo_error_map[l_p][rank][l_n] = 1;
	 }
	 
	 
	
			} 
		}
			
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		 
rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {

	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
			} 
		}
		}
		
		for(int l_bit=0;l_bit<4;l_bit++){
		for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=l_bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	}
	
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
	
	 }
	 
	    
	}
    
    return rc;	
}
fapi::ReturnCode generic_shmoo::knob_update_dqs_by8(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
{	
    fapi::ReturnCode rc;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase data_buffer_64_1(64);
    
    
    
    uint8_t  l_rp=0;
    input_type_t l_input_type_e = WR_DQ;
	input_type_t l_input_type_e_dqs = WR_DQS;
    uint8_t l_dq=0;
	uint8_t l_dqs=0;
    access_type_t l_access_type_e = WRITE;
	uint8_t l_n=0;
	uint8_t l_scen_dqs=4;
	
	
	uint8_t l_p=0;
    uint16_t l_delay=0;
    //uint32_t l_max=0;
	uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
	//uint8_t l_SCHMOO_BYTES=10;
	uint8_t l_SCHMOO_NIBBLES=20;
	
	uint8_t i_rp=0;
	
	
	
			
		rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
	
	
	if(iv_dmm_type==1)
    {
	//l_SCHMOO_BYTES=9;
	l_SCHMOO_NIBBLES=18;
	}
    //rc = mss_getrankpair(i_target,iv_port,rank,&l_rp,valid_rank);if(rc) return rc; 
	
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 schmoo_error_map[l_p][rank][l_n]=0;
	 }
	 }
	 }
	
    
	
    
	
    
    if(bound==RIGHT)
    {
        
	if(algorithm==SEQ_LIN)
        {
		
	
	 for (l_delay=1;((pass==0));l_delay++){
	 
	 //for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=0;
	 l_dqs=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
		//FAPI_INF("\n abhijit here after  port=%d rank=%d \n",l_p,rank);
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	 if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)){
	 //FAPI_INF("\n value of nominal delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_scen_dqs,rank,l_p,l_n,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_scen_dqs,rank,l_p,l_n,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d bit=%d is %d ",scenario,rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  
	 }
	 //FAPI_INF("\n abhijit here before \n");
	 if(SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]>l_max_limit){
	 schmoo_error_map[l_p][rank][l_n]=1;
	 schmoo_error_map[l_p][rank][l_n+1]=1;
	 }
		if((schmoo_error_map[l_p][rank][l_n]==1)||(schmoo_error_map[l_p][rank][l_n+1]==1)){
		
		schmoo_error_map[l_p][rank][l_n]=1;
	 schmoo_error_map[l_p][rank][l_n+1]=1;
	 }
		
		l_n=l_n+1;
		l_dqs=l_dqs+1;
		} 
		
		
	}
		
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {

	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 //FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
			} 
		}
		}
		
		for(int l_bit=0;l_bit<4;l_bit++){
		for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=l_bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	}
		
		rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
	
		
	 }
		
	}
 	
    if(bound==LEFT)
    {
        if(algorithm==SEQ_LIN)
        {
		
		for (l_delay=1;(pass==0);l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=0;
	 l_dqs=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	 //l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 
	 
	 if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)){
	  SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n][l_rp]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]-l_delay;
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	 }
	 if(SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp] == 0){
	 schmoo_error_map[l_p][rank][l_n] = 1;
	 schmoo_error_map[l_p][rank][l_n+1] = 1;
	 }
	 
	 if((schmoo_error_map[l_p][rank][l_n]==1)||(schmoo_error_map[l_p][rank][l_n+1]==1)){
		
		schmoo_error_map[l_p][rank][l_n]=1;
	 schmoo_error_map[l_p][rank][l_n+1]=1;
	 }
	 
	l_n=l_n+1;
	l_dqs=l_dq+1;
			} 
		}
			
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		 
rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {

	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 //FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
			} 
		}
		}
		
		for(int l_bit=0;l_bit<4;l_bit++){
		for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=l_bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	}
	
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
	
	 }
	 
	    
	}
    
    return rc;	
}
fapi::ReturnCode generic_shmoo::knob_update_dqs_by8_isdimm(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
{	
    fapi::ReturnCode rc;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase data_buffer_64_1(64);
    
    
    
    uint8_t  l_rp=0;
    input_type_t l_input_type_e = WR_DQ;
	input_type_t l_input_type_e_dqs = WR_DQS;
    uint8_t l_dq=0;
	uint8_t l_dqs=0;
    access_type_t l_access_type_e = WRITE;
	uint8_t l_n=0;
	uint8_t l_scen_dqs=4;
	
	
	uint8_t l_p=0;
    uint16_t l_delay=0;
    //uint32_t l_max=0;
	uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
	//uint8_t l_SCHMOO_BYTES=10;
	uint8_t l_SCHMOO_NIBBLES=20;
	
	uint8_t i_rp=0;
	
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }	
	
	if(iv_dmm_type==1)
    {
	//l_SCHMOO_BYTES=9;
	l_SCHMOO_NIBBLES=18;
	}
    //rc = mss_getrankpair(i_target,iv_port,rank,&l_rp,valid_rank);if(rc) return rc; 
	
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for(int i=0;i<iv_MAX_RANKS[l_p];i++){
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[i];
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 schmoo_error_map[l_p][rank][l_n]=0;
	 }
	 }
	 }
	
    
	
    
    if(bound==RIGHT)
    {
        
	if(algorithm==SEQ_LIN)
        {
		
	
	 for (l_delay=1;((pass==0));l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=0;
	 l_dqs=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
		//FAPI_INF("\n abhijit here after  port=%d rank=%d \n",l_p,rank);
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	 l_dqs=l_n/2;
	 //FAPI_INF("\n the value of error check is %d \n",schmoo_error_map[l_p][rank][l_n]);
	 if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)){
	 //FAPI_INF("\n value of nominal delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_scen_dqs,rank,l_p,l_dqs,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_dqs][l_rp]);
	 SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs][l_rp]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_dqs][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_scen_dqs,rank,l_p,l_dqs,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_dqs,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d bit=%d is %d ",scenario,rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 //FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  
	 }
	 //FAPI_INF("\n abhijit here before \n");
	 if(SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs][l_rp]>l_max_limit){
	
	 schmoo_error_map[l_p][rank][l_n]=1;
	 schmoo_error_map[l_p][rank][l_n+1]=1;
	 }
	 
	 if((schmoo_error_map[l_p][rank][l_n]==1)||(schmoo_error_map[l_p][rank][l_n+1]==1)){
		
		schmoo_error_map[l_p][rank][l_n]=1;
	 schmoo_error_map[l_p][rank][l_n+1]=1;
	 }
		
		l_n=l_n+1;
		
		} 
		
		
	}
		
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {

	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 //FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
			} 
		}
		}
		
		for(int l_bit=0;l_bit<4;l_bit++){
		for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=l_bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	}
	
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
		
		
		
	 }
		
	}
 	
    if(bound==LEFT)
    {
        if(algorithm==SEQ_LIN)
        {
		
		for (l_delay=1;(pass==0);l_delay++){
	 
	 for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=0;
	 l_dqs=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	// l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 l_dqs=l_n/2;
	 
	 if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)){
	  SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs][l_rp]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_dqs][l_rp]-l_delay;
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_dqs,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 //FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	 }
	 if(SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs][l_rp] == 0){
	 schmoo_error_map[l_p][rank][l_n] = 1;
	 schmoo_error_map[l_p][rank][l_n+1] = 1;
	 }
	 
	 if((schmoo_error_map[l_p][rank][l_n]==1)||(schmoo_error_map[l_p][rank][l_n+1]==1)){
		
		schmoo_error_map[l_p][rank][l_n]=1;
	 schmoo_error_map[l_p][rank][l_n+1]=1;
	 }
	 
	l_n=l_n+1;
	
			} 
		}
			
	 }
	 rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		 
rc=check_error_map(i_target,l_p,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}		
		
	
	 }
		
		
	for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {

	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 //FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
			} 
		}
		}
		
		for(int l_bit=0;l_bit<4;l_bit++){
		for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	 l_dq=l_bit;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
	}
	rc=do_mcbist_test(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
		
		rc=mcb_error_map(i_target,mcbist_error_map);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
	
	 }
	 
	    
	}
    
    return rc;	
}

/*------------------------------------------------------------------------------
 * Function: find_bound
 * Description  : This function calls the knob_update for each DQ which is used to find bound  that is left/right according to schmoo type
 *
 * Parameters: Target:MBA,bound:RIGHT/LEFT,
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::find_bound(const fapi::Target & i_target,bound_t bound){
    uint8_t l_bit=0;
    fapi::ReturnCode rc;
    
    
	uint8_t pass=0;
	uint8_t l_dram_width=0;
    bool flag=false;
    
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_dram_width); if(rc) return rc;
    
	FAPI_INF("\n SCHMOO IS IN PROGRESS ...... \n");
   // FAPI_INF("generic_shmoo::find_bound running find_bound function ");
    
        
        //rc=knob_update_dqs_by8_isdimm(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc;
              if(iv_DQS_ON == 1){
			  rc=do_mcbist_reset(i_target);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_reset failed");
		    return rc;
		}
			  pass=0;
			  if(l_dram_width == 4){
			  if(iv_dmm_type==1)
    {
	rc=knob_update_dqs_by4_isdimm(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc; 
	}else{
			  rc=knob_update_dqs_by4(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc; 
			  }
              }else{
			  if(iv_dmm_type==1)
    {
	rc=knob_update_dqs_by8_isdimm(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc;
	}else{
			   rc=knob_update_dqs_by8(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc;
			   //rc=knob_update_dqs_by8_isdimm(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc;
			   }
			   }
				}else if(iv_DQS_ON == 2){
				pass=0;
				rc=knob_update_gate(i_target,bound,iv_shmoo_type,pass,flag); if(rc) return rc; 
				}
				else{
			//Bit loop
                    for(l_bit=0;l_bit< MAX_BITS;++l_bit)
                    {
			// preetham function here
			
			pass=0;
			//FAPI_INF("\n abhijit is inside find bound and schmoo type is %d \n",iv_shmoo_type);
			
			//rc=knob_update(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc;   
            ////////////////////////////////////////////////////////////////////////////////////
			if(iv_shmoo_param==4){
			rc=knob_update_bin(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc; 	
				}else{
				rc=knob_update(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc;
				}
					
                }
            }
        
    return rc;
}
//#ifdef char
/*------------------------------------------------------------------------------
 * Function: print_report
 * Description  : This function is used to print the information needed such as freq,voltage etc, and also the right,left and total margin 
 *
 * Parameters: Target:MBA
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::print_report(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    
    uint8_t l_rnk,l_byte,l_nibble,l_bit;
    uint8_t l_dq=0;
    uint8_t l_rp=0;
	uint8_t l_p=0;
    uint8_t i_rank=0;
    uint8_t l_mbapos = 0;
    uint32_t l_attr_mss_freq_u32 = 0;
    uint32_t l_attr_mss_volt_u32 = 0;
    uint8_t l_attr_eff_dimm_type_u8 = 0;
    uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
    uint8_t l_attr_eff_dram_width_u8 = 0;
	
    fapi::Target l_target_centaur;
    
    
    rc = fapiGetParentChip(i_target, l_target_centaur); if(rc) return rc;
   
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_u32); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_attr_mss_volt_u32); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, l_attr_eff_dimm_type_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target, l_attr_eff_num_drops_per_port_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_attr_eff_dram_width_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbapos);if(rc) return rc;
    
   
   
    FAPI_INF("      freq = %d on %s.", l_attr_mss_freq_u32, l_target_centaur.toEcmdString());
    FAPI_INF("volt = %d on %s.", l_attr_mss_volt_u32, l_target_centaur.toEcmdString());
    FAPI_INF("dimm_type = %d on %s.", l_attr_eff_dimm_type_u8, i_target.toEcmdString());
    if ( l_attr_eff_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM )
    {
	FAPI_INF("It is a CDIMM"); 
    }
    else
    {
	FAPI_INF("It is an ISDIMM"); 
    }
	FAPI_INF("\n Number of ranks on port = 0 is %d ",iv_MAX_RANKS[0]);
	FAPI_INF("\n Number of ranks on port = 1 is %d \n \n",iv_MAX_RANKS[1]);
	
    //FAPI_INF("num_drops_per_port = %d on %s.", l_attr_eff_num_drops_per_port_u8, i_target.toEcmdString());
    //FAPI_INF("num_ranks  = %d on %s.", iv_MAX_RANKS,i_target.toEcmdString());
    //FAPI_INF("dram_width = %d on %s. \n\n", l_attr_eff_dram_width_u8, i_target.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//// Based on schmoo param the print will change eventually 
	if(iv_shmoo_type==2)
			    {
    FAPI_INF("Schmoo  POS\tPort\tRank\tByte\tnibble\tbit\tNominal\t\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ");
    }else{
	FAPI_INF("Schmoo  POS\tPort\tRank\tByte\tnibble\tbit\tNominal\t\tSetup_Limit\tHold_Limit\tRdD_Setup(ps)\tRdD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ");
    }
        
	    
		for (l_p=0;l_p<MAX_PORT;l_p++){
		for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
	    {			rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
					    i_rank=valid_rank[l_rnk];
			    rc = mss_getrankpair(i_target,l_p,i_rank,&l_rp,valid_rank);if(rc) return rc;
		for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
		{
		    
		    //Nibble loop
		    for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
		    {
			for(l_bit=0;l_bit< MAX_BITS;++l_bit)
			{	
			    l_dq=8*l_byte+4*l_nibble+l_bit;

			    if(iv_shmoo_type==2)
			    {
				FAPI_INF("WR_EYE %d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",l_mbapos,l_p,i_rank,l_byte,l_nibble,l_bit,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_dq][l_rp],l_attr_mss_freq_u32,iv_vref_mul);
			    }
			    if(iv_shmoo_type==8)
			    {
				FAPI_INF("RD_EYE %d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",l_mbapos,l_p,i_rank,l_byte,l_nibble,l_bit,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_dq][l_rp],l_attr_mss_freq_u32,iv_vref_mul);
			    }
			    
			}
		    }
		}
	    }
	}
    
    return rc;
 }
 
 
 fapi::ReturnCode generic_shmoo::print_report_dqs(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    
    uint8_t l_rnk,l_nibble;
    //uint8_t l_dq=0;
    uint8_t l_rp=0;
	uint8_t l_p=0;
    uint8_t i_rank=0;
    uint8_t l_mbapos = 0;
    uint32_t l_attr_mss_freq_u32 = 0;
    uint32_t l_attr_mss_volt_u32 = 0;
    uint8_t l_attr_eff_dimm_type_u8 = 0;
    uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
    uint8_t l_attr_eff_dram_width_u8 = 0;
    fapi::Target l_target_centaur;
    uint8_t l_SCHMOO_NIBBLES=20;
	uint8_t l_by8_dqs=0;
	
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
    
    rc = fapiGetParentChip(i_target, l_target_centaur); if(rc) return rc;
   
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_u32); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_attr_mss_volt_u32); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, l_attr_eff_dimm_type_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target, l_attr_eff_num_drops_per_port_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_attr_eff_dram_width_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbapos);if(rc) return rc;
   
   if(l_attr_eff_dram_width_u8 == 8){
   l_SCHMOO_NIBBLES=10;
   if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=9;
	}
   }
   
   //FAPI_INF("Shmoonibbles val is=%d",l_SCHMOO_NIBBLES);
   
    FAPI_INF("      freq = %d on %s.", l_attr_mss_freq_u32, l_target_centaur.toEcmdString());
    FAPI_INF("volt = %d on %s.", l_attr_mss_volt_u32, l_target_centaur.toEcmdString());
    FAPI_INF("dimm_type = %d on %s.", l_attr_eff_dimm_type_u8, i_target.toEcmdString());
	FAPI_INF("\n Number of ranks on port=0 is %d ",iv_MAX_RANKS[0]);
	FAPI_INF("\n Number of ranks on port=1 is %d ",iv_MAX_RANKS[1]);
	
	
    if ( l_attr_eff_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM )
    {
	FAPI_INF("It is a CDIMM"); 
    }
    else
    {
	FAPI_INF("It is an ISDIMM"); 
    }
	
	FAPI_INF("\n Number of ranks on port=0 is %d ",iv_MAX_RANKS[0]);
	FAPI_INF("\n Number of ranks on port=1 is %d \n \n",iv_MAX_RANKS[1]);
    //FAPI_INF("num_drops_per_port = %d on %s.", l_attr_eff_num_drops_per_port_u8, i_target.toEcmdString());
    //FAPI_INF("num_ranks  = %d on %s.", iv_MAX_RANKS,i_target.toEcmdString());
    //FAPI_INF("dram_width = %d on %s. \n\n", l_attr_eff_dram_width_u8, i_target.toEcmdString());
	//fprintf(fp, "Schmoo  POS\tPort\tRank\tDQS\tNominal\t\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate  \n");
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    FAPI_INF("Schmoo  POS\tPort\tRank\tDQS\tNominal\t\ttDQSSmin_PR_limit\ttDQSSmax_PR_limit\ttDQSSmin(ps)\ttDQSSmax(ps)\ttDQSS_Window(ps)\tBitRate  ");
    
    iv_shmoo_type=4;
        
	    
		for (l_p=0;l_p<MAX_PORT;l_p++){
		for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
	    {			rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
					    i_rank=valid_rank[l_rnk];
			    rc = mss_getrankpair(i_target,l_p,i_rank,&l_rp,valid_rank);if(rc) return rc;
		
		    for(l_nibble=0;l_nibble< l_SCHMOO_NIBBLES;++l_nibble)
		    {
				
			   l_by8_dqs=l_nibble;
			   if(iv_dmm_type==0)
			   {
			    if(l_attr_eff_dram_width_u8 == 8)
			    {
				l_nibble=l_nibble*2;
			    }
			   }
			/*if(l_attr_eff_dram_width_u8 == 8){
			l_by8_dqs=l_nibble*2;
			
			} */
			  //fprintf(fp,"WR_DQS %d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",l_mbapos,l_p,i_rank,l_nibble,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_by8_dqs][l_rp],l_attr_mss_freq_u32);
				FAPI_INF("WR_DQS %d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",l_mbapos,l_p,i_rank,l_nibble,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_by8_dqs][l_rp],l_attr_mss_freq_u32);
			    
			    
			    
			
		    }
		}
	    }
	
    //fclose(fp);
    return rc;
 }
   fapi::ReturnCode generic_shmoo::print_report_gate(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    
    uint8_t l_rank,l_n;
    //uint8_t l_dq=0;
    uint8_t l_rp=0;
	uint8_t l_p=0;
    uint8_t rank=0;
    uint8_t l_mbapos = 0;
    uint32_t l_attr_mss_freq_u32 = 0;
    uint32_t l_attr_mss_volt_u32 = 0;
    uint8_t l_attr_eff_dimm_type_u8 = 0;
    uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
    uint8_t l_attr_eff_dram_width_u8 = 0;
    fapi::Target l_target_centaur;
    uint8_t l_SCHMOO_NIBBLES=20;
	
	
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
    
    rc = fapiGetParentChip(i_target, l_target_centaur); if(rc) return rc;
   
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_u32); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_attr_mss_volt_u32); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, l_attr_eff_dimm_type_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target, l_attr_eff_num_drops_per_port_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_attr_eff_dram_width_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbapos);if(rc) return rc;
   
   if(l_attr_eff_dram_width_u8 == 8){
   l_SCHMOO_NIBBLES=20;
   if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
   }
   
   //FAPI_INF("Shmoonibbles val is=%d",l_SCHMOO_NIBBLES);
   
    FAPI_INF("      freq = %d on %s.", l_attr_mss_freq_u32, l_target_centaur.toEcmdString());
    FAPI_INF("volt = %d on %s.", l_attr_mss_volt_u32, l_target_centaur.toEcmdString());
    FAPI_INF("dimm_type = %d on %s.", l_attr_eff_dimm_type_u8, i_target.toEcmdString());
	FAPI_INF("\n Number of ranks on port=0 is %d ",iv_MAX_RANKS[0]);
	FAPI_INF("\n Number of ranks on port=1 is %d ",iv_MAX_RANKS[1]);
	
	
    if ( l_attr_eff_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM )
    {
	FAPI_INF("It is a CDIMM"); 
    }
    else
    {
	FAPI_INF("It is an ISDIMM"); 
    }
	
	FAPI_INF("\n Number of ranks on port=0 is %d ",iv_MAX_RANKS[0]);
	FAPI_INF("\n Number of ranks on port=1 is %d \n \n",iv_MAX_RANKS[1]);
    //FAPI_INF("num_drops_per_port = %d on %s.", l_attr_eff_num_drops_per_port_u8, i_target.toEcmdString());
    //FAPI_INF("num_ranks  = %d on %s.", iv_MAX_RANKS,i_target.toEcmdString());
    //FAPI_INF("dram_width = %d on %s. \n\n", l_attr_eff_dram_width_u8, i_target.toEcmdString());
	//fprintf(fp, "Schmoo  POS\tPort\tRank\tDQS\tNominal\t\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate  \n");
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    FAPI_INF("Schmoo  POS\tPort\tRank\tNIBBLE\tOFFSET\tBitRate  ");
    
        
		for (l_p=0;l_p<MAX_PORT;l_p++){
	 for (l_rank=0;l_rank<iv_MAX_RANKS[l_p];++l_rank)
    {
	
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 
	 
	 //FAPI_INF("\n schmoo=%d port=%d rank=%d and nibble=%d and value=%d ",iv_shmoo_type,l_p,rank,l_n,SHMOO[iv_shmoo_type].MBA.P[l_p].S[rank].K.offset[l_n]);
	 FAPI_INF("RD_DQS %d\t%d\t%d\t%d\t%d\t\t%d\n ",l_mbapos,l_p,rank,l_n,SHMOO[iv_shmoo_type].MBA.P[l_p].S[rank].K.offset[l_n],l_attr_mss_freq_u32);
	 //rc=get_error_cnt(i_target,l_p,rank,l_rp,l_dq,bound);
	 
			} 
		
		
	}
		
	 }
	    
    return rc;
 }

//#endif
/*------------------------------------------------------------------------------
 * Function: get_margin
 * Description  : This function is used to get margin for setup,hold and total eye width in Ps by using frequency  
 *
 * Parameters: Target:MBA
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::get_margin(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint8_t l_rnk,l_byte,l_nibble,l_bit;
    uint32_t l_attr_mss_freq_margin_u32 = 0;
    uint32_t l_freq=0;
	uint64_t l_cyc = 1000000000000000ULL;
    uint8_t l_dq=0;
    uint8_t  l_rp=0;
	uint8_t  l_p=0;
    uint8_t i_rank=0;
    uint64_t l_factor=0;
	uint64_t l_factor_ps=1000000000;
    
	//FAPI_INF("   the factor is % llu ",l_cyc);
    
    fapi::Target l_target_centaur;
    rc = fapiGetParentChip(i_target, l_target_centaur); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_margin_u32); if(rc) return rc;
    l_freq=l_attr_mss_freq_margin_u32/2;
    l_cyc=l_cyc/l_freq;// converting to zepto to get more accurate data  
    l_factor=l_cyc/128;
	//FAPI_INF("l_factor is % llu ",l_factor);
    
    
        	
	    
		for (l_p=0;l_p<MAX_PORT;l_p++){
		for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
	    {
		rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		i_rank=valid_rank[l_rnk];
		rc = mss_getrankpair(i_target,l_p,i_rank,&l_rp,valid_rank);if(rc) return rc; 
		for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
		{
		    
		    //Nibble loop
		    for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
		    {
			for(l_bit=0;l_bit< MAX_BITS;++l_bit)
			{
			    l_dq=8*l_byte+4*l_nibble+l_bit;
			    //FAPI_INF("  the right bound = %d and nominal = %d",SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_dq][l_rp]);
				if(iv_shmoo_type==8)
			    {
				if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp] == 0){
				//FAPI_INF("\n abhijit saurabh is here and dq=%d \n",l_dq);
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]=0;
				if(iv_shmoo_param!=4){
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]-2;
				}else{
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]-1;
				}
				//FAPI_INF("\n the value of left bound after is %d \n",SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]);
				}
				} 
				
				if(iv_shmoo_param==4){
				if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp]>SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_dq][l_rp]){
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp]-1;
				}
				if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]<SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_dq][l_rp]){
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]+1;
				}
				}else{
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp]-1;
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]+1;
				}
				
			    SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp]=((SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp]-SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_dq][l_rp])*l_factor)/l_factor_ps;
                            SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp]= ((SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_dq][l_rp]-SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp])*l_factor)/l_factor_ps;//((1/uint32_t_freq*1000000)/128);
			    SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp]+SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp];
                        }
                    }
                }
	    }
         }
     
    return rc;
 }

 fapi::ReturnCode generic_shmoo::get_margin_dqs_by4(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint8_t l_rnk;
    uint32_t l_attr_mss_freq_margin_u32 = 0;
    uint32_t l_freq=0;
	uint64_t l_cyc = 1000000000000000ULL;
   // uint8_t l_dq=0;
	uint8_t l_nibble=0;
    uint8_t  l_rp=0;
	uint8_t  l_p=0;
    uint8_t i_rank=0;
    uint64_t l_factor=0;
	uint64_t l_factor_ps=1000000000;
	uint8_t l_SCHMOO_NIBBLES=20;
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
    
	//FAPI_INF("   the factor is % llu ",l_cyc);
    
    fapi::Target l_target_centaur;
    rc = fapiGetParentChip(i_target, l_target_centaur); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_margin_u32); if(rc) return rc;
    l_freq=l_attr_mss_freq_margin_u32/2;
    l_cyc=l_cyc/l_freq;// converting to zepto to get more accurate data  
    l_factor=l_cyc/128;
	//FAPI_INF("l_factor is % llu ",l_factor);
    
    
        	
	    
		for (l_p=0;l_p<MAX_PORT;l_p++){
		//FAPI_INF("\n Abhijit is here before %d \n",l_p);  
		for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
	    {
		
		rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		i_rank=valid_rank[l_rnk];
		rc = mss_getrankpair(i_target,l_p,i_rank,&l_rp,valid_rank);if(rc) return rc; 
		    
		    //Nibble loop
			// FAPI_INF("\n Abhijit is outside  %d \n",l_p); 
		    for(l_nibble=0;l_nibble<l_SCHMOO_NIBBLES;l_nibble++)
		    {
			//FAPI_INF("\n Abhijit 11111 is here after schmoo type=%d  and port=%d \n",iv_shmoo_type,l_p);
			//FAPI_INF("  the right bound = %d and nominal = %d",SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble][l_rp]);
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble][l_rp]-1;
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble][l_rp]+1;
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble][l_rp]=((SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble][l_rp]-SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble][l_rp])*l_factor)/l_factor_ps;
                            SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble][l_rp]= ((SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble][l_rp]-SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble][l_rp])*l_factor)/l_factor_ps;//((1/uint32_t_freq*1000000)/128);
			    SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_nibble][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble][l_rp]+SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble][l_rp];
				//FAPI_INF("\n Abhijit is here after %d  and port=%d \n",l_nibble,l_p);
				//FAPI_INF("\n Abhijit is here after 2 %d \n",l_rnk); 
            }
          
			
        }
		 
	    }
          
     
    return rc;
 }
 
 fapi::ReturnCode generic_shmoo::get_margin_dqs_by8(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint8_t l_rnk;
    uint32_t l_attr_mss_freq_margin_u32 = 0;
    uint32_t l_freq=0;
	uint64_t l_cyc = 1000000000000000ULL;
    //uint8_t l_dq=0;
	uint8_t l_nibble=0;
    uint8_t  l_rp=0;
	uint8_t  l_p=0;
    uint8_t i_rank=0;
    uint64_t l_factor=0;
	uint64_t l_factor_ps=1000000000;
	uint8_t l_SCHMOO_NIBBLES=20;
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=9;
	}
    
	//FAPI_INF("   the factor is % llu ",l_cyc);
    
    fapi::Target l_target_centaur;
    rc = fapiGetParentChip(i_target, l_target_centaur); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_margin_u32); if(rc) return rc;
    l_freq=l_attr_mss_freq_margin_u32/2;
    l_cyc=l_cyc/l_freq;// converting to zepto to get more accurate data  
    l_factor=l_cyc/128;
	//FAPI_INF("l_factor is % llu ",l_factor);
    
    
        	
	    
		for (l_p=0;l_p<MAX_PORT;l_p++){
		//FAPI_INF("\n Abhijit is here before %d \n",l_p);  
		for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
	    {
		
		rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		i_rank=valid_rank[l_rnk];
		rc = mss_getrankpair(i_target,l_p,i_rank,&l_rp,valid_rank);if(rc) return rc; 
		    
		    //Nibble loop
			 //FAPI_INF("\n Abhijit is outside  %d \n",l_p); 
		    for(l_nibble=0;l_nibble<l_SCHMOO_NIBBLES;l_nibble++)
		    {
			if(iv_dmm_type==0)
			{
				if((l_nibble%2)){
				continue ;
				}
			}
			//FAPI_INF("\n Abhijit 11111 is here after schmoo type=%d  and port=%d \n",iv_shmoo_type,l_p);
			//FAPI_INF("  the port=%d rank=%d byte=%d right bound = %d and nominal = %d",l_p,i_rank,l_nibble,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble][l_rp]);
				//FAPI_INF("  the port=%d rank=%d byte=%d left bound = %d and nominal = %d",l_p,i_rank,l_nibble,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble][l_rp]);
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble][l_rp]-1;
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble][l_rp]+1;
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble][l_rp]=((SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble][l_rp]-SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble][l_rp])*l_factor)/l_factor_ps;
                            SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble][l_rp]= ((SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble][l_rp]-SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble][l_rp])*l_factor)/l_factor_ps;//((1/uint32_t_freq*1000000)/128);
			    SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_nibble][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble][l_rp]+SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble][l_rp];
				//FAPI_INF("\n Abhijit is here after %d  and port=%d \n",l_nibble,l_p);
				//FAPI_INF("\n Abhijit is here after 2 %d \n",l_rnk); 
            }
          
			
        }
		 
	    }
          
     
    return rc;
 }
/*------------------------------------------------------------------------------
 * Function: get_min_margin
 * Description  : This function is used to get the minimum margin of all the schmoo margins  
 *
 * Parameters: Target:MBA,right minimum margin , left minimum margin, pass fail 
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::get_min_margin(const fapi::Target & i_target,uint32_t *o_right_min_margin,uint32_t *o_left_min_margin)
{
    fapi::ReturnCode rc;
    uint8_t l_rnk,l_byte,l_nibble,l_bit,i_rank;
    uint16_t l_temp_right=4800;
    uint16_t l_temp_left=4800;
	//uint16_t l_temp_right_nibble=4800;
    //uint16_t l_temp_left_nibble=4800;
    uint8_t l_dq=0;
    uint8_t l_rp=0;
	uint8_t l_p=0;
	//uint32_t min_margin_nibble_right[MAX_PORT][MAX_RANK][MAX_BYTE][MAX_NIBBLES];
	//uint32_t min_margin_nibble_left[MAX_PORT][MAX_RANK][MAX_BYTE][MAX_NIBBLES];
    
    
        
	    for (l_p=0;l_p<MAX_PORT;l_p++){
		for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
	    {
		rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		i_rank=valid_rank[l_rnk];
		rc = mss_getrankpair(i_target,l_p,i_rank,&l_rp,valid_rank);if(rc) return rc; 
		for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
		{
		    
		    //Nibble loop
		    for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
		    {
			//l_temp_right_nibble=4800;
			//l_temp_left_nibble=4800;
			for(l_bit=0;l_bit< MAX_BITS;++l_bit)
			{	
			    l_dq=8*l_byte+4*l_nibble+l_bit;
			    if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp]<l_temp_right)
			    {
				l_temp_right=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp];
			    }
			    if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp]<l_temp_left)
			    {
				l_temp_left=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp];
			    }
				
				
				// if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp]<l_temp_right_nibble)
			    // {
				// l_temp_right_nibble=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp];
			    // }
			    // if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp]<l_temp_left_nibble)
			    // {
				// l_temp_left_nibble=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp];
			    // }
				
				// min_margin_nibble_right[l_p][i_rank][l_byte][l_nibble]=l_temp_right_nibble;
				// min_margin_nibble_left[l_p][i_rank][l_byte][l_nibble]=l_temp_left_nibble;
				
				//FAPI_INF("\n the minimum right margin for port=%d rank=%d byte=%d nibble=%d is %d \n",l_p,i_rank,l_byte,l_nibble,l_temp_right_nibble);
				//FAPI_INF("\n the minimum left margin for port=%d rank=%d byte=%d nibble=%d is %d \n",l_p,i_rank,l_byte,l_nibble,l_temp_left_nibble);
				
                        }
						
						
                    }
                }
				}
	    }
        
     
    // hacked for now till schmoo is running 
	if(iv_shmoo_type==8)
	{
		*o_right_min_margin=l_temp_left;
		*o_left_min_margin=l_temp_right;
	}else{
    *o_right_min_margin=l_temp_right;
    *o_left_min_margin=l_temp_left;
		}
    return rc;
 }
 
  fapi::ReturnCode generic_shmoo::get_min_margin_dqs(const fapi::Target & i_target,uint32_t *o_right_min_margin,uint32_t *o_left_min_margin)
{
    fapi::ReturnCode rc;
    uint8_t l_rnk,l_nibble,i_rank;
    uint16_t l_temp_right=4800;
    uint16_t l_temp_left=4800;
    
    uint8_t l_rp=0;
	uint8_t l_p=0;
	uint8_t l_attr_eff_dram_width_u8=0;

	
	
    
   
   
    
    uint8_t l_SCHMOO_NIBBLES=20;
	uint8_t l_by8_dqs=0;
	
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_attr_eff_dram_width_u8); if(rc) return rc;
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=18;
	}
	
	 if(l_attr_eff_dram_width_u8 == 8){
   l_SCHMOO_NIBBLES=10;
   if(iv_dmm_type==1)
    {
	l_SCHMOO_NIBBLES=9;
	}
   }
	iv_shmoo_type=4;
	
    for (l_p=0;l_p<MAX_PORT;l_p++){
		for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
	    {			rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
					    i_rank=valid_rank[l_rnk];
			    rc = mss_getrankpair(i_target,l_p,i_rank,&l_rp,valid_rank);if(rc) return rc;
		
		    for(l_nibble=0;l_nibble< l_SCHMOO_NIBBLES;++l_nibble)
		    {
				
			   l_by8_dqs=l_nibble;
			   if(iv_dmm_type==0)
			   {
			    if(l_attr_eff_dram_width_u8 == 8)
			    {
				l_nibble=l_nibble*2;
			    }
			   }
			
			if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_by8_dqs][l_rp]<l_temp_right)
			    {
				l_temp_right=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_by8_dqs][l_rp];
			    }
			    if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_by8_dqs][l_rp]<l_temp_left)
			    {
				l_temp_left=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_by8_dqs][l_rp];
			    }
		    }
		}
	    }
    
        
    // hacked for now till schmoo is running 
	if(iv_shmoo_type==8)
	{
		*o_right_min_margin=l_temp_left;
		*o_left_min_margin=l_temp_right;
	}else{
    *o_right_min_margin=l_temp_right;
    *o_left_min_margin=l_temp_left;
		}
    return rc;
 }
  fapi::ReturnCode generic_shmoo:: schmoo_setup_mcb( const fapi::Target & i_target)
{

struct Subtest_info l_sub_info[30];
    uint32_t l_pattern=0;
	uint32_t l_testtype=0;
    
	//uint32_t rc_num =0;
	mcbist_byte_mask i_mcbbytemask1;
	
	i_mcbbytemask1 = UNMASK_ALL;
	
    fapi::ReturnCode rc;
	

	
	
l_pattern=iv_pattern;
l_testtype=iv_test_type;

if(iv_shmoo_type==16){
FAPI_INF("\n Read DQS is running \n");
if(iv_DQS_ON==1){
	l_testtype=3;
	}
	if(iv_DQS_ON==2){
	l_testtype=4;
	}
	}
     //send shmoo mode to vary the address range
	if(iv_shmoo_type==16){ 
 rc = FAPI_ATTR_SET(ATTR_MCBIST_PATTERN, &i_target,l_pattern); if(rc) return rc;//-----------i_mcbpatt------->run
	rc = FAPI_ATTR_SET(ATTR_MCBIST_TEST_TYPE, &i_target, l_testtype); if(rc) return rc;//---------i_mcbtest------->run
	}
//rc = FAPI_ATTR_SET(ATTR_MCBIST_PATTERN, &i_target,iv_pattern); if(rc) return rc;//-----------i_mcbpatt------->run
//rc = FAPI_ATTR_SET(ATTR_MCBIST_TEST_TYPE, &i_target, iv_test_type); if(rc) return rc;//---------i_mcbtest------->run

rc = setup_mcbist(i_target,i_mcbbytemask1,0,l_sub_info);if(rc) return rc;
 

 
return rc;
}

 
}//Extern C
