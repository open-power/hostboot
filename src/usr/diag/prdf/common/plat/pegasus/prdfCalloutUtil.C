/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCalloutUtil.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

/** @file prdfCalloutUtil.C */

#include <prdfCalloutUtil.H>

#include <iipServiceDataCollector.h>

namespace PRDF
{
namespace CalloutUtil
{

void defaultError( STEP_CODE_DATA_STRUCT & i_sc )
{
    i_sc.service_data->SetCallout( NextLevelSupport_ENUM );
    i_sc.service_data->SetCallout( SP_CODE );
    i_sc.service_data->SetServiceCall();
}

} // end namespace CalloutUtil
} // end namespace PRDF

