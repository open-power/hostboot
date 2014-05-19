/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfResetThresholdResolution.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2014              */
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

#ifndef prdfResetThresholdResolution_H
#define prdfResetThresholdResolution_H
/**
 @file prdfResetThresholdResolution.H
 @brief Resolution that counts occurrances up to a threshold, then reports and resets
        the count and starts counting again.
*/

#include <prdfThresholdResolutions.H>
#warning -This is an obsolite part

#if defined(_OBSOLITE_)
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#ifndef iipResolution_h
#include <iipThresholdResolution.h>
#endif

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

/**
 ResetThresholdResolution
 @par
 Resolution that has a threshold and keeps track of how
 many times its called. When the threshold is reached, it
 tells the service data collector and sends it a mask id,
 then resets the threshold count to 0.
 @code
   enum { thresholdValue = 32, MaskId = 05 };
   ResetThresholdResolution rtr(thresholdValue,MaskId);
   Resolution & fr = ResolutionFactory::Access().GetCalloutResolution(HOM_IOHUBCHIP0,MRU_HIGH);
   ResolutionMap rm(...);    // see ResolutionMap
   rm.Add(BIT_LIST_STRING_05,&rtr,&ftr);   // Resolution invoked when bit 5
  //                                          is on - callsout callout and
  //                                          thresholds at thresholdValue
 @endcode
*/
class ResetThresholdResolution : public ThresholdResolution
{
public:
  /**
   ctor
   @param thresholdValue, error is reported when count == thresholdValue
   @param maskId is send to the service data collector when threshold is reached
   @pre none
   @post internal count set to zero
   @note If another resolution is chained to this one, it is always called reguardless of the count
   */
  ResetThresholdResolution(uint16_t thresholdValue, uint32_t mask_id);

  /**
   ctor
   @param thresholdValue, error is reported when count == thresholdValue
   @param maskId is send to the service data collector when threshold is reached
   @param Another resolution to call (chained) after this one
   @pre none
   @post internal count set to zero
   @note If another resolution is chained to this one, it is always called reguardless of the count
   */
//  ResetThresholdResolution(uint32_t thresholdValue, uint32_t mask_id, Resolution &r);

  // ~ResetThresholdResolution(); compiler default is ok
  // copy ctor - Compiler default ok
  // Assignment - Compiler default ok

  /**
   Resolve this part of the error (increment count)
   @param error, Access to ServiceDataCollector @see ServiceDataCollector
   @returns [SUCCESS| return code]
   @pre none
   @post 1) ++count.
         2) if count == threshold then error.service_data->IsAtThreshold() == true and
             maskId is sent to serviceDataCollector.
         3)Chained resolution called if one was provided in ctor
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);


private:  // functions
private:  // Data

//  uint8_t  threshold;
//  uint8_t  count;
//  uint16_t maskId;
//  Resolution * xRes;
};

inline
ResetThresholdResolution::ResetThresholdResolution(uint16_t thresholdValue, uint32_t mask_id)
: ThresholdResolution(thresholdValue,mask_id)
{}

/*
inline
ResetThresholdResolution::ResetThresholdResolution(uint32_t thresholdValue,
                                         uint32_t mask_id,
                                         Resolution & r)
: Resolution(), threshold(thresholdValue), count(0), maskId(mask_id), xRes(&r)
{}
*/
#endif
#endif /* xspprdResetThresholdResolution_h */
