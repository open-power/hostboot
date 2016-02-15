/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_draminit_training_advanced.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
// $Id: mss_draminit_training_advanced.C,v 1.60 2015/12/08 19:16:51 sglancy Exp $
/* File is created by SARAVANAN SETHURAMAN on Thur 29 Sept 2011. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE :mss_draminit_training_advanced.C
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME : Preetham Hosmane              email:   preeragh@in.ibm.com
// *! BACKUP NAME: Saravanan Sethuraman          email ID:saravanans@in.ibm.com
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
//  1.1    | sasethur |30-Sep-11| Initial draft.
//  1.2    | sasethur |18-Nov-11| Changed function names
//  1.3    | sasethur |01-Dec-11| Added details on Vref shmoo, reg addresses
//  1.4    | sasethur |29-Jan-12| Updated wr&rd vref, removed ecmd workarounds
//  1.5    | sasethur |13-Feb-12| Updated register naming conventions
//  1.6    | sasethur |08-Mar-12| Changed rc_num, multiple changes to drv_imp, Vref funcs
//  1.7    | sasethur |23-Mar-12| Added Receiver Impedance shmoo & changes to mcbist call
//  1.8    | sasethur |30-Mar-12| Removed port from start_mcb, added 15,20,48 receiver imp settings
//  1.9    | sasethur |03-Apr-12| Fixed warning messages
//  1.13   | bellows  |16-Jul-12| Added in Id tag
//  1.14   | bellows  |18-Jul-12| Disabled some checking code
//  1.15   | gollub   |05-Sep-12| Calling mss_unmask_draminit_training_advanced_errors after mss_draminit_training_advanced_cloned
//  1.16   | sasethur |15-Oct-12| Fixed FW review comments and modified function based on new attributes, added slew function
//  1.17   | sasethur |17-Oct-12| Updated index bound checks
//  1.18   | sasethur |17-Oct-12| Removed Hardcoding of Shmoo parameter value
//  1.19   | sasethur |26-Oct-12| Updated fapi::ReturnCode, const Target& and removed fapi::RC_SUCCSESS as per FW comments
//  1.20   | bellows  |13-Nov-12| Updated for new SI attributes
//  1.21   | sasethur |11-Nov-12| Updated for new SI attribute change, fw review comments
//  1.22   | sasethur |07-Dec-12| Updated for FW review comments - multiple changes
//  1.23   | sasethur |14-Dec-12| Updated for FW review comments
//  1.24   | sasethur |17-Jan-13| Updated for mss_mcbist_common.C include file
//  1.25   | abhijsau |31-Jan-13| Removed  mss_mcbist_common.C include file , needs to be included while compiling
//  1.26   | abhijsau |06-Mar-13| Fixed fw comment
//  1.27   | sasethur |09-Apr-13| Updated for port in parallel and pass shmoo param
//  1.28   | sasethur |22-Apr-13| Fixed fw comment
//  1.29   | sasethur |23-Apr-13| Fixed fw comment
//  1.30   | sasethur |24-Apr-13| Fixed fw comment
//  1.31   | sasethur |10-May-13| Added user input for test type, pattern from wrapper
//  1.32   | sasethur |04-Jun-13| Fixed for PortD cnfg, vref print for min setup, hold, fixed rdvref print, added set/reset mcbist attr
//  1.33   | sasethur |12-Jun-13| Updated mcbist setup attribute
//  1.34   | sasethur |20-Jun-13| Fixed read_vref print, setup attribute
//  1.35   | sasethur |08-Aug-13| Fixed fw comment
//  1.36   | sasethur |23-Aug-13| Ability to run MCBIST is enabled.
//  1.37   | sasethur |04-Sep-13| Fixed fw review comment
//  1.38   | bellows  |19-SEP-13| fixed possible buffer overrun found by stradale
//  1.39   | abhijsau |17-OCT-13| fixed a logical bug
//  1.40   | abhijsau |17-DEC-13| added creation and deletion of schmoo object
//  1.41   | abhijsau |16-JAN-14| removed EFF_DIMM_TYPE attribute
//  1.42   | mjjones  |17-Jan-14| Fixed layout and error handling for RAS Review
//  1.43   | jdsloat  |10-MAR-14| Edited comments
//  1.44   |preeragh  |06-NOV-14| Added Sanity checks for wr_vref and rd_vref only at nominal and disabled any other
//  1.45   |sglancy   |09-FEB-14| Responded to FW comments
//  1.46   |preeragh  |22-Jun-14| DDR4 Enhancements and Optimizations
//  1.47   |preeragh  |22-Jul-14| 64 Bit compile Fix
//  1.48   |preeragh  |19-Aug-14| Fix FW Review Comments
//  1.49   |eliner    |27-Aug-15| Fixing Index Overflow Bug
//  1.50   |eliner    |27-Aug-15| Fixing Index Overflow Bug
//  1.51   |eliner    |07-Oct-15| PDA Write Back
//  1.51   |preeragh  |21-Oct-15| Fix V-Ref Range 0-50
//  1.53   |janssens  |21-Oct-15| 64 Bit compile Fix
//  1.54   |sglancy   |10-Oct-15| Changed attribute names
//  1.56   |preeragh  |12-Nov-15| V-ref CAL_CONTROL options
//  1.57   |preeragh  |13-Nov-15| Mask MCBIT_DONE bit FIR before Schmoos
//  1.58   |dcrowell  |13-Nov-15| Change allocation of generic_shmoo object
//  1.59   |preeragh  |18-Nov-15| Update Nibble PDA while PDA_Storage
// This procedure Schmoo's DRV_IMP, SLEW, VREF (DDR, CEN), RCV_IMP based on attribute from effective config procedure
// DQ & DQS Driver impedance, Slew rate, WR_Vref shmoo would call only write_eye shmoo for margin calculation
// DQ & DQS VREF (rd_vref), RCV_IMP shmoo would call rd_eye for margin calculation
// Internal Vref controlled by this function & external vref

// Not supported
// DDR4, DIMM Types
//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------

#include <fapi.H>

//----------------------------------------------------------------------
//Centaur functions
//----------------------------------------------------------------------
#include <mss_termination_control.H>
#include "mss_mcbist.H"
#include <mss_shmoo_common.H>
#include <mss_generic_shmoo.H>
#include <mss_draminit_training_advanced.H>
#include <mss_unmask_errors.H>
#include <mss_mrs6_DDR4.H>
#include <mss_ddr4_pda.H>
#include <vector>

const uint32_t MASK = 1;
const uint32_t MAX_DIMM =2;

enum shmoo_param
{
    PARAM_NONE = 0x00,
    DELAY_REG = 0x01,
    DRV_IMP = 0x02,
    SLEW_RATE = 0x04,
    WR_VREF = 0x08,
    RD_VREF = 0x10,
    RCV_IMP = 0x20
};


extern "C"
{

    using namespace fapi;

    fapi::ReturnCode mss_draminit_training_advanced_cloned(const fapi::Target & i_target_mba);

    fapi::ReturnCode drv_imped_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
                                     shmoo_type_t i_shmoo_type_valid);

    fapi::ReturnCode slew_rate_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
                                     shmoo_type_t i_shmoo_type_valid);

    fapi::ReturnCode wr_vref_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
                                   shmoo_type_t i_shmoo_type_valid);

    fapi::ReturnCode wr_vref_shmoo_ddr4(const fapi::Target & i_target_mba);
    fapi::ReturnCode wr_vref_shmoo_ddr4_bin(const fapi::Target & i_target_mba);
    fapi::ReturnCode rd_vref_shmoo_ddr4(const fapi::Target & i_target_mba);

    fapi::ReturnCode rd_vref_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
                                   shmoo_type_t i_shmoo_type_valid);

    fapi::ReturnCode rcv_imp_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
                                   shmoo_type_t i_shmoo_type_valid);

    fapi::ReturnCode delay_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
                                 shmoo_type_t i_shmoo_type_valid,
                                 uint32_t *o_left_margin, uint32_t *o_right_margin,
                                 uint32_t i_shmoo_param);
    fapi::ReturnCode delay_shmoo_ddr4(const fapi::Target & i_target_mba, uint8_t i_port,
                                      shmoo_type_t i_shmoo_type_valid,
                                      uint32_t *o_left_margin, uint32_t *o_right_margin,
                                      uint32_t i_shmoo_param,uint32_t pda_nibble_table[2][2][4][16][2]);

    fapi::ReturnCode delay_shmoo_ddr4_pda(const fapi::Target & i_target_mba, uint8_t i_port,
                                          shmoo_type_t i_shmoo_type_valid,
                                          uint32_t *o_left_margin, uint32_t *o_right_margin,
                                          uint32_t i_shmoo_param,uint32_t pda_nibble_table[2][2][4][16][2]);

    void find_best_margin(shmoo_param i_shmoo_param_valid,uint32_t i_left[],
                          uint32_t i_right[], const uint8_t l_max,
                          uint32_t i_param_nom, uint8_t& o_index);

    fapi::ReturnCode set_attribute(const fapi::Target & i_target_mba);

    fapi::ReturnCode reset_attribute(const fapi::Target & i_target_mba);


    //-----------------------------------------------------------------------------------
    //Function name: mss_draminit_training_advanced()
    //Description: This function varies driver impedance, receiver impedance, slew, wr & rd vref
    //based on attribute definition and runs either mcbist/delay shmoo based on attribute
    //Also calls unmask function mss_unmask_draminit_training_advanced_errors()
    //Input : const fapi::Target MBA, i_pattern = pattern selection during mcbist @ lab,
    //	l_test type  = test type selection during mcbist @ lab
    //	Default vlaues are Zero
    //-----------------------------------------------------------------------------------

    fapi::ReturnCode mss_draminit_training_advanced(const fapi::Target & i_target_mba)
    {
        // const fapi::Target is centaur.mba
        fapi::ReturnCode rc;
        //FAPI_INF(" pattern bit is %d and test_type_bit is %d");
        rc = mss_draminit_training_advanced_cloned(i_target_mba);
        if (rc)
        {
            FAPI_ERR("Advanced DRAM Init training procedure is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
        }

        // If mss_unmask_draminit_training_advanced_errors gets it's own bad rc,
        // it will commit the passed in rc (if non-zero), and return it's own bad rc.
        // Else if mss_unmask_draminit_training_advanced_errors runs clean,
        // it will just return the passed in rc.

        rc = mss_unmask_draminit_training_advanced_errors(i_target_mba, rc);
        if (rc)
        {
            FAPI_ERR("Unmask Function is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }
        return rc;
    }

}
//end of extern C

//-----------------------------------------------------------------------------------
// Function name: mss_draminit_training_advanced_cloned()
// Description: This function varies driver impedance, receiver impedance, slew, wr & rd vref
// based on attribute definition and runs either mcbist/delay shmoo based on attribute
// Input : const fapi::Target MBA
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//-----------------------------------------------------------------------------------
fapi::ReturnCode mss_draminit_training_advanced_cloned(const fapi::Target & i_target_mba)
{
    //const fapi::Target is centaur.mba
    fapi::ReturnCode rc;

    FAPI_INF("+++++++ Executing mss_draminit_training_advanced +++++++");

    // Define attribute variables
    uint32_t l_attr_mss_freq_u32 = 0;
    uint32_t l_attr_mss_volt_u32 = 0;
    uint8_t l_num_drops_per_port_u8 = 2;
    uint8_t l_num_ranks_per_dimm_u8array[MAX_PORT][MAX_DIMM] = {{0}};
    uint8_t l_port = 0;
    uint32_t l_left_margin=0;
    uint32_t l_right_margin=0;
    uint32_t l_shmoo_param=0;
    uint8_t l_dram_type=0;
    uint8_t bin_pda=0;
    uint8_t vref_cal_control = 0;
    uint8_t temp_cal_control = 0;
    uint32_t int32_cal_control[2] = {0};
    uint64_t int64_cal_control = 0;


    // Define local variables
    uint8_t l_shmoo_type_valid_t=0;
    uint8_t l_shmoo_param_valid_t=0;
    enum dram_type { EMPTY = 0, DDR3 = 1, DDR4 = 2};
    //const fapi::Target is centaur
    fapi::Target l_target_centaur;
    rc = fapiGetParentChip(i_target_mba, l_target_centaur);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_u32);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_attr_mss_volt_u32);
    if(rc) return rc;
    //Preet Add MSS_CAL control here
    rc = FAPI_ATTR_GET(ATTR_MSS_VREF_CAL_CNTL, &l_target_centaur, vref_cal_control);
    if(rc) return rc;
    FAPI_INF("+++++++++++++++++++++++++++++ - DDR4 - CAL Control - %d +++++++++++++++++++++++++++++++++++++++++++++",vref_cal_control);


    //const fapi::Target is centaur.mba
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target_mba, l_num_drops_per_port_u8);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm_u8array);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target_mba, l_dram_type);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MCBIST_USER_BANK, &i_target_mba, bin_pda);
    if(rc) return rc;

    if ((vref_cal_control == 0) && (l_dram_type == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4)&& (bin_pda != 3))
    {
        FAPI_INF("+++++++++++++++++++++++++++++ - DDR4 - Skipping - V-Ref CAL Control +++++++++++++++++++++++++++++++++++++++++++++");
        int32_cal_control[0] = 37;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_TEST_TYPE, &i_target_mba, int32_cal_control[0]);
        if(rc) return rc;

        rc = wr_vref_shmoo_ddr4_bin(i_target_mba);
        if (rc)
        {
            FAPI_ERR("Write Vref Schmoo Function is Failed rc = 0x%08X (creator = %d)",
                     uint32_t(rc), rc.getCreator());
            return rc;
        }
        return rc;
    }

    else if ((vref_cal_control != 0) && (l_dram_type == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4) && (bin_pda != 3))
    {
        FAPI_INF("+++++++++++++++++++++++++++++ - DDR4 - CAL Control +++++++++++++++++++++++++++++++++++++++++++++");

        temp_cal_control = 8;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_PARAM_VALID, &i_target_mba, temp_cal_control);
        if(rc) return rc;
        temp_cal_control = 6;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_MODE, &i_target_mba, temp_cal_control);
        if(rc) return rc;
        temp_cal_control = 1;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_USER_BANK, &i_target_mba, temp_cal_control);
        if(rc) return rc;
        temp_cal_control = 2;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, temp_cal_control);
        if(rc) return rc;
        l_shmoo_param_valid_t = 1;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_RANK, &i_target_mba, l_shmoo_param_valid_t);
        if(rc) return rc;
        l_shmoo_param_valid_t = 1;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_ADDR_MODE, &i_target_mba, l_shmoo_param_valid_t);
        if(rc) return rc;
        int32_cal_control[0] = 0xFFFFFFFF;
        int32_cal_control[1] = 0xFFFFFFFF;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_VREF_SCHMOO, &i_target_mba, int32_cal_control);
        if(rc) return rc;
        int32_cal_control[0] = 37;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_TEST_TYPE, &i_target_mba, int32_cal_control[0]);
        if(rc) return rc;
        int64_cal_control = 0x0000000000000000ull;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_START_ADDR, &i_target_mba, int64_cal_control);
        if(rc) return rc;
        int64_cal_control = 0x0000001fc0000000ull;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_END_ADDR, &i_target_mba, int64_cal_control);
        if(rc) return rc;
    }

    rc = FAPI_ATTR_GET(ATTR_MCBIST_USER_BANK, &i_target_mba, bin_pda);
    if(rc) return rc;


    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    FAPI_INF("freq = %d on %s.", l_attr_mss_freq_u32, l_target_centaur.toEcmdString());
    FAPI_INF("volt = %d on %s.", l_attr_mss_volt_u32, l_target_centaur.toEcmdString());
    FAPI_INF("num_drops_per_port = %d on %s.", l_num_drops_per_port_u8, i_target_mba.toEcmdString());
    FAPI_INF("num_ranks_per_dimm = [%02d][%02d][%02d][%02d]",
             l_num_ranks_per_dimm_u8array[0][0],
             l_num_ranks_per_dimm_u8array[0][1],
             l_num_ranks_per_dimm_u8array[1][0],
             l_num_ranks_per_dimm_u8array[1][1]);


    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, l_shmoo_type_valid_t);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_PARAM_VALID, &i_target_mba, l_shmoo_param_valid_t);
    if(rc) return rc;

    shmoo_type_t l_shmoo_type_valid;
    shmoo_param l_shmoo_param_valid;

    l_shmoo_type_valid=(shmoo_type_t)l_shmoo_type_valid_t;
    l_shmoo_param_valid=(shmoo_param)l_shmoo_param_valid_t;
    FAPI_INF("+++++++++++++++++++++++++ Read Schmoo Attributes ++++++++++++++++++++++++++");
    FAPI_INF("Schmoo param valid = 0x%x on %s", l_shmoo_param_valid, i_target_mba.toEcmdString());
    FAPI_INF("Schmoo test valid = 0x%x on %s", l_shmoo_type_valid, i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    //Check for Shmoo Parameter, if anyof them is enabled then go into the loop else the procedure exit

    if ((l_num_ranks_per_dimm_u8array[0][0] > 0) ||
            (l_num_ranks_per_dimm_u8array[0][1] > 0) ||
            (l_num_ranks_per_dimm_u8array[1][0] > 0) ||
            (l_num_ranks_per_dimm_u8array[1][1] > 0))
    {
        if ((l_shmoo_param_valid != PARAM_NONE) ||
                (l_shmoo_type_valid != TEST_NONE))
        {
            if ((l_shmoo_param_valid & DRV_IMP) != 0)
            {
                rc = drv_imped_shmoo(i_target_mba, l_port, l_shmoo_type_valid);
                if (rc)
                {
                    FAPI_ERR("Driver Impedance Schmoo function is Failed rc = 0x%08X (creator = %d)",
                             uint32_t(rc), rc.getCreator());
                    return rc;
                }
            }
            if ((l_shmoo_param_valid & SLEW_RATE) != 0)
            {
                rc = slew_rate_shmoo(i_target_mba, l_port, l_shmoo_type_valid);
                if (rc)
                {
                    FAPI_ERR("Slew Rate Schmoo Function is Failed rc = 0x%08X (creator = %d)",
                             uint32_t(rc), rc.getCreator());
                    return rc;
                }
            }
            if ((l_shmoo_param_valid & WR_VREF) != 0)
            {
                if(l_dram_type==DDR3) {
                    rc = wr_vref_shmoo(i_target_mba, l_port, l_shmoo_type_valid);
                    if (rc)
                    {
                        FAPI_ERR("Write Vref Schmoo Function is Failed rc = 0x%08X (creator = %d)",
                                 uint32_t(rc), rc.getCreator());
                        return rc;
                    }
                }
                else {
                    if(bin_pda == 1)
                    {
                        FAPI_INF("************* Bin - PDA - Vref_Schmoo **************");

                        rc = wr_vref_shmoo_ddr4_bin(i_target_mba);
                        if (rc)
                        {
                            FAPI_ERR("Write Vref Schmoo Function is Failed rc = 0x%08X (creator = %d)",
                                     uint32_t(rc), rc.getCreator());
                            return rc;
                        }
                    }
                    else
                    {
                        rc = wr_vref_shmoo_ddr4(i_target_mba);
                        if (rc)
                        {
                            FAPI_ERR("Write Vref Schmoo Function is Failed rc = 0x%08X (creator = %d)",
                                     uint32_t(rc), rc.getCreator());
                            return rc;
                        }
                    }
                }
            }
            if ((l_shmoo_param_valid & RD_VREF) != 0)
            {
                if(l_dram_type==DDR3) {
                    rc = rd_vref_shmoo(i_target_mba, l_port, l_shmoo_type_valid);
                    if (rc)
                    {
                        FAPI_ERR("Read Vref Schmoo Function is Failed rc = 0x%08X (creator = %d)",
                                 uint32_t(rc), rc.getCreator());
                        return rc;
                    }
                }
                else
                {
                    rc = rd_vref_shmoo_ddr4(i_target_mba);
                    if (rc)
                    {
                        FAPI_ERR("rd_vref_shmoo_ddr4 Function is Failed rc = 0x%08X (creator = %d)",
                                 uint32_t(rc), rc.getCreator());
                        return rc;
                    }
                }
            }
            if ((l_shmoo_param_valid & RCV_IMP) != 0)
            {
                rc = rcv_imp_shmoo(i_target_mba, l_port, l_shmoo_type_valid);
                if (rc)
                {
                    FAPI_ERR("Receiver Impedance Schmoo Function is Failed rc = 0x%08X (creator = %d)",
                             uint32_t(rc), rc.getCreator());
                    return rc;
                }
            }
            if (((l_shmoo_param_valid == PARAM_NONE)))
            {
                rc = delay_shmoo(i_target_mba, l_port, l_shmoo_type_valid,
                                 &l_left_margin, &l_right_margin,
                                 l_shmoo_param);
                if (rc)
                {
                    FAPI_ERR("Delay Schmoo Function is Failed rc = 0x%08X (creator = %d)",
                             uint32_t(rc), rc.getCreator());
                    return rc;
                }
            }
        }
    }
    return rc;
}

//-------------------------------------------------------------------------------
// Function name: drv_imped_shmoo()
// This function varies the driver impedance in the nominal mode
// for both dq/dqs & adr/cmd signals - DQ_DQS<24,30,34,40>,CMD_CNTL<15,20,30,40>
// if there is any mcbist failure, that will be reported to put_bad_bits function
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//-------------------------------------------------------------------------------

fapi::ReturnCode drv_imped_shmoo(const fapi::Target & i_target_mba,
                                 uint8_t i_port,
                                 shmoo_type_t i_shmoo_type_valid)
{
    fapi::ReturnCode rc;
    uint8_t l_drv_imp_dq_dqs[MAX_PORT] = {0};
    uint8_t l_drv_imp_dq_dqs_nom[MAX_PORT] = {0};
    //uint8_t l_drv_imp_dq_dqs_new[MAX_PORT] = {0};
    uint8_t index=0;
    uint8_t l_slew_rate_dq_dqs[MAX_PORT] = {0};
    uint8_t l_slew_rate_dq_dqs_schmoo[MAX_PORT] = {0};
    uint32_t l_drv_imp_dq_dqs_schmoo[MAX_PORT] = {0};
    uint8_t l_drv_imp_dq_dqs_nom_fc = 0;
    uint8_t l_drv_imp_dq_dqs_in = 0;
    //Temporary
    i_shmoo_type_valid = WR_EYE;  //Hard coded, since no other schmoo is applicable for this parameter
    uint32_t l_left_margin_drv_imp_array[MAX_DRV_IMP] = {0};
    uint32_t l_right_margin_drv_imp_array[MAX_DRV_IMP] = {0};
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint8_t count = 0;
    uint8_t shmoo_param_count = 0;
    uint8_t l_slew_type = 0; // Hard coded since this procedure will touch only DQ_DQS and not address

    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, l_drv_imp_dq_dqs_nom);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, l_slew_rate_dq_dqs);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, &i_target_mba, l_drv_imp_dq_dqs_schmoo);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO, &i_target_mba, l_slew_rate_dq_dqs_schmoo);
    if (rc) return rc;

    FAPI_INF("+++++++++++++++++Read DRIVER IMP Attributes values++++++++++++++++");
    FAPI_INF("CEN_DRV_IMP_DQ_DQS[%d]  = [%02d] Ohms, on %s",
             i_port,
             l_drv_imp_dq_dqs_nom[i_port],
             i_target_mba.toEcmdString());
    FAPI_INF("CEN_DRV_IMP_DQ_DQS_SCHMOO[0]  = [0x%x], CEN_DRV_IMP_DQ_DQS_SCHMOO[1]  = [0x%x] on %s",
             l_drv_imp_dq_dqs_schmoo[0],
             l_drv_imp_dq_dqs_schmoo[1],
             i_target_mba.toEcmdString());
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS[0] = [%02d]V/ns , CEN_SLEW_RATE_DQ_DQS[1] = [%02d]V/ns on %s",
             l_slew_rate_dq_dqs[0],
             l_slew_rate_dq_dqs[1],
             i_target_mba.toEcmdString());
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS_SCHMOO[0] = [0x%x], CEN_SLEW_RATE_DQ_DQS_SCHMOO[1] = [0x%x] on %s",
             l_slew_rate_dq_dqs_schmoo[0],
             l_slew_rate_dq_dqs_schmoo[1],
             i_target_mba.toEcmdString());
    FAPI_INF("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    if(l_drv_imp_dq_dqs_schmoo[i_port] == 0) //Check for any of the bits enabled in the shmoo
    {
        FAPI_INF("DRIVER IMP Shmoo set to FAST Mode and won't do anything");
    }
    else
    {
        for (index = 0; index < MAX_DRV_IMP; index += 1)
        {
            if (l_drv_imp_dq_dqs_schmoo[i_port] & MASK)
            {
                l_drv_imp_dq_dqs[i_port] = drv_imp_array[index];
                FAPI_INF("Current Driver Impedance Value = %d Ohms",
                         drv_imp_array[index]);
                FAPI_INF("Configuring Driver Impedance Registers:");
                rc = config_drv_imp(i_target_mba, i_port,
                                    l_drv_imp_dq_dqs[i_port]);
                if (rc) return rc;
                l_drv_imp_dq_dqs_in = l_drv_imp_dq_dqs[i_port];
                FAPI_INF("Configuring Slew Rate Registers:");
                rc = config_slew_rate(i_target_mba, i_port, l_slew_type,
                                      l_drv_imp_dq_dqs[i_port],
                                      l_slew_rate_dq_dqs[i_port]);
                if (rc) return rc;
                FAPI_INF("Calling Shmoo for finding Timing Margin:");
                if (shmoo_param_count)
                {
                    rc = set_attribute(i_target_mba);
                    if (rc) return rc;
                }
                rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid,
                                 &l_left_margin, &l_right_margin,
                                 l_drv_imp_dq_dqs_in);
                if (rc) return rc;
                l_left_margin_drv_imp_array[index] = l_left_margin;
                l_right_margin_drv_imp_array[index] = l_right_margin;
                shmoo_param_count++;
            }
            else
            {
                l_left_margin_drv_imp_array[index] = 0;
                l_right_margin_drv_imp_array[index] = 0;
            }
            l_drv_imp_dq_dqs_schmoo[i_port] = (l_drv_imp_dq_dqs_schmoo[i_port] >> 1);
        }
        l_drv_imp_dq_dqs_nom_fc = l_drv_imp_dq_dqs_nom[i_port];
        find_best_margin(DRV_IMP, l_left_margin_drv_imp_array,
                         l_right_margin_drv_imp_array, MAX_DRV_IMP,
                         l_drv_imp_dq_dqs_nom_fc, count);

        if (count >= MAX_DRV_IMP)
        {
            FAPI_ERR("Driver Imp new input(%d) out of bounds, (>= %d)", count,
                     MAX_DRV_IMP);
            const uint8_t & COUNT_DATA = count;
            FAPI_SET_HWP_ERROR(rc, RC_DRV_IMPED_SHMOO_INVALID_MARGIN_DATA);
            return rc;
        }
        else
        {
            FAPI_INF("Restoring the nominal values!");
            rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba,
                               l_drv_imp_dq_dqs_nom);
            if (rc) return rc;
            rc = config_drv_imp(i_target_mba, i_port,
                                l_drv_imp_dq_dqs_nom[i_port]);
            if (rc) return rc;
            rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba,
                               l_slew_rate_dq_dqs);
            if (rc) return rc;
            rc = config_slew_rate(i_target_mba, i_port, l_slew_type,
                                  l_drv_imp_dq_dqs_nom[i_port],
                                  l_slew_rate_dq_dqs[i_port]);
            if (rc) return rc;
        }
        FAPI_INF("Restoring mcbist setup attribute...");
        rc = reset_attribute(i_target_mba);
        if (rc) return rc;
        FAPI_INF("++++ Driver impedance shmoo function executed successfully ++++");
    }
    return rc;
}

//-----------------------------------------------------------------------------------------
// Function name: slew_rate_shmoo()
// This function varies the slew rate of the data & adr signals (fast/slow)
// calls the write eye shmoo which internally calls mcbist function to see for failure
// if there is any mcbist failure, this function will report to baddqpins function
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//-----------------------------------------------------------------------------------------

fapi::ReturnCode slew_rate_shmoo(const fapi::Target & i_target_mba,
                                 uint8_t i_port,
                                 shmoo_type_t i_shmoo_type_valid)
{
    fapi::ReturnCode rc;
    uint8_t l_slew_rate_dq_dqs[MAX_PORT] = {0};
    uint8_t l_slew_rate_dq_dqs_nom[MAX_PORT] = {0};
    uint8_t l_slew_rate_dq_dqs_nom_fc = 0;
    uint8_t l_slew_rate_dq_dqs_in = 0;
    uint32_t l_slew_rate_dq_dqs_schmoo[MAX_PORT] = {0};
    uint8_t l_drv_imp_dq_dqs_nom[MAX_PORT] = {0};
    i_shmoo_type_valid = WR_EYE; // Hard coded - Other shmoo type is not valid - Temporary

    uint8_t index = 0;
    uint8_t count = 0;
    uint8_t shmoo_param_count = 0;
    uint32_t l_left_margin_slew_array[MAX_NUM_SLEW_RATES] = {0};
    uint32_t l_right_margin_slew_array[MAX_NUM_SLEW_RATES] = {0};
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint8_t l_slew_type = 0; // Hard coded since this procedure will touch only DQ_DQS and not address

    //Read Attributes - DRV IMP, SLEW, SLEW RATES values to be Schmoo'ed
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, l_drv_imp_dq_dqs_nom);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, l_slew_rate_dq_dqs_nom);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, &i_target_mba, l_slew_rate_dq_dqs_schmoo);
    if (rc) return rc;

    FAPI_INF("+++++++++++++++++Read Slew Shmoo Attributes values+++++++++++++++");
    FAPI_INF("CEN_DRV_IMP_DQ_DQS[0]  = [%02d] Ohms, CEN_DRV_IMP_DQ_DQS[1]  = [%02d] Ohms on %s",
             l_drv_imp_dq_dqs_nom[0],
             l_drv_imp_dq_dqs_nom[1],
             i_target_mba.toEcmdString());
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS[0] = [%02d]V/ns , CEN_SLEW_RATE_DQ_DQS[1] = [%02d]V/ns on %s",
             l_slew_rate_dq_dqs_nom[0],
             l_slew_rate_dq_dqs_nom[1],
             i_target_mba.toEcmdString());
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS_SCHMOO[0] = [0x%x], CEN_SLEW_RATE_DQ_DQS_SCHMOO[1] = [0x%x] on %s",
             l_slew_rate_dq_dqs_schmoo[0],
             l_slew_rate_dq_dqs_schmoo[1],
             i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    if(l_slew_rate_dq_dqs_schmoo == 0) //Check for any of the bits enabled in the shmoo
    {
        FAPI_INF("Slew Rate Shmoo set to FAST Mode and won't do anything");
    }
    else
    {
        for (index = 0; index < MAX_NUM_SLEW_RATES; index += 1)
        {
            if (l_slew_rate_dq_dqs_schmoo[i_port] & MASK)
            {
                l_slew_rate_dq_dqs[i_port] = slew_rate_array[index];
                FAPI_INF("Current Slew rate value is %d V/ns",
                         slew_rate_array[index]);
                FAPI_INF("Configuring Slew registers:");
                rc = config_slew_rate(i_target_mba, i_port, l_slew_type,
                                      l_drv_imp_dq_dqs_nom[i_port],
                                      l_slew_rate_dq_dqs[i_port]);
                if (rc) return rc;
                l_slew_rate_dq_dqs_in = l_slew_rate_dq_dqs[i_port];
                FAPI_INF("Calling Shmoo for finding Timing Margin:");
                if (shmoo_param_count)
                {
                    rc = set_attribute(i_target_mba);
                    if (rc) return rc;
                }
                rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid,
                                 &l_left_margin, &l_right_margin,
                                 l_slew_rate_dq_dqs_in);
                if (rc) return rc;
                l_left_margin_slew_array[index] = l_left_margin;
                l_right_margin_slew_array[index] = l_right_margin;
                shmoo_param_count++;
            }
            else
            {
                l_left_margin_slew_array[index] = 0;
                l_right_margin_slew_array[index] = 0;
            }
            l_slew_rate_dq_dqs_schmoo[i_port]
                = (l_slew_rate_dq_dqs_schmoo[i_port] >> 1);
        }
        l_slew_rate_dq_dqs_nom_fc = l_slew_rate_dq_dqs_nom[i_port];
        find_best_margin(SLEW_RATE, l_left_margin_slew_array,
                         l_right_margin_slew_array, MAX_NUM_SLEW_RATES,
                         l_slew_rate_dq_dqs_nom_fc, count);
        if (count >= MAX_NUM_SLEW_RATES)
        {
            FAPI_ERR("Driver Imp new input(%d) out of bounds, (>= %d)", count,
                     MAX_NUM_SLEW_RATES);
            const uint8_t & COUNT_DATA = count;
            FAPI_SET_HWP_ERROR(rc, RC_SLEW_RATE_SHMOO_INVALID_MARGIN_DATA);
            return rc;
        }
        else
        {
            FAPI_INF("Restoring the nominal values!");
            rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba,
                               l_drv_imp_dq_dqs_nom);
            if (rc) return rc;
            rc = config_drv_imp(i_target_mba, i_port,
                                l_drv_imp_dq_dqs_nom[i_port]);
            if (rc) return rc;
            rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba,
                               l_slew_rate_dq_dqs_nom);
            if (rc) return rc;
            rc = config_slew_rate(i_target_mba, i_port, l_slew_type,
                                  l_drv_imp_dq_dqs_nom[i_port],
                                  l_slew_rate_dq_dqs_nom[i_port]);
            if (rc) return rc;
        }
        FAPI_INF("Restoring mcbist setup attribute...");
        rc = reset_attribute(i_target_mba);
        if (rc) return rc;
        FAPI_INF("++++ Slew Rate shmoo function executed successfully ++++");
    }
    return rc;
}

//----------------------------------------------------------------------------------------------
// Function name: wr_vref_shmoo()
// This function varies the DIMM vref using PC_VREF_DRV_CNTL register in 32 steps with vref sign
// Calls mcbist/write eye shmoo function and look for failure, incase of failure
// this function reports bad DQ pins matrix to put bad bits function
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//----------------------------------------------------------------------------------------------

fapi::ReturnCode wr_vref_shmoo(const fapi::Target & i_target_mba,
                               uint8_t i_port,
                               shmoo_type_t i_shmoo_type_valid)
{
    fapi::ReturnCode rc;
    uint32_t l_wr_dram_vref[MAX_PORT] = {0};
    uint32_t l_wr_dram_vref_nom[MAX_PORT] = {0};
    uint32_t l_wr_dram_vref_schmoo[MAX_PORT] = {0};
    uint32_t l_wr_dram_vref_nom_fc = 0;
    uint32_t l_wr_dram_vref_in = 0;
    i_shmoo_type_valid = MCBIST;

    uint8_t index = 0;
    uint8_t count = 0;
    //uint8_t shmoo_param_count = 0;
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint32_t l_left_margin_wr_vref_array[MAX_WR_VREF]= {0};
    uint32_t l_right_margin_wr_vref_array[MAX_WR_VREF]= {0};

    //Read the write vref attributes
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR_VREF, &i_target_mba, l_wr_dram_vref_nom);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR_VREF_SCHMOO, &i_target_mba, l_wr_dram_vref_schmoo);
    if (rc) return rc;

    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++ Patch - Preet - WR_VREF - Check Sanity only at 500 +++++++++++++++++++++++++++");
    rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid,
                     &l_left_margin, &l_right_margin,
                     l_wr_dram_vref_in);
    if(rc) return rc;
    FAPI_INF(" Setup and Sanity - Check disabled from now on..... Continuing .....");
    rc = set_attribute(i_target_mba);
    if (rc) return rc;



    i_shmoo_type_valid = WR_EYE;

    FAPI_INF("+++++++++++++++++WRITE DRAM VREF Shmoo Attributes Values+++++++++++++++");
    FAPI_INF("DRAM_WR_VREF[0]  = %d , DRAM_WR_VREF[1]  = %d on %s",
             l_wr_dram_vref_nom[0],
             l_wr_dram_vref_nom[1],
             i_target_mba.toEcmdString());
    FAPI_INF("DRAM_WR_VREF_SCHMOO[0] = [%x],DRAM_WR_VREF_SCHMOO[1] = [%x] on %s",
             l_wr_dram_vref_schmoo[0],
             l_wr_dram_vref_schmoo[1],
             i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");


    if (l_wr_dram_vref_schmoo[i_port] == 0)
    {
        FAPI_INF("FAST Shmoo Mode: This function will not change any Write DRAM VREF settings");
    }
    else
    {
        for (index = 0; index < MAX_WR_VREF; index += 1)
        {
            if (l_wr_dram_vref_schmoo[i_port] & MASK)
            {
                FAPI_INF("Current Vref multiplier value is %d",
                         wr_vref_array[index]);
                l_wr_dram_vref[i_port] = wr_vref_array[index];
                rc = config_wr_dram_vref(i_target_mba, i_port,
                                         l_wr_dram_vref[i_port]);
                if (rc) return rc;
                l_wr_dram_vref_in = l_wr_dram_vref[i_port];
                //FAPI_INF(" Calling Shmoo for finding Timing Margin:");

                rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid,
                                 &l_left_margin, &l_right_margin,
                                 l_wr_dram_vref_in);
                if (rc) return rc;
                l_left_margin_wr_vref_array[index] = l_left_margin;
                l_right_margin_wr_vref_array[index] = l_right_margin;

                FAPI_INF("Wr Vref = %d ; Min Setup time = %d; Min Hold time = %d",
                         wr_vref_array[index],
                         l_left_margin_wr_vref_array[index],
                         l_right_margin_wr_vref_array[index]);
            }
            else
            {
                l_left_margin_wr_vref_array[index] = 0;
                l_right_margin_wr_vref_array[index] = 0;
            }
            l_wr_dram_vref_schmoo[i_port] = (l_wr_dram_vref_schmoo[i_port] >> 1);
            //FAPI_INF("Wr Vref = %d ; Min Setup time = %d; Min Hold time = %d", wr_vref_array[index],l_left_margin_wr_vref_array[index],  l_right_margin_wr_vref_array[index]);
            //FAPI_INF("Configuring Vref registers_2:, index %d , max value %d, schmoo %x mask %d ", index, MAX_WR_VREF, l_wr_dram_vref_schmoo[i_port], MASK);
        }
        l_wr_dram_vref_nom_fc = l_wr_dram_vref_nom[i_port];
        find_best_margin(WR_VREF, l_left_margin_wr_vref_array,
                         l_right_margin_wr_vref_array, MAX_WR_VREF,
                         l_wr_dram_vref_nom_fc, count);
        if (count >= MAX_WR_VREF)
        {
            FAPI_ERR("Write dram vref input(%d) out of bounds, (>= %d)", count,
                     MAX_WR_VREF);
            const uint8_t & COUNT_DATA = count;
            FAPI_SET_HWP_ERROR(rc, RC_WR_VREF_SHMOO_INVALID_MARGIN_DATA);
            return rc;
        }
        else
        {
            //   FAPI_INF("Nominal value will not be changed!- Restoring the original values!");
            FAPI_INF(" Restoring the nominal values!");
            rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_VREF, &i_target_mba,
                               l_wr_dram_vref_nom);
            if (rc) return rc;
            rc = config_wr_dram_vref(i_target_mba, i_port,
                                     l_wr_dram_vref_nom[i_port]);
            if (rc) return rc;
        }
        FAPI_INF("Restoring mcbist setup attribute...");
        rc = reset_attribute(i_target_mba);
        if (rc) return rc;
        FAPI_INF("++++ Write DRAM Vref Shmoo function executed successfully ++++");
    }
    return rc;
}

//////////////////////////////////////////////wr_vref schmoo for ddr4 ////////////////////////////////////////////////////////////
fapi::ReturnCode wr_vref_shmoo_ddr4(const fapi::Target & i_target_mba)
{
    fapi::ReturnCode rc;
    uint8_t max_port = 2;
    uint8_t max_ddr4_vrefs1 = 51;
    shmoo_type_t i_shmoo_type_valid = MCBIST; // Hard coded - Temporary
    ecmdDataBufferBase l_data_buffer_64(64);
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint8_t l_attr_eff_dimm_type_u8 = 0;
    uint8_t vrefdq_train_range[2][2][4];
    uint8_t num_ranks_per_dimm[2][2];
    uint8_t l_MAX_RANKS[2];
    uint32_t rc_num = 0;
    uint8_t l_SCHMOO_NIBBLES=20;
    uint32_t base_percent = 60000;

    uint32_t index_mul_print = 650;
    uint8_t l_attr_schmoo_test_type_u8 = 1;
    uint32_t vref_val_print = 0;
    rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_attr_eff_dimm_type_u8);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, num_ranks_per_dimm);
    if(rc) return rc;
    rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_RANGE, &i_target_mba, vrefdq_train_range);
    if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, l_attr_schmoo_test_type_u8);
    if(rc) return rc;
    if(vrefdq_train_range[0][0][0] == 1)
    {
        base_percent = 45000;
    }

    l_MAX_RANKS[0]=num_ranks_per_dimm[0][0]+num_ranks_per_dimm[0][1];
    l_MAX_RANKS[1]=num_ranks_per_dimm[1][0]+num_ranks_per_dimm[1][1];
    //FAPI_INF("\n ** l_max_rank 0 = %d",l_MAX_RANKS[0]);
    if ( l_attr_eff_dimm_type_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES )
    {
        l_SCHMOO_NIBBLES=20;
    }
    else
    {
        l_SCHMOO_NIBBLES=18;
    }
    FAPI_INF(" +++  l_SCHMOO_NIBBLES = %d +++ ",l_SCHMOO_NIBBLES);
    ///// ddr4 vref //////
    fapi::Target l_target_centaur=i_target_mba;

    uint8_t vrefdq_train_value[2][2][4];
    uint8_t vrefdq_train_enable[2][2][4];
    //uint32_t best_margin[2][8][20];
    //uint32_t best_vref[50][2][8][20];
    //uint32_t best_vref_nibble[2][8][20];
    uint32_t vref_val=0;
    uint32_t pda_nibble_table[2][2][4][16][2];
    uint8_t i=0;
    uint8_t j=0;
    uint8_t k=0;
    uint8_t a=0;
    uint8_t c=0;
    uint8_t l_ranks = 0;
    uint8_t l_vref_num = 0;
    uint8_t i_port=0;

    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++ Patch - WR_VREF - Check Sanity only at 500 ddr4 +++++++++++++++++++++++++++");
    rc = delay_shmoo_ddr4(i_target_mba, i_port, i_shmoo_type_valid,
                          &l_left_margin, &l_right_margin,
                          vref_val,pda_nibble_table);

    if(rc) return rc;
    FAPI_INF(" Setup and Sanity - Check disabled from now on..... Continuing .....");
    rc = set_attribute(i_target_mba);
    if (rc) return rc;



    i_shmoo_type_valid = WR_EYE;
    l_attr_schmoo_test_type_u8 = 2;
    rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, l_attr_schmoo_test_type_u8);
    if(rc) return rc;
    //Initialize all to zero

    for(l_vref_num=0; l_vref_num < max_ddr4_vrefs1; l_vref_num++) {
        vref_val = l_vref_num;
        vref_val_print = base_percent + (l_vref_num * index_mul_print);

        rc = fapiGetScom(i_target_mba,0x03010432,l_data_buffer_64);
        if(rc) return rc;
        rc_num = rc_num | l_data_buffer_64.clearBit(0);
        if(rc_num) return rc;
        rc = fapiPutScom(i_target_mba,0x03010432,l_data_buffer_64);
        if(rc) return rc;
        //system("putscom cen.mba 03010432 0 1 0 -ib -all");
        FAPI_INF("\n After Clearing Refresh");
        for(i=0; i< max_port; i++) {
            for(j=0; j<2; j++) {
                for(k=0; k<4; k++) {

                    vrefdq_train_enable[i][j][k]=0x00;

                }
            }
        }

        rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_RANGE, &i_target_mba, vrefdq_train_range);
        if(rc) return rc;
        rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target_mba, vrefdq_train_enable);
        if(rc) return rc;
        rc = mss_mrs6_DDR4(l_target_centaur);
        if(rc)
        {
            //FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }



        for(a=0; a < max_port; a++) {
            for(l_ranks=0; l_ranks < l_MAX_RANKS[0]; l_ranks++) {
                for(c=0; c<4; c++) {

                    vrefdq_train_value[a][l_ranks][c]=vref_val;

                }
            }
        }

        rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_VALUE, &i_target_mba, vrefdq_train_value);


        rc = mss_mrs6_DDR4(l_target_centaur);
        if(rc)
        {
            //FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }

        FAPI_INF("The Vref value is %d .... The percent voltage bump = %d ",vref_val,vref_val_print);

        for(i=0; i< max_port; i++) {
            for(j=0; j<l_MAX_RANKS[0]; j++) {
                for(k=0; k<4; k++) {

                    vrefdq_train_enable[i][j][k]=0x01;

                }
            }
        }
        rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target_mba, vrefdq_train_enable);
        if(rc) return rc;
        rc = mss_mrs6_DDR4(l_target_centaur);
        if(rc)
        {
            //FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }

        rc = fapiGetScom(i_target_mba,0x03010432,l_data_buffer_64);
        if(rc) return rc;
        rc_num = rc_num | l_data_buffer_64.setBit(0);
        if(rc_num) return rc;
        rc = fapiPutScom(i_target_mba,0x03010432,l_data_buffer_64);
        if(rc) return rc;

        //system("putscom cen.mba 03010432 0 1 1 -ib -all");

        rc = delay_shmoo_ddr4(i_target_mba, i_port, i_shmoo_type_valid,
                              &l_left_margin, &l_right_margin,
                              vref_val,pda_nibble_table);
        if (rc) return rc;

        FAPI_INF("Wr Vref = %d ; Min Setup time = %d; Min Hold time = %d",
                 vref_val_print,
                 l_left_margin,
                 l_right_margin);

        //vref_val=vref_val+1;
    }




    //Read the write vref attributes



    return rc;
}


fapi::ReturnCode wr_vref_shmoo_ddr4_bin(const fapi::Target & i_target_mba)
{
    fapi::ReturnCode rc;
    uint8_t MAX_PORT = 2;
    uint8_t MAX_DIMM = 2;
    //uint8_t max_ddr4_vrefs1 = 52;
    shmoo_type_t i_shmoo_type_valid = MCBIST;
    ecmdDataBufferBase l_data_buffer_64(64);
    ecmdDataBufferBase refresh_reg(64);
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint8_t l_attr_eff_dimm_type_u8 = 0;
    uint8_t vrefdq_train_range[2][2][4];
    uint8_t num_ranks_per_dimm[2][2];
    //uint8_t l_MAX_RANKS[2];
    uint32_t total_val = 0;
    uint32_t last_total = 0;
    uint32_t base_percent = 60000;
    uint32_t pda_nibble_table[2][2][4][16][2];  // Port,Dimm,Rank,Nibble,[2]
    uint32_t best_pda_nibble_table[2][2][4][16][2];
    uint8_t cal_control = 0;
    ///// ddr4 vref //////
    uint8_t vrefdq_train_value[2][2][4];
    uint8_t vrefdq_train_enable[2][2][4];
    uint32_t vref_val=0;
    uint8_t i=0;
    uint8_t j=0;
    uint8_t k=0;
    uint8_t a=0;
    uint8_t c=0;
    uint32_t avg_best_vref = 0;
    uint32_t rc_num = 0;
    uint8_t l_dimm = 0;
    uint8_t i_port=0;
    uint8_t l_vref_mid = 0;
    uint8_t imax = 	39;
    uint8_t imin = 13;
    uint8_t last_known_vref = 0;
    uint8_t l_loop_count = 0;
    uint8_t dram_width = 0;
    vector<PDA_MRS_Storage> pda;
    pda.clear();
    uint32_t index_mul_print = 650;
    uint8_t l_attr_schmoo_test_type_u8 = 1;
    uint32_t vref_val_print = 0;
    uint8_t vpd_wr_vref_value[2] = {0};
    fapi::Target l_target_centaur=i_target_mba;
    fapi::Target l_target_centaur1;
    rc = fapiGetParentChip(i_target_mba, l_target_centaur1);
    if(rc) return rc;

    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, dram_width);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_attr_eff_dimm_type_u8);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target_mba, num_ranks_per_dimm);
    if(rc) return rc;
    rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_RANGE, &i_target_mba, vrefdq_train_range);
    if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, l_attr_schmoo_test_type_u8);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_WRDDR4_VREF, &i_target_mba, vpd_wr_vref_value);
    if(rc) return rc;
    rc = FAPI_ATTR_GET( ATTR_MSS_VREF_CAL_CNTL, &l_target_centaur1, cal_control);
    if(rc) return rc;
    rc = FAPI_ATTR_GET( ATTR_MSS_VREF_CAL_CNTL, &l_target_centaur1, cal_control);
    if(rc) return rc;
    //FAPI_INF("++++++++++++++ATTR_MSS_VREF_CAL_CNTL = %d +++++++++++++++++++++++++++",cal_control);

    if(vrefdq_train_range[0][0][0] == 1)
    {
        base_percent = 45;
    }

    FAPI_INF("Setting MCBIST DONE bit MASK as FW reports FIR bits!...");
    //Workaround MCBIST MASK Bit as FW reports FIR bits --- > SET
    rc = fapiGetScom(i_target_mba, 0x03010614, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.setBit(10);
    if (rc_num)
    {
        FAPI_ERR("Buffer error in function wr_vref_shmoo_ddr4_bin Workaround MCBIST MASK Bit");
        rc.setEcmdError(rc_num);
        return rc;
    }


    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++ WR_VREF - Check Sanity only MCBIST +++++++++++++++++++++++++++");
    rc = delay_shmoo_ddr4_pda(i_target_mba, i_port, i_shmoo_type_valid,
                              &l_left_margin, &l_right_margin,
                              vref_val,pda_nibble_table);

    if(rc) return rc;
    FAPI_INF(" Setup and Sanity - Check disabled from now on..... Continuing .....");
    FAPI_INF(" RUNNING GLANCY'S CODE UPDATES!!!!!!!!!!!!!!");
    rc = set_attribute(i_target_mba);
    if (rc) return rc;

    if (cal_control !=0)
    {
        i_shmoo_type_valid = WR_EYE;
        l_attr_schmoo_test_type_u8 = 2;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, l_attr_schmoo_test_type_u8);
        if(rc) return rc;
        //Initialize all to zero
        /*for(index = 0; index < 50;index++)
        {
        	best_vref[index] = 0;

        }
        */
        //Initialise All to Zero [2][2][4]

        for(k=0; k < MAX_PORT; k++) // port
        {
            for(l_dimm=0; l_dimm < 2; l_dimm++) //Dimm
            {
                for(j=0; j < 4; j++) //Rank
                {
                    for(i=0; i<16; i++) //Nibble
                    {
                        pda_nibble_table[k][l_dimm][j][i][0] = 0;  //  Index 0 Are V-refs
                        pda_nibble_table[k][l_dimm][j][i][1] = 0;   // Index 1 are Total Margin Values
                        best_pda_nibble_table[k][l_dimm][j][i][0] = 0;   //  Index 0 Are V-refs
                        best_pda_nibble_table[k][l_dimm][j][i][1] = 0;    // Index 1 are Total Margin Values
                    }
                }
            }
        }

        while(imax >= imin) {

            if(l_loop_count==0)
                l_vref_mid = imin;
            else
                l_vref_mid = (imax+imin)/2;

            vref_val = l_vref_mid;
            vref_val_print = base_percent + (l_vref_mid * index_mul_print);
            FAPI_INF("The Vref value is = %d; The percent voltage bump = %d ",vref_val,vref_val_print);
            //FAPI_INF("\n Before Clearing Refresh");
            rc = fapiGetScom(i_target_mba,0x03010432,l_data_buffer_64);
            if(rc) return rc;
            l_data_buffer_64.clearBit(0);
            rc = fapiPutScom(i_target_mba,0x03010432,l_data_buffer_64);
            if(rc) return rc;
            //FAPI_INF("\n After Clearing Refresh");

            for(i=0; i<MAX_PORT; i++) {
                for(j=0; j<MAX_DIMM; j++) {
                    for(k=0; k<4; k++) {

                        vrefdq_train_enable[i][j][k]=0x01;

                    }
                }
            }

            rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_RANGE, &i_target_mba, vrefdq_train_range);
            if(rc) return rc;
            rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target_mba, vrefdq_train_enable);
            if(rc) return rc;
            for(a=0; a < MAX_PORT; a++) //Port
            {
                for(l_dimm=0; l_dimm < MAX_DIMM; l_dimm++) //Max dimms
                {
                    for(c=0; c < 4; c++) //Ranks
                    {

                        vrefdq_train_value[a][l_dimm][c]=vref_val;

                    }
                }
            }

            rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_VALUE, &i_target_mba, vrefdq_train_value);
            if(rc) return rc;
            rc = mss_mrs6_DDR4(l_target_centaur);
            if(rc)
            {
                FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                return rc;
            }
            // Call it Twice to Latch (Steve)
            rc = mss_mrs6_DDR4(l_target_centaur);
            if(rc)
            {
                FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                return rc;
            }

            for(i=0; i < MAX_PORT; i++) {
                for(j=0; j<2; j++) {
                    for(k=0; k<4; k++) {

                        vrefdq_train_enable[i][j][k]=0x00;

                    }
                }
            }
            rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target_mba, vrefdq_train_enable);
            if(rc) return rc;
            rc = mss_mrs6_DDR4(l_target_centaur);
            if(rc)
            {
                FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                return rc;
            }

            rc = fapiGetScom(i_target_mba,0x03010432,l_data_buffer_64);
            if(rc) return rc;
            l_data_buffer_64.setBit(0);
            rc = fapiPutScom(i_target_mba,0x03010432,l_data_buffer_64);
            if(rc) return rc;


            rc = delay_shmoo_ddr4_pda(i_target_mba, i_port, i_shmoo_type_valid,&l_left_margin,&l_right_margin,vref_val,pda_nibble_table);
            if (rc) return rc;

            total_val = l_right_margin+l_left_margin;
            FAPI_INF("Preet2 - %d ; Wr Vref = %d ; Min Setup time = %d; Min Hold time = %d and Total = %d",vref_val,vref_val_print,l_left_margin,l_right_margin,total_val);

            if(total_val > last_total)
            {
                last_known_vref = vref_val;
                last_total = total_val;
                if(l_loop_count != 0)
                    imin = l_vref_mid+1;
            }
            else
            {
                imax = l_vref_mid - 1;
            }
            l_loop_count ++;
            for(int i_port=0; i_port < MAX_PORT; i_port++) {
                for(l_dimm=0; l_dimm < 2; l_dimm++) {
                    for(int i_rank=0; i_rank < num_ranks_per_dimm[i_port][l_dimm]; i_rank++) {
                        for(int i_nibble=0; i_nibble < 16; i_nibble++) {
                            if (best_pda_nibble_table[i_port][l_dimm][i_rank][i_nibble][1] < pda_nibble_table[i_port][l_dimm][i_rank][i_nibble][1])
                            {
                                best_pda_nibble_table[i_port][l_dimm][i_rank][i_nibble][1] = pda_nibble_table[i_port][l_dimm][i_rank][i_nibble][1];
                                best_pda_nibble_table[i_port][l_dimm][i_rank][i_nibble][0] = vref_val;
                            }
                        }
                    } //Rank Loop
                } //dimm loop
            } //Port loop

        } //end of While


        vref_val_print = base_percent + (last_known_vref * index_mul_print);
        FAPI_INF("Best V-Ref - %d - %d  ; Total Window = %d",last_known_vref,vref_val_print,last_total);
        // What do we do Once we know best V-Ref

        rc = fapiGetScom( i_target_mba,  0x03010432,  refresh_reg);
        if(rc) return rc;
        refresh_reg.clearBit(0);
        fapiPutScom( i_target_mba,  0x03010432,  refresh_reg);
        if(rc) return rc;

        if(cal_control==2)
        {
            FAPI_INF("CAL_CONTROL in RANK_Wise Mode!! ");
            rc = fapiGetScom(i_target_mba,0x03010432,l_data_buffer_64);
            if(rc) return rc;
            l_data_buffer_64.clearBit(0);
            rc = fapiPutScom(i_target_mba,0x03010432,l_data_buffer_64);
            if(rc) return rc;
            //FAPI_INF("\n After Clearing Refresh");

            for(i=0; i<MAX_PORT; i++) {
                for(j=0; j<MAX_DIMM; j++) {
                    for(k=0; k<4; k++) {

                        vrefdq_train_enable[i][j][k]=0x01;

                    }
                }
            }
            rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target_mba, vrefdq_train_enable);
            if(rc) return rc;
            //Calculate the Average V-Ref Value

            for(int i_port=0; i_port < 2; i_port++) {
                for(int i_dimm=0; i_dimm < 2; i_dimm++) {
                    for(int i_rank=0; i_rank < num_ranks_per_dimm[i_port][i_dimm]; i_rank++) {
                        for(int i_nibble=0; i_nibble < 16; i_nibble++) {

                            avg_best_vref = best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][0] + avg_best_vref;
                        }
                        avg_best_vref = avg_best_vref/16;
                        FAPI_INF("++ RANK_Wise  ++++ Best Avg V-Ref = %d !! ",avg_best_vref);
                        vrefdq_train_value[i_port][i_dimm][i_rank] = avg_best_vref;

                    } //End of Rank Loop
                } //end of dimm loop
            } //End of Port Loop

            rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_VALUE, &i_target_mba, vrefdq_train_value);
            if(rc) return rc;

            //issue call to run_pda (entering into train mode)
            rc = mss_mrs6_DDR4(l_target_centaur);
            if(rc)
            {
                FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                return rc;
            }

            // Call it Twice to Latch (Steve)
            rc = mss_mrs6_DDR4(l_target_centaur);
            if(rc)
            {
                FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                return rc;
            }

            for(i=0; i < MAX_PORT; i++) {
                for(j=0; j<2; j++) {
                    for(k=0; k<4; k++) {

                        vrefdq_train_enable[i][j][k]=0x00;

                    }
                }
            }
            rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target_mba, vrefdq_train_enable);
            if(rc) return rc;
            rc = mss_mrs6_DDR4(l_target_centaur);
            if(rc)
            {
                FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
                return rc;
            }

        } //end of RANK wise if
        else
        {
//1 - Issue PDA commands with enable train enable 1 for all DRAMs with good VREF values
            uint32_t max_vref;
            uint8_t dram_num;
            for(int i_port=0; i_port < 2; i_port++) {
                for(int i_dimm=0; i_dimm < 2; i_dimm++) {
                    for(int i_rank=0; i_rank < num_ranks_per_dimm[i_port][i_dimm]; i_rank++) {
                        for(int i_nibble=0; i_nibble < 16; i_nibble++) {
                            FAPI_INF("\n Port %d Dimm %d Rank:%d Pda_Nibble: %d  V-ref:%d  Margin:%d",i_port,i_dimm,i_rank,i_nibble,best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][0],best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][1]);

                            //if x8, averages the two nibbles together and, regardless, converts the DRAM over to the nibble
                            dram_num = i_nibble;
                            max_vref = best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][0];
                            if(dram_width == fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X8) {
                                i_nibble++;
                                dram_num = dram_num / 2;
                                max_vref += best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][0];
                                max_vref = max_vref / 2;
                            }
                            FAPI_INF("\n Port %d Dimm %d Rank:%d Pda_Nibble: %d DRAM_num %d  V-ref:%d  Margin:%d",i_port,i_dimm,i_rank,i_nibble,dram_num,best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][0],best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][1]);

                            pda.push_back(PDA_MRS_Storage(0x01,ATTR_EFF_VREF_DQ_TRAIN_ENABLE,dram_num,i_dimm,i_rank,i_port));
                            FAPI_INF("PDA STRING: %s %d %s",i_target_mba.toEcmdString(),pda.size()-1,pda[pda.size()-1].c_str());
                            pda.push_back(PDA_MRS_Storage(max_vref,ATTR_EFF_VREF_DQ_TRAIN_VALUE,dram_num,i_dimm,i_rank,i_port));
                            FAPI_INF("PDA STRING: %s %d %s",i_target_mba.toEcmdString(),pda.size()-1,pda[pda.size()-1].c_str());
                        }


                    } //End of Rank Loop
                } //end of dimm loop
            } //End of Port Loop
            FAPI_INF("RUNNING PDA FOR 1ST TIME");
            rc = mss_ddr4_run_pda((fapi::Target &)i_target_mba,pda);
            if(rc) return rc;
            FAPI_INF("FINISHED RUNNING PDA FOR 1ST TIME");
	    
            //issue call to run PDA again (latching good value in train mode)
            FAPI_INF("RUNNING PDA FOR 2ND TIME");
            rc = mss_ddr4_run_pda((fapi::Target &)i_target_mba,pda);
            if(rc) return rc;
            FAPI_INF("FINISHED RUNNING PDA FOR 2ND TIME");
            //clear the PDA vector
            pda.clear();

            //build PDA vector with good VREF values and train enable DISABLED

            for(int i_port=0; i_port < 2; i_port++) {
                for(int i_dimm=0; i_dimm < 2; i_dimm++) {
                    for(int i_rank=0; i_rank < num_ranks_per_dimm[i_port][i_dimm]; i_rank++) {
                        for(int i_nibble=0; i_nibble < 16; i_nibble++) {
                            //if x8, averages the two nibbles together and, regardless, converts the DRAM over to the nibble
                            dram_num = i_nibble;
                            max_vref = best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][0];
                            if(dram_width == fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X8) {
                                i_nibble++;
                                dram_num = dram_num / 2;
                                max_vref += best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][0];
                                max_vref = max_vref / 2;
                            }
                            FAPI_INF("\n Port %d Dimm %d Rank:%d Pda_Nibble: %d DRAM_num %d  V-ref:%d  Margin:%d",i_port,i_dimm,i_rank,i_nibble,dram_num,best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][0],best_pda_nibble_table[i_port][i_dimm][i_rank][i_nibble][1]);

                            pda.push_back(PDA_MRS_Storage(0x00,ATTR_EFF_VREF_DQ_TRAIN_ENABLE,dram_num,i_dimm,i_rank,i_port));
                            FAPI_INF("%s PDA STRING: %d %s",i_target_mba.toEcmdString(),pda.size()-1,pda[pda.size()-1].c_str());
                            pda.push_back(PDA_MRS_Storage(max_vref,ATTR_EFF_VREF_DQ_TRAIN_VALUE,dram_num,i_dimm,i_rank,i_port));
                            FAPI_INF("%s PDA STRING: %d %s",i_target_mba.toEcmdString(),pda.size()-1,pda[pda.size()-1].c_str());
                        }
                    } //End of Rank Loop
                } //end of dimm loop
            } //End of Port Loop

            FAPI_INF("RUNNING PDA FOR 3RD TIME");
            //issue call to PDA command
            rc = mss_ddr4_run_pda((fapi::Target &)i_target_mba,pda);
            if(rc) return rc;
            FAPI_INF("FINISHED RUNNING PDA FOR 3RD TIME");
        } //End of Else

        //turn on refresh then exit
        rc = fapiGetScom( i_target_mba,0x03010432,refresh_reg);
        refresh_reg.setBit(0);
        fapiPutScom( i_target_mba,0x03010432,refresh_reg);

    } // end of if

    else     //Skipping Shmoos ... Writing VPD data directly

    {
        vref_val_print = base_percent + (vpd_wr_vref_value[0] * index_mul_print);
        FAPI_INF("The Vref value is from VPD = %d; The  Voltage bump = %d ",vpd_wr_vref_value[0],vref_val_print);

        rc = fapiGetScom(i_target_mba,0x03010432,l_data_buffer_64);
        if(rc) return rc;
        l_data_buffer_64.clearBit(0);
        rc = fapiPutScom(i_target_mba,0x03010432,l_data_buffer_64);
        if(rc) return rc;
        //FAPI_INF("\n After Clearing Refresh");

        for(i=0; i<MAX_PORT; i++) {
            for(j=0; j<MAX_DIMM; j++) {
                for(k=0; k<4; k++) {

                    vrefdq_train_enable[i][j][k]=0x01;

                }
            }
        }

        rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_RANGE, &i_target_mba, vrefdq_train_range);
        if(rc) return rc;
        rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target_mba, vrefdq_train_enable);
        if(rc) return rc;
        rc = mss_mrs6_DDR4(l_target_centaur);
        if(rc)
        {
            FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }

        for(a=0; a < MAX_PORT; a++) //Port
        {
            for(l_dimm=0; l_dimm < MAX_DIMM; l_dimm++) //Max dimms
            {
                for(c=0; c < 4; c++) //Ranks
                {

                    vrefdq_train_value[a][l_dimm][c]=vpd_wr_vref_value[0];

                }
            }
        }

        rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_VALUE, &i_target_mba, vrefdq_train_value);
        if(rc) return rc;
        rc = mss_mrs6_DDR4(l_target_centaur);
        if(rc)
        {
            FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }

        for(i=0; i < MAX_PORT; i++) {
            for(j=0; j<2; j++) {
                for(k=0; k<4; k++) {

                    vrefdq_train_enable[i][j][k]=0x00;

                }
            }
        }
        rc = FAPI_ATTR_SET( ATTR_EFF_VREF_DQ_TRAIN_ENABLE, &i_target_mba, vrefdq_train_enable);
        if(rc) return rc;
        rc = mss_mrs6_DDR4(l_target_centaur);
        if(rc)
        {
            FAPI_ERR(" mrs_load Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
            return rc;
        }

        rc = fapiGetScom(i_target_mba,0x03010432,l_data_buffer_64);
        if(rc) return rc;
        l_data_buffer_64.setBit(0);
        rc = fapiPutScom(i_target_mba,0x03010432,l_data_buffer_64);
        if(rc) return rc;

    }

