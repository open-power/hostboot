/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipscr.C $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1997,2012              */
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

#define IIPSCR_C

/* Module Description *************************************************/
/*                                                                    */
/*  Description:  This module contains the implementation for the     */
/*   Processor Runtime Diagnostics Scan Communication                 */
/*   Register class.                                                  */
/*                                                                    */
/*  Notes:  Unless stated otherwise, assume that each function        */
/*   specification has no side-effects, no dependencies, and          */
/*   constant time complexity.                                        */
/*                                                                    */
/* End Module Description *********************************************/

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#include <iipbits.h>
#include <iipscr.h>
#include <iipconst.h>

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

/*--------------------------------------------------------------------*/
/*  Static Variables                                                  */
/*--------------------------------------------------------------------*/

// Function Specification //////////////////////////////////////////
//
// Title:  ~SCAN_COMM_REGISTER_CLASS (Virtual destructor)
//
// Purpose:  This destructor deallocates the Bit String.
//
// Side-effects:  Memory is deallocated.
//
// Dependencies:  None.
//
// End Function Specification //////////////////////////////////////

namespace PRDF
{

SCAN_COMM_REGISTER_CLASS::~SCAN_COMM_REGISTER_CLASS
(
 void
 /*!i No parameters                                               */
 )
/*!o No value returned                                           */
{
}

// Function Specification ///////////////////////////////////////////
//
// Title:  Read
//
// Purpose:  This function reads the actual hardware register and
//           sets the Bit String data member values.  The specified
//           Bit String is then used to mask the Bit String data
//           member.  If an error occur, then the error is reported
//           and the Bit String values are undefined.
//
// Side-effects:  Hardware register is read.
//                Bit String data member is modified.
//                Memory is reallocated.
//
// End Function Specification //////////////////////////////////////

uint32_t SCAN_COMM_REGISTER_CLASS::Read
(
 BIT_STRING_CLASS & mask
 /*!i Reference to Bit String mask                                */
 )
/*!o Error return code                                           */
{
  uint32_t rc = Read();

  if(rc == SUCCESS)
  {
    BIT_STRING_CLASS & bitString = AccessBitString();
    bitString.Mask(mask);
  }

  return(rc);
}


uint32_t SCAN_COMM_REGISTER_CLASS::UnSync(void){return(SUCCESS);}

// Function Specification //////////////////////////////////////////
//
//  Title:  Set Bit
//
//  Purpose:  This function sets(1) the specified bit position in
//            the Bit String.  If the Bit String is NULL, then a
//            new Bit String is allocated and cleared to all zero
//            before setting the bit.
//
//  Side-effects:  Bit String is modified.
//                 Memory may be allocated.
//
//  Dependencies:  bit_position must be in the string
//
// End Function Specification //////////////////////////////////////

void SCAN_COMM_REGISTER_CLASS::SetBit
(
 uint32_t bit_position
 /*!i Bit position in string                                      */
 )
/*!o No value returned                                           */
{

  BIT_STRING_CLASS & bitString = AccessBitString();
  bitString.Set(bit_position);
}

// Function Specification //////////////////////////////////////////
//
//  Title:  Clear Bit
//
//  Purpose:  This function clears(0) the specified bit position in
//            the Bit String.  If the Bit String is NULL, then a
//            new Bit String is allocated and cleared to all zeros.
//
//  Side-effects:  Bit String is modified.
//                 Memory may be allocated.
//
//  Dependencies:  bit_position must be in the string
//
// End Function Specification //////////////////////////////////////

void SCAN_COMM_REGISTER_CLASS::ClearBit
(
 uint32_t bit_position
 /*!i Bit position in string                                      */
 )
/*!o No value returned                                           */
{
  BIT_STRING_CLASS & bitString = AccessBitString();
  bitString.Clear(bit_position);
}

// Function Specification //////////////////////////////////////////
//
// Title:  SCAN_COMM_REGISTER_CLASS (Copy constructor)
//
// Purpose:  This constuctor initializes the data members.  This
//           copy constructor uses a "deep" copy.
//
// Side-effects:  This instance is initialized.
//
// Dependencies:  None.
//
// Time Complexity:  Constant + time complexity of SetBitString()
//
// End Function Specification //////////////////////////////////////

SCAN_COMM_REGISTER_CLASS::SCAN_COMM_REGISTER_CLASS
(
 const SCAN_COMM_REGISTER_CLASS & scr
 /*!i Scan Comm Register reference to copy                        */
 ) :
/*!o No value returned                                           */
address(scr.address)
{
}

// Function Specification ///////////////////////////////////////////
//
// Title:  operator= (Assignment operator)
//
// Purpose:  This assignment operator assigns the Bit String data
//           member.
//
// Side-effects:  Bit String data member is modified.
//                Memory is reallocated.
//
// Dependencies:  None.
//
// Time Complexity:  Constant
//
// End Function Specification //////////////////////////////////////

SCAN_COMM_REGISTER_CLASS & SCAN_COMM_REGISTER_CLASS::operator=
(
 const SCAN_COMM_REGISTER_CLASS & scr
 /*!i Scan Comm Register instance to assign from              */
 )
/*!o Reference to this Scan Comm Register instance           */
{
  // Check for assignment to self
  if(this != &scr)
  {
    address = scr.address;
  }

  return(*this);
}

// Function Specification ///////////////////////////////////////////
//
// Title:  Clear Bit String
//
// Purpose:  This function clears the Bit String.  If the data
//           member is NULL, then a new Bit String is allocated.
//           Upon return, the state of the Bit String is all zero.
//
// Side-effects:  Bit String data member is modified.
//                Memory is allocated or reallocated.
//
// End Function Specification //////////////////////////////////////

void SCAN_COMM_REGISTER_CLASS::clearAllBits()
{
    BIT_STRING_CLASS & bitString = AccessBitString();
    bitString.Pattern( 0, bitString.GetLength(), 0x00000000, 32 );
}

void SCAN_COMM_REGISTER_CLASS::setAllBits()
{
    BIT_STRING_CLASS & bitString = AccessBitString();
    bitString.Pattern( 0, bitString.GetLength(), 0xffffffff, 32 );
}

// Function Specification //////////////////////////////////////////
//
// Title:  SCAN_COMM_REGISTER_CLASS (Constructor)
//
// Purpose:  This constuctor initializes the data members.
//
// Side-effects:  This instance is initialized. Memory may be allocated
//
// Dependencies:  None.
//
// End Function Specification //////////////////////////////////////

SCAN_COMM_REGISTER_CLASS::SCAN_COMM_REGISTER_CLASS
(
 uint64_t a
 /*!i Physical address of register                                */
 ) :
/*!o No value returned                                           */
address(a)
{
}

} // end namespace PRDF

#undef IIPSCR_C
