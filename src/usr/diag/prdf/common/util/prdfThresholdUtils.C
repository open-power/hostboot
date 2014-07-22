/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfThresholdUtils.C $          */
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

/** @file prdfThresholdUtils.C */

#include <prdfThresholdUtils.H>
#include <iipServiceDataCollector.h>

namespace PRDF
{

void TimeBasedThreshold::reset()
{
    iv_timerInited = false;
    iv_count = 0;
}

//------------------------------------------------------------------------------

bool TimeBasedThreshold::inc( const STEP_CODE_DATA_STRUCT & i_sc )
{
    return inc( i_sc, 1 );
}

//------------------------------------------------------------------------------

bool TimeBasedThreshold::inc( const STEP_CODE_DATA_STRUCT & i_sc,
                              uint8_t i_count )
{
    if ( !iv_timerInited || timeElapsed(i_sc) )
    {
        reset();
        iv_timer = i_sc.service_data->GetTOE() + iv_thPolicy.interval;
        iv_timerInited = true;
    }

    iv_count += i_count;

    return thReached(i_sc);
}

//------------------------------------------------------------------------------

uint8_t TimeBasedThreshold::getCount() const
{
    return iv_timerInited ? iv_count : 0;
}

//------------------------------------------------------------------------------

bool TimeBasedThreshold::timeElapsed( const STEP_CODE_DATA_STRUCT & i_sc ) const
{
    return ( iv_timerInited && (i_sc.service_data->GetTOE() > iv_timer) );
}

//------------------------------------------------------------------------------

bool TimeBasedThreshold::thReached( const STEP_CODE_DATA_STRUCT & i_sc ) const
{
    return ( !timeElapsed(i_sc) && (iv_thPolicy.threshold <= iv_count) );
}

} // end namespace PRDF

