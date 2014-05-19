/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfFilters.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2014              */
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
 @file iipFilters.C
 @brief Definition of SingleBitFilter, PrioritySingleBitFilter, FilterLink,
 and ScanCommFilter classes.
*/

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define iipFilters_C

#include <prdfBitKey.H>
#include <prdfFilters.H>
//#include <xspprdScanCommFilter.h>
#include <iipscr.h>
//#include <xspprdFilterLink.h>

#undef iipFilters_C

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

//----------------------------------------------------------------------
// Member Function Specifications
//----------------------------------------------------------------------

FilterClass::~FilterClass(void)
{}

//-------------------------------------------------------------------------------------------------

bool FilterPriority::Apply(BitKey & ioBitList)
{
  bool modified = false;
  if(ioBitList.isSubset(ivBitKey))
  {
    ioBitList = ivBitKey;
    modified = true;
  }
  return modified;
}


//-------------------------------------------------------------------------------------------------

bool SingleBitFilter::Apply(BitKey & bit_list)
{
  bool rc = false;
  uint32_t list_length = bit_list.size();
  if(list_length > 1)
  {
    rc = true;
    while(--list_length)
    {
      bit_list.removeBit();
    }
  }
  return(rc);
}


//-------------------------------------------------------------------------------------------------

bool PrioritySingleBitFilter::Apply(BitKey & bit_list)
{
    bool l_modified = false;

    // Do priority bit.
    for (size_t i = 0; i < iv_bitList.size(); i++)
    {
        BitKey l_key = iv_bitList[i];
        if (bit_list.isSubset(l_key))
        {
            l_modified = true;
            bit_list = l_key;
            break;
        }
    }
    // Do single bit filter portion.
    if (!l_modified)
    {
        while (1 < bit_list.size())
        {
            l_modified = true;
            bit_list.removeBit();
        }
    }
    return l_modified;
}

//-------------------------------------------------------------------------------------------------

bool FilterTranspose::Apply(BitKey & iBitList)
{
  bool result = false;
  if(iBitList == ivBitKey)
  {
    BitKey bk(ivSingleBitPos);
    iBitList = bk;
    result = true;
  }
  return result;
}

bool FilterTranspose::Undo(BitKey & iBitList)
{
  bool result = false;
  BitKey testbl(ivSingleBitPos);
  if(iBitList.isSubset(testbl))
  {
    iBitList = ivBitKey;
    result = true;
  }

  return result;
}

//-------------------------------------------------------------------------------------------------

bool FilterLink::Apply(BitKey & bit_list)
{
  bool rc = xFilter1.Apply(bit_list);
  rc = rc || xFilter2.Apply(bit_list);
  return rc;
}

bool FilterLink::Undo(BitKey & bit_list)
{
  bool rc = xFilter1.Undo(bit_list);
  rc = rc || xFilter2.Undo(bit_list);
  return rc;
}

//-------------------------------------------------------------------------------------------------

bool ScanCommFilter::Apply(BitKey & bitList)
{
  // Read HW register
  scr.Read();

  // local copy of bit string from scan comm register
  BIT_STRING_BUFFER_CLASS bsb(*scr.GetBitString());
  BitKey bl;
  bool rc = false;

  // Invert if necessary
  if (xInvert)
  {
    bsb = ~bsb;
  }

  // Create bit list
  bl = bsb;
  uint32_t bsize = bitList.size();
  bitList.removeBits(bl);
  if(bsize != bitList.size())
  {
    rc = true;
  }

  return(rc);
}
} //End namespace PRDF

// Change Log *************************************************************************************
//
//  Flag Reason   Vers    Date     Coder    Description
//  ---- -------- ------- -------- -------- ------------------------------
//                v4r1    09/05/96 DGILBERT Initial Creation
//                v4r3    01/27/98 SERAFIN  Add PrioritySingleBitFilter
//  dg00          v4r5    06/30/99 DGILBERT fix PrioritySingleBitFilter
//  mk01 P4904712 v4r5    10/21/99 mkobler  really fix PrioritySingleBitFilter
//       490420.x v5r2    07/06/00 mkobler  Add ScanCommFilter
//       490420.x v5r2    07/06/00 dgilbert added FilterLink
//                fips    03/19/04 dgilbert rename to Filters.C;rewrote PrioritySingleBitFilter
//                                          changed to use BitKey
//       558003   fips310 06/21/06 dgilbert Add Undo()
//       582595          fips310 12/12/06 iawillia Update priority sb filter to maintain bit order.
//
// End Change Log *********************************************************************************
