/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_termination_control.C $    */
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
// $Id: mss_termination_control.C,v 1.13 2012/12/18 15:00:36 mwuu Exp $
/* File is created by SARAVANAN SETHURAMAN on Thur 29 Sept 2011. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE :mss_draminit_training_advanced.C
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME : Saravanan Sethuraman          email ID:saravanans@in.ibm.com
// *! BACKUP NAME: Menlo Wuu	 	         email ID:menlowuu@us.ibm.com
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
//  1.13   | mwuu	  |18-Dec-12| Took out initialization of array_rcs in declaration.
//  1.12   | mwuu	  |14-Dec-12| Updated additional fw review comments
//  1.11   | sasethur |07-Dec-12| Updated for fw review comments
//  1.10   | mwuu     |28-Nov-12| Added changes suggested from FW team.
//  1.9    | mwuu     |20-Nov-12| Changed warning status to not cause error.
//  1.8    | sasethur |19-Nov-12| Updated for fw review comments
//  1.7	   | mwuu     |14-Nov-12| Switched some old attributes to new, added
//  							  Partial good support in slew_cal FN.
//  1.6    | bellows  |13-Nov-12| SI attribute Updates
//  1.5    | mwuu     |29-Oct-12| fixed config_drv_imp missed a '&'
//  1.4    | mwuu     |26-Oct-12| Added mss_slew_cal FN, not 100% complete
//  1.3    | sasethur |26-Oct-12| Updated FW review comments - fapi::, const fapi:: Target
//  1.2    | mwuu     |17-Oct-12| Updated return codes to use common error, also
//                                updates to the slew function
//  1.1    | sasethur |15-Oct-12| Functions defined & moved from training adv,
//  							  Menlo upated slew function

// Saravanan - Yet to update DRV_IMP new attribute enum change

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
#include <cen_scom_addresses.H>
#include <mss_draminit_training_advanced.H>

/*------------------------------------------------------------------------------
 * Function: config_drv_imp()
 * This function will configure the Driver impedance values to the registers
 *
 * Parameters: target: mba;		port: 0, 1
 * Driver_imp: OHM24 = 24, OHM30 = 30, OHM34 = 34, OHM40 = 40
 * ---------------------------------------------------------------------------*/

fapi::ReturnCode config_drv_imp(const fapi::Target & i_target_mba, uint8_t i_port, uint8_t i_drv_imp_dq_dqs)
{

    ecmdDataBufferBase data_buffer(64);
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;
    uint8_t enslice_drv = 0xFF;
    uint8_t enslice_ffedrv = 0xF;
    uint8_t i = 0;

    //Driver impedance settings are per PORT basis

    if (i_port > 1)
    {
	FAPI_ERR("Driver impedance port input(%u) out of bounds", i_port);
	FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
	return rc;
    }
    for(i=0; i< MAX_DRV_IMP; i++)
    {
	if (drv_imp_array[i] == i_drv_imp_dq_dqs)
	{
	    switch (i)
	    {
		case 0:   //40 ohms
		enslice_drv = 0x3C;
		enslice_ffedrv =0xF;
		break;
		case 1:   //34 ohms
		enslice_drv = 0x7C;
		enslice_ffedrv =0xF;
		break;
		case 2:  //30 ohms
		enslice_drv = 0x7E;
		enslice_ffedrv = 0xF;
		break;
		case 3:   //24 ohms
		enslice_drv = 0xFF;
		enslice_ffedrv = 0xF;
		break;
            }
	break;
	}
    }

    if (i_port == 0)
    {
        rc = fapiGetScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_0_0x800000780301143F,
		    data_buffer); if(rc) return rc;
	rc_num = data_buffer.insertFromRight(enslice_drv,48,8);
        rc_num = rc_num | data_buffer.insertFromRight(enslice_ffedrv,56,4);
        if (rc_num)
        {
            FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
            rc.setEcmdError(rc_num);
            return rc;
        }
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_0_0x800000780301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_1_0x800004780301143F,
		    data_buffer); if(rc) return rc;
        rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_2_0x800008780301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_3_0x80000C780301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_4_0x800010780301143F,
		    data_buffer); if(rc) return rc;
       	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_0_0x800000790301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_1_0x800004790301143F,
		    data_buffer); if(rc) return rc;
        rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_2_0x800008790301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_3_0x80000C790301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_4_0x800010790301143F,
		    data_buffer); if(rc) return rc;
    }
    else    // Port = 1
    {
        rc = fapiGetScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_0_0x800100780301143F,
		    data_buffer); if(rc) return rc;
	rc_num = data_buffer.insertFromRight(enslice_drv,48,8);
        rc_num = rc_num | data_buffer.insertFromRight(enslice_ffedrv,56,4);
        if (rc_num)
        {
            FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
            rc.setEcmdError(rc_num);
            return rc;
        }
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_0_0x800100780301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_1_0x800104780301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_2_0x800108780301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_3_0x80010C780301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_4_0x800110780301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_0_0x800100790301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_1_0x800104790301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_2_0x800108790301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_3_0x80010C790301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_4_0x800110790301143F,
		    data_buffer); if(rc) return rc;
    }
    return rc;
}


/*------------------------------------------------------------------------------
 * Function: config_rcv_imp()
 * This function will configure the Receiver impedance values to the registers
 *
 * Parameters: target: mba;		port: 0, 1
 * receiver_imp:OHM15 = 15, OHM20 = 20, OHM30 = 30, OHM40 = 40, OHM48 = 48,
 * OHM60 = 60,  OHM80 = 80, OHM120 = 120, OHM160 = 160, OHM240 = 240
 * ---------------------------------------------------------------------------*/

