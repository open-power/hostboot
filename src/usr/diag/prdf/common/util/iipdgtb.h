/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/iipdgtb.h $                     */
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

#ifndef IIPDGTB_H
#define IIPDGTB_H

/* Module Description *************************************************/
/*                                                                    */
/*  Name:  iipdgtb.h                                                  */
/*                                                                    */
/*  Description:  This module provides the Digit String Byte class
                  declaration.                                        */
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
/* Reference the virtual function tables and inline function
   defintions in another translation unit.                            */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#include <iipdigit.h>

namespace PRDF
{
/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

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
/*  Global Variables                                                  */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Function Prototypes                                               */
/*--------------------------------------------------------------------*/

/* Class Specification ************************************************/
/*                                                                    */
/*  Name:  DIGIT_STRING_BYTE_CLASS                                    */
/*                                                                    */
/*  Title:  Byte Digit String                                         */
/*                                                                    */
/*  Purpose:  DIGIT_STRING_BYTE_CLASS provides an efficient
              representation using a byte (8 bits) for each digit in
              the string.                                             */
/*                                                                    */
/*  Usage:  This is general purpose base class.                       */
/*                                                                    */
/*  Side-effects:  Memory is allocated.                               */
/*                                                                    */
/*  Dependencies:  None.                                              */
/*                                                                    */
/*  Notes:  The Compact Digit String represents each digit in the
            string using a byte.  This limits the maximum_digit_value
            that can be represented to 255.  If an attempt is made
            to set a digit to a value greater than 255, then the
            contents and behaviour of the Digit String are undefined. */
/*                                                                    */
/*  Cardinality:  N                                                   */
/*                                                                    */
/*  Metaclass:  None.                                                 */
/*                                                                    */
/*  Space Complexity: O(m) where m is the number of digits in the
                      string.                                         */
/*                                                                    */
/* End Class Specification ********************************************/

class DIGIT_STRING_BYTE_CLASS : public DIGIT_STRING_CLASS
  {
  private:

    // Data Specification //////////////////////////////////////////////
    //
    // Purpose:  This buffer is dynamically allocated for digits.
    //
    // End Data Specification //////////////////////////////////////////

    uint8_t *                  xbuffer;

  protected:

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
    //                to the first Digit read or write.
    //
    // End Function Specification //////////////////////////////////////

    virtual void SetString
      (
         void
         /*!i No parameters                                           */
      );
         /*!o No value returned                                       */

  public:

    // Function Specification //////////////////////////////////////////
    //
    // Title:  DIGIT_STRING_BYTE_CLASS (Constructor)
    //
    // Purpose:  This function initializes the data members.
    //
    // Side-effects:  This instance is initialized.
    //                Memory is allocated.
    //
    // Dependencies:  None.
    //
    // Time Complexity:  Dominated by time complexity of SetString().
    //
    // End Function Specification //////////////////////////////////////

    DIGIT_STRING_BYTE_CLASS
      (
         uint32_t mdv,
         /*!i Maximum digit value                                     */
         uint32_t l
         /*!i String length                                           */
      ) :
         /*!o No value returned                                       */
      DIGIT_STRING_CLASS(mdv, l),
      xbuffer(nullptr)
      {
      SetString();
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

    DIGIT_STRING_BYTE_CLASS
      (
         const DIGIT_STRING_CLASS & string
         /*!i Digit String reference to copy                          */
      );
         /*!o No value returned                                       */

    // Function Specification //////////////////////////////////////////
    //
    // Title:  DIGIT_STRING_BYTE_CLASS (Copy Constructor)
    //
    // Purpose:  This function initializes the data members.  The digit
    //           string values are also copied.
    //
    // Side-effects:  This instance is initialized.
    //                Memory is allocated.
    //
    // Dependencies:  None.
    //
    // Time Complexity:  Dominated by time complexity of the functions
    //                   called.
    //
    // End Function Specification //////////////////////////////////////

    DIGIT_STRING_BYTE_CLASS
      (
         const DIGIT_STRING_BYTE_CLASS & string
         /*!i Digit String Compact reference to copy                  */
      );
         /*!o No value returned                                       */

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

    virtual ~DIGIT_STRING_BYTE_CLASS
      (
         void
         /*!i No parameters                                            */
      );
         /*!o No value returned                                       */

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Assingment operator
    //
    // Purpose:  This function assigns the data members with the values
    //           from the Digit String reference.  The digit string
    //           values are also assigned.
    //
    // Side-effects:  Data members are modified.
    //                Memory is reallocated.
    //
    // Dependencies:  All Digit String values must be less than or equal
    //                to 255.
    //
    // Time Complexity:  Dominated by time complexity of the functions
    //                   called.
    //
    // End Function Specification //////////////////////////////////////

    DIGIT_STRING_BYTE_CLASS & operator=
      (
         const DIGIT_STRING_CLASS & string
         /*!i Digit string instance to assign from                    */
      );
         /*!o Reference to this Digit String instance                 */

    DIGIT_STRING_BYTE_CLASS & operator=
      (
         const DIGIT_STRING_BYTE_CLASS & string
         /*!i Digit string instance to assign from                    */
      );

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

    virtual uint32_t GetValue
      (
         uint32_t offset
         /*!i Digit offset                                            */
      ) const;
         /*!o Digit value                                             */

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Set Value (Virtual)
    //
    // Purpose:  This function sets the value of the digit at the
    //           specified position.  No other digits are affected.
    //
    // Side-effects:  A digit in the string is modified.
    //
    // Dependencies:  Position must be in the string.
    //                Digit value must be less than or equal to 255.
    //
    // End Function Specification //////////////////////////////////////

    virtual void SetValue
      (
         uint32_t offset,
         /*!i Digit offset                                            */
         uint32_t value
         /*!i Digit value to set                                      */
      );
         /*!o No value returned                                       */

  };

} //End namespace PRDF
#endif
