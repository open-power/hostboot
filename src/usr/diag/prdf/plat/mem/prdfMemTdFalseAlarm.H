/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdFalseAlarm.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

#ifndef __prdfMemTdFalseAlarm_H
#define __prdfMemTdFalseAlarm_H

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfThresholdUtils.H>

// Other includes
#include <map>

namespace PRDF
{

/** @brief This is used at runtime to keep track of false alarm for Targeted
 *         Diagnostics to avoid flooding of intermittent errors. */
class TdFalseAlarm
{
  public: // functions

    /** @brief Default destructor */
    virtual ~TdFalseAlarm()  = default;

    /**
     * @brief  Queries if the threshold timer has expired.
     * @param  i_rank The rank with the false alarm.
     * @param  io_sc  The step code data struct.
     * @return True if the threshold timer has expired, false otherwise.
     */
    bool elapsed( MemRank i_rank, STEP_CODE_DATA_STRUCT & io_sc )
    {
        uint32_t key = init( i_rank, io_sc );
        return iv_thMap[key].timeElapsed( io_sc );
    }

    /**
     * @brief  Queries the current false alarm count.
     * @param  i_rank The rank with the false alarm.
     * @param  io_sc  The step code data struct.
     * @return The current false alarm count.
     */
    uint8_t count( MemRank i_rank, STEP_CODE_DATA_STRUCT & io_sc )
    {
        uint32_t key = init( i_rank, io_sc );
        return iv_thMap[key].getCount();
    }

  protected: // functions

    /**
     * @brief Constructor.
     * @param i_th Threshold for each entry in the threshold map.
     */
    explicit TdFalseAlarm( TimeBasedThreshold i_th ) : iv_th(i_th) {}

    /**
     * @brief  The key could be different per TD procedure. For example, VCM
     *         events will use only the master rank, where TPS events will use
     *         both the master and slave rank.
     * @param  i_rank The rank with the false alarm.
     * @return The key value for this rank.
     */
    virtual uint32_t getKey( MemRank i_rank ) const = 0;

    /**
     * @brief  Initializes data specific to each child class.
     * @param  i_rank The rank with the false alarm.
     * @param  io_sc  The step code data struct.
     * @return The key for this rank (see getKey()).
     * @note   This function should be called before accessing the instance
     *         variables to ensure this key is initialized with the correct
     *         threshold.
     * @note   The default is to call initThMap(). Each child class that
     *         overloads this function should also call initThMap() to ensure
     *         the threshold map is initialized properly.
     */
    virtual uint32_t init( MemRank i_rank, STEP_CODE_DATA_STRUCT & io_sc )
    {
        return initThMap( i_rank );
    }

    /**
     * @brief  Initializes this key in the threshold map.
     * @param  i_rank The rank with the false alarm.
     * @return The key for this rank (see getKey()).
     * @note   This function should only be called from init().
     */
    uint32_t initThMap( MemRank i_rank )
    {
        uint32_t key = getKey( i_rank );

        // Create a new entry if an entry does not exist.
        if ( iv_thMap.end() == iv_thMap.find(key) ) iv_thMap[key] = iv_th;

        return key;
    }

    /**
     * @brief  Increments the false alarm count.
     * @param  i_rank The rank with the false alarm.
     * @param  io_sc  The step code data struct.
     * @return True if false alarm count has reached threshold, false otherwise.
     */
    bool incThMap( MemRank i_rank, STEP_CODE_DATA_STRUCT & io_sc )
    {
        uint32_t key = init( i_rank, io_sc );
        return iv_thMap[key].inc( io_sc );
    }

  private: // instance variables

    /** Threshold for each entries in the map. */
    const TimeBasedThreshold iv_th;

  protected: // instance variables

    /** A map containing the thresholds for each key. */
    std::map<uint32_t, TimeBasedThreshold> iv_thMap;
};

/** @brief A false alarm class specific to VCM procedures. */
class VcmFalseAlarm : public TdFalseAlarm
{
  public:

