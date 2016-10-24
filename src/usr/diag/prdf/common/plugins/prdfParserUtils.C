/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfParserUtils.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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

#include <prdfParserUtils.H>
#include <prdfMemConst.H>

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

template<>
uint8_t symbol2Dq<TARGETING::TYPE_MBA>( uint8_t i_symbol )
{
    uint8_t dq = DQS_PER_DIMM;

    if ( SYMBOLS_PER_RANK > i_symbol )
    {
        if ( 8 > i_symbol )
            dq = ( ((3 - (i_symbol % 4)) * 2) + 64 );
        else
            dq = ( (31 - (((i_symbol - 8) % 32))) * 2 );
    }

    return dq;
}

//------------------------------------------------------------------------------

template<>
uint8_t symbol2Dq<TARGETING::TYPE_MCA>( uint8_t i_symbol )
{
    uint8_t dq = DQS_PER_DIMM;

    static const uint8_t symbol2dq[] =
    {
        71, 70, 69, 68, 67, 66, 65, 64, // symbols  0- 7
        63, 62, 61, 60, 55, 54, 53, 52, // symbols  8-15
        47, 46, 45, 44, 39, 38, 37, 36, // symbols 16-23
        31, 30, 29, 28, 23, 22, 21, 20, // symbols 24-31
        15, 14, 13, 12,  7,  6,  5,  4, // symbols 32-39
        59, 58, 57, 56, 51, 50, 49, 48, // symbols 40-47
        43, 42, 41, 40, 35, 34, 33, 32, // symbols 48-55
        27, 26, 25, 24, 19, 18, 17, 16, // symbols 56-63
        11, 10,  9,  8,  3,  2,  1,  0, // symbols 64-71
    };

    if ( SYMBOLS_PER_RANK > i_symbol )
    {
        dq = symbol2dq[i_symbol];
    }

    return dq;
}

//------------------------------------------------------------------------------

uint8_t symbol2PortSlct( uint8_t i_symbol )
{
    uint8_t portSlct = MBA_DIMMS_PER_RANK;

    if ( SYMBOLS_PER_RANK > i_symbol )
    {
        portSlct = ( ((i_symbol <= 3) || ((8 <= i_symbol) && (i_symbol <= 39)))
                     ? 1 : 0 );
    }

    return portSlct;
}

//------------------------------------------------------------------------------
/* TODO: RTC 136126
uint8_t dram2Symbol( uint8_t i_dram, bool i_isX4Dram )
{
    const uint8_t dramsPerRank   = i_isX4Dram ? MBA_NIBBLES_PER_RANK
                                              : MBA_BYTES_PER_RANK;

    const uint8_t symbolsPerDram = i_isX4Dram ? MBA_SYMBOLS_PER_NIBBLE
                                              : MBA_SYMBOLS_PER_BYTE;

    return (dramsPerRank > i_dram) ? (i_dram * symbolsPerDram)
                                   : SYMBOLS_PER_RANK;
}

//------------------------------------------------------------------------------

uint8_t symbol2Dram( uint8_t i_symbol, bool i_isX4Dram )
{
    const uint8_t dramsPerRank   = i_isX4Dram ? MBA_NIBBLES_PER_RANK
                                              : MBA_BYTES_PER_RANK;

    const uint8_t symbolsPerDram = i_isX4Dram ? MBA_SYMBOLS_PER_NIBBLE
                                              : MBA_SYMBOLS_PER_BYTE;

    return (SYMBOLS_PER_RANK > i_symbol) ? (i_symbol / symbolsPerDram)
                                         : dramsPerRank;
}
*/

} // namespace PARSERUTILS

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
} // end namespace HOSTBOOT
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
} // end namespace FSP
#endif

} // End of namespace PRDF
