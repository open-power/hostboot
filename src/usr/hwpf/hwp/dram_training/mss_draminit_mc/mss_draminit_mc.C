/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_mc/mss_draminit_mc.C $ */
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
// $Id: mss_draminit_mc.C,v 1.54 2016/02/29 15:07:56 sglancy Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : cen_draminit_mc.C
// *! DESCRIPTION : Procedure for handing over control to the MC
// *! OWNER NAME :  David Cadigan   Email: dcadiga@us.ibm.com
// *! BACKUP NAME : Jacob Sloat   Email: jdsloat@us.ibm.com
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
//  1.54   | sglancy  |29-FEB-16| Addressed FW comments - on leap day!
//  1.53   | sglancy  |12-FEB-16| Addressed FW comments
//  1.52   | sglancy  |07-DEC-15| Temporary: commented out call to RCD check code to workaround DDR4 ISRDIMM bug
//  1.51   | dcadiga  |18-MAR-15| Added function to enable address inversion on port 1
//  1.50   | gollub   |12-FEB-15| Changed maint cmd delay from 100mSec to 1mSec
//  1.49   | gollub   |12-FEB-15| Add check for RCD protect time on RDIMM and LRDIMM
//  1.48   | dcadiga  |05-DEC-14| Powerdown control at initfile
//  1.47   | dcadiga  |09-SEP-14| Removed SPARE cke disable step
//  1.46   | gollub   |07-APR-14| Removed call to mss_unmask_inband_errors (moved it to proc_cen_framelock)
//  1.45   | dcadiga  |14-FEB-14| Periodic Cal Fix for DD2
//  1.44   | bellows  |12-FEB-14| Workaround for ENABLE_RCE_WITH_OTHER_ERRORS_HW246685
//  1.43   | dcadiga  |28-OCT-13| Fixed code review comments for parent chip and typos
//  1.42   | dcadiga  |16-OCT-13| Fixed Code Review Comments, added DD2.X EC check for parity on 32GB
//  1.41   | dcadiga  |16-OCT-13| repeating Brent's test
//  1.40   | bwieman  |21-JUN-13| just testing a commit
//  1.39   | dcadiga  |21-JUN-13| Fixed Code Review Comments
//  1.38   | dcadiga  |10-JUN-13| Removed Local Edit Info, added version comment
//  1.37   | dcadiga  |10-JUN-13| Added Periodic Cal for 1.1
//  1.36   | dcadiga  |03-APR-13| Fixed compile warning
//  1.35   | dcadiga  |01-APR-13| Temp Fix For Parity Error on 32GB
//  1.34   | dcadiga  |12-MAR-13| Added spare cke disable as step 0
//  1.33   | dcadiga  |04-FEB-13| For some reason the main procedure call was commented out in the last commit... commenting it back in
//  1.32   | gollub   |31-JAN-13| Uncommenting mss_unmask_maint_errors and mss_unmask_inband_errors
//  1.31   | dcadiga  |21-JAN-13| Fixed variable name for memcal_interval (coded as memcal_iterval...)
//  1.30   | dcadiga  |21-JAN-13| Hardcoded memcal interval to 0 (disabled) until attribute for EC is available
//  1.29   | jdsloat  |14-JAN-13| Owner changed to Dave Cadigan.
//  1.28   | bellows  |01-JAN-13| Added ECC Enable 64-byte data/checkbit inversion (from jdsloat)
//  1.27   | gollub   |21-DEC-12| Calling mss_unmask_maint_errors and mss_unmask_inband_errors after mss_draminit_mc_cloned
//  1.26   | jdsloat  |21-NOV-12| Changed Periodic Cal to Execute via MBA regs depending upon the ZQ Cal and MEM Cal timer values; 0 = disabled
//  1.25   | jdsloat  |11-SEP-12| Calling mss_unmask_maint_errors and mss_unmask_inband_errors after mss_draminit_mc_cloned
//  1.24   | bellows  |16-JUL-12| added in Id tag
//  1.22   | bellows  |13-JUL-12| Fixed periodic cal bit 61 being set. HW214829
//  1.20   | jdsloat  |21-MAY-12| Typo fix, addresses moved to cen_scom_addresses.H, moved per cal settings to initfile
//  1.19   | jdsloat  |08-MAY-12| All Refresh controls moved to initfile, changed to just enable refresh
//  1.18   | jdsloat  |07-MAY-12| Fixed refresh interval, trfc, ref check interval bit ordering
//  1.16   | bellows  |04-MAY-12| Temporary remove of attr read of freq until method defined
//  1.15   | jdsloat  |16-APR-12| TRFC fixed to insert the right aligned 8 bits
//  1.15   | jdsloat  |12-Mar-12| Attribute upgrade for cronusflex 12.4 ... trfc to uint32
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

//----------------------------------------------------------------------
//  FAPI Includes
//----------------------------------------------------------------------
#include <fapi.H>

//----------------------------------------------------------------------
//  Centaur function Includes
//----------------------------------------------------------------------
#include <mss_funcs.H>
#include <mss_unmask_errors.H>

//----------------------------------------------------------------------
//  Address Includes
//----------------------------------------------------------------------
#include <cen_scom_addresses.H>


