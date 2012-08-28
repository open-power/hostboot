/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_setup.C $ */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_a_x_pci_dmi_pll_setup.C,v 1.7 2012/08/14 18:32:45 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_a_x_pci_dmi_pll_setup.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_a_x_pci_dmi_pll_setup.C
// *! DESCRIPTION : Configure the PLLs
// *!
// *! OWNER NAME  : Ralph Koester            Email: rkoester@de.ibm.com
// *!
// *! The purpose of this procedure is to setup the PLLs
// *!
// *! - prerequesit is that the PLLs run in bypass mode so far
// *!   to bring-up the pervasive part of the chiplet (chiplet_init)
// *! - setup the tank PLLs by a load_ring of PLL config bits
// *! - release the RESET, check for the LOCK and release the bypass
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p8_scom_addresses.H"
#include "proc_a_x_pci_dmi_pll_setup.H"


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// GP3 register bit/field definitions
const uint8_t GP3_PLL_TEST_ENABLE = 3;
const uint8_t GP3_PLL_RESET = 4;
const uint8_t GP3_PLL_BYPASS = 5;
const uint8_t FSI_GP4_PLL_TEST_BYPASS1 = 22;
const uint8_t PLLLOCK = 0;





//------------------------------------------------------------------------------
// Function definition
//------------------------------------------------------------------------------

