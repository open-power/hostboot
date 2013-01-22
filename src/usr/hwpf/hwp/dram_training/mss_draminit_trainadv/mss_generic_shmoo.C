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
// $Id: mss_generic_shmoo.C,v 1.23 2013/01/18 12:04:57 sasethur Exp $
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
//   1.21  |sasethur|01/17/13 | Updated for sanity mcbist function
//   1.20  |abhijith|01/11/13 | Updated for change in setup_mcbist function
//   1.19  |aditya  |01/07/13 | Updated for change in setup_mcbist function
//   1.18  |sasethur|14-DEC-12| Updated for change in access delay function 
//   1.16  |sasethur|14-DEC-12| Updated for Warning 
//   1.15  |abhijit |13-DEC-12| Updated for FW review comments 
//   1.14  |abhijit |06-DEC-12| Fixed more FW review comments
//   1.12  |abhijit |15-Nov-12| Fixed FW review comments
//   1.11  |abhijit |29-Oct-12| added change for ISDIMM checker DQS.
//   1.9   |abhijit |22-Oct-12| added Write and read DQS.  
//   1.8   |abhijit |15-Oct-12|Updated multiple changes 
//   1.0   |varkeykv|27-Sep-11|Initial check in
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
generic_shmoo:: generic_shmoo(uint8_t prt,uint32_t shmoo_mask,shmoo_algorithm_t shmoo_algorithm)
{
    this->shmoo_mask=shmoo_mask; //! Sets what Shmoos the caller wants to run
    this->algorithm=shmoo_algorithm ;
    this->iv_port=prt ;
    
    
    iv_MAX_RANKS=8;
    iv_MAX_BYTES=10;
    iv_DQS_ON=0;
    iv_pattern=0;
    iv_test_type=0;
    iv_dmm_type=0;
    
    for(int i=0;i<iv_MAX_RANKS;++i)
    {
        valid_rank[i]=0;
    }
    
    FAPI_DBG("mss_generic_shmoo : constructor running for shmoo type %d",shmoo_mask);
    
    
    
    if(shmoo_mask & WR_EYE)
    {
        FAPI_DBG("mss_generic_shmoo : WR_EYE selected %d",shmoo_mask);
        iv_shmoo_type = 0;
        SHMOO[0].static_knob.min_val=0;
        SHMOO[0].static_knob.max_val=512;   
    }
    if(shmoo_mask & RD_EYE)
    {
        FAPI_DBG("mss_generic_shmoo : RD_EYE selected %d",shmoo_mask);
        iv_shmoo_type = 2;
        SHMOO[2].static_knob.min_val=0;
        SHMOO[2].static_knob.max_val=128;
    }
	
     if(shmoo_mask & WRT_DQS) //preet
    {
        FAPI_DBG("mss_generic_shmoo : WRT_DQS selected %d",shmoo_mask);
        iv_shmoo_type = 1;
		iv_DQS_ON = 1;
        SHMOO[1].static_knob.min_val=0;
        SHMOO[1].static_knob.max_val=512;
    }
	
    if(shmoo_mask & RD_GATE) //preet
    {
        FAPI_DBG("mss_generic_shmoo : RD_EYE selected %d",shmoo_mask);
        
        iv_shmoo_type = 3;
	iv_DQS_ON = 1;
        SHMOO[3].static_knob.min_val=0;
        SHMOO[3].static_knob.max_val=128;
    }
	
    for(int j=0;j<iv_MAX_RANKS;++j)
    {
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.nom_val,0);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.lb_regval,SHMOO[iv_shmoo_type].static_knob.min_val);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.rb_regval,SHMOO[iv_shmoo_type].static_knob.max_val);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.total_margin,0);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.right_margin_val,0);
        init_multi_array(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.left_margin_val,0);
    }
	
	if(iv_DQS_ON == 1)
	{
		for(int j=0;j<iv_MAX_RANKS;++j) //initialize values for DQS
        {
            init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.nom_val,0);
            init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.lb_regval,SHMOO[iv_shmoo_type].static_knob.min_val);
            init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.rb_regval,SHMOO[iv_shmoo_type].static_knob.max_val);
            init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.total_margin,0);
	    init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.right_margin_val,0);
	    init_multi_array_dqs(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[j].K.left_margin_val,0);
        }
	}
}

