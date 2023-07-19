/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfParserUtils.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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
#include <prdfParserEnums.H>

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

//------------------------------------------------------------------------------

template<>
uint8_t symbol2Dq<TARGETING::TYPE_OCMB_CHIP>( uint8_t i_symbol,
                                              bool i_isX4Dram )
{
    uint8_t dq = DQS_PER_DIMM;

    static const uint8_t symbol2dq_x4[] =
    {
        39, 38, 37, 36, 35, 34, 33, 32, // symbols  0- 7
        79, 78, 77, 76, 71, 70, 69, 68, // symbols  8-15
        63, 62, 61, 60, 55, 54, 53, 52, // symbols 16-23
        31, 30, 29, 28, 23, 22, 21, 20, // symbols 24-31
        15, 14, 13, 12,  7,  6,  5,  4, // symbols 32-39
        75, 74, 73, 72, 67, 66, 65, 64, // symbols 40-47
        59, 58, 57, 56, 51, 50, 49, 48, // symbols 48-55
        27, 26, 25, 24, 19, 18, 17, 16, // symbols 56-63
        11, 10,  9,  8,  3,  2,  1,  0, // symbols 64-71
    };

    // Note: x8 drams are currently Odyssey only. x8 drams only have 40
    // symbols (2 DQs per symbol), however the symbol indexes used are not
    // 0:39, instead using 0:7 and 40:71, so symbols 8:39 will be unused.
    static const uint8_t un = DQS_PER_DIMM; // unused symbol indexes
    static const uint8_t symbol2dq_x8[] =
    {
        46, 44, 42, 40, 38, 36, 34, 32, // symbols  0- 7
        un, un, un, un, un, un, un, un, // symbols  8-15
        un, un, un, un, un, un, un, un, // symbols 16-23
        un, un, un, un, un, un, un, un, // symbols 24-31
        un, un, un, un, un, un, un, un, // symbols 32-39
        78, 76, 74, 72, 70, 68, 66, 64, // symbols 40-47
        62, 60, 58, 56, 54, 52, 50, 48, // symbols 48-55
        30, 28, 26, 24, 22, 20, 18, 16, // symbols 56-63
        14, 12, 10,  8,  6,  4,  2,  0, // symbols 64-71
    };

    if ( SYMBOLS_PER_RANK > i_symbol )
    {
        // x4 drams
        if (i_isX4Dram)
        {
            dq = symbol2dq_x4[i_symbol];
        }
        // x8 drams
        else
        {
            dq = symbol2dq_x8[i_symbol];
        }
    }

    return dq;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint8_t dq2Symbol( uint8_t i_dq, bool i_isX4Dram )
{
    uint8_t symbol = SYMBOLS_PER_RANK;
    static const uint8_t sp = SYMBOLS_PER_RANK; // Spare symbols

    static const uint8_t dq2symbol_x4[] =
    {
        71, 70, 69, 68, 39, 38, 37, 36, // dqs 0- 7
        67, 66, 65, 64, 35, 34, 33, 32, // dqs 8-15
        63, 62, 61, 60, 31, 30, 29, 28, // dqs 16-23
        59, 58, 57, 56, 27, 26, 25, 24, // dqs 24-31
         7,  6,  5,  4,  3,  2,  1,  0, // dqs 32-39
        sp, sp, sp, sp, sp, sp, sp, sp, // dqs 40-47 - spare
        55, 54, 53, 52, 23, 22, 21, 20, // dqs 48-55
        51, 50, 49, 48, 19, 18, 17, 16, // dqs 56-63
        47, 46, 45, 44, 15, 14, 13, 12, // dqs 64-71
        43, 42, 41, 40, 11, 10,  9,  8, // dqs 72-79
    };

    // For x8 drams, each symbol covers 2 DQs
    static const uint8_t dq2symbol_x8[] =
    {
        71, 70, 69, 68, 67, 66, 65, 64, // dqs 0-15
        63, 62, 61, 60, 59, 58, 57, 56, // dqs 16-31
         7,  6,  5,  4,  3,  2,  1,  0, // dqs 32-47
        55, 54, 53, 52, 51, 50, 49, 48, // dqs 48-63
        47, 46, 45, 44, 43, 42, 41, 40, // dqs 64-79
    };

    if ( DQS_PER_DIMM > i_dq )
    {
        // x4 drams
        if (i_isX4Dram)
        {
            symbol = dq2symbol_x4[i_dq];
        }
        // x8 drams
        else
        {
            // There are 2 DQs per symbol, so divide by 2 here to simplify the
            // conversion table.
            uint8_t tmp = i_dq/2;
            symbol = dq2symbol_x8[tmp];
        }
    }

    return symbol;
}

template
uint8_t dq2Symbol<TARGETING::TYPE_OCMB_CHIP>( uint8_t i_dq, bool i_isX4Dram );
template
uint8_t dq2Symbol<TARGETING::TYPE_MEM_PORT>( uint8_t i_dq, bool i_isX4Dram );

//------------------------------------------------------------------------------

template<>
uint8_t nibble2Symbol<TARGETING::TYPE_OCMB_CHIP>( uint8_t i_x4Dram )
{
    uint8_t symbol = SYMBOLS_PER_RANK;
    static const uint8_t sp = SYMBOLS_PER_RANK; // Spare symbols

    static const uint8_t nibble2symbol[] =
    {
        68, 36, 64, 32, 60, // nibbles 0-4
        28, 56, 24, 52, 20, // nibbles 5-9
        48, 16, 44, 12, 40, // nibbles 10-14
         8,  4,  0, sp, sp, // nibbles 15-19
    };

    if ( NIBBLES_PER_DIMM > i_x4Dram )
    {
        symbol = nibble2symbol[i_x4Dram];
    }

    return symbol;
}

//------------------------------------------------------------------------------

template<>
uint8_t byte2Symbol<TARGETING::TYPE_OCMB_CHIP>( uint8_t i_x8Dram )
{
    uint8_t symbol = SYMBOLS_PER_RANK;

    // Note: x8 drams are currently Odyssey only
    static const uint8_t byte2symbol[] =
    {
        68, 64, 60, 56,  4, // bytes 0-4
         0, 52, 48, 44, 40, // bytes 5-9
    };

    if ( BYTES_PER_DIMM > i_x8Dram )
    {
        symbol = byte2symbol[i_x8Dram];
    }

    return symbol;
}

//------------------------------------------------------------------------------

template<>
uint8_t symbol2Nibble<TARGETING::TYPE_OCMB_CHIP>( uint8_t i_symbol )
{
    uint8_t nibble = NIBBLES_PER_DIMM;

    // There are 4 symbols per nibble, always grouped together, so divide
    // by 4 here to simplify our conversion table.
    uint8_t tmp = i_symbol/4;

    static const uint8_t symbol2nibble[] =
    {
        17, 16, 15, 13, // symbols  0-15
        11,  9,  7,  5, // symbols 16-31
         3,  1, 14, 12, // symbols 32-47
        10,  8,  6,  4, // symbols 48-63
         2,  0,         // symbols 64-71
    };

    if ( SYMBOLS_PER_RANK > i_symbol )
    {
        nibble = symbol2nibble[tmp];
    }

    return nibble;
}

//------------------------------------------------------------------------------

template<>
uint8_t symbol2Byte<TARGETING::TYPE_OCMB_CHIP>( uint8_t i_symbol )
{
    uint8_t byte = MEM_BYTES_PER_RANK;

    // Each symbol covers 2 DQs, so there are 4 symbols per byte grouped
    // together, so divide by 4 here to simplify the conversion table.
    uint8_t tmp = i_symbol/4;

    // Note: x8 drams are currently Odyssey only. x8 drams only have 40
    // symbols (2 DQs per symbol), however the symbol indexes used are not
    // 0:39, instead using 0:7 and 40:71, so symbols 8:39 will be unused.
    static const uint8_t un = MEM_BYTES_PER_RANK; // unused symbol indexes

    static const uint8_t symbol2byte[] =
    {
        5,  4,  un, un, // symbols 0:15
        un, un, un, un, // symbols 16:31
        un, un, 9,  8,  // symbols 32:47
        7,  6,  3,  2,  // symbols 48:63
        1,  0,          // symbols 64:71
    };

    if ( SYMBOLS_PER_RANK > i_symbol )
    {
        byte = symbol2byte[tmp];
    }

    return byte;
}

//------------------------------------------------------------------------------

template<>
uint8_t dram2Symbol<TARGETING::TYPE_OCMB_CHIP>( uint8_t i_dram,
                                                bool i_isX4Dram )
{
    return (true == i_isX4Dram) ?
        nibble2Symbol<TARGETING::TYPE_OCMB_CHIP>(i_dram) :
        byte2Symbol<TARGETING::TYPE_OCMB_CHIP>(i_dram);
}

//------------------------------------------------------------------------------

template<>
uint8_t symbol2Dram<TARGETING::TYPE_OCMB_CHIP>( uint8_t i_symbol,
                                                bool i_isX4Dram )
{
    return (true == i_isX4Dram) ?
        symbol2Nibble<TARGETING::TYPE_OCMB_CHIP>(i_symbol) :
        symbol2Byte<TARGETING::TYPE_OCMB_CHIP>(i_symbol);
}

//------------------------------------------------------------------------------

} // namespace PARSERUTILS

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif

} // End of namespace PRDF
