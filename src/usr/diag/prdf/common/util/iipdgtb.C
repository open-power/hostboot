/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/iipdgtb.C $                     */
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

#define IIPDGTB_CPP

/* Module Description *************************************************/
/*                                                                    */
/*  Name:  iipdgtb.cpp                                                */
/*                                                                    */
/*  Description:  This module provides the Digit String Byte class
                  implementation.                                     */
/*                                                                    */
/* End Module Description *********************************************/

/* Change Log *********************************************************/
/*                                                                    */
/*  Flag  PTR/DCR#  Userid    Date      Description                   */
/*  ----  --------  --------  --------  -----------                   */
/*                  JST       10/20/93  Initial Creation              */
/*                                                                    */
/* End Change Log *****************************************************/

/*--------------------------------------------------------------------*/
/* Emit the virtual function tables and inline function defintions in
   this translation unit.                                             */
/*--------------------------------------------------------------------*/
#ifdef __GNUC__
#endif

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#include <string.h> // for memcpy
#include <iipdgtb.h>

namespace PRDF
{

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Constants                                                         */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Macros                                                            */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Internal Function Prototypes                                      */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Global Variables                                                  */
/*--------------------------------------------------------------------*/

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Set String (Virtual)
    //
    // Purpose:  This function allocates memory for the string
    //           representation.  Any memory that has been previously
    //           allocated is deallocated.
    //
    // Side-effects:  Memory is allocated.
    //
    // Dependencies:  This function must be called at least once prior
    //                to the first DIgit read or write.
    //
    // End Function Specification //////////////////////////////////////

void DIGIT_STRING_BYTE_CLASS::SetString
  (
     void
     /*!i No parameters                                               */
  )
     /*!o No value returned                                           */
  {
  delete [] xbuffer;
  xbuffer = new uint8_t[GetLength()];
  }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  DIGIT_STRING_BYTE_CLASS (Base Class Copy Constructor)
    //
    // Purpose:  This function initializes the data members.  The digit
    //           string values are also copied.
    //
    // Side-effects:  This instance is initialized.
    //                Memory is allocated.
    //
    // Dependencies:  All Digit String values must be less than or equal
    //                to 255.
    //
    // Time Complexity:  Dominated by time complexity of the functions
    //                   called.
    //
    // End Function Specification //////////////////////////////////////

DIGIT_STRING_BYTE_CLASS::DIGIT_STRING_BYTE_CLASS
  (
     const DIGIT_STRING_CLASS & string
     /*!i Digit String instance to copy                               */
  ) :
     /*!o No value returned                                           */
  DIGIT_STRING_CLASS(string),
  xbuffer(nullptr)
  {
  SetString();
  SetValues(string);
  }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  DIGIT_STRING_BYTE_CLASS (Copy Constructor)
    //
    // Purpose:  This function initializes the data members.  The digit
    //           string values are also copied.
    //
    // Side-effects:  This instance is initialized.
    //
    // Dependencies:  None.
    //
    // Time Complexity:  0(m) where m is the length of the string being
    //                   copied.
    //
    // End Function Specification //////////////////////////////////////

DIGIT_STRING_BYTE_CLASS::DIGIT_STRING_BYTE_CLASS
  (
     const DIGIT_STRING_BYTE_CLASS & string
     /*!i Digit String instance to copy                               */
  ) :
     /*!o Reference to this Digit String instance                     */
  DIGIT_STRING_CLASS(string),
  xbuffer(nullptr)
  {
  SetString();

  // Use direct copy of buffer since the lengths are equal
  memcpy(xbuffer, string.xbuffer, GetLength());
  }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  ~DIGIT_STRING_BYTE_CLASS (Virtual destructor)
    //
    // Purpose:  This function deallocates the digit string
    //           representation.
    //
    // Side-effects:  Memory is deallocated.
    //
    // Dependencies:  None.
    //
    // End Function Specification //////////////////////////////////////

DIGIT_STRING_BYTE_CLASS::~DIGIT_STRING_BYTE_CLASS
  (
     void
     /*!i No parameters                                                */
  )
     /*!o No value returned                                           */
  {
  delete [] xbuffer;
  }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Assingment operator
    //
    // Purpose:  This function assigns the data members with the values
    //           from the Digit String reference.  The digit string
    //           values are also assigned.
    //
    // Side-effects:  Data members are modified.
    //
    // Dependencies:  None.
    //
    // Time Complexity:  Dominated by time complexity of the functions
    //                   called.
    //
    // End Function Specification //////////////////////////////////////

DIGIT_STRING_BYTE_CLASS & DIGIT_STRING_BYTE_CLASS::operator=
  (
     const DIGIT_STRING_CLASS & string
     /*!i Digit string instance to assign from                        */
  )
     /*!o Reference to this Digit String instance                     */
  {
  // Check for assignment to self
  if(this != &string)
    {
    // Assign the base class part
    DIGIT_STRING_CLASS::operator=(string);

    // Assign the derived class part
    SetString();
    SetValues(string);
    }

  return(*this);
  }

DIGIT_STRING_BYTE_CLASS & DIGIT_STRING_BYTE_CLASS::operator=
  (
     const DIGIT_STRING_BYTE_CLASS & string
     /*!i Digit string instance to assign from                        */
  )
     /*!o Reference to this Digit String instance                     */
  {
  // Check for assignment to self
  if(this != &string)
    {
    // Assign the base class part
    DIGIT_STRING_CLASS::operator=(string);

    // Assign the derived class part
    SetString();
    SetValues(string);
    }

  return(*this);
  }
    // Function Specification //////////////////////////////////////////
    //
    // Title:  Get Value (Virtual)
    //
    // Purpose:  This function returns the value of a digit at the
    //           specified position.
    //
    // Side-effects:  None.
    //
    // Dependencies:  Position must be in the string.
    //
    // End Function Specification //////////////////////////////////////

uint32_t DIGIT_STRING_BYTE_CLASS::GetValue
  (
     uint32_t offset
     /*!i Digit offset                                                */
  ) const
     /*!o Digit value                                                 */
  {
  return(xbuffer[offset]);
  }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Set Value (Pure virtual)
    //
    // Purpose:  This function sets the value of the digit at the
    //           specified position.  No other digits are affected.
    //
    // Side-effects:  A digit in the string is modified.
    //
    // Dependencies:  Position must be in the string.
    //
    // End Function Specification //////////////////////////////////////

void DIGIT_STRING_BYTE_CLASS::SetValue
  (
     uint32_t offset,
     /*!i Digit offset                                                */
     uint32_t value
     /*!i Digit value to set                                          */
  )
     /*!o No value returned                                           */
  {
  xbuffer[offset] = value;
  }

} // end namespace PRDF

#undef IIPDGTB_CPP
