//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_training/mss_draminit_training.C $
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
//---------|----------|---------|------------------------------------------------
//  1.17   | divyakum |20-Feb-12| Adding comments to include target type 
//  1.16   | divyakum |20-Feb-12| Replaced calls to insertFromBin with setHalfWord and setBit functions
//  1.15   | divyakum |14-Feb-12| Removed port field from mss_ccs_mode, mss_ccs_inst_arry_1, mss_execute_ccs_inst_array. 
//         |          |         | NOTE: compatible with mss_funcs.H v1.19 or newer 
//  1.14   | divyakum |10-Feb-12| Added/Modified error codes, var names and declarations to meet coding guidlines
//  1.13   | divyakum |08-Feb-12| Modified Attributes to FAPI attributes
//         |          |         | Added rc checking
//  1.12   | divyakum |31-Jan-12| Modified number of ports to work with Brent's userlevel.   
//  1.11   | divyakum |20-Jan-12| Modified print messages. Fixed indentations
//  1.16   | divyakum |20-Jan-12| Fixed CCS func names to match mss_funcs.H ver 1.16
//         | divyakum |         | Added resetn initialization. 
//  1.15   | bellows  |23-Dec-11| Set poll count to 100, set the end bit and when to execute the array time
//  1.14   | divyakum |21-Dec-11| Added more info prints. Fixed Execution of CCS
//  1.13   | bellows  |20-Dec-11| Fixed up rank loop so that it goes over both DIMMs
//  1.12   | jdsloat  |23-Nov-11| Incremented instruction number, added info messages
//  1.11   | jdsloat  |21-Nov-11| Got rid of GOTO argument in CCS cmds.   
//  1.10   | divyakum |18-Nov-11| Fixed function calls to match procedure name. 
//  1.9    | divyakum |11-Oct-11| Fix to include mss_funcs instead of cen_funcs. 
//	   |          |         | Changed usage of array attributes. 
//         |          |         | NOTE: Needs to be compiled with mss_funcs v1.3.
//  1.8    | divyakum |03-Oct-11| Removed primary_ranks_arrayvariable. Fixed rank loop for Socket1
//  1.7    | divyakum |30-Sep-11| First drop for Centaur. This code compiles
//  1.6    | divyakum |28-Sep-11| Added Error path with cal fails. 
//         |          |         | Modified CCS_MODE, CCS_EXECUTE call
//  1.5    | divyakum |27-Sep-11| Updated code to match with cen_funcs.H v.1.5 
//  1.4    | divyakum |27-Sep-11| Added capability to issue CCS cmds to a port pair where possible.
//  1.3    | divyakum |26-Sep-11| Added calls to attributes and CCS array for ZQ and initial calibrations. 
//         |          |         | Added rank loopers. 
//  1.2    | jdsloat  |14-Jul-11| Proper call name fix
//  1.1    | jdsloat  |22-Apr-11| Initial draft

//TODO:
//Enable appropriate init cal steps in PC Initial Calibration Config0 based on CAL_STEP attribute 
//Add error path when Cal fails 
//Enable complex training procedure based on DIMM_TYPE
//Check BAD BYTE attribute with DISABLE DP18
//Figure out DISABLE DP18 mapping for each physical byte. 
//Need to add cal_timer_cnt_mult to CCS_MODE func

/**
 * @brief Draminit Training procedure. Calibrating DRAMs
 *
 * @param[in]  i_target  Reference to MBA target
 *
 * @return ReturnCode
 */

//----------------------------------------------------------------------
//  FAPI function Includes
//----------------------------------------------------------------------

#include <fapi.H>

//----------------------------------------------------------------------
//  Centaur function Includes
//----------------------------------------------------------------------
#include <mss_funcs.H>

//------------End My Includes-------------------------------------------



