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
//  1.26   | asaetow  |12-Apr-12| Added "if(rc) return rc;" at line 180.
//  1.25   | asaetow  |06-Apr-12| Added "if(rc) return rc;" at line 165.
//  1.24   | asaetow  |03-Apr-12| Changed FAPI_INF to FAPI_ERR where applicable from lines 275 to 324, per Mike Jones.
//  1.23   | asaetow  |29-Mar-12| Fixed FAPI_SET_HWP_ERROR using temp error callout RC_MSS_PLACE_HOLDER_ERROR.
//         |          |         | Changed uint32_t NUM_POLL to const.
//  1.22   | divyakum |29-Mar-12| Fixed rc assignment. Added comments for error handling. 
//  1.21   | divyakum |06-Mar-12| Added cal status checking function. 
//         |          |         | Fixed init cal issue via CCS to account for both ports.
//  1.20   | divyakum |         | Modified to execute CCS after every instruction. 
//         |          |         | Added error checking for calibration. Needs cen_scom_addresses.H v.1.15 or newer. 
//  1.19   | divyakum |01-Mar-12| Fixed ddr_cal_enable_buffer_1 value for ZQ cal long 
//  1.18   | divyakum |29-Feb-12| Removed call to ccs_mode function. writing to scom directly
//         |          |         | Fixed wen_buffer value when re-issuing zqcal
//         |          |         | Fixed test_buffer value when re-issuing zqcal
//         |          |         | Added cen_scom_addresses.H in include
//  1.17   | divyakum |20-Feb-12| Adding comments to include i_target type 
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

//----------------------------------------------------------------------
//  FAPI function Includes
//----------------------------------------------------------------------

#include <fapi.H>

//----------------------------------------------------------------------
//  Centaur function Includes
//----------------------------------------------------------------------
#include <cen_scom_addresses.H>
#include <mss_funcs.H>

//------------End My Includes-------------------------------------------



