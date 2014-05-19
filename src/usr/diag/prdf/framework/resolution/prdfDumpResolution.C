/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/resolution/prdfDumpResolution.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2014              */
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
 @file  prdfDumpResolution.C
 @brief defines resolve action for dump resolution for hostboot platform
 */

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <prdDumpResolution.H>
#include <iipServiceDataCollector.h>

namespace PRDF
{

int32_t DumpResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData )
{
    // Note: Dump is not supported on hostboot.
    return SUCCESS;
}

} // end namespace PRDF