//Workaround MCBIST MASK Bit as FW reports FIR bits --- > CLEAR
    rc = fapiGetScom(i_target_mba, 0x03010614, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.clearBit(10);
    if (rc_num)
    {
        FAPI_ERR("Buffer error in function wr_vref_shmoo_ddr4_bin Workaround MCBIST MASK Bit");
        rc.setEcmdError(rc_num);
        return rc;
    }

//Read the write vref attributes
    return rc;
}


//----------------------------------------------------------------------------------------------
// Function name: rd_vref_shmoo()
// Description: This function varies the Centaur IO vref in 16 steps
// 		Calls write eye shmoo function
// Input param: const fapi::Target MBA, port = 0,1
// 	Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// 	Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// 	Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// 	i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//----------------------------------------------------------------------------------------------

fapi::ReturnCode rd_vref_shmoo(const fapi::Target & i_target_mba,
                               uint8_t i_port,
                               shmoo_type_t i_shmoo_type_valid)
{
    fapi::ReturnCode rc;
    uint32_t l_rd_cen_vref[MAX_PORT] = {0};
    uint32_t l_rd_cen_vref_nom[MAX_PORT] = {0};
    uint32_t l_rd_cen_vref_nom_fc = 0;
    uint32_t l_rd_cen_vref_in = 0;
    uint32_t l_rd_cen_vref_schmoo[MAX_PORT] = {0};
    uint8_t index  = 0;
    uint8_t count  = 0;
    //uint8_t shmoo_param_count = 0;
    //i_shmoo_type_valid = RD_EYE; // Hard coded - Temporary

    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint32_t l_left_margin_rd_vref_array[MAX_RD_VREF] = {0};
    uint32_t l_right_margin_rd_vref_array[MAX_RD_VREF] = {0};

    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RD_VREF, &i_target_mba, l_rd_cen_vref_nom);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RD_VREF_SCHMOO, &i_target_mba, l_rd_cen_vref_schmoo);
    if (rc) return rc;
    i_shmoo_type_valid = MCBIST;


    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++ Patch - Preet - RD_VREF - Check Sanity only at 500000 +++++++++++++++++++++++++++");
    rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid,
                     &l_left_margin, &l_right_margin,
                     l_rd_cen_vref_in);
    if(rc) return rc;
    FAPI_INF(" Setup and Sanity - Check disabled from now on..... Continuing .....");
    rc = set_attribute(i_target_mba);
    if (rc) return rc;

    i_shmoo_type_valid = RD_EYE;
    FAPI_INF("+++++++++++++++++CENTAUR VREF Read Shmoo Attributes values+++++++++++++++");
    FAPI_INF("CEN_RD_VREF[0]  = %d CEN_RD_VREF[1]  = %d on %s",
             l_rd_cen_vref_nom[0],
             l_rd_cen_vref_nom[1],
             i_target_mba.toEcmdString());
    FAPI_INF("CEN_RD_VREF_SCHMOO[0] = [%x], CEN_RD_VREF_SCHMOO[1] = [%x] on %s",
             l_rd_cen_vref_schmoo[0],
             l_rd_cen_vref_schmoo[1],
             i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++ Patch - Preet - RD_VREF +++++++++++++++++++++++++++");

    if (l_rd_cen_vref_schmoo[i_port] == 0)
    {
        FAPI_INF("FAST Shmoo Mode: This function will not change any Read Centaur VREF settings");
    }
    else
    {
        for (index = 0; index < MAX_RD_VREF; index += 1)
        {
            if ((l_rd_cen_vref_schmoo[i_port] & MASK) == 1)
            {
                l_rd_cen_vref[i_port] = rd_cen_vref_array[index];
                FAPI_INF("Current Read Vref Multiplier value is %d",
                         rd_cen_vref_array[index]);
                FAPI_INF("Configuring Read Vref Registers:");
                rc = config_rd_cen_vref(i_target_mba, i_port,
                                        l_rd_cen_vref[i_port]);
                if (rc) return rc;
                l_rd_cen_vref_in = l_rd_cen_vref[i_port];
                //FAPI_INF(" Calling Shmoo function to find out Timing Margin:");

                rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid,
                                 &l_left_margin, &l_right_margin,
                                 l_rd_cen_vref_in);
                if (rc) return rc;
                l_left_margin_rd_vref_array[index] = l_left_margin;
                l_right_margin_rd_vref_array[index] = l_right_margin;

                FAPI_INF("Read Vref = %d ; Min Setup time = %d; Min Hold time = %d",
                         rd_cen_vref_array[index],
                         l_left_margin_rd_vref_array[index],
                         l_right_margin_rd_vref_array[index]);
            }
            else
            {
                l_left_margin_rd_vref_array[index] = 0;
                l_right_margin_rd_vref_array[index] = 0;
            }
            l_rd_cen_vref_schmoo[i_port] = (l_rd_cen_vref_schmoo[i_port] >> 1);
            /* FAPI_INF("Read Vref = %d ; Min Setup time = %d; Min Hold time = %d", rd_cen_vref_array[index],l_left_margin_rd_vref_array[index],  l_right_margin_rd_vref_array[index]);  */
        }
        l_rd_cen_vref_nom_fc = l_rd_cen_vref_nom[i_port];
        find_best_margin(RD_VREF, l_left_margin_rd_vref_array,
                         l_right_margin_rd_vref_array, MAX_RD_VREF,
                         l_rd_cen_vref_nom_fc, count);
        if (count >= MAX_RD_VREF)
        {
            FAPI_ERR("Read vref new input(%d) out of bounds, (>= %d)", count,
                     MAX_RD_VREF);
            const uint8_t & COUNT_DATA = count;
            FAPI_SET_HWP_ERROR(rc, RC_RD_VREF_SHMOO_INVALID_MARGIN_DATA);
            return rc;
        }
        else
        {
            // FAPI_INF("Nominal value will not be changed!- Restoring the original values!");
            FAPI_INF("Restoring Nominal values!");
            rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RD_VREF, &i_target_mba,
                               l_rd_cen_vref_nom);
            if (rc) return rc;
            rc = config_rd_cen_vref(i_target_mba, i_port,
                                    l_rd_cen_vref_nom[i_port]);
            if (rc) return rc;
        }

        FAPI_INF("++++ Centaur Read Vref Shmoo function executed successfully ++++");
    }
    FAPI_INF("Restoring mcbist setup attribute...");
    rc = reset_attribute(i_target_mba);
    if (rc) return rc;
    return rc;
}

