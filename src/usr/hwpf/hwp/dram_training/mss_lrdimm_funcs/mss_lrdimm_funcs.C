/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_lrdimm_funcs/mss_lrdimm_funcs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: mss_lrdimm_funcs.C,v 1.9 2014/08/05 15:08:12 kahnevan Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : mss_lrdimm_funcs.C
// *! DESCRIPTION : Tools for LRDIMM centaur procedures
// *! OWNER NAME : kcook@us.ibm.com
// *! BACKUP NAME : mwuu@us.ibm.com
// #! ADDITIONAL COMMENTS :
//

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.8    | kcook    |13-FEB-14| More FW updates.
//  1.7    | kcook    |12-FEB-14| Updated HWP_ERROR per RAS review to be used with memory_mss_lrdimm_funcs.xml
//  1.6    | bellows  |02-JAN-14| VPD attribute removal
//  1.5    | kcook    |12/03/13 | Updated VPD attributes. 
//  1.4    | bellows  |09/16/13 | Hostboot compile update
//  1.3    | bellows  |09/16/13 | Added ID tag.
//  1.2    | kcook    |09/13/13 | Updated define FAPI_LRDIMM token.
//  1.1    | kcook    |08/27/13 | First drop of Centaur

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <fapi.H>
#include <mss_lrdimm_funcs.H>
#include <mss_funcs.H>

#ifdef FAPI_LRDIMM
const uint8_t MAX_NUM_DIMMS = 2;
const uint8_t MAX_NUM_LR_RANKS = 8;
const uint8_t MRS1_BA = 1;
const uint8_t PORT_SIZE = 2;
const uint8_t DIMM_SIZE = 2;
const uint8_t RANK_SIZE = 4;
const uint32_t MSS_EFF_VALID = 255;


using namespace fapi;

