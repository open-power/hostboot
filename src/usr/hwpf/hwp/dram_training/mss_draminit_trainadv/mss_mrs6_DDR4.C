/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_mrs6_DDR4.C $ */
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
// $Id: mss_mrs6_DDR4.C,v 1.7 2015/10/23 15:12:05 sglancy Exp $


//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! ***  ***


//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.06   |10-23-15  |sglancy | Fixed attribute names
//  1.05   | 09/03/15 | kmack   | RC updates
//  1.04   | 08/05/15 | sglancy | Fixed FW compile error
//  1.03   | 08/04/15 | sglancy | Changed to address FW comments
//  1.02   | 05/07/15 | sglancy | Fixed enable disable bug and added 3DS support
//  1.00   | 06/27/14 | abhijsau | Initial Draft

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <fapi.H>
#include <mss_funcs.H>
#include <cen_scom_addresses.H>
#include <mss_mrs6_DDR4.H>
using namespace fapi;

extern "C"
{

// loads and runs MRS6 commands on a given MBA
ReturnCode mss_mrs6_DDR4( fapi::Target& i_target)
{
ReturnCode rc;
uint32_t port_number;
uint32_t ccs_inst_cnt=0;

for ( port_number = 0; port_number < 2; port_number++)
        {
            // Step four: Load MRS Setting
            FAPI_INF("Loading MRS6 for port %d",port_number);
            rc = mss_mr6_loader(i_target, port_number, ccs_inst_cnt);
            if(rc)
            {
                FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                return rc;
            }

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
        }

          return rc;

}

//Adds a NOP to CCS
fapi::ReturnCode add_nop_to_ccs(fapi::Target& i_target_mba, ecmdDataBufferBase &addr_16, uint32_t instruction_number,uint8_t rank,uint8_t bank,uint32_t delay,uint8_t port) {
   fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
   fapi::ReturnCode l_rc_buff = fapi::FAPI_RC_SUCCESS;
   uint32_t l_ecmd_rc = 0;

   //CCS Array 0 buffers
   ecmdDataBufferBase bank_3(3);
   ecmdDataBufferBase ddr4_activate_1(1);
   ecmdDataBufferBase rasn_1(1);
   ecmdDataBufferBase casn_1(1);
   ecmdDataBufferBase wen_1(1);
   ecmdDataBufferBase cke_4(4);
   ecmdDataBufferBase csn_8(8);
   ecmdDataBufferBase odt_4(4);
   ecmdDataBufferBase cal_type_4(4);

   //CCS Array 1 buffers
   ecmdDataBufferBase idles_16(16);
   ecmdDataBufferBase repeat_16(16);
   ecmdDataBufferBase pattern_20(20);
   ecmdDataBufferBase read_compare_1(1);
   ecmdDataBufferBase rank_cal_4(4);
   ecmdDataBufferBase cal_enable_1(1);
   ecmdDataBufferBase ccs_end_1(1);
   FAPI_INF("\n Running NO -OP command");

   //CCS Array 0 Setup

   //Buffer conversions from inputs
   l_ecmd_rc |= addr_16.reverse();
   l_ecmd_rc |= bank_3.insertFromRight(bank, 0, 3);
   l_ecmd_rc |= bank_3.reverse();  //Banks are 0:2
   l_ecmd_rc |= csn_8.flushTo1();
   l_ecmd_rc |= csn_8.clearBit(rank);

   //Command structure setup
   l_ecmd_rc |= cke_4.flushTo1();
   l_ecmd_rc |= rasn_1.setBit(0);
   l_ecmd_rc |= casn_1.setBit(0);
   l_ecmd_rc |= wen_1.setBit(0);

   l_ecmd_rc |= read_compare_1.clearBit(0);

   //Final setup
   l_ecmd_rc |= odt_4.flushTo0();
   l_ecmd_rc |= cal_type_4.flushTo0();
   l_ecmd_rc |= ddr4_activate_1.setBit(0);

   if (l_ecmd_rc) {
      FAPI_ERR( "add_activate_to_ccs: Error setting up buffers");
      l_rc_buff.setEcmdError(l_ecmd_rc);
      return l_rc_buff;
   }

   l_rc = mss_ccs_inst_arry_0(i_target_mba, instruction_number, addr_16, bank_3, ddr4_activate_1, rasn_1, casn_1, wen_1, cke_4, csn_8, odt_4, cal_type_4, port);
   if (l_rc) return l_rc;


   //CCS Array 1 Setup
   l_ecmd_rc |= idles_16.insertFromRight(delay, 0, 16);
   l_ecmd_rc |= repeat_16.flushTo0();
   l_ecmd_rc |= pattern_20.flushTo0();
   l_ecmd_rc |= read_compare_1.flushTo0();
   l_ecmd_rc |= rank_cal_4.flushTo0();
   l_ecmd_rc |= cal_enable_1.flushTo0();
   l_ecmd_rc |= ccs_end_1.flushTo0();

   if (l_ecmd_rc) {
      FAPI_ERR( "add_activate_to_ccs: Error setting up buffers");
      l_rc_buff.setEcmdError(l_ecmd_rc);
      return l_rc_buff;
   }

   l_rc = mss_ccs_inst_arry_1(i_target_mba, instruction_number, idles_16, repeat_16, pattern_20, read_compare_1, rank_cal_4, cal_enable_1, ccs_end_1);
   if (l_rc) return l_rc;

   return l_rc;
}

//Loads MRS6 commands for a given port into the CCS array
ReturnCode mss_mr6_loader( fapi::Target& i_target,uint32_t i_port_number,uint32_t& io_ccs_inst_cnt)
{

    const uint8_t MRS6_BA = 6;
    uint32_t dimm_number;
    uint32_t rank_number;
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
        uint8_t tmod_delay = 12;
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

    uint32_t instruction_number;
    ecmdDataBufferBase num_idles_16(16);
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

    uint16_t MRS6 = 0;

    ecmdDataBufferBase data_buffer(64);
    instruction_number = 0;

    uint16_t num_ranks = 0;

    FAPI_INF( "+++++++++++++++++++++ LOADING MRS SETTINGS FOR PORT %d +++++++++++++++++++++", i_port_number);

    uint8_t num_ranks_array[2][2]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;

    uint8_t dimm_type;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;

    uint8_t is_sim = 0;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
    if(rc) return rc;

    uint8_t address_mirror_map[2][2]; //address_mirror_map[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_ADDRESS_MIRRORING, &i_target, address_mirror_map);
    if(rc) return rc;


    // WORKAROUNDS
    rc = fapiGetScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.setBit(51);
    if (rc_num)
    {
        FAPI_ERR( "mss_mr6_loader: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }
    rc = fapiPutScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, data_buffer);
    if(rc) return rc;

        if(i_port_number==0){
    rc = fapiGetScom(i_target,DPHY01_DDRPHY_WC_CONFIG3_P0_0x8000CC050301143F, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.clearBit(48);
    if (rc_num)
    {
        FAPI_ERR( "mss_mr6_loader: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }
    rc = fapiPutScom(i_target,DPHY01_DDRPHY_WC_CONFIG3_P0_0x8000CC050301143F, data_buffer);
    if(rc) return rc;
        }
        else{

        rc = fapiGetScom(i_target,DPHY01_DDRPHY_WC_CONFIG3_P1_0x8001CC050301143F, data_buffer);
    if(rc) return rc;
    //Setting up CCS mode
    rc_num = rc_num | data_buffer.clearBit(48);
    if (rc_num)
    {
        FAPI_ERR( "mss_mr6_loader: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }
    rc = fapiPutScom(i_target,DPHY01_DDRPHY_WC_CONFIG3_P1_0x8001CC050301143F, data_buffer);
    if(rc) return rc;
        }

    //Lines commented out in the following section are waiting for xml attribute adds

    uint8_t dram_stack[2][2];
    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target, dram_stack);
    if(rc) return rc;

    FAPI_INF( "Stack Type: %d\n", dram_stack[0][0]);


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

    FAPI_INF("enable attribute %d",vrefdq_train_enable[0][0][0]);



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

    if (rc_num)
    {
        FAPI_ERR( "mss_mr6_loader: Error setting up buffers");
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

    // Dimm 0-1
    for ( dimm_number = 0; dimm_number < 2; dimm_number++)
    {
        num_ranks = num_ranks_array[i_port_number][dimm_number];

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
                        vrefdq_train_enable[i_port_number][dimm_number][rank_number] = 0xff;FAPI_INF("ENABLE is enabled");
                    }
                    else if (vrefdq_train_enable[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE)
                    {
                        vrefdq_train_enable[i_port_number][dimm_number][rank_number] = 0x00;FAPI_INF("DISABLE is enabled");
                    }

                    rc_num = rc_num | mrs6.insert((uint8_t) vrefdq_train_value[i_port_number][dimm_number][rank_number], 0, 6);
                    rc_num = rc_num | mrs6.insert((uint8_t) vrefdq_train_range[i_port_number][dimm_number][rank_number], 6, 1);
                    rc_num = rc_num | mrs6.insertFromRight((uint8_t) vrefdq_train_enable[i_port_number][dimm_number][rank_number], 7, 1);

                    rc_num = rc_num | mrs6.insert((uint8_t) 0x00, 8, 2);
                    rc_num = rc_num | mrs6.insert((uint8_t) tccd_l, 10, 3);
                    rc_num = rc_num | mrs6.insert((uint8_t) 0x00, 13, 2);

                    rc_num = rc_num | mrs6.extractPreserve(&MRS6, 0, 16, 0);

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

                    if (dram_stack[0][0] == ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS)
                    {
                       FAPI_INF( "=============  Got in the 3DS stack loop CKE !!!!=====================\n");
                       rc_num = rc_num | csn_8.clearBit(2+4*dimm_number,2);
                       // I'm leaving this commented out - I need to double check it with Luke Mulkey to see which CS's are wired to which CKE's
                       // rc_num = rc_num | cke_4.clearBit(1);
                    }

                    // Propogate through the 4 MRS cmds
                        // Copying the current MRS into address buffer matching the MRS_array order
                        // Setting the bank address
                            rc_num = rc_num | address_16.insert(mrs6, 0, 16, 0);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6);
                            rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5);

                        if (rc_num)
                        {
                            FAPI_ERR( "mss_mrs_load: Error setting up buffers");
                            rc_buff.setEcmdError(rc_num);
                            return rc_buff;
                        }

                        if (( address_mirror_map[i_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
                        {
                            rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm_number, rank_number, address_16, bank_3);
                                if(rc) return rc;
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

                                                    // Address inversion for RCD
                    if ( (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || (dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_RDIMM || dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) )
                    {
                       FAPI_INF( "Sending out MRS with Address Inversion to B-side DRAMs\n");


                       // Propogate through the 4 MRS cmds
                           // Copying the current MRS into address buffer matching the MRS_array order
                           // Setting the bank address
                               rc_num = rc_num | address_16.insert(mrs6, 0, 16, 0);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6);
                               rc_num = rc_num | bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5);

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

                           if (( address_mirror_map[i_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
                           {
                               rc = mss_address_mirror_swizzle(i_target, i_port_number, dimm_number, rank_number, address_16, bank_3);
                               if(rc) return rc;
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
instruction_number = io_ccs_inst_cnt;

rc = add_nop_to_ccs (i_target, address_16,instruction_number,rank_number,MRS6_BA,tmod_delay,i_port_number);
io_ccs_inst_cnt = instruction_number;
io_ccs_inst_cnt++;
if (rc) return rc;

            }
        }
    }





    return rc;
}





}































