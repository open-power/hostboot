/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_ddr4_funcs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
// $Id: mss_ddr4_funcs.C,v 1.23 2016/02/19 21:14:32 sglancy Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : mss_ddr4_funcs.C
// *! DESCRIPTION : Tools for DDR4 DIMMs centaur procedures
// *! OWNER NAME : jdsloat@us.ibm.com
// *! BACKUP NAME : sglancy@us.ibm.com
// #! ADDITIONAL COMMENTS :
//

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//         |          |         |
//  1.22   | 02/19/16 | sglancy | Fixed B-side MRS inversion bug
//  1.21   | 02/12/16 | sglancy | Addressed FW comments
//  1.20   | 01/14/16 | sglancy | Fixed bug in termination swap code
//  1.19   | 11/16/15 | sglancy | Fixed R/LRDIMM bug
//  1.18   | 11/03/15 | sglancy | Fixed attribute names for DDR4 RDIMM
//  1.17   | 10/23/15 | sglancy | Changed attribute names
//  1.16   | 10/21/15 | sglancy | Changed attribute names
//  1.15   | 08/28/15 | sglancy | Added RCs - addressed FW comments
//  1.14   | 08/21/15 | sglancy | Fixed ODT initialization bug - ODT must be held low through ZQ cal 
//  1.13   | 08/05/15 | kmack   | Commented out FAPI_DDR4 code
//  1.12   | 07/31/15 | kmack   | Mostly removed and changed comments.  Reviewed some questions about the code. No real functional changes
//         |          |         | Need new ATTRIBUTE, see comments with FIXME
//  1.11   | 07/15/15 | sglancy | Addeded DDR4 Register functions and changes for DDR4 LRDIMM
//  1.10   | 05/14/15 | sglancy | Addeded DDR4 Register functions and changes for DDR4 3DS
//  1.7    | 03/14/14 | kcook   | Addeded DDR4 Register functions
//  1.6    | 01/10/14 | kcook   | Updated Address mirroring swizzle (removed DIMM_TYPE_CDIMM) and
//         |          |         | added DDR4 RDIMM support
//  1.5    | 12/03/13 | kcook   | Updated VPD attributes.
//  1.4    | 11/27/13 | bellows | Added using namespace fapi
//  1.3    | 10/10/13 | bellows | Added required cvs id tag
//  1.2    | 10/09/13 | jdsloat | Added CONSTs
//  1.1    | 10/04/13 | jdsloat | First revision


//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_funcs.H>
#include <cen_scom_addresses.H>
#include <mss_ddr4_funcs.H>

using namespace fapi;

//#ifdef FAPI_DDR4

const uint8_t MAX_NUM_DIMMS = 2;
const uint8_t MRS0_BA = 0;
const uint8_t MRS1_BA = 1;
const uint8_t MRS2_BA = 2;
const uint8_t MRS3_BA = 3;
const uint8_t MRS4_BA = 4;
const uint8_t MRS5_BA = 5;
const uint8_t MRS6_BA = 6;

const uint8_t PORT_SIZE = 2;

ReturnCode mss_ddr4_invert_mpr_write( Target& i_target_mba) {
   ReturnCode rc;
    uint32_t rank_number;

    ReturnCode rc_buff;
    uint32_t rc_num = 0;

    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase activate_1(1);
    rc_num = rc_num | activate_1.setBit(0);
    ecmdDataBufferBase rasn_1(1);
    rc_num = rc_num | rasn_1.clearBit(0);
    ecmdDataBufferBase casn_1(1);
    rc_num = rc_num | casn_1.clearBit(0);
    ecmdDataBufferBase wen_1(1);
    rc_num = rc_num | wen_1.clearBit(0);
    ecmdDataBufferBase cke_4(4);
    rc_num = rc_num | cke_4.setBit(0,4);
    ecmdDataBufferBase csn_8(8);
    rc_num = rc_num | csn_8.setBit(0,8);
    ecmdDataBufferBase odt_4(4);
    rc_num = rc_num | odt_4.clearBit(0,4);
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);

    ecmdDataBufferBase mrs3(16);
    uint16_t MRS3 = 0;
    uint8_t mpr_op; // MPR Op

    ecmdDataBufferBase data_buffer(64);

    uint32_t io_ccs_inst_cnt = 0;

    uint16_t num_ranks = 0;
    uint8_t mpr_pattern = 0xAA;
    
    if(rc_num)
    {
    	rc.setEcmdError(rc_num);
    	return rc;
    }
    
    uint8_t num_ranks_array[2][2]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, num_ranks_array);
    if(rc) return rc;

    uint8_t num_master_ranks_array[2][2]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target_mba, num_master_ranks_array);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ADDRESS_MIRRORING, &i_target_mba, address_mirror_map);
    if(rc) return rc;

   uint8_t dram_stack[2][2];
    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target_mba, dram_stack);
    if(rc) return rc;

   for (uint8_t l_port = 0; l_port < PORT_SIZE; l_port++) {
      // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
      rc_num = rc_num | csn_8.setBit(0,8);
      rc_num = rc_num | address_16.clearBit(0, 16);
      rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 400, 0, 16);

       FAPI_INF( "Stack Type in mss_ddr4_invert_mpr_write : %d\n", dram_stack[0][0]);
      if (dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS)
      {
         FAPI_INF( "=============  Got in the 3DS stack loop =====================\n");
         rc_num = rc_num | csn_8.clearBit(2,2);
         rc_num = rc_num | csn_8.clearBit(6,2);
        // COMMENT IN LATER!!!!!! rc_num = rc_num | cke_4.clearBit(1);
      }

      if(rc_num)
      {
          rc.setEcmdError(rc_num);
          return rc;
      }
      rc = mss_ccs_inst_arry_0( i_target_mba,
                                io_ccs_inst_cnt,
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
                                l_port);
      if(rc) return rc;
      rc = mss_ccs_inst_arry_1( i_target_mba,
                                io_ccs_inst_cnt,
                                num_idles_16,
                                num_repeat_16,
                                data_20,
                                read_compare_1,
                                rank_cal_4,
                                ddr_cal_enable_1,
                                ccs_end_1);
      if(rc) return rc;
      io_ccs_inst_cnt ++;

      for (uint8_t l_dimm = 0; l_dimm < MAX_NUM_DIMMS; l_dimm++) {
         if (dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS)
         {
            num_ranks = num_master_ranks_array[l_port][l_dimm];
         }
         else {
            num_ranks = num_ranks_array[l_port][l_dimm];
         }

         if (num_ranks == 0)
         {
            FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d ", l_port, l_dimm, num_ranks);
         }
         else
         {
            // Rank 0-3
            for ( rank_number = 0; rank_number < num_ranks; rank_number++)
            {

                rc_num = rc_num | csn_8.setBit(0,8);
                rc_num = rc_num | csn_8.clearBit(rank_number+4*l_dimm);
                rc_num = rc_num | address_16.clearBit(0, 16);

                // MRS CMD to CMD spacing = 12 cycles
                rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 24, 0, 16);
                if(rc_num)
                {
                    rc.setEcmdError(rc_num);
                    return rc;
                }

                if (l_port == 0) {
                    rc = fapiGetScom(i_target_mba, DPHY01_DDRPHY_PC_MR3_PRI_RP0_P0_0x8000C01F0301143F, data_buffer); // Need to look up Rank Group???
		    if(rc) return rc;
                }
                else if ( l_port == 1 ) {
                    rc = fapiGetScom(i_target_mba, DPHY01_DDRPHY_PC_MR3_PRI_RP0_P1_0x8001C01F0301143F, data_buffer); // Need to look up Rank Group???
		    if(rc) return rc;
                }

                rc_num = rc_num | data_buffer.reverse();
                rc_num = rc_num | mrs3.insert(data_buffer, 0, 16, 0);
                rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);

                if(rc_num)
                {
                    rc.setEcmdError(rc_num);
                    return rc;
                }

                FAPI_INF( "CURRENT MRS 3: 0x%04X", MRS3);

                mpr_op = 0xff;

                rc_num = rc_num | mrs3.insert((uint8_t) mpr_op, 2, 1);

                rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
                FAPI_INF( "Set data flow from MPR, New MRS 3: 0x%04X", MRS3);

                if (rc_num)
                {
                    FAPI_ERR( " Error setting up buffers");
                    rc_buff.setEcmdError(rc_num);
                    return rc_buff;
                }


                rc_num = rc_num | address_16.insert(mrs3, 0, 16, 0);
                rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
                rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
                rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);

                // Indicate B-Side DRAMS BG1=1
                rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1

                rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
                rc_num = rc_num | address_16.flipBit(11);  // Invert A11
                rc_num = rc_num | address_16.flipBit(13);  // Invert A13
                rc_num = rc_num | address_16.flipBit(14);  // Invert A17
                rc_num = rc_num | bank_3.flipBit(0,3);     // Invert BA0,BA1,BG0

                if (rc_num)
                {
                    FAPI_ERR( " Error setting up buffers");
                    rc_buff.setEcmdError(rc_num);
                    return rc_buff;
                }


                if (( address_mirror_map[l_port][l_dimm] & (0x08 >> rank_number) ) && (is_sim == 0))
                {
                    rc = mss_address_mirror_swizzle(i_target_mba, l_port, l_dimm, rank_number, address_16, bank_3);
                    if(rc) return rc;
                }

                // Send out to the CCS array
                rc = mss_ccs_inst_arry_0( i_target_mba,
                                  io_ccs_inst_cnt,
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
                                  l_port);
                if(rc) return rc;
                rc = mss_ccs_inst_arry_1( i_target_mba,
                                  io_ccs_inst_cnt,
                                  num_idles_16,
                                  num_repeat_16,
                                  data_20,
                                  read_compare_1,
                                  rank_cal_4,
                                  ddr_cal_enable_1,
                                  ccs_end_1);
                if(rc) return rc;
                io_ccs_inst_cnt ++;


                // Write pattern to MPR register
                //Command structure setup
                rc_num = rc_num | cke_4.flushTo1();
                rc_num = rc_num | rasn_1.setBit(0);
                rc_num = rc_num | casn_1.clearBit(0);
                rc_num = rc_num | wen_1.clearBit(0);


                //Final setup
                rc_num = rc_num | odt_4.flushTo0();
                rc_num = rc_num | ddr_cal_type_4.flushTo0();
                rc_num = rc_num | activate_1.setBit(0);


                //CCS Array 1 Setup
                rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 24, 0, 16);
                rc_num = rc_num | num_repeat_16.flushTo0();
                rc_num = rc_num | data_20.flushTo0();
                rc_num = rc_num | read_compare_1.flushTo0();
                rc_num = rc_num | rank_cal_4.flushTo0();
                rc_num = rc_num | ddr_cal_enable_1.flushTo0();
                rc_num = rc_num | ccs_end_1.flushTo0();

                rc_num = rc_num | address_16.clearBit(0, 16);
                rc_num = rc_num | address_16.insertFromRight(mpr_pattern,0, 8);

                rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
                rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
                rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);

                // Indicate B-Side DRAMS BG1=1
                rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1

                rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
                rc_num = rc_num | address_16.flipBit(11);  // Invert A11
                rc_num = rc_num | address_16.flipBit(13);  // Invert A13
                rc_num = rc_num | address_16.flipBit(14);  // Invert A17
                rc_num = rc_num | bank_3.flipBit(0,3);     // Invert BA0,BA1,BG0

                if (rc_num)
                {
                    FAPI_ERR( " Error setting up buffers");
                    rc_buff.setEcmdError(rc_num);
                    return rc_buff;
                }


                if (( address_mirror_map[l_port][l_dimm] & (0x08 >> rank_number) ) && (is_sim == 0))
                {
                    rc = mss_address_mirror_swizzle(i_target_mba, l_port, l_dimm, rank_number, address_16, bank_3);
                    if(rc) return rc;
                }

                FAPI_INF( "Writing MPR register with 0101 pattern");
                // Send out to the CCS array
                rc = mss_ccs_inst_arry_0( i_target_mba,
                                  io_ccs_inst_cnt,
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
                                  l_port);
                if(rc) return rc;
                rc = mss_ccs_inst_arry_1( i_target_mba,
                                  io_ccs_inst_cnt,
                                  num_idles_16,
                                  num_repeat_16,
                                  data_20,
                                  read_compare_1,
                                  rank_cal_4,
                                  ddr_cal_enable_1,
                                  ccs_end_1);
                if(rc) return rc;
                io_ccs_inst_cnt ++;

                // Restore MR3 to normal MPR operation
                //Command structure setup
                rc_num = rc_num | cke_4.flushTo1();
                rc_num = rc_num | rasn_1.clearBit(0);
                rc_num = rc_num | casn_1.clearBit(0);
                rc_num = rc_num | wen_1.clearBit(0);

                rc_num = rc_num | read_compare_1.clearBit(0);

                rc_num = rc_num | odt_4.flushTo0();
                rc_num = rc_num | ddr_cal_type_4.flushTo0();
                rc_num = rc_num | activate_1.setBit(0);

                rc_num = rc_num | num_repeat_16.flushTo0();
                rc_num = rc_num | data_20.flushTo0();
                rc_num = rc_num | read_compare_1.flushTo0();
                rc_num = rc_num | rank_cal_4.flushTo0();
                rc_num = rc_num | ddr_cal_enable_1.flushTo0();
                rc_num = rc_num | ccs_end_1.flushTo0();

                rc_num = rc_num | address_16.clearBit(0, 16);

                // MRS CMD to CMD spacing = 12 cycles
                rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 24, 0, 16);
                if(rc_num)
                {
                    rc.setEcmdError(rc_num);
                    return rc;
                }

                if (l_port == 0) {
                    rc = fapiGetScom(i_target_mba, DPHY01_DDRPHY_PC_MR3_PRI_RP0_P0_0x8000C01F0301143F, data_buffer); // Need to look up Rank Group???
		    if(rc) return rc;
                }
                else if ( l_port == 1 ) {
                    rc = fapiGetScom(i_target_mba, DPHY01_DDRPHY_PC_MR3_PRI_RP0_P1_0x8001C01F0301143F, data_buffer); // Need to look up Rank Group???
		    if(rc) return rc;
                }

                rc_num = rc_num | data_buffer.reverse();
                rc_num = rc_num | mrs3.insert(data_buffer, 0, 16, 0);
                rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);

                if(rc_num)
                {
                    rc.setEcmdError(rc_num);
                    return rc;
                }

                FAPI_INF( "CURRENT MRS 3: 0x%04X", MRS3);

                mpr_op = 0x00;

                rc_num = rc_num | mrs3.insert((uint8_t) mpr_op, 2, 1);

                rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
                FAPI_INF( "Set data flow from MPR, New MRS 3: 0x%04X", MRS3);

                if (rc_num)
                {
                    FAPI_ERR( " Error setting up buffers");
                    rc_buff.setEcmdError(rc_num);
                    return rc_buff;
                }


                rc_num = rc_num | address_16.insert(mrs3, 0, 16, 0);
                rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
                rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
                rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);

                // Indicate B-Side DRAMS BG1=1
                rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1

                rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
                rc_num = rc_num | address_16.flipBit(11);  // Invert A11
                rc_num = rc_num | address_16.flipBit(13);  // Invert A13
                rc_num = rc_num | address_16.flipBit(14);  // Invert A17
                rc_num = rc_num | bank_3.flipBit(0,3);     // Invert BA0,BA1,BG0


                if (( address_mirror_map[l_port][l_dimm] & (0x08 >> rank_number) ) && (is_sim == 0))
                {
                    rc = mss_address_mirror_swizzle(i_target_mba, l_port, l_dimm, rank_number, address_16, bank_3);
                    if(rc) return rc;
                }


                if (rc_num)
                {
                    FAPI_ERR( " Error setting up buffers");
                    rc_buff.setEcmdError(rc_num);
                    return rc_buff;
                }

                // Send out to the CCS array
                rc = mss_ccs_inst_arry_0( i_target_mba,
                                  io_ccs_inst_cnt,
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
                                  l_port);
                if(rc) return rc;
                rc = mss_ccs_inst_arry_1( i_target_mba,
                                  io_ccs_inst_cnt,
                                  num_idles_16,
                                  num_repeat_16,
                                  data_20,
                                  read_compare_1,
                                  rank_cal_4,
                                  ddr_cal_enable_1,
                                  ccs_end_1);
                if(rc) return rc;
                io_ccs_inst_cnt ++;

             }
          }
      }
   }

   uint32_t NUM_POLL = 100;
   rc = mss_execute_ccs_inst_array( i_target_mba, NUM_POLL, 60);

   return rc;
}

