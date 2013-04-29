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

// $Id: mss_generic_shmoo.C,v 1.47 2013/04/25 12:14:00 sasethur Exp $
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
// *! BACKUP NAME          : preetham      	      Email: preeragh@in.ibm.com
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:   | Comment:
// --------|--------|---------|--------------------------------------------------
//   1.45  |abhijit	|04/25/13 | added test type SIMPLE_FIX_RF and SHMOO_STRESS  
//   1.40  |abhijit	|03/22/13 | Fixed boundary checks  
//   1.38  |abhijit	|03/19/13 | included spare byte and ECC and fixed printing for RD_EYE 
//   1.36  |abhijit	|03/19/13 | changed mcbist call position   
//   1.35  |abhijit	|03/16/13 | fixed clearing of error map regs for mba23  
//   1.32  |abhijit	|03/12/13 | new parallel schmoo under dev 
//   1.27  |abhijit	|01/21/13 | fixed ISDIMM mapping need some workaround 
//   1.26  |abhijit	|01/21/13 | fixed fw comments  
//   1.25  |abhijit	|01/21/13 | fixed the constructor definition 
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
#include <dimmBadDqBitmapFuncs.H>
#include <mss_access_delay_reg.H>



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
        FAPI_DBG("mss_generic_shmoo : WR_EYE selected %d",shmoo_mask);
        iv_shmoo_type = 0;
        SHMOO[0].static_knob.min_val=0;
        SHMOO[0].static_knob.max_val=512;   
    }
    
    if(shmoo_mask & WR_EYE)
    {
        FAPI_DBG("mss_generic_shmoo : WR_EYE selected %d",shmoo_mask);
        iv_shmoo_type = 2;
        SHMOO[0].static_knob.min_val=0;
        SHMOO[0].static_knob.max_val=512;   
    }
    if(shmoo_mask & RD_EYE)
    {
        FAPI_DBG("mss_generic_shmoo : RD_EYE selected %d",shmoo_mask);
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
        FAPI_DBG("mss_generic_shmoo : RD_EYE selected %d",shmoo_mask);
        
        iv_shmoo_type = 3;
	iv_DQS_ON = 1;
        SHMOO[3].static_knob.min_val=2;
        SHMOO[3].static_knob.max_val=128;
    }
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