//------------------------------------------------------------------------------
// Function name: rcv_imp_shmoo()
// Receiver impedance shmoo function varies 9 values
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
//------------------------------------------------------------------------------
fapi::ReturnCode rcv_imp_shmoo(const fapi::Target & i_target_mba,
                               uint8_t i_port,
                               shmoo_type_t i_shmoo_type_valid)
{
    fapi::ReturnCode rc;
    uint8_t l_rcv_imp_dq_dqs[MAX_PORT] = {0};
    uint8_t l_rcv_imp_dq_dqs_nom[MAX_PORT] = {0};
    uint8_t l_rcv_imp_dq_dqs_nom_fc = 0;
    uint8_t l_rcv_imp_dq_dqs_in = 0;
    uint32_t l_rcv_imp_dq_dqs_schmoo[MAX_PORT] = {0};
    uint8_t index = 0;
    uint8_t count  = 0;
    uint8_t shmoo_param_count = 0;
    i_shmoo_type_valid = RD_EYE;   //Hard coded since no other shmoo is applicable - Temporary

    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint32_t l_left_margin_rcv_imp_array[MAX_RCV_IMP] = {0};
    uint32_t l_right_margin_rcv_imp_array[MAX_RCV_IMP] = {0};

    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS, &i_target_mba, l_rcv_imp_dq_dqs_nom);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO, &i_target_mba, l_rcv_imp_dq_dqs_schmoo);
    if (rc) return rc;

    FAPI_INF("+++++++++++++++++RECIVER IMP Read Shmoo Attributes values+++++++++++++++");
    FAPI_INF("CEN_RCV_IMP_DQ_DQS[0]  = %d , CEN_RCV_IMP_DQ_DQS[1]  = %d on %s",
             l_rcv_imp_dq_dqs_nom[0],
             l_rcv_imp_dq_dqs_nom[1],
             i_target_mba.toEcmdString());
    FAPI_INF("CEN_RCV_IMP_DQ_DQS_SCHMOO[0] = [%d], CEN_RCV_IMP_DQ_DQS_SCHMOO[1] = [%d], on %s",
             l_rcv_imp_dq_dqs_schmoo[0],
             l_rcv_imp_dq_dqs_schmoo[1],
             i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    if (l_rcv_imp_dq_dqs_schmoo[i_port] == 0)
    {
        FAPI_INF("FAST Shmoo Mode: This function will not change any Write DRAM VREF settings");
    }
    else
    {
        for (index = 0; index < MAX_RCV_IMP; index += 1)
        {
            if ((l_rcv_imp_dq_dqs_schmoo[i_port] & MASK) == 1)
            {
                l_rcv_imp_dq_dqs[i_port] = rcv_imp_array[index];
                FAPI_INF("Current Receiver Impedance: %d Ohms ",
                         rcv_imp_array[index]);
                FAPI_INF("Configuring Receiver impedance registers:");
                rc = config_rcv_imp(i_target_mba, i_port,
                                    l_rcv_imp_dq_dqs[i_port]);
                if (rc) return rc;
                l_rcv_imp_dq_dqs_in = l_rcv_imp_dq_dqs[i_port];
                //FAPI_INF("Calling Shmoo function to find out timing margin:");
                if (shmoo_param_count)
                {
                    rc = set_attribute(i_target_mba);
                    if (rc) return rc;
                }
                rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid,
                                 &l_left_margin, &l_right_margin,
                                 l_rcv_imp_dq_dqs_in);
                if (rc) return rc;
                l_left_margin_rcv_imp_array[index] = l_left_margin;
                l_right_margin_rcv_imp_array[index] = l_right_margin;
                shmoo_param_count++;
            }
            else
            {
                l_left_margin_rcv_imp_array[index] = 0;
                l_right_margin_rcv_imp_array[index] = 0;
            }
            l_rcv_imp_dq_dqs_schmoo[i_port] = (l_rcv_imp_dq_dqs_schmoo[i_port] >> 1);
        }
        l_rcv_imp_dq_dqs_nom_fc = l_rcv_imp_dq_dqs_nom[i_port];
        find_best_margin(RCV_IMP, l_left_margin_rcv_imp_array,
                         l_right_margin_rcv_imp_array, MAX_RCV_IMP,
                         l_rcv_imp_dq_dqs_nom_fc, count);
        if (count >= MAX_RCV_IMP)
        {
            FAPI_ERR("Receiver Imp new input(%d) out of bounds, (>= %d)",
                     count, MAX_RCV_IMP);
            const uint8_t & COUNT_DATA = count;
            FAPI_SET_HWP_ERROR(rc, RC_RCV_IMP_SHMOO_INVALID_MARGIN_DATA);
            return rc;
        }
        else
        {
            //   FAPI_INF("Nominal value will not be changed!- Restoring the original values!");
            FAPI_INF("Restoring the nominal values!");
            rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS, &i_target_mba,
                               l_rcv_imp_dq_dqs_nom);
            if (rc) return rc;
            rc = config_rcv_imp(i_target_mba, i_port,
                                l_rcv_imp_dq_dqs_nom[i_port]);
            if (rc) return rc;
        }
        FAPI_INF("Restoring mcbist setup attribute...");
        rc = reset_attribute(i_target_mba);
        if (rc) return rc;
        FAPI_INF("++++ Receiver Impdeance Shmoo function executed successfully ++++");
    }
    return rc;
}

