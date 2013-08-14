/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdSpareDramData.H $ */
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
// $Id: getMBvpdSpareDramData.H,v 1.1 2013/08/13 20:35:10 mjjones Exp $
#ifndef GETMBVPDSPAREDRAMDATA_H_
#define GETMBVPDSPAREDRAMDATA_H_

#include <fapi.H>
#include <dimmConsts.H>

typedef fapi::ReturnCode (*getMBvpdSpareDramData_FP_t)(
    const fapi::Target &,
    const fapi::Target &,
    uint8_t &);

extern "C"
{

/**
 * @brief FW Team HWP that, for C-DIMMs, queries MBvpd to determine spare DRAM
 * availability and, for IS-DIMMS, returns NO_SPARE.
 *
 * This HWP should be called through the VPD_DIMM_SPARE attribute.
 *
 * @param[in]  i_mba       Reference to MBA Target associated with the DIMM.
 * @param[in]  i_dimm      Reference to DIMM Target.
 * @param[out] o_data      Reference to spare DRAM data.
 *
 * @return ReturnCode
 */
fapi::ReturnCode getMBvpdSpareDramData(
    const fapi::Target & i_mba,
    const fapi::Target & i_dimm,
    uint8_t &o_data);

}

#endif
