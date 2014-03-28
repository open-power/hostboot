/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfParserUtils.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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

#ifndef PRDFPARSERUTILS_H
#define PRDFPARSERUTILS_H

/**
 * @file  prdfParserUtils.H
 * @brief Utility functions common across Log Parser and plat code.
 */

#include <stdint.h>

namespace PRDF
{

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
{
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
namespace FSP
{
#endif

namespace PARSERUTILS
{

/**
 * @brief Find the even Centaur DQ of the given symbol
 * @param i_symbol The symbol
 * @return The Centaur DQ
 */
uint8_t symbol2CenDq( uint8_t i_symbol );

/**
 * @brief Find the port select for given symbol
 * @param i_symbol The Symbol
 * @return The Port Select
 */
uint8_t symbol2PortSlct( uint8_t i_symbol );

/**
 * @brief Find the first symbol of the given DRAM index
 * @param i_dram     The Dram
 * @param i_isX4Dram TRUE if DRAM is x4
 * @return The Symbol
 */
uint8_t dram2Symbol( uint8_t i_dram, bool i_isX4Dram );

/**
 * @brief Find the symbol of the given Centaur DQ and port select
 * @param i_CenDq The Centaur DQ
 * @param i_ps    The Port Select
 * @return The Symbol
 */
uint8_t cenDq2Symbol( uint8_t i_CenDq, uint8_t i_ps );

/**
 * @brief Find the DRAM index for the given symbol
 * @param i_symbol The symbol
 * @param i_isX4Dram TRUE if DRAM is x4
 * @return The Symbol
 */
uint8_t symbol2Dram( uint8_t i_symbol, bool i_isX4Dram );

} // namespace PARSERUTILS

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
} // end namespace HOSTBOOT
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
} // end namespace FSP
#endif

} // End of namespace PRDF
#endif
