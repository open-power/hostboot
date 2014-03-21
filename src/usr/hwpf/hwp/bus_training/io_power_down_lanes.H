/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_power_down_lanes.H $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: io_power_down_lanes.H,v 1.5 2014/03/06 11:12:24 varkeykv Exp $
#ifndef IO_POWER_DOWN_LANES_H_
#define IO_POWER_DOWN_LANES_H_


#include <fapi.H> 

/**
 * @brief IO Power down lanes
 * The user needs to pass in Lane numbers that needs to be powered down
 **/
typedef fapi::ReturnCode (*io_power_down_lanes_FP_t)(const fapi::Target &target,const std::vector<uint8_t> &tx_lanes,const std::vector<uint8_t> &rx_lanes);

extern "C"
{

/**
 * @brief IO read erepair function 
 *
 * @param[in] target could P8 MCS ,Centaur ( MEMBUF )  , p8 XBUS or p8 ABUS
 *
 * rx lanes and tx lanes -- user needs to pass in lanes that should be powered down 
 * 
 *
 * @return ReturnCode
 */

fapi::ReturnCode io_power_down_lanes(const fapi::Target &target,const std::vector<uint8_t> &tx_lanes,const std::vector<uint8_t> &rx_lanes);

} // extern "C"

#endif // IO_POWER_DOWN_LANES_H_
