/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_access_delay_reg.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: mss_access_delay_reg.C,v 1.25 2014/04/18 19:23:36 jdsloat Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_access_delay_reg
// *! OWNER NAME  : Saurabh Chadha     Email: sauchadh@in.ibm.com
// *! ADDITIONAL COMMENTS :
//
// The purpose of this procedure is to give different phase rototor values like RD_DQ, RD_DQS, WR_DQ, WR_DQS 
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.1   | sauchadh |15-Oct-12| First Draft.
//   1.2   | sauchadh |29-Oct-12| Fixed Firmware comments
//   1.3   | sauchadh |29-Oct-12| Fixed error due to rc_num
//   1.4   | sauchadh |29-Oct-12| Fixed error due to rc
//   1.5   | sauchadh |6-Nov-12 | Added RAW modes
//   1.6   | sauchadh |20-Nov-12| Made index to follow ISDIMM net for DQS and added glacier 2 suppport
//   1.7   | sauchadh |30-Nov-12| Glacier 1 and 2 selected based on init file settings
//   1.8   | sauchadh |5-Dec-12 | Fixed firmware comments and added DQS align DQS gate
//   1.9   | sauchadh |14-Dec-12| Fixed Firmware comments
//   1.10  | sauchadh |14-Dec-12| Fixed Firmware comments
//   1.11  | sauchadh |18-Dec-12| Fixed Frimware comments and removed print statements in between
//   1.12  | sauchadh |18-Dec-12| Added support for unused DQS in x8 mode
//   1.13  | sauchadh |7-Jan-12 | Added DQSCLK and RDCLK in phase select register
//   1.14  | sauchadh |8-Jan-12 | Fixed Firmware comments
//   1.15  | sauchadh |20-may-13| Fixed swizzle issue in DQSCLK phase rotators
//   1.16  | sauchadh |12-jun-13| ADDED	 CAC registers for read dqs
//   1.17  | sauchadh |18-Jul-13| Added data bit disable registers
//   1.19  | abhijsau |9-Oct-13 | Added mss_c4_phy() function 
//   1.21  | abhijsau |16-Dec-13| Added function for fw
//   1.22  |sauchadh  |10-Jan-14| changed dimmtype attribute to ATTR_EFF_CUSTOM_DIMM
//   1.23  | mjjones  |17-Jan-14| Fixed layout and error handling for RAS Review
//   1.24  |sauchadh  |24-Jan-14| Added check for unused DQS 
//   1.25  |sauchadh  |18-Apr-14| SW257010: mss_c4_phy: initialized dqs_lane array and verbose flag, used array indexes rather than counter

//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------
#include <mss_access_delay_reg.H>

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>

