/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfTrace.H $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef PRDF_TRACE_H
#define PRDF_TRACE_H

#include <tracinterface.H>
#include <prdf_service_codes.H>

namespace PRDF
{
    #ifdef __HOSTBOOT_MODULE
    typedef trace_desc_t* tracDesc_t;
    #endif

    extern tracDesc_t traceDesc;
}

#ifdef __HOSTBOOT_MODULE
  // FIXME: Will need to make a change in hbotcompid.H later.
  #define PRDF_COMP_ID   HBPRDF_COMP_ID
  #define PRDF_COMP_NAME HBPRDF_COMP_NAME
#endif

// field traces -------------------

#define PRDF_TRAC(args...)  TRACFCOMP(PRDF::traceDesc, args)
#define PRDF_ENTER(args...) TRACFCOMP(PRDF::traceDesc, ENTER_MRK"" args)
#define PRDF_EXIT(args...)  TRACFCOMP(PRDF::traceDesc, EXIT_MRK"" args)
#define PRDF_ERR(args...)   TRACFCOMP(PRDF::traceDesc, ERR_MRK"" args)
#define PRDF_INF(args...)   TRACFCOMP(PRDF::traceDesc, INFO_MRK"" args)

// debug traces -------------------

#define PRDF_DTRAC(args...)  TRACDCOMP(PRDF::traceDesc, args)
#define PRDF_DENTER(args...) TRACDCOMP(PRDF::traceDesc, ENTER_MRK"" args)
#define PRDF_DEXIT(args...)  TRACDCOMP(PRDF::traceDesc, EXIT_MRK"" args)

#endif // PRDF_TRACE_H

