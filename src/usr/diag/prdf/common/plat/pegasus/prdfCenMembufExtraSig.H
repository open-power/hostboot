/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMembufExtraSig.H $ */
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

#ifndef __prdfCenMembufExtraSig_H
#define __prdfCenMembufExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE(MnfgDramCte,    0x44440000, "", "MNFG per DRAM CTE");
PRDR_ERROR_SIGNATURE(MnfgHrCte,      0x44440001, "", "MNFG per half-rank CTE");
PRDR_ERROR_SIGNATURE(MnfgDimmCte,    0x44440002, "", "MNFG per DIMM CTE");

#endif // __prdfCenMembufExtraSig_H