extern "C" {

//******************************************************************************
//Function name: mss_access_delay_reg()
//Description:This function Read and Write delay values for RD_DQ, WR_DQ, RD_DQS, WR_DQS
//RD_DQ  - Read Delay (DQ) registers
//WR_DQ  - Write delay (DQ) registers
//RD_DQS - DQS_CLK_ALIGN
//WR_DQS - Write delay (DQS)registers
//Input  : Target MBA=i_target_mba, i_access_type_e = READ or WRITE, i_port_u8=0 or 1, i_rank_u8=valid ranks,i_input_type_e=RD_DQ or RD_DQS or WR_DQ or WR_DQS or RAW_modes, i_input_index_u8=follow ISDIMMnet/C4 for non raw modes and supports raw modes, i_verbose-extra print statements   
//Output : delay value=io_value_u32 if i_access_type_e = READ else if i_access_type_e = WRITE no return value
//******************************************************************************
fapi::ReturnCode mss_access_delay_reg(const fapi::Target & i_target_mba,
                                      access_type_t i_access_type_e,
                                      uint8_t i_port_u8,
                                      uint8_t i_rank_u8,
                                      input_type_t i_input_type_e,
                                      uint8_t i_input_index_u8,
                                      uint8_t i_verbose,
                                      uint32_t &io_value_u32)
{
   // Reference variables for Error FFDC
   const fapi::Target & MBA_TARGET = i_target_mba;
   const access_type_t & ACCESS_TYPE_PARAM = i_access_type_e;
   const uint8_t & PORT_PARAM = i_port_u8;
   const uint8_t & RANK_PARAM = i_rank_u8;
   const input_type_t & TYPE_PARAM = i_input_type_e;
   const uint8_t & INDEX_PARAM = i_input_index_u8;

   fapi::ReturnCode rc; 
    
   const uint8_t max_rp=8; 
   uint8_t l_val=0;
   uint8_t l_dram_width=0;
   scom_location l_out;
   uint64_t l_scom_add=0x0ull;
   uint32_t l_sbit=0;
   uint32_t l_len=0;
   uint32_t rc_num=0;
   ecmdDataBufferBase data_buffer_64(64);
   ecmdDataBufferBase out(16);
   uint32_t l_output=0;
   uint32_t l_start=0;
   uint8_t l_rank_pair=9;
   uint8_t l_rankpair_table[max_rp]={255};
   uint8_t l_dimmtype=0;
   uint8_t l_block=0;
   uint8_t l_lane=0;
   uint8_t l_start_bit=0;
   uint8_t l_len8=0;
   input_type l_type;
   uint8_t l_mbapos=0;
   const uint8_t l_ISDIMM_dqmax=71;
   const uint8_t l_CDIMM_dqmax=79;
   uint8_t l_adr=0;
    const uint8_t addr_max=19;
   const uint8_t cmd_max=3;
   const uint8_t cnt_max=20;
   const uint8_t clk_max=8;
   const uint8_t addr_lanep0[addr_max]={1,5,3,7,10,6,4,10,13,12,9,9,0,0,6,4,1,4,8};
   const uint8_t addr_adrp0[addr_max]={2,1,1,3,1,3,1,3,3,3,2,3,2,3,1,0,3,3,3};
   const uint8_t addr_lanep1[addr_max]={7,10,3,6,8,12,6,1,5,8,2,0,13,4,5,9,6,11,9};
   const uint8_t addr_adrp1[addr_max]={2,1,2,2,1,3,1,1,1,3,1,3,2,3,3,0,0,1,3};
   const uint8_t addr_lanep2[addr_max]={8,0,7,1,12,10,1,5,9,5,13,5,4,2,4,9,10,9,0};
   const uint8_t addr_adrp2[addr_max]={2,2,3,0,3,1,2,0,1,3,2,1,0,2,3,3,3,2,1};
   const uint8_t addr_lanep3[addr_max]={6,2,9,9,2,3,4,10,0,5,1,5,4,1,8,11,5,12,1};
   const uint8_t addr_adrp3[addr_max]={3,0,2,3,2,0,3,3,1,2,2,1,0,1,3,3,0,3,0};
   
   const uint8_t cmd_lanep0[cmd_max]={2,11,5};
   const uint8_t cmd_adrp0[cmd_max]={3,1,3};
   const uint8_t cmd_lanep1[cmd_max]={2,10,10};
   const uint8_t cmd_adrp1[cmd_max]={2,3,2};
   const uint8_t cmd_lanep2[cmd_max]={3,11,3};
   const uint8_t cmd_adrp2[cmd_max]={1,3,0};
   const uint8_t cmd_lanep3[cmd_max]={7,10,7};
   const uint8_t cmd_adrp3[cmd_max]={1,1,3};
   
   const uint8_t cnt_lanep0[cnt_max]={0,7,3,1,7,8,8,3,8,6,7,2,2,0,9,1,3,6,9,2};
   const uint8_t cnt_adrp0[cnt_max]={1,0,3,0,2,2,1,2,0,0,1,2,0,0,1,1,0,2,0,1};
   const uint8_t cnt_lanep1[cnt_max]={5,4,0,5,11,9,10,7,1,11,0,4,12,3,6,8,1,4,7,7};
   const uint8_t cnt_adrp1[cnt_max]={2,1,2,0,2,1,0,1,3,0,1,0,2,1,3,0,2,2,3,0};
   const uint8_t cnt_lanep2[cnt_max]={0,4,7,13,11,5,12,2,3,6,11,6,7,1,10,8,8,2,4,1};
   const uint8_t cnt_adrp2[cnt_max]={0,1,1,3,1,2,2,0,2,2,0,1,2,1,0,3,1,1,2,3};
   const uint8_t cnt_lanep3[cnt_max]={0,11,9,8,4,7,0,3,8,6,13,8,7,0,6,6,1,2,9,5};
   const uint8_t cnt_adrp3[cnt_max]={2,1,0,2,1,0,3,2,0,1,3,1,2,0,0,2,3,1,1,3};
   
   const uint8_t clk_lanep0[clk_max]={10,11,11,10,4,5,13,12};
   const uint8_t clk_adrp0[clk_max]={0,0,2,2,2,2,2,2};
   const uint8_t clk_lanep1[clk_max]={3,2,8,9,1,0,3,2};
   const uint8_t clk_adrp1[clk_max]={3,3,2,2,0,0,0,0};
   const uint8_t clk_lanep2[clk_max]={11,10,6,7,2,3,8,9};
   const uint8_t clk_adrp2[clk_max]={2,2,0,0,3,3,0,0};
   const uint8_t clk_lanep3[clk_max]={3,2,13,12,10,11,11,10};
   const uint8_t clk_adrp3[clk_max]={3,3,2,2,0,0,2,2};
   
   
   rc = mss_getrankpair(i_target_mba,i_port_u8,i_rank_u8,&l_rank_pair,l_rankpair_table);   if(rc) return rc;
   
   rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_dimmtype); if(rc) return rc;
   
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, l_dram_width); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbapos);  if(rc) return rc;
   
   if(i_verbose==1)
   {
      FAPI_INF("dimm type=%d",l_dimmtype);
      FAPI_INF("rank pair=%d",l_rank_pair);       
   }
   if(i_port_u8 >1)
   {
      FAPI_ERR("Wrong port specified (%d)", i_port_u8);
      FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
      return rc;
   }

   if (l_mbapos>1)
   {
       FAPI_ERR("Bad position from ATTR_CHIP_UNIT_POS (%d)", l_mbapos);
       const uint8_t & MBA_POS = l_mbapos;
       FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_BAD_MBA_POS);
       return rc;
   }

   if((l_dram_width ==fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4) || (l_dram_width ==fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X8))   // Checking for dram width here so that checking can be skipped in called function
   {
      if(i_verbose==1)
      {
         FAPI_INF("dram width=%d",l_dram_width);
      }
   }
   else
   {
      FAPI_ERR("Bad dram width from ATTR_EFF_DRAM_WIDTH (%d)", l_dram_width);
      const uint8_t & DRAM_WIDTH = l_dram_width;
      FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_BAD_DRAM_WIDTH);
      return rc;
   }
   
   if(i_input_type_e==RD_DQ || i_input_type_e==WR_DQ) 
   {
      if(l_dimmtype==fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
      {
         l_type=CDIMM_DQ;
         
         if(i_input_index_u8>l_CDIMM_dqmax)    
         {
            FAPI_ERR("CDIMM_DQ: Wrong input index specified (%d, max %d)" ,
                     i_input_index_u8, l_CDIMM_dqmax);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
            return rc;
         }
      }
      else
      {
         l_type=ISDIMM_DQ;
         if(i_input_index_u8>l_ISDIMM_dqmax)
         {
            FAPI_ERR("ISDIMM_DQ: Wrong input index specified (%d, max %d)",
                     i_input_index_u8, l_ISDIMM_dqmax);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
            return rc;
         }
      }
      
      rc=rosetta_map(i_target_mba,i_port_u8,l_type,i_input_index_u8,i_verbose,l_val); if(rc) return rc;
      
      if(i_verbose==1)
      {
         FAPI_INF("C4 value is=%d",l_val);
      }   
      rc=cross_coupled(i_target_mba,i_port_u8,l_rank_pair,i_input_type_e,l_val,i_verbose,l_out); if(rc) return rc;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_out.scom_addr);
         FAPI_INF("start bit=%d",l_out.start_bit);
         FAPI_INF("length=%d",l_out.bit_length);
      }   
      l_scom_add=l_out.scom_addr;
      l_sbit=l_out.start_bit;
      l_len=l_out.bit_length;
	 
   }
   
   else if(i_input_type_e==ADDRESS)
   {
      if(i_input_index_u8<=18) // 19 delay values for Address
      {
         if((i_port_u8==0) && (l_mbapos==0))
         {
            l_lane=addr_lanep0[i_input_index_u8];
            l_adr=addr_adrp0[i_input_index_u8];
         }
         else if((i_port_u8==1) && (l_mbapos==0))
         {
            l_lane=addr_lanep1[i_input_index_u8];
            l_adr=addr_adrp1[i_input_index_u8]; 
         }
         else if((i_port_u8==0) && (l_mbapos==1))
         {
            l_lane=addr_lanep2[i_input_index_u8];
            l_adr=addr_adrp2[i_input_index_u8]; 
         }
         else
         {
            l_lane=addr_lanep3[i_input_index_u8];
            l_adr=addr_adrp3[i_input_index_u8]; 
         }
         
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      
      ip_type_t l_input=ADDRESS_t;
      if(i_verbose==1)
      {
         FAPI_INF("ADR=%d",l_adr);
         FAPI_INF("lane=%d",l_lane);
      }
      l_block=l_adr;
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==DATA_DISABLE)
   {
      if(i_input_index_u8<=4) // 5 delay values for data bits disable register
      {
         l_block=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      
      ip_type_t l_input=DATA_DISABLE_t;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
      }
      l_lane=0;
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   
   else if(i_input_type_e==COMMAND)
   {
      if(i_input_index_u8<=2) // 3 delay values for Command
      {
         if((i_port_u8==0) && (l_mbapos==0))
         {
            l_lane=cmd_lanep0[i_input_index_u8];
            l_adr=cmd_adrp0[i_input_index_u8];
         }
         else if((i_port_u8==1) && (l_mbapos==0))
         {
            l_lane=cmd_lanep1[i_input_index_u8];
            l_adr=cmd_adrp1[i_input_index_u8]; 
         }
         else if((i_port_u8==0) && (l_mbapos==1))
         {
            l_lane=cmd_lanep2[i_input_index_u8];
            l_adr=cmd_adrp2[i_input_index_u8]; 
         }
         else
         {
            l_lane=cmd_lanep3[i_input_index_u8];
            l_adr=cmd_adrp3[i_input_index_u8]; 
         }
         
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;      
      }
      
      ip_type_t l_input=COMMAND_t;
      if(i_verbose==1)
      {
         FAPI_INF("ADR=%d",l_adr);
         FAPI_INF("lane=%d",l_lane);
      }
      l_block=l_adr;
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }   
   
    else if(i_input_type_e==CONTROL)
   {
      if(i_input_index_u8<=19) // 20 delay values for Control
      {
         if((i_port_u8==0) && (l_mbapos==0))
         {
            l_lane=cnt_lanep0[i_input_index_u8];
            l_adr=cnt_adrp0[i_input_index_u8];
         }
         else if((i_port_u8==1) && (l_mbapos==0))
         {
            l_lane=cnt_lanep1[i_input_index_u8];
            l_adr=cnt_adrp1[i_input_index_u8]; 
         }
         else if((i_port_u8==0) && (l_mbapos==1))
         {
            l_lane=cnt_lanep2[i_input_index_u8];
            l_adr=cnt_adrp2[i_input_index_u8]; 
         }
         else
         {
            l_lane=cnt_lanep3[i_input_index_u8];
            l_adr=cnt_adrp3[i_input_index_u8]; 
         }
         
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;      
      }
      
      ip_type_t l_input=CONTROL_t;
      if(i_verbose==1)
      {
         FAPI_INF("ADR=%d",l_adr);
         FAPI_INF("lane=%d",l_lane);
      }
      l_block=l_adr;
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==CLOCK)
   {
      if(i_input_index_u8<=7) // 8 delay values for CLK
      {
         if((i_port_u8==0) && (l_mbapos==0))
         {
            l_lane=clk_lanep0[i_input_index_u8];
            l_adr=clk_adrp0[i_input_index_u8];
         }
         else if((i_port_u8==1) && (l_mbapos==0))
         {
            l_lane=clk_lanep1[i_input_index_u8];
            l_adr=clk_adrp1[i_input_index_u8]; 
         }
         else if((i_port_u8==0) && (l_mbapos==1))
         {
            l_lane=clk_lanep2[i_input_index_u8];
            l_adr=clk_adrp2[i_input_index_u8]; 
         }
         else
         {
            l_lane=clk_lanep3[i_input_index_u8];
            l_adr=clk_adrp3[i_input_index_u8]; 
         }
         
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;      
      }
      
      ip_type_t l_input=CLOCK_t;
      if(i_verbose==1)
      {
         FAPI_INF("ADR=%d",l_adr);
         FAPI_INF("lane=%d",l_lane);
      }
      l_block=l_adr;
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }   
   
    
   else if (i_input_type_e==RD_DQS || i_input_type_e==WR_DQS || i_input_type_e==DQS_ALIGN ||  i_input_type_e==DQS_GATE || i_input_type_e==RDCLK || i_input_type_e==DQSCLK)	    
   {
     
      if(l_dimmtype==fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
      {
         l_type=CDIMM_DQS;
      }
      else
      {
         l_type=ISDIMM_DQS;
      }
      
      rc=rosetta_map(i_target_mba,i_port_u8,l_type,i_input_index_u8,i_verbose,l_val); if(rc) return rc;
      if(i_verbose==1)
      {
         FAPI_INF("C4 value is=%d",l_val);
      }
      rc=cross_coupled(i_target_mba,i_port_u8,l_rank_pair,i_input_type_e,l_val,i_verbose,l_out); if(rc) return rc;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_out.scom_addr);
         FAPI_INF("start bit=%d",l_out.start_bit);
         FAPI_INF("length=%d",l_out.bit_length); 
      }
      l_scom_add=l_out.scom_addr;
      l_sbit=l_out.start_bit;
      l_len=l_out.bit_length;   
         
   }
   
   
   else if(i_input_type_e==RAW_RDCLK_0 || i_input_type_e==RAW_RDCLK_1 || i_input_type_e==RAW_RDCLK_2 || i_input_type_e==RAW_RDCLK_3 || i_input_type_e==RAW_RDCLK_4) 
   {
      if(i_input_type_e==RAW_RDCLK_0)
      {
         l_block=0;
      }
      
      else if(i_input_type_e==RAW_RDCLK_1)
      {
         l_block=1;
      }
      
      else if(i_input_type_e==RAW_RDCLK_2)
      {
         l_block=2;
      }
      
      else if(i_input_type_e==RAW_RDCLK_3)
      {
         l_block=3;
      }
      
      else
      {
         l_block=4;
      }
      if(i_input_index_u8<=3) // 4 delay values for RDCLK 
      {
         l_lane=i_input_index_u8;
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;      
      }
     
      ip_type_t l_input=RAW_RDCLK;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_DQSCLK_0 || i_input_type_e==RAW_DQSCLK_1 || i_input_type_e==RAW_DQSCLK_2 || i_input_type_e==RAW_DQSCLK_3 || i_input_type_e==RAW_DQSCLK_4)
   {
      if(i_input_type_e==RAW_DQSCLK_0)
      {
         l_block=0;
      }
      
      else if(i_input_type_e==RAW_DQSCLK_1)
      {
         l_block=1;
      }
      
      else if(i_input_type_e==RAW_DQSCLK_2)
      {
         l_block=2;
      }
      
      else if(i_input_type_e==RAW_DQSCLK_3)
      {
         l_block=3;
      }
      
      else
      {
         l_block=4;
      }
      if(i_input_index_u8<=3) // 4 delay values for DQSCLK
      {
         l_lane=i_input_index_u8;
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      ip_type_t l_input=RAW_DQSCLK;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
         
   else if(i_input_type_e==RAW_WR_DQ_0 || i_input_type_e==RAW_WR_DQ_1 || i_input_type_e==RAW_WR_DQ_2 || i_input_type_e==RAW_WR_DQ_3 || i_input_type_e==RAW_WR_DQ_4)
   {
      if(i_input_type_e==RAW_WR_DQ_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_WR_DQ_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_WR_DQ_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_WR_DQ_3)
      {
         l_block=3;
      }
      else
      {
         l_block=4;
      }
      if(i_input_index_u8<=15) // 16 Write delay values for DQ bits
      {
         l_lane=i_input_index_u8;
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
     
      ip_type_t l_input=RAW_WR_DQ;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_RD_DQ_0 || i_input_type_e==RAW_RD_DQ_1 || i_input_type_e==RAW_RD_DQ_2 || i_input_type_e==RAW_RD_DQ_3 || i_input_type_e==RAW_RD_DQ_4)
   {
      if(i_input_type_e==RAW_RD_DQ_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_RD_DQ_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_RD_DQ_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_RD_DQ_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      }
      if(i_input_index_u8<=15)   // 16 read delay values for DQ bits
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      ip_type_t l_input=RAW_RD_DQ;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_RD_DQS_0 || i_input_type_e==RAW_RD_DQS_1 || i_input_type_e==RAW_RD_DQS_2 || i_input_type_e==RAW_RD_DQS_3 || i_input_type_e==RAW_RD_DQS_4)
   {
      if(i_input_type_e==RAW_RD_DQS_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_RD_DQS_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_RD_DQS_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_RD_DQS_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      }
      if(i_input_index_u8<=3) // 4 Read DQS delay values 
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      
      ip_type_t l_input=RAW_RD_DQS;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_DQS_ALIGN_0 || i_input_type_e==RAW_DQS_ALIGN_1 || i_input_type_e==RAW_DQS_ALIGN_2 || i_input_type_e==RAW_DQS_ALIGN_3 || i_input_type_e==RAW_DQS_ALIGN_4)
   {
      if(i_input_type_e==RAW_DQS_ALIGN_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_DQS_ALIGN_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_DQS_ALIGN_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_DQS_ALIGN_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      }
      if(i_input_index_u8<=3)     // 4 DQS alignment delay values
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      ip_type_t l_input=RAW_DQS_ALIGN;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   
   else if(i_input_type_e==RAW_WR_DQS_0 || i_input_type_e==RAW_WR_DQS_1 || i_input_type_e==RAW_WR_DQS_2 || i_input_type_e==RAW_WR_DQS_3 || i_input_type_e==RAW_WR_DQS_4)
   {
      if(i_input_type_e==RAW_WR_DQS_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_WR_DQS_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_WR_DQS_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_WR_DQS_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      }
      if(i_input_index_u8<=3)      // 4 Write DQS delay values
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      ip_type_t l_input=RAW_WR_DQS;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   else if(i_input_type_e==RAW_SYS_CLK_0 || i_input_type_e==RAW_SYS_CLK_1 || i_input_type_e==RAW_SYS_CLK_2 || i_input_type_e==RAW_SYS_CLK_3 || i_input_type_e==RAW_SYS_CLK_4)
   {
      if(i_input_type_e==RAW_SYS_CLK_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_SYS_CLK_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_SYS_CLK_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_SYS_CLK_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      } 
      if(i_input_index_u8==0) // 1 system clock delay value
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      ip_type_t l_input=RAW_SYS_CLK;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_SYS_ADDR_CLK)
   {
      if(i_input_index_u8<=1)   // 1 system address clock delay value
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      ip_type_t l_input=RAW_SYS_ADDR_CLKS0S1;
      if(i_verbose==1)
      {
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   
   else if(i_input_type_e==RAW_WR_CLK_0 || i_input_type_e==RAW_WR_CLK_1 || i_input_type_e==RAW_WR_CLK_2 || i_input_type_e==RAW_WR_CLK_3 || i_input_type_e==RAW_WR_CLK_4)
   {
      if(i_input_type_e==RAW_WR_CLK_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_WR_CLK_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_WR_CLK_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_WR_CLK_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      } 
      if(i_input_index_u8==0)           //  1 Write clock delay value
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      ip_type_t l_input=RAW_WR_CLK;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_ADDR_0 || i_input_type_e==RAW_ADDR_1 || i_input_type_e==RAW_ADDR_2 || i_input_type_e==RAW_ADDR_3)
   {
      if(i_input_type_e==RAW_ADDR_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_ADDR_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_ADDR_2)
      {
         l_block=2;
      }
      else 
      {
         l_block=3;
      }
      if(i_input_index_u8<=15)      //  16 Addr delay values
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      ip_type_t l_input=RAW_ADDR;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
  
   else if(i_input_type_e==RAW_DQS_GATE_0 || i_input_type_e==RAW_DQS_GATE_1 || i_input_type_e==RAW_DQS_GATE_2 || i_input_type_e==RAW_DQS_GATE_3 || i_input_type_e==RAW_DQS_GATE_4)
   {
      if(i_input_type_e==RAW_DQS_GATE_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_DQS_GATE_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_DQS_GATE_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_DQS_GATE_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      }
              
      if(i_input_index_u8<=3)     // 4 Gate Delay values
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc; 
      }
      ip_type_t l_input=RAW_DQS_GATE;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   } 
   
   else
   {
      FAPI_ERR("Wrong input type specified (%d)", i_input_type_e);
      FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
      return rc;
   } 
     
   if(i_access_type_e==READ)   
   {
      rc=fapiGetScom(i_target_mba,l_scom_add,data_buffer_64);if(rc) return rc;
      rc_num= rc_num | data_buffer_64.extractToRight(&l_output,l_sbit,l_len);
      if(rc_num)
      {
        FAPI_ERR( "ecmd error on l_scom_add extract");       
	rc.setEcmdError(rc_num);
        return rc;
      }    
      io_value_u32=l_output;
     // FAPI_INF("Delay value=%d",io_value_u32);
   }
   
   else if(i_access_type_e==WRITE)
   {
      
      if(i_input_type_e==RD_DQ || i_input_type_e==RD_DQS || i_input_type_e==RAW_RD_DQ_0 || i_input_type_e==RAW_RD_DQ_1 || i_input_type_e==RAW_RD_DQ_2 || i_input_type_e==RAW_RD_DQ_3 || i_input_type_e==RAW_RD_DQ_4 || i_input_type_e==RAW_RD_DQS_0 || i_input_type_e==RAW_RD_DQS_1 || i_input_type_e==RAW_RD_DQS_2 || i_input_type_e==RAW_RD_DQS_3 || i_input_type_e==RAW_RD_DQS_4
      || i_input_type_e==RAW_SYS_ADDR_CLK || i_input_type_e==RAW_SYS_CLK_0 || i_input_type_e==RAW_SYS_CLK_1 || i_input_type_e==RAW_SYS_CLK_2 || i_input_type_e==RAW_SYS_CLK_3 || i_input_type_e==RAW_SYS_CLK_4 || i_input_type_e==RAW_WR_CLK_0 || i_input_type_e==RAW_WR_CLK_1 || i_input_type_e==RAW_WR_CLK_2 || i_input_type_e==RAW_WR_CLK_3 || i_input_type_e==RAW_WR_CLK_4
      || i_input_type_e==RAW_ADDR_0 || i_input_type_e==RAW_ADDR_1 || i_input_type_e==RAW_ADDR_2 || i_input_type_e==RAW_ADDR_3 || i_input_type_e==RAW_DQS_ALIGN_0 || i_input_type_e==RAW_DQS_ALIGN_1 || i_input_type_e==RAW_DQS_ALIGN_2 || i_input_type_e==RAW_DQS_ALIGN_3 || i_input_type_e==RAW_DQS_ALIGN_4
      || i_input_type_e==DQS_ALIGN || i_input_type_e==COMMAND || i_input_type_e==ADDRESS || i_input_type_e==CONTROL || i_input_type_e==CLOCK )   
      {
         l_start=25;   // l_start is starting bit of delay value in the register. There are different registers and each register has a different field for delay
      }
      else if(i_input_type_e==WR_DQ || i_input_type_e==WR_DQS || i_input_type_e==RAW_WR_DQ_0 || i_input_type_e==RAW_WR_DQ_1 || i_input_type_e==RAW_WR_DQ_2 || i_input_type_e==RAW_WR_DQ_3 || i_input_type_e==RAW_WR_DQ_4 || i_input_type_e==RAW_WR_DQS_0 || i_input_type_e==RAW_WR_DQS_1 || i_input_type_e==RAW_WR_DQS_2 || i_input_type_e==RAW_WR_DQS_3 || i_input_type_e==RAW_WR_DQS_4 )
      {
         l_start=22;
      }
   
      else if(i_input_type_e==RAW_DQS_GATE_0 || i_input_type_e==RAW_DQS_GATE_1 || i_input_type_e==RAW_DQS_GATE_2 || i_input_type_e==RAW_DQS_GATE_3 || i_input_type_e==RAW_DQS_GATE_4 || i_input_type_e==DQS_GATE)
      {
         l_start=29;
      }
      
      else if(i_input_type_e==RAW_RDCLK_0 || i_input_type_e==RAW_RDCLK_1 || i_input_type_e==RAW_RDCLK_2 || i_input_type_e==RAW_RDCLK_3 || i_input_type_e==RAW_RDCLK_4 || i_input_type_e==RDCLK || i_input_type_e==RAW_DQSCLK_0 || i_input_type_e==RAW_DQSCLK_1 || i_input_type_e==RAW_DQSCLK_2 || i_input_type_e==RAW_DQSCLK_3 || i_input_type_e==RAW_DQSCLK_4 || i_input_type_e==DQSCLK)
      {
         l_start=30;  
      }
      
      else if(i_input_type_e==DATA_DISABLE)
      {
         l_start=16;
      }
      
      else
      {
         FAPI_ERR("Wrong input type specified (%d)", i_input_type_e);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_INVALID_INPUT);
         return rc;
      }
      if(i_verbose==1)
      {
         FAPI_INF("value given=%d",io_value_u32);
      }
      
      rc=fapiGetScom(i_target_mba,l_scom_add,data_buffer_64);if(rc) return rc;	  
      rc_num=data_buffer_64.insert(io_value_u32,l_sbit,l_len,l_start);
      if(rc_num)
      {
        FAPI_ERR( "ecmd error on l_scom_add extract");       
	rc.setEcmdError(rc_num);
        return rc;
      }    
      rc=fapiPutScom(i_target_mba,l_scom_add,data_buffer_64); if(rc) return rc;
   }
   return rc;
}

//******************************************************************************
//Function name: cross_coupled()
//Description:This function returns address,start bit and bit length for RD_DQ, WR_DQ, RD_DQS, WR_DQS
//Input  : Target MBA=i_target_mba, i_port_u8=0 or 1, i_rank_pair=0 or 1 or 2 or 3, i_input_type_e=RD_DQ or RD_DQS or WR_DQ or WR_DQS,i_input_index_u8=0-79/0-71/0-8/0-19 , i_verbose-extra print statements  
//Output : out (address,start bit and bit length)
//******************************************************************************    
fapi::ReturnCode cross_coupled(const fapi::Target & i_target_mba,
                               uint8_t i_port,
                               uint8_t i_rank_pair,
                               input_type_t i_input_type_e,
                               uint8_t i_input_index,
                               uint8_t i_verbose,
                               scom_location& out)
{    
   fapi::ReturnCode rc; 
   const uint8_t l_dqmax=80;
   const uint8_t l_dqsmax=20;
   const uint8_t l_dqs=4;
   const uint8_t lane_dq_p0[l_dqmax]={4,6,5,7,2,1,3,0,13,15,12,14,8,9,11,10,13,15,12,14,9,8,11,10,13,15,12,14,11,9,10,8,11,8,9,10,12,13,14,15,7,6,5,4,1,3,2,0,5,6,4,7,3,1,2,0,7,4,5,6,2,0,3,1,3,0,1,2,6,5,4,7,11,8,9,10,15,13,12,14}; 
   const uint8_t lane_dq_p1[l_dqmax]={9,11,8,10,13,14,15,12,10,8,11,9,12,13,14,15,1,0,2,3,4,5,6,7,9,11,10,8,15,12,13,14,5,7,6,4,1,0,2,3,0,2,1,3,5,4,6,7,0,2,3,1,4,5,6,7,12,15,13,14,11,8,10,9,5,7,4,6,3,2,0,1,14,12,15,13,9,8,11,10}; 
   const uint8_t lane_dq_p2[l_dqmax]={13,15,12,14,11,9,10,8,13,12,14,15,10,9,11,8,5,6,7,4,2,3,0,1,10,9,8,11,13,12,15,14,15,12,13,14,11,10,9,8,7,6,4,5,1,0,3,2,0,2,1,3,5,6,4,7,5,7,6,4,1,0,2,3,1,2,3,0,7,6,5,4,9,10,8,11,12,15,14,13};
   const uint8_t lane_dq_p3[l_dqmax]={4,5,6,7,0,1,3,2,12,13,15,14,8,9,10,11,10,8,11,9,12,13,15,14,3,0,1,2,4,6,7,5,9,10,11,8,14,13,15,12,7,5,6,4,3,1,2,0,5,6,7,4,1,2,3,0,14,12,15,13,8,10,9,11,0,3,2,1,6,5,7,4,10,11,9,8,12,13,15,14};
   const uint8_t dqs_dq_lane_p0[l_dqsmax]={4,0,12,8,12,8,12,8,8,12,4,0,4,0,4,0,0,4,8,12};
   const uint8_t dqs_dq_lane_p1[l_dqsmax]={8,12,8,12,0,4,8,12,4,0,0,4,0,4,12,8,4,0,12,8};
   const uint8_t dqs_dq_lane_p2[l_dqsmax]={12,8,12,8,4,0,8,12,12,8,4,0,0,4,4,0,0,4,8,12};
   const uint8_t dqs_dq_lane_p3[l_dqsmax]={4,0,12,8,8,12,0,4,8,12,4,0,4,0,12,8,0,4,8,12};
   const uint8_t block_p1[l_dqmax]={0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2};
   const uint8_t block_p0[l_dqmax]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
   const uint8_t block_p2[l_dqmax]={1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,4,4,4,4,4,4,4,4};
   const uint8_t block_p3[l_dqmax]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
   const uint8_t block_dqs_p0[l_dqsmax]={2,2,2,2,0,0,3,3,4,4,3,3,4,4,1,1,0,0,1,1};
   const uint8_t block_dqs_p1[l_dqsmax]={0,0,3,3,0,0,1,1,2,2,3,3,4,4,4,4,1,1,2,2};
   const uint8_t block_dqs_p2[l_dqsmax]={1,1,3,3,0,0,0,0,2,2,2,2,3,3,4,4,1,1,4,4};
   const uint8_t block_dqs_p3[l_dqsmax]={2,2,2,2,0,0,0,0,3,3,3,3,4,4,4,4,1,1,1,1};
   const uint8_t dqslane[l_dqs]={16,18,20,22};
   uint8_t l_j=0;
   uint8_t l_flag=0; 
   uint8_t l_mbapos = 0;
   uint8_t l_dram_width=0;
   uint8_t l_lane=0;
   const uint8_t & INVALID_DQS =l_lane;
   uint8_t l_block=0;
   uint8_t lane_dqs[4];
   uint8_t l_index=0;
   uint8_t l_dq=0;
   uint64_t l_scom_address_64=0x0ull;
   uint8_t l_start_bit=0;
   uint8_t l_len=0;
   ip_type_t l_input_type;
   ecmdDataBufferBase data_buffer_64(64);
   uint8_t l_dimmtype=0;
   uint8_t l_swizzle=0;
      
   rc = FAPI_ATTR_GET(ATTR_MSS_DQS_SWIZZLE_TYPE, &i_target_mba, l_swizzle); if(rc) return rc;
      
   rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbapos); if(rc) return rc;
   
   rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_dimmtype); if(rc) return rc;
         
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, l_dram_width); if(rc) return rc;
   
      
   if(i_input_type_e==RD_DQ || i_input_type_e==WR_DQ)
   {
      if(i_port==0 && l_mbapos==0)
      {
         l_lane=lane_dq_p0[i_input_index];
	 l_block=block_p0[i_input_index];	    
      }
      else if(i_port==1 && l_mbapos==0)
      {
         l_lane=lane_dq_p1[i_input_index];
         l_block=block_p1[i_input_index];	    
      } 
      else if(i_port==0 && l_mbapos==1)
      {
         l_lane=lane_dq_p2[i_input_index];
         l_block=block_p2[i_input_index];	
      }
      else
      {
	 l_lane=lane_dq_p3[i_input_index];
	 l_block=block_p3[i_input_index];	
      }
      
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      } 
      if(i_input_type_e==RD_DQ)
      {
         l_input_type=RD_DQ_t;
      }
      else 	
      {
         l_input_type=WR_DQ_t;    
      }
      
            
      rc=get_address(i_target_mba,i_port,i_rank_pair,l_input_type,l_block,l_lane,l_scom_address_64,l_start_bit,l_len); if(rc) return rc; 		 
      out.scom_addr=l_scom_address_64;
      out.start_bit=l_start_bit;
      out.bit_length=l_len; 
   }
   
   else if (i_input_type_e==WR_DQS ||  i_input_type_e==DQS_ALIGN)	    
   {
      if(i_port==0 && l_mbapos==0)
      {
         l_dq=dqs_dq_lane_p0[i_input_index];
         l_block=block_dqs_p0[i_input_index]; 
      }
             
      else if(i_port==1 && l_mbapos==0)
      {
         l_dq=dqs_dq_lane_p1[i_input_index];   
         l_block=block_dqs_p1[i_input_index]; 
      }   
      else if(i_port==0 && l_mbapos==1)
      {
         l_dq=dqs_dq_lane_p2[i_input_index];   
         l_block=block_dqs_p2[i_input_index]; 
      }
      else 
      {
         l_dq=dqs_dq_lane_p3[i_input_index];   
         l_block=block_dqs_p3[i_input_index]; 
      }
       
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("dqs_dq_lane=%d",l_dq);
      }
      l_input_type=RD_CLK_t; 
      rc=get_address(i_target_mba,i_port,i_rank_pair, l_input_type,l_block,l_lane,l_scom_address_64,l_start_bit,l_len); if(rc) return rc;
      if(i_verbose==1)
      {
         FAPI_INF("read clock address=%llx",l_scom_address_64);
      }
      rc=fapiGetScom(i_target_mba,l_scom_address_64,data_buffer_64);if(rc) return rc; 
            
      if(l_dram_width==fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4)
      {
         
         if (data_buffer_64.isBitSet(48))
         {
            lane_dqs[l_index]=16;
            l_index++;
         }
         else if(data_buffer_64.isBitSet(52))
         { 
            lane_dqs[l_index]=18;
            l_index++;
         }
        
         if (data_buffer_64.isBitSet(49))
         {
            lane_dqs[l_index]=16;
            l_index++;
         }
     
         else if (data_buffer_64.isBitSet(53))
         {
            lane_dqs[l_index]=18;
            l_index++;
         }
         
         if (data_buffer_64.isBitSet(54))
         {
            lane_dqs[l_index]=20;
            l_index++;
         }
         else if (data_buffer_64.isBitSet(56))
         {
            lane_dqs[l_index]=22;
            l_index++;
         }
      
         if (data_buffer_64.isBitSet(55))
         {
            lane_dqs[l_index]=20;
            l_index++;
         }
         else if (data_buffer_64.isBitSet(57))   // else is not possible as one of them will definitely get set
         {
            lane_dqs[l_index]=22;
            l_index++;
         }
         if(i_verbose==1)
         {
            FAPI_INF("array is=%d and %d and %d and %d",lane_dqs[0],lane_dqs[1],lane_dqs[2],lane_dqs[3]);
         }   
         if(l_dq==0)
         {
            l_lane=lane_dqs[0];
         }
         else if(l_dq==4)
         {
            l_lane=lane_dqs[1];
         }  
         else if(l_dq==8)
         {
            l_lane=lane_dqs[2];
         }
         else 
         {
            l_lane=lane_dqs[3];
         }
         
         if(i_verbose==1)
         {
            FAPI_INF("lane is=%d",l_lane); 
         }
      }			  
   
     
      else
      {   
         if (data_buffer_64.isBitSet(48)&& data_buffer_64.isBitSet(49))
         {		  
            lane_dqs[l_index]=16;
            l_index++; 		    
         }
         else if (data_buffer_64.isBitSet(52)&& data_buffer_64.isBitSet(53))
         {		  
            lane_dqs[l_index]=18;
            l_index++; 		    
         }
         if (data_buffer_64.isBitSet(54)&& data_buffer_64.isBitSet(55))
         {		  
            lane_dqs[l_index]=20;
            l_index++; 		    
         }
         else if (data_buffer_64.isBitSet(56)&& data_buffer_64.isBitSet(57))   // else is not possible as one of them will definitely get set
         {		  
            lane_dqs[l_index]=22;
            l_index++; 		    
         }
         if(i_verbose==1)
         {
            FAPI_INF("array is=%d and %d",lane_dqs[0],lane_dqs[1]); 
         } 
         if((l_dq==0) || (l_dq==4))
         {
            l_lane=lane_dqs[0];
         }
         else 
         {
            l_lane=lane_dqs[1];
         }
         
         if(l_dimmtype==fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
         {
            if((i_input_index==1) || (i_input_index==3) || (i_input_index==5) || (i_input_index==7) || (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) || (i_input_index==17) || (i_input_index==19))
            {
               if(l_lane==16)
               {
                  l_lane=18;
               }
               else if(l_lane==18)
               {
                  l_lane=16;
               }
               
               else if(l_lane==20)
               {
                  l_lane=22;
               }
               
               else
               {
                  l_lane=20;
               }
               
            }
         }
         
         else
         {
            if((i_port==0) && (l_mbapos==0))
            {
               if(l_swizzle==1)
               {
                  if((i_input_index==3) || (i_input_index==1) || (i_input_index==4) || (i_input_index==17)|| (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) ||  (i_input_index==6))
                  {
                     if(l_lane==16)
                     {
                        l_lane=18;
                     }
                     else if(l_lane==18)
                     {
                        l_lane=16;
                     }
                     
                     else if(l_lane==20)
                     {
                        l_lane=22;
                     }
                     
                     else
                     {
                        l_lane=20;
                     }
                  
                  }   
               }
                           
               else
               {
                  if((i_input_index==3) || (i_input_index==1) || (i_input_index==5) || (i_input_index==7)|| (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) ||  (i_input_index==17))
                  {
                     if(l_lane==16)
                     {
                        l_lane=18;
                     }
                     else if(l_lane==18)
                     {
                        l_lane=16;
                     }
                       
                     else if(l_lane==20)
                     {
                        l_lane=22;
                     }
                       
                     else
                     {
                        l_lane=20;
                     }
                  }   
                          
               }
            }   
            
            else if((i_port==1) && (l_mbapos==0))
            {
               if(l_swizzle==1)
               {
                  if((i_input_index==2) || (i_input_index==0) || (i_input_index==4) || (i_input_index==17)|| (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) ||  (i_input_index==7))
                  {
                     if(l_lane==16)
                     {
                        l_lane=18;
                     }
                     else if(l_lane==18)
                     {
                        l_lane=16;
                     }
                     
                     else if(l_lane==20)
                     {
                        l_lane=22;
                     }
                  
                     else
                     {
                        l_lane=20;
                     }
                  }   
               }
               
               else
               {
                  if((i_input_index==1) || (i_input_index==3) || (i_input_index==5) || (i_input_index==7)|| (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) ||  (i_input_index==17))
                  {
                     if(l_lane==16)
                     {
                        l_lane=18;
                     }
                     else if(l_lane==18)
                     {
                        l_lane=16;
                     }
                     
                     else if(l_lane==20)
                     {
                        l_lane=22;
                     }
                  
                     else
                     {
                        l_lane=20;
                     }
                  }   
               }
            }
                  
                  
            else
            {
               if((i_input_index==1) || (i_input_index==3) || (i_input_index==5) || (i_input_index==7)|| (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) ||  (i_input_index==17))
               {
                  if(l_lane==16)
                  {
                     l_lane=18;
                  }
                  else if(l_lane==18)
                  {
                     l_lane=16;
                  }
                  
                  else if(l_lane==20)
                  {
                     l_lane=22;
                  }
                  
                  else
                  {
                     l_lane=20;
                  }
               
               }   
            }
            
            
            
         }
         if(i_verbose==1)
         {
            FAPI_INF("lane is=%d",l_lane);
         }   
      }
      
      if(i_input_type_e==WR_DQS)	  		  
      {
         l_input_type=WR_DQS_t;  
      }
      else
      {
         l_input_type=DQS_ALIGN_t;
      }
      
      
      for(l_j=0;l_j<4;l_j++)
      {
         if(l_lane==dqslane[l_j])
         {
            l_flag=1;
            break;
         }
         
      }
      if(l_flag==0)
      {
        FAPI_ERR("Invalid DQS and DQS lane=%d",l_lane);
        FAPI_SET_HWP_ERROR(rc, RC_CROSS_COUPLED_INVALID_DQS);
        return rc; 
      }
      
      
      rc=get_address(i_target_mba,i_port,i_rank_pair,l_input_type,l_block,l_lane,l_scom_address_64,l_start_bit,l_len); if(rc) return rc; 		 
      out.scom_addr=l_scom_address_64;
      out.start_bit=l_start_bit;
      out.bit_length=l_len; 
   }   
      
    
   else if (i_input_type_e==RD_DQS || i_input_type_e==DQS_GATE || i_input_type_e==RDCLK || i_input_type_e==DQSCLK)	    
   {
      
      
      if(i_port==0 && l_mbapos==0)
      {
         l_dq=dqs_dq_lane_p0[i_input_index];
         l_block=block_dqs_p0[i_input_index]; 
      }
             
      else if(i_port==1 && l_mbapos==0)
      {
         l_dq=dqs_dq_lane_p1[i_input_index];   
         l_block=block_dqs_p1[i_input_index]; 
      }   
      else if(i_port==0 && l_mbapos==1)
      {
         l_dq=dqs_dq_lane_p2[i_input_index];   
         l_block=block_dqs_p2[i_input_index]; 
      }
      else
      {
         l_dq=dqs_dq_lane_p3[i_input_index];   
         l_block=block_dqs_p3[i_input_index]; 
      }
      
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("dqs_dq_lane=%d",l_dq);
      }   
      if(l_dq==0)
      {
         l_lane=16;
      }
         
      else if(l_dq==4)
      {
         l_lane=18;
      }
         
      else if (l_dq==8)
      {
         l_lane=20;
      }
         
      else
      {
         l_lane=22;
      }
      //FAPI_INF("here");
      
      if (i_input_type_e==DQS_GATE)
      {
         l_input_type=DQS_GATE_t;
      }
      
      else if(i_input_type_e==RDCLK)
      {
         l_input_type=RDCLK_t;
      }
      
      else if(i_input_type_e==RD_DQS)
      {
         l_input_type=RD_DQS_t;
      }
      
      else
      {
         l_input_type=DQSCLK_t;
      }
      
      if(i_verbose==1)
      {
         FAPI_INF("lane is=%d",l_lane);
      }
      
      rc=get_address(i_target_mba,i_port,i_rank_pair,l_input_type,l_block,l_lane,l_scom_address_64,l_start_bit,l_len); if(rc) return rc; 		 
      out.scom_addr=l_scom_address_64;
      out.start_bit=l_start_bit;
      out.bit_length=l_len; 
   }
   
   else
   {
      FAPI_ERR("Wrong input type specified (%d)", i_input_type_e);
      const input_type_t & TYPE_PARAM = i_input_type_e;
      FAPI_SET_HWP_ERROR(rc, RC_CROSS_COUPLED_INVALID_INPUT);
      return rc;
   }  

   return rc; 
}


//******************************************************************************
//Function name: rosetta_map()
//Description:This function returns C4 bit for the corresponding ISDIMM bit
//Input  : Target MBA=i_target_mba, i_port_u8=0 or 1,i_input_type_e=RD_DQ or RD_DQS or WR_DQ or WR_DQS, i_input_index_u8=0-79/0-71/0-8/0-19, i_verbose-extra print statements    
//Output : C4 bit=o_value
//****************************************************************************** 
fapi::ReturnCode rosetta_map(const fapi::Target & i_target_mba,
                             uint8_t i_port,
                             input_type i_input_type_e,
                             uint8_t i_input_index,
                             uint8_t i_verbose,
                             uint8_t &o_value) //This function is used by some other procedures
{  // Boundary check is done again
    // Reference variables for Error FFDC
    const fapi::Target & MBA_TARGET = i_target_mba;
    const uint8_t & PORT_PARAM = i_port;
    const input_type & TYPE_PARAM = i_input_type_e;
    const uint8_t & INDEX_PARAM = i_input_index;

    fapi::ReturnCode rc;
   
   const uint8_t l_ISDIMM_dqmax=71; 
   const uint8_t l_CDIMM_dqmax=79;
   uint8_t l_mbapos = 0;
   uint8_t l_dimmtype=0;
   const uint8_t l_maxdq=72;
   const uint8_t l_maxdqs=18;
   uint8_t l_swizzle=0;
   const uint8_t GL_DQ_p0_g1[l_maxdq]={10,9,11,8,12,13,14,15,3,1,2,0,7,5,4,6,20,21,22,23,16,17,18,19,64,65,66,67,71,70,69,68,32,33,34,35,36,37,38,39,42,40,43,41,44,46,45,47,48,51,50,49,52,53,54,55,58,56,57,59,60,61,62,63,31,28,29,30,25,27,26,24};
   const uint8_t GL_DQ_p0_g2[l_maxdq]={10,9,11,8,12,13,14,15,3,1,2,0,7,5,4,6,16,17,18,19,20,21,22,23,64,65,66,67,71,70,69,68,32,33,34,35,36,37,38,39,42,40,43,41,44,46,45,47,48,51,50,49,52,53,54,55,58,56,57,59,60,61,62,63,25,27,26,24,28,31,29,30};
   const uint8_t GL_DQ_p1_g1[l_maxdq]={15,13,12,14,9,8,10,11,5,7,4,6,3,2,1,0,20,22,21,23,16,17,18,19,70,71,69,68,67,66,65,64,32,35,34,33,38,37,39,36,40,41,42,43,44,45,46,47,49,50,48,51,52,53,54,55,59,57,56,58,60,62,61,63,27,26,25,24,31,30,28,29};
   const uint8_t GL_DQ_p1_g2[l_maxdq]={8,9,10,11,12,13,14,15,3,2,1,0,4,5,6,7,16,17,18,19,20,21,22,23,67,66,64,65,70,71,69,68,32,35,34,33,38,37,39,36,40,41,42,43,44,45,46,47,49,50,48,51,52,53,54,55,59,57,56,58,60,62,61,63,27,26,25,24,31,30,28,29};
   const uint8_t GL_DQ_p2[l_maxdq]={9,11,10,8,12,15,13,14,0,1,3,2,5,4,7,6,19,17,16,18,20,22,21,23,66,67,65,64,71,70,69,68,32,33,34,35,36,37,38,39,41,40,43,42,45,44,47,46,48,49,50,51,52,53,54,55,58,56,57,59,60,61,62,63,25,27,24,26,28,31,29,30};
   const uint8_t GL_DQ_p3[l_maxdq]={3,2,0,1,4,5,6,7,11,10,8,9,15,14,12,13,16,17,18,19,20,21,22,23,64,65,66,67,68,69,70,71,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,24,25,26,27,28,29,30,31};

   const uint8_t GL_DQS_p0_g1[l_maxdqs]={2,0,5,16,8,10,12,14,7,3,1,4,17,9,11,13,15,6};
   const uint8_t GL_DQS_p0_g2[l_maxdqs]={2,0,4,16,8,10,12,14,6,3,1,5,17,9,11,13,15,7};
   const uint8_t GL_DQS_p1_g1[l_maxdqs]={3,1,5,16,8,10,12,14,6,2,0,4,17,9,11,13,15,7};
   const uint8_t GL_DQS_p1_g2[l_maxdqs]={2,0,4,16,8,10,12,14,6,3,1,5,17,9,11,13,15,7};
   const uint8_t GL_DQS_p2[l_maxdqs]={2,0,4,16,8,10,12,14,6,3,1,5,17,9,11,13,15,7};
   const uint8_t GL_DQS_p3[l_maxdqs]={0,2,4,16,8,10,12,14,6,1,3,5,17,9,11,13,15,7};
   
   rc = FAPI_ATTR_GET(ATTR_MSS_DQS_SWIZZLE_TYPE, &i_target_mba, l_swizzle); if(rc) return rc;
   
   
   if(l_swizzle ==0 || l_swizzle ==1)
   {
      if(i_verbose==1)
      {
         FAPI_INF("swizzle type=%d",l_swizzle);
      }   
   }
   
   else
   {
      FAPI_ERR("Wrong swizzle value (%d)", l_swizzle);
      const uint8_t & SWIZZLE_TYPE = l_swizzle;
      FAPI_SET_HWP_ERROR(rc, RC_ROSETTA_MAP_BAD_SWIZZLE_VALUE);
      return rc;
   }
   
   rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbapos); if(rc) return rc;

   if(i_port >1)
   {
      FAPI_ERR("Wrong port specified (%d)", i_port);
      FAPI_SET_HWP_ERROR(rc, RC_ROSETTA_MAP_INVALID_INPUT);
      return rc;
   }

   if (l_mbapos>1)
   {
       FAPI_ERR("Bad position from ATTR_CHIP_UNIT_POS (%d)", l_mbapos);
       const uint8_t & MBA_POS = l_mbapos;
       FAPI_SET_HWP_ERROR(rc, RC_ROSETTA_MAP_BAD_MBA_POS);
       return rc;
   }
   
   rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_dimmtype); if(rc) return rc;
   
   if(l_dimmtype==fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
   {
      if(i_input_index>l_CDIMM_dqmax)    
      {
         FAPI_SET_HWP_ERROR(rc, RC_ROSETTA_MAP_INVALID_INPUT);
         FAPI_ERR("Wrong input index specified rc = 0x%08X" ,uint32_t(rc));
         return rc;      
      }
   }
   else
   {
      if(i_input_index>l_ISDIMM_dqmax)
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index);
         FAPI_SET_HWP_ERROR(rc, RC_ROSETTA_MAP_INVALID_INPUT);
         return rc;
      }
   }
    	
   if(i_input_type_e ==ISDIMM_DQ)
   {
      if(i_port==0 && l_mbapos==0)
      {
         if(l_swizzle==1)
         {
            o_value=GL_DQ_p0_g1[i_input_index];   
         }
         else
         {
            o_value=GL_DQ_p0_g2[i_input_index];    
         }
            
      }
	            
      else if(i_port==1 && l_mbapos==0)
      {
         if(l_swizzle==1)
         {
            o_value=GL_DQ_p1_g1[i_input_index];
         }
         else
         {
            o_value=GL_DQ_p1_g2[i_input_index];    
         }
      }
   
      else if(i_port==0 && l_mbapos==1)
      {
         o_value=GL_DQ_p2[i_input_index];    
      }
      else 
      {
         o_value=GL_DQ_p3[i_input_index];    
      }
          
   }
      
    
   else if(i_input_type_e ==ISDIMM_DQS)
   {
        
      if(i_port==0 && l_mbapos==0)
      {
         if(l_swizzle==1)
         {
            o_value=GL_DQS_p0_g1[i_input_index];
         }
         else 
         {
            o_value=GL_DQS_p0_g2[i_input_index];    
         }
            
      }    
      else if(i_port==1 && l_mbapos==0)
      {
         if(l_swizzle==1)
         {
            o_value=GL_DQS_p1_g1[i_input_index];
         }
         else 
         {
            o_value=GL_DQS_p1_g2[i_input_index];    
         }
            
      }
      else if(i_port==0 && l_mbapos==1)
      {
         o_value=GL_DQS_p2[i_input_index];
      }
      else 
      {
         o_value=GL_DQS_p3[i_input_index];
      }
                    
   }      
   else if(i_input_type_e==CDIMM_DQS)
   {
      o_value=i_input_index;   
   }
      
   else if(i_input_type_e==CDIMM_DQ)
   {
      o_value=i_input_index;
   }
       
   else
   {
      FAPI_ERR("Wrong input type specified (%d)", i_input_type_e);
      FAPI_SET_HWP_ERROR(rc, RC_ROSETTA_MAP_INVALID_INPUT);
      return rc;      
   }
   
   return rc;
}

