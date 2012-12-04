/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/iipdigit.h $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1993,2013              */
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

#ifndef IIPDIGIT_H
#define IIPDIGIT_H

/* Module Description *************************************************/
/*                                                                    */
/*  Name:  iipdigit.h                                                 */
/*                                                                    */
/*  Description:  This module provides the Digit String class
                  hierarchy definition.                               */
/*                                                                    */
/* End Module Description *********************************************/

/* Change Log *********************************************************/
/*                                                                    */
/*  Flag  PTR/DCR#  Userid    Date      Description                   */
/*  ----  --------  --------  --------  -----------                   */
/*                  JST       06/04/93  Initial Creation              */
/*        D24694.3  JST       06/13/94  I1 Review changes             */
/*                                                                    */
/* End Change Log *****************************************************/

/*--------------------------------------------------------------------*/
/* Reference the virtual function tables and inline function
   defintions in another translation unit.                            */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#include <prdf_types.h>
namespace PRDF
{
/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

// Type Specification //////////////////////////////////////////////////
//
// Title:  CPU_WORD
//
// Purpose:  This type is used to take advantage of the most efficient
//           memory reference size for a specific CPU architecture.
//           This type defintion is provided only to handle the case
//           where no previous defintions exists.
//
// End Type Specification //////////////////////////////////////////////

#ifndef CPU_WORD

typedef uint32_t CPU_WORD;

#endif

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
/*  Name:  DIGIT_STRING_CLASS                                         */
/*                                                                    */
/*  Title:  Digit String                                              */
/*                                                                    */
/*  Purpose:  DIGIT_STRING_CLASS provides the representation and
              access to a sequence of digits in a specified range.    */
/*                                                                    */
/*  Usage:  This is an abstract base class.                           */
/*                                                                    */
/*  Side-effects:  None.                                              */
/*                                                                    */
/*  Dependencies:  Access operations must specify position less than
                   the length.                                        */
/*                                                                    */
/*  Notes:  The Digit String maintains a sequence of digits in the
            range of 0 to maximum_digit_value.  If a value that is
            being written is is larger than the maximum_digit_value,
            then the digit is set to the maximum_digit_value.  A
            length of 0 is allowed, but no digits can be accessed.  If
            length is greater than 0, then the Digit positions are
            specified 0 to (length - 1) from left to right.

            0 1 2 3 .... (length - 1)

            D D D D ....      D                                       */
/*                                                                    */
/*  Cardinality:  0                                                   */
/*                                                                    */
/*  Space Complexity:  Constant                                       */
/*                                                                    */
/* End Class Specification ********************************************/

class DIGIT_STRING_CLASS
  {
  public:

    // Function Specification //////////////////////////////////////////
    //
    // Title:  ~DIGIT_STRING_CLASS (Virtual destructor)
    //
    // Purpose:  This function performs no special action.
    //
    // Side-effects:  This instance is no longer valid.
    //
    // Dependencies:  None.
    //
    // Notes:  This function performs the same action as a default
    //         defintion.  It is included because the virtual
    //         declaration is required for this base class.
    //
    // End Function Specification //////////////////////////////////////

    virtual ~DIGIT_STRING_CLASS
      (
         void
         /*!i No paramters                                            */
      )
         /*!o No value returned                                       */
      {
      }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Assingment operator
    //
    // Purpose:  This function assigns the data members with the values
    //           from the Digit String reference.
    //
    // Side-effects:  Data members are modified.
    //
    // Dependencies:  None.
    //
    // Notes:  This function performs the same action as a default
    //         defintion.  It is included here to emphasize the actions
    //         performed and the need for an explicit definition in each
    //         derived class.
    //
    // End Function Specification //////////////////////////////////////

    DIGIT_STRING_CLASS & operator=
      (
         const DIGIT_STRING_CLASS & string
         /*!i Digit string instance to assign from                    */
      )
         /*!o Reference to this Digit String instance                 */
      {
      // No check for assignment to self is required

      maximum_digit_value = string.maximum_digit_value;
      length = string.length;

      return(*this);
      }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Get Value (Pure virtual)
    //
    // Purpose:  This function returns the value of a digit at the
    //           specified position.
    //
    // Side-effects:  None.
    //
    // Dependencies:  Position must be in the string.
    //
    // Notes:  This function has no definition.
    //
    // End Function Specification //////////////////////////////////////

    virtual uint32_t GetValue
      (
         uint32_t position
         /*!i Digit position                                          */
      ) const = 0;
         /*!o Digit value                                             */

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
    // Notes:  This function has no definition.
    //
    // End Function Specification //////////////////////////////////////

