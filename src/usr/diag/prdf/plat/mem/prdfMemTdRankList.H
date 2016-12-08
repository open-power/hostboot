/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdRankList.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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

#ifndef __prdfTdRankList_H
#define __prdfTdRankList_H

// Platform includes
#include <prdfMemRank.H>
#include <prdfPlatServices.H>

// Other includes
#include <algorithm>
#include <vector>

namespace PRDF
{

/** @brief Structure to represent a rank list entry. */
class TdRankListEntry
{
  public:

    /** @brief Default constructor. */
    TdRankListEntry() = default;

    /** @brief Constructor from components. */
    TdRankListEntry( ExtensibleChip * i_chip, const MemRank & i_rank ) :
        iv_chip(i_chip), iv_rank(i_rank)
    {}

    /** @brief Accessor function. */
    ExtensibleChip * getChip() const { return iv_chip; }

    /** @brief Accessor function. */
    MemRank getRank() const { return iv_rank; }

    /** @brief '==' operator */
    bool operator==( const TdRankListEntry & e ) const
    {
        PRDF_ASSERT( this->getChip()->getType() == e.getChip()->getType() );
        return ( this->getChip()->getPos() == e.getChip()->getPos() ) &&
               ( this->iv_rank             == e.iv_rank             );
    }

    /** @brief '<' operator */
    bool operator<( const TdRankListEntry & e ) const
    {
        PRDF_ASSERT( this->getChip()->getType() == e.getChip()->getType() );
        return (  this->getChip()->getPos() <  e.getChip()->getPos()    ) ||
               ( (this->getChip()->getPos() == e.getChip()->getPos()) &&
                 (this->getRank()           <  e.getRank()          )   );
    }

    /** @brief '<=' operator */
    bool operator<=( const TdRankListEntry & e ) const
    {
        return ( *this < e || *this == e );
    }

  private:

    ExtensibleChip * iv_chip; ///< MCA or MBA chip.
    MemRank          iv_rank; ///< Any rank on the MCA or MBA.
};

/**
 * @brief A sorted list of all master/slave ranks behind an MBA or MCBIST. The
 *        list will be sorted by the order in which hardware will scrub memory.
 */
template <TARGETING::TYPE T>
class TdRankList
{
  public: // structs, typedefs

  public: // functions

    /**
     * @brief Constructor.
     * @param MCBIST or MBA chip.
     */
    explicit TdRankList( ExtensibleChip * i_chip );

    /**
     * @brief  Will return the entry in the list that immediately follows the
     *         given entry.
     *
     * If the current entry is at the end of the list, this function will wrap
     * around to the beginning of the list. In broadcast mode, the rank
     * configuration for all chips will be the same. Therefore, this function
     * will wrap to the first rank for the given chip, if needed. Users can
     * compare if the 'next' entry is less than or equal to the 'current' entry
     * to determine of the search wrapped.
     *
     * @param  i_current       The staring point for the search.
     * @param  i_broadcastMode True if commands are being run in broadcast mode
     *                         (MCBIST super-fast commands only). False
     *                         otherwise.
     * @return The next entry in the list.
     */
    TdRankListEntry getNext( const TdRankListEntry & i_current,
                             bool i_broadcastMode = false ) const
    {
        // Find the current entry in the list.
        std::vector<TdRankListEntry>::const_iterator next_it;
        next_it = std::find( iv_list.begin(), iv_list.end(), i_current );
        PRDF_ASSERT( iv_list.end() != next_it ); // code bug

        // Get the next entry and wrap to the beginning, if needed.
        if ( iv_list.end() == ++next_it ) next_it = iv_list.begin();

        // Check broadcast mode. If the chip changed, wrap to the first rank of
        // the given chip. This is to ensure the user can do the 'next <=
        // current' check to determine if it wrapped.
        if ( i_broadcastMode && (i_current.getChip() != next_it->getChip()) )
        {
            // The rank configurations for all chips will be the same. Also, we
            // know the rank in the next entry will be the first rank of that
            // chip. So we can assume the rank in the next entry will be the
            // first rank of the target chip.
            TdRankListEntry entry ( i_current.getChip(), next_it->getRank() );
            next_it = std::find( iv_list.begin(), iv_list.end(), entry );
            PRDF_ASSERT( iv_list.end() != next_it ); // code bug
        }

        return *next_it;
    }

  private: // instance variables

    std::vector<TdRankListEntry> iv_list; ///< The list of ranks.
};

//------------------------------------------------------------------------------

template<>
inline TdRankList<TARGETING::TYPE_MCBIST>::TdRankList( ExtensibleChip * i_chip )
{
    using namespace TARGETING;
    using namespace PlatServices;

    PRDF_ASSERT( TYPE_MCBIST == i_chip->getType() );

    ExtensibleChipList mcaChipList = getConnected( i_chip, TYPE_MCA );
    for ( auto & mcaChip : mcaChipList )
    {
        std::vector<MemRank> rankList;
        getSlaveRanks<TYPE_MCA>( mcaChip->getTrgt(), rankList );
        PRDF_ASSERT( !rankList.empty() ); // target configured with no ranks

        for ( auto & rank : rankList )
        {
            iv_list.push_back( TdRankListEntry(mcaChip, rank) );
        }
    }
}

//------------------------------------------------------------------------------

template<>
inline TdRankList<TARGETING::TYPE_MBA>::TdRankList( ExtensibleChip * i_chip )
{
    using namespace TARGETING;
    using namespace PlatServices;

    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    std::vector<MemRank> rankList;
    getSlaveRanks<TYPE_MBA>( i_chip->getTrgt(), rankList );
    PRDF_ASSERT( !rankList.empty() ); // target configured with no ranks

    for ( auto & rank : rankList )
    {
        iv_list.push_back( TdRankListEntry(i_chip, rank) );
    }
}

} // end namespace PRDF

#endif // __prdfTdRankList_H

