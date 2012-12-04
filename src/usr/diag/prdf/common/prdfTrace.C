/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfTrace.C $                        */
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

/**
 * @file prdfTrace.C
 * @brief prdf trace descriptor
 */

#include "prdfTrace.H"
#include <limits.h>

namespace PRDF
{
    tracDesc_t traceDesc = 0;
#ifdef __HOSTBOOT_MODULE
    TRAC_INIT( &traceDesc, PRDF_COMP_NAME, KILOBYTE );
#else
    TRAC_INIT( &traceDesc, PRDF_COMP_NAME, 4096 );
#endif
} //End namespace PRDF

