/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaTdRankData_rt.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

#ifndef __prdfCenMbaTdRankData_rt_H
#define __prdfCenMbaTdRankData_rt_H

/** @file prdfCenMbaTdRankData_rt.H */

// Framework includes
#include <prdfPlatServices.H>

// Pegasus includes
#include <prdfCenAddress.H>
#include <prdfThresholdUtils.H>

// Other includes
#include <vector>
#include <algorithm>

namespace PRDF
{

/**
 * @brief A sorted list of all master ranks behind an MBA.
 *
 * The list will be sorted by the order in which hardware will scrub memory.
 * Each time a rank is targeted for diagnostics, the rank should be marked as
 * bad. This is intended to assist in the design in which PRD will do a fast
 * scrub on the next 'good' rank between targeted diagnostics procedures. The
 * hope is that even though we may skip around in memory targeting ranks that
 * are reporting errors, we are still able to continue scrubbing the rest of
 * the good memory at least one every 24 hours.
 *
 * @note  This list is only intended to be used by the runtime TD controller.
 */
class TdRankList
{
  public: // structs, typedefs

    /** @brief Structure to represent a rank list entry. */
    struct Entry
    {
        CenRank rank;   ///< The rank in which this event occurred.
        bool    isGood; ///< False if currently being targeted by diagnotics

        /** @brief Default constructor */
        Entry() : isGood(true) {}

        /** @brief Constructor */
        explicit Entry( const CenRank & i_rank ) :
            rank(i_rank), isGood(true)
        {}
    };

    typedef std::vector<Entry>           List;
    typedef std::vector<Entry>::iterator ListItr;

  public: // functions

    /** @brief Default constructor */
    TdRankList() : iv_list(), iv_curRank(iv_list.end()) {}

    /**
     * @brief  Populates and sorts the list.
     * @param  i_mbaTrgt The target MBA.
     * @note   Should be called in the TD controller's initialize() function.
     * @note   Will fail if unable to find any configured ranks behind the given
     *         MBA. This is to guarantee the list is not empty.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t initialize( TARGETING::TargetHandle_t i_mbaTrgt );

    /**
     * @return A contant reference to the master rank list.
     * @note   This is useful if someone needs to iterate over the list of
     *         ranks.
     */
    const List & getList() const { return iv_list; }

    /**
     * @brief  Will find the next rank in the list that is marked as 'good'.
     *
     * Will start with the entry that iv_curRank is pointing to and increment
     * the iterator until it points to a rank that is marked as good. If the
     * search reaches the end of the list, this function will wrap around to the
     * beginning the list.
     *
     * @note   If the returned entry's isGood field is false, it means all ranks
     *         in the list are set to bad.
     *
     * @return The next 'good' list entry.
     */
    Entry findNextGoodRank();

    /**
     * @brief  Marks the given rank as 'good'.
     * @param  i_rank A rank that has completed Targeted diagnostics.
     * @note   Should be called when all entries for a rank are removed from
     *         the TD queue.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t setGood( const CenRank & i_rank )
    { return setRankStatus( i_rank, true ); }

    /**
     * @brief  Marks the given rank as 'bad'.
     * @param  i_rank A rank that is currently targeted for diagnostics.
     * @note   Should be called when an entry is added to the TD queue.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t setBad( const CenRank & i_rank )
    { return setRankStatus( i_rank, false ); }

    /**
     * @brief  Will initialize iv_curRank so that background  scrubbing (or the
     *         fast rank scrub) can resume on the next good rank after the rank
     *         that was interrupted.
     * @param  i_rank The rank that was interrupted.
     * @note   Should be called when background scrubbing is interrupted by an
     *         error.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t setInterruptedRank( const CenRank & i_rank );

  private: // functions

    /**
     * @brief  Sets a rank's status to good or bad depending on inputs.
     * @param  i_rank   The target rank.
     * @param  i_isGood True to set good, false to set bad.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t setRankStatus( const CenRank & i_rank, bool i_isGood );

    /**
     * @param i_rank The target rank.
     * @return An iterator pointing the rank in the list. Will return
     *         iv_list.end() if the rank is not found.
     */
    ListItr findRank( const CenRank & i_rank )
    { return std::find_if(iv_list.begin(), iv_list.end(), MatchRank(i_rank)); }

  private: // instance variables

    List    iv_list;    ///< The master list
    ListItr iv_curRank; ///< Will point to the next rank that is considered good

  private: // functors

    /**
     * @brief Functor to find a rank in this list.
     * @note  This functor will only match master rank.
     */
    class MatchRank
    {
      public:
        explicit MatchRank( const CenRank & i_rank ) : iv_rank(i_rank) {}

