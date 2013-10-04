/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfCenLogParse.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
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

/** @file  prdfCenLogParse.H
 *  @brief Error log parsing code specific to the memory subsystem.
 */

#ifndef __prdfCenLogParse_H
#define __prdfCenLogParse_H

#include <stdint.h>

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
 * @param i_memMru The MemoryMru data.
 */
bool parseMemMruData( ErrlUsrParser & i_parser, uint32_t i_memMru );

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

} // namespace FSP/HOSTBBOT
} // end namespace PRDF

#endif // __prdfCenLogParse_H

