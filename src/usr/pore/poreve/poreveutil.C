//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/poreveutil.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#include <trace/interface.H>

//******************************************************************************
// Trace descriptors
//******************************************************************************
trace_desc_t* g_poreDbgTd = NULL;
trace_desc_t* g_poreErrTd = NULL;

//******************************************************************************
// Global TracInit objects. Construction will initialize the trace buffer
//******************************************************************************
TRAC_INIT(&g_poreDbgTd, "PORE_D", 4096);
TRAC_INIT(&g_poreErrTd, "PORE_E", 4096);
