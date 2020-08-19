/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipThresholdResolution.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 1996,2020                        */
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

#ifndef iipThresholdResolution_h
#define iipThresholdResolution_h

// Class Description *************************************************
//
//  Name:  ThresholdResolution
//  Base class: Resolution
//
//  Description: Resolution that has a threshold and keeps track of how
//               many times its called. When the threshold is reached, it
//               tells the service data collector and sends it a mask id.
//  Usage:
//
//  MruCallout callout[] = {PU0};
//  enum { thresholdValue = 32, MaskId = 05 };
//  ThresholdResolution tr(thresholdValue,MaskId);
//  FinalResolution fr(callout,1);
//  ResolutionList rl(&tr,&fr);
//  ResolutionMap rm(...);
//  rm.Add(BIT_LIST_STRING_05,&rl);   // Resolution invoked when bit 5
//                                       is on - callsouts callout and
//                                       thresholds at thresholdValue
//
// End Class Description *********************************************

/**
 @file iipThresholdResolution.h
 @brief PRD ThresholdResolution class declairation
*/

#include <prdfThresholdResolutions.H>
#warning This part is obsolite

#if defined(_OBSOLITE_)
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

class ThresholdResolution : public Resolution
{
public:
  ThresholdResolution(uint16_t thresholdValue, uint32_t mask_id);
//  ThresholdResolution(uint16_t thresholdValue, uint32_t mask_id, Resolution &r);
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   thresholdValue: value at which threshold is reached
  //               mask_id: mask_id value to give to the service data
  //               Resolution: Another resolution to call when this one
  //                           is called
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************

  // ~ThresholdResolution();
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        Compiler default ok
  //
  // End Function Specification ****************************************

  // copy ctor - Compiler default ok
  // Assignment - Compiler default ok

  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error,
                          bool i_default = false);
  // Function Specification ********************************************
  //
  // Purpose:      Resolve service data for a specific error bit
  // Parameters:   Reference to the Step code data structure
  // Returns:      return code
  // Requirements: None
  // Promises:     count++;
  //               if count > threshold then
  //                  error.service_data->IsAtThreshold() == TRUE
  //                  maskId sent to error.service_data
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:        if rc != SUCCESS then state of service data is unpredictable
  //
  // End Function Specification ****************************************


private:  // functions
protected:  // Data

  uint16_t  threshold;     // dg00c
  uint16_t  count;         // dg00c
  uint32_t maskId;         // dg00c
//  Resolution * xRes;
};

inline
ThresholdResolution::ThresholdResolution(uint16_t thresholdValue, uint32_t mask_id)
: Resolution(), threshold(thresholdValue), count(0), maskId(mask_id) //, xRes(nullptr)
{}

/*
inline
ThresholdResolution::ThresholdResolution(uint16_t thresholdValue,
                                         uint32_t mask_id,
                                         Resolution & r)
: Resolution(), threshold(thresholdValue), count(0), maskId(mask_id), xRes(&r)
{}
*/
#endif // _OBSOLITE_
#endif /* iipThresholdResolution_h */

// Change Log *********************************************************
//
//  Flag Reason   Vers    Date     Coder Description
//  ---- -------- ------  -------- ----- -------------------------------
//       d49127.1 v4r1m0  05/31/96  DRG  Initial Creation
//  dg00 390545   fsp     02/26/03  dgilbert increase size of vars
//  dg01 400647   fips    03/31/03  dgilbert This part is going away (see prdfThreholdResolutions.H)
//
// End Change Log *****************************************************