extern "C" {

using namespace fapi;

ReturnCode mss_draminit_training(Target& target);

ReturnCode mss_draminit_training(Target& target)
{
    // Target is centaur.mba
    //Enums and Constants
    enum size 
    {
       MAX_NUM_PORT = 2,
       MAX_NUM_DIMM = 2,
       MAX_NUM_GROUP = 4,
       INVALID = 255
    };
    uint32_t NUM_POLL = 100;
 
    ReturnCode rc;
    ReturnCode buffer_rc;

    //Issue ZQ Cal first per rank   
    uint32_t instruction_number = 0;
    ecmdDataBufferBase address_buffer_16(16);
    buffer_rc = buffer_rc | address_buffer_16.setHalfWord(0, 0x0020); //Set A10 bit for ZQCal Long
    ecmdDataBufferBase bank_buffer_8(8);
    buffer_rc = buffer_rc | bank_buffer_8.flushTo0();
    ecmdDataBufferBase activate_buffer_1(1);
    buffer_rc = buffer_rc | activate_buffer_1.flushTo0();
    ecmdDataBufferBase rasn_buffer_1(1);
    buffer_rc = buffer_rc | rasn_buffer_1.flushTo1(); //For ZQCal rasn = 1; casn = 1; wen = 0;
    ecmdDataBufferBase casn_buffer_1(1);
    buffer_rc = buffer_rc | casn_buffer_1.flushTo1();
    ecmdDataBufferBase wen_buffer_1(1);
    buffer_rc = buffer_rc | wen_buffer_1.flushTo1();
    ecmdDataBufferBase cke_buffer_8(8);
    buffer_rc = buffer_rc | cke_buffer_8.flushTo1();
    ecmdDataBufferBase csn_buffer_8(8);
    buffer_rc = buffer_rc | csn_buffer_8.flushTo1();
    ecmdDataBufferBase odt_buffer_8(8);
    buffer_rc = buffer_rc | odt_buffer_8.flushTo0(); 
    ecmdDataBufferBase test_buffer_4(4);
    buffer_rc = buffer_rc | test_buffer_4.setBit(1); // 11XX:Initial Calibration, 01XX:External ZQ calibration
 
    ecmdDataBufferBase num_idles_buffer_16(16);
    buffer_rc = buffer_rc | num_idles_buffer_16.setHalfWord(0, 0x0400); //1024 for ZQCal
    ecmdDataBufferBase num_repeat_buffer_16(16);
    buffer_rc = buffer_rc | num_repeat_buffer_16.flushTo0();
    ecmdDataBufferBase data_buffer_20(20);
    buffer_rc = buffer_rc | data_buffer_20.flushTo0();
    ecmdDataBufferBase read_compare_buffer_1(1);
    buffer_rc = buffer_rc | read_compare_buffer_1.flushTo0();
    ecmdDataBufferBase rank_cal_buffer_3(3); 
    buffer_rc = buffer_rc | rank_cal_buffer_3.flushTo0();
    ecmdDataBufferBase ddr_cal_enable_buffer_1(1);
    buffer_rc = buffer_rc | ddr_cal_enable_buffer_1.flushTo1();
    ecmdDataBufferBase ccs_end_buffer_1(1);
    buffer_rc = buffer_rc | ccs_end_buffer_1.flushTo0();
 

    ecmdDataBufferBase stop_on_err_buffer_1(1);
    buffer_rc = buffer_rc | stop_on_err_buffer_1.flushTo0();
    ecmdDataBufferBase ue_disable_buffer_1(1);
    buffer_rc = buffer_rc | ue_disable_buffer_1.flushTo0();
    ecmdDataBufferBase data_sel_buffer_2(2);
    ecmdDataBufferBase pclk_buffer_2(2);
    ecmdDataBufferBase nclk_buffer_2(2);
    ecmdDataBufferBase cal_time_cnt_buffer_16(16);
    buffer_rc = buffer_rc | cal_time_cnt_buffer_16.flushTo1();
    ecmdDataBufferBase resetn_buffer_1(1);
    buffer_rc = buffer_rc | resetn_buffer_1.setBit(0);
    ecmdDataBufferBase reset_recover_buffer_1(1);
    ecmdDataBufferBase copy_spare_cke_buffer_1(1);
 
    if(buffer_rc)
    {
        FAPI_ERR( "Error setting up buffers");
        return buffer_rc;
    }

    uint32_t current_rank = 0;
    uint32_t port = 0;
    uint32_t start_rank = 0;

    uint8_t num_ranks_array[2][2]; //num_ranks_array[port][dimm]
    uint8_t primary_ranks_array[4][2]; //primary_ranks_array[group][port]

    //populate num_ranks_array
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &target, num_ranks_array);
    if(rc) return rc;
 
    //populate primary_ranks_arrays_array
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &target, primary_ranks_array[0]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &target, primary_ranks_array[1]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &target, primary_ranks_array[2]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &target, primary_ranks_array[3]);
    if(rc) return rc;
   
    for(port = 0; port < MAX_NUM_PORT; port++)
    {
        for(uint32_t dimm = 0; dimm < MAX_NUM_DIMM; dimm++) 
        {
            start_rank=(4 * dimm);
            for(current_rank = start_rank; current_rank < start_rank + num_ranks_array[port][dimm]; current_rank++) {
                FAPI_INF( "+++++++++++++++ Sending zqcal to port: %d rank: %d +++++++++++++++", port, current_rank);
                buffer_rc = buffer_rc | test_buffer_4.setBit(1);
                buffer_rc = buffer_rc | num_idles_buffer_16.setHalfWord(0,0x0400);
                if(buffer_rc)
                {
                    FAPI_ERR( "Error setting up buffers");
                    return buffer_rc;
                }
                //Need to add cal_timer_cnt_mult to CCS_MODE func
                rc = mss_ccs_mode(target, stop_on_err_buffer_1, ue_disable_buffer_1, data_sel_buffer_2, pclk_buffer_2, nclk_buffer_2, cal_time_cnt_buffer_16, resetn_buffer_1, reset_recover_buffer_1, copy_spare_cke_buffer_1);
                if(rc) return rc;
                buffer_rc = buffer_rc | csn_buffer_8.flushTo1(); 
                buffer_rc = buffer_rc | csn_buffer_8.clearBit(current_rank);
                if(buffer_rc)
                {
                    FAPI_ERR( "Error setting up buffers");
                    return buffer_rc;
                }
                if(instruction_number == 28)
                {
                    //CCS array is full. Issue execute.
                    FAPI_INF( "+++++++++++++++ Execute CCS array on port: %d +++++++++++++++", port);
                    buffer_rc = buffer_rc | ccs_end_buffer_1.flushTo1();
                    buffer_rc = buffer_rc | bank_buffer_8.flushTo0();
                    buffer_rc = buffer_rc | activate_buffer_1.flushTo0();
                    buffer_rc = buffer_rc | cke_buffer_8.flushTo1();
                    buffer_rc = buffer_rc | odt_buffer_8.flushTo0();
                    if(buffer_rc)
                    {
                        FAPI_ERR( "Error setting up buffers");
                        return buffer_rc;
                    }
                    rc = mss_ccs_inst_arry_0(target, instruction_number, address_buffer_16, bank_buffer_8, activate_buffer_1, rasn_buffer_1, casn_buffer_1, wen_buffer_1, cke_buffer_8, csn_buffer_8, odt_buffer_8, test_buffer_4, port);
                    if(rc) return rc;
                    rc = mss_ccs_inst_arry_1(target, instruction_number, num_idles_buffer_16, num_repeat_buffer_16, data_buffer_20, read_compare_buffer_1, rank_cal_buffer_3, ddr_cal_enable_buffer_1, ccs_end_buffer_1);
                    if(rc) return rc;
                    rc = mss_execute_ccs_inst_array(target, NUM_POLL, 60);
                    if(rc) return rc;
                    instruction_number = 0;
                } 
                else 
                {
                    buffer_rc = buffer_rc | ccs_end_buffer_1.flushTo0();
                    rc = mss_ccs_inst_arry_0(target, instruction_number, address_buffer_16, bank_buffer_8, activate_buffer_1, rasn_buffer_1, casn_buffer_1, wen_buffer_1, cke_buffer_8, csn_buffer_8, odt_buffer_8, test_buffer_4, port);
                    if(rc) return rc;
                    rc = mss_ccs_inst_arry_1(target, instruction_number, num_idles_buffer_16, num_repeat_buffer_16, data_buffer_20, read_compare_buffer_1, rank_cal_buffer_3, ddr_cal_enable_buffer_1, ccs_end_buffer_1);
                    if(rc) return rc;
                } 
     	        instruction_number++;
            }
        }   
        buffer_rc = buffer_rc | test_buffer_4.setBit(0, 2);
        buffer_rc = buffer_rc | num_idles_buffer_16.flushTo1();
        buffer_rc = buffer_rc | odt_buffer_8.flushTo0();
        buffer_rc = buffer_rc | csn_buffer_8.flushTo1();
        buffer_rc = buffer_rc | cke_buffer_8.flushTo1();
        buffer_rc = buffer_rc | wen_buffer_1.flushTo1();
        buffer_rc = buffer_rc | casn_buffer_1.flushTo1();
        buffer_rc = buffer_rc | rasn_buffer_1.flushTo1();
        buffer_rc = buffer_rc | activate_buffer_1.flushTo0();
        buffer_rc = buffer_rc | bank_buffer_8.flushTo0();
        buffer_rc = buffer_rc | address_buffer_16.flushTo0();
        if(buffer_rc)
        {
            FAPI_ERR( "Error setting up buffers");
            return buffer_rc;
        }

        for(uint32_t group = 0; group < MAX_NUM_GROUP; group++)
        {
            if(primary_ranks_array[group][port] != INVALID) 
            {   
                //Check if rank group exists
  	        FAPI_INF( "+++++++++++++++ Sending init cal to port %d rank group: %d +++++++++++++++", port, group);
                if(instruction_number == 28) 
                {
                    //CCS array is full. Issue execute. 
                    //Reset CCS array and start populating instructions
                    buffer_rc = buffer_rc | ccs_end_buffer_1.flushTo1();
                    rc = mss_ccs_inst_arry_0(target, instruction_number, address_buffer_16, bank_buffer_8, activate_buffer_1, rasn_buffer_1, casn_buffer_1, wen_buffer_1, cke_buffer_8, csn_buffer_8, odt_buffer_8, test_buffer_4, port);
                    if(rc) return rc;
                    buffer_rc = buffer_rc | rank_cal_buffer_3.insert(primary_ranks_array[group][port], 0, 3, 0);
                    rc = mss_ccs_inst_arry_1(target, instruction_number, num_idles_buffer_16, num_repeat_buffer_16, data_buffer_20, read_compare_buffer_1, rank_cal_buffer_3, ddr_cal_enable_buffer_1, ccs_end_buffer_1);
                    if(rc) return rc;
                    FAPI_INF( "+++++++++++++++ Execute CCS array on port: %d +++++++++++++++", port);
                    rc = mss_execute_ccs_inst_array( target, NUM_POLL, 60);
                    if(rc) return rc;
                    instruction_number = 0;
                }
                else 
                {
                    buffer_rc = buffer_rc | ccs_end_buffer_1.flushTo0();
                    rc = mss_ccs_inst_arry_0(target, instruction_number, address_buffer_16, bank_buffer_8, activate_buffer_1, rasn_buffer_1, casn_buffer_1, wen_buffer_1, cke_buffer_8, csn_buffer_8, odt_buffer_8, test_buffer_4, port);
                    if(rc) return rc;
                    buffer_rc = buffer_rc | rank_cal_buffer_3.insert(primary_ranks_array[group][port], 0, 3, 0);
                    rc = mss_ccs_inst_arry_1(target, instruction_number, num_idles_buffer_16, num_repeat_buffer_16, data_buffer_20, read_compare_buffer_1, rank_cal_buffer_3, ddr_cal_enable_buffer_1, ccs_end_buffer_1);
                    if(rc) return rc;
                }
                instruction_number++;
            }
        }
        if(instruction_number > 0) 
        {
            //execute CCS array even though it's not full before moving on to the next port. 
            buffer_rc = buffer_rc | ccs_end_buffer_1.flushTo1();
            buffer_rc = buffer_rc | ddr_cal_enable_buffer_1.flushTo0();
            if(buffer_rc)
            {
                FAPI_ERR( "Error setting up buffers");
                return buffer_rc;
            }
            rc = mss_ccs_inst_arry_0(target, instruction_number, address_buffer_16, bank_buffer_8, activate_buffer_1, rasn_buffer_1, casn_buffer_1, wen_buffer_1, cke_buffer_8, csn_buffer_8, odt_buffer_8, test_buffer_4, port);
            if(rc) return rc;
            buffer_rc = buffer_rc | rank_cal_buffer_3.flushTo0();
            rc = mss_ccs_inst_arry_1(target, instruction_number, num_idles_buffer_16, num_repeat_buffer_16, data_buffer_20, read_compare_buffer_1, rank_cal_buffer_3, ddr_cal_enable_buffer_1, ccs_end_buffer_1);
            if(rc) return rc;
            FAPI_INF( "+++++++++++++++ Execute CCS array on port: %d +++++++++++++++", port);
            rc = mss_execute_ccs_inst_array( target, NUM_POLL, 60);
            if(rc) return rc;
            instruction_number = 0;
            buffer_rc = buffer_rc | ddr_cal_enable_buffer_1.flushTo1();
            buffer_rc = buffer_rc | ccs_end_buffer_1.flushTo0();
            if(buffer_rc)
            {
                FAPI_ERR( "Error setting up buffers");
                return buffer_rc;
            }
            
        }  
    } 
    for(port = 0; port < 2; port++)
    {
       FAPI_INF( "+++++++++++++++ Check Cal Status on port: %d (PLACE HOLDER!) +++++++++++++++", port);
    }
    return rc; 
}
} //end extern C