extern "C"
{

//------------------------------------------------------------------------------
// function:
//      REAL PLL setup for X , A, PCIE, DMI
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

        // return codes
        uint32_t rc_ecmd = 0;
        fapi::ReturnCode rc;

        // locals
        const uint32_t  max     = 50;  // Set to maximum number of times to poll for PLL each lock
        uint32_t        timeout = 0;
        uint32_t        num     = 0;


        // mark function entry
        FAPI_INF("Entry1, start_XBUS=%s\n, Entry2, start_ABUS=%s\n, Entry3, start_PCIE=%s\n, Entry4, start_DMI=%s \n" ,
                 i_startX? "true":"false",
                 i_startA? "true":"false",
                 i_startPCIE? "true":"false",
                 i_startDMI? "true":"false");

        do
        {

            //---------------------------//
            // Common code for all PLLs  //
            //---------------------------//

            FAPI_INF("FSI GP4 bit 22: Clear pll_test_bypass1.\n");
            rc = fapiGetScom(i_target, MBOX_FSIGP4_0x00050013, gp_data);
            if (rc)
            {
                FAPI_ERR("Error reading FSI GP4 register .");
                break;
            }
            rc_ecmd |= gp_data.clearBit(FSI_GP4_PLL_TEST_BYPASS1);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up data buffer to clear FSI_GP4_PLL_TEST_BYPASS1", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, MBOX_FSIGP4_0x00050013, gp_data);
            if (rc)
            {
                FAPI_ERR("fapiPutScom error (MBOX_FSIGP4_0x00050013)");
                break;
            }



            //------------//
            // X Bus PLL  //
            //------------//
            if (!i_startX)
            {
                FAPI_DBG("X BUS PLL not selected for setup in this routine.\n");
            }
            else
            {
                FAPI_INF("This routine does not do X-BUS PLL setup at this time!.\n");
                FAPI_INF("It is assumed that the X-BUS PLL is already set up in synchronous mode for use with the NEST logic.\n");
            }
            // end X-bus PLL setup



            //------------//
            // A Bus PLL  //
            //------------//
            if (!i_startA)
            {
                FAPI_DBG("A BUS PLL not selected for setup in this routine.\n");
            }
            else
            {
                FAPI_DBG("Starting PLL setup for A BUS PLL ...\n");


                FAPI_INF("ABUS GP3: Release PLL test enable of ABUS chiplet. \n");
                rc_ecmd |= gp_data.flushTo1();
                rc_ecmd |= gp_data.clearBit(GP3_PLL_TEST_ENABLE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up data buffer to clear GP3_PLL_TEST_ENABLE", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, A_GP3_AND_0x080F0013, gp_data);
                if (rc)
                {
                    FAPI_ERR("fapiPutScom error (A_GP3_AND_0x080F0013)");
                    break;
                }



                FAPI_INF("ABUS GP3: Release PLL reset of ABUS chiplet \n");
                rc_ecmd |= gp_data.flushTo1();
                rc_ecmd |= gp_data.clearBit(GP3_PLL_RESET);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up data buffer to clear GP3_PLL_RESET", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, A_GP3_AND_0x080F0013, gp_data);
                if (rc)
                {
                    FAPI_ERR("fapiPutScom error (A_GP3_AND_0x080F0013)");
                    break;
                }



                FAPI_INF("CHIPLET PLLLK: Check the PLL lock of A-BUS \n");
                num = 0;
                do
                {
                    num++;
                    if ( num > max )
                    {
                        timeout = 1;
                        break;
                    }
                    rc = fapiGetScom(i_target, A_PLLLOCKREG_0x080F0019, gp_data);
                    if (rc)
                    {
                        FAPI_ERR("fapiGetScom error (A_PLLLOCKREG_0x080F0019)");
                        break;
                    }
                    // sleep (10); // not accurate anymore for P8
                } while ( !timeout && !gp_data.isBitSet(PLLLOCK) ); // Poll until PLL is locked or max count is reached.
                if (rc) break;    // Go to end of proc if error found inside polling loop.
                if (timeout)
                {
                    FAPI_ERR("Timed out polling for pll-lock PLLLOCK_ABUS 0x%X ", gp_data.getWord(0) );
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_A_X_PCI_DMI_PLL_SETUP_ABUS_PLL_NO_LOCK);
                    break;
                }
                FAPI_INF("A-Bus PLL is locked.\n");



                FAPI_INF("ABUS GP3: Release PLL bypass of A-BUS \n");
                rc_ecmd |= gp_data.flushTo1();
                rc_ecmd |= gp_data.clearBit(GP3_PLL_BYPASS);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up data buffer to clear GP3_PLL_BYPASS", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, A_GP3_AND_0x080F0013, gp_data);
                if (rc)
                {
                    FAPI_ERR("fapiPutScom error (A_GP3_AND_0x080F0013)");
                    break;
                }



                FAPI_INF("Done setting up A-Bus PLL. \n");
            }  // end A PLL



            //----------//
            // DMI PLL  //
            //----------//
            if (!i_startDMI)
            {
                FAPI_DBG("DMI PLL not selected for setup in this routine.\n");
            }
            else
            {
                FAPI_DBG("Starting PLL setup for DMI PLL ...\n");


                FAPI_INF("NEST GP3: Release PLL test enable for DMI PLL.\n");
                rc_ecmd |= gp_data.flushTo1();
                rc_ecmd |= gp_data.clearBit(GP3_PLL_TEST_ENABLE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up data buffer to clear GP3_PLL_TEST_ENABLE", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, NEST_GP3_AND_0x020F0013, gp_data);
                if (rc)
                {
                    FAPI_ERR("fapiPutScom error (NEST_GP3_AND_0x020F0013)");
                    break;
                }



                FAPI_INF("NEST GP3: Release PLL reset for DMI PLL.\n");
                rc_ecmd |= gp_data.flushTo1();
                rc_ecmd |= gp_data.clearBit(GP3_PLL_RESET);
                if (rc_ecmd)
                {
                     FAPI_ERR("Error 0x%x setting up data buffer to clear GP3_PLL_RESET", rc_ecmd);
                     rc.setEcmdError(rc_ecmd);
                     break;
                }
                rc = fapiPutScom(i_target, NEST_GP3_AND_0x020F0013, gp_data);
                if (rc)
                {
                     FAPI_ERR("fapiPutScom error (NEST_GP3_AND_0x020F0013)");
                     break;
                }



                FAPI_INF("CHIPLET PLLLK: Check the PLL lock of DMI PLL.\n");
                num = 0;
                do
                {
                    num++;
                    if ( num > max )
                    {
                        timeout = 1;
                        break;
                    }
                    rc = fapiGetScom(i_target, PB_PLLLOCKREG_0x020F0019, gp_data);
                    if (rc)
                    {
                        FAPI_ERR("fapiGetScom error (PB_PLLLOCKREG_0x020F0019)");
                        break;
                    }
                    // sleep (10); // not accurate anymore for P8
                } while ( !timeout && !gp_data.isBitSet(PLLLOCK) ); // Poll until PLL is locked or max count is reached.
                if (rc) break;    // Go to end of proc if error found inside polling loop.
                if (timeout)
                {
                    FAPI_ERR("Timed out polling for pll-lock PLLLOCK_DMI 0x%X ", gp_data.getWord(0) );
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_A_X_PCI_DMI_PLL_SETUP_DMI_PLL_NO_LOCK);
                    break;
                }
                FAPI_INF("DMI PLL is locked.\n");



                FAPI_INF("NEST GP3: Release PLL bypass of for DMI PLL.\n");
                rc_ecmd |= gp_data.flushTo1();
                rc_ecmd |= gp_data.clearBit(GP3_PLL_BYPASS);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up data buffer to clear GP3_PLL_BYPASS", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, NEST_GP3_AND_0x020F0013, gp_data);
                if (rc)
                {
                    FAPI_ERR("fapiPutScom error (NEST_GP3_AND_0x020F0013)");
                    break;
                }



                FAPI_INF("Done setting up DMI PLL. \n");
            }  // end DMI PLL



            //-----------//
            // PCIE PLL  //
            //-----------//
            if (!i_startPCIE)
            {
                FAPI_DBG("PCIE PLL not selected for setup in this routine.\n");
            }
            else
            {
                FAPI_DBG("Starting PLL setup for PCIE PLL ...\n");

                FAPI_INF("PCIE GP3: Release PLL test enable of PCIE chiplet. \n");
                rc_ecmd |= gp_data.flushTo1();
                rc_ecmd |= gp_data.clearBit(GP3_PLL_TEST_ENABLE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up data buffer to clear GP3_PLL_TEST_ENABLE", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, PCIE_GP3_AND_0x090F0013, gp_data);
                if (rc)
                {
                    FAPI_ERR("fapiPutScom error (PCIE_GP3_AND_0x090F0013)");
                    break;
                }



                FAPI_INF("PCIE GP3: Release PLL reset of PCIE chiplet \n");
                rc_ecmd |= gp_data.flushTo1();
                rc_ecmd |= gp_data.clearBit(GP3_PLL_RESET);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up data buffer to clear GP3_PLL_RESET", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, PCIE_GP3_AND_0x090F0013, gp_data);
                if (rc)
                {
                    FAPI_ERR("fapiPutScom error (PCIE_GP3_AND_0x090F0013)");
                    break;
                }



                FAPI_INF("PCIE GP3: Release PLL bypass of PCIE-BUS \n");
                // 24july2012  mfred moved this before checking PLL lock as this is required for analog PLLs.
                rc_ecmd |= gp_data.flushTo1();
                rc_ecmd |= gp_data.clearBit(GP3_PLL_BYPASS);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up data buffer to clear GP3_PLL_BYPASS", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, PCIE_GP3_AND_0x090F0013, gp_data);
                if (rc)
                {
                    FAPI_ERR("fapiPutScom error (PCIE_GP3_AND_0x090F0013)");
                    break;
                }



                FAPI_INF("CHIPLET PLLLK: Check the PLL lock of PCIE-BUS \n");
                num = 0;
                do
                {
                    num++;
                    if ( num > max )
                    {
                        timeout = 1;
                        break;
                    }
                    rc = fapiGetScom(i_target, PCIE_PLLLOCKREG_0x090F0019, gp_data);
                    if (rc)
                    {
                        FAPI_ERR("fapiGetScom error (PCIE_PLLLOCKREG_0x090F0019)");
                        break;
                    }
                    // sleep (10); // not accurate anymore for P8
                } while ( !timeout && !gp_data.isBitSet(PLLLOCK) ); // Poll until PLL is locked or max count is reached.
                if (rc) break;    // Go to end of proc if error found inside polling loop.
                if (timeout)
                {
                    FAPI_ERR("Timed out polling for pll-lock PLLLOCK_PCIE 0x%X ", gp_data.getWord(0) );
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_A_X_PCI_DMI_PLL_SETUP_PCIE_PLL_NO_LOCK);
                    break;
                }
                FAPI_INF("PCIE PLL is locked.\n");



                FAPI_INF("Done setting up PCIE PLL. \n");
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
Revision 1.7  2012/08/14 18:32:45  mfred
Changed input parms from bool & to const bool.

Revision 1.6  2012/08/14 14:18:06  mfred
Separating proc_a_x_pci_dmi_pll_setup into two hwp.  And update code to use real scanning instead of sim cheats.


*/

