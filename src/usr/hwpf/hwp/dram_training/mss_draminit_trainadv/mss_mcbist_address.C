/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_mcbist_address.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: mss_mcbist_address.C,v 1.9 2013/04/04 20:56:10 bellows Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998, 2013
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             :  mss_mcbist_address_default.C
// *! TITLE                : 
// *! DESCRIPTION          : MCBIST procedures
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : preeragh@in.ibm.com
// *! BACKUP               : 
// *!***************************************************************************
// CHANGE HISTORY:
//-------------------------------------------------------------------------------
// Version:|Author: | Date:   | Comment:
// --------|--------|---------|--------------------------------------------------
// 1.9     |bellows |04-Apr-13| Changed program to be Hostboot compliant
// 1.2     |bellows |03-Apr-13| Added Id and cleaned up a warning msg.
// 1.1     |        |xx-Apr-13| Copied from original which is now known as mss_mcbist_address_default/_lab.C
//------------------------------------------------------------------------------

#include "mss_mcbist_address.H"
extern "C"
{
using namespace fapi;

#define MAX_STRING_LEN 80
#define DELIMITERS ","

fapi::ReturnCode address_generation(const fapi:: Target & i_target_mba,uint8_t i_port,mcbist_addr_mode i_addr_type,interleave_type i_add_inter_type,uint8_t i_rank,uint64_t &io_start_address, uint64_t &io_end_address)

{
fapi::ReturnCode  rc;
uint8_t l_num_ranks_per_dimm[2][2];
uint8_t l_num_master_ranks[2][2];
uint8_t l_dram_gen=0;
uint8_t l_dram_banks=0;
uint8_t l_dram_rows=0;
uint8_t l_dram_cols=0;
uint8_t l_dram_density=0;
uint8_t l_dram_width=0;
uint8_t l_addr_inter=0;
uint8_t l_num_ranks_p0_dim0,l_num_ranks_p0_dim1,l_num_ranks_p1_dim0,l_num_ranks_p1_dim1;
uint8_t mr3_valid,mr2_valid,mr1_valid;
uint32_t __attribute__((unused)) rc_num; // SW198827 
char S0[] = "b";
//char l_my_addr[MAX_STRING_LEN];

//Choose a default buffer for the below
//0			1	2		3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	25	26	27	28	29	30	31	32	33	34	35	36
//MR0(MSB)	MR1	MR2 	MR3	BA0	BA1	BA2	BA3	C3	C4	C5	C6	C7	C8	C9	C10	C11	R0	R1	R2	R3	R4	R5	R6	R7	R8	R9	R10	R11	R12	R13	R14	R15	R16	SL0(MSB)	SL1	SL2
ecmdDataBufferBase l_default_add_buffer(64);
ecmdDataBufferBase l_new_add_buffer(64);

 rc_num = l_default_add_buffer.flushTo0();
 rc_num = l_new_add_buffer.flushTo0();


rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm); if(rc) return rc;
rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target_mba, l_num_master_ranks); if(rc) return rc;
rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target_mba, l_dram_gen); if(rc) return rc;
rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_BANKS, &i_target_mba, l_dram_banks); if(rc) return rc;
rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ROWS, &i_target_mba, l_dram_rows); if(rc) return rc;
rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_COLS, &i_target_mba, l_dram_cols); if(rc) return rc;
rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DENSITY, &i_target_mba, l_dram_density); if(rc) return rc;
rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, l_dram_width); if(rc) return rc;
rc = FAPI_ATTR_GET(ATTR_MCBIST_ADDR_INTER, &i_target_mba, l_addr_inter); if(rc) return rc;


//------------------------------ Debug Stuff -------------------------------
FAPI_INF("ATTR_EFF_NUM_RANKS_PER_DIMM is %d ",l_num_ranks_per_dimm[0][0]);
FAPI_INF("ATTR_EFF_NUM_RANKS_PER_DIMM is %d ",l_num_ranks_per_dimm[0][1]);
FAPI_INF("ATTR_EFF_NUM_RANKS_PER_DIMM is %d ",l_num_ranks_per_dimm[1][0]);
FAPI_INF("ATTR_EFF_NUM_RANKS_PER_DIMM is %d ",l_num_ranks_per_dimm[1][1]);
//------------------------------ Debug Stuff -------------------------------

