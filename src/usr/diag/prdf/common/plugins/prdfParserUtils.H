/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfParserUtils.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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

#ifndef PRDFPARSERUTILS_H
#define PRDFPARSERUTILS_H

/**
 * @file  prdfParserUtils.H
 * @brief Utility functions common across Log Parser and plat code.
 */

#include <stdint.h>
#include <prdfMemConst.H>
#include <attributeenums.H> // For TARGETING::TYPE

namespace PRDF
{

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN)
namespace HOSTBOOT
{
#elif defined(PRDF_FSP_ERRL_PLUGIN)
namespace FSP
{
#endif

namespace PARSERUTILS
{

/**
 * Depending on system configuration, a symbol may have more than one DQ. The DQ
 * numbering within a symbol will always be contiguous. Therefore, the first DQ
 * within the symbol will be returned. The user will need to calculate the other
 * DQ values if needed.
 *
 * @param  i_symbol Target symbol.
 * @return The first DQ of the given symbol.
 */
template<TARGETING::TYPE T>
uint8_t symbol2Dq( uint8_t i_symbol );

/**
 * @brief Find the port select for given symbol
 * @param i_symbol The Symbol
 * @return The Port Select
 */
template<TARGETING::TYPE T>
uint8_t symbol2PortSlct( uint8_t i_symbol );

/**
 * @brief Find the symbol for the given DQ
 * @param i_dq The chip DQ
 * @param i_ps The port select. Default is 0. Only needed for MBA.
 * @return The Symbol
 */
template<TARGETING::TYPE T>
uint8_t dq2Symbol( uint8_t i_dq, uint8_t i_ps = 0 );

/**
 * @brief Find the first symbol of the given x4 DRAM index
 * @param i_x4Dram     The x4 Dram index
 * @return The Symbol
 */
template<TARGETING::TYPE T>
uint8_t nibble2Symbol( uint8_t i_x4Dram );

/**
 * @brief Find the first symbol of the given x8 DRAM index
 * @param i_x8Dram     The x8 Dram index
 * @return The Symbol
 */
template<TARGETING::TYPE T>
uint8_t byte2Symbol( uint8_t i_x8Dram );

/**
 * @brief Find the x4 DRAM index for the given symbol
 * @param i_symbol The symbol
 * @return The Symbol
 */
template<TARGETING::TYPE T>
uint8_t symbol2Nibble( uint8_t i_symbol );

/**
 * @brief Find the x8 DRAM index for the given symbol
 * @param i_symbol The symbol
 * @return The Symbol
 */
template<TARGETING::TYPE T>
uint8_t symbol2Byte( uint8_t i_symbol );

/**
 * @brief Find the first symbol of the given DRAM index
 * @param i_dram     The Dram
 * @param i_isX4Dram TRUE if DRAM is x4
 * @return The Symbol
 */
template<TARGETING::TYPE T>
uint8_t dram2Symbol( uint8_t i_dram, bool i_isX4Dram );

/**
 * @brief Find the dram index of a given symbol
 * @param i_dram     The Dram
 * @param i_isX4Dram TRUE if DRAM is x4
 * @return The Symbol
 */
template<TARGETING::TYPE T>
uint8_t symbol2Dram( uint8_t i_symbol, bool i_isX4Dram );

} // namespace PARSERUTILS

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif

} // End of namespace PRDF
#endif