    virtual void SetValue
      (
         uint32_t position,
         /*!i Digit position                                          */
         uint32_t value
         /*!i Digit value to set                                      */
      ) = 0;
         /*!o No value returned                                       */

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

    void Fill
      (
         uint32_t value
         /*!i Digit value for each position                           */
      );
         /*!o No value returned                                       */

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

    bool operator==
      (
         const DIGIT_STRING_CLASS & string
         /*!i Digit string instance to compare                        */
      ) const;
         /*!o Non-zero if digit strings are equal, otherwise zero     */

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Get Maximum Digit Value
    //
    // Purpose:  This function returns the maximum digit value.
    //
    // Side-effects:  None.
    //
    // Dependencies:  None.
    //
    // End Function Specification //////////////////////////////////////

    uint32_t GetMaximumDigitValue
      (
         void
         /*!i No parameters                                           */
      ) const
         /*!o Maximum allowable digit value in the string             */
      {
      return(maximum_digit_value);
      }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  Get Length
    //
    // Purpose:  This function returns the length.
    //
    // Side-effects:  None.
    //
    // Dependencies:  None.
    //
    // End Function Specification //////////////////////////////////////

    uint32_t GetLength
      (
         void
         /*!i No parameters                                           */
      ) const
         /*!o Digit string length                                     */
      {
      return(length);
      }

  protected:

    // Function Specification //////////////////////////////////////////
    //
    // Title:  DIGIT_STRING_CLASS (Constructor)
    //
    // Purpose:  This function initializes the data members.
    //
    // Side-effects:  This instance is initialized.
    //
    // Dependencies:  None.
    //
    // End Function Specification //////////////////////////////////////

    DIGIT_STRING_CLASS
      (
         uint32_t mdv,
         /*!i Maximum digit value                                     */
         uint32_t le
         /*!i Digit length                                            */
      ) :
         /*!o No value returned                                       */
      maximum_digit_value(mdv),
      length(le)
      {
      }

    // Function Specification //////////////////////////////////////////
    //
    // Title:  DIGIT_STRING_CLASS (Copy constructor)
    //
    // Purpose:  This function initializes the data members from the
    //           Digit String reference.
    //
    // Side-effects:  This instance is initialized.
    //
    // Dependencies:  None.
    //
    // Notes:  This function performs the same action as a default
    //         defintion.  It is included here to emphasize the actions
    //         performed and the need for an explicit definition in each
    //         derived class.
    //
    // End Function Specification //////////////////////////////////////

    DIGIT_STRING_CLASS
      (
         const DIGIT_STRING_CLASS & string
         /*!i Digit string reference to copy                          */
      ) :
         /*!o No value returned                                       */
      maximum_digit_value(string.maximum_digit_value),
      length(string.length)
      {
      }

    // Function Specification ///////////////////////////////////////////
    //
    // Title:  Set String (Pure virtual)
    //
    // Purpose:  This function performs any required representation
    //           actions.
    //
    // Side-effects:  The Digit String is valid.
    //
    // Dependencies:  This function must be called at least once prior
    //                to the first DIgit read or write.
    //
    // Notes:  This function has no definition.
    //
    // End Function Specification //////////////////////////////////////

    virtual void SetString
      (
         void
         /*!i No parameters                                           */
      ) = 0;
         /*!o No value returned                                       */

    // Function Specification ///////////////////////////////////////////
    //
    // Title:  Set String
    //
    // Purpose:  This function assigns the data members and calls
    //           SetString() to perform any required representation
    //           actions.
    //
    // Side-effects:  The Digit String is valid.
    //
    // Dependencies:  None.
    //
    // End Function Specification //////////////////////////////////////

    void SetString
      (
         uint32_t mdv,
         /*!i Maximum digit value                                     */
         uint32_t le
         /*!i Digit length                                            */
      )
         /*!o No value returned                                       */
      {
      maximum_digit_value = mdv;
      length = le;

      SetString();
      }

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

    virtual void SetValues
      (
         const DIGIT_STRING_CLASS & string
         /*!i Reference to Digit string set set values from           */
      );
         /*!o No value returned                                       */

  private:

    // Data Specification //////////////////////////////////////////////
    //
    // Purpose:  This data is used to maintain the Digit String.
    //
    // End Data Specification //////////////////////////////////////////

    uint32_t                      maximum_digit_value;
    uint32_t                      length;

  };

} //End namespace PRDF
#endif
