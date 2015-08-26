/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_mcbist_address.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_mcbist_address.C,v 1.26 2015/07/24 08:32:13 sasethur Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998, 2013
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME             :  mss_mcbist_address_default.C
// *! TITLE                : 
// *! DESCRIPTION          : MCBIST procedures
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Preetham Hosmane | preeragh@in.ibm.com
// *! BACKUP               : Saravanan Sethuraman
// *!***************************************************************************
// CHANGE HISTORY:
//-------------------------------------------------------------------------------
// Version:|Author: | Date:   | Comment:
// --------|--------|---------|--------------------------------------------------
// 1.26    |preeragh|22-Jul-15| 64bit compile fix
// 1.25    |preeragh|22-Jun-15| DDR4 - Mods and fixes
// 1.24    |lwmulkey|15-JUN-15| Add 2H CDIMM support
// 1.20    |lwmulkey|06-JUN-15| Add slave rank support
// 1.17    |sglancy |16-FEB-15| Merged FW comments with lab debugging needs
// 1.17    |preeragh|15-Dec-14| Fix FW Review Comments
// 1.16    |rwheeler|10-Nov-14| Update to address_generation for custom address string
// 1.15    |preeragh|03-Nov-14| Fix for 128GB Schmoo
// 1.14    |mjjones |20-Jan-13| RAS Review Updates
// 1.13    |preet   |18-Dec-13| Added 64K default for few addr_mode
// 1.12    |preet   |17-Dec-13| Added Addr modes
// 1.11	   |preeragh|17-May-13| Fixed FW Review Comments
// 1.10	   |preeragh|30-Apr-13| Fixed FW Review Comment
// 1.9     |bellows |04-Apr-13| Changed program to be Hostboot compliant
// 1.2     |bellows |03-Apr-13| Added Id and cleaned up a warning msg.
// 1.1     |        |xx-Apr-13| Copied from original which is now known as mss_mcbist_address_default/_lab.C
// 1.2 	   Preetham | xx - Apr -13| Fixed rc_num call
//------------------------------------------------------------------------------

#include "mss_mcbist_address.H"
extern "C"
{
using namespace fapi;

#define MAX_ADDR_BITS 37
#define MAX_VALUE_TWO 2

#define DELIMITERS ","

fapi::ReturnCode address_generation(const fapi:: Target & i_target_mba,uint8_t i_port,mcbist_addr_mode i_addr_type,interleave_type i_add_inter_type,uint8_t i_rank,uint64_t &io_start_address, uint64_t &io_end_address, char * l_str_cust_addr)
{
    fapi::ReturnCode rc;
    uint8_t l_num_ranks_per_dimm[MAX_VALUE_TWO][MAX_VALUE_TWO];
    uint8_t l_num_master_ranks[MAX_VALUE_TWO][MAX_VALUE_TWO];
    uint8_t l_dram_banks = 0;
    uint8_t l_dram_rows = 0;
    uint8_t l_dram_cols = 0;
    //uint8_t l_dram_density = 0;
    //uint8_t l_dram_width = 0;
    uint8_t l_addr_inter = 0;
    uint8_t l_num_ranks_p0_dim0,l_num_ranks_p0_dim1,l_num_ranks_p1_dim0,l_num_ranks_p1_dim1;
    uint8_t l_master_ranks_p0_dim0,l_master_ranks_p0_dim1,l_master_ranks_p1_dim0;
    uint8_t mr3_valid, mr2_valid, mr1_valid,sl0_valid,sl1_valid,sl2_valid;
    uint32_t rc_num;
    char S0[] = "b";
    //Choose a default buffer for the below
    //0			1	2		3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	25	26	27	28	29	30	31	32	33	34	35	36
    //MR0(MSB)	MR1	MR2 	MR3	BA0	BA1	BA2	BA3	C3	C4	C5	C6	C7	C8	C9	C10	C11	R0	R1	R2	R3	R4	R5	R6	R7	R8	R9	R10	R11	R12	R13	R14	R15	R16	SL0(MSB)	SL1	SL2
    ecmdDataBufferBase l_default_add_buffer(64);
    ecmdDataBufferBase l_new_add_buffer(64);

    rc_num = l_default_add_buffer.flushTo0();
    rc_num |= l_new_add_buffer.flushTo0();
    if (rc_num)
    {
        FAPI_ERR("Error in function  addr_gen:");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target_mba,l_num_master_ranks);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_BANKS, &i_target_mba, l_dram_banks);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ROWS, &i_target_mba, l_dram_rows);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_COLS, &i_target_mba, l_dram_cols);
    if (rc) return rc;
    //rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DENSITY, &i_target_mba, l_dram_density);
    //if (rc) return rc;
    //rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, l_dram_width);
    //if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MCBIST_ADDR_INTER, &i_target_mba, l_addr_inter);
    if (rc) return rc;

    //------------------------------ Debug Stuff -------------------------------
   //FAPI_INF("ATTR_EFF_NUM_RANKS_PER_DIMM is %d ",l_num_ranks_per_dimm[0][0]);
   //FAPI_INF("ATTR_EFF_NUM_RANKS_PER_DIMM is %d ",l_num_ranks_per_dimm[0][1]);
   //FAPI_INF("ATTR_EFF_NUM_RANKS_PER_DIMM is %d ",l_num_ranks_per_dimm[1][0]);
   //FAPI_INF("ATTR_EFF_NUM_RANKS_PER_DIMM is %d ",l_num_ranks_per_dimm[1][1]);
   //------------------------------ Debug Stuff -------------------------------
   //FAPI_INF("ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM l_num_master_p0_dim0 is %d ",l_num_master_ranks[0][0]);
   //FAPI_INF("ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM l_num_master_p0_dim1 is %d ",l_num_master_ranks[0][1]);
   //FAPI_INF("ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM l_num_master_p1_dim0 is %d ",l_num_master_ranks[1][0]);
   //FAPI_INF("ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM l_num_master_p1_dim1 is %d ",l_num_master_ranks[1][1]);
   //-------------------------------------------------------------------------------