fapi::ReturnCode config_rcv_imp(const fapi::Target & i_target_mba, uint8_t i_port, uint8_t i_rcv_imp_dq_dqs)
{

    ecmdDataBufferBase data_buffer(64);
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;
    uint8_t enslicepterm = 0xFF;
    uint8_t enslicepffeterm = 0;
    uint8_t i = 0;

    if (i_port > 1)
    {
	FAPI_ERR("Receiver impedance port input(%u) out of bounds", i_port);
	FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
	return rc;
    }


    for(i=0; i< MAX_RCV_IMP; i++)
    {
	if (rcv_imp_array[i] == i_rcv_imp_dq_dqs)
	{
            switch (i)
   	    {
 		case 0:  //120 OHMS
		enslicepterm = 0x10;
		enslicepffeterm =0x0;
		break;
	        case 1:   //80 OHMS
		enslicepterm = 0x10;
		enslicepffeterm =0x2;
		break;
	        case 2:   //60 OHMS
		enslicepterm = 0x18;
		enslicepffeterm =0x0;
		break;
	        case 3:   //48 OHMS
		enslicepterm = 0x18;
		enslicepffeterm =0x2;
		break;
	        case 4:   //40 OHMS
		enslicepterm = 0x18;
		enslicepffeterm =0x6;
		break;
	        case 5:   //34 OHMS
		enslicepterm = 0x38;
		enslicepffeterm =0x2;
		break;
	        case 6:   //30 OHMS
		enslicepterm = 0x3C;
		enslicepffeterm =0x0;
		break;
	        case 7:   //20 OHMS
		enslicepterm = 0x7E;
		enslicepffeterm = 0x0;
		break;
  	        case 8:    //15 OHMS
		enslicepterm = 0xFF;
		enslicepffeterm = 0x0;
		break;
 	    }
	break;
	}
    }


    if (i_port == 0)
    {
        rc = fapiGetScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_0_0x8000007A0301143F,
		    data_buffer); if(rc) return rc;
	rc_num = data_buffer.insertFromRight(enslicepterm,48,8);
        rc_num = rc_num | data_buffer.insertFromRight(enslicepffeterm,56,4);
        if (rc_num)
        {
            FAPI_ERR( "config_drv_imp: Error in setting up buffer ");
            rc.setEcmdError(rc_num);
            return rc;
        }
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_0_0x8000007A0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_1_0x8000047A0301143F,
		    data_buffer); if(rc) return rc;
        rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_2_0x8000087A0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_3_0x80000C7A0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P0_4_0x8000107A0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P0_0_0x8000007B0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P0_1_0x8000047B0301143F,
		    data_buffer); if(rc) return rc;
        rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P0_2_0x8000087B0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P0_3_0x80000C7B0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P0_4_0x8000107B0301143F,
		    data_buffer); if(rc) return rc;
    }
    else
    {
        rc = fapiGetScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_0_0x8001007A0301143F,
		    data_buffer); if(rc) return rc;
	rc_num = data_buffer.insertFromRight(enslicepterm,48,8);
        rc_num = rc_num | data_buffer.insertFromRight(enslicepffeterm,56,4);
        if (rc_num)
        {
            FAPI_ERR( "config_drv_imp: Error in setting up buffer ");
            rc.setEcmdError(rc_num);
            return rc;
        }
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_0_0x8001007A0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_1_0x8001047A0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_2_0x8001087A0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_3_0x80010C7A0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_NFET_TERM_P1_4_0x8001107A0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P1_0_0x8001007B0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P1_1_0x8001047B0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P1_2_0x8001087B0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P1_3_0x80010C7B0301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_IO_TX_PFET_TERM_P1_4_0x8001107B0301143F,
		    data_buffer); if(rc) return rc;
    }
    return rc;
}

/*------------------------------------------------------------------------------
 * Function: config_slew_rate()
 * This function will configure the Slew rate values to the registers
 *
 * Parameters: target: mba;		port: 0, 1
 * i_slew_type: SLEW_TYPE_DATA=0, SLEW_TYPE_ADR_ADDR=1, SLEW_TYPE_ADR_CNTL=2
 * i_slew_imp: OHM15=15, OHM20=20, OHM24=24, OHM30=30, OHM34=34, OHM40=40
 *		note: 15, 20, 30, 40 valid for ADR; 24, 30, 34, 40 valid for DATA
 * i_slew_rate: SLEW_3V_NS=3, SLEW_4V_NS=4, SLEW_5V_NS=5, SLEW_6V_NS=6,
 * SLEW_MAXV_NS=7 (note SLEW_MAXV_NS bypasses slew calibration.)
 * ---------------------------------------------------------------------------*/
