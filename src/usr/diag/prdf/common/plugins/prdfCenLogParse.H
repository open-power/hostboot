/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfCenLogParse.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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

/** @file  prdfCenLogParse.H
 *  @brief Error log parsing code specific to the memory subsystem.
 */

#ifndef __prdfCenLogParse_H
#define __prdfCenLogParse_H

#include <stdint.h>
#include <prdfMemoryMruData.H>

class ErrlUsrParser;

namespace PRDF
{
#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
#else
namespace FSP
#endif
{

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
 */
void parseMemMruData( ErrlUsrParser & i_parser,
                      const MemoryMruData::ExtendedData & i_extMemMru );

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
 * @brief Parses Memory RCE table.
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 */
bool parseMemRceTable( uint8_t * i_buffer, uint32_t i_buflen,
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
 */
bool parseDramRepairsVpd( uint8_t * i_buffer, uint32_t i_buflen,
                          ErrlUsrParser & i_parser );

/**
 * @brief Parses Bad DQ Bitmap data (Used in IPL UE isolation).
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 */
bool parseBadDqBitmap( uint8_t * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser );

/**
 * @brief Parses TD Controller state data.
 * @param i_buffer The data buffer.
 * @param i_buflen The buffer length.
 * @param i_parser The error log parser.
 * @param i_sigId  The signature ID.
 */
bool parseTdCtlrStateData( uint8_t * i_buffer, uint32_t i_buflen,
                           ErrlUsrParser & i_parser, uint32_t i_sigId );

} // namespace FSP/HOSTBBOT
} // end namespace PRDF

#endif // __prdfCenLogParse_H