//------------------------------------------------------------------------------
// Function name:delay_shmoo()
// Calls Delay shmoo function varies delay values of each dq and returns timing margin
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
// Output param: l_left_margin = Left Margin(Setup time),
// l_right_margin = Right Margin (Hold time) in ps
//------------------------------------------------------------------------------

fapi::ReturnCode delay_shmoo(const fapi::Target & i_target_mba, uint8_t i_port,
                             shmoo_type_t i_shmoo_type_valid,
                             uint32_t *o_left_margin,
                             uint32_t *o_right_margin,
                             uint32_t i_shmoo_param)
{
    fapi::ReturnCode rc;
    //FAPI_INF(" Inside before the delay shmoo " );
    //Constructor CALL: generic_shmoo::generic_shmoo(uint8_t i_port, uint32_t shmoo_mask,shmoo_algorithm_t shmoo_algorithm)
    //generic_shmoo mss_shmoo=generic_shmoo(i_port,2,SEQ_LIN);

    //need to use fapi allocator to avoid memory fragmentation issues in Hostboot
    //  then use an in-place new to put the object in the pre-allocated memory
    void* l_mallocptr = fapiMalloc(sizeof(generic_shmoo));
    generic_shmoo * l_pShmoo = new (l_mallocptr) generic_shmoo(i_port,i_shmoo_type_valid,SEQ_LIN);
    rc = l_pShmoo->run(i_target_mba, o_left_margin, o_right_margin,i_shmoo_param);
    if(rc)
    {
        FAPI_ERR("Delay Schmoo Function is Failed rc = 0x%08X (creator = %d)", uint32_t(rc), rc.getCreator());
    }
    fapiFree(l_mallocptr);
    return rc;
}

