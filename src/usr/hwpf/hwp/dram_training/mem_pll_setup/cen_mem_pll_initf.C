/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mem_pll_setup/cen_mem_pll_initf.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: cen_mem_pll_initf.C,v 1.2 2012/08/27 16:05:20 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_mem_pll_initf.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_mem_pll_initf
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// #! ADDITIONAL COMMENTS :
//
// The purpose of this procedure is scan the correct values into the Centaur chip MEM PLL controller.
//
// The MEM PLL needs to be set to various frequency settings based on the value of some memory attributes.
// Here is some specific information in a 4/4/2012 note from Jeff Sabrowski:
//
// Hi Mark F,
// The valid values for Voltage are:  1350, 1250 and 1200.
// In the future, we may have a 900-ish value for low voltage DDR4, but the actual value won't be known for a year or more.
// One thing I am thinking about that will complicate things is how to run corners.
// This attribute will contain the nominal voltage.
// To margin the voltage, a second attribute (that is set before IPL) exists that indicates the percent offset (plus or minus) to the nominal.
// Power code will need to figure out the correct value from both those attributes.
// I suppose there's the possibility that the offset value will also be in millivolts, but we haven't talked to the firmware group about this recently,
// so this may be a good time to ping them on the offset piece again.
//
// For Frequency, we only have a few specific values we plan to support, although I plan to have a few extra "buckets" coded for lab bringup work.
// The supported frequencies are 1066, 1333 and 1600.  I plan to code in 800, 1866 as well, and maybe 2133.
// These are all the nominal/standard DDR3 and DDR4 JEDEC speeds.
// Mark B will need to correct me if I am wrong, but I believe we are doing the same as voltage
// -- having an attribute for nominal frequency and a second attribute for margin (+/- percent of nominal).
//
// The reason for "nominal" attribute plus a "margin" attribute is due to our firmware procedures being designed to work with nominal voltage and frequency
// -- when at any margin, we don't want our code to recalculate "actuals" in order to properly stress parts.
//
// -Jeff
//
// Jeff Sabrowski  (jsabrow@us.ibm.com)
//
//
// The supported frequencies listed above are the DDR frequencies. They also match the MEM PLL output B frequencies and the MBA frequencies.
// MEM PLL output A should be running at half of the output B frequency.
// MEM PLL output A drives the DDR phys.  The DDR phys double the MEM PLL output A frequency to get back to the MEM PLL output B frequency.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------

#include <fapi.H>
#include <cen_scom_addresses.H>
#include <cen_mem_pll_initf.H>

#define RING_LENGTH_TP_PLL_BNDY    442

//  Constants

// Register values for using setpulse
const uint64_t OPCG_REG0_FOR_SETPULSE  = 0x818C000000000000ull;
const uint64_t OPCG_REG2_FOR_SETPULSE  = 0x0000000000002000ull;
const uint64_t OPCG_REG3_FOR_SETPULSE  = 0x6000000000000000ull;
const uint64_t CLK_REGION_FOR_SETPULSE = 0x0010040000000000ull;



// The supported frequencies are 800, 1066, 1333, 1600, 1866, and 2133 MHz  (These are the DDR frequencies and the PLL output B frequencies.)

