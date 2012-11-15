/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfIntervalThresholdResolution.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef prdfIntervalThresholdResolution_H
#define prdfIntervalThresholdResolution_H

/**
 @file prdfIntervalThresholdResolution.H
 @brief Common PRD IntervalThresholdResolution class declairation
*/

// Class Description *************************************************
//
//  Name:  IntervalThresholdResolution
//  Base class: Resolution
//
//  Description: Resolution that has a threshold and keeps track of how
//               many times its called within an interval of time.
//             . When the threshold is reached within that time, it
//               tells the service data collector and sends it a mask id,
//               then resets the threshold count to 0. If the threshold
//               is not reached within the specified interval, the
//               interval is reset with the count at 1.
//  Usage:
//
//  MruCallout callout[] = {PU0};
//  enum { thresholdValue = 32, MaskId = 05 , Minutes = 60 };
//  Time intervalValue = 5 * Minutes;  // Length set to 5 minutes
//  IntervalThresholdResolution itr(thresholdValue,intervalValue,MaskId);
//  FinalResolution fr(callout,1);
//  ResolutionList rl(&itr,&fr);
//  ResolutionMap rm(...);
//  rm.Add(BIT_LIST_STRING_05,&rl);   // Resolution invoked when bit 5
//                                       is on - callsout callout and
//                                       thresholds at thresholdValue
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <prdfThresholdResolutions.H>
#warning this is an obsolite part

#if defined(_OBSOLITE_)

#if !defined(Resolution_h)
 #include <iipThresholdResolution.h>
#endif

#if !defined(PRDFTIMER_H)
 #include <prdfTimer.H>
#endif
//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

class IntervalThresholdResolution : public ThresholdResolution
{
public:
  /**
   Constructor
   @param thresholdValue at which threshold is reached
   @param intervalValue length of time window (in seconds)
   @param mask_id value given to the service data at threshold
   @return nothing
   @pre None
   @post Object created
   */
  IntervalThresholdResolution(uint16_t thresholdValue, uint32_t intervalLengthValue, uint32_t mask_id);

  /**
   Constructor
   @param thresholdValue at which threshold is reached
   @param intervalValue length of time window (in seconds)
   @param mask_id value given to the service data at threshold
   @param Resolution to call from this one.
   @return nothing
   @pre None
   @post Object created
   */
//   IntervalThresholdResolution(uint16_t thresholdValue, uint32_t intervalLengthValue, uint32_t mask_id,
//                              Resolution & r);

  // ~IntervalThresholdResolution();
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

  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);
  // Function Specification ********************************************
  //
  // Purpose:      Resolve service data for a specific error bit
  // Parameters:   Reference to the Step code data structure
  // Returns:      return code
  // Requirements: None
  // Promises:     count++;
  //               if currentTime is past intervalEndTime then
  //                  count = 1
  //                  new intervalEndTime calculated based on currentTime
  //               else if count == threshold then
  //                  error.service_data->IsAtThreshold() == TRUE
  //                  maskId sent to error.service_data
  //                  count = 0
  //               else; // count still remains incremented
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:        if rc != SUCCESS then state of service data is unpredictable
  //
  // End Function Specification ****************************************


private:  // functions
private:  // Data

//  uint8_t    threshold; // moved to base class
//  uint8_t    count;
//  uint16_t   maskId;
  uint32_t   intervalLength;
  PrdTimer intervalEndTime;
//  Resolution * xRes;
};

inline
IntervalThresholdResolution::IntervalThresholdResolution(uint16_t thresholdValue,
                                                         uint32_t intervalLengthValue,
                                                         uint32_t mask_id)
: ThresholdResolution(thresholdValue,mask_id),  intervalLength(intervalLengthValue), intervalEndTime()
{}

/*
inline
IntervalThresholdResolution::IntervalThresholdResolution(uint16_t thresholdValue,
                                                         uint32_t intervalLengthValue,
                                                         uint32_t mask_id,
                                                         Resolution & r)
: ThresholdResolution(thresholdValue,mask_id,r), intervalLength(intervalLengthValue), intervalEndTime()
{}
*/
#endif // _OBSOLITE_
#endif /* prdfIntervalThresholdResolution_h */

// Change Log *********************************************************
//
//  Flag Reason   Vers    Date     Coder Description
//  ---- -------- ------  -------- ----- -------------------------------
//       ft637.1  csp     02/28/02  RAC  Initial Creation
//       368019   fsp     09/03/02 dgilbert port to FSP
//       390545   fsp     02/26/03 dgilbert inherrit from TresholdResolution
//
// End Change Log *****************************************************


/***************** END File prdfIntervalThresholdResolution.h
*********************************************************************/
/********************************************************************/
