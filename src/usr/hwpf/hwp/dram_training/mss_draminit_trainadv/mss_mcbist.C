/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_mcbist.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: mss_mcbist.C,v 1.23 2012/12/14 06:30:44 sasethur Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : mss_mcbist.C
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
//   1.22  |aditya  |12/14/12|Updated FW review comments   
//   1.22  |aditya  |12/6/12 | Updated Review Comments
//   1.21  |aditya  |11/15/12| Updated for FIRMWARE REVIEW COMMENTS
//   1.20  |aditya  |10/29/12| updated fw review comments 
//   1.18  |aditya  |10/29/12| Updated from ReturnCode to fapi::ReturnCode and Target to const fapi::Target &  
//   1.17  |aditya  |10/18/12| Replaced insertFromHexRight by SetDoubleWord   
//   1.16  |aditya  |10/17/12| updated code to be compatible with ecmd 13 release
//   1.15  |aditya  |10/01/12| updated fw review comments, datapattern, testtype, addressing	
//   1.14  |mwuu    |07/17/12| updated dram_width tests to new definition
//   1.13  |bellows |07/16/12| added in Id tag
//   1.10  |gaushard|04/26/12| Added ONE_SHMOO parameter
//   1.9   |gaushard|03/26/12| Updated start_mcbist 
//   1.8   |gaushard|03/26/12| Removed Extra Comments/Codes
//   1.7   |gaushard|03/26/12| Added new shmoo modes
//   1.6   |sasethur|03/23/12| Corrected Warning Messages 
//   1.5   |sasethur|03/23/12| Corrected Warning messages
//   1.4   |gaushard|03/22/12| Added Address generation
//   1.3   |gaushard|02/29/12| Added rc_num for Buffer operation
//   1.2   |gaushard|02/14/12| Added rc_buff for buffer access
//   1.1   |gaushard|02/13/12| Updated scom addresses
//   1.0   |gaushard|01/19/12| Initial Version
//------------------------------------------------------------------------------