l_num_ranks_p0_dim0 = l_num_ranks_per_dimm[0][0];
l_num_ranks_p0_dim1 = l_num_ranks_per_dimm[0][1];
l_num_ranks_p1_dim0 = l_num_ranks_per_dimm[1][0];
l_num_ranks_p1_dim1 = l_num_ranks_per_dimm[1][1];
l_master_ranks_p0_dim0 = l_num_master_ranks[0][0];
l_master_ranks_p0_dim1 = l_num_master_ranks[0][1];
l_master_ranks_p1_dim0 = l_num_master_ranks[1][0];
//l_master_ranks_p1_dim1 = l_num_master_ranks[1][1];
//Initial all ranks are invalid
mr3_valid = 0;
mr2_valid = 0;
mr1_valid = 0;
sl2_valid = 0;
sl1_valid = 0;
sl0_valid = 0;

if( (l_num_ranks_p0_dim0 == 1 && l_num_ranks_p0_dim1 == 0) || (l_num_ranks_p1_dim0 == 1 && l_num_ranks_p1_dim1 == 0) )   //Single Rank case   -- default0
	{
		//do rank-only stuff for this
		FAPI_DBG("%s:--- INSIDE 1R",i_target_mba.toEcmdString());
		l_addr_inter=3;
	}
	
else if ( (l_num_ranks_p0_dim0 == 1 && l_num_ranks_p0_dim1 == 1) || (l_num_ranks_p1_dim0 == 1 && l_num_ranks_p1_dim1 == 1) )
{
	FAPI_DBG("%s:--- INSIDE p0d0 valid and p0d1 valid --- 0 4----  2R",i_target_mba.toEcmdString());
	mr1_valid=1;
}

else if ( (l_num_ranks_p0_dim0 == 2 && l_num_ranks_p0_dim1 == 0) || (l_num_ranks_p1_dim0 == 2 && l_num_ranks_p1_dim1 == 0) )
{
	FAPI_DBG("%s:--- INSIDE p0d0 valid and p0d1 valid --- 0 1----  2R",i_target_mba.toEcmdString());
	mr3_valid=1;
}
else if (((l_num_ranks_p0_dim0 == 2 && l_num_ranks_p0_dim1 == 2)|| (l_num_ranks_p1_dim0 == 2 && l_num_ranks_p1_dim1 == 2)) && (l_master_ranks_p0_dim0 != 1 && l_master_ranks_p0_dim1 != 1))   //Rank 01 and 45 case
	{
		FAPI_DBG("%s:--- INSIDE  --- 2R   0145",i_target_mba.toEcmdString());
		mr3_valid = 1;
		mr1_valid=1;
	}

