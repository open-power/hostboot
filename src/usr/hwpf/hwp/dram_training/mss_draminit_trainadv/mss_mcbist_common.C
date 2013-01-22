/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_mcbist_common.C $ */
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
// $Id: mss_mcbist_common.C,v 1.17 2013/01/16 15:16:15 sasethur Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : mss_mcbist_common.C
// *! TITLE                : 
// *! DESCRIPTION          : MCBIST Procedures
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Devashikamani, Aditya         Email: adityamd@in.ibm.com
// *! BACKUP               : Sethuraman, Saravanan         Email: saravanans@in.ibm.com
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.17  |aditya  |01/11/16|Updated setup_mcbist function 
//   1.16  |aditya  |01/11/13|Updated function headers 
//   1.15  |aditya  |01/11/13|added  parameters to setup_mcbist function
//   1.14  |aditya  |01/07/13|Updated Review Comments  
//   1.13  |aditya  |01/03/13| Updated FW Comments 
//   1.10  |sasethur|12/14/12| Updated for warnings
//   1.9   |aditya  |12/14/12| Updated FW review comments   
//   1.8   |aditya  |12/6/12 | Updated Review Comments
//   1.7   |aditya  |11/15/12| Updated for FW REVIEW COMMENTS
//   1.6   |aditya  |10/31/12| Fixed issue in mcb_error_map function   
//   1.5   |abhijit |10/29/12| fixed issue in byte mask function   
//   1.4   |aditya  |10/29/12| Updated from ReturnCode to fapi::ReturnCode and Target to const fapi::Target &   
//   1.3   |aditya  |10/18/12| Replaced insertFromBin by InsertFromRight 
//   1.2   |aditya  |10/17/12| updated code to be compatible with ecmd 13 release
//   1.1   |aditya  |10/01/12| updated fw review comments, datapattern, testtype, addressing	
//
//
//This File mss_mcbist_common.C contains the definition of common procedures for the files mss_mcbist.C and mss_mcbist_lab.C
//------------------------------------------------------------------------------
#include "mss_mcbist.H"
#include <mss_access_delay_reg.H>
#include <fapiTestHwpDq.H>
#include <dimmBadDqBitmapFuncs.H>