//#include "mss_mcbist_common.C"
#include "mss_mcbist.H"
extern "C"
{
using namespace fapi;


//*****************************************************************/
// Funtion name : cfg_mcb_test_mem
// Description  : This function executes different MCBIST subtests
// Input Parameters :
//     const fapi::Target & i_target_mba      Centaur.mba
//     mcbist_test_mem i_test_type      Subtest Type
//****************************************************************/

fapi::ReturnCode  cfg_mcb_test_mem(const fapi::Target & i_target_mba,mcbist_test_mem i_test_type)
{
    fapi::ReturnCode  rc;
    FAPI_INF("Function - cfg_mcb_test_mem");
   


    if(i_test_type == CENSHMOO)
    {                                                 
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,W,0,SF,FIX,0,DEFAULT,PORTA0_SEQ,0);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,R,0,SF,FIX,1,DEFAULT,PORTA0_SEQ,1);  if(rc) return rc;
    }
    
    else if(i_test_type == MEMWRITE)
    {
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,W,0,SF,FIX,1,DEFAULT,FIX_ADDR,0);   if(rc) return rc;      
    }
    else if(i_test_type == MEMREAD)
    {
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,R,0,SF,FIX,1,DEFAULT,FIX_ADDR,0);    if(rc) return rc;     
    }
    
   else if (i_test_type == SIMPLE_FIX)
    {
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,W,   0,SF,FIX, 0,DEFAULT,FIX_ADDR,0);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,R,   0,SF,FIX, 1,DEFAULT,FIX_ADDR,1);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,R,   0,SF,FIX, 1,DEFAULT,FIX_ADDR,2);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,OPER_RAND,0,RF,FIX, 1,DEFAULT,FIX_ADDR,3);  if(rc) return rc;
        
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR1Q_0x030106a9,RW,  0,RF,RAND,0,DEFAULT,FIX_ADDR,0);   if(rc) return rc;
    }
    else if (i_test_type == SIMPLE_RAND)
    {
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,W,   0,SF,RAND,0,DEFAULT,FIX_ADDR,0);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,R,   0,SF,RAND,1,DEFAULT,FIX_ADDR,1);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,W,   0,RF,RAND,1,DEFAULT,FIX_ADDR,2);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,R,   0,RF,RAND,1,DEFAULT,FIX_ADDR,3);  if(rc) return rc;
        
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR1Q_0x030106a9,RW,  4,RF,RAND,0,DEFAULT,FIX_ADDR,0);   if(rc) return rc;      
    }
    
    else if (i_test_type == WR_ONLY)
    {
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,W,   0,SF,RAND,0,DEFAULT,FIX_ADDR,0);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,R,   0,SF,RAND,1,DEFAULT,FIX_ADDR,1);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,W,   0,RF,FIX,0,DEFAULT,FIX_ADDR,2);  if(rc) return rc; 
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,OPER_RAND,0,RF,FIX,1,DEFAULT,FIX_ADDR,3);  if(rc) return rc;
        
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR1Q_0x030106a9,RW,  4,RF,RAND,0,DEFAULT,FIX_ADDR,0);   if(rc) return rc;       
    } 
    else if (i_test_type == W_ONLY)
    {
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,W,   0,SF,RAND,1,DEFAULT,FIX_ADDR,0);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,R,   0,SF,FIX, 1,DEFAULT,FIX_ADDR,1);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,W,   0,RF,FIX, 0,DEFAULT,FIX_ADDR,2);  if(rc) return rc; 
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,OPER_RAND,0,RF,FIX, 1,DEFAULT,FIX_ADDR,3);  if(rc) return rc;
        
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR1Q_0x030106a9,RW,  4,RF,RAND,0,DEFAULT,FIX_ADDR,0);   if(rc) return rc;    
    }
    else if (i_test_type == R_ONLY)
    {
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,R,   0,SF,RAND,1,DEFAULT,FIX_ADDR,0);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,W,   0,RF,FIX, 0,DEFAULT,FIX_ADDR,2);  if(rc) return rc;
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR0Q_0x030106a8,OPER_RAND,0,RF,FIX, 1,DEFAULT,FIX_ADDR,3);  if(rc) return rc;
        
        rc = mcb_write_test_mem(i_target_mba,MBA01_MCBIST_MCBMR1Q_0x030106a9,RW,  4,RF,RAND,0,DEFAULT,FIX_ADDR,0);  if(rc) return rc;  
    }
    
    else
    {
	    
		FAPI_SET_HWP_ERROR(rc, RC_MSS_INPUT_ERROR);
		FAPI_ERR("Invalid MCBIST test type! cfg_mcb_test_mem Function  ");
		return rc;
    }
    
    return rc;
}





