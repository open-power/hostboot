/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatCalloutUtil.C $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

/** @file prdfPlatCalloutUtil.C */

#include <prdfPlatCalloutUtil.H>

// Framework includes
#include <prdfErrlUtil.H>
#include <prdfPfa5Data.h>
#include <prdfPlatServices.H>

// Pegasus includes
#include <prdfMemoryMru.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace CalloutUtil
{

void calloutMemoryMru( errlHndl_t io_errl, const MemoryMru & i_memmru,
                       const HWAS::callOutPriority i_priority,
                       const HWAS::DeconfigEnum    i_deconfigState,
                       const HWAS::GARD_ErrorType  i_gardType )
{
    // Add all parts to the error log.
    TargetHandleList partList = i_memmru.getCalloutList();
    for ( TargetHandleList::iterator it = partList.begin();
          it != partList.end(); it++ )
    {
        io_errl->addHwCallout( *it, i_priority, i_deconfigState, i_gardType );
    }

    // Add the MemoryMru to the capture data.
    uint32_t tmpMru = i_memmru.toUint32();
    PRDF_ADD_FFDC( io_errl, &tmpMru, sizeof(tmpMru), ErrlVer1, ErrlMruData_1 );
}

} // end namespace CalloutUtil

} // end namespace PRDF

