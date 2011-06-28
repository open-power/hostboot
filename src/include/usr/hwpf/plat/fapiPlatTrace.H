/**
 *  @file platTrace.H
 *
 *  @brief Defines the FAPI trace macros.
 *
 *  Note that platform code must provide the implementation.
 *
 *  FAPI has provided a default implementation of printfs. Platform code must
 *  provide an alternate implementation if needed.
 */

#ifndef PLATTRACE_H_
#define PLATTRACE_H_

#include <stdio.h>
#include <trace/interface.H>

//******************************************************************************
// Trace buffer names
//******************************************************************************
const char * const FAPI_INF_TRACE_NAME = "FAPI_T";
const char * const FAPI_IMP_TRACE_NAME = "FAPI_I";
const char * const FAPI_ERR_TRACE_NAME = "FAPI_E";
const char * const FAPI_DBG_TRACE_NAME = "FAPI_D";

//******************************************************************************
// Trace descriptors that are defined in a C file
//******************************************************************************
extern trace_desc_t* g_fapiInfTd;
extern trace_desc_t* g_fapiImpTd;
extern trace_desc_t* g_fapiErrTd;
extern trace_desc_t* g_fapiDbgTd;

// Information traces (standard flight recorder that can wrap often)
#define FAPI_INF(_fmt_, _args_...) TRACFCOMP(g_fapiInfTd, _fmt_, ##_args_ )

// Important traces (should not wrap often)
#define FAPI_IMP(_fmt_, _args_...) TRACFCOMP(g_fapiImpTd, _fmt_, ##_args_ )

// Error traces (should not wrap often)
#define FAPI_ERR(_fmt_, _args_...) TRACFCOMP(g_fapiErrTd, _fmt_, ##_args_ )

// Debug traces (can wrap often)
#define FAPI_DBG(_fmt_, _args_...) TRACDCOMP(g_fapiDbgTd, _fmt_, ##_args_)

#endif // PLATTRACE_H_
