/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_initf.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: proc_a_x_pci_dmi_pll_initf.C,v 1.20 2015/05/14 21:03:40 jmcgill Exp $
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


//------------------------------------------------------------------------------
// Constant definitons
//------------------------------------------------------------------------------
const uint32_t DMI_PLL_VCO_WORKAROUND_THRESHOLD_FREQ = 4800;


//------------------------------------------------------------------------------
// Function definition
//------------------------------------------------------------------------------

extern "C"
{


//------------------------------------------------------------------------------
// function:
//      Scan PLL settings for A/X/PCI/DMI PLLs
//
// parameters: i_target    => chip target
//             i_startX    => True to start X BUS PLL, else false
//             i_startA    => True to start A BUS PLL, else false
//             i_startPCIE => True to start PCIE PLL, else false
//             i_startDMI  => True to start DMI PLL, else false
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_a_x_pci_dmi_pll_initf(
    const fapi::Target & i_target,
    const bool i_startX,
    const bool i_startA,
    const bool i_startPCIE,
    const bool i_startDMI)
{
    // attribute data
    uint8_t pcie_enable_attr;
    uint8_t abus_enable_attr;
    uint8_t is_simulation;
    uint8_t lctank_pll_vco_workaround = 0;

    // return codes
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
            // apply workaround for A PLL for all frequencies
            bool a_lctank_pll_vco_workaround = (lctank_pll_vco_workaround != 0);
            FAPI_DBG("A-Bus PLL VCO bug circumvention is %s",
                     (a_lctank_pll_vco_workaround ? "enabled" : "disabled"));

            // establish base ring state
            rc = proc_a_x_pci_dmi_pll_scan_bndy(i_target,
                                                RING_ADDRESS_PROC_AB_BNDY_PLL,
                                                RING_OP_BASE,
                                                RING_BUS_ID_0,
                                                false);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
                break;
            }

            if (a_lctank_pll_vco_workaround)
            {
                rc = proc_a_x_pci_dmi_pll_scan_bndy(i_target,
                                                    RING_ADDRESS_PROC_AB_BNDY_PLL,
                                                    RING_OP_MOD_VCO_S1,
                                                    RING_BUS_ID_0,
                                                    false);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
                    break;
                }

                // release PLL (skip lock check) & re-scan
                rc = proc_a_x_pci_dmi_pll_release_pll(i_target,
                                                      A_BUS_CHIPLET_0x08000000,
                                                      false);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_release_pll");
                    break;
                }

                rc = proc_a_x_pci_dmi_pll_scan_bndy(i_target,
                                                    RING_ADDRESS_PROC_AB_BNDY_PLL,
                                                    RING_OP_MOD_VCO_S2,
                                                    RING_BUS_ID_0,
                                                    false);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
                    break;
                }
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

            // establish base ring state
            rc = proc_a_x_pci_dmi_pll_scan_bndy(i_target,
                                                RING_ADDRESS_PROC_PB_BNDY_DMIPLL,
                                                RING_OP_BASE,
                                                RING_BUS_ID_0,
                                                true);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
                break;
            }

            if (dmi_lctank_pll_vco_workaround)
            {
                rc = proc_a_x_pci_dmi_pll_scan_bndy(i_target,
                                                    RING_ADDRESS_PROC_PB_BNDY_DMIPLL,
                                                    RING_OP_MOD_VCO_S1,
                                                    RING_BUS_ID_0,
                                                    true);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
                    break;
                }

                // release PLL (skip lock check) & re-scan
                rc = proc_a_x_pci_dmi_pll_release_pll(i_target,
                                                      NEST_CHIPLET_0x02000000,
                                                      false);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_release_pll");
                    break;
                }

                rc = proc_a_x_pci_dmi_pll_scan_bndy(i_target,
                                                    RING_ADDRESS_PROC_PB_BNDY_DMIPLL,
                                                    RING_OP_MOD_VCO_S2,
                                                    RING_BUS_ID_0,
                                                    true);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
                    break;
                }
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
            // establish base ring state
            rc = proc_a_x_pci_dmi_pll_scan_bndy(i_target,
                                                RING_ADDRESS_PROC_PCI_BNDY_PLL,
                                                RING_OP_BASE,
                                                RING_BUS_ID_0,
                                                false);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy");
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
Revision 1.20  2015/05/14 21:03:40  jmcgill
Update to use modified proc_a_x_pci_dmi_pll_utils API

Revision 1.19  2014/12/02 00:17:23  szhong
remove hardcoded bndy pll length in code

Revision 1.18  2014/11/13 20:17:22  szhong
adjust pb_bndy_dmi_pll length to 240

Revision 1.17  2014/11/11 22:10:35  szhong
increased attribute data length to support Naples

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

