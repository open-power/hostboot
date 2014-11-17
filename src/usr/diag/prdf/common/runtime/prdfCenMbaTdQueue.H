/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/runtime/prdfCenMbaTdQueue.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

/** @file  prdfCenMbaTdQueue.H
 *  @brief Support code for a Targeted Diagnostics weighted event queue.
 */

#ifndef PRDF_CEN_MBA_TD_QUEUE_H
#define PRDF_CEN_MBA_TD_QUEUE_H

// Framework includes
#include <prdf_types.h>

// Pegasus includes
#include <prdfCenAddress.H>
#include <prdfCenMbaTdCtlr_common.H>

// Other includes
#include <algorithm>
#include <queue>

namespace PRDF
{

/**
 * @brief Structure to represent a TD event.
 */
struct TdQueueEntry
{
    CenMbaTdCtlrCommon::TdType type; ///< The event type (see enum TdType).
    CenRank                    rank; ///< The rank in which this event occurred.

    /** @brief Constructor */
    TdQueueEntry( CenMbaTdCtlrCommon::TdType i_type, CenRank i_rank ) :
        type(i_type), rank(i_rank)
    {}

    /** @return TRUE if event are equal, FALSE otherwise. */
    bool operator==( const TdQueueEntry & i_e ) const
    {
        return ( this->type == i_e.type ) && ( this->rank == i_e.rank );
    }
};

/**
 * @brief This is a weighted queue for all TD events.
 * @note  Events with a higher priority will be moved ahead of lower priority
 *        events.
 */
class TdQueue
{
  public: // typedefs

    typedef std::deque<TdQueueEntry>           Queue;
    typedef std::deque<TdQueueEntry>::iterator QueueItr;

  public:

    /** @return TRUE if the queue is empty, FALSE otherwise. */
    bool empty() const { return iv_queue.empty(); }

    /**
     * @param  i_rank The target rank.
     * @return TRUE if the target rank exists in the queue.
     */
    bool exists( const CenRank & i_rank )
    {
        return ( iv_queue.end() != find_if( iv_queue.begin(), iv_queue.end(),
                                            MatchRank(i_rank) ) );
    }

    /**
     * @brief  Sorts the queue by priority order then returns the first entry.
     * @return The first entry in the queue.
     * @note   This is intended to be called only once for each time the TD
     *         controller needs to find the next TD procedure to do. If it is
     *         called multiple times, it is possible the list is reordered such
     *         that a new entry is moved to the front of the queue and is
     *         mistakenly removed via pop() before the TD controller is able to
     *         execute the request.
     */
    const TdQueueEntry & getNextEntry()
    {
        // TODO: RTC 66487 This function currently has the complexity of
        //       O(n lg n) because of the sorting. It is possible to optimize
        //       this to O(n) if we use push_heap()/pop_heap(). However, there
        //       is a problem were push_heap() could possibly reorder the queue
        //       while a TD procedure is in progress, which is undesirable.

        std::sort( iv_queue.begin(), iv_queue.end(), sortType );

        return iv_queue.front();
    }

    /**
     * @brief Add new TD entry at the end of the queue.
     * @param i_e A TD entry.
     * @note  Only adds the entry to the queue if the entry does not already
     *        exist in the queue.
     */
    void push( const TdQueueEntry & i_e )
    {
        QueueItr it = std::find( iv_queue.begin(), iv_queue.end(), i_e );
        if ( iv_queue.end() == it )
        {
            iv_queue.push_back( i_e );
        }
    }

    /**
     * @brief Removes the entry at the beginning of the queue.
     */
    void pop() { iv_queue.pop_front(); }

    /**
     * @return A constant reference to the queue.
     * @note   The only purpose for this is for FFDC.
     */
    const Queue & getQueue() const { return iv_queue; }

  private: // instance variables

    /** Stores all ranks that are marked for targeted diagnostics. */
    Queue iv_queue;

  private: // functors

    /** Functor sort by event type. */
    static bool sortType( const TdQueueEntry & i_e1, const TdQueueEntry & i_e2 )
    {
        return i_e1.type < i_e2.type; // 0 is highest priority.
    }

    /**
     * @brief Functor to find a rank in this queue.
     * @note  This functor will only match master rank.
     */
    class MatchRank
    {
      public:
        explicit MatchRank( const CenRank & i_rank ) : iv_rank(i_rank) {}

        bool operator() ( const TdQueueEntry & i_e ) const
        { return ( iv_rank.getMaster() == i_e.rank.getMaster() ); }

      private:
        CenRank iv_rank; ///< Rank to match.
    };
};

} // end namespace PRDF

#endif // PRDF_CEN_MBA_TD_QUEUE_H