//******************************************************************************
//Function name: get address()
//Description:This function returns address,start bit and bit length for RD_DQ, WR_DQ, RD_DQS, WR_DQS
//Input  : Target MBA=i_target_mba, i_port_u8=0 or 1, i_rank_pair=0 or 1 or 2 or 3, i_input_type_e=RD_DQ or RD_DQS or WR_DQ or WR_DQS, i_block=0 or 1 or 2 or 3 or 4, i_lane=0-15   
//Output : scom address=o_scom_address_64, start bit=o_start_bit, bit length=o_len 
//******************************************************************************    
fapi::ReturnCode get_address(const fapi::Target & i_target_mba,
                             uint8_t i_port,
                             uint8_t i_rank_pair,
                             ip_type_t i_input_type_e,
                             uint8_t i_block,
                             uint8_t i_lane,
                             uint64_t &o_scom_address_64,
                             uint8_t &o_start_bit,
                             uint8_t &o_len)
{
   fapi::ReturnCode rc;
   
   uint64_t l_scom_address_64 = 0x0ull;
   uint64_t l_temp=0x0ull;
   uint8_t l_mbapos;
   uint8_t l_lane=0;
   const uint64_t l_port01_st=0x8000000000000000ull;
   const uint64_t l_port23_st=0x8001000000000000ull;
   const uint64_t l_port01_adr_st=0x8000400000000000ull;
   const uint64_t l_port23_adr_st=0x8001400000000000ull;
   const uint32_t l_port01_en=0x0301143f;
   const uint64_t l_rd_port01_en=0x040301143full;
   const uint64_t l_sys_clk_en=0x730301143full;
   const uint64_t l_wr_clk_en =0x740301143full;
   const uint64_t l_adr02_st=0x8000400000000000ull;
   const uint64_t l_adr13_st=0x8001400000000000ull;
   const uint64_t l_dqs_gate_en=0x000000130301143full;
   const uint64_t l_dqsclk_en=0x090301143full;
   const uint64_t l_data_ds_en=0x7c0301143full;
   uint8_t l_tmp=0;
   rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbapos); if(rc) return rc;
   
   if(i_input_type_e==WR_DQ_t || i_input_type_e==RAW_WR_DQ)
   {
      if(i_lane > 7)
      {
         l_scom_address_64 = 0x00000040;
         l_scom_address_64=l_scom_address_64<<32;
         l_temp|=(i_lane-8);
      }
		
      else
      {
         l_scom_address_64|=0x00000038;
         l_scom_address_64=l_scom_address_64<<32;
         l_temp|=i_lane;
      }
      l_temp|=(i_block*4)<<8;
      l_temp|=i_rank_pair<<8;
      l_temp=l_temp<<32;
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_port01_st | l_temp | l_port01_en;
      }
      else 
      { 
         l_scom_address_64|= l_port23_st | l_temp | l_port01_en;
      }
             
      o_scom_address_64=l_scom_address_64;
      o_start_bit=48; 
      o_len=10;
     
   }
   
   else if(i_input_type_e==RD_DQ_t || i_input_type_e==RAW_RD_DQ)
   {
      l_scom_address_64|=0x00000050;       
      l_scom_address_64=l_scom_address_64<<32;
      l_lane=i_lane/2;           
      l_temp|=l_lane;
      l_temp|=(i_block*4)<<8;     
      l_temp|=i_rank_pair<<8;     
      l_temp=l_temp<<32;
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_port01_st | l_temp | l_port01_en;
      }
      else 
      { 
         l_scom_address_64|= l_port23_st | l_temp | l_port01_en;
      }
            
      if((i_lane % 2) == 0)
      {
         o_start_bit=48;
         o_len=7;
      }
      else
      {
         o_start_bit=56;
         o_len=7;
      }
   
      
      o_scom_address_64=l_scom_address_64; 
     
   }
   
   else if(i_input_type_e==COMMAND_t || i_input_type_e==CLOCK_t ||  i_input_type_e==CONTROL_t ||  i_input_type_e==ADDRESS_t )
   {
      l_tmp|=4;       
      l_lane=i_lane/2;           
      l_temp=l_lane+l_tmp;
      l_temp|=(i_block*4)<<8;     
      l_temp=l_temp<<32;
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_port01_adr_st | l_temp | l_port01_en;
      }
      else 
      { 
         l_scom_address_64|= l_port23_adr_st | l_temp | l_port01_en;
      }
            
      if((i_lane % 2) == 0)
      {
         o_start_bit=49;
         o_len=7;
      }
      else
      {
         o_start_bit=57;
         o_len=7;
      }
   
      
      o_scom_address_64=l_scom_address_64; 
     
   }    
        
       
   else if(i_input_type_e==WR_DQS_t  || i_input_type_e==RAW_WR_DQS)    
   {
      
      if(i_input_type_e==RAW_WR_DQS)
      {
         if(i_lane==0)
         {
            i_lane=16;   
         }
         else if(i_lane==1)
         {
            i_lane=18;   
         }
         else if(i_lane==2)
         {
            i_lane=20;   
         }
         else 
         {
            i_lane=22;   
         }
      }
      if(i_lane==16)
      {
         l_scom_address_64|=0x00000048;   	    
      }
      else if(i_lane==18)
      {
         l_scom_address_64|=0x0000004a;   	    
      }
      else if(i_lane==20)
      {
         l_scom_address_64|=0x0000004c;   	    
      }
      else
      {
         l_scom_address_64|=0x0000004e;   	    
      }
               
      l_scom_address_64=l_scom_address_64<<32;             
      l_temp|=(i_block*4)<<8;     
      l_temp|=i_rank_pair<<8;     
      l_temp=l_temp<<32;
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_port01_st | l_temp | l_port01_en;
      }
      else
      { 
         l_scom_address_64|= l_port23_st | l_temp | l_port01_en;
      }
     
      o_start_bit=48; 
      o_len=10;  
      o_scom_address_64=l_scom_address_64; 
      
   }
   
   else if(i_input_type_e==DATA_DISABLE_t)    
   {
      l_temp|=(i_block*4)<<8;     
      l_temp|=i_rank_pair<<8;     
      l_temp=l_temp<<32;
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_port01_st | l_temp | l_data_ds_en;
      }
      else
      { 
         l_scom_address_64|= l_port23_st | l_temp | l_data_ds_en;
      }
     
      o_start_bit=48; 
      o_len=16;  
      o_scom_address_64=l_scom_address_64; 
   }
   
   else if(i_input_type_e==RD_CLK_t)
   {  
      l_temp|=(i_block*4)<<8;     
      l_temp|=i_rank_pair<<8;     
      l_temp=l_temp<<32;
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {   
         l_scom_address_64|= l_port01_st | l_temp| l_rd_port01_en;
      }
      else 
      {   
         l_scom_address_64|= l_port23_st | l_temp| l_rd_port01_en;
      }
      
         
      o_start_bit=0;
      o_len=0;
      o_scom_address_64=l_scom_address_64;   
      
   } 
            
   else if(i_input_type_e==RD_DQS_t || i_input_type_e==RAW_RD_DQS) 
   {
      
      if(i_input_type_e==RAW_RD_DQS)
      {
         if(i_lane==0)
         {
            i_lane=16;   
         }
         else if(i_lane==1)
         {
            i_lane=18;   
         }
         else if(i_lane==2)
         {
            i_lane=20;   
         }
         else
         {
            i_lane=22;   
         }
      }   
      if(i_lane==16)
      {
         l_scom_address_64|=0x00000030;  
         o_start_bit=49;  	    
      }
      else if(i_lane==18)
      {
	 l_scom_address_64|=0x00000030;   	
	 o_start_bit=57;     
      }
      else if(i_lane==20)
      {
         l_scom_address_64|=0x00000031; 
         o_start_bit=49;   	    
      }
      else 
      {
         l_scom_address_64|=0x00000031;  
         o_start_bit=57;  	    
      }
   
      l_scom_address_64=l_scom_address_64<<32;             
      l_temp|=(i_block*4)<<8;     
      l_temp|=i_rank_pair<<8;     
      l_temp=l_temp<<32;
      
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_port01_st | l_temp | l_port01_en;
      }
      else 
      { 
         l_scom_address_64|= l_port23_st | l_temp | l_port01_en;
      }
      
        
      o_len=7;  
      o_scom_address_64=l_scom_address_64; 
     
   }
   
   else if(i_input_type_e==RDCLK_t || i_input_type_e==RAW_RDCLK) 
   {
      if(i_input_type_e==RAW_RDCLK) 
      {
         if(i_lane==0)
         {
            i_lane=16;   
         }
         else if(i_lane==1)
         {
            i_lane=18;   
         }
         else if(i_lane==2)
         {
            i_lane=20;   
         }
         else
         {
            i_lane=22;   
         }
      }   
      if(i_lane==16)
      {
         o_start_bit=50;    
      }
      else if(i_lane==18)
      {
	 o_start_bit=54;     
      }
      else if(i_lane==20)
      {
         o_start_bit=58;   	    
      }
      else 
      {
         o_start_bit=62;  	    
      }
   
      l_temp|=(i_block*4)<<8;     
      l_temp|=i_rank_pair<<8;     
      l_temp=l_temp<<32;
      
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_port01_st | l_temp | l_dqsclk_en;
      }
      else 
      { 
         l_scom_address_64|= l_port23_st | l_temp | l_dqsclk_en;
      }
             
      o_len=2;  
      o_scom_address_64=l_scom_address_64; 
     
   }
   
    else if(i_input_type_e==DQSCLK_t || i_input_type_e==RAW_DQSCLK) 
   {
      if(i_input_type_e==RAW_DQSCLK) 
      {
         if(i_lane==0)
         {
            i_lane=16;   
         }
         else if(i_lane==1)
         {
            i_lane=18;   
         }
         else if(i_lane==2)
         {
            i_lane=20;   
         }
         else
         {
            i_lane=22;   
         }
      }
           
      if(i_lane==16)
      {
         o_start_bit=48;    
      }
      else if(i_lane==18)
      {
	 o_start_bit=52;     
      }
      else if(i_lane==20)
      {
         o_start_bit=56;   	    
      }
      else 
      {
         o_start_bit=60;  	    
      }
   
      l_temp|=(i_block*4)<<8;     
      l_temp|=i_rank_pair<<8;     
      l_temp=l_temp<<32;
      
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_port01_st | l_temp | l_dqsclk_en;
      }
      else 
      { 
         l_scom_address_64|= l_port23_st | l_temp | l_dqsclk_en;
      }
             
      o_len=2;  
      o_scom_address_64=l_scom_address_64; 
     
   }
   
     
   else if(i_input_type_e==DQS_ALIGN_t || i_input_type_e==RAW_DQS_ALIGN) 
   {
      
      if(i_input_type_e==RAW_DQS_ALIGN)
      {
         if(i_lane==0)
         {
            i_lane=16;   
         }
         else if(i_lane==1)
         {
            i_lane=18;   
         }
         else if(i_lane==2)
         {
            i_lane=20;   
         }
         else 
         {
            i_lane=22;   
         }
      }   
      if(i_lane==16)
      {
         l_scom_address_64|=0x0000005c;  
         o_start_bit=49;  	    
      }
      else if(i_lane==18)
      {
	 l_scom_address_64|=0x0000005c;   	
	 o_start_bit=57;     
      }
      else if(i_lane==20)
      {
         l_scom_address_64|=0x0000005d; 
         o_start_bit=49;   	    
      }
      else 
      {
         l_scom_address_64|=0x0000005d;  
         o_start_bit=57;  	    
      }
   
      l_scom_address_64=l_scom_address_64<<32;             
      l_temp|=(i_block*4)<<8;     
      l_temp|=i_rank_pair<<8;     
      l_temp=l_temp<<32;
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_port01_st | l_temp | l_port01_en;
      }
      else 
      { 
         l_scom_address_64|= l_port23_st | l_temp | l_port01_en;
      }
       
          
      o_len=7;  
      o_scom_address_64=l_scom_address_64; 
     
   }
   
   
   
   else if(i_input_type_e==RAW_SYS_ADDR_CLKS0S1)
   {  
     
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         if(i_lane==0)
         {
            l_scom_address_64=0x800080340301143full;
         }
         else
         {
            l_scom_address_64=0x800084340301143full;   
         }
      }
         
      else 
      {
         if(i_lane==0)
         {
            l_scom_address_64=0x800180340301143full;
         }
         else
         {
            l_scom_address_64=0x800184340301143full;   
         }
      }   
         
      o_start_bit=49;
      o_len=7;
      o_scom_address_64=l_scom_address_64;   
      
   }
   
   else if(i_input_type_e==RAW_SYS_CLK)
   {  
      l_temp|=(i_block*4)<<8;     
      l_temp=l_temp<<32;
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {   
         l_scom_address_64|= l_port01_st | l_temp| l_sys_clk_en;
      }
      else 
      {   
         l_scom_address_64|= l_port23_st | l_temp| l_sys_clk_en;
      }
               
      o_start_bit=49;
      o_len=7;
      o_scom_address_64=l_scom_address_64;  
      
   }
   
    else if(i_input_type_e==RAW_WR_CLK)
   {  
      l_temp|=(i_block*4)<<8;     
      l_temp=l_temp<<32;
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {   
         l_scom_address_64|= l_port01_st | l_temp| l_wr_clk_en;
      }
      else 
      {   
         l_scom_address_64|= l_port23_st | l_temp| l_wr_clk_en;
      }
               
      o_start_bit=49;
      o_len=7;
      o_scom_address_64=l_scom_address_64;  
      
   } 
   
   else if(i_input_type_e==RAW_ADDR)
   {
      l_scom_address_64|=0x00000004;       
      l_lane=i_lane;
      if(i_lane<=7)
      {
         i_lane=i_lane/2;   
      }
      else if(i_lane==8 || i_lane==9)
      {
      l_scom_address_64=0x00000008;
      i_lane=0;
      }
      else if(i_lane==10 || i_lane==11)
      {
      l_scom_address_64=0x00000009;
      i_lane=0;
      }
      else if(i_lane==12 || i_lane==13)
      {
      l_scom_address_64=0x0000000a;
      i_lane=0;
      }
      else 
      {
      l_scom_address_64=0x0000000b;
      i_lane=0;
      }
      l_scom_address_64=l_scom_address_64<<32; 
      l_temp|=i_lane;
      l_temp|=(i_block*4)<<8;     
      l_temp=l_temp<<32;
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_adr02_st | l_temp | l_port01_en;
      }
      else 
      { 
         l_scom_address_64|= l_adr13_st | l_temp | l_port01_en;
      }
       
      if((l_lane % 2) == 0)
      {
         o_start_bit=49;
         o_len=7;
      }
      else
      {
         o_start_bit=57;
         o_len=7;
      }
   
      
      o_scom_address_64=l_scom_address_64; 
     
   }    
   
   else if(i_input_type_e==RAW_DQS_GATE ||  i_input_type_e==DQS_GATE_t)
   {
      if(i_input_type_e==RAW_DQS_GATE)
      {
         l_lane=i_lane/4;    
         l_temp|=l_lane;
      }
      if(i_input_type_e==DQS_GATE_t)
      {
         l_lane=i_lane;    
      }
      
      l_temp|=(i_block*4)<<8;     
      l_temp|=i_rank_pair<<8;     
      l_temp=l_temp<<32;
     
      if(i_input_type_e==RAW_DQS_GATE)
      {
         if((i_lane % 4) == 0)
         {
            o_start_bit=49;
            o_len=3;
         }
         else if((i_lane % 4) == 1)
         {
            o_start_bit=53;
            o_len=3;
         }
      
         else if((i_lane % 4) == 2)
         {
            o_start_bit=57;
            o_len=3;
         }
      
         else 
         {
            o_start_bit=61;
            o_len=3;
         }
      }
      
      else
      {
         if(l_lane == 16)
         {
            o_start_bit=49;
            o_len=3;
         }
         else if(l_lane ==18)
         {
            o_start_bit=53;
            o_len=3;
         }
      
         else if(l_lane ==20)
         {
            o_start_bit=57;
            o_len=3;
         }
      
         else 
         {
            o_start_bit=61;
            o_len=3;
         }
         
      }
      
      if((i_port==0 && l_mbapos==0) || (i_port==0 && l_mbapos==1))
      {
         l_scom_address_64|= l_port01_st | l_temp | l_dqs_gate_en;
      }
      else 
      { 
         l_scom_address_64|= l_port23_st | l_temp | l_dqs_gate_en;
      }
                 
      o_scom_address_64=l_scom_address_64; 
      
   } 
      
   return rc;
} 
 