FAPI_INF("ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM l_num_master_p0_dim0 is %d ",l_num_master_ranks[0][0]);
FAPI_INF("ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM l_num_master_p0_dim1 is %d ",l_num_master_ranks[0][1]);
FAPI_INF("ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM l_num_master_p1_dim0 is %d ",l_num_master_ranks[1][0]);
FAPI_INF("ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM is l_num_master_p1_dim1 %d ",l_num_master_ranks[1][1]);

//-------------------------------------------------------------------------------

l_num_ranks_p0_dim0 = l_num_ranks_per_dimm[0][0];
l_num_ranks_p0_dim1 = l_num_ranks_per_dimm[0][1];
l_num_ranks_p1_dim0 = l_num_ranks_per_dimm[1][0];
l_num_ranks_p1_dim1 = l_num_ranks_per_dimm[1][1];

//Initial all ranks are invalid
mr3_valid = 0;
mr2_valid = 0;
mr1_valid = 0;

if( (l_num_ranks_p0_dim0 == 1 && l_num_ranks_p0_dim1 == 0) || (l_num_ranks_p1_dim0 == 1 && l_num_ranks_p1_dim1 == 0) )   //Single Rank case   -- default0
	{
		//do rank-only stuff for this
		FAPI_INF("--- INSIDE 1R");
		l_addr_inter=3;
	}
	
else if ( (l_num_ranks_p0_dim0 == 1 && l_num_ranks_p0_dim1 == 1) || (l_num_ranks_p1_dim0 == 1 && l_num_ranks_p1_dim1 == 1) )
{
	FAPI_INF("--- INSIDE p0d0 valid and p0d1 valid --- 0 4----  2R");
	mr1_valid=1;
}

else if ( (l_num_ranks_p0_dim0 == 2 && l_num_ranks_p0_dim1 == 0) || (l_num_ranks_p1_dim0 == 2 && l_num_ranks_p1_dim1 == 0) )
{
	FAPI_INF("--- INSIDE p0d0 valid and p0d1 valid --- 0 1----  2R");
	mr3_valid=1;
}
else if ((l_num_ranks_p0_dim0 == 2 && l_num_ranks_p0_dim1 == 2)|| (l_num_ranks_p1_dim0 == 2 && l_num_ranks_p1_dim1 == 2))   //Rank 01 and 45 case
	{
		FAPI_INF("--- INSIDE  --- 2R   0145");
		mr3_valid = 1;
		mr1_valid=1;
	}

else if((l_num_ranks_p0_dim0 == 4 && l_num_ranks_p0_dim1 == 0 )|| (l_num_ranks_p1_dim0 == 4 && l_num_ranks_p1_dim1 == 0 ))	//Rank 0123 on single dimm case
	{
		mr3_valid = 1;mr2_valid = 1;
	}

else if ((l_num_ranks_p0_dim0 == 4 && l_num_ranks_p0_dim1 == 4) || (l_num_ranks_p1_dim0 == 4 && l_num_ranks_p1_dim1 == 4)) //Rank 0123 and 4567 case
{
	mr3_valid = 1;
	mr2_valid = 1;
	mr1_valid = 1;
}
 	
else
	
	{
		FAPI_INF("-- Error ---- Check Config ----- ");
	}
	
FAPI_INF("ATTR_EFF_DRAM_GEN is %d ",l_dram_gen);
FAPI_INF("ATTR_EFF_DRAM_BANKS is %d ",l_dram_banks);
FAPI_INF("ATTR_EFF_DRAM_ROWS is %d ",l_dram_rows);
FAPI_INF("ATTR_EFF_DRAM_COLS is %d ",l_dram_cols);
FAPI_INF("ATTR_EFF_DRAM_DENSITY is %d ",l_dram_density);
FAPI_INF("ATTR_EFF_DRAM_WIDTH is %d ",l_dram_width);
FAPI_INF("ATTR_ADDR_INTER Mode is %d ",l_addr_inter);