extern "C" {

using namespace fapi;


//----------------------------------------------------------------------
//  Subroutine declarations 
//----------------------------------------------------------------------
ReturnCode mss_draminit_mc_cloned(Target& i_target);
ReturnCode mss_start_refresh (Target& i_mbatarget, Target& i_centarget);
ReturnCode mss_enable_periodic_cal(Target& i_target);
ReturnCode mss_set_iml_complete(Target& i_target);
ReturnCode mss_enable_power_management(Target& i_target);
ReturnCode mss_enable_control_bit_ecc(Target& i_target);
ReturnCode mss_ccs_mode_reset(Target& i_target);
ReturnCode mss_check_RCD_protect_time(Target& i_target);
ReturnCode mss_spare_cke_disable(Target& i_target);
ReturnCode mss_enable_addr_inversion(Target& i_target);


ReturnCode mss_draminit_mc(Target& i_target)
{
    // Target is centaur.mba
    fapi::ReturnCode l_rc;
   //Commented back in by dcadiga 
    l_rc = mss_draminit_mc_cloned(i_target);
    //FAPI_INF("DID NOT RUN DRAMINIT MC\n");
	// If mss_unmask_maint_errors gets it's own bad rc,
	// it will commit the passed in rc (if non-zero), and return it's own bad rc.
	// Else if mss_unmask_maint_errors runs clean,
	// it will just return the passed in rc.
	l_rc = mss_unmask_maint_errors(i_target, l_rc);

	return l_rc;
}



ReturnCode mss_draminit_mc_cloned(Target& i_target)
{
// Target is centaur
//
    ReturnCode rc;
    std::vector<fapi::Target> l_mbaChiplets;
    uint32_t rc_num  = 0;
    uint8_t scom_parity_fixed_dd2 = 0;
    uint8_t dram_gen = 0;
    rc = FAPI_ATTR_GET(ATTR_CENTAUR_EC_SCOM_PARITY_ERROR_HW244827_FIXED, &i_target, scom_parity_fixed_dd2);
    if (rc) return rc;
    // Get associated MBA's on this centaur
    rc=fapiGetChildChiplets(i_target, fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
    if (rc) return rc;


    // Step Zero: Turn Off Spare CKE - This needs to be off before IML complete 
    // STEP COMMENTED FOR SW275629
    FAPI_INF("+++ Disabling Spare CKE FIX DISABLED +++");
    //for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
    //{
    //   rc = mss_spare_cke_disable(l_mbaChiplets[i]);
    //   if(rc)
    //   {
    //      FAPI_ERR("---Error During Spare CKE Disable rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
    //      return rc;
    //   }

    //}


    // Step One: Set IML COMPLETE
    FAPI_INF( "+++ Setting IML Complete +++");
    rc = mss_set_iml_complete(i_target);
    if(rc)
    {
       FAPI_ERR("---Error During IML Complete Enable rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
       return rc;
    }
    //DD1.X Scom Parity Fix HW244827
    if(!scom_parity_fixed_dd2)
    {
       FAPI_INF("+++DD1.X Centaur, clearing MBS Parity FIR +++");
       ecmdDataBufferBase parity_tmp_data_buffer_64(64);
       rc = fapiGetScom(i_target, MBS_FIR_REG_0x02011400, parity_tmp_data_buffer_64);
       if(rc) return rc;
       rc_num = rc_num | parity_tmp_data_buffer_64.clearBit(8);
       if(rc_num)
       {
           rc.setEcmdError(rc_num);
           return rc;
       }
       rc = fapiPutScom(i_target, MBS_FIR_REG_0x02011400, parity_tmp_data_buffer_64);
       if(rc)
       {
          FAPI_ERR("---Error During Clear Parity Bit rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
          return rc;
       }

    }
    // Loop through the 2 MBA's
    for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
    {
        
        
        rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &l_mbaChiplets[i], dram_gen);
        if (rc) return rc;
	
        // Step Two: Disable CCS address lines
        FAPI_INF( "+++ Disabling CCS Address Lines +++");
        rc = mss_ccs_mode_reset(l_mbaChiplets[i]);
        if(rc)
        {
           FAPI_ERR("---Error During CCS Mode Reset rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
           return rc;
        }


        // Step Two.1: Check RCD protect time on RDIMM and LRDIMM
        FAPI_INF( "+++ Check RCD protect time on RDIMM and LRDIMM +++");
	//forced this to only run if the test type is NOT DDR4 - as DDR4 ISRDIMMs are having IPL issues
	if(dram_gen != ENUM_ATTR_EFF_DRAM_GEN_DDR4) {
     	   rc = mss_check_RCD_protect_time(l_mbaChiplets[i]);
     	   if(rc)
     	   {
     	      FAPI_ERR("---Error During Check RCD protect time rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
     	      return rc;
     	   }
	}
	
	//Step Two.2: Enable address inversion on each MBA for ALL CARDS
	FAPI_INF("+++ Setting up adr inversion for port 1 +++");
	rc = mss_enable_addr_inversion(l_mbaChiplets[i]);
        if(rc)
        {
           FAPI_ERR("---Error During ADR Inversion rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
           return rc;
        }
	


        // Step Three: Enable Refresh
        FAPI_INF( "+++ Enabling Refresh +++");
	ecmdDataBufferBase mba01_ref0q_data_buffer_64(64);
	rc = fapiGetScom(l_mbaChiplets[i], MBA01_REF0Q_0x03010432, mba01_ref0q_data_buffer_64);
	if(rc) return rc;
	//Bit 0 is enable		   
	rc_num = rc_num | mba01_ref0q_data_buffer_64.setBit(0);
        if(rc_num)
        {
           rc.setEcmdError(rc_num);
           return rc;
        }
	rc = fapiPutScom(l_mbaChiplets[i], MBA01_REF0Q_0x03010432, mba01_ref0q_data_buffer_64);
        if(rc)
        {
           FAPI_ERR("---Error During Refresh Enable rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
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
        FAPI_INF( "+++ POWER MANAGEMENT HANDLED AT INITFILE +++");
        //Procedure commented out because domain reduction enablement now handled at the initfile
        //rc = mss_enable_power_management(l_mbaChiplets[i]);
        //if(rc)
        //{
        //   FAPI_ERR("---Error During Power Management Setup and Enable rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
        //   return rc;
        //}
  
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

ReturnCode mss_enable_periodic_cal (Target& i_target)
{
    //Target MBA

    //Procedure to setup and enable periodic cals
    //Variables
    ReturnCode rc;
    uint32_t rc_num  = 0;
    uint8_t bluewaterfall_broken = 0;
    uint8_t nwell_misplacement = 0;

    //Find Parent chip for EC check
    fapi::Target l_target_centaur;
    rc = fapiGetParentChip(i_target, l_target_centaur);
    if(rc) return rc;


 

    ecmdDataBufferBase data_buffer_64(64);

    uint32_t memcal_iterval; //  00 = Disable
    rc = FAPI_ATTR_GET(ATTR_EFF_MEMCAL_INTERVAL, &i_target, memcal_iterval);
    if(rc) return rc;
    //Determine what type of Centaur this is
    rc = FAPI_ATTR_GET(ATTR_MSS_BLUEWATERFALL_BROKEN, &l_target_centaur, bluewaterfall_broken);
    if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_NWELL_MISPLACEMENT, &l_target_centaur, nwell_misplacement);
    if(rc) return rc;



    if((bluewaterfall_broken == 0) && (nwell_misplacement == 0)){
       FAPI_INF("+++ Centaur is DD1.1 or later, enabling MEMCAL +++");
    }
    else{
       FAPI_INF("+++ RD Phase Select Workaround, DISABLING MEMCAL VIA HARDCODE +++");
       memcal_iterval = 0;
    }

    uint32_t zq_cal_iterval; //  00 = Disable
    rc = FAPI_ATTR_GET(ATTR_EFF_ZQCAL_INTERVAL, &i_target, zq_cal_iterval);
    if(rc) return rc;

    
    rc = fapiGetScom(i_target, MBA01_MBA_CAL0Q_0x0301040F, data_buffer_64);
    if(rc) return rc;

    FAPI_INF("+++ Enabling Periodic Calibration +++");

    if (zq_cal_iterval != 0)
    {
        //ZQ Cal Enabled
	rc_num = rc_num | data_buffer_64.setBit(0);
        if(rc_num)
        {
           rc.setEcmdError(rc_num);
           return rc;
        }
	FAPI_INF("+++ Periodic Calibration: ZQ Cal Enabled +++");
    }
    else
    {
        //ZQ Cal Disabled
	rc_num = rc_num | data_buffer_64.clearBit(0);
        if(rc_num)
        {
           rc.setEcmdError(rc_num);
           return rc;
        }
	FAPI_INF("+++ Periodic Calibration: ZQ Cal Disabled +++");
    }

    rc = fapiPutScom(i_target, MBA01_MBA_CAL0Q_0x0301040F, data_buffer_64);
    if(rc) return rc;


    if (memcal_iterval != 0)
    {



        uint8_t attr_centaur_ec_rdclk_pr_update_hw236658_fixed; 
        rc = FAPI_ATTR_GET(ATTR_CENTAUR_EC_RDCLK_PR_UPDATE_HW236658_FIXED, &i_target, attr_centaur_ec_rdclk_pr_update_hw236658_fixed);
        if(rc) return rc;

        if(!attr_centaur_ec_rdclk_pr_update_hw236658_fixed){
	
           //Check EC, Disable Phase Select Update for DD2 HW
           //Phase Select Fix for DD1.1
           rc_num = rc_num | data_buffer_64.flushTo0();
           rc_num = rc_num | data_buffer_64.setBit(52);
           if(rc_num)
           {
              rc.setEcmdError(rc_num);
              return rc;
           }
	
	
           rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_RD_DIA_CONFIG5_P0_0_0x800000120301143F,data_buffer_64);
           if(rc) return rc;
           rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_RD_DIA_CONFIG5_P0_1_0x800004120301143F,data_buffer_64);
           if(rc) return rc;
           rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_RD_DIA_CONFIG5_P0_2_0x800008120301143F,data_buffer_64);
           if(rc) return rc;
           rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_RD_DIA_CONFIG5_P0_3_0x80000C120301143F,data_buffer_64);
           if(rc) return rc;
           rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_RD_DIA_CONFIG5_P0_4_0x800010120301143F,data_buffer_64);
           if(rc) return rc;

           rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_RD_DIA_CONFIG5_P1_0_0x800100120301143F,data_buffer_64);
           if(rc) return rc;
           rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_RD_DIA_CONFIG5_P1_1_0x800104120301143F,data_buffer_64);
           if(rc) return rc;
           rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_RD_DIA_CONFIG5_P1_2_0x800108120301143F,data_buffer_64);
           if(rc) return rc;
           rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_RD_DIA_CONFIG5_P1_3_0x80010C120301143F,data_buffer_64);
           if(rc) return rc;
           rc = fapiPutScom(i_target,DPHY01_DDRPHY_DP18_RD_DIA_CONFIG5_P1_4_0x800110120301143F,data_buffer_64);
	
	
	}
	
	//Disable Periodic Read Centering for ALL HW
        rc_num = rc_num | data_buffer_64.flushTo0();
	if(rc_num)
        {
           rc.setEcmdError(rc_num);
           return rc;
        }
	rc = fapiGetScom(i_target,DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P0_0x8000C00B0301143F,data_buffer_64);
        rc_num = rc_num | data_buffer_64.clearBit(54);
	rc = fapiPutScom(i_target,DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P0_0x8000C00B0301143F,data_buffer_64);



        rc_num = rc_num | data_buffer_64.flushTo0();
	if(rc_num)
        {
           rc.setEcmdError(rc_num);
           return rc;
        }
	rc = fapiGetScom(i_target,DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P1_0x8001C00B0301143F,data_buffer_64);
        rc_num = rc_num | data_buffer_64.clearBit(54);
	rc = fapiPutScom(i_target,DPHY01_DDRPHY_PC_PER_CAL_CONFIG_P1_0x8001C00B0301143F,data_buffer_64);

        if(rc) return rc;


        //Mem Cal Enabled
        rc_num = rc_num | data_buffer_64.flushTo0();
        if(rc_num)
        {
           rc.setEcmdError(rc_num);
           return rc;
        }
        rc = fapiGetScom(i_target, MBA01_MBA_CAL1Q_0x03010410, data_buffer_64);
        if(rc) return rc;
	rc_num = rc_num | data_buffer_64.setBit(0);
        if(rc_num)
        {
           rc.setEcmdError(rc_num);
           return rc;
        }
	FAPI_INF("+++ Periodic Calibration: Mem Cal Enabled +++");
    }
    else
    {
        //Mem Cal Disabled
        rc_num = rc_num | data_buffer_64.flushTo0();
        if(rc_num)
        {
           rc.setEcmdError(rc_num);
           return rc;
        }
        rc = fapiGetScom(i_target, MBA01_MBA_CAL1Q_0x03010410, data_buffer_64);
        if(rc) return rc;
	rc_num = rc_num | data_buffer_64.clearBit(0);
        if(rc_num)
        {
           rc.setEcmdError(rc_num);
           return rc;
        }
	FAPI_INF("+++ Periodic Calibration: Mem Cal Disabled +++");
    }
    rc = fapiPutScom(i_target, MBA01_MBA_CAL1Q_0x03010410, data_buffer_64);
    if(rc) return rc;
    return rc;

}

