/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/io_restore_erepair/io_restore_erepair.H $    */
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
// $Id: io_restore_erepair.H,v 1.8 2012/12/10 17:30:46 varkeykv Exp $
#ifndef IO_RESTORE_EREPAIR_H_
#define IO_RESTORE_EREPAIR_H_

#include <fapi.H>

/**
 * @brief IO restore e repair function
 * In Cronus the tx_lanes and rx_lanes vectors should be passed empty so we will use the accessor provided data instead 
 * This is due to a MFG FW requirement that needed to pass in bad lanes as args instead of via VPD
 * Note that power down of lanes is done by a seperate HWP called io_power_down_lanes
 * Its up to the caller to call that separately to power down a lane if required
 *
 */
typedef fapi::ReturnCode (*io_restore_erepair_FP_t)(const fapi::Target &target,std::vector<uint8_t> &tx_lanes,std::vector<uint8_t> &rx_lanes);

extern "C"
{

/**
 * @brief IO restore erepair function 
 *
 * @param[in] target could P8 MCS ,Centaur ( MEMBUF )  , p8 XBUS or p8 ABUS
 *
 * rx lanes and tx lanes should be passed in by the caller based on VPD data for bad lanes on this target endpoint.
 * Invalidation and other checks should be done prior to passing in these parms
 *
 * @return ReturnCode
 */

fapi::ReturnCode io_restore_erepair(const fapi::Target &target,std::vector<uint8_t> &tx_lanes,std::vector<uint8_t> &rx_lanes);

} // extern "C"

#endif // IO_RESTORE_EREPAIR_H_
