/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mem_pll_setup/cen_mem_pll_initf.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: cen_mem_pll_initf.C,v 1.12 2014/02/04 21:08:46 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_mem_pll_initf.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_mem_pll_initf
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! SCREEN      : pervasive_screen
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

#include <p8_delta_scan_rw.h>
#include <p8_ring_identification.H>


//  Constants

// Register values for using setpulse
const uint64_t OPCG_REG0_FOR_SETPULSE  = 0x818C000000000000ull;
const uint64_t OPCG_REG2_FOR_SETPULSE  = 0x0000000000002000ull;
const uint64_t OPCG_REG3_FOR_SETPULSE  = 0x6000000000000000ull;
const uint64_t CLK_REGION_FOR_SETPULSE = 0x0010040000000000ull;

const uint32_t MEMB_TP_BNDY_PLL_RING_ADDR  = 0x01030088;

// Pervasive LFIR Register field/bit definitions
const uint8_t PERV_LFIR_SCAN_COLLISION_BIT = 3;

const bool MASK_SCAN_COLLISION  = true;

extern "C" {

using namespace fapi;



//------------------------------------------------------------------------------
// cen_load_pll_ring_from_buffer
//------------------------------------------------------------------------------
fapi::ReturnCode cen_load_pll_ring_from_buffer(const fapi::Target & i_target,
                                               ecmdDataBufferBase i_scan_ring_data
                                               )
{
    // Target is centaur

    fapi::ReturnCode    rc;
    uint32_t            rc_ecmd = 0;
    ecmdDataBufferBase  scom_data(64);


    FAPI_INF("Starting subroutine: cen_load_pll_ring_from_buffer...");
    do
    {
        //-------------------------------------------
        //  Mask Pervasive LFIR
        //------------------------------------------

        if (MASK_SCAN_COLLISION)
        {
            FAPI_DBG("Masking Pervasive LFIR scan collision bit ...");
            rc_ecmd |= scom_data.flushTo0();
            rc_ecmd |= scom_data.setBit(PERV_LFIR_SCAN_COLLISION_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to set Pervasive LFIR Mask Register.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, TP_PERV_LFIR_MASK_OR_0x0104000F, scom_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error writing Pervasive LFIR Mask OR Register.");
                break;
            }
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

        //------------------------------------------------
        //  Scan new ring data into tp_pll_bndy scan ring.
        //------------------------------------------------
        rc = fapiPutRing(i_target, MEMB_TP_BNDY_PLL_RING_ADDR, i_scan_ring_data, RING_MODE_SET_PULSE);
        if (rc)
        {
            FAPI_ERR("fapiPutRing failed with rc = 0x%x", (uint32_t)rc);
            break;
        }
        FAPI_DBG("Loading of the scan ring data for ring tp_pll_bndy is done.\n");

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

        //-------------------------------------------
        //  Clear & Unmask Pervasive LFIR
        //------------------------------------------
        if (MASK_SCAN_COLLISION)
        {
            FAPI_DBG("Clearing Pervasive LFIR scan collision bit ...");
            rc_ecmd |= scom_data.flushTo1();
            rc_ecmd |= scom_data.clearBit(PERV_LFIR_SCAN_COLLISION_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear Pervasive LFIR Register.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, TP_PERV_LFIR_AND_0x0104000B, scom_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error writing Pervasive LFIR AND Register.");
                break;
            }

            // Change for SW245030. Leave this FIR masked.   Feb. 4 2014   M.Fredrickson
            //FAPI_DBG("Unmasking Pervasive LFIR scan collision bit ...");
            //rc = fapiPutScom(i_target, TP_PERV_LFIR_MASK_AND_0x0104000E, scom_data);
            //if (!rc.ok())
            //{
            //    FAPI_ERR("Error writing Pervasive LFIR Mask And Register.");
            //    break;
            //}
        }

    } while(0);

    FAPI_INF("Finished executing subroutine: cen_load_pll_ring_from_buffer");
    return rc;
}

//------------------------------------------------------------------------------
// cen_mem_pll_initf
//------------------------------------------------------------------------------
fapi::ReturnCode cen_mem_pll_initf(const fapi::Target & i_target)
{
    // Target is centaur
    fapi::ReturnCode    rc;
    uint32_t            rc_ecmd         = 0;
    uint8_t             is_simulation   = 0;
    uint32_t            mss_freq        = 0;
    uint32_t            nest_freq       = 0;
    uint32_t            ring_length     = 0;
    uint32_t            mem_pll_update_bit_offset = 0;
    uint8_t             attrRingData[80]={0};   // Set to 80 bytes to match length in XML file, not actual scan ring length.
    ecmdDataBufferBase  ring_data;

    FAPI_INF("********* cen_mem_pll_initf start *********");
    do
    {
        FAPI_DBG("Setting up the Centaur MEM PLL.");

        //------------------------------------------
        //  Read attributes for setting the PLL data
        //------------------------------------------

        // The code that loads the PLL scan ring data should choose the correct data to load based on
        // the DDR frequency and voltage settings and a lab override value.
        // The supported frequencies are 800, 1066, 1333, 1600, 1866, and 2133 MHz
        // (These are the DDR frequencies and the PLL output B frequencies.)
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
        rc = FAPI_ATTR_GET( ATTR_MSS_FREQ, &i_target, mss_freq);
        if (rc)
        {
            FAPI_ERR("Failed to get attribute: ATTR_MSS_FREQ.");
            break;
        }
        // ATTR_FREQ_PB is a "system" attribute, so use NULL as the target.
        rc = FAPI_ATTR_GET( ATTR_FREQ_PB, NULL, nest_freq);
        if (rc)
        {
            FAPI_ERR("Failed to get attribute: ATTR_FREQ_PB.");
            break;
        }

        FAPI_DBG("ATTR_IS_SIMULATION attribute is set to : %d.", is_simulation);
        FAPI_DBG("DDR frequency is set to : %d.", mss_freq);
        FAPI_DBG("NEST frequency is set to : %d.", nest_freq);

        // Read in the PLL Ring LENGTH based on the frequency attributes.
        if ( is_simulation )
        {
            rc = FAPI_ATTR_GET( ATTR_MEMB_TP_BNDY_PLL_LENGTH, &i_target, ring_length);
        }
        else if ( nest_freq == 2000 )
        {
            switch (mss_freq) {
                case 1066 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_LENGTH, &i_target, ring_length);
                    break;
                case 1333 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_LENGTH, &i_target, ring_length);
                    break;
                case 1600 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_LENGTH, &i_target, ring_length);
                    break;
                case 1866 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_LENGTH, &i_target, ring_length);
                    break;
                default   :
                    FAPI_ERR("Un-Supported DDR frequency detected: %d.", mss_freq);
                    FAPI_ERR("DDR frequency of 1066, 1333, 1600, or 1866 expected.");
                    uint32_t & MSS_FREQ = mss_freq;
                    FAPI_SET_HWP_ERROR(rc, RC_CEN_MEM_PLL_INITF_UNSUPPORTED_MSS_FREQ);
            }
        }
        else if ( nest_freq == 2400 )
        {
            switch (mss_freq) {
                case 1066 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_LENGTH, &i_target, ring_length);
                    break;
                case 1333 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_LENGTH, &i_target, ring_length);
                    break;
                case 1600 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_LENGTH, &i_target, ring_length);
                    break;
                case 1866 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_LENGTH, &i_target, ring_length);
                    break;
                default   :
                    FAPI_ERR("Un-Supported DDR frequency detected: %d.", mss_freq);
                    FAPI_ERR("DDR frequency of 1066, 1333, 1600, or 1866 expected.");
                    uint32_t & MSS_FREQ = mss_freq;
                    FAPI_SET_HWP_ERROR(rc, RC_CEN_MEM_PLL_INITF_UNSUPPORTED_MSS_FREQ);
            }
        }
        else
        {
            FAPI_ERR("Un-Supported NEST frequency detected: %d.", nest_freq);
            FAPI_ERR("NEST frequency of 2000 or 2400 expected.");
            uint32_t & NEST_FREQ = nest_freq;
            FAPI_SET_HWP_ERROR(rc, RC_CEN_MEM_PLL_INITF_UNSUPPORTED_NEST_FREQ);
            break;
        }
        if (rc)
        {
            FAPI_ERR("Failed to get the PLL ring LENGTH attribute.");
            break;
        }
        FAPI_DBG("PLL ring LENGTH attribute is set to : %d.", ring_length);

        // Read in the PLL Ring DATA based on the frequency attributes.
        if ( is_simulation )
        {
            rc = FAPI_ATTR_GET( ATTR_MEMB_TP_BNDY_PLL_DATA, &i_target, attrRingData);
        }
        else if ( nest_freq == 2000 )
        {
            switch (mss_freq) {
                case 1066 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA, &i_target, attrRingData);
                    break;
                case 1333 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA, &i_target, attrRingData);
                    break;
                case 1600 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA, &i_target, attrRingData);
                    break;
                case 1866 :
                    rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA, &i_target, attrRingData);
                    break;
                default   :
                    FAPI_ERR("Un-Supported DDR frequency detected: %d.", mss_freq);
                    FAPI_ERR("DDR frequency of 1066, 1333, 1600, or 1866 expected.");
                    uint32_t & MSS_FREQ = mss_freq;
                    FAPI_SET_HWP_ERROR(rc, RC_CEN_MEM_PLL_INITF_UNSUPPORTED_MSS_FREQ);
            }
        }
        else if ( nest_freq == 2400 )
        {
            switch (mss_freq) {
                case 1066 :
                    rc = FAPI_ATTR_GET( ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA, &i_target, attrRingData);
                    break;
                case 1333 :
                    rc = FAPI_ATTR_GET( ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA, &i_target, attrRingData);
                    break;
                case 1600 :
                    rc = FAPI_ATTR_GET( ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA, &i_target, attrRingData);
                    break;
                case 1866 :
                    rc = FAPI_ATTR_GET( ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA, &i_target, attrRingData);
                    break;
                default   :
                    FAPI_ERR("Un-Supported DDR frequency detected: %d.", mss_freq);
                    FAPI_ERR("DDR frequency of 1066, 1333, 1600, or 1866 expected.");
                    uint32_t & MSS_FREQ = mss_freq;
                    FAPI_SET_HWP_ERROR(rc, RC_CEN_MEM_PLL_INITF_UNSUPPORTED_MSS_FREQ);
            }
        }
        else
        {
            FAPI_ERR("Un-Supported NEST frequency detected: %d.", nest_freq);
            FAPI_ERR("NEST frequency of 2000 or 2400 expected.");
            uint32_t & NEST_FREQ = nest_freq;
            FAPI_SET_HWP_ERROR(rc, RC_CEN_MEM_PLL_INITF_UNSUPPORTED_NEST_FREQ);
            break;
        }
        if (rc)
        {
            FAPI_ERR("Failed to get the PLL ring DATA attribute.");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_MEMB_MEM_PLL_CFG_UPDATE_OFFSET, &i_target, mem_pll_update_bit_offset);
        if (rc)
        {
            FAPI_ERR("Failed to get the MEM PLL PLLCTR1(44) offset attribute");
            break;
        }
        FAPI_DBG("MEM PLL PLLCTR1(44) offset is set to : %d.", mem_pll_update_bit_offset);


        // Set the ring_data buffer to the right length for the ring data
        rc_ecmd |= ring_data.setBitLength(ring_length);   // This length needs to match the real scan length in the scandef file (Required for hostboot.)
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // in order to update its output frequency, the MEM PLL needs to see PLLCTRL1(44) toggle
        // ensure output frequency changes by running three scans w/ setpulse (PLLCTRL1(44) = 0->1->0)
        for (uint32_t scan_num = 0; scan_num < 3; scan_num++)
        {
            // Put the ring data from the attribute into the buffer
            rc_ecmd |= ring_data.insert(attrRingData, 0, ring_length, 0);

            // force desired value of PLLCTR1(44)
            if (scan_num % 2) {
                rc_ecmd |= ring_data.setBit(mem_pll_update_bit_offset);
            }
            else {
                rc_ecmd |= ring_data.clearBit(mem_pll_update_bit_offset);
            }
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading scan chain attribute data into buffer (scan=%d).",  rc_ecmd, scan_num);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // Call the subroutine to load the data into the simulation or HW model
            rc = cen_load_pll_ring_from_buffer ( i_target, ring_data );
            if (rc)
            {
                FAPI_ERR("Subroutine: cen_load_pll_ring_from_buffer failed (scan=%d)!", scan_num);
                break;
            }
        }
        if (rc)
        {
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
Revision 1.12  2014/02/04 21:08:46  mfred
Change to leave TP FIR bit 3 masked out.  SW245030.

Revision 1.11  2014/01/15 03:34:28  jmcgill
scan ring 3x to ensure toggle on MEM PLLCTR1(44), which will guarantee output frequency change

Revision 1.10  2013/12/10 03:41:34  mfred
Make changes to support TP_BNDY scan chain addresses changing to chiplet 1 for zSeries.

Revision 1.9  2013/11/15 16:29:56  mfred
Changes made by Mike Jones for gerrit review, mostly for improved error handling.

Revision 1.8  2013/10/02 16:09:38  mfred
Mask FIR bit during scanning to resolve HW255774.  Add code to load desired MEM PLL freq after determining DDR freq.

Revision 1.7  2013/07/08 14:00:24  mfred
Back out accidental change.

Revision 1.5  2013/03/04 17:56:24  mfred
Add some header comments for BACKUP and SCREEN.

Revision 1.4  2013/01/29 21:50:52  mfred
Use new PLL ring attributes.

Revision 1.3  2012/11/07 23:22:44  mfred
Updated MEM PLL settings for HW with values from Tim Diemoz.

Revision 1.2  2012/08/27 16:05:20  mfred
committing minor updates as suggested by FW review.

Revision 1.1  2012/08/13 17:16:08  mfred
Adding new hwp cen_mem_pll_initf.


*/