fapi::ReturnCode mss_lrdimm_rcd_load( fapi::Target& i_target, uint32_t port_number, uint32_t& ccs_inst_cnt)
{
    ReturnCode rc;
    uint8_t num_drops_per_port;
    // LRDIMM
    uint8_t func1_rcd_number_array_u8[12] = {7,0,1,2,8,9,10,11,12,13,14,15};
    uint8_t func2_rcd_number_array_u8[8] = {7,0,1,2,3,4,5,6};
    uint8_t func3_rcd_number_array_u8[7] = {7,0,1,2,6,8,9};
    uint8_t funcODT_rcd_number_array_u8[3] = {7,10,11};
    uint8_t *p_func_num_arr;
    ecmdDataBufferBase data_buff_rcd_word(64);
    uint64_t func_rcd_control_word[2];
    uint8_t num_ranks_array[2][2]; //[port][dimm]
    uint8_t dimm_number;
    uint8_t rank_number;
    uint64_t spd_func_words;
    uint64_t att_spd_func_words[2][2];
    uint8_t num_rows;
    uint8_t num_cols;
    uint8_t dram_width;
    uint64_t l_func1_mask = 0x00000000F00FFFFFLL;
    uint8_t l_rcd_cntl_word_0;
    uint8_t l_rcd_cntl_word_1;
    uint8_t l_rcd_cntl_word_2;
    uint8_t l_rcd_cntl_word_3;
    uint8_t l_rcd_cntl_word_4;
    uint8_t l_rcd_cntl_word_5;
    uint8_t l_rcd_cntl_word_6;
    uint8_t l_rcd_cntl_word_7;
    uint8_t l_rcd_cntl_word_8;
    uint8_t l_rcd_cntl_word_9;
    uint8_t l_rcd_cntl_word_10;
    uint8_t l_rcd_cntl_word_11;
    uint8_t dimm_func_vec;

    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_LRDIMM_ADDITIONAL_CNTL_WORDS, &i_target, att_spd_func_words);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ROWS, &i_target, num_rows);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_COLS, &i_target, num_cols);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, dram_width);
    if (rc) return rc;
    rc=FAPI_ATTR_GET(ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, &i_target, dimm_func_vec);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target, num_drops_per_port);
    if(rc) return rc;


    // Fucntion 1
    for (dimm_number = 0;dimm_number < MAX_NUM_DIMMS; dimm_number++)
    {

       if ( num_ranks_array[port_number][dimm_number] != 0 )
       {
          //F[1]RC0 IBT settings for DCS pins
          l_rcd_cntl_word_0 = 0; // IBT DCS[1:0] 100 Ohm,  DCS[3:2] IBT as defined DCS[1:0]
          l_rcd_cntl_word_1 = 0; //IBT DCKE 100 Ohm
          l_rcd_cntl_word_2 = 0; //IBT DODT[1:0] 100 Ohm

          l_rcd_cntl_word_7 = 1; //Function select
          l_rcd_cntl_word_9 = 0; //Refresh stagger = 0clocks
          l_rcd_cntl_word_10 = 0; //Refresh stagger limit = unimited

          data_buff_rcd_word.clearBit(0,64);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_0, 0,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_1, 4,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_2, 8,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_7, 28,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_9, 36,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_10, 40,4);

          func_rcd_control_word[dimm_number] = data_buff_rcd_word.getDoubleWord(0);
          if(rc) return rc;
          spd_func_words = att_spd_func_words[port_number][dimm_number] & l_func1_mask; // SPD for F[1]RC8,11-15
          func_rcd_control_word[dimm_number] = func_rcd_control_word[dimm_number] | spd_func_words;
       }
    }

    FAPI_INF("SELECTING FUNCTION %d", l_rcd_cntl_word_7);
    p_func_num_arr = func1_rcd_number_array_u8;
    rc = mss_spec_rcd_load(i_target, port_number, p_func_num_arr,
                           sizeof(func1_rcd_number_array_u8)/sizeof(func1_rcd_number_array_u8[0]),
                           func_rcd_control_word , ccs_inst_cnt,1);
    if(rc)
    {
       FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
       return rc;
    }

    // Function 2
    for (dimm_number = 0;dimm_number < MAX_NUM_DIMMS; dimm_number++)
    {
       if ( num_ranks_array[port_number][dimm_number] != 0 )
       {
          l_rcd_cntl_word_0 = 0; // Transparent mode
          l_rcd_cntl_word_1 = 0; // Reset control
          l_rcd_cntl_word_2 = 0; // SMBus access control
          l_rcd_cntl_word_3 = 8; // Training control & Errorout enable driven Low when Training
          l_rcd_cntl_word_4 = 0; // MEMBIST Rank control

          //RC5 DRAM row & column addressing
          if ( num_rows == 13 )
          {
             if ( num_cols == 10 )
             {
                l_rcd_cntl_word_5 = 0;
             }
             else if ( num_cols == 11 )
             {
                l_rcd_cntl_word_5 = 1;
             }
             else if ( num_cols == 12 )
             {
                l_rcd_cntl_word_5 = 2;
             }
             else if ( num_cols == 3 )
             {
                l_rcd_cntl_word_5 = 3;
             }
          }
          else if ( num_rows == 14 )
          {
             if ( num_cols == 10 )
             {
                l_rcd_cntl_word_5 = 4;
             }
             else if ( num_cols == 11 )
             {
                l_rcd_cntl_word_5 = 5;
             }
             else if ( num_cols == 12 )
             {
                l_rcd_cntl_word_5 = 6;
             }
             else if ( num_cols == 3 )
             {
                l_rcd_cntl_word_5 = 7;
             }
          }
          else if ( num_rows == 15 )
          {
             if ( num_cols == 10 )
             {
                l_rcd_cntl_word_5 = 8;
             }
             else if ( num_cols == 11 )
             {
                l_rcd_cntl_word_5 = 9;
             }
             else if ( num_cols == 12 )
             {
                l_rcd_cntl_word_5 = 10;
             }
             else if ( num_cols == 3 )
             {
                l_rcd_cntl_word_5 = 11;
             }
          }
          else if ( num_rows == 16 )
          {
             if ( num_cols == 10 )
             {
                l_rcd_cntl_word_5 = 12;
             }
             else if ( num_cols == 11 )
             {
                l_rcd_cntl_word_5 = 13;
             }
             else if ( num_cols == 12 )
             {
                l_rcd_cntl_word_5 = 14;
             }
             else if ( num_cols == 3 )
             {
                l_rcd_cntl_word_5 = 15;
             }
          }

          l_rcd_cntl_word_6 = 0; // MEMBIST control
          l_rcd_cntl_word_7 = 2; //Function select

          data_buff_rcd_word.clearBit(0,64);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_0, 0,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_1, 4,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_2, 8,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_3,12,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_4,16,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_5,20,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_6,24,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_7, 28,4);

          func_rcd_control_word[dimm_number] = data_buff_rcd_word.getDoubleWord(0);
        
          //check for rc but not seeing where rc is set in this loop/if statment
          if(rc) return rc;
       }
    }


    FAPI_INF("SELECTING FUNCTION %d", l_rcd_cntl_word_7);
    p_func_num_arr = func2_rcd_number_array_u8;
    rc = mss_spec_rcd_load(i_target, port_number, p_func_num_arr,
                           sizeof(func2_rcd_number_array_u8)/sizeof(func2_rcd_number_array_u8[0]),
                           func_rcd_control_word , ccs_inst_cnt,1);
    if(rc)
    {
       FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
       return rc;
    }

    // Function 3
    for (dimm_number = 0;dimm_number < MAX_NUM_DIMMS; dimm_number++)
    {
       if ( num_ranks_array[port_number][dimm_number] != 0 )
       {
          data_buff_rcd_word.setDoubleWord(0, att_spd_func_words[port_number][dimm_number]);
          data_buff_rcd_word.extractToRight(&l_rcd_cntl_word_8 , 40, 4); // f[3]RC8 is in space RCD10
          data_buff_rcd_word.extractToRight(&l_rcd_cntl_word_9 , 36, 4);

          //F[3]RC0 connector interface DQ RTT_Nom Termination, TDQS control
          if ( num_drops_per_port == ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL )
          { // Single rank, dual drop
             if ( dram_width == 8 )
             {
                l_rcd_cntl_word_0 = 9; // RTT_Nom 60 Ohm, TDQS enabled
             }
             else
             {
                l_rcd_cntl_word_0 = 1; // RTT_NOM 60 Ohm, TDQS disabled
             }
          }
          else
          { // Single rank, Single drop
             if ( dram_width == 8 )
             {
                l_rcd_cntl_word_0 = 9; // RTT_Nom 60 Ohm, TDQS enabled
             }
             else
             {
                l_rcd_cntl_word_0 = 1; // RTT_NOM 60 Ohm, TDQS disabled
             }
          }

          //F[3]RC1 connector interface DQ RTT_WR termination & Reference voltage
          if ( num_drops_per_port == ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL )
          { // Single rank, dual drop
             l_rcd_cntl_word_1 = 2; // RTT_WR 120 Ohm , VrefDQ input pin
             l_rcd_cntl_word_2 = 1; // Connecter interface DQ/DQS output driver imp 34 Ohm, DQ/DQS drivers enabled
          }
          else
          { // Single rank, Single drop
             l_rcd_cntl_word_1 = 0; // RTT_WR disabled, VrefDQ input pin
             l_rcd_cntl_word_2 = 1; // Connecter interface DQ/DQS output driver imp 34 Ohm, DQ/DQS drivers enabled
          }

          FAPI_INF("Using ATTR_EFF_SCHMOO_TEST_VALID for dq LRDIMM timing mode");
          rc=FAPI_ATTR_GET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target, l_rcd_cntl_word_6);

          l_rcd_cntl_word_7 = 3; //Function select

          data_buff_rcd_word.clearBit(0,64);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_0, 0,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_1, 4,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_2, 8,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_6,24,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_7, 28,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_8,32,4);
          data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_9, 36,4);

          func_rcd_control_word[dimm_number] = data_buff_rcd_word.getDoubleWord(0);
          //why check rc here and not at the FAPI_ATTR_GET line
          if(rc) return rc;
       }
    }

    FAPI_INF("SELECTING FUNCTION %d", l_rcd_cntl_word_7);
    p_func_num_arr = func3_rcd_number_array_u8;
    rc = mss_spec_rcd_load(i_target, port_number, p_func_num_arr,
                           sizeof(func3_rcd_number_array_u8)/sizeof(func3_rcd_number_array_u8[0]),
                           func_rcd_control_word , ccs_inst_cnt,1);
    if(rc)
    {
       FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
       return rc;
    }

    for ( rank_number = 0; rank_number < MAX_NUM_LR_RANKS; rank_number++ )
    {
       for (dimm_number = 0;dimm_number < MAX_NUM_DIMMS; dimm_number++)
       {
          if ( num_ranks_array[port_number][dimm_number] != 0 )
          {
             data_buff_rcd_word.setDoubleWord(0, att_spd_func_words[port_number][dimm_number]);
             data_buff_rcd_word.extractToRight(&l_rcd_cntl_word_10 , rank_number/2*8, 4);   // RC10 is in space RCD0/2/4/6
             data_buff_rcd_word.extractToRight(&l_rcd_cntl_word_11 , rank_number/2*8+4, 4); // RC11 is in space RCD1/3/5/7

             l_rcd_cntl_word_7 = rank_number + 3; // Function word select 3:10 for Ranks 0-7

             data_buff_rcd_word.clearBit(0,64);
             data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_7, 28,4);
             data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_10,40,4);
             data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_11,44,4);

             func_rcd_control_word[dimm_number] = data_buff_rcd_word.getDoubleWord(0);
             //not sure why the rc check is here since there are no rc calls
             if(rc) return rc;
          }
       }

       FAPI_INF("SELECTING FUNCTION %d", l_rcd_cntl_word_7);
       p_func_num_arr = funcODT_rcd_number_array_u8;
       rc = mss_spec_rcd_load(i_target, port_number, p_func_num_arr,
                              sizeof(funcODT_rcd_number_array_u8)/sizeof(funcODT_rcd_number_array_u8[0]),
                              func_rcd_control_word , ccs_inst_cnt,1);
       if(rc)
       {
          FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
          return rc;
       }
    } // end rank loop

    // Function 13
    l_rcd_cntl_word_7 = 13;
    FAPI_INF("SELECTING FUNCTION %d", l_rcd_cntl_word_7);

    uint8_t Rx_MR1_2_DATA[2][2];
    rc=FAPI_ATTR_GET(ATTR_LRDIMM_MR12_REG, &i_target, Rx_MR1_2_DATA);
    if(rc) return rc;

    uint8_t rcw = 7;
    uint64_t rcd0_15[2] = { 0x0000000D00000000ll,           // select FN 13  dimm0
                            0x0000000D00000000ll };         //     "         dimm1

    // set FN 13 via RC 7
    rc = mss_spec_rcd_load( i_target, port_number, &rcw, 1, rcd0_15, ccs_inst_cnt,1);
    if(rc)
    {
       FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)",
       uint32_t(rc), rc.getCreator());
       return rc;
    }

    uint8_t func13_rcd_number_array_size = 4;
    uint8_t func13_rcd_number_array_u8[4] = { 10, 11, 14, 15 };
    p_func_num_arr = func13_rcd_number_array_u8;

    data_buff_rcd_word.clearBit(0,64);
    data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_7, 28,4);  // select F13

    const uint8_t num_ecw = 11;          // number of external funcs
    uint8_t R2_7_MR1_2_DATA[2][2];
    R2_7_MR1_2_DATA[port_number][0] = Rx_MR1_2_DATA[port_number][0] & 0xE3; // disable RTT_NOM on ranks 2:7
    R2_7_MR1_2_DATA[port_number][1] = Rx_MR1_2_DATA[port_number][1] & 0xE3; // disable RTT_NOM on ranks 2:7


         // extended control word                        addr, data
    uint8_t   ext_funcs[MAX_NUM_DIMMS][num_ecw][2] = {
                                                      {
                                                       {0xAC, 0x00},      // MRS_CTRL = 0xAC;     snoop/forward/store
                                                                          // MRx_SNOOP = 0xC8-CF  MR(0:3) MR to DRAM      0xC8/C9-CE/CF
                                                       {0xC8, 0x00},      // MR0_SNOOP(0:7)  = 0xC8       MR0 to DRAM
                                                       {0xC9, 0x00},      // MR0_SNOOP(8:15) = 0xC9;      MR0 to DRAM
                                                                          // Rx_MR1_2 = 0xB8-BF;  R(0:7) ranks, RTT_WR, RTT_NOM, D_IMP
                                                       {0xB8, Rx_MR1_2_DATA[port_number][0]},   // rank 0
                                                       {0xB9, Rx_MR1_2_DATA[port_number][0]},   // rank 1
                                                       {0xBA, R2_7_MR1_2_DATA[port_number][0]}, // rank 2
                                                       {0xBB, R2_7_MR1_2_DATA[port_number][0]}, // rank 3
                                                       {0xBC, R2_7_MR1_2_DATA[port_number][0]}, // rank 4
                                                       {0xBD, R2_7_MR1_2_DATA[port_number][0]}, // rank 5
                                                       {0xBE, R2_7_MR1_2_DATA[port_number][0]}, // rank 6
                                                       {0xBF, R2_7_MR1_2_DATA[port_number][0]}  // rank 7
                                                      },
                                                      {
                                                       {0xAC, 0x00},      // MRS_CTRL = 0xAC;     snoop/forward/store
                                                                          // MRx_SNOOP = 0xC8-CF  MR(0:3) MR to DRAM      0xC8/C9-CE/CF
                                                       {0xC8, 0x00},      // MR0_SNOOP(0:7)  = 0xC8       MR0 to DRAM
                                                       {0xC9, 0x00},      // MR0_SNOOP(8:15) = 0xC9;      MR0 to DRAM
                                                                          // Rx_MR1_2 = 0xB8-BF;  R(0:7) ranks, RTT_WR, RTT_NOM, D_IMP
                                                       {0xB8, Rx_MR1_2_DATA[port_number][1]},   // rank 0
                                                       {0xB9, Rx_MR1_2_DATA[port_number][1]},   // rank 1
                                                       {0xBA, R2_7_MR1_2_DATA[port_number][1]}, // rank 2
                                                       {0xBB, R2_7_MR1_2_DATA[port_number][1]}, // rank 3
                                                       {0xBC, R2_7_MR1_2_DATA[port_number][1]}, // rank 4
                                                       {0xBD, R2_7_MR1_2_DATA[port_number][1]}, // rank 5
                                                       {0xBE, R2_7_MR1_2_DATA[port_number][1]}, // rank 6
                                                       {0xBF, R2_7_MR1_2_DATA[port_number][1]}  // rank 7
                                                      }
                                                     };
    for (uint8_t i=0; i < num_ecw; i++)
    {
       // set func_rcd_control_word[dimm_number]
       for (dimm_number = 0;dimm_number < MAX_NUM_DIMMS; dimm_number++)
       {
          if ( num_ranks_array[port_number][dimm_number] != 0 )
          {
             // load address
             data_buff_rcd_word.insertFromRight(ext_funcs[dimm_number][i][0],40,4);        // lsb address
             data_buff_rcd_word.insert(ext_funcs[dimm_number][i][0],44,4); // msb address
             // load data
             data_buff_rcd_word.insertFromRight(ext_funcs[dimm_number][i][1], 56,4);       // lsb data
             data_buff_rcd_word.insert(ext_funcs[dimm_number][i][1], 60,4);        // msb data

             func_rcd_control_word[dimm_number] = data_buff_rcd_word.getDoubleWord(0);
            
            //not sure where the rc call is made
             if(rc) return rc;
           } // end if  has ranks
       } // end dimm loop


       // load CCS with F13 RC 10:11, 14:15
       rc = mss_spec_rcd_load( i_target, port_number, p_func_num_arr, func13_rcd_number_array_size,
       func_rcd_control_word , ccs_inst_cnt,1);
       if(rc)
       {
          FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
          return rc;
       }
    } // end # extended control words to write
    // end Function 13

    // set FN 0 via RC 7
    rcd0_15[0] = 0;
    rcd0_15[1] = 0;
    rc = mss_spec_rcd_load( i_target, port_number, &rcw, 1, rcd0_15, ccs_inst_cnt,1);
    if(rc)
    {
       FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)",
       uint32_t(rc), rc.getCreator());
       return rc;
    }

    // force execute of remaining rcd               !! not necessary???  !!
    // Execute the contents of CCS array
    if (ccs_inst_cnt  > 0)
    {
    // Set the End bit on the last CCS Instruction
       rc = mss_ccs_set_end_bit( i_target, ccs_inst_cnt-1);
       if(rc)
       {
           FAPI_ERR("CCS_SET_END_BIT FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
           return rc;
       }

       rc = mss_execute_ccs_inst_array(i_target, 10, 10);
       if(rc)
       {
           FAPI_ERR(" EXECUTE_CCS_INST_ARRAY FAILED rc = 0x%08X (creator = %d)",
                                           uint32_t(rc), rc.getCreator());
           return rc;
       }

       ccs_inst_cnt = 0;
    }
    // end force execute of rcd


    return rc;

}