extern "C"
{
using namespace fapi;

#define MCB_DEBUG
#define MCB_DEBUG1
#define MCB_DEBUG2


//const uint8_t MAX_PORT = 2;
const uint8_t MAX_DRAM = 20;

//const uint8_t MAX_BYTE = 10;
//const uint8_t MAX_RANK = 8;
//const uint8_t MAX_NIBBLE = 1;
const uint8_t MCB_TEST_NUM = 16;
const uint64_t MCB_MAX_TIMEOUT = 3000000000000000ull;
const uint64_t  DELAY_100US = 100000;   // general purpose 100 usec delay for HW mode (2000000 sim cycles if simclk = 20ghz)
const uint64_t  DELAY_2000SIMCYCLES     = 2000;     // general purpose 2000 sim cycle delay for sim mode     (100 ns if simclk = 20Ghz)
//const uint64_t END_ADDRESS = 0x0000000004;  //Will be fixed later, once the address generation function is ready
// const uint64_t START_ADDRESS = 0x0000000001;
//const uint64_t FEW_INTERVAL = 0x0000000003;

const uint64_t END_ADDRESS = 0x0000000010000000ull;  //Will be fixed later, once the address generation function is ready
 const uint64_t START_ADDRESS = 0x0000000004000000ull;
const uint64_t FEW_INTERVAL = 0x000000000C000000ull;
const uint64_t FOUR = 0x0000000000000004ull;


//*****************************************************************/
// Funtion name : setup_mcbist
// Description  : Will setup the required MCBIST configuration register
// Input Parameters :
//     const fapi::Target &            Centaur.mba
//     uint8_t i_port                   Port on which we are operating.

//     mcbist_data_gen i_mcbpatt        Data pattern 
//     mcbist_test_mem i_mcbtest        subtest Type
//     mcbist_byte_mask i_mcbbytemask   It is used to mask bad bits read from SPD 
//     uint8_t i_mcbrotate              Provides the number of bit to shift per burst

//     uint8_t i_pattern                Data Pattern
//     uint8_t i_test_type              Subtest Type
//     uint8_t i_rank                   Current Rank   
//     ,uint8_t i_bit32                 Flag to set bit 32 of register 02011674   
//uint64_t i_start                      Flag to set start address
// uint64_t i_end                       Flag to set End address  
//****************************************************************/


fapi::ReturnCode  setup_mcbist(const fapi::Target & i_target_mba, uint8_t i_port,mcbist_data_gen i_mcbpatt,mcbist_test_mem i_mcbtest,mcbist_byte_mask i_mcbbytemask,uint8_t i_mcbrotate,uint8_t i_pattern,uint8_t i_test_type,uint8_t i_rank,uint8_t i_bit32,uint64_t i_start,uint64_t i_end)
{
    
    fapi::ReturnCode  rc;
    uint32_t rc_num = 0;
    FAPI_INF("Function Setup_MCBIST");
    ecmdDataBufferBase l_data_buffer_64(64);
    ecmdDataBufferBase l_data_bufferx1_64(64); 
    ecmdDataBufferBase l_data_bufferx2_64(64);
    ecmdDataBufferBase l_data_bufferx3_64(64); 
    ecmdDataBufferBase l_data_bufferx4_64(64);
    //ecmdDataBufferBase l_data_buffer_64_1(64);
   // FAPI_INF("Value  of Start is %016llX and end %016llX ",i_start,i_end);
	
    rc = mcb_reset_trap(i_target_mba); 
    if(rc) return rc;

	if(i_bit32 == 1)
	{
	
	rc = fapiGetScom(i_target_mba,0x02011674,l_data_buffer_64);if(rc) return rc;
    rc_num =  l_data_buffer_64.setBit(32);if (rc_num){FAPI_ERR( "Error in function  setup_mcbist:");rc.setEcmdError(rc_num);return rc;}
    
    rc = fapiPutScom(i_target_mba,0x02011674,l_data_buffer_64);if(rc) return rc;
    
    rc = fapiGetScom(i_target_mba,0x02011774,l_data_buffer_64);if(rc) return rc;
    rc_num =  l_data_buffer_64.setBit(32);if (rc_num){FAPI_ERR( "Error in function  setup_mcbist:");rc.setEcmdError(rc_num);return rc;}
    
    rc = fapiPutScom(i_target_mba,0x02011774,l_data_buffer_64);if(rc) return rc;
	
	}
	
	
	
   /* rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,l_data_buffer_64); if(rc) return rc; 
    rc_num = rc_num | l_data_buffer_64.flushTo0();
    rc_num = rc_num | l_data_buffer_64.setBit(18); 
    rc_num = rc_num | l_data_buffer_64.setBit(27); 
    rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8, l_data_buffer_64); if(rc) return rc; 
   
    rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_buffer_64);if(rc) return rc; 
    rc_num = rc_num | l_data_buffer_64.setBit(36); 
    rc_num = rc_num | l_data_buffer_64.setBit(37); 
    rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_buffer_64); if(rc) return rc; 
    
    rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCBSSARA0Q_0x030106d0,l_data_buffer_64); if(rc) return rc; 
    rc_num = rc_num | l_data_buffer_64.flushTo0();
    rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBSSARA0Q_0x030106d0,l_data_buffer_64); if(rc) return rc; 
    
    rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCBAGRAQ_0x030106d6,l_data_buffer_64); if(rc) return rc; 
    rc_num = rc_num | l_data_buffer_64.setBit(24); 
    rc_num = rc_num | l_data_buffer_64.clearBit(25); 
    rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBAGRAQ_0x030106d6, l_data_buffer_64); if(rc) return rc; 
  */ 
    rc = fapiGetScom(i_target_mba,MBA01_CCS_MODEQ_0x030106a7, l_data_buffer_64);  if(rc) return rc;   
    rc_num =  l_data_buffer_64.clearBit(29); if (rc_num){FAPI_ERR( "Error in function setup_mcb:");rc.setEcmdError(rc_num);return rc;}
  
 
    rc = fapiPutScom(i_target_mba,MBA01_CCS_MODEQ_0x030106a7, l_data_buffer_64);  if(rc) return rc;   
   //Hard coded to single address - Saravanan for debug 
   /* rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_buffer_64);if(rc) return rc; 
    rc_num = rc_num | l_data_buffer_64.flushTo0(); 
    rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_buffer_64); if(rc) return rc; 
    */
    //rc = print_pattern(i_target_mba);if(rc)return rc;
    if((i_test_type == 1) && (i_pattern == 1))
    {
	FAPI_INF("User pattern and User test_type modes enabled");
	rc = cfg_mcb_dgen(i_target_mba,USR_MODE,i_mcbrotate); if(rc) return rc;
	FAPI_INF("Inside setup mcbist Entering cfg_mcb_addr");
        rc = cfg_mcb_addr(i_target_mba,i_rank,i_port,i_start,i_end);if(rc) return rc;
        rc = cfg_mcb_test_mem(i_target_mba,USER_MODE); if(rc) return rc; 
    }
    else if(i_pattern == 1) 
    {
        FAPI_INF("User pattern  mode enabled");
        rc = cfg_mcb_dgen(i_target_mba,USR_MODE,i_mcbrotate); if(rc) return rc;
        FAPI_INF("Inside setup mcbist Entering cfg_mcb_addr");
        rc = cfg_mcb_addr(i_target_mba,i_rank,i_port,i_start,i_end);if(rc) return rc;
        rc = cfg_mcb_test_mem(i_target_mba,i_mcbtest); if(rc) return rc;
    }
    else if(i_test_type == 1)
    {
	FAPI_INF(" User test_type mode enabled");
	rc = cfg_mcb_dgen(i_target_mba,i_mcbpatt,i_mcbrotate); if(rc) return rc;
        FAPI_INF("Inside setup mcbist Entering cfg_mcb_addr");
        rc = cfg_mcb_addr(i_target_mba,i_rank,i_port,i_start,i_end);if(rc) return rc;
        rc = cfg_mcb_test_mem(i_target_mba,USER_MODE); if(rc) return rc;
    }
    else
    {
	rc = cfg_mcb_dgen(i_target_mba,i_mcbpatt,i_mcbrotate); if(rc) return rc;
	FAPI_INF("Inside setup mcbist Entering cfg_mcb_addr");
        rc = cfg_mcb_addr(i_target_mba,i_rank,i_port,i_start,i_end);if(rc) return rc;
        rc = cfg_mcb_test_mem(i_target_mba,i_mcbtest); if(rc) return rc;
    }
	
    if(i_mcbbytemask != NONE)
    {
        rc = cfg_byte_mask(i_target_mba,i_rank,i_port);  if(rc) return rc;
	   
    }
   

    return rc;
}

//*****************************************************************/
// Funtion name : mcb_reset_trap
// Description: Clears all the trap registers in MCBIST engine
//Input Parameters :
//     const fapi::Target &            centaur.mba 
//*****************************************************************/

fapi::ReturnCode  mcb_reset_trap(const fapi::Target & i_target_mba)
{
    ecmdDataBufferBase l_data_buffer_64(64);
    fapi::ReturnCode  rc;
    uint32_t rc_num = 0;
	
    
    FAPI_INF("Function - mcb_reset_trap");
    FAPI_INF("Using MCB Reset Trap Function -- This automatically resets error log RA, error counters, Status Reg and error map");
    
    rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCBCFGQ_0x030106e0,l_data_buffer_64);if(rc) return rc;
    rc_num =  l_data_buffer_64.setBit(60);if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}
    //rc = fapiDelay(DELAY_100US, DELAY_2000SIMCYCLES);if(rc) return rc; // wait 2000 simcycles (in sim mode) OR 100 uS (in hw mode)
    rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBCFGQ_0x030106e0,l_data_buffer_64);if(rc) return rc;
    rc_num =  l_data_buffer_64.clearBit(60);if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBCFGQ_0x030106e0,l_data_buffer_64);if(rc) return rc;
    //rc = fapiDelay(DELAY_100US, DELAY_2000SIMCYCLES);if(rc) return rc; // wait 2000 simcycles (in sim mode) OR 100 uS (in hw mode)
    rc_num =  l_data_buffer_64.setBit(60);if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBCFGQ_0x030106e0,l_data_buffer_64);if(rc) return rc;
    //Reset MCB Maintanence register
    FAPI_INF("Clearing the MCBIST Maintenance ");
    rc_num =  l_data_buffer_64.flushTo0();if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCB_CNTLSTATQ_0x030106dc,l_data_buffer_64);if(rc) return rc;
    rc_num =  l_data_buffer_64.clearBit(0,3);if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCB_CNTLSTATQ_0x030106dc,l_data_buffer_64);if(rc) return rc;
 
     //Reset the MCBIST runtime counter
    FAPI_INF("Clearing the MCBIST Runtime Counter ");     
    rc_num =  l_data_buffer_64.flushTo0();if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiGetScom(i_target_mba,MBA01_MCBIST_RUNTIMECTRQ_0x030106b0,l_data_buffer_64);if(rc) return rc;
    rc_num =  l_data_buffer_64.clearBit(0,37);if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiPutScom(i_target_mba,MBA01_MCBIST_RUNTIMECTRQ_0x030106b0,l_data_buffer_64);if(rc) return rc;

    FAPI_INF("To clear Port error map registers of both port A and B");
    rc_num =  l_data_buffer_64.flushTo0();if (rc_num){FAPI_ERR( "Error in function  mcb_reset_trap:");rc.setEcmdError(rc_num);return rc;}
    //PORT - A
    rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBEMA1Q_0x0201166a,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBEMA2Q_0x0201166b,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBEMA3Q_0x0201166c,l_data_buffer_64); if(rc) return(rc);

    //PORT - B
    rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBEMB1Q_0x0201166d,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBEMB2Q_0x0201166e,l_data_buffer_64); if(rc) return(rc);
    rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBEMB3Q_0x0201166f,l_data_buffer_64); if(rc) return(rc);

    
 
    return rc;
}


//*****************************************************************/
// Funtion name : start_mcb
// Description: Checks for dimms drop in the particular port & starts MCBIST
//Input Parameters :
//     const fapi::Target &            Centaur.mba
//*****************************************************************/