/*------------------------------------------------------------------------------
 * Function: run
 * Description  : ! Delegator function that runs shmoo using other  functions
 *
 * Parameters: i_target: mba;		iv_port: 0, 1
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::run(const fapi::Target & i_target,uint32_t *o_right_min_margin,uint32_t *o_left_min_margin,uint8_t i_pattern,uint8_t i_test_type,uint32_t i_shmoo_param){
    fapi::ReturnCode rc;  
    uint8_t num_ranks_per_dimm[2][2];
    uint8_t l_attr_eff_dimm_type_u8=0;
	uint8_t l_attr_schmoo_test_type_u8=0;
    //uint8_t l_val=2;
	iv_shmoo_param=i_shmoo_param;
	
    ecmdDataBufferBase l_data_buffer1_64(64);
	uint8_t l_dram_width=0;
    
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_dram_width); if(rc) return rc;
    
    
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_per_dimm); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, l_attr_eff_dimm_type_u8); if(rc) return rc; 
    rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target, l_attr_schmoo_test_type_u8); if(rc) return rc; 
	
	
	
    iv_MAX_RANKS[0]=num_ranks_per_dimm[0][0]+num_ranks_per_dimm[0][1];
	iv_MAX_RANKS[1]=num_ranks_per_dimm[1][0]+num_ranks_per_dimm[1][1];
	
    iv_pattern=i_pattern;
    iv_test_type=i_test_type;
    
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
	}else if(l_attr_schmoo_test_type_u8 == 4){
	
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
	rc=schmoo_setup_mcb(i_target);if(rc) return rc;
    //Find RIGHT BOUND OR SETUP BOUND
    rc=find_bound(i_target,RIGHT);if(rc) return rc;
    //Find LEFT BOUND OR HOLD BOUND
    rc=find_bound(i_target,LEFT);if(rc) return rc;
    //Find the margins in Ps i.e setup margin ,hold margin,Eye width 
    rc=get_margin(i_target);if(rc) return rc;
    //It is used to find the lowest of setup and hold margin
    rc=get_min_margin(i_target,o_right_min_margin,o_left_min_margin);if(rc) return rc;
    // It is used to print the schmoo report
    rc=print_report(i_target);if(rc) return rc;
	}
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
    uint8_t l_mcb_status=0;
    uint64_t l_time = 0x0000000000000000ull;
    uint8_t l_rank_valid = 0;
    
	
    
	FAPI_INF("  entering set_up mcbist now and rank %d",l_rank_valid);
	
	//rc = setup_mcbist(i_target, 0, MCBIST_2D_CUP_PAT8, CENSHMOO, UNMASK_ALL, 0,iv_pattern,iv_test_type,l_rank_valid,0,l_start,l_end,0);if(rc) return rc;  //send shmoo mode to vary the address range
	rc=schmoo_setup_mcb(i_target);if(rc) return rc;
	FAPI_INF("  starting  mcbist now");
	rc=start_mcb(i_target);if(rc) return rc;
	FAPI_INF("  polling   mcbist now");
	rc=poll_mcb(i_target,false,&l_mcb_status,l_time);if(rc) return rc;
	FAPI_INF("  checking error map ");
	rc=mcb_error_map(i_target,mcbist_error_map,0,l_rank_valid);if(rc) return rc;
    
    
    if(l_mcb_status)
    {
        FAPI_ERR("generic_shmoo:sanity_check failed !! MCBIST failed on intial run , memory is not in good state aborting shmoo");
		 FAPI_SET_HWP_ERROR(rc,RC_MSS_MCBIST_ERROR);		
        return rc;
    }

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
    uint64_t l_time = 0x0000000000000000ull;
	uint32_t rc_num =0;
	uint8_t l_mcb_status=0;
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
	
	rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTA1Q_0x02011664,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTA2Q_0x02011665,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTB1Q_0x02011667,l_data_buffer_64); if(rc) return(rc);
	rc = fapiPutScom(i_target,MBS_MCBIST01_MCB_ERRCNTB2Q_0x02011668,l_data_buffer_64); if(rc) return(rc);
	
   rc = start_mcb(i_target);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: Start MCBIST failed !!");  
				
        return rc;
    }
    rc=poll_mcb(i_target,false,&l_mcb_status,l_time);
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
	
	  
    for (l_p=0;l_p<MAX_PORT;l_p++){
	for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
    {// Byte loop
	rc = mss_getrankpair(i_target,l_p,0,&i_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rnk];
	rc=mcb_error_map(i_target,mcbist_error_map,port,rank);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
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
		//schmoo_error_map[l_p][rank][l_n]=0;
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
		    FAPI_INF("Nominal  Value for port=%d rank=%d  and rank pair=%d and dq=%d is  %d",l_p,i_rnk,i_rp,l_dq,val);
                    
		}
	    }
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
		    FAPI_INF("Nominal  Value for port=%d rank=%d  and rank pair=%d and dqs=%d is  %d",l_p,rank,i_rp,l_n,SHMOO[iv_shmoo_type].MBA.P[l_p].S[rank].K.nom_val[l_n][i_rp]);
	 }
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
	 
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
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
    uint32_t __attribute__((unused)) l_max=0; //SW198827    
	uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
	uint8_t l_SCHMOO_NIBBLES=20;
	uint8_t i_rp=0;
	
	
	
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
	 FAPI_INF("\n value of nominal delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_dqs,rank,l_p,l_n,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]+l_delay;
	 FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_dqs,rank,l_p,l_n,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,1,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d bit=%d is %d ",scenario,rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
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
	 FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,1,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
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
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
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
	 l_dq=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	 l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	  SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n][l_rp]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]-l_delay;
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,1,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
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
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,1,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
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
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
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
    uint32_t __attribute__((unused)) l_max=0; //SW198827
	uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
	uint8_t l_SCHMOO_NIBBLES=20;
	uint8_t i_rp=0;
	
	
	
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
	 FAPI_INF("\n value of nominal delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_dqs,rank,l_p,l_my_dqs,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_my_dqs][l_rp]);
	 SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_my_dqs][l_rp]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_my_dqs][l_rp]+l_delay;
	 FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_dqs,rank,l_p,l_my_dqs,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_my_dqs][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_my_dqs,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_my_dqs][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d bit=%d is %d ",scenario,rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
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
	 FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
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
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
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
	 l_dq=0;
	 l_my_dqs=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	 	 l_my_dqs=l_dqs_arr[l_n];
	 l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 
	 
	 if(schmoo_error_map[l_p][rank][l_n]==0){
	  SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_my_dqs][l_rp]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_my_dqs][l_rp]-l_delay;
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_my_dqs,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_my_dqs][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
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
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
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
    uint32_t __attribute__((unused)) l_max=0; //SW198827
    uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
        uint8_t __attribute__((unused))l_SCHMOO_BYTES=10; //SW198827
	uint8_t l_SCHMOO_NIBBLES=20;
	
	uint8_t i_rp=0;
	
	
	
			
		
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_BYTES=9;
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
	 FAPI_INF("\n value of nominal delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_scen_dqs,rank,l_p,l_n,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]+l_delay;
	 FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_scen_dqs,rank,l_p,l_n,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d bit=%d is %d ",scenario,rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
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
	 FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
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
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
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
	 l_dq=0;
	 l_dqs=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	 l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 
	 
	 if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)){
	  SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n][l_rp]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]-l_delay;
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
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
	 FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
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
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
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
    uint32_t __attribute__((unused)) l_max=0; //SW198827
	uint16_t l_max_limit=500;
    uint8_t rank=0;
	uint8_t l_rank=0;
        uint8_t  __attribute__((unused)) l_SCHMOO_BYTES=10;  //SW198827
	uint8_t l_SCHMOO_NIBBLES=20;
	
	uint8_t i_rp=0;
	
	
	
	if(iv_dmm_type==1)
    {
	l_SCHMOO_BYTES=9;
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
	 FAPI_INF("\n the value of error check is %d \n",schmoo_error_map[l_p][rank][l_n]);
	 if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)){
	 FAPI_INF("\n value of nominal delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_scen_dqs,rank,l_p,l_dqs,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_dqs][l_rp]);
	 SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs][l_rp]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_dqs][l_rp]+l_delay;
	 FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d dqs=%d is %d ",l_scen_dqs,rank,l_p,l_dqs,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_dqs,1,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay scenario=%d rank=%d for port=%d bit=%d is %d ",scenario,rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]+l_delay;
	 FAPI_INF("\n value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.rb_regval[l_dq][l_rp]);if(rc) return rc;
	  
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
	 FAPI_INF("\n restoring nominal values for dqs=%d port=%d rank=%d is %d \n",l_n,l_p,rank,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,1,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
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
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
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
	 l_dq=0;
	 l_dqs=0;
	 rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
		rank=valid_rank[l_rank];
		rc = mss_getrankpair(i_target,l_p,rank,&l_rp,valid_rank);if(rc) return rc;
	 for (l_n=0; l_n<l_SCHMOO_NIBBLES;l_n++){
	 l_dq=4*l_n;
	 l_max=SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp];
	 l_dqs=l_n/2;
	 
	 if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)){
	  SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs][l_rp]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_dqs][l_rp]-l_delay;
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_dqs,1,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs][l_rp]);if(rc) return rc;
	 SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
	  l_dq=l_dq+1;
	  SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]=SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]-l_delay;
	 FAPI_INF("\n left value of delay rank=%d for port=%d bit=%d is %d ",rank,l_p,l_dq,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);
	  rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.lb_regval[l_dq][l_rp]);if(rc) return rc;
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
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,1,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n][l_rp]);if(rc) return rc;
	 
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
	 rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,1,SHMOO[scenario].MBA.P[l_p].S[rank].K.nom_val[l_dq][l_rp]);if(rc) return rc;
	 l_dq=l_dq+4;
			} 
		}
	 }
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
    
    FAPI_INF("generic_shmoo::find_bound running find_bound function ");
    
        
        //rc=knob_update_dqs_by8_isdimm(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc;
              if(iv_DQS_ON == 1){
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
				}else{
			//Bit loop
                    for(l_bit=0;l_bit< MAX_BITS;++l_bit)
                    {
			// preetham function here
			
			pass=0;
			FAPI_INF("\n abhijit is inside find bound and schmoo type is %d \n",iv_shmoo_type);
			rc=knob_update(i_target,bound,iv_shmoo_type,l_bit,pass,flag); if(rc) return rc;   
                    
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
    //FAPI_INF("num_drops_per_port = %d on %s.", l_attr_eff_num_drops_per_port_u8, i_target.toEcmdString());
    //FAPI_INF("num_ranks  = %d on %s.", iv_MAX_RANKS,i_target.toEcmdString());
    //FAPI_INF("dram_width = %d on %s. \n\n", l_attr_eff_dram_width_u8, i_target.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    FAPI_INF("Schmoo  POS\tPort\tRank\tByte\tnibble\tbit\tNominal\t\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ");
    
    
        
	    
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
				FAPI_INF("WR_EYE %d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",l_mbapos,l_p,i_rank,l_byte,l_nibble,l_bit,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_dq][l_rp],l_attr_mss_freq_u32,iv_shmoo_param);
			    }
			    if(iv_shmoo_type==8)
			    {
				FAPI_INF("RD_EYE %d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",l_mbapos,l_p,i_rank,l_byte,l_nibble,l_bit,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_dq][l_rp],l_attr_mss_freq_u32,iv_shmoo_param);
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
    //FAPI_INF("num_drops_per_port = %d on %s.", l_attr_eff_num_drops_per_port_u8, i_target.toEcmdString());
    //FAPI_INF("num_ranks  = %d on %s.", iv_MAX_RANKS,i_target.toEcmdString());
    //FAPI_INF("dram_width = %d on %s. \n\n", l_attr_eff_dram_width_u8, i_target.toEcmdString());
	//fprintf(fp, "Schmoo  POS\tPort\tRank\tDQS\tNominal\t\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate  \n");
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    FAPI_INF("Schmoo  POS\tPort\tRank\tDQS\tNominal\t\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate  ");
    
    iv_shmoo_type=4;
        
	    
		for (l_p=0;l_p<MAX_PORT;l_p++){
		for (l_rnk=0;l_rnk<iv_MAX_RANKS[l_p];++l_rnk)
	    {			rc = mss_getrankpair(i_target,l_p,0,&l_rp,valid_rank);if(rc) return rc;
					    i_rank=valid_rank[l_rnk];
			    rc = mss_getrankpair(i_target,l_p,i_rank,&l_rp,valid_rank);if(rc) return rc;
		
		    for(l_nibble=0;l_nibble< l_SCHMOO_NIBBLES;++l_nibble)
		    {
				
			   l_by8_dqs=l_nibble;
			if(l_attr_eff_dram_width_u8 == 8){
			l_by8_dqs=l_nibble*2;
			
			}
			  //fprintf(fp,"WR_DQS %d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",l_mbapos,l_p,i_rank,l_nibble,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_by8_dqs][l_rp],l_attr_mss_freq_u32);
				FAPI_INF("WR_DQS %d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",l_mbapos,l_p,i_rank,l_nibble,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_by8_dqs][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.total_margin[l_by8_dqs][l_rp],l_attr_mss_freq_u32);
			    
			    
			    
			
		    }
		}
	    }
	
    //fclose(fp);
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
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]-2;
				//FAPI_INF("\n the value of left bound after is %d \n",SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]);
				}
				}
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq][l_rp]-1;
				SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq][l_rp]+1;
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
			FAPI_INF("  the port=%d rank=%d nibble=%d right bound = %d and nominal = %d",l_p,i_rank,l_nibble,SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble][l_rp],SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble][l_rp]);
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
    uint8_t l_dq=0;
    uint8_t l_rp=0;
	uint8_t l_p=0;

    
    
        
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
			    if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp]<l_temp_right)
			    {
				l_temp_right=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq][l_rp];
			    }
			    if(SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp]<l_temp_left)
			    {
				l_temp_left=SHMOO[iv_shmoo_type].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq][l_rp];
			    }
                        }
                    }
                }
				}
	    }
        
     
    // hacked for now till schmoo is running 
    *o_right_min_margin=l_temp_right;
    *o_left_min_margin=l_temp_left;
    return rc;
 }
 fapi::ReturnCode generic_shmoo:: schmoo_setup_mcb( const fapi::Target & i_target)
{


    
    
	//uint32_t rc_num =0;
	uint8_t l_pattern=0;
	uint8_t l_testtype=0;
	
    fapi::ReturnCode rc;
	
	uint64_t l_start =0x0000000000000000ull; 
    uint64_t l_end = 0x0000000000000000ull; 
	
	
	mcbist_test_mem i_mcbtest= CENSHMOO;
	mcbist_data_gen i_mcbpatt= ABLE_FIVE;
	
	
	  
	
	
    
	
    
     //send shmoo mode to vary the address range
   

l_pattern=iv_pattern;
FAPI_INF("value of pattern is %d",l_pattern);
switch(l_pattern)
{
case 0 : i_mcbpatt = ABLE_FIVE;break;
case 1 : i_mcbpatt = USR_MODE;break;
case 2 : i_mcbpatt = ONEHOT;break;
case 3 : i_mcbpatt = DQ0_00011111_RESTALLONE;break;
case 4 : i_mcbpatt = DQ0_11100000_RESTALLZERO;break;
case 5 : i_mcbpatt = ALLZERO;break;
case 6 : i_mcbpatt = ALLONE;break;
case 7 : i_mcbpatt = BYTE_BURST_SIGNATURE;break;
case 8 : i_mcbpatt = BYTE_BURST_SIGNATURE_V1;break;
case 9 : i_mcbpatt = BYTE_BURST_SIGNATURE_V2;break;
case 10 : i_mcbpatt = BYTE_BURST_SIGNATURE_V3;break;
case 11 : i_mcbpatt = DATA_GEN_DELTA_I;break;
case 12 : i_mcbpatt = MCBIST_2D_CUP_PAT0;break;
case 13 : i_mcbpatt = MPR;break;
case 14 : i_mcbpatt = MPR03;break;
case 15 : i_mcbpatt = MPR25;break;
case 16 : i_mcbpatt = MPR47;break;
case 17 : i_mcbpatt = DELTA_I1;break;
case 18 : i_mcbpatt = MCBIST_2D_CUP_PAT1;break;
case 19 : i_mcbpatt = MHC_55;break;
case 20 : i_mcbpatt = MHC_DQ_SIM;break;
case 21 : i_mcbpatt = MCBIST_2D_CUP_PAT2;break;
case 22 : i_mcbpatt = MCBIST_2D_CUP_PAT3;break;
case 23 : i_mcbpatt = MCBIST_2D_CUP_PAT4;break;
case 24 : i_mcbpatt = MCBIST_2D_CUP_PAT5;break;
case 25 : i_mcbpatt = MCBIST_2D_CUP_PAT6;break;
case 26 : i_mcbpatt = MCBIST_2D_CUP_PAT7;break;
case 27 : i_mcbpatt = MCBIST_2D_CUP_PAT8;break;
case 28 : i_mcbpatt = MCBIST_2D_CUP_PAT9;break;
case 29 : i_mcbpatt = CWLPATTERN;break;
case 30 : i_mcbpatt = GREY1;break;
case 31 : i_mcbpatt = DC_ONECHANGE;break;
case 32 : i_mcbpatt = DC_ONECHANGEDIAG;break;
case 33 : i_mcbpatt = GREY2;break;
case 34 : i_mcbpatt = FIRST_XFER;break;
case 35 : i_mcbpatt = MCBIST_222_XFER;break;
case 36 : i_mcbpatt = MCBIST_333_XFER;break;
case 37 : i_mcbpatt = MCBIST_444_XFER;break;
case 38 : i_mcbpatt = MCBIST_555_XFER;break;
case 39 : i_mcbpatt = MCBIST_666_XFER;break;
case 40 : i_mcbpatt = MCBIST_777_XFER;break;
case 41 : i_mcbpatt = MCBIST_888_XFER;break;
case 42 : i_mcbpatt = FIRST_XFER_X4MODE;break;
case 43 : i_mcbpatt = MCBIST_LONG;break;
case 44 : i_mcbpatt = PSEUDORANDOM;break;
case 45 : i_mcbpatt = CASTLE;break;

default : FAPI_INF("Wrong Data Pattern,so using default pattern");
}
l_testtype=iv_test_type;
switch(l_testtype)
{
case 0 : i_mcbtest = USER_MODE;break;
case 1 : i_mcbtest = CENSHMOO;break;
case 2 : i_mcbtest = SUREFAIL;break;
case 3 : i_mcbtest = MEMWRITE;break;
case 4 : i_mcbtest = MEMREAD;break;
case 5 : i_mcbtest = CBR_REFRESH;break;
case 6 : i_mcbtest = MCBIST_SHORT;break;
case 7 : i_mcbtest = SHORT_SEQ;break;
case 8 : i_mcbtest = DELTA_I;break;
case 9 : i_mcbtest = DELTA_I_LOOP;break;
case 10 : i_mcbtest = SHORT_RAND;break;
case 11 : i_mcbtest = LONG1;break;
case 12 : i_mcbtest = BUS_TAT;break;
case 13 : i_mcbtest = SIMPLE_FIX;break;
case 14 : i_mcbtest = SIMPLE_RAND;break;
case 15 : i_mcbtest = SIMPLE_RAND_2W;break;
case 16 : i_mcbtest = SIMPLE_RAND_FIXD;break;
case 17 : i_mcbtest = SIMPLE_RA_RD_WR;break;
case 18 : i_mcbtest = SIMPLE_RA_RD_R;break;
case 19 : i_mcbtest = SIMPLE_RA_FD_R;break;
case 20 : i_mcbtest = SIMPLE_RA_FD_R_INF;break;
case 21 : i_mcbtest = SIMPLE_SA_FD_R;break;
case 22 : i_mcbtest = SIMPLE_RA_FD_W;break;
case 23 : i_mcbtest = INFINITE;break;
case 24 : i_mcbtest = WR_ONLY;break;
case 25 : i_mcbtest = W_ONLY;break;
case 26 : i_mcbtest = R_ONLY;break;
case 27 : i_mcbtest = W_ONLY_RAND;break;
case 28 : i_mcbtest = R_ONLY_RAND;break;
case 29 : i_mcbtest = R_ONLY_MULTI;break;
case 30 : i_mcbtest = SHORT;break;  
case 31 : i_mcbtest = SIMPLE_RAND_BARI;break; 
case 32 : i_mcbtest = W_R_INFINITE;break; 
case 33 : i_mcbtest = W_R_RAND_INFINITE;break; 
case 34 : i_mcbtest = R_INFINITE1;break; 
case 35 : i_mcbtest = R_INFINITE_RF;break; 
case 36 : i_mcbtest = MARCH;break; 
case 37 : i_mcbtest = SIMPLE_FIX_RF;break;
case 38 : i_mcbtest = SHMOO_STRESS;break;
default : FAPI_INF("Wrong Test_type,so using default test_type");
}
rc = setup_mcbist(i_target, 0,  i_mcbpatt, i_mcbtest, UNMASK_ALL, 0,iv_pattern,iv_test_type,0,0,l_start,l_end,iv_addr);if(rc) return rc;

return rc;
}

 
}//Extern C