fapi::ReturnCode mss_lrdimm_mrs_load( fapi::Target& i_target , uint32_t i_port_number,uint32_t dimm_number, uint32_t& io_ccs_inst_cnt)
{
     // For LRDIMM  Set Rtt_nom, rtt_wr, driver impedance for R0 and R1
     // turn off  MRS broadcast
        ReturnCode rc;
        ReturnCode rc_buff;
        uint32_t rc_num = 0;
        ecmdDataBufferBase csn_8(8);
        rc_num = rc_num | csn_8.setBit(0,8);
        ecmdDataBufferBase address_16(16);
        ecmdDataBufferBase bank_3(3);
        ecmdDataBufferBase activate_1(1);
        ecmdDataBufferBase rasn_1(1);
        rc_num = rc_num | rasn_1.clearBit(0);
        ecmdDataBufferBase casn_1(1);
        rc_num = rc_num | casn_1.clearBit(0);
        ecmdDataBufferBase wen_1(1);
        rc_num = rc_num | wen_1.clearBit(0);
        ecmdDataBufferBase cke_4(4);
        rc_num = rc_num | cke_4.setBit(0,4);
        ecmdDataBufferBase odt_4(4);
        rc_num = rc_num | odt_4.setBit(0,4);
        ecmdDataBufferBase ddr_cal_type_4(4);
        ecmdDataBufferBase csn_setup_8(8);
        rc_num = rc_num | csn_setup_8.setBit(0,8);

        ecmdDataBufferBase num_idles_16(16);
        rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 400, 0, 16);
        ecmdDataBufferBase num_idles_setup_16(16);
        rc_num = rc_num | num_idles_setup_16.insertFromRight((uint32_t) 400, 0, 16);
        ecmdDataBufferBase num_repeat_16(16);
        ecmdDataBufferBase data_20(20);
        ecmdDataBufferBase read_compare_1(1);
        ecmdDataBufferBase rank_cal_4(4);
        ecmdDataBufferBase ddr_cal_enable_1(1);
        ecmdDataBufferBase ccs_end_1(1);

        ecmdDataBufferBase mrs1(16);
        uint16_t MRS1 = 0;
        //uint32_t mrs_number;
        uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
        uint8_t is_sim = 0;
        uint8_t dram_2n_mode = 0;
 
        uint32_t rank_number;
        uint16_t num_ranks = 2;
        uint8_t func13_rcd_number_array_size;
        uint8_t func13_rcd_number_array_u8[4] = {10,11,14,15};
        ecmdDataBufferBase data_buff_rcd_word(64);
        uint8_t l_rcd_cntl_word_7 = 0;
        uint64_t func_rcd_control_word[2];
        uint8_t l_rcd_cntl_word_14;
        uint64_t rcd_array[2][2]; //[port][dimm]
        uint8_t num_ranks_array[2][2];

        // cs 0:7                   R0   R1   R2   R3   R4   R5   R6   R7
        uint8_t lrdimm_cs8n [] = { 0x4, 0x8, 0x6, 0xA, 0x5, 0x9, 0x7, 0xB };

        rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target, rcd_array);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_2N_MODE_ENABLED, &i_target, dram_2n_mode);
        if(rc) return rc;

        //MRS1
        uint8_t dll_enable;
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


        if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_ENABLE)
        {
            dll_enable = 0x00;
        }
        else if (dll_enable == ENUM_ATTR_EFF_DRAM_DLL_ENABLE_DISABLE)
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

        for (uint8_t dimm_num = 0;dimm_num < MAX_NUM_DIMMS; dimm_num++)
        {

           if ( num_ranks_array[i_port_number][dimm_num] != 0 )
           {
              l_rcd_cntl_word_14 = (rcd_array[i_port_number][dimm_num] & 0xF0) >> 4;  // MRS broadcast
              FAPI_INF("current F0RC14 = 0x%X",l_rcd_cntl_word_14);
              l_rcd_cntl_word_14 = l_rcd_cntl_word_14 | 0x4;
              FAPI_INF("setting F0RC14 = 0x%X",l_rcd_cntl_word_14);
              data_buff_rcd_word.clearBit(0,64);
              data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_14, 56,4);
              func_rcd_control_word[dimm_num] = data_buff_rcd_word.getDoubleWord(0);
            
              //not sure need this rc check
              if(rc) return rc;
           }
        }

        FAPI_INF("SELECTING FUNCTION %d", l_rcd_cntl_word_7);

        uint8_t *p_func_num_arr;
        uint8_t func0_rcd_number_array_size = 2;
        uint8_t func0_rcd_number_array_u8[] = { 7, 14 };
        p_func_num_arr = func0_rcd_number_array_u8;
        rc = mss_spec_rcd_load(i_target, i_port_number, p_func_num_arr, func0_rcd_number_array_size,
                                  func_rcd_control_word , io_ccs_inst_cnt,1);
        if(rc)
        {
           FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
           return rc;
        }


        // set FN 0 via RC 7
        func_rcd_control_word[0]=0;
        func_rcd_control_word[1]=0;
        func0_rcd_number_array_u8 [0] = 7;
        rc = mss_spec_rcd_load( i_target, i_port_number, p_func_num_arr, 1,
                                func_rcd_control_word, io_ccs_inst_cnt,1);

        if(rc)
        {
           FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
           return rc;
        }
     // end turn off MRS broadcast

     // Disable MRS snooping
        l_rcd_cntl_word_7 = 13;
        FAPI_INF("SELECTING FUNCTION %d", l_rcd_cntl_word_7);

        // extended control word  addr, data
        uint8_t ext_func[2] =   { 0xAC, 0x04};                  // MRS_CTRL = 0xAC;     snoop/forward/store
        uint8_t rcw = 7;
        uint64_t rcd0_15[2] = { 0x0000000D00000000ll,           // select FN 13  dimm0
                                0x0000000D00000000ll };         // "             dimm1

        // set FN 13 via RC 7
        rc = mss_spec_rcd_load( i_target, i_port_number, &rcw, 1, rcd0_15, io_ccs_inst_cnt,1);
        if(rc)
        {
           FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)",
                            uint32_t(rc), rc.getCreator());
           return rc;
        }

        func13_rcd_number_array_size = 4;
        p_func_num_arr = func13_rcd_number_array_u8;

        data_buff_rcd_word.clearBit(0,64);
        data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_7, 28,4);   // select F13

        // set func_rcd_control_word[dimm_number]
        if ( num_ranks_array[i_port_number][dimm_number] != 0 ) {
           // load address
           data_buff_rcd_word.insertFromRight(ext_func[0],40,4);    // lsb address
           data_buff_rcd_word.insert(ext_func[0],44,4);     // msb address
           // load data
           data_buff_rcd_word.insertFromRight(ext_func[1], 56,4);   // lsb data
           data_buff_rcd_word.insert(ext_func[1], 60,4);    // msb data

           func_rcd_control_word[dimm_number] = data_buff_rcd_word.getDoubleWord(0);
           //not sure need this rc check
           if(rc) return rc;
        } // end if  has ranks

        // load CCS with F13 RC 10:11, 14:15
        rc = mss_spec_rcd_load( i_target, i_port_number, p_func_num_arr, func13_rcd_number_array_size,
                                       func_rcd_control_word , io_ccs_inst_cnt,1);
        if(rc)
        {
               FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
               return rc;
        }

        // set FN 0 via RC 7
        rcd0_15[0] = 0;
        rcd0_15[1] = 0;
        rc = mss_spec_rcd_load( i_target, i_port_number, &rcw, 1, rcd0_15, io_ccs_inst_cnt,1);
        if(rc)
        {
           FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)",
                           uint32_t(rc), rc.getCreator());
           return rc;
        }

     // force execute of remaining rcd               !! not necessary???  !!
        // Execute the contents of CCS array
        if (io_ccs_inst_cnt  > 0)
        {
           // Set the End bit on the last CCS Instruction
           rc = mss_ccs_set_end_bit( i_target, io_ccs_inst_cnt-1);
           if(rc)
           {
                   FAPI_ERR("CCS_SET_END_BIT FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                   return rc;
           }

           rc = mss_execute_ccs_inst_array(i_target, 10, 10);
           if(rc)
           {
                   FAPI_ERR(" EXECUTE_CCS_INST_ARRAY FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                   return rc;
           }

           io_ccs_inst_cnt = 0;
        }
     // end force execute of rcd

     // Set RTT_nom, rtt_wr, driver impdance through MR1
        for ( rank_number = 0; rank_number < num_ranks; rank_number++)
        {
           FAPI_INF( "MRS SETTINGS FOR PORT%d DIMM%d RANK%d", i_port_number, dimm_number, rank_number);

           rc_num = rc_num | csn_8.setBit(0,8);
           rc_num = rc_num | address_16.clearBit(0, 16);

           if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE)
           {
               dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x00;
           }
           else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20)
           {
               dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x20;
           }
           else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30)
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

           if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_VPD_DRAM_RON_OHM40)
           {
               out_drv_imp_cntl[i_port_number][dimm_number] = 0x00;
           }
           else if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_VPD_DRAM_RON_OHM34)
           {
               out_drv_imp_cntl[i_port_number][dimm_number] = 0x80;
           }


           rc_num = rc_num | mrs1.insert((uint8_t) dll_enable, 0, 1, 0);
           rc_num = rc_num | mrs1.insert((uint8_t) out_drv_imp_cntl[i_port_number][dimm_number], 1, 1, 0);
           rc_num = rc_num | mrs1.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][rank_number], 2, 1, 0);
           rc_num = rc_num | mrs1.insert((uint8_t) dram_al, 3, 2, 0);
           rc_num = rc_num | mrs1.insert((uint8_t) out_drv_imp_cntl[i_port_number][dimm_number], 5, 1, 1);
           rc_num = rc_num | mrs1.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][rank_number], 6, 1, 1);
           rc_num = rc_num | mrs1.insert((uint8_t) wr_lvl, 7, 1, 0);
           rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 8, 1);
           rc_num = rc_num | mrs1.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][rank_number], 9, 1, 2);
           rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 10, 1);
           rc_num = rc_num | mrs1.insert((uint8_t) tdqs_enable, 11, 1, 0);
           rc_num = rc_num | mrs1.insert((uint8_t) q_off, 12, 1, 0);
           rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 13, 3);

           rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);

           FAPI_INF( "MRS 1: 0x%04X", MRS1);

           if (rc_num)
           {
               FAPI_ERR( "mss_mrs_load: Error setting up buffers");
               rc_buff.setEcmdError(rc_num);
               return rc_buff;
           }

           // Only corresponding CS to rank
           rc_num = rc_num | csn_8.setBit(0,8);
           rc_num = rc_num | csn_8.insert(lrdimm_cs8n[rank_number],(4*dimm_number),4,4);
           //mrs_number = 2;

           // Copying the current MRS into address buffer matching the MRS_array order
           // Setting the bank address
           rc_num = rc_num | address_16.insert(mrs1, 0, 16, 0);
           rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7);
           rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6);
           rc_num = rc_num | bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5);


           if (rc_num)
           {
               FAPI_ERR( "mss_mrs_load: Error setting up buffers");
               rc_buff.setEcmdError(rc_num);
               return rc_buff;
           }

           if (( address_mirror_map[i_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
           {
               rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm_number, rank_number, address_16, bank_3);
           }


           if (dram_2n_mode  == ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_TRUE)
           {

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
                                csn_setup_8,
                                odt_4,
                                ddr_cal_type_4,
                                i_port_number);
              if(rc) return rc;
              rc = mss_ccs_inst_arry_1( i_target,
                                io_ccs_inst_cnt,
                                num_idles_setup_16,
                                num_repeat_16,
                                data_20,
                                read_compare_1,
                                rank_cal_4,
                                ddr_cal_enable_1,
                                ccs_end_1);
              if(rc) return rc;
              io_ccs_inst_cnt ++;
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

        } // end rank loop

     // turn on  MRS broadcast

        l_rcd_cntl_word_7 = 0;

        for (uint8_t dimm_num = 0;dimm_num < MAX_NUM_DIMMS; dimm_num++)
        {

           if ( num_ranks_array[i_port_number][dimm_num] != 0 )
           {
              l_rcd_cntl_word_14 = (rcd_array[i_port_number][dimm_num] & 0xF0) >> 4;  // MRS broadcast
              FAPI_INF("current F0RC14 = 0x%X",l_rcd_cntl_word_14);
              l_rcd_cntl_word_14 = l_rcd_cntl_word_14 & 0xB;
              FAPI_INF("setting F0RC14 = 0x%X",l_rcd_cntl_word_14);
              ecmdDataBufferBase data_buff_rcd_word(64);
              data_buff_rcd_word.clearBit(0,64);
              data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_14, 56,4);
              func_rcd_control_word[dimm_num] = data_buff_rcd_word.getDoubleWord(0);

              //not sure if need the rc check
              if(rc) return rc;
           }
        }

        FAPI_INF("SELECTING FUNCTION %d", l_rcd_cntl_word_7);

        func0_rcd_number_array_size = 2;
        p_func_num_arr = func0_rcd_number_array_u8;
        rc = mss_spec_rcd_load(i_target, i_port_number, p_func_num_arr, func0_rcd_number_array_size,
                                  func_rcd_control_word , io_ccs_inst_cnt,1);
        if(rc)
        {
           FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
           return rc;
        }


        // set FN 0 via RC 7
        func_rcd_control_word[0]=0;
        func_rcd_control_word[1]=0;
        func0_rcd_number_array_u8 [0] = 7;
        rc = mss_spec_rcd_load( i_target, i_port_number, p_func_num_arr, 1,
                                 func_rcd_control_word, io_ccs_inst_cnt,1);

        if(rc)
        {
           FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
           return rc;
        }
     // end turn on MRS broadcast

     // Enable MRS snooping
        l_rcd_cntl_word_7 = 13;
        FAPI_INF("SELECTING FUNCTION %d", l_rcd_cntl_word_7);

        // extended control word  data
        ext_func[1] = 0x00;                  // MRS_CTRL = 0xAC;     snoop/forward/store
        rcw = 7;
        rcd0_15[0] = 0x0000000D00000000ll;          // select FN 13  dimm0
        rcd0_15[1] = 0x0000000D00000000ll ;         // "             dimm1

        // set FN 13 via RC 7
        rc = mss_spec_rcd_load( i_target, i_port_number, &rcw, 1, rcd0_15, io_ccs_inst_cnt,1);
        if(rc)
        {
           FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)",
                            uint32_t(rc), rc.getCreator());
           return rc;
        }

        func13_rcd_number_array_size = 4;
        p_func_num_arr = func13_rcd_number_array_u8;

        data_buff_rcd_word.clearBit(0,64);
        data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_7, 28,4);   // select F13

        // set func_rcd_control_word[dimm_number]
        if ( num_ranks_array[i_port_number][dimm_number] != 0 ) {
           // load address
           data_buff_rcd_word.insertFromRight(ext_func[0],40,4);    // lsb address
           data_buff_rcd_word.insert(ext_func[0],44,4);     // msb address
           // load data
           data_buff_rcd_word.insertFromRight(ext_func[1], 56,4);   // lsb data
           data_buff_rcd_word.insert(ext_func[1], 60,4);    // msb data

           func_rcd_control_word[dimm_number] = data_buff_rcd_word.getDoubleWord(0); if(rc) return rc;
        } // end if  has ranks


        // load CCS with F13 RC 10:11, 14:15
        rc = mss_spec_rcd_load( i_target, i_port_number, p_func_num_arr, func13_rcd_number_array_size,
                       func_rcd_control_word , io_ccs_inst_cnt,1);
        if(rc)
        {
               FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
               return rc;
        }

        // set FN 0 via RC 7
        rcd0_15[0] = 0;
        rcd0_15[1] = 0;
        rc = mss_spec_rcd_load( i_target, i_port_number, &rcw, 1, rcd0_15, io_ccs_inst_cnt,1);
        if(rc)
        {
           FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)",
                           uint32_t(rc), rc.getCreator());
           return rc;
        }

     // force execute of remaining rcd               !! not necessary???  !!
        // Execute the contents of CCS array
        if (io_ccs_inst_cnt  > 0)
        {
           // Set the End bit on the last CCS Instruction
           rc = mss_ccs_set_end_bit( i_target, io_ccs_inst_cnt-1);
           if(rc)
           {
                   FAPI_ERR("CCS_SET_END_BIT FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                   return rc;
           }

           rc = mss_execute_ccs_inst_array(i_target, 10, 10);
           if(rc)
           {
                   FAPI_ERR(" EXECUTE_CCS_INST_ARRAY FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                   return rc;
           }

           io_ccs_inst_cnt = 0;
        }
     // end force execute of rcd
     // End enable MRS snooping


    return rc;
}

fapi::ReturnCode  mss_execute_lrdimm_mb_dram_training(fapi::Target &i_target)
{
   ReturnCode rc;
   uint8_t l_rcd_cntl_word_7;
   uint8_t l_rcd_cntl_word_12;
   ecmdDataBufferBase data_buff_rcd_word(64);
   uint32_t port;
   uint8_t dimm_number;
   const uint8_t MAX_NUM_DIMMS = 2;
   const uint8_t MAX_NUM_PORT = 2;
   uint8_t num_ranks_array[MAX_NUM_PORT][MAX_NUM_DIMMS];
   uint64_t func_rcd_control_word[2];
   uint8_t *p_func_num_arr;
   uint8_t funcTRAIN_rcd_number_array_u8[2] = {7,12};

   uint32_t ccs_inst_cnt = 0;
   uint32_t rc_num = 0;
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
   rc_num = rc_num | csn_8.setBit(0,2);
   rc_num = rc_num | csn_8.setBit(4,2);
   ecmdDataBufferBase odt_4(4);
   rc_num = rc_num | odt_4.setBit(0,4);
   ecmdDataBufferBase ddr_cal_type_4(4);

   if(rc_num)
   {
       rc.setEcmdError(rc_num);
       return rc;
   }
   ecmdDataBufferBase num_idles_16(16);
   ecmdDataBufferBase num_repeat_16(16);
   ecmdDataBufferBase data_20(20);
   ecmdDataBufferBase read_compare_1(1);
   ecmdDataBufferBase rank_cal_4(4);
   ecmdDataBufferBase ddr_cal_enable_1(1);
   ecmdDataBufferBase ccs_end_1(1);

   uint32_t l_mss_freq;
   uint32_t l_num_idles_delay=20;

   fapi::Target l_target_centaur;
   rc = fapiGetParentChip(i_target, l_target_centaur);
   if(rc) return rc;

   rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_mss_freq);
   if(rc) return rc;

   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
   if(rc) return rc;

   for ( port = 0; port < MAX_NUM_PORT; port++ )
   {
      // MB-DRAM training
      l_rcd_cntl_word_7 = 0;
      l_rcd_cntl_word_12 = 2; // Training control, start DRAM interface training

      data_buff_rcd_word.clearBit(0,64);
      data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_7, 28, 4);
      data_buff_rcd_word.insertFromRight(&l_rcd_cntl_word_12, 48, 4);

      for ( dimm_number = 0; dimm_number < MAX_NUM_DIMMS; dimm_number++ )
      {
         if ( num_ranks_array[port][dimm_number] != 0 )
         {
            func_rcd_control_word[dimm_number] = data_buff_rcd_word.getDoubleWord(0);
            if(rc) return rc;
         }
      }

      FAPI_INF("SELECTING FUNCTION %d", l_rcd_cntl_word_7);
      p_func_num_arr = funcTRAIN_rcd_number_array_u8;
      rc = mss_spec_rcd_load(i_target, port, p_func_num_arr,
                            (uint8_t) sizeof(funcTRAIN_rcd_number_array_u8)/(uint8_t)sizeof(funcTRAIN_rcd_number_array_u8[0]),
                            func_rcd_control_word , ccs_inst_cnt,1);
      if(rc)
      {
         FAPI_ERR(" spec_rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
         return rc;
      }


      rc_num = rc_num | address_16.clearBit(0, 16);
      rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) l_num_idles_delay, 0, 16);
      if(rc_num)
      {
          rc.setEcmdError(rc_num);
          return rc;
      }

      rc = mss_ccs_inst_arry_0( i_target,
                                 ccs_inst_cnt,
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
                                 port);
      if(rc) return rc;
      rc = mss_ccs_inst_arry_1( i_target,
                                 ccs_inst_cnt,
                                 num_idles_16,
                                 num_repeat_16,
                                 data_20,
                                 read_compare_1,
                                 rank_cal_4,
                                 ddr_cal_enable_1,
                                 ccs_end_1);
      if(rc) return rc;
      ccs_inst_cnt++;
   }

   // Execute the contents of CCS array
   if (ccs_inst_cnt  > 0)
   {
   // Set the End bit on the last CCS Instruction
      rc = mss_ccs_set_end_bit( i_target, ccs_inst_cnt-1);
      if(rc)
      {
              FAPI_ERR("CCS_SET_END_BIT FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
              return rc;
      }

      rc = mss_execute_ccs_inst_array(i_target, 10, 10);
      if(rc)
      {
              FAPI_ERR(" EXECUTE_CCS_INST_ARRAY FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
              return rc;
      }

      ccs_inst_cnt = 0;
   }// end force execute of rcd
   return rc;
}

fapi::ReturnCode mss_lrdimm_eff_config(const fapi::Target &i_target_mba, 
                                 uint8_t cur_dimm_spd_valid_u8array[PORT_SIZE][DIMM_SIZE],
                                 uint32_t mss_freq, uint8_t eff_num_ranks_per_dimm[PORT_SIZE][DIMM_SIZE])
{
   ReturnCode rc;

   std::vector<fapi::Target> l_target_dimm_array;
   uint8_t l_cur_mba_port = 0;
   uint8_t l_cur_mba_dimm = 0;

   mss_lrdimm_spd_data *p_l_lr_spd_data = new mss_lrdimm_spd_data();
   memset( p_l_lr_spd_data, 0, sizeof(mss_lrdimm_spd_data) );

   uint8_t lrdimm_mr12_reg[PORT_SIZE][DIMM_SIZE];
   uint64_t lrdimm_additional_cntl_words[PORT_SIZE][DIMM_SIZE];
   uint8_t lrdimm_rank_mult_mode;
   uint8_t eff_ibm_type[PORT_SIZE][DIMM_SIZE];
   uint64_t eff_dimm_rcd_cntl_word_0_15[PORT_SIZE][DIMM_SIZE];

   do 
   {
      rc = fapiGetAssociatedDimms(i_target_mba, l_target_dimm_array);
      if(rc)
      {
          FAPI_ERR("Error retrieving assodiated dimms");
          break;
      }
   
      for (uint8_t l_dimm_index = 0; l_dimm_index < l_target_dimm_array.size(); l_dimm_index += 1)
      {
         rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &l_target_dimm_array[l_dimm_index],
                 l_cur_mba_port);
         if(rc)
         {
             FAPI_ERR("Error retrieving ATTR_MBA_PORT");
             break;
         }
   //------------------------------------------------------------------------
         rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &l_target_dimm_array[l_dimm_index], l_cur_mba_dimm);
         if(rc)
         {
             FAPI_ERR("Error retrieving ATTR_MBA_DIMM");
             break;
         }
   
         // Setup SPD attributes
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_ADDR_MIRRORING, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_addr_mirroring[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F0RC3_F0RC2, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f0rc3_f0rc2[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F0RC5_F0RC4, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f0rc5_f0rc4[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F1RC11_F1RC8, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f1rc11_f1rc8[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F1RC13_F1RC12, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f1rc13_f1rc12[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F1RC15_F1RC14, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f1rc15_f1rc14[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F3RC9_F3RC8_FOR_800_1066, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f3rc9_f3rc8_for_800_1066[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F34RC11_F34RC10_FOR_800_1066, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f34rc11_f34rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F56RC11_F56RC10_FOR_800_1066, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f56rc11_f56rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F78RC11_F78RC10_FOR_800_1066, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f78rc11_f78rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F910RC11_F910RC10_FOR_800_1066, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f910rc11_f910rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_MR12_FOR_800_1066, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_mr12_for_800_1066[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F3RC9_F3RC8_FOR_1333_1600, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f3rc9_f3rc8_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F34RC11_F34RC10_FOR_1333_1600, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f34rc11_f34rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F56RC11_F56RC10_FOR_1333_1600, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f56rc11_f56rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F78RC11_F78RC10_FOR_1333_1600, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f78rc11_f78rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F910RC11_F910RC10_FOR_1333_1600, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f910rc11_f910rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_MR12_FOR_1333_1600, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_mr12_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F3RC9_F3RC8_FOR_1866_2133, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f3rc9_f3rc8_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F34RC11_F34RC10_FOR_1866_2133, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f34rc11_f34rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F56RC11_F56RC10_FOR_1866_2133, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f56rc11_f56rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F78RC11_F78RC10_FOR_1866_2133, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f78rc11_f78rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_F910RC11_F910RC10_FOR_1866_2133, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_f910rc11_f910rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
         rc = FAPI_ATTR_GET(ATTR_SPD_LR_MR12_FOR_1866_2133, &l_target_dimm_array[l_dimm_index],
             p_l_lr_spd_data->lr_mr12_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm]);
         if(rc) break;
      }
   
      if(rc)
      {
          FAPI_ERR("Error reading spd data from caller");
          break;
      }
   
   
      // Setup attributes
      for (int l_cur_mba_port = 0; l_cur_mba_port < PORT_SIZE; l_cur_mba_port += 1)
      {
         for (int l_cur_mba_dimm = 0; l_cur_mba_dimm < DIMM_SIZE; l_cur_mba_dimm += 1)
         {
            if (cur_dimm_spd_valid_u8array[l_cur_mba_port][l_cur_mba_dimm] == MSS_EFF_VALID)
            {
               FAPI_INF("  !! LRDIMM Detected  -MW");
   
               ecmdDataBuffer rcd(64);
               rcd.flushTo0();
   
               rcd.setDoubleWord(0,eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm]);
               FAPI_INF("rcd0_15=0x%016llX",rcd.getDoubleWord(0));
   
               rcd.insert(p_l_lr_spd_data->lr_f0rc3_f0rc2[l_cur_mba_port][l_cur_mba_dimm],12,4,0);  //rcd3
               rcd.insert(p_l_lr_spd_data->lr_f0rc3_f0rc2[l_cur_mba_port][l_cur_mba_dimm],8,4,4);   //rcd2
   
               rcd.insert(p_l_lr_spd_data->lr_f0rc5_f0rc4[l_cur_mba_port][l_cur_mba_dimm],20,4,0);  //rcd5
               rcd.insert(p_l_lr_spd_data->lr_f0rc5_f0rc4[l_cur_mba_port][l_cur_mba_dimm],16,4,4);  //rcd4
   
               rcd.insert(p_l_lr_spd_data->lr_addr_mirroring[l_cur_mba_port][l_cur_mba_dimm],59,1,7); // address mirroring
   
               eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm]=rcd.getDoubleWord(0);
   
               ecmdDataBuffer rcd_1(64);
               rcd_1.flushTo0();
                    // F[1]RC11,8
               rcd_1.insert(p_l_lr_spd_data->lr_f1rc11_f1rc8[l_cur_mba_port][l_cur_mba_dimm],44,4,0);  //F[1]RC11 -> rcd11
               rcd_1.insert(p_l_lr_spd_data->lr_f1rc11_f1rc8[l_cur_mba_port][l_cur_mba_dimm],32,4,4);  //F[1]RC8  -> rcd8
   
                    // F[1]RC13,12
               rcd_1.insert(p_l_lr_spd_data->lr_f1rc13_f1rc12[l_cur_mba_port][l_cur_mba_dimm],52,4,0);  //F[1]RC13 -> rcd13
               rcd_1.insert(p_l_lr_spd_data->lr_f1rc13_f1rc12[l_cur_mba_port][l_cur_mba_dimm],48,4,4);  //F[1]RC12 -> rcd12
   
                    // F[1]RC15,14
               rcd_1.insert(p_l_lr_spd_data->lr_f1rc15_f1rc14[l_cur_mba_port][l_cur_mba_dimm],60,4,0);  //F[1]RC15 -> rcd15
               rcd_1.insert(p_l_lr_spd_data->lr_f1rc15_f1rc14[l_cur_mba_port][l_cur_mba_dimm],56,4,4);  //F[1]RC14 -> rcd14
   
   
               if ( mss_freq > 1733 ) {
                    rcd_1.insert(p_l_lr_spd_data->lr_f3rc9_f3rc8_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm],36,4,0);       // F[3]RC9 -> rcd9
                    rcd_1.insert(p_l_lr_spd_data->lr_f3rc9_f3rc8_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm],40,4,4);       // F[3]RC8 -> rcd10
                    rcd_1.insert(p_l_lr_spd_data->lr_f34rc11_f34rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm],4,4,0);    // F[3,4]RC11 -> rcd1
                    rcd_1.insert(p_l_lr_spd_data->lr_f34rc11_f34rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm],0,4,4);    // F[3,4]RC10 -> rcd0
                    rcd_1.insert(p_l_lr_spd_data->lr_f56rc11_f56rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm],12,4,0);   // F[6,6]RC11 -> rcd3
                    rcd_1.insert(p_l_lr_spd_data->lr_f56rc11_f56rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm],8,4,4);    // F[5,6]RC10 -> rcd2
                    rcd_1.insert(p_l_lr_spd_data->lr_f78rc11_f78rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm],20,4,0);   // F[7,8]RC11 -> rcd5
                    rcd_1.insert(p_l_lr_spd_data->lr_f78rc11_f78rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm],16,4,4);   // F[7,8]RC10 -> rcd4
                    rcd_1.insert(p_l_lr_spd_data->lr_f910rc11_f910rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm],28,4,0); // F[9,10]RC11 -> rcd7
                    rcd_1.insert(p_l_lr_spd_data->lr_f910rc11_f910rc10_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm],24,4,4); // F[9,10]RC10 -> rcd6
   
                    lrdimm_mr12_reg[l_cur_mba_port][l_cur_mba_dimm] = p_l_lr_spd_data->lr_mr12_for_1866_2133[l_cur_mba_port][l_cur_mba_dimm];
   
               } else if ( mss_freq > 1200 )  {
                    rcd_1.insert(p_l_lr_spd_data->lr_f3rc9_f3rc8_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm],36,4,0);       // F[3]RC9 -> rcd9
                    rcd_1.insert(p_l_lr_spd_data->lr_f3rc9_f3rc8_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm],40,4,4);       // F[3]RC8 -> rcd10
                    rcd_1.insert(p_l_lr_spd_data->lr_f34rc11_f34rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm],4,4,0);    // F[3,4]RC11 -> rcd1
                    rcd_1.insert(p_l_lr_spd_data->lr_f34rc11_f34rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm],0,4,4);    // F[3,4]RC10 -> rcd0
                    rcd_1.insert(p_l_lr_spd_data->lr_f56rc11_f56rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm],12,4,0);   // F[6,6]RC11 -> rcd3
                    rcd_1.insert(p_l_lr_spd_data->lr_f56rc11_f56rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm],8,4,4);    // F[5,6]RC10 -> rcd2
                    rcd_1.insert(p_l_lr_spd_data->lr_f78rc11_f78rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm],20,4,0);   // F[7,8]RC11 -> rcd5
                    rcd_1.insert(p_l_lr_spd_data->lr_f78rc11_f78rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm],16,4,4);   // F[7,8]RC10 -> rcd4
                    rcd_1.insert(p_l_lr_spd_data->lr_f910rc11_f910rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm],28,4,0); // F[9,10]RC11 -> rcd7
                    rcd_1.insert(p_l_lr_spd_data->lr_f910rc11_f910rc10_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm],24,4,4); // F[9,10]RC10 -> rcd6
   
                    lrdimm_mr12_reg[l_cur_mba_port][l_cur_mba_dimm] = p_l_lr_spd_data->lr_mr12_for_1333_1600[l_cur_mba_port][l_cur_mba_dimm];
   
               } else {
                    rcd_1.insert(p_l_lr_spd_data->lr_f3rc9_f3rc8_for_800_1066[l_cur_mba_port][l_cur_mba_dimm],36,4,0);       // F[3]RC9 -> rcd9
                    rcd_1.insert(p_l_lr_spd_data->lr_f3rc9_f3rc8_for_800_1066[l_cur_mba_port][l_cur_mba_dimm],40,4,4);       // F[3]RC8 -> rcd10
                    rcd_1.insert(p_l_lr_spd_data->lr_f34rc11_f34rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm],4,4,0);    // F[3,4]RC11 -> rcd1
                    rcd_1.insert(p_l_lr_spd_data->lr_f34rc11_f34rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm],0,4,4);    // F[3,4]RC10 -> rcd0
                    rcd_1.insert(p_l_lr_spd_data->lr_f56rc11_f56rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm],12,4,0);   // F[6,6]RC11 -> rcd3
                    rcd_1.insert(p_l_lr_spd_data->lr_f56rc11_f56rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm],8,4,4);    // F[5,6]RC10 -> rcd2
                    rcd_1.insert(p_l_lr_spd_data->lr_f78rc11_f78rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm],20,4,0);   // F[7,8]RC11 -> rcd5
                    rcd_1.insert(p_l_lr_spd_data->lr_f78rc11_f78rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm],16,4,4);   // F[7,8]RC10 -> rcd4
                    rcd_1.insert(p_l_lr_spd_data->lr_f910rc11_f910rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm],28,4,0); // F[9,10]RC11 -> rcd7
                    rcd_1.insert(p_l_lr_spd_data->lr_f910rc11_f910rc10_for_800_1066[l_cur_mba_port][l_cur_mba_dimm],24,4,4); // F[9,10]RC10 -> rcd6
   
                    lrdimm_mr12_reg[l_cur_mba_port][l_cur_mba_dimm] = p_l_lr_spd_data->lr_mr12_for_800_1066[l_cur_mba_port][l_cur_mba_dimm];
               }
   
               uint64_t rcd1 = rcd_1.getDoubleWord(0);
               lrdimm_additional_cntl_words[l_cur_mba_port][l_cur_mba_dimm] = rcd1;
   
               if ( eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 8 ) {
                  lrdimm_rank_mult_mode = 4; // Default for 8R is 4x mult mode
               }
   
                   // ========================================================================================
   
   
                                // FIX finding stack type properly.
               if ( eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 1 ) {
                  //p_o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_STACK_TYPE_NONE;
                  eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_5A;
               } else if ( eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 2 ) {
                  //p_o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_STACK_TYPE_NONE;
                  eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_5B;
               } else if ( eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 4 ) {
                  //p_o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_STACK_TYPE_DDP_QDP;
                  eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_5C;
               } else if ( eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 8 ) {
                  //p_o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_STACK_TYPE_DDP_QDP;
                  eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_5D;
               } else {
                  //p_o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_STACK_TYPE_NONE;
                  eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_UNDEFINED;
                  FAPI_ERR("Currently unsupported IBM_TYPE on %s!", i_target_mba.toEcmdString());
                  uint8_t IBM_TYPE = eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm];
                  const fapi::Target& TARGET = i_target_mba;
                  fapi::Target& DIMM = l_target_dimm_array[l_cur_mba_dimm];
                  FAPI_SET_HWP_ERROR(rc, RC_MSS_LRDIMM_UNSUPPORTED_TYPE);
                  return rc;
               }
            } // end valid dimm
         } // end dimm loop
      } // end port loop
   
      rc = FAPI_ATTR_SET(ATTR_EFF_IBM_TYPE, &i_target_mba,
              eff_ibm_type);
      rc = FAPI_ATTR_SET(ATTR_LRDIMM_MR12_REG, &i_target_mba,
              lrdimm_mr12_reg);
      rc = FAPI_ATTR_SET(ATTR_LRDIMM_ADDITIONAL_CNTL_WORDS, &i_target_mba,
              lrdimm_additional_cntl_words);
      rc = FAPI_ATTR_SET(ATTR_LRDIMM_RANK_MULT_MODE, &i_target_mba,
              lrdimm_rank_mult_mode);
      rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba,
              eff_dimm_rcd_cntl_word_0_15);
   
      if(rc)
      {
         FAPI_ERR("Error setting attributes");
         break;
      }
   } while(0);

   return rc;
}

