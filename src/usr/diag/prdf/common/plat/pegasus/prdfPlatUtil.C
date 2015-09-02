/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPlatUtil.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

/** @file prdfPlatUtil.C */

#include <prdfPlatServices.H>
#include <iipServiceDataCollector.h>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
namespace PlatUtil
{

bool ignoreErrorForSapphire( STEP_CODE_DATA_STRUCT & i_stepcode )
{
    bool ignoreError = false;

    // First of all ensure that we are not in AVP mode. Hypervisor becomes
    // irrelevant in that case.
    if( !isMfgAvpEnabled() && !isMfgHdatAvpEnabled() && !mfgMode() )
    {
        if( isHyprConfigOpal() )
        {
            // For an OPAL based system, analysis for certain errors is either
            // not supported or shall be added later. We need to simply
            // threshold and mask these errors. There should not be any service
            // action. However, there are some scenarios to consider:
            // 1. manufacturing or AVP mode - threshold and predictive callout
            // 2. SP less system    - mask error on first instance.
            // 3. SP based Tuleta-L - mask error once threshold is met (say 32
            //                        per Day ).

            if( !isSpConfigFsp() )
            {
                //Mask the error on first instance for FSP less systems.
                i_stepcode.service_data->setFlag(
                                ServiceDataCollector::AT_THRESHOLD );
            }

            //Prevent predictive callout of the chip.
            i_stepcode.service_data->clearServiceCall();

            ignoreError = true;
        }
    }

    return ignoreError;
}

} // end namespace PlatUtil

} // end namespace PRDF

