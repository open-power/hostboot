/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_initf.C $ */
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
// $Id: proc_a_x_pci_dmi_pll_initf.C,v 1.16 2014/01/07 14:43:23 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_a_x_pci_dmi_pll_initf.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_a_x_pci_dmi_pll_initf.C
// *! DESCRIPTION : Scan PLL settings for A/X/PCI/DMI PLLs
// *!
// *! OWNER NAME  : Ralph Koester            Email: rkoester@de.ibm.com
// *!
// *! The purpose of this procedure is to scan in runtime PLL settings
// *! for the X/A/PCIE/DMI PLLs
// *!
// *! - prerequisite is that the PLLs are in bypass mode
// *! - setup the PLLs by a ring load of PLL config bits
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p8_scom_addresses.H>
#include <proc_a_x_pci_dmi_pll_initf.H>
#include <proc_a_x_pci_dmi_pll_utils.H>

using namespace fapi;


//------------------------------------------------------------------------------
// Function definition
//------------------------------------------------------------------------------

extern "C"
{


//------------------------------------------------------------------------------
// function:
//      Scan PLL settings for A/X/PCI/DMI PLLs
//
// parameters: i_target       =>   chip target
//             i_startX       =>   True to start X BUS PLL, else false
//             i_startA       =>   True to start A BUS PLL, else false
//             i_startPCIE    =>   True to start PCIE PLL, else false
//             i_startDMI     =>   True to start DMI PLL, else false
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_a_x_pci_dmi_pll_initf(const fapi::Target & i_target,
                                 const bool i_startX,
                                 const bool i_startA,
                                 const bool i_startPCIE,
                                 const bool i_startDMI)
{
    // data buffer to hold register values
    ecmdDataBufferBase scom_data(64);
    ecmdDataBufferBase ring_data;
    uint8_t pcie_enable_attr;
    uint8_t abus_enable_attr;
    uint8_t is_simulation;
    uint8_t lctank_pll_vco_workaround = 0;
    uint32_t ring_length     = 0;
    uint8_t attrABRingData[80]  ={0};  // Set to 80 bytes to match length in XML file, not actual scan ring length.
    uint8_t attrDMIRingData[231]={0};  // Set to 231 bytes to match length in XML file, not actual scan ring length.
    uint8_t attrPCIRingData[80] ={0};  // Set to 80 bytes to match length in XML file, not actual scan ring length.

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_INF("\n   Parameter1, start_XBUS=%s\n   Parameter2, start_ABUS=%s\n   Parameter3, start_PCIE=%s\n   Parameter4, start_DMI=%s \n" ,
             i_startX ? "true":"false",
             i_startA ? "true":"false",
             i_startPCIE ? "true":"false",
             i_startDMI ? "true":"false");
    do
    {
        //------------//
        // Workaround //
        //------------//
        rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION,
                           NULL,
                           is_simulation);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying ATTR_IS_SIMULATION");
            break;
        }

        if (!is_simulation)
        {
            rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_LCTANK_PLL_VCO_BUG,
                               &i_target,
                               lctank_pll_vco_workaround);
            if (!rc.ok())
            {
                FAPI_ERR("Error querying Chip EC feature: ATTR_CHIP_EC_FEATURE_LCTANK_PLL_VCO_BUG");
                break;
            }
        }

        FAPI_DBG("lctank PLL VCO bug circumvention is %s",
                 (lctank_pll_vco_workaround ? "enabled" : "disabled"));


        //------------//
        // X Bus PLL  //
        //------------//
        if (!i_startX)
        {
            FAPI_DBG("X BUS PLL not selected for setup in this routine.");
        }
        else
        {
            FAPI_INF("This routine does not do X-BUS PLL setup at this time!.");
            FAPI_INF("It is assumed that the X-BUS PLL is already set up in synchronous mode for use with the NEST logic.");
        }
        // end X-bus PLL setup


        //------------//
        // A Bus PLL  //
        //------------//

        // query ABUS partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_A_ENABLE,
                           &i_target,
                           abus_enable_attr);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying ATTR_PROC_A_ENABLE");
            break;
        }

        if (!i_startA)
        {
            FAPI_DBG("A BUS PLL not selected for setup in this routine.");
        }
        else if (abus_enable_attr != fapi::ENUM_ATTR_PROC_A_ENABLE_ENABLE)
        {
            FAPI_DBG("A BUS PLL setup skipped (partial good).");
        }
        else
        {
            // Read the ring length attribute value.
            rc = FAPI_ATTR_GET(ATTR_PROC_AB_BNDY_PLL_LENGTH, &i_target, ring_length);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_AB_BNDY_PLL_LENGTH.");
                break;
            }
            FAPI_DBG("ATTR_PROC_AB_BNDY_PLL_LENGTH attribute is set to : %d.", ring_length);

            // Read the ring data attribute value.
            rc = FAPI_ATTR_GET(ATTR_PROC_AB_BNDY_PLL_DATA, &i_target, attrABRingData);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_AB_BNDY_PLL_DATA.");
                break;
            }

            // Set the ring_data buffer to the right length for the ring data
            rc_ecmd |= ring_data.setBitLength(ring_length);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // Put the ring data from the attribute into the buffer
            rc_ecmd |= ring_data.insert(attrABRingData, 0, ring_length, 0);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading scan chain attribute data into buffer.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // apply workaround for A PLL for all frequencies
            bool a_lctank_pll_vco_workaround = (lctank_pll_vco_workaround != 0);
            FAPI_DBG("A-Bus PLL VCO bug circumvention is %s",
                     (a_lctank_pll_vco_workaround ? "enabled" : "disabled"));

            // scan ab_bndy_pll ring with setpulse
            FAPI_DBG("Loading the config bits into A BUS PLL");
            rc = proc_a_x_pci_dmi_pll_scan_pll(
                    i_target,
                    A_BUS_CHIPLET_0x08000000,
                    AB_BNDY_PLL_RING_ADDR,
                    ring_data,
                    a_lctank_pll_vco_workaround,
                    AB_BNDY_PLL_RING_CCALLOAD_OFFSET,
                    AB_BNDY_PLL_RING_CCALFMIN_OFFSET,
                    false);
            if (rc)
            {
                FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_pll");
                break;
            }

            FAPI_INF("Done setting up A-Bus PLL. ");
        }  // end A PLL



        //----------//
        // DMI PLL  //
        //----------//
        if (!i_startDMI)
        {
            FAPI_DBG("DMI PLL not selected for setup in this routine.");
        }
        else
        {
            // Read the ring length attribute value.
            rc = FAPI_ATTR_GET(ATTR_PROC_PB_BNDY_DMIPLL_LENGTH, &i_target, ring_length);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_PB_BNDY_DMIPLL_LENGTH.");
                break;
            }
            FAPI_DBG("ATTR_PROC_PB_BNDY_DMIPLL_LENGTH attribute is set to : %d.", ring_length);


            // Read the ring data attribute value.
            rc = FAPI_ATTR_GET(ATTR_PROC_PB_BNDY_DMIPLL_DATA, &i_target, attrDMIRingData);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_PB_BNDY_DMIPLL_DATA.");
                break;
            }

            // Set the ring_data buffer to the right length for the ring data
            rc_ecmd |= ring_data.setBitLength(ring_length);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // Put the ring data from the attribute into the buffer
            rc_ecmd |= ring_data.insert(attrDMIRingData, 0, ring_length, 0);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading scan chain attribute data into buffer.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // only apply DMI workaround if needed when frequency < 4800 MHz,
            bool dmi_lctank_pll_vco_workaround = (lctank_pll_vco_workaround != 0);
            uint32_t dmi_freq;
            if (dmi_lctank_pll_vco_workaround)
            {
                // frequency reported via X attribute should be equivalent to DMI freq
                // given that we are running NEST off of X-bus PLL (NEST=X/2) and
                // DMI=NEST*2
                rc = FAPI_ATTR_GET(ATTR_FREQ_X, NULL, dmi_freq);
                if (!rc.ok())
                {
                    FAPI_ERR("Failed to get attribute: ATTR_FREQ_X");
                    break;
                }

                if (dmi_freq >= DMI_PLL_VCO_WORKAROUND_THRESHOLD_FREQ)
                {
                    dmi_lctank_pll_vco_workaround = false;
                }
            }
            FAPI_DBG("DMI PLL VCO bug circumvention is %s",
                     (dmi_lctank_pll_vco_workaround ? "enabled" : "disabled"));

            // scan pb_bndy_dmipll ring with setpulse
            FAPI_DBG("Loading the config bits into DMI PLL");
            rc = proc_a_x_pci_dmi_pll_scan_pll(
                    i_target,
                    NEST_CHIPLET_0x02000000,
                    PB_BNDY_DMIPLL_RING_ADDR,
                    ring_data,
                    dmi_lctank_pll_vco_workaround,
                    PB_BNDY_DMIPLL_RING_CCALLOAD_OFFSET,
                    PB_BNDY_DMIPLL_RING_CCALFMIN_OFFSET,
                    true);
            if (rc)
            {
                FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_pll");
                break;
            }

            FAPI_INF("Done setting up DMI PLL. ");
        }  // end DMI PLL



        //-----------//
        // PCIE PLL  //
        //-----------//

        // query PCIE partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_ENABLE,
                           &i_target,
                           pcie_enable_attr);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying ATTR_PROC_PCIE_ENABLE");
            break;
        }

        if (!i_startPCIE)
        {
            FAPI_DBG("PCIE PLL not selected for setup in this routine.");
        }
        else if (pcie_enable_attr != fapi::ENUM_ATTR_PROC_PCIE_ENABLE_ENABLE)
        {
            FAPI_DBG("PCIE PLL setup skipped (partial good).");
        }
        else
        {
            FAPI_DBG("Loading the config bits into PCIE BUS PLL");

            // Read the ring length attribute value.
            rc = FAPI_ATTR_GET(ATTR_PROC_PCI_BNDY_PLL_LENGTH, &i_target, ring_length);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_PCI_BNDY_PLL_LENGTH.");
                break;
            }
            FAPI_DBG("ATTR_PROC_PCI_BNDY_PLL_LENGTH attribute is set to : %d.", ring_length);

            // Read the ring data attribute value.
            rc = FAPI_ATTR_GET(ATTR_PROC_PCI_BNDY_PLL_DATA, &i_target, attrPCIRingData);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_PCI_BNDY_PLL_DATA.");
                break;
            }

            // Set the ring_data buffer to the right length for the ring data
            rc_ecmd |= ring_data.setBitLength(ring_length);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // Put the ring data from the attribute into the buffer
            rc_ecmd |= ring_data.insert(attrPCIRingData, 0, ring_length, 0);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading scan chain attribute data into buffer.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // scan pci_bndy_pll ring with setpulse
            rc = proc_a_x_pci_dmi_pll_scan_pll(
                    i_target,
                    PCIE_CHIPLET_0x09000000,
                    PCI_BNDY_PLL_RING_ADDR,
                    ring_data,
                    false,
                    PCI_BNDY_PLL_RING_CCALLOAD_OFFSET,
                    PCI_BNDY_PLL_RING_CCALFMIN_OFFSET,
                    false);
            if (rc)
            {
                FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_pll");
                break;
            }

            FAPI_INF("Done setting up PCIE PLL.");
        }  // end PCIE PLL



    } while (0); // end do

    // mark function exit
    FAPI_INF("Exit");
    return rc;
}  // end FAPI procedure proc_a_x_pci_dmi_pll_initf


} // extern "C"

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.
$Log: proc_a_x_pci_dmi_pll_initf.C,v $
Revision 1.16  2014/01/07 14:43:23  mfred
Checking in updates from Andrea Ma:  Include statements fixed and one fapi dbg statement changed.