fapi::ReturnCode mss_lrdimm_rewrite_odt(const fapi::Target& i_target_mba, uint32_t * p_b_var_array, uint32_t *var_array_p_array[5])
{
   ReturnCode rc;
   uint8_t l_num_ranks_per_dimm_u8array[PORT_SIZE][DIMM_SIZE];
//   uint8_t l_arr_offset;
   uint32_t l_mss_freq = 0;
   uint8_t l_dram_width_u8;
   
   //   uint32_t *odt_array;

   // For dual drop, Set ODT_RD as 2rank (8R LRDIMM) or 4rank (4R LRDIMM)
   fapi::Target l_target_centaur;
   rc = fapiGetParentChip(i_target_mba, l_target_centaur); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_mss_freq); if(rc) return rc;

   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm_u8array); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, l_dram_width_u8); if(rc) return rc;

//   uint8_t l_start=44, l_end=60;
// 8/4/2014 kahnevan - ifdefing this out to avoid 64 bit compiler warnings for unused odt_array variable.
// With the code at the bottom commented out, (comment from mdb) nothing was being done with the value.
#if 0
   if ( (l_num_ranks_per_dimm_u8array[0][1] == 4) || (l_num_ranks_per_dimm_u8array[1][1] == 4) ) {
     odt_array = var_array_p_array[0];
      FAPI_INF("Setting LRDIMM ODT_RD as 4 rank dimm");
   } else if ( (l_num_ranks_per_dimm_u8array[0][1] == 8) || (l_num_ranks_per_dimm_u8array[1][1] == 8) ) {
      if ( l_mss_freq <= 1466 ) { // 1333Mbps
         if ( l_dram_width_u8 == 4 ) {
	   odt_array = var_array_p_array[1];
         } else if ( l_dram_width_u8 == 8 ) {
            odt_array = var_array_p_array[2];
         }
      } else if ( l_mss_freq <= 1733 ) { // 1600 Mbps
         if ( l_dram_width_u8 == 4 ) {
	   odt_array = var_array_p_array[3];
         } else if ( l_dram_width_u8 == 8 ) {
	   odt_array = var_array_p_array[4];
         }
      }
      FAPI_INF("Setting LRDIMM ODT_RD as 2 logical rank dimm");
   }
