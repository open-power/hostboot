/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfClockResolution.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
    // Use clock routines for CLOCK_CARD types.
    // FIXME: RTC: 51628 will address clock target issue
    if ( (iv_targetType == TYPE_PROC) || (iv_targetType == TYPE_MEMBUF) )
    {
        // Get clock card.
        TargetHandle_t l_ptargetClock = PlatServices::getClockId(
                                                                iv_ptargetClock,
                                                                iv_targetType );

        // Find mux if no clock card available.
        if(NULL == l_ptargetClock)
        {
            l_ptargetClock = PlatServices::getClockMux(iv_ptargetClock);
        }

        // Callout this chip if nothing else.
        if(NULL == l_ptargetClock)
        {
            l_ptargetClock = iv_ptargetClock;
        }

        //Just callout the clock source.
        //There is no clock target now so we don't want to make
        //any incorrect callout until it's implemented.
        //serviceData.service_data->SetCallout(l_ptargetClock);
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
