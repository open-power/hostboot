/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdDram2NModeEnabled.H $ */
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
// $Id: getMBvpdDram2NModeEnabled.H,v 1.1 2013/10/30 21:02:44 whs Exp $
/**
 *  @file getMBvpdDram2NModeEnabled.H
 *
 *  @brief MBVPD Accessor for providing the ATTR_VPD_DRAM_2N_MODE_ENABLED
 *    attribute
 */

#ifndef _HWP_GETMBVPDDRAM2NMODEENABLED_
#define _HWP_GETMBVPDDRAM2NMODEENABLED_

#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdDram2NModeEnabled_FP_t)
    (const fapi::Target &, uint8_t &);

extern "C"
{
/**
 * @brief Get the ATTR_DRAM_2N_MODE_ENABLED FAPI attribute
 *
 * Return whether Dram 2N Mode is enabled based on the MR keyword
 *   DRAM_2N_MODE value. The DRAM_2N_Mode values for both ports of the mba
 *   must be equal, otherwise an error is returned.
 *
 * @param[in]  i_mbaTarget - Reference to mba Target
 * @param[out] o_val  - ATTR_VPD_DRAM_2N_MODE_ENABLED enumeration value
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode getMBvpdDram2NModeEnabled(
    const fapi::Target & i_mbaTarget,
    uint8_t & o_val);
}

#endif