FAPI_INF("--- BANK-RANK  Address interleave ---");
rc = parse_addr(i_target_mba,S0,mr3_valid,mr2_valid,mr1_valid,l_dram_rows,l_dram_cols,l_addr_inter);if(rc) return rc;
		


return rc;

}


fapi::ReturnCode parse_addr(const fapi:: Target & i_target_mba, char addr_string[],uint8_t mr3_valid,uint8_t mr2_valid,uint8_t mr1_valid,uint8_t l_dram_rows,uint8_t l_dram_cols,uint8_t l_addr_inter) 
{
fapi::ReturnCode  rc; 
uint8_t i=37;

uint8_t l_slave_rank = 0;
uint8_t l_value;
uint32_t l_value32 = 0;
uint32_t l_sbit,rc_num;
uint32_t l_start=0;
uint32_t l_len = 6;
uint64_t l_readscom_value = 0;
uint64_t l_end = 0;
uint64_t l_start_addr = 0;
uint8_t l_value_zero = 0;
uint8_t l_user_end_addr = 0;
ecmdDataBufferBase l_data_buffer_64(64);
ecmdDataBufferBase l_data_buffer_rd64(64); 
uint8_t l_attr_addr_mode = 3;
uint8_t l_num_cols = 0;
uint8_t l_num_rows = 0;



rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_ADDR_MODE, &i_target_mba, l_attr_addr_mode); if(rc) return rc;

rc = FAPI_ATTR_GET(ATTR_MCBIST_ADDR_NUM_COLS, &i_target_mba, l_num_cols); if(rc) return rc;
rc = FAPI_ATTR_GET(ATTR_MCBIST_ADDR_NUM_ROWS, &i_target_mba, l_num_rows); if(rc) return rc;

if(l_num_cols == 0)
{l_num_cols = l_dram_cols;}

if(l_num_rows == 0 )
{l_num_rows = l_dram_rows;}


//Set all the addr reg to 0

//Define Custom String

//Set all Params based on the string.