fapi::ReturnCode  start_mcb(const fapi::Target & i_target_mba)
{
    ecmdDataBufferBase l_data_buffer_64(64);
    uint8_t l_num_ranks_per_dimm[2][2];
    fapi::ReturnCode  rc;
    uint32_t rc_num = 0;
    FAPI_INF("Function - start_mcb");
    
	
    rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCBAGRAQ_0x030106d6,l_data_buffer_64); if(rc) return rc; 
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm); if(rc) return rc;
    
     
    if(l_num_ranks_per_dimm[0][0] > 0)
    {
        FAPI_INF("Port AB configured, Socket 0 Configured");
        rc_num =  l_data_buffer_64.setBit(24);if (rc_num){FAPI_ERR( "Error in function  start_mcb:");rc.setEcmdError(rc_num);return rc;}
        rc_num =  l_data_buffer_64.clearBit(25);if (rc_num){FAPI_ERR( "Error in function  start_mcb:");rc.setEcmdError(rc_num);return rc;}
    }
    else if(l_num_ranks_per_dimm[0][1] > 0)
    {
        FAPI_INF("Port AB configured, Socket 1 Configured");
        rc_num =  l_data_buffer_64.clearBit(24);if (rc_num){FAPI_ERR( "Error in function  start_mcb:");rc.setEcmdError(rc_num);return rc;}
        rc_num =  l_data_buffer_64.setBit(25);if (rc_num){FAPI_ERR( "Error in function  start_mcb:");rc.setEcmdError(rc_num);return rc;}
    }
    else if((l_num_ranks_per_dimm[0][0] > 0) && (l_num_ranks_per_dimm[0][1] > 0))
    {
        FAPI_INF("Port AB configured, Socket 0, 1 Configured");
        rc_num =  l_data_buffer_64.setBit(24);if (rc_num){FAPI_ERR( "Error in function  start_mcb:");rc.setEcmdError(rc_num);return rc;}
        rc_num =  l_data_buffer_64.setBit(25);if (rc_num){FAPI_ERR( "Error in function  start_mcb:");rc.setEcmdError(rc_num);return rc;}
    }
    else
    {
	    FAPI_INF("No Socket found");
		
    }
    
    
    //rc = fapiDelay(DELAY_100US, DELAY_2000SIMCYCLES);if(rc) return rc; // wait 2000 simcycles (in sim mode) OR 100 uS (in hw mode)
    
    rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBAGRAQ_0x030106d6,l_data_buffer_64); if(rc) return rc; 
    FAPI_INF("STARTING MCBIST for Centaur Target");
    rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCB_CNTLSTATQ_0x030106dc,l_data_buffer_64); if(rc) return rc;
    
    if(l_data_buffer_64.isBitSet(0))
    {
        FAPI_INF("MCBIST already in progess, wait till MCBIST completes");
       
	   return rc;
	   
    }
    rc_num =  l_data_buffer_64.flushTo0();if (rc_num){FAPI_ERR( "Error in function  start_mcb:");rc.setEcmdError(rc_num);return rc;}
    rc_num =  l_data_buffer_64.setBit(0);if (rc_num){FAPI_ERR( "Error in function  start_mcb:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCB_CNTLQ_0x030106db,l_data_buffer_64); if(rc) return rc;
   
    //rc = fapiDelay(DELAY_100US, DELAY_2000SIMCYCLES);if(rc) return rc; // wait 2000 simcycles (in sim mode) OR 100 uS (in hw mode)
    

       
    return rc;
}



//*****************************************************************/
// Funtion name : poll_mcb
// Description  : Will check the MCBIST Configuration Register for mcb fail, in progress
//                fail. It will print the corresponding  centaur on which MCBIST has
//                been completed, in progress or failed.
// Input Parameters :
//    const fapi::Target &             Centaur.mba
//    bool           i_mcb_stop_on_fail       Whether MCBIST should stop on fail or not
//    uint64_t i_time                          Sets the max Time out value  
// Output Parameter :
//    uint32    status  = 1                 MCBIST done with fail or MCBIST not complete (default value)
//                      = 0                 MCBIST Done without fail
//****************************************************************/
fapi::ReturnCode  poll_mcb(const fapi::Target & i_target_mba,bool i_mcb_stop_on_fail,uint8_t *o_mcb_status,uint64_t i_time)
{
    fapi::ReturnCode  rc;             // return value after each SCOM access/buffer modification
    uint32_t rc_num = 0;
    ecmdDataBufferBase l_data_buffer_64(64);
	ecmdDataBufferBase l_data_buffer1_64(64);
    ecmdDataBufferBase l_stop_on_fail_buffer_64(64);
    //Current status of the MCB (done, fail, in progress)
    uint8_t l_mcb_done = 0;
    uint8_t l_mcb_fail = 0;
    uint8_t l_mcb_ip = 0;
    //Time out variables
    uint64_t l_mcb_timeout = 0;
    uint32_t l_count = 0;
    // Clear to register to zero;
    
	/*uint8_t  l_out_4(8);
    uint32_t  l_out_20(20); 
	uint64_t  l_out_40(40);*/
    
	
    FAPI_INF("Function Poll_MCBIST");
    
    if(i_time <= 0x0000000000000000)
    {

	i_time = MCB_MAX_TIMEOUT;
	
    }    
	//FAPI_INF("Value  of max time %016llX",i_time);
	
    while ((l_mcb_done == 0) && (l_mcb_timeout <= i_time))
    {
        rc = fapiDelay(DELAY_100US, DELAY_2000SIMCYCLES);if(rc) return rc; // wait 2000 simcycles (in sim mode) OR 100 uS (in hw mode)
        rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCB_CNTLSTATQ_0x030106dc,l_data_buffer_64);  if(rc) return rc;
        if(l_data_buffer_64.isBitSet(0))          
        {
            //FAPI_INF("MCBIST is in progress_inside poll_mcb");
            l_mcb_ip = 1;
        }
        if(l_data_buffer_64.isBitSet(1))         
        {
            FAPI_INF("MCBIST is done");
            l_mcb_ip = 0;
            l_mcb_done = 1;
        }
        if(l_data_buffer_64.isBitSet(2))        
        {
            l_mcb_fail = 1;
            if(i_mcb_stop_on_fail == true)          //if stop on error is 1, break after the current subtest completes 
            {
                rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCBCFGQ_0x030106e0,l_stop_on_fail_buffer_64);  if(rc) return rc;
                rc_num =  l_stop_on_fail_buffer_64.setBit(62);if (rc_num){FAPI_ERR( "Error in function  poll_mcb:");rc.setEcmdError(rc_num);return rc;}                              // Set bit 61 to break after current subtest
                rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBCFGQ_0x030106e0,l_stop_on_fail_buffer_64);  if(rc) return rc;
                FAPI_INF("MCBIST will break after Current Subtest");
                
                while(l_mcb_done == 0)                                            // Poll till MCBIST is done 
                {
                    rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCB_CNTLSTATQ_0x030106dc,l_data_buffer_64);  if(rc) return rc;
                    if(l_data_buffer_64.isBitSet(1))
                    {
                        l_mcb_ip = 0;
                        l_mcb_done = 1;
                        FAPI_INF("MCBIST Done");
                        rc_num =  l_stop_on_fail_buffer_64.clearBit(62);if (rc_num){FAPI_ERR( "Error in function  poll_mcb:");rc.setEcmdError(rc_num);return rc;}         // Clearing bit 61 to avoid breaking after current subtest
                        rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBCFGQ_0x030106e0,l_stop_on_fail_buffer_64);  if(rc) return rc;
                    }
                }
            }
        }
        l_mcb_timeout++;
        if (l_mcb_timeout >= i_time)
        {
            FAPI_ERR( "poll_mcb:Maximun time out");  	
            FAPI_SET_HWP_ERROR(rc,RC_MSS_MCBIST_TIMEOUT_ERROR);		
            return rc;
        }
		
