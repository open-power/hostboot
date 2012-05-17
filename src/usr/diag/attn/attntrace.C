/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attntrace.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 * @file attntrace.C
 *
 * @brief HBATTN trace descriptors.
 */

#include "attntrace.H"

namespace ATTN
{

trace_desc_t * fastTd = 0, * slowTd = 0;

TRAC_INIT(&fastTd, "ATTN_FAST", 4096);
TRAC_INIT(&slowTd, "ATTN_SLOW", 4096);
}
