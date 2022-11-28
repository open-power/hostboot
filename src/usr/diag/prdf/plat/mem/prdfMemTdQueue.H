/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdQueue.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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

/** @file  prdfMemTdQueue.H
 *  @brief Support code for a Targeted Diagnostics weighted event queue.
 */

#ifndef __prdfMemTdQueue_H
#define __prdfMemTdQueue_H

// Framework includes
#include <iipServiceDataCollector.h>

// Platform includes
#include <prdfMemRank.H>

// Other includes
#include <algorithm>
#include <vector>

namespace PRDF
{

//------------------------------------------------------------------------------
//                               TdEntry class
//------------------------------------------------------------------------------

/** @brief Abstract class for a Targeted Diagnostics event. */
class TdEntry
{
  public: // enums, constants

    /**
     * @brief This enum will be used to indicate type of TD event requested to
     *        be handled.
     * @note  The order of the enums values is important because it is used for
     *        sorting the TdQueue by event type priority.
     *        A copy of this enum exists in prdfMemLogParse.C as well as a
     *        corresponding map in the 'tdTypeToStr' function of the be500.py
     *        user data parser. These should all be kept consistent.
     */
    enum TdType
    {
        VCM_EVENT = 0,       ///< A Verify Chip Mark event.
        RRD_EVENT,           ///< A Row Repair Deploy event.
        DSD_EVENT,           ///< A DRAM Spare Deploy event.
        TPS_EVENT,           ///< A Two-Phase Scrub event.
        INVALID_EVENT = 0xf, ///< Used to denote that no event is in progress
    };

    /**
     * @brief This enum will indicate which VCM or TPS phase we are currently on
     */
    enum Phase
    {
        TD_PHASE_0,
        TD_PHASE_1,
        TD_PHASE_2,
    };

  public: // functions

    /** @brief Default destructor */
    virtual ~TdEntry() = default;

    /**
     * @brief  Each entry will have a set of steps that need to be performed.
     *         This function tells the procedure to move onto the next step.
     * @param  io_sc  The step code data struct.
     * @param  o_done True if the procedure is complete or has aborted, false
     *                otherwise.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc,
                               bool & o_done ) = 0;

    /** @return Each event type will have a unique key identifier used for each
     *          procedure. The value is arbitrary. The only requirement is that
     *          it is unique to the hardware it is targeting. For example, VCM
     *          events will use only the master rank, where TPS events will use
     *          both the master and slave rank. */
    virtual uint32_t getKey() const = 0;

    /** @brief '==' operator */
    bool operator==( const TdEntry & i_e ) const
    {
        return ( this->iv_tdType == i_e.iv_tdType &&
                 this->getKey()  == i_e.getKey()  &&
                 this->iv_chip   == i_e.iv_chip );
    }

    /**
     * @brief '<' operator
     * @note This only compares iv_tdType because the TdQueue only sorts by type
     */
    bool operator<( const TdEntry & i_e ) const
    {
        return this->iv_tdType < i_e.iv_tdType;
    }

    /** @return The event type */
    TdType getType() const { return iv_tdType; }

    /** @return The chip in which this event occurred */
    ExtensibleChip * getChip() const { return iv_chip; }

    /** @return The rank in which this event occurred */
    MemRank getRank() const { return iv_rank; }

    /** @return The event phase */
    Phase getPhase() const { return iv_phase; }

  protected: // functions

    /**
     * @brief Constructor
     * @param i_tdType  See TdType enum
     * @param i_chip    OCMB chip
     * @param i_rank    Target rank
     */
    TdEntry( TdType i_tdType, ExtensibleChip * i_chip, MemRank i_rank ) :
        iv_tdType(i_tdType), iv_chip(i_chip), iv_rank(i_rank)
    {}

  protected: // instance variables

    const TdType iv_tdType;         ///< The event type (see enum TdType).
    Phase iv_phase = TD_PHASE_0;    ///< The event phase (see enum Phase).
    ExtensibleChip * const iv_chip; ///< The chip in which this event occurred.

    // These are not used for comparisons, but used by all procedures and also
    // used for displaying FFDC in the TD controller.
    const MemRank          iv_rank; ///< The rank in which this event occurred.

    /** True if the current TD command can be resumed, false otherwise. Resume
     *  only supported for MBA at this time. */
    bool iv_canResumeScrub = false;
};

//------------------------------------------------------------------------------
//                               TdQueue class
//------------------------------------------------------------------------------

/**
 * @brief This is a weighted queue for all Targeted Diagnostics events.
 * @note  Events with a higher priority will be moved ahead of lower priority
 *        events.
 */
class TdQueue
{
  public: // typedefs

    typedef          std::vector< TdEntry * >           Queue;
    typedef typename std::vector< TdEntry * >::iterator QueueItr;

  public: // functions

    /** @brief Destructor. */
    ~TdQueue() { for ( auto & a : iv_queue ) delete a; }

    /** @return TRUE if the queue is empty, FALSE otherwise. */
    bool empty() const { return iv_queue.empty(); }

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
    TdEntry * getNextEntry()
    {
        PRDF_ASSERT( !iv_queue.empty() );

        // TODO: RTC 66487 This function currently has the complexity of
        //       O(n lg n) because of the sorting. It is possible to optimize
        //       this to O(n) if we use push_heap()/pop_heap(). However, there
        //       is a problem were push_heap() could possibly reorder the queue
        //       while a TD procedure is in progress, which is undesirable.

        std::sort( iv_queue.begin(), iv_queue.end(),
                   [](TdEntry * a, TdEntry * b) { return *a < *b; } );

        return iv_queue.front();
    }

    /**
     * @brief Add new TD entry at the end of the queue.
     * @param i_e A TD entry.
     * @note  Only adds the entry to the queue if the entry does not already
     *        exist in the queue.
     */
    void push( TdEntry * i_e )
    {
        QueueItr it = std::find_if( iv_queue.begin(), iv_queue.end(),
                                    [=](TdEntry * a){return *i_e == *a;} );
        if ( iv_queue.end() == it )
        {
            iv_queue.push_back( i_e );
        }
        else
        {
            // The event is already in the queue. So free up the memory.
            delete i_e;
        }
    }

    /**
     * @brief Removes the entry at the beginning of the queue.
     */
    // TODO: RTC 66487 This function currently has a complexity of 0(n). It
    //       is preferred to have 0(1), which could be accomplished with by
    //       using a deque or list. Unfortunately, Hostboot currently does not
    //       support std::deque or std::list::sort(). Therefore, we must use a
    //       vector at this time.
    void pop()
    {
        PRDF_ASSERT( !iv_queue.empty() );

        delete *(iv_queue.begin());
        iv_queue.erase(iv_queue.begin());
    }

    /**
     * @return A constant reference to the queue.
     * @note   The only purpose for this is for FFDC.
     */
    const Queue & getQueue() const { return iv_queue; }

  private: // instance variables

    /** Stores all ranks that are marked for targeted diagnostics. */
    Queue iv_queue;
};

} // end namespace PRDF

#endif // __prdfMemTdQueue_H

