/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_setup.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_a_x_pci_dmi_pll_setup.C,v 1.15 2014/04/02 14:02:33 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_a_x_pci_dmi_pll_setup.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_a_x_pci_dmi_pll_setup.C
// *! DESCRIPTION : Initialize and lock A/X/PCI/DMI PLLs
// *!
// *! OWNER NAME  : Ralph Koester            Email: rkoester@de.ibm.com
// *!
// *! The purpose of this procedure is to initialize (remove from reset/bypass)
// *! and lock the X/A/PCIE/DMI PLLs
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p8_scom_addresses.H>
#include <proc_a_x_pci_dmi_pll_setup.H>
#include <proc_a_x_pci_dmi_pll_utils.H>



//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const uint64_t GENERIC_PCB_CONFIG_0x000F001E = 0x000F001EULL;


//------------------------------------------------------------------------------
// Function definition
//------------------------------------------------------------------------------

extern "C"
{

//------------------------------------------------------------------------------
// function:
//      Clear and unmask chiplet PLL lock indication
//
// parameters: i_target                 => chip target
//             i_chiplet_base_scom_addr => aligned base address of chiplet SCOM
//                                         address space
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_a_x_pci_dmi_pll_setup_unmask_lock(const fapi::Target & i_target,
                                                        const uint32_t i_chiplet_base_scom_addr)
{
    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // data buffer to hold register values
    ecmdDataBufferBase data(64);

    do
    {
        rc = fapiGetScom(i_target,
                         i_chiplet_base_scom_addr | GENERIC_PCB_ERR_0x000F001F,
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("Error reading PCB Slave PLL Lock Indication");
            break;
        }
        
        rc_ecmd |= data.setBit(25);  // set bit to clear previous lock errors 
        rc_ecmd |= data.setBit(26);  // set bit to clear previous lock errors 
        rc_ecmd |= data.setBit(27);  // set bit to clear previous lock errors
        rc_ecmd |= data.setBit(28);  // set bit to clear previous lock errors
        
        if (rc_ecmd)
        {
        	FAPI_ERR("Error (0x%x) setting up PLL Lock Indication ecmdDataBufferBase", rc_ecmd);
        	rc.setEcmdError(rc_ecmd);
        	break;		
        }
        
        FAPI_INF("Clearing PCB Slave Lock Indication Bit 25,26,27,28");
        rc = fapiPutScom(i_target,
                         i_chiplet_base_scom_addr | GENERIC_PCB_ERR_0x000F001F,
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing PCB Slave PLL Lock Indication");
            break;
        }
        
        rc = fapiGetScom(i_target,
                         i_chiplet_base_scom_addr | GENERIC_PCB_CONFIG_0x000F001E,
                         data);
        if (!rc.ok())
        {
           FAPI_ERR("Error reading PCB Slave PLL Lock Mask");
           break;
        }
        
        rc_ecmd |= data.clearBit(12);  // set bit to clear PLL Lock Mask 
        
        if (rc_ecmd)
        {
        	FAPI_ERR("Error (0x%x) setting up PLL Lock Mask ecmdDataBufferBase", rc_ecmd);
        	rc.setEcmdError(rc_ecmd);
        	break;		
        }
        
        FAPI_INF("Clearing PCB Slave Lock Mask Bit 12");
        rc = fapiPutScom(i_target, 
                         i_chiplet_base_scom_addr | GENERIC_PCB_CONFIG_0x000F001E,
                         data);
        if (!rc.ok())
        {
           FAPI_ERR("Error writing PCB Slave Lock Mask");
           break;
        }
    } while(0);

    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Initialize and lock A/X/PCI/DMI PLLs
//
// parameters: i_target       =>   chip target
//             i_startX       =>   True to start X BUS PLL, else false
//             i_startA       =>   True to start A BUS PLL, else false
//             i_startPCIE    =>   True to start PCIE PLL, else false
//             i_startDMI     =>   True to start DMI PLL, else false
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_a_x_pci_dmi_pll_setup(const fapi::Target & i_target,
                                     const bool i_startX,
                                     const bool i_startA,
                                     const bool i_startPCIE,
                                     const bool i_startDMI)
    {
        // data buffer to hold register values
        ecmdDataBufferBase gp_data(64);
		ecmdDataBufferBase scom_data(64);
	

        // return codes
        fapi::ReturnCode rc;
		
        // locals
        uint8_t pcie_enable_attr;
        uint8_t abus_enable_attr;

        // mark function entry
        FAPI_INF("Entry1, start_XBUS=%s\n, Entry2, start_ABUS=%s\n, Entry3, start_PCIE=%s\n, Entry4, start_DMI=%s \n" ,
                 i_startX? "true":"false",
                 i_startA? "true":"false",
                 i_startPCIE? "true":"false",
                 i_startDMI? "true":"false");

        do
        {
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

                rc = proc_a_x_pci_dmi_pll_setup_unmask_lock(
                    i_target,
                    TP_CHIPLET_0x01000000);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_setup_unmask_lock");
                    break;
                }
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
                FAPI_DBG("Starting PLL setup for A BUS PLL ...");
                rc = proc_a_x_pci_dmi_pll_release_pll(
                        i_target,
                        A_BUS_CHIPLET_0x08000000,
                        true);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_release_pll");
                    break;
                }

                rc = proc_a_x_pci_dmi_pll_setup_unmask_lock(
                    i_target,
                    A_BUS_CHIPLET_0x08000000);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_setup_unmask_lock");
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
                FAPI_DBG("Starting PLL setup for DMI PLL ...");
                rc = proc_a_x_pci_dmi_pll_release_pll(
                        i_target,
                        NEST_CHIPLET_0x02000000,
                        true);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_release_pll");
                    break;
                }
                rc = proc_a_x_pci_dmi_pll_setup_unmask_lock(
                    i_target,
                    NEST_CHIPLET_0x02000000);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_setup_unmask_lock");
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
                FAPI_DBG("Starting PLL setup for PCIE PLL ...");
                rc = proc_a_x_pci_dmi_pll_release_pll(
                        i_target,
                        PCIE_CHIPLET_0x09000000,
                        true);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_release_pll");
                    break;
                }

