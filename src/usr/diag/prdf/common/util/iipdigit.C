/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/iipdigit.C $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1993,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#define IIPDIGIT_CPP

/* Module Description *************************************************/
/*                                                                    */
/*  Name:  iipdigit.cpp                                               */
/*                                                                    */
/*  Description:  This module provides the Digit String class
                  implementation.                                     */
/*                                                                    */
/* End Module Description *********************************************/

/* Change Log *********************************************************/
/*                                                                    */
/*  Flag  PTR/DCR#  Userid    Date      Description                   */
/*  ----  --------  --------  --------  -----------                   */
/*                  JST       06/07/93  Initial Creation              */
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

#include <iipdigit.h>

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
    // Title:  Set Values
    //
    // Purpose:  This function sets the values of the string at
    //                 corresponding positions.  If one of the Digit Strings
    //                 is larger, than the extra digits are ignored.  If a
    //                 value from the string is larger than the
    //                 maximum_digit_value, then the digit is set to the
    //                 maximum_digit_value.
    //
    // Side-effects:  Digits in string are modified.
    //
    // Dependencies:  None.
    //
    // Time Complexity:  O(m) where m is the length
    //
    // End Function Specification //////////////////////////////////////

void DIGIT_STRING_CLASS::SetValues
  (
     const DIGIT_STRING_CLASS & string
     /*!i Reference to Digit string set set values from               */
  )
     /*!o No value returned                                           */
  {
  for(unsigned int i = 0;i < length;i++)
    {
    if(i < string.length)
      {
      SetValue(i, string.GetValue(i));
      }
    }
  }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Fill
    //
    // Purpose:  This function sets the value of each digit in the
    //           string with the same specified value.
    //
    // Side-effects:  All digits in the string is modified.
    //
    // Dependencies:  None.
    //
    // Time Complexity:  O(m) where m is the length
    //
    // End Function Specification //////////////////////////////////////

void DIGIT_STRING_CLASS::Fill
  (
     uint32_t value
     /*!i Digit value for each position                               */
  )
     /*!o No value returned                                           */
  {
  for(unsigned int i = 0;i < length;i++)
    {
    SetValue(i, value);
    }
  }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Equality operator
    //
    // Purpose:  This function determines if the specified string is
    //           equal two this one.  If the lengths are equal and the
    //           corresponding values at every position are equal, then
    //           the Digit strings are equal.
    //
    // Side-effects:  None.
    //
    // Dependencies:  None.
    //
    // Time Complexity:  O(m) where m is the length
    //
    // End Function Specification //////////////////////////////////////

bool DIGIT_STRING_CLASS::operator==
(
 const DIGIT_STRING_CLASS & string
 /*!i Digit string instance to compare                            */
 ) const
/*!o Non-zero if digit strings are equal, otherwise zero         */
{
  bool rc = (length == string.length);

  if(rc)
  {
    for(unsigned int i = 0;i < length;i++)
    {
      if(GetValue(i) != string.GetValue(i))
      {
        rc = false;
        break;
      }
    }
  }

  return(rc);
}

} //End namespace PRDF
#undef IIPDIGIT_CPP
