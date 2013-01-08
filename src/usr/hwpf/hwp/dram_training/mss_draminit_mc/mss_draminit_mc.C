/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_mc/mss_draminit_mc.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_draminit_mc.C,v 1.27 2012/12/21 20:39:08 gollub Exp $
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
//  1.27   | gollub   |21-DEC-12| Calling mss_unmask_maint_errors and mss_unmask_inband_errors after mss_draminit_mc_cloned
//  1.25   | jdsloat  |11-SEP-12| Changed Periodic Cal to Execute via MBA regs depending upon the ZQ Cal and MEM Cal timer values; 0 = disabled
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


ReturnCode mss_draminit_mc(Target& i_target)
{
    // Target is centaur.mba
    
    fapi::ReturnCode l_rc;
    
    l_rc = mss_draminit_mc_cloned(i_target);
    
	// If mss_unmask_maint_errors gets it's own bad rc,
	// it will commit the passed in rc (if non-zero), and return it's own bad rc.
	// Else if mss_unmask_maint_errors runs clean, 
	// it will just return the passed in rc.
	//l_rc = mss_unmask_maint_errors(i_target, l_rc); // TODO: uncomment after this can be tested on hw

	// If mss_unmask_inband_errors gets it's own bad rc,
	// it will commit the passed in rc (if non-zero), and return it's own bad rc.
	// Else if mss_unmask_inband_errors runs clean, 
	// it will just return the passed in rc.
	//l_rc = mss_unmask_inband_errors(i_target, l_rc); // TODO: uncomment after this can be tested on hw

	return l_rc;
}



ReturnCode mss_draminit_mc_cloned(Target& i_target)
{
// Target is centaur
//
    ReturnCode rc;
    std::vector<fapi::Target> l_mbaChiplets;
    uint32_t rc_num  = 0;

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

        // Step Three: Enable Refresh
        FAPI_INF( "+++ Enabling Refresh +++");
	ecmdDataBufferBase mba01_ref0q_data_buffer_64(64);
	rc = fapiGetScom(l_mbaChiplets[i], MBA01_REF0Q_0x03010432, mba01_ref0q_data_buffer_64);
	if(rc) return rc;
	//Bit 0 is enable		   
	rc_num = rc_num | mba01_ref0q_data_buffer_64.setBit(0);
	rc = fapiPutScom(l_mbaChiplets[i], MBA01_REF0Q_0x03010432, mba01_ref0q_data_buffer_64);
        if(rc)
        {
           FAPI_ERR("---Error During Refresh Enable rc = 0x%08X (creator = %d)---", uint32_t(rc), rc.getCreator());
           return rc;
        }
	if (rc_num)
	{
	    FAPI_ERR( "Refresh Enable: Error setting up buffers");
	    rc.setEcmdError(rc_num);
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

ReturnCode mss_enable_periodic_cal (Target& i_target)
{
    //Target MBA

    //Procedure to setup and enable periodic cals
    //Variables
    ReturnCode rc;
    ReturnCode rc_buff;
    uint32_t rc_num  = 0;

 
    ecmdDataBufferBase mba01_data_buffer_64_p0(64);
    ecmdDataBufferBase mba01_data_buffer_64_p1(64);

    ecmdDataBufferBase data_buffer_64(64);

    uint32_t memcal_iterval; //  00 = Disable
    rc = FAPI_ATTR_GET(ATTR_EFF_MEMCAL_INTERVAL, &i_target, memcal_iterval);
    if(rc) return rc;

    uint32_t zq_cal_iterval; //  00 = Disable
    rc = FAPI_ATTR_GET(ATTR_EFF_ZQCAL_INTERVAL, &i_target, zq_cal_iterval);
    if(rc) return rc;

    rc_num = rc_num | data_buffer_64.flushTo0();
    rc = fapiGetScom(i_target, MBA01_MBA_CAL0Q_0x0301040F, data_buffer_64);
    if(rc) return rc;

    FAPI_INF("+++ Enabling Periodic Calibration +++");

    if (zq_cal_iterval != 0)
    {
        //ZQ Cal Enabled
	rc_num = rc_num | data_buffer_64.setBit(0);
	FAPI_INF("+++ Periodic Calibration: ZQ Cal Enabled p0+++");
    }
    else
    {
        //ZQ Cal Disabled
	rc_num = rc_num | data_buffer_64.clearBit(0);
	FAPI_INF("+++ Periodic Calibration: ZQ Cal Disabled p0+++");
    }

    rc = fapiPutScom(i_target, MBA01_MBA_CAL0Q_0x0301040F, data_buffer_64);
    if(rc) return rc;

    rc_num = rc_num | data_buffer_64.flushTo0();
    rc = fapiGetScom(i_target, MBA01_MBA_CAL1Q_0x03010410, data_buffer_64);
    if (memcal_iterval != 0)
    {
        //Mem Cal Enabled
	rc_num = rc_num | data_buffer_64.setBit(0);
	FAPI_INF("+++ Periodic Calibration: Mem Cal Enabled p0+++");
    }
    else
    {
        //Mem Cal Disabled
	rc_num = rc_num | data_buffer_64.clearBit(0);
	FAPI_INF("+++ Periodic Calibration: Mem Cal Disabled p0+++");
    }
    rc = fapiPutScom(i_target, MBA01_MBA_CAL1Q_0x03010410, data_buffer_64);
    if(rc) return rc;

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

    rc = fapiGetScom(i_target, MBS_ECC1_MBSECCQ_0x0201148A, ecc1_data_buffer_64);
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