ReturnCode mss_set_iml_complete (Target& i_target)
{
    //Target centaur

    //Set IML Complete
    //Variables
    ReturnCode rc;
    uint32_t rc_num  = 0; 
    ecmdDataBufferBase data_buffer_64(64);

    rc = fapiGetScom(i_target, MBSSQ_0x02011417, data_buffer_64);
    if(rc) return rc;

    rc_num = rc_num | data_buffer_64.setBit(2);
    if (rc_num)
    {
        FAPI_ERR( "mss_set_iml_complete: Error setting up buffers");
        rc.setEcmdError(rc_num);
        return rc;
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
    uint32_t rc_num  = 0;
    ecmdDataBufferBase ecc0_data_buffer_64(64);
    ecmdDataBufferBase ecc1_data_buffer_64(64);

    rc = fapiGetScom(i_target, MBS_ECC0_MBSECCQ_0x0201144A, ecc0_data_buffer_64);
    if(rc) return rc;

    rc = fapiGetScom(i_target, MBS_ECC1_MBSECCQ_0x0201148A, ecc1_data_buffer_64);
    if(rc) return rc;

    // Enable Memory ECC Check/Correct for MBA01
    // This assumes that all other settings of this register
    // are set in previous precedures or initfile. 
    rc_num = rc_num | ecc0_data_buffer_64.clearBit(0);
    rc_num = rc_num | ecc0_data_buffer_64.clearBit(1);
    rc_num = rc_num | ecc0_data_buffer_64.setBit(3);

    // Enable Memory ECC Check/Correct for MBA23
    // This assumes that all other settings of this register
    // are set in previous precedures or initfile. 
    rc_num = rc_num | ecc1_data_buffer_64.clearBit(0);
    rc_num = rc_num | ecc1_data_buffer_64.clearBit(1);
    rc_num = rc_num | ecc1_data_buffer_64.setBit(3);

    uint8_t attr_centaur_ec_enable_rce_with_other_errors_hw246685; 
    rc = FAPI_ATTR_GET(ATTR_CENTAUR_EC_ENABLE_RCE_WITH_OTHER_ERRORS_HW246685, &i_target, attr_centaur_ec_enable_rce_with_other_errors_hw246685);
    if(rc) return rc;

    if(attr_centaur_ec_enable_rce_with_other_errors_hw246685) {
      rc_num = rc_num | ecc0_data_buffer_64.setBit(16);
      rc_num = rc_num | ecc1_data_buffer_64.setBit(16);
    }

    if (rc_num)
    {
        FAPI_ERR( "mss_enable_control_bit_ecc: Error setting up buffers");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target, MBS_ECC0_MBSECCQ_0x0201144A, ecc0_data_buffer_64);
    if(rc) return rc;

    rc = fapiPutScom(i_target, MBS_ECC1_MBSECCQ_0x0201148A, ecc1_data_buffer_64);
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
        FAPI_ERR( "mss_enable_power_management: Error setting up buffers");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target, MBA01_PM0Q_0x03010434, pm_data_buffer_64);
    if(rc) return rc;

    FAPI_INF("+++ mss_enable_power_management complete +++");
    return rc;
}