/*------------------------------------------------------------------------------
 * Function: run
 * Description  : ! Delegator function that runs shmoo using other  functions
 *
 * Parameters: i_target: mba;		iv_port: 0, 1
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::run(const fapi::Target & i_target,uint32_t *o_right_min_margin,uint32_t *o_left_min_margin,uint8_t i_pattern,uint8_t i_test_type){
    fapi::ReturnCode rc;  
    uint8_t num_ranks_per_dimm[2][2];
    uint8_t l_attr_eff_dimm_type_u8=0;
	uint8_t l_attr_schmoo_test_type_u8=0;
    uint8_t rank_pair=0;
    uint16_t l_sp_mask=0x00ff;
    ecmdDataBufferBase l_data_buffer1_64(64);
    uint32_t rc_num = 0;
    
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_per_dimm); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, l_attr_eff_dimm_type_u8); if(rc) return rc; 
    rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target, l_attr_schmoo_test_type_u8); if(rc) return rc; 
    iv_MAX_RANKS=num_ranks_per_dimm[iv_port][0]+num_ranks_per_dimm[iv_port][1];
    iv_pattern=i_pattern;
    iv_test_type=i_test_type;
    //FAPI_INF("\n abhijit the test type %d \n",l_attr_schmoo_test_type_u8);
    if ( l_attr_eff_dimm_type_u8 == 0 )
    {
	iv_MAX_BYTES=8;
    }
    else
    {
	if(iv_port==0)
	{
	    rc_num = rc_num | l_data_buffer1_64.insertFromRight(l_sp_mask,0,16);
	    if(rc_num)
	    {
		FAPI_ERR( "mss_generic_shmoo: Error in run !");       
		rc.setEcmdError(rc_num); 
		return rc;
	    } 
	}
	else
	{
	    rc_num = rc_num | l_data_buffer1_64.insertFromRight(l_sp_mask,16,16);
	    if(rc_num)
	    {
		FAPI_ERR( "mss_generic_shmoo:");       
		rc.setEcmdError(rc_num); 
		return rc;
	    } 
	}
	rc = fapiPutScom(i_target,MBS_MCBIST01_MCBCMABQ_0x02011674,l_data_buffer1_64); if(rc) return rc;
	iv_dmm_type=1;
	iv_MAX_BYTES=9;
    }
    rc = mss_getrankpair(i_target,iv_port,0,&rank_pair,valid_rank);if(rc) return rc; 
    FAPI_DBG("mss_generic_shmoo : run() for shmoo type %d",shmoo_mask);
     // Check if all bytes/bits are in a pass condition initially .Otherwise quit
    if(l_attr_schmoo_test_type_u8 == 0){
	FAPI_INF("This procedure wont change any delay settings");
	}
    if(l_attr_schmoo_test_type_u8 == 1){
	rc=sanity_check(i_target); // Run MCBIST only when ATTR_EFF_SCHMOO_TEST_VALID is mcbist only 
    if(!rc.ok())
    {
    FAPI_ERR("generic_shmoo::run MSS Generic Shmoo failed initial Sanity Check. Memory not in an all pass Condition");
    return rc; 
    }
	}else{
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
    uint8_t l_rank = 0;
    uint8_t l_rank_valid = 0;
    uint8_t l_byte = 0;
    uint8_t l_nibble = 0;
    uint8_t l_socket =0;
	uint32_t rc_num = 0;
    uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE];
	uint64_t l_original_start_address1 = 0x0000000000000000;
    uint64_t l_original_end_address1 = 0x0000000000000000;
    uint64_t l_original_start_address2 = 0x0000000000000000;
    uint64_t l_original_end_address2 = 0x0000000000000000;
	uint64_t l_start =0x0000000000000000ull; 
    uint64_t l_end = 0x0000000000000000ull; 
	uint64_t l_time = 0x0000000000000000ull;
    ecmdDataBufferBase l_data_bufferx1_64(64); 
    ecmdDataBufferBase l_data_bufferx2_64(64);
    ecmdDataBufferBase l_data_bufferx3_64(64); 
    ecmdDataBufferBase l_data_bufferx4_64(64);
    
	rc = fapiGetScom(i_target,MBA01_MCBIST_MCBSSARA0Q_0x030106d0,l_data_bufferx1_64); if(rc) return rc;
	rc = fapiGetScom(i_target,MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_bufferx2_64); if(rc) return rc;
	rc = fapiGetScom(i_target,MBA01_MCBIST_MCBSSARA1Q_0x030106d1,l_data_bufferx3_64); if(rc) return rc;    
	rc = fapiGetScom(i_target,MBA01_MCBIST_MCBSEARA1Q_0x030106d3,l_data_bufferx4_64); if(rc) return rc;
	l_original_start_address1 = l_data_bufferx1_64.getDoubleWord (0);
        l_original_end_address1 = l_data_bufferx2_64.getDoubleWord (0);
        l_original_start_address2 = l_data_bufferx3_64.getDoubleWord (0);
        l_original_end_address2 = l_data_bufferx4_64.getDoubleWord (0);
    for(l_rank = 0; l_rank < iv_MAX_RANKS; l_rank++)
    {
	l_rank_valid=valid_rank[l_rank];
	
	if(l_rank_valid<MAX_RANK_DIMM)
	{   
	    l_socket=0;
	}
	else
	{
	l_socket=1;
	}	
	FAPI_INF("  entering set_up mcbist now and rank %d",l_rank_valid);
	
	rc = setup_mcbist(i_target, iv_port, MCBIST_2D_CUP_PAT8, CENSHMOO, UNMASK_ALL, 0,iv_pattern,iv_test_type,l_rank_valid,0,l_start,l_end);if(rc) return rc;  //send shmoo mode to vary the address range

	FAPI_INF("  starting  mcbist now");
	rc=start_mcb(i_target);if(rc) return rc;
	FAPI_INF("  polling   mcbist now");
	rc=poll_mcb(i_target,false,&l_mcb_status,l_time);if(rc) return rc;
	FAPI_INF("  checking error map ");
	rc=mcb_error_map(i_target,mcbist_error_map,iv_port,l_rank_valid);if(rc) return rc;
	for(l_byte = 0; l_byte < iv_MAX_BYTES; l_byte++)
	{
	    for(l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
	    {
	        if(mcbist_error_map[iv_port][l_rank_valid][l_byte][l_nibble] == 1)
		{
		    if(l_nibble == 0)
		    {
			l_dqBitmap[l_byte] = 0xf0;
		    }
		    else
		    {
			l_dqBitmap[l_byte] = 0x0f;
		    }	
		    rc = dimmSetBadDqBitmap(i_target,iv_port,l_socket, l_rank_valid, l_dqBitmap);if(rc) return rc;
		}
	    }    
        }
		rc_num  =  l_data_bufferx1_64.setDoubleWord(0,l_original_start_address1);if (rc_num){FAPI_ERR( "Error in function  sanity_check:");rc.setEcmdError(rc_num);return rc;}
	    rc_num  =  l_data_bufferx2_64.setDoubleWord(0,l_original_end_address1);if (rc_num){FAPI_ERR( "Error in function  sanity_check:");rc.setEcmdError(rc_num);return rc;}
	    rc_num  =  l_data_bufferx3_64.setDoubleWord(0,l_original_start_address2);if (rc_num){FAPI_ERR( "Error in function  sanity_check:");rc.setEcmdError(rc_num);return rc;}
	    rc_num  =  l_data_bufferx4_64.setDoubleWord(0,l_original_end_address2);if (rc_num){FAPI_ERR( "Error in function  sanity_check:");rc.setEcmdError(rc_num);return rc;}
        rc = fapiPutScom(i_target,MBA01_MCBIST_MCBSSARA0Q_0x030106d0,l_data_bufferx1_64);  if(rc) return rc;
        rc = fapiPutScom(i_target,MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_bufferx2_64);  if(rc) return rc;
        rc = fapiPutScom(i_target,MBA01_MCBIST_MCBSSARA1Q_0x030106d1,l_data_bufferx3_64); if(rc) return rc;
        rc = fapiPutScom(i_target,MBA01_MCBIST_MCBSEARA1Q_0x030106d3,l_data_bufferx4_64); if(rc) return rc;
    
    }
    
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
fapi::ReturnCode generic_shmoo::do_mcbist_test(const fapi::Target & i_target,uint8_t i_rank,uint8_t i_byte,uint8_t i_nibble,uint8_t &pass)
{
    mcbist_mode=QUARTER_SLOW;
    uint8_t l_socket=0;
    uint8_t l_mcb_status=0;
    input_type l_input_type_e =  ISDIMM_DQ;
    uint8_t i_input_index_u8=0;
    uint8_t l_val =0;
	uint32_t rc_num =0;
    fapi::ReturnCode rc;
	uint64_t l_original_start_address1 = 0x0000000000000000;
    uint64_t l_original_end_address1 = 0x0000000000000000;
    uint64_t l_original_start_address2 = 0x0000000000000000;
    uint64_t l_original_end_address2 = 0x0000000000000000;
    ecmdDataBufferBase l_data_bufferx1_64(64); 
    ecmdDataBufferBase l_data_bufferx2_64(64);
    ecmdDataBufferBase l_data_bufferx3_64(64); 
    ecmdDataBufferBase l_data_bufferx4_64(64);
	uint64_t l_start =0x0000000000000000ull; 
    uint64_t l_end = 0x0000000000000000ull; 
	uint64_t l_time = 0x0000000000000000ull;
	rc = fapiGetScom(i_target,MBA01_MCBIST_MCBSSARA0Q_0x030106d0,l_data_bufferx1_64); if(rc) return rc;
	rc = fapiGetScom(i_target,MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_bufferx2_64); if(rc) return rc;
	rc = fapiGetScom(i_target,MBA01_MCBIST_MCBSSARA1Q_0x030106d1,l_data_bufferx3_64); if(rc) return rc;    
	rc = fapiGetScom(i_target,MBA01_MCBIST_MCBSEARA1Q_0x030106d3,l_data_bufferx4_64); if(rc) return rc;
	l_original_start_address1 = l_data_bufferx1_64.getDoubleWord (0);
    l_original_end_address1 = l_data_bufferx2_64.getDoubleWord (0);
    l_original_start_address2 = l_data_bufferx3_64.getDoubleWord (0);
    l_original_end_address2 = l_data_bufferx4_64.getDoubleWord (0);
	
    if(i_rank<4)
    {   
	l_socket=0;
    }
    else
    {
	l_socket=1;
    }	
    
	
    
   rc = setup_mcbist(i_target, iv_port, MCBIST_2D_CUP_PAT5, CENSHMOO, UNMASK_ALL, 0,iv_pattern,iv_test_type,i_rank,0,l_start,l_end);if(rc) return rc;  //send shmoo mode to vary the address range
   
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
    rc=mcb_error_map(i_target,mcbist_error_map,iv_port,i_rank);
    if(rc)
    {
        FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!"); 
			
        return rc;
    }
    rc_num  =  l_data_bufferx1_64.setDoubleWord(0,l_original_start_address1);if (rc_num){FAPI_ERR( "Error in function  do_mcbist_test:");rc.setEcmdError(rc_num);return rc;}
	rc_num  =  l_data_bufferx2_64.setDoubleWord(0,l_original_end_address1);if (rc_num){FAPI_ERR( "Error in function  do_mcbist_test:");rc.setEcmdError(rc_num);return rc;}
	rc_num  =  l_data_bufferx3_64.setDoubleWord(0,l_original_start_address2);if (rc_num){FAPI_ERR( "Error in function  do_mcbist_test:");rc.setEcmdError(rc_num);return rc;}
	rc_num  =  l_data_bufferx4_64.setDoubleWord(0,l_original_end_address2);if (rc_num){FAPI_ERR( "Error in function  do_mcbist_test:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiPutScom(i_target,MBA01_MCBIST_MCBSSARA0Q_0x030106d0,l_data_bufferx1_64);  if(rc) return rc;
    rc = fapiPutScom(i_target,MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_bufferx2_64);  if(rc) return rc;
    rc = fapiPutScom(i_target,MBA01_MCBIST_MCBSSARA1Q_0x030106d1,l_data_bufferx3_64); if(rc) return rc;
    rc = fapiPutScom(i_target,MBA01_MCBIST_MCBSEARA1Q_0x030106d3,l_data_bufferx4_64); if(rc) return rc;
	
    if(iv_dmm_type==1)
    {
	i_input_index_u8=8*i_byte+4*i_nibble;
	rc=rosetta_map(i_target,iv_port,l_input_type_e,i_input_index_u8,0,l_val);if(rc) return rc;
	i_byte=l_val/8;
	i_nibble=l_val%4;
	check_error_map(i_rank,i_byte,i_nibble,pass);
    
    }
    else
    {
	check_error_map(i_rank,i_byte,i_nibble,pass);
	
    }
    return rc;
}
/*------------------------------------------------------------------------------
 * Function: check_error_map
 * Description  : used by do_mcbist_test  to check the error map for particular nibble
 *
 * Parameters: iv_port 0/1 , rank 0-7 , byte 0-7, nibble 0/1, pass;	
 * ---------------------------------------------------------------------------*/
