/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipscr.C $        */
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

#include <prdfBitString.H>
#include <iipscr.h>
#include <iipconst.h>

#include <prdfAssert.h>

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
 BitString & mask
 /*!i Reference to Bit String mask                                */
 )
/*!o Error return code                                           */
{
  uint32_t rc = Read();

  if(rc == SUCCESS)
  {
    BitString & bitString = AccessBitString();
    bitString.maskString(mask);
  }

  return(rc);
}
// Function Specification //////////////////////////////////////////
//
//  Title:  Set Bit
//
//  Purpose:  This function sets(1) the specified bit position in
//            the Bit String.  If the Bit String is nullptr, then a
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

  BitString & bitString = AccessBitString();
  bitString.setBit(bit_position);
}

// Function Specification //////////////////////////////////////////
//
//  Title:  Clear Bit
//
//  Purpose:  This function clears(0) the specified bit position in
//            the Bit String.  If the Bit String is nullptr, then a
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
  BitString & bitString = AccessBitString();
  bitString.clearBit(bit_position);
}



// Function Specification ///////////////////////////////////////////
//
// Title:  Clear Bit String
//
// Purpose:  This function clears the Bit String.  If the data
//           member is nullptr, then a new Bit String is allocated.
//           Upon return, the state of the Bit String is all zero.
//
// Side-effects:  Bit String data member is modified.
//                Memory is allocated or reallocated.
//
// End Function Specification //////////////////////////////////////

void SCAN_COMM_REGISTER_CLASS::clearAllBits()
{
    BitString & bitString = AccessBitString();
    bitString.clearAll();
}

void SCAN_COMM_REGISTER_CLASS::setAllBits()
{
    BitString & bitString = AccessBitString();
    bitString.setAll();
}

//------------------------------------------------------------------------------

uint64_t SCAN_COMM_REGISTER_CLASS::GetBitFieldJustified( uint32_t i_pos,
                                                         uint32_t i_len ) const
{
    uint64_t o_value = 0;

    const uint32_t len_cpu_word = sizeof(CPU_WORD) * 8;
    const uint32_t len_uint64   = sizeof(uint64_t) * 8;
    const uint32_t pos_end      = i_pos + i_len;

    PRDF_ASSERT( pos_end <= len_uint64 );

    const BitString * bs = GetBitString();

    for ( uint32_t pos = i_pos; pos < pos_end; pos += len_cpu_word )
    {
        // Calculate chunk length.
        uint32_t len_chunk = len_cpu_word;
        if ( len_chunk > pos_end - pos )
            len_chunk = pos_end - pos;

        o_value <<= len_chunk; // Make room for new chunk.

        // Get chunk.
        o_value |= static_cast<uint64_t>(bs->getFieldJustify(pos, len_chunk));
    }

    return o_value;
}

//------------------------------------------------------------------------------

void SCAN_COMM_REGISTER_CLASS::SetBitFieldJustified( uint32_t i_pos,
                                                     uint32_t i_len,
                                                     uint64_t i_value )
{
    const uint32_t len_cpu_word = sizeof(CPU_WORD) * 8;
    const uint32_t len_uint64   = sizeof(uint64_t) * 8;

    PRDF_ASSERT( i_pos + i_len <= len_uint64 );

    BitString & bs = AccessBitString();

    for ( uint32_t offset = 0; offset < i_len; offset += len_cpu_word )
    {
        // Calculate chunk length.
        uint32_t len_chunk = len_cpu_word;
        if ( len_chunk > i_len - offset )
            len_chunk = i_len - offset;

        uint64_t value = i_value;
        value >>= i_len - (offset + len_chunk); // right justify

        // Set chunk.
        bs.setFieldJustify( i_pos + offset, len_chunk,
                            static_cast<CPU_WORD>(value) );
    }
}

} // end namespace PRDF

#undef IIPSCR_C

