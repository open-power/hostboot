/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_initf.C $ */
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
// $Id: proc_a_x_pci_dmi_pll_initf.C,v 1.4 2012/08/27 15:29:03 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_a_x_pci_dmi_pll_initf.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_a_x_pci_dmi_pll_initf.C
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
#include "proc_a_x_pci_dmi_pll_initf.H"
#include <fapi.H>

#define RING_LENGTH_AB_BNDY_PLL      536
#define RING_LENGTH_PB_BNDY_DMIPLL  1234
#define RING_LENGTH_PCI_BNDY_PLL     565

using namespace fapi;


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// Register values for using setpulse
const uint64_t OPCG_REG0_FOR_SETPULSE  = 0x818C000000000000ull;
const uint64_t OPCG_REG2_FOR_SETPULSE  = 0x0000000000002000ull;
const uint64_t OPCG_REG3_FOR_SETPULSE  = 0x6000000000000000ull;
const uint64_t CLK_REGION_FOR_SETPULSE = 0x0010040000000000ull;

// PLL Settings for simulation from Johannes Koesters  20 July 2012
// TPFLEX.PLLNESTFLT.PLLCTL.C_PLL_CNTRL_LEAF		= x"13C54402001C000B 0008000000000000 00"
// TPFLEX.PLLEMFLT.PLLCTL.C_PLL_CNTRL_LEAF 		= x"13C54402001C000B 0008000000000000 00"
// TPFLEX.PLLXB.PLLCTL.C_PLL_CNTRL_LEAF			= x"174B1402001C0009 0008000000000000 00"
// TPFLEX.PLLNEST.PLLCTL.C_PLL_CNTRL_LEAF		= x"10CB1402001C0009 0008000000000000 00"
// IOMC1.TX_WRAP.PLL_MCIO.CWRAP.PLLCTL.C_PLL_CNTRL_LEAF	= x"10CB1402001C0009 0008000000000000 00"
// ABUS.TX_WRAP.PLL_A.CWRAP.PLLCTL.C_PLL_CNTRL_LEAF	= x"1F4CB402000C0009 0008000000000000 00"
// TPFLEX.PLLPCIE.PLLCTL.C_PLL_CNTRL_LEAF		= x"128000000A0060DB B000000200000000 00"


// Settings for A Bus PLL  //
// const uint64_t ABUS_PLL_CONFIG_RING_CNTRL0         = 0x0745D402001C000Bull;     version 06/22/12
const uint64_t ABUS_PLL_CONFIG_RING_CNTRL0            = 0x10C5D402000C0008ull;
const uint64_t ABUS_PLL_CONFIG_RING_CNTRL1            = 0x0008000000000000ull;
const uint8_t  ABUS_PLL_CONFIG_RING_CNTRL2            = 0x00;
const uint64_t ABUS_PLL_CONFIG_RING_CNTRL0_FOR_SIM    = 0x10C5D402001C0009ull;    // TODO turn fastlock bit (63) OFF when new PLL model is available.
const uint64_t ABUS_PLL_CONFIG_RING_CNTRL1_FOR_SIM    = 0x0008000000000000ull;
const uint8_t  ABUS_PLL_CONFIG_RING_CNTRL2_FOR_SIM    = 0x00;

// Settings for DMI PLLs  //
// const uint64_t DMI_PLL_CONFIG_RING_CNTRL0          = 0x074B1402001C000Bull;     version 06/22/12
const uint64_t DMI_PLL_CONFIG_RING_CNTRL0             = 0x10CB1402001C0008ull;
const uint64_t DMI_PLL_CONFIG_RING_CNTRL1             = 0x0008000000000000ull;
const uint8_t  DMI_PLL_CONFIG_RING_CNTRL2             = 0x00;
const uint64_t DMI_PLL_CONFIG_RING_CNTRL0_FOR_SIM     = 0x10CB1402000C0009ull;    // TODO turn fastlock bit (63) OFF when new PLL model is available.
const uint64_t DMI_PLL_CONFIG_RING_CNTRL1_FOR_SIM     = 0x0008000000000000ull;
const uint8_t  DMI_PLL_CONFIG_RING_CNTRL2_FOR_SIM     = 0x00;

