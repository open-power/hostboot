/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipCalloutResolution.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1998,2014              */
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

#ifndef iipCalloutResolution_h
#define iipCalloutResolution_h

// Class Description *************************************************
//
//  Name:  CalloutResolution
//  Base class: Resolution
//
//  Description: Resolution makes a MRU Callout.
//
//  Usage:
//
//
//  CalloutResolution  r1(PU0,MRU_MED);
//  ResolutionMap rm(....)    // see iipResolutionMap.h
//  rm.Add(BIT_LIST_STRING_31,&r1);  // if bit 31 is on callout PU0 HIGH as
//                                   // the failing item
//
//  ...
//
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <prdfCallouts.H>
#include <iipResolution.h>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

/**
 A resolution that adds a MRU callout to the service data collector
 @version V4R5
 @author Douglas R. Gilbert
*/

class CalloutResolution: public Resolution
{
public:

  /**
   CTOR
   <ul>
   <br><b>Parameters:  </b> a MruValues, a PriorityValues (see xspiiCallout.h)
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  CalloutResolution(PRDcallout callout, PRDpriority priority);
  CalloutResolution(void);    // default
  CalloutResolution(const CalloutResolution & cr);

  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        Compiler default is sufficient
  //
  // End Function Specification ****************************************
  //~CalloutResolution();

  /**
   Resolve by adding a the MRU callout to the service data collector
   <ul>
   <br><b>Parameters:  </b> ServiceDataCollector
   <br><b>Returns:     </b> Return code [SUCCESS | nonZero]
   <br><b>Requirements:</b> none.
   <br><b>Promises:    </b> serviceData::GetMruList().GetCount()++
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);

  // dg00 start
  virtual bool operator==(const Resolution & r) const
  {
    return r.operator==(*this);  // compare whatever r is with this
  }

  virtual bool operator==(const CalloutResolution & r) const
  {
    return((xMruCallout == r.xMruCallout) && (xPriority == r.xPriority));
  }

//  friend int operator==(const CalloutResolution& a, const CalloutResolution& b)
//  {
//    return((a.xMruCallout == b.xMruCallout) && (a.xPriority == b.xPriority));
//  }
  // dg00 end

private:  // functions
private:  // Data

 PRDcallout xMruCallout;
 PRDpriority xPriority;

};


inline
CalloutResolution::CalloutResolution(PRDcallout callout,
                                     PRDpriority priority)
: xMruCallout(callout), xPriority(priority)
{}

inline
CalloutResolution::CalloutResolution() :
    xMruCallout(NULL), xPriority(MRU_MED)
{}

inline
CalloutResolution::CalloutResolution(const CalloutResolution & cr)
: xMruCallout(cr.xMruCallout), xPriority(cr.xPriority)
{}

} // end namespace PRDF

#endif /* iipCalloutResolution_h */
