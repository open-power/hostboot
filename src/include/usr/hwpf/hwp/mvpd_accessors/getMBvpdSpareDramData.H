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
    uint8_t (&)[DIMM_DQ_MAX_MBA_PORTS][DIMM_DQ_MAX_MBAPORT_DIMMS]
                                         [DIMM_DQ_MAX_DIMM_RANKS]);
extern "C"
{

/**
 * @brief FW Team HWP that handles the ATTR_VPD_DIMM_SPARE attribute
 * by querying MBvpd to determine spare DRAM availability for C-DIMMs.
 *
 * This HWP should be called through the VPD_DIMM_SPARE attribute.
 *
 * @param[in]  i_mba       Reference to MBA Target.
 * @param[out] o_data      Reference to spare DRAM data.
 *
 * @return ReturnCode
 */
fapi::ReturnCode getMBvpdSpareDramData(
    const fapi::Target & i_mba,
    uint8_t (&o_data)[DIMM_DQ_MAX_MBA_PORTS][DIMM_DQ_MAX_MBAPORT_DIMMS]
                                               [DIMM_DQ_MAX_DIMM_RANKS]);
}

#endif
