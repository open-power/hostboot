/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8McsExtraSig.H $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
#ifndef __prdfP8McsExtraSig_H
#define __prdfP8McsExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE(MciFir_48_DD1Signature, 0x55550000, "MCIFIR[48]",
                                            "DD1: MCIFIRQ_INTERNAL_SCOM_ERROR");
PRDR_ERROR_SIGNATURE(MciFir_49_DD1Signature, 0x55550001, "MCIFIR[49]",
                                      "DD1: MCIFIRQ_INTERNAL_SCOM_ERROR_CLONE");

#endif // __prdfP8McsExtraSig_H