//------------------------------------------------------------------------------
// Function name:delay_shmoo()
// Calls Delay shmoo function varies delay values of each dq and returns timing margin
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo type: MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
// Shmoo Mode: FEW_ADDR, QUARTER_ADDR, HALF_ADDR, FULL_ADDR
// i_pattern, i_test_type : Default = 0, mcbist lab function would use this arg
// Output param: l_left_margin = Left Margin(Setup time),
// l_right_margin = Right Margin (Hold time) in ps
//------------------------------------------------------------------------------

fapi::ReturnCode delay_shmoo_ddr4(const fapi::Target & i_target_mba, uint8_t i_port,
                                  shmoo_type_t i_shmoo_type_valid,
                                  uint32_t *o_left_margin,
                                  uint32_t *o_right_margin,
                                  uint32_t i_shmoo_param,uint32_t pda_nibble_table[2][2][4][16][2])
{
    fapi::ReturnCode rc;

    //need to use fapi allocator to avoid memory fragmentation issues in Hostboot
    //  then use an in-place new to put the object in the pre-allocated memory
    void* l_mallocptr = fapiMalloc(sizeof(generic_shmoo));
    generic_shmoo * l_pShmoo = new (l_mallocptr) generic_shmoo(i_port,i_shmoo_type_valid,SEQ_LIN);

    rc = l_pShmoo->run(i_target_mba, o_left_margin, o_right_margin,i_shmoo_param);
    if (rc) return rc;



    fapiFree(l_mallocptr);
    return rc;
}