else if((l_num_ranks_p0_dim0 == 4 && l_num_ranks_p0_dim1 == 0 )|| (l_num_ranks_p1_dim0 == 4 && l_num_ranks_p1_dim1 == 0 ))	//Rank 0123 on single dimm case
	{
		mr3_valid = 1;mr2_valid = 1;
	}
else if (((l_num_ranks_p0_dim0 == 4 && l_num_ranks_p0_dim1 == 4) || (l_num_ranks_p1_dim0 == 4 && l_num_ranks_p1_dim1 == 4)) && l_master_ranks_p0_dim0 == 1) //1r 4h stack
{
        mr1_valid = 0; //DDC
	sl1_valid = 1;
	sl2_valid = 1;
}

else if (((l_num_ranks_p0_dim0 == 8 && l_num_ranks_p0_dim1 == 0) || (l_num_ranks_p1_dim0 == 8 && l_num_ranks_p1_dim1 == 0)) && ((l_master_ranks_p0_dim0 == 2) || (l_master_ranks_p0_dim1 == 0 && l_master_ranks_p1_dim0 == 2))) //2rx4 4h ddr4 3ds 
{
	l_addr_inter = 4;
	//l_str_cust_addr = "sl2,sl1,ba0,mr3,cl3,cl4,cl5,ba1,cl6,cl7,cl8,ba2,r0,r1,r2,ba3,cl2,cl9,cl11,cl13,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,sl0,mr2,mr1,mr0"; //DDC
        mr3_valid = 1; //DDC
	sl1_valid = 1;
	sl2_valid = 1;
}
else if ((l_num_ranks_p0_dim0 == 4 && l_num_ranks_p0_dim1 == 4) || (l_num_ranks_p1_dim0 == 4 && l_num_ranks_p1_dim1 == 4)) //Rank 0123 and 4567 case
{
	mr3_valid = 1;
	mr2_valid = 1;
	mr1_valid = 1;
}
    else if (((l_num_ranks_p0_dim0 == 2 && l_num_ranks_p0_dim1 == 2) ||
              (l_num_ranks_p1_dim0 == 2 && l_num_ranks_p1_dim1 == 2)) &&
              (l_master_ranks_p0_dim0 == 1 && l_master_ranks_p0_dim1 == 1)) //1rx4 2h ddr4 3ds 2 dimm, CDIMM
    {
        sl1_valid = 0;
        sl2_valid = 1;
	mr1_valid = 1;
    }

    else
    {
        FAPI_INF("-- Error ---- mcbist_addr_Check dimm_Config ----- ");
    }

    //FAPI_INF("ATTR_EFF_DRAM_GEN is %d ",l_dram_gen);
    //FAPI_INF("ATTR_EFF_DRAM_BANKS is %d ",l_dram_banks);
    //FAPI_INF("ATTR_EFF_DRAM_ROWS is %d ",l_dram_rows);
    //FAPI_INF("ATTR_EFF_DRAM_COLS is %d ",l_dram_cols);
    //FAPI_INF("ATTR_EFF_DRAM_DENSITY is %d ",l_dram_density);
    //FAPI_INF("ATTR_EFF_DRAM_WIDTH is %d ",l_dram_width);
    //FAPI_INF("ATTR_ADDR_INTER Mode is %d ",l_addr_inter);
    //FAPI_INF("--- BANK-RANK  Address interleave ---");
    //custom addressing string is not to be used
    if(l_addr_inter != 4) {
       rc = parse_addr(i_target_mba, S0, mr3_valid, mr2_valid, mr1_valid,
                    l_dram_rows, l_dram_cols, l_addr_inter,sl2_valid,sl1_valid,sl0_valid);
       if (rc) return rc;
    }
    else {
       FAPI_DBG("Custom addressing flag was selected");
       rc = parse_addr(i_target_mba, l_str_cust_addr, mr3_valid, mr2_valid, mr1_valid,
                    l_dram_rows, l_dram_cols, l_addr_inter,sl2_valid,sl1_valid,sl0_valid);
       if (rc) return rc;
    }

    return rc;
}