    /**
     * @brief Constructor.
     * @param i_th Threshold for each entry in the map.
     */
    VcmFalseAlarm( TimeBasedThreshold i_th ) : TdFalseAlarm(i_th) {}

    /**
     * @brief  Increments the false alarm count and stores the DRAM.
     * @param  i_rank The rank with the false alarm.
     * @param  i_dram The DRAM with the false alarm.
     * @param  io_sc  The step code data struct.
     * @return True if false alarm count has reached threshold, false otherwise.
     */
    bool inc( MemRank i_rank, uint8_t i_dram, STEP_CODE_DATA_STRUCT & io_sc )
    {
        // Increment the count and determine whether threshold is reached or
        // not. Note that incThMap() calls init() and initializes all maps.
        bool isTh = incThMap( i_rank, io_sc );

        // Add the DRAM to the list. Note that the value for each DRAM is not
        // important. The only reason to use a map verses a vector is to ensure
        // unique entries in the list.
        iv_dramMap[getKey(i_rank)][i_dram] = 1;

        return isTh;
    }

    /**
     * @param  i_rank The rank with the false alarm.
     * @param  i_dram The DRAM with the false alarm.
     * @param  io_sc  The step code data struct.
     * @return True if there is at least one DRAM on this rank with a false
     *         alarm other than i_dram.
     */
    bool queryDrams( MemRank i_rank, uint8_t i_dram,
                     STEP_CODE_DATA_STRUCT & io_sc )
    {
        uint32_t key = init( i_rank, io_sc ); // will clear list if time elapsed

        if ( 2 <= iv_dramMap[key].size() )
        {
            // Regardless if i_dram is in the list, or not, there is at least
            // one extra DRAM.
            return true;
        }
        else if ( 1 == iv_dramMap[key].size() &&
                  i_dram != iv_dramMap[key].begin()->first )
        {
            // The only DRAM in the list is not i_dram.
            return true;
        }

        return false; // No extra DRAMs.
    }

  private: // functions

    // Overloaded from parent class.
    uint32_t getKey( MemRank i_rank ) const
    {
        return MemRank(i_rank.getMaster()).getKey(); // master only
    }

    // Overloaded from parent class.
    uint32_t init( MemRank i_rank, STEP_CODE_DATA_STRUCT & io_sc )
    {
        uint32_t key = initThMap( i_rank );

        // Clear out the list of DRAMs if the threshold time has elapsed.
        // Note that we cannot call elapsed() because it will do a recursive
        // call to init().
        if ( iv_thMap[key].timeElapsed(io_sc) ) iv_dramMap[key].clear();

        return key;
    }

  private: // instance variables

    /** A map to keep track of which DRAMs per rank have reported chip marks. */
    std::map< uint32_t, std::map<uint8_t, uint8_t> > iv_dramMap;
};

/** @brief A false alarm class specific to TPS procedures. */
class TpsFalseAlarm : public TdFalseAlarm
{
  public:

    /**
     * @brief Constructor.
     * @param i_th Threshold for each entry in the map.
     */
    TpsFalseAlarm( TimeBasedThreshold i_th ) : TdFalseAlarm(i_th) {}

    /**
     * @brief  Increments the false alarm count.
     * @param  i_rank The rank with the false alarm.
     * @param  io_sc  The step code data struct.
     * @return True if false alarm count has reached threshold, false otherwise.
     */
    bool inc( MemRank i_rank, STEP_CODE_DATA_STRUCT & io_sc )
    {
        return incThMap( i_rank, io_sc );
    }

  private: // functions

    // Overloaded from parent class.
    uint32_t getKey( MemRank i_rank ) const
    {
        return i_rank.getKey(); // both master and slave
    }
};

} // end namespace PRDF

#endif // __prdfMemTdFalseAlarm_H