//*****************************************************************/
// Funtion name : cfg_mcb_dgen
// Description  : This function writes data patterns based on i_datamode passed
// Input Parameters :
//     const fapi::Target & i_target_mba      Centaur.mba
//     mcbist_data_gen i_datamode       MCBIST Data mode 
//     uint8_t i_mcbrotate              Provides the number of bit to shift per burst
//****************************************************************/
fapi::ReturnCode  cfg_mcb_dgen(const fapi::Target & i_target_mba,mcbist_data_gen i_datamode,uint8_t i_mcbrotate)
{
    ecmdDataBufferBase l_data_buffer_64(64);
	ecmdDataBufferBase l_var_data_buffer_64(64);
	ecmdDataBufferBase l_var1_data_buffer_64(64);
	ecmdDataBufferBase l_spare_data_buffer_64(64);
    ecmdDataBufferBase l_data_buffer_32(32);
    ecmdDataBufferBase l_data_buffer_16(16);
    ecmdDataBufferBase l_data_buffer_4(4);
	ecmdDataBufferBase l_data_buffer1_4(4);
    uint64_t l_var = 0x0000000000000000ull;
    uint64_t l_var1 = 0x0000000000000000ull;
    uint64_t l_spare = 0x0000000000000000ull;
	//uint64_t l_data = 0x0000000000000000ull;
    uint8_t l_rotnum = 0;
    uint32_t l_mba01_mcb_pseudo_random[NINE] = { MBA01_MCBIST_MCBFD0Q_0x030106be,MBA01_MCBIST_MCBFD1Q_0x030106bf,MBA01_MCBIST_MCBFD2Q_0x030106c0,MBA01_MCBIST_MCBFD3Q_0x030106c1,MBA01_MCBIST_MCBFD4Q_0x030106c2, MBA01_MCBIST_MCBFD5Q_0x030106c3,MBA01_MCBIST_MCBFD6Q_0x030106c4,MBA01_MCBIST_MCBFD7Q_0x030106c5,MBA01_MCBIST_MCBFDQ_0x030106c6};
    uint32_t l_mba01_mcb_random[MAX_BYTE] = {MBA01_MCBIST_MCBRDS0Q_0x030106b2,MBA01_MCBIST_MCBRDS1Q_0x030106b3,MBA01_MCBIST_MCBRDS2Q_0x030106b4,MBA01_MCBIST_MCBRDS3Q_0x030106b5,MBA01_MCBIST_MCBRDS4Q_0x030106b6,MBA01_MCBIST_MCBRDS5Q_0x030106b7,MBA01_MCBIST_MCBRDS6Q_0x030106b8,MBA01_MCBIST_MCBRDS7Q_0x030106b9,MBA01_MCBIST_MCBRDS8Q_0x030106ba,MBA01_MCBIST_MCBDRSRQ_0x030106bc};
    uint8_t l_index,l_index1 = 0;
    uint32_t l_rand_32 = 0;
	
    uint32_t l_rand_8 = 0;
    
    fapi::ReturnCode  rc;
    uint32_t rc_num = 0;
    FAPI_INF(" Data mode is %d ",i_datamode);
    uint8_t l_mbaPosition =0;   
    
    FAPI_INF("Function cfg_mcb_dgen");
    //Read MBA position attribute 0 - MBA01 1 - MBA23
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbaPosition);
    if(rc)
    {
       	FAPI_ERR("Error getting MBA position"); return rc;
    }
	
	
	/*if ((l_mbaPosition != 0)||(l_mbaPosition != 1))
	{
	    return rc;
	} */
	
	
	
    if(i_datamode == MCBIST_2D_CUP_PAT5)
    {   
	    l_var = 0xFFFF0000FFFF0000ull;
        l_var1 =0x0000FFFF0000FFFFull; 
        l_spare = 0xFF00FF00FF00FF00ull;
		
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}  rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD0Q_0x030106be, l_data_buffer_64); if(rc) return rc;
        rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD1Q_0x030106bf, l_data_buffer_64); if(rc) return rc;
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD2Q_0x030106c0, l_data_buffer_64); if(rc) return rc;
	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD3Q_0x030106c1, l_data_buffer_64); if(rc) return rc;
	rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD4Q_0x030106c2, l_data_buffer_64); if(rc) return rc;
	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD5Q_0x030106c3, l_data_buffer_64); if(rc) return rc;
	rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD6Q_0x030106c4, l_data_buffer_64); if(rc) return rc;	
	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD7Q_0x030106c5, l_data_buffer_64); if(rc) return rc;
	rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDQ_0x030106c6 , l_data_buffer_64); if(rc) return rc;
	rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDSPQ_0x030106c7 , l_data_buffer_64); if(rc) return rc;
	
	

	
	
	
	
	
	}
	
	
	
    else if(i_datamode == MCBIST_2D_CUP_PAT8)
    {
        l_var = 0xFFFFFFFFFFFFFFFFull;                                                                                                                                         
        l_var1 =0x0000000000000000ull;                                                                                                                                                                                                                                            
        l_spare = 0xFFFF0000FFFF0000ull;                                                                                                                                
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD0Q_0x030106be, l_data_buffer_64); if(rc) return rc; 
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD1Q_0x030106bf, l_data_buffer_64); if(rc) return rc;  
        rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD2Q_0x030106c0, l_data_buffer_64); if(rc) return rc;   
 	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD3Q_0x030106c1, l_data_buffer_64); if(rc) return rc;        
 	rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD4Q_0x030106c2, l_data_buffer_64); if(rc) return rc;         
 	rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD5Q_0x030106c3, l_data_buffer_64); if(rc) return rc;        
 	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD6Q_0x030106c4, l_data_buffer_64); if(rc) return rc;	    
 	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD7Q_0x030106c5, l_data_buffer_64); if(rc) return rc;      
 	rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDQ_0x030106c6 , l_data_buffer_64); if(rc) return rc;     
 	rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDSPQ_0x030106c7 , l_data_buffer_64); if(rc) return rc;    
 
 
    }
    else if(i_datamode == ABLE_FIVE)
    {
         
        l_var = 0xA5A5A5A5A5A5A5A5ull;                                                                                                                                      
        l_var1 =0x5A5A5A5A5A5A5A5Aull;                                                                                                                                  
        l_spare = 0xA55AA55AA55AA55Aull;                                                                                                                                
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD0Q_0x030106be, l_data_buffer_64); if(rc) return rc; 
        rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD1Q_0x030106bf, l_data_buffer_64); if(rc) return rc;
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD2Q_0x030106c0, l_data_buffer_64); if(rc) return rc; 
  	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD3Q_0x030106c1, l_data_buffer_64); if(rc) return rc;    
  	rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD4Q_0x030106c2, l_data_buffer_64); if(rc) return rc;     
  	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD5Q_0x030106c3, l_data_buffer_64); if(rc) return rc;    
  	rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD6Q_0x030106c4, l_data_buffer_64); if(rc) return rc;	    
  	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD7Q_0x030106c5, l_data_buffer_64); if(rc) return rc;    
  	rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDQ_0x030106c6 , l_data_buffer_64); if(rc) return rc;   
  	rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDSPQ_0x030106c7 , l_data_buffer_64); if(rc) return rc;    
  
    }
	else if((i_datamode == DATA_GEN_DELTA_I) || (i_datamode == MCBIST_2D_CUP_PAT0))
    {
       
                                                                                                                                                                        
        l_var = 0xFFFFFFFFFFFFFFFFull;                                                                                                                                    
        l_var1 =0x0000000000000000ull;                                                                                                                                    
        l_spare = 0xFF00FF00FF00FF00ull;                                                                                                                                  
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD0Q_0x030106be, l_data_buffer_64); if(rc) return rc;   
        rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD1Q_0x030106bf, l_data_buffer_64); if(rc) return rc;  
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD2Q_0x030106c0, l_data_buffer_64); if(rc) return rc;   
	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD3Q_0x030106c1, l_data_buffer_64); if(rc) return rc;       
	rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD4Q_0x030106c2, l_data_buffer_64); if(rc) return rc;        
	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD5Q_0x030106c3, l_data_buffer_64); if(rc) return rc;       
	rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD6Q_0x030106c4, l_data_buffer_64); if(rc) return rc;	       
	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD7Q_0x030106c5, l_data_buffer_64); if(rc) return rc;       
	rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDQ_0x030106c6 , l_data_buffer_64); if(rc) return rc;      
	rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDSPQ_0x030106c7 , l_data_buffer_64); if(rc) return rc;     
                                                                                                                                                                        
    }
	
    else if(i_datamode == PSEUDORANDOM)
    {
       // srand(2);
        FAPI_INF("Need to check the value of RAND_MAX for this compiler -- assuming 32bit of data is returned");
        for (l_index = 0; l_index< (MAX_BYTE-1) ; l_index++)
        {
            //l_rand_32 = rand();
			l_rand_32 = 0xFFFFFFFF;//Hard Coded Temporary Fix till random function is fixed
            rc_num =  l_data_buffer_32.insertFromRight(l_rand_32,0,32); 	 	
            rc_num =  l_data_buffer_64.insert(l_data_buffer_32,0,32,0);
            //l_rand_32 = rand();
			l_rand_32 = 0xFFFFFFFF;
            rc_num =  l_data_buffer_32.insertFromRight(l_rand_32,0,32);             
            rc_num =  l_data_buffer_64.insert(l_data_buffer_32,32,32,0);
	    if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, l_mba01_mcb_pseudo_random[l_index] , l_data_buffer_64); if(rc) return rc;
        }
    }
    else
    {
        FAPI_ERR("Data generation configuration mcbist_data_gen enum : %d does not exist for centaur printPosData(i_target_mba)",(int)i_datamode);
       
		FAPI_SET_HWP_ERROR(rc, RC_MSS_INPUT_ERROR);
		return rc;
    }
    
    fapi::Target i_target_centaur ;
    rc = fapiGetParentChip(i_target_mba, i_target_centaur); 
    if (rc)
    {
	FAPI_INF("Error in getting parent chip!"); return rc;
    }
	
    if(i_datamode == MCBIST_2D_CUP_PAT5)
    {
	  l_var = 0xFFFF0000FFFF0000ull;                                                                                                                                      
      l_var1 =0x0000FFFF0000FFFFull;                                                                                                                                  
      l_spare = 0xFF00FF00FF00FF00ull; 
    	if (l_mbaPosition == 0)
	{
	    	//Writing MBS 01 pattern registers for comparison mode   
	    	
	                                                                                                                                  
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD0Q_0x02011681, l_data_buffer_64); if(rc) return rc;
        rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD1Q_0x02011682, l_data_buffer_64); if(rc) return rc;
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD2Q_0x02011683, l_data_buffer_64); if(rc) return rc;
    	rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD3Q_0x02011684, l_data_buffer_64); if(rc) return rc; 
	    rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD4Q_0x02011685, l_data_buffer_64); if(rc) return rc; 
	    rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD5Q_0x02011686, l_data_buffer_64); if(rc) return rc; 
	    rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD6Q_0x02011687, l_data_buffer_64); if(rc) return rc;	
	    rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD7Q_0x02011688, l_data_buffer_64); if(rc) return rc; 
	    rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDQ_0x02011689,  l_data_buffer_64); if(rc) return rc; 
	    rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDSPQ_0x0201168A,l_data_buffer_64); if(rc) return rc; 
                                                                                                                                                                            
	}
	else if (l_mbaPosition == 1)
	{
	    	//Writing MBS 23 pattern registers for comparison mode   
	                                                                                                                                
	    rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD0Q_0x02011781, l_data_buffer_64); if(rc) return rc;
	    rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD1Q_0x02011782, l_data_buffer_64); if(rc) return rc;
	    rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD2Q_0x02011783, l_data_buffer_64); if(rc) return rc;
	    rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD3Q_0x02011784, l_data_buffer_64); if(rc) return rc; 
	    rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD4Q_0x02011785, l_data_buffer_64); if(rc) return rc;  
	    rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD5Q_0x02011786, l_data_buffer_64); if(rc) return rc; 
	    rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD6Q_0x02011787, l_data_buffer_64); if(rc) return rc;   
  	    rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD7Q_0x02011788, l_data_buffer_64); if(rc) return rc; 
	    rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDQ_0x02011789,  l_data_buffer_64); if(rc) return rc; 
	    rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);    if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDSPQ_0x0201178A,l_data_buffer_64); if(rc) return rc; 
                                                                                                                                                                              
	}
    }
    else if(i_datamode == MCBIST_2D_CUP_PAT8)
    {
	l_var = 0xFFFFFFFFFFFFFFFFull;                                                                                                                                              
	l_var1 =0x0000000000000000ull;                                                                                                                                          
    l_spare = 0xFFFF0000FFFF0000ull; 
	if (l_mbaPosition == 0)
	{
	    	//Writing MBS 01 pattern registers for comparison mod
                                                                                                                                             
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD0Q_0x02011681, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD1Q_0x02011682, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD2Q_0x02011683, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD3Q_0x02011684, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD4Q_0x02011685, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD5Q_0x02011686, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); 	if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD6Q_0x02011687, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD7Q_0x02011688, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDQ_0x02011689,  l_data_buffer_64); if(rc) return rc; 
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);     if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDSPQ_0x0201168A,l_data_buffer_64); if(rc) return rc;  	
    	}
    	else if (l_mbaPosition == 1)
    	{
	    	//Writing MBS 23 pattern registers for comparison mod
      
		                                                                                                                                       
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD0Q_0x02011781, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD1Q_0x02011782, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD2Q_0x02011783, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD3Q_0x02011784, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD4Q_0x02011785, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD5Q_0x02011786, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD6Q_0x02011787, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD7Q_0x02011788, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDQ_0x02011789,  l_data_buffer_64); if(rc) return rc;  
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDSPQ_0x0201178A,l_data_buffer_64); if(rc) return rc;       


        }
    }
    else if(i_datamode == ABLE_FIVE)
    {
	    l_var = 0xA5A5A5A5A5A5A5A5ull;                                                                                                                                      
		l_var1 =0x5A5A5A5A5A5A5A5Aull;                                                                                                                                      
		l_spare = 0xA55AA55AA55AA55Aull;                                                                                                                                    
		
         if (l_mbaPosition == 0)
	 {
	    	//Writing MBS 01 pattern registers for comparison mod
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST01_MBS_MCBFD0Q_0x02011681, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST01_MBS_MCBFD1Q_0x02011682, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST01_MBS_MCBFD2Q_0x02011683, l_data_buffer_64); if(rc) return rc;  
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST01_MBS_MCBFD3Q_0x02011684, l_data_buffer_64);  if(rc) return rc;     
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST01_MBS_MCBFD4Q_0x02011685, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST01_MBS_MCBFD5Q_0x02011686, l_data_buffer_64);  if(rc) return rc;     
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST01_MBS_MCBFD6Q_0x02011687, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST01_MBS_MCBFD7Q_0x02011688, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST01_MBS_MCBFDQ_0x02011689,  l_data_buffer_64);  if(rc) return rc;     
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);    if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba,MBS_MCBIST01_MBS_MCBFDSPQ_0x0201168A, l_data_buffer_64); if(rc) return rc;   
         }
    	 else if (l_mbaPosition == 1)
    	 {
	    	//Writing MBS 23 pattern registers for comparison mod
        	                                                                                                                                                                           	 
		                                                                                                                                        
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST23_MBS_MCBFD0Q_0x02011781, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST23_MBS_MCBFD1Q_0x02011782, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST23_MBS_MCBFD2Q_0x02011783, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST23_MBS_MCBFD3Q_0x02011784, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST23_MBS_MCBFD4Q_0x02011785, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST23_MBS_MCBFD5Q_0x02011786, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST23_MBS_MCBFD6Q_0x02011787, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST23_MBS_MCBFD7Q_0x02011788, l_data_buffer_64); if(rc) return rc;      
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST23_MBS_MCBFDQ_0x02011789,  l_data_buffer_64); if(rc) return rc;      
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);    if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_mba, MBS_MCBIST23_MBS_MCBFDSPQ_0x0201178A,l_data_buffer_64); if(rc) return rc;      
                                                                                                                                                                           	   			
         }
    }
    else if((i_datamode == DATA_GEN_DELTA_I) || (i_datamode == MCBIST_2D_CUP_PAT0))
    {
	                                                                                                                                                                    	
        	l_var = 0xFFFFFFFFFFFFFFFFull;                                                                                                                                    	
        	l_var1 =0x0000000000000000ull;                                                                                                                                    	
        	l_spare = 0xFF00FF00FF00FF00ull;  
		if (l_mbaPosition == 0)
		{
	    	//Writing MBS 01 pattern registers for comparison mod
        		
                                                                                                                                       	
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD0Q_0x02011681, l_data_buffer_64); if(rc) return rc;
        rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD1Q_0x02011682, l_data_buffer_64); if(rc) return rc;
        rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD2Q_0x02011683, l_data_buffer_64); if(rc) return rc;
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD3Q_0x02011684, l_data_buffer_64); if(rc) return rc;   
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD4Q_0x02011685, l_data_buffer_64); if(rc) return rc;   
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD5Q_0x02011686, l_data_buffer_64); if(rc) return rc;   
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD6Q_0x02011687, l_data_buffer_64); if(rc) return rc;   
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD7Q_0x02011688, l_data_buffer_64); if(rc) return rc;   
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare); if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDQ_0x02011689,  l_data_buffer_64); if(rc) return rc;   
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);     if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDSPQ_0x0201168A,l_data_buffer_64); if(rc) return rc;   
                                                                                                                                                                          	
	
    	}
    	else if (l_mbaPosition == 1)
    	{
	    	//Writing MBS 23 pattern registers for comparison mod
        	                                                                                                                                                                    	         
	                                                                                                                               	     
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);    if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD0Q_0x02011781, l_data_buffer_64); if(rc) return rc;
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD1Q_0x02011782, l_data_buffer_64); if(rc) return rc;
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);    if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD2Q_0x02011783, l_data_buffer_64); if(rc) return rc;
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD3Q_0x02011784, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);    if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD4Q_0x02011785, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD5Q_0x02011786, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var_data_buffer_64.setDoubleWord(0,l_var);    if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD6Q_0x02011787, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_var1_data_buffer_64.setDoubleWord(0,l_var1);   if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD7Q_0x02011788, l_data_buffer_64); if(rc) return rc; 
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);  if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDQ_0x02011789,  l_data_buffer_64); if(rc) return rc; 
		rc_num = l_spare_data_buffer_64.setDoubleWord(0,l_spare);      if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDSPQ_0x0201178A,l_data_buffer_64); if(rc) return rc; 

    	}
    }
	
    
    else
    {
        FAPI_ERR("Data generation configuration mcbist_data_gen enum : %d does not exist for centaur printPosData(i_target_mba)",(int)i_datamode);
        
		FAPI_SET_HWP_ERROR(rc, RC_MSS_INPUT_ERROR);
		return rc;
    }
    for(l_index = 0; l_index<MAX_BYTE ;l_index ++)
    {
        
        for(l_index1 = 0; l_index1 < 8; l_index1++)
        {
            //l_rand_8 = rand();
			l_rand_8 = 0xFF;
            rc_num =  l_data_buffer_64.insert(l_rand_8,8*l_index1,8,24);if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}       // Source start in sn is given as 24 -- need to ask
        }
	rc = fapiPutScom(i_target_mba, l_mba01_mcb_random[l_index] , l_data_buffer_64); if(rc) return rc;
    }

   // rc = print_pattern(i_target_mba);if(rc)return rc;
	

	
	
	
	
    if(i_mcbrotate == 0)
    {
        FAPI_INF("i_mcbrotate == 0 , the l_rotnum is set to 13");
        l_rotnum = 13;   // for random data generation - basic setup
    }
    else
    {
        l_rotnum = i_mcbrotate;
    }
      
    rc_num = rc_num| l_data_buffer_4.insert(l_rotnum,0,4,0);
    rc_num = rc_num| l_data_buffer_64.insert(l_data_buffer_4,0,4,0);
	if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}
   // rc_num =  l_data_buffer_4.insert(l_rotnum,0,4,0);if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}
	
    rc_num = rc_num| l_data_buffer_16.insert(l_data_buffer1_4,0,4);
	rc_num = rc_num| l_data_buffer_16.insert(l_data_buffer1_4,4,4);
	rc_num = rc_num| l_data_buffer_16.insert(l_data_buffer1_4,8,4);
	rc_num =  rc_num|l_data_buffer_16.insert(l_data_buffer1_4,12,4);
	
	
	
    rc_num = rc_num| l_data_buffer_64.insert(l_data_buffer_16,4,16,0);
	
    FAPI_INF("Clearing bit 20 of MBA01_MCBIST_MCBDRCRQ_0x030106bd to avoid inversion of data to the write data flow");
    rc_num =  rc_num|l_data_buffer_64.clearBit(20);
	
	if (rc_num){ FAPI_ERR( "cfg_mcb_dgen:");rc.setEcmdError(rc_num);return rc;}
    rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBDRCRQ_0x030106bd,l_data_buffer_64); if(rc) return rc;
  
    return rc;
    }
}