fapi::ReturnCode delay_shmoo_ddr4_pda(const fapi::Target & i_target_mba, uint8_t i_port,
                                      shmoo_type_t i_shmoo_type_valid,
                                      uint32_t *o_left_margin,
                                      uint32_t *o_right_margin,
                                      uint32_t i_shmoo_param,uint32_t pda_nibble_table[2][2][4][16][2])
{
    fapi::ReturnCode rc;

    //need to use fapi allocator to avoid memory fragmentation issues in Hostboot
    //  then use an in-place new to put the object in the pre-allocated memory
    void* l_mallocptr = fapiMalloc(sizeof(generic_shmoo));
    generic_shmoo * l_pShmoo = new (l_mallocptr) generic_shmoo(i_port,i_shmoo_type_valid,SEQ_LIN);

    rc = l_pShmoo->run(i_target_mba, o_left_margin, o_right_margin,i_shmoo_param);
    if (rc) return rc;

    rc = l_pShmoo->get_nibble_pda(i_target_mba,pda_nibble_table);
    if (rc) return rc;

    fapiFree(l_mallocptr);
    return rc;
}

//------------------------------------------------------------------------------
//Function name: set_attributes()
//Description: Sets the attribute used  by all functions
//------------------------------------------------------------------------------

fapi::ReturnCode set_attribute(const fapi::Target & i_target_mba)
{
    fapi::ReturnCode rc;
    uint8_t l_mcbist_setup_multiple_set = 1;  //Hard coded it wont change
    rc =  FAPI_ATTR_SET(ATTR_SCHMOO_MULTIPLE_SETUP_CALL, &i_target_mba, l_mcbist_setup_multiple_set);
    return rc;
}

