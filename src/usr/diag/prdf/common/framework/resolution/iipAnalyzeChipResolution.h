/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipAnalyzeChipResolution.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1997,2014              */
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

#ifndef iipAnalyzeChipResolution_h
#define iipAnalyzeChipResolution_h

// Class Description *************************************************
//
//  Name:  AnalyzeChipResolution
//  Base class: Resolution
//
//  Description: Resolution to call Analyze() on a CHIP_CLASS
//  Usage:
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
class CHIP_CLASS;

/**
 <One line Class description>
 @author Doug Gilbert
 */
class AnalyzeChipResolution: public Resolution
{
public:
  /**
   Constructor
   <ul>
   <br><b>Parameters:</b>   chip: Chip object
   <br><b>Requirements:</b> None
   <br><b>Promises:</b>     Object created
   <br><b>Exceptions:</b>   None
   </ul><br>
   */
  AnalyzeChipResolution(CHIP_CLASS & chip) : xChip(chip) {}

  /*
   Destructor
   <ul>
   <br><b>Parameters:</b>   None.
   <br><b>Returns:</b>      No value returned
   <br><b>Requirements:</b> None.
   <br><b>Promises:</b>     None.
   <br><b>Exceptions:</b>   None.
   <br><b>Notes:</b>        Compiler default is sufficient
   </ul><br>
   */
  //  ~iipAnalyzeChipResolution();

  /**
   Resolve service data by calling chip.Analyze()
   <ul>
   <br><b>Parameters:</b>   {parms}
   <br><b>Returns:</b>      {return}
   <br><b>Requirements:</b> {preconditions}
   <br><b>Promises:</b>     {postconditions}
   <br><b>Exceptions:</b>   None.
   <br><b>Notes:</b>        {optional}
   </ul><br>
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & serviceData);

private:  // functions
private:  // Data

  /**
   @see CHIP_CLASS
   */
  CHIP_CLASS & xChip;

};

} // end namespace PRDF

#endif /* iipAnalyzeChipResolution_h */

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder Description
//  ---- -------- ---- -------- ----- -------------------------------
//                     05/05/98 DRG   Initial Creation
//
// End Change Log *****************************************************