// Settings for PCIE PLL  //
const uint64_t PCIE_PLL_CONFIG_RING_CNTRL0            = 0x128000000A00789Aull;
const uint64_t PCIE_PLL_CONFIG_RING_CNTRL1            = 0xA000000000000000ull;
const uint8_t  PCIE_PLL_CONFIG_RING_CNTRL2            = 0x00;
const uint64_t PCIE_PLL_CONFIG_RING_CNTRL0_FOR_SIM    = 0x128000000A0010DBull;
const uint64_t PCIE_PLL_CONFIG_RING_CNTRL1_FOR_SIM    = 0xB000000200000000ull;
const uint8_t  PCIE_PLL_CONFIG_RING_CNTRL2_FOR_SIM    = 0x00;




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
    fapi::ReturnCode proc_a_x_pci_dmi_pll_initf(const fapi::Target & i_target,
                                     const bool i_startX,
                                     const bool i_startA,
                                     const bool i_startPCIE,
                                     const bool i_startDMI)
    {
        // data buffer to hold register values
        ecmdDataBufferBase scom_data(64);
        ecmdDataBufferBase rxpll_data(47);
        ecmdDataBufferBase pll_data(136);
        ecmdDataBufferBase ring_data;

        // return codes
        uint32_t rc_ecmd = 0;
        fapi::ReturnCode rc;

        // locals
        uint8_t         is_simulation = 0;


        // mark function entry
        FAPI_INF("\n   Parameter1, start_XBUS=%s\n   Parameter2, start_ABUS=%s\n   Parameter3, start_PCIE=%s\n   Parameter4, start_DMI=%s \n" ,
                 i_startX ? "true":"false",
                 i_startA ? "true":"false",
                 i_startPCIE ? "true":"false",
                 i_startDMI ? "true":"false");
        do
        {

            //---------------------------//
            // Common code for all PLLs  //
            //---------------------------//
            // Read the ATTR_IS_SIMULATION attribute
            rc = FAPI_ATTR_GET( ATTR_IS_SIMULATION, NULL, is_simulation);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_IS_SIMULATION.");
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
                FAPI_DBG("Loading the config bits into A BUS PLL\n");
                if (is_simulation)
                {
                    rc_ecmd |= pll_data.setDoubleWord( 0, ABUS_PLL_CONFIG_RING_CNTRL0_FOR_SIM);
                    rc_ecmd |= pll_data.setDoubleWord( 1, ABUS_PLL_CONFIG_RING_CNTRL1_FOR_SIM);
                    rc_ecmd |= pll_data.setByte(      16, ABUS_PLL_CONFIG_RING_CNTRL2_FOR_SIM);
                }
                else
                {
                    rc_ecmd |= pll_data.setDoubleWord( 0, ABUS_PLL_CONFIG_RING_CNTRL0);
                    rc_ecmd |= pll_data.setDoubleWord( 1, ABUS_PLL_CONFIG_RING_CNTRL1);
                    rc_ecmd |= pll_data.setByte(      16, ABUS_PLL_CONFIG_RING_CNTRL2);
                }
                if (rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                // Set bit 17 of the controller for the ABus Cleanup PLLs
                rc_ecmd |= rxpll_data.flushTo0();
                rc_ecmd |= rxpll_data.setBit(17);
                if(rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }



                //---------------------------------------------------------------------------
                //  Scan out the original contents from ring and modify it with new settings.
                //---------------------------------------------------------------------------
                FAPI_DBG("Loading PLL settings into scan ring ab_bndy_pll for A-Bus PLL.");

                // The scan chain that we need to modify is:  Name = ab_bndy_pll  Address = {0x08030088}
                // This chain is 536 bits long.
                // RX2 clean up PLL control bits (47) go into positions  58 - 104
                // RX1 clean up PLL control bits (47) go into positions 105 - 151
                // RX0 clean up PLL control bits (47) go into positions 152 - 198
                // A-BUS PLL control bits       (136) go into positions 200 - 335

                rc_ecmd |= ring_data.setBitLength(RING_LENGTH_AB_BNDY_PLL);   // This length needs to match the length in the scandef file (Required for hostboot.)
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiGetRing(i_target, 0x08030088, ring_data);
                if (rc)
                {
                    FAPI_ERR("fapiGetRing failed with rc = 0x%x", (uint32_t)rc);
                    break;
                }
                // Reverse the bits in the pll data buffers so they match the order of the bits in the scan chain
                rc_ecmd |= pll_data.reverse( );
                rc_ecmd |= rxpll_data.reverse( );
                if (rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) reversing the bits in the pll data buffer", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                // Insert the PLL settings in to the scan ring.
                rc_ecmd |= ring_data.insert( rxpll_data,  58, 47);
                rc_ecmd |= ring_data.insert( rxpll_data, 105, 47);
                rc_ecmd |= ring_data.insert( rxpll_data, 152, 47);
                rc_ecmd |= ring_data.insert( pll_data,   200, 136);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) inserting config bits into ring_data buffer", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }



                //-------------------------------------------
                //  Set the OPCG to generate the setpulse
                //------------------------------------------
                //   Write SCOM   address=0x08030002  data=0x818C000000000000  unicast, write ABus OPCG Reg0 to generate setpulse
                FAPI_DBG("Writing ABus OPCG Register 0 to 0x818C000000000000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG0_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write ABus OPCG Register 0.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, A_OPCG_CNTL0_0x08030002, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing ABus OPCG Register0 0x08030002 to 0x818C000000000000 to generate setpulse.");
                    break;
                }

                //   Write SCOM   address=0x08030004  data=0x0000000000002000  unicast, write ABus OPCG Reg2 to generate setpulse
                FAPI_DBG("Writing ABus OPCG Register 2 to 0x0000000000002000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG2_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write ABus OPCG Register 2.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, A_OPCG_CNTL2_0x08030004, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing ABus OPCG Register2 0x08030004 to 0x0000000000002000 to generate setpulse.");
                    break;
                }

                //   Write SCOM   address=0x08030005  data=0x6000000000000000  unicast, write ABus OPCG Reg3 to generate setpulse
                FAPI_DBG("Writing ABus OPCG Register 3 to 0x6000000000000000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG3_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write ABus OPCG Register 3.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, A_OPCG_CNTL3_0x08030005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing ABus OPCG Register3 0x08030005 to 0x6000000000000000 to generate setpulse.");
                    break;
                }

                //   Write SCOM   address=0x08030006  data=0x0010040000000000  unicast, write ABus Clock Region Reg to generate setpulse
                FAPI_DBG("Writing ABus OPCG Clock Region Register to 0x0010040000000000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, CLK_REGION_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write ABus Clock Region Register.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, A_CLK_REGION_0x08030006, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing ABus Clock Region Register 0x08030006 to 0x0010040000000000 to generate setpulse.");
                    break;
                }



                //-----------------------------------------------------
                //  Scan new ring data back into ab_bndy_pll scan ring.
                //-----------------------------------------------------
                rc = fapiPutRing(i_target, 0x08030088, ring_data, RING_MODE_SET_PULSE);
                if (rc)
                {
                    FAPI_ERR("fapiPutRing failed with rc = 0x%x", (uint32_t)rc);
                    break;
                }
                FAPI_DBG("Loading of the config bits for A-BUS PLL is done.\n");



                //-------------------------------------------
                //  Set the OPCG back to a good state
                //------------------------------------------
                //   Write SCOM   address=0x08030005  data=0x0000000000000000  unicast, clear ABus OPCG Reg3
                FAPI_DBG("Writing ABus OPCG Register 3 to 0x0000000000000000 to clear setpulse ...");
                rc_ecmd |= scom_data.flushTo0();
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear ABus OPCG Register 3.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, A_OPCG_CNTL3_0x08030005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing ABus OPCG Register3 0x08030005 to 0x0000000000000000 to clear setpulse.");
                    break;
                }

                //   Write SCOM   address=0x08030006  data=0x0000000000000000  unicast, clear ABus Clock Region Reg
                FAPI_DBG("Writing ABus OPCG Clock Region Register to 0x0000000000000000 to clear setpulse ...");
                rc_ecmd |= scom_data.flushTo0();
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear ABus Clock Region Register.",  rc_ecmd);
                  rc.setEcmdError(rc_ecmd);
                  break;
                }
                rc = fapiPutScom( i_target, A_CLK_REGION_0x08030006, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing ABus Clock Region Register 0x08030006 to 0x0000000000000000 to clear setpulse.");
                    break;
                }


                FAPI_DBG("Loading of the config bits for A BUS PLL is done.\n");
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
                FAPI_DBG("Loading the config bits into DMI PLL\n");
                if (is_simulation)
                {
                     rc_ecmd |= pll_data.setDoubleWord( 0, DMI_PLL_CONFIG_RING_CNTRL0_FOR_SIM);
                     rc_ecmd |= pll_data.setDoubleWord( 1, DMI_PLL_CONFIG_RING_CNTRL1_FOR_SIM);
                     rc_ecmd |= pll_data.setByte(      16, DMI_PLL_CONFIG_RING_CNTRL2_FOR_SIM);
                }
                else
                {
                     rc_ecmd |= pll_data.setDoubleWord( 0, DMI_PLL_CONFIG_RING_CNTRL0);
                     rc_ecmd |= pll_data.setDoubleWord( 1, DMI_PLL_CONFIG_RING_CNTRL1);
                     rc_ecmd |= pll_data.setByte(      16, DMI_PLL_CONFIG_RING_CNTRL2);
                }
                if (rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                // Set bit 17 of the controller for the DMI Cleanup PLLs
                rc_ecmd |= rxpll_data.flushTo0();
                rc_ecmd |= rxpll_data.setBit(17);
                if(rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }



                //---------------------------------------------------------------------------
                //  Scan out the original contents from ring and modify it with new settings.
                //---------------------------------------------------------------------------
                FAPI_DBG("Loading PLL settings into scan ring pb_bndy_dmipll for DMI PLL.");

                // The scan chain that we need to modify is:  Name = pb_bndy_dmipll  Address = {0x02030088}
                // This chain is 1234 bits long.
                // RX3 clean up PLL control bits (47) go into positions 314 - 360
                // RX2 clean up PLL control bits (47) go into positions 361 - 407
                // RX1 clean up PLL control bits (47) go into positions 408 - 454
                // RX0 clean up PLL control bits (47) go into positions 455 - 501
                // DMI PLL control bits         (136) go into positions 502 - 637

                rc_ecmd |= ring_data.setBitLength(RING_LENGTH_PB_BNDY_DMIPLL);   // This length needs to match the length in the scandef file (Required for hostboot.)
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiGetRing(i_target, 0x02030088, ring_data);
                if (rc)
                {
                    FAPI_ERR("fapiGetRing failed with rc = 0x%x", (uint32_t)rc);
                    break;
                }
                // Reverse the bits in the pll data buffers so they match the order of the bits in the scan chain
                rc_ecmd |= pll_data.reverse( );
                rc_ecmd |= rxpll_data.reverse( );
                if (rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) reversing the bits in the pll data buffer", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                // Insert the PLL settings in to the scan ring.
                rc_ecmd |= ring_data.insert( rxpll_data, 314, 47);
                rc_ecmd |= ring_data.insert( rxpll_data, 361, 47);
                rc_ecmd |= ring_data.insert( rxpll_data, 408, 47);
                rc_ecmd |= ring_data.insert( rxpll_data, 455, 47);
                rc_ecmd |= ring_data.insert( pll_data,   502, 136);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) inserting config bits into ring_data buffer", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }



                //-------------------------------------------
                //  Set the OPCG to generate the setpulse
                //------------------------------------------
                //   Write SCOM   address=0x02030002  data=0x818C000000000000  unicast, write DMI OPCG Reg0 to generate setpulse
                FAPI_DBG("Writing DMI OPCG Register 0 to 0x818C000000000000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG0_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write DMI OPCG Register 0.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_OPCG_CNTL0_0x02030002, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing DMI OPCG Register0 0x02030002 to 0x818C000000000000 to generate setpulse.");
                    break;
                }

                //   Write SCOM   address=0x02030004  data=0x0000000000002000  unicast, write DMI OPCG Reg2 to generate setpulse
                FAPI_DBG("Writing DMI OPCG Register 2 to 0x0000000000002000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG2_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write DMI OPCG Register 2.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_OPCG_CNTL2_0x02030004, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing DMI OPCG Register2 0x02030004 to 0x0000000000002000 to generate setpulse.");
                    break;
                }

                //   Write SCOM   address=0x02030005  data=0x6000000000000000  unicast, write DMI OPCG Reg3 to generate setpulse
                FAPI_DBG("Writing DMI OPCG Register 3 to 0x6000000000000000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG3_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write DMI OPCG Register 3.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_OPCG_CNTL3_0x02030005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing DMI OPCG Register3 0x02030005 to 0x6000000000000000 to generate setpulse.");
                    break;
                }

                //   Write SCOM   address=0x02030006  data=0x0010040000000000  unicast, write DMI Clock Region Reg to generate setpulse
                FAPI_DBG("Writing DMI OPCG Clock Region Register to 0x0010040000000000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, CLK_REGION_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write DMI Clock Region Register.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_CLK_REGION_0x02030006, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing DMI Clock Region Register 0x02030006 to 0x0010040000000000 to generate setpulse.");
                    break;
                }



                //-----------------------------------------------------
                //  Scan new ring data back into pb_bndy_dmipll scan ring.
                //-----------------------------------------------------
                rc = fapiPutRing(i_target, 0x02030088, ring_data, RING_MODE_SET_PULSE);
                if (rc)
                {
                    FAPI_ERR("fapiPutRing failed with rc = 0x%x", (uint32_t)rc);
                    break;
                }
                FAPI_DBG("Loading of the config bits for DMI PLL is done.\n");



                //-------------------------------------------
                //  Set the OPCG back to a good state
                //------------------------------------------
                //   Write SCOM   address=0x02030005  data=0x0000000000000000  unicast, clear DMI OPCG Reg3
                FAPI_DBG("Writing DMI OPCG Register 3 to 0x0000000000000000 to clear setpulse ...");
                rc_ecmd |= scom_data.flushTo0();
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear DMI OPCG Register 3.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_OPCG_CNTL3_0x02030005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing DMI OPCG Register3 0x02030005 to 0x0000000000000000 to clear setpulse.");
                    break;
                }

                //   Write SCOM   address=0x02030006  data=0x0000000000000000  unicast, clear DMI Clock Region Reg
                FAPI_DBG("Writing DMI OPCG Clock Region Register to 0x0000000000000000 to clear setpulse ...");
                rc_ecmd |= scom_data.flushTo0();
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear DMI Clock Region Register.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, NEST_CLK_REGION_0x02030006, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing DMI Clock Region Register 0x02030006 to 0x0000000000000000 to clear setpulse.");
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
                FAPI_DBG("Loading the config bits into PCIE BUS PLL\n");
                if (is_simulation)
                {
                    rc_ecmd |= pll_data.setDoubleWord( 0, PCIE_PLL_CONFIG_RING_CNTRL0_FOR_SIM);
                    rc_ecmd |= pll_data.setDoubleWord( 1, PCIE_PLL_CONFIG_RING_CNTRL1_FOR_SIM);
                    rc_ecmd |= pll_data.setByte(      16, PCIE_PLL_CONFIG_RING_CNTRL2_FOR_SIM);
                }
                else
                {
                    rc_ecmd |= pll_data.setDoubleWord( 0, PCIE_PLL_CONFIG_RING_CNTRL0);
                    rc_ecmd |= pll_data.setDoubleWord( 1, PCIE_PLL_CONFIG_RING_CNTRL1);
                    rc_ecmd |= pll_data.setByte(      16, PCIE_PLL_CONFIG_RING_CNTRL2);
                }
                if (rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }



                //---------------------------------------------------------------------------
                //  Scan out the original contents from ring and modify it with new settings.
                //---------------------------------------------------------------------------
                FAPI_DBG("Loading PLL settings into scan ring pci_bndy_pll for DMI PLL.");

                // The scan chain that we need to modify is:  Name = pci_bndy_pll  Address = {0x09030088}
                // This chain is 565 bits long.
                // PCIE PLL control bits       (136) go into positions 258 - 393

                rc_ecmd |= ring_data.setBitLength(RING_LENGTH_PCI_BNDY_PLL);   // This length needs to match the length in the scandef file (Required for hostboot.)
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiGetRing(i_target, 0x09030088, ring_data);
                if (rc)
                {
                    FAPI_ERR("fapiGetRing failed with rc = 0x%x", (uint32_t)rc);
                    break;
                }
                // Reverse the bits in the pll data buffers so they match the order of the bits in the scan chain
                rc_ecmd |= pll_data.reverse( );
                if (rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) reversing the bits in the pll data buffer", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                // Insert the PLL settings in to the scan ring.
                rc_ecmd |= ring_data.insert( pll_data,   258, 136);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error (0x%x) inserting config bits into ring_data buffer", rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }



                //-------------------------------------------
                //  Set the OPCG to generate the setpulse
                //------------------------------------------
                //   Write SCOM   address=0x09030002  data=0x818C000000000000  unicast, write PCIE OPCG Reg0 to generate setpulse
                FAPI_DBG("Writing PCIE OPCG Register 0 to 0x818C000000000000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG0_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write PCIE OPCG Register 0.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, PCIE_OPCG_CNTL0_0x09030002, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing PCIE OPCG Register0 0x09030002 to 0x818C000000000000 to generate setpulse.");
                    break;
                }

                //   Write SCOM   address=0x09030004  data=0x0000000000002000  unicast, write PCIE OPCG Reg2 to generate setpulse
                FAPI_DBG("Writing PCIE OPCG Register 2 to 0x0000000000002000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG2_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write PCIE OPCG Register 2.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, PCIE_OPCG_CNTL2_0x09030004, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing PCIE OPCG Register2 0x09030004 to 0x0000000000002000 to generate setpulse.");
                    break;
                }

                //   Write SCOM   address=0x09030005  data=0x6000000000000000  unicast, write PCIE OPCG Reg3 to generate setpulse
                FAPI_DBG("Writing PCIE OPCG Register 3 to 0x6000000000000000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG3_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write PCIE OPCG Register 3.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, PCIE_OPCG_CNTL3_0x09030005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing PCIE OPCG Register3 0x09030005 to 0x6000000000000000 to generate setpulse.");
                    break;
                }

                //   Write SCOM   address=0x09030006  data=0x0010040000000000  unicast, write PCIE Clock Region Reg to generate setpulse
                FAPI_DBG("Writing PCIE OPCG Clock Region Register to 0x0010040000000000 to generate setpulse ...");
                rc_ecmd |= scom_data.setDoubleWord(0, CLK_REGION_FOR_SETPULSE);
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to write PCIE Clock Region Register.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, PCIE_CLK_REGION_0x09030006, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing PCIE Clock Region Register 0x09030006 to 0x0010040000000000 to generate setpulse.");
                    break;
                }



                //-----------------------------------------------------
                //  Scan new ring data back into pci_bndy_pll scan ring.
                //-----------------------------------------------------
                rc = fapiPutRing(i_target, 0x09030088, ring_data, RING_MODE_SET_PULSE);
                if (rc)
                {
                    FAPI_ERR("fapiPutRing failed with rc = 0x%x", (uint32_t)rc);
                    break;
                }
                FAPI_DBG("Loading of the config bits for PCIE PLL is done.\n");



                //-------------------------------------------
                //  Set the OPCG back to a good state
                //------------------------------------------
                //   Write SCOM   address=0x09030005  data=0x0000000000000000  unicast, clear PCIE OPCG Reg3
                FAPI_DBG("Writing PCIE OPCG Register 3 to 0x0000000000000000 to clear setpulse ...");
                rc_ecmd |= scom_data.flushTo0();
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear PCIE OPCG Register 3.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, PCIE_OPCG_CNTL3_0x09030005, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing PCIE OPCG Register3 0x09030005 to 0x0000000000000000 to clear setpulse.");
                    break;
                }

                //   Write SCOM   address=0x09030006  data=0x0000000000000000  unicast, clear PCIE Clock Region Reg
                FAPI_DBG("Writing PCIE OPCG Clock Region Register to 0x0000000000000000 to clear setpulse ...");
                rc_ecmd |= scom_data.flushTo0();
                if (rc_ecmd)
                {
                    FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear PCIE Clock Region Register.",  rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom( i_target, PCIE_CLK_REGION_0x09030006, scom_data);
                if (rc)
                {
                    FAPI_ERR("Error writing PCIE Clock Region Register 0x09030006 to 0x0000000000000000 to clear setpulse.");
                    break;
                }


                FAPI_INF("Done setting up PCIE PLL. \n");
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
Revision 1.4  2012/08/27 15:29:03  mfred
Fixed some findings from the latest FW code review.

Revision 1.3  2012/08/20 16:00:09  jmcgill
adjust ring offsets for 39 model

Revision 1.2  2012/08/14 18:32:42  mfred
Changed input parms from bool & to const bool.

Revision 1.1  2012/08/14 14:18:02  mfred
Separating proc_a_x_pci_dmi_pll_setup into two hwp.  And update code to use real scanning instead of sim cheats.


*/

