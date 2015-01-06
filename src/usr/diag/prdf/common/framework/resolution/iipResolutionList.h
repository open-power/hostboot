/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipResolutionList.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

#ifndef iipResolutionList_h
#define iipResolutionList_h

// Class Description *************************************************
//
//  Name:  ResolutionList
//  Base class: Resolution
//
//  Description: A Resolution whose Resolve function calls the Resolve
//               function on each Resolution in a List of Resolutions.
//  Usage:
//
//  MruCallout calloutList[] = {PU0,PU1};
//  FinalResolution  r1(calloutList,2);
//  CaptureResolution r2(someScanCommRegister);
//
//  ResolutionList rl(&r1,&r2);     // up to 4 resolutions
//
//  ResolutionMap rm(...);  // see iipResolutionMap.h
//  rm.Add(BIT_LIST_STRING_01,&rl);  // When bit 1 is on perform r1 and r2
//
// End Class Description *********************************************
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

#include <vector>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

class ResolutionList : public Resolution
{
public:
  ResolutionList(Resolution * r1,Resolution * r2);
  ResolutionList(Resolution * r1,Resolution * r2,Resolution * r3);
  ResolutionList(Resolution * r1,Resolution * r2,Resolution * r3,Resolution * r4);
  ResolutionList(Resolution * r1,Resolution * r2,Resolution * r3,
                 Resolution * r4,Resolution * r5);
  ResolutionList(Resolution * r1,Resolution * r2,Resolution * r3,
                 Resolution * r4,Resolution * r5,Resolution * r6);
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   r1 - r4: 2-4 Resolutions to perform as one resolution
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************

  //~ResolutionList();
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        Compiler default is ok
  //
  // End Function Specification ****************************************

  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);
  // Function Specification ********************************************
  //
  // Purpose:      Resolve service data for a specific error bit (Pure Virtual)
  // Parameters:   Reference to the Step code data structure
  // Returns:      return code
  // Requirements: None
  // Promises:     if rc = SUCCESS then data filled with appropriate service
  //               data
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:        if rc != SUCCESS then state of service data is unpredictable
  //
  // End Function Specification ****************************************

private:  // functions

  ResolutionList(const ResolutionList &rl);  // not allowed
  ResolutionList & operator=(const ResolutionList &rl); // not allowed

private:  // Data

  std::vector<void *> resolutionList;  // use void * to reduce template code bloat

};

inline
ResolutionList::ResolutionList(Resolution * r1,Resolution * r2)
{
  resolutionList.reserve(2);
  resolutionList.push_back(r1);
  resolutionList.push_back(r2);
}

inline
ResolutionList::ResolutionList(Resolution * r1,Resolution * r2,Resolution * r3)
{
  resolutionList.reserve(3);
  resolutionList.push_back(r1);
  resolutionList.push_back(r2);
  resolutionList.push_back(r3);
}

inline
ResolutionList::ResolutionList(Resolution * r1,Resolution * r2,
                               Resolution * r3,Resolution * r4)
{
  resolutionList.reserve(4);
  resolutionList.push_back(r1);
  resolutionList.push_back(r2);
  resolutionList.push_back(r3);
  resolutionList.push_back(r4);
}

inline
ResolutionList::ResolutionList(Resolution * r1,Resolution * r2,
                               Resolution * r3,Resolution * r4,
                               Resolution * r5)
{
  resolutionList.reserve(5);
  resolutionList.push_back(r1);
  resolutionList.push_back(r2);
  resolutionList.push_back(r3);
  resolutionList.push_back(r4);
  resolutionList.push_back(r5);
}

inline
ResolutionList::ResolutionList(Resolution * r1,Resolution * r2,
                               Resolution * r3,Resolution * r4,
                               Resolution * r5,Resolution * r6)
{
  resolutionList.reserve(6);
  resolutionList.push_back(r1);
  resolutionList.push_back(r2);
  resolutionList.push_back(r3);
  resolutionList.push_back(r4);
  resolutionList.push_back(r5);
  resolutionList.push_back(r6);
}

} // end namespace PRDF

#endif /* iipResolutionList_h */

