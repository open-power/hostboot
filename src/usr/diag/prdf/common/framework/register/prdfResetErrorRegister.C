/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfResetErrorRegister.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
 @file iipResetErrorRegister.C
 @brief ResetErrorRegister class definition
*/

// Module Description **************************************************
//
// Description:
//
// End Module Description **********************************************
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define iipResetErrorRegister_C

#include <iipscr.h>
#include <iipResetErrorRegister.h>
#include <iipServiceDataCollector.h>

#ifndef __HOSTBOOT_MODULE
  #include <prdfSdcFileControl.H> // for SyncAnalysis
#endif

#undef iipResetErrorRegister_C
//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

namespace PRDF
{

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
int32_t ResetErrorRegister::Reset(const BitKey & bit_list,
                                 STEP_CODE_DATA_STRUCT & error)
{
  #ifndef __HOSTBOOT_MODULE
  ServiceDataCollector & sdc = *(error.service_data);
  SyncAnalysis (sdc);  //Add call to Sync SDC
  #endif

  int32_t rc = ErrorRegisterMask::Reset(bit_list,error);  // set mask bits & undo filters
  uint32_t bl_length = bit_list.size();

  if(bl_length != 0) // Check for bits to reset
  {
    if(&scr != resetScr)  // reset different then ereg scr - move bits
    {
      resetScr->SetBitString(scr.GetBitString());
    }
    uint32_t i;
    for(i = 0; i < bl_length; ++i)  // Turn off all bits specified
    {
      resetScr->ClearBit(bit_list.getListValue(i));
    }
    rc = resetScr->Write();    // Write hardware
  }
  return rc;
}

// Reset and Mask error registers.
int32_t
ResetAndMaskErrorRegister::Reset(const BitKey & bit_list,
                                 STEP_CODE_DATA_STRUCT & error)
{
    int32_t rc = SUCCESS;
    // Don't do reset on CS.
    if (CHECK_STOP != error.service_data->getPrimaryAttnType())
    {
      #ifndef __HOSTBOOT_MODULE
      ServiceDataCollector & sdc = *(error.service_data);
      SyncAnalysis (sdc);  //Add call to Sync SDC
      #endif

      // We're not allowed to clear black-listed FIRs from the FSP
      #if defined(__HOSTBOOT_MODULE) || defined(ESW_SIM_COMPILE)
      rc = ErrorRegisterMask::Reset(bit_list,error); //undo filters

      // Mask registers as needed, if at threshold.
      if (error.service_data->IsAtThreshold())
      {
        for (ResetRegisterVector::iterator i = cv_masks.begin();
             i != cv_masks.end();
             ++i)
        {
            rc |= i->op->Reset(bit_list, error, i->read, i->write);
        }
      }

      // Reset registers as needed.
      for (ResetRegisterVector::iterator i = cv_resets.begin();
           i != cv_resets.end();
           ++i)
      {
        rc |= i->op->Reset(bit_list, error, i->read, i->write);
      }
      #endif
    }

    return rc;
}

} //End namespace PRDF
