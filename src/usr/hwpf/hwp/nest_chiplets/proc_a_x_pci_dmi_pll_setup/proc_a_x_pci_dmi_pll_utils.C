/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_utils.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: proc_a_x_pci_dmi_pll_utils.C,v 1.6 2014/01/07 14:43:36 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_a_x_pci_dmi_pll_utils.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_a_x_pci_dmi_pll_utils.C
// *! DESCRIPTION : Configure the PLLs
// *!
// *! OWNER NAME  : Ralph Koester            Email: rkoester@de.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p8_scom_addresses.H>
#include <proc_a_x_pci_dmi_pll_utils.H>
#include <fapi.H>

using namespace fapi;


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// lock polling constants
const uint32_t PROC_A_X_PCI_DMI_PLL_UTILS_MAX_LOCK_POLLS = 50;
const uint32_t PROC_A_X_PCI_DMI_PLL_UTILS_POLL_DELAY_HW = 2000000;
const uint32_t PROC_A_X_PCI_DMI_PLL_UTILS_POLL_DELAY_SIM = 1;

// Pervasive LFIR Register field/bit definitions
const uint8_t PERV_LFIR_SCAN_COLLISION_BIT = 3;

// OPCG/Clock Region Register values
const uint64_t OPCG_REG0_FOR_SETPULSE  = 0x818C000000000000ull;
const uint64_t OPCG_REG2_FOR_SETPULSE  = 0x0000000000002000ull;
const uint64_t OPCG_REG3_FOR_SETPULSE  = 0x6000000000000000ull;
const uint64_t CLK_REGION_FOR_SETPULSE = 0x0010040000000000ull;

// GP3 Register field/bit definitions
const uint8_t GP3_PLL_TEST_ENABLE_BIT = 3;
const uint8_t GP3_PLL_RESET_BIT = 4;
const uint8_t GP3_PLL_BYPASS_BIT = 5;

// PLL Lock Register field/bit definitions
const uint8_t PLL_LOCK_REG_LOCK_START_BIT = 0;
const uint8_t PLL_LOCK_REG_LOCK_END_BIT = 3;


//------------------------------------------------------------------------------
// Function definition
//------------------------------------------------------------------------------