fapi::ReturnCode config_slew_rate(const fapi::Target & i_target_mba,
	const uint8_t i_port, const uint8_t i_slew_type, const uint8_t i_slew_imp,
	const uint8_t i_slew_rate)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data_buffer(64);
    uint32_t rc_num = 0;
    uint8_t slew_cal_value = 0;
    uint8_t imp_idx = 255;
    uint8_t slew_idx = 255;
    // array for ATTR_MSS_SLEW_RATE_DATA/ADR [2][4][4]
	// port,imp,slew_rat	cal'd slew settings
    uint8_t calibrated_slew_rate_table
		[MAX_NUM_PORTS][MAX_NUM_IMP][MAX_NUM_CAL_SLEW_RATES]={{{0}}};

    if (i_port >= MAX_NUM_PORTS)
    {
	FAPI_ERR("Slew port input(%u) out of bounds", i_port);
	FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
	return rc;
    }

    if (i_slew_type >= MAX_NUM_SLEW_TYPES)
    {
	FAPI_ERR("Slew type input(%u) out of bounds, (>= %u)",
			i_slew_type, MAX_NUM_SLEW_TYPES);
	FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
	return rc;
    }

	switch (i_slew_rate)		// get slew index
	{
	case SLEW_MAXV_NS:			// max slew
		FAPI_INF("Slew rate is set to MAX, using bypass mode");
		slew_cal_value = 0;		// slew cal value for bypass mode
		break;
	case SLEW_6V_NS:
		slew_idx = 3;
		break;
	case SLEW_5V_NS:
		slew_idx = 2;
		break;
	case SLEW_4V_NS:
		slew_idx = 1;
		break;
	case SLEW_3V_NS:
		slew_idx = 0;
		break;
	default:
		FAPI_ERR("Slew rate input(%u) out of bounds", i_slew_rate);
		FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
	return rc;
    }

    if (i_slew_type == SLEW_TYPE_DATA)
    {
		FAPI_INF("Setting data (dq/dqs) slew");
        switch (i_slew_imp)		// get impedance index for data
   	    {
 		case OHM40:
			imp_idx = 3;
			break;
		case OHM34:
			imp_idx = 2;
			break;
		case OHM30:
			imp_idx = 1;
			break;
		case OHM24:
			imp_idx = 0;
			break;
		default:			// OHM15 || OHM20 not valid for data
	    	FAPI_ERR("Slew impedance input(%u) invalid "
			   "or out of bounds, index=%u", i_slew_imp, imp_idx);
		    FAPI_SET_HWP_ERROR(rc, RC_MSS_IMP_INPUT_ERROR);
	    	return rc;
		}

	if (i_slew_rate != SLEW_MAXV_NS)
	{
		rc = FAPI_ATTR_GET(ATTR_MSS_SLEW_RATE_DATA, &i_target_mba,
			calibrated_slew_rate_table); if(rc) return rc;

		slew_cal_value =
			calibrated_slew_rate_table[i_port][imp_idx][slew_idx];
	}

	FAPI_DBG("port%u type=%u imp_idx=%u slew_idx=%u cal_slew=%u",
			i_port, i_slew_type, imp_idx, slew_idx, slew_cal_value);

	if (slew_cal_value > MAX_SLEW_VALUE)
	{
	    FAPI_ERR("!! Slew rate(0x%02x) unsupported, but continuining... !!",
				slew_cal_value);
		slew_cal_value = slew_cal_value & 0x0F;
	}

	if (i_port == 0)	// port dq/dqs slew
	{
	    rc = fapiGetScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_0_0x800000750301143F,
			data_buffer); if(rc) return rc;

	    rc_num = rc_num | data_buffer.insertFromRight(slew_cal_value, 56, 4);
	    if (rc_num)
	    {
		FAPI_ERR("Error in setting up DATA slew buffer");
			rc.setEcmdError(rc_num);
			return rc;
	    }

	    rc = fapiPutScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_0_0x800000750301143F,
			data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_1_0x800004750301143F,
			data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_2_0x800008750301143F,
			data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_3_0x80000C750301143F,
			data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P0_4_0x800010750301143F,
			data_buffer); if(rc) return rc;
	    }
	else	// port 1 dq/dqs slew
	{
	    rc = fapiGetScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_0_0x800100750301143F,
			data_buffer); if(rc) return rc;

	    rc_num = rc_num | data_buffer.insertFromRight(slew_cal_value,56,4);
	    if (rc_num)
	    {
		FAPI_ERR( "Error in setting up DATA slew buffer");
		rc.setEcmdError(rc_num);
		return rc;
	    }

	    rc = fapiPutScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_0_0x800100750301143F,
			data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_1_0x800104750301143F,
			data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_2_0x800108750301143F,
			data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_3_0x80010C750301143F,
			data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
			DPHY01_DDRPHY_DP18_IO_TX_CONFIG0_P1_4_0x800110750301143F,
			data_buffer); if(rc) return rc;
	    }
	}
    else	// Slew type = ADR
    {
	uint8_t adr_pos = 48;	// SLEW_CTL0(48:51) of reg for ADR command slew

	switch (i_slew_type)		// get impedance index for data
   	{
 	case SLEW_TYPE_ADR_ADDR:
		// CTL0 for command slew (A0:15, BA0:3, ACT, PAR, CAS, RAS, WE)
	    FAPI_INF("Setting ADR command/address slew in CTL0 register");
		adr_pos = 48;
		break;
 	case SLEW_TYPE_ADR_CNTL:
		// CTL1 for control slew (CKE0:1, CKE4:5, ODT0:3, CSN0:3)
	    FAPI_INF("Setting ADR control slew in CTL1 register");
		adr_pos = 52;
		break;
	case SLEW_TYPE_ADR_CLK:
		// CTL2 for clock slew (CLK0:3)
	    FAPI_INF("Setting ADR clock slew in CTL2 register");
		adr_pos = 56;
		break;
 	case SLEW_TYPE_ADR_SPCKE:
		// CTL3 for spare clock  slew (CKE2:3)
	    FAPI_INF("Setting ADR Spare clock in CTL3 register");
		adr_pos = 60;
		break;
	}
	for(uint8_t i=0; i < MAX_NUM_IMP; i++)	// find ADR imp index
	{
	    if (adr_imp_array[i] == i_slew_imp)
		{
		    imp_idx = i;
		    break;
		}
	}
	if ((i_slew_imp == OHM24) || (i_slew_imp == OHM34) ||
		(imp_idx >= MAX_NUM_IMP))
	{
		FAPI_ERR("Slew impedance input(%u) out of bounds", i_slew_imp);
	    FAPI_SET_HWP_ERROR(rc, RC_MSS_IMP_INPUT_ERROR);
	    return rc;
	}

	if (i_slew_rate == SLEW_MAXV_NS)
	{
		slew_cal_value = 0;
	}
	else
	{
		rc = FAPI_ATTR_GET(ATTR_MSS_SLEW_RATE_ADR, &i_target_mba,
			calibrated_slew_rate_table); if(rc) return rc;

	    slew_cal_value =
			calibrated_slew_rate_table[i_port][imp_idx][slew_idx];
	}
	FAPI_DBG("port%u type=%u slew_idx=%u imp_idx=%u cal_slew=%u",
			i_port, i_slew_type, slew_idx, imp_idx, slew_cal_value);

    if (slew_cal_value > MAX_SLEW_VALUE)
	{
	    FAPI_ERR("!! Slew rate(0x%02x) unsupported, but continuing... !!",
				slew_cal_value);
	    slew_cal_value = slew_cal_value & 0x0F;
	}

	if (i_port == 0)
	{
   	    rc = fapiGetScom(i_target_mba,
			DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR0_0x8000401A0301143F,
			data_buffer); if(rc) return rc;

	    rc_num |= data_buffer.insertFromRight(slew_cal_value, adr_pos, 4);
	    if (rc_num)
	    {
	        FAPI_ERR( "Error in setting up ADR slew buffer");
	        rc.setEcmdError(rc_num);
	        return rc;
	    }

	    rc = fapiPutScom(i_target_mba,
		DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR0_0x8000401A0301143F,
		data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
		DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR1_0x8000441A0301143F,
		data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
		DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR2_0x8000481A0301143F,
		data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
		DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR3_0x80004C1A0301143F,
		data_buffer); if(rc) return rc;
        }
        else	// port 1 ADR slew
        {
   	    rc = fapiGetScom(i_target_mba,
		DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR0_0x8001401A0301143F,
		data_buffer); if(rc) return rc;

	    rc_num |= data_buffer.insertFromRight(slew_cal_value, adr_pos, 4);
	    if (rc_num)
	    {
	        FAPI_ERR( "Error in setting up ADR slew buffer");
	        rc.setEcmdError(rc_num);
	        return rc;
	    }
	    rc = fapiPutScom(i_target_mba,
		DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR0_0x8001401A0301143F,
		data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
		DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR1_0x8001441A0301143F,
		data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
		DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR2_0x8001481A0301143F,
		data_buffer); if(rc) return rc;
	    rc = fapiPutScom(i_target_mba,
		DPHY01_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR3_0x80014C1A0301143F,
		data_buffer); if(rc) return rc;
        }
    }
    return rc;
}

