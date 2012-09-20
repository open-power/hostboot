/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/rule/prdrSignatures.H $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2007,2012              */
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

#include <stdint.h>

// Create a constant integer for PRDR_ERROR_SIGNATURE( foo, 0x1, "asdf", "ASDF")
#define PRDR_ERROR_SIGNATURE(a,b,c,d) \
            const uint32_t PRDFSIG_##a = b

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- -------------------------------
//           D586213  f310 02/19/07 iawillia Add extra signature support.
// End Change Log *****************************************************

