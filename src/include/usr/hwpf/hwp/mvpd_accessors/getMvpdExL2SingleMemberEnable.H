/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMvpdExL2SingleMemberEnable.H $ */
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
// $Id: getMvpdExL2SingleMemberEnable.H,v 1.1 2013/04/10 22:02:29 mjjones Exp $
/**
 *  @file getMvpdExL2SingleMemberEnable.H
 *
 *  @brief MVPD Accessor for providing the ATTR_EX_L2_SINGLE_MEMBER_ENABLE
 *         attribute
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/10/2013  Created.
 */

#ifndef _HWP_GETMVPDEXL2SINGLEMEMBERENABLE_
#define _HWP_GETMVPDEXL2SINGLEMEMBERENABLE_

#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMvpdExL2SingleMemberEnable_FP_t)
    (const fapi::Target &, uint32_t &);

extern "C"
{
/**
 * @brief Get the ATTR_EX_L2_SINGLE_MEMBER_ENABLE FAPI attribute
 *
 * This data in MVPD indicates which EX chiplets must be configured with the L2
 * cache in single member mode. The data is used by the p8_xip_customize HWP. It
 * is used by the FSP platform to build the IPL image, and the Hostboot platform
 * to build the SLW image. The data is a bit-field.
 *
 * @param[in]  i_procTarget - Reference to Processor Chip FAPI Target
 * @param[out] o_val        - Filled in with attribute value
 *                            0x00008000 - EX00 single member enable
 *                            0x00004000 - EX01 single member enable
 *                            <snip>
 *                            0x00000002 - EX14 single member enable
 *                            0x00000001 - EX15 single member enable
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode getMvpdExL2SingleMemberEnable(
    const fapi::Target & i_procTarget,
    uint32_t & o_val);
}

#endif
