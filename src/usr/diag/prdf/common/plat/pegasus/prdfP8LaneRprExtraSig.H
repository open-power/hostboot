/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8LaneRprExtraSig.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#ifndef __prdfP8LaneRprExtraSig_H
#define __prdfP8LaneRprExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE( ERepair_ERROR, 0xffff0000, "","ERepair Internal error" );
PRDR_ERROR_SIGNATURE( ERepair_FWThrExceeded, 0xffff0001, "",
                      "ERepair FW threshold exceeded" );

#endif // __prdfP8LaneRprExtraSig_H
