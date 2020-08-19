/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfCaptureResolution.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2006,2020                        */
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

#include <prdfCaptureResolution.H>
#include <iipServiceDataCollector.h>

namespace PRDF
{

int32_t CaptureResolution::Resolve( STEP_CODE_DATA_STRUCT & io_error,
                                    bool i_default )
{
    ExtensibleChip * l_pResolutionChip =
                                ServiceDataCollector::getChipAnalyzed( );
    PRDF_ASSERT( nullptr != l_pResolutionChip );

    return l_pResolutionChip->CaptureErrorData(
                                    io_error.service_data->GetCaptureData(),
                                    iv_captureGroup );
};

} // end namespace PRDF

