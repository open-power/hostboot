/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatTrace.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
const char * const FAPI_TRACE_NAME = "FAPI";
const char * const FAPI_IMP_TRACE_NAME = "FAPI_I";
const char * const FAPI_SCAN_TRACE_NAME = "SCAN";

//******************************************************************************
// Trace descriptors that are defined in a C file
//******************************************************************************
extern trace_desc_t* g_fapiTd;
extern trace_desc_t* g_fapiImpTd;
extern trace_desc_t* g_fapiScanTd;

// Information traces (go into fast trace buffer that can wrap often)
#define FAPI_INF(_fmt_, _args_...) TRACFCOMP(g_fapiTd, TRACE_FILENAME _fmt_, ##_args_ )

// Important traces (go into slow trace buffer that should not wrap often)
#define FAPI_IMP(_fmt_, _args_...) TRACFCOMP(g_fapiImpTd, TRACE_FILENAME _fmt_, ##_args_ )

// Error traces (go into slow trace buffer that should not wrap often)
#define FAPI_ERR(_fmt_, _args_...) TRACFCOMP(g_fapiImpTd, TRACE_FILENAME _fmt_, ##_args_ )

// Debug traces (go into fast trace buffer that can wrap often)
#define FAPI_DBG(_fmt_, _args_...) TRACDCOMP(g_fapiTd, TRACE_FILENAME _fmt_, ##_args_)

// Scan traces
#define FAPI_SCAN(_fmt_, _args_...) TRACSCOMP(g_fapiScanTd, _fmt_, ##_args_)

#endif // PLATTRACE_H_