ReturnCode mss_create_rcd_ddr4(const Target& i_target_mba) {
   ReturnCode rc;
   uint32_t rc_num = 0;

   uint8_t l_rcd_cntl_word_0_1;
   uint8_t l_rcd_cntl_word_2;
   uint8_t l_rcd_cntl_word_3;
   uint8_t l_rcd_cntl_word_4;
   uint8_t l_rcd_cntl_word_5;
   uint8_t l_rcd_cntl_word_6_7;
   uint8_t l_rcd_cntl_word_8_9;
   uint8_t l_rcd_cntl_word_10;
   uint8_t l_rcd_cntl_word_11;
   uint8_t l_rcd_cntl_word_12;
   uint8_t l_rcd_cntl_word_13;
   uint8_t l_rcd_cntl_word_14;
   uint8_t l_rcd_cntl_word_15;
   uint64_t l_rcd_cntl_word_0_15;
   uint8_t stack_type[PORT_SIZE][MAX_NUM_DIMMS];
   uint64_t l_attr_eff_dimm_rcd_cntl_word_0_15[PORT_SIZE][MAX_NUM_DIMMS];
   uint8_t l_num_ranks_per_dimm_u8array[PORT_SIZE][MAX_NUM_DIMMS];
   uint8_t l_num_master_ranks_per_dimm_u8array[PORT_SIZE][MAX_NUM_DIMMS];
   uint8_t l_dimm_type_u8;
   uint8_t l_dram_width_u8;
   ecmdDataBufferBase data_buffer_8(8);
   ecmdDataBufferBase data_buffer_64(64);


   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM,&i_target_mba, l_num_master_ranks_per_dimm_u8array); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target_mba, stack_type); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target_mba, l_dimm_type_u8); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm_u8array); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, l_dram_width_u8); if(rc) return rc;

   uint64_t l_attr_eff_dimm_cntl_word_x;

   uint8_t l_rcd_cntl_word_1x;
   uint8_t l_rcd_cntl_word_2x;
   uint8_t l_rcd_cntl_word_3x;
   uint8_t l_rcd_cntl_word_7x;
   uint8_t l_rcd_cntl_word_8x;
   uint8_t l_rcd_cntl_word_9x;
   uint8_t l_rcd_cntl_word_Ax;
   uint8_t l_rcd_cntl_word_Bx;

   //FIXME: ATTR_MCBIST_MAX_TIMEOUT is being used until firmware is ready with a new attribute, ATTR_EFF_LRDIMM_WORD_X (subject to change)
   rc = FAPI_ATTR_GET(ATTR_MCBIST_MAX_TIMEOUT, &i_target_mba, l_attr_eff_dimm_cntl_word_x); if(rc) return rc;

   fapi::Target l_target_centaur;
   uint32_t l_mss_freq = 0;
   uint32_t l_mss_volt = 0;
   rc = fapiGetParentChip(i_target_mba, l_target_centaur); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_mss_freq); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_mss_volt); if(rc) return rc;

   for (uint8_t l_port = 0; l_port < PORT_SIZE; l_port++) {
      for (uint8_t l_dimm = 0; l_dimm < MAX_NUM_DIMMS; l_dimm++) {

         // Global Features, Clock Driver Enable Control Words
         l_rcd_cntl_word_0_1   = 0x00;

         // Timing and IBT Control Word
         l_rcd_cntl_word_2 = 0;

         // CA and CS Signals Driver Characteristics Control Word
         if (l_num_ranks_per_dimm_u8array[l_port][l_dimm] > 1) {
            l_rcd_cntl_word_3   = 6; // QxCS0_n...QxCS3_n Outputs strong drive, Address/Command moderate drive
         } else {
            l_rcd_cntl_word_3   = 5; // QxCS0_n...QxCS3_n Outputs moderate drive, Address/Command moderate drive
         }

         l_rcd_cntl_word_4     = 5;    // QxODT0...QxODT1 and QxCKE0...QxCKE1 Output Drivers moderate drive
         l_rcd_cntl_word_5     = 5;    // Clock Y1_t, Y1_c, Y3_t, Y3_c and Y0_t, Y0_c, Y2_t, Y2_c Output Drivers moderate drive

         // Command Space Control Word
         l_rcd_cntl_word_6_7 = 0xf0; // No op
         // Input/Output Configuration, Power Saving Settings Control Words
         if(stack_type[l_port][l_dimm] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
            //no master ranks found, then program to disable all CIDs
            //master ranks should always be found so this is a bit weird - might want to throw an error here
            if(l_num_master_ranks_per_dimm_u8array[l_port][l_dimm] == 0) {
               l_rcd_cntl_word_8_9 = 0x30;
            }
            //determine stack density - 2H, 4H, or 8H
            else {
               uint8_t stack_height = l_num_ranks_per_dimm_u8array[l_port][l_dimm] / l_num_master_ranks_per_dimm_u8array[l_port][l_dimm];
               FAPI_INF("3DS RCD set stack_height: %d",stack_height);
               if(stack_height == 8) {
                  l_rcd_cntl_word_8_9 = 0x00;
               }
               else if(stack_height == 4) {
                  l_rcd_cntl_word_8_9 = 0x10;
               }
               else if(stack_height == 2) {
                  l_rcd_cntl_word_8_9 = 0x20;
               }
               //weird, we shouldn't have 1H stacks
               else {
                  l_rcd_cntl_word_8_9 = 0x30;
               }
            }
         }

         //LR DIMM and 4 ranks
         else if(l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM && l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 4) {
            FAPI_INF("Creating RCD value for F0rC08 - LRDDIMM and 4 ranks -> 0x10");
            l_rcd_cntl_word_8_9 = 0x10;
         }
         else {
            l_rcd_cntl_word_8_9 = 0x30;
         }

         // RDIMM Operating Speed Control Word
         if ( l_mss_freq <= 1733 ) {        // 1600
            l_rcd_cntl_word_10 = 0;
         } else if ( l_mss_freq <= 2000 ) { // 1866
            l_rcd_cntl_word_10 = 1;
         } else if ( l_mss_freq <= 2266 ) { // 2133
            l_rcd_cntl_word_10 = 2;
         } else if ( l_mss_freq <= 2533 ) { // 2400
            l_rcd_cntl_word_10 = 3;
         } else if ( l_mss_freq <= 2800 ) { // 2666
            l_rcd_cntl_word_10 = 4;
         } else if ( l_mss_freq <= 3333 ) { // 3200
            l_rcd_cntl_word_10 = 5;
         } else {
            FAPI_ERR("Invalid LRDIMM ATTR_MSS_FREQ = %d on %s!", l_mss_freq, i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         }

         // Operating Voltage VDD and VREFCA Source Control Word
         if ( l_mss_volt >= 1120 ) {        // 1.2V
            l_rcd_cntl_word_11 = 14;
         } else if ( l_mss_volt >= 1020 ) { // 1.0xV
            l_rcd_cntl_word_11 = 15;
         } else {
            FAPI_ERR("Invalid LRDIMM ATTR_MSS_VOLT = %d on %s!", l_mss_volt, i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         }

         // Training Control Word
         l_rcd_cntl_word_12 = 0;

         // DIMM Configuration Control words
         data_buffer_8.clearBit(0,8);
         if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 4 ) {
            rc_num |= data_buffer_8.setBit(3); // Direct QuadCS mode
         }
         if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM  ) {
            rc_num |= data_buffer_8.setBit(1);
         }
         if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] > 1 ) {
            rc_num |= data_buffer_8.setBit(0); // Address mirroring for MRS commands
         }

         rc_num |= data_buffer_8.extractToRight( &l_rcd_cntl_word_13, 0, 4);

         // Parity Control Word
         l_rcd_cntl_word_14 = 0;

         // Command Latency Adder Control Word
         if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM  ) {
            l_rcd_cntl_word_15 = 4; // 0nCk latency adder
         }
         else {
            l_rcd_cntl_word_15 = 0; // 1nCk latency adder with DB control bus
         }
	 
	 FAPI_INF("RCD_CNTL_WORDS %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x ",l_rcd_cntl_word_0_1,
l_rcd_cntl_word_2,  
l_rcd_cntl_word_3,  
l_rcd_cntl_word_4,  
l_rcd_cntl_word_5,  
l_rcd_cntl_word_6_7,
l_rcd_cntl_word_8_9,
l_rcd_cntl_word_10, 
l_rcd_cntl_word_11, 
l_rcd_cntl_word_12, 
l_rcd_cntl_word_13, 
l_rcd_cntl_word_14, 
l_rcd_cntl_word_15 );

         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_0_1, 0 , 8);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_2,   8 , 4);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_3,   12, 4);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_4,   16, 4);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_5,   20, 4);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_6_7, 24, 8);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_8_9, 32, 8);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_10,  40, 4);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_11,  44, 4);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_12,  48, 4);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_13,  52, 4);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_14,  56, 4);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_15,  60, 4);
	 
	 if(rc_num)
         {
             rc.setEcmdError(rc_num);
             return rc;
         }
	 
         l_rcd_cntl_word_0_15 = data_buffer_64.getDoubleWord(0); if(rc) return rc;
         l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] =  l_rcd_cntl_word_0_15;

         // Set RCD control word x

         // RC1x Internal VREF CW
         l_rcd_cntl_word_1x = 0;

         // RC2x I2C Bus Control Word
         l_rcd_cntl_word_2x = 0;

         // RC3x Fine Granularity  RDIMM Operating Speed Control Word
         if ( l_mss_freq > 1240 && l_mss_freq < 3200 ) {
            l_rcd_cntl_word_3x = int ((l_mss_freq - 1250) / 20);
         } else {
            FAPI_ERR("Invalid DIMM ATTR_MSS_FREQ = %d on %s!", l_mss_freq, i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         }

         // RC7x IBT Control Word
         l_rcd_cntl_word_7x = 0;

         // RC8x ODT Input Buffer/IBT, QxODT Output Buffer and Timing Control Word
         l_rcd_cntl_word_8x = 0;

         // RC9x QxODT[1:0] Write Pattern CW
         l_rcd_cntl_word_9x = 0;

         // RCAx QxODT[1:0] Read Pattern CW
         l_rcd_cntl_word_Ax = 0;

         // RCBx IBT and MRS Snoop CW
         if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 4 ) {
            l_rcd_cntl_word_Bx = 4;
         } else {
            l_rcd_cntl_word_Bx = 7;
         }


         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_1x, 0 , 8);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_2x, 8 , 8);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_3x, 16, 8);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_7x, 24, 8);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_8x, 32, 8);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_9x, 40, 8);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_Ax, 48, 8);
         rc_num |= data_buffer_64.insertFromRight(&l_rcd_cntl_word_Bx, 56, 8);
	 if(rc_num)
         {
             rc.setEcmdError(rc_num);
             return rc;
         }

         l_attr_eff_dimm_cntl_word_x = data_buffer_64.getDoubleWord(0); if(rc) return rc;
         FAPI_INF("from data buffer: rcd control word X %llX", l_attr_eff_dimm_cntl_word_x );

      } // end dimm loop
   } // end port loop

   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;

   //FIXME: ATTR_MCBIST_MAX_TIMEOUT is being used until firmware is ready with a new attribute, ATTR_EFF_LRDIMM_WORD_X (subject to change)
   rc = FAPI_ATTR_SET(ATTR_MCBIST_MAX_TIMEOUT, &i_target_mba, l_attr_eff_dimm_cntl_word_x); if(rc) return rc;

   return rc;

}