/*------------------------------------------------------------------------------
 * Function: config_wr_dram_vref()
 * This function configures PC_VREF_DRV_CONTROL registers to vary the DIMM VREF
 *
 * Parameters: target: mba;		port: 0, 1
 * Wr_dram_vref: VDD420 = 420, VDD425 = 425, VDD430 = 430, VDD435 = 435, VDD440 = 440,
 * VDD445 = 445, VDD450 = 450, VDD455 = 455, VDD460 = 460, VDD465 = 465, VDD470 = 470,
 * VDD475 = 475, VDD480 = 480, VDD485 = 485, VDD490 = 490, VDD495 = 495, VDD500 = 500,
 * VDD505 = 505, VDD510 = 510, VDD515 = 515, VDD520 = 520, VDD525 = 525, VDD530 = 530,
 * VDD535 = 535, VDD540 = 540, VDD545 = 545, VDD550 = 550, VDD555 = 555, VDD560 = 560,
 * VDD565 = 565, VDD570 = 570, VDD575 = 575
 * ---------------------------------------------------------------------------*/

fapi::ReturnCode config_wr_dram_vref(const fapi::Target & i_target_mba, uint8_t i_port, uint32_t i_wr_dram_vref)
{

    ecmdDataBufferBase data_buffer(64);
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;
    uint32_t pcvref = 0;
    uint32_t i = 0;

    // For DDR3 vary from VDD*0.42 to VDD*575
    // For DDR4 internal voltage is there this function is not required
    if (i_port > 1)
    {
	FAPI_ERR("Write Vref port input(%u) out of bounds", i_port);
	FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
	return rc;
    }
    for(i=0; i< MAX_WR_VREF; i++)
    {
	if (wr_vref_array[i] == i_wr_dram_vref)
	{
            pcvref = i;
	    break;
	}
    }

    if (i_port == 0)
    {
	rc = fapiGetScom(i_target_mba, DPHY01_DDRPHY_PC_VREF_DRV_CONTROL_P0_0x8000C0150301143F, data_buffer); if(rc) return rc;
        rc_num = rc_num | data_buffer.insertFromRight(pcvref,48,5);
        rc_num = rc_num | data_buffer.insertFromRight(pcvref,53,5);
        if (rc_num)
        {
            FAPI_ERR( "config_wr_vref: Error in setting up buffer ");
	    rc.setEcmdError(rc_num);
            return rc;
        }
	rc = fapiPutScom(i_target_mba, DPHY01_DDRPHY_PC_VREF_DRV_CONTROL_P0_0x8000C0150301143F, data_buffer); if(rc) return rc;
    }
    else
    {
	rc = fapiGetScom(i_target_mba, DPHY01_DDRPHY_PC_VREF_DRV_CONTROL_P1_0x8001C0150301143F, data_buffer); if(rc) return rc;
        rc_num = rc_num | data_buffer.insertFromRight(pcvref,48,5);
        rc_num = rc_num | data_buffer.insertFromRight(pcvref,53,5);
        if (rc_num)
        {
            FAPI_ERR( "config_wr_vref: Error in setting up buffer ");
	    rc.setEcmdError(rc_num);
            return rc;
        }
	rc = fapiPutScom(i_target_mba, DPHY01_DDRPHY_PC_VREF_DRV_CONTROL_P1_0x8001C0150301143F, data_buffer); if(rc) return rc;
    }
    return rc;
}
/*------------------------------------------------------------------------------
 * Function: config_rd_cen_vref()
 * This function configures read vref registers to vary the CEN VREF
 *
 * Parameters: target: mba;		port: 0, 1
 * Rd_cen_Vref: VDD40375 = 40375, VDD41750 = 41750, VDD43125 = 43125, VDD44500 = 44500,
 * VDD45875 = 45875, VDD47250 = 47250, VDD48625 = 48625, VDD50000 = 50000, VDD51375 = 51375,
 * VDD52750 = 52750, VDD54125 = 54125, VDD55500 = 55500, VDD56875 = 56875, VDD58250 = 58250,
 * VDD59625 = 59625, VDD61000 = 61000, VDD60375 = 60375, VDD61750 = 61750, VDD63125 = 63125,
 * VDD64500 = 64500, VDD65875 = 65875, VDD67250 = 67250, VDD68625 = 68625, VDD70000 = 70000,
 * VDD71375 = 71375, VDD72750 = 72750, VDD74125 = 74125, VDD75500 = 75500, VDD76875 = 76875,
 * VDD78250 = 78250, VDD79625 = 79625, VDD81000 = 81000
 * DDR3 supports upto 61000
 * ---------------------------------------------------------------------------*/

