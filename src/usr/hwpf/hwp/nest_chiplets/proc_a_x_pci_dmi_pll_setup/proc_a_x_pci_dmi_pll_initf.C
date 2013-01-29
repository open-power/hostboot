/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_initf.C $ */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_a_x_pci_dmi_pll_initf.C,v 1.11 2013/01/24 16:34:45 jmcgill Exp $
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

using namespace fapi;


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// Register values for using setpulse
const uint64_t OPCG_REG0_FOR_SETPULSE  = 0x818C000000000000ull;
const uint64_t OPCG_REG2_FOR_SETPULSE  = 0x0000000000002000ull;
const uint64_t OPCG_REG3_FOR_SETPULSE  = 0x6000000000000000ull;
const uint64_t CLK_REGION_FOR_SETPULSE = 0x0010040000000000ull;



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
        ecmdDataBufferBase ring_data;
        uint8_t            pcie_enable_attr;
        uint8_t            abus_enable_attr;
        uint32_t           ring_length     = 0;
        uint8_t            attrABRingData[80]  ={0};  // Set to 80 bytes to match length in XML file, not actual scan ring length.
        uint8_t            attrDMIRingData[231]={0};  // Set to 231 bytes to match length in XML file, not actual scan ring length.
        uint8_t            attrPCIRingData[80] ={0};  // Set to 80 bytes to match length in XML file, not actual scan ring length.

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
                FAPI_DBG("Loading the config bits into A BUS PLL");

                //---------------------------------------------------------------------------
                //  Get ring data from cronus attribute and put it into eCmdDataBufferBase
                //---------------------------------------------------------------------------

                // Read the ring length attribute value.
                rc = FAPI_ATTR_GET( ATTR_PROC_AB_BNDY_PLL_LENGTH, &i_target, ring_length);
                if (rc)
                {
                    FAPI_ERR("Failed to get attribute: ATTR_PROC_AB_BNDY_PLL_LENGTH.");
                    break;
                }
                FAPI_DBG("ATTR_PROC_AB_BNDY_PLL_LENGTH attribute is set to : %d.", ring_length);


                // Read the ring data attribute value.
                rc = FAPI_ATTR_GET( ATTR_PROC_AB_BNDY_PLL_DATA, &i_target, attrABRingData);
                if (rc)
                {
                    FAPI_ERR("Failed to get attribute: ATTR_PROC_AB_BNDY_PLL_DATA.");
                    break;
                }


                // Set the ring_data buffer to the right length for the ring data
                rc_ecmd |= ring_data.setBitLength(ring_length);   // This length needs to match the real scan length in the scandef file (Required for hostboot.)
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
                //  Scan new ring data into ab_bndy_pll scan ring.
                //-----------------------------------------------------
                rc = fapiPutRing(i_target, 0x08030088, ring_data, RING_MODE_SET_PULSE);
                if (rc)
                {
                    FAPI_ERR("fapiPutRing failed with rc = 0x%x", (uint32_t)rc);
                    break;
                }
                FAPI_DBG("Loading of the config bits for A-BUS PLL is done.");



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


                FAPI_DBG("Loading of the config bits for A BUS PLL is done.");
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
                FAPI_DBG("Loading the config bits into DMI PLL");

                //---------------------------------------------------------------------------
                //  Get ring data from cronus attribute and put it into eCmdDataBufferBase
                //---------------------------------------------------------------------------

                // Read the ring length attribute value.
                rc = FAPI_ATTR_GET( ATTR_PROC_PB_BNDY_DMIPLL_LENGTH, &i_target, ring_length);
                if (rc)
                {
                    FAPI_ERR("Failed to get attribute: ATTR_PROC_PB_BNDY_DMIPLL_LENGTH.");
                    break;
                }
                FAPI_DBG("ATTR_PROC_PB_BNDY_DMIPLL_LENGTH attribute is set to : %d.", ring_length);


                // Read the ring data attribute value.
                rc = FAPI_ATTR_GET( ATTR_PROC_PB_BNDY_DMIPLL_DATA, &i_target, attrDMIRingData);
                if (rc)
                {
                    FAPI_ERR("Failed to get attribute: ATTR_PROC_PB_BNDY_DMIPLL_DATA.");
                    break;
                }


                // Set the ring_data buffer to the right length for the ring data
                rc_ecmd |= ring_data.setBitLength(ring_length);   // This length needs to match the real scan length in the scandef file (Required for hostboot.)
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
                //  Scan new ring data into pb_bndy_dmipll scan ring.
                //-----------------------------------------------------
                rc = fapiPutRing(i_target, 0x02030088, ring_data, RING_MODE_SET_PULSE);
                if (rc)
                {
                    FAPI_ERR("fapiPutRing failed with rc = 0x%x", (uint32_t)rc);
                    break;
                }
                FAPI_DBG("Loading of the config bits for DMI PLL is done.");



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

                //---------------------------------------------------------------------------
                //  Get ring data from cronus attribute and put it into eCmdDataBufferBase
                //---------------------------------------------------------------------------

                // Read the ring length attribute value.
                rc = FAPI_ATTR_GET( ATTR_PROC_PCI_BNDY_PLL_LENGTH, &i_target, ring_length);
                if (rc)
                {
                    FAPI_ERR("Failed to get attribute: ATTR_PROC_PCI_BNDY_PLL_LENGTH.");
                    break;
                }
                FAPI_DBG("ATTR_PROC_PCI_BNDY_PLL_LENGTH attribute is set to : %d.", ring_length);


                // Read the ring data attribute value.
                rc = FAPI_ATTR_GET( ATTR_PROC_PCI_BNDY_PLL_DATA, &i_target, attrPCIRingData);
                if (rc)
                {
                    FAPI_ERR("Failed to get attribute: ATTR_PROC_PCI_BNDY_PLL_DATA.");
                    break;
                }


                // Set the ring_data buffer to the right length for the ring data
                rc_ecmd |= ring_data.setBitLength(ring_length);   // This length needs to match the real scan length in the scandef file (Required for hostboot.)
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
                //  Scan new ring data into pci_bndy_pll scan ring.
                //-----------------------------------------------------
                rc = fapiPutRing(i_target, 0x09030088, ring_data, RING_MODE_SET_PULSE);
                if (rc)
                {
                    FAPI_ERR("fapiPutRing failed with rc = 0x%x", (uint32_t)rc);
                    break;
                }
                FAPI_DBG("Loading of the config bits for PCIE PLL is done.");



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


                FAPI_INF("Done setting up PCIE PLL. ");
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

