/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/iipchip.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1993,2014              */
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

#define IIPCHIP_CPP

/* Module Description *************************************************/
/*                                                                    */
/*  Name:  iipchip.cpp                                                */
/*                                                                    */
/*  Description:  This module contains the implementation for the
 Processor Runtime Diagnostics Chip class.           */
/*                                                                    */
/* End Module Description *********************************************/

/* Change Log *********************************************************/
/*                                                                    */
/*  Flag Reason   Vers Date     Coder Description                     */
/*  ---- -------- ---- -------- ----- ------------------------------- */
/*                V2ST 07/30/93 JST   Initial Creation                */
/*                V2ST 08/20/93 JST   Added Tables and Analyze()
 Converted to ABC                */
/*                V300 11/02/93 JST   Using Error Register,
 ATTENTION_TYPE                  */
/*                V300 11/02/93 JST   Created CHIP_IDENTITY           */
/*                V300 01/04/94 JST   Analyze() returns Step Code Data
 via parameter reference         */
/*                V300 01/11/94 JST   Removed CHIP_IDENTITY           */
/*                V300 01/20/94 JST   Removed Analyze()               */
/*                V300 05/04/94 JST   Added Initialize()              */
/*       D24585.5 V300 06/07/94 JST   Adding CapruteErrorData()       */
/*                V400 07/28/94 JST   Removing CapruteErrorData()     */
/*                                                                    */
/* End Change Log *****************************************************/

/*--------------------------------------------------------------------*/
/* Emit the virtual function tables and inline function defintions in
 this translation unit.                                             */
/*--------------------------------------------------------------------*/

#include <iipchip.h>
#include <prdfPlatServices.H>

namespace PRDF
{

/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

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
// Title:  ~CHIP_CLASS (Virtual destructor)
//
//  Purpose:  This destructor does nothing.  This declaration is
//            provided to enable derived class destuctores to be
//            called properly.
//
// Side-effects:  None.
//
// Dependencies:  None.
//
// End Function Specification //////////////////////////////////////

CHIP_CLASS::~CHIP_CLASS
(
 void
 /*!i No parameters                                               */
 )
/*!o No value returned                                           */
{
}

// Function Specification //////////////////////////////////////////
//
// Title:  Initialize (Virtual)
//
// Purpose:  This function handles the PRD initialization of the
//           corresponding hardware chip and any associated data.
//
//           This default implementation does nothing and returns
//           SUCCESS(0).
//
// Side-effects:  Scan comm registers may be written.
//                Internal data may be modified.
//
// Dependencies:  None.
//
// End Function Specification //////////////////////////////////////

int32_t CHIP_CLASS::Initialize
(
 void
 /*!i No parameters                                               */
 )
/*!o Error Return code                                           */
{
  return(SUCCESS);
}

HUID CHIP_CLASS::GetId() const
{
    return(PlatServices::getHuid(iv_pchipHandle));
}

} // end namespace PRDF

#undef IIPCHIP_CPP
