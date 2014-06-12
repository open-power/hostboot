/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfThresholdUtils.H $          */
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

#ifndef __prdfThresholdUtils_H
#define __prdfThresholdUtils_H

/** @file prdfThresholdUtils.H */

#include <prdfThresholdResolutions.H>

namespace PRDF
{

class TimeBasedThreshold
{
  public:

    /**
     * @brief Constructor
     */
    TimeBasedThreshold() :
        iv_thPolicy(ThresholdResolution::cv_fieldDefault), iv_count(0),
        iv_timerInited(false)
    {}

    /**
     * @brief Constructor
     * @param i_thPolicy A threshold policy.
     */
    explicit TimeBasedThreshold(
                    const ThresholdResolution::ThresholdPolicy i_thPolicy ) :
        iv_thPolicy(i_thPolicy), iv_count(0), iv_timerInited(false)
    {}

    /**
     * @brief Constructor
     * @param i_thr The target threshold.
     * @param i_int The threshold time interval (in seconds).
     */
    TimeBasedThreshold( uint8_t i_thr, uint32_t i_int ) :
        iv_thPolicy(ThresholdResolution::ThresholdPolicy(i_thr, i_int)),
        iv_count(0), iv_timerInited(false)
    {}

    /** @brief Resets the threshold. */
    void reset();

    /**
     * @brief  Increments the count by 1.
     * @param  i_sc The step code data struct.
     * @return TRUE if the threshold has been reached, FALSE otherwise.
     */
    bool inc( const STEP_CODE_DATA_STRUCT & i_sc );

    /**
     * @brief  Increments the count by amount specified.
     * @param  i_sc    The step code data struct.
     * @param  i_count The specifies amount to increment.
     * @return TRUE if the threshold has been reached, FALSE otherwise.
     */
    bool inc( const STEP_CODE_DATA_STRUCT & i_sc, uint8_t i_count );

    /** @return The current count. */
    uint8_t getCount() const;

    /**
     * @param  i_sc The step code data struct.
     * @return TRUE if the time interval has elapsed, FALSE otherwise.
     */
    bool timeElapsed( const STEP_CODE_DATA_STRUCT & i_sc ) const;

    /**
     * @param  i_sc The step code data struct.
     * @return TRUE if the threshold has been reached, FALSE otherwise.
     */
    bool thReached( const STEP_CODE_DATA_STRUCT & i_sc ) const;

  private:

    /** The threshold policy for this object. */
    ThresholdResolution::ThresholdPolicy iv_thPolicy;

    uint8_t iv_count;    ///< The current count.
    Timer iv_timer;      ///< The threshold timer.
    bool iv_timerInited; ///< TRUE if the timer has been initialized.

};

} // end namespace PRDF

#endif // __prdfThresholdUtils_H