Revision 1.15  2013/09/30 16:09:56  jmcgill
fix HW268965

Revision 1.14  2013/04/29 16:38:51  jmcgill
add constants for Murano DD1 ccalload/ccalfmin ring offsets used in workaround

Revision 1.13  2013/04/18 17:33:35  jmcgill
qualify workaround for DMI bus based on frequency

Revision 1.12  2013/04/17 22:38:38  jmcgill
implement A/DMI PLL workaround for SW194943, reorganize code to use common subroutines for PLL scan/setup

Revision 1.11  2013/01/24 16:34:45  jmcgill
fix comment as well...

Revision 1.10  2013/01/24 16:33:40  jmcgill
adjust for DMI attribute change

Revision 1.9  2013/01/20 19:21:03  jmcgill
update for A chiplet partial good support

Revision 1.8  2013/01/10 14:42:53  jmcgill
add partial good support

Revision 1.6  2012/12/07 17:09:39  mfred
fix to add DMI PLL settings for MC1 for Venice.

Revision 1.5  2012/12/06 22:59:18  mfred
adjust DMI PLL settings based on chip type.

Revision 1.4  2012/08/27 15:29:03  mfred
Fixed some findings from the latest FW code review.

Revision 1.3  2012/08/20 16:00:09  jmcgill
adjust ring offsets for 39 model

Revision 1.2  2012/08/14 18:32:42  mfred
Changed input parms from bool & to const bool.

Revision 1.1  2012/08/14 14:18:02  mfred
Separating proc_a_x_pci_dmi_pll_setup into two hwp.  And update code to use real scanning instead of sim cheats.


*/