extern "C" {

using namespace fapi;

ReturnCode mss_draminit_training(Target& i_target);
ReturnCode mss_check_cal_status(Target& i_target, uint8_t i_port, uint8_t i_group);

ReturnCode mss_draminit_training(Target& i_target)
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
    const uint32_t NUM_POLL = 100;
 
    ReturnCode rc;
    uint32_t rc_num = 0;

    //Issue ZQ Cal first per rank   
    uint32_t instruction_number = 0;
    ecmdDataBufferBase address_buffer_16(16);
    rc_num = rc_num | address_buffer_16.flushTo0();
    ecmdDataBufferBase bank_buffer_8(8);
    rc_num = rc_num | bank_buffer_8.flushTo0();
    ecmdDataBufferBase activate_buffer_1(1);
    rc_num = rc_num | activate_buffer_1.flushTo0();
    ecmdDataBufferBase rasn_buffer_1(1);
    ecmdDataBufferBase casn_buffer_1(1);
    ecmdDataBufferBase wen_buffer_1(1);
    ecmdDataBufferBase cke_buffer_8(8);
    rc_num = rc_num | cke_buffer_8.flushTo1();
    ecmdDataBufferBase csn_buffer_8(8);
    rc_num = rc_num | csn_buffer_8.flushTo1();
    ecmdDataBufferBase odt_buffer_8(8);
    rc_num = rc_num | odt_buffer_8.flushTo0(); 
    ecmdDataBufferBase test_buffer_4(4);
 
    ecmdDataBufferBase num_idles_buffer_16(16);
    rc_num = rc_num | num_idles_buffer_16.flushTo1();
    ecmdDataBufferBase num_repeat_buffer_16(16);
    rc_num = rc_num | num_repeat_buffer_16.flushTo0();
    ecmdDataBufferBase data_buffer_20(20);
    rc_num = rc_num | data_buffer_20.flushTo0();
    ecmdDataBufferBase read_compare_buffer_1(1);
    rc_num = rc_num | read_compare_buffer_1.flushTo0();
    ecmdDataBufferBase rank_cal_buffer_3(3); 
    rc_num = rc_num | rank_cal_buffer_3.flushTo0();
    ecmdDataBufferBase ddr_cal_enable_buffer_1(1);
    ecmdDataBufferBase ccs_end_buffer_1(1);
    rc_num = rc_num | ccs_end_buffer_1.flushTo1();
 

    ecmdDataBufferBase stop_on_err_buffer_1(1);
    rc_num = rc_num | stop_on_err_buffer_1.flushTo0();
    ecmdDataBufferBase cal_timeout_cnt_buffer_16(16);
    rc_num = rc_num | cal_timeout_cnt_buffer_16.flushTo1();
    ecmdDataBufferBase resetn_buffer_1(1);
    rc_num = rc_num | resetn_buffer_1.setBit(0);
    ecmdDataBufferBase cal_timeout_cnt_mult_buffer_2(2);
    rc_num = rc_num | cal_timeout_cnt_mult_buffer_2.flushTo0();

    ecmdDataBufferBase data_buffer_64(64);
    if(rc_num)
    {
        rc.setEcmdError(rc_num);
        return rc;
    }

    uint8_t port = 0;
    uint8_t group = 0;

    uint8_t primary_ranks_array[4][2]; //primary_ranks_array[group][port]

 
    //populate primary_ranks_arrays_array
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &i_target, primary_ranks_array[0]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &i_target, primary_ranks_array[1]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &i_target, primary_ranks_array[2]);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &i_target, primary_ranks_array[3]);
    if(rc) return rc;

    //Set up CCS Mode Reg for Init cal
    rc = fapiGetScom(i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data_buffer_64);
    if(rc) return rc;
    rc_num = rc_num | data_buffer_64.insert(stop_on_err_buffer_1, 0, 1, 0);
    rc_num = rc_num | data_buffer_64.insert(cal_timeout_cnt_buffer_16, 8, 16, 0);
    rc_num = rc_num | data_buffer_64.insert(resetn_buffer_1, 24, 1, 0);
    rc_num = rc_num | data_buffer_64.insert(cal_timeout_cnt_mult_buffer_2, 30, 2, 0);
    if(rc_num)
    {
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target, MEM_MBA01_CCS_MODEQ_0x030106A7, data_buffer_64);
    if(rc) return rc;

    for(port = 0; port < MAX_NUM_PORT; port++)
    {
        rc = mss_execute_zq_cal(i_target, port);
        if(rc) return rc;
    }

    //Set up for Init Cal - Done per port pair
    rc_num = rc_num | test_buffer_4.setBit(0, 2); //Init Cal test = 11XX
    rc_num = rc_num | wen_buffer_1.flushTo1(); //Init Cal ras/cas/we = 1/1/1
    rc_num = rc_num | casn_buffer_1.flushTo1();
    rc_num = rc_num | rasn_buffer_1.flushTo1();
    rc_num = rc_num | ddr_cal_enable_buffer_1.flushTo1(); //Init cal
    if(rc_num)
    {
        rc.setEcmdError(rc_num);
        return rc;
    }

    for(group = 0; group < MAX_NUM_GROUP; group++)
    {
        if((primary_ranks_array[group][0] != INVALID) || (primary_ranks_array[group][1] != INVALID))
        {  
            //Check if rank group exists
            FAPI_INF( "+++++++++++++++ Sending init cal on rank group: %d +++++++++++++++", group);
            rc = mss_ccs_inst_arry_0(i_target, instruction_number, address_buffer_16, bank_buffer_8, activate_buffer_1, rasn_buffer_1, casn_buffer_1, wen_buffer_1, cke_buffer_8, csn_buffer_8, odt_buffer_8, test_buffer_4, 0);
            if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs
            if(primary_ranks_array[group][0] == INVALID)
            {
                rc_num = rc_num | rank_cal_buffer_3.insert(primary_ranks_array[group][1], 0, 3, 0);
            }
            else
            {
                rc_num = rc_num | rank_cal_buffer_3.insert(primary_ranks_array[group][0], 0, 3, 0);
            }
            rc = mss_ccs_inst_arry_1(i_target, instruction_number, num_idles_buffer_16, num_repeat_buffer_16, data_buffer_20, read_compare_buffer_1, rank_cal_buffer_3, ddr_cal_enable_buffer_1, ccs_end_buffer_1);
            if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs
            FAPI_INF( "+++++++++++++++ Execute CCS array +++++++++++++++");
            rc = mss_execute_ccs_inst_array( i_target, NUM_POLL, 60);
            if(rc) return rc; //Error handling for mss_ccs_inst built into mss_funcs
            for(port = 0; port < 2; port++)
            {
                rc = mss_check_cal_status(i_target, port, group);
                if(rc) return rc;
            }
        }
    }
    return rc; 
}
ReturnCode mss_check_cal_status(
                                Target& i_target, 
                                uint8_t i_port,
                                uint8_t i_group
                               )    {
    ecmdDataBufferBase cal_status_buffer_64(64);
    ecmdDataBufferBase cal_error_buffer_64(64);
    uint8_t cal_status_reg_offset = 0;
    uint8_t cal_error_reg_offset = 0;
    cal_status_reg_offset = 48 + i_group;  
    cal_error_reg_offset = 60 + i_group;
    uint8_t poll_count = 1;

    ReturnCode rc;

    FAPI_INF( "+++++++++++++++ Check Cal Status on port: %d rank group: %d +++++++++++++++", i_port, i_group);
    if(i_port == 0)
    {
        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P0_0x8000C0190301143F, cal_status_buffer_64);
        if(rc) return rc;
        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P0_0x8000C0180301143F, cal_error_buffer_64);
        if(rc) return rc;
    }
    else
    {
        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P1_0x8001C0190301143F, cal_status_buffer_64);
        if(rc) return rc;
        rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P1_0x8001C0180301143F, cal_error_buffer_64);
        if(rc) return rc;
    }
    while((!cal_status_buffer_64.isBitSet(cal_status_reg_offset)) && (!cal_error_buffer_64.isBitSet(cal_error_reg_offset)) && (poll_count <= 5))
    {
        FAPI_INF( "+++++++++++++++ Calibration on port: %d rank group: %d in progress. Poll count: %d +++++++++++++++", i_port, i_group, poll_count);
        poll_count++;
        if(i_port == 0)
        {
            rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P0_0x8000C0190301143F, cal_status_buffer_64);
            if(rc) return rc;
            rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P0_0x8000C0180301143F, cal_error_buffer_64);
            if(rc) return rc;
        }
        else
        {
            rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_STATUS_P1_0x8001C0190301143F, cal_status_buffer_64);
            if(rc) return rc;
            rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_INIT_CAL_ERROR_P1_0x8001C0180301143F, cal_error_buffer_64);
            if(rc) return rc;
        }
    }
    if(cal_error_buffer_64.isBitSet(cal_error_reg_offset))
    {
        //Should it be changed to FAPI_ERR once integrated to xml file. Using FAPI_INF so procedure moves to next group before erroring out.
        FAPI_ERR( "+++++++++++++++ Calibration on port: %d rank group: %d failed! +++++++++++++++", i_port, i_group);
        FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); 
        //FAPI_SET_HWP_ERROR(rc, RC_MSS_INIT_CAL_FAILED);
        if(cal_error_buffer_64.isBitSet(48))
        {
            FAPI_ERR( "+++++++++++++++ Write leveling error occured on port: %d rank group: %d! +++++++++++++++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(50))
        {
            FAPI_ERR( "+++++++++++++++ DQS Alignment error occured on port: %d rank group: %d! +++++++++++++++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(51))
        {
            FAPI_ERR( "+++++++++++++++ RDCLK to SysClk alignment error occured on port: %d rank group: %d! +++++++++++++++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(52))
        {
            FAPI_ERR( "+++++++++++++++ Read centering error occured on port: %d rank group: %d! +++++++++++++++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(53))
        {
            FAPI_ERR( "+++++++++++++++ Write centering error occured on port: %d rank group: %d! +++++++++++++++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(55))
        {
            FAPI_ERR( "+++++++++++++++ Coarse read centering error occured on port: %d rank group: %d! +++++++++++++++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(56))
        {
            FAPI_ERR( "+++++++++++++++ Custom pattern read centering error occured on port: %d rank group: %d! +++++++++++++++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(57))
        {
            FAPI_ERR( "+++++++++++++++ Custom pattern write centering error occured on port: %d rank group: %d! +++++++++++++++", i_port, i_group);
        }
        if(cal_error_buffer_64.isBitSet(58))
        {
            FAPI_ERR( "+++++++++++++++ Digital eye error occured on port: %d rank group: %d! +++++++++++++++", i_port, i_group);
        }
    }
    else
    {
        if(cal_status_buffer_64.isBitSet(cal_status_reg_offset))
        {
            FAPI_INF( "+++++++++++++++ Calibration on port: %d rank group: %d was successful! +++++++++++++++", i_port, i_group);
        }
        else
        {
            FAPI_ERR( "+++++++++++++++ Calibration on port: %d rank group: %d has stalled! +++++++++++++++", i_port, i_group);
            //Should it be changed to FAPI_ERR once integrated to xml file. Using FAPI_INF so procedure moves to next group before erroring out.
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); 
        }
    }
    return rc;
}

} //end extern C

