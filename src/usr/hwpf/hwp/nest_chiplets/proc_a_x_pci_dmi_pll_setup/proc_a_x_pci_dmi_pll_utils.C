/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
// $Id: proc_a_x_pci_dmi_pll_utils.C,v 1.9 2015/08/14 16:31:17 thi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_a_x_pci_dmi_pll_utils.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2015
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_a_x_pci_dmi_pll_utils.C
// *! DESCRIPTION : PLL configuration utility functions
// *!
// *! OWNER NAME  : Joe McGill               Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p8_scom_addresses.H>
#include <proc_a_x_pci_dmi_pll_utils.H>
#include <p8_istep_num.H>
#include <proc_sbe_scan_service.H>
#include <proc_use_sbe_scan_service.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// SBE polling constants
const uint32_t PROC_A_X_PCI_DMI_PLL_UTILS_SBE_MAX_POLLS = 100;
const uint32_t PROC_A_X_PCI_DMI_PLL_UTILS_SBE_POLL_DELAY_HW = 2000000;
const uint32_t PROC_A_X_PCI_DMI_PLL_UTILS_SBE_POLL_DELAY_SIM = 0;

// SBE Control Register field/bit definitions
const uint32_t SBE_CONTROL_REG_CTL_NO_LB_BIT = 0;

// SBE Mailbox0 Register scan request format constants
const uint32_t MBOX0_REQUEST_VALID_BIT = 0;
const uint32_t MBOX0_RING_SELECT_START_BIT = 6;
const uint32_t MBOX0_RING_SELECT_END_BIT = 7;
const uint32_t MBOX0_RING_OP_START_BIT = 9;
const uint32_t MBOX0_RING_OP_END_BIT = 11;
const uint32_t MBOX0_RING_BUS_ID_START_BIT = 13;
const uint32_t MBOX0_RING_BUS_ID_END_BIT = 15;

// SBE MBOX1 Scratch Register scan reply format constants
const uint32_t MBOX1_SCAN_REPLY_SUCCESS_BIT = 0;

// VCO PLL workaround ring offsets
const uint32_t PB_BNDY_DMIPLL_RING_CCALLOAD_OFFSET = 580;
const uint32_t PB_BNDY_DMIPLL_RING_CCALFMIN_OFFSET = 581;

const uint32_t AB_BNDY_PLL_RING_CCALLOAD_OFFSET = 278;
const uint32_t AB_BNDY_PLL_RING_CCALFMIN_OFFSET = 279;

// PLL lock polling constants
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
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

using namespace fapi;