// Here are the bit definitions for the Analog PLL controller:
//
//  Bits        Purpose                Value to be used for OutB=1600MHz (when using real HW PLL)
// -------      --------------         ------------------------
// 0 to 2       bypmode                000
// 3            bypassn                1
// 4 to 5       charmode               00
// 6 to 8       cp_tune                101
// 9 to 11      duty_adj               000
// 12           fbkmode                0
// 13 to 14     iref_tune              00
// 15 to 34     jit_cntl               00000000000000000000
// 35 to 45     lock_tune              01010000000
// 46 to 54     mult                   011000000   (put different values here for different freqs)
// 55 to 56     outsel                 00
// 57 to 58     phasedet_tune          10
// 59           fbksel                 1
// 60 to 63     rangea                 0001        (put different values here for different freqs)
// 64 to 67     rangeb                 0011        (put different values here for different freqs)
// 68           refdiv                 0
// 69 to 75     a2d_tune               0000000
// 76 to 81     analogout_tune         000000
// 82 to 83     vreg_tune              00
// 84           ctst_tune              0
// 85           lock_sel               0
// 86           tstmode_en             0
// 87           tstmode_ncap_lt        0
// 88           tstmode_iref_lt        0
// 89           tstmode_dt_lt          0
// 90           tstmode_aout_lt        0
// 91           tstmode_vcocmp_lt      0
// 92           tstmode_ctst_lt        0
// 93           tstmode_vco_sel        0
// 94           cphase                 1
// 95           e_mode_enable          0
// 96 to 126    tune                   0000000000000000000000000000000
// 127          outa_disable           0
// 128          outb_disable           0
// 129 to 130   vcodiv                 00
// 131          digtestout             0
// 132          reset                  0
// 133 to 135   unused                 000

// Take the above bit string and convert it to hex for the scan chain data.

// Scan chain data for MEM PLL controller:

//------------------------------
// SIMULATION-ONLY PLL SETTINGS:
//------------------------------
// SIMULATION-ONLY Setting for PLL OutputB = 1600 Mhz  (Output B = 6up/6down)
const uint64_t MEM_PLL_CNTRL0_SIM_FREQ_1600  = 0x128000000A0060D3ull;
const uint64_t MEM_PLL_CNTRL1_SIM_FREQ_1600  = 0x7000000200000000ull;
//const uint64_t MEM_PLL_CNTRL2_SIM_FREQ_1600  = 0x00;   //  TODO:  Put this value back in and remove temp value on the next line.
const uint64_t MEM_PLL_CNTRL2_SIM_FREQ_1600  = 0x0F;   // Temp value:  Put F into some unused bits to make unique value. (For testing the putRing).

//------------------------------
// HARDWARE-ONLY PLL SETTINGS:
//------------------------------
// TODO adjust this HW setting for PLL OutputB = 800 Mhz
const uint64_t MEM_PLL_CNTRL0_FREQ_800   = 0x128000000A018051ull;
const uint64_t MEM_PLL_CNTRL1_FREQ_800   = 0x3000000200000000ull;
const uint64_t MEM_PLL_CNTRL2_FREQ_800   = 0x00;

// TODO adjust this HW setting for PLL OutputB = 1066 Mhz
const uint64_t MEM_PLL_CNTRL0_FREQ_1066  = 0x128000000A018051ull;
const uint64_t MEM_PLL_CNTRL1_FREQ_1066  = 0x3000000200000000ull;
const uint64_t MEM_PLL_CNTRL2_FREQ_1066  = 0x00;

// HW Setting for PLL OutputB = 1333 Mhz
const uint64_t MEM_PLL_CNTRL0_FREQ_1333  = 0x128000000A028051ull;
const uint64_t MEM_PLL_CNTRL1_FREQ_1333  = 0x3000000200000000ull;
const uint64_t MEM_PLL_CNTRL2_FREQ_1333  = 0x00;

// HW Setting for PLL OutputB = 1600 Mhz
const uint64_t MEM_PLL_CNTRL0_FREQ_1600  = 0x128000000A018051ull;
const uint64_t MEM_PLL_CNTRL1_FREQ_1600  = 0x3000000200000000ull;
const uint64_t MEM_PLL_CNTRL2_FREQ_1600  = 0x00;

// HW Setting for PLL OutputB = 1866 Mhz
const uint64_t MEM_PLL_CNTRL0_FREQ_1866  = 0x128000000A038055ull;
const uint64_t MEM_PLL_CNTRL1_FREQ_1866  = 0xB000000200000000ull;
const uint64_t MEM_PLL_CNTRL2_FREQ_1866  = 0x00;

