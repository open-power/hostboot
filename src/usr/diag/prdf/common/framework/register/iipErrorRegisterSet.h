/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipErrorRegisterSet.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 1997,2020                        */
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

#ifndef iipErrorRegisterSet_h
#define iipErrorRegisterSet_h

// Class Description *************************************************
//
//  Name:  ErrorRegisterSet
//  Base class: ErrorRegisterMask
//
//  Description: To be used when the bits on in the error register
//               represent a set of errors reported and the error
//               analysis is to a union of the Resolutions
//               for each error bit.
//
//  Usage: See iipErrorRegister.h
//
//  Warning:
//   If this class is used with recoverable errors then all bits on are
//   masked when ANY threshold is detected, therefore the chip should
//   mask the hardware accordingly.
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipErrorRegisterMask_h)
#include <iipErrorRegisterMask.h>
#endif

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

class ErrorRegisterSet: public ErrorRegisterMask
{
public:
  ErrorRegisterSet(SCAN_COMM_REGISTER_CLASS & r,
                   ResolutionMap & rm,
                   FILTER_CLASS * f = nullptr);
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

  //~ErrorRegisterSet();
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:
  //
  // End Function Specification ****************************************

  virtual int32_t Analyze(STEP_CODE_DATA_STRUCT & error);
  // Function Specification ********************************************
  //
  // Purpose:      Analyze the error(s) reported by this error register
  // Parameters:   Reference to area to return Service Data
  // Returns:      Return code
  // Requirements: None.
  // Promises:     At least one Resolution called (See notes)
  //               Service data error signature scrid and error code modified
  //               if register has no bits on then
  //                  rc = PRD_SCAN_COMM_REGISTER_ZERO (iipconst.h)
  //               If rc != SUCCESS then no promises
  // Exceptions:   Simulator may throw TBD otherwise none.
  // Concurrency:
  // Notes:
  //                A Resolution called for Each bit that's on in the error
  //                register.
  //                If no resolutions exist for a bit then the
  //                ResolutionMap default Resolution is Called.
  //
  // End Function Specification ****************************************
private:  // functions
private:  // Data

};

} // end namespace PRDF

#endif /* iipErrorRegisterSet_h */

