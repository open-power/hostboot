/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemIplCeStats.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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

#ifndef PRDF_MEM_IPL_CE_STATS_H
#define PRDF_MEM_IPL_CE_STATS_H

/** @file  prdfMemIplCeStats.H */

//------------------------------------------------------------------------------
#include <prdfExtensibleChip.H>
#include <prdfMemAddress.H>
#include <prdfMemSymbol.H>
#include <map>

namespace PRDF
{
class ExtensibleChip;
class MemoryMru;
//------------------------------------------------------------------------------

/**
 * This class is used for storing the CE statistics that are gathered during a
 * manufacturing mode IPL for MDIA analysis. Only one instance of this object is
 * meant to be used for each MBA/MCA and is stored in its data bundle.
 * It is expected that when the IPL memory diagnostics is complete, MDIA will
 * call the appropriate function to tell this object to analyze all statistics
 * that were collected during the IPL.
 */
template<TARGETING::TYPE T>
class MemIplCeStats
{
  public:

    /**
     * @brief Constructor
     * @param i_chip The MBA or MCA chip.
     */
    explicit MemIplCeStats( ExtensibleChip * i_chip ): iv_chip(i_chip) {}

    /**
     * @brief Destructor
     */
    ~MemIplCeStats() {}

    /**
     * @brief Bans analysis of the given DIMM select.
     * @param i_dimmSlct The DIMM select.
     */
    void banAnalysis( uint8_t i_dimmSlct );

    /**
     * @brief Bans analysis of the given DIMM select and port select.
     * @param i_dimmSlct The DIMM select.
     * @param i_portSlct The port select.
     */
    void banAnalysis( uint8_t i_dimmSlct, uint8_t i_portSlct );

    /**
     * @brief  Will collect all the maintenance statistics and store them for
     *         analysis. Will also clear the scrub statistics counters when
     *         collection is complete.
     * @param  i_rank The rank the maintenance command stopped on.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t collectStats( const MemRank & i_rank );

    /**
     * @brief  Analyzes the maintenance statistics that were gathered, making
     *         the appropriate callouts.
     * @return TRUE if PRD made a hardware callout, FALSE otherwise.
     */
    bool analyzeStats();

    /** @brief  Calls out all symbols with hard CEs.
     *  @param  i_stopRank The rank the maintenance command stopped on.
     */
    int32_t calloutHardCes( const MemRank & i_stopRank );

  private: // enums, structs, typedefs

    /** @brief The key type for each entry in iv_symMap. */
    struct SymbolKey
    {
        MemSymbol symbol; ///< The failing symbol

        /** @brief Overrides the '==' operator. */
        bool operator==( const SymbolKey & i ) const
        { return ( symbol == i.symbol ); }

        /** @brief Overrides the '<' operator. */
        bool operator<( const SymbolKey & i ) const
        { return  (symbol < i.symbol ); }
    };

    /** @brief The key to identify half rank.
     *   This key will be used to ban analysis, rank and dimm
     *   threshold analysis
     */
    struct HalfRankKey
    {
        MemRank rank;     ///< The rank
        uint8_t portSlct; ///< The port select

        /** @brief Overrides the '==' operator. */
        bool operator==( const HalfRankKey & i ) const
        { return ( (rank == i.rank) && (portSlct == i.portSlct) ); }

        /** @brief Overrides the '<' operator. */
        bool operator<( const HalfRankKey & i ) const
        {
            return ( (rank < i.rank) ||
                 ((rank == i.rank) && (portSlct < i.portSlct)) );
        }
    };

    /** @brief The key to identify a DIMM. This key will be used to ban analysis
     *         on a DIMM after a DIMM has been called out. */
    struct DimmKey
    {
        uint8_t dimmSlct; ///< The DIMM select
        uint8_t portSlct; ///< The port select

        /** @brief Overrides the '==' operator. */
        bool operator==( const DimmKey & i ) const
        { return ( (dimmSlct == i.dimmSlct) && (portSlct == i.portSlct) ); }

        /** @brief Overrides the '<' operator. */
        bool operator<( const DimmKey & i ) const
        {
            return (  (dimmSlct <  i.dimmSlct) ||
                     ((dimmSlct == i.dimmSlct) && (portSlct < i.portSlct)) );
        }
    };

    /** @brief The key type for each entry in iv_dramMap. */
    struct DramKey
    {
        MemRank rank;     ///< The rank
        uint8_t dram;     ///< The DRAM (x8:0-17 x4:0-35)
        uint8_t portSlct; ///< The port select (0-1)

        // Techinally, the port select can be derived from the DRAM value,
        // however, it simplifies things to just store the port select here.
        // Therefore, the port select does not need to be used in operator==()
        // or operators<().

        /** @brief Overrides the '==' operator. */
        bool operator==( const DramKey & i ) const
        { return ( (rank == i.rank) && (dram == i.dram) ); }

        /** @brief Overrides the '<' operator. */
        bool operator<( const DramKey & i ) const
        { return ( (rank < i.rank) || ((rank == i.rank) && (dram < i.dram)) ); }
    };

    // data type to collect all symbol statistics
    typedef std::vector<SymbolKey> CESymbols;

    // data type to collect dimm specific statitics. While
    // filling up data for this data type, we should ignore rank select
    // and only consider dimm slct.
    typedef std::map<HalfRankKey, uint32_t>  CePerHalfDsMap;
    // data type to collect all symbol statistics for a rank.
    typedef std::map<HalfRankKey, uint32_t>  CePerHalfRankMap;
    // data type to store banned DIMMs on which analysis is not required.
    typedef std::map<DimmKey,     bool>      BannedAnalysisMap;
    // data type to collect all symbol statistics for a dram.
    typedef std::map<DramKey,     uint32_t>  CePerDramMap;

  private: // functions

    /** @brief  Calls out all symbols on a dram that has exceeded threshold.
     *  @return TRUE if a callout was made, FALSE othewise.
     */
    bool calloutCePerDram();

    /** @brief  Calls out all symbols on a rank that has exceeded threshold.
     *  @return TRUE if a callout was made, FALSE othewise.
     */
    bool calloutCePerRank();

    /** @brief  Calls out all symbols on a dimm select that has exceeded
     *          threshold.
     *  @return TRUE if a callout was made, FALSE othewise.
     */
    bool calloutCePerDs();

    /**
     * @brief Add MemoryMru callout to error log and commit it.
     * @param i_memmru Memory MRU.
     * @param i_errl   Error log.
     */
    void addMruAndCommitErrl( const MemoryMru & i_memmru, errlHndl_t i_errl );

  private: // instance variables

    /** The MBA or MCA chip. */
    ExtensibleChip * iv_chip;

    /** A map to keep track of which half ranks have all ready been called out.
     *  This helps reduce excessive callouts for the same hardware. */
    BannedAnalysisMap iv_bannedAnalysis;

    /** A vector containing all data for every failing symbol. */
    CESymbols iv_ceSymbols;

    /** A map containing count for every failing dimm select. */
    CePerHalfDsMap iv_dsMap;

    /** A map containing count for every failing rank. */
    CePerHalfRankMap iv_rankMap;

    /** A map containing count for every failing DRAM. */
    CePerDramMap iv_dramMap;
};

} //end namespace PRDF
#endif /* PRDF_MEM_IPL_CE_STATS_H */
