//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_mc/mss_draminit_mc.C $
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
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : cen_draminit_mc.C
// *! DESCRIPTION : Procedure for handing over control to the MC
// *! OWNER NAME :  David Cadigan   Email: dcadiga@us.ibm.com
// *! BACKUP NAME : Mark Bellows   Email: bellows@us.ibm.com
// #! ADDITIONAL COMMENTS :
//
//
//Run cen_draminit_mc.C to complete the initialization sequence. This performs the steps of
//***Set the IML Complete bit MBSSQ(2) (SCOM Addr: 0x02011417) to indicate that IML has completed
//***Start the refresh engines
//***Enabling periodic calibration and power management.
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.14   | jdsloat  |07-Mar-12| Fixed iml_complete to match target
//  1.13   | jdsloat  |07-Mar-12| Changed to target centaur with getChildchip, fixed buffer insert
//  1.12   | jdsloat  |20-Feb-12| Built control_bit_ecc and power_management, added ccs_mode_reset
//  1.11   | jdsloat  |20-Feb-12| removing #include <fapiClientCapi.H>
//  1.10   | jdsloat  |20-Feb-12| Made Constants, Fixed RC_buff checking, Num_ranks check
//  1.10   | jdsloat  |10-Feb-12| updated formatting/style, fixed some addresses, removed mba23 calls
//  1.9    | M Bellows|19-Jan-12| temporarily added includes and getconfig functions
//  1.8    | M Bellows|12-Jan-12| fixed refresh address, temporarly disabled periodic cal, 
//         |          |         | fixed unsigned long constants, fixed variable declaration 
//         |          |         | for calibration registers"
//  1.7    | D Cadigan| 011012  | Changed periodic cal routine to reflect changes in registers for Centaur1
//  1.6    | D Cadigan| 12222011| Fixed insert again
//  1.5    | D Cadigan| 12212011| Fixed insert for buffers, modified dram_freq to temporarily calculate a value based on the method in mss_freq
//  1.4    | D Cadigan| 12092011| Added header file
//  1.3    | D Cadigan| 09302011| Moved to FAPI VBU directory
//  1.2    | D Cadigan| 09282011| Converted to fapi, enhanced procedures to take in some variables.  Still need to debug those functions
//  1.1    | D Cadigan| 04072011| Initial Copy


//------------------------------------------------------------------------------
// To-Do's
//------------------------------------------------------------------------------
// 1) Move addresses to cen_scom_addresses.H
// 2) Add in attributes after they are added to the XML
//------------------------------------------------------------------------------

//----------------------------------------------------------------------
//  FAPI Includes
//----------------------------------------------------------------------
#include <fapi.H>

//----------------------------------------------------------------------
//  Centaur function Includes
//----------------------------------------------------------------------
#include <mss_funcs.H>