        bool operator() ( const Entry & i_e ) const
        { return ( iv_rank.getMaster() == i_e.rank.getMaster() ); }

      private:
        CenRank iv_rank; ///< Rank to match.
    };

};

//------------------------------------------------------------------------------

/**
 * @brief A map containing VCM data for affected ranks.
 *
 * Keeps track of VCM false alarm thresholds.
 *
 * @note  This data is only intended to be used by the runtime TD controller.
 */
class VcmRankData
{
  private: // structs, typedefs

    /** @brief Structure to represent a data entry. */
    struct Entry
    {
        /** Time based false alarm counter. */
        TimeBasedThreshold falseAlarms;

        /** @brief Default constructor */
        Entry() :
            falseAlarms( 4, 7 * ThresholdResolution::ONE_DAY )
        {}
    };

  public: // functions

    /** @brief Default constructor */
    VcmRankData() : iv_map() {}

    /**
     * @brief  Increments the time based counter for false alarms.
     * @param  i_rank        Target master rank.
     * @param  i_sc          The step code data struct.
     * @return TRUE if false alarm threshold is exceeded, FALSE otherwise.
     */
    bool incFalseAlarm( const CenRank & i_rank, STEP_CODE_DATA_STRUCT & i_sc )
    {
        return (iv_map[getKey(i_rank)].falseAlarms).inc( i_sc );
    }

    /**
     * @param  Target master rank.
     * @return Current false alarm threshold count.
     */
    uint8_t getFalseAlarmCount( const CenRank & i_rank );

  private: // functions

    /**
     * @brief  VCM procedures operate on master ranks only.
     * @return Master rank key value.
     */
    uint8_t getKey( const CenRank & i_rank )
    {
        return i_rank.getMaster();
    }

  private: // instance variables

    std::map<uint8_t, Entry> iv_map; ///< The VCM data map

};

//------------------------------------------------------------------------------

/**
 * @brief A map containing TPS data for affected ranks.
 *
 * Keeps track of TPS false alarm thresholds and whether a rank has been banned
 * from further TPS request because TPS is no longer useful for that rank.
 *
 * @note  This data is only intended to be used by the runtime TD controller.
 */
class TpsRankData
{
  private: // structs, typedefs

    /** @brief Structure to represent a data entry. */
    struct Entry
    {
        bool isBanned; ///< True if TPS is no longer allowed on this rank.

        /** Time based false alarm counter. */
        TimeBasedThreshold falseAlarms;

        /** @brief Default constructor */
        Entry() :
            isBanned(false),
            falseAlarms( 3, 7 * ThresholdResolution::ONE_DAY )
        {}
    };

  public: // functions

    /** @brief Default constructor */
    TpsRankData() : iv_map() {}

    /**
     * @brief  Increments the time based counter for false alarms.
     * @param  i_rank        Target slave rank.
     * @param  i_sc          The step code data struct.
     * @return TRUE if false alarm threshold is exceeded, FALSE otherwise.
     */
    bool incFalseAlarm( const CenRank & i_rank, STEP_CODE_DATA_STRUCT & i_sc )
    {
        return (iv_map[i_rank].falseAlarms).inc( i_sc );
    }

    /**
     * @param  Target slave rank.
     * @return Current false alarm threshold count.
     */
    uint8_t getFalseAlarmCount( const CenRank & i_rank );

    /**
     * @brief  Initially TPS only counts hard CEs. After serveral false alarms
     *         TPS needs to switch to counting all CEs.
     * @param  i_rank Target slave rank.
     * @return True if this threshold has been reached and TPS needs to count
     *         all CEs, false otherwise.
     */
    bool checkCeTypeTh( const CenRank & i_rank );

    /**
     * @brief  Ban all future TPS requests on this rank.
     * @param  i_rank  Target slave rank.
     */
    void ban( const CenRank & i_rank ) { iv_map[i_rank].isBanned = true; }

    /**
     * @brief  Check if TPS requests are banned on this rank.
     *
     * There are two ways a rank can be banned:
     *  - If ban() was called on this rank. This is a permanent ban. It should
     *    only be called if there was a predictive error log calling out this
     *    rank.
     *  - If there was a TPS false alarm threshold. This is a temporary ban. All
     *    subsequent TPS requests for this rank will be suppressed until the
     *    threshold time period has expired.
     *
     * @param  i_rank  Target slave rank.
     * @param  i_sc    The step code data struct.
     * @return True if TPS is not allowed on this rank, false otherwise.
     */
    bool isBanned( const CenRank & i_rank, STEP_CODE_DATA_STRUCT & i_sc );

  private: // instance variables

    std::map<CenRank, Entry> iv_map; ///< The TPS data map

};

} // end namespace PRDF

#endif // __prdfCenMbaTdRankData_rt_H

