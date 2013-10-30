/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdVersion.H $ */
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
// $Id: getMBvpdVersion.H,v 1.1 2013/10/30 21:04:08 whs Exp $
/**
 *  @file getMBvpdVersion.H
 *
 *  @brief MBVPD Accessor for providing the ATTR_VPD_VERSION attribute
 */

#ifndef _HWP_GETMBVPDVERSION_
#define _HWP_GETMBVPDVERSION_

#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdVersion_FP_t)
    (const fapi::Target &, uint32_t &);

extern "C"
{
/**
 * @brief Get the ATTR_VPD_VERSION FAPI attribute
 *
 * Return the VPD version from MBvpd record VINI keyword VZ.
 *
 * The ATTR_VPD_VERSION attribute is associated with a DIMM. The platfrom must
 * get the associated MBA chip to be passed to this hwp accessor.
 *
 * @param[in]  i_mbaTarget - Reference to mba Target
 * @param[out] o_val      - Filled in with vpd version
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode getMBvpdVersion(
    const fapi::Target & i_mbaTarget,
    uint32_t & o_val);
}

#endif
