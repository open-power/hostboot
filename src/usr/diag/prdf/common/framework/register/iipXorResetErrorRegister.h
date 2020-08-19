/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipXorResetErrorRegister.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#ifndef iipXorResetErrorRegister_h
#define iipXorResetErrorRegister_h

/**
 @file iipXorResetErrorRegister.h
 @brief XorResetErrorRegister declaration
*/

// Class Description *************************************************
//
//  Name:  XorResetErrorRegister
//  Base class: ErrorRegisterMask
//
//  Description: Reset error register after analyze.  Hardware register
//               is reset by XORing value written.
//
//  Usage:  See iipResetErrorRegister.h
//
//  Implementation in iipResetErrorRegister.C
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#ifndef iipErrorRegisterMask_h
#include <iipErrorRegisterMask.h>
#endif

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

class XorResetErrorRegister : public ErrorRegisterMask
{
public:
  XorResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r,
                        ResolutionMap & rm,
                        FILTER_CLASS * f = nullptr);

  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   r: scan comm register associated with error register
  //               rm: Map of bitList to Resolutions
  //               reset: scan comm register to write reset to
  //               f: ptr to a bitList filter object
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************

  //~XorResetErrorRegister();
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

protected:  // functions

  virtual int32_t Reset(const BIT_LIST_CLASS & bit_list, STEP_CODE_DATA_STRUCT & error);
  // Function Specification ********************************************
  //
  // Purpose:      Reset the hardware & perform any other actions needed
  //               to prepare for the next Analysis
  // Parameters:   Reference to a bit list
  // Returns:      Return code
  // Requirements: None.
  // Promises:     Hardware Registers modified
  //               Bits in bit_list are turned off in SCR then SCR::Write()
  //               Mask bits set if threshold was reached (see parent class)
  // Exceptions:   None.
  // Concurrency:
  // Notes:        bit_list.GetListLength() may be zero
  //
  // End Function Specification ****************************************

private: // functions

  XorResetErrorRegister(const XorResetErrorRegister & er);  // Copy not allowed
  // Assignment not allowed
  XorResetErrorRegister & operator=(const XorResetErrorRegister & er);

private:  // Data

};


inline
XorResetErrorRegister::XorResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r,
                                       ResolutionMap & rm,
                                       FILTER_CLASS * f)
: ErrorRegisterMask(r,rm,f)
{}

} // end namespace PRDF

#endif /* iipXorResetErrorRegister_h */

