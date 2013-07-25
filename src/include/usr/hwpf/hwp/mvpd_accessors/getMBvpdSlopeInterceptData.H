/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdSlopeInterceptData.H $ */
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
// $Id: getMBvpdSlopeInterceptData.H,v 1.1 2013/07/18 15:35:01 whs Exp $

/**
 *  @file getMBvpdSlopeInterceptData.H
 *
 *  @brief Prototype for getMBvpdSlopeInterceptData() -
 *          get master and supplier power slope and intercept from MBvpd
 */

#ifndef    _HWP_MBVPDSLOPEINTERCEPTDATA_
#define    _HWP_MBVPDSLOPEINTERCEPTDATA_

#include   <fapi.H>

namespace fapi
{

    enum MBvpdSlopeIntercept
    {
       MASTER_POWER_SLOPE =                0x00,
       MASTER_POWER_INTERCEPT =            0x01,
       SUPPLIER_POWER_SLOPE =              0x02,
       SUPPLIER_POWER_INTERCEPT =          0x03,
    };
}

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdSlopeInterceptData_FP_t)
     (const fapi::Target &, const fapi::MBvpdSlopeIntercept,  uint32_t &);

extern "C"
{
/**
 * @brief Return power slope and intercept data from cvpd record VSPD
 *        keyword MW and MV
 *
 * The Master power slope and intercept data is in the MW keyword.
 * The Supplier power slope and intercept data is in the MV keyword.
 * The #I keyword has the Module ID for this CDIMM. The MV keyword
 *  has the supplier power slope and intercept for multiple vendors.
 *  The list in MV is searched for the Module ID in the #I keyword.
 *  Values for the matching vendor are returned.
 *
 * @param[in]  i_mbTarget   -   membuf chip target
 * @param[in]  i_attr       -   enumerator to select requested value
 * @param[out] o_val        -   master/supplier slope/intercept value
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getMBvpdSlopeInterceptData(
                              const fapi::Target &i_mbTarget,
                              const fapi::MBvpdSlopeIntercept i_attr,
                              uint32_t &o_val);

}

#endif
