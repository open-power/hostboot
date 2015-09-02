/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_funcs.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: mss_funcs.C,v 1.43 2015/09/10 14:57:26 thi Exp $
/* File mss_funcs.C created by SLOAT JACOB D. (JAKE),2D3970 on Fri Apr 22 2011. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
//------------------------------------------------------------------------------
// *! TITLE : mss_funcs.C
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME : jdsloat@us.ibm.com
// *! BACKUP NAME :
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
//  1.43   | thi      |10-SEP-15| Fixed more RC stuff
//  1.42   | kmack    |03-SEP-15| Fixed up some RC stuff
//  1.41   | sglancy  |21-AUG-15| Fixed ODT initialization bug - ODT must be held low through ZQ cal
//  1.40   | sglancy  |09-JUL-15| Added fixes to ZQ cal bug
//  1.39   | sglancy  |27-MAY-15| Added fixes to ZQ cal for 3DS DIMMs
//  1.38   | jdsloat  |01-APL-14| RAS review edits/changes
//  1.37   | jdsloat  |28-MAR-14| RAS review edits/changes
//  1.36   | kcook    | 03/12/14| Added check for DDR3 LRDIMM during mss_execut_zq_cal.
//  1.35   | jdsloat  | 02/21/14| Fixed an inf loop with edit 1.34 and 128GB DIMMs.
//  1.34   | jdsloat  | 02/20/14| Edited set_end_bit to add a NOP to the end of every CCS execution per CCS defect
//  1.33   | kcook    | 08/27/13| Removed LRDIMM functions to mss_lrdimm_funcs.C. Use with mss_funcs.H v1.16.
//  1.32   | kcook    | 08/16/13| Added LRDIMM support. Use with mss_funcs.H v1.15.
//  1.31   | jdsloat  | 05/20/13| Added ddr_gen determination in address mirror mode function
//  1.30   | jdsloat  | 04/09/13| Moved Address mirror mode sub function in  from mss_draminit
//  1.29   | jsabrow  | 11/19/12| added CCS data loader: mss_ccs_load_data_pattern
//  1.28   | bellows  | 07/16/12|added in Id tag
//  1.27   | divyakum | 3/22/12 | Fixed warnings from mss_execute_zq_cal function
//  1.26   | divyakum | 3/22/12 | Fixed mss_execute_zq_cal function variable name mismatch
//  1.25   | divyakum | 3/21/12 | Added mss_execute_zq_cal function
//  1.24   | jdsloat  | 3/20/12 | ccs_inst_arry0 bank fields reverse function removed
//  1.23   | jdsloat  | 3/05/12 | ccs_inst_arry0 address fields reversed - needed to delete commented code out
//  1.22   | jdsloat  | 2/17/12 | ccs_inst_arry0 address fields reversed
//  1.21   | jdsloat  | 2/17/12 | FAPI ERRORs uncommented
//  1.20   | jdsloat  | 2/16/12 | Initialize rc_num
//  1.19   | 2/14/12  |  jdsloat| MBA translation, elminate unnecesary RC returns, got rid of some port arguments
//  1.18   | 2/08/12  |  jdsloat| Target to Target&, Added Error reporting
//  1.17   | 2/02/12  |  jdsloat| Initialized reg_address to 0
//  1.16   | 1/19/12  |  jdsloat| tabs to 4 spaces - properly, cke fix in mss_ccs_inst_arry_0
//  1.15   | 1/16/12  |  jdsloat| tabs to 4 spaces
//  1.14   | 1/13/12  |  jdsloat| Capatilization, curley brackets, "mss_" prefix, adding rc checks, argument prefixes, includes, RC checks
//  1.13   | 1/6/12   |  jdsloat| Got rid of Globals
//  1.12   | 12/23/11 | bellows | Printout poll count
//  1.11   | 12/20/11 | bellows | Fixed up ODT default value of 00 for CCS
//  1.10   | 12/16/11 | bellows | Bit number correction for ras,cas,wen and cal_type
//  1.9    | 12/14/11 | bellows | Fixed Bank and Address bit reversals restored others
//  1.8    | 12/13/11 | jdsloat | Insert from right fix
//  1.7    | 12/13/11 | jdsloat | Bank Address shift for reserved bit - 3 bits long, invert several fields in CCS0
//  1.6    | 10/31/11 | jdsloat | CCS Update - goto_inst now assumed to be +1, CCS_fail fix, CCS_status fix
//  1.5    | 10/18/11 | jdsloat | Debug Messages
//  1.4    | 10/13/11 | jdsloat | End of CCS array check fix
//  1.3    | 10/11/11 | jdsloat | Fix CS Lines, dataBuffer.insert functions
//  1.2    | 10/05/11 | jdsloat | Convert integers to ecmdDataBufferBase in CCS_INST_1, CCS_INST_2, CCS_MODE
//  1.1    | 10/04/11 | jdsloat | First drop of Centaur in FAPI dir
//---------|----------|---------|-----------------------------------------------
//  1.7    | 09/29/11 | jdsloat | Functional Changes: port flow, CCS changes, only configed CS, CCS overflow precaution etc.  Compiles.
//  1.6    | 09/26/11 | jdsloat | Added port information.
//  1.5    | 09/22/11 | jdsloat | Full update to FAPI.  Functional changes to match procedure.
//  1.4    | 09/13/11 | jdsloat | First attempt at FAPI upgrade - attributes still in ecmd.
//  1.1    | 06/27/11 | jdsloat | CCS function update
//  1.00   | 04/22/11 | jdsloat | First drop of Centaur

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <fapi.H>
#include <mss_funcs.H>
#include <cen_scom_addresses.H>
using namespace fapi;

ReturnCode mss_ccs_set_end_bit(
            Target& i_target,
            uint32_t i_instruction_number
              )
{
    uint32_t rc_num = 0;
    ReturnCode rc;
    ecmdDataBufferBase data_buffer(64);

    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase activate_1(1);
    ecmdDataBufferBase rasn_1(1);
    ecmdDataBufferBase casn_1(1);
    ecmdDataBufferBase wen_1(1);
    ecmdDataBufferBase cke_4(4);
    ecmdDataBufferBase csn_8(8);
    ecmdDataBufferBase odt_4(4);
    ecmdDataBufferBase ddr_cal_type_4(4);
    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);

    uint32_t l_port_number = 0xFFFFFFFF;

    i_instruction_number = i_instruction_number + 1;

    FAPI_INF( "Setting End Bit on instruction (NOP): %d.", i_instruction_number);

    // Single NOP with CKE raised high and the end bit set high
    rc_num = rc_num | csn_8.setBit(0,8);
    rc_num = rc_num | address_16.clearBit(0, 16);
    rc_num = rc_num | num_idles_16.clearBit(0, 16);
    rc_num = rc_num | odt_4.clearBit(0,4);
    rc_num = rc_num | csn_8.setBit(0,8);
    rc_num = rc_num | cke_4.setBit(0,4);
    rc_num = rc_num | wen_1.clearBit(0);
    rc_num = rc_num | casn_1.clearBit(0);
    rc_num = rc_num | rasn_1.clearBit(0);
    rc_num = rc_num | ccs_end_1.setBit(0);

    if (rc_num)
    {
        FAPI_ERR( "Error setting up buffers");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = mss_ccs_inst_arry_0( i_target,
                              i_instruction_number,
                              address_16,
                              bank_3,
                              activate_1,
                              rasn_1,
                              casn_1,
                              wen_1,
                              cke_4,
                              csn_8,
                              odt_4,
                              ddr_cal_type_4,
                              l_port_number);
    if(rc) return rc;
    rc = mss_ccs_inst_arry_1( i_target,
                              i_instruction_number,
                              num_idles_16,
                              num_repeat_16,
                              data_20,
                              read_compare_1,
                              rank_cal_4,
                              ddr_cal_enable_1,
                              ccs_end_1);
    if(rc) return rc;

    return rc;
}


ReturnCode mss_address_mirror_swizzle(
            Target& i_target,
            uint32_t i_port,
            uint32_t i_dimm,
            uint32_t i_rank,
            ecmdDataBufferBase& io_address,
            ecmdDataBufferBase& io_bank
              )
{
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    ecmdDataBufferBase address_post_swizzle_16(16);
    ecmdDataBufferBase bank_post_swizzle_3(3);
    uint16_t mirror_mode_ba = 0;
    uint16_t mirror_mode_ad  = 0;
    uint8_t dram_gen = 0;

    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, dram_gen);
    if(rc) return rc;

        FAPI_INF( "ADDRESS MIRRORING ON %s PORT%d DIMM%d RANK%d", i_target.toEcmdString(), i_port, i_dimm, i_rank);

        rc_num = rc_num | io_address.extractPreserve(&mirror_mode_ad, 0, 16, 0);
        FAPI_INF( "PRE - MIRROR MODE ADDRESS: 0x%04X", mirror_mode_ad);
        rc_num = rc_num | io_bank.extractPreserve(&mirror_mode_ba, 0, 3, 0);
        FAPI_INF( "PRE - MIRROR MODE BANK ADDRESS: 0x%04X", mirror_mode_ba);

        //Initialize address and bank address as the same pre mirror mode swizzle
        rc_num = rc_num | address_post_swizzle_16.insert(io_address, 0, 16, 0);
        rc_num = rc_num | bank_post_swizzle_3.insert(io_bank, 0, 3, 0);

        if (rc_num)
        {
            FAPI_ERR( "mss_address_mirror_swizzle: Error setting up buffers");
            rc_buff.setEcmdError(rc_num);
            return rc_buff;
        }
        if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR3)
        {
                //Swap A3 and A4
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 4, 1, 3);
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 3, 1, 4);

                //Swap A5 and A6
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 6, 1, 5);
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 5, 1, 6);

                //Swap A7 and A8
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 8, 1, 7);
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 7, 1, 8);

                //Swap BA0 and BA1
                rc_num = rc_num | bank_post_swizzle_3.insert(io_bank, 1, 1, 0);
                rc_num = rc_num | bank_post_swizzle_3.insert(io_bank, 0, 1, 1);

                if (rc_num)
                {
                    FAPI_ERR( "mss_address_mirror_swizzle: Error setting up buffers");
                    rc_buff.setEcmdError(rc_num);
                    return rc_buff;
                }
        }
        else if (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR4)
        {
                //Swap A3 and A4
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 4, 1, 3);
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 3, 1, 4);

                //Swap A5 and A6
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 6, 1, 5);
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 5, 1, 6);

                //Swap A7 and A8
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 8, 1, 7);
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 7, 1, 8);

                //Swap A11 and A13
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 13, 1, 11);
                rc_num = rc_num | address_post_swizzle_16.insert(io_address, 11, 1, 13);

                //Swap BA0 and BA1
                rc_num = rc_num | bank_post_swizzle_3.insert(io_bank, 1, 1, 0);
                rc_num = rc_num | bank_post_swizzle_3.insert(io_bank, 0, 1, 1);

                //Swap BG0 and BG1 (BA2 and ADDR 15)
                rc_num = rc_num | bank_post_swizzle_3.insert(io_address, 2, 1, 15);
                rc_num = rc_num | address_post_swizzle_16.insert(io_bank, 15, 1, 2);

                if (rc_num)
                {
                    FAPI_ERR( "mss_address_mirror_swizzle: Error setting up buffers");
                    rc_buff.setEcmdError(rc_num);
                    return rc_buff;
                }
        }

        rc_num = rc_num | address_post_swizzle_16.extractPreserve(&mirror_mode_ad, 0, 16, 0);
        FAPI_INF( "POST - MIRROR MODE ADDRESS: 0x%04X", mirror_mode_ad);
        rc_num = rc_num | bank_post_swizzle_3.extractPreserve(&mirror_mode_ba, 0, 3, 0);
        FAPI_INF( "POST - MIRROR MODE BANK ADDRESS: 0x%04X", mirror_mode_ba);

        //copy address and bank address back to the IO variables
        rc_num = rc_num | io_address.insert(address_post_swizzle_16, 0, 16, 0);
        rc_num = rc_num | io_bank.insert(bank_post_swizzle_3, 0, 3, 0);

        if (rc_num)
        {
            FAPI_ERR( "mss_address_mirror_swizzle: Error setting up buffers");
            rc_buff.setEcmdError(rc_num);
            return rc_buff;
        }

    return rc;
}

ReturnCode mss_ccs_inst_arry_0(
            Target& i_target,
            uint32_t& io_instruction_number,
            ecmdDataBufferBase i_address,
            ecmdDataBufferBase i_bank,
            ecmdDataBufferBase i_activate,
            ecmdDataBufferBase i_rasn,
            ecmdDataBufferBase i_casn,
            ecmdDataBufferBase i_wen,
            ecmdDataBufferBase i_cke,
            ecmdDataBufferBase i_csn,
            ecmdDataBufferBase i_odt,
            ecmdDataBufferBase i_ddr_cal_type,
            uint32_t i_port
              )
{
    //Example Use:
    //CCS_INST_ARRY_0( i_target, io_instruction_number, i_address, i_bank, i_activate, i_rasn, i_casn, i_wen, i_cke, i_csn, i_odt, i_ddr_cal_type, i_port);
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint32_t reg_address = 0;
    ecmdDataBufferBase data_buffer(64);

    if ((io_instruction_number >= 30)&&(i_port != 0xFFFFFFFF))
    {
        uint32_t num_retry = 10;
        uint32_t timer = 10;
        rc = mss_ccs_set_end_bit( i_target, 29);
        if(rc) return rc;
        rc = mss_execute_ccs_inst_array( i_target, num_retry, timer);
        if(rc) return rc;
        io_instruction_number = 0;
    }

    if (i_port == 0xFFFFFFFF)
    {
        i_port = 0;
    }

    reg_address = io_instruction_number + CCS_INST_ARRY0_AB_REG0_0x03010615;

    rc_num = rc_num | data_buffer.flushTo0();
    rc_num = rc_num | data_buffer.insert(i_cke, 24, 4, 0);
    rc_num = rc_num | data_buffer.insert(i_cke, 28, 4, 0);

    if (i_port == 0)
    {
        rc_num = rc_num | data_buffer.insert(i_csn, 32, 8, 0);
        rc_num = rc_num | data_buffer.insertFromRight((uint8_t)0xFF,40,8);
        rc_num = rc_num | data_buffer.insert(i_odt, 48, 4, 0);
        rc_num = rc_num | data_buffer.insertFromRight((uint8_t)0x00,52,4);
    }
    else
    {
        rc_num = rc_num | data_buffer.insert((uint8_t)0xFF,32,8);
        rc_num = rc_num | data_buffer.insert(i_csn, 40, 8, 0);
        rc_num = rc_num | data_buffer.insertFromRight((uint8_t)0x00,48,4);
        rc_num = rc_num | data_buffer.insert(i_odt, 52, 4, 0);
    }

    //Placing bits into the data buffer
    rc_num = rc_num | data_buffer.insert( i_address, 0, 16, 0);
    rc_num = rc_num | data_buffer.insert( i_bank, 17, 3, 0);
    rc_num = rc_num | data_buffer.insert( i_activate, 20, 1, 0);
    rc_num = rc_num | data_buffer.insert( i_rasn, 21, 1, 0);
    rc_num = rc_num | data_buffer.insert( i_casn, 22, 1, 0);
    rc_num = rc_num | data_buffer.insert( i_wen, 23, 1, 0);
    rc_num = rc_num | data_buffer.insert( i_ddr_cal_type, 56, 4, 0);

    if (rc_num)
    {
        FAPI_ERR( "mss_ccs_inst_arry_0: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    rc = fapiPutScom(i_target, reg_address, data_buffer);

    return rc;
}

ReturnCode mss_ccs_inst_arry_1(
            Target& i_target,
            uint32_t& io_instruction_number,
            ecmdDataBufferBase i_num_idles,
            ecmdDataBufferBase i_num_repeat,
            ecmdDataBufferBase i_data,
            ecmdDataBufferBase i_read_compare,
            ecmdDataBufferBase i_rank_cal,
            ecmdDataBufferBase i_ddr_cal_enable,
            ecmdDataBufferBase i_ccs_end
            )
{

    //Example Use:
    //CCS_INST_ARRY_1( i_target, io_instruction_number, i_num_idles, i_num_repeat, i_data, i_read_compare, i_rank_cal, i_ddr_cal_enable, i_ccs_end);
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint32_t reg_address = 0;
    ecmdDataBufferBase goto_inst(5);

    if ((io_instruction_number >= 30)&&(i_ccs_end.isBitClear(0)))
    {
        uint32_t num_retry = 10;
        uint32_t timer = 10;
        rc = mss_ccs_set_end_bit( i_target, 29);
        if(rc) return rc;
        rc = mss_execute_ccs_inst_array( i_target, num_retry, timer);
        if(rc) return rc;
        io_instruction_number = 0;
    }

    reg_address = io_instruction_number + CCS_INST_ARRY1_AB_REG0_0x03010635;

    ecmdDataBufferBase data_buffer(64);

    rc_num = rc_num | goto_inst.insertFromRight(io_instruction_number + 1, 0, 5);

    //Setting up a CCS Instruction Array Type 1
    rc_num = rc_num | data_buffer.insert( i_num_idles, 0, 16, 0);
    rc_num = rc_num | data_buffer.insert( i_num_repeat, 16, 16, 0);
    rc_num = rc_num | data_buffer.insert( i_data, 32, 20, 0);
    rc_num = rc_num | data_buffer.insert( i_read_compare, 52, 1, 0);
    rc_num = rc_num | data_buffer.insert( i_rank_cal, 53, 4, 0);
    rc_num = rc_num | data_buffer.insert( i_ddr_cal_enable, 57, 1, 0);
    rc_num = rc_num | data_buffer.insert( i_ccs_end, 58, 1, 0);
    rc_num = rc_num | data_buffer.insert( goto_inst, 59, 5, 0);

    if (rc_num)
    {
        FAPI_ERR( "mss_ccs_inst_arry_1: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    rc = fapiPutScom(i_target, reg_address, data_buffer);

    return rc;
}

//--------------
ReturnCode mss_ccs_load_data_pattern(
            Target& i_target,
            uint32_t io_instruction_number,
            mss_ccs_data_pattern data_pattern)
{
    //Example Use:
    //
    ReturnCode rc;

    if (data_pattern == MSS_CCS_DATA_PATTERN_00)
      {
        rc = mss_ccs_load_data_pattern(i_target, io_instruction_number, 0x00000000);
      }
    else if (data_pattern == MSS_CCS_DATA_PATTERN_0F)
      {
        rc = mss_ccs_load_data_pattern(i_target, io_instruction_number, 0x00055555);
      }
    else if (data_pattern == MSS_CCS_DATA_PATTERN_F0)
      {
        rc = mss_ccs_load_data_pattern(i_target, io_instruction_number, 0x000aaaaa);
      }
    else if (data_pattern == MSS_CCS_DATA_PATTERN_FF)
      {
        rc = mss_ccs_load_data_pattern(i_target, io_instruction_number, 0x000fffff);
      }

    return rc;
}


ReturnCode mss_ccs_load_data_pattern(
            Target& i_target,
            uint32_t io_instruction_number,
            uint32_t data_pattern)
{
    //Example Use:
    //
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint32_t reg_address = 0;

    if (io_instruction_number > 31)
    {
        FAPI_INF("mss_ccs_load_data_pattern: CCS Instruction Array index out of bounds");
    }
    else
    {
      reg_address = io_instruction_number + CCS_INST_ARRY1_AB_REG0_0x03010635;
      ecmdDataBufferBase data_buffer(64);

      //read current array1 reg
      rc = fapiGetScom(i_target, reg_address, data_buffer);
      if(rc) return rc;

      //modify data bits for specified pattern
      rc_num = rc_num | data_buffer.insertFromRight(data_pattern, 32, 20);
      if (rc_num)
        {
        FAPI_ERR( "mss_ccs_load_data_pattern: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
        }

      //write array1 back out
      rc = fapiPutScom(i_target, reg_address, data_buffer);
      if(rc) return rc;
    }

    return rc;
}
//--------------



ReturnCode mss_ccs_mode(
            Target& i_target,
            ecmdDataBufferBase i_stop_on_err,
            ecmdDataBufferBase i_ue_disable,
            ecmdDataBufferBase i_data_sel,
            ecmdDataBufferBase i_pclk,
            ecmdDataBufferBase i_nclk,
            ecmdDataBufferBase i_cal_time_cnt,
            ecmdDataBufferBase i_resetn,
            ecmdDataBufferBase i_reset_recover,
            ecmdDataBufferBase i_copy_spare_cke
              )
{
    ecmdDataBufferBase data_buffer(64);
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;


    rc = fapiGetScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;

    //Setting up CCS mode
    rc_num = rc_num | data_buffer.insert( i_stop_on_err, 0, 1, 0);
    rc_num = rc_num | data_buffer.insert( i_ue_disable, 1, 1, 0);
    rc_num = rc_num | data_buffer.insert( i_data_sel, 2, 2, 0);
    rc_num = rc_num | data_buffer.insert( i_nclk, 4, 2, 0);
    rc_num = rc_num | data_buffer.insert( i_pclk, 6, 2, 0);
    rc_num = rc_num | data_buffer.insert( i_cal_time_cnt, 8, 16, 0);
    rc_num = rc_num | data_buffer.insert( i_resetn, 24, 1, 0);
    rc_num = rc_num | data_buffer.insert( i_reset_recover, 25, 1, 0);
    rc_num = rc_num | data_buffer.insert( i_copy_spare_cke, 26, 1, 0);

    if (rc_num)
    {
        FAPI_ERR( "mss_ccs_mode: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    rc = fapiPutScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;

    return rc;
}

ReturnCode mss_ccs_start_stop(
            Target& i_target,
            bool i_start_stop
              )
{
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    ecmdDataBufferBase data_buffer(64);


    rc = fapiGetScom(i_target, CCS_CNTLQ_AB_REG_0x030106A5, data_buffer);
    if(rc) return rc;

    if (i_start_stop == MSS_CCS_START)
    {
        rc_num = rc_num | data_buffer.setBit(0,1);
        FAPI_INF(" Executing contents of CCS." );
    }
    else if (i_start_stop == MSS_CCS_STOP)
    {
        rc_num = rc_num | data_buffer.setBit(1,1);
        FAPI_INF(" Halting execution of the CCS." );
    }

    if (rc_num)
    {
        FAPI_ERR( "mss_ccs_start_stop: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    rc = fapiPutScom(i_target, CCS_CNTLQ_AB_REG_0x030106A5, data_buffer);

    return rc;
}

ReturnCode mss_ccs_status_query( Target& i_target, mss_ccs_status_query_result& io_status)    {

    ecmdDataBufferBase data_buffer(64);
    ReturnCode rc;

    rc = fapiGetScom(i_target, CCS_STATQ_AB_REG_0x030106A6, data_buffer);
    if(rc) return rc;

    if (data_buffer.getBit(2))
    {
        io_status = MSS_STAT_QUERY_FAIL;
        return rc;
    }
    else if (data_buffer.getBit(0))
    {
        io_status = MSS_STAT_QUERY_IN_PROGRESS;
        return rc;
    }
    else if (data_buffer.getBit(1))
    {
        io_status = MSS_STAT_QUERY_PASS;
    }
    else
    {
        FAPI_INF("CCS Status Undetermined.");
    }
    return rc;
}

ReturnCode mss_ccs_fail_type(
            Target& i_target
            )
{
    ecmdDataBufferBase data_buffer(64);
    ReturnCode rc;

    rc = fapiGetScom(i_target, CCS_STATQ_AB_REG_0x030106A6, data_buffer);
    if(rc) return rc;

    if (data_buffer.getBit(3))
    {
        //DECONFIG and FFDC INFO
        const fapi::Target & TARGET_MBA_ERROR = i_target;
        const ecmdDataBufferBase & REG_CONTENTS = data_buffer;

        FAPI_ERR("CCS returned a FAIL condtion of \"Read Miscompare\" ");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_CCS_READ_MISCOMPARE);
    }
    else if (data_buffer.getBit(4))
    {
        //DECONFIG and FFDC INFO
        const fapi::Target & TARGET_MBA_ERROR = i_target;
        const ecmdDataBufferBase & REG_CONTENTS = data_buffer;

        FAPI_ERR("CCS returned a FAIL condition of \"UE or SUE Error\" ");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_CCS_UE_SUE);
    }
    else if (data_buffer.getBit(5))
    {
        //DECONFIG and FFDC INFO
        const fapi::Target & TARGET_MBA_ERROR = i_target;
        const ecmdDataBufferBase & REG_CONTENTS = data_buffer;

        FAPI_ERR("CCS returned a FAIL condition of \"Calibration Operation Time Out\" ");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_CCS_CAL_TIMEOUT);
    }

    return rc;
}

ReturnCode mss_execute_ccs_inst_array(
        Target& i_target,
        uint32_t i_num_poll,
        uint32_t i_wait_timer
            )
{
    enum mss_ccs_status_query_result status = MSS_STAT_QUERY_IN_PROGRESS;
    uint32_t count = 0;
    ReturnCode rc;

    rc = mss_ccs_start_stop( i_target, MSS_CCS_START);
    if(rc) return rc;

    while ((count < i_num_poll) && (status == MSS_STAT_QUERY_IN_PROGRESS))
    {
        rc = mss_ccs_status_query( i_target, status);
        if(rc) return rc;
        count++;
        fapiDelay(i_wait_timer, i_wait_timer);
    }

    FAPI_INF("CCS Executed Polling %d times.", count);

    if (status == MSS_STAT_QUERY_FAIL)
    {
        FAPI_ERR("CCS FAILED");
        rc = mss_ccs_fail_type(i_target);
        if(rc) return rc;
        FAPI_ERR("CCS has returned a fail.");
    }
    else if (status == MSS_STAT_QUERY_IN_PROGRESS)
    {
        FAPI_ERR("CCS Operation Hung");
        FAPI_ERR("CCS has returned a IN_PROGRESS status and considered Hung.");
        rc = mss_ccs_fail_type(i_target);
        if(rc)
        {
            return rc;
        }
        else
        {
            //DECONFIG and FFDC INFO
            const fapi::Target & TARGET_MBA_ERROR = i_target;

            FAPI_ERR("Returning a CCS HUNG RC Value.");
            FAPI_SET_HWP_ERROR(rc, RC_MSS_CCS_HUNG);
            return rc;
        }
    }
    else if (status == MSS_STAT_QUERY_PASS)
    {
        FAPI_INF("CCS Executed Successfully.");
    }
    else
    {
        FAPI_INF("CCS Status Undetermined.");
    }

    return rc;
}

uint32_t mss_reverse_32bits(uint32_t i_x)
{
    //reversing bit order of a 32 bit uint
    i_x = (((i_x & 0xaaaaaaaa) >> 1) | ((i_x & 0x55555555) << 1));
    i_x = (((i_x & 0xcccccccc) >> 2) | ((i_x & 0x33333333) << 2));
    i_x = (((i_x & 0xf0f0f0f0) >> 4) | ((i_x & 0x0f0f0f0f) << 4));
    i_x = (((i_x & 0xff00ff00) >> 8) | ((i_x & 0x00ff00ff) << 8));
    return((i_x >> 16) | (i_x << 16));
}

uint8_t mss_reverse_8bits(uint8_t i_number){

    //reversing bit order of a 8 bit uint
    uint8_t temp = 0;
    for (uint8_t loop = 0; loop < 8; loop++)
    {
        uint8_t bit = (i_number&(1<<loop))>>loop;
        temp |= bit<<(7-loop);
    }
    return temp;
}



ReturnCode mss_rcd_parity_check(
            Target& i_target,
            uint32_t i_port
            )
{
    //checks all ports for a parity error
    ecmdDataBufferBase data_buffer(64);
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint8_t port_0_error = 0;
    uint8_t port_1_error = 0;
    uint8_t rcd_parity_fail = 0;

    rc = fapiGetScom(i_target, MBA01_CALFIR_REG_0x03010402, data_buffer);
    if(rc) return rc;

    rc_num = rc_num | data_buffer.extract(&port_0_error, 4, 1);
    rc_num = rc_num | data_buffer.extract(&port_1_error, 7, 1);
    rc_num = rc_num | data_buffer.extract(&rcd_parity_fail, 5, 1);
    if (rc_num)
    {
        FAPI_ERR( "mss_rcd_parity_check: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    FAPI_INF("Checking for RCD Parity Error.");

    if (rcd_parity_fail)
    {
        //DECONFIG and FFDC INFO
        const fapi::Target & TARGET_MBA_ERROR = i_target;

        FAPI_ERR("Ports 0 and 1 has exceeded a maximum number of RCD Parity Errors.");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_RCD_PARITY_ERROR_LIMIT);
    }
    else if ((port_0_error) && (i_port == 0))
    {
        //DECONFIG and FFDC INFO
        const fapi::Target & TARGET_MBA_ERROR = i_target;

        FAPI_ERR("Port 0 has recorded an RCD Parity Error. ");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_RCD_PARITY_ERROR_PORT0);
    }
    else if ((port_1_error) && (i_port == 1))
    {
        //DECONFIG and FFDC INFO
        const fapi::Target & TARGET_MBA_ERROR = i_target;

        FAPI_ERR("Port 1 has recorded an RCD Parity Error. ");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_RCD_PARITY_ERROR_PORT1);
    }
    else
    {
        FAPI_INF("No RCD Parity Errors on Port %d.", i_port);
    }

    return rc;
}

//ZQ Cal
ReturnCode mss_execute_zq_cal(
            Target& i_target,
            uint8_t i_port
            )
{
    //Enums and Constants
    enum size
    {
       MAX_NUM_DIMM = 2,
    };

    uint32_t NUM_POLL = 100;

    uint32_t instruction_number = 0;
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;

    //adds a NOP before ZQ cal
    ecmdDataBufferBase address_buffer_16(16);
    rc_num = rc_num | address_buffer_16.setHalfWord(0, 0x0000); //Set A10 bit for ZQCal Long
    ecmdDataBufferBase bank_buffer_8(8);
    rc_num = rc_num | bank_buffer_8.flushTo0();
    ecmdDataBufferBase activate_buffer_1(1);
    rc_num = rc_num | activate_buffer_1.flushTo1();
    ecmdDataBufferBase rasn_buffer_1(1);
    rc_num = rc_num | rasn_buffer_1.flushTo1(); //For NOP rasn = 1; casn = 1; wen = 1;
    ecmdDataBufferBase casn_buffer_1(1);
    rc_num = rc_num | casn_buffer_1.flushTo1();
    ecmdDataBufferBase wen_buffer_1(1);
    rc_num = rc_num | wen_buffer_1.flushTo1();
    ecmdDataBufferBase cke_buffer_8(8);
    rc_num = rc_num | cke_buffer_8.flushTo1();
    ecmdDataBufferBase csn_buffer_8(8);
    rc_num = rc_num | csn_buffer_8.flushTo1();;
    ecmdDataBufferBase odt_buffer_8(8);
    rc_num = rc_num | odt_buffer_8.flushTo0();
    ecmdDataBufferBase test_buffer_4(4);
    rc_num = rc_num | test_buffer_4.flushTo0(); // 01XX:External ZQ calibration
    rc_num = rc_num | test_buffer_4.setBit(1);
    ecmdDataBufferBase num_idles_buffer_16(16);
    rc_num = rc_num | num_idles_buffer_16.setHalfWord(0, 0x0400); //1024 for ZQCal
    ecmdDataBufferBase num_repeat_buffer_16(16);
    rc_num = rc_num | num_repeat_buffer_16.flushTo0();
    ecmdDataBufferBase data_buffer_20(20);
    rc_num = rc_num | data_buffer_20.flushTo0();
    ecmdDataBufferBase read_compare_buffer_1(1);
    rc_num = rc_num | read_compare_buffer_1.flushTo0();
    ecmdDataBufferBase rank_cal_buffer_3(3);
    rc_num = rc_num | rank_cal_buffer_3.flushTo0();
    ecmdDataBufferBase ddr_cal_enable_buffer_1(1);
    rc_num = rc_num | ddr_cal_enable_buffer_1.flushTo0();
    ecmdDataBufferBase ccs_end_buffer_1(1);
    rc_num = rc_num | ccs_end_buffer_1.flushTo0();

    ecmdDataBufferBase stop_on_err_buffer_1(1);
    rc_num = rc_num | stop_on_err_buffer_1.flushTo0();
    ecmdDataBufferBase resetn_buffer_1(1);
    rc_num = rc_num | resetn_buffer_1.setBit(0);
    ecmdDataBufferBase data_buffer_64(64);
    rc_num = rc_num | data_buffer_64.flushTo0();

    if (rc_num)
    {
        FAPI_ERR( "mss_execute_zq_cal: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    rc = mss_ccs_inst_arry_0(i_target, instruction_number, address_buffer_16, bank_buffer_8, activate_buffer_1, rasn_buffer_1, casn_buffer_1, wen_buffer_1, cke_buffer_8, csn_buffer_8, odt_buffer_8, test_buffer_4, i_port);
    if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs
    rc = mss_ccs_inst_arry_1(i_target, instruction_number, num_idles_buffer_16, num_repeat_buffer_16, data_buffer_20, read_compare_buffer_1, rank_cal_buffer_3, ddr_cal_enable_buffer_1, ccs_end_buffer_1);
    if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs

    rc = mss_ccs_inst_arry_0(i_target, instruction_number, address_buffer_16, bank_buffer_8, activate_buffer_1, rasn_buffer_1, casn_buffer_1, wen_buffer_1, cke_buffer_8, csn_buffer_8, odt_buffer_8, test_buffer_4, i_port);
    if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs
    rc = mss_ccs_inst_arry_1(i_target, instruction_number, num_idles_buffer_16, num_repeat_buffer_16, data_buffer_20, read_compare_buffer_1, rank_cal_buffer_3, ddr_cal_enable_buffer_1, ccs_end_buffer_1);
    if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs

    rc = mss_ccs_inst_arry_0(i_target, instruction_number, address_buffer_16, bank_buffer_8, activate_buffer_1, rasn_buffer_1, casn_buffer_1, wen_buffer_1, cke_buffer_8, csn_buffer_8, odt_buffer_8, test_buffer_4, i_port);
    if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs
    rc = mss_ccs_inst_arry_1(i_target, instruction_number, num_idles_buffer_16, num_repeat_buffer_16, data_buffer_20, read_compare_buffer_1, rank_cal_buffer_3, ddr_cal_enable_buffer_1, ccs_end_buffer_1);
    if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs

    instruction_number = 1;

    //now sets up for ZQ CAL
    rc_num = rc_num | address_buffer_16.setHalfWord(0, 0x0020); //Set A10 bit for ZQCal Long
    rc_num = rc_num | bank_buffer_8.flushTo0();
    rc_num = rc_num | activate_buffer_1.flushTo1();
    rc_num = rc_num | rasn_buffer_1.flushTo1(); //For ZQCal rasn = 1; casn = 1; wen = 0;
    rc_num = rc_num | casn_buffer_1.flushTo1();
    rc_num = rc_num | wen_buffer_1.flushTo0();
    rc_num = rc_num | cke_buffer_8.flushTo1();
    rc_num = rc_num | odt_buffer_8.flushTo0();
    rc_num = rc_num | test_buffer_4.flushTo0(); // 01XX:External ZQ calibration
    rc_num = rc_num | test_buffer_4.setBit(1);
    rc_num = rc_num | num_idles_buffer_16.setHalfWord(0, 0x0400); //1024 for ZQCal
    rc_num = rc_num | num_repeat_buffer_16.flushTo0();
    rc_num = rc_num | data_buffer_20.flushTo0();
    rc_num = rc_num | read_compare_buffer_1.flushTo0();
    rc_num = rc_num | rank_cal_buffer_3.flushTo0();
    rc_num = rc_num | ddr_cal_enable_buffer_1.flushTo0();
    rc_num = rc_num | ccs_end_buffer_1.flushTo0();
    rc_num = rc_num | stop_on_err_buffer_1.flushTo0();
    rc_num = rc_num | resetn_buffer_1.setBit(0);
    rc_num = rc_num | data_buffer_64.flushTo0();

    if (rc_num)
    {
        FAPI_ERR( "mss_execute_zq_cal: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }


    uint8_t current_rank = 0;
    uint8_t start_rank = 0;
    uint8_t num_master_ranks_array[2][2];
    uint8_t num_ranks_array[2][2]; //num_ranks_array[port][dimm]
    uint8_t stack_type[2][2];
    uint8_t dimm_type;
    uint8_t lrdimm_rank_mult_mode;
    uint8_t dram_gen = 0;
    uint8_t rank_end = 0;

    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, dram_gen);
    if(rc) return rc;

    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, stack_type);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target, num_master_ranks_array);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;

    //Set up CCS Mode Reg for ZQ cal long and Init cal
    rc = fapiGetScom(i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data_buffer_64);
    if(rc) return rc;

    rc_num = rc_num | data_buffer_64.insert(stop_on_err_buffer_1, 0, 1, 0);
    rc_num = rc_num | data_buffer_64.insert(resetn_buffer_1, 24, 1, 0);
    if(rc_num)
    {
        rc.setEcmdError(rc_num);
        return rc;
    }
     rc = fapiPutScom(i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data_buffer_64);
    if(rc) return rc;

    for(uint8_t dimm = 0; dimm < MAX_NUM_DIMM; dimm++)
    {
        start_rank=(4 * dimm);

        if ( (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) && (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR3) )
        {
           rc = FAPI_ATTR_GET(ATTR_LRDIMM_RANK_MULT_MODE, &i_target, lrdimm_rank_mult_mode);
           if(rc) return rc;

           if ( num_ranks_array[i_port][dimm] == 8 && lrdimm_rank_mult_mode == 4)
           { // For LRDIMM 8 Rank, RM=4, CS0 and CS1 to execute ZQ cal
              rank_end = 2;
           }
        }
        else if(stack_type[i_port][dimm] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
           rank_end = num_master_ranks_array[i_port][dimm];
        }
        else {
           rank_end = num_ranks_array[i_port][dimm];
        }

        for(current_rank = start_rank; current_rank < start_rank + rank_end; current_rank++) {
            FAPI_INF( "+++++++++++++++ Sending zqcal to port: %d rank: %d +++++++++++++++", i_port, current_rank);
            rc_num = rc_num | csn_buffer_8.flushTo1();
            rc_num = rc_num | csn_buffer_8.clearBit(current_rank);
            if(rc_num)
            {
                rc.setEcmdError(rc_num);
                return rc;
            }

            //Issue execute.
            FAPI_INF( "+++++++++++++++ Execute CCS array on port: %d +++++++++++++++", i_port);
            rc = mss_ccs_inst_arry_0(i_target, instruction_number, address_buffer_16, bank_buffer_8, activate_buffer_1, rasn_buffer_1, casn_buffer_1, wen_buffer_1, cke_buffer_8, csn_buffer_8, odt_buffer_8, test_buffer_4, i_port);
            if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs
            rc = mss_ccs_inst_arry_1(i_target, instruction_number, num_idles_buffer_16, num_repeat_buffer_16, data_buffer_20, read_compare_buffer_1, rank_cal_buffer_3, ddr_cal_enable_buffer_1, ccs_end_buffer_1);
            if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs
            rc = mss_ccs_set_end_bit(i_target,instruction_number);
            if(rc) return rc;
            rc = mss_execute_ccs_inst_array(i_target, NUM_POLL, 60);
            instruction_number = 1;
            if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs
        }
    }
return rc;
}