// TODO adjust this HW setting for PLL OutputB = 2133 Mhz
const uint64_t MEM_PLL_CNTRL0_FREQ_2133  = 0x128000000A018051ull;
const uint64_t MEM_PLL_CNTRL1_FREQ_2133  = 0x3000000200000000ull;
const uint64_t MEM_PLL_CNTRL2_FREQ_2133  = 0x00;


extern "C" {

using namespace fapi;

fapi::ReturnCode cen_mem_pll_initf(const fapi::Target & i_target)
{
    // Target is centaur

    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase scom_data(64);
    ecmdDataBufferBase pll_data(136);
    ecmdDataBufferBase ring_data;

    uint8_t   is_simulation        = 0;
    uint32_t  mss_freq             = 0;
    // uint8_t  mss_pll_lab_override = 0;






    FAPI_INF("********* cen_mem_pll_initf start *********");
    do
    {

        FAPI_DBG("Setting up the Centaur MEM PLL.");


        //------------------------------------------
        //  Read attributes for setting the PLL data
        //------------------------------------------

        // The code that loads the PLL scan ring data should choose the correct data to load based on
        // the DDR frequency and voltage settings and a lab override value.
        // The supported frequencies are 800, 1066, 1333, 1600, 1866, and 2133 MHz  (These are the DDR frequencies and the PLL output B frequencies.)
        // The DDR frequency can be determined from attribute ATTR_MSS_FREQ  (in MHz)
        // The DDR voltage can be determined from attribute ATTR_MSS_VOLT  (in millivolts)
        // Get another attribute for selecting the "override" ring.    Use CQ to request an attribute.
        // (The selection of rings should include an "override ring that can be used in the lab")


        // Read the attributes
        rc = FAPI_ATTR_GET( ATTR_IS_SIMULATION, NULL, is_simulation);
        if (rc)
        {
            FAPI_ERR("Failed to get attribute: ATTR_IS_SIMULATION.");
            break;
        }
//        rc = FAPI_ATTR_GET( ATTR_MSS_LAB_OVERRIDE_FOR_MEM_PLL, &i_target, mss_pll_lab_override);
//        if (rc)
//        {
//            FAPI_ERR("Failed to get attribute: ATTR_MSS_LAB_OVERRIDE_FOR_MEM_PLL.");
//            break;
//        }
        rc = FAPI_ATTR_GET( ATTR_MSS_FREQ, &i_target, mss_freq);
        if (rc)
        {
            FAPI_ERR("Failed to get attribute: ATTR_MSS_FREQ.");
            break;
        }

        FAPI_DBG("ATTR_IS_SIMULATION attribute is set to : %d.", is_simulation);
//        FAPI_DBG("Lab override attribute is set to : %d.", mss_pll_lab_override);
        FAPI_DBG("DDR frequency is set to : %d.", mss_freq);



        //-----------------------------------------------
        //  Set PLL control ring data based on attributes
        //-----------------------------------------------

        // TODO - How do we set the scan ring data for a lab override?

        if (is_simulation)
        {
            rc_ecmd |= pll_data.setDoubleWord( 0, MEM_PLL_CNTRL0_SIM_FREQ_1600 );
            rc_ecmd |= pll_data.setDoubleWord( 1, MEM_PLL_CNTRL1_SIM_FREQ_1600 );
            rc_ecmd |= pll_data.setByte(      16, MEM_PLL_CNTRL2_SIM_FREQ_1600 );
        }
        else
        {
            // Use the attribute values to select the right PLL controller settings
            // The supported frequencies are 800, 1066, 1333, 1600, 1866, and 2133 MHz  (These are the DDR frequencies and the PLL output B frequencies.)
            if (mss_freq == 800)
            {
                rc_ecmd |= pll_data.setDoubleWord( 0, MEM_PLL_CNTRL0_FREQ_800 );
                rc_ecmd |= pll_data.setDoubleWord( 1, MEM_PLL_CNTRL1_FREQ_800 );
                rc_ecmd |= pll_data.setByte(      16, MEM_PLL_CNTRL2_FREQ_800 );
            }
            else if (mss_freq == 1066)
            {
                rc_ecmd |= pll_data.setDoubleWord( 0, MEM_PLL_CNTRL0_FREQ_1066 );
                rc_ecmd |= pll_data.setDoubleWord( 1, MEM_PLL_CNTRL1_FREQ_1066 );
                rc_ecmd |= pll_data.setByte(      16, MEM_PLL_CNTRL2_FREQ_1066 );
            }
            else if (mss_freq == 1333)
            {
                rc_ecmd |= pll_data.setDoubleWord( 0, MEM_PLL_CNTRL0_FREQ_1333 );
                rc_ecmd |= pll_data.setDoubleWord( 1, MEM_PLL_CNTRL1_FREQ_1333 );
                rc_ecmd |= pll_data.setByte(      16, MEM_PLL_CNTRL2_FREQ_1333 );
            }
            else if (mss_freq == 1600)
            {
                rc_ecmd |= pll_data.setDoubleWord( 0, MEM_PLL_CNTRL0_FREQ_1600 );
                rc_ecmd |= pll_data.setDoubleWord( 1, MEM_PLL_CNTRL1_FREQ_1600 );
                rc_ecmd |= pll_data.setByte(      16, MEM_PLL_CNTRL2_FREQ_1600 );
            }
            else if (mss_freq == 1866)
            {
                rc_ecmd |= pll_data.setDoubleWord( 0, MEM_PLL_CNTRL0_FREQ_1866 );
                rc_ecmd |= pll_data.setDoubleWord( 1, MEM_PLL_CNTRL1_FREQ_1866 );
                rc_ecmd |= pll_data.setByte(      16, MEM_PLL_CNTRL2_FREQ_1866 );
            }
            else if (mss_freq == 2133)
            {
                rc_ecmd |= pll_data.setDoubleWord( 0, MEM_PLL_CNTRL0_FREQ_2133 );
                rc_ecmd |= pll_data.setDoubleWord( 1, MEM_PLL_CNTRL1_FREQ_2133 );
                rc_ecmd |= pll_data.setByte(      16, MEM_PLL_CNTRL2_FREQ_2133 );
            }
            else
            {
                FAPI_ERR("Unexpected frequency value specified using ATTR_MSS_FREQ attribute!");
                FAPI_ERR("Specified value = %u.  Supported values are 800, 1066, 1333, 1600, 1866, and 2133 MHz", mss_freq);
                FAPI_SET_HWP_ERROR(rc, RC_MSS_UNSUPPORTED_FREQ_CALCULATED);
                break;
            }
        }
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x loading ecmd data buffer with 136 bits of data for MEM PLL control ring.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }



        //---------------------------------------------------------------------------
        //  Scan out the original contents from ring and modify it with new settings.
        //---------------------------------------------------------------------------
        FAPI_DBG("Loading PLL settings into scan ring tp_pll_bndy for MEM PLL.");

        // We need to load 136 bits of control data into this scan chain:  Name = tp_pll_bndy  Address = {0x00030088}
        // The scan chain is 442 bits long.  The bits need to go into positions 295 - 430
        rc_ecmd |= ring_data.setBitLength(RING_LENGTH_TP_PLL_BNDY);   // This length needs to match the length in the scandef file (Required for hostboot.)
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiGetRing(i_target, 0x00030088, ring_data);
        if (rc)
        {
            FAPI_ERR("fapiGetRing failed with rc = 0x%x", (uint32_t)rc);
            break;
        }
        // Reverse the bits in the pll data buffer so they match the order of the bits in the scan chain
        rc_ecmd |= pll_data.reverse( );
        if (rc_ecmd)
        {
            FAPI_ERR("Error (0x%x) reversing the bits in the pll data buffer", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        // Insert the PLL settings in to the scan ring.
        rc_ecmd |= ring_data.insert( pll_data, 295, 136);
        if (rc_ecmd)
        {
            FAPI_ERR("Error (0x%x) inserting config bits into ring_data buffer", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }



        //-------------------------------------------
        //  Set the OPCG to generate the setpulse
        //------------------------------------------
        //   Write SCOM   address=0x01030002  data=0x818C000000000000  unicast, write TP OPCG Reg0 to generate setpulse
        FAPI_DBG("Writing TP OPCG Register 0 to 0x818C000000000000 to generate setpulse ...");
        rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG0_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write TP OPCG Register 0.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, TP_OPCG_CNTL0_0x01030002, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing TP OPCG Register0 0x01030002 to 0x818C000000000000 to generate setpulse.");
            break;
        }

        //   Write SCOM   address=0x01030004  data=0x0000000000002000  unicast, write TP OPCG Reg2 to generate setpulse
        FAPI_DBG("Writing TP OPCG Register 2 to 0x0000000000002000 to generate setpulse ...");
        rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG2_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write TP OPCG Register 2.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, TP_OPCG_CNTL2_0x01030004, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing TP OPCG Register2 0x01030004 to 0x0000000000002000 to generate setpulse.");
            break;
        }

        //   Write SCOM   address=0x01030005  data=0x6000000000000000  unicast, write TP OPCG Reg3 to generate setpulse
        FAPI_DBG("Writing TP OPCG Register 3 to 0x6000000000000000 to generate setpulse ...");
        rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG3_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write TP OPCG Register 3.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, TP_OPCG_CNTL3_0x01030005, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing TP OPCG Register3 0x01030005 to 0x6000000000000000 to generate setpulse.");
            break;
        }

        //   Write SCOM   address=0x01030006  data=0x0010040000000000  unicast, write TP Clock Region Reg to generate setpulse
        FAPI_DBG("Writing TP OPCG Clock Region Register to 0x0010040000000000 to generate setpulse ...");
        rc_ecmd |= scom_data.setDoubleWord(0, CLK_REGION_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write TP Clock Region Register.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, TP_CLK_REGION_0x01030006, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing TP Clock Region Register 0x01030006 to 0x0010040000000000 to generate setpulse.");
            break;
        }



        //-----------------------------------------------------
        //  Scan new ring data back into tp_pll_bndy scan ring.
        //-----------------------------------------------------
        rc = fapiPutRing(i_target, 0x00030088, ring_data, RING_MODE_SET_PULSE);
        if (rc)
        {
            FAPI_ERR("fapiPutRing failed with rc = 0x%x", (uint32_t)rc);
            break;
        }
        FAPI_DBG("Loading of the config bits for MEM PLL is done.\n");



        //-------------------------------------------
        //  Set the OPCG back to a good state
        //------------------------------------------
        //   Write SCOM   address=0x01030005  data=0x0000000000000000  unicast, clear TP OPCG Reg3
        FAPI_DBG("Writing TP OPCG Register 3 to 0x0000000000000000 to clear setpulse ...");
        rc_ecmd |= scom_data.flushTo0();
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear TP OPCG Register 3.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, TP_OPCG_CNTL3_0x01030005, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing TP OPCG Register3 0x01030005 to 0x0000000000000000 to clear setpulse.");
            break;
        }

        //   Write SCOM   address=0x01030006  data=0x0000000000000000  unicast, clear TP Clock Region Reg
        FAPI_DBG("Writing TP OPCG Clock Region Register to 0x0000000000000000 to clear setpulse ...");
        rc_ecmd |= scom_data.flushTo0();
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear TP Clock Region Register.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, TP_CLK_REGION_0x01030006, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing TP Clock Region Register 0x01030006 to 0x0000000000000000 to clear setpulse.");
            break;
        }




    } while(0);

    FAPI_INF("********* cen_mem_pll_initf complete *********");
    return rc;
}

} //end extern C



/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.
$Log: cen_mem_pll_initf.C,v $
Revision 1.2  2012/08/27 16:05:20  mfred
committing minor updates as suggested by FW review.

Revision 1.1  2012/08/13 17:16:08  mfred
Adding new hwp cen_mem_pll_initf.


*/