void  generic_shmoo::check_error_map(uint8_t i_rank,uint8_t i_byte,uint8_t i_nibble,uint8_t &pass)
{
    
    if( mcbist_error_map [iv_port][i_rank][i_byte][i_nibble] == 1){
        pass=0;
       // FAPI_INF("We are in error1");
    }
    else
    {
        pass=1;
        //FAPI_INF("We are in error2");
    }
    
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
             
    input_type_t l_input_type_e = WR_DQ;
    access_type_t l_access_type_e = READ ;
    FAPI_DBG("mss_generic_shmoo : get_all_noms : Reading in all nominal values");
    
    
             if(iv_shmoo_type == 1)
            {   
		l_input_type_e = WR_DQS;
                
            }
            else if(iv_shmoo_type == 2)
            {   
		
		l_input_type_e = RD_DQ;
                
            }
            else if(iv_shmoo_type == 3)
            {   
		
		l_input_type_e = RD_DQS;
                   
            }
            
	   
    for (l_rnk=0;l_rnk<iv_MAX_RANKS;++l_rnk)
    {// Byte loop
		i_rnk=valid_rank[l_rnk];
		    rc = mss_getrankpair(i_target,iv_port,i_rnk,&i_rp,valid_rank);if(rc) return rc; 
        for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
        {   //Nibble loop
            for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
            { 
		//Bit loop
                for(l_bit=0;l_bit<MAX_BITS;++l_bit)
                {  
		    l_dq=8*l_byte+4*l_nibble+l_bit;
		    
		    rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,i_rnk,l_input_type_e,l_dq,0,val);if(rc) return rc; 
		    SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rnk].K.nom_val[l_dq][i_rp]=val;
		    FAPI_INF("Nominal  Value for rank=%d  and rank pair=%d and dq=%d is  %d",i_rnk,i_rp,l_dq,val);
                    
		}
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
fapi::ReturnCode generic_shmoo::knob_update(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t rank,uint8_t byte,uint8_t nibble,uint8_t bit,uint8_t pass,bool &flag)
{	
    fapi::ReturnCode rc;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase data_buffer_64_1(64);
    uint32_t l_current_val=0;
    uint32_t l_left_del=1;
    uint32_t l_right_del=1;
    uint32_t l_max_value=0;
    uint32_t l_min_value=0;
    uint16_t l_nibb_err_chk=2*byte+nibble;
    uint32_t l_rd_cnt_A=0;
    uint32_t l_rd_cnt_B=0;
    uint32_t l_err_cnt_C=0;
    uint32_t l_start_bit=0;
    uint32_t rc_ecmd;
    uint32_t l_length_buffer=7;
    uint32_t l_delta=0;
    uint32_t l_err_prblty=0;
    uint8_t  l_rp=0;
    input_type_t l_input_type_e = WR_DQ;
    uint8_t l_dq=0;
    access_type_t l_access_type_e = WRITE;

    
    
    l_dq=8*byte+4*nibble+bit;
	
    rc = mss_getrankpair(i_target,iv_port,rank,&l_rp,valid_rank);if(rc) return rc; 
	
	
    if(scenario == 2) {
	l_input_type_e = RD_DQ;
	}
	
    
    if(bound==LEFT)
    {
        
	if(algorithm==SEQ_LIN)
        {
	    l_min_value=SHMOO[scenario].static_knob.min_val;
	    for(l_current_val=SHMOO[scenario].MBA.P[iv_port].S[rank].K.nom_val[l_dq][l_rp];((l_current_val >= l_left_del)&&(pass==1));l_current_val-=l_left_del)
	    {
		FAPI_INF("  The current value inside left bound for dq=%d and rp=%d  is %d  ",l_dq,l_rp,l_current_val);
		rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,rank,l_input_type_e,l_dq,1,l_current_val);if(rc) return rc;
		rc=do_mcbist_test(i_target,rank,byte,nibble,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
	    }
	    if(flag)
	    {
		pass=1;
		for(l_current_val=l_current_val+10;((l_current_val>l_min_value)&&(pass==1));l_current_val--)
		{ 
		    rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,rank,l_input_type_e,l_dq,0,l_current_val);if(rc) return rc;
		    rc = fapiGetScom(i_target,MBA01_MBA_PMU0Q_0x03010437,data_buffer_64); if(rc) return rc;
		    l_rd_cnt_A = data_buffer_64.getDoubleWord(0);
			do
			{
			    rc = fapiGetScom(i_target,MBA01_MBA_PMU0Q_0x03010437,data_buffer_64); if(rc) return rc;
			    l_rd_cnt_B = data_buffer_64.getDoubleWord(0);
				if(iv_port==0)
				{
				    if(l_nibb_err_chk<9)
				    {
					rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTA1Q_0x02011664,data_buffer_64_1); if(rc) return rc;
					l_start_bit=l_nibb_err_chk*7;
					rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
				    }
				    else
				    {
					rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTA2Q_0x02011665,data_buffer_64_1); if(rc) return rc;
					l_nibb_err_chk=l_nibb_err_chk-9;
					l_start_bit=l_nibb_err_chk*7;
					rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
				    }
				}
				else
				{
				    if(l_nibb_err_chk<9)
				    {
					rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTB1Q_0x02011667,data_buffer_64_1); if(rc) return rc;
					l_start_bit=l_nibb_err_chk*7;
					rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
				    }
				    else
				    {
					rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTB2Q_0x02011668,data_buffer_64_1); if(rc) return rc;
					l_nibb_err_chk=l_nibb_err_chk-9;
					l_start_bit=l_nibb_err_chk*7;
					rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
				    }
				}
				if(l_rd_cnt_A>l_rd_cnt_B)
				{
				    l_delta=l_rd_cnt_A-l_rd_cnt_B;
				}
				else
				{
				    l_delta=l_rd_cnt_B-l_rd_cnt_A;
				}
				if(l_delta>read_counter_threshold)
				{
				    l_err_prblty=l_err_cnt_C*read_counter_threshold;
				    l_err_prblty=l_err_prblty/l_delta;
				    if(l_err_prblty>error_threshold_count)
				    {
					pass=0;
				    }
				    else
				    {
					pass=1;
				    }
				}	
			}while(l_delta<read_counter_threshold);
			if(!pass)
			{
			    SHMOO[scenario].MBA.P[iv_port].S[rank].K.lb_regval[l_dq][l_rp]=l_current_val;
			}
		}	
	    }
	    if(!pass)
	    {
		SHMOO[scenario].MBA.P[iv_port].S[rank].K.lb_regval[l_dq][l_rp]=l_current_val+l_left_del;
	    }
	    else
	    {
		SHMOO[scenario].MBA.P[iv_port].S[rank].K.lb_regval[l_dq][l_rp]=l_current_val+l_left_del;
	    }
	    l_current_val=SHMOO[scenario].MBA.P[iv_port].S[rank].K.nom_val[l_dq][l_rp];
		FAPI_INF("  the restoring nominal value for rank=%d dq=%d and rp=%d is %d",rank,l_dq,l_rp,l_current_val);
	    rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,rank,l_input_type_e,l_dq,0,l_current_val);if(rc) return rc;
	}
    }	
    if(bound==RIGHT)
    {
        if(algorithm==SEQ_LIN)
        {
	    l_max_value=SHMOO[scenario].static_knob.max_val;
	    for(l_current_val=SHMOO[scenario].MBA.P[iv_port].S[rank].K.nom_val[l_dq][l_rp];((l_current_val<l_max_value)&&(pass==1));l_current_val+=l_right_del)
	    {
		FAPI_INF("  The current value inside right bound dq=%d and rp=%d  is %d  ",l_dq,l_rp,l_current_val);
		rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,rank,l_input_type_e,l_dq,1,l_current_val);if(rc) return rc;
		rc=do_mcbist_test(i_target,rank,byte,nibble,pass);
		if(rc)
		{   
		    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		}
	    }
	    
	    if(flag)
	    {
		pass=1;
		for(l_current_val=l_current_val-20;((l_current_val<l_max_value)&&(pass==1));l_current_val++)
		{
		    rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,rank,l_input_type_e,l_dq,0,l_current_val);if(rc) return rc;
		    rc = fapiGetScom(i_target,MBA01_MBA_PMU0Q_0x03010437,data_buffer_64); if(rc) return rc;
		    l_rd_cnt_A = data_buffer_64.getDoubleWord(0);
		    do
		    {
			rc = fapiGetScom(i_target,MBA01_MBA_PMU0Q_0x03010437,data_buffer_64); if(rc) return rc;
			l_rd_cnt_B = data_buffer_64.getDoubleWord(0);
			if(iv_port==0)
			{
			    if(l_nibb_err_chk<9)
			    {
				rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTA1Q_0x02011664,data_buffer_64_1); if(rc) return rc;
				l_start_bit=l_nibb_err_chk*7;
				rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
			    }
			    else
			    {
				rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTA2Q_0x02011665,data_buffer_64_1); if(rc) return rc;
				l_nibb_err_chk=l_nibb_err_chk-9;
				l_start_bit=l_nibb_err_chk*7;
				rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
			    }
			}
			else
			{
			    if(l_nibb_err_chk<9)
			    {
				rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTB1Q_0x02011667,data_buffer_64_1); if(rc) return rc;
				l_start_bit=l_nibb_err_chk*7;
				rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
			    }
			    else
			    {
				rc = fapiGetScom(i_target,MBS_MCBIST01_MCB_ERRCNTB2Q_0x02011668,data_buffer_64_1); if(rc) return rc;
				l_nibb_err_chk=l_nibb_err_chk-9;
				l_start_bit=l_nibb_err_chk*7;
				rc_ecmd=data_buffer_64.extractToRight(&l_err_cnt_C,l_start_bit,l_length_buffer);if (rc_ecmd){ rc.setEcmdError(rc_ecmd); return rc;}
			    }
			}
			if(l_rd_cnt_A>l_rd_cnt_B)
			{
			    l_delta=l_rd_cnt_A-l_rd_cnt_B;
			}
			else
			{
			    l_delta=l_rd_cnt_B-l_rd_cnt_A;
			}
			if(l_delta>read_counter_threshold)
			{
			    l_err_prblty=l_err_cnt_C*read_counter_threshold;
			    l_err_prblty=l_err_prblty/l_delta;
			    if(l_err_prblty>error_threshold_count)
			    {
				pass=0;
			    }
			    else
			    {
				pass=1;
			    }
			}	
		    }while(l_delta<read_counter_threshold);
		    if(!pass)
		    {
			SHMOO[scenario].MBA.P[iv_port].S[rank].K.rb_regval[l_dq][l_rp]=l_current_val;
		    }
		    else
		    {
			SHMOO[scenario].MBA.P[iv_port].S[rank].K.rb_regval[l_dq][l_rp]=l_current_val-l_right_del;
		    }
		}
	    }
	    if(!pass)
	    {
		SHMOO[scenario].MBA.P[iv_port].S[rank].K.rb_regval[l_dq][l_rp]=l_current_val-l_right_del;
	    }
	    else
	    {
		SHMOO[scenario].MBA.P[iv_port].S[rank].K.rb_regval[l_dq][l_rp]=l_current_val-l_right_del;
	    }
	    FAPI_INF(" the right bound  for dq=%d is %d ",l_dq,SHMOO[scenario].MBA.P[iv_port].S[rank].K.rb_regval[l_dq][l_rp]);
	    l_current_val=SHMOO[scenario].MBA.P[iv_port].S[rank].K.nom_val[l_dq][l_rp];
		FAPI_INF("  the restoring nominal value for rank=%d dq=%d and rp=%d is %d",rank,l_dq,l_rp,l_current_val);
	    rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,rank,l_input_type_e,l_dq,0,l_current_val);if(rc) return rc;
	    
	}
    }
    return rc;	
}
/*------------------------------------------------------------------------------
 * Function: knob_update_dqs
 * Description  : This is a key function is used to find right and left bound using new algorithm -- there is an option u can chose not to use it by setting a flag
 *
 * Parameters: Target:MBA,bound:RIGHT/LEFT,scenario:type of schmoo,iv_port:0/1,rank:0-7,byte:0-7,nibble:0/1,bit:0-3,pass,
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode generic_shmoo::knob_update_dqs(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t rank,uint8_t byte,uint8_t nibble,uint8_t bit,uint8_t pass)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase data_buffer_64_1(64);
    data_buffer_64.flushTo0();
    data_buffer_64_1.flushTo0();
    uint32_t l_current_val=0;
    uint32_t l_max_value=0;
    uint32_t l_min_value=0;
    
    uint8_t  l_rp=0;
    input_type_t l_input_type_e = WR_DQS;
    uint8_t l_dq=0;
    access_type_t l_access_type_e = WRITE;
	
    if(scenario == 1) 
    {
	l_input_type_e = WR_DQS;
    }
    else if(scenario == 3) 
    {
	l_input_type_e = RD_DQS;
    }
	
    if(bound==LEFT)
    {
        
        if(algorithm==SEQ_LIN)
        {
	    l_min_value=SHMOO[scenario].static_knob.min_val;
	    FAPI_INF("  curr val in left above  = %d and pass=%d ",l_current_val,pass);
	    for(l_current_val=SHMOO[scenario].MBA.P[iv_port].S[rank].K.nom_val[l_dq][l_rp];((l_current_val >= 20)&&(pass==1));l_current_val-=20)
	    {
		    //use saurabh function for writing here 
		    FAPI_INF("  curr val in left = %d and pass=%d ",l_current_val,pass);
		    rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,0,l_input_type_e,l_dq,0,l_current_val);if(rc) return rc;
		    
		    rc=do_mcbist_test(i_target,rank,byte,nibble,pass);
		    if(rc)
		    {   
			FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
			return rc;
		    }
       	    }
	    if(!pass)
	    {
		SHMOO[scenario].MBA.P[iv_port].S[rank].K.lb_regval[l_dq][l_rp]=l_current_val;
	    }
	    FAPI_INF("  left  bound = %d  ",SHMOO[scenario].MBA.P[iv_port].S[rank].K.rb_regval[l_dq][l_rp]);
	    l_current_val=SHMOO[scenario].MBA.P[iv_port].S[rank].K.nom_val[l_dq][l_rp];
	    rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,0,l_input_type_e,l_dq,0,l_current_val);if(rc) return rc;
	    
	}
    }
	
    else if(bound==RIGHT)
    {
         
        if(algorithm==SEQ_LIN)
         {
	    l_max_value=SHMOO[scenario].static_knob.max_val;
	    for(l_current_val=SHMOO[scenario].MBA.P[iv_port].S[rank].K.nom_val[l_dq][l_rp];((l_current_val<l_max_value)&&(pass==1));l_current_val+=100)
	    {
		    //use saurabh function for writing here 
		    FAPI_INF("  curr val  = %d ",l_current_val);
		    rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,0,l_input_type_e,l_dq,0,l_current_val);if(rc) return rc;
		    
		    rc=do_mcbist_test(i_target,rank,byte,nibble,pass);
		    if(rc)
		    {   
			FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
		    return rc;
		    }
	    }
	    if(!pass)
	    {
		SHMOO[scenario].MBA.P[iv_port].S[rank].K.rb_regval[l_dq][l_rp]=l_current_val;
	    }
	    l_current_val=SHMOO[scenario].MBA.P[iv_port].S[rank].K.nom_val[l_dq][l_rp];
		
	    rc=mss_access_delay_reg(i_target,l_access_type_e,iv_port,0,l_input_type_e,l_dq,0,l_current_val);if(rc) return rc;
	    FAPI_INF("  right bound = %d  ",SHMOO[scenario].MBA.P[iv_port].S[rank].K.rb_regval[l_dq][l_rp]);
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
    uint8_t l_rnk,l_byte,l_nibble,l_bit;
    fapi::ReturnCode rc;
    
    uint8_t i_rank=0;
    bool flag=false;
    
    
    
    FAPI_INF("generic_shmoo::find_bound running find_bound function ");
    
        
        for (l_rnk=0;l_rnk<iv_MAX_RANKS;++l_rnk)
        {// Byte loop
			i_rank=valid_rank[l_rnk];
            for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
            {   //Nibble loop
		
                for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
                {
                    
		    //Bit loop
                    for(l_bit=0;l_bit< MAX_BITS;++l_bit)
                    {
			// preetham function here
			
			
			if(iv_DQS_ON==1)
			rc=knob_update_dqs(i_target,bound,iv_shmoo_type,i_rank,l_byte,l_nibble,l_bit,1);if(rc) return rc;
			else
			rc=knob_update(i_target,bound,iv_shmoo_type,i_rank,l_byte,l_nibble,l_bit,1,flag); if(rc) return rc;   
                    }
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
    FAPI_INF("num_drops_per_port = %d on %s.", l_attr_eff_num_drops_per_port_u8, i_target.toEcmdString());
    FAPI_INF("num_ranks  = %d on %s.", iv_MAX_RANKS,i_target.toEcmdString());
    FAPI_INF("dram_width = %d on %s. \n\n", l_attr_eff_dram_width_u8, i_target.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    FAPI_INF("Schmoo  POS\tPort\tRank\tByte\tnibble\tbit\tNominal\t\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate  ");
    
    
        
	    for (l_rnk=0;l_rnk<iv_MAX_RANKS;++l_rnk)
	    {// Byte loop
					    i_rank=valid_rank[l_rnk];
			    rc = mss_getrankpair(i_target,iv_port,i_rank,&l_rp,valid_rank);if(rc) return rc;
		for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
		{
		    
		    //Nibble loop
		    for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
		    {
			for(l_bit=0;l_bit< MAX_BITS;++l_bit)
			{	
			    l_dq=8*l_byte+4*l_nibble+l_bit;

			    if(iv_shmoo_type==0)
			    {
				FAPI_INF("WR_EYE %d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",iv_port,l_mbapos,i_rank,l_byte,l_nibble,l_bit,SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.nom_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.rb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.lb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.right_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.left_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.total_margin[l_dq][l_rp],l_attr_mss_freq_u32);
			    }
			    if(iv_shmoo_type==2)
			    {
				FAPI_INF("RD_EYE\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n ",iv_port,l_mbapos,i_rank,l_byte,l_nibble,l_bit,SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.nom_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.rb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.lb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.right_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.left_margin_val[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.total_margin[l_dq][l_rp],l_attr_mss_freq_u32);
			    }
			    
			}
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
    
    
        	
	    for (l_rnk=0;l_rnk<iv_MAX_RANKS;++l_rnk)
	    {// Byte loop
		i_rank=valid_rank[l_rnk];
		rc = mss_getrankpair(i_target,iv_port,i_rank,&l_rp,valid_rank);if(rc) return rc; 
		for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
		{
		    
		    //Nibble loop
		    for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
		    {
			for(l_bit=0;l_bit< MAX_BITS;++l_bit)
			{
			    l_dq=8*l_byte+4*l_nibble+l_bit;
			    //FAPI_INF("  the right bound = %d and nominal = %d",SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.rb_regval[l_dq][l_rp],SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.nom_val[l_dq][l_rp]);
			    SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.right_margin_val[l_dq][l_rp]=((SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.rb_regval[l_dq][l_rp]-SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.nom_val[l_dq][l_rp])*l_factor)/l_factor_ps;
                            SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.left_margin_val[l_dq][l_rp]= ((SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.nom_val[l_dq][l_rp]-SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.lb_regval[l_dq][l_rp])*l_factor)/l_factor_ps;//((1/uint32_t_freq*1000000)/128);
			    SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.total_margin[l_dq][l_rp]=SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.right_margin_val[l_dq][l_rp]+SHMOO[iv_shmoo_type].MBA.P[iv_port].S[i_rank].K.left_margin_val[l_dq][l_rp];
                        }
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
    uint8_t l_rnk,l_byte,l_nibble,l_bit;
    uint16_t l_temp_right=4800;
    uint16_t l_temp_left=4800;
    uint8_t l_dq=0;
    uint8_t l_rp=0;

    
    
        
	    for (l_rnk=0;l_rnk<iv_MAX_RANKS;++l_rnk)
	    {// Byte loop
		for(l_byte=0;l_byte<iv_MAX_BYTES;++l_byte)
		{
		    
		    //Nibble loop
		    for(l_nibble=0;l_nibble< MAX_NIBBLES;++l_nibble)
		    {
			for(l_bit=0;l_bit< MAX_BITS;++l_bit)
			{	
			    l_dq=8*l_byte+4*l_nibble+l_bit;
			    if(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[l_rnk].K.right_margin_val[l_dq][l_rp]<l_temp_right)
			    {
				l_temp_right=SHMOO[iv_shmoo_type].MBA.P[iv_port].S[l_rnk].K.right_margin_val[l_dq][l_rp];
			    }
			    if(SHMOO[iv_shmoo_type].MBA.P[iv_port].S[l_rnk].K.left_margin_val[l_dq][l_rp]<l_temp_left)
			    {
				l_temp_left=SHMOO[iv_shmoo_type].MBA.P[iv_port].S[l_rnk].K.left_margin_val[l_dq][l_rp];
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
 
}//Extern C
