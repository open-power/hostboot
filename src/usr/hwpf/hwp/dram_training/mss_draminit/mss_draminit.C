//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/dram_training/mss_draminit/mss_draminit.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.22   | jdsloat  | 2/27/12 | Fixed hostboot parenthesis error
//  1.21   | jdsloat  | 2/27/12 | Cycle through Ports local of MRS/RCD, CL shift fix, Initialization of address/CS, neg end bit bug fix
//  1.20   | jdsloat  | 2/23/12 | Fixed CL typo in MRS load
//  1.19   | jdsloat  | 2/23/12 | MRS per rank, Interpret MRS ENUM correctly, CSN initialized to 0xFF
//  1.18   | jdsloat  | 2/16/12 | Initialize rc_num, add num_ranks ==1 to MRS, Fix BA position in MRS
//  1.17   | jdsloat  | 2/14/12 | MBA target translation, if statement clarification, style fixes
//  1.16   | jdsloat  | 2/08/12 | Target to Target&, Described target with comment
//  1.15   | jdsloat  | 2/02/12 | Fixed attributes array sizes, added debug messagesTarget to Target&, Described target
//  1.14   | jdsloat  | 1/19/12 | Tabs to 4 spaces - properly
//  1.13   | jdsloat  | 1/16/12 | Tabs to 4 spaces
//  1.12   | jdsloat  | 1/13/12 | Curly Brackets, capitalization, "mss_" prefix, argument prefixes, no include C's, RC checks
//  1.11   | jdsloat  | 1/5/12  | Changed Attribute grab, cleaned up includes section, Got rid of Globals
//  1.10   | jdsloat  | 12/08/11| Changed MRS load  RAS, CAS, WEN
//  1.9    | jdsloat  | 12/07/11| CSN for 2 rank dimms 0x3 to 0xC
//  1.8    | jdsloat  | 11/08/11| Cycling through Ports - fix
//  1.7    | jdsloat  | 10/31/11| CCS Update - goto_inst now assumed to be +1, CCS_fail fix, CCS_status fix
//  1.6    | jdsloat  | 10/18/11| RCD execution fix, debug messages
//  1.5    | jdsloat  | 10/13/11| MRS fix, CCS count fix, get attribute fix, ecmdbuffer lengths within name
//  1.4    | jdsloat  | 10/11/11| Fix CS Lines, dataBuffer.insert functions, ASSERT_RESETN_DRIVE_MEM_CLKS fix, attribute names
//  1.3    | jdsloat  | 10/05/11| Convert integers to ecmdDataBufferBase in CCS_INST_1, CCS_INST_2, CCS_MODE
//  1.2    | jdsloat  |04-OCT-11| Changing cen_funcs.C, cen_funcs.H to mss_funcs.C, mss_funcs.H
//  1.1    | jdsloat  |04-OCT-11| First drop
//---------|----------|---------|-----------------------------------------------
//  1.6    | jdsloat  |29-Sep-11|Functional Changes: port flow, CCS changes, only configed CS, etc.  Compiles.
//  1.5    | jdsloat  |22-Sep-11|Converted to FAPI, functional changes to match documentation
//  1.3    | jdsloat  |14-Jul-11|Change GP4 register address from 1013 to 0x1013
//  1.2    | jdsloat  |22-Apr-11|Moved CCS operations to Cen_funcs.C, draminit_training to cen_draminit_training.C
//  1.1    | jdsloat  |31-Mar-11|First drop for centaur

//----------------------------------------------------------------------
//  FAPI function Includes
//----------------------------------------------------------------------

#include <fapi.H>

//----------------------------------------------------------------------
//  Centaur function Includes
//----------------------------------------------------------------------
#include <mss_funcs.H>


//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
const uint8_t MAX_NUM_RANKS = 4;
const uint8_t MAX_NUM_DIMMS = 2;
const uint8_t MAX_NUM_PORTS = 2; 
const uint8_t MRS0_BA = 0;
const uint8_t MRS1_BA = 1;
const uint8_t MRS2_BA = 2;
const uint8_t MRS3_BA = 3;
const uint16_t GP4_REG_0x1013 = 0x1013;