fapi::ReturnCode parse_addr(const fapi::Target & i_target_mba,
                            char addr_string[],
                            uint8_t mr3_valid,
                            uint8_t mr2_valid,
                            uint8_t mr1_valid,
                            uint8_t l_dram_rows,
                            uint8_t l_dram_cols,
                            uint8_t l_addr_inter,
			    uint8_t sl2_valid,
                            uint8_t sl1_valid,
                            uint8_t sl0_valid)
{
    fapi::ReturnCode rc;
    uint8_t i = MAX_ADDR_BITS;

    uint8_t l_value;
    uint32_t l_value32 = 0;
    uint32_t l_sbit, rc_num;
    uint32_t l_start = 0;
    uint32_t l_len = 0;
    uint64_t l_readscom_value = 0;
    uint64_t l_end = 0;
    uint64_t l_start_addr = 0;
    uint8_t l_value_zero = 0;
    uint8_t l_user_end_addr = 0;
    ecmdDataBufferBase l_data_buffer_64(64);
    ecmdDataBufferBase l_data_buffer_rd64(64);
    uint8_t l_attr_addr_mode = 0;
    uint8_t l_num_cols = 0;
    uint8_t l_num_rows = 0;
	uint8_t l_dram_gen = 0;
	
    rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_ADDR_MODE, &i_target_mba, l_attr_addr_mode);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MCBIST_ADDR_NUM_COLS, &i_target_mba, l_num_cols);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MCBIST_ADDR_NUM_ROWS, &i_target_mba, l_num_rows);
    if (rc) return rc;
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target_mba, l_dram_gen);
    if (rc) return rc;

    if (l_num_cols == 0)
    {
        l_num_cols = l_dram_cols;
    }

    if (l_num_rows == 0)
    {
        l_num_rows = l_dram_rows;
    }

    //Set all the addr reg to 0
    //Define Custom String
    //Set all Params based on the string.
    rc_num = l_data_buffer_64.flushTo0();
    if (rc_num)
    {
        FAPI_ERR("Error in function  parse_addr:");
        rc.setEcmdError(rc_num);
        return rc;
    }

    l_sbit = 0;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
    if (rc_num)
    {
        FAPI_ERR("Error in function  parse_addr:");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    i--;

    l_sbit = 54;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
    if (rc_num)
    {
        FAPI_ERR("Error in function  parse_addr:");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    i--;
	
	////FAPI_INF("Inside strcmp mr3");
    l_sbit = 18;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    if (mr3_valid == 1)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
        if (rc) return rc;
        //FAPI_INF("mr3 Invalid");
		
        
    }

    ////FAPI_INF("Inside strcmp mr2");
    l_sbit = 12;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    if (mr2_valid == 1)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        //FAPI_INF("Inside mr2 --- l_addr_inter");
        rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
        if (rc) return rc;
        //FAPI_INF("mr2 Invalid");
		
        
    }

    ////FAPI_INF("Inside strcmp mr1");
    l_sbit = 6;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    if (mr1_valid == 1)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        //FAPI_INF("Inside mr1 --- l_addr_inter");
        rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    else
    {
        rc_num =  l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
        if (rc) return rc;
        //FAPI_INF("mr1 Invalid");
		
        
    }


    ////FAPI_INF("Inside strcmp ba2");
    l_sbit = 48;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
    if (rc_num)
    {
        FAPI_ERR("Error in function  parse_addr:");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    i--;

    ////FAPI_INF("Inside strcmp ba3");
    l_sbit = 42;
    l_value = i;
    //------- Enable these for DDR4 --- for now constant map to zero
    rc = fapiGetScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    //FAPI_INF("ba3 Invalid");
	if (l_dram_gen == 2){
    rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
    if (rc_num)
    {
        FAPI_ERR("Error in function  parse_addr:");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
	i--;
}
else
{
	rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
    if (rc_num)
    {
        FAPI_ERR("Error in function  parse_addr:");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
	
}


    ////FAPI_INF("Inside strcmp mr0");
    l_sbit = 0;
    l_value = i;
    //------- Enable these for DDR4 --- for now constant map to zero
    rc = fapiGetScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    rc_num =  l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
    if (rc_num)
    {
        FAPI_ERR("Error in function  parse_addr:");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
	
    
    ////FAPI_INF("Value of i = %d",i);
    //FAPI_INF("mr0 Invalid\n");

    ////FAPI_INF("Inside strcmp cl3");
    l_sbit = 42;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106cb, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
    if (rc_num)
    {
        FAPI_ERR("Error in function  parse_addr:");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
    if (rc) return rc;
	
	///////////////////////////////////////////////////////////////////
    
    //FAPI_INF("col2 Invalid");
    ////FAPI_INF("Value of i = %d",i);
    ////FAPI_INF("Inside strcmp cl3");
    l_sbit = 36;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106cb, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_cols >= 1)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("Col 3 -- Invalid");
        
    }

    ////FAPI_INF("Inside strcmp cl4");
    l_sbit = 30;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106cb, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_cols >= 2)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("Col 4 -- Invalid");
        
    }

    ////FAPI_INF("Inside strcmp cl5");
    l_sbit = 24;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106cb, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_cols >= 3)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("Col 5 -- Invalid");
       
    }

    ////FAPI_INF("Inside strcmp cl6");
    l_sbit = 18;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106cb, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_cols >= 4)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("Col 6 -- Invalid");
        
    }

    ////FAPI_INF("Inside strcmp cl7");
    l_sbit = 12;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106cb, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_cols >= 5)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num =  l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("Col 7 -- Invalid");
        
    }

    ////FAPI_INF("Inside strcmp cl8");
    l_sbit = 6;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106cb, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_cols >= 6)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("Col 8 -- Invalid");
        
    }

    ////FAPI_INF("Inside strcmp cl9");
    l_sbit = 0;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106cb, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_cols >= 7)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }

    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106cb, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("Col 9 -- Invalid");
        
    }

    ////FAPI_INF("Inside strcmp cl11");
    l_sbit = 54;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106ca, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_cols >= 11)
    {
        if (l_dram_cols >= 11)
        {
            rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
            if (rc_num)
            {
                FAPI_ERR("Error in function  parse_addr:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
            if (rc) return rc;
            //FAPI_DBG("%s: Inside l_dram_cols > 10");
            i--;
        }
        else
        {
            rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
            if (rc_num)
            {
                FAPI_ERR("Error in function  parse_addr:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
            if (rc) return rc;
			
            FAPI_DBG("%s:Col 11 -- Invalid", i_target_mba.toEcmdString());
            
        }
    }
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("Col 11 -- Invalid");
        
    }

    ////FAPI_INF("Value of i = %d",i);
    ////FAPI_INF("Inside strcmp cl13");
    l_sbit = 48;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106ca, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_cols >= 12)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("Col 13 Invalid");
        
    }
    ////FAPI_INF("Value of i = %d",i);
    ////FAPI_INF("Inside strcmp r0");
    l_sbit = 42;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106ca, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 0)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 0 --  Invalid");
        
    }

    ////FAPI_INF("Inside strcmp r1");
    l_sbit = 36;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106ca, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 1)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 1 --  Invalid");
        
    }

    ////FAPI_INF("Inside strcmp r2");
    l_sbit = 30;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106ca, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 2)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 2 --  Invalid");
        
    }

    ////FAPI_INF("Inside strcmp r3");
    l_sbit = 24;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106ca, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 3)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 3 --  Invalid");
        
    }

    ////FAPI_INF("Inside strcmp r4");
    l_sbit = 18;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106ca, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 4)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 4 --  Invalid");
        
    }

    ////FAPI_INF("Inside strcmp r5");
    l_sbit = 12;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106ca, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 5)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 5 --  Invalid");
        
    }

    ////FAPI_INF("Inside strcmp r6");
    l_sbit = 6;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106ca, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 6)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 6 --  Invalid");
        
    }

    ////FAPI_INF("Inside strcmp r7");
    l_sbit = 0;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106ca, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 7)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106ca, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 7 --  Invalid");
       
    }

    ////FAPI_INF("Inside strcmp r8");
    l_sbit = 54;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 8)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 8 --  Invalid");
       
    }

    ////FAPI_INF("Inside strcmp r9");
    l_sbit = 48;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 9)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 9 --  Invalid");
       
    }

    ////FAPI_INF("Inside strcmp r10");
    l_sbit = 42;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 10)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 10 --  Invalid");
        
    }

    ////FAPI_INF("Inside strcmp r11");
    l_sbit = 36;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 11)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 11 --  Invalid");
       
    }

    ////FAPI_INF("Inside strcmp r12");
    l_sbit = 30;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 12)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 12 --  Invalid");
       
    }

    ////FAPI_INF("Inside strcmp r13");
    l_sbit = 24;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 13)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 13 --  Invalid");
       
    }

    ////FAPI_INF("Inside strcmp r14");
    l_sbit = 18;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 14)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    ////FAPI_INF("Value of i = %d",i);
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 14 --  Invalid");
       
    }

    ////FAPI_INF("Inside strcmp r15");
    l_sbit = 12;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    if (l_num_rows > 15)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    else
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
		
        //FAPI_INF("row 15 --  Invalid");
       
    }
    ////FAPI_INF("Value of i = %d",i);
    ////FAPI_INF("Inside strcmp r16 and l_dram_rows = %d",l_dram_rows);
    l_sbit = 6;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c9, l_data_buffer_64);
    if (rc) return rc;
    if (l_dram_rows >= 17)
    {
        rc_num = l_data_buffer_64.insertFromRight(l_value, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
        i--;
    }
    else
    {
        ////FAPI_INF("r16 not used");
        rc_num = l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        //FAPI_INF("Row 16 Invalid");
        rc = fapiPutScom(i_target_mba, 0x030106c9, l_data_buffer_64);
        if (rc) return rc;
		
       
    }
    ////FAPI_INF("Value of i = %d",i);


    ////FAPI_INF("Inside strcmp sl2");
    l_sbit = 36;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    if(sl2_valid==1)
    {
	  rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);
      if (rc_num)
      {
         FAPI_ERR( "Error in function  parse_addr:");
         rc.setEcmdError(rc_num);
         return rc;
      }
      rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);
	  i--;
    }
    else
    {
        rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);
        if (rc_num)
        {
            FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);
        if(rc) return rc;
        FAPI_DBG("%s:sl2 Invalid",i_target_mba.toEcmdString());
        //FAPI_DBG("%s:Value of i = %d",i);
     }

    ////FAPI_INF("Inside strcmp sl1");
    l_sbit = 30;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    //------- Enable these for later --- for now constant map to zero
    if(sl1_valid==1)
    {

      rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);
      if (rc_num)
      {
         FAPI_ERR( "Error in function  parse_addr:");
         rc.setEcmdError(rc_num);
         return rc;
      }
      rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);
      if(rc) return rc;
	  i--;
    }
    else
    {
        rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);
        if (rc_num)
        {
            FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);
        if(rc) return rc;
        FAPI_DBG("%s:sl1 Invalid",i_target_mba.toEcmdString());
        //FAPI_DBG("%s:Value of i = %d",i);
     }
    FAPI_INF("Inside strcmp sl0");
    l_sbit = 24;
    l_value = i;
    rc = fapiGetScom(i_target_mba, 0x030106c8, l_data_buffer_64);
    if (rc) return rc;
    //------- Enable these for later --- for now constant map to zero
    if(sl0_valid==1)
    {

      rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value,l_sbit ,6);
      if (rc_num)
      {
         FAPI_ERR( "Error in function  parse_addr:");
         rc.setEcmdError(rc_num);
         return rc;
      }
      rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  
      if(rc) return rc;
	  i--;
    }
    else
    {
        rc_num = rc_num| l_data_buffer_64.insertFromRight(l_value_zero,l_sbit ,6);
        if (rc_num)
        {
            FAPI_ERR( "Error in function  parse_addr:");rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba,0x030106c8,l_data_buffer_64);  
        if(rc) return rc;
        FAPI_DBG("%s:sl0 Invalid",i_target_mba.toEcmdString());
        //FAPI_DBG("%s:Value of i = %d",i);
     }



    //------ Setting Start and end addr counters

    FAPI_INF("Debug - --------------- Setting Start and End Counters -----------\n");
    rc_num = l_data_buffer_rd64.flushTo0();
    if (rc_num)
    {
        FAPI_ERR("Error in function  parse_addr:");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_mba, 0x030106d0, l_data_buffer_rd64);
    if (rc) return rc;
    l_value = i+1;
    FAPI_INF("Setting end_addr Value of i = %d",i);
    rc_num = l_data_buffer_rd64.flushTo0();

    //Calculate and set Valid bits for end_addr
    for (i = l_value; i <= 37; i++)
    {
        rc_num |= l_data_buffer_rd64.clearBit(i);
        rc_num |= l_data_buffer_rd64.setBit(i);
    }
    if (rc_num)
    {
        FAPI_ERR("Error in function  parse_addr:");
        rc.setEcmdError(rc_num);
        return rc;
    }

    l_readscom_value = l_data_buffer_rd64.getDoubleWord(0);

    rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_ADDR_MODE, &i_target_mba, l_attr_addr_mode);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MCBIST_START_ADDR, &i_target_mba, l_start_addr);
    if (rc) return rc;
    //FAPI_INF("User Defined ATTR - Start = %016llX",l_start_addr);
    rc = FAPI_ATTR_GET(ATTR_MCBIST_END_ADDR, &i_target_mba, l_end);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MCBIST_RANK, &i_target_mba, l_user_end_addr);
    if (rc) return rc;

    if (l_user_end_addr == 1)
    {
        //Setting start and end Temp
        rc_num = l_data_buffer_rd64.setDoubleWord(0, l_start_addr);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106d0, l_data_buffer_rd64);
        if (rc) return rc;
        rc = fapiPutScom(i_target_mba, 0x030106d1, l_data_buffer_rd64);
        if (rc) return rc;

        rc_num = l_data_buffer_rd64.setDoubleWord(0, l_end);
        if (rc_num)
        {
            FAPI_ERR("Error in function  parse_addr:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiPutScom(i_target_mba, 0x030106d2, l_data_buffer_rd64);
        if (rc) return rc;
        rc = fapiPutScom(i_target_mba, 0x030106d3, l_data_buffer_rd64);
        if (rc) return rc;
    }

    else
    {
        if (l_attr_addr_mode == 0)
        {
            FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- Few Address Mode --------",l_attr_addr_mode);
            l_sbit = 32;
            rc_num = l_data_buffer_rd64.flushTo0();
            l_start = 24;
            l_len = 8;
            l_value32 = 28;
            rc_num |= l_data_buffer_rd64.insert(l_value32, l_sbit, l_len,  l_start);
            l_readscom_value = 0x000003FFF8000000ull;
            rc_num |= l_data_buffer_rd64.setDoubleWord(0, l_readscom_value);
            if (rc_num)
            {
                FAPI_ERR("Error in function  parse_addr:");
                rc.setEcmdError(rc_num);
                return rc;
            }

            rc = fapiPutScom(i_target_mba, 0x030106d2, l_data_buffer_rd64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, 0x030106d3, l_data_buffer_rd64);
            if (rc) return rc;
            l_readscom_value = l_data_buffer_rd64.getDoubleWord(0);
            //FAPI_INF("Debug - Final End addr for 0x030106d2 = %016llX",l_readscom_value);
        }
        else if (l_attr_addr_mode == 1)
        {
            FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- QUARTER ADDRESSING Mode --------",l_attr_addr_mode);
            l_readscom_value = l_readscom_value >> 2;
            FAPI_INF("Debug - Final End addr for 0x030106d2 = %016llX",l_readscom_value);
            rc_num = l_data_buffer_rd64.setDoubleWord(0, l_readscom_value);
            if (rc_num)
            {
                FAPI_ERR("Error in function  parse_addr:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_mba, 0x030106d2, l_data_buffer_rd64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, 0x030106d3, l_data_buffer_rd64);
            if (rc) return rc;
        }
        else if (l_attr_addr_mode == 2)
        {
            FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- HALF ADDRESSING Mode --------",l_attr_addr_mode);
            l_readscom_value = l_readscom_value >> 1;
            FAPI_INF("Debug - Final End addr for 0x030106d2 = %016llX",l_readscom_value);
            rc_num = l_data_buffer_rd64.setDoubleWord(0, l_readscom_value);
            if (rc_num)
            {
                FAPI_ERR("Error in function  parse_addr:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_mba, 0x030106d2, l_data_buffer_rd64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, 0x030106d3, l_data_buffer_rd64);
            if (rc) return rc;
        }
        else
        {
            FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- FULL Address Mode --------",l_attr_addr_mode);
            FAPI_INF("Debug - Final End addr for 0x030106d2 = %016llX",l_readscom_value);
            rc = fapiPutScom(i_target_mba, 0x030106d2, l_data_buffer_rd64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, 0x030106d3, l_data_buffer_rd64);
            if (rc) return rc;
        }
    }

    return rc;
}
}
