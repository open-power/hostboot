/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipScanCommRegisterChip.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2012              */
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

// Module Description **************************************************
//
// Description: This module provides the implementation for the PRD Scan
//              Comm Register Chip class.
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#define iipScanCommRegisterChip_C

#include <iipchip.h>
// #include <iipMopRegisterAccessScanCommSingle.h>
#include <iipScanCommRegisterChip.h>

#undef iipScanCommRegisterChip_C

//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

ScanCommRegisterChip::ScanCommRegisterChip(uint64_t ra,
                                           unsigned int bl,
                                           MopRegisterAccess & hopsAccess)
 :
 ScanCommRegisterAccess(ra,hopsAccess),
 xBitString(bl)
{
  xBitString.Pattern(0); // Clear
}

// --------------------------------------------------------------------


// ---------------------------------------------------------------------

void ScanCommRegisterChip::SetBitString(const BIT_STRING_CLASS *bs)
{
  xBitString.SetBits(*bs);
}

// ---------------------------------------------------------------------

// const uint32_t * ScanCommRegisterChip::GetChipSelectValues
//   (unsigned int & chipSelectCount) const
// {
//   const uint32_t * chipSelectValues = NULL;

//   if(chipPtr)
//   {
//     chipSelectCount = chipPtr->GetChipSelectCount();
//     chipSelectValues = chipPtr->GetChipSelectValues();
//   }
//   else
//   {
//     chipSelectCount = 0;
//   }

//   return(chipSelectValues);
// }

// Change Log **********************************************************
//
//  Flag  PTR/DCR#  Userid    Date      Description
//  ----  --------  --------  --------  -----------
//  n/a   n/a       JST       04/18/95  Created.
//        D49127.7  DGILBERT  09/20/96  Added xBitString, Get/SetBitString()
//                                      AccessBitString()
//                  DGILBERT  05/27/97  V4R3 changes
//
// End Change Log ******************************************************

