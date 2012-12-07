/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/mss_getecid/mss_get_cen_ecid.H $ */
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
// $Id: mss_get_cen_ecid.H,v 1.4 2012/12/07 19:12:05 lapietra Exp $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : mss_get_cen_ecid.H
// *! DESCRIPTION : Get ECID string from target using SCOM's
// *!
// *! OWNER NAME  : Mark Bellows Email: bellows@us.ibm.com
// *! Copied From : Joe McGill's proc_cleanup code 
// *!
// *! ADDITIONAL COMMENTS:
// *!
// *!
//------------------------------------------------------------------------------

#ifndef _MSS_GET_CEN_ECID_H_
#define _MSS_GET_CEN_ECID_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "cen_scom_addresses.H"

//defines enumerators
enum mss_get_cen_ecid_ddr_status
{
   MSS_GET_CEN_ECID_DDR_STATUS_ALL_GOOD = 0,
   MSS_GET_CEN_ECID_DDR_STATUS_MBA1_BAD = 1,
   MSS_GET_CEN_ECID_DDR_STATUS_MBA0_BAD = 2,
   MSS_GET_CEN_ECID_DDR_STATUS_ALL_BAD = 3,
};

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*mss_get_cen_ecid_FP_t)(const fapi::Target& i_target, uint8_t & ddr_port_status);


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

// function: FAPI mss_get_cen_ecid HWP entry point
// parameters: i_target => cen chip target
//             &ddr_port_status => indicates if the MBA's are bad, with MBA 1 being the rightmost bit and MBA 0 being the next to right most bit
// returns: FAPI_RC_SUCCESS if FBC stop is deasserted at end of execution
//          else FAPI getscom/putscom return code for failing operation
// Updates attributes: ATTR_MSS_ECID[2] -> bits 1-64 and 65-128 of the ECID
//                     ATTR_MSS_CACHE_ENABLE -> Stores which parts of the eDRAM are enabled
fapi::ReturnCode mss_get_cen_ecid(
    const fapi::Target& i_target,
    uint8_t & ddr_port_status
    );

} // extern "C"

#endif // _MSS_GET_CEN_ECID_H_