fapi::ReturnCode config_rd_cen_vref (const fapi::Target & i_target_mba, uint8_t i_port, uint32_t i_rd_cen_vref)
{

    ecmdDataBufferBase data_buffer(64);
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;
    uint32_t rd_vref = 0;

    if (i_port > 1)
    {
	FAPI_ERR("Read vref port input(%u) out of bounds", i_port);
	FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FN_INPUT_ERROR);
	return rc;
    }
    for(uint8_t i=0; i< MAX_RD_VREF; i++)
    {
	if (rd_cen_vref_array[i] == i_rd_cen_vref)
	{
            rd_vref = i;
	    break;
	}
    }

    if (i_port == 0)
    {
	rc = fapiGetScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_0_0x800000060301143F,
		    data_buffer); if(rc) return rc;
        rc_num = rc_num | data_buffer.insertFromRight(rd_vref,56,4);
        if (rc_num)
        {
            FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
            rc.setEcmdError(rc_num);
            return rc;
        }
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_0_0x800000060301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_1_0x800004060301143F,
		    data_buffer); if(rc) return rc;
    	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_2_0x800008060301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_3_0x80000c060301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P0_4_0x800010060301143F,
		    data_buffer); if(rc) return rc;
    }
    else
    {
	rc = fapiGetScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_0_0x800100060301143F,
		    data_buffer); if(rc) return rc;
        rc_num = rc_num | data_buffer.insertFromRight(rd_vref,56,4);
        if (rc_num)
        {
            FAPI_ERR( "config_rd_vref: Error in setting up buffer ");
            rc.setEcmdError(rc_num);
            return rc;
        }
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_0_0x800100060301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_1_0x800104060301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_2_0x800108060301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_3_0x80010c060301143F,
		    data_buffer); if(rc) return rc;
	rc = fapiPutScom(i_target_mba,
		    DPHY01_DDRPHY_DP18_RX_PEAK_AMP_P1_4_0x800110060301143F,
		    data_buffer); if(rc) return rc;
    }
    return rc;
}
/*------------------------------------------------------------------------------
 * Function: mss_slew_cal()
 * This function runs the slew calibration engine to configure MSS_SLEW_DATA/ADR
 * attributes and calls config_slew_rate to set the slew rate in the registers.
 *
 * Parameters: target: mba;
 * ---------------------------------------------------------------------------*/

