/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfParserUtils.C $          */
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

#include <prdfParserUtils.H>
#include <prdfCenConst.H>

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

uint8_t symbol2CenDq( uint8_t i_symbol )
{
    uint8_t cenDq = DQS_PER_DIMM;

    if ( SYMBOLS_PER_RANK > i_symbol )
    {
        if ( 8 > i_symbol )
            cenDq = ( ((3 - (i_symbol % 4)) * 2) + 64 );
        else
            cenDq = ( (31 - (((i_symbol - 8) % 32))) * 2 );
    }

    return cenDq;
}

//------------------------------------------------------------------------------

uint8_t symbol2PortSlct( uint8_t i_symbol )
{
    uint8_t portSlct = PORT_SLCT_PER_MBA;

    if ( SYMBOLS_PER_RANK > i_symbol )
    {
        portSlct = ( ((i_symbol <= 3) || ((8 <= i_symbol) && (i_symbol <= 39)))
                     ? 1 : 0 );
    }

    return portSlct;
}

//------------------------------------------------------------------------------

uint8_t dram2Symbol( uint8_t i_dram, bool i_isX4Dram )
{
    const uint8_t dramsPerRank   = i_isX4Dram ? X4DRAMS_PER_RANK
                                              : X8DRAMS_PER_RANK;

    const uint8_t symbolsPerDram = i_isX4Dram ? SYMBOLS_PER_X4DRAM
                                              : SYMBOLS_PER_X8DRAM;

    return (dramsPerRank > i_dram) ? (i_dram * symbolsPerDram)
                                   : SYMBOLS_PER_RANK;
}

//------------------------------------------------------------------------------

uint8_t cenDq2Symbol( uint8_t i_cenDq, uint8_t i_ps )
{
    uint8_t sym = SYMBOLS_PER_RANK;

    if ( DQS_PER_DIMM > i_cenDq && PORT_SLCT_PER_MBA > i_ps )
    {
        if ( i_cenDq >= 64 )
            sym = ( (3 - ((i_cenDq - 64) / 2)) + ((0 == i_ps) ? 4 : 0) );
        else
            sym = ( ((63 - i_cenDq) / 2) + ((0 == i_ps) ? 32 : 0) + 8 );
    }

    return sym;
}

//------------------------------------------------------------------------------

uint8_t symbol2Dram( uint8_t i_symbol, bool i_isX4Dram )
{
    const uint8_t dramsPerRank   = i_isX4Dram ? X4DRAMS_PER_RANK
                                              : X8DRAMS_PER_RANK;

    const uint8_t symbolsPerDram = i_isX4Dram ? SYMBOLS_PER_X4DRAM
                                              : SYMBOLS_PER_X8DRAM;

    return (SYMBOLS_PER_RANK > i_symbol) ? (i_symbol / symbolsPerDram)
                                         : dramsPerRank;
}

} // namespace PARSERUTILS

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
} // end namespace HOSTBOOT
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
} // end namespace FSP
#endif

} // End of namespace PRDF
