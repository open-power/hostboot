/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipScanCommRegisterAccess.C $ */
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
//              Comm Register Access class.
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define iipScanCommRegisterAccess_C

#include <CcSynch.h>
#include <iipconst.h>
#include <iipbits.h>
#include <iipMopRegisterAccess.h>
#include <iipScanCommRegisterAccess.h>
#include <prdfMain.H>
#undef iipScanCommRegisterAccess_C

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
//
#define GCC_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__)
#if (GCC_VERSION >= 3004)
template<>
#endif
ScanCommRegisterAccess::SynchType::StepType
  ScanCommRegisterAccess::SynchType::step =
    ScanCommRegisterAccess::SynchType::STATIC_INITIAL_VALUE;

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

uint32_t ScanCommRegisterAccess::UnSync(void)
{
    uint32_t l_rc = SUCCESS;
    synch.Advance();  // make everything out of synch
    return(l_rc);
}

uint32_t ScanCommRegisterAccess::Read(void)
{
  uint32_t rc = SUCCESS;

  if(!synch.IsCurrent())
  {
//    BIT_STRING_BUFFER_CLASS bs(GetBitLength(), GetBufferByteSize());
    BIT_STRING_CLASS & bs = AccessBitString();

    rc = Access(bs,GetAddress(), MopRegisterAccess::READ);
    // dg01 start
    if (rc != SUCCESS)
    {
      synch.Advance();  // make everything out of synch if failed
    }
    // dg01 end

//    if(rc == SUCCESS)
//    {
//      SetBitString(&bs);
//    }
  }

  return(rc);
}

// ----------------------------------------------------------------------------
// dg00 start
uint32_t ScanCommRegisterAccess::ForceRead(void)
{
  uint32_t rc = SUCCESS;

  BIT_STRING_CLASS & bs = AccessBitString();
  rc = Access(bs,GetAddress(), MopRegisterAccess::READ);
  synch.IsCurrent();

  return rc;
}
// dg00 end
//-------------------------------------------------------------------------------

uint32_t ScanCommRegisterAccess::Write(void)
{
  uint32_t rc = (uint32_t) FAIL;

//  const BIT_STRING_CLASS * bit_string_ptr = GetBitString();

  BIT_STRING_CLASS & bs = AccessBitString();
//  if(bit_string_ptr != NULL)
//  {
//    BIT_STRING_BUFFER_CLASS bs(GetBitLength(), GetBufferByteSize());

//    bs.SetBits(*bit_string_ptr);

  rc = Access(bs, GetAddress(),MopRegisterAccess::WRITE);
//  }

  return(rc);
}

// unsigned int ScanCommRegisterAccess::GetBufferByteSize(void) const
// {
//   return(BUFFER_BYTE_SIZE);
// }

uint32_t ScanCommRegisterAccess::Access(BIT_STRING_CLASS & bs, uint64_t registerId,
                                     MopRegisterAccess::Operation op) const
{
  using namespace PRDF;

  uint32_t rc = SCR_ACCESS_FAILED;
  if(hops != NULL)
  {
    rc = hops->Access(bs, registerId, op);
  }
  return(rc);
}

// #ifdef _USE_IOSTREAMS_

// ostream & operator<<(ostream & out, const ScanCommRegisterAccess & scr)
//   {
//     out << "Address: " << scr.GetAddress() << " Chip: "; // << hops;


//     uint32_t count;
//     const uint32_t * values = scr.GetChipSelectValues(count);

//     if(count)
//     {
//       for(uint32_t i = 0;i < count;i++)
//       {
//         out << values[i] << " ";
//       }
//     }
//     else
//     {
//       out << "None ";
//     }

//   const BIT_STRING_CLASS * bit_string_ptr = scr.GetBitString();

//   if(bit_string_ptr == NULL)
//     {
//     out << " No Data";
//     }
//   else
//     {
//     out << " Data: " << (*bit_string_ptr);
//     }

//   return(out);
//   }

// #endif

// Change Log **********************************************************
//
//  Flag  PTR/DCR#  Userid    Date      Description
//  ----  --------  --------  --------  -----------
//  n/a   n/a       JST       ??/??/95  Created.
//        D24747.4  JFP       02/23/95  Added #include <CuLib.h>
//                  DGILBERT  05/23/97  Access()/Read()/Write() change
//  dg01  aix343882 dgilbert  07/16/01  Make out of synch if Read fails
//
// End Change Log ******************************************************