//------------------------------------------------------------------------------
// function:
//      Calculate state to apply to Centaur tp_bndy_pll ring
//
// parameters: i_target      => chip target
//             i_pll_ring_op => modification to be made to PLL content
//             o_ring_data   => data buffer containing ring state to apply
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_pll_utils_calc_memb_tp_bndy_pll(
    const fapi::Target & i_target,
    const p8_pll_utils_ring_op i_pll_ring_op,
    ecmdDataBufferBase & o_ring_data)
{
    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        // determine ring length
        fapi::ATTR_MEMB_TP_BNDY_PLL_LENGTH_Type ring_length;
        rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_LENGTH, &i_target, ring_length);
        if (!rc.ok())
        {
            FAPI_ERR("Failed to get attribute: ATTR_MEMB_TP_BNDY_PLL_LENGTH.");
            break;
        }
        rc_ecmd |= o_ring_data.setBitLength(ring_length);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // determine starting ring state
        if (i_pll_ring_op == RING_OP_BASE)
        {
            // start from attribute data
            fapi::ATTR_MEMB_TP_BNDY_PLL_DATA_Type ring_data_attr = {0};
            rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_DATA, &i_target, ring_data_attr);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_MEMB_TP_BNDY_PLL_DATA.");
                break;
            }
            rc_ecmd |= o_ring_data.insert(ring_data_attr, 0, ring_length, 0);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading scan chain attribute data into buffer.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else
        {
            // start from data currently in ring
            rc = fapiGetRing(i_target, RING_ADDRESS_MEMB_TP_BNDY_PLL, o_ring_data, fapi::RING_MODE_SET_PULSE);
            if (!rc.ok())
            {
                FAPI_ERR("Error from fapiGetRing (ring ID: 0x08%x)", RING_ADDRESS_MEMB_TP_BNDY_PLL);
                break;
            }
        }

        // modify ring data
        if (i_pll_ring_op == RING_OP_MOD_REFCLK_SEL)
        {
            fapi::ATTR_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET_Type refclksel_offset;
            rc = FAPI_ATTR_GET(ATTR_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET, &i_target, refclksel_offset);
            if (!rc.ok())
            {
                FAPI_ERR("Failed to get attribute: ATTR_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET");
                break;
            }

            if (o_ring_data.isBitClear(refclksel_offset))
            {
                rc_ecmd |= o_ring_data.setBit(refclksel_offset);
            }
            else
            {
                rc_ecmd |= o_ring_data.clearBit(refclksel_offset);
            }
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading refclock select attribute data into buffer.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else if (i_pll_ring_op == RING_OP_MOD_PFD360)
        {
            fapi::ATTR_MEMB_DMI_CUPLL_PFD360_OFFSET_Type pfd360_offset;
            rc = FAPI_ATTR_GET(ATTR_MEMB_DMI_CUPLL_PFD360_OFFSET, &i_target, pfd360_offset);
            if (!rc.ok())
            {
                FAPI_ERR("Failed to get attribute: ATTR_MEMB_DMI_CUPLL_PFD360_OFFSET");
                break;
            }

            if (o_ring_data.isBitClear(pfd360_offset))
            {
                rc_ecmd |= o_ring_data.setBit(pfd360_offset);
            }
            else
            {
                rc_ecmd |= o_ring_data.clearBit(pfd360_offset);
            }

            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading pfd360 attribute data into buffer.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("End");

    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Calculate state to apply to processor pci_bndy_pll ring
//
// parameters: i_target     => chip target
//             o_ring_data  => data buffer containing ring state to apply
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_pll_utils_calc_proc_pci_bndy_pll(
    const fapi::Target & i_target,
    ecmdDataBufferBase & o_ring_data)
{
    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        // determine ring length
        fapi::ATTR_PROC_PCI_BNDY_PLL_LENGTH_Type ring_length;
        rc = FAPI_ATTR_GET(ATTR_PROC_PCI_BNDY_PLL_LENGTH, &i_target, ring_length);
        if (!rc.ok())
        {
            FAPI_ERR("Failed to get attribute: ATTR_PROC_PCI_BNDY_PLL_LENGTH.");
            break;
        }
        rc_ecmd |= o_ring_data.setBitLength(ring_length);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // determine starting ring state
        fapi::ATTR_PROC_PCI_BNDY_PLL_DATA_Type ring_data_attr = {0};
        rc = FAPI_ATTR_GET(ATTR_PROC_PCI_BNDY_PLL_DATA, &i_target, ring_data_attr);
        if (rc)
        {
            FAPI_ERR("Failed to get attribute: ATTR_PROC_PCI_BNDY_PLL_DATA.");
            break;
        }
        rc_ecmd |= o_ring_data.insert(ring_data_attr, 0, ring_length, 0);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x loading scan chain attribute data into buffer.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("End");

    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Calculate state to apply to processor pb_bndy_dmipll ring
//
// parameters: i_target      => chip target
//             i_pll_ring_op => modification to be made to base PLL content
//             i_pll_bus_id  => bus instance to target for modification
//             o_ring_data   => data buffer containing ring state to apply
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_pll_utils_calc_proc_pb_bndy_dmipll(
    const fapi::Target & i_target,
    const p8_pll_utils_ring_op i_pll_ring_op,
    const p8_pll_utils_bus_id i_pll_bus_id,
    ecmdDataBufferBase & o_ring_data)
{
    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        // determine ring length
        fapi::ATTR_PROC_PB_BNDY_DMIPLL_LENGTH_Type ring_length;
        rc = FAPI_ATTR_GET(ATTR_PROC_PB_BNDY_DMIPLL_LENGTH, &i_target, ring_length);
        if (!rc.ok())
        {
            FAPI_ERR("Failed to get attribute: ATTR_PROC_PB_BNDY_DMIPLL_LENGTH.");
            break;
        }
        rc_ecmd |= o_ring_data.setBitLength(ring_length);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // determine starting ring state
        if (i_pll_ring_op == RING_OP_BASE)
        {
            // start from attribute data
            fapi::ATTR_PROC_PB_BNDY_DMIPLL_DATA_Type ring_data_attr = {0};
            rc = FAPI_ATTR_GET(ATTR_PROC_PB_BNDY_DMIPLL_DATA, &i_target, ring_data_attr);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_PB_BNDY_DMIPLL_DATA.");
                break;
            }
            rc_ecmd |= o_ring_data.insert(ring_data_attr, 0, ring_length, 0);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading scan chain attribute data into buffer.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else
        {
            // start from data currently in ring
            rc = fapiGetRing(i_target, RING_ADDRESS_PROC_PB_BNDY_DMIPLL, o_ring_data, fapi::RING_MODE_SET_PULSE);
            if (!rc.ok())
            {
                FAPI_ERR("Error from fapiGetRing (ring ID: 0x08%x)", RING_ADDRESS_PROC_PB_BNDY_DMIPLL);
                break;
            }
        }

        // modify ring data
        if (i_pll_ring_op == RING_OP_MOD_VCO_S1)
        {
            rc_ecmd |= o_ring_data.setBit(PB_BNDY_DMIPLL_RING_CCALLOAD_OFFSET);
            rc_ecmd |= o_ring_data.setBit(PB_BNDY_DMIPLL_RING_CCALFMIN_OFFSET);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up data buffer to enable lctank PLL vco workaround (scan1)", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else if (i_pll_ring_op == RING_OP_MOD_VCO_S2)
        {
            rc_ecmd |= o_ring_data.setBit(PB_BNDY_DMIPLL_RING_CCALLOAD_OFFSET);
            rc_ecmd |= o_ring_data.clearBit(PB_BNDY_DMIPLL_RING_CCALFMIN_OFFSET);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up data buffer to enable lctank PLL vco workaround (scan2)", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else if (i_pll_ring_op == RING_OP_MOD_REFCLK_SEL)
        {
            fapi::ATTR_PROC_DMI_CUPLL_REFCLKSEL_OFFSET_Type refclksel_offset = {0};
            rc = FAPI_ATTR_GET(ATTR_PROC_DMI_CUPLL_REFCLKSEL_OFFSET, &i_target, refclksel_offset);
            if (!rc.ok())
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_DMI_CUPLL_REFCLKSEL_OFFSET");
                break;
            }

            if (o_ring_data.isBitSet(refclksel_offset[i_pll_bus_id]))
            {
                rc_ecmd |= o_ring_data.clearBit(refclksel_offset[i_pll_bus_id]);
            }
            else
            {
                rc_ecmd |= o_ring_data.setBit(refclksel_offset[i_pll_bus_id]);
            }
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading refclock select attribute data into buffer.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else if (i_pll_ring_op == RING_OP_MOD_PFD360)
        {
            fapi::ATTR_PROC_DMI_CUPLL_PFD360_OFFSET_Type pfd360_offset;
            rc = FAPI_ATTR_GET(ATTR_PROC_DMI_CUPLL_PFD360_OFFSET, &i_target, pfd360_offset);
            if (!rc.ok())
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_DMI_CUPLL_PFD360_OFFSET");
                break;
            }

            if (o_ring_data.isBitSet(pfd360_offset[i_pll_bus_id]))
            {
                rc_ecmd |= o_ring_data.clearBit(pfd360_offset[i_pll_bus_id]);
            }
            else
            {
                rc_ecmd |= o_ring_data.setBit(pfd360_offset[i_pll_bus_id]);
            }
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading pfd360 attribute data into buffer.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("End");

    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Calculate state to apply to processor ab_bndy_pll ring
//
// parameters: i_target      => chip target
//             i_pll_ring_op => modification to be made to base PLL content
//             i_pll_bus_id  => bus instance to target for modification
//             o_ring_data   => data buffer containing ring state to apply
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_pll_utils_calc_proc_ab_bndy_pll(
    const fapi::Target & i_target,
    const p8_pll_utils_ring_op i_pll_ring_op,
    const p8_pll_utils_bus_id i_pll_bus_id,
    ecmdDataBufferBase & o_ring_data)
{
    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        // determine ring length
        fapi::ATTR_PROC_AB_BNDY_PLL_LENGTH_Type ring_length;
        rc = FAPI_ATTR_GET(ATTR_PROC_AB_BNDY_PLL_LENGTH, &i_target, ring_length);
        if (!rc.ok())
        {
            FAPI_ERR("Failed to get attribute: ATTR_PROC_AB_BNDY_PLL_LENGTH.");
            break;
        }
        rc_ecmd |= o_ring_data.setBitLength(ring_length);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting ecmd data buffer length. Buffer must be set to length of scan chain.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // determine starting ring state
        if (i_pll_ring_op == RING_OP_BASE)
        {
            // start from attribute data
            fapi::ATTR_PROC_AB_BNDY_PLL_DATA_Type ring_data_attr = {0};
            rc = FAPI_ATTR_GET(ATTR_PROC_AB_BNDY_PLL_DATA, &i_target, ring_data_attr);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_AB_BNDY_PLL_DATA.");
                break;
            }
            rc_ecmd |= o_ring_data.insert(ring_data_attr, 0, ring_length, 0);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading scan chain attribute data into buffer.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else
        {
            // start from data currently in ring
            rc = fapiGetRing(i_target, RING_ADDRESS_PROC_AB_BNDY_PLL, o_ring_data, fapi::RING_MODE_SET_PULSE);
            if (!rc.ok())
            {
                FAPI_ERR("Error from fapiGetRing (ring ID: 0x08%x)", RING_ADDRESS_PROC_AB_BNDY_PLL);
                break;
            }
        }

        // modify ring data
        if (i_pll_ring_op == RING_OP_MOD_VCO_S1)
        {
            rc_ecmd |= o_ring_data.setBit(AB_BNDY_PLL_RING_CCALLOAD_OFFSET);
            rc_ecmd |= o_ring_data.setBit(AB_BNDY_PLL_RING_CCALFMIN_OFFSET);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up data buffer to enable lctank PLL vco workaround (scan1)", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else if (i_pll_ring_op == RING_OP_MOD_VCO_S2)
        {
            rc_ecmd |= o_ring_data.setBit(AB_BNDY_PLL_RING_CCALLOAD_OFFSET);
            rc_ecmd |= o_ring_data.clearBit(AB_BNDY_PLL_RING_CCALFMIN_OFFSET);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up data buffer to enable lctank PLL vco workaround (scan2)", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else if (i_pll_ring_op == RING_OP_MOD_REFCLK_SEL)
        {
            fapi::ATTR_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET_Type refclksel_offset = {0};
            rc = FAPI_ATTR_GET(ATTR_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET, &i_target, refclksel_offset);
            if (!rc.ok())
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET");
                break;
            }

            if (o_ring_data.isBitSet(refclksel_offset[i_pll_bus_id]))
            {
                rc_ecmd |= o_ring_data.clearBit(refclksel_offset[i_pll_bus_id]);
            }
            else
            {
                rc_ecmd |= o_ring_data.setBit(refclksel_offset[i_pll_bus_id]);
            }
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading refclock select attribute data into buffer.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else if (i_pll_ring_op == RING_OP_MOD_PFD360)
        {
            fapi::ATTR_PROC_ABUS_CUPLL_PFD360_OFFSET_Type pfd360_offset;
            rc = FAPI_ATTR_GET(ATTR_PROC_ABUS_CUPLL_PFD360_OFFSET, &i_target, pfd360_offset);
            if (!rc.ok())
            {
                FAPI_ERR("Failed to get attribute: ATTR_PROC_ABUS_CUPLL_PFD360_OFFSET");
                break;
            }

            if (o_ring_data.isBitSet(pfd360_offset[i_pll_bus_id]))
            {
                rc_ecmd |= o_ring_data.clearBit(pfd360_offset[i_pll_bus_id]);
            }
            else
            {
                rc_ecmd |= o_ring_data.setBit(pfd360_offset[i_pll_bus_id]);
            }
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x loading pfd360 attribute data into buffer.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("End");
    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Poll for SBE to reach designated state (interlocked with scan requests)
//
// parameters: i_target     => chip target
//             i_poll_limit => number of polls permitted before timeout
//
// returns: FAPI_RC_SUCCESS if desired state was reached, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_pll_utils_poll_sbe(
    const fapi::Target & i_target,
    const uint32_t i_num_polls)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    uint32_t poll_num = 0;
    bool poll_timeout = false;
    bool sbe_running = true;
    bool sbe_ready = false;

    ecmdDataBufferBase sbe_control_data(64);
    ecmdDataBufferBase sbe_vital_data(64);
    uint32_t istep_num;
    uint8_t substep_num;
    ecmdDataBufferBase mbox_data(64);

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        do
        {
            // delay between poll attempts
            if (poll_num)
            {
                FAPI_DBG("Pausing prior to next poll...");
                rc = fapiDelay(PROC_A_X_PCI_DMI_PLL_UTILS_SBE_POLL_DELAY_HW,
                               PROC_A_X_PCI_DMI_PLL_UTILS_SBE_POLL_DELAY_SIM);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from fapiDelay");
                    break;
                }
            }

            // increment poll count, timeout if threshold exceeded
            poll_num++;
            if (poll_num > i_num_polls)
            {
                poll_timeout = true;
                break;
            }

            // determine SBE run state
            FAPI_DBG("Reading SBE state (poll %d / %d)", poll_num, i_num_polls);
            rc = fapiGetScom(i_target, PORE_SBE_CONTROL_0x000E0001, sbe_control_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error reading SBE Control Register");
                break;
            }
            sbe_running = sbe_control_data.isBitClear(SBE_CONTROL_REG_CTL_NO_LB_BIT);
            FAPI_DBG("Run state: %s", ((sbe_running)?("run"):("halted")));

            // get SBE istep/substep information
            rc = fapiGetScom(i_target, MBOX_SBEVITAL_0x0005001C, sbe_vital_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error reading SBE Vital Register");
                break;
            }

            rc_ecmd |= sbe_vital_data.extractToRight(&istep_num,
                                                     ISTEP_NUM_BIT_POSITION,
                                                     ISTEP_NUM_BIT_LENGTH);
            rc_ecmd |= sbe_vital_data.extractToRight(&substep_num,
                                                     SUBSTEP_NUM_BIT_POSITION,
                                                     SUBSTEP_NUM_BIT_LENGTH);
            if (rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // get HB->SBE request mailbox, check that it is clear
            rc = fapiGetScom(i_target, MBOX_SCRATCH_REG0_0x00050038, mbox_data);
            if (!rc.ok())
            {
                FAPI_ERR("Scom error reading SBE MBOX0 Register");
                break;
            }

            sbe_ready = (istep_num == PROC_SBE_SCAN_SERVICE_ISTEP_NUM) &&
                        (substep_num == SUBSTEP_SBE_READY) &&
                        (mbox_data.getDoubleWord(0) == 0);

            FAPI_DBG("Istep: 0x%03X, Substep: %X, MBOX: %016llX", istep_num, substep_num, mbox_data.getDoubleWord(0));

        } while (!poll_timeout &&
                 sbe_running &&
                 !sbe_ready);

        if (!rc.ok())
        {
            break;
        }
        if (!sbe_running)
        {
            FAPI_ERR("SBE is NOT running!");
            const fapi::Target & TARGET = i_target;
            ecmdDataBufferBase & SBE_CONTROL = sbe_control_data;
            FAPI_SET_HWP_ERROR(rc, RC_P8_PLL_UTILS_SBE_STOPPED);
            break;
        }
        if (poll_timeout || !sbe_ready)
        {
            FAPI_ERR("Poll limit reached waiting for SBE to attain expected state");
            FAPI_ERR("Expected istep 0x%03llX, substep 0x%X but found istep 0x%03X, substep 0x%X",
                     PROC_SBE_SCAN_SERVICE_ISTEP_NUM, SUBSTEP_SBE_READY,
                     istep_num, substep_num);
            const fapi::Target & TARGET = i_target;
            const uint32_t & POLL_COUNT = i_num_polls;
            const ecmdDataBufferBase & SBE_VITAL = sbe_vital_data;
            FAPI_SET_HWP_ERROR(rc, RC_P8_PLL_UTILS_SBE_TIMEOUT_ERROR);
            break;
        }

        FAPI_DBG("SBE reached expected state");

    } while(0);

    // mark function entry
    FAPI_DBG("End");
    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Scan PLL boundary ring with setpulse (scan executed by SBE)
//
// parameters: i_target              => chip target
//             i_pll_ring_addr       => PLL ring address
//             i_pll_ring_op         => modification to be made to base PLL content
//             i_pll_bus_id          => bus instance to target for modification
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_pll_utils_scan_bndy_sbe(
    const fapi::Target & i_target,
    const p8_pll_utils_ring_address i_pll_ring_addr,
    const p8_pll_utils_ring_op i_pll_ring_op,
    const p8_pll_utils_bus_id i_pll_bus_id)
{
    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        // check request content
        p8_pll_utils_ring_id pll_ring_id;
        if (i_pll_ring_addr == RING_ADDRESS_PROC_AB_BNDY_PLL)
        {
            pll_ring_id = RING_ID_ABUS;
        }
        else if (i_pll_ring_addr == RING_ADDRESS_PROC_PCI_BNDY_PLL)
        {
            pll_ring_id = RING_ID_PCI;
        }
        else if (i_pll_ring_addr == RING_ADDRESS_PROC_PB_BNDY_DMIPLL)
        {
            pll_ring_id = RING_ID_DMI;
        }
        else
        {
            FAPI_ERR("Invalid/unsupported SBE ring operation requested");
            const fapi::Target & TARGET = i_target;
            const p8_pll_utils_ring_address & PLL_RING_ADDR = i_pll_ring_addr;
            const p8_pll_utils_ring_op & PLL_RING_OP = i_pll_ring_op;
            const p8_pll_utils_bus_id & PLL_BUS_ID = i_pll_bus_id;
            const bool & INVALID_RING_ADDRESS = true;
            const bool & INVALID_RING_OP = false;
            const bool & INVALID_BUS_ID = false;
            FAPI_SET_HWP_ERROR(rc, RC_P8_PLL_UTILS_INVALID_OPERATION);
            break;
        }

        // verify that SBE is ready to service scan operation
        // (it should be waiting for our request)
        FAPI_DBG("Checking SBE is ready to receive scan request");
        rc = p8_pll_utils_poll_sbe(i_target, 1);
        if (!rc.ok())
        {
            FAPI_ERR("Error from p8_pll_utils_poll_sbe");
            break;
        }

        // construct scan request format
        ecmdDataBufferBase mbox_data(64);
        rc_ecmd |= mbox_data.setBit(MBOX0_REQUEST_VALID_BIT);
        rc_ecmd |= mbox_data.insertFromRight(static_cast<uint32_t>(pll_ring_id),
                                             MBOX0_RING_SELECT_START_BIT,
                                             (MBOX0_RING_SELECT_END_BIT-
                                              MBOX0_RING_SELECT_START_BIT+1));
        rc_ecmd |= mbox_data.insertFromRight(static_cast<uint32_t>(i_pll_ring_op),
                                             MBOX0_RING_OP_START_BIT,
                                             (MBOX0_RING_OP_END_BIT-
                                              MBOX0_RING_OP_START_BIT+1));
        rc_ecmd |= mbox_data.insertFromRight(static_cast<uint32_t>(i_pll_bus_id),
                                             MBOX0_RING_BUS_ID_START_BIT,
                                             (MBOX0_RING_BUS_ID_END_BIT-
                                              MBOX0_RING_BUS_ID_START_BIT+1));
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up SBE MBOX0 data buffer.", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // submit request to SBE
        FAPI_DBG("Submitting scan request to SBE");
        rc = fapiPutScom(i_target, MBOX_SCRATCH_REG0_0x00050038, mbox_data);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing SBE MBOX0 Register");
            break;
        }

        // poll until SBE drops response SBE indicates scan is finished (back to 'ready' state)
        // or until maximum poll count is reached
        FAPI_DBG("Polling for SBE completion...");
        rc = p8_pll_utils_poll_sbe(i_target,
                                   PROC_A_X_PCI_DMI_PLL_UTILS_SBE_MAX_POLLS);
        if (!rc.ok())
        {
            FAPI_ERR("Error from p8_pll_utils_poll_sbe");
            break;
        }

        // check result of scan operation
        FAPI_DBG("SBE reached ready state, checking result of scan operation");
        rc = fapiGetScom(i_target, MBOX_SCRATCH_REG1_0x00050039, mbox_data);
        if (!rc.ok())
        {
            FAPI_ERR("Error reading SBE MBOX1 Register");
            break;
        }

        if (mbox_data.isBitClear(MBOX1_SCAN_REPLY_SUCCESS_BIT))
        {
            FAPI_ERR("SBE indicated scan operation failure!");
            const fapi::Target & TARGET = i_target;
            const p8_pll_utils_ring_address & PLL_RING_ADDR = i_pll_ring_addr;
            const p8_pll_utils_ring_op & PLL_RING_OP = i_pll_ring_op;
            const p8_pll_utils_bus_id & PLL_BUS_ID = i_pll_bus_id;
            const ecmdDataBufferBase & MBOX1_DATA = mbox_data;
            FAPI_SET_HWP_ERROR(rc, RC_P8_PLL_UTILS_SBE_SCAN_ERROR);
            break;
        }

        FAPI_DBG("SBE reply indicates scan was successful!");

    } while(0);

    // mark function exit
    FAPI_DBG("End");
    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Scan PLL boundary ring with setpulse (scan executed by HB/FSP platform)
//
// parameters: i_target              => chip target
//             i_pll_ring_addr       => PLL ring address
//             i_pll_ring_op         => modification to be made to base PLL content
//             i_pll_bus_id          => bus instance to target for modification
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_pll_utils_scan_bndy_non_sbe(
    const fapi::Target & i_target,
    const p8_pll_utils_ring_address i_pll_ring_addr,
    const p8_pll_utils_ring_op i_pll_ring_op,
    const p8_pll_utils_bus_id i_pll_bus_id)
{
    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        // form base chiplet ID / ring data to scan
        uint32_t chiplet_base_scom_addr;
        ecmdDataBufferBase ring_data;
        if (i_pll_ring_addr == RING_ADDRESS_MEMB_TP_BNDY_PLL)
        {
            chiplet_base_scom_addr = TP_CHIPLET_0x01000000;
            rc = p8_pll_utils_calc_memb_tp_bndy_pll(i_target,
                                                    i_pll_ring_op,
                                                    ring_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error from p8_pll_utils_calc_memb_tp_bndy_pll");
                break;
            }
        }
        else if (i_pll_ring_addr == RING_ADDRESS_PROC_PB_BNDY_DMIPLL)
        {
            chiplet_base_scom_addr = NEST_CHIPLET_0x02000000;
            rc = p8_pll_utils_calc_proc_pb_bndy_dmipll(i_target,
                                                       i_pll_ring_op,
                                                       i_pll_bus_id,
                                                       ring_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error from p8_pll_utils_calc_proc_pb_bndy_dmipll");
                break;
            }
        }
        else if (i_pll_ring_addr == RING_ADDRESS_PROC_AB_BNDY_PLL)
        {
            chiplet_base_scom_addr = A_BUS_CHIPLET_0x08000000;
            rc = p8_pll_utils_calc_proc_ab_bndy_pll(i_target,
                                                    i_pll_ring_op,
                                                    i_pll_bus_id,
                                                    ring_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error from p8_pll_utils_calc_proc_ab_bndy_pll");
                break;
            }
        }
        else
        {
            chiplet_base_scom_addr = PCIE_CHIPLET_0x09000000;
            rc = p8_pll_utils_calc_proc_pci_bndy_pll(i_target,
                                                     ring_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error from p8_pll_utils_calc_proc_pci_bndy_pll");
                break;
            }
        }

        // configure OPCG to generate setpulse
        ecmdDataBufferBase scom_data(64);
        FAPI_DBG("Writing OPCG Register 0 to generate setpulse ...");
        rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG0_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write OPCG Register 0.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, chiplet_base_scom_addr | GENERIC_OPCG_CNTL0_0x00030002, scom_data);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing OPCG Register0 to generate setpulse.");
            break;
        }

        FAPI_DBG("Writing OPCG Register 2 to generate setpulse ...");
        rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG2_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write OPCG Register 2.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, chiplet_base_scom_addr | GENERIC_OPCG_CNTL2_0x00030004, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing OPCG Register2 to generate setpulse.");
            break;
        }

        FAPI_DBG("Writing OPCG Register 3 to generate setpulse ...");
        rc_ecmd |= scom_data.setDoubleWord(0, OPCG_REG3_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write OPCG Register 3.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, chiplet_base_scom_addr | GENERIC_OPCG_CNTL3_0x00030005, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing OPCG Register3 to generate setpulse.");
            break;
        }

        FAPI_DBG("Writing OPCG Clock Region Register to generate setpulse ...");
        rc_ecmd |= scom_data.setDoubleWord(0, CLK_REGION_FOR_SETPULSE);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write Clock Region Register.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, chiplet_base_scom_addr | GENERIC_CLK_REGION_0x00030006, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing Clock Region Register to generate setpulse.");
            break;
        }

        // scan new ring data into PLL boundary scan ring
        rc = fapiPutRing(i_target, i_pll_ring_addr, ring_data, fapi::RING_MODE_SET_PULSE);
        if (rc)
        {
            FAPI_ERR("fapiPutRing failed with rc = 0x%x", (uint32_t) rc);
            break;
        }
        FAPI_DBG("Loading of the config bits for PLL is done.");


        // set the OPCG back to a good state
        FAPI_DBG("Writing OPCG Register 3 to clear setpulse ...");
        rc_ecmd |= scom_data.flushTo0();
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear OPCG Register 3.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, chiplet_base_scom_addr | GENERIC_OPCG_CNTL3_0x00030005, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing OPCG Register3 to clear setpulse.");
            break;
        }

        FAPI_DBG("Writing OPCG Clock Region Register to clear setpulse ...");
        rc_ecmd |= scom_data.flushTo0();
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear Clock Region Register.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, chiplet_base_scom_addr | GENERIC_CLK_REGION_0x00030006, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing Clock Region Register to clear setpulse.");
            break;
        }

    } while(0);

    // mark function exit
    FAPI_DBG("End");
    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Scan PLL boundary ring with setpulse
//
// parameters: i_target              => chip target
//             i_pll_ring_addr       => PLL ring address
//             i_pll_ring_op         => modification to be made to base PLL content
//             i_pll_bus_id          => bus instance to target for modification
//             i_mask_scan_collision => mask scan collision bit in chiplet
//                                      pervasive LFIR
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_a_x_pci_dmi_pll_scan_bndy(
    const fapi::Target& i_target,
    const p8_pll_utils_ring_address i_pll_ring_addr,
    const p8_pll_utils_ring_op i_pll_ring_op,
    const p8_pll_utils_bus_id i_pll_bus_id,
    const bool i_mask_scan_collision)
{
    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // mark function entry
    FAPI_DBG("Start");

    do
    {
        // check validity of arguments
        bool invalid_ring_address = ((i_pll_ring_addr != RING_ADDRESS_MEMB_TP_BNDY_PLL) &&
                                     (i_pll_ring_addr != RING_ADDRESS_PROC_PB_BNDY_DMIPLL) &&
                                     (i_pll_ring_addr != RING_ADDRESS_PROC_AB_BNDY_PLL) &&
                                     (i_pll_ring_addr != RING_ADDRESS_PROC_PCI_BNDY_PLL));
        bool invalid_ring_op = (((i_pll_ring_op != RING_OP_BASE) &&
                                 (i_pll_ring_op != RING_OP_MOD_VCO_S1) &&
                                 (i_pll_ring_op != RING_OP_MOD_VCO_S2) &&
                                 (i_pll_ring_op != RING_OP_MOD_REFCLK_SEL) &&
                                 (i_pll_ring_op != RING_OP_MOD_PFD360)) ||
                                ((i_pll_ring_addr == RING_ADDRESS_MEMB_TP_BNDY_PLL) &&
                                 ((i_pll_ring_op == RING_OP_MOD_VCO_S1) ||
                                  (i_pll_ring_op == RING_OP_MOD_VCO_S2))) ||
                                ((i_pll_ring_addr == RING_ADDRESS_PROC_PCI_BNDY_PLL) &&
                                 (i_pll_ring_op != RING_OP_BASE)));
        bool invalid_bus_id = ((((i_pll_ring_addr == RING_ADDRESS_MEMB_TP_BNDY_PLL) ||
                                 (i_pll_ring_addr == RING_ADDRESS_PROC_PCI_BNDY_PLL)) &&
                                (i_pll_bus_id != RING_BUS_ID_0)) ||
                               (((i_pll_ring_op == RING_OP_BASE) ||
                                 (i_pll_ring_op == RING_OP_MOD_VCO_S1) ||
                                 (i_pll_ring_op == RING_OP_MOD_VCO_S2)) &&
                                (i_pll_bus_id != RING_BUS_ID_0)) ||
                               ((i_pll_ring_addr == RING_ADDRESS_PROC_AB_BNDY_PLL) &&
                                (i_pll_bus_id != RING_BUS_ID_0) &&
                                (i_pll_bus_id != RING_BUS_ID_1) &&
                                (i_pll_bus_id != RING_BUS_ID_2) &&
                                (i_pll_bus_id != RING_BUS_ID_3)) ||
                               ((i_pll_ring_addr == RING_ADDRESS_PROC_PB_BNDY_DMIPLL) &&
                                (i_pll_bus_id != RING_BUS_ID_0) &&
                                (i_pll_bus_id != RING_BUS_ID_1) &&
                                (i_pll_bus_id != RING_BUS_ID_2) &&
                                (i_pll_bus_id != RING_BUS_ID_3) &&
                                (i_pll_bus_id != RING_BUS_ID_4) &&
                                (i_pll_bus_id != RING_BUS_ID_5) &&
                                (i_pll_bus_id != RING_BUS_ID_6) &&
                                (i_pll_bus_id != RING_BUS_ID_7)));

        if (invalid_ring_address ||
            invalid_ring_op ||
            invalid_bus_id)
        {
            FAPI_ERR("Invalid/unsupported ring operation requested");
            FAPI_ERR("  ring address: %x (invalid = %d)", i_pll_ring_addr, invalid_ring_address);
            FAPI_ERR("  ring op: %x (invalid = %d)", i_pll_ring_op, invalid_ring_op);
            FAPI_ERR("  bus id: %x (invalid = %d)", i_pll_bus_id, invalid_bus_id);

            const fapi::Target & TARGET = i_target;
            const p8_pll_utils_ring_address & PLL_RING_ADDR = i_pll_ring_addr;
            const p8_pll_utils_ring_op & PLL_RING_OP = i_pll_ring_op;
            const p8_pll_utils_bus_id & PLL_BUS_ID = i_pll_bus_id;
            const bool & INVALID_RING_ADDRESS = invalid_ring_address;
            const bool & INVALID_RING_OP = invalid_ring_op;
            const bool & INVALID_BUS_ID = invalid_bus_id;
            FAPI_SET_HWP_ERROR(rc, RC_P8_PLL_UTILS_INVALID_OPERATION);
            break;
        }

        // optionally mask pervasive LFIR prior to scan operation
        bool unmask_scan_collision = false;
        uint32_t chiplet_base_scom_addr;
        ecmdDataBufferBase scom_data(64);
        if (i_pll_ring_addr == RING_ADDRESS_MEMB_TP_BNDY_PLL)
        {
            chiplet_base_scom_addr = TP_CHIPLET_0x01000000;
        }
        else if (i_pll_ring_addr == RING_ADDRESS_PROC_PB_BNDY_DMIPLL)
        {
            chiplet_base_scom_addr = NEST_CHIPLET_0x02000000;
        }
        else if (i_pll_ring_addr == RING_ADDRESS_PROC_AB_BNDY_PLL)
        {
            chiplet_base_scom_addr = A_BUS_CHIPLET_0x08000000;
        }
        else
        {
            chiplet_base_scom_addr = PCIE_CHIPLET_0x09000000;
        }

        if (i_mask_scan_collision)
        {
            FAPI_DBG("Reading value of Pervasive LFIR scan collision mask bit ...");
            rc = fapiGetScom(i_target, chiplet_base_scom_addr | GENERIC_PERV_LFIR_MASK_0x0004000D, scom_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error reading Pervasive LFIR Mask OR Register.");
                break;
            }
            unmask_scan_collision = scom_data.isBitClear(PERV_LFIR_SCAN_COLLISION_BIT);

            FAPI_DBG("Masking Pervasive LFIR scan collision bit ...");
            rc_ecmd |= scom_data.flushTo0();
            rc_ecmd |= scom_data.setBit(PERV_LFIR_SCAN_COLLISION_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to set Pervasive LFIR Mask Register.", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, chiplet_base_scom_addr | GENERIC_PERV_LFIR_MASK_OR_0x0004000F, scom_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error writing Pervasive LFIR Mask OR Register.");
                break;
            }
        }

        // make determination of scan path to use
        bool use_sbe;
        FAPI_EXEC_HWP(rc, proc_use_sbe_scan_service, i_target, use_sbe);
        if (!rc.ok())
        {
            FAPI_ERR("Error from proc_use_sbe_scan_service");
            break;
        }

        // scan path determined
        // request SCAN via SBE (SBE holds data)
        if (use_sbe)
        {
            rc = p8_pll_utils_scan_bndy_sbe(i_target,
                                            i_pll_ring_addr,
                                            i_pll_ring_op,
                                            i_pll_bus_id);
            if (!rc.ok())
            {
                FAPI_ERR("Error from p8_pll_utils_scan_bndy_sbe");
                break;
            }
        }
        // construct ring content to scan via attributes, invoke FAPI API
        else
        {
            rc = p8_pll_utils_scan_bndy_non_sbe(i_target,
                                                i_pll_ring_addr,
                                                i_pll_ring_op,
                                                i_pll_bus_id);
            if (!rc.ok())
            {
                FAPI_ERR("Error from p8_pll_utils_scan_bndy_non_sbe");
                break;
            }
        }

        // clear & Unmask Pervasive LFIR
        if (i_mask_scan_collision)
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
            rc = fapiPutScom(i_target, chiplet_base_scom_addr | GENERIC_PERV_LFIR_AND_0x0004000B, scom_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error writing Pervasive LFIR AND Register.");
                break;
            }

            if (unmask_scan_collision)
            {
                FAPI_DBG("Unmasking Pervasive LFIR scan collision bit ...");
                rc = fapiPutScom(i_target, chiplet_base_scom_addr | GENERIC_PERV_LFIR_MASK_AND_0x0004000E, scom_data);
                if (!rc.ok())
                {
                    FAPI_ERR("Error writing Pervasive LFIR Mask And Register.");
                    break;
                }
            }
        }

    } while(0);

    // mark function exit
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
    FAPI_DBG("Start");

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
                const fapi::Target & CHIP_IN_ERROR = i_target;
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
    FAPI_DBG("End");
    return rc;
}


} // extern "C"
