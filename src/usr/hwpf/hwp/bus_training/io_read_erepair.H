/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/io_read_erepair/io_read_erepair.H $          */
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