//******************************************************************************
//Function name: mss_getrankpair()
//Description:This function returns rank pair and valid ranks from a given rank 
//Input  : Target MBA=i_target_mba, i_port_u8=0 or 1, i_rank=valid ranks  
//Output : rank pair=o_rank_pair, valid ranks=o_rankpair_table[] 
//******************************************************************************
fapi::ReturnCode mss_getrankpair(const fapi::Target & i_target_mba,
                                 uint8_t i_port,
                                 uint8_t i_rank,
                                 uint8_t *o_rank_pair,
                                 uint8_t o_rankpair_table[])
{
   fapi::ReturnCode rc;
   uint8_t l_temp_rank[2]={0};
   uint8_t l_temp_rankpair_table[16]={0};
   uint8_t l_i= 0;
   uint8_t l_rank_pair = 0;
   uint8_t l_j= 0;
   uint8_t l_temp_swap = 0;
 
 
   for(l_i=0; l_i<8; l_i++)     	//populate Rank Pair Table as FF - invalid
   {
      //l_temp_rankpair_table[l_i]=255;
      o_rankpair_table[l_i]=255;
   }
 
   if(i_port==0 || i_port ==1)
   {	
	
      rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[0]=l_temp_rank[i_port];
	
      rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[1]=l_temp_rank[i_port];
	
      rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[2]=l_temp_rank[i_port];
      rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[3]=l_temp_rank[i_port];
   	
      rc = FAPI_ATTR_GET(ATTR_EFF_SECONDARY_RANK_GROUP0, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[4]=l_temp_rank[i_port];
	
      rc = FAPI_ATTR_GET(ATTR_EFF_SECONDARY_RANK_GROUP1, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[5]=l_temp_rank[i_port];
      rc = FAPI_ATTR_GET(ATTR_EFF_SECONDARY_RANK_GROUP2, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[6]=l_temp_rank[i_port];
   	
      rc = FAPI_ATTR_GET(ATTR_EFF_SECONDARY_RANK_GROUP3, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[7]=l_temp_rank[i_port];
   	
      rc = FAPI_ATTR_GET(ATTR_EFF_TERTIARY_RANK_GROUP0, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[8]=l_temp_rank[i_port];
   	
      rc = FAPI_ATTR_GET(ATTR_EFF_TERTIARY_RANK_GROUP1, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[9]=l_temp_rank[i_port];
   	
      rc = FAPI_ATTR_GET(ATTR_EFF_TERTIARY_RANK_GROUP2, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[10]=l_temp_rank[i_port];
   	
      rc = FAPI_ATTR_GET(ATTR_EFF_TERTIARY_RANK_GROUP3, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[11]=l_temp_rank[i_port];
   	
      rc = FAPI_ATTR_GET(ATTR_EFF_QUATERNARY_RANK_GROUP0, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[12]=l_temp_rank[i_port];
	
      rc = FAPI_ATTR_GET(ATTR_EFF_QUATERNARY_RANK_GROUP1, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[13]=l_temp_rank[i_port];
   	
      rc = FAPI_ATTR_GET(ATTR_EFF_QUATERNARY_RANK_GROUP2, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[14]=l_temp_rank[i_port];
   	
      rc = FAPI_ATTR_GET(ATTR_EFF_QUATERNARY_RANK_GROUP3, &i_target_mba, l_temp_rank);if(rc) return rc;
      l_temp_rankpair_table[15]=l_temp_rank[i_port];

	
   }

   for(l_i=0; l_i<16; l_i++)
   {
      if(l_temp_rankpair_table[l_i]==i_rank)
      {
	 l_rank_pair=l_i;break;
      }
   }
	
   l_rank_pair = l_rank_pair%4; // if index l_i is greater than 4,8,12 Secondary, Tertiary, Quaternary.
	
	
   for(l_i=0; l_i<15; l_i++)
   {
      for(l_j=l_i+1;l_j<16;l_j++)
      {
         if(l_temp_rankpair_table[l_i]>l_temp_rankpair_table[l_j])
         {
            l_temp_swap = l_temp_rankpair_table[l_j];
            l_temp_rankpair_table[l_j]=l_temp_rankpair_table[l_i];
            l_temp_rankpair_table[l_i]=l_temp_swap;
         }
      }
   }
	
   for(l_i=0; l_i<8; l_i++)
   {
      if(l_temp_rankpair_table[l_i]!=255)
         o_rankpair_table[l_i]=l_temp_rankpair_table[l_i];
   }
   *o_rank_pair = l_rank_pair;
	
	
   return rc;
} //end of mss_getrankpair

//******************************************************************************
//Function name: mss_c4_phy()
//Description:This function returns address,start bit and bit length for RD_DQ, WR_DQ, RD_DQS, WR_DQS
//Input  : Target MBA=i_target_mba, i_port_u8=0 or 1, i_rank_pair=0 or 1 or 2 or 3, i_input_type_e=RD_DQ or RD_DQS or WR_DQ or WR_DQS,i_input_index_u8=0-79/0-71/0-8/0-19 , i_verbose-extra print statements  
//Output : out (address,start bit and bit length)
//******************************************************************************
fapi::ReturnCode mss_c4_phy(const fapi::Target & i_target_mba,
                            uint8_t i_port,
                            uint8_t i_rank_pair,
                            input_type_t i_input_type_e,
                            uint8_t &i_input_index,
                            uint8_t i_verbose,
                            uint8_t &phy_lane,
                            uint8_t &phy_block,
                            uint8_t flag)
{
   fapi::ReturnCode rc; 
   const uint8_t l_dqmax=80;
   const uint8_t l_dqsmax=20;
   //const uint8_t l_blkmax=5;
   const uint8_t lane_dq_p0[l_dqmax]={4,6,5,7,2,1,3,0,13,15,12,14,8,9,11,10,13,15,12,14,9,8,11,10,13,15,12,14,11,9,10,8,11,8,9,10,12,13,14,15,7,6,5,4,1,3,2,0,5,6,4,7,3,1,2,0,7,4,5,6,2,0,3,1,3,0,1,2,6,5,4,7,11,8,9,10,15,13,12,14}; 
   const uint8_t lane_dq_p1[l_dqmax]={9,11,8,10,13,14,15,12,10,8,11,9,12,13,14,15,1,0,2,3,4,5,6,7,9,11,10,8,15,12,13,14,5,7,6,4,1,0,2,3,0,2,1,3,5,4,6,7,0,2,3,1,4,5,6,7,12,15,13,14,11,8,10,9,5,7,4,6,3,2,0,1,14,12,15,13,9,8,11,10}; 
   const uint8_t lane_dq_p2[l_dqmax]={13,15,12,14,11,9,10,8,13,12,14,15,10,9,11,8,5,6,7,4,2,3,0,1,10,9,8,11,13,12,15,14,15,12,13,14,11,10,9,8,7,6,4,5,1,0,3,2,0,2,1,3,5,6,4,7,5,7,6,4,1,0,2,3,1,2,3,0,7,6,5,4,9,10,8,11,12,15,14,13};
   const uint8_t lane_dq_p3[l_dqmax]={4,5,6,7,0,1,3,2,12,13,15,14,8,9,10,11,10,8,11,9,12,13,15,14,3,0,1,2,4,6,7,5,9,10,11,8,14,13,15,12,7,5,6,4,3,1,2,0,5,6,7,4,1,2,3,0,14,12,15,13,8,10,9,11,0,3,2,1,6,5,7,4,10,11,9,8,12,13,15,14};
   const uint8_t dqs_dq_lane_p0[l_dqsmax]={4,0,12,8,12,8,12,8,8,12,4,0,4,0,4,0,0,4,8,12};
   const uint8_t dqs_dq_lane_p1[l_dqsmax]={8,12,8,12,0,4,8,12,4,0,0,4,0,4,12,8,4,0,12,8};
   const uint8_t dqs_dq_lane_p2[l_dqsmax]={12,8,12,8,4,0,8,12,12,8,4,0,0,4,4,0,0,4,8,12};
   const uint8_t dqs_dq_lane_p3[l_dqsmax]={4,0,12,8,8,12,0,4,8,12,4,0,4,0,12,8,0,4,8,12};
   const uint8_t block_p1[l_dqmax]={0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2};
   const uint8_t block_p0[l_dqmax]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
   const uint8_t block_p2[l_dqmax]={1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,4,4,4,4,4,4,4,4};
   const uint8_t block_p3[l_dqmax]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
   const uint8_t block_dqs_p0[l_dqsmax]={2,2,2,2,0,0,3,3,4,4,3,3,4,4,1,1,0,0,1,1};
   const uint8_t block_dqs_p1[l_dqsmax]={0,0,3,3,0,0,1,1,2,2,3,3,4,4,4,4,1,1,2,2};
   const uint8_t block_dqs_p2[l_dqsmax]={1,1,3,3,0,0,0,0,2,2,2,2,3,3,4,4,1,1,4,4};
   const uint8_t block_dqs_p3[l_dqsmax]={2,2,2,2,0,0,0,0,3,3,3,3,4,4,4,4,1,1,1,1};
   uint8_t l_mbapos = 0;
   uint8_t l_dram_width=0;
   uint8_t l_lane=0;
   uint8_t l_block=0;
   uint8_t lane_dqs[4]={0}; //Initialize to 0.  This is a numerical ID of a false lane.  Another function catches this in mss_draminit_training.
   uint8_t l_index=0;
   uint8_t l_dq=0;
   uint8_t l_phy_dq=0;
   //uint8_t l_phy_block=0;
   uint64_t l_scom_address_64=0x0ull;
   uint8_t l_start_bit=0;
   uint8_t l_len=0;
   ip_type_t l_input_type;
   ecmdDataBufferBase data_buffer_64(64);
   uint8_t l_dimmtype=0;
   uint8_t l_swizzle=0;
   i_verbose=1; //Default the verbose flag high 
      
   rc = FAPI_ATTR_GET(ATTR_MSS_DQS_SWIZZLE_TYPE, &i_target_mba, l_swizzle); if(rc) return rc;
      
   rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbapos); if(rc) return rc;
   
   rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_dimmtype); if(rc) return rc;
         
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, l_dram_width); if(rc) return rc;
   
      
   if(i_input_type_e==RD_DQ || i_input_type_e==WR_DQ)
   {
   
      if(i_port==0 && l_mbapos==0)
      {
	  
	  if(flag==1){
		for(l_phy_dq=0;l_phy_dq<l_dqmax;l_phy_dq++){
			if(phy_block==block_p0[l_phy_dq]){
				if(phy_lane==lane_dq_p0[l_phy_dq]){
				i_input_index=l_phy_dq;
				}
			}
		}	
	  }else{
	  
         l_lane=lane_dq_p0[i_input_index];
		l_block=block_p0[i_input_index];	 
		}
      }
      else if(i_port==1 && l_mbapos==0)
      {
	  
	  if(flag==1){
		for(l_phy_dq=0;l_phy_dq<l_dqmax;l_phy_dq++){
			if(phy_block==block_p1[l_phy_dq]){
				if(phy_lane==lane_dq_p1[l_phy_dq]){
				i_input_index=l_phy_dq;
				}
			}
		}
	}else{
         l_lane=lane_dq_p1[i_input_index];
         l_block=block_p1[i_input_index];	    
		}
	} 
    else if(i_port==0 && l_mbapos==1)
      {
	  if(flag==1){
		for(l_phy_dq=0;l_phy_dq<l_dqmax;l_phy_dq++){
			if(phy_block==block_p2[l_phy_dq]){
				if(phy_lane==lane_dq_p2[l_phy_dq]){
				i_input_index=l_phy_dq;
				}
			}
		}
	}else{
	  
         l_lane=lane_dq_p2[i_input_index];
         l_block=block_p2[i_input_index];	
		}
    }
    else
      {
	  if(flag==1){
		for(l_phy_dq=0;l_phy_dq<l_dqmax;l_phy_dq++){
			if(phy_block==block_p3[l_phy_dq]){
				if(phy_lane==lane_dq_p3[l_phy_dq]){
				i_input_index=l_phy_dq;
				}
			}
		}
	}else{
		l_lane=lane_dq_p3[i_input_index];
		l_block=block_p3[i_input_index];	
	 }
    }
      
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      } 
      // if(i_input_type_e==RD_DQ)
      // {
         // l_input_type=RD_DQ_t;
      // }
      // else 	
      // {
         // l_input_type=WR_DQ_t;    
      // }
      
            
      // rc=get_address(i_target_mba,i_port,i_rank_pair,l_input_type,l_block,l_lane,l_scom_address_64,l_start_bit,l_len); if(rc) return rc; 		 
      if(flag==0){
	  phy_lane=l_lane;
	  phy_block=l_block;
	  }
	  // out.scom_addr=l_scom_address_64;
      // out.start_bit=l_start_bit;
      // out.bit_length=l_len; 
   }
   
   else if (i_input_type_e==WR_DQS ||  i_input_type_e==DQS_ALIGN)	    
   {
      if(i_port==0 && l_mbapos==0)
      {
         l_dq=dqs_dq_lane_p0[i_input_index];
         l_block=block_dqs_p0[i_input_index]; 
      }
             
      else if(i_port==1 && l_mbapos==0)
      {
         l_dq=dqs_dq_lane_p1[i_input_index];   
         l_block=block_dqs_p1[i_input_index]; 
      }   
      else if(i_port==0 && l_mbapos==1)
      {
         l_dq=dqs_dq_lane_p2[i_input_index];   
         l_block=block_dqs_p2[i_input_index]; 
      }
      else 
      {
         l_dq=dqs_dq_lane_p3[i_input_index];   
         l_block=block_dqs_p3[i_input_index]; 
      }
       
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("dqs_dq_lane=%d",l_dq);
      }
      l_input_type=RD_CLK_t; 
      rc=get_address(i_target_mba,i_port,i_rank_pair, l_input_type,l_block,l_lane,l_scom_address_64,l_start_bit,l_len); if(rc) return rc;
      if(i_verbose==1)
      {
         FAPI_INF("read clock address=%llx",l_scom_address_64);
      }
      rc=fapiGetScom(i_target_mba,l_scom_address_64,data_buffer_64);if(rc) return rc; 
            
      if(l_dram_width==fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4)
      {
         
         if (data_buffer_64.isBitSet(48))
         {
            lane_dqs[0]=16;
            
         }
         else if(data_buffer_64.isBitSet(52))
         { 
            lane_dqs[0]=18;
            
         }
        
         if (data_buffer_64.isBitSet(49))
         {
            lane_dqs[1]=16;
            
         }
     
         else if (data_buffer_64.isBitSet(53))
         {
            lane_dqs[1]=18;
            
         }
         
         if (data_buffer_64.isBitSet(54))
         {
            lane_dqs[2]=20;
            
         }
         else if (data_buffer_64.isBitSet(56))
         {
            lane_dqs[2]=22;
           
         }
      
         if (data_buffer_64.isBitSet(55))
         {
            lane_dqs[3]=20;
         }
         else if (data_buffer_64.isBitSet(57))   // else is not possible as one of them will definitely get set
         {
            lane_dqs[3]=22;
          
         }
         if(i_verbose==1)
         {
            FAPI_INF("array is=%d and %d and %d and %d",lane_dqs[0],lane_dqs[1],lane_dqs[2],lane_dqs[3]);
         }   
         if(l_dq==0)
         {
            l_lane=lane_dqs[0];
         }
         else if(l_dq==4)
         {
            l_lane=lane_dqs[1];
         }  
         else if(l_dq==8)
         {
            l_lane=lane_dqs[2];
         }
         else 
         {
            l_lane=lane_dqs[3];
         }
         
         if(i_verbose==1)
         {
            FAPI_INF("lane is=%d",l_lane); 
         }
      }			  
   
     
      else
      {   
         if (data_buffer_64.isBitSet(48)&& data_buffer_64.isBitSet(49))
         {		  
            lane_dqs[l_index]=16;
            l_index++; 		    
         }
         else if (data_buffer_64.isBitSet(52)&& data_buffer_64.isBitSet(53))
         {		  
            lane_dqs[l_index]=18;
            l_index++; 		    
         }
         if (data_buffer_64.isBitSet(54)&& data_buffer_64.isBitSet(55))
         {		  
            lane_dqs[l_index]=20;
            l_index++; 		    
         }
         else if (data_buffer_64.isBitSet(56)&& data_buffer_64.isBitSet(57))   // else is not possible as one of them will definitely get set
         {		  
            lane_dqs[l_index]=22;
            l_index++; 		    
         }
         if(i_verbose==1)
         {
            FAPI_INF("array is=%d and %d",lane_dqs[0],lane_dqs[1]); 
         } 
         if((l_dq==0) || (l_dq==4))
         {
            l_lane=lane_dqs[0];
         }
         else 
         {
            l_lane=lane_dqs[1];
         }
         
         if(l_dimmtype==fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
         {
            if((i_input_index==1) || (i_input_index==3) || (i_input_index==5) || (i_input_index==7) || (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) || (i_input_index==17) || (i_input_index==19))
            {
               if(l_lane==16)
               {
                  l_lane=18;
               }
               else if(l_lane==18)
               {
                  l_lane=16;
               }
               
               else if(l_lane==20)
               {
                  l_lane=22;
               }
               
               else
               {
                  l_lane=20;
               }
               
            }
         }
         
         else
         {
            if((i_port==0) && (l_mbapos==0))
            {
               if(l_swizzle==1)
               {
                  if((i_input_index==3) || (i_input_index==1) || (i_input_index==4) || (i_input_index==17)|| (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) ||  (i_input_index==6))
                  {
                     if(l_lane==16)
                     {
                        l_lane=18;
                     }
                     else if(l_lane==18)
                     {
                        l_lane=16;
                     }
                     
                     else if(l_lane==20)
                     {
                        l_lane=22;
                     }
                     
                     else
                     {
                        l_lane=20;
                     }
                  
                  }   
               }
                           
               else
               {
                  if((i_input_index==3) || (i_input_index==1) || (i_input_index==5) || (i_input_index==7)|| (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) ||  (i_input_index==17))
                  {
                     if(l_lane==16)
                     {
                        l_lane=18;
                     }
                     else if(l_lane==18)
                     {
                        l_lane=16;
                     }
                       
                     else if(l_lane==20)
                     {
                        l_lane=22;
                     }
                       
                     else
                     {
                        l_lane=20;
                     }
                  }   
                          
               }
            }   
            
            else if((i_port==1) && (l_mbapos==0))
            {
               if(l_swizzle==1)
               {
                  if((i_input_index==2) || (i_input_index==0) || (i_input_index==4) || (i_input_index==17)|| (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) ||  (i_input_index==7))
                  {
                     if(l_lane==16)
                     {
                        l_lane=18;
                     }
                     else if(l_lane==18)
                     {
                        l_lane=16;
                     }
                     
                     else if(l_lane==20)
                     {
                        l_lane=22;
                     }
                  
                     else
                     {
                        l_lane=20;
                     }
                  }   
               }
               
               else
               {
                  if((i_input_index==1) || (i_input_index==3) || (i_input_index==5) || (i_input_index==7)|| (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) ||  (i_input_index==17))
                  {
                     if(l_lane==16)
                     {
                        l_lane=18;
                     }
                     else if(l_lane==18)
                     {
                        l_lane=16;
                     }
                     
                     else if(l_lane==20)
                     {
                        l_lane=22;
                     }
                  
                     else
                     {
                        l_lane=20;
                     }
                  }   
               }
            }
                  
                  
            else
            {
               if((i_input_index==1) || (i_input_index==3) || (i_input_index==5) || (i_input_index==7)|| (i_input_index==9) || (i_input_index==11) || (i_input_index==13) || (i_input_index==15) ||  (i_input_index==17))
               {
                  if(l_lane==16)
                  {
                     l_lane=18;
                  }
                  else if(l_lane==18)
                  {
                     l_lane=16;
                  }
                  
                  else if(l_lane==20)
                  {
                     l_lane=22;
                  }
                  
                  else
                  {
                     l_lane=20;
                  }
               
               }   
            }
            
            
            
         }
         if(i_verbose==1)
         {
            FAPI_INF("lane is=%d",l_lane);
         }   
      }  
      
      // if(i_input_type_e==WR_DQS)	  		  
      // {
         // l_input_type=WR_DQS_t;  
      // }
      // else
      // {
         // l_input_type=DQS_ALIGN_t;
      // }
      
      // rc=get_address(i_target_mba,i_port,i_rank_pair,l_input_type,l_block,l_lane,l_scom_address_64,l_start_bit,l_len); if(rc) return rc; 		 
	 if(flag==0){
	 phy_lane=l_lane;
	  phy_block=l_block;
	  }
	  // out.scom_addr=l_scom_address_64;
      // out.start_bit=l_start_bit;
      // out.bit_length=l_len; 
   } else if (i_input_type_e==RD_DQS || i_input_type_e==DQS_GATE || i_input_type_e==RDCLK || i_input_type_e==DQSCLK)	    
   {
      
      
      if(i_port==0 && l_mbapos==0)
      {
         l_dq=dqs_dq_lane_p0[i_input_index];
         l_block=block_dqs_p0[i_input_index]; 
      }
             
      else if(i_port==1 && l_mbapos==0)
      {
         l_dq=dqs_dq_lane_p1[i_input_index];   
         l_block=block_dqs_p1[i_input_index]; 
      }   
      else if(i_port==0 && l_mbapos==1)
      {
         l_dq=dqs_dq_lane_p2[i_input_index];   
         l_block=block_dqs_p2[i_input_index]; 
      }
      else
      {
         l_dq=dqs_dq_lane_p3[i_input_index];   
         l_block=block_dqs_p3[i_input_index]; 
      }
      
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("dqs_dq_lane=%d",l_dq);
      }   
      if(l_dq==0)
      {
         l_lane=16;
      }
         
      else if(l_dq==4)
      {
         l_lane=18;
      }
         
      else if (l_dq==8)
      {
         l_lane=20;
      }
         
      else
      {
         l_lane=22;
      }
      //FAPI_INF("here");
      
      if (i_input_type_e==DQS_GATE)
      {
         l_input_type=DQS_GATE_t;
      }
      
      else if(i_input_type_e==RDCLK)
      {
         l_input_type=RDCLK_t;
      }
      
      else if(i_input_type_e==RD_DQS)
      {
         l_input_type=RD_DQS_t;
      }
      
      else
      {
         l_input_type=DQSCLK_t;
      }
      
      if(i_verbose==1)
      {
         FAPI_INF("lane is=%d",l_lane);
      }
	  
	  if(flag==0){
	 phy_lane=l_lane;
	  phy_block=l_block;
	  }
      
      // rc=get_address(i_target_mba,i_port,i_rank_pair,l_input_type,l_block,l_lane,l_scom_address_64,l_start_bit,l_len); if(rc) return rc; 		 
      // out.scom_addr=l_scom_address_64;
      // out.start_bit=l_start_bit;
      // out.bit_length=l_len; 
   }   
      
   else
   {
      FAPI_ERR("Wrong input type specified (%d)", i_input_type_e);
      const input_type_t & TYPE_PARAM = i_input_type_e;
      FAPI_SET_HWP_ERROR(rc, RC_MSS_C4_PHY_INVALID_INPUT);
      return rc;
   }  

   return rc;
}
 
fapi::ReturnCode mss_access_delay_reg_schmoo(const fapi::Target & i_target_mba,
                                             access_type_t i_access_type_e,
                                             uint8_t i_port_u8,
                                             uint8_t i_rank_u8,
                                             input_type_t i_input_type_e,
                                             uint8_t i_input_index_u8,
                                             uint8_t i_verbose,
                                             uint16_t &io_value_u16)
{
   // Reference variables for Error FFDC
   const fapi::Target & MBA_TARGET = i_target_mba;
   const access_type_t & ACCESS_TYPE_PARAM = i_access_type_e;
   const uint8_t & PORT_PARAM = i_port_u8;
   const uint8_t & RANK_PARAM = i_rank_u8;
   const input_type_t & TYPE_PARAM = i_input_type_e;
   const uint8_t & INDEX_PARAM = i_input_index_u8;

   fapi::ReturnCode rc; 
    
   const uint8_t max_rp=8; 
   uint8_t l_val=0;
   uint8_t l_dram_width=0;
   scom_location l_out;
   uint64_t l_scom_add=0x0ull;
   uint32_t l_sbit=0;
   uint32_t l_len=0;
   uint32_t l_value_u32=0;
   uint32_t rc_num=0;
   ecmdDataBufferBase data_buffer_64(64);
   ecmdDataBufferBase data_buffer_32(32);
   ecmdDataBufferBase out(16);
   uint32_t l_output=0;
   uint32_t l_start=0;
   uint8_t l_rank_pair=9;
   uint8_t l_rankpair_table[max_rp]={255};
   uint8_t l_dimmtype=0;
   uint8_t l_block=0;
   uint8_t l_lane=0;
   uint8_t l_start_bit=0;
   uint8_t l_len8=0;
   input_type l_type;
   uint8_t l_mbapos=0;
   const uint8_t l_ISDIMM_dqmax=71;
   const uint8_t l_CDIMM_dqmax=79;
   uint8_t l_adr=0;
    const uint8_t addr_max=19;
   const uint8_t cmd_max=3;
   const uint8_t cnt_max=20;
   const uint8_t clk_max=8;
   const uint8_t addr_lanep0[addr_max]={1,5,3,7,10,6,4,10,13,12,9,9,0,0,6,4,1,4,8};
   const uint8_t addr_adrp0[addr_max]={2,1,1,3,1,3,1,3,3,3,2,3,2,3,1,0,3,3,3};
   const uint8_t addr_lanep1[addr_max]={7,10,3,6,8,12,6,1,5,8,2,0,13,4,5,9,6,11,9};
   const uint8_t addr_adrp1[addr_max]={2,1,2,2,1,3,1,1,1,3,1,3,2,3,3,0,0,1,3};
   const uint8_t addr_lanep2[addr_max]={8,0,7,1,12,10,1,5,9,5,13,5,4,2,4,9,10,9,0};
   const uint8_t addr_adrp2[addr_max]={2,2,3,0,3,1,2,0,1,3,2,1,0,2,3,3,3,2,1};
   const uint8_t addr_lanep3[addr_max]={6,2,9,9,2,3,4,10,0,5,1,5,4,1,8,11,5,12,1};
   const uint8_t addr_adrp3[addr_max]={3,0,2,3,2,0,3,3,1,2,2,1,0,1,3,3,0,3,0};
   
   const uint8_t cmd_lanep0[cmd_max]={2,11,5};
   const uint8_t cmd_adrp0[cmd_max]={3,1,3};
   const uint8_t cmd_lanep1[cmd_max]={2,10,10};
   const uint8_t cmd_adrp1[cmd_max]={2,3,2};
   const uint8_t cmd_lanep2[cmd_max]={3,11,3};
   const uint8_t cmd_adrp2[cmd_max]={1,3,0};
   const uint8_t cmd_lanep3[cmd_max]={7,10,7};
   const uint8_t cmd_adrp3[cmd_max]={1,1,3};
   
   const uint8_t cnt_lanep0[cnt_max]={0,7,3,1,7,8,8,3,8,6,7,2,2,0,9,1,3,6,9,2};
   const uint8_t cnt_adrp0[cnt_max]={1,0,3,0,2,2,1,2,0,0,1,2,0,0,1,1,0,2,0,1};
   const uint8_t cnt_lanep1[cnt_max]={5,4,0,5,11,9,10,7,1,11,0,4,12,3,6,8,1,4,7,7};
   const uint8_t cnt_adrp1[cnt_max]={2,1,2,0,2,1,0,1,3,0,1,0,2,1,3,0,2,2,3,0};
   const uint8_t cnt_lanep2[cnt_max]={0,4,7,13,11,5,12,2,3,6,11,6,7,1,10,8,8,2,4,1};
   const uint8_t cnt_adrp2[cnt_max]={0,1,1,3,1,2,2,0,2,2,0,1,2,1,0,3,1,1,2,3};
   const uint8_t cnt_lanep3[cnt_max]={0,11,9,8,4,7,0,3,8,6,13,8,7,0,6,6,1,2,9,5};
   const uint8_t cnt_adrp3[cnt_max]={2,1,0,2,1,0,3,2,0,1,3,1,2,0,0,2,3,1,1,3};
   
   const uint8_t clk_lanep0[clk_max]={10,11,11,10,4,5,13,12};
   const uint8_t clk_adrp0[clk_max]={0,0,2,2,2,2,2,2};
   const uint8_t clk_lanep1[clk_max]={3,2,8,9,1,0,3,2};
   const uint8_t clk_adrp1[clk_max]={3,3,2,2,0,0,0,0};
   const uint8_t clk_lanep2[clk_max]={11,10,6,7,2,3,8,9};
   const uint8_t clk_adrp2[clk_max]={2,2,0,0,3,3,0,0};
   const uint8_t clk_lanep3[clk_max]={3,2,13,12,10,11,11,10};
   const uint8_t clk_adrp3[clk_max]={3,3,2,2,0,0,2,2};
   
   
   rc = mss_getrankpair(i_target_mba,i_port_u8,i_rank_u8,&l_rank_pair,l_rankpair_table);   if(rc) return rc;
   
   rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_dimmtype); if(rc) return rc;
   
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, l_dram_width); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbapos);  if(rc) return rc;
   
   if(i_verbose==1)
   {
      FAPI_INF("dimm type=%d",l_dimmtype);
      FAPI_INF("rank pair=%d",l_rank_pair);       
   }
   if(i_port_u8 >1)
   {
      FAPI_ERR("Wrong port specified (%d)", i_port_u8);
      FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
      return rc;
   }
   
   if (l_mbapos>1)
   {
      FAPI_ERR("Bad position from ATTR_CHIP_UNIT_POS (%d)", l_mbapos);
      const uint8_t & MBA_POS = l_mbapos;
      FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_BAD_MBA_POS);
   }

   if((l_dram_width ==fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4) || (l_dram_width ==fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X8))   // Checking for dram width here so that checking can be skipped in called function
   {
      if(i_verbose==1)
      {
         FAPI_INF("dram width=%d",l_dram_width);
      }
   }
   
   else
   {
      FAPI_ERR("Bad dram width from ATTR_EFF_DRAM_WIDTH (%d)", l_dram_width);
      const uint8_t & DRAM_WIDTH = l_dram_width;
      FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_BAD_DRAM_WIDTH);
      return rc;
   }
   
   if(i_input_type_e==RD_DQ || i_input_type_e==WR_DQ) 
   {
      
      if(l_dimmtype==fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
      {
         l_type=CDIMM_DQ;
         
         if(i_input_index_u8>l_CDIMM_dqmax)    
         {
            FAPI_ERR("CDIMM_DQ: Wrong input index specified (%d, max %d)" ,
                     i_input_index_u8, l_CDIMM_dqmax);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
            return rc;
         }
            
      }
      else
      {
         l_type=ISDIMM_DQ;
         if(i_input_index_u8>l_ISDIMM_dqmax)
         {
            FAPI_ERR("ISDIMM_DQ: Wrong input index specified (%d, max %d)",
                     i_input_index_u8, l_ISDIMM_dqmax);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
            return rc;
         }
      }
         
      rc=rosetta_map(i_target_mba,i_port_u8,l_type,i_input_index_u8,i_verbose,l_val); if(rc) return rc;
      
      if(i_verbose==1)
      {
         FAPI_INF("C4 value is=%d",l_val);
      }   
      rc=cross_coupled(i_target_mba,i_port_u8,l_rank_pair,i_input_type_e,l_val,i_verbose,l_out); if(rc) return rc;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_out.scom_addr);
         FAPI_INF("start bit=%d",l_out.start_bit);
         FAPI_INF("length=%d",l_out.bit_length);
      }   
      l_scom_add=l_out.scom_addr;
      l_sbit=l_out.start_bit;
      l_len=l_out.bit_length;
	 
   }
   
   else if(i_input_type_e==ADDRESS)
   {
      if(i_input_index_u8<=18) // 19 delay values for Address
      {
         if((i_port_u8==0) && (l_mbapos==0))
         {
            l_lane=addr_lanep0[i_input_index_u8];
            l_adr=addr_adrp0[i_input_index_u8];
         }
         else if((i_port_u8==1) && (l_mbapos==0))
         {
            l_lane=addr_lanep1[i_input_index_u8];
            l_adr=addr_adrp1[i_input_index_u8]; 
         }
         else if((i_port_u8==0) && (l_mbapos==1))
         {
            l_lane=addr_lanep2[i_input_index_u8];
            l_adr=addr_adrp2[i_input_index_u8]; 
         }
         else
         {
            l_lane=addr_lanep3[i_input_index_u8];
            l_adr=addr_adrp3[i_input_index_u8]; 
         }
         
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;      
      }
      
      ip_type_t l_input=ADDRESS_t;
      if(i_verbose==1)
      {
         FAPI_INF("ADR=%d",l_adr);
         FAPI_INF("lane=%d",l_lane);
      }
      l_block=l_adr;
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==DATA_DISABLE)
   {
      if(i_input_index_u8<=4) // 5 delay values for data bits disable register
      {
         l_block=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;      
      }
      
      ip_type_t l_input=DATA_DISABLE_t;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
      }
      l_lane=0;
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   
   else if(i_input_type_e==COMMAND)
   {
      if(i_input_index_u8<=2) // 3 delay values for Command
      {
         if((i_port_u8==0) && (l_mbapos==0))
         {
            l_lane=cmd_lanep0[i_input_index_u8];
            l_adr=cmd_adrp0[i_input_index_u8];
         }
         else if((i_port_u8==1) && (l_mbapos==0))
         {
            l_lane=cmd_lanep1[i_input_index_u8];
            l_adr=cmd_adrp1[i_input_index_u8]; 
         }
         else if((i_port_u8==0) && (l_mbapos==1))
         {
            l_lane=cmd_lanep2[i_input_index_u8];
            l_adr=cmd_adrp2[i_input_index_u8]; 
         }
         else
         {
            l_lane=cmd_lanep3[i_input_index_u8];
            l_adr=cmd_adrp3[i_input_index_u8]; 
         }
         
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;      
      }
      
      ip_type_t l_input=COMMAND_t;
      if(i_verbose==1)
      {
         FAPI_INF("ADR=%d",l_adr);
         FAPI_INF("lane=%d",l_lane);
      }
      l_block=l_adr;
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }   
   
    else if(i_input_type_e==CONTROL)
   {
      if(i_input_index_u8<=19) // 20 delay values for Control
      {
         if((i_port_u8==0) && (l_mbapos==0))
         {
            l_lane=cnt_lanep0[i_input_index_u8];
            l_adr=cnt_adrp0[i_input_index_u8];
         }
         else if((i_port_u8==1) && (l_mbapos==0))
         {
            l_lane=cnt_lanep1[i_input_index_u8];
            l_adr=cnt_adrp1[i_input_index_u8]; 
         }
         else if((i_port_u8==0) && (l_mbapos==1))
         {
            l_lane=cnt_lanep2[i_input_index_u8];
            l_adr=cnt_adrp2[i_input_index_u8]; 
         }
         else
         {
            l_lane=cnt_lanep3[i_input_index_u8];
            l_adr=cnt_adrp3[i_input_index_u8]; 
         }
         
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;      
      }
      
      ip_type_t l_input=CONTROL_t;
      if(i_verbose==1)
      {
         FAPI_INF("ADR=%d",l_adr);
         FAPI_INF("lane=%d",l_lane);
      }
      l_block=l_adr;
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==CLOCK)
   {
      if(i_input_index_u8<=7) // 8 delay values for CLK
      {
         if((i_port_u8==0) && (l_mbapos==0))
         {
            l_lane=clk_lanep0[i_input_index_u8];
            l_adr=clk_adrp0[i_input_index_u8];
         }
         else if((i_port_u8==1) && (l_mbapos==0))
         {
            l_lane=clk_lanep1[i_input_index_u8];
            l_adr=clk_adrp1[i_input_index_u8]; 
         }
         else if((i_port_u8==0) && (l_mbapos==1))
         {
            l_lane=clk_lanep2[i_input_index_u8];
            l_adr=clk_adrp2[i_input_index_u8]; 
         }
         else
         {
            l_lane=clk_lanep3[i_input_index_u8];
            l_adr=clk_adrp3[i_input_index_u8]; 
         }
         
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;      
      }
      
      ip_type_t l_input=CLOCK_t;
      if(i_verbose==1)
      {
         FAPI_INF("ADR=%d",l_adr);
         FAPI_INF("lane=%d",l_lane);
      }
      l_block=l_adr;
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }   
   
    
   else if (i_input_type_e==RD_DQS || i_input_type_e==WR_DQS || i_input_type_e==DQS_ALIGN ||  i_input_type_e==DQS_GATE || i_input_type_e==RDCLK || i_input_type_e==DQSCLK)	    
   {
     
      if(l_dimmtype==fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
      {
         l_type=CDIMM_DQS;
      }
      else
      {
         l_type=ISDIMM_DQS;
      }
      
      rc=rosetta_map(i_target_mba,i_port_u8,l_type,i_input_index_u8,i_verbose,l_val); if(rc) return rc;
      if(i_verbose==1)
      {
         FAPI_INF("C4 value is=%d",l_val);
      }
      rc=cross_coupled(i_target_mba,i_port_u8,l_rank_pair,i_input_type_e,l_val,i_verbose,l_out); if(rc) return rc;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_out.scom_addr);
         FAPI_INF("start bit=%d",l_out.start_bit);
         FAPI_INF("length=%d",l_out.bit_length); 
      }
      l_scom_add=l_out.scom_addr;
      l_sbit=l_out.start_bit;
      l_len=l_out.bit_length;   
         
   }
   
   
   else if(i_input_type_e==RAW_RDCLK_0 || i_input_type_e==RAW_RDCLK_1 || i_input_type_e==RAW_RDCLK_2 || i_input_type_e==RAW_RDCLK_3 || i_input_type_e==RAW_RDCLK_4) 
   {
      if(i_input_type_e==RAW_RDCLK_0)
      {
         l_block=0;
      }
      
      else if(i_input_type_e==RAW_RDCLK_1)
      {
         l_block=1;
      }
      
      else if(i_input_type_e==RAW_RDCLK_2)
      {
         l_block=2;
      }
      
      else if(i_input_type_e==RAW_RDCLK_3)
      {
         l_block=3;
      }
      
      else
      {
         l_block=4;
      }
      if(i_input_index_u8<=3) // 4 delay values for RDCLK 
      {
         l_lane=i_input_index_u8;
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;
      }
     
      ip_type_t l_input=RAW_RDCLK;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_DQSCLK_0 || i_input_type_e==RAW_DQSCLK_1 || i_input_type_e==RAW_DQSCLK_2 || i_input_type_e==RAW_DQSCLK_3 || i_input_type_e==RAW_DQSCLK_4)
   {
      if(i_input_type_e==RAW_DQSCLK_0)
      {
         l_block=0;
      }
      
      else if(i_input_type_e==RAW_DQSCLK_1)
      {
         l_block=1;
      }
      
      else if(i_input_type_e==RAW_DQSCLK_2)
      {
         l_block=2;
      }
      
      else if(i_input_type_e==RAW_DQSCLK_3)
      {
         l_block=3;
      }
      
      else
      {
         l_block=4;
      }
      if(i_input_index_u8<=3) // 4 delay values for DQSCLK
      {
         l_lane=i_input_index_u8;
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;      
      }
      ip_type_t l_input=RAW_DQSCLK;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
         
   else if(i_input_type_e==RAW_WR_DQ_0 || i_input_type_e==RAW_WR_DQ_1 || i_input_type_e==RAW_WR_DQ_2 || i_input_type_e==RAW_WR_DQ_3 || i_input_type_e==RAW_WR_DQ_4)
   {
      if(i_input_type_e==RAW_WR_DQ_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_WR_DQ_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_WR_DQ_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_WR_DQ_3)
      {
         l_block=3;
      }
      else
      {
         l_block=4;
      }
      if(i_input_index_u8<=15) // 16 Write delay values for DQ bits
      {
         l_lane=i_input_index_u8;
      }
      
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;      
      }
     
      ip_type_t l_input=RAW_WR_DQ;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_RD_DQ_0 || i_input_type_e==RAW_RD_DQ_1 || i_input_type_e==RAW_RD_DQ_2 || i_input_type_e==RAW_RD_DQ_3 || i_input_type_e==RAW_RD_DQ_4)
   {
      if(i_input_type_e==RAW_RD_DQ_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_RD_DQ_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_RD_DQ_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_RD_DQ_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      }
      if(i_input_index_u8<=15)   // 16 read delay values for DQ bits
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;
      }
      ip_type_t l_input=RAW_RD_DQ;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_RD_DQS_0 || i_input_type_e==RAW_RD_DQS_1 || i_input_type_e==RAW_RD_DQS_2 || i_input_type_e==RAW_RD_DQS_3 || i_input_type_e==RAW_RD_DQS_4)
   {
      if(i_input_type_e==RAW_RD_DQS_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_RD_DQS_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_RD_DQS_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_RD_DQS_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      }
      if(i_input_index_u8<=3) // 4 Read DQS delay values 
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;      
      }
      
      ip_type_t l_input=RAW_RD_DQS;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_DQS_ALIGN_0 || i_input_type_e==RAW_DQS_ALIGN_1 || i_input_type_e==RAW_DQS_ALIGN_2 || i_input_type_e==RAW_DQS_ALIGN_3 || i_input_type_e==RAW_DQS_ALIGN_4)
   {
      if(i_input_type_e==RAW_DQS_ALIGN_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_DQS_ALIGN_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_DQS_ALIGN_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_DQS_ALIGN_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      }
      if(i_input_index_u8<=3)     // 4 DQS alignment delay values
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;
      }
      ip_type_t l_input=RAW_DQS_ALIGN;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   
   else if(i_input_type_e==RAW_WR_DQS_0 || i_input_type_e==RAW_WR_DQS_1 || i_input_type_e==RAW_WR_DQS_2 || i_input_type_e==RAW_WR_DQS_3 || i_input_type_e==RAW_WR_DQS_4)
   {
      if(i_input_type_e==RAW_WR_DQS_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_WR_DQS_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_WR_DQS_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_WR_DQS_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      }
      if(i_input_index_u8<=3)      // 4 Write DQS delay values
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc; 
      }
      ip_type_t l_input=RAW_WR_DQS;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   else if(i_input_type_e==RAW_SYS_CLK_0 || i_input_type_e==RAW_SYS_CLK_1 || i_input_type_e==RAW_SYS_CLK_2 || i_input_type_e==RAW_SYS_CLK_3 || i_input_type_e==RAW_SYS_CLK_4)
   {
      if(i_input_type_e==RAW_SYS_CLK_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_SYS_CLK_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_SYS_CLK_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_SYS_CLK_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      } 
      if(i_input_index_u8==0) // 1 system clock delay value
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc; 
      }
      ip_type_t l_input=RAW_SYS_CLK;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_SYS_ADDR_CLK)
   {
      if(i_input_index_u8<=1)   // 1 system address clock delay value
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc; 
      }
      ip_type_t l_input=RAW_SYS_ADDR_CLKS0S1;
      if(i_verbose==1)
      {
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   
   else if(i_input_type_e==RAW_WR_CLK_0 || i_input_type_e==RAW_WR_CLK_1 || i_input_type_e==RAW_WR_CLK_2 || i_input_type_e==RAW_WR_CLK_3 || i_input_type_e==RAW_WR_CLK_4)
   {
      if(i_input_type_e==RAW_WR_CLK_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_WR_CLK_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_WR_CLK_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_WR_CLK_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      } 
      if(i_input_index_u8==0)           //  1 Write clock delay value
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc; 
      }
      ip_type_t l_input=RAW_WR_CLK;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
   
   else if(i_input_type_e==RAW_ADDR_0 || i_input_type_e==RAW_ADDR_1 || i_input_type_e==RAW_ADDR_2 || i_input_type_e==RAW_ADDR_3)
   {
      if(i_input_type_e==RAW_ADDR_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_ADDR_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_ADDR_2)
      {
         l_block=2;
      }
      else 
      {
         l_block=3;
      }
      if(i_input_index_u8<=15)      //  16 Addr delay values
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc; 
      }
      ip_type_t l_input=RAW_ADDR;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   }
  
   else if(i_input_type_e==RAW_DQS_GATE_0 || i_input_type_e==RAW_DQS_GATE_1 || i_input_type_e==RAW_DQS_GATE_2 || i_input_type_e==RAW_DQS_GATE_3 || i_input_type_e==RAW_DQS_GATE_4)
   {
      if(i_input_type_e==RAW_DQS_GATE_0)
      {
         l_block=0;
      }
      else if(i_input_type_e==RAW_DQS_GATE_1)
      {
         l_block=1;
      }
      else if(i_input_type_e==RAW_DQS_GATE_2)
      {
         l_block=2;
      }
      else if(i_input_type_e==RAW_DQS_GATE_3)
      {
         l_block=3;
      }
      else 
      {
         l_block=4;
      }
              
      if(i_input_index_u8<=3)     // 4 Gate Delay values
      {
         l_lane=i_input_index_u8;
      }
      else
      {
         FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc; 
      }
      ip_type_t l_input=RAW_DQS_GATE;
      if(i_verbose==1)
      {
         FAPI_INF("block=%d",l_block);
         FAPI_INF("lane=%d",l_lane);
      }
      rc=get_address(i_target_mba,i_port_u8,l_rank_pair,l_input,l_block,l_lane,l_scom_add,l_start_bit,l_len8); if(rc) return rc;
      l_sbit=l_start_bit;    
      l_len=l_len8;
      if(i_verbose==1)
      {
         FAPI_INF("scom_address=%llX",l_scom_add);
         FAPI_INF("start bit=%d",l_start_bit);
         FAPI_INF("length=%d",l_len8); 
      }
   } 
   
   else
   {
      FAPI_ERR("Wrong input index specified (%d)", i_input_index_u8);
      FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
      return rc;
   } 
     
   if(i_access_type_e==READ)   
   {
      rc=fapiGetScom(i_target_mba,l_scom_add,data_buffer_64);if(rc) return rc;
      rc_num= rc_num | data_buffer_64.extractToRight(&l_output,l_sbit,l_len);
      if(rc_num)
      {
        FAPI_ERR( "ecmd error on l_scom_add extract");       
	rc.setEcmdError(rc_num);
        return rc;
      }    
	  	rc_num  = data_buffer_32.setWord(0,l_output);if(rc_num) return rc;
io_value_u16=data_buffer_32.getHalfWord(1);
      //io_value_u32=l_output;
	  
      //FAPI_INF(" Abhijit Delay value=%d and original=%d",io_value_u16,l_output);
   }
   
   else if(i_access_type_e==WRITE)
   {
      
      if(i_input_type_e==RD_DQ || i_input_type_e==RD_DQS || i_input_type_e==RAW_RD_DQ_0 || i_input_type_e==RAW_RD_DQ_1 || i_input_type_e==RAW_RD_DQ_2 || i_input_type_e==RAW_RD_DQ_3 || i_input_type_e==RAW_RD_DQ_4 || i_input_type_e==RAW_RD_DQS_0 || i_input_type_e==RAW_RD_DQS_1 || i_input_type_e==RAW_RD_DQS_2 || i_input_type_e==RAW_RD_DQS_3 || i_input_type_e==RAW_RD_DQS_4
      || i_input_type_e==RAW_SYS_ADDR_CLK || i_input_type_e==RAW_SYS_CLK_0 || i_input_type_e==RAW_SYS_CLK_1 || i_input_type_e==RAW_SYS_CLK_2 || i_input_type_e==RAW_SYS_CLK_3 || i_input_type_e==RAW_SYS_CLK_4 || i_input_type_e==RAW_WR_CLK_0 || i_input_type_e==RAW_WR_CLK_1 || i_input_type_e==RAW_WR_CLK_2 || i_input_type_e==RAW_WR_CLK_3 || i_input_type_e==RAW_WR_CLK_4
      || i_input_type_e==RAW_ADDR_0 || i_input_type_e==RAW_ADDR_1 || i_input_type_e==RAW_ADDR_2 || i_input_type_e==RAW_ADDR_3 || i_input_type_e==RAW_DQS_ALIGN_0 || i_input_type_e==RAW_DQS_ALIGN_1 || i_input_type_e==RAW_DQS_ALIGN_2 || i_input_type_e==RAW_DQS_ALIGN_3 || i_input_type_e==RAW_DQS_ALIGN_4
      || i_input_type_e==DQS_ALIGN || i_input_type_e==COMMAND || i_input_type_e==ADDRESS || i_input_type_e==CONTROL || i_input_type_e==CLOCK )   
      {
         l_start=25;   // l_start is starting bit of delay value in the register. There are different registers and each register has a different field for delay
      }
      else if(i_input_type_e==WR_DQ || i_input_type_e==WR_DQS || i_input_type_e==RAW_WR_DQ_0 || i_input_type_e==RAW_WR_DQ_1 || i_input_type_e==RAW_WR_DQ_2 || i_input_type_e==RAW_WR_DQ_3 || i_input_type_e==RAW_WR_DQ_4 || i_input_type_e==RAW_WR_DQS_0 || i_input_type_e==RAW_WR_DQS_1 || i_input_type_e==RAW_WR_DQS_2 || i_input_type_e==RAW_WR_DQS_3 || i_input_type_e==RAW_WR_DQS_4 )
      {
         l_start=22;
      }
   
      else if(i_input_type_e==RAW_DQS_GATE_0 || i_input_type_e==RAW_DQS_GATE_1 || i_input_type_e==RAW_DQS_GATE_2 || i_input_type_e==RAW_DQS_GATE_3 || i_input_type_e==RAW_DQS_GATE_4 || i_input_type_e==DQS_GATE)
      {
         l_start=29;
      }
      
      else if(i_input_type_e==RAW_RDCLK_0 || i_input_type_e==RAW_RDCLK_1 || i_input_type_e==RAW_RDCLK_2 || i_input_type_e==RAW_RDCLK_3 || i_input_type_e==RAW_RDCLK_4 || i_input_type_e==RDCLK || i_input_type_e==RAW_DQSCLK_0 || i_input_type_e==RAW_DQSCLK_1 || i_input_type_e==RAW_DQSCLK_2 || i_input_type_e==RAW_DQSCLK_3 || i_input_type_e==RAW_DQSCLK_4 || i_input_type_e==DQSCLK)
      {
         l_start=30;  
      }
      
      else if(i_input_type_e==DATA_DISABLE)
      {
         l_start=16;
      }
      
      else
      {
         FAPI_ERR("Wrong input type specified (%d)", i_input_type_e);
         FAPI_SET_HWP_ERROR(rc, RC_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT);
         return rc;      
      }
      if(i_verbose==1)
      {
         FAPI_INF("value given=%d",io_value_u16);
      }
      rc_num  = data_buffer_32.setHalfWord(1,io_value_u16);if(rc_num) return rc;
	  l_value_u32  = data_buffer_32.getWord(0);
	  
	 // FAPI_INF("\n Abhijit the original passed=%d and the changed=%d ",io_value_u16,l_value_u32);
      rc=fapiGetScom(i_target_mba,l_scom_add,data_buffer_64);if(rc) return rc;	  
      rc_num=data_buffer_64.insert(l_value_u32,l_sbit,l_len,l_start);
      if(rc_num)
      {
        FAPI_ERR( "ecmd error on l_scom_add extract");       
	rc.setEcmdError(rc_num);
        return rc;
      }    
      rc=fapiPutScom(i_target_mba,l_scom_add,data_buffer_64); if(rc) return rc;
   }
   return rc;
}

} // extern "C"
