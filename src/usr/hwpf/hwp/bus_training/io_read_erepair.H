/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_read_erepair.H $             */
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
// $Id: io_read_erepair.H,v 1.4 2013/02/05 06:06:06 varkeykv Exp $
#ifndef IO_READ_EREPAIR_H_
#define IO_READ_EREPAIR_H_

#include <fapi.H>

/**
 * @brief IO read e repair function
 * the  rx vectors will return to the caller(PRD or e-repair)the bad lane numbers on this endpoint 
 */
typedef fapi::ReturnCode (*io_read_erepair_FP_t)(const fapi::Target &target,std::vector<uint8_t> &rx_lanes);

extern "C"
{

/**
 * @brief IO read erepair function 
 *
 * @param[in] target could P8 MCS ,Centaur ( MEMBUF )  , p8 XBUS or p8 ABUS
 *
 * rx lanes will return bad lane data to the caller on this particular bus/endpoint
 * e-repair will duplicate this to TX vpd records as well on the other connected side 
 * 
 *
 * @return ReturnCode
 */

fapi::ReturnCode io_read_erepair(const fapi::Target &target,std::vector<uint8_t> &rx_lanes);

} // extern "C"

#endif // IO_READ_EREPAIR_H_