extern "C"
{


//------------------------------------------------------------------------------
// function:
//      Scan PLL boundary ring with setpulse
//
// parameters: i_target                 => chip target
//             i_chiplet_base_scom_addr => aligned base address of chiplet SCOM
//                                         address space
//             i_pll_ring_addr          => PLL ring address
//             i_pll_ring_data          => data buffer containing full PLL ring
//                                         content
//             i_mask_scan_collision    => mask scan collision bit in chiplet
//                                         pervasive LFIR
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------

fapi::ReturnCode proc_a_x_pci_dmi_pll_scan_bndy(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_scom_addr,
    const uint32_t i_pll_ring_addr,
    ecmdDataBufferBase& i_pll_ring_data,
    const bool i_mask_scan_collision)
{
    // data buffer to hold SCOM data
    ecmdDataBufferBase data(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;
    bool unmask_scan_collision = false;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        //-------------------------------------------
        //  Mask Pervasive LFIR
        //------------------------------------------

        if (i_mask_scan_collision)
        {
            FAPI_DBG("Reading value of Pervasive LFIR scan collision mask bit ...");
            rc = fapiGetScom(i_target, i_chiplet_base_scom_addr | GENERIC_PERV_LFIR_MASK_0x0004000D, data);
            if (!rc.ok())
            {
                FAPI_ERR("Error reading Pervasive LFIR Mask OR Register.");
                break;
            }
            unmask_scan_collision = data.isBitClear(PERV_LFIR_SCAN_COLLISION_BIT);            

            FAPI_DBG("Masking Pervasive LFIR scan collision bit ...");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(PERV_LFIR_SCAN_COLLISION_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to set Pervasive LFIR Mask Register.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_PERV_LFIR_MASK_OR_0x0004000F, data);
            if (!rc.ok())
            {
                FAPI_ERR("Error writing Pervasive LFIR Mask OR Register.");
                break;
            }
        }

        //-------------------------------------------
        //  Set the OPCG to generate the setpulse
        //------------------------------------------

        FAPI_DBG("Writing OPCG Register 0 to generate setpulse ...");
        rc_ecmd |= data.setDoubleWord(0, OPCG_REG0_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write OPCG Register 0.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_OPCG_CNTL0_0x00030002, data);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing OPCG Register0 to generate setpulse.");
            break;
        }

        FAPI_DBG("Writing OPCG Register 2 to generate setpulse ...");
        rc_ecmd |= data.setDoubleWord(0, OPCG_REG2_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write OPCG Register 2.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_OPCG_CNTL2_0x00030004, data);
        if (rc)
        {
            FAPI_ERR("Error writing OPCG Register2 to generate setpulse.");
            break;
        }

        FAPI_DBG("Writing OPCG Register 3 to generate setpulse ...");
        rc_ecmd |= data.setDoubleWord(0, OPCG_REG3_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write OPCG Register 3.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_OPCG_CNTL3_0x00030005, data);
        if (rc)
        {
            FAPI_ERR("Error writing OPCG Register3 to generate setpulse.");
            break;
        }

        FAPI_DBG("Writing OPCG Clock Region Register to generate setpulse ...");
        rc_ecmd |= data.setDoubleWord(0, CLK_REGION_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write Clock Region Register.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_CLK_REGION_0x00030006, data);
        if (rc)
        {
            FAPI_ERR("Error writing Clock Region Register to generate setpulse.");
            break;
        }

        //-----------------------------------------------------
        //  Scan new ring data into boundary scan ring
        //-----------------------------------------------------
        rc = fapiPutRing(i_target, i_pll_ring_addr, i_pll_ring_data, RING_MODE_SET_PULSE);
        if (rc)
        {
            FAPI_ERR("fapiPutRing failed with rc = 0x%x", (uint32_t)rc);
            break;
        }
        FAPI_DBG("Loading of the config bits for PLL is done.");


        //-----------------------------------------------------
        //  Set the OPCG back to a good state
        //-----------------------------------------------------

        FAPI_DBG("Writing OPCG Register 3 to clear setpulse ...");
        rc_ecmd |= data.flushTo0();
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear OPCG Register 3.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_OPCG_CNTL3_0x00030005, data);
        if (rc)
        {
            FAPI_ERR("Error writing OPCG Register3 to clear setpulse.");
            break;
        }

        FAPI_DBG("Writing OPCG Clock Region Register to clear setpulse ...");
        rc_ecmd |= data.flushTo0();
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear Clock Region Register.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_CLK_REGION_0x00030006, data);
        if (rc)
        {
            FAPI_ERR("Error writing Clock Region Register to clear setpulse.");
            break;
        }


        //-------------------------------------------
        //  Clear & Unmask Pervasive LFIR
        //------------------------------------------

        if (i_mask_scan_collision)
        {
            FAPI_DBG("Clearing Pervasive LFIR scan collision bit ...");
            rc_ecmd |= data.flushTo1();
            rc_ecmd |= data.clearBit(PERV_LFIR_SCAN_COLLISION_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear Pervasive LFIR Register.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_PERV_LFIR_AND_0x0004000B, data);
            if (!rc.ok())
            {
                FAPI_ERR("Error writing Pervasive LFIR AND Register.");
                break;
            }

            if (unmask_scan_collision)
            {
                FAPI_DBG("Unmasking Pervasive LFIR scan collision bit ...");
                rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_PERV_LFIR_MASK_AND_0x0004000E, data);
                if (!rc.ok())
                {
                    FAPI_ERR("Error writing Pervasive LFIR Mask And Register.");
                    break;
                }
            }
        }
    } while(0);


    // mark function entry
    FAPI_DBG("End");

    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Scan PLL ring to establish runtime state
//
// parameters: i_target                    => chip target
//             i_chiplet_base_scom_addr    => aligned base address of chiplet SCOM
//                                            address space
//             i_pll_ring_addr             => PLL ring address
//             i_pll_ring_data             => data buffer containing full PLL ring
//                                            content
//             i_lctank_pll_vco_workaround => enable 2-pass scan workaround for
//                                            lctank PLL vco runaway issue
//             i_ccalload_ring_offset      => ring offset for ccalload PLL control
//                                            bit (used only if workaround
//                                            is true)
//             i_ccalfmin_ring_offset      => ring offset for ccalfmin PLL control
//                                            bit (used only if workaround
//                                            is true)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_a_x_pci_dmi_pll_scan_pll(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_scom_addr,
    const uint32_t i_pll_ring_addr,
    ecmdDataBufferBase& i_pll_ring_data,
    const bool i_lctank_pll_vco_workaround,
    const uint32_t i_ccalload_ring_offset,
    const uint32_t i_ccalfmin_ring_offset,
    const bool i_mask_scan_collision)
{
    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;
    uint8_t scan_count = 1;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        // modify ring for first scan if workaround is engaged
        if (i_lctank_pll_vco_workaround)
        {
            rc_ecmd |= i_pll_ring_data.setBit(i_ccalload_ring_offset);
            rc_ecmd |= i_pll_ring_data.setBit(i_ccalfmin_ring_offset);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up data buffer to enable lctank PLL vco workaround (scan = %d)", rc_ecmd, scan_count);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }

        // scan with setpulse
        rc = proc_a_x_pci_dmi_pll_scan_bndy(
                i_target,
                i_chiplet_base_scom_addr,
                i_pll_ring_addr,
                i_pll_ring_data,
                i_mask_scan_collision);
        if (!rc.ok())
        {
            FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy (scan = %d)", scan_count);
            break;
        }
        scan_count++;

        // release PLL & re-scan if workaround is engaged
        if (i_lctank_pll_vco_workaround)
        {
            rc = proc_a_x_pci_dmi_pll_release_pll(
                    i_target,
                    i_chiplet_base_scom_addr,
                    false);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_a_x_pci_dmi_pll_release_pll");
                break;
            }

            rc_ecmd |= i_pll_ring_data.setBit(i_ccalload_ring_offset);
            rc_ecmd |= i_pll_ring_data.clearBit(i_ccalfmin_ring_offset);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up data buffer to enable lctank PLL vco workaround (scan = %d)", rc_ecmd, scan_count);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // scan with setpulse
            rc = proc_a_x_pci_dmi_pll_scan_bndy(
                    i_target,
                    i_chiplet_base_scom_addr,
                    i_pll_ring_addr,
                    i_pll_ring_data,
                    i_mask_scan_collision);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_a_x_pci_dmi_pll_scan_bndy (scan = %d)", scan_count);
                break;
            }
        }
    } while(0);

    // mark function entry
    FAPI_DBG("End");

    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Release PLL from test mode/bypass/reset and optionally check for lock
