/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfClockResolution.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define prdfClockResolution_C
#include <iipServiceDataCollector.h>
#include <prdfClockResolution.H>
#include <prdfPlatServices.H>
#undef prdfClockResolution_C

namespace PRDF
{

//------------------------------------------------------------------------------
// Member Function Specifications
//------------------------------------------------------------------------------

// Find the active clock source and blame it
int32_t ClockResolution::Resolve(STEP_CODE_DATA_STRUCT & serviceData)
{
    using namespace TARGETING;

    uint32_t l_rc = SUCCESS;
    // callout clock osc
    if ( (iv_targetType == TYPE_PROC) ||
         (iv_targetType == TYPE_MEMBUF) )
    {
        // even though we pass in pos=0 for systemref clk,
        // getActiveRefClk will make sure it returns the active osc.
        TargetHandle_t l_ptargetClock =
            PlatServices::getActiveRefClk(iv_ptargetClock,
                                     TYPE_OSCREFCLK, 0);

        // Callout this chip if nothing else.
        if(NULL == l_ptargetClock)
        {
            l_ptargetClock = iv_ptargetClock;
        }

        // callout the clock source
        // HB does not have the osc target modeled
        // so we need to use the proc target with
        // osc clock type to call out
        #ifndef __HOSTBOOT_MODULE
        serviceData.service_data->SetCallout(l_ptargetClock);
        #else
        serviceData.service_data->SetCallout(
                            PRDcallout(l_ptargetClock,
                            PRDcalloutData::TYPE_PROCCLK));
        #endif
    }
    else if (iv_targetType == TYPE_PCI)
    {
        // The PCIe OSC callout is being done inside
        // chip plugins (prdfP8PllPcie) since the connected
        // OSC can dynamically change and requires
        // reading chip reg to figure out.
    }
    // Get all connected chips for non-CLOCK_CARD types.
    else
    {
        //Callout every device connected to this clock source.
        TargetHandleList l_targetsConnectedToClock =
                PlatServices::getConnected( iv_ptargetClock, iv_targetType );

        for( TargetHandleList::iterator i = l_targetsConnectedToClock.begin();
             i != l_targetsConnectedToClock.end(); ++i )
        {
            if ( NULL != (*i) )
            {
                serviceData.service_data->SetCallout( *i );
            }
        }
    }
    return(l_rc);
}

} // end namespace PRDF
