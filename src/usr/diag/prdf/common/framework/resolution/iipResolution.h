/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipResolution.h $ */
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

#ifndef iipResolution_h
#define iipResolution_h

// Class Description *************************************************
//
//  Name:  Resolution
//  Base class: None
//
//  Description:  This module contains the Processor Runtime
//                  Diagnostics Resolution class declaration.
//                Resolution provides a mechansim to resolve a
//                hardware error and provide service data
//
//  Usage:  Abstract base class
//
//  int32_t foo(STEP_CODE_DATA_STRUCT &serviceData,
//             ResolutionMap &map)
//  {
//    Resolution &r = map.LookUp(BIT_LIST_STRING_21);
//    int32_t rc = r.Resolve(serviceData);
//    return(rc);
//  }
//
// End Class Description *********************************************
/*--------------------------------------------------------------------*/
/* Reference the virtual function tables and inline function
   defintions in another translation unit.                            */
/*--------------------------------------------------------------------*/

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <prdf_types.h>
#include <iipstep.h>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------


class Resolution
{
public:

  /**
   Destructor
   @pre None
   @post None
   @note This destructor does nothing.  This definitions
         would have the same effect as the compiler generated
         default destructor.  It is declared virtual so that
         derived classes will be destructed properly.
   */
  virtual ~Resolution();

  /**
   * @brief     Resolve the service data for this error syndrome
   * @param[io] io_data Reference to STEP_CODE_DATA_STRUCT
   * @return    SUCCESS | non-zero
   */
  virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_data ) = 0;
  // Function Specification ********************************************
  //
  // Purpose:      Resolve service data for a specific error bit (Pure Virtual)
  // Parameters:   Reference to the Step code data structure
  // Returns:      return code
  // Requirements: None
  // Promises:     if rc = SUCCESS then data filled with apropriate service data
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:        if rc != SUCCESS then state of service data is unpredictable
  //
  // End Function Specification ****************************************


  // Copy ctor   - compiler default is sufficient
  // Assignment  - compiler default is sufficient

  // dg00 start
  /**
   Comparison
   <ul>
   <br><b>Parameters:  </b> A Resolution
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Each derived class that supports comparison must be listed
   here.
   </ul><br>
   */
  virtual bool operator==(const Resolution & r) const
  { return false; }  // default

protected:

  Resolution() {}
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   Pointer to charater string bit list encoding (opt)
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************

private:  // functions
private:  // Data


};

} // end namespace PRDF

#endif /* iipResolution_h */

