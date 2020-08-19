/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipEregResolution.h $ */
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

#ifndef iipEregResolution_h
#define iipEregResolution_h

// Class Description *************************************************
//
//  Name:  EregResolution     concrete class
//  Base class: Resolution
//
//  Description: Resolve an error by analyzing an error register
//  Usage:
//
//    ResolutionMap ereg1Resolutions(...);
//    ErrorRegister ereg1(....);
//    ErrorRegister ereg2(....);
//
//    Resolution *r = new EregResolution(ereg2);
//    ereg1Resolutions.add(BIT_LIST_STRING_20,r); // If bit 20 of ereg1 on then
//                                                // Resolution = ereg2.Analyze();
//
//
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
class ErrorRegisterType;

class EregResolution : public Resolution
{
  public:
  EregResolution();
  EregResolution(ErrorRegisterType & er);
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   ErrorRegister object to be invoked by Resolve()
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************

  // ~EregResolution();
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
  // Copy ctor   - compiler default is sufficient
  // Assignment  - compiler default is sufficient

    virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & data,
                            bool i_default = false);
  // Function Specification ********************************************
  //
  // Purpose:
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        Compiler default is sufficient
  //
  // End Function Specification ****************************************

  private:  // functions
  private:  // Data

    ErrorRegisterType * errorRegister;

};

inline
EregResolution::EregResolution(ErrorRegisterType &er)
: errorRegister(&er) {}

inline
EregResolution::EregResolution()
  : errorRegister(nullptr) {}

} // end namespace PRDF

#endif /* iipEregResolution_h */

