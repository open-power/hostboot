/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaIplCeStats.H $       */
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

#ifndef PRDF_CEN_MBA_IPL_CE_STATS_H
#define PRDF_CEN_MBA_IPL_CE_STATS_H

/** @file  prdfCenMbaIplCeStats.H */

//------------------------------------------------------------------------------
#include <prdfExtensibleChip.H>
#include <prdfCenAddress.H>
#include <prdfCenSymbol.H>
#include <prdfCenAddress.H>
#include <map>

namespace PRDF
{
class ExtensibleChip;
class MemoryMru;
//------------------------------------------------------------------------------

/**
 * This class is used for storing the CE statistics that are gathered during a
 * manufacturing mode IPL for MDIA analysis. Only one instance of this object is
 * meant to be used for each MBA and is stored in its data bundle.
 * It is expected that when the IPL memory diagnostics is complete, MDIA will
 * call the appropriate function to tell this object to analyze all statistics
 * that were collected during the IPL.
 */
class CenMbaIplCeStats
{
  public:

    /**
     * @brief Constructor
     * @param i_mbaChip The MBA chip.
     */
    explicit CenMbaIplCeStats( ExtensibleChip * i_mbaChip )
            :iv_mbaChip(i_mbaChip) {}

    /**
     * @brief Destructor
     */
    ~CenMbaIplCeStats() {}

    /**
     * @brief Bans analysis of the given rank.
     * @param i_rank The rank to ban.
     */
    void banAnalysis( const CenRank & i_rank );

    /**
     * @brief  Bans analysis of the given half rank.
     * @param  i_rank        The rank.
     * @param  i_portSlct The port select.
     * @return Non-SUCCESS if the parameters are invalid, SUCCESS otherwise.
     */
    int32_t banAnalysis( const CenRank & i_rank, uint8_t i_portSlct );

    /**
     * @brief  Will collect all the maintenance statistics and store them for
     *         analysis. Will also clear the scrub statistics counters when
     *         collection is complete.
     * @param  i_rank The rank the maintenance command stopped on.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t collectStats( const CenRank & i_rank );

    /**
     * @brief  Analyzes the maintenance statistics that were gathered, making
     *         the appropriate callouts.
     * @param  o_callOutsDone TRUE if PRD made a hardware callout, FALSE
     *         otherwise.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t analyzeStats ( bool & o_callOutsDone );

    /** @brief  Calls out all symbols with hard CEs.
     *  @param  i_stopRank The rank the maintenance command stopped on.
     */
    int32_t calloutHardCes( const CenRank & i_stopRank );

  private: // enums, structs, typedefs

    /** @brief The key type for each entry in iv_symMap. */
    struct SymbolKey
    {
        CenSymbol symbol; ///< The failing symbol

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
        CenRank rank;   ///< The rank
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

    /** @brief The key type for each entry in iv_dramMap. */
    struct DramKey
    {
        CenRank rank;     ///< The rank
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
    typedef std::map<HalfRankKey,   uint32_t>  CePerHalfDsMap;
    // data type to collect all symbol statistics for a rank.
    typedef std::map<HalfRankKey, uint32_t>  CePerHalfRankMap;
    // data type to store banned half ranks on which analysis is not required.
    typedef std::map<HalfRankKey, bool> BannedAnalysisMap;
    // data type to collect all symbol statistics for a dram.
    typedef std::map<DramKey,     uint32_t>  CePerDramMap;

  private: // functions

    /** @brief  Calls out all symbols on a dram that has exceeded threshold.
     *  @param  o_callOutsMade TRUE if a callout was made, FALSE othewise.
     *  @return Non-SUCCESS if an internal function fails, SUCCESS othewise.
     */
    int32_t calloutCePerDram( bool & o_callOutsMade );

    /** @brief  Calls out all symbols on a rank that has exceeded threshold.
     *  @param  o_callOutsMade TRUE if a callout was made, FALSE othewise.
     *  @return Non-SUCCESS if an internal function fails, SUCCESS othewise.
     */
    int32_t calloutCePerRank( bool & o_callOutsMade );

    /** @brief  Calls out all symbols on a dimm select that has exceeded
     *          threshold.
     *  @param  o_callOutsMade TRUE if a callout was made, FALSE othewise.
     *  @return Non-SUCCESS if an internal function fails, SUCCESS othewise.
     */
    int32_t calloutCePerDs( bool & o_callOutsMade );

    /**
     * @brief Add MemoryMru callout to error log and commit it.
     * @param i_memmru Memory MRU.
     * @param i_errl   Error log.
     */
    void addMruAndCommitErrl( const MemoryMru & i_memmru, errlHndl_t i_errl );

  private: // instance variables

    /** The MBA chip. */
    ExtensibleChip * iv_mbaChip;

    /** The rank that this object is expecting to collect for. */
    CenRank iv_rankToAnalyze;

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
#endif /* PRDF_CEN_MBA_IPL_CE_STATS_H */