#ifdef MCB_DEBUG_1        
        if(l_count%100 == 0)//Can be changed later
        {
            FAPI_INF("MCB done bit : l_mcb_done");
            FAPI_INF("MCB fail bit : l_mcb_fail");
            FAPI_INF("MCB IP   bit : l_mcb_ip");
        }
#endif
    l_count++;
    }
    
    if((l_mcb_done == 1) && (l_mcb_fail == 1) && (i_mcb_stop_on_fail == true))
    {
        *o_mcb_status = 1;      /// MCB fail
        #ifdef MCB_DEBUG_2
        FAPI_INF("*************************************************");
        FAPI_INF("MCB done bit : %d",l_mcb_done);
        FAPI_INF("MCB fail bit : %d",l_mcb_fail);
        FAPI_INF("MCB IP   bit : %d",l_mcb_ip);
        FAPI_INF("*************************************************");
        #endif
    }
    else if((l_mcb_done == 1) && (l_mcb_fail == 0))
    {
        *o_mcb_status = 0;//pass;        
        #ifdef MCB_DEBUG2
        FAPI_INF("*************************************************");
        FAPI_INF("MCB done bit : %d",l_mcb_done);
        FAPI_INF("MCB fail bit : %d",l_mcb_fail);
        FAPI_INF("MCB IP   bit : %d",l_mcb_ip);
        FAPI_INF("*************************************************");
        #endif
    }
    else if((l_mcb_done == 0) && (l_mcb_ip == 1) && (l_mcb_timeout == i_time))
    {
        *o_mcb_status = 1;//fail;                
        #ifdef MCB_DEBUG2
        FAPI_INF("****************************************");
        FAPI_INF("MCB done bit : %d",l_mcb_done);
        FAPI_INF("MCB fail bit : %d",l_mcb_fail);
        FAPI_INF("MCB IP   bit : %d",l_mcb_ip);
        FAPI_INF("****************************************");
       
        #endif
    }
	
    
	if (*o_mcb_status == 1)
    {
        FAPI_ERR( "poll_mcb:MCBIST failed");  	
		//rc = fapiGetScom(i_target_mba,0x03010665,l_data_buffer1_64);  if(rc) return rc;
	/*l_sbit = 0;
	l_len = 4;
	rc_num= rc_num | l_data_buffer1_64.extractToRight(&l_out_4,l_sbit,l_len);
	l_sbit = 5;
	l_len = 19;
	rc_num= rc_num | l_data_buffer1_64.extractToRight(&l_out_20,l_sbit,l_len);
	
	
	l_sbit = 25;
	l_len = 39;
	rc_num= rc_num | l_data_buffer1_64.extractToRight(&l_out_40,l_sbit,l_len);
	
	FAPI_ERR(" FAILURE DETAILS ");
	
	FAPI_ERR(" subtest_num(0:4) :%X",l_out_4 );
	FAPI_ERR(" cmd number  :%05lX",l_out_20 );
	FAPI_ERR(" trap addr(0:38)  :%08llX",l_out_40 );*/
        FAPI_SET_HWP_ERROR(rc,RC_MSS_MCBIST_ERROR);		
        return rc;
    }
	
   

    return rc;    
}



/****************************************************************/
// Funtion name :  mcb_error_map_print
// Description  : Prints the error Map of a Rank   
// Input Parameters :
//    const fapi::Target &                  Centaur.mba
//    uint8_t i_port                        Port in use
//    uint8_t i_rank                        Rank in use
//    ecmdDataBufferBase & l_mcb_fail_320   Ecmd Buffer 
// Output Parameter :
//    uint8_t o_error_map[][8][10][2]   Contains the error map      
//****************************************************************/

fapi::ReturnCode  mcb_error_map_print(const fapi::Target & i_target_mba,uint8_t i_port,uint8_t i_rank,ecmdDataBufferBase & l_mcb_fail_320)
{	
	ReturnCode rc;
	uint8_t l_num_ranks_per_dimm[MAX_PORT][MAX_PORT];
	uint8_t l_rankpair_table[MAX_RANK] = {0};
	uint8_t l_cur_rank =0;
    uint8_t l_cur_dram =0;
	uint8_t l_max_rank = 0;
	uint8_t l_rank_pair = 0;
	char l_str1[200] = "";
	uint8_t l_index = 0;
	uint8_t l_mbaPosition = 0;
	rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbaPosition);
	//uint8_t l_dimmtype = 0;
	//rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target_mba, l_dimmtype); if(rc) return rc;
	// if(l_dimmtype==1)
	// {
	
	// return rc;
	
	// }
	if(i_port == 0)
	{
	if(l_mbaPosition ==0)
	{
	FAPI_INF("################# PortA Error MAP #################\n");
	FAPI_INF("################# MBA01 ###########################\n");
	}
	else
	{
	FAPI_INF("################# PortA Error MAP #################\n");
	FAPI_INF("################# MBA023 ###########################\n");
	}
	
	}
	if(i_port == 1)
	{
	
	if(l_mbaPosition ==0)
	{
	FAPI_INF("################# PortB Error MAP #################\n");
	FAPI_INF("################# MBA01 ###########################\n");
	}
	else
	{
	FAPI_INF("################# PortB Error MAP #################\n");
	FAPI_INF("################# MBA023 ###########################\n");
	}
    
	
	}
	
    FAPI_INF("Byte      00112233445566778899");
    FAPI_INF("          --------------------");
    FAPI_INF("Nibble    00000000001111111111");
    FAPI_INF("Nibble    01234567890123456789");
      
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm); if(rc) return rc;   
    l_max_rank=l_num_ranks_per_dimm[i_port][0]+l_num_ranks_per_dimm[i_port][1];	
	rc = mss_getrankpair(i_target_mba,i_port,0,&l_rank_pair,l_rankpair_table);  if(rc) return rc;	
	
	if(l_max_rank > MAX_RANK)
	{
	 FAPI_ERR(" Maximum ranks available exceeded 8");
	 FAPI_SET_HWP_ERROR(rc, RC_MSS_INPUT_ERROR);
	 
	 return rc;
	}
    for(l_cur_rank = 0;l_cur_rank < l_max_rank;l_cur_rank++)
    {
	    if(i_rank == l_rankpair_table[l_cur_rank])
		{
        sprintf(l_str1,"%-4s%d%5s","RANK",l_rankpair_table[l_cur_rank],"");
        for(l_cur_dram = 0; l_cur_dram < MAX_DRAM; l_cur_dram++)
        {
            
			if(i_port == 1)
	        {
	        l_index = (l_rankpair_table[l_cur_rank])*(MAX_DRAM) + l_cur_dram + 160;
            }
			
			if(i_port == 0)
	        {
	        l_index = (l_rankpair_table[l_cur_rank])*(MAX_DRAM) + l_cur_dram ;
            }
			
			
			
			
            if(l_mcb_fail_320.isBitSet(l_index))
            {
                
				strcat(l_str1,"X");
            }
            else
            {
                
				strcat(l_str1,".");
            }
        }
	
	        
                FAPI_INF("%s",l_str1);
				break;
	    }	
    }