//TODO: Temporarily undo this unmask for Brazos until Joe McGill fixes SW255565 
//                rc = proc_a_x_pci_dmi_pll_setup_unmask_lock(
//                    i_target,
//                    PCIE_CHIPLET_0x09000000);
//                if (!rc.ok())
//                {
//                    FAPI_ERR("Error from proc_a_x_pci_dmi_pll_setup_unmask_lock");
//                    break;
//                }

                FAPI_INF("Done setting up PCIE PLL. ");

            }  // end PCIE PLL

        } while (0); // end do

        // mark function exit
        FAPI_INF("Exit");
        return rc;
    }  // end FAPI procedure proc_a_x_pci_dmi_pll_setup

} // extern "C"

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.
$Log: proc_a_x_pci_dmi_pll_setup.C,v $
Revision 1.15  2014/04/02 14:02:33  jmcgill
respect function input parameters/partial good in unlock error clear/unmask logic (SW252901)

Revision 1.14  2014/03/28 15:25:39  bgeukes
updates for SW252901 after RAS review

Revision 1.13  2014/03/27 17:58:08  bgeukes
fix for the scominit updates

Revision 1.12  2014/01/07 14:43:34  mfred
Checking in updates from Andrea Ma:  Include statements fixed and one fapi dbg statement changed.

Revision 1.11  2013/04/17 22:38:42  jmcgill
implement A/DMI PLL workaround for SW194943, reorganize code to use common subroutines for PLL scan/setup

Revision 1.10  2013/01/25 19:30:22  mfred
Release PLLs from bypass before checking for PLL lock.  Also, check for two lock bits on DMI PLL to support Venice.

Revision 1.9  2013/01/20 19:22:44  jmcgill
update for A chiplet partial good support

Revision 1.8  2013/01/10 14:40:13  jmcgill
add partial good support

Revision 1.7  2012/08/14 18:32:45  mfred
Changed input parms from bool & to const bool.

Revision 1.6  2012/08/14 14:18:06  mfred
Separating proc_a_x_pci_dmi_pll_setup into two hwp.  And update code to use real scanning instead of sim cheats.


*/