ReturnCode mss_rcd_load_ddr4(
            Target& i_target,
            uint32_t i_port_number,
            uint32_t& io_ccs_inst_cnt
            )    {

    ReturnCode rc;
    //generates the RCD words
    rc = mss_create_rcd_ddr4(i_target);
    if(rc) return rc;
    
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint32_t dimm_number;
    uint32_t rcd_number;

    ecmdDataBufferBase rcd_cntl_wrd_4(8);
    ecmdDataBufferBase rcd_cntl_wrd_8(8);
    ecmdDataBufferBase rcd_cntl_wrd_64(64);
    uint16_t num_ranks;

    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase activate_1(1);
    ecmdDataBufferBase rasn_1(1);
    rc_num = rc_num | rasn_1.setBit(0);
    ecmdDataBufferBase casn_1(1);
    rc_num = rc_num | casn_1.setBit(0);
    ecmdDataBufferBase wen_1(1);
    rc_num = rc_num | wen_1.setBit(0);
    ecmdDataBufferBase cke_4(4);
    rc_num = rc_num | cke_4.setBit(0,4);
    ecmdDataBufferBase csn_8(8);
    rc_num = rc_num | csn_8.setBit(0,8);
    ecmdDataBufferBase odt_4(4);
    rc_num = rc_num | odt_4.clearBit(0,4);
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);
    
    if(rc_num)
    {
    	rc.setEcmdError(rc_num);
    	return rc;
    }
	 
    uint8_t num_ranks_array[2][2]; //[port][dimm]
    uint64_t rcd_array[2][2]; //[port][dimm]
    uint8_t dimm_type;

    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target, rcd_array);
    if(rc) return rc;

    uint32_t cntlx_offset[]= {1,2,3,7,8,9,10,11};
    // Dummy attribute for addtitional cntl words
    uint64_t rcdx_array;
    // uint64_t rcdx_array[2][2];

    //FIXME: ATTR_MCBIST_MAX_TIMEOUT is being used until firmware is ready with a new attribute, ATTR_EFF_LRDIMM_WORD_X (subject to change)
    rc = FAPI_ATTR_GET(ATTR_MCBIST_MAX_TIMEOUT, &i_target, rcdx_array);
    if(rc) return rc;

    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    rc_num = rc_num | address_16.clearBit(0, 16);
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 400, 0, 16);
    rc = mss_ccs_inst_arry_0( i_target,
                              io_ccs_inst_cnt,
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
                              i_port_number);
    if(rc) return rc;
    rc = mss_ccs_inst_arry_1( i_target,
                              io_ccs_inst_cnt,
                              num_idles_16,
                              num_repeat_16,
                              data_20,
                              read_compare_1,
                              rank_cal_4,
                              ddr_cal_enable_1,
                              ccs_end_1);
    if(rc) return rc;
    io_ccs_inst_cnt ++;

    FAPI_INF( "+++++++++++++++++++++ LOADING RCD CONTROL WORDS FOR %s PORT %d +++++++++++++++++++++", i_target.toEcmdString(), i_port_number);

    for ( dimm_number = 0; dimm_number < MAX_NUM_DIMMS; dimm_number++)
    {
        num_ranks = num_ranks_array[i_port_number][dimm_number];

        if (num_ranks == 0)
        {
            FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d", i_port_number, dimm_number, num_ranks);
        }
        else
        {
            FAPI_INF( "RCD SETTINGS FOR %s PORT%d DIMM%d ", i_target.toEcmdString(), i_port_number, dimm_number);
            FAPI_INF( "RCD Control Word: 0x%016llX", rcd_array[i_port_number][dimm_number]);
            //FAPI_INF( "RCD Control Word X: 0x%016llX", rcdx_array[i_port_number][dimm_number]);
            FAPI_INF( "RCD Control Word X: 0x%016llX", rcdx_array);

            if (rc_num)
            {
                FAPI_ERR( "mss_rcd_load: Error setting up buffers");
                rc_buff.setEcmdError(rc_num);
                return rc_buff;
            }

            // ALL active CS lines at a time.
            rc_num = rc_num | csn_8.setBit(0,8);
            rc_num = rc_num | csn_8.clearBit(0); //DCS0_n is LOW

            // DBG1, DBG0, DBA1, DBA0 = 4`b0111
            rc_num = rc_num | bank_3.setBit(0, 3);
            // DACT_n is HIGH
            rc_num = rc_num | activate_1.setBit(0);
            // RAS_n/CAS_n/WE_n are LOW
            rc_num = rc_num | rasn_1.clearBit(0);
            rc_num = rc_num | casn_1.clearBit(0);
            rc_num = rc_num | wen_1.clearBit(0);

            // Propogate through the 16, 4-bit control words
            for ( rcd_number = 0; rcd_number<= 15; rcd_number++)
            {
                //rc_num = rc_num | bank_3.clearBit(0, 3);
                rc_num = rc_num | address_16.clearBit(0, 16);

                rc_num = rc_num | rcd_cntl_wrd_64.setDoubleWord(0, rcd_array[i_port_number][dimm_number]);
                rc_num = rc_num | rcd_cntl_wrd_64.extract(rcd_cntl_wrd_4, 4*rcd_number, 4);

                //control word number code bits A[7:4]
                rc_num = rc_num | address_16.insert(rcd_number, 7, 1, 28);
                rc_num = rc_num | address_16.insert(rcd_number, 6, 1, 29);
                rc_num = rc_num | address_16.insert(rcd_number, 5, 1, 30);
                rc_num = rc_num | address_16.insert(rcd_number, 4, 1, 31);

                //control word values RCD0 = A0, RCD1 = A1, RCD2 = A2, RCD3 = A3
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_4, 0, 1, 3);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_4, 1, 1, 2);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_4, 2, 1, 1);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_4, 3, 1, 0);

                // Send out to the CCS array
                //if ( dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM && (rcd_number == 2 || rcd_number == 10) )
                if ( rcd_number == 2 || rcd_number == 10 )
                {
                   rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 4000, 0 , 16 ); // wait tStab for clock timing rcd words
                }
                else
                {
                   rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 12, 0, 16);
                }


                if (rc_num)
                {
                   FAPI_ERR( "mss_rcd_load: Error setting up buffers");
                   rc_buff.setEcmdError(rc_num);
                   return rc_buff;
                }

                rc = mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
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
                                          i_port_number);
                if(rc) return rc;
                rc = mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1);
                if(rc) return rc;
                io_ccs_inst_cnt ++;

                if (rc_num)
                {
                    FAPI_ERR( "mss_rcd_load: Error setting up buffers");
                    rc_buff.setEcmdError(rc_num);
                    return rc_buff;
                }
            }

            // 8-bit Control words
            for ( rcd_number = 0; rcd_number<= 7; rcd_number++)
            {
                //rc_num = rc_num | bank_3.clearBit(0, 3);
                rc_num = rc_num | address_16.clearBit(0, 16);

                //rc_num = rc_num | rcd_cntl_wrd_64.setDoubleWord(0, rcdx_array[i_port_number][dimm_number]);
                rc_num = rc_num | rcd_cntl_wrd_64.setDoubleWord(0, rcdx_array);
                rc_num = rc_num | rcd_cntl_wrd_64.extract(rcd_cntl_wrd_8, 8*rcd_number, 8);

                //control word number code bits A[11:8]
                rc_num = rc_num | address_16.insert(cntlx_offset[rcd_number], 11, 1, 28);
                rc_num = rc_num | address_16.insert(cntlx_offset[rcd_number], 10, 1, 29);
                rc_num = rc_num | address_16.insert(cntlx_offset[rcd_number],  9, 1, 30);
                rc_num = rc_num | address_16.insert(cntlx_offset[rcd_number],  8, 1, 31);

                //control word values RCD0 = A0, RCD1 = A1, RCD2 = A2, RCD3 = A3, RCD4=A4, RCD5=A5, RCD6=A6, RCD7=A7
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_8, 0, 1, 7);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_8, 1, 1, 6);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_8, 2, 1, 5);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_8, 3, 1, 4);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_8, 4, 1, 3);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_8, 5, 1, 2);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_8, 6, 1, 1);
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd_8, 7, 1, 0);

                // Send out to the CCS array
                if ( rcd_number == 2 ) // CW RC3x
                {
                   rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 4000, 0 , 16 ); // wait tStab for clock timing rcd words
                }
                else
                {
                   rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 12, 0, 16);
                }

                if (rc_num)
                {
                   FAPI_ERR( "mss_rcd_load: Error setting up buffers");
                   rc_buff.setEcmdError(rc_num);
                   return rc_buff;
                }

                rc = mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
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
                                          i_port_number);
                if(rc) return rc;
                rc = mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1);
                if(rc) return rc;
                io_ccs_inst_cnt ++;

                if (rc_num)
                {
                    FAPI_ERR( "mss_rcd_load: Error setting up buffers");
                    rc_buff.setEcmdError(rc_num);
                    return rc_buff;
                }
            }
        }
    }
    
    rc = mss_ccs_set_end_bit( i_target, io_ccs_inst_cnt-1);
    if(rc)
    {
        FAPI_ERR("CCS_SET_END_BIT FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
        return rc;
    }
    io_ccs_inst_cnt = 0;
    
    rc = mss_execute_ccs_inst_array(i_target, 10, 10);
    if(rc)
    {
        FAPI_ERR(" EXECUTE_CCS_INST_ARRAY FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
        return rc;
    }
    
    
    return rc;
}

ReturnCode mss_mrs_load_ddr4(
            Target& i_target,
            uint32_t i_port_number,
            uint32_t& io_ccs_inst_cnt
            )
{

    uint32_t dimm_number;
    uint32_t rank_number;
    uint32_t mrs_number;
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    ecmdDataBufferBase data_buffer_64(64);
    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase activate_1(1);
    rc_num = rc_num | activate_1.setBit(0);
    ecmdDataBufferBase rasn_1(1);
    rc_num = rc_num | rasn_1.clearBit(0);
    ecmdDataBufferBase casn_1(1);
    rc_num = rc_num | casn_1.clearBit(0);
    ecmdDataBufferBase wen_1(1);
    rc_num = rc_num | wen_1.clearBit(0);
    ecmdDataBufferBase cke_4(4);
    rc_num = rc_num | cke_4.clearBit(0,4);
    ecmdDataBufferBase csn_8(8);
    rc_num = rc_num | csn_8.clearBit(0,8);
    ecmdDataBufferBase odt_4(4);
    rc_num = rc_num | odt_4.clearBit(0,4);
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_idles_16_vref_train(16);
    rc_num = rc_num | num_idles_16_vref_train.insertFromRight((uint32_t) 160, 0, 16);

    if(rc_num) {
       rc.setEcmdError(rc_num);
       return rc;
    }

    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);

    ecmdDataBufferBase mrs0(16);
    ecmdDataBufferBase mrs1(16);
    ecmdDataBufferBase mrs2(16);
    ecmdDataBufferBase mrs3(16);
    ecmdDataBufferBase mrs4(16);
    ecmdDataBufferBase mrs5(16);
    ecmdDataBufferBase mrs6(16);
    ecmdDataBufferBase mrs6_train_on(16);
    uint16_t MRS0 = 0;
    uint16_t MRS1 = 0;
    uint16_t MRS2 = 0;
    uint16_t MRS3 = 0;
    uint16_t MRS4 = 0;
    uint16_t MRS5 = 0;
    uint16_t MRS6 = 0;

    ecmdDataBufferBase data_buffer(64);


    uint16_t num_ranks = 0;

    FAPI_INF( "+++++++++++++++++++++ LOADING MRS SETTINGS FOR PORT %d +++++++++++++++++++++", i_port_number);

    uint8_t num_ranks_array[2][2]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;

    uint8_t num_master_ranks_array[2][2]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target, num_master_ranks_array);
    if(rc) return rc;

    uint8_t dimm_type;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;


    // WORKAROUNDS
    rc = fapiGetScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.setBit(61);
    if(rc_num) {
       rc.setEcmdError(rc_num);
       return rc;
    }
    rc = fapiPutScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;

    rc = fapiGetScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P0_0x8000CC050301143F, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.clearBit(48);
    if(rc_num) {
       rc.setEcmdError(rc_num);
       return rc;
    }
    rc = fapiPutScom(i_target,  DPHY01_DDRPHY_WC_CONFIG3_P0_0x8000CC050301143F, data_buffer);
    if(rc) return rc;


    uint8_t dram_stack[2][2];
    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, dram_stack);
    if(rc) return rc;

    FAPI_INF( "Stack Type: %d\n", dram_stack[0][0]);
    if (dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS)
    {
       FAPI_INF( "=============  Got in the 3DS stack loop CKE !!!!! =====================\n");
       rc_num = rc_num | csn_8.clearBit(2,2);
       rc_num = rc_num | csn_8.clearBit(6,2);
       // COMMENT IN LATER!!!! rc_num = rc_num | cke_4.clearBit(1);
       if(rc_num) {
          rc.setEcmdError(rc_num);
          return rc;
       }
    }

    //Lines commented out in the following section are waiting for xml attribute adds
    //MRS0
    uint8_t dram_bl;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_BL, &i_target, dram_bl);
    if(rc) return rc;
    uint8_t read_bt; //Read Burst Type
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RBT, &i_target, read_bt);
    if(rc) return rc;
    uint8_t dram_cl;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_CL, &i_target, dram_cl);
    if(rc) return rc;
    uint8_t test_mode; //TEST MODE
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TM, &i_target, test_mode);
    if(rc) return rc;
    uint8_t dll_reset; //DLL Reset
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DLL_RESET, &i_target, dll_reset);
    if(rc) return rc;
    uint8_t dram_wr; //DRAM write recovery
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR, &i_target, dram_wr);
    if(rc) return rc;
    uint8_t dram_rtp; //DRAM RTP - read to precharge
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR, &i_target, dram_rtp);
    if(rc) return rc;
    uint8_t dll_precharge; //DLL Control For Precharge
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DLL_PPD, &i_target, dll_precharge);
    if(rc) return rc;

    if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_BL8)
    {
        dram_bl = 0x00;
    }
    else if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_OTF)
    {
        dram_bl = 0x80;
    }
    else if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_BC4)
    {
        dram_bl = 0x40;
    }

    uint8_t dram_wr_rtp = 0x00;
    if ( (dram_wr == 10) )//&& (dram_rtp == 5) )
    {
        dram_wr_rtp = 0x00;
    }
    else if ( (dram_wr == 12) )//&& (dram_rtp == 6) )
    {
        dram_wr_rtp = 0x80;
    }
    else if ( (dram_wr == 13) )//&& (dram_rtp == 7) )
    {
        dram_wr_rtp = 0x40;
    }
    else if ( (dram_wr == 14) )//&& (dram_rtp == 8) )
    {
        dram_wr_rtp = 0xC0;
    }
    else if ( (dram_wr == 18) )//&& (dram_rtp == 9) )
    {
        dram_wr_rtp = 0x20;
    }
    else if ( (dram_wr == 20) )//&& (dram_rtp == 10) )
    {
        dram_wr_rtp = 0xA0;
    }
    else if ( (dram_wr == 24) )//&& (dram_rtp == 12) )
    {
        dram_wr_rtp = 0x60;
    }

    if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_SEQUENTIAL)
    {
        read_bt = 0x00;
    }
    else if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_INTERLEAVE)
    {
        read_bt = 0xFF;
    }

    if ((dram_cl > 8)&&(dram_cl < 17))
    {
        dram_cl = dram_cl - 9;
    }
    else if ((dram_cl > 17)&&(dram_cl < 25))
    {
        dram_cl = (dram_cl >> 1) - 1;
    }
    dram_cl = mss_reverse_8bits(dram_cl);

    if (test_mode == ENUM_ATTR_EFF_DRAM_TM_NORMAL)
    {
        test_mode = 0x00;
    }
    else if (test_mode == ENUM_ATTR_EFF_DRAM_TM_TEST)
    {
        test_mode = 0xFF;
    }

    if (dll_reset == ENUM_ATTR_EFF_DRAM_DLL_RESET_YES)
    {
        dll_reset = 0xFF;
    }
    else if (dll_reset == ENUM_ATTR_EFF_DRAM_DLL_RESET_NO)
    {
        dll_reset = 0x00;
    }

    if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_SLOWEXIT)
    {
        dll_precharge = 0x00;
    }
    else if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_FASTEXIT)
    {
        dll_precharge = 0xFF;
    }

    //MRS1
    uint8_t dll_enable; //DLL Enable
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DLL_ENABLE, &i_target, dll_enable);
    if(rc) return rc;
    uint8_t out_drv_imp_cntl[2][2];
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RON, &i_target, out_drv_imp_cntl);
    if(rc) return rc;
    uint8_t dram_rtt_nom[2][2][4];
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_NOM, &i_target, dram_rtt_nom);
    if(rc) return rc;
    uint8_t dram_al;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_AL, &i_target, dram_al);
    if(rc) return rc;
    uint8_t wr_lvl; //write leveling enable
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR_LVL_ENABLE, &i_target, wr_lvl);
    if(rc) return rc;
    uint8_t tdqs_enable; //TDQS Enable
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TDQS, &i_target, tdqs_enable);
    if(rc) return rc;
    uint8_t q_off; //Qoff - Output buffer Enable
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_OUTPUT_BUFFER, &i_target, q_off);
    if(rc) return rc;

    if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_DISABLE)
    {
        dll_enable = 0x00;
    }
    else if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_ENABLE)
    {
        dll_enable = 0xFF;
    }

    if (dram_al == ENUM_ATTR_EFF_DRAM_AL_DISABLE)
    {
        dram_al = 0x00;
    }
    else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_1)
    {
        dram_al = 0x80;
    }
    else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_2)
    {
        dram_al = 0x40;
    }
    else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_3) //Jeremy
    {
    	dram_al = 0xC0;
    }

    if (wr_lvl == ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_DISABLE)
    {
        wr_lvl = 0x00;
    }
    else if (wr_lvl == ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_ENABLE)
    {
        wr_lvl = 0xFF;
    }

    if (tdqs_enable == ENUM_ATTR_EFF_DRAM_TDQS_DISABLE)
    {
        tdqs_enable = 0x00;
    }
    else if (tdqs_enable == ENUM_ATTR_EFF_DRAM_TDQS_ENABLE)
    {
        tdqs_enable = 0xFF;
    }

    if (q_off == ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_DISABLE)
    {
        q_off = 0xFF;
    }
    else if (q_off == ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_ENABLE)
    {
        q_off = 0x00;
    }

    //MRS2

    uint8_t lpasr; // Low Power Auto Self-Refresh -- new not yet supported
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_LPASR, &i_target, lpasr);
    if(rc) return rc;
    uint8_t cwl; // CAS Write Latency
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_CWL, &i_target, cwl);
    if(rc) return rc;
    uint8_t dram_rtt_wr[2][2][4];
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_WR, &i_target, dram_rtt_wr);
    if(rc) return rc;
    uint8_t write_crc; // CAS Write Latency
    rc = FAPI_ATTR_GET(ATTR_EFF_WRITE_CRC, &i_target, write_crc);
    if(rc) return rc;

    if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_NORMAL)
    {
        lpasr = 0x00;
    }
    else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_REDUCED)
    {
        lpasr = 0x80;
    }
    else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_EXTENDED)
    {
        lpasr = 0x40;
    }
    else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_ASR)
    {
        lpasr = 0xFF;
    }

    if ((cwl > 8)&&(cwl < 13))
    {
        cwl = cwl - 9;
    }
    else if ((cwl > 13)&&(cwl < 19))
    {
        cwl = (cwl >> 1) - 3;
    }
    else
    {
       //no correcct value for CWL was found
       FAPI_INF("ERROR: Improper CWL value found. Setting CWL to 9 and continuing...");
       cwl = 0;
    }
    cwl = mss_reverse_8bits(cwl);

    if ( write_crc == ENUM_ATTR_EFF_WRITE_CRC_ENABLE)
    {
        write_crc = 0xFF;
    }
    else if (write_crc == ENUM_ATTR_EFF_WRITE_CRC_DISABLE)
    {
        write_crc = 0x00;
    }

    //MRS3
    uint8_t mpr_op; // MPR Op
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_MODE, &i_target, mpr_op);
    if(rc) return rc;
    uint8_t mpr_page; // MPR Page Selection  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_PAGE, &i_target, mpr_page);
    if(rc) return rc;
    uint8_t geardown_mode; // Gear Down Mode  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_GEARDOWN_MODE, &i_target, geardown_mode);
    if(rc) return rc;
    uint8_t dram_access; // per dram accessibility  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_PER_DRAM_ACCESS, &i_target, dram_access);
    if(rc) return rc;
    uint8_t temp_readout; // Temperature sensor readout  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_READOUT, &i_target, temp_readout);
    if(rc) return rc;
    uint8_t fine_refresh; // fine refresh mode  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_FINE_REFRESH_MODE, &i_target, fine_refresh);
    if(rc) return rc;
    uint8_t wr_latency; // write latency for CRC and DM  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_CRC_WR_LATENCY, &i_target, wr_latency);
    if(rc) return rc;
    uint8_t read_format; // MPR READ FORMAT  - NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_RD_FORMAT, &i_target, read_format);
    if(rc) return rc;

    if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_ENABLE)
    {
        mpr_op = 0xFF;
    }
    else if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_DISABLE)
    {
        mpr_op = 0x00;
    }

    mpr_page = mss_reverse_8bits(mpr_page);

    if (dram_access == ENUM_ATTR_EFF_PER_DRAM_ACCESS_ENABLE)
    {
        dram_access = 0xFF;
    }
    else if (dram_access == ENUM_ATTR_EFF_PER_DRAM_ACCESS_DISABLE)
    {
        dram_access = 0x00;
    }

    if ( geardown_mode == ENUM_ATTR_EFF_GEARDOWN_MODE_HALF)
    {
         geardown_mode = 0x00;
    }
    else if ( geardown_mode == ENUM_ATTR_EFF_GEARDOWN_MODE_QUARTER)
    {
         geardown_mode = 0xFF;
    }

    if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_ENABLE)
    {
        temp_readout = 0xFF;
    }
    else if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_DISABLE)
    {
        temp_readout = 0x00;
    }

    if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_NORMAL)
    {
        fine_refresh = 0x00;
    }
    else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_2X)
    {
        fine_refresh = 0x80;
    }
    else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_4X)
    {
        fine_refresh = 0x40;
    }
    else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_2X)
    {
        fine_refresh = 0xA0;
    }
    else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_4X)
    {
        fine_refresh = 0x60;
    }

    if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_4NCK)
    {
        wr_latency = 0x00;
    }
    else if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_5NCK)
    {
        wr_latency = 0x80;
    }
    else if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_6NCK)
    {
        wr_latency = 0xC0;
    }

    if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_SERIAL)
    {
        read_format = 0x00;
    }
    else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_PARALLEL)
    {
        read_format = 0x80;
    }
    else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_STAGGERED)
    {
        read_format = 0x40;
    }
    else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_RESERVED_TEMP)
    {
        read_format = 0xC0;
    }

    //MRS4
    uint8_t max_pd_mode; // Max Power down mode -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_MAX_POWERDOWN_MODE, &i_target, max_pd_mode);
    if(rc) return rc;
    uint8_t temp_ref_range; // Temp ref range -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_REF_RANGE, &i_target, temp_ref_range);
    if(rc) return rc;
    uint8_t temp_ref_mode; // Temp controlled ref mode -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_REF_MODE, &i_target, temp_ref_mode);
    if(rc) return rc;
    uint8_t vref_mon; // Internal Vref Monitor -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_INT_VREF_MON, &i_target, vref_mon);
    if(rc) return rc;
    uint8_t cs_cmd_latency; // CS to CMD/ADDR Latency -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_CS_CMD_LATENCY, &i_target, cs_cmd_latency);
    if(rc) return rc;
    uint8_t ref_abort; // Self Refresh Abort -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_SELF_REF_ABORT, &i_target, ref_abort);
    if(rc) return rc;
    uint8_t rd_pre_train_mode; // Read Pre amble Training Mode -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_RD_PREAMBLE_TRAIN, &i_target, rd_pre_train_mode);
    if(rc) return rc;
    uint8_t rd_preamble; // Read Pre amble -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_RD_PREAMBLE, &i_target, rd_preamble);
    if(rc) return rc;
    uint8_t wr_preamble; // Write Pre amble -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_WR_PREAMBLE, &i_target, wr_preamble);
    if(rc) return rc;

    if ( max_pd_mode == ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_ENABLE)
    {
        max_pd_mode = 0xF0;
    }
    else if ( max_pd_mode == ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_DISABLE)
    {
        max_pd_mode = 0x00;
    }

    if (temp_ref_range == ENUM_ATTR_EFF_TEMP_REF_RANGE_NORMAL)
    {
        temp_ref_range = 0x00;
    }
    else if ( temp_ref_range== ENUM_ATTR_EFF_TEMP_REF_RANGE_EXTEND)
    {
        temp_ref_range = 0xFF;
    }

    if (temp_ref_mode == ENUM_ATTR_EFF_TEMP_REF_MODE_ENABLE)
    {
        temp_ref_mode = 0x80;
    }
    else if (temp_ref_mode == ENUM_ATTR_EFF_TEMP_REF_MODE_DISABLE)
    {
        temp_ref_mode = 0x00;
    }

    if ( vref_mon == ENUM_ATTR_EFF_INT_VREF_MON_ENABLE)
    {
        vref_mon = 0xFF;
    }
    else if ( vref_mon == ENUM_ATTR_EFF_INT_VREF_MON_DISABLE)
    {
        vref_mon = 0x00;
    }


    if ( cs_cmd_latency == 3)
    {
        cs_cmd_latency = 0x80;
    }
    else if (cs_cmd_latency == 4)
    {
        cs_cmd_latency = 0x40;
    }
    else if (cs_cmd_latency == 5)
    {
        cs_cmd_latency = 0xC0;
    }
    else if (cs_cmd_latency == 6)
    {
        cs_cmd_latency = 0x20;
    }
    else if (cs_cmd_latency == 8)
    {
        cs_cmd_latency = 0xA0;
    }

    if (ref_abort == ENUM_ATTR_EFF_SELF_REF_ABORT_ENABLE)
    {
        ref_abort = 0xFF;
    }
    else if (ref_abort == ENUM_ATTR_EFF_SELF_REF_ABORT_DISABLE)
    {
        ref_abort = 0x00;
    }

    if (rd_pre_train_mode == ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_ENABLE)
    {
        rd_pre_train_mode = 0xFF;
    }
    else if (rd_pre_train_mode == ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_DISABLE)
    {
        rd_pre_train_mode = 0x00;
    }

    if (rd_preamble == ENUM_ATTR_EFF_RD_PREAMBLE_1NCLK)
    {
        rd_preamble = 0x00;
    }
    else if (rd_preamble == ENUM_ATTR_EFF_RD_PREAMBLE_2NCLK)
    {
        rd_preamble = 0xFF;
    }

    if (wr_preamble == ENUM_ATTR_EFF_WR_PREAMBLE_1NCLK)
    {
        wr_preamble = 0x00;
    }
    else if (wr_preamble == ENUM_ATTR_EFF_WR_PREAMBLE_2NCLK)
    {
        wr_preamble = 0xFF;
    }


    //MRS5
    uint8_t ca_parity_latency; //C/A Parity Latency Mode  -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_CA_PARITY_LATENCY , &i_target, ca_parity_latency);
    if(rc) return rc;
    uint8_t crc_error_clear; //CRC Error Clear  -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_CRC_ERROR_CLEAR , &i_target, crc_error_clear);
    if(rc) return rc;
    uint8_t ca_parity_error_status; //C/A Parity Error Status  -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_CA_PARITY_ERROR_STATUS , &i_target, ca_parity_error_status);
    if(rc) return rc;
    uint8_t odt_input_buffer; //ODT Input Buffer during power down  -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_ODT_INPUT_BUFF , &i_target, odt_input_buffer);
    if(rc) return rc;
    uint8_t rtt_park[2][2][4]; //RTT_Park value  -  NEW
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_PARK , &i_target, rtt_park);
    if(rc) return rc;
    uint8_t ca_parity; //CA Parity Persistance Error  -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_CA_PARITY , &i_target, ca_parity);
    if(rc) return rc;
    uint8_t data_mask; //Data Mask  -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_DATA_MASK , &i_target, data_mask);
    if(rc) return rc;
    uint8_t write_dbi; //Write DBI  -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_WRITE_DBI , &i_target, write_dbi);
    if(rc) return rc;
    uint8_t read_dbi; //Read DBI  -  NEW
    rc = FAPI_ATTR_GET(ATTR_EFF_READ_DBI , &i_target, read_dbi);
    if(rc) return rc;


    if (ca_parity_latency == 4)
    {
        ca_parity_latency = 0x80;
    }
    else if (ca_parity_latency == 5)
    {
        ca_parity_latency = 0x40;
    }
    else if (ca_parity_latency == 6)
    {
        ca_parity_latency = 0xC0;
    }
    else if (ca_parity_latency == 8)
    {
        ca_parity_latency = 0x20;
    }
    else if (ca_parity_latency == ENUM_ATTR_EFF_CA_PARITY_LATENCY_DISABLE)
    {
        ca_parity_latency = 0x00;
    }

    if (crc_error_clear == ENUM_ATTR_EFF_CRC_ERROR_CLEAR_ERROR)
    {
        crc_error_clear = 0xFF;
    }
    else if (crc_error_clear == ENUM_ATTR_EFF_CRC_ERROR_CLEAR_CLEAR)
    {
        crc_error_clear = 0x00;
    }

    if (ca_parity_error_status == ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_ERROR)
    {
        ca_parity_error_status = 0xFF;
    }
    else if (ca_parity_error_status == ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_CLEAR)
    {
        ca_parity_error_status = 0x00;
    }

    if (odt_input_buffer == ENUM_ATTR_EFF_ODT_INPUT_BUFF_ACTIVATED)
    {
        odt_input_buffer = 0x00;
    }
    else if (odt_input_buffer == ENUM_ATTR_EFF_ODT_INPUT_BUFF_DEACTIVATED)
    {
        odt_input_buffer = 0xFF;
    }


    if (ca_parity == ENUM_ATTR_EFF_CA_PARITY_ENABLE)
    {
        ca_parity = 0xFF;
    }
    else if (ca_parity == ENUM_ATTR_EFF_CA_PARITY_DISABLE)
    {
        ca_parity = 0x00;
    }

    if (data_mask == ENUM_ATTR_EFF_DATA_MASK_DISABLE)
    {
        data_mask = 0x00;
    }
    else if (data_mask == ENUM_ATTR_EFF_DATA_MASK_ENABLE)
    {
        data_mask = 0xFF;
    }

    if (write_dbi == ENUM_ATTR_EFF_WRITE_DBI_DISABLE)
    {
        write_dbi = 0x00;
    }
    else if (write_dbi == ENUM_ATTR_EFF_WRITE_DBI_ENABLE)
    {
        write_dbi = 0xFF;
    }

    if (read_dbi == ENUM_ATTR_EFF_READ_DBI_DISABLE)
    {
        read_dbi = 0x00;
    }
    else if (read_dbi == ENUM_ATTR_EFF_READ_DBI_ENABLE)
    {
        read_dbi = 0xFF;
    }

    //MRS6
    uint8_t vrefdq_train_value[2][2][4]; //vrefdq_train value   -  NEW
    rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_VALUE, &i_target, vrefdq_train_value);
    if(rc) return rc;
    uint8_t vrefdq_train_range[2][2][4]; //vrefdq_train range   -  NEW
    rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_RANGE, &i_target, vrefdq_train_range);
    if(rc) return rc;
    uint8_t vrefdq_train_enable[2][2][4]; //vrefdq_train enable  -  NEW
    rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target, vrefdq_train_enable);
    if(rc) return rc;
    uint8_t tccd_l; //tccd_l  -  NEW
    rc = FAPI_ATTR_GET( ATTR_TCCD_L, &i_target, tccd_l);
    if(rc) return rc;
    if (tccd_l == 4)
    {
        tccd_l = 0x00;
    }
    else if (tccd_l == 5)
    {
        tccd_l = 0x80;
    }
    else if (tccd_l == 6)
    {
        tccd_l = 0x40;
    }
    else if (tccd_l == 7)
    {
        tccd_l = 0xC0;
    }
    else if (tccd_l == 8)
    {
        tccd_l = 0x20;
    }

    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    rc_num = rc_num | cke_4.setBit(0,4);
    rc_num = rc_num | csn_8.setBit(0,8);
    rc_num = rc_num | address_16.clearBit(0, 16);
    rc_num = rc_num | odt_4.clearBit(0,4);
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 400, 0, 16);
    if(rc_num) {
       rc.setEcmdError(rc_num);
       return rc;
    }
    rc = mss_ccs_inst_arry_0( i_target,
                              io_ccs_inst_cnt,
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
                              i_port_number);
    if(rc) return rc;
    rc = mss_ccs_inst_arry_1( i_target,
                              io_ccs_inst_cnt,
                              num_idles_16,
                              num_repeat_16,
                              data_20,
                              read_compare_1,
                              rank_cal_4,
                              ddr_cal_enable_1,
                              ccs_end_1);
    if(rc) return rc;
    io_ccs_inst_cnt ++;

    // Dimm 0-1
    for ( dimm_number = 0; dimm_number < MAX_NUM_DIMMS; dimm_number++)
    {
        //if the dram stack type is a 3DS dimm
        if(dram_stack[i_port_number][dimm_number]  == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
           FAPI_INF("DIMM is a 3DS type, using num_masetr_ranks_array");
           num_ranks = num_master_ranks_array[i_port_number][dimm_number];
        }
        else {
           num_ranks = num_ranks_array[i_port_number][dimm_number];
        }

        if (num_ranks == 0)
        {
            FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d ", i_port_number, dimm_number, num_ranks);
        }
        else
        {
            // Rank 0-3
            for ( rank_number = 0; rank_number < num_ranks; rank_number++)
            {
                    FAPI_INF( "MRS SETTINGS FOR PORT%d DIMM%d RANK%d", i_port_number, dimm_number, rank_number);

                    rc_num = rc_num | csn_8.setBit(0,8);
                    rc_num = rc_num | address_16.clearBit(0, 16);

                    //For DDR4:
                    //Address 14 = Address 17, Address 15 = BG1
                    rc_num = rc_num | mrs0.insert((uint8_t) dram_bl, 0, 2, 0);
                    rc_num = rc_num | mrs0.insert((uint8_t) dram_cl, 2, 1, 0);
                    rc_num = rc_num | mrs0.insert((uint8_t) read_bt, 3, 1, 0);
                    rc_num = rc_num | mrs0.insert((uint8_t) dram_cl, 4, 3, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) test_mode, 7, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) dll_reset, 8, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) dram_wr_rtp, 9, 3);
                    rc_num = rc_num | mrs0.insert((uint8_t) 0x00, 12, 4);

                    rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);
		    if(rc_num) {
		       rc.setEcmdError(rc_num);
                       return rc;
		    }

                    if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x00;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM240) //not supported
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x20;
                        FAPI_INF("DRAM RTT_NOM is configured for 240 OHM which is not supported.");
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM48) //not supported
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xA0;
                        FAPI_INF("DRAM RTT_NOM is configured for 48 OHM which is not supported.");
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xC0;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x80;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM120)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x40;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM80) // not supported
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x60;
                        FAPI_INF("DRAM RTT_NOM is configured for 80 OHM which is not supported.");
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34) // not supported
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xE0;
                        FAPI_INF("DRAM RTT_NOM is configured for 34 OHM which is not supported.");
                    }

                    if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_VPD_DRAM_RON_OHM34)
                    {
                        out_drv_imp_cntl[i_port_number][dimm_number] = 0x00;
                    }
                    // Not currently supported
                    else if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_VPD_DRAM_RON_OHM48) //not supported
                    {
                        out_drv_imp_cntl[i_port_number][dimm_number] = 0x80;
                        FAPI_INF("DRAM RON is configured for 48 OHM which is not supported.");
                    }

                    //For DDR4:
                    //Address 14 = Address 17, Address 15 = BG1
                    rc_num = rc_num | mrs1.insert((uint8_t) dll_enable, 0, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) out_drv_imp_cntl[i_port_number][dimm_number], 1, 2, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) dram_al, 3, 2, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 5, 2);
                    rc_num = rc_num | mrs1.insert((uint8_t) wr_lvl, 7, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][rank_number], 8, 3, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) tdqs_enable, 11, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) q_off, 12, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 13, 3);


                    rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);
		    if(rc_num) {
		       rc.setEcmdError(rc_num);
                       return rc;
		    }


                    if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE)
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x00;
                    }
                    else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120)
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x80;
                    }
                    else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == 240)//ENUM_ATTR_EFF_DRAM_RTT_WR_OHM240)
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x40;
                    }
                    else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == 0xFF)//ENUM_ATTR_EFF_DRAM_RTT_WR_HIGHZ)
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0xFF;
                    }

                    rc_num = rc_num | mrs2.insert((uint8_t) 0x00, 0, 3);
                    rc_num = rc_num | mrs2.insert((uint8_t) cwl, 3, 3);
                    rc_num = rc_num | mrs2.insert((uint8_t) lpasr, 6, 2);
                    rc_num = rc_num | mrs2.insert((uint8_t) 0x00, 8, 1);
                    rc_num = rc_num | mrs2.insert((uint8_t) dram_rtt_wr[i_port_number][dimm_number][rank_number], 9, 2);
                    rc_num = rc_num | mrs2.insert((uint8_t) 0x00, 11, 1);
                    rc_num = rc_num | mrs2.insert((uint8_t) write_crc, 12, 1);
                    rc_num = rc_num | mrs2.insert((uint8_t) 0x00, 13, 2);

                    rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);
		    if(rc_num) {
		       rc.setEcmdError(rc_num);
                       return rc;
		    }

                    rc_num = rc_num | mrs3.insert((uint8_t) mpr_page, 0, 2);
                    rc_num = rc_num | mrs3.insert((uint8_t) mpr_op, 2, 1);
                    rc_num = rc_num | mrs3.insert((uint8_t) geardown_mode, 3, 1);
                    rc_num = rc_num | mrs3.insert((uint8_t) dram_access, 4, 1);
                    rc_num = rc_num | mrs3.insert((uint8_t) temp_readout, 5, 1);
                    rc_num = rc_num | mrs3.insert((uint8_t) fine_refresh, 6, 3);
                    rc_num = rc_num | mrs3.insert((uint8_t) wr_latency, 9, 2);
                    rc_num = rc_num | mrs3.insert((uint8_t) read_format, 11, 2);
                    rc_num = rc_num | mrs3.insert((uint8_t) 0x00, 13, 2);


                    rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
		    if(rc_num) {
		       rc.setEcmdError(rc_num);
                       return rc;
		    }

                    rc_num = rc_num | mrs4.insert((uint8_t) 0x00, 0, 1);
                    rc_num = rc_num | mrs4.insert((uint8_t) max_pd_mode, 1, 1);
                    rc_num = rc_num | mrs4.insert((uint8_t) temp_ref_range, 2, 1);
                    rc_num = rc_num | mrs4.insert((uint8_t) temp_ref_mode, 3, 1);
                    rc_num = rc_num | mrs4.insert((uint8_t) vref_mon, 4, 1);
                    rc_num = rc_num | mrs4.insert((uint8_t) 0x00, 5, 1);
                    rc_num = rc_num | mrs4.insert((uint8_t) cs_cmd_latency, 6, 3);
                    rc_num = rc_num | mrs4.insert((uint8_t) ref_abort, 9, 1);
                    rc_num = rc_num | mrs4.insert((uint8_t) rd_pre_train_mode, 10, 1);
                    rc_num = rc_num | mrs4.insert((uint8_t) rd_preamble, 11, 1);
                    rc_num = rc_num | mrs4.insert((uint8_t) wr_preamble, 12, 1);
                    rc_num = rc_num | mrs4.extractPreserve(&MRS4, 0, 16, 0);
		    if(rc_num) {
		       rc.setEcmdError(rc_num);
                       return rc;
		    }


                    //MRS5
                    if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_DISABLE)
                    {
                        rtt_park[i_port_number][dimm_number][rank_number] = 0x00;
                    }
                    else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_60OHM)
                    {
                        rtt_park[i_port_number][dimm_number][rank_number] = 0x80;
                    }
                    else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_40OHM)
                    {
                        rtt_park[i_port_number][dimm_number][rank_number] = 0xC0;
                    }
                    else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_120OHM)
                    {
                        rtt_park[i_port_number][dimm_number][rank_number] = 0x40;
                    }
                    else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_240OHM)
                    {
                        rtt_park[i_port_number][dimm_number][rank_number] = 0x20;
                    }
                    else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_48OHM)
                    {
                        rtt_park[i_port_number][dimm_number][rank_number] = 0xA0;
                    }
                    else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_80OHM)
                    {
                        rtt_park[i_port_number][dimm_number][rank_number] = 0x60;
                    }
                    else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_34OHM)
                    {
                        rtt_park[i_port_number][dimm_number][rank_number] = 0xE0;
                    }

                    rc_num = rc_num | mrs5.insert((uint8_t) ca_parity_latency, 0, 2);
                    rc_num = rc_num | mrs5.insert((uint8_t) crc_error_clear, 3, 1);
                    rc_num = rc_num | mrs5.insert((uint8_t) ca_parity_error_status, 4, 1);
                    rc_num = rc_num | mrs5.insert((uint8_t) odt_input_buffer, 5, 1);
                    rc_num = rc_num | mrs5.insert((uint8_t) rtt_park[i_port_number][dimm_number][rank_number], 6, 3);
                    rc_num = rc_num | mrs5.insert((uint8_t) ca_parity, 9, 1);
                    rc_num = rc_num | mrs5.insert((uint8_t) data_mask, 10, 1);
                    rc_num = rc_num | mrs5.insert((uint8_t) write_dbi, 11, 1);
                    rc_num = rc_num | mrs5.insert((uint8_t) read_dbi, 12, 1);
                    rc_num = rc_num | mrs5.insert((uint8_t) 0x00, 13, 2);


                    rc_num = rc_num | mrs5.extractPreserve(&MRS5, 0, 16, 0);
		    if(rc_num) {
		       rc.setEcmdError(rc_num);
                       return rc;
		    }

                    //MRS6

                    vrefdq_train_value[i_port_number][dimm_number][rank_number] = mss_reverse_8bits(vrefdq_train_value[i_port_number][dimm_number][rank_number]);

                    if (vrefdq_train_range[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1)
                    {
                        vrefdq_train_range[i_port_number][dimm_number][rank_number] = 0x00;
                    }
                    else if (vrefdq_train_range[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2)
                    {
                        vrefdq_train_range[i_port_number][dimm_number][rank_number] = 0xFF;
                    }

                    if (vrefdq_train_enable[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE)
                    {
                        vrefdq_train_enable[i_port_number][dimm_number][rank_number] = 0xFF;
                    }
                    else if (vrefdq_train_enable[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE)
                    {
                        vrefdq_train_enable[i_port_number][dimm_number][rank_number] = 0x00;
                    }

                    rc_num = rc_num | mrs6.insert((uint8_t) vrefdq_train_value[i_port_number][dimm_number][rank_number], 0, 6);
                    rc_num = rc_num | mrs6.insert((uint8_t) vrefdq_train_range[i_port_number][dimm_number][rank_number], 6, 1);
                    rc_num = rc_num | mrs6.insert((uint8_t) vrefdq_train_enable[i_port_number][dimm_number][rank_number], 7, 1);
                    rc_num = rc_num | mrs6.insert((uint8_t) 0x00, 8, 2);
                    rc_num = rc_num | mrs6.insert((uint8_t) tccd_l, 10, 3);
                    rc_num = rc_num | mrs6.insert((uint8_t) 0x00, 13, 2);

                    rc_num = rc_num | mrs6_train_on.insert((uint8_t) vrefdq_train_value[i_port_number][dimm_number][rank_number], 0, 6);
                    rc_num = rc_num | mrs6_train_on.insert((uint8_t) vrefdq_train_range[i_port_number][dimm_number][rank_number], 6, 1);
                    rc_num = rc_num | mrs6_train_on.insert((uint8_t) 0xff, 7, 1);
                    rc_num = rc_num | mrs6_train_on.insert((uint8_t) 0x00, 8, 2);
                    rc_num = rc_num | mrs6_train_on.insert((uint8_t) tccd_l, 10, 3);
                    rc_num = rc_num | mrs6_train_on.insert((uint8_t) 0x00, 13, 2);


                    rc_num = rc_num | mrs6.extractPreserve(&MRS6, 0, 16, 0);

                    FAPI_INF( "MRS 0: 0x%04X", MRS0);
                    FAPI_INF( "MRS 1: 0x%04X", MRS1);
                    FAPI_INF( "MRS 2: 0x%04X", MRS2);
                    FAPI_INF( "MRS 3: 0x%04X", MRS3);
                    FAPI_INF( "MRS 4: 0x%04X", MRS4);
                    FAPI_INF( "MRS 5: 0x%04X", MRS5);
                    FAPI_INF( "MRS 6: 0x%04X", MRS6);

                    if (rc_num)
                    {
                        FAPI_ERR( "mss_mrs_load: Error setting up buffers");
                        rc_buff.setEcmdError(rc_num);
                        return rc_buff;
                    }

                    // Only corresponding CS to rank
                    rc_num = rc_num | csn_8.setBit(0,8);
                    rc_num = rc_num | csn_8.clearBit(rank_number+4*dimm_number);
		    
		    if(rc_num) {
		       rc.setEcmdError(rc_num);
                       return rc;
		    }
		    
                     uint8_t dram_stack[2][2];
                    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, dram_stack);
                    if(rc) return rc;

                    FAPI_INF( "Stack Type: %d\n", dram_stack[0][0]);
                    if (dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS)
                    {
                       FAPI_INF( "=============  Got in the 3DS stack loop CKE !!!!=====================\n");
                       rc_num = rc_num | csn_8.clearBit(2+4*dimm_number,2);
                       // COMMENT IN LATER!!!! rc_num = rc_num | cke_4.clearBit(1);
		       if(rc_num) {
		          rc.setEcmdError(rc_num);
                          return rc;
		       }
                    }

                    // Propogate through the 4 MRS cmds
                    for ( mrs_number = 0; mrs_number < 7; mrs_number++)
                    {
                        //mrs_number = 1;
                        // Copying the current MRS into address buffer matching the MRS_array order
                        // Setting the bank address
                        if (mrs_number == 0)
                        {
                            rc_num = rc_num | address_16.insert(mrs3, 0, 16, 0);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);
                        }
                        else if ( mrs_number == 1)
                        {

                            rc_num = rc_num | address_16.insert(mrs6, 0, 16, 0);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5);
                        }
                        else if ( mrs_number == 2)
                        {
                            rc_num = rc_num | address_16.insert(mrs5, 0, 16, 0);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 2, 1, 5);
                        }
                        else if ( mrs_number == 3)
                        {
                            rc_num = rc_num | address_16.insert(mrs4, 0, 16, 0);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 2, 1, 5);
                        }
                        else if ( mrs_number == 4)
                        {
                            rc_num = rc_num | address_16.insert(mrs2, 0, 16, 0);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 2, 1, 5);
                        }
                        else if ( mrs_number == 5)
                        {
                            rc_num = rc_num | address_16.insert(mrs1, 0, 16, 0);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5);
                        }
                        else if ( mrs_number == 6)
                        {
                            rc_num = rc_num | address_16.insert(mrs0, 0, 16, 0);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 2, 1, 5);
                        }
                        //mrs_number = 7;

                       if (( address_mirror_map[i_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
                       {
                           rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm_number, rank_number, address_16, bank_3);
                           if(rc) return rc;
                       }


                        if (rc_num)
                        {
                            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
                            rc_buff.setEcmdError(rc_num);
                            return rc_buff;
                        }

                        // Send out to the CCS array
                        rc = mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
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
                                          i_port_number);
                        if(rc) return rc;
                        rc = mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1);
                        if(rc) return rc;
                        io_ccs_inst_cnt ++;



                    }

                    // Address inversion for RCD
                    if ( (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) )
                    {
                       FAPI_INF( "Sending out MRS with Address Inversion to B-side DRAMs\n");


                       // Propogate through the 4 MRS cmds
                       for ( mrs_number = 0; mrs_number < 7; mrs_number++)
                       {
                           //mrs_number = 1;
                           // Copying the current MRS into address buffer matching the MRS_array order
                           // Setting the bank address
                           if (mrs_number == 0)
                           {
                               rc_num = rc_num | address_16.insert(mrs3, 0, 16, 0);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);
                           }
                           else if ( mrs_number == 1)
                           {


                               rc_num = rc_num | address_16.insert(mrs6, 0, 16, 0);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5);
                           }
                           else if ( mrs_number == 2)
                           {
                               rc_num = rc_num | address_16.insert(mrs5, 0, 16, 0);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 0, 1, 7);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 1, 1, 6);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 2, 1, 5);
                           }
                           else if ( mrs_number == 3)
                           {
                               rc_num = rc_num | address_16.insert(mrs4, 0, 16, 0);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 0, 1, 7);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 1, 1, 6);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 2, 1, 5);
                           }
                           else if ( mrs_number == 4)
                           {
                               rc_num = rc_num | address_16.insert(mrs2, 0, 16, 0);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 0, 1, 7);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 1, 1, 6);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 2, 1, 5);
                           }
                           else if ( mrs_number == 5)
                           {
                               rc_num = rc_num | address_16.insert(mrs1, 0, 16, 0);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5);
                           }
                           else if ( mrs_number == 6)
                           {
                               rc_num = rc_num | address_16.insert(mrs0, 0, 16, 0);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 0, 1, 7);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 1, 1, 6);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 2, 1, 5);
                           }

                           // Indicate B-Side DRAMS BG1=1
                           rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1

                           rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
                           rc_num = rc_num | address_16.flipBit(11);  // Invert A11
                           rc_num = rc_num | address_16.flipBit(13);  // Invert A13
                           rc_num = rc_num | address_16.flipBit(14);  // Invert A17
                           rc_num = rc_num | bank_3.flipBit(0,3);     // Invert BA0,BA1,BG0


                           if (( address_mirror_map[i_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
                           {
                               rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm_number, rank_number, address_16, bank_3);
                               if(rc) return rc;
                           }


                           if (rc_num)
                           {
                               FAPI_ERR( " Error setting up buffers");
                               rc_buff.setEcmdError(rc_num);
                               return rc_buff;
                           }

                           // Send out to the CCS array
                           rc = mss_ccs_inst_arry_0( i_target,
                                             io_ccs_inst_cnt,
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
                                             i_port_number);
                           if(rc) return rc;
                           rc = mss_ccs_inst_arry_1( i_target,
                                             io_ccs_inst_cnt,
                                             num_idles_16,
                                             num_repeat_16,
                                             data_20,
                                             read_compare_1,
                                             rank_cal_4,
                                             ddr_cal_enable_1,
                                             ccs_end_1);
                           if(rc) return rc;
                           io_ccs_inst_cnt ++;

                       }
                 }

            }
        }
    }

    return rc;
}

