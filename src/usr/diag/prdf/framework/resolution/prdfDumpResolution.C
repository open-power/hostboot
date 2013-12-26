/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/resolution/prdfDumpResolution.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2014              */
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
