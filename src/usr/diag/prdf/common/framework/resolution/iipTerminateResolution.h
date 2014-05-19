/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipTerminateResolution.h $ */
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

#ifndef iipTerminateResolution_h
#define iipTerminateResolution_h

// Class Description *************************************************
//
//  Name:  TerminateResolution
//  Base class: Resolution
//
//  Description:  This module contains the Processor Runtime
//                  Diagnostics TerminateResolution class declaration.
//                TerminateResolution provides a mechanism to terminate
//                the operation of the machine on a recovered error attention
//                after PRD exists.
//                This resolution was made to be used with other Resolutions in
//                a resolution list.
//
//  Usage:  Abstract base class
//
//   Static Globals
// TerminateResolution bringDownMachine();
// FinalResolution co(&someMruList);
// ResolutionList resolution (&co,&bringDownMachine);
//
// int32_t foo(ResolutionMap &resolutionMap)
// {
//    resolutionMap.Add(BIT_LIST_STRING_01,&resolution);
// }
// ...
// int32_t foo(STEP_CODE_DATA_STRUCT &serviceData,
//             ResolutionMap &map)
// {
//    Resolution &r = map.LookUp(BIT_LIST_STRING_01);
//    int32_t rc = r.Resolve(serviceData);  // flag the termination of machine
//    return(rc);
// }
//
// End Class Description *********************************************
/*--------------------------------------------------------------------*/

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
class TerminateResolution: public Resolution
{
public:
  TerminateResolution();
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   None
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************
  // virtual ~TerminateResolution();
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        The compiler default is sufficient
  //
  // End Function Specification ****************************************

  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & data);
  // Function Specification ********************************************
  //
  // Purpose:      Tells the ServiceDataCollector (data) that machine operation
  //               needs to be terminated.
  // Parameters:   Reference to the ServiceDataCollector
  // Returns:      Return code (rc)
  // Requirements: None
  // Promises:     data.serviceData->Terminate() == TRUE
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:        if rc != SUCCESS then state of service data is unpredictable
  //
  // End Function Specification ****************************************


  // Copy ctor   - compiler default is sufficient
  // Assignment  - compiler default is sufficient

private:  // functions
private:  // Data


};

inline
TerminateResolution::TerminateResolution(): Resolution() {}

} // end namespace PRDF

#endif /* iipResolution_h */

