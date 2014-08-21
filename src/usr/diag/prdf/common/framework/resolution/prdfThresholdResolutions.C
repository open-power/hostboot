/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfThresholdResolutions.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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

/**
   @file prdfThresholdResolutions.C
   @brief MaskResolution, IntervalThresholdResolution, ResetThresholdResolution
*/
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define prdfThresholdResolutions_C

#include <iipServiceDataCollector.h>
#include <prdfTimer.H>
#include <prdfFlyWeight.H>
#include <prdfThresholdResolutions.H>
#include <prdfFlyWeight.C>

#undef prdfThresholdResolutions_C
//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

namespace PRDF
{

// This is global varaible for stroring threshold policy instances.
// It must be cleared in prdf uninitialize
FlyWeight<ThresholdResolution::ThresholdPolicy, 10> g_thresholdPFW;

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

const ThresholdResolution::ThresholdPolicy ThresholdResolution::cv_fieldDefault
    = g_thresholdPFW.get(
        ThresholdResolution::ThresholdPolicy(32,ThresholdResolution::ONE_DAY));

const ThresholdResolution::ThresholdPolicy ThresholdResolution::cv_mnfgDefault
    = g_thresholdPFW.get(
        ThresholdResolution::ThresholdPolicy(1,ThresholdResolution::NONE));

const ThresholdResolution::ThresholdPolicy ThresholdResolution::cv_pllDefault
    = g_thresholdPFW.get(
      ThresholdResolution::ThresholdPolicy(2,5 * ThresholdResolution::ONE_MIN));

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

int32_t MaskResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
  error.service_data->SetHits(1);
  error.service_data->SetThreshold(1);
  error.service_data->SetThresholdMaskId(iv_maskId);
  return SUCCESS;
}

//---------------------------------------------------------------------

int32_t MaskResolution::GetCount()          // wl01
{
  return 1;
}

//---------------------------------------------------------------------

void MaskResolution::ResetCount()           // wl01
{
  return;
}

//---------------------------------------------------------------------

ThresholdResolution::ThresholdResolution( uint32_t maskId,
                                          uint8_t i_threshold,
                                          uint32_t i_interval ) :
    MaskResolution(maskId),
    iv_policy( &g_thresholdPFW.get(ThresholdPolicy(i_threshold,i_interval))),
    iv_count(0)
{}

//---------------------------------------------------------------------

ThresholdResolution::ThresholdResolution() :
    MaskResolution(0),
    iv_policy( &(ThresholdResolution::cv_fieldDefault)),
    iv_count(0)
{}

//---------------------------------------------------------------------

ThresholdResolution::ThresholdResolution( uint32_t maskId,
                                          const ThresholdPolicy& thresholdp ) :
    MaskResolution(maskId),
    iv_policy(&g_thresholdPFW.get(thresholdp)),
    iv_count(0)
{}

//---------------------------------------------------------------------

int32_t ThresholdResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
  int32_t rc = SUCCESS;
  Timer curTime = error.service_data->GetTOE();    // get timestamp (Time Of Error) from SDC
  ++iv_count;
  error.service_data->SetHits((uint8_t)iv_count);
  error.service_data->SetThreshold((uint8_t)iv_policy->threshold);
  if (iv_count == 1)                                  // Interval begins at the 1st occurrence
  {
    iv_endTime = curTime + iv_policy->interval;       // Project the end of interval (in sec)
    if((iv_count == iv_policy->threshold) ||
            (error.service_data->IsFlooding()))       // We've hit threshold within the interval
    {
      error.service_data->SetThresholdMaskId(iv_maskId);  // threshold, degraded YES
      iv_count = 0;                                       // Reset the counter on threshold
    }
  }
  else
  {
    if (curTime > iv_endTime)                         // Are we already past the time window?
    {
        iv_count = 1;                                   // Reset count as if it were the first
        error.service_data->SetHits((uint8_t)iv_count); // pw01
        iv_endTime = curTime + iv_policy->interval;     // Project the new end of interval
    }
    else if((iv_count == iv_policy->threshold) ||
            (error.service_data->IsFlooding()))       // We've hit threshold within the interval
    {
      error.service_data->SetThresholdMaskId(iv_maskId);  // threshold, degraded YES
      iv_count = 0;                                       // Reset the counter on threshold
    }
    else ;                                              // Nothing else
  }

  return rc;
}

//---------------------------------------------------------------------

void ThresholdResolution::ResetCount()          // wl01
{
  iv_count = 0;
  return;
}

//---------------------------------------------------------------------

int32_t ThresholdResolution::GetCount()         // wl01
{
  return iv_count;
}

//---------------------------------------------------------------------

void ThresholdResolution::reset()
{
    g_thresholdPFW.clear();
}

//---------------------------------------------------------------------

ThresholdSigResolution::ThresholdSigResolution( uint8_t i_threshold,
                                                uint32_t i_interval ) :
    iv_policy( &g_thresholdPFW.get(
                  ThresholdResolution::ThresholdPolicy(i_threshold,i_interval)))
{}

//---------------------------------------------------------------------

ThresholdSigResolution::ThresholdSigResolution(
                         const ThresholdResolution::ThresholdPolicy & policy ) :
    iv_policy( &g_thresholdPFW.get(policy))
{}

//---------------------------------------------------------------------

ThresholdSigResolution::ThresholdSigResolution() :
    iv_policy( &(ThresholdResolution::cv_fieldDefault))
{}

//---------------------------------------------------------------------

int32_t ThresholdSigResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
    int32_t l_rc = SUCCESS;

    Timer l_curTime = error.service_data->GetTOE();
    ErrorSignature l_sig = *error.service_data->GetErrorSignature();
    ThresholdCountAndTimer & l_countTime = iv_thresholds[l_sig];

    uint32_t l_count = ++(l_countTime.first); // increment count.

    // update service data with threshold info.
    error.service_data->SetHits((uint8_t) l_count);
    error.service_data->SetThreshold((uint8_t)iv_policy->threshold);

    if (1 == l_count) // first time: set end timer.
    {
        l_countTime.second = l_curTime + iv_policy->interval;
        if ((l_countTime.first == iv_policy->threshold) ||
                 (error.service_data->IsFlooding()))
        {
            // set overthreshold flag / maskid, clear count.
            error.service_data->SetThresholdMaskId(l_sig.getSigId());
            l_countTime.first = 0;
        }
    }
    else
    {
        if (l_curTime > l_countTime.second) // time > interval: reset end timer
        {
            l_countTime.first = 1;
            error.service_data->SetHits((uint8_t)l_countTime.first); // pw01
            l_countTime.second = l_curTime + iv_policy->interval;
        }
        // Check over threshold and under time interval.
        else if ((l_countTime.first == iv_policy->threshold) ||
                 (error.service_data->IsFlooding()))
        {
            // set overthreshold flag / maskid, clear count.
            error.service_data->SetThresholdMaskId(l_sig.getSigId());
            l_countTime.first = 0;
        }
        else; // nothing else.
    }

    return l_rc;
}

} // end namespace PRDF