return rc;
}	







/*****************************************************************/
// Funtion name : mcb_error_map
// Description  : Reads the nibblewise Error map registers into o_error_map   
// Input Parameters :
//    const fapi::Target &             Centaur.mba
//    uint8_t i_port                   Current port
//    uint8_t i_rank                   Current Rank 
// Output Parameter :
//    uint8_t o_error_map[][8][10][2]   Contains the error map      
//****************************************************************/
fapi::ReturnCode  mcb_error_map(const fapi::Target & i_target_mba, uint8_t  o_error_map[][8][10][2],uint8_t i_port,uint8_t i_rank)
{
    ecmdDataBufferBase l_mcbem1ab(64);
    ecmdDataBufferBase l_mcbem2ab(64);
    ecmdDataBufferBase l_mcbem3ab(64);
	ecmdDataBufferBase l_data_buffer_64(64);
	ecmdDataBufferBase l_data_buffer1_64(64);
    ecmdDataBufferBase l_mcb_fail_320(320);
   
    
	

    //####################
    fapi::Target i_target_centaur ;
    //####################
    fapi::ReturnCode  rc;
    uint32_t rc_num = 0;
    //uint8_t l_cur_rank =0;
    //uint8_t l_cur_dram =0;
    uint8_t l_index0 = 0;
    uint8_t l_index1 = 0; 
    uint8_t l_port = 0;
    uint8_t l_rank = 0;
    uint8_t l_byte = 0;
    uint8_t l_nibble = 0;
    uint8_t l_num_ranks_per_dimm[MAX_PORT][MAX_PORT];
   // uint8_t l_max_rank = 0;
   // uint8_t l_rankpair_table[MAX_RANK] = {0};
    //uint8_t l_rank_pair = 0;
    uint8_t l_mbaPosition = 0;
    FAPI_INF("Function MCB_ERROR_MAP");
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbaPosition);
    if(rc)
    {
       	FAPI_ERR("Error getting MBA position"); return rc;
    }
   
  
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm); if(rc) return rc;        
    rc = fapiGetParentChip(i_target_mba, i_target_centaur); 
    if (rc)
    {
        FAPI_ERR("Error in getting Parent Chiplet");
		return rc;
    }
     
    
    rc = fapiGetScom(i_target_centaur,MBS_MCBIST01_MCBEMA1Q_0x0201166a,l_mcbem1ab); if(rc) return rc;
    rc_num =  l_mcb_fail_320.insert(l_mcbem1ab,0,60,0);if (rc_num){FAPI_ERR( "Error in function  mcb_error_map:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiGetScom(i_target_centaur,MBS_MCBIST01_MCBEMA2Q_0x0201166b,l_mcbem2ab); if(rc) return rc;
    rc_num =  l_mcb_fail_320.insert(l_mcbem2ab,60,60,0);if (rc_num){FAPI_ERR( "Error in function  mcb_error_map:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiGetScom(i_target_centaur,MBS_MCBIST01_MCBEMA3Q_0x0201166c,l_mcbem3ab); if(rc) return rc;
    rc_num =  l_mcb_fail_320.insert(l_mcbem3ab,120,40,0);if (rc_num){FAPI_ERR( "Error in function  mcb_error_map:");rc.setEcmdError(rc_num);return rc;}
     

    //rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm); if(rc) return rc; 
    //l_max_rank=l_num_ranks_per_dimm[0][0]+l_num_ranks_per_dimm[0][1];	
   // rc = mss_getrankpair(i_target_mba,i_port,0,&l_rank_pair,l_rankpair_table);  if(rc) return rc;	
	
	/*if(l_max_rank > MAX_RANK)
	{
	 FAPI_ERR(" Maximum ranks available exceeded 8");
	 FAPI_SET_HWP_ERROR(rc, RC_MSS_INPUT_ERROR);
	 return rc;
	}*/
    if(i_port == 0)
    {     
    
     mcb_error_map_print( i_target_mba ,i_port, i_rank, l_mcb_fail_320);    
   	
    }
    rc = fapiGetScom(i_target_centaur,MBS_MCBIST01_MCBEMB1Q_0x0201166d,l_mcbem1ab); if(rc) return rc;
    rc_num =  l_mcb_fail_320.insert(l_mcbem1ab,160,60,0);if (rc_num){FAPI_ERR( "Error in function  mcb_error_map:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiGetScom(i_target_centaur,MBS_MCBIST01_MCBEMB2Q_0x0201166e,l_mcbem2ab); if(rc) return rc;
    rc_num =  l_mcb_fail_320.insert(l_mcbem2ab,220,60,0);if (rc_num){FAPI_ERR( "Error in function  mcb_error_map:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiGetScom(i_target_centaur,MBS_MCBIST01_MCBEMB3Q_0x0201166f,l_mcbem3ab); if(rc) return rc;
    rc_num =  l_mcb_fail_320.insert(l_mcbem3ab,280,40,0);if (rc_num){FAPI_ERR( "Error in function  mcb_error_map:");rc.setEcmdError(rc_num);return rc;}
    //Restore values    
    
    if(i_port == 1)
    {   	    
       mcb_error_map_print(i_target_mba, i_port, i_rank, l_mcb_fail_320);    
    }
	
    //Need to check the DIMM plugged in and decide the rank? - Implement that.
    
    for (l_port = 0; l_port < MAX_PORT ; l_port++)
    {
        for(l_rank = 0; l_rank < MAX_RANK; l_rank++)
        {
            for(l_byte = 0; l_byte < MAX_BYTE; l_byte++)
            {
                for(l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                {
	            l_index0 = (l_rank*20) + (l_byte*2) + l_nibble;
                    l_index1 = l_index0 + 160*(l_port);
					if((l_mcb_fail_320.isBitSet(l_index1)))
					{
					 o_error_map[l_port][l_rank][l_byte][l_nibble] = 1;
					}
					else
					{
					 o_error_map[l_port][l_rank][l_byte][l_nibble] = 0;
					}
                    
                }
            }
        }
    }
	
   
    /* rc = fapiGetScom(i_target_mba,0x03010665,l_data_buffer1_64);  if(rc) return rc;
	 rc = fapiGetScom(i_target_mba,0x03010666,l_data_buffer1_64);  if(rc) return rc;
	 rc = fapiGetScom(i_target_mba,0x03010667,l_data_buffer1_64);  if(rc) return rc;
	 rc = fapiGetScom(i_target_mba,0x03010668,l_data_buffer1_64);  if(rc) return rc;
	 rc = fapiGetScom(i_target_mba,0x03010669,l_data_buffer1_64);  if(rc) return rc;
	 rc = fapiGetScom(i_target_mba,0x0301066a,l_data_buffer1_64);  if(rc) return rc;
	 rc = fapiGetScom(i_target_mba,0x0301066b,l_data_buffer1_64);  if(rc) return rc;
	 rc = fapiGetScom(i_target_mba,0x0301066c,l_data_buffer1_64);  if(rc) return rc;*/
	 
    return rc;
}
/*****************************************************************/
// Funtion name : mcb_write_test_mem
// Description  :   : Based on parameters passed we write data into Register being passed  
// Input Parameters :
//    const fapi::Target &                     Centaur.mba
//    const uint64_t i_reg_addr                 Register address 
//    mcbist_oper_type i_operation_type         Operation Type
//    mcbist_addr_mode i_addr_mode              Sequential or Random address modes
//    mcbist_data_mode i_data_mode              Data Mode
//    uint8_t i_done                               Done Bit  
//   mcbist_data_select_mode i_data_select_mode Different BURST modes or DEFAULT 
//    mcbist_add_select_mode i_addr_select_mode Address Select mode
//    uint8_t i_testnumber                      Subtest number 
//    uint8_t i_cfg_test_123_cmd                Integer value

//****************************************************************/
fapi::ReturnCode  mcb_write_test_mem(const fapi::Target & i_target_mba,const uint64_t i_reg_addr,mcbist_oper_type i_operation_type,uint8_t i_cfg_test_123_cmd,mcbist_addr_mode i_addr_mode,mcbist_data_mode i_data_mode,uint8_t i_done,mcbist_data_select_mode i_data_select_mode, mcbist_add_select_mode i_addr_select_mode,uint8_t i_testnumber)
{
    fapi::ReturnCode  rc;
    uint32_t rc_num = 0;
    uint8_t l_index = 0;
    uint8_t l_operation_type = i_operation_type;
    uint8_t l_cfg_test_123_cmd = i_cfg_test_123_cmd;
    uint8_t l_addr_mode = i_addr_mode;
    uint8_t l_data_mode = i_data_mode;
    uint8_t l_data_select_mode = i_data_select_mode;
    uint8_t l_addr_select_mode = i_addr_select_mode;
	
    ecmdDataBufferBase l_data_buffer_64(64);
   
    
    FAPI_INF("Function mcb_write_test_mem");
    rc = fapiGetScom(i_target_mba,i_reg_addr,l_data_buffer_64);if(rc) return rc;
    l_index = i_testnumber * (MCB_TEST_NUM) ; 
    
    // Operation type
    
	
    rc_num = rc_num| l_data_buffer_64.insertFromRight(l_operation_type,l_index ,3);
   	 
    
    rc_num = rc_num| l_data_buffer_64.insertFromRight(l_cfg_test_123_cmd,l_index + 3,3);

    // ADDR MODE
    
    rc_num = rc_num| l_data_buffer_64.insertFromRight(l_addr_mode,l_index + 6,2);
    // DATA MODE 
    
   rc_num = rc_num| l_data_buffer_64.insertFromRight(l_data_mode,l_index + 8,3);
    // Done bit
    
    rc_num = rc_num| l_data_buffer_64.insertFromRight(i_done,l_index + 11,1);
    // Data Select Mode
 
    rc_num = rc_num| l_data_buffer_64.insertFromRight(l_data_select_mode,l_index + 12,2);
    
    // Address Select mode
    
    rc_num = rc_num| l_data_buffer_64.insertFromRight(l_addr_select_mode,l_index + 14,2);
	
	
	if (rc_num){FAPI_ERR( "Error in function  mcb_write_test_mem:");rc.setEcmdError(rc_num);return rc;}
    
    rc = fapiPutScom(i_target_mba,i_reg_addr,l_data_buffer_64); if(rc) return rc;
    rc = fapiGetScom(i_target_mba,i_reg_addr,l_data_buffer_64); if(rc) return rc;
    
       
    return rc;
}
/*****************************************************************/
// Funtion name : cfg_byte_mask
// Description  :     
// Input Parameters :  It is used to mask bad bits read from SPD 
//    const fapi::Target &                     Centaur.mba
//    uint8_t i_rank                            Current Rank
//    uint8_t i_port                            Current Port  
//****************************************************************/
fapi::ReturnCode  cfg_byte_mask(const fapi::Target & i_target_mba,uint8_t i_rank,uint8_t i_port)
{

    uint8_t l_dimm=0;
    ecmdDataBufferBase l_data_buffer1_64(64);
    ecmdDataBufferBase l_data_buffer2_64(64);
    ecmdDataBufferBase l_data_buffer3_64(64);
   

    fapi::ReturnCode  rc;
    uint32_t rc_num = 0;
     
    rc_num =  l_data_buffer3_64.flushTo1();if (rc_num){FAPI_ERR( "Error in function  cfg_byte_mask:");rc.setEcmdError(rc_num);return rc;}
    

    uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE];
    uint8_t l_dq[8]={0};
    uint8_t l_sp[2]={0};
    uint8_t l_index0=0;
    uint8_t l_index_sp=0;
    uint16_t l_sp_mask=0xffff;

    FAPI_INF("Function cfg_byte_mask");
    if(i_rank>3)
    {
	l_dimm=1;
	i_rank=4-i_rank;
    }
    else
    {
	l_dimm=0;
    }
    rc = dimmGetBadDqBitmap(i_target_mba, i_port, l_dimm, i_rank,l_dqBitmap);if(rc) return rc;
	
    for ( l_index0 = 0; l_index0 < DIMM_DQ_RANK_BITMAP_SIZE; l_index0++)
    {
		if(l_index0<8)
		{
			l_dq[l_index0]=l_dqBitmap[l_index0];
			FAPI_INF("\n the bad dq=%x ",l_dqBitmap[l_index0]);

		}
		else
		{
			l_sp[l_index_sp]=l_dqBitmap[l_index0];
			l_index_sp++;
		}
	}


    rc_num =  l_data_buffer1_64.insertFromRight(l_dq,0,64);if (rc_num){FAPI_ERR( "Error in function  cfg_byte_mask:");rc.setEcmdError(rc_num);return rc;}
  //  rc_num =  l_data_buffer2_64.insertFromRight(l_sp,0,16);if (rc_num){FAPI_ERR( "Error in function  cfg_byte_mask:");rc.setEcmdError(rc_num);return rc;}
	
    if(i_port == 0)
    {
	rc_num =  l_data_buffer2_64.insertFromRight(l_sp,0,16);if (rc_num){FAPI_ERR( "Error in function  cfg_byte_mask:");rc.setEcmdError(rc_num);return rc;}
	rc_num =  l_data_buffer2_64.insertFromRight(l_sp_mask,16,16);if (rc_num){FAPI_ERR( "Error in function  cfg_byte_mask:");rc.setEcmdError(rc_num);return rc;}
	rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBCMA1Q_0x02011672,l_data_buffer1_64); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBCMABQ_0x02011674,l_data_buffer2_64); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBCMB1Q_0x02011673,l_data_buffer3_64); if(rc) return rc;
    }
    else 
    {
	rc_num =  l_data_buffer2_64.insertFromRight(l_sp,16,16);if (rc_num){FAPI_ERR( "Error in function  cfg_byte_mask:");rc.setEcmdError(rc_num);return rc;}
	rc_num =  l_data_buffer2_64.insertFromRight(l_sp_mask,0,16);if (rc_num){FAPI_ERR( "Error in function  cfg_byte_mask:");rc.setEcmdError(rc_num);return rc;}
	rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBCMB1Q_0x02011673,l_data_buffer1_64); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBCMABQ_0x02011674,l_data_buffer2_64); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MCBCMA1Q_0x02011672,l_data_buffer3_64); if(rc) return rc;
    }
    
    
    return rc;
}
/*****************************************************************/
// Funtion name : addr_gen_func
// Description  : Based on the Schmoo Address Mode this function decides the address range on which MCBIST must operate    
// Input Parameters :
//    const fapi::Target &                     Centaur.mba
//    mcbist_addr_mode i_addr_mode              MCBIST address mode
//    uint8_t i_attr_eff_schmoo_addr_mode       Schmoo address mode
// Output Parameters : 
//    uint64_t &io_end_address                   End address of MCBIST   
//    uint64_t &io_start_address                 Start address of MCBIST
//    uint8_t i_rank                            Current Rank
//    uint8_t i_port                            Current Port
//****************************************************************/

fapi::ReturnCode  addr_gen_func(const fapi::Target & i_target_mba, mcbist_addr_mode i_addr_mode, uint8_t i_attr_eff_schmoo_addr_mode ,uint64_t &io_end_address,uint64_t &io_start_address,uint8_t i_rank,uint8_t i_port)
{
    fapi::ReturnCode  rc;  
    //uint8_t l_rank = 0;	
   // uint8_t l_cur_rank = 0;
    uint8_t l_rankpair_table[8];
    FAPI_INF("Function mss_address_gen");
    uint64_t l_end_address = io_end_address;
    uint64_t l_start_address = io_start_address;
    uint64_t l_diff_address = 0;
	uint64_t l_diff_address1 = 0;
	uint64_t l_addr1 = 0;
	uint64_t l_addr2 = 0;
    uint8_t l_num_ranks_per_dimm[MAX_PORT][MAX_PORT];
    uint8_t l_max_rank = 0;
    //uint8_t i_port = 0;
    uint8_t l_rank_pair = 0;
    //uint8_t i = 0;
    uint8_t l_compare = 0; 
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm); if(rc) return rc; 
    l_max_rank=l_num_ranks_per_dimm[i_port][0]+l_num_ranks_per_dimm[i_port][1];	
    rc = mss_getrankpair(i_target_mba,i_port,0,&l_rank_pair,l_rankpair_table);  if(rc) return rc;
	
	//FAPI_INF("FLAG 111  value of start and end addr is %016llX and %016llX",io_start_address,io_end_address);
	
	if(l_max_rank > MAX_RANK)
	{
	 FAPI_ERR(" Maximum ranks available exceeded 8");
	 FAPI_SET_HWP_ERROR(rc, RC_MSS_INPUT_ERROR);
	 return rc;
	}
	
	
   /* for(l_cur_rank = 0;l_cur_rank < l_max_rank;l_cur_rank++)
	{
	    if(i_rank == l_rankpair_table[l_cur_rank])
		{
		l_rank = l_cur_rank;
		break;
		} 
	} */
	FAPI_INF("Shmoo Addressing mode is %d ",i_attr_eff_schmoo_addr_mode);
	//l_cur_rank = 0;
	
	if(i_addr_mode == SF)
	{
	l_addr1 = l_start_address;
	l_addr2 = l_end_address;
	}
	else if(i_addr_mode == SR)
	{
	l_addr1 = l_end_address;
	l_addr2 = l_start_address;
	}
	else
	{
	 FAPI_INF("Wrong Shmoo address mode");
	 FAPI_SET_HWP_ERROR(rc, RC_MSS_INPUT_ERROR);
	 return rc;
	} 
		
		if(i_attr_eff_schmoo_addr_mode == FEW_ADDR)
		{
		// FAPI_INF("Value 0 of Start is %016llX and Diff %016llX",l_addr1,l_addr2);
		
		l_diff_address = l_addr2 - l_addr1;
		
		/*for(i=0;i<l_rank;i++)
		{
			l_addr1 = l_addr1 + START_ADDRESS + l_diff_address;
		}*/
		
		//FAPI_INF("Value 1 of Start is %016llX and Diff %016llX",l_addr1,l_addr2);
		
		//l_addr1 += (END_ADDRESS * l_rank);
		//l_addr1 += ((START_ADDRESS + l_diff_address) * l_rank);
		l_addr1 += ((START_ADDRESS + l_diff_address) * i_rank);
		l_addr2 = l_addr1 + FEW_INTERVAL;
        //FAPI_INF("Value 2 of Start is %016llX and Diff %016llX",l_addr1,l_addr2);
		

		}

		else if(i_attr_eff_schmoo_addr_mode == QUARTER_ADDR)
		{

			

			l_diff_address = l_addr2 - l_addr1;

			if (l_diff_address >= (FOUR))
			{
				l_diff_address1 = l_diff_address>>2;

				

				/*for(i=0;i<l_rank;i++)
				{
					l_addr1 = l_addr1 + START_ADDRESS + l_diff_address;
				}*/
				//FAPI_INF("Value 3 of Start is %016llX and Diff %016llX",l_addr1,l_addr2);
				
				//l_addr1 += ((START_ADDRESS+l_diff_address) * l_rank);
				//l_addr1 += ((START_ADDRESS + l_diff_address) * l_rank);
				l_addr1 += ((START_ADDRESS + l_diff_address) * i_rank);
				l_addr2 = l_addr1 + l_diff_address1;
				
				
				//FAPI_INF("Value 4 of Start is %016llX and Diff %016llX",l_addr1,l_addr2);
			}

			
		}
		else if(i_attr_eff_schmoo_addr_mode == HALF_ADDR)
		{

			

			l_diff_address = l_addr2 - l_addr1;
			l_compare = (FOUR)>>1;
			
			if (l_diff_address >= l_compare)
			{
				l_diff_address1 = l_diff_address>>1;

				//FAPI_INF("Value 5.1 of diff is %016llX and FOUR %016llX",l_diff_address,l_compare);

				/*for(i=0;i<l_rank;i++)
				{
					l_addr1 = l_addr1 + l_diff_address + START_ADDRESS;
				} */
				//FAPI_INF("Value 5 of Start is %016llX and Diff %016llX",l_addr1,l_addr2);
				//l_addr1 += ((START_ADDRESS+l_diff_address) * l_rank);
				//l_addr1 += ((START_ADDRESS + l_diff_address) * l_rank);
				l_addr1 += ((START_ADDRESS + l_diff_address) * i_rank);
				l_addr2 = l_addr1 + l_diff_address1;
				//FAPI_INF("Value 6 of Start is %016llX and Diff %016llX",l_addr1,l_addr2);
			}
		}

		else if(i_attr_eff_schmoo_addr_mode == FULL_ADDR)
		{
			
			l_diff_address = l_addr2 - l_addr1;
			
			/*for(i=0;i<l_rank;i++)
			{
				l_addr1 = l_addr1 + l_diff_address + START_ADDRESS;
				
			}*/
			
		   // l_addr1 += ((START_ADDRESS+l_diff_address) * l_rank);
		   // l_addr1 += ((START_ADDRESS + l_diff_address) * l_rank);
		   l_addr1 += ((START_ADDRESS + l_diff_address) * i_rank);
			l_addr2 = l_addr1 + l_diff_address;
			
		}
	
	if(i_addr_mode == SF)
	{
	l_start_address = l_addr1 ;
	l_end_address = l_addr2 ;
	}
	else if(i_addr_mode == SR)
	{
	l_end_address = l_addr1;
	l_start_address = l_addr2;
	}
	
	
	
    io_start_address = l_start_address;
    io_end_address = l_end_address;
    //FAPI_INF("Value of end_address is %016llX and start address %016llX",io_end_address,io_start_address);
    return rc;
}


