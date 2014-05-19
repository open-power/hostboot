/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_power_down_lanes.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