ReturnCode mss_ccs_mode_reset (Target& i_target)
{

    //Target MBA
    //Selects address data from the mainline
    //Variables
    ReturnCode rc;
    uint32_t rc_num  = 0;
    ecmdDataBufferBase ccs_mode_data_buffer_64(64);

    rc = fapiGetScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, ccs_mode_data_buffer_64);
    if(rc) return rc;

    rc_num = rc_num | ccs_mode_data_buffer_64.clearBit(29);

    if (rc_num)
    {
        FAPI_ERR( "mss_ccs_mode_reset: Error setting up buffers");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target, CCS_MODEQ_AB_REG_0x030106A7, ccs_mode_data_buffer_64);
    if(rc) return rc;

    FAPI_INF("+++ mss_ccs_mode_reset complete +++");
    return rc;
}


ReturnCode mss_check_RCD_protect_time (Target& i_target)
{

    // Target MBA
    
    uint32_t l_ecmd_rc = 0; 
    fapi::ReturnCode l_rc;
    fapi::Target l_targetCentaur;
    uint8_t l_mbaPosition = 0;    
    uint8_t l_dimm_type = 0;
    uint8_t l_cfg_wrdone_dly = 0;
    uint8_t l_cfg_rdtag_dly = 0;
    uint8_t l_cfg_rcd_protection_time = 0;
    uint8_t l_highest_cfg_rcd_protection_time = 0;
    uint8_t l_max_cfg_rcd_protection_time = 0;
    uint8_t l_cmdType = 0x10; // DISPLAY, bit 0:5 = 10000b 
    uint8_t l_valid_dimms  = 0;
    uint8_t l_valid_dimm[2][2];
    uint8_t l_port=0;
    uint8_t l_dimm=0;
    uint8_t l_dimm_index = 0;

    std::vector<fapi::Target> l_target_dimm_array;
    uint8_t l_target_port = 0;
    uint8_t l_target_dimm = 0;

    // 1 ms delay for HW mode
    const uint64_t  HW_MODE_DELAY = 1000000;
    
    // 200000 sim cycle delay for SIM mode
    const uint64_t  SIM_MODE_DELAY = 200000;

    uint32_t l_mbeccfir_mask_or_address[2]={
    // port0/1                            port2/3
    MBS_ECC0_MBECCFIR_MASK_OR_0x02011445, MBS_ECC1_MBECCFIR_MASK_OR_0x02011485};

    uint32_t l_mbeccfir_and_address[2]={
    // port0/1                            port2/3
    MBS_ECC0_MBECCFIR_AND_0x02011441,  MBS_ECC0_MBECCFIR_AND_0x02011481};
    
    uint32_t l_mbeccfir_address[2]={
    // port0/1                            port2/3
    MBS_ECC0_MBECCFIR_0x02011440, MBS_ECC1_MBECCFIR_0x02011480};
      
    ecmdDataBufferBase l_mbeccfir_mask_or(64);  
    ecmdDataBufferBase l_mbeccfir_and(64);
    ecmdDataBufferBase l_mbeccfir(64);
    ecmdDataBufferBase l_mbacalfir_mask_or(64);
    ecmdDataBufferBase l_mbacalfir_mask_and(64);
    ecmdDataBufferBase l_mbacalfir_and(64);    
    ecmdDataBufferBase l_mbacalfir(64);        
    ecmdDataBufferBase l_mba_dsm0(64);    
    ecmdDataBufferBase l_mba_farb0(64);    
    ecmdDataBufferBase l_mbmct(64);    
    ecmdDataBufferBase l_mbmaca(64);    
    ecmdDataBufferBase l_mbasctl(64);
    ecmdDataBufferBase l_mbmcc(64);
    ecmdDataBufferBase l_mbafir(64);    
    ecmdDataBufferBase l_mbmsr(64);

    //------------------------------------------------------    
    // Get DIMM type        
    //------------------------------------------------------        
    l_rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, l_dimm_type);
    if(l_rc)
    {
        FAPI_ERR("Error getting ATTR_EFF_DIMM_TYPE on %s.",i_target.toEcmdString());
        return l_rc;
    }
    
    //------------------------------------------------------            
    // Only run on RDIMM or LRDIMM
    //------------------------------------------------------            
    if ((l_dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_RDIMM)||(l_dimm_type == ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM))
    {
        //------------------------------------------------------
        // Exit if parity error reporting disabled
        //------------------------------------------------------
        // NOTE: This is just to be safe, so we don't create errors in case the initfile is out of sync.
        // Read FARB0
        l_rc = fapiGetScom(i_target, MBA01_MBA_FARB0Q_0x03010413, l_mba_farb0);
        if(l_rc) return l_rc;
        
        if(l_mba_farb0.isBitSet(60))
        {
            FAPI_ERR("Exit mss_check_RCD_protect_time, since parity error reporting disabled on %s.",i_target.toEcmdString());
            return l_rc;
        }

        //------------------------------------------------------    
        // Get Centaur target for the given MBA
        //------------------------------------------------------
        l_rc = fapiGetParentChip(i_target, l_targetCentaur);
        if(l_rc)
        {
            FAPI_ERR("Error getting Centaur parent target for the given MBA on %s.",i_target.toEcmdString());
            return l_rc;
        }        

        //------------------------------------------------------
        // Get MBA position: 0 = mba01, 1 = mba23
        //------------------------------------------------------
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbaPosition);
        if(l_rc)
        {
            FAPI_ERR("Error getting MBA position on %s.",i_target.toEcmdString());
            return l_rc;
        } 

        //------------------------------------------------------
        // Find out which DIMMs are functional
        //------------------------------------------------------
        l_rc = FAPI_ATTR_GET(ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, &i_target, l_valid_dimms);
        if (l_rc)
        {
            FAPI_ERR("Failed to get attribute: ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR on %s.",i_target.toEcmdString());
            return l_rc;
        }
        l_valid_dimm[0][0] = (l_valid_dimms & 0x80); // port0, dimm0
        l_valid_dimm[0][1] = (l_valid_dimms & 0x40); // port0, dimm1
        l_valid_dimm[1][0] = (l_valid_dimms & 0x08); // port1, dimm0
        l_valid_dimm[1][1] = (l_valid_dimms & 0x04); // port1, dimm1


        //------------------------------------------------------ 
        // Mask MBECCFIR bit 45: maint RCD parity error
        //------------------------------------------------------    
        l_ecmd_rc |= l_mbeccfir_mask_or.flushTo0();
        // Set bit 45 in the OR mask
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(45);
        if(l_ecmd_rc)
        {
            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }
        // Write OR mask
        l_rc = fapiPutScom(l_targetCentaur, l_mbeccfir_mask_or_address[l_mbaPosition], l_mbeccfir_mask_or); 
        if(l_rc) return l_rc;


        //------------------------------------------------------ 
        // Mask MBACALFIR bits 4,7: port0,1 RCD parity error
        //------------------------------------------------------    
        l_ecmd_rc |= l_mbacalfir_mask_or.flushTo0();
        // Set bit 4,7 in the OR mask
        l_ecmd_rc |= l_mbacalfir_mask_or.setBit(4);
        l_ecmd_rc |= l_mbacalfir_mask_or.setBit(7);
        if(l_ecmd_rc)
        {
            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }
        // Write OR mask
        l_rc = fapiPutScom(i_target, MBA01_MBACALFIR_MASK_OR_0x03010405, l_mbacalfir_mask_or); 
        if(l_rc) return l_rc;


        //------------------------------------------------------ 
        // Find l_max_cfg_rcd_protection_time
        //------------------------------------------------------    
        l_rc = fapiGetScom(i_target, MBA01_MBA_DSM0_0x0301040a, l_mba_dsm0);
        if(l_rc) return l_rc;
        // Get 24:29 cfg_wrdone_dly
        l_ecmd_rc |= l_mba_dsm0.extractPreserve(&l_cfg_wrdone_dly, 24, 6, 8-6);
        // Get 36:41 cfg_rdtag_dly
        l_ecmd_rc |= l_mba_dsm0.extractPreserve(&l_cfg_rdtag_dly, 36, 6, 8-6);
        if(l_ecmd_rc)
        {
            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }

        // Pick lower of the two: cfg_wrdone_dly and cfg_rdtag_dly, and use that for l_max_cfg_rcd_protection_time
        if (l_cfg_wrdone_dly <= l_cfg_rdtag_dly)
        {
            l_max_cfg_rcd_protection_time = l_cfg_wrdone_dly;
        }
        else
        {
            l_max_cfg_rcd_protection_time = l_cfg_rdtag_dly;
        }                       
        
        //------------------------------------------------------ 
        // Maint cmd setup steps we can do once per MBA
        //------------------------------------------------------    

        // Load display cmd type: MBMCT, 0:5 = 10000b      
        l_rc = fapiGetScom(i_target, MBA01_MBMCTQ_0x0301060A, l_mbmct);
        if(l_rc) return l_rc;        
        l_ecmd_rc |= l_mbmct.insert(l_cmdType, 0, 5, 8-5 );
        if(l_ecmd_rc)
        {
            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }
        l_rc = fapiPutScom(i_target, MBA01_MBMCTQ_0x0301060A, l_mbmct);
        if(l_rc) return l_rc;

        // Clear all stop conditions in MBASCTL        
        l_rc = fapiGetScom(i_target, MBA01_MBASCTLQ_0x0301060F, l_mbasctl);
        if(l_rc) return l_rc;
        l_ecmd_rc |= l_mbasctl.clearBit(0,13);
        l_ecmd_rc |= l_mbasctl.clearBit(16);
        if(l_ecmd_rc)
        {
            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }
        l_rc = fapiPutScom(i_target, MBA01_MBASCTLQ_0x0301060F, l_mbasctl);
        if(l_rc) return l_rc;


        //------------------------------------------------------
        // For each port in the given MBA:0,1
        //------------------------------------------------------
        for(l_port=0; l_port<2; l_port++ )
        {
            //------------------------------------------------------
            // For each DIMM select on the given port:0,1
            //------------------------------------------------------            
            for(l_dimm=0; l_dimm<2; l_dimm++ )
            {
                //------------------------------------------------------
                // If DIMM valid
                //------------------------------------------------------            
                if (l_valid_dimm[l_port][l_dimm])
                {
                    //------------------------------------------------------ 
                    // Start with cfg_rcd_protection_time of 8
                    //------------------------------------------------------                     
                    l_cfg_rcd_protection_time = 8;

                    //------------------------------------------------------ 
                    // Clear MBECCFIR bit 45: maint RCD parity error
                    //------------------------------------------------------    
                    l_ecmd_rc |= l_mbeccfir_and.flushTo1();
                    // Clear bit 45 in the AND mask
                    l_ecmd_rc |= l_mbeccfir_and.clearBit(45);
                    if(l_ecmd_rc)
                    {
                        l_rc.setEcmdError(l_ecmd_rc);
                        return l_rc;
                    }
                    // Write AND mask
                    l_rc = fapiPutScom(l_targetCentaur, l_mbeccfir_and_address[l_mbaPosition], l_mbeccfir_and); 
                    if(l_rc) return l_rc;

                    //------------------------------------------------------ 
                    // Loop until we find a passing cfg_rcd_protection_time
                    //------------------------------------------------------    
                    do
                    {
                        //------------------------------------------------------ 
                        // Clear MBACALFIR bits 4,7: port0,1 RCD parity error
                        //------------------------------------------------------
                        // NOTE: Clearing these each time so they will be accrate for FFDC
                        l_ecmd_rc |= l_mbacalfir_and.flushTo1();
                        // Clear bit 4,7 in the AND mask
                        l_ecmd_rc |= l_mbacalfir_and.clearBit(4);
                        l_ecmd_rc |= l_mbacalfir_and.clearBit(7);
                        if(l_ecmd_rc)
                        {
                            l_rc.setEcmdError(l_ecmd_rc);
                            return l_rc;
                        }
                        // Write AND mask
                        l_rc = fapiPutScom(i_target, MBA01_MBACALFIR_AND_0x03010401, l_mbacalfir_and); 
                        if(l_rc) return l_rc;


                        //------------------------------------------------------ 
                        // Set l_cfg_rcd_protection_time
                        //------------------------------------------------------                            
                        // Read FARB0
                        l_rc = fapiGetScom(i_target, MBA01_MBA_FARB0Q_0x03010413, l_mba_farb0);
                        if(l_rc) return l_rc;
                        
                        // Set cfg_rcd_protection_time
                        l_ecmd_rc |= l_mba_farb0.insert( l_cfg_rcd_protection_time, 48, 6, 8-6 );
                                

                        //------------------------------------------------------ 
                        // Arm single shot RCD parity error for the given port
                        //------------------------------------------------------                            
                        // Select single shot
                        l_ecmd_rc |= l_mba_farb0.clearBit(59);                                
                        if(l_port == 0)
                        {
                            // Select port0 CAS
                            l_ecmd_rc |= l_mba_farb0.setBit(40);
                        }
                        else
                        {
                            // Select port1 CAS
                            l_ecmd_rc |= l_mba_farb0.setBit(42);
                        }                                
                        if(l_ecmd_rc)
                        {
                            l_rc.setEcmdError(l_ecmd_rc);
                            return l_rc;
                        }
                        // Write FARB0
                        l_rc = fapiPutScom(i_target, MBA01_MBA_FARB0Q_0x03010413, l_mba_farb0);
                        if(l_rc) return l_rc;


                        //------------------------------------------------------ 
                        // Do single address display cmd
                        //------------------------------------------------------    

                        // Load start address in MBMACA for the given DIMM
                        l_ecmd_rc |= l_mbmaca.flushTo0();                      
                        if(l_dimm == 1)
                        {
                            l_ecmd_rc |= l_mbmaca.setBit(1);
                        }
                        
                        if(l_ecmd_rc)
                        {
                            l_rc.setEcmdError(l_ecmd_rc);
                            return l_rc;
                        }                        
                        l_rc = fapiPutScom(i_target, MBA01_MBMACAQ_0x0301060D, l_mbmaca);
                        if(l_rc) return l_rc;
                        
                        // Start the command: MBMCCQ
                        l_ecmd_rc |= l_mbmcc.flushTo0();        
                        l_ecmd_rc |= l_mbmcc.setBit(0);
                        if(l_ecmd_rc)
                        {
                            l_rc.setEcmdError(l_ecmd_rc);
                            return l_rc;
                        }
                        l_rc = fapiPutScom(i_target, MBA01_MBMCCQ_0x0301060B, l_mbmcc);
                        if(l_rc) return l_rc;        

                        // Check for MBAFIR[1], invalid maint address.
                        l_rc = fapiGetScom(i_target, MBA01_MBAFIRQ_0x03010600, l_mbafir);
                        if(l_rc) return l_rc;
                        
                        if (l_mbafir.isBitSet(1))
                        {
                            FAPI_ERR("Display invalid address = 0x%.8X 0x%.8X, on port%d, dimm%d, %s.",
                            l_mbmaca.getWord(0), l_mbmaca.getWord(1), l_port, l_dimm, i_target.toEcmdString());

                            // Calling out FW high
                            // FFDC: MBA target
                            const fapi::Target & MBA = i_target;
                            // FFDC: Capture invalid address
                            ecmdDataBufferBase & MBMACA = l_mbmaca;
                            // FFDC: Capture FIR
                            ecmdDataBufferBase & MBAFIR = l_mbafir;
                            // Create new log
                            FAPI_SET_HWP_ERROR(l_rc, RC_MSS_DRAMINIT_MC_DISPLAY_INVALID_ADDR);
                            
                            return l_rc;                            
                        }

                        // Delay 1 mSec
                        fapiDelay(HW_MODE_DELAY, SIM_MODE_DELAY);

                        // See if MBMSRQ[0] maint cmd in progress bit if off
                        l_rc = fapiGetScom(i_target, MBA01_MBMSRQ_0x0301060C, l_mbmsr);
                        if(l_rc) return l_rc;

                        // If cmd still in progress
                        if (l_mbmsr.isBitSet(1))
                        {
                            FAPI_ERR("Display timeout on %s.",i_target.toEcmdString());

                            // Calling out FW high
                            // Calling out MBA target low, deconfig, gard
                            const fapi::Target & MBA = i_target;
                            // FFDC: Capture cmd type
                            ecmdDataBufferBase & MBMCT = l_mbmct;
                            // FFDC: Capture address
                            ecmdDataBufferBase & MBMACA = l_mbmaca;
                            // FFDC: Capture stop conditions
                            ecmdDataBufferBase & MBASCTL = l_mbasctl;
                            // FFDC: Capture stop/start control reg
                            ecmdDataBufferBase & MBMCC = l_mbmcc;
                            // FFDC: Capture Capture cmd in progress reg
                            ecmdDataBufferBase & MBMSR = l_mbmsr;
                            // FFDC: Capture FIR
                            ecmdDataBufferBase & MBAFIR = l_mbafir;
                            // Create new log
                            FAPI_SET_HWP_ERROR(l_rc, RC_MSS_DRAMINIT_MC_DISPLAY_TIMEOUT);
                            
                            return l_rc;
                        }
                    

                        // DEBUG Read MBACALFIR
                        l_rc = fapiGetScom(i_target, MBA01_MBACALFIR_0x03010400, l_mbacalfir); 
                        if(l_rc) return l_rc;
                        FAPI_DBG("DEBUG: MBACALFIR after RCD parity error inject = 0x%.8X 0x%.8X port%d, dimm%d, %s",
                        l_mbacalfir.getWord(0), l_mbacalfir.getWord(1), l_port, l_dimm, i_target.toEcmdString());


                        //------------------------------------------------------ 
                        // Check for MBECCFIR bit 45: maint RCD parity error
                        //------------------------------------------------------    

                        l_rc = fapiGetScom(l_targetCentaur, l_mbeccfir_address[l_mbaPosition], l_mbeccfir); 
                        if(l_rc) return l_rc;

                        // If FIR bit set
                        if (l_mbeccfir.isBitSet(45))
                        {                            
                            // Save highest value seen on this MBA
                            if (l_cfg_rcd_protection_time > l_highest_cfg_rcd_protection_time)
                            {
                                l_highest_cfg_rcd_protection_time = l_cfg_rcd_protection_time;
                            }
                            
                            break; // Exit do-while loop and move on to another DIMM
                        }
                        
                        // Else FIR not set
                        else
                        {                        
                            // Reached max_cfg_rcd_protection_time
                            if (l_cfg_rcd_protection_time == l_max_cfg_rcd_protection_time)
                            {
                                FAPI_ERR("Injected RCD parity error detected too late for RCD retry to be effective, max_cfg_rcd_protection_time=%d, port%d, dimm%d, %s",
                                 l_max_cfg_rcd_protection_time, l_port, l_dimm, i_target.toEcmdString());


                                //Read mbacalfir for FFDC                               
                                l_rc = fapiGetScom(i_target, MBA01_MBACALFIR_0x03010400, l_mbacalfir);
                                if(l_rc) return l_rc;

                                // Get DIMM targets for this MBA
                                l_rc = fapiGetAssociatedDimms(i_target, l_target_dimm_array);
                                if (l_rc)
                                {
                                    FAPI_ERR("Failed to get associated DIMMs on %s.",i_target.toEcmdString());
                                    return l_rc;
                                }
                                
                                // Find DIMM target for this l_port and l_dimm
                                for (l_dimm_index = 0; l_dimm_index < l_target_dimm_array.size(); l_dimm_index ++)
                                {
                                    l_rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &l_target_dimm_array[l_dimm_index], l_target_port);
                                    if (l_rc)
                                    {
                                        FAPI_ERR("Failed to get ATTR_MBA_PORT on %s.",i_target.toEcmdString());
                                        return l_rc;
                                    }

                                    l_rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &l_target_dimm_array[l_dimm_index], l_target_dimm);
                                    if (l_rc)
                                    {
                                        FAPI_ERR("Failed to get ATTR_MBA_DIMM on %s.",i_target.toEcmdString());
                                        return l_rc;
                                    }
                                    
                                    if ((l_target_port == l_port) && (l_target_dimm == l_dimm))
                                    {
                                        break; // Break out of for loop since we found the DIMM target for this l_port and l_dimm
                                    }
                                }


                                // Calling out DIMM high, deconfig, gard                                
                                const fapi::Target & DIMM = l_target_dimm_array[l_dimm_index];
                                // Calling out MBA target low, deconfig, gard
                                const fapi::Target & MBA = i_target;
                                // FFDC: PORT select: 0,1
                                uint8_t PORT_SELECT = l_port;
                                // FFDC: DIMM select: 0,1
                                uint8_t DIMM_SELECT = l_dimm;
                                // FFDC: MBS has to be told about RCD parity error before cfg_wrdone_dly so it knows to retry writes
                                uint8_t CFG_WRDONE_DLY = l_cfg_wrdone_dly;
                                // FFDC: MBS has to be told about RCD parity error before cfg_rdtag_dly so it knows to retry reads                                
                                uint8_t CFG_RDTAG_DLY = l_cfg_rdtag_dly;
                                // FFDC: Injected RCD parity error not detected within detected max_cfg_rcd_protection_time, so RCD retry not effective
                                uint8_t MAX_CFG_RCD_PROTECTION_TIME = l_max_cfg_rcd_protection_time;                                
                                // FFDC: Capture register with the RCD retry settings
                                ecmdDataBufferBase & MBA_FARB0 = l_mba_farb0;
                                // FFDC: Capture MBACALFIR to see if at least the MBA detected the injected RCD parity error
                                ecmdDataBufferBase & MBACALFIR = l_mbacalfir;
                                // Create new log
                                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_DRAMINIT_MC_INSUF_RCD_PROTECT_TIME);
                                // 'Commit' the log so we can keep running
                                fapiLogError(l_rc);
                                                                                                                               
                                break; // Exit do-while loop and move on to another DIMM
                            }
                            
                            // Else increment cfg_rcd_protection_time and try again
                            else
                            {                           
                                l_cfg_rcd_protection_time++;                        
                            }                        
                        }
                    }
                    while (1);
                    
                }// End if valid DIMM
            }// End for each DIMM select
        }// End for each port                                                


        //------------------------------------------------------ 
        // Clear MBECCFIR bit 45
        //------------------------------------------------------    
        l_ecmd_rc |= l_mbeccfir_and.flushTo1();
        // Clear bit 45 in the AND mask
        l_ecmd_rc |= l_mbeccfir_and.clearBit(45);
        if(l_ecmd_rc)
        {
            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }
        // Write AND mask
        l_rc = fapiPutScom(l_targetCentaur, l_mbeccfir_and_address[l_mbaPosition], l_mbeccfir_and); 
        if(l_rc) return l_rc;


        //------------------------------------------------------ 
        // Clear MBACALFIR bits 4,7: port0,1 RCD parity error
        //------------------------------------------------------    
        l_ecmd_rc |= l_mbacalfir_and.flushTo1();
        // Clear bit 4,7 in the AND mask
        l_ecmd_rc |= l_mbacalfir_and.clearBit(4);
        l_ecmd_rc |= l_mbacalfir_and.clearBit(7);
        if(l_ecmd_rc)
        {
            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }
        // Write AND mask
        l_rc = fapiPutScom(i_target, MBA01_MBACALFIR_AND_0x03010401, l_mbacalfir_and); 
        if(l_rc) return l_rc;


        //------------------------------------------------------ 
        // Unmask MBACALFIR bits 4,7: port0,1 RCD parity error
        //------------------------------------------------------    
        l_ecmd_rc |= l_mbacalfir_mask_and.flushTo1();
        // Set bit 4,7 in the AND mask
        l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(4);
        l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(7);
        if(l_ecmd_rc)
        {
            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }
        // Write AND mask
        l_rc = fapiPutScom(i_target, MBA01_MBACALFIR_MASK_AND_0x03010404, l_mbacalfir_mask_and); 
        if(l_rc) return l_rc;


        //------------------------------------------------------ 
        // Load l_highest_cfg_rcd_protection_time
        //------------------------------------------------------    
        // NOTE: We are loading highest_cfg_rcd_protection_time here just so we can stop after mss_draminit_mc and read out the values from the hw as a way to debug
        // NOTE: The final value we want to load is max_cfg_rcd_protection_time, which we will do in mss_thermal_init, before we enable RCD recovery.
        // NOTE: If no DIMM on this MBA passed, highest_cfg_rcd_protection_time will be 0
        
        // Read FARB0
        l_rc = fapiGetScom(i_target, MBA01_MBA_FARB0Q_0x03010413, l_mba_farb0);
        if(l_rc) return l_rc;        
        // Set highest_cfg_rcd_protection_time
        l_ecmd_rc |= l_mba_farb0.insert( l_highest_cfg_rcd_protection_time, 48, 6, 8-6 );
        if(l_ecmd_rc)
        {
            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }
        // Write FARB0
        l_rc = fapiPutScom(i_target, MBA01_MBA_FARB0Q_0x03010413, l_mba_farb0);
        if(l_rc) return l_rc;

        
    } // End if RDIMM or LRDIMM



    FAPI_INF("+++ mss_check_RCD_protect_time complete +++");
    return l_rc;
}