extern "C" {

using namespace fapi;


//----------------------------------------------------------------------
//  Subroutine declarations 
//----------------------------------------------------------------------
ReturnCode mss_start_refresh (Target& i_mbatarget, Target& i_centarget);
ReturnCode mss_enable_periodic_cal(Target& i_target);
ReturnCode mss_set_iml_complete(Target& i_target);
ReturnCode mss_enable_power_management(Target& i_target);
ReturnCode mss_enable_control_bit_ecc(Target& i_target);
ReturnCode mss_ccs_mode_reset(Target& i_target);

//----------------------------------------------------------------------
//  Constants - Addresses - TODO: to be moved to cen_scom_addresses.H later
//----------------------------------------------------------------------
const uint32_t MBA01_REF0Q_0x03010432 = 0x03010432;
//Master Registers
const uint64_t DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P0_0x8000C00B0301143FULL = 0x8000C00B0301143FULL;
const uint64_t DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P1_0x8001C00B0301143FULL = 0x8001C00B0301143FULL;
//ZQCal Control Registers - currently not being used, need to write in settings for these regs
const uint64_t DPHY01_DDRPHY_PC_PER_ZCAL_CONFIG_P0_0x8000C00F0301143FULL = 0x8000C00F0301143FULL;
const uint64_t DPHY01_DDRPHY_PC_PER_ZCAL_CONFIG_P1_0x8001C00F0301143FULL = 0x8001C00F0301143FULL;
const uint32_t MBSSQ_0x02011417 = 0x02011417;
// Power Management addresses
const uint32_t MBA01_PM0Q_0x03010434 = 0x03010434;
// ECC enable addresses
const uint32_t MBS_ECC0_MBSECCQ_0x0201144A = 0x0201144A;
const uint32_t MBS_ECC1_MBSECCQ_0x0201148A = 0x0201148A;

ReturnCode mss_draminit_mc (Target& i_target)
{
// Target is centaur
//
    ReturnCode rc;
    std::vector<fapi::Target> l_mbaChiplets;

    // Get associated MBA's on this centaur
    rc=fapiGetChildChiplets(i_target, fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
    if (rc) return rc;

    // Step One: Set IML COMPLETE
    FAPI_INF( "+++ Setting IML Complete +++");
    rc = mss_set_iml_complete(i_target);
    if(rc)
    {
       FAPI_ERR("---Error During IML Complete Enable rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
       return rc;
    }

    // Loop through the 2 MBA's
    for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
    {

        // Step Two: Disable CCS address lines
        FAPI_INF( "+++ Disabling CCS Address Lines +++");
        rc = mss_ccs_mode_reset(l_mbaChiplets[i]);
        if(rc)
        {
           FAPI_ERR("---Error During CCS Mode Reset rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
           return rc;
        }

        // Step Three: Setup Refresh Controls
        FAPI_INF( "+++ Setting Up Refresh Controls +++");
        rc = mss_start_refresh(l_mbaChiplets[i],i_target);
        if(rc)
        {
           FAPI_ERR("---Error During Refresh Control Setup and Enable rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
           return rc;
        }

        // Step Four: Setup Periodic Cals
        FAPI_INF( "+++ Setting Up Periodic Cals +++");
        rc = mss_enable_periodic_cal(l_mbaChiplets[i]);
        if(rc)
        {
           FAPI_ERR("---Error During Periodic Cal Setup and Enable rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
           return rc;
        }

        // Step Five: Setup Power Management
        FAPI_INF( "+++ Setting Up Power Management +++");
        rc = mss_enable_power_management(l_mbaChiplets[i]);
        if(rc)
        {
           FAPI_ERR("---Error During Power Management Setup and Enable rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
           return rc;
        }
  
    }

    // Step Six: Setup Control Bit ECC
    FAPI_INF( "+++ Setting Up Control Bit ECC +++");
    rc = mss_enable_control_bit_ecc(i_target);
    if(rc)
    {
        FAPI_ERR("---Error During Control Bit ECC Setup rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
        return rc;
    }

    return rc;
}

ReturnCode mss_start_refresh (Target& i_mbatarget, Target& i_centarget)
{
    //Target MBA, centaur

    //Variables
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num = 0;

    uint32_t refresh_interval = 0;
    uint32_t refresh_interval_reset = 0;
    uint32_t num_ranks = 0;

    //Bit 0 is enable
    //bit 4..7 cfg_refresh_priority_threshold
    //bit 8..18 cfg_refresh_interval
    //bit 19..29 cfg_refresh_reset_interval
    //bit 30..39 cfg_trfc
    //bit 40..49 cfg_refr_tsv_stack
    //bit 50..60 cfg_refr_check_interval
    ecmdDataBufferBase mba01_ref0q_data_buffer_64(64);


    uint32_t dimm_freq;
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &i_centarget, dimm_freq);
    if(rc) return rc; 

    //Configure Refresh based on system attributes MBA01
    rc = fapiGetScom(i_mbatarget, MBA01_REF0Q_0x03010432, mba01_ref0q_data_buffer_64);
    if(rc) return rc;

    //Configure Refresh Priority  Hard coded to 8 refreshes 
    rc_num = rc_num | mba01_ref0q_data_buffer_64.setBit(4);
    
    //Configure Refresh Interval
    //MBA01 - Get number of ranks, then calculate refresh rate.  

    // FAPI ATTR GET NUM RANKS
    uint8_t num_ranks_array[2][2]; //[port][dimm]
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_mbatarget, num_ranks_array);
    if(rc) return rc;

    // Adding them up
    num_ranks = num_ranks_array[0][0] + num_ranks_array[0][1]+ num_ranks_array[1][0] + num_ranks_array[1][1];

    if (num_ranks == 0)
    {
        FAPI_INF("+++ No Configured Ranks for current target +++");
    }
    else
    {
        //Now program in the refresh rate for MBA01

        // TODO: Waiting for tREFI to appear as attribute in XML file 
        // Until then tREFI will be hardcoded 
        uint16_t trefi = 6240; // given in Nclks = 3.9us (DDR3 Jedec) at 1600
        //rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TREFI, &i_target, num_ranks_array);
        //if(rc) return rc;

        refresh_interval = (trefi/num_ranks)/8;
        refresh_interval_reset = refresh_interval - 1;
        rc_num = rc_num | mba01_ref0q_data_buffer_64.insert(refresh_interval, 8,10);
        rc_num = rc_num | mba01_ref0q_data_buffer_64.insert(refresh_interval, 50,10);
        rc_num = rc_num | mba01_ref0q_data_buffer_64.insert(refresh_interval_reset,19,10);
        //tRFC
        uint8_t trfc = 0;
        rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TRFC, &i_mbatarget, trfc);
        if(rc) return rc;

        rc_num = rc_num | mba01_ref0q_data_buffer_64.insert(trfc, 30, 8);
        rc_num = rc_num | mba01_ref0q_data_buffer_64.insert((uint8_t) 0, 38, 2);

        //Enable Refresh
        //MBA01
        rc_num = rc_num | mba01_ref0q_data_buffer_64.setBit(0);
        rc = fapiPutScom(i_mbatarget, MBA01_REF0Q_0x03010432, mba01_ref0q_data_buffer_64);
        if(rc) return rc;

        if (rc_num)
        {
            FAPI_ERR( "mss_start_refresh: Error setting up buffers");
            rc_buff.setEcmdError(rc_num);
            return rc_buff;
        }

        FAPI_INF("+++ Refresh Enabled +++");

    }

    return rc;
}

ReturnCode mss_enable_periodic_cal (Target& i_target)
{
    //Target MBA

    //Procedure to setup and enable periodic cals
    //Variables
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num  = 0;

    //PER CAL Types  
    //MBA01

    // TODO: Waiting for these attributes in XML
    // Used to pull enable bits.
    //uint8_t memcal_interval;
    //rc = FAPI_ATTR_GET(ATTR_EFF_MEMCAL_INTERVAL, &i_target, memcal_interval);
    //if(rc) return rc;
    //uint8_t zqcal_interval;
    //rc = FAPI_ATTR_GET(ATTR_EFF_ZQCAL_INTERVAL, &i_target, zqcal_interval);
    //if(rc) return rc;

    uint32_t p0_per_zqcal_mba01_ena = 1;
    uint32_t p0_per_sysclk_mba01_ena = 1;
    uint32_t p0_per_rd_ck_mba01_ena = 1;
    uint32_t p0_per_rd_dqs_mba01_ena = 1;
    uint32_t p0_per_rd_center_mba01_ena = 1;
    uint32_t p1_per_zqcal_mba01_ena = 1;
    uint32_t p1_per_sysclk_mba01_ena = 1;
    uint32_t p1_per_rd_ck_mba01_ena = 1;
    uint32_t p1_per_rd_dqs_mba01_ena = 1;
    uint32_t p1_per_rd_center_mba01_ena = 1;

    // TODO: waiting for ZQ Cal and Mem Cal intevals in XML
    // Example one hot code.  Not the real order/decode. 
    //p0_per_zqcal_mba01_ena = 0x1 & zqcal_interval;
    //p1_per_zqcal_mba01_ena = 0x2 & zqcal_interval >> 1;
    //p0_per_sysclk_mba01_ena = 0x1 & memcal_interval;
    //p0_per_rd_ck_mba01_ena = (0x2 & memcal_interval) >> 1;
    //p0_per_rd_dqs_mba01_ena = (0x4 & memcal_interval) >> 2;
    //p0_per_rd_center_mba01_ena = (0x8 & memcal_interval) >> 3;
    //p1_per_sysclk_mba01_ena = 0x1 & memcal_interval;
    //p1_per_rd_ck_mba01_ena = (0x2 & memcal_interval) >> 1;
    //p1_per_rd_dqs_mba01_ena = (0x4 & memcal_interval) >> 2;
    //p1_per_rd_center_mba01_ena = (0x8 & memcal_interval) >> 3;

    //DDR Calibration Register Addresses - currently not in use, need to write in settings for these regs
    //uint32_t mba01_cal0q = 0x0301040F;
    //uint32_t mba01_cal1q = 0x03010410;
    //uint32_t mba01_cal2q = 0x03010411;

 
    ecmdDataBufferBase mba01_data_buffer_64_p0(64);
    ecmdDataBufferBase mba01_data_buffer_64_p1(64);

    //Determine whether or not we want to do a particular type of calibration on the given ranks
    //ALL CALS CURRENTLY SET AS ON, ONLY CHECK RANK PAIRS PRESENT
    //***mba01 Setup
    rc_num = rc_num | mba01_data_buffer_64_p0.flushTo0();
    rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P0_0x8000C00B0301143FULL, mba01_data_buffer_64_p0);
    if(rc) return rc;

    rc_num = rc_num | mba01_data_buffer_64_p1.flushTo0();
    rc = fapiGetScom(i_target, DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P1_0x8001C00B0301143FULL, mba01_data_buffer_64_p1);
    if(rc) return rc;

    uint8_t primary_rank_group0_array[2]; //[rank]
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &i_target, primary_rank_group0_array);
    if(rc) return rc;

    uint8_t primary_rank_group1_array[2]; //[rank]
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &i_target, primary_rank_group1_array);
    if(rc) return rc;

    uint8_t primary_rank_group2_array[2]; //[rank]
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &i_target, primary_rank_group2_array);
    if(rc) return rc;

    uint8_t primary_rank_group3_array[2]; //[rank]
    rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &i_target, primary_rank_group3_array);
    if(rc) return rc;

    if(primary_rank_group0_array[0] != 255)
    {
       //Rank Group 0 Enabled
       rc_num = rc_num | mba01_data_buffer_64_p0.setBit(48);
    }
    if(primary_rank_group1_array[0] != 255)
    {
       //Rank Group 1 Enabled
       rc_num = rc_num | mba01_data_buffer_64_p0.setBit(49);
    }
    if(primary_rank_group2_array[0] != 255)
    {
       //Rank Group 2 Enabled
       rc_num = rc_num | mba01_data_buffer_64_p0.setBit(50);
    }
    if(primary_rank_group3_array[0] != 255)
    {
       //Rank Group 3 Enabled
       rc_num = rc_num | mba01_data_buffer_64_p0.setBit(51);
    }
    if(primary_rank_group0_array[1] != 255)
    {
       //Rank Group 0 Enabled
       rc_num = rc_num | mba01_data_buffer_64_p1.setBit(48);
    }
    if(primary_rank_group1_array[1] != 255)
    {
       //Rank Group 1 Enabled
       rc_num = rc_num | mba01_data_buffer_64_p1.setBit(49);
    }
    if(primary_rank_group2_array[1] != 255)
    {
       //Rank Group 2 Enabled
       rc_num = rc_num | mba01_data_buffer_64_p1.setBit(50);
    }
    if(primary_rank_group3_array[1] != 255)
    {
       //Rank Group 3 Enabled
       rc_num = rc_num | mba01_data_buffer_64_p1.setBit(51);
    }

   
    
    //p0
    if(p0_per_zqcal_mba01_ena == 1)
    {
       rc_num = rc_num | mba01_data_buffer_64_p0.setBit(52);
    }
    if(p0_per_sysclk_mba01_ena == 1)
    {
       rc_num = rc_num | mba01_data_buffer_64_p0.setBit(53);
    }
    if(p0_per_rd_ck_mba01_ena == 1)
    {
       rc_num = rc_num | mba01_data_buffer_64_p0.setBit(54);
    }
    if(p0_per_rd_dqs_mba01_ena == 1)
    {
       rc_num = rc_num | mba01_data_buffer_64_p0.setBit(55);
    }
    if(p0_per_rd_center_mba01_ena == 1)
    {
       rc_num = rc_num | mba01_data_buffer_64_p0.setBit(56);
    }

    //p1
    if(p1_per_zqcal_mba01_ena == 1)
    {
       rc_num = rc_num | mba01_data_buffer_64_p1.setBit(52);
    }
    if(p1_per_sysclk_mba01_ena == 1)
    {
       rc_num = rc_num | mba01_data_buffer_64_p1.setBit(53);
    }
    if(p1_per_rd_ck_mba01_ena == 1)
    {
       rc_num = rc_num | mba01_data_buffer_64_p1.setBit(54);
    }
    if(p1_per_rd_dqs_mba01_ena == 1)
    {
       rc_num = rc_num | mba01_data_buffer_64_p1.setBit(55);
    }
    if(p1_per_rd_center_mba01_ena == 1)
    {
       rc_num = rc_num | mba01_data_buffer_64_p1.setBit(56);
    }
    
    //Write the mba_p01_PER_CAL_CFG_REG
    rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P0_0x8000C00B0301143FULL, mba01_data_buffer_64_p0);
    if(rc) return rc;
    FAPI_INF("+++ Periodic Calibration Enabled p0+++");
    rc = fapiPutScom(i_target, DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P1_0x8001C00B0301143FULL, mba01_data_buffer_64_p1);
    if(rc) return rc;
    FAPI_INF("+++ Periodic Calibration Enabled p1+++");

    if (rc_num)
    {
        FAPI_ERR( "mss_enable_periodic_cal: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    return rc;

}

ReturnCode mss_set_iml_complete (Target& i_target)
{
    //Target centaur

    //Set IML Complete
    //Variables
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num  = 0; 
    ecmdDataBufferBase data_buffer_64(64);

    rc = fapiGetScom(i_target, MBSSQ_0x02011417, data_buffer_64);
    if(rc) return rc;

    rc_num = rc_num | data_buffer_64.setBit(2);
    if (rc_num)
    {
        FAPI_ERR( "mss_set_iml_complete: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    rc = fapiPutScom(i_target, MBSSQ_0x02011417, data_buffer_64);
    if(rc) return rc;

    FAPI_INF("+++ IML Complete Enabled +++");
    return rc;
}

ReturnCode mss_enable_control_bit_ecc (Target& i_target)
{
    //Target centaur

    //Enable Control Bit ECC
    //Variables
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num  = 0;
    ecmdDataBufferBase ecc0_data_buffer_64(64);
    ecmdDataBufferBase ecc1_data_buffer_64(64);

    rc = fapiGetScom(i_target, MBS_ECC0_MBSECCQ_0x0201144A, ecc0_data_buffer_64);
    if(rc) return rc;

    rc = fapiGetScom(i_target, MBS_ECC1_MBSECCQ_0x0201148A, ecc0_data_buffer_64);
    if(rc) return rc;

    // Enable Memory ECC Check/Correct for MBA01
    // This assumes that all other settings of this register
    // are set in previous precedures or initfile. 
    rc_num = rc_num | ecc0_data_buffer_64.clearBit(0);
    rc_num = rc_num | ecc0_data_buffer_64.clearBit(1);

    // Enable Memory ECC Check/Correct for MBA23
    // This assumes that all other settings of this register
    // are set in previous precedures or initfile. 
    rc_num = rc_num | ecc1_data_buffer_64.clearBit(0);
    rc_num = rc_num | ecc1_data_buffer_64.clearBit(1);

    if (rc_num)
    {
        FAPI_ERR( "mss_enable_control_bit_ecc: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    rc = fapiPutScom(i_target, MBS_ECC0_MBSECCQ_0x0201144A, ecc0_data_buffer_64);
    if(rc) return rc;

    rc = fapiPutScom(i_target, MBS_ECC1_MBSECCQ_0x0201148A, ecc0_data_buffer_64);
    if(rc) return rc;

    FAPI_INF("+++ mss_enable_control_bit_ecc complete +++");
    return rc;
}

ReturnCode mss_enable_power_management (Target& i_target)
{
    // Target MBA
    //Enable Power Management
    //Variables
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num  = 0;
    ecmdDataBufferBase pm_data_buffer_64(64);

    rc = fapiGetScom(i_target, MBA01_PM0Q_0x03010434, pm_data_buffer_64);
    if(rc) return rc;

    // Enable power domain control
    // This assumes that all other settings of this register
    // are set in previous precedures or initfile. 
    rc_num = rc_num | pm_data_buffer_64.setBit(2);

    
    if (rc_num)
    {
        FAPI_ERR( "mss_enable_control_bit_ecc: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    rc = fapiPutScom(i_target, MBA01_PM0Q_0x03010434, pm_data_buffer_64);
    if(rc) return rc;

    FAPI_INF("+++ mss_enable_control_bit_ecc complete +++");
    return rc;
}

ReturnCode mss_ccs_mode_reset (Target& i_target)
{

    //Target MBA
    //Selects address data from the mainline
    //Variables
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num  = 0;
    ecmdDataBufferBase ccs_mode_data_buffer_64(64);

    rc = fapiGetScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, ccs_mode_data_buffer_64);
    if(rc) return rc;

    rc_num = rc_num | ccs_mode_data_buffer_64.clearBit(29);

    if (rc_num)
    {
        FAPI_ERR( "mss_enable_control_bit_ecc: Error setting up buffers");
        rc_buff.setEcmdError(rc_num);
        return rc_buff;
    }

    rc = fapiPutScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, ccs_mode_data_buffer_64);
    if(rc) return rc;

    FAPI_INF("+++ mss_ccs_mode_reset complete +++");
    return rc;
}

} //end extern C