fapi::ReturnCode rd_vref_shmoo_ddr4(const fapi::Target & i_target_mba)
{
    fapi::ReturnCode rc;
    shmoo_type_t i_shmoo_type_valid = MCBIST; // Hard coded - Temporary
    ecmdDataBufferBase l_data_buffer_64(64);
    ecmdDataBufferBase data_buffer(64);
    uint32_t l_rd_cen_vref_schmoo[MAX_PORT] = {0};
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint32_t l_rd_cen_vref_in = 0;
    uint8_t l_attr_schmoo_test_type_u8 = 1;
    rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, l_attr_schmoo_test_type_u8);
    if(rc) return rc;
    uint8_t i_port=0;
    uint32_t diff_value = 1375;
    uint32_t base = 70000;
    uint32_t vref_value_print = 0;
    uint32_t l_left_margin_rd_vref_array[16] = {0};
    uint32_t l_right_margin_rd_vref_array[16] = {0};
    uint32_t rc_num = 0;
    uint8_t l_vref_num = 0;

    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++ Patch - Preet - RD_VREF - Check Sanity only - DDR4 +++++++++++++++++++++++++++");
    rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid,
                     &l_left_margin, &l_right_margin,
                     l_rd_cen_vref_in);
    if(rc) return rc;
    FAPI_INF(" Setup and Sanity - Check disabled from now on..... Continuing .....");
    rc = set_attribute(i_target_mba);
    if (rc) return rc;

    i_shmoo_type_valid = RD_EYE;
    l_attr_schmoo_test_type_u8 = 4;
    rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, l_attr_schmoo_test_type_u8);
    if(rc) return rc;
    //rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RD_VREF, &i_target_mba, l_rd_cen_vref_nom);if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RD_VREF_SCHMOO, &i_target_mba, l_rd_cen_vref_schmoo);
    if (rc) return rc;


    FAPI_INF("CEN_RD_VREF_SCHMOO[0] = [%x], CEN_RD_VREF_SCHMOO[1] = [%x] on %s",
             l_rd_cen_vref_schmoo[0],
             l_rd_cen_vref_schmoo[1],
             i_target_mba.toEcmdString());
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++ Patch - Preet - RD_VREF DDR4 +++++++++++++++++++++++++++");

    //For DDR3 - DDR4 Range
    if (l_rd_cen_vref_schmoo[i_port] == 1)
    {
        FAPI_INF("\n Testing Range - DDR3 to DDR4 - Vrefs");
        base = 50000;
    }
    else
    {
        FAPI_INF("\n Testing Range - DDR4 Range Only - Vrefs");

        for(l_vref_num = 7; l_vref_num > 0 ; l_vref_num--)
        {
            l_rd_cen_vref_in = l_vref_num;
            vref_value_print = base - (l_vref_num*diff_value);
            FAPI_INF("Current Vref value is %d",vref_value_print);
            FAPI_INF("Configuring Read Vref Registers:");
            rc = fapiGetScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_0_0x800000060301143F,
                             data_buffer);
            if(rc) return rc;
            rc_num = rc_num | data_buffer.insertFromRight(l_rd_cen_vref_in,56,4);
            if (rc_num)
            {
                FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc_num = data_buffer.setBit(60);
            if (rc_num)
            {
                FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_0_0x800000060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_1_0x800004060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_2_0x800008060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_3_0x80000c060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_4_0x800010060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiGetScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_0_0x800100060301143F,
                             data_buffer);
            if(rc) return rc;
            rc_num = rc_num | data_buffer.insertFromRight(l_rd_cen_vref_in,56,4);
            if (rc_num)
            {
                FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc_num = data_buffer.setBit(60);
            if (rc_num)
            {
                FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_0_0x800100060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_1_0x800104060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_2_0x800108060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_3_0x80010c060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_4_0x800110060301143F,
                             data_buffer);
            if(rc) return rc;

            rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid,&l_left_margin, &l_right_margin,vref_value_print);
            if (rc) return rc;
            l_left_margin_rd_vref_array[l_vref_num] = l_left_margin;
            l_right_margin_rd_vref_array[l_vref_num] = l_right_margin;

            FAPI_INF("Read Vref = %d ; Min Setup time = %d; Min Hold time = %d",vref_value_print, l_left_margin_rd_vref_array[l_vref_num],l_right_margin_rd_vref_array[l_vref_num]);
        }
        // For base + values

        for(l_vref_num = 0; l_vref_num < 9; l_vref_num++)
        {

            l_rd_cen_vref_in = l_vref_num;
            vref_value_print = base + (l_vref_num*diff_value);
            FAPI_INF("Current Vref value is %d",vref_value_print);
            FAPI_INF("Configuring Read Vref Registers:");
            rc = fapiGetScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_0_0x800000060301143F,
                             data_buffer);
            if(rc) return rc;
            rc_num = rc_num | data_buffer.insertFromRight(l_rd_cen_vref_in,56,4);
            if (rc_num)
            {
                FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc_num = data_buffer.setBit(60);
            if (rc_num)
            {
                FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_0_0x800000060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_1_0x800004060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_2_0x800008060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_3_0x80000c060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_4_0x800010060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiGetScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_0_0x800100060301143F,
                             data_buffer);
            if(rc) return rc;
            rc_num = rc_num | data_buffer.insertFromRight(l_rd_cen_vref_in,56,4);
            if (rc_num)
            {
                FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc_num = data_buffer.setBit(60);
            if (rc_num)
            {
                FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_0_0x800100060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_1_0x800104060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_2_0x800108060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_3_0x80010c060301143F,
                             data_buffer);
            if(rc) return rc;
            rc = fapiPutScom(i_target_mba,
                             DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_4_0x800110060301143F,
                             data_buffer);
            if(rc) return rc;

            rc = delay_shmoo(i_target_mba, i_port, i_shmoo_type_valid,&l_left_margin, &l_right_margin,vref_value_print);
            if (rc) return rc;
            l_left_margin_rd_vref_array[l_vref_num] = l_left_margin;
            l_right_margin_rd_vref_array[l_vref_num] = l_right_margin;

            FAPI_INF("Read Vref = %d ; Min Setup time = %d; Min Hold time = %d",vref_value_print, l_left_margin_rd_vref_array[l_vref_num],l_right_margin_rd_vref_array[l_vref_num]);
        }


    }
    FAPI_INF("++++ Centaur Read Vref Shmoo function DDR4 done ! ++++");
    FAPI_INF("Restoring mcbist setup attribute...");
    rc = reset_attribute(i_target_mba);
    return rc;
}

