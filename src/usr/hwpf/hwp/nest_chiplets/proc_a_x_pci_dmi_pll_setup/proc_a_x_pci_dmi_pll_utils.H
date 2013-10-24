/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_utils.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: proc_a_x_pci_dmi_pll_utils.H,v 1.2 2013/09/30 16:09:57 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_a_x_pci_dmi_pll_utils.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_a_x_pci_dmi_pll_utils.H
// *! DESCRIPTION : A/X/PCI/DMI PLL utility functions
// *!
// *! OWNER NAME  : Ralph Koester            Email: rkoester@de.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_A_X_PCI_DMI_PLL_UTILS_H_
#define _PROC_A_X_PCI_DMI_PLL_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const uint32_t TP_BNDY_PLL_RING_ADDR    = 0x00030088;
const uint32_t PB_BNDY_DMIPLL_RING_ADDR = 0x02030088;
const uint32_t AB_BNDY_PLL_RING_ADDR    = 0x08030088;
const uint32_t PCI_BNDY_PLL_RING_ADDR   = 0x09030088;

const uint32_t DMI_PLL_VCO_WORKAROUND_THRESHOLD_FREQ = 4800;

const uint32_t PB_BNDY_DMIPLL_RING_CCALLOAD_OFFSET = 580;
const uint32_t PB_BNDY_DMIPLL_RING_CCALFMIN_OFFSET = 581;

const uint32_t AB_BNDY_PLL_RING_CCALLOAD_OFFSET = 278;
const uint32_t AB_BNDY_PLL_RING_CCALFMIN_OFFSET = 279;

const uint32_t PCI_BNDY_PLL_RING_CCALLOAD_OFFSET = 0x0;
const uint32_t PCI_BNDY_PLL_RING_CCALFMIN_OFFSET = 0x0;


//------------------------------------------------------------------------------
// Function prototypes
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
    const bool i_mask_scan_collision);


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
//             i_mask_scan_collision       => mask scan collision bit in chiplet
//                                            pervasive LFIR
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
    const bool i_mask_scan_collision);


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
    const bool i_check_lock);


} // extern "C"

#endif // _PROC_A_X_PCI_DMI_PLL_UTILS_H_