fapi::ReturnCode mss_slew_cal(const fapi::Target &i_target)
{
	fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
	fapi::ReturnCode array_rcs[MAX_NUM_PORTS]; // capture rc per port loop
    uint32_t poll_count = 0;
	uint8_t ports_valid = 0;
	uint8_t is_sim = 0;

	uint8_t freq_idx = 0;		// freq index into lookup table
	uint32_t ddr_freq = 0;		// current ddr freq
	uint8_t	ddr_idx = 0;		// ddr type index into lookup table
	uint8_t ddr_type = 0;		// ATTR_EFF_DRAM_GEN{0=invalid, 1=ddr3, 2=ddr4}

	uint8_t cal_status = 0;
	// bypass slew (MAX slew rate) not included since it is not calibrated.
	// for output ATTR_MSS_SLEW_RATE_DATA(0),
	//            ATTR_MSS_SLEW_RATE_ADR(1), [port=2][imp=4][slew=4]
	uint8_t calibrated_slew[2][MAX_NUM_PORTS][MAX_NUM_IMP]
		[MAX_NUM_CAL_SLEW_RATES] = {{{{ 0 }}}};

	fapi::Target l_target_centaur;	// temporary target for parent

	ecmdDataBufferBase ctl_reg(64);
	ecmdDataBufferBase stat_reg(64);

	// [ddr3/4][dq/adr][speed][impedance][slew_rate]
	// note: Assumes standard voltage for DDR3(1.35V), DDR4(1.2V),
	// little endian, if >=128, lab only debug.
	//
	// ddr_type(2)	ddr3=0, ddr4=1
	// data/adr(2)	data(dq/dqs)=0, adr(cmd/cntl)=1
	// speed(4)		1066=0, 1333=1, 1600=2, 1866=3
	// imped(4)		24ohms=0, 30ohms=1, 34ohms=2, 40ohms=3 for DQ/DQS
	// imped(4)		15ohms=0, 20ohms=1, 30ohms=2, 40ohms=3 for ADR driver
	// slew(3)		3V/ns=0, 4V/ns=1, 5V/ns=2, 6V/ns=3
	const uint8_t slew_table[2][2][4][4][4] = {
//	NOTE: bit 7 = unsupported slew, and actual value is in bits 4:0

/*	DDR3(0)	*/
	{ {
	// dq/dqs(0)
/* Imp. ________24ohms______..________30ohms______..________34ohms______..________40ohms______
   Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
/*1066*/{{ 12,   9,   7, 134}, { 13,   9,   7, 133}, { 13,  10,   7, 134}, { 14,  10,   7, 132}},
/*1333*/{{ 15,  11,   8, 135}, { 16,  12,   9, 135}, { 17,  12,   9, 135}, { 17,  12,   8, 133}},
/*1600*/{{ 18,  13,  10, 136}, { 19,  14,  10, 136}, { 20,  15,  11, 136}, { 21,  14,  10, 134}},
/*1866*/{{149, 143, 140, 138}, {151, 144, 140, 137}, {151, 145, 141, 138}, {152, 145, 139, 135}}
	}, {
	// adr(1),
/* Imp. ________15ohms______..________20ohms______..________30ohms______..________40ohms______
   Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
/*1066*/{{ 17,  13,  10,   8}, { 13,  11,   7,   6}, { 12,   8,   5, 131}, {  7,   4, 131, 131}},
/*1333*/{{ 21,  16,  12,  10}, { 17,  12,   9,   7}, { 15,  10,   6, 132}, {  9,   5, 132, 132}},
/*1600*/{{ 25,  19,  15,  12}, { 20,  14,  13,   8}, { 19,  12,   7, 133}, { 11,   6, 133, 133}},
/*1866*/{{157, 150, 145, 142}, {151, 145, 141, 138}, {150, 142, 136, 134}, {141, 134, 134, 134}}
	} },
/* DDR4(1) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
	{ {
	// dq/dqs(0)
/* Imp. ________24ohms______..________30ohms______..________34ohms______..________40ohms______
   Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
/*1066*/{{138, 135, 134, 133}, {139, 136, 134, 132}, {140, 136, 134, 132}, {140, 136, 132, 132}},
/*1333*/{{139, 137, 135, 134}, {142, 138, 135, 133}, {143, 138, 135, 133}, {143, 138, 133, 132}},
/*1600*/{{ 15,  11,   9, 135}, { 17,  11,   9, 135}, { 18,  13,   9, 134}, { 18,  11,   6, 133}},
/*1866*/{{ 18,  13,  10, 137}, { 19,  13,  10, 136}, { 21,  15,  10, 135}, { 21,  13,   8, 134}}
	}, {
	// adr(1)
/* Imp. ________15ohms______..________20ohms______..________30ohms______..________40ohms______
   Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
/*1066*/{{142, 139, 136, 134}, {140, 136, 134, 133}, {138, 134, 131, 131}, {133, 131, 131, 131}},
/*1333*/{{145, 142, 139, 136}, {143, 138, 135, 134}, {140, 135, 132, 132}, {134, 132, 132, 132}},
/*1600*/{{ 21,  16,  13,  10}, { 18,  12,   9, 135}, { 15,   8, 133, 133}, {  7, 133, 133, 133}},
/*1866*/{{ 24,  19,  15,  11}, { 21,  14,  10, 136}, { 17,  10, 134, 134}, {  9, 134, 134, 134}}
	} }
	};

	// slew calibration control register
	const uint64_t slew_cal_cntl[] = {
		DPHY01_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_0x800080390301143F, // port 0
		DPHY01_DDRPHY_ADR_SLEW_CAL_CNTL_P1_ADR32S0_0x800180390301143F  // port 1
	};
	// slew calibration status registers
	const uint64_t slew_cal_stat[] = {
		DPHY01_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_0x800080340301143F,
		DPHY01_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P1_ADR32S0_0x800180340301143F
	};
	const uint8_t ENABLE_BIT = 48;
	const uint8_t START_BIT = 49;
	const uint8_t BB_LOCK_BIT = 56;
	// general purpose 100 ns delay for HW mode  (2000 sim cycles if simclk = 20ghz)
	const uint16_t	DELAY_100NS		= 100;
	// normally 2000, but since cal doesn't work in SIM, setting to 1
	const uint16_t	DELAY_SIMCYCLES	= 1;	
	const uint8_t	MAX_POLL_LOOPS	= 20;

	// verify which ports are functional
	rc = FAPI_ATTR_GET(ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR,
			&i_target, ports_valid);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: "
				"ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR");
		return rc;
	}

	// Check if in SIM
	rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, is_sim);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_IS_SIMULATION");
		return rc;
	}
	// Get DDR type (DDR3 or DDR4)
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, ddr_type);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_DRAM_GEN");
		return rc;
	}
	// ddr_type(2)	ddr3=0, ddr4=1
	if (ddr_type == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4) {	//type=2
		ddr_idx = 1;
	} else if (ddr_type == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3) { //type=1
		ddr_idx = 0;
	} else {	// EMPTY ?? how to handle?
		FAPI_ERR("Invalid ATTR_DRAM_DRAM_GEN = %d, %s!", ddr_type,
				i_target.toEcmdString());
		FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_DRAM_GEN);
		return rc;
	}

	// get freq from parent
	rc = fapiGetParentChip(i_target, l_target_centaur); if(rc) return rc;
	rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, ddr_freq);
	if(rc) return rc;

	if (ddr_freq == 0) {
		FAPI_ERR("Invalid ATTR_MSS_FREQ = %d on %s!", ddr_freq,
				i_target.toEcmdString());
		FAPI_SET_HWP_ERROR(rc, RC_MSS_INVALID_FREQ);
		return rc;
	}
	// speed(4)		1066=0, 1333=1, 1600=2, 1866=3
	if (ddr_freq > 1732) {
		freq_idx= 3;		// for 1866+
	} else if ((ddr_freq > 1460) && (ddr_freq <= 1732)) {
		freq_idx = 2;		// for 1600
	} else if ((ddr_freq > 1200) && (ddr_freq <= 1460)) {
		freq_idx = 1;		// for 1333
	} else {		// (ddr_freq <= 1200)
		freq_idx = 0;		// for 1066-
	}

	FAPI_INF("Enabling slew calibration engine... dram=DDR%i(%u), freq=%u(%u)",
			(ddr_type+2), ddr_idx, ddr_freq, freq_idx);

	for (uint8_t l_port=0; l_port < MAX_NUM_PORTS; l_port++)
	{
		uint8_t port_val = (ports_valid & (0xF0 >> (4 * l_port)));

		if (port_val == 0) {
			FAPI_INF("WARNING:  Port %u is invalid from "
					"ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR (0x%02x), skipping.",
					l_port, ports_valid);
			continue;
		}
	//	Step A: Configure ADR registers and MCLK detect (done in ddr_phy_reset)
	// DPHY01_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_0x800080390301143F + port
		rc = fapiGetScom(i_target, slew_cal_cntl[l_port], ctl_reg);
		if (rc)
		{
			FAPI_ERR("Error reading DDRPHY_ADR_SLEW_CAL_CNTL register.");
			return rc;
		}

		rc_ecmd = ctl_reg.flushTo0();
		rc_ecmd |= ctl_reg.setBit(ENABLE_BIT);		// set enable (bit49) to 1
		if (rc_ecmd)
		{
			FAPI_ERR("Error setting enable bit in ADR Slew calibration "
					"control register.");
			rc.setEcmdError(rc_ecmd);
			return rc;
		}

		// DPHY01_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_0x800080390301143F + port
		rc = fapiPutScom(i_target, slew_cal_cntl[l_port], ctl_reg);
		if (rc)
		{
			FAPI_ERR("Error enabling slew calibration engine in "
					"DDRPHY_ADR_SLEW_CAL_CNTL register.");
			return rc;
		}

		//---------------------------------------------------------------------/
		//	Step 1. Check for BB lock.
		FAPI_INF("Wait for BB lock in status register, bit %u", BB_LOCK_BIT);
		for (poll_count=0; poll_count < MAX_POLL_LOOPS; poll_count++)
		{
			rc = fapiDelay(DELAY_100NS, DELAY_SIMCYCLES);
			if (rc) {
				FAPI_ERR("Error executing fapiDelay of 100ns or 2000simcycles");
				return rc;
			}
	// DPHY01_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_0x800080340301143F + port
			rc = fapiGetScom(i_target, slew_cal_stat[l_port], stat_reg);
			if (rc)
			{
				FAPI_ERR("Error reading DDRPHY_ADR_SYSCLK_PR_VALUE_RO register "
						"for BB_Lock.");
				return rc;
			}
			FAPI_DBG("stat_reg = 0x%04x, count=%i",stat_reg.getHalfWord(3),
					poll_count);

			if (stat_reg.isBitSet(BB_LOCK_BIT)) break;
		}

		if (poll_count == MAX_POLL_LOOPS) {
			FAPI_INF("Timeout on polling BB_Lock, continuing...");
		}

		//---------------------------------------------------------------------/
		// Create calibrated slew settings
		// dq/adr(2)	dq/dqs=0, adr=1
		// slew(4)		3V/ns=0, 4V/ns=1, 5V/ns=2, 6V/ns=3
		for (uint8_t data_adr=0; data_adr < 2; data_adr++)
		{
			for (uint8_t imp=0; imp < MAX_NUM_IMP; imp++)
			{
				uint8_t cal_slew;

				for (uint8_t slew=0; slew < MAX_NUM_CAL_SLEW_RATES; slew++)
				{
					cal_slew =
						slew_table[ddr_idx][data_adr][freq_idx][imp][slew];

					// set slew phase rotator from slew_table
					// slew_table[ddr3/4][dq/adr][freq][impedance][slew_rate]
					rc_ecmd |= ctl_reg.insertFromRight(cal_slew, 59, 5);

					// Note: must be 2000 nclks+ after setting enable bit
					rc_ecmd |= ctl_reg.setBit(START_BIT);	// set start bit(48)
					FAPI_DBG("%s Slew cntl_reg(48:63)=0x%04X, i_slew=%i,0x%02x "
						"(59:63)", (data_adr ? "ADR" : "DATA"),
						ctl_reg.getHalfWord(3), cal_slew, cal_slew);
					if (rc_ecmd)
					{
						FAPI_ERR("Error setting start bit or cal input value.");
						rc.setEcmdError(rc_ecmd);
						return rc;
					}

	// DPHY01_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_0x800080390301143F + port
					FAPI_INF("Starting slew calibration, ddr_idx=%i, "
						"data_adr=%i, imp=%i, slewrate=%i", ddr_idx, data_adr,
						imp, (slew+3));
					rc = fapiPutScom(i_target, slew_cal_cntl[l_port], ctl_reg);
					if (rc)
					{
						FAPI_ERR("Error starting slew calibration.");
						return rc;
					}

					// poll for calibration status done or timeout...
					for (poll_count=0; poll_count < MAX_POLL_LOOPS;
							poll_count++)
					{
						FAPI_INF("polling for calibration status, count=%i",
								poll_count);
	// DPHY01_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_0x800080340301143F + port
						rc = fapiGetScom(i_target, slew_cal_stat[l_port],
								stat_reg);
						if (rc)
						{
							FAPI_ERR("Error reading "
									"DDRPHY_ADR_SYSCLK_PR_VALUE_RO "
									"register for calibration status.");
							return rc;
						}
						rc_ecmd = stat_reg.extractToRight(&cal_status, 58, 2);
						if (rc_ecmd)
						{
							FAPI_ERR("Error getting calibration status bits");
							rc.setEcmdError(rc_ecmd);
							return rc;
						}
						FAPI_DBG("cal_status = %i",cal_status);
						if (cal_status != 0)
							break;
						 // wait (1020 mclks / MAX_POLL_LOOPS)
						rc = fapiDelay(DELAY_100NS, DELAY_SIMCYCLES);
						if(rc)
						{
							return rc;
						}
					}

					if (cal_status == 3)
					{
						FAPI_INF("slew calibration completed successfully");

						cal_slew = cal_slew & 0x80;	// clear bits 6:0
						rc_ecmd = stat_reg.extractPreserve(&cal_slew, 60, 4);
						if (rc_ecmd)
						{
							FAPI_ERR("Error getting calibration output "
									"slew value");
							rc.setEcmdError(rc_ecmd);
							return rc;
						}
						calibrated_slew[data_adr][l_port][imp][slew] = cal_slew;
					}
					else if (cal_status == 2)
					{
						FAPI_INF("WARNING: occurred during slew "
								"calibration, continuing...");
					}
					else
					{
						if (cal_status == 1)
						{
							FAPI_ERR("Error occurred during slew calibration");
						}
						else
						{
							FAPI_ERR("Slew calibration timed out");
						}
						FAPI_ERR("Slew calibration failed on %s slew: imp_idx="
								"%d, slew_idx=%d, slew_table=0x%02X, "
								"status=0x%04X on %s!",
								(data_adr ? "ADR" : "DATA"), imp, slew,
								cal_slew, stat_reg.getHalfWord(3),
								i_target.toEcmdString());
						
						if (is_sim) {
							// Calibration fails in sim since bb_lock not
							// possible in cycle simulator, putting initial
							// to be cal'd value in output table
							FAPI_INF("In SIM setting calibrated slew array");
							calibrated_slew[data_adr][l_port][imp][slew] =
								cal_slew;
						}
						else
						{
							FAPI_SET_HWP_ERROR(rc, RC_MSS_SLEW_CAL_ERROR);
							//return rc;
							array_rcs[l_port]=rc;
							continue;
						}
					} // end error check
				} // end slew
			} // end imp
		} // end data_adr

		// disable calibration engine for port
		ctl_reg.clearBit(ENABLE_BIT);
		rc = fapiPutScom(i_target, slew_cal_cntl[l_port], ctl_reg);
		if (rc)
		{
			FAPI_ERR("Error disabling slew calibration engine in "
					"DDRPHY_ADR_SLEW_CAL_CNTL register.");
			return rc;
		}
	} // end port loop

	for (uint8_t rn=0; rn < MAX_NUM_PORTS; rn++)
	{
		if (array_rcs[rn] != fapi::FAPI_RC_SUCCESS)
		{
			FAPI_ERR("Returning ERROR RC for port %u",rn);
			return array_rcs[rn];
		}
	}
	FAPI_INF("Setting output slew tables ATTR_MSS_SLEW_RATE_DATA/ADR");
	// ATTR_MSS_SLEW_RATE_DATA [2][4][4]	port, imped, slew_rate
	rc = FAPI_ATTR_SET(ATTR_MSS_SLEW_RATE_DATA, &i_target, calibrated_slew[0]);
	if (rc)
	{
		FAPI_ERR("Failed to set attribute: ATTR_MSS_SLEW_RATE_DATA");
		return rc;
	}
	// ATTR_MSS_SLEW_RATE_ADR [2][4][4]		port, imped, slew_rate
	rc = FAPI_ATTR_SET(ATTR_MSS_SLEW_RATE_ADR, &i_target, calibrated_slew[1]);
	if (rc)
	{
		FAPI_ERR("Failed to set attribute: ATTR_MSS_SLEW_RATE_ADR");
		return rc;
	}