rc_num = l_data_buffer_64.flushTo0();
	
	l_sbit = 0;l_value =i;
	rc = fapiGetScom(i_target_mba,0x030106c9,l_data_buffer_64); if(rc) return rc;
	rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
	rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
	i--;
		
		l_sbit = 54;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c8,l_data_buffer_64);
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);
		rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
		i--;
		//FAPI_INF("Inside strcmp ba2");
		l_sbit = 48;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c8,l_data_buffer_64); if(rc) return rc;
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);
		rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
		i--;
		
		//FAPI_INF("Inside strcmp ba3");
		l_sbit = 42;l_value =i;
		//------- Enable these for DDR4 --- for now constant map to zero
		rc = fapiGetScom(i_target_mba,0x030106c8,l_data_buffer_64); if(rc) return rc;
		FAPI_INF("ba3 Invalid");
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);
		rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
		i++;
		
		
		//FAPI_INF("Inside strcmp mr3");
		l_sbit = 18;l_value =i;
			rc = fapiGetScom(i_target_mba,0x030106c8,l_data_buffer_64); if(rc) return rc;
			if(mr3_valid==1)
			{
				
				rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
				rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
				i--;
			}
			else
			{
				rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
				rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
				FAPI_INF("mr3 Invalid");
				i++;
			}
		
		
	
		//FAPI_INF("Inside strcmp mr2");
		l_sbit = 12;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c8,l_data_buffer_64); if(rc) return rc;
			if(mr2_valid==1)
			{
				rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
				FAPI_INF("Inside mr2 --- l_addr_inter");
				rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
				i--;
			}
		
			else
			{	
				rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
				rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
				FAPI_INF("mr2 Invalid");
				i++;
			}
		
		
	
	
		//FAPI_INF("Inside strcmp mr1");
		l_sbit = 6;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c8,l_data_buffer_64); if(rc) return rc;
			if(mr1_valid==1)
			{
				rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
				FAPI_INF("Inside mr1 --- l_addr_inter");
				rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
				i--;
			}
			else
				{
					rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
					rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
					FAPI_INF("mr1 Invalid");
					i++;
				}
	
		
	
	
	
		//FAPI_INF("Inside strcmp mr0");
		l_sbit = 0;l_value =i;
		//------- Enable these for DDR4 --- for now constant map to zero
		rc = fapiGetScom(i_target_mba,0x030106c8,l_data_buffer_64); if(rc) return rc;
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
		i++;
		//FAPI_INF("Value of i = %d",i);
		FAPI_INF("mr0 Invalid\n");
		
	
	
		//FAPI_INF("Inside strcmp cl3");
		l_sbit = 42;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106cb,l_data_buffer_64); if(rc) return rc;
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
		i++;
		FAPI_INF("col2 Invalid");
		//FAPI_INF("Value of i = %d",i);
		
	
	
	
		//FAPI_INF("Inside strcmp cl3");
		l_sbit = 36;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106cb,l_data_buffer_64); if(rc) return rc;
		if(l_num_cols >= 1)
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			i--;
		}
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("Col 3 -- Invalid");
			i++;
		}
		
		//FAPI_INF("Inside strcmp cl4");
		l_sbit = 30;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106cb,l_data_buffer_64); if(rc) return rc;
		if(l_num_cols >= 2)
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			i--;
		
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("Col 4 -- Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp cl5");
		l_sbit = 24;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106cb,l_data_buffer_64); if(rc) return rc;
		if(l_num_cols >= 3)
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			i--;
		}
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("Col 5 -- Invalid");
			i++;
		}
		
		//FAPI_INF("Inside strcmp cl6");
		l_sbit = 18;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106cb,l_data_buffer_64); if(rc) return rc;
		if(l_num_cols >= 4)
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("Col 6 -- Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp cl7");
		l_sbit = 12;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106cb,l_data_buffer_64); if(rc) return rc;
		if(l_num_cols >= 5)
		{
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("Col 7 -- Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp cl8");
		l_sbit = 6;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106cb,l_data_buffer_64); if(rc) return rc;
		if(l_num_cols >= 6)
		{
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("Col 8 -- Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp cl9");
		l_sbit = 0;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106cb,l_data_buffer_64); if(rc) return rc;
		if(l_num_cols >= 7)
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;i--;}
		
		
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106cb,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("Col 9 -- Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp cl11");
		l_sbit = 54;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106ca,l_data_buffer_64); if(rc) return rc;
		if(l_num_cols >= 11)
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			i--;
			
			
		}
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("Col 11 -- Invalid");
			i++;
			
		}
		
		//FAPI_INF("Value of i = %d",i);
		
	

		//FAPI_INF("Inside strcmp cl13");
		l_sbit = 48;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106ca,l_data_buffer_64); if(rc) return rc;
		if(l_num_cols >= 12)
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			i--;
		}
		else
		{	
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("Col 13 Invalid");
			i++;
		}
		//FAPI_INF("Value of i = %d",i);
		
	
	


		//FAPI_INF("Inside strcmp r0");
		l_sbit = 42;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106ca,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 0 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 0 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r1");
		l_sbit = 36;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106ca,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 1 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 1 --  Invalid");
			i++;
		}
		
	
	
	
		//FAPI_INF("Inside strcmp r2");
		l_sbit = 30;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106ca,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 2 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 2 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r3");
		l_sbit = 24;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106ca,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 3 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 3 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r4");
		l_sbit = 18;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106ca,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 4 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
		i--;}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 4 --  Invalid");
			i++;
		}
		
	
	

	
		//FAPI_INF("Inside strcmp r5");
		l_sbit = 12;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106ca,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 5 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 5 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r6");
		l_sbit = 6;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106ca,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 6 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 6 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r7");
		l_sbit = 0;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106ca,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 7 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106ca,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 7 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r8");
		l_sbit = 54;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c9,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 8 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 8 --  Invalid");
			i++;
		}
		
	
	

		//FAPI_INF("Inside strcmp r9");
		l_sbit = 48;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c9,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 9 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 9 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r10");
		l_sbit = 42;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c9,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 10 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 10 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r11");
		l_sbit = 36;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c9,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 11 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 11 --  Invalid");
			i++;
		}
		
	
	
		//FAPI_INF("Inside strcmp r12");
		l_sbit = 30;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c9,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 12 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 12 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r13");
		l_sbit = 24;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c9,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 13 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 13 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r14");
		l_sbit = 18;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c9,l_data_buffer_64); if(rc) return rc;
		if(l_num_rows > 14 )
		{rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		//FAPI_INF("Value of i = %d",i);
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 14 --  Invalid");
			i++;
		}
		
	

		//FAPI_INF("Inside strcmp r15");
		l_sbit = 12;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c9,l_data_buffer_64); if(rc) return rc;
		if ( l_num_rows > 15 )
		{	rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
			i--;
		}
		else
		{
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
			FAPI_INF("row 15 --  Invalid");
			i++;
		}
		//FAPI_INF("Value of i = %d",i);
		
	

		//FAPI_INF("Inside strcmp r16 and l_dram_rows = %d",l_dram_rows); 
		l_sbit = 6;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c9,l_data_buffer_64); if(rc) return rc;
		if ( l_dram_rows >= 17 )
		{
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
		i--;
		}
		else
		{
			//FAPI_INF("r16 not used");
			rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
			FAPI_INF("Row 16 Invalid");
			rc = fapiPutScom(i_target_mba,0x030106c9,l_data_buffer_64);  if(rc) return rc;
			i++;
		}
		//FAPI_INF("Value of i = %d",i);
		
	

		//FAPI_INF("Inside strcmp sl2");
		l_sbit = 36;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c8,l_data_buffer_64); if(rc) return rc;
		//------- Enable these for later --- for now constant map to zero
		if (l_slave_rank==0)
		{l_value =0;}
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
		FAPI_INF("sl2 Invalid");
		i++;
		//FAPI_INF("Value of i = %d",i);
		
	

		//FAPI_INF("Inside strcmp sl1");
		l_sbit = 30;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c8,l_data_buffer_64); if(rc) return rc;
		//------- Enable these for later --- for now constant map to zero
		if (l_slave_rank==0)
		{l_value =0;}
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
		i++;
		FAPI_INF("sl1 Invalid");
		//FAPI_INF("Value of i = %d",i);
		
	

		//FAPI_INF("Inside strcmp sl0");
		l_sbit = 24;l_value =i;
		rc = fapiGetScom(i_target_mba,0x030106c8,l_data_buffer_64); if(rc) return rc;
		//------- Enable these for later --- for now constant map to zero
		if (l_slave_rank==0)
		{l_value =0;}
		rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);if (rc_num){FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);return rc;}
		rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  if(rc) return rc;
		FAPI_INF("sl0 Invalid");
		i++;
		//FAPI_INF("Value of i = %d",i);
		
	
	

  

  //------ Setting Start and end addr counters
  