//
// parameters: i_target                 => chip target
//             i_chiplet_base_scom_addr => aligned base address of chiplet SCOM
//                                         address space
//             i_check_lock             => check for PLL lock?
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_a_x_pci_dmi_pll_release_pll(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_scom_addr,
    const bool i_check_lock)
{
    // data buffer to hold SCOM data
    ecmdDataBufferBase data(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("Start proc_a_x_pci_dmi_pll_release_pll");

    do
    {
        FAPI_DBG("Release PLL test enable");
        rc_ecmd |= data.flushTo1();
        rc_ecmd |= data.clearBit(GP3_PLL_TEST_ENABLE_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up data buffer to clear GP3 PLL test enable", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_GP3_AND_0x000F0013, data);
        if (rc)
        {
            FAPI_ERR("Error writing GP3 to clear PLL test enable");
            break;
        }

        FAPI_DBG("Release PLL reset");
        rc_ecmd |= data.flushTo1();
        rc_ecmd |= data.clearBit(GP3_PLL_RESET_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up data buffer to clear GP3 PLL reset", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_GP3_AND_0x000F0013, data);
        if (rc)
        {
            FAPI_ERR("Error writing GP3 to clear PLL reset");
            break;
        }

        FAPI_DBG("Release PLL bypass");
        // 24july2012  mfred moved this before checking PLL lock as this is required for analog PLLs.
        rc_ecmd |= data.flushTo1();
        rc_ecmd |= data.clearBit(GP3_PLL_BYPASS_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up data buffer to clear GP3 PLL bypass", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, i_chiplet_base_scom_addr | GENERIC_GP3_AND_0x000F0013, data);
        if (rc)
        {
            FAPI_ERR("Error writing GP3 to clear PLL bypass");
            break;
        }

        if (i_check_lock)
        {
            FAPI_DBG("Checking for PLL lock...");
            uint32_t num = 0;
            bool timeout = false;

            // poll until PLL is locked or max count is reached
            do
            {
                num++;
                if (num > PROC_A_X_PCI_DMI_PLL_UTILS_MAX_LOCK_POLLS)
                {
                    timeout = 1;
                    break;
                }
                rc = fapiGetScom(i_target, i_chiplet_base_scom_addr | GENERIC_PLLLOCKREG_0x000F0019, data);
                if (rc)
                {
                    FAPI_ERR("Error reading PLL lock register");
                    break;
                }
                rc = fapiDelay(PROC_A_X_PCI_DMI_PLL_UTILS_POLL_DELAY_HW,
                               PROC_A_X_PCI_DMI_PLL_UTILS_POLL_DELAY_SIM);
                if (rc)
                {
                    FAPI_ERR("Error from fapiDelay");
                    break;
                }
            } while (!timeout &&
                     !data.isBitSet(PLL_LOCK_REG_LOCK_START_BIT,
                                    (PLL_LOCK_REG_LOCK_END_BIT-
                                     PLL_LOCK_REG_LOCK_START_BIT+1)));

            if (rc)
            {
                break;
            }
            if (timeout)
            {
                FAPI_ERR("Timed out polling for PLL lock");
                const uint8_t LOCK_STATUS = data.getByte(0);
                if (i_chiplet_base_scom_addr == NEST_CHIPLET_0x02000000)
                {
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_A_X_PCI_DMI_PLL_SETUP_DMI_PLL_NO_LOCK);
                }
                else if (i_chiplet_base_scom_addr == A_BUS_CHIPLET_0x08000000)
                {
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_A_X_PCI_DMI_PLL_SETUP_ABUS_PLL_NO_LOCK);
                }
                else if (i_chiplet_base_scom_addr == PCIE_CHIPLET_0x09000000)
                {
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_A_X_PCI_DMI_PLL_SETUP_PCIE_PLL_NO_LOCK);
                }
                break;
            }
            else
            {
                FAPI_DBG("PLL is locked.");
            }
        }
    } while(0);

    // mark function entry
    FAPI_DBG("End proc_a_x_pci_dmi_pll_release_pll");
    return rc;
}


} // extern "C"
