/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfMemLogParse.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

/** @file  prdfMemLogParse.H
 *  @brief Error log parsing code specific to the memory subsystem.
 */

#ifndef __prdfMemLogParse_H
#define __prdfMemLogParse_H

#include <stdint.h>
#include <prdfMemoryMruData.H>
#include <attributeenums.H> // For TARGETING::TYPE enum
#include <errlusrparser.H>  // For errlver_t

class ErrlUsrParser;

namespace PRDF
{
#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN)
namespace HOSTBOOT
{
#elif defined(PRDF_FSP_ERRL_PLUGIN)
namespace FSP
{
#endif

/**
 * @brief Parses MemoryMru data.
 * @note  Since this will be used in several different sections, this function
 *        simply parses the data. It does not print header information (i.e.
 *        "MemoryMru") or print out the uint32_t value of the MemoryMru. It is
 *        up to the caller to add that data.
 * @param i_parser The error log parser.
 * @param i_memMru A MemoryMru.
 */
void parseMemMruData( ErrlUsrParser & i_parser, uint32_t i_memMru );

/**
 * @brief Parses extended MemoryMru data.
 * @note  Since this will be used in several different sections, this function
 *        simply parses the data. It does not print header information (i.e.
 *        "MemoryMru") or print out the uint32_t value of the MemoryMru. It is
 *        up to the caller to add that data.
 * @param i_parser    The error log parser.
 * @param i_extMemMru A MemoryMru with extended data for extra FFDC.
 * @param i_ver This error log section's version
 */
void parseMemMruData( ErrlUsrParser & i_parser,
                      const MemoryMruData::ExtendedData & i_extMemMru,
                      errlver_t i_ver );

/**
 * @brief Parses Memory UE table.
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 */
bool parseMemUeTable( uint8_t * i_buffer, uint32_t i_buflen,
                      ErrlUsrParser & i_parser );

/**
 * @brief Parses Memory CE table.
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 */
bool parseMemCeTable( uint8_t * i_buffer, uint32_t i_buflen,
                      ErrlUsrParser & i_parser );

/**
 * @brief Parses IUE threshold counts.
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 */
bool parseIueCounts( uint8_t * i_buffer, uint32_t i_buflen,
                     ErrlUsrParser & i_parser );

/**
 * @brief Parses DRAM Repairs data (actual chip/symbol marks and DRAM repairs in
 *        hardware).
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 */
bool parseDramRepairsData( uint8_t * i_buffer, uint32_t i_buflen,
                           ErrlUsrParser & i_parser );

/**
 * @brief Parses DRAM Repairs VPD (data in bad DQ bitmap attributes).
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 * @param i_type   The target type
 */
bool parseDramRepairsVpd( uint8_t * i_buffer, uint32_t i_buflen,
                          ErrlUsrParser & i_parser, TARGETING::TYPE i_type );

/**
 * @brief Parses Row Repair VPD (data in Row Repair Data attributes).
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 */
bool parseRowRepairVpd( uint8_t * i_buffer, uint32_t i_buflen,
                        ErrlUsrParser & i_parser );

/**
 * @brief Parses Bad DQ Bitmap data (Used in IPL UE isolation).
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 * @param i_type   The target type
 */
bool parseBadDqBitmap( uint8_t * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser, TARGETING::TYPE i_type );

/**
 * @brief Parses TD Controller state data.
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 * @param i_sigId  The signature ID.
 */
bool parseTdCtlrStateData( uint8_t * i_buffer, uint32_t i_buflen,
                           ErrlUsrParser & i_parser, uint32_t i_sigId );

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif
} // end namespace PRDF

#endif // __prdfMemLogParse_H

