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

#ifdef __HOSTBOOT_RUNTIME // All of this code is runtime only

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfThresholdUtils.H>

// Other includes
#include <map>

namespace PRDF
{

/**
 * @brief At runtime, we have to keep a false alarm threshold for Targeted
 *        Diagnostics to avoid flooding of intermittent errors.
 *
 * This class is intented to be a static class variable for each TD event class
 * that requires this type of thresholding. It will contain a map for each chip
 * and unique key within each chip to the threshold container. Note that the key
 * could be different per TD event class. For example, VCM events will use only
 * the master rank, where TPS events will use both the master and slave rank.
 */
class TdFalseAlarm
{
  public:

    /**
     * @brief Constructor.
     * @param i_th  Threshold value for all entries in the map.
     * @param i_int Threshold interval for all entries in the map.
     */
    TdFalseAlarm( uint8_t i_th, uint32_t i_int ) :
        iv_thVal(i_th), iv_thInt(i_int)
    {}

    /**
     * @brief  Increments the false alarm count.
     * @param  i_chip Target chip.
     * @param  i_key  Key relative to the chip.
     * @param  io_sc  The step code data struct.
     * @return True if false alarm count has reached threshold, false otherwise.
     */
    bool inc( ExtensibleChip * i_chip, uint32_t i_key,
              STEP_CODE_DATA_STRUCT & io_sc )
    {
        // Create a new entry if an entry does not exist.
        if ( iv_map[i_chip].end() == iv_map[i_chip].find(i_key) )
            iv_map[i_chip][i_key] = TimeBasedThreshold( iv_thVal, iv_thInt );

        return iv_map[i_chip][i_key].inc( io_sc );
    }

  private:

    const uint8_t  iv_thVal; ///< Threshold value for all entries in the map.
    const uint32_t iv_thInt; ///< Threshold interval for all entries in the map.

    /** A nested map containing the thresholds for each chip and key. */
    std::map< ExtensibleChip *, std::map<uint32_t,TimeBasedThreshold> > iv_map;
};

} // end namespace PRDF

#endif // __HOSTBOOT_RUNTIME

#endif // __prdfMemTdFalseAlarm_H

