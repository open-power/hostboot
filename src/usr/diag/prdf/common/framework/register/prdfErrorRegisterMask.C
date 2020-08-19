/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfErrorRegisterMask.C $ */
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

/**
 @file prdfErrorRegisterMask.C
 @brief ErrorRegisterMask class definition
*/

// Module Description **************************************************
//
// Description:
//
// End Module Description **********************************************
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define prdfErrorRegisterMask_C

#include <iipscr.h>
#include <prdfFilters.H>
#include <iipErrorRegisterMask.h>
#include <iipServiceDataCollector.h>

#undef prdfErrorRegisterMask_C

namespace PRDF
{
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
ErrorRegisterMask::ErrorRegisterMask
(
 SCAN_COMM_REGISTER_CLASS & r,
 ResolutionMap & rm,
 FILTER_CLASS * f,
 uint16_t scrId,
 SCAN_COMM_REGISTER_CLASS & maskScr   // dg00
 )
:
ErrorRegisterFilter(r,rm,f,scrId),
bitString(r.GetBitLength()),
bitStringMask(r.GetBitLength()),
xMaskScr(maskScr)
{
  bitStringMask.clearAll();
}

ErrorRegisterMask::ErrorRegisterMask
(
 SCAN_COMM_REGISTER_CLASS & r,
 ResolutionMap & rm,
 uint16_t scrId,
 SCAN_COMM_REGISTER_CLASS & maskScr     // dg00
)
:
ErrorRegisterFilter(r,rm,scrId),
bitString(r.GetBitLength()),
bitStringMask(r.GetBitLength()),
xMaskScr(maskScr)
{
  bitStringMask.clearAll();     // clear software mask
}

// **********************************************************************

const BitString & ErrorRegisterMask::Read()
{
  scr_rc = scr.Read();
  bitString = *scr.GetBitString();
  // apply software mask
  bitString.maskString(bitStringMask);
  // apply hardware mask - if scan comm register for it was specified
  if(&xMaskScr != nullptr)  /*constant condition*/        // dg00
  {                                                    // dg00
    int32_t rc = xMaskScr.Read();                       // dg00
    if(rc == SUCCESS)                                  // dg00
    {                                                  // dg00
      bitString.maskString(*(xMaskScr.GetBitString()));      // dg00
    }                                                  // dg00
  }                                                    // dg00

  return(bitString);
}

// ***********************************************************************

int32_t ErrorRegisterMask::Reset(const BIT_LIST_CLASS & bit_list,
                                STEP_CODE_DATA_STRUCT & error)
{
  int32_t rc = SUCCESS;
  if(error.service_data->IsAtThreshold())
  {
    int32_t blLength = bit_list.size();
    int i = 0;
    if(&xMaskScr == nullptr) /* constant condition*/ // dg00
    {                     // dg00
      for(i = 0; i < blLength; ++i)
      {
        SetMaskBit(bit_list.getListValue(i));
      }
    }                                                    // dg00
//    else // valid maskSCR                                // dg00
//    {                                                    // dg00
//      for(i = 0; i < blLength; ++i)                      // dg00
//      {                                                  // dg00
//        xMaskScr.SetBit(bit_list.GetListValue(i));       // dg00
//      }                                                  // dg00
//      rc = xMaskScr.Write();                             // dg00
//    }                                                    // dg00
  }
  return rc;
}

// ***************************************************************************

BIT_LIST_CLASS ErrorRegisterFilter::Filter( const BitString & bs,
                                            STEP_CODE_DATA_STRUCT & io_sdc )
{
    BIT_LIST_CLASS bit_list;
    bit_list = bs;
    if( filter ) filter->Apply( bit_list, io_sdc );
    return bit_list;
}

} //End namespace PRDF

// Change Log *********************************************************
//
//  Flag Reason   Vers    Date     Coder    Description
//  ---- -------- ------ -------- -------- ------------------------------
//                v4r1mo 05/03/96 DGILBERT Initial Creation
//       d49127.1 v4r1m0 05/31/96 DGILBERT Added Analyze() and Reset()
//       p4902214 v4r1m0 05/09/97 DGILBERT Added service data to Reset()
//                                         Removed Analyse()
//       D49274.2 v4r5   09/24/98 DGILBERT Added scrId
//  dg00          v5r2   04/05/00 DGILBERT Added maskScr
//       P4907878 v5r2   04/27/01 DGILBERT factor out filter into
//                                         ErrorRegisterFilter class
//       423599   fsp    10/28/03 dgilbert make scrId a uint16_t
//
// End Change Log *****************************************************