//Converts RTT_WR values to RTT_NOM
uint8_t convert_rtt_wr_to_rtt_nom(uint8_t rtt_wr, uint8_t & rtt_nom) {
   switch(rtt_wr) {
      case ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120:
           rtt_nom = ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM120;
	   break;
      case 240:
           rtt_nom = ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM240;
	   break;
      case 0xFF:
      case ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE: 
      default:
           FAPI_INF("RTT_WR is disabled! Skipping the swap of termination values to keep RTT_NOM with it's nominal values!!");
	   return 1;
   }
   return 0;
}

ReturnCode mss_ddr4_rtt_nom_rtt_wr_swap(
            Target& i_target,
            uint8_t i_mbaPosition,
            uint32_t i_port_number,
            uint8_t i_rank,
	    uint32_t i_rank_pair_group,
            uint32_t& io_ccs_inst_cnt,
	    uint8_t& io_dram_rtt_nom_original
            )
{
    // Target MBA level
    // This is a function written specifically for mss_draminit_training
    // Meant for placing RTT_WR into RTT_NOM within MR1 before wr_lvl
    // If the function argument dram_rtt_nom_original has a value of 0xFF it will put the original rtt_nom there
    // and write rtt_wr to the rtt_nom value
    // If the function argument dram_rtt_nom_original has any value besides 0xFF it will try to write that value to rtt_nom.
    
    FAPI_INF("Swapping RTT_WR values into RTT_NOM or swapping RTT_NOM back to its nominal value");
    
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;

    ecmdDataBufferBase address_16(16);
    ecmdDataBufferBase address_16_backup(16);
    ecmdDataBufferBase bank_3(3);
    ecmdDataBufferBase bank_3_backup(3);
    ecmdDataBufferBase activate_1(1);
    rc_num = rc_num | activate_1.setBit(0);
    ecmdDataBufferBase rasn_1(1);
    rc_num = rc_num | rasn_1.clearBit(0);
    ecmdDataBufferBase casn_1(1);
    rc_num = rc_num | casn_1.clearBit(0);
    ecmdDataBufferBase wen_1(1);
    rc_num = rc_num | wen_1.clearBit(0);
    ecmdDataBufferBase cke_4(4);
    rc_num = rc_num | cke_4.setBit(0,4);
    ecmdDataBufferBase csn_8(8);
    rc_num = rc_num | csn_8.setBit(0,8);
    ecmdDataBufferBase odt_4(4);
    rc_num = rc_num | odt_4.clearBit(0,4);
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);

    ecmdDataBufferBase mrs1_16(16);
    ecmdDataBufferBase mrs2_16(16);

    ecmdDataBufferBase data_buffer_64(64);

    uint8_t dimm = 0;
    uint8_t dimm_rank = 0;

    // dimm 0, dimm_rank 0-3 = ranks 0-3; dimm 1, dimm_rank 0-3 = ranks 4-7
    dimm = (i_rank) / 4;
    dimm_rank = i_rank - 4*dimm;


    uint8_t dimm_type;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;
    
    uint8_t dram_stack[2][2];
    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, dram_stack);
    if(rc) return rc;
   
    

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;


    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    rc_num = rc_num | csn_8.setBit(0,8);
    rc_num = rc_num | address_16.clearBit(0, 16);
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 400, 0, 16);
    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }
    rc = mss_ccs_inst_arry_0( i_target,
                              io_ccs_inst_cnt,
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
                              i_port_number);
    if(rc) return rc;
    rc = mss_ccs_inst_arry_1( i_target,
                              io_ccs_inst_cnt,
                              num_idles_16,
                              num_repeat_16,
                              data_20,
                              read_compare_1,
                              rank_cal_4,
                              ddr_cal_enable_1,
                              ccs_end_1);
    if(rc) return rc;
    io_ccs_inst_cnt ++;

    rc_num = rc_num | csn_8.setBit(0,8);
    rc_num = rc_num | csn_8.clearBit(i_rank);
    //sets up the MRS
    rc_num = rc_num | rasn_1.clearBit(0,1);
    rc_num = rc_num | casn_1.clearBit(0,1);
    rc_num = rc_num | wen_1.clearBit(0,1);
    
    // MRS CMD to CMD spacing = 12 cycles
    rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 12, 0, 16);
    if(rc_num)
    {
	rc.setEcmdError(rc_num);
	return rc;
    }

    FAPI_INF( "Editing RTT_NOM during wr_lvl or for PDA for %s PORT: %d RP: %d", i_target.toEcmdString(), i_port_number, i_rank_pair_group);
    
    //load nominal MRS values for the MR1, which contains RTT_NOM
    rc = mss_ddr4_load_nominal_mrs_pda(i_target, bank_3, address_16,MRS1_BA, i_port_number,  dimm,  dimm_rank);
    if(rc) return rc;
    
    uint8_t dram_rtt_nom[2][2][4];
    uint8_t dram_rtt_wr[2][2][4];
    
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_WR, &i_target, dram_rtt_wr);
    if(rc) return rc;
    
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_NOM, &i_target, dram_rtt_nom);
    if(rc) return rc;
    
    uint32_t addr16_print1,addr16_print2;
    addr16_print1 = addr16_print2 = 0;
    
    //do modifications based upon RTT_WR values if need be - a 0xFF indicates no swap done, so do the swap
    if(io_dram_rtt_nom_original == 0xFF) {
       io_dram_rtt_nom_original = 1;
       uint8_t skip_swap = convert_rtt_wr_to_rtt_nom(dram_rtt_wr[i_port_number][dimm][dimm_rank], dram_rtt_nom[i_port_number][dimm][dimm_rank]);
       //skips the remainder of the swapping code if it is not needed - this is not an error, just returning out of the function
       if(skip_swap) return rc;
       
       FAPI_INF("Swapping RTT_WR value of 0x%02x into RTT_NOM=0x%02x",dram_rtt_wr[i_port_number][dimm][dimm_rank],dram_rtt_nom[i_port_number][dimm][dimm_rank]);
       rc_num = rc_num | address_16.extractPreserve(&addr16_print1, 0, 16, 0);
       if(rc_num)
       {
	   rc.setEcmdError(rc_num);
	   return rc;
       }
       
       rc = mss_ddr4_modify_mrs_pda(i_target,address_16,ATTR_VPD_DRAM_RTT_NOM,dram_rtt_nom[i_port_number][dimm][dimm_rank]);
       if(rc) return rc;
       rc_num = rc_num | address_16.extractPreserve(&addr16_print2, 0, 16, 0);
       if(rc_num)
       {
	   rc.setEcmdError(rc_num);
	   return rc;
       }
       FAPI_INF("Modified MR1 to have RTT_WR's value in RTT_NOM");
       FAPI_INF("Printing before 0x%04x and after 0x%04x",addr16_print1,addr16_print2);
    }
    else {
       FAPI_INF("Not doing the swap, just setting back to nominal values 0x%02x",io_dram_rtt_nom_original);
       uint8_t skip_swap = convert_rtt_wr_to_rtt_nom(dram_rtt_wr[i_port_number][dimm][dimm_rank], dram_rtt_nom[i_port_number][dimm][dimm_rank]);
       //skips the remainder of the swapping code if it is not needed - this is not an error, just returning out of the function
       if(skip_swap) return rc;
    }
   
   rc_num = rc_num | address_16_backup.insert(address_16, 0, 16, 0);
   rc_num = rc_num | bank_3_backup.insert(bank_3, 0 , 3, 0);
   if(rc_num)
   {
       rc.setEcmdError(rc_num);
       return rc;
   }
   
   
   FAPI_INF("Issueing MRS command"); 
   
    //loads the previous DRAM
   if (( address_mirror_map[i_port_number][dimm] & (0x08 >> dimm_rank) ) && (is_sim == 0))
   {
       FAPI_INF("Doing address_mirroring_swizzle for %d %d %d %02x",i_port_number,dimm,dimm_rank,address_mirror_map[i_port_number][dimm] );
       rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm, dimm_rank, address_16, bank_3);
       if(rc) return rc;
   }
   else {
      FAPI_INF("No swizzle for address_mirroring_swizzle necessary for %d %d %d 0x%02x",i_port_number,dimm,dimm_rank,address_mirror_map[i_port_number][dimm] );
   }

   // Only corresponding CS to rank
   rc_num = rc_num | csn_8.setBit(0,8); 
   rc_num = rc_num | csn_8.clearBit(i_rank);
   if(dram_stack[i_port_number][dimm]  == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
      rc_num = rc_num | csn_8.clearBit(2,2); 
      rc_num = rc_num | csn_8.clearBit(6,2); 
   }
   
   if(rc_num)
   {
       rc.setEcmdError(rc_num);
       return rc;
   }
   
   // Send out to the CCS array 
   rc = mss_ccs_inst_arry_0( i_target,
   	    io_ccs_inst_cnt,
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
   	    i_port_number);
   if(rc) return rc;
   rc = mss_ccs_inst_arry_1( i_target,
   	    io_ccs_inst_cnt,
   	    num_idles_16,
   	    num_repeat_16,
   	    data_20,
   	    read_compare_1,
   	    rank_cal_4,
   	    ddr_cal_enable_1,
   	    ccs_end_1);
   if(rc) return rc;
   io_ccs_inst_cnt ++;

   //is an R or LR DIMM -> do a B side MRS write
   if ( (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) ) {
      //takes values from the backup
      rc_num = rc_num | address_16.clearBit(0, 16);
      rc_num = rc_num | address_16.insert(address_16_backup, 0, 16, 0);
      rc_num = rc_num | bank_3.clearBit(0,3);
      rc_num = rc_num | bank_3.insert(bank_3_backup, 0, 3, 0);
      
      //FLIPS all necessary bits
      // Indicate B-Side DRAMS BG1=1 
      rc_num = rc_num | address_16.setBit(15);  // Set BG1 = 1
 
      rc_num = rc_num | address_16.flipBit(3,7); // Invert A3:A9
      rc_num = rc_num | address_16.flipBit(11);  // Invert A11
      rc_num = rc_num | address_16.flipBit(13);  // Invert A13
      rc_num = rc_num | address_16.flipBit(14);  // Invert A17
      rc_num = rc_num | bank_3.flipBit(0,3);	 // Invert BA0,BA1,BG0
      
      if(rc_num)
      {
         rc.setEcmdError(rc_num);
         return rc;
      }
      
      //loads the previous DRAM
      if (( address_mirror_map[i_port_number][dimm] & (0x08 >> dimm_rank) ) && (is_sim == 0))
      {
   	  rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm, dimm_rank, address_16, bank_3);
   	  if(rc) return rc;
      }
      
      // Only corresponding CS to rank
      rc_num = rc_num | csn_8.setBit(0,8); 
      rc_num = rc_num | csn_8.clearBit(i_rank);
      if(dram_stack[i_port_number][dimm]  == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) {
         rc_num = rc_num | csn_8.clearBit(2,2); 
         rc_num = rc_num | csn_8.clearBit(6,2); 
      }
   
      if(rc_num)
      {
         rc.setEcmdError(rc_num);
         return rc;
      }
      
      // Send out to the CCS array 
      rc = mss_ccs_inst_arry_0( i_target,
   	       io_ccs_inst_cnt,
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
   	       i_port_number);
      if(rc) return rc;
      rc = mss_ccs_inst_arry_1( i_target,
   	       io_ccs_inst_cnt,
   	       num_idles_16,
   	       num_repeat_16,
   	       data_20,
   	       read_compare_1,
   	       rank_cal_4,
   	       ddr_cal_enable_1,
   	       ccs_end_1);
      if(rc) return rc;
      io_ccs_inst_cnt ++;
   }
   
   
   //sets a NOP as the last command
   rc_num = rc_num | cke_4.setBit(0,4);
   rc_num = rc_num | csn_8.setBit(0,8);
   rc_num = rc_num | address_16.clearBit(0, 16);
   rc_num = rc_num | rasn_1.setBit(0,1);
   rc_num = rc_num | casn_1.setBit(0,1);
   rc_num = rc_num | wen_1.setBit(0,1);
   
   if(rc_num)
   {
       rc.setEcmdError(rc_num);
       return rc;
   }
   
   // Send out to the CCS array 
   rc = mss_ccs_inst_arry_0( i_target,
   	    io_ccs_inst_cnt,
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
   	    i_port_number);
   if(rc) return rc;
   rc = mss_ccs_inst_arry_1( i_target,
   	    io_ccs_inst_cnt,
   	    num_idles_16,
   	    num_repeat_16,
   	    data_20,
   	    read_compare_1,
   	    rank_cal_4,
   	    ddr_cal_enable_1,
   	    ccs_end_1);
   if(rc) return rc;
   io_ccs_inst_cnt ++;
   
   //Setup end bit for CCS
   rc = mss_ccs_set_end_bit (i_target, io_ccs_inst_cnt-1);
   if (rc) return rc;
   
   //Execute the CCS array
   FAPI_INF("Executing the CCS array\n");
   rc = mss_execute_ccs_inst_array (i_target, 100, 60);
   if(rc) return rc;
    
    return rc;

}