//************************************************************************/
// Funtion name : cfg_mcb_addr
// Description  : Configures the address range of MCBIST
// Input Parameters :
//    const fapi::Target &                     Centaur.mba
//    uint8_t i_rank                            Current Rank Being Passed
//    uint8_t i_port                             Current port
//    uint64_t i_start                          Flag to set start address
//    uint64_t i_end                            Flag to set end address 
//************************************************************************/
fapi::ReturnCode  cfg_mcb_addr(const fapi::Target & i_target_mba,uint8_t rank,uint8_t i_port,uint64_t i_start,uint64_t i_end)
{
    fapi::ReturnCode  rc;             // return value after each SCOM access/buffer modification
    uint32_t rc_num = 0; 
    
    ecmdDataBufferBase l_data_buffer_64(64); 
    ecmdDataBufferBase l_data_buffer2_64(64);
    
	uint32_t io_value_u32 = 0x00000000; 
	uint32_t l_sbit = 38;   
	uint32_t l_len = 26;
	uint32_t l_start = 0;
    uint8_t l_attr_eff_schmoo_addr_mode = 0;
    uint8_t l_num_ranks_per_dimm[MAX_PORT][MAX_PORT];
    uint64_t start_address = 0;
    uint64_t end_address = 0;
	
    
	
	
	
	
    rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_ADDR_MODE, &i_target_mba, l_attr_eff_schmoo_addr_mode); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm); if(rc) return rc;
    FAPI_INF("Function cfg_mcb_addr");
   
    
    FAPI_INF("Num ranks per dimm :%d ", l_num_ranks_per_dimm[0][0]);
    FAPI_INF("Num ranks per dimm :%d ", l_num_ranks_per_dimm[0][1]);
    FAPI_INF("Num ranks per dimm :%d ", l_num_ranks_per_dimm[1][0]);
    FAPI_INF("Num ranks per dimm :%d ", l_num_ranks_per_dimm[1][1]);    

	//FAPI_INF("FLAG 111  value of start and end addr is %016llX and %016llX",i_start,i_end);
    

    if( ( l_attr_eff_schmoo_addr_mode == FEW_ADDR) || ( l_attr_eff_schmoo_addr_mode == QUARTER_ADDR) ||( l_attr_eff_schmoo_addr_mode == HALF_ADDR) ||( l_attr_eff_schmoo_addr_mode == FULL_ADDR))
    {
        
		
	
	if(((l_num_ranks_per_dimm[0][0] != 0) || (l_num_ranks_per_dimm[1][0] != 0)) && (rank <=3))
	{
            FAPI_INF("Slot 0 is configured\n");
            
            rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCBSSARA0Q_0x030106d0,l_data_buffer_64); if(rc) return rc;
	    rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_buffer2_64); if(rc) return rc;
            start_address = l_data_buffer_64.getDoubleWord (0);
            end_address = l_data_buffer2_64.getDoubleWord (0);
			if((i_start >= 0x0000000000000000) && (i_end > 0x0000000000000000) )
	        {      	  
        	   //FAPI_INF("FLAG 111  value of start and end addr is %016llX and %016llX",i_start,i_end);
			   rc=addr_gen_func(i_target_mba,SF, l_attr_eff_schmoo_addr_mode,i_end,i_start,rank,i_port);if(rc)return rc;  
				start_address = i_start;
			    end_address = i_end;
				FAPI_INF(" value of start and end addr is %016llX and %016llX",start_address,end_address);
            }
		     else
			 {
			  FAPI_INF(" value of start and end addr is %016llX and %016llX",start_address,end_address);
			  rc=addr_gen_func(i_target_mba,SF, l_attr_eff_schmoo_addr_mode,end_address,start_address,rank,i_port);if(rc)return rc;
			 } 
	    
             


        //rc_num=rc_num|l_data_buffer_64.insert(io_value_u32,l_sbit,l_len,l_start);
		//rc_num=rc_num|l_data_buffer2_64.insert(io_value_u32,l_sbit,l_len,l_start);			
	    rc_num  =  rc_num|l_data_buffer_64.setDoubleWord(0,start_address);
	    rc_num  = rc_num| l_data_buffer2_64.setDoubleWord(0,end_address);
		if (rc_num){FAPI_ERR( "Error in function  cfg_mcb_addr:");rc.setEcmdError(rc_num);return rc;}
         
		 
		rc_num=l_data_buffer_64.insert(io_value_u32,l_sbit,l_len,l_start);if (rc_num){FAPI_ERR( "Error in function  cfg_mcb_addr:");rc.setEcmdError(rc_num);return rc;}
		rc_num=l_data_buffer2_64.insert(io_value_u32,l_sbit,l_len,l_start);	if (rc_num){FAPI_ERR( "Error in function  cfg_mcb_addr:");rc.setEcmdError(rc_num);return rc;} 
		 
		 
		 FAPI_INF(" value of start and end addr is %016llX and %016llX",start_address,end_address);
            rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBSSARA0Q_0x030106d0,l_data_buffer_64);  if(rc) return rc;
            rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_buffer2_64);  if(rc) return rc;
    	}
       
	   if(((l_num_ranks_per_dimm[0][1] != 0) ||  (l_num_ranks_per_dimm[1][1] != 0)) && (rank >=4))
	{
            FAPI_INF("Slot 1 is configured\n");
            
	    rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCBSSARA0Q_0x030106d0,l_data_buffer_64); if(rc) return rc;
	    rc = fapiGetScom(i_target_mba,MBA01_MCBIST_MCBSEARA0Q_0x030106d2,l_data_buffer2_64); if(rc) return rc;
            start_address = l_data_buffer_64.getDoubleWord (0);
            end_address = l_data_buffer2_64.getDoubleWord (0);
	    FAPI_INF(" value of start and end addr is %016llX and %016llX",start_address,end_address);
            
			
			if((i_start >= 0x0000000000000000) && (i_end > 0x0000000000000000) )
	        {      	  
              // FAPI_INF("FLAG 111  value of start and end addr is %016llX and %016llX",i_start,i_end);         	   
			   rc=addr_gen_func(i_target_mba,SF, l_attr_eff_schmoo_addr_mode,i_end,i_start,rank,i_port); if(rc)return rc;  
            start_address = i_start;
			end_address = i_end;
			FAPI_INF(" value of start and end addr is %016llX and %016llX",start_address,end_address);
			}
			else
			{
			rc=addr_gen_func(i_target_mba,SF, l_attr_eff_schmoo_addr_mode,end_address,start_address,rank,i_port); if(rc)return rc;  
            }	    
		rc_num  = rc_num| l_data_buffer_64.setDoubleWord(0,start_address);
	    rc_num  =  rc_num|l_data_buffer2_64.setDoubleWord(0,end_address);
		if (rc_num){FAPI_ERR( "Error in function  cfg_mcb_addr:");rc.setEcmdError(rc_num);return rc;}
	        
		rc_num=rc_num|l_data_buffer_64.insert(io_value_u32,l_sbit,l_len,l_start);
		rc_num=rc_num|l_data_buffer2_64.insert(io_value_u32,l_sbit,l_len,l_start);	
		if (rc_num){FAPI_ERR( "Error in function  cfg_mcb_addr:");rc.setEcmdError(rc_num);return rc;}
		FAPI_INF(" value of start and end addr is %016llX and %016llX",start_address,end_address);	
            rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBSSARA1Q_0x030106d1,l_data_buffer_64);  if(rc) return rc;
            rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBSEARA1Q_0x030106d3,l_data_buffer2_64);  if(rc) return rc;
        }

    }
  
     
    return rc;   
    
}


   
}