FAPI_INF("Debug - --------------- Setting Start and End Counters -----------\n");
rc_num = l_data_buffer_rd64.flushTo0();
rc = fapiPutScom(i_target_mba,0x030106d0,l_data_buffer_rd64); if(rc) return rc;
l_value = i+1;
FAPI_INF("Setting end_addr Value of i = %d",i);
rc_num = l_data_buffer_rd64.flushTo0();

//Calculate and set Valid bits for end_addr

for(i=l_value;i <= 37;i++)
	{	rc_num =  l_data_buffer_rd64.clearBit(i);
		rc_num =  l_data_buffer_rd64.setBit(i);
	}
	if (rc_num){FAPI_ERR( "Error in function  addr_gen:");rc.setEcmdError(rc_num);return rc;}

l_readscom_value = l_data_buffer_rd64.getDoubleWord (0);
FAPI_INF("Debug - Initial End addr for 0x030106d2 = %016llX",l_readscom_value);

rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_ADDR_MODE, &i_target_mba, l_attr_addr_mode); if(rc) return rc;

rc = FAPI_ATTR_GET(ATTR_MCBIST_START_ADDR, &i_target_mba, l_start_addr); if(rc) return rc;
FAPI_INF("User Defined ATTR - Start = %016llX",l_start_addr);

rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_ADDR_MODE, &i_target_mba, l_attr_addr_mode); if(rc) return rc;
rc = FAPI_ATTR_GET(ATTR_MCBIST_END_ADDR, &i_target_mba, l_end); if(rc) return rc;

FAPI_INF("User defined END ATTR - End Address = %016llX",l_end);

rc = FAPI_ATTR_GET(ATTR_MCBIST_RANK, &i_target_mba, l_user_end_addr); if(rc) return rc;

if(l_user_end_addr == 1)
{

//Setting start and end Temp

rc_num  = l_data_buffer_rd64.setDoubleWord(0,l_start_addr);if(rc_num) return rc;
rc = fapiPutScom(i_target_mba,0x030106d0,l_data_buffer_rd64); if(rc) return rc;
rc = fapiPutScom(i_target_mba,0x030106d1,l_data_buffer_rd64); if(rc) return rc;

rc_num  = l_data_buffer_rd64.setDoubleWord(0,l_end);if(rc_num) return rc;
rc = fapiPutScom(i_target_mba,0x030106d2,l_data_buffer_rd64); if(rc) return rc;
rc = fapiPutScom(i_target_mba,0x030106d3,l_data_buffer_rd64); if(rc) return rc;
}

else
{

l_attr_addr_mode = 3;

if(l_attr_addr_mode == 0)
{
	FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- Few Address Mode --------",l_attr_addr_mode);
	l_sbit = 32;
	rc_num = l_data_buffer_rd64.flushTo0();
	l_start = 24;
	l_len = 8;
	l_value32 = 28;
	rc_num=l_data_buffer_rd64.insert(l_value32,l_sbit,l_len,l_start);
	rc = fapiPutScom(i_target_mba,0x030106d2,l_data_buffer_rd64); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,0x030106d3,l_data_buffer_rd64); if(rc) return rc;
	l_readscom_value = l_data_buffer_rd64.getDoubleWord (0);
	FAPI_INF("Debug - Final End addr for 0x030106d2 = %016llX",l_readscom_value);
}

else if(l_attr_addr_mode == 1)
{
	FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- QUARTER ADDRESSING Mode --------",l_attr_addr_mode);
	l_readscom_value = l_readscom_value >> 2;
	FAPI_INF("Debug - Final End addr for 0x030106d2 = %016llX",l_readscom_value);
	rc_num  = l_data_buffer_rd64.setDoubleWord(0,l_readscom_value);if(rc_num) return rc;
	rc = fapiPutScom(i_target_mba,0x030106d2,l_data_buffer_rd64); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,0x030106d3,l_data_buffer_rd64); if(rc) return rc;

}
else if(l_attr_addr_mode == 2)
{
	FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- HALF ADDRESSING Mode --------",l_attr_addr_mode);
	l_readscom_value = l_readscom_value >> 1;
	FAPI_INF("Debug - Final End addr for 0x030106d2 = %016llX",l_readscom_value);
	rc_num  = l_data_buffer_rd64.setDoubleWord(0,l_readscom_value);if(rc_num) return rc;
	rc = fapiPutScom(i_target_mba,0x030106d2,l_data_buffer_rd64); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,0x030106d3,l_data_buffer_rd64); if(rc) return rc;
}
else
{
	FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- FULL Address Mode --------",l_attr_addr_mode);
	FAPI_INF("Debug - Final End addr for 0x030106d2 = %016llX",l_readscom_value);
	rc = fapiPutScom(i_target_mba,0x030106d2,l_data_buffer_rd64); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,0x030106d3,l_data_buffer_rd64); if(rc) return rc;
}

}

return rc;

}
}