//------------------------------------------------------------------------------
//Function name: reset_attributes()
//Description: Sets the attribute used  by all functions
//------------------------------------------------------------------------------

fapi::ReturnCode reset_attribute(const fapi::Target & i_target_mba)
{
    fapi::ReturnCode rc;
    uint8_t l_mcbist_setup_multiple_reset = 0; //Hard coded it wont change
    rc = FAPI_ATTR_SET(ATTR_SCHMOO_MULTIPLE_SETUP_CALL, &i_target_mba, l_mcbist_setup_multiple_reset);
    return rc;
}

//------------------------------------------------------------------------------
// Function name:find_best_margin()
// Finds better timing margin and returns the index
// Input param: const fapi::Target MBA, port = 0,1
// Shmoo param: PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// i_left[], i_right[] - timing margin arrays, i_max = Max enum value of schmoo param
// i_param_nom = selected shmoo parameter (DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
// Output param: o_index (returns index)
//------------------------------------------------------------------------------


void find_best_margin(shmoo_param i_shmoo_param_valid,
                      uint32_t i_left[],
                      uint32_t i_right[],
                      const uint8_t i_max,
                      uint32_t i_param_nom,
                      uint8_t& o_index)
{
    uint32_t left_margin = 0;
    uint32_t right_margin = 0;
    uint32_t left_margin_nom = 0;
    uint32_t right_margin_nom = 0;
    uint32_t diff_margin_nom = 0;
    //uint32_t total_margin = 0;
    uint32_t diff_margin = 0;
    uint8_t index = 0;
    uint8_t index2 = 0;

    for (index = 0; index < i_max; index += 1) //send max from top function
    {
        if (i_shmoo_param_valid & DRV_IMP)
        {
            if (drv_imp_array[index] == i_param_nom)
            {
                left_margin_nom = i_left[index];
                right_margin_nom = i_right[index];
                diff_margin_nom = (i_left[index] >= i_right[index]) ?
                                  (i_left[index]- i_right[index]) :
                                  (i_right[index] - i_left[index]);
                //FAPI_INF("Driver impedance value (NOM): %d Ohms  Setup Margin: %d Hold Margin: %d", i_param_nom, i_left[index], i_right[index]);
                break;
            }
        }
        else if (i_shmoo_param_valid & SLEW_RATE)
        {
            if (slew_rate_array[index] == i_param_nom)
            {
                left_margin_nom = i_left[index];
                right_margin_nom = i_right[index];
                diff_margin_nom = (i_left[index] >= i_right[index]) ?
                                  (i_left[index] - i_right[index]) :
                                  (i_right[index] - i_left[index]);
                //FAPI_INF("Slew rate value (NOM): %d V/ns  Setup Margin: %d Hold Margin: %d", i_param_nom, i_left[index], i_right[index]);
                break;
            }
        }
        else if (i_shmoo_param_valid & WR_VREF)
        {
            if (wr_vref_array_fitness[index] == i_param_nom)
            {
                left_margin_nom = i_left[index];
                right_margin_nom = i_right[index];
                diff_margin_nom = (i_left[index] >= i_right[index]) ?
                                  (i_left[index] - i_right[index]) :
                                  (i_right[index] - i_left[index]);
                //FAPI_INF("Write DRAM Vref Multiplier value (NOM): %d   Setup Margin: %d Hold Margin: %d", i_param_nom, i_left[index], i_right[index]);
                break;
            }
        }
        else if (i_shmoo_param_valid & RD_VREF)
        {
            if (rd_cen_vref_array_fitness[index] == i_param_nom)
            {
                left_margin_nom = i_left[index];
                right_margin_nom = i_right[index];
                diff_margin_nom = (i_left[index] >= i_right[index]) ?
                                  (i_left[index] - i_right[index]) :
                                  (i_right[index] - i_left[index]);
                //FAPI_INF("Centaur Read Vref Multiplier value (NOM): %d  Setup Margin: %d Hold Margin: %d", i_param_nom, i_left[index], i_right[index]);
                break;
            }
        }
        else if (i_shmoo_param_valid & RCV_IMP)
        {
            if (rcv_imp_array[index] == i_param_nom)
            {
                left_margin_nom = i_left[index];
                right_margin_nom = i_right[index];
                diff_margin_nom = (i_left[index] >= i_right[index]) ?
                                  (i_left[index] - i_right[index]) :
                                  (i_right[index] - i_left[index]);
                // FAPI_INF("Receiver Impedance value (NOM): %d Ohms  Setup Margin: %d Hold Margin: %d", i_param_nom, i_left[index], i_right[index]);
                break;
            }
        }
    }
    for (index2 = 0; index2 < i_max; index2 += 1)
    {
        left_margin = i_left[index2];
        right_margin = i_right[index2];
        //total_margin = i_left[index2] + i_right[index2];
        diff_margin = (i_left[index2] >= i_right[index2]) ? (i_left[index2]
                      - i_right[index2]) : (i_right[index2] - i_left[index2]);
        if ((left_margin > 0 && right_margin > 0))
        {
            if ((left_margin >= left_margin_nom) && (right_margin
                    >= right_margin_nom) && (diff_margin <= diff_margin_nom))
            {
                o_index = index2;
                //wont break this loop, since the purpose is to find the best parameter value & best timing margin The enum is constructed to do that
                //  FAPI_INF("Index value %d, Min Setup Margin: %d, Min Hold Margin: %d", o_index, i_left[index2], i_right[index2]);
            }
        }
    }
}