#endif

// mdb - we do not have eff config attributes, so we can't set this array.  This function probably goes away
//   for ( l_arr_offset = l_start; l_arr_offset < l_end; l_arr_offset++ ) {
//      *(p_b_var_array + l_arr_offset) = *(odt_array + l_arr_offset);
//   }

   return rc;
}

fapi::ReturnCode mss_lrdimm_term_atts(const fapi::Target& i_target_mba)
{
   ReturnCode rc;

   uint8_t l_dram_ron[PORT_SIZE][DIMM_SIZE];
   uint8_t l_dram_rtt_wr[PORT_SIZE][DIMM_SIZE];
   uint8_t l_dram_rtt_nom[PORT_SIZE][DIMM_SIZE];

   uint8_t attr_eff_dram_ron[PORT_SIZE][DIMM_SIZE];
   uint8_t attr_eff_dram_rtt_nom[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
   uint8_t attr_eff_dram_rtt_wr[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
   uint8_t attr_eff_odt_wr[PORT_SIZE][DIMM_SIZE][RANK_SIZE];

   uint32_t l_mss_freq = 0;
   uint32_t l_mss_volt = 0;
   uint8_t l_num_ranks_per_dimm_u8array[PORT_SIZE][DIMM_SIZE];
   uint8_t l_num_drops_per_port;
   uint8_t l_dram_density;
   uint8_t l_dram_width_u8;
   
   uint8_t l_lrdimm_mr12_u8array[PORT_SIZE][DIMM_SIZE];
   uint8_t l_lrdimm_rank_mult_mode;

   uint8_t l_rcd_cntl_word_0_1;
   uint8_t l_rcd_cntl_word_6_7;
   uint8_t l_rcd_cntl_word_8_9;
   uint8_t l_rcd_cntl_word_10;
   uint8_t l_rcd_cntl_word_11;
   uint8_t l_rcd_cntl_word_12;
   uint8_t l_rcd_cntl_word_13;
   uint8_t l_rcd_cntl_word_14;
   uint8_t l_rcd_cntl_word_15;
   uint64_t l_rcd_cntl_word_0_15;
   uint64_t l_rcd_cntl_word_2_5_mask = 0x00FFFF0000000010LL;
   ecmdDataBufferBase data_buffer_64(64);
   ecmdDataBufferBase data_buffer_8(8);

   // Fetch impacted attributes
   uint64_t l_attr_eff_dimm_rcd_cntl_word_0_15[PORT_SIZE][DIMM_SIZE];
   rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RON, &i_target_mba, attr_eff_dram_ron); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_NOM, &i_target_mba, attr_eff_dram_rtt_nom); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_WR, &i_target_mba, attr_eff_dram_rtt_wr); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_VPD_ODT_WR, &i_target_mba, attr_eff_odt_wr); if(rc) return rc;

   // Fetch impacted attributes
   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target_mba, l_num_drops_per_port); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, l_dram_width_u8); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm_u8array); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_DENSITY, &i_target_mba, l_dram_density); if(rc) return rc;

   fapi::Target l_target_centaur;
   rc = fapiGetParentChip(i_target_mba, l_target_centaur); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_mss_freq); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_mss_volt); if(rc) return rc;

   // Fetch SPD MR1,2
   rc = FAPI_ATTR_GET(ATTR_LRDIMM_MR12_REG, &i_target_mba, l_lrdimm_mr12_u8array); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_LRDIMM_RANK_MULT_MODE, &i_target_mba, l_lrdimm_rank_mult_mode); if(rc) return rc;

   for (uint8_t l_port = 0; l_port < PORT_SIZE; l_port++) {
      for (uint8_t l_dimm = 0; l_dimm < DIMM_SIZE; l_dimm++) {

         // Set RCD control word
         FAPI_INF("before setting: rcd control word 0-15 %.16llX", l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] );
         l_rcd_cntl_word_0_1   = 0x00; // Global features,  Clock driver enable
         FAPI_INF("rcd control word 0-1 %X", l_rcd_cntl_word_0_1 );

         // RCD cntl words 2-5 from SPD

         l_rcd_cntl_word_6_7   = 0x00; // CKE & ODT management, Function select
         FAPI_INF("rcd control word 6-7 %X", l_rcd_cntl_word_6_7 );

         if ( l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL ) {
            l_rcd_cntl_word_8_9   = 0x20; // IBT=200 Ohm & Vref settings for address, command, par_in, Power saving settings
         }
         else {
            l_rcd_cntl_word_8_9   = 0x00; // IBT=100 Ohm & Vref settings for address, command, par_in, Power saving settings
         }
         FAPI_INF("rcd control word 8-9 %X", l_rcd_cntl_word_8_9 );


        const fapi::Target& TARGET = i_target_mba;
         // RC10 LRDIMM operating speed
         if ( l_mss_freq <= 933 ) {         // 800Mbps
            l_rcd_cntl_word_10 = 0;
         } else if ( l_mss_freq <= 1200 ) { // 1066Mbps
            l_rcd_cntl_word_10 = 1;
         } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
            l_rcd_cntl_word_10 = 2;
         } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
            l_rcd_cntl_word_10 = 3;
         } else if ( l_mss_freq <= 2000 ) { // 1866Mbps
            l_rcd_cntl_word_10 = 4;
         } else {
            FAPI_ERR("Invalid LRDIMM ATTR_MSS_FREQ = %d on %s!", l_mss_freq, i_target_mba.toEcmdString());
            uint32_t& L_MSS_FREQ = l_mss_freq;
            FAPI_SET_HWP_ERROR(rc, RC_MSS_LRDIMM_INVALID_MSS_FREQ); return rc;
         }
         FAPI_INF("rcd control word 10 %X", l_rcd_cntl_word_10 );

         // RC11 Operating voltage & parity calculation (buffer does not include A17:16)
         if ( l_mss_volt >= 1420 ) {        // 1.5V
            l_rcd_cntl_word_11 = 4;
         } else if ( l_mss_volt >= 1270 ) { // 1.35V
            l_rcd_cntl_word_11 = 5;
         } else if ( l_mss_volt >= 1170 ) { // 1.25V
            l_rcd_cntl_word_11 = 6;
         } else {
            FAPI_ERR("Invalid LRDIMM ATTR_MSS_VOLT = %d on %s!", l_mss_volt, i_target_mba.toEcmdString());
            uint32_t& L_MSS_VOLT = l_mss_volt;
            FAPI_SET_HWP_ERROR(rc, RC_MSS_LRDIMM_INVALID_MSS_VOLT); return rc;
         }
         FAPI_INF("rcd control word 11 %X", l_rcd_cntl_word_11 );

         l_rcd_cntl_word_12 = 0; //Training
         FAPI_INF("rcd control word 12 %X", l_rcd_cntl_word_12 );

         // rC13 DIMM configuration
         if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 8 ) {
            l_rcd_cntl_word_13 = 4;       // 8 physical ranks, 2 logical ranks, RM=4
         } else if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 4 ) {
            l_rcd_cntl_word_13 = 9;       // 4 physical ranks, 4 logical ranks, direct rank mapping
      //   } else if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 2 ) {
      //      l_rcd_cntl_word_13 = 6;       // 2 physical ranks, 2 logical ranks, direct rank mapping
      //   } else if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 1 ) {
      //      l_rcd_cntl_word_13 = 3;       // 1 physical rank, 1 logical rank, direct rank mapping
         } else {
            l_rcd_cntl_word_13 = 0;
         }
         FAPI_INF("rcd control word 13 %X", l_rcd_cntl_word_13 );

         // RC14 DRAM configuration & DRAM command
         if ( l_lrdimm_rank_mult_mode != 0 ) {
            data_buffer_8.setBit(2);         // turn off refresh broadcast
         }
         if ( l_dram_width_u8 == 8 )  {
            data_buffer_8.setBit(0);
         }
         data_buffer_8.extractToRight( &l_rcd_cntl_word_14, 0, 4);
         FAPI_INF("rcd control word 14 %X", l_rcd_cntl_word_14 );
         uint8_t& L_LRDIMM_RANK_MULT_MODE=l_lrdimm_rank_mult_mode;
         uint8_t& L_DRAM_DENSITY=l_dram_density;

         // RC15 Rank multiplication
         if ( l_lrdimm_rank_mult_mode == 4 ) {
            if ( l_dram_density == 1 ) {
               l_rcd_cntl_word_15 = 5;    // A[15:14]; 4x multiplication, 1 Gbit DDR3 SDRAM
            } else if ( l_dram_density == 2 ) {
               l_rcd_cntl_word_15 = 6;    // A[16:15]; 4x multiplication, 2 Gbit DDR3 SDRAM               
            } else if ( l_dram_density == 4 ) {
               l_rcd_cntl_word_15 = 7;    // A[17:16]; 4x multiplication, 4 Gbit DDR3 SDRAM
            } else {
               FAPI_ERR("Invalid LRDIMM Rank mult mode =%d, ATTR_EFF_DRAM_DENSITY = %d on %s!", l_lrdimm_rank_mult_mode, l_dram_density, i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_LRDIMM_INVALID_RANK_MULT_MODE); return rc;
            }
         } else if ( l_lrdimm_rank_mult_mode == 2 ) {
            if ( l_dram_density == 1 ) {
               l_rcd_cntl_word_15 = 1;    // A[14]; 2x multiplication, 1 Gbit DDR3 SDRAM
            } else if ( l_dram_density == 2 ) {
               l_rcd_cntl_word_15 = 2;    // A[15]; 2x multiplication, 2 Gbit DDR3 SDRAM
            } else if ( l_dram_density == 4 ) {
               l_rcd_cntl_word_15 = 3;    // A[16]; 2x multiplication, 4 Gbit DDR3 SDRAM
            } else {
               FAPI_ERR("Invalid LRDIMM Rank Mult mode = %d,  ATTR_EFF_DRAM_DENSITY = %d on %s!", l_lrdimm_rank_mult_mode, l_dram_density, i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_LRDIMM_INVALID_DRAM_DENSITY_MULT_2); return rc;
            }
         } else {
            l_rcd_cntl_word_15 = 0;
         }
         FAPI_INF("rcd control word 15 %X", l_rcd_cntl_word_15 );

         data_buffer_64.insertFromRight(&l_rcd_cntl_word_0_1, 0, 8);
         data_buffer_64.clearBit( 8, 16);
         data_buffer_64.insertFromRight(&l_rcd_cntl_word_6_7, 24, 8);
         data_buffer_64.insertFromRight(&l_rcd_cntl_word_8_9, 32, 8);
         data_buffer_64.insertFromRight(&l_rcd_cntl_word_10,  40, 4);
         data_buffer_64.insertFromRight(&l_rcd_cntl_word_11,  44, 4);
         data_buffer_64.insertFromRight(&l_rcd_cntl_word_12,  48, 4);
         data_buffer_64.insertFromRight(&l_rcd_cntl_word_13,  52, 4);
         data_buffer_64.insertFromRight(&l_rcd_cntl_word_14,  56, 4);
         data_buffer_64.insertFromRight(&l_rcd_cntl_word_15,  60, 4);
         l_rcd_cntl_word_0_15 = data_buffer_64.getDoubleWord(0); if(rc) return rc;
         FAPI_INF("from data buffer: rcd control word 0-15 %llX", l_rcd_cntl_word_0_15 );
         l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] & l_rcd_cntl_word_2_5_mask;
         l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] | l_rcd_cntl_word_0_15;

         FAPI_INF("after mask: rcd control word 0-15 %.16llX", l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] );

        // Setup LRDIMM drive impedance, rtt nom, rtt wr, odt wr
         l_dram_ron[l_port][l_dimm] = l_lrdimm_mr12_u8array[l_port][l_dimm] & 0x03; // Pulled from SPD LR MR1,2 DRAM DriverImpedance [1:0]
         l_dram_rtt_nom[l_port][l_dimm] = (l_lrdimm_mr12_u8array[l_port][l_dimm] & 0x1C) >> 2; // Pulled from SPD LR MR1,2 DRAM RTT_nom for ranks 0/1 [4:2]
         l_dram_rtt_wr[l_port][l_dimm]  = (l_lrdimm_mr12_u8array[l_port][l_dimm] & 0xC0) >> 6; // Pulled from SPD LR MR1,2 DRAM RTT_WR [7:6]

         if ( l_dram_ron[l_port][l_dimm] == 0 ) {
            l_dram_ron[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RON_OHM40;
         } else if ( l_dram_ron[l_port][l_dimm] == 1 ) {
            l_dram_ron[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34;
         } else {
            uint8_t& L_DRAM_RON = l_dram_ron[l_port][l_dimm];
            FAPI_ERR("Invalid SPD LR MR1,2 DRAM drv imp on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_LRDIMM_INVALID_SPD_DRV_IMP); return rc;
         }

         attr_eff_dram_ron[l_port][l_dimm] = l_dram_ron[l_port][l_dimm];
         FAPI_INF("Set LRDIMM DRAM_RON to SPD LR MR1,2 DRAM drv imp");

         switch (l_dram_rtt_nom[l_port][l_dimm]) {
            case 0 : l_dram_rtt_nom[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE;
                break;
            case 1 : l_dram_rtt_nom[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60;
                break;
            case 2 : l_dram_rtt_nom[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM120;
                break;
            case 3 : l_dram_rtt_nom[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40;
                break;
            case 4 : l_dram_rtt_nom[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20;
                break;
            case 5 : l_dram_rtt_nom[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30;
                break;
            default: FAPI_ERR("Invalid SPD LR MR1,2 DRAM RTT_NOM on %s!", i_target_mba.toEcmdString());
                uint8_t& L_DRAM_RTT_NOM = l_dram_rtt_nom[l_port][l_dimm];
                FAPI_SET_HWP_ERROR(rc, RC_MSS_LRDIMM_INVALID_SPD_RTT_NOM);
                return rc;
         }

         switch (l_dram_rtt_wr[l_port][l_dimm]) {
            case 0 : l_dram_rtt_wr[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE;
                break;
            case 1 : l_dram_rtt_wr[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60;
                break;
            case 2 : l_dram_rtt_wr[l_port][l_dimm] = fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120;
                break;
            default: FAPI_ERR("Invalid SPD LR MR1,2 DRAM RTT_WR on %s!", i_target_mba.toEcmdString());
                uint8_t& L_DRAM_RTT_WR = l_dram_rtt_wr[l_port][l_dimm];
                FAPI_SET_HWP_ERROR(rc, RC_MSS_LRDIMM_INVALID_SPD_RTT_WR);
                return rc;
         }

         uint8_t l_rank;
         for ( l_rank = 0; l_rank < RANK_SIZE; l_rank++ ) {           // clear RTT_NOM & RTT_WR
            attr_eff_dram_rtt_nom[l_port][l_dimm][l_rank] = fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE;
            attr_eff_dram_rtt_wr[l_port][l_dimm][l_rank] = fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE;
         }

         if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] > 0 ) { // Set RTT_NOM Rank 0 for multi rank LRDIMM
            attr_eff_dram_rtt_nom[l_port][l_dimm][0] = l_dram_rtt_nom[l_port][l_dimm]; // set attr_eff_dram_rtt_nom[0][0][0]
            attr_eff_dram_rtt_wr[l_port][l_dimm][0] = l_dram_rtt_wr[l_port][l_dimm]; // set attr_eff_dram_rtt_wr[0][0][0]

            FAPI_INF("Setting Port0 Rank 0 LRDIMM RTT_NOM & RTT_WR from SPD LR MR1,2");

            if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] > 1 ) { // Set RTT_NOM Rank 1 for 4rank or 8rank LRDIMM
               attr_eff_dram_rtt_nom[l_port][l_dimm][1] = l_dram_rtt_nom[l_port][l_dimm]; // set attr_eff_dram_rtt_nom[0][0][1]
               attr_eff_dram_rtt_wr[l_port][l_dimm][1] = l_dram_rtt_wr[l_port][l_dimm]; // set attr_eff_dram_rtt_wr[0][0][1]

               attr_eff_dram_rtt_wr[l_port][l_dimm][2] = l_dram_rtt_wr[l_port][l_dimm]; // set attr_eff_dram_rtt_wr[0][0][2]
               attr_eff_dram_rtt_wr[l_port][l_dimm][3] = l_dram_rtt_wr[l_port][l_dimm]; // set attr_eff_dram_rtt_wr[0][0][3]
               FAPI_INF("Setting Port0 Rank 1+ LRDIMM RTT_NOM & RTT_WR from SPD LR MR1,2");
            }
         }

//-------------------------------------------------------------------------------------------------------------

         // Set ODT_WR for each valid rank as single RDIMM rank value.
         if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] > 1 ) { // SET ODT_WR Rank 1 for multi rank LRDIMM (8R or 4R)
            attr_eff_odt_wr[l_port][l_dimm][1] = attr_eff_odt_wr[l_port][l_dimm][0]; // set attr_eff_odt_wr[0][0][1] to attr_eff_odt_wr[0][0][0]
            if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 4 ) { // Set ODT_WR Rankd 2,3 for 4 rank LRDIMM
               attr_eff_odt_wr[l_port][l_dimm][2] = attr_eff_odt_wr[l_port][l_dimm][0]; // set attr_eff_odt_wr[0][0][2] to attr_eff_odt_wr[0][0][0]
               attr_eff_odt_wr[l_port][l_dimm][3] = attr_eff_odt_wr[l_port][l_dimm][0]; // set attr_eff_odt_wr[0][0][3] to attr_eff_odt_wr[0][0][0]
            }
         }

      } // end dimm loop
   } // end port loop

   // Set adjusted attributes
   rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_RON, &i_target_mba, attr_eff_dram_ron); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_RTT_NOM, &i_target_mba, attr_eff_dram_rtt_nom); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_RTT_WR, &i_target_mba, attr_eff_dram_rtt_wr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_VPD_ODT_WR, &i_target_mba, attr_eff_odt_wr); if(rc) return rc;

   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;

   return rc;
}