//////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_modify_mrs_pda
/// disables per-DRAM addressability funcitonality on both ports on the passed MBA
//////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_modify_mrs_pda(Target& i_target,ecmdDataBufferBase& address_16,uint32_t attribute_name,uint8_t attribute_data) {
   ReturnCode rc;
   uint32_t rc_num = 0;
   uint8_t dram_bl = attribute_data;
   uint8_t read_bt = attribute_data; //Read Burst Type 
   uint8_t dram_cl = attribute_data;
   uint8_t test_mode = attribute_data; //TEST MODE 
   uint8_t dll_reset = attribute_data; //DLL Reset 
   uint8_t dram_wr = attribute_data; //DRAM write recovery
   uint8_t dram_rtp = attribute_data; //DRAM RTP - read to precharge
   uint8_t dram_wr_rtp = attribute_data;
   uint8_t dll_precharge = attribute_data; //DLL Control For Precharge if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_SLOWEXIT)
   uint8_t dll_enable = attribute_data; //DLL Enable 
   uint8_t out_drv_imp_cntl = attribute_data;
   uint8_t dram_rtt_nom = attribute_data;
   uint8_t dram_al = attribute_data;
   uint8_t wr_lvl = attribute_data; //write leveling enable
   uint8_t tdqs_enable = attribute_data; //TDQS Enable 
   uint8_t q_off = attribute_name; //Qoff - Output buffer Enable 
   uint8_t lpasr = attribute_data; // Low Power Auto Self-Refresh -- new not yet supported
   uint8_t cwl = attribute_data; // CAS Write Latency 
   uint8_t dram_rtt_wr = attribute_data;
   uint8_t mpr_op = attribute_data; // MPR Op
   uint8_t mpr_page = attribute_data; // MPR Page Selection  
   uint8_t geardown_mode = attribute_data; // Gear Down Mode  
   uint8_t temp_readout = attribute_data; // Temperature sensor readout  
   uint8_t fine_refresh = attribute_data; // fine refresh mode  
   uint8_t wr_latency = attribute_data; // write latency for CRC and DM  
   uint8_t write_crc = attribute_data; // CAS Write Latency 
   uint8_t read_format = attribute_data; // MPR READ FORMAT  
   uint8_t max_pd_mode = attribute_data; // Max Power down mode 
   uint8_t temp_ref_range = attribute_data; // Temp ref range 
   uint8_t temp_ref_mode = attribute_data; // Temp controlled ref mode 
   uint8_t vref_mon = attribute_data; // Internal Vref Monitor 
   uint8_t cs_cmd_latency = attribute_data; // CS to CMD/ADDR Latency 
   uint8_t ref_abort = attribute_data; // Self Refresh Abort 
   uint8_t rd_pre_train_mode = attribute_data; // Read Pre amble Training Mode 
   uint8_t rd_preamble = attribute_data; // Read Pre amble 
   uint8_t wr_preamble = attribute_data; // Write Pre amble 
   uint8_t ca_parity_latency = attribute_data; //C/A Parity Latency Mode  
   uint8_t crc_error_clear = attribute_data; //CRC Error Clear  
   uint8_t ca_parity_error_status = attribute_data; //C/A Parity Error Status  
   uint8_t odt_input_buffer = attribute_data; //ODT Input Buffer during power down  
   uint8_t rtt_park = attribute_data; //RTT_Park value  
   uint8_t ca_parity = attribute_data; //CA Parity Persistance Error  
   uint8_t data_mask = attribute_data; //Data Mask  
   uint8_t write_dbi = attribute_data; //Write DBI  
   uint8_t read_dbi = attribute_data; //Read DBI  
   uint8_t vrefdq_train_value = attribute_data; //vrefdq_train value   
   uint8_t vrefdq_train_range = attribute_data; //vrefdq_train range   
   uint8_t vrefdq_train_enable = attribute_data; //vrefdq_train enable  
   uint8_t tccd_l = attribute_data; //tccd_l  
   uint8_t dram_access;

   switch (attribute_name) {
       case ATTR_EFF_DRAM_BL:
	   if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_BL8)
           {
               dram_bl = 0x00;
           }
           else if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_OTF)
           {
               dram_bl = 0x80;
           }
           else if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_BC4)
           {
               dram_bl = 0x40;
           }
	   rc_num = rc_num | address_16.insert((uint8_t) dram_bl, 0, 2, 0);
	   break;
       case ATTR_EFF_DRAM_RBT:
	   if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_SEQUENTIAL)
           {
               read_bt = 0x00;
           }
           else if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_INTERLEAVE)
           {
               read_bt = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) read_bt, 3, 1, 0);
	   break;
       case ATTR_EFF_DRAM_CL:
	   if ((dram_cl > 8)&&(dram_cl < 17))
           {
               dram_cl = dram_cl - 9; 
           }
           else if ((dram_cl > 17)&&(dram_cl < 25))
           {
               dram_cl = (dram_cl >> 1) - 1;   
           }
           dram_cl = mss_reverse_8bits(dram_cl);
           rc_num = rc_num | address_16.insert((uint8_t) dram_cl, 2, 1, 0);
           rc_num = rc_num | address_16.insert((uint8_t) dram_cl, 4, 3, 1);
	   break;
       case ATTR_EFF_DRAM_TM:
	   if (test_mode == ENUM_ATTR_EFF_DRAM_TM_NORMAL)
           {
               test_mode = 0x00;
           }
           else if (test_mode == ENUM_ATTR_EFF_DRAM_TM_TEST)
           {
               test_mode = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) test_mode, 7, 1);
	   break;
       case ATTR_EFF_DRAM_DLL_RESET:
	   dll_reset = 0x00;
	   FAPI_ERR( "ERROR: ATTR_EFF_DRAM_DLL_RESET accessed during PDA functionality, overwritten");
           rc_num = rc_num | address_16.insert((uint8_t) dll_reset, 8, 1);
	   break;
       case ATTR_EFF_DRAM_WR:
           if ( (dram_wr == 10) )//&& (dram_rtp == 5) )
           {
               dram_wr_rtp = 0x00;
           }
           else if ( (dram_wr == 12) )//&& (dram_rtp == 6) )
           {
               dram_wr_rtp = 0x80;
           }
           else if ( (dram_wr == 13) )//&& (dram_rtp == 7) )
           {
               dram_wr_rtp = 0x40;
           }
           else if ( (dram_wr == 14) )//&& (dram_rtp == 8) )
           {
               dram_wr_rtp = 0xC0;
           }
           else if ( (dram_wr == 18) )//&& (dram_rtp == 9) )
           {
               dram_wr_rtp = 0x20;
           }
           else if ( (dram_wr == 20) )//&& (dram_rtp == 10) )
           {
               dram_wr_rtp = 0xA0;
           }
           else if ( (dram_wr == 24) )//&& (dram_rtp == 12) )
           {
               dram_wr_rtp = 0x60;
           }
    	   rc_num = rc_num | address_16.insert((uint8_t) dram_wr_rtp, 9, 3);
	   break;
       case ATTR_EFF_DRAM_TRTP:
           if ( (dram_rtp == 5) )
           {
               dram_wr_rtp = 0x00;
           }
           else if ( (dram_rtp == 6) )
           {
               dram_wr_rtp = 0x80;
           }
           else if ( (dram_rtp == 7) )
           {
               dram_wr_rtp = 0x40;
           }
           else if ( (dram_rtp == 8) )
           {
               dram_wr_rtp = 0xC0;
           }
           else if ( (dram_rtp == 9) )
           {
               dram_wr_rtp = 0x20;
           }
           else if ( (dram_rtp == 10) )
           {
               dram_wr_rtp = 0xA0;
           }
           else if ( (dram_rtp == 12) )
           {
               dram_wr_rtp = 0x60;
           }
    	   rc_num = rc_num | address_16.insert((uint8_t) dram_wr_rtp, 9, 3);
	   break;
       case ATTR_EFF_DRAM_DLL_PPD:
           if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_SLOWEXIT)
	   {
               dll_precharge = 0x00;
           }
           else if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_FASTEXIT)
           {
               dll_precharge = 0xFF;
           }
	   FAPI_INF("ERROR: ATTR_EFF_DRAM_DLL_PPD is an unused MRS value!!! Skipping...");
	   break;
       case ATTR_EFF_DRAM_DLL_ENABLE:
           if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_DISABLE)
           {
               dll_enable = 0x00;
           }
           else if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_ENABLE)
           {
               dll_enable = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) dll_enable, 0, 1, 0);
	   break;
       case ATTR_VPD_DRAM_RON:
	   if (out_drv_imp_cntl == ENUM_ATTR_VPD_DRAM_RON_OHM34)
           {
               out_drv_imp_cntl = 0x00;
           }
    	   // Not currently supported
           else if (out_drv_imp_cntl == ENUM_ATTR_VPD_DRAM_RON_OHM48) //not supported
           {
               out_drv_imp_cntl = 0x80;
           }
           rc_num = rc_num | address_16.insert((uint8_t) out_drv_imp_cntl, 1, 2, 0);
	   break;
       case ATTR_VPD_DRAM_RTT_NOM:
	   if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE)
           {
               dram_rtt_nom = 0x00;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM240) //not supported
           {
               dram_rtt_nom = 0x20;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM48) //not supported
           {
               dram_rtt_nom = 0xA0;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40)
           {
               dram_rtt_nom = 0xC0;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60)
           {
               dram_rtt_nom = 0x80;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM120)
           {
               dram_rtt_nom = 0x40;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM80) // not supported
           {
               dram_rtt_nom = 0x60;
           }
           else if (dram_rtt_nom == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34) // not supported
           {
               dram_rtt_nom = 0xE0;
           }
	   
           rc_num = rc_num | address_16.insert((uint8_t) dram_rtt_nom, 8, 3, 0);
	   break;
       case ATTR_EFF_DRAM_AL:
	   if (dram_al == ENUM_ATTR_EFF_DRAM_AL_DISABLE)
           {
               dram_al = 0x00;
           }
           else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_1)
           {
               dram_al = 0x80;
           }
           else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_2)
           {
               dram_al = 0x40;
           }
           rc_num = rc_num | address_16.insert((uint8_t) dram_al, 3, 2, 0);
	   break;
       case ATTR_EFF_DRAM_WR_LVL_ENABLE:
	   if (wr_lvl == ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_DISABLE)
           {
               wr_lvl = 0x00;
           }
           else if (wr_lvl == ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_ENABLE)
           {
               wr_lvl = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) wr_lvl, 7, 1, 0);
	   break;
       case ATTR_EFF_DRAM_TDQS:
	   if (tdqs_enable == ENUM_ATTR_EFF_DRAM_TDQS_DISABLE)
           {
               tdqs_enable = 0x00;
           }
           else if (tdqs_enable == ENUM_ATTR_EFF_DRAM_TDQS_ENABLE)
           {
               tdqs_enable = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) tdqs_enable, 11, 1, 0);
	   break;
       case ATTR_EFF_DRAM_OUTPUT_BUFFER:
           if (q_off == ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_DISABLE)
           {
               q_off = 0xFF;
           }
           else if (q_off == ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_ENABLE)
           {
               q_off = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) q_off, 12, 1, 0);
	   break;
       case ATTR_EFF_DRAM_LPASR:
           if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_NORMAL)
           {
               lpasr = 0x00;
           }
           else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_REDUCED)
           {
               lpasr = 0x80;
           }
           else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_EXTENDED)
           {
               lpasr = 0x40;
           }
           else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_ASR)
           {
               lpasr = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) lpasr, 6, 2);
	   break;
       case ATTR_EFF_DRAM_CWL:
	   if ((cwl > 8)&&(cwl < 13))
           {
               cwl = cwl - 9; 
           }
           else if ((cwl > 13)&&(cwl < 19))
           {
               cwl = (cwl >> 1) - 3;   
           }
           else
           {
              //no correcct value for CWL was found
              FAPI_INF("ERROR: Improper CWL value found. Setting CWL to 9 and continuing...");
              cwl = 0;
           }
	   cwl = mss_reverse_8bits(cwl);
	   rc_num = rc_num | address_16.insert((uint8_t) cwl, 3, 3);
	   break;
       case ATTR_VPD_DRAM_RTT_WR:
	   if (dram_rtt_wr == ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE)
           {
               dram_rtt_wr = 0x00;
           }
           else if (dram_rtt_wr == ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120)
           {
               dram_rtt_wr = 0x80;
           }
           else if (dram_rtt_wr == 240)//ENUM_ATTR_EFF_DRAM_RTT_WR_OHM240)
           {
               dram_rtt_wr = 0x40;
           }
           else if (dram_rtt_wr == 0xFF)//ENUM_ATTR_EFF_DRAM_RTT_WR_HIGHZ)
           {
               dram_rtt_wr = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) dram_rtt_wr, 9, 2);
           break;
       case ATTR_EFF_WRITE_CRC:
	   if ( write_crc == ENUM_ATTR_EFF_WRITE_CRC_ENABLE)
           {
               write_crc = 0xFF;
           }
           else if (write_crc == ENUM_ATTR_EFF_WRITE_CRC_DISABLE)
           {
               write_crc = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) write_crc, 12, 1);
	   break;
       case ATTR_EFF_MPR_MODE:
	   if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_ENABLE)
           {
               mpr_op = 0xFF;
           }
           else if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_DISABLE)
           {
               mpr_op = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) mpr_op, 2, 1);
	   break;
       case ATTR_EFF_MPR_PAGE:
           mpr_page = mss_reverse_8bits(mpr_page);
    	   rc_num = rc_num | address_16.insert((uint8_t) mpr_page, 0, 2);
	   break;
       case ATTR_EFF_GEARDOWN_MODE:
	   if ( geardown_mode == ENUM_ATTR_EFF_GEARDOWN_MODE_HALF)
           {
        	geardown_mode = 0x00;
           }
           else if ( geardown_mode == ENUM_ATTR_EFF_GEARDOWN_MODE_QUARTER)
           {
        	geardown_mode = 0xFF;
           }
           
           if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_ENABLE)
           {
               temp_readout = 0xFF;
           }
           else if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_DISABLE)
           {
               temp_readout = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) geardown_mode, 3, 1);
	   break;
       case ATTR_EFF_TEMP_READOUT:
	   if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_ENABLE)
    	   {
    	       temp_readout = 0xFF;
    	   }
    	   else if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_DISABLE)
    	   {
    	       temp_readout = 0x00;
    	   }
           rc_num = rc_num | address_16.insert((uint8_t) temp_readout, 5, 1);
	   break;
       case ATTR_EFF_FINE_REFRESH_MODE:
	   if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_NORMAL)
           {
               fine_refresh = 0x00;
           }
           else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_2X)
           {
               fine_refresh = 0x80;
           }
           else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_4X)
           {
               fine_refresh = 0x40;
           }
           else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_2X)
           {
               fine_refresh = 0xA0;
           }
           else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_4X)
           {
               fine_refresh = 0x60;
           }
           rc_num = rc_num | address_16.insert((uint8_t) fine_refresh, 6, 3);
	   break;
       case ATTR_EFF_CRC_WR_LATENCY:
           if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_4NCK)
           {
               wr_latency = 0x00;
           }
           else if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_5NCK)
           {
               wr_latency = 0x80;
           }
           else if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_6NCK)
           {
               wr_latency = 0xC0;
           }
           rc_num = rc_num | address_16.insert((uint8_t) wr_latency, 9, 2);
	   break;
       case ATTR_EFF_MPR_RD_FORMAT:
           if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_SERIAL)
           {
               read_format = 0x00;
           }
           else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_PARALLEL)
           {
               read_format = 0x80;
           }
           else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_STAGGERED)
           {
               read_format = 0x40;
           }
           else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_RESERVED_TEMP)
           {
               read_format = 0xC0;
           }
           rc_num = rc_num | address_16.insert((uint8_t) read_format, 11, 2);
	   break;
       case ATTR_EFF_PER_DRAM_ACCESS:
           FAPI_INF("ERROR: ATTR_EFF_PER_DRAM_ACCESS selected.  Forcing PDA to be on for this function");
	   dram_access = 0xFF;
	   rc_num = rc_num | address_16.insert((uint8_t) dram_access, 4, 1);
	   break;
       case ATTR_EFF_MAX_POWERDOWN_MODE:
	   if ( max_pd_mode == ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_ENABLE)
           {
               max_pd_mode = 0xF0;
           }
           else if ( max_pd_mode == ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_DISABLE)
           {
               max_pd_mode = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) max_pd_mode, 1, 1);
	   break;
       case ATTR_EFF_TEMP_REF_RANGE:
	   if (temp_ref_range == ENUM_ATTR_EFF_TEMP_REF_RANGE_NORMAL)
           {
               temp_ref_range = 0x00;
           }
           else if ( temp_ref_range== ENUM_ATTR_EFF_TEMP_REF_RANGE_EXTEND)
           {
               temp_ref_range = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) temp_ref_range, 2, 1);
	   break;
       case ATTR_EFF_TEMP_REF_MODE:
	   if (temp_ref_mode == ENUM_ATTR_EFF_TEMP_REF_MODE_ENABLE)
           {
               temp_ref_mode = 0x80;
           }
           else if (temp_ref_mode == ENUM_ATTR_EFF_TEMP_REF_MODE_DISABLE)
           {
               temp_ref_mode = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) temp_ref_mode, 3, 1);
	   break;
       case ATTR_EFF_INT_VREF_MON:
	   if ( vref_mon == ENUM_ATTR_EFF_INT_VREF_MON_ENABLE)
           {
               vref_mon = 0xFF;
           }
           else if ( vref_mon == ENUM_ATTR_EFF_INT_VREF_MON_DISABLE)
           {
               vref_mon = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) vref_mon, 4, 1);
	   break;
       case ATTR_EFF_CS_CMD_LATENCY:
	   if ( cs_cmd_latency == 3)
           {
               cs_cmd_latency = 0x80;
           }
           else if (cs_cmd_latency == 4)
           {
               cs_cmd_latency = 0x40;
           }
           else if (cs_cmd_latency == 5)
           {
               cs_cmd_latency = 0xC0;
           }
           else if (cs_cmd_latency == 6)
           {
               cs_cmd_latency = 0x20;
           }
           else if (cs_cmd_latency == 8)
           {
               cs_cmd_latency = 0xA0;
           }
           rc_num = rc_num | address_16.insert((uint8_t) cs_cmd_latency, 6, 3);
	   break;
       case ATTR_EFF_SELF_REF_ABORT:
	   if (ref_abort == ENUM_ATTR_EFF_SELF_REF_ABORT_ENABLE)
           {
               ref_abort = 0xFF;
           }
           else if (ref_abort == ENUM_ATTR_EFF_SELF_REF_ABORT_DISABLE)
           {
               ref_abort = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) ref_abort, 9, 1);
	   break;
       case ATTR_EFF_RD_PREAMBLE_TRAIN:
	   if (rd_pre_train_mode == ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_ENABLE)
           {
               rd_pre_train_mode = 0xFF;
           }
           else if (rd_pre_train_mode == ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_DISABLE)
           {
               rd_pre_train_mode = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) rd_pre_train_mode, 10, 1);
	   break;
       case ATTR_EFF_RD_PREAMBLE:
	   if (rd_preamble == ENUM_ATTR_EFF_RD_PREAMBLE_1NCLK)
           {
               rd_preamble = 0x00;
           }
           else if (rd_preamble == ENUM_ATTR_EFF_RD_PREAMBLE_2NCLK)
           {
               rd_preamble = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) rd_preamble, 11, 1);
	   break;
       case ATTR_EFF_WR_PREAMBLE:
           if (wr_preamble == ENUM_ATTR_EFF_WR_PREAMBLE_1NCLK)
           {
               wr_preamble = 0x00;
           }
           else if (wr_preamble == ENUM_ATTR_EFF_WR_PREAMBLE_2NCLK)
           {
               wr_preamble = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) wr_preamble, 12, 1);
	   break;
       case ATTR_EFF_CA_PARITY_LATENCY:
	   if (ca_parity_latency == 4)
           {
               ca_parity_latency = 0x80;
           }
           else if (ca_parity_latency == 5)
           {
               ca_parity_latency = 0x40;
           }
           else if (ca_parity_latency == 6)
           {
               ca_parity_latency = 0xC0;
           }
           else if (ca_parity_latency == 8)
           {
               ca_parity_latency = 0x20;
           }
           else if (ca_parity_latency == ENUM_ATTR_EFF_CA_PARITY_LATENCY_DISABLE)
           {
               ca_parity_latency = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) ca_parity_latency, 0, 2);
	   break;
       case ATTR_EFF_CRC_ERROR_CLEAR:
	   if (crc_error_clear == ENUM_ATTR_EFF_CRC_ERROR_CLEAR_ERROR)
           {
               crc_error_clear = 0xFF;
           }
           else if (crc_error_clear == ENUM_ATTR_EFF_CRC_ERROR_CLEAR_CLEAR)
           {
               crc_error_clear = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) crc_error_clear, 3, 1);
	   break;
       case ATTR_EFF_CA_PARITY_ERROR_STATUS:
	   if (ca_parity_error_status == ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_ERROR)
           {
               ca_parity_error_status = 0xFF;
           }
           else if (ca_parity_error_status == ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_CLEAR)
           {
               ca_parity_error_status = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) ca_parity_error_status, 4, 1);
	   break;
       case ATTR_EFF_ODT_INPUT_BUFF:
	   if (odt_input_buffer == ENUM_ATTR_EFF_ODT_INPUT_BUFF_ACTIVATED)
           {
               odt_input_buffer = 0x00;
           }
           else if (odt_input_buffer == ENUM_ATTR_EFF_ODT_INPUT_BUFF_DEACTIVATED)
           {
               odt_input_buffer = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) odt_input_buffer, 5, 1);
	   break;
       case ATTR_VPD_DRAM_RTT_PARK:
	   if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_DISABLE)
           {
               rtt_park = 0x00;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_60OHM)
           {
               rtt_park = 0x80;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_40OHM)
           {
               rtt_park = 0xC0;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_120OHM)
           {
               rtt_park = 0x40;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_240OHM)
           {
               rtt_park = 0x20;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_48OHM)
           {
               rtt_park = 0xA0;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_80OHM)
           {
               rtt_park = 0x60;
           }
           else if (rtt_park == ENUM_ATTR_VPD_DRAM_RTT_PARK_34OHM)
           {
               rtt_park = 0xE0;
           }
           rc_num = rc_num | address_16.insert((uint8_t) rtt_park, 6, 3);
	   break;
       case ATTR_EFF_CA_PARITY:
	   if (ca_parity == ENUM_ATTR_EFF_CA_PARITY_ENABLE)
           {
               ca_parity = 0xFF;
           }
           else if (ca_parity == ENUM_ATTR_EFF_CA_PARITY_DISABLE)
           {
               ca_parity = 0x00;
           }
           rc_num = rc_num | address_16.insert((uint8_t) ca_parity, 9, 1);
	   break;
       case ATTR_EFF_DATA_MASK:
	   if (data_mask == ENUM_ATTR_EFF_DATA_MASK_DISABLE)
           {
               data_mask = 0x00;
           }
           else if (data_mask == ENUM_ATTR_EFF_DATA_MASK_ENABLE)
           {
               data_mask = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) data_mask, 10, 1);
	   break;
       case ATTR_EFF_WRITE_DBI:
	   if (write_dbi == ENUM_ATTR_EFF_WRITE_DBI_DISABLE)
           {
               write_dbi = 0x00;
           }
           else if (write_dbi == ENUM_ATTR_EFF_WRITE_DBI_ENABLE)
           {
               write_dbi = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) write_dbi, 11, 1);
	   break;
       case ATTR_EFF_READ_DBI:
           if (read_dbi == ENUM_ATTR_EFF_READ_DBI_DISABLE)
           {
               read_dbi = 0x00;
           }
           else if (read_dbi == ENUM_ATTR_EFF_READ_DBI_ENABLE)
           {
               read_dbi = 0xFF;
           }
           rc_num = rc_num | address_16.insert((uint8_t) read_dbi, 12, 1);
	   break;
       case ATTR_EFF_VREF_DQ_TRAIN_VALUE:
	   vrefdq_train_value = mss_reverse_8bits(vrefdq_train_value);
           rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_value, 0, 6);
	   break;
       case ATTR_EFF_VREF_DQ_TRAIN_RANGE:
	   if (vrefdq_train_range == ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1)
           {
               vrefdq_train_range = 0x00;
           }
           else if (vrefdq_train_range == ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2)
           {
               vrefdq_train_range = 0xFF;
           } 
           rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_range, 6, 1);
	   break;
       case ATTR_EFF_VREF_DQ_TRAIN_ENABLE:
	   if (vrefdq_train_enable == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE)
           {
               vrefdq_train_enable = 0xFF;
           }
           else if (vrefdq_train_enable == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE)
           {
               vrefdq_train_enable = 0x00;
           }   
           rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_enable, 7, 1);
	   break;
       case ATTR_TCCD_L:
           if (tccd_l == 4)
           {
               tccd_l = 0x00;
           }
           else if (tccd_l == 5)
           {
               tccd_l = 0x80;
           }
           else if (tccd_l == 6)
           {
               tccd_l = 0x40;
           }	
           else if (tccd_l == 7)
           {
               tccd_l = 0xC0;
           }
           else if (tccd_l == 8)
           {
               tccd_l = 0x20;
           }
           rc_num = rc_num | address_16.insert((uint8_t) tccd_l, 10, 3);
	   break;
	//MRS attribute not found, error out
      default: 
         const uint32_t NONMRS_ATTR_NAME = attribute_name;
	 const fapi::Target & MBA_TARGET = i_target; 
	 FAPI_SET_HWP_ERROR(rc, RC_MSS_PDA_NONMRS_ATTR_NAME);
	 FAPI_ERR("ERROR!! Found attribute name not associated with an MRS! Exiting...");
   }
   if (rc_num)
   {
       FAPI_ERR( "mss_ddr4_modify_mrs_pda: Error setting up buffers");
       rc.setEcmdError(rc_num);
       return rc;
   }
   return rc;
}

