/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/iipstep.h $        */
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

#ifndef IIPSTEP_H
#define IIPSTEP_H

/*!
 Processor Runtime Diagnostics Step Code class declaration
 @file iipstep.h
*/

/* Change Log *********************************************************/
/*                                                                    */
/*  Flag Reason   Vers Date     Coder Description                     */
/*  ---- -------- ---- -------- ----- ------------------------------- */
/*                V300 07/16/93 JST   Initial Creation                */
/*                V300 12/20/93 JST   Modifying Step Code Data        */
/*                V300 02/15/94 JST   Removed Step Code Class         */
/*                V300 03/11/94 JST   Modified Step Code Data         */
/*       d24737.? V4R1 10/25/95 DRG   Added ServiceDataCollector      */
/*       357551  fips1 02/01/02 dgilbert FSP - removed ERROR_OBJECT   */
/*                                                                    */
/* End Change Log *****************************************************/

/*--------------------------------------------------------------------*/
/* Reference the virtual function tables and inline function
   defintions in another translation unit.                            */
/*--------------------------------------------------------------------*/
#ifdef __GNUC__
#endif
/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

#include <stddef.h>

namespace PRDF
{

class ServiceDataCollector;

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
/*  Global Variables                                                  */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Function Prototypes                                               */
/*--------------------------------------------------------------------*/

/* Structure Specification ********************************************/
/*                                                                    */
/*  Title:  Step Code Data                                            */
/*                                                                    */
/*  Purpose:  STEP_CODE_DATA_STRUCT represents the static information
              required for a unique errror condition.                 */
/*                                                                    */
/*  Usage:  Concrete structure                                        */
/*                                                                    */
/*  Side-effects:  None.                                              */
/*                                                                    */
/*  Dependencies:  None.                                              */
/*                                                                    */
/*  Cardinality:  N                                                   */
/*                                                                    */
/*  Space Complexity:  Constant                                       */
/*                                                                    */
/* End Structure Specification ****************************************/

struct STEP_CODE_DATA_STRUCT
{
    // Used to identify a unique error condition and collect related
    // information
    STEP_CODE_DATA_STRUCT () : service_data( nullptr ) {};
    ServiceDataCollector *     service_data;
};

} // end namespace PRDF

#endif
