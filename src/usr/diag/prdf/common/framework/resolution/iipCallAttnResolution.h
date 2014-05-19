/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipCallAttnResolution.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1997,2014              */
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

#ifndef iipCallAttnResolution_h
#define iipCallAttnResolution_h

// Class Description *************************************************
//
//  Name:  CallAttnResolution
//  Base class: Resolution
//
//  Description: A resolution to call all chips raising attention
//  Usage:  See iipResolution.h
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
//class CalloutMap;

class CallAttnResolution : public Resolution
{
public:
//  CallAttnResolution(CalloutMap & callmap);
  CallAttnResolution() {}
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   Object that maps chipId's to Callouts
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************

  // ~CallAttnResolution();
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes: Compiler default defn is sufficent
  //
  // End Function Specification ****************************************

  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);
  // Function Specification ********************************************
  //
  // Purpose:      Resolve service data - callout all chips at attention as
  //               reported by the service processor sysdebug area.
  // Parameters:   Reference to the Step code data structure
  // Returns:      return code
  // Requirements: None
  // Promises:     if rc = SUCCESS then
  //                   ServiceData signature set, Callout list modified
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:        if rc != SUCCESS then state of service data is unpredictable
  //
  // End Function Specification ****************************************
private:  // functions
private:  // Data

//  CalloutMap & calloutMap;

};

//inline
//CallAttnResolution::CallAttnResolution(CalloutMap & callmap)
//: calloutMap(callmap)
//{
//}

} // end namespace PRDF

#endif /* iipCallAttnResolution_h */