/******************************************************************************/
	uint8_t slew_imp_val [MAX_NUM_SLEW_TYPES][2][MAX_NUM_PORTS]={{{0}}};
	enum {
		SLEW = 0,
		IMP = 1,
	};

	// Get desired dq/dqs slew rate & impedance from attribute
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target,
			slew_imp_val[SLEW_TYPE_DATA][SLEW]);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_CEN_SLEW_RATE_DQ_DQS");
		return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target,
			slew_imp_val[SLEW_TYPE_DATA][IMP]);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_CEN_DRV_IMP_DQ_DQS");
		return rc;
	}
	// convert enum value to actual ohms.
	for (uint8_t j=0; j < MAX_NUM_PORTS; j++)
	{
		FAPI_INF("DQ_DQS IMP Attribute[%i] = %u", j,
				slew_imp_val[SLEW_TYPE_DATA][IMP][j]);
		
		switch (slew_imp_val[SLEW_TYPE_DATA][IMP][j])
		{
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM24_FFE0:
				slew_imp_val[SLEW_TYPE_DATA][IMP][j]=24;
				break;
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE0:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE480:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE240:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE160:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE120:
				slew_imp_val[SLEW_TYPE_DATA][IMP][j]=30;
				break;
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE480:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE240:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE160:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE120:
				slew_imp_val[SLEW_TYPE_DATA][IMP][j]=34;
				break;
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE480:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE240:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE160:
			case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE120:
				slew_imp_val[SLEW_TYPE_DATA][IMP][j]=40;
				break;
		}
		FAPI_DBG("switched imp to value of %u",
				slew_imp_val[SLEW_TYPE_DATA][IMP][j]);
	}
	// Get desired ADR control slew rate & impedance from attribute
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_CNTL, &i_target,
			slew_imp_val[SLEW_TYPE_ADR_CNTL][SLEW]);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_CEN_SLEW_RATE_CNTL");
		return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_CNTL, &i_target,
			slew_imp_val[SLEW_TYPE_ADR_CNTL][IMP]);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_CEN_DRV_IMP_CNTL");
		return rc;
	}
	// Get desired ADR command slew rate & impedance from attribute
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_ADDR, &i_target,
			slew_imp_val[SLEW_TYPE_ADR_ADDR][SLEW]);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_CEN_SLEW_RATE_ADDR");
		return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_ADDR, &i_target,
			slew_imp_val[SLEW_TYPE_ADR_ADDR][IMP]);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_CEN_DRV_IMP_ADDR");
		return rc;
	}
	// Get desired ADR clock slew rate & impedance from attribute
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_CLK, &i_target,
			slew_imp_val[SLEW_TYPE_ADR_CLK][SLEW]);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_CEN_SLEW_RATE_CLK");
		return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_CLK, &i_target,
			slew_imp_val[SLEW_TYPE_ADR_CLK][IMP]);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_CEN_DRV_IMP_CLK");
		return rc;
	}
	// Get desired ADR Spare clock slew rate & impedance from attribute
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_SPCKE, &i_target,
			slew_imp_val[SLEW_TYPE_ADR_SPCKE][SLEW]);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_CEN_SLEW_RATE_SPCKE");
		return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_SPCKE, &i_target,
			slew_imp_val[SLEW_TYPE_ADR_SPCKE][IMP]);
	if (rc)
	{
		FAPI_ERR("Failed to get attribute: ATTR_EFF_CEN_DRV_IMP_SPCKE");
		return rc;
	}

	for (uint8_t l_port=0; l_port < MAX_NUM_PORTS; l_port++)
	{
		//uint8_t ports_mask = 0xF0;  // bits 0:3 = port0, bits 4:7 = port1
		uint8_t port_val = (ports_valid & (0xF0 >> (4 * l_port)));

		if (port_val == 0)
		{
			FAPI_INF("WARNING:  Port %u is invalid from "
					"ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, 0x%02x "
					"skipping configuration of slew rate on this port",
					l_port, ports_valid);
			continue;
		}
		for (uint8_t slew_type=0; slew_type < MAX_NUM_SLEW_TYPES; slew_type++)
		{
			FAPI_DBG("slew_imp_val imp=%u, slew=%u",
				slew_imp_val[slew_type][IMP][l_port],
				slew_imp_val[slew_type][SLEW][l_port]);

			config_slew_rate(i_target, l_port, slew_type,
					slew_imp_val[slew_type][IMP][l_port],
					slew_imp_val[slew_type][SLEW][l_port]);
		}
	}
	return rc;
}