fapi::ReturnCode mss_spec_rcd_load( fapi::Target& i_target,  uint32_t i_port_number, uint8_t  *p_i_rcd_num_arr, uint8_t i_rcd_num_arr_length, uint64_t  i_rcd_word[], uint32_t& io_ccs_inst_cnt,uint8_t i_keep_cke_high)
{
    const uint8_t MAX_NUM_PORTS=2;
    const uint8_t MAX_NUM_DIMMS=2;
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint32_t dimm_number;
    uint8_t spec_rcd;

    ecmdDataBufferBase rcd_cntl_wrd_4(8);
    ecmdDataBufferBase rcd_cntl_wrd_64(64);
    uint16_t num_ranks;

    uint16_t num_idles_delay = 20; // default=12 klc

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
    if (i_keep_cke_high == 1)
        rc_num = rc_num | cke_4.setBit(0,4);
    else
        rc_num = rc_num | cke_4.clearBit(0,4);
    ecmdDataBufferBase csn_8(8);
    rc_num = rc_num | csn_8.setBit(0,8);
    ecmdDataBufferBase odt_4(4);
    rc_num = rc_num | odt_4.setBit(0,4);
    ecmdDataBufferBase ddr_cal_type_4(4);

    ecmdDataBufferBase num_idles_16(16);
    ecmdDataBufferBase num_repeat_16(16);
    ecmdDataBufferBase data_20(20);
    ecmdDataBufferBase read_compare_1(1);
    ecmdDataBufferBase rank_cal_4(4);
    ecmdDataBufferBase ddr_cal_enable_1(1);
    ecmdDataBufferBase ccs_end_1(1);

    uint8_t num_ranks_array[MAX_NUM_PORTS][MAX_NUM_DIMMS]; //[port][dimm]

    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;

    FAPI_INF( "+++++++++++++++++++++ LOADING RCD CONTROL WORD FOR PORT %d +++++++++++++++++++++", i_port_number);

    for ( dimm_number = 0; dimm_number < MAX_NUM_DIMMS; dimm_number++)
    {
        num_ranks = num_ranks_array[i_port_number][dimm_number];

        if (num_ranks == 0)
        {
            FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d", i_port_number, dimm_number, num_ranks);
        }
        else
        {
            FAPI_INF( "RCD SETTINGS FOR PORT%d DIMM%d ", i_port_number, dimm_number);
            FAPI_INF( "RCD Control Word: 0x%016llX", i_rcd_word[dimm_number]);
            FAPI_INF( "Loading function specific RCD Control Words");

            if (rc_num)
            {
                FAPI_ERR( "mss_spec_rcd_load: Error setting up buffers");
                rc_buff.setEcmdError(rc_num);
                return rc_buff;
            }

            rc_num = rc_num | csn_8.setBit(0,8);        // reset CS lines
            // for dimm0 use CS0,1 (active low); for dimm1 use CS4,5 (active low)
            rc_num = rc_num | csn_8.clearBit( (dimm_number * 4), 2 );
            // set specific control words
            for ( spec_rcd = 0; spec_rcd < i_rcd_num_arr_length; spec_rcd++ )
            {
               rc_num = rc_num | bank_3.clearBit(0, 3);
               rc_num = rc_num | address_16.clearBit(0, 16);

               rc_num = rc_num | rcd_cntl_wrd_64.setDoubleWord(0, i_rcd_word[dimm_number]);
               rc_num = rc_num | rcd_cntl_wrd_64.extract(rcd_cntl_wrd_4, 4*p_i_rcd_num_arr[spec_rcd], 4);

               //control word number code bits A0, A1, A2, BA2
               rc_num = rc_num | bank_3.insert(p_i_rcd_num_arr[spec_rcd], 2, 1, 4);  // BA2(MSB) from array bit 4
               rc_num = rc_num | address_16.insert(p_i_rcd_num_arr[spec_rcd], 2, 1, 5);  // A2
               rc_num = rc_num | address_16.insert(p_i_rcd_num_arr[spec_rcd], 1, 1, 6);  // A1
               rc_num = rc_num | address_16.insert(p_i_rcd_num_arr[spec_rcd], 0, 1, 7);  // A0

               //control word values RCD0 = A3, RCD1 = A4, RCD2 = BA0, RCD3 = BA1
               rc_num = rc_num | bank_3.insert(rcd_cntl_wrd_4, 1, 1, 0);                        // BA1 (MSB)
               rc_num = rc_num | bank_3.insert(rcd_cntl_wrd_4, 0, 1, 1);                        // BA0
               rc_num = rc_num | address_16.insert(rcd_cntl_wrd_4, 4, 1, 2);            // A4
               rc_num = rc_num | address_16.insert(rcd_cntl_wrd_4, 3, 1, 3);            // A3

               FAPI_INF("Loading RCD %d (0x%02x) = 0x%01X",  p_i_rcd_num_arr[spec_rcd],
                                           p_i_rcd_num_arr[spec_rcd],
                                           (rcd_cntl_wrd_4.getByte(0)>>4));

               // Send out to the CCS array
               rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) num_idles_delay, 0, 16);
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
           } //end control word loop
        } // end valid rank
    } // end dimm loop
    return rc;
}

#endif