ReturnCode mss_spare_cke_disable (Target& i_target)
{

    //Target MBA
    //Selects address data from the mainline
    //Variables
    ReturnCode rc;
    uint32_t rc_num  = 0;
    ecmdDataBufferBase spare_cke_data_buffer_64(64);

    //Setup SPARE CKE enable bit
    rc = fapiGetScom(i_target, MBA01_MBARPC0Q_0x03010434, spare_cke_data_buffer_64);
    if(rc) return rc;
    rc_num = rc_num | spare_cke_data_buffer_64.clearBit(42);
    if(rc_num)
    {
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target, MBA01_MBARPC0Q_0x03010434, spare_cke_data_buffer_64);
    if(rc) return rc;


    FAPI_INF("+++ mss_spare_cke_disable complete +++");
    return rc;
}

ReturnCode mss_enable_addr_inversion (Target& i_target)
{

    //Target MBA
    //Sets address inversion on port 1 of an MBA
    //Variables
    ReturnCode rc;
    uint32_t rc_num  = 0;
    ecmdDataBufferBase MBA_FARB0_DB_64(64);

    //Set bit 56 for adr inversion on port 1
    rc = fapiGetScom(i_target, MBA01_MBA_FARB0Q_0x03010413, MBA_FARB0_DB_64);
    if(rc) return rc;
    rc_num = rc_num | MBA_FARB0_DB_64.setBit(56);
    if(rc_num)
    {
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target, MBA01_MBA_FARB0Q_0x03010413, MBA_FARB0_DB_64);
    if(rc) return rc;


    FAPI_INF("+++ mss_enable_addr_inversion complete +++");
    return rc;
}



} //end extern C