extern "C" {

using namespace fapi;

ReturnCode mss_rcd_load( Target& i_target, uint32_t i_port_number, uint32_t& io_ccs_inst_cnt);
ReturnCode mss_mrs_load( Target& i_target, uint32_t i_port_number, uint32_t& io_ccs_inst_cnt);
ReturnCode mss_assert_resetn_drive_mem_clks( Target& i_target);
ReturnCode mss_deassert_force_mclk_low( Target& i_target);


ReturnCode mss_draminit(Target& i_target)
{
    // Target is centaur.mba
    //

    ReturnCode rc;
    uint32_t port_number;
    uint32_t ccs_inst_cnt = 0;
    uint8_t dram_gen; 
    uint8_t dimm_type; 

    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, dram_gen);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, dimm_type);
    if(rc) return rc;


    if ((!(dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM)) && (dram_gen == ENUM_ATTR_EFF_DRAM_GEN_DDR3))
    {
        //Commented because Master Attention Reg Check not written yet.
        //Master Attntion Reg Check... Need to add appropriate call below.
        //MASTER_ATTENTION_REG_CHECK();

        // Step one: Deassert Force_mclk_low signal     
        rc = mss_deassert_force_mclk_low(i_target);
        if(rc)
        {
            FAPI_ERR(" deassert_force_mclk_low Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }


        // Step two: Assert Resetn signal, Begin driving mem clks
        rc = mss_assert_resetn_drive_mem_clks(i_target);
        if(rc)
        {
            FAPI_ERR(" assert_resetn_drive_mem_clks Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }

        // Cycle through Ports...
        // Ports 0-1
        for ( port_number = 0; port_number < MAX_NUM_PORTS; port_number++)
        {
            if (!(dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_UDIMM))
            {
                // Step three: Load RCD Control Words
                rc = mss_rcd_load(i_target, port_number, ccs_inst_cnt);
                if(rc)
                {
                    FAPI_ERR(" rcd_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                    return rc;
                }
            }
        }

        // Cycle through Ports...
        // Ports 0-1
        for ( port_number = 0; port_number < MAX_NUM_PORTS; port_number++)
        {
            // Step four: Load MRS Setting
            rc = mss_mrs_load(i_target, port_number, ccs_inst_cnt);
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
        else
        {
            FAPI_INF("No Memory configured.");
        }


        // TODO:
        // This is Commented out because RCD Parity Check has not been written yet.
        // Check RCD Parity
        //rc = RCD_PARITY_CHECK(i_target);
        //if(rc){
            //FAPI_ERR(" RCD_PARITY_CHECK FAILED rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            //return rc;
        //}

        //Master Attntion Reg Check... Need to add appropriate call below.
        //MASTER_ATTENTION_REG_CHECK();

    }
    else
    {
        FAPI_INF( "++ COMPLICATED FLOW GOES HERE ++");
        // TODO:
        // This is Commented out because COMPLICATED_FLOW_CONTROL has not been written yet.
        //COMPLICATED_FLOW_CONTROL(); //--- currently dummy function
    }
    return rc;
}



ReturnCode mss_deassert_force_mclk_low (Target& i_target)
{ 
    ReturnCode rc;
    uint32_t rc_num = 0;
    ecmdDataBufferBase data_buffer(64);

    FAPI_INF( "+++++++++++++++++++++ DEASSERTING FORCE MCLK LOW +++++++++++++++++++++");

    // Read GP4 
    rc = fapiGetCfamRegister(i_target, GP4_REG_0x1013, data_buffer);
    if(rc)return rc;
    // set bit 3 high
    rc_num = data_buffer.setBit(4);
    if(rc_num)
    {
        rc.setEcmdError(rc_num);
        return rc;
    }
    //  Stick it back into GP4
    rc = fapiPutCfamRegister(i_target, GP4_REG_0x1013, data_buffer);
    if(rc)return rc;

    return rc;
}

ReturnCode mss_assert_resetn_drive_mem_clks(
            Target& i_target
            )
{    
    // mcbist_ddr_resetn = 1 -- to deassert DDR RESET#
    //mcbist_ddr_dphy_nclk = 01, mcbist_ddr_dphy_pclk = 10 -- to drive the memory clks

    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    ecmdDataBufferBase stop_on_err_1(1);
    ecmdDataBufferBase ue_disable_1(1);
    ecmdDataBufferBase data_sel_2(2);
    ecmdDataBufferBase pclk_2(2);
    rc_num = rc_num | pclk_2.insertFromRight((uint32_t) 2, 0, 2);
    ecmdDataBufferBase nclk_2(2);
    rc_num = rc_num | nclk_2.insertFromRight((uint32_t) 1, 0, 2);
    ecmdDataBufferBase cal_time_cnt_16(16);
    ecmdDataBufferBase resetn_1(1);
    rc_num = rc_num | resetn_1.setBit(0);
    ecmdDataBufferBase reset_recover_1(1);
    ecmdDataBufferBase copy_spare_cke_1(1);

    FAPI_INF( "+++++++++++++++++++++ ASSERTING RESETN, DRIVING MEM CLKS +++++++++++++++++++++");

    if (rc_num)
    {
        FAPI_ERR( "mss_assert_resetn_drive_mem_clks: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    // Setting CCS Mode 
    rc = mss_ccs_mode(i_target,
                      stop_on_err_1,
                      ue_disable_1,
                      data_sel_2,
                      pclk_2,
                      nclk_2,
                      cal_time_cnt_16,
                      resetn_1,
                      reset_recover_1,
                      copy_spare_cke_1);

    return rc;
}

ReturnCode mss_rcd_load(
            Target& i_target,
            uint32_t i_port_number,
            uint32_t& io_ccs_inst_cnt
            )    {

    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;
    uint32_t dimm_number;
    uint32_t rcd_number;

    ecmdDataBufferBase rcd_cntl_wrd(4);
    ecmdDataBufferBase rcd_cntl_wrd_tmp(64);
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

    uint8_t num_ranks_array[2][2]; //[port][dimm]
    uint64_t rcd_array[2][2]; //[port][dimm]

    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target, rcd_array);
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

    FAPI_INF( "+++++++++++++++++++++ LOADING RCD CONTROL WORDS FOR PORT %d +++++++++++++++++++++", i_port_number);

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
	    FAPI_INF( "RCD Control Word: 0x%016X", rcd_array[i_port_number][dimm_number]);

            if (rc_num)
            {
                FAPI_ERR( "mss_rcd_load: Error setting up buffers");
                rc_buff.setEcmdError(rc_num);
                return rc_buff;
            }

            // ALL active CS lines at a time.
            rc_num = rc_num | csn_8.setBit(0,8);
            if (num_ranks == 1)
            {
                rc_num = rc_num | csn_8.clearBit(0+4*dimm_number);
            }
            else if (num_ranks == 2)
            {
                rc_num = rc_num | csn_8.clearBit(0+4*dimm_number);
                rc_num = rc_num | csn_8.clearBit(1+4*dimm_number);
            }
            else if (num_ranks == 4)
            {
                rc_num = rc_num | csn_8.clearBit(0+4*dimm_number);
                rc_num = rc_num | csn_8.clearBit(1+4*dimm_number);
                rc_num = rc_num | csn_8.clearBit(2+4*dimm_number);
                rc_num = rc_num | csn_8.clearBit(3+4*dimm_number);
            }

            ecmdDataBufferBase rcd_number_tmp(32);

            // Propogate through the 16, 4-bit control words
            for ( rcd_number = 0; rcd_number<= 15; rcd_number++)
            {
                rc_num = rc_num | address_16.clearBit(0, 16);
                rc_num = rc_num | rcd_cntl_wrd_tmp.setDoubleWord(0, rcd_array[i_port_number][dimm_number]);  
                rc_num = rc_num | rcd_cntl_wrd_tmp.extract(rcd_cntl_wrd, 4*rcd_number, 4);
                rc_num = rc_num | rcd_number_tmp.setWord( 0 , rcd_number);

                //control word code bits A0, A1, A2, BA2
                rc_num = rc_num | address_16.insert(rcd_number_tmp, 13, 1, 29);
                rc_num = rc_num | address_16.insert(rcd_number_tmp, 14, 1, 30);
                rc_num = rc_num | address_16.insert(rcd_number_tmp, 15, 1, 31);
                rc_num = rc_num | bank_3.insert(rcd_number_tmp, 2, 1, 28);

                //control word values A3, A4, BA0, BA1
                rc_num = rc_num | address_16.insert(rcd_cntl_wrd, 3, 2, 0);
                rc_num = rc_num | bank_3.insert(rcd_cntl_wrd, 0, 2, 2);

                // Send out to the CCS array 
                rc_num = rc_num | num_idles_16.insertFromRight((uint32_t) 12, 0, 16);
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
    return rc;
}

ReturnCode mss_mrs_load(
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

    ecmdDataBufferBase mrs0(16); 
    ecmdDataBufferBase mrs1(16);
    ecmdDataBufferBase mrs2(16);
    ecmdDataBufferBase mrs3(16);
    uint16_t MRS0 = 0;
    uint16_t MRS1 = 0;
    uint16_t MRS2 = 0;
    uint16_t MRS3 = 0;

    uint16_t num_ranks = 0;

    FAPI_INF( "+++++++++++++++++++++ LOADING MRS SETTINGS FOR PORT %d +++++++++++++++++++++", i_port_number);

    uint8_t num_ranks_array[2][2]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, num_ranks_array);
    if(rc) return rc;

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
    uint8_t dram_wr;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR, &i_target, dram_wr);
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

    if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_SEQUENTIAL)
    {
        read_bt = 0x00;
    }
    else if (read_bt == ENUM_ATTR_EFF_DRAM_RBT_INTERLEAVE)
    {
        read_bt = 0xFF;
    }

    if ((dram_cl > 4)&&(dram_cl < 12))
    {
        dram_cl = (dram_cl - 4) << 1; 
    }
    else if ((dram_cl > 11)&&(dram_cl > 16))
    {
        dram_cl = ((dram_cl - 12) << 1) + 1;   
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

    dram_wr = mss_reverse_8bits(dram_wr);

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
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RON, &i_target, out_drv_imp_cntl);
    if(rc) return rc;
    uint8_t dram_rtt_nom[2][2][4];
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RTT_NOM, &i_target, dram_rtt_nom);
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
    else if (dram_al == ENUM_ATTR_EFF_DRAM_AL_CL_MUNUS_2)
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

    //MRS2
    uint8_t pt_arr_sr; //Partial Array Self Refresh  
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_PASR, &i_target, pt_arr_sr);
    if(rc) return rc;
    uint8_t cwl; // CAS Write Latency 
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_CWL, &i_target, cwl);
    if(rc) return rc;
    uint8_t auto_sr; // Auto Self-Refresh 
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_ASR, &i_target, auto_sr);
    if(rc) return rc;
    uint8_t sr_temp; // Self-Refresh Temp Range 
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_SRT, &i_target, sr_temp);
    if(rc) return rc;
    uint8_t dram_rtt_wr[2][2][4];
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RTT_WR, &i_target, dram_rtt_wr);
    if(rc) return rc;

    if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_FULL)
    {
        pt_arr_sr = 0x00;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_FIRST_HALF)
    {
        pt_arr_sr = 0x80;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_FIRST_QUARTER)
    {
        pt_arr_sr = 0x40;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_FIRST_EIGHTH)
    {
        pt_arr_sr = 0xC0;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_LAST_THREE_FOURTH)
    {
        pt_arr_sr = 0x20;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_LAST_HALF)
    {
        pt_arr_sr = 0xA0;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_LAST_QUARTER)
    {
        pt_arr_sr = 0x60;
    }
    else if (pt_arr_sr == ENUM_ATTR_EFF_DRAM_PASR_LAST_EIGHTH)
    {
        pt_arr_sr = 0xE0;
    }

    cwl = mss_reverse_8bits(cwl - 5); 

    if (auto_sr == ENUM_ATTR_EFF_DRAM_ASR_SRT)
    {
        auto_sr = 0x00;
    }
    else if (auto_sr == ENUM_ATTR_EFF_DRAM_ASR_ASR)
    {
        auto_sr = 0xFF;
    }

    if (sr_temp == ENUM_ATTR_EFF_DRAM_SRT_NORMAL)
    {
        sr_temp = 0x00;
    }
    else if (sr_temp == ENUM_ATTR_EFF_DRAM_SRT_EXTEND)
    {
        sr_temp = 0xFF;
    }

    //MRS3
    uint8_t mpr_loc; // MPR Location 
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_LOC, &i_target, mpr_loc);
    if(rc) return rc;
    uint8_t mpr_op; // MPR Operation Mode
    rc = FAPI_ATTR_GET(ATTR_EFF_MPR_MODE, &i_target, mpr_op);
    if(rc) return rc;

    mpr_loc = mss_reverse_8bits(mpr_loc);

    if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_ENABLE)
    {
        mpr_op = 0x00;
    }
    else if (mpr_op == ENUM_ATTR_EFF_MPR_MODE_DISABLE)
    {
        mpr_op = 0xFF;
    }

    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    rc_num = rc_num | csn_8.setBit(0,8);
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

    // Dimm 0-1
    for ( dimm_number = 0; dimm_number < MAX_NUM_DIMMS; dimm_number++)
    {
        num_ranks = num_ranks_array[i_port_number][dimm_number];

        if (num_ranks == 0)
        {
            FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d ", i_port_number, dimm_number, num_ranks);
        }
        else
        {
            // Rank 0-3
            for ( rank_number = 0; rank_number < MAX_NUM_RANKS; rank_number++)
            {
                    FAPI_INF( "MRS SETTINGS FOR PORT%d DIMM%d RANK%d", i_port_number, dimm_number, rank_number);

                    rc_num = rc_num | csn_8.setBit(0,8);
                    rc_num = rc_num | address_16.clearBit(0, 16);

                    rc_num = rc_num | mrs0.insert((uint8_t) dram_bl, 0, 2, 0);
                    rc_num = rc_num | mrs0.insert((uint8_t) dram_cl, 2, 1, 0);
                    rc_num = rc_num | mrs0.insert((uint8_t) read_bt, 3, 1, 0);
                    rc_num = rc_num | mrs0.insert((uint8_t) dram_cl, 4, 3, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) test_mode, 7, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) dll_reset, 8, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) dram_wr, 9, 3);
                    rc_num = rc_num | mrs0.insert((uint8_t) dll_precharge, 12, 1);
                    rc_num = rc_num | mrs0.insert((uint8_t) 0x00, 13, 3);

	            rc_num = rc_num | mrs0.extractPreserve(&MRS0, 0, 16, 0);

                    if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x00;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM20)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x20;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xA0;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0xC0;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM60)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x80;
                    }
                    else if (dram_rtt_nom[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM120)
                    {
                        dram_rtt_nom[i_port_number][dimm_number][rank_number] = 0x40;
                    }

                    if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_EFF_DRAM_RON_OHM40)
                    {
                        out_drv_imp_cntl[i_port_number][dimm_number] = 0x00;
                    }
                    else if (out_drv_imp_cntl[i_port_number][dimm_number] == ENUM_ATTR_EFF_DRAM_RON_OHM34)
                    {
                        out_drv_imp_cntl[i_port_number][dimm_number] = 0x80;
                    }

                    rc_num = rc_num | mrs1.insert((uint8_t) dll_enable, 0, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) out_drv_imp_cntl[i_port_number][dimm_number], 1, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][0], 2, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) dram_al, 3, 2, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) out_drv_imp_cntl[i_port_number][dimm_number], 5, 1, 1);
                    rc_num = rc_num | mrs1.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][0], 6, 1, 2);
                    rc_num = rc_num | mrs1.insert((uint8_t) wr_lvl, 7, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 8, 1);
                    rc_num = rc_num | mrs1.insert((uint8_t) dram_rtt_nom[i_port_number][dimm_number][0], 9, 1, 3);
                    rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 10, 1);
                    rc_num = rc_num | mrs1.insert((uint8_t) tdqs_enable, 11, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) q_off, 12, 1, 0);
                    rc_num = rc_num | mrs1.insert((uint8_t) 0x00, 13, 3);

        	    rc_num = rc_num | mrs1.extractPreserve(&MRS1, 0, 16, 0);


                    if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE)
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x00;
                    }
                    else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_DRAM_RTT_WR_OHM60)
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x80;
                    }
                    else if (dram_rtt_wr[i_port_number][dimm_number][rank_number] == ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120)
                    {
                        dram_rtt_wr[i_port_number][dimm_number][rank_number] = 0x40;
                    }

                    rc_num = rc_num | mrs2.insert((uint8_t) pt_arr_sr, 0, 3);
                    rc_num = rc_num | mrs2.insert((uint8_t) cwl, 3, 3);
                    rc_num = rc_num | mrs2.insert((uint8_t) auto_sr, 6, 1);
                    rc_num = rc_num | mrs2.insert((uint8_t) sr_temp, 7, 1);
                    rc_num = rc_num | mrs2.insert((uint8_t) 0x00, 8, 1);
                    rc_num = rc_num | mrs2.insert((uint8_t) dram_rtt_wr[i_port_number][dimm_number][0], 9, 2);
                    rc_num = rc_num | mrs2.insert((uint8_t) 0x00, 10, 6);

        	    rc_num = rc_num | mrs2.extractPreserve(&MRS2, 0, 16, 0);
     
                    rc_num = rc_num | mrs3.insert((uint8_t) mpr_loc, 0, 2);
                    rc_num = rc_num | mrs3.insert((uint8_t) mpr_op, 2, 1);
                    rc_num = rc_num | mrs3.insert((uint16_t) 0x0000, 3, 13);

        	    rc_num = rc_num | mrs3.extractPreserve(&MRS3, 0, 16, 0);
        	    FAPI_INF( "MRS 0: 0x%04X", MRS0);
        	    FAPI_INF( "MRS 1: 0x%04X", MRS1);
        	    FAPI_INF( "MRS 2: 0x%04X", MRS2);	
                    FAPI_INF( "MRS 3: 0x%04X", MRS3);

                    if (rc_num)
                    {
                        FAPI_ERR( "mss_mrs_load: Error setting up buffers");
                        rc_buff.setEcmdError(rc_num);
                        return rc_buff;
                    }

                    // Only corresponding CS to rank
                    rc_num = rc_num | csn_8.setBit(0,8); 
                    rc_num = rc_num | csn_8.clearBit(rank_number+4*dimm_number);
              
                    // Propogate through the 4 MRS cmds
                    for ( mrs_number = 0; mrs_number < 4; mrs_number++)
                    {
     
                        // Copying the current MRS into address buffer matching the MRS_array order
                        // Setting the bank address
                        if (mrs_number == 0)
                        {
                            rc_num = rc_num | address_16.insert(mrs2, 0, 16, 0);
                            rc_num = rc_num | bank_3.insertFromRight((uint8_t) MRS2_BA, 0, 3);
                        }
                        else if ( mrs_number == 1)
                        {
                            rc_num = rc_num | address_16.insert(mrs3, 0, 16, 0);
                            rc_num = rc_num | bank_3.insertFromRight((uint8_t) MRS3_BA, 0, 3);
                        }
                        else if ( mrs_number == 2)
                        {
                            rc_num = rc_num | address_16.insert(mrs1, 0, 16, 0);
                            rc_num = rc_num | bank_3.insertFromRight((uint8_t) MRS1_BA, 0, 3);
                        }
                        else if ( mrs_number == 3)
                        {
                            rc_num = rc_num | address_16.insert(mrs0, 0, 16, 0);
                            rc_num = rc_num | bank_3.insertFromRight((uint8_t) MRS0_BA, 0, 3);
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
            }
        }
    }
    return rc;
}

} //end extern C