//////////////////////////////////////////////////////////////////////////////////
/// mss_ddr4_load_nominal_mrs_pda
/// disables per-DRAM addressability funcitonality on both ports on the passed MBA
//////////////////////////////////////////////////////////////////////////////////
ReturnCode mss_ddr4_load_nominal_mrs_pda(Target& i_target,ecmdDataBufferBase& bank_3,ecmdDataBufferBase& address_16,uint8_t MRS,uint8_t i_port_number, uint8_t dimm_number, uint8_t rank_number) {
    ReturnCode rc;  
    uint32_t rc_num = 0;
    
    rc_num = rc_num | address_16.clearBit(0,16);
    rc_num = rc_num | bank_3.clearBit(0,3);
    if (rc_num)
    {
    	FAPI_ERR( "mss_mrs_load: Error setting up buffers");
    	rc.setEcmdError(rc_num);
    	return rc;
    }

    //Lines commented out in the following section are waiting for xml attribute adds
    //MRS0
    if(MRS == MRS0_BA) {
    	uint8_t dram_bl;
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_BL, &i_target, dram_bl);
    	if(rc) return rc;
    	uint8_t read_bt; //Read Burst Type 
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RBT, &i_target, read_bt);
    	if(rc) return rc;
    	uint8_t dram_cl;
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_CL, &i_target, dram_cl);
    	if(rc) return rc;
    	uint8_t test_mode; //TEST MODE 
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TM, &i_target, test_mode);
    	if(rc) return rc;
    	uint8_t dll_reset; //DLL Reset 
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DLL_RESET, &i_target, dll_reset);
    	if(rc) return rc;
    	uint8_t dram_wr; //DRAM write recovery
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR, &i_target, dram_wr);
    	if(rc) return rc;
    	uint8_t dram_rtp; //DRAM RTP - read to precharge
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TRTP, &i_target, dram_rtp);
    	if(rc) return rc;
    	uint8_t dll_precharge; //DLL Control For Precharge 
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DLL_PPD, &i_target, dll_precharge);
    	if(rc) return rc;

    	if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_BL8)
    	{
    	    dram_bl = 0x00;
    	}
    	else if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_OTF)
    	{
    	    dram_bl = 0x80;
    	}
    	else if (dram_bl == ENUM_ATTR_EFF_DRAM_BL_BC4)
    	{
    	    dram_bl = 0x40;
    	}

    	uint8_t dram_wr_rtp = 0x00;
    	if ( (dram_wr == 10) )//&& (dram_rtp == 5) )
    	{
    	    dram_wr_rtp = 0x00;
    	}
    	else if ( (dram_wr == 12) )//&& (dram_rtp == 6) )
    	{
    	    dram_wr_rtp = 0x80;
    	}
    	else if ( (dram_wr == 13) )//&& (dram_rtp == 7) )
    	{
    	    dram_wr_rtp = 0x40;
    	}
    	else if ( (dram_wr == 14) )//&& (dram_rtp == 8) )
    	{
    	    dram_wr_rtp = 0xC0;
    	}
    	else if ( (dram_wr == 18) )//&& (dram_rtp == 9) )
    	{
    	    dram_wr_rtp = 0x20;
    	}
    	else if ( (dram_wr == 20) )//&& (dram_rtp == 10) )
    	{
    	    dram_wr_rtp = 0xA0;
    	}
    	else if ( (dram_wr == 24) )//&& (dram_rtp == 12) )
    	{
    	    dram_wr_rtp = 0x60;
    	}

    	if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_SEQUENTIAL)
    	{
    	    read_bt = 0x00;
    	}
    	else if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_INTERLEAVE)
    	{
    	    read_bt = 0xFF;
    	}

    	if ((dram_cl > 8)&&(dram_cl < 17))
    	{
    	    dram_cl = dram_cl - 9; 
    	}
    	else if ((dram_cl > 17)&&(dram_cl < 25))
    	{
    	    dram_cl = (dram_cl >> 1) - 1;   
    	}
    	dram_cl = mss_reverse_8bits(dram_cl);

    	if (test_mode == ENUM_ATTR_EFF_DRAM_TM_NORMAL)
    	{
    	    test_mode = 0x00;
    	}
    	else if (test_mode == ENUM_ATTR_EFF_DRAM_TM_TEST)
    	{
    	    test_mode = 0xFF;
    	}
	
	FAPI_INF("Overwriting DLL reset with values to not reset the DRAM.");
    	dll_reset = 0x00;

    	if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_SLOWEXIT)
    	{
    	    dll_precharge = 0x00;
    	}
    	else if (dll_precharge == ENUM_ATTR_EFF_DRAM_DLL_PPD_FASTEXIT)
    	{
    	    dll_precharge = 0xFF;
    	}
	//For DDR4:
	//Address 14 = Address 17, Address 15 = BG1
        rc_num = rc_num | address_16.insert((uint8_t) dram_bl, 0, 2, 0);
        rc_num = rc_num | address_16.insert((uint8_t) dram_cl, 2, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) read_bt, 3, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) dram_cl, 4, 3, 1);
        rc_num = rc_num | address_16.insert((uint8_t) test_mode, 7, 1);
        rc_num = rc_num | address_16.insert((uint8_t) dll_reset, 8, 1);
	rc_num = rc_num | address_16.insert((uint8_t) dram_wr_rtp, 9, 3);
	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 12, 4);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS0_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    
    //MRS1
    else if(MRS == MRS1_BA) {
    	uint8_t dll_enable; //DLL Enable 
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DLL_ENABLE, &i_target, dll_enable);
    	if(rc) return rc;
    	uint8_t out_drv_imp_cntl[2][2];
    	rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RON, &i_target, out_drv_imp_cntl);
    	if(rc) return rc;
    	uint8_t dram_rtt_nom[2][2][4];
    	rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_NOM, &i_target, dram_rtt_nom);
    	if(rc) return rc;
    	uint8_t dram_al;
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_AL, &i_target, dram_al);
    	if(rc) return rc;
    	uint8_t wr_lvl; //write leveling enable
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR_LVL_ENABLE, &i_target, wr_lvl);
    	if(rc) return rc;
    	uint8_t tdqs_enable; //TDQS Enable 
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TDQS, &i_target, tdqs_enable);
    	if(rc) return rc;
    	uint8_t q_off; //Qoff - Output buffer Enable 
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_OUTPUT_BUFFER, &i_target, q_off);
    	if(rc) return rc;

    	if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_DISABLE)
    	{
    	    dll_enable = 0x00;
    	}
    	else if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_ENABLE)
    	{
    	    dll_enable = 0xFF;
    	}

    	if (dram_al == ENUM_ATTR_EFF_DRAM_AL_DISABLE)
    	{
    	    dram_al = 0x00;
    	}
    	else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_1)
    	{
    	    dram_al = 0x80;
    	}
    	else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_2)
    	{
    	    dram_al = 0x40;
    	}
	else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_3) {
	    dram_al = 0xC0;
	}

    	if (wr_lvl == ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_DISABLE)
    	{
    	    wr_lvl = 0x00;
    	}
    	else if (wr_lvl == ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_ENABLE)
    	{
    	    wr_lvl = 0xFF;
    	}

    	if (tdqs_enable == ENUM_ATTR_EFF_DRAM_TDQS_DISABLE)
    	{
    	    tdqs_enable = 0x00;
    	}
    	else if (tdqs_enable == ENUM_ATTR_EFF_DRAM_TDQS_ENABLE)
    	{
    	    tdqs_enable = 0xFF;
    	}

    	if (q_off == ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_DISABLE)
    	{
    	    q_off = 0xFF;
    	}
    	else if (q_off == ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_ENABLE)
    	{
    	    q_off = 0x00;
    	}
        if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE)
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x00;
        }
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM240) //not supported
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x20;
        }
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM48) //not supported
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xA0;
        }
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40)
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xC0;
        }
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60)
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x80;
        }
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM120)
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x40;
        }
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM80) // not supported
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x60;
        }
        else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34) // not supported
        {
            dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xE0;
        }

        if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_VPD_DRAM_RON_OHM34)
        {
            out_drv_imp_cntl[i_port_number][dimm_number] = 0x00;
        }
	// Not currently supported
        else if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_VPD_DRAM_RON_OHM48) //not supported
        {
            out_drv_imp_cntl[i_port_number][dimm_number] = 0x80;
        }

	//For DDR4:
	//Address 14 = Address 17, Address 15 = BG1
        rc_num = rc_num | address_16.insert((uint8_t) dll_enable, 0, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) out_drv_imp_cntl[i_port_number][dimm_number], 1, 2, 0);
        rc_num = rc_num | address_16.insert((uint8_t) dram_al, 3, 2, 0);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 5, 2);
        rc_num = rc_num | address_16.insert((uint8_t) wr_lvl, 7, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][rank_number], 8, 3, 0);
        rc_num = rc_num | address_16.insert((uint8_t) tdqs_enable, 11, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) q_off, 12, 1, 0);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 13, 3);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    //MRS2
    else if(MRS == MRS2_BA) {
    	uint8_t lpasr; // Low Power Auto Self-Refresh -- new not yet supported
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_LPASR, &i_target, lpasr);
    	if(rc) return rc;
    	uint8_t cwl; // CAS Write Latency 
    	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_CWL, &i_target, cwl);
    	if(rc) return rc;
    	uint8_t dram_rtt_wr[2][2][4];
    	rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_WR, &i_target, dram_rtt_wr);
    	if(rc) return rc;
    	uint8_t write_crc; // CAS Write Latency 
    	rc = FAPI_ATTR_GET(ATTR_EFF_WRITE_CRC, &i_target, write_crc);
    	if(rc) return rc;

    	if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_NORMAL)
    	{
    	    lpasr = 0x00;
    	}
    	else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_REDUCED)
    	{
    	    lpasr = 0x80;
    	}
    	else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_EXTENDED)
    	{
    	    lpasr = 0x40;
    	}
    	else if (lpasr == ENUM_ATTR_EFF_DRAM_LPASR_ASR)
    	{
    	    lpasr = 0xFF;
    	}

    	if ((cwl > 8)&&(cwl < 13))
    	{
    	    cwl = cwl - 9; 
    	}
    	else if ((cwl > 13)&&(cwl < 19))
    	{
    	    cwl = (cwl >> 1) - 3;   
    	}
    	else
    	{
    	   //no correcct value for CWL was found
    	   FAPI_INF("ERROR: Improper CWL value found. Setting CWL to 9 and continuing...");
    	   cwl = 0;
    	}
    	cwl = mss_reverse_8bits(cwl);

    	if ( write_crc == ENUM_ATTR_EFF_WRITE_CRC_ENABLE)
    	{
    	    write_crc = 0xFF;
    	}
    	else if (write_crc == ENUM_ATTR_EFF_WRITE_CRC_DISABLE)
    	{
    	    write_crc = 0x00;
    	}
	if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE)
        {
            dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x00;
        }
        else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120)
        {
            dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x80;
        }
        else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == 240)//ENUM_ATTR_EFF_DRAM_RTT_WR_OHM240)
        {
            dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x40;
        }
        else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == 0xFF)//ENUM_ATTR_EFF_DRAM_RTT_WR_HIGHZ)
        {
            dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0xFF;
        }

        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 0, 3);
        rc_num = rc_num | address_16.insert((uint8_t) cwl, 3, 3);
        rc_num = rc_num | address_16.insert((uint8_t) lpasr, 6, 2);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 8, 1);
        rc_num = rc_num | address_16.insert((uint8_t) dram_rtt_wr[i_port_number][dimm_number][rank_number], 9, 2);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 11, 1);
        rc_num = rc_num | address_16.insert((uint8_t) write_crc, 12, 1);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 13, 2);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS2_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    //MRS3
    else if(MRS == MRS3_BA) {
    	uint8_t mpr_op; // MPR Op
    	rc = FAPI_ATTR_GET(ATTR_EFF_MPR_MODE, &i_target, mpr_op);
    	if(rc) return rc;
    	uint8_t mpr_page; // MPR Page Selection  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_MPR_PAGE, &i_target, mpr_page);
    	if(rc) return rc;
    	uint8_t geardown_mode; // Gear Down Mode  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_GEARDOWN_MODE, &i_target, geardown_mode);
    	if(rc) return rc;
    	uint8_t temp_readout; // Temperature sensor readout  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_READOUT, &i_target, temp_readout);
    	if(rc) return rc;
    	uint8_t fine_refresh; // fine refresh mode  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_FINE_REFRESH_MODE, &i_target, fine_refresh);
    	if(rc) return rc;
    	uint8_t wr_latency; // write latency for CRC and DM  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CRC_WR_LATENCY, &i_target, wr_latency);
    	if(rc) return rc;
    	uint8_t read_format; // MPR READ FORMAT  - NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_MPR_RD_FORMAT, &i_target, read_format);
    	if(rc) return rc;

    	if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_ENABLE)
    	{
    	    mpr_op = 0xFF;
    	}
    	else if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_DISABLE)
    	{
    	    mpr_op = 0x00;
    	}

    	mpr_page = mss_reverse_8bits(mpr_page);

    	if ( geardown_mode == ENUM_ATTR_EFF_GEARDOWN_MODE_HALF)
    	{
    	     geardown_mode = 0x00;
    	}
    	else if ( geardown_mode == ENUM_ATTR_EFF_GEARDOWN_MODE_QUARTER)
    	{
    	     geardown_mode = 0xFF;
    	}
    	
    	if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_ENABLE)
    	{
    	    temp_readout = 0xFF;
    	}
    	else if (temp_readout == ENUM_ATTR_EFF_TEMP_READOUT_DISABLE)
    	{
    	    temp_readout = 0x00;
    	}

    	if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_NORMAL)
    	{
    	    fine_refresh = 0x00;
    	}
    	else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_2X)
    	{
    	    fine_refresh = 0x80;
    	}
    	else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_4X)
    	{
    	    fine_refresh = 0x40;
    	}
    	else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_2X)
    	{
    	    fine_refresh = 0xA0;
    	}
    	else if (fine_refresh == ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_4X)
    	{
    	    fine_refresh = 0x60;
    	}

    	if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_4NCK)
    	{
    	    wr_latency = 0x00;
    	}
    	else if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_5NCK)
    	{
    	    wr_latency = 0x80;
    	}
    	else if (wr_latency == ENUM_ATTR_EFF_CRC_WR_LATENCY_6NCK)
    	{
    	    wr_latency = 0xC0;
    	}

    	if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_SERIAL)
    	{
    	    read_format = 0x00;
    	}
    	else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_PARALLEL)
    	{
    	    read_format = 0x80;
    	}
    	else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_STAGGERED)
    	{
    	    read_format = 0x40;
    	}
    	else if (read_format == ENUM_ATTR_EFF_MPR_RD_FORMAT_RESERVED_TEMP)
    	{
    	    read_format = 0xC0;
    	}
	
	rc_num = rc_num | address_16.insert((uint8_t) mpr_page, 0, 2);
        rc_num = rc_num | address_16.insert((uint8_t) mpr_op, 2, 1);
        rc_num = rc_num | address_16.insert((uint8_t) geardown_mode, 3, 1);
        rc_num = rc_num | address_16.insert((uint8_t) 0xFF, 4, 1); //has PDA mode enabled!!!! just for this code!
        rc_num = rc_num | address_16.insert((uint8_t) temp_readout, 5, 1);
        rc_num = rc_num | address_16.insert((uint8_t) fine_refresh, 6, 3);
        rc_num = rc_num | address_16.insert((uint8_t) wr_latency, 9, 2);
        rc_num = rc_num | address_16.insert((uint8_t) read_format, 11, 2);
        rc_num = rc_num | address_16.insert((uint8_t) 0x00, 13, 2);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    //MRS4
    else if(MRS == MRS4_BA) {
    	uint8_t max_pd_mode; // Max Power down mode -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_MAX_POWERDOWN_MODE, &i_target, max_pd_mode);
    	if(rc) return rc;
    	uint8_t temp_ref_range; // Temp ref range -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_REF_RANGE, &i_target, temp_ref_range);
    	if(rc) return rc;
    	uint8_t temp_ref_mode; // Temp controlled ref mode -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_TEMP_REF_MODE, &i_target, temp_ref_mode);
    	if(rc) return rc;
    	uint8_t vref_mon; // Internal Vref Monitor -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_INT_VREF_MON, &i_target, vref_mon);
    	if(rc) return rc;
    	uint8_t cs_cmd_latency; // CS to CMD/ADDR Latency -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CS_CMD_LATENCY, &i_target, cs_cmd_latency);
    	if(rc) return rc;
    	uint8_t ref_abort; // Self Refresh Abort -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_SELF_REF_ABORT, &i_target, ref_abort);
    	if(rc) return rc;
    	uint8_t rd_pre_train_mode; // Read Pre amble Training Mode -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_RD_PREAMBLE_TRAIN, &i_target, rd_pre_train_mode);
    	if(rc) return rc;
    	uint8_t rd_preamble; // Read Pre amble -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_RD_PREAMBLE, &i_target, rd_preamble);
    	if(rc) return rc;
    	uint8_t wr_preamble; // Write Pre amble -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_WR_PREAMBLE, &i_target, wr_preamble);
    	if(rc) return rc;

    	if ( max_pd_mode == ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_ENABLE)
    	{
    	    max_pd_mode = 0xF0;
    	}
    	else if ( max_pd_mode == ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_DISABLE)
    	{
    	    max_pd_mode = 0x00;
    	}

    	if (temp_ref_range == ENUM_ATTR_EFF_TEMP_REF_RANGE_NORMAL)
    	{
    	    temp_ref_range = 0x00;
    	}
    	else if ( temp_ref_range== ENUM_ATTR_EFF_TEMP_REF_RANGE_EXTEND)
    	{
    	    temp_ref_range = 0xFF;
    	}

    	if (temp_ref_mode == ENUM_ATTR_EFF_TEMP_REF_MODE_ENABLE)
    	{
    	    temp_ref_mode = 0x80;
    	}
    	else if (temp_ref_mode == ENUM_ATTR_EFF_TEMP_REF_MODE_DISABLE)
    	{
    	    temp_ref_mode = 0x00;
    	}

    	if ( vref_mon == ENUM_ATTR_EFF_INT_VREF_MON_ENABLE)
    	{
    	    vref_mon = 0xFF;
    	}
    	else if ( vref_mon == ENUM_ATTR_EFF_INT_VREF_MON_DISABLE)
    	{
    	    vref_mon = 0x00;
    	}


    	if ( cs_cmd_latency == 3)
    	{
    	    cs_cmd_latency = 0x80;
    	}
    	else if (cs_cmd_latency == 4)
    	{
    	    cs_cmd_latency = 0x40;
    	}
    	else if (cs_cmd_latency == 5)
    	{
    	    cs_cmd_latency = 0xC0;
    	}
    	else if (cs_cmd_latency == 6)
    	{
    	    cs_cmd_latency = 0x20;
    	}
    	else if (cs_cmd_latency == 8)
    	{
    	    cs_cmd_latency = 0xA0;
    	}

    	if (ref_abort == ENUM_ATTR_EFF_SELF_REF_ABORT_ENABLE)
    	{
    	    ref_abort = 0xFF;
    	}
    	else if (ref_abort == ENUM_ATTR_EFF_SELF_REF_ABORT_DISABLE)
    	{
    	    ref_abort = 0x00;
    	}

    	if (rd_pre_train_mode == ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_ENABLE)
    	{
    	    rd_pre_train_mode = 0xFF;
    	}
    	else if (rd_pre_train_mode == ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_DISABLE)
    	{
    	    rd_pre_train_mode = 0x00;
    	}

    	if (rd_preamble == ENUM_ATTR_EFF_RD_PREAMBLE_1NCLK)
    	{
    	    rd_preamble = 0x00;
    	}
    	else if (rd_preamble == ENUM_ATTR_EFF_RD_PREAMBLE_2NCLK)
    	{
    	    rd_preamble = 0xFF;
    	}

    	if (wr_preamble == ENUM_ATTR_EFF_WR_PREAMBLE_1NCLK)
    	{
    	    wr_preamble = 0x00;
    	}
    	else if (wr_preamble == ENUM_ATTR_EFF_WR_PREAMBLE_2NCLK)
    	{
    	    wr_preamble = 0xFF;
    	}
    	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 0, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) max_pd_mode, 1, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) temp_ref_range, 2, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) temp_ref_mode, 3, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) vref_mon, 4, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 5, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) cs_cmd_latency, 6, 3);
    	rc_num = rc_num | address_16.insert((uint8_t) ref_abort, 9, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) rd_pre_train_mode, 10, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) rd_preamble, 11, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) wr_preamble, 12, 1);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS4_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    //MRS5
    else if(MRS == MRS5_BA) {
    	uint8_t ca_parity_latency; //C/A Parity Latency Mode  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CA_PARITY_LATENCY , &i_target, ca_parity_latency);
    	if(rc) return rc;
    	uint8_t crc_error_clear; //CRC Error Clear  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CRC_ERROR_CLEAR , &i_target, crc_error_clear);
    	if(rc) return rc;
    	uint8_t ca_parity_error_status; //C/A Parity Error Status  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CA_PARITY_ERROR_STATUS , &i_target, ca_parity_error_status);
    	if(rc) return rc;
    	uint8_t odt_input_buffer; //ODT Input Buffer during power down  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_ODT_INPUT_BUFF , &i_target, odt_input_buffer);
    	if(rc) return rc;
    	uint8_t rtt_park[2][2][4]; //RTT_Park value  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_PARK , &i_target, rtt_park);
    	if(rc) return rc;
    	uint8_t ca_parity; //CA Parity Persistance Error  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_CA_PARITY , &i_target, ca_parity);
    	if(rc) return rc;
    	uint8_t data_mask; //Data Mask  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_DATA_MASK , &i_target, data_mask);
    	if(rc) return rc;
    	uint8_t write_dbi; //Write DBI  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_WRITE_DBI , &i_target, write_dbi);
    	if(rc) return rc;
    	uint8_t read_dbi; //Read DBI  -  NEW
    	rc = FAPI_ATTR_GET(ATTR_EFF_READ_DBI , &i_target, read_dbi);
    	if(rc) return rc;


    	if (ca_parity_latency == 4)
    	{
    	    ca_parity_latency = 0x80;
    	}
    	else if (ca_parity_latency == 5)
    	{
    	    ca_parity_latency = 0x40;
    	}
    	else if (ca_parity_latency == 6)
    	{
    	    ca_parity_latency = 0xC0;
    	}
    	else if (ca_parity_latency == 8)
    	{
    	    ca_parity_latency = 0x20;
    	}
    	else if (ca_parity_latency == ENUM_ATTR_EFF_CA_PARITY_LATENCY_DISABLE)
    	{
    	    ca_parity_latency = 0x00;
    	}

    	if (crc_error_clear == ENUM_ATTR_EFF_CRC_ERROR_CLEAR_ERROR)
    	{
    	    crc_error_clear = 0xFF;
    	}
    	else if (crc_error_clear == ENUM_ATTR_EFF_CRC_ERROR_CLEAR_CLEAR)
    	{
    	    crc_error_clear = 0x00;
    	}

    	if (ca_parity_error_status == ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_ERROR)
    	{
    	    ca_parity_error_status = 0xFF;
    	}
    	else if (ca_parity_error_status == ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_CLEAR)
    	{
    	    ca_parity_error_status = 0x00;
    	}

    	if (odt_input_buffer == ENUM_ATTR_EFF_ODT_INPUT_BUFF_ACTIVATED)
    	{
    	    odt_input_buffer = 0x00;
    	}
    	else if (odt_input_buffer == ENUM_ATTR_EFF_ODT_INPUT_BUFF_DEACTIVATED)
    	{
    	    odt_input_buffer = 0xFF;
    	}


    	if (ca_parity == ENUM_ATTR_EFF_CA_PARITY_ENABLE)
    	{
    	    ca_parity = 0xFF;
    	}
    	else if (ca_parity == ENUM_ATTR_EFF_CA_PARITY_DISABLE)
    	{
    	    ca_parity = 0x00;
    	}

    	if (data_mask == ENUM_ATTR_EFF_DATA_MASK_DISABLE)
    	{
    	    data_mask = 0x00;
    	}
    	else if (data_mask == ENUM_ATTR_EFF_DATA_MASK_ENABLE)
    	{
    	    data_mask = 0xFF;
    	}

    	if (write_dbi == ENUM_ATTR_EFF_WRITE_DBI_DISABLE)
    	{
    	    write_dbi = 0x00;
    	}
    	else if (write_dbi == ENUM_ATTR_EFF_WRITE_DBI_ENABLE)
    	{
    	    write_dbi = 0xFF;
    	}

    	if (read_dbi == ENUM_ATTR_EFF_READ_DBI_DISABLE)
    	{
    	    read_dbi = 0x00;
    	}
    	else if (read_dbi == ENUM_ATTR_EFF_READ_DBI_ENABLE)
    	{
    	    read_dbi = 0xFF;
    	}
    	if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_DISABLE)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0x00;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_60OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0x80;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_40OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0xC0;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_120OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0x40;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_240OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0x20;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_48OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0xA0;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_80OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0x60;
    	}
    	else if (rtt_park[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_PARK_34OHM)
    	{
    	    rtt_park[i_port_number][dimm_number][rank_number] = 0xE0;
    	}

    	rc_num = rc_num | address_16.insert((uint8_t) ca_parity_latency, 0, 2);
    	rc_num = rc_num | address_16.insert((uint8_t) crc_error_clear, 3, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) ca_parity_error_status, 4, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) odt_input_buffer, 5, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) rtt_park[i_port_number][dimm_number][rank_number], 6, 3);
    	rc_num = rc_num | address_16.insert((uint8_t) ca_parity, 9, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) data_mask, 10, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) write_dbi, 11, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) read_dbi, 12, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 13, 2);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS5_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    //MRS6
    else if(MRS == MRS6_BA) {
    	uint8_t vrefdq_train_value[2][2][4]; //vrefdq_train value   -  NEW
    	rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_VALUE, &i_target, vrefdq_train_value);
    	if(rc) return rc;
    	uint8_t vrefdq_train_range[2][2][4]; //vrefdq_train range   -  NEW
    	rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_RANGE, &i_target, vrefdq_train_range);
    	if(rc) return rc;
    	uint8_t vrefdq_train_enable[2][2][4]; //vrefdq_train enable  -  NEW
    	rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target, vrefdq_train_enable);
    	if(rc) return rc;
    	uint8_t tccd_l; //tccd_l  -  NEW
    	rc = FAPI_ATTR_GET( ATTR_TCCD_L, &i_target, tccd_l);
    	if(rc) return rc;
    	if (tccd_l == 4)
    	{
    	    tccd_l = 0x00;
    	}
    	else if (tccd_l == 5)
    	{
    	    tccd_l = 0x80;
    	}
    	else if (tccd_l == 6)
    	{
    	    tccd_l = 0x40;
    	}    
    	else if (tccd_l == 7)
    	{
    	    tccd_l = 0xC0;
    	}
    	else if (tccd_l == 8)
    	{
    	    tccd_l = 0x20;
    	}

    	vrefdq_train_value[i_port_number][dimm_number][rank_number] = mss_reverse_8bits(vrefdq_train_value[i_port_number][dimm_number][rank_number]);

    	if (vrefdq_train_range[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1)
    	{
    	    vrefdq_train_range[i_port_number][dimm_number][rank_number] = 0x00;
    	}
    	else if (vrefdq_train_range[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2)
    	{
    	    vrefdq_train_range[i_port_number][dimm_number][rank_number] = 0xFF;
    	}   

    	if (vrefdq_train_enable[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE)
    	{
    	    vrefdq_train_enable[i_port_number][dimm_number][rank_number] = 0xFF;
    	}
    	else if (vrefdq_train_enable[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE)
    	{
    	    vrefdq_train_enable[i_port_number][dimm_number][rank_number] = 0x00;
    	}   

    	rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_value[i_port_number][dimm_number][rank_number], 0, 6);
    	rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_range[i_port_number][dimm_number][rank_number], 6, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) vrefdq_train_enable[i_port_number][dimm_number][rank_number], 7, 1);
    	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 8, 2);
    	rc_num = rc_num | address_16.insert((uint8_t) tccd_l, 10, 3);
    	rc_num = rc_num | address_16.insert((uint8_t) 0x00, 13, 2);
	
	rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6);
        rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5);
	if (rc_num)
        {
            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    else {
        const uint32_t MRS_VALUE = MRS;
	const fapi::Target & MBA_TARGET = i_target; 
	FAPI_SET_HWP_ERROR(rc, RC_MSS_PDA_MRS_NOT_FOUND);
	FAPI_ERR("ERROR!! Found attribute name not associated with an MRS! Exiting...");
    }
    
    return rc;
}

//#endif






