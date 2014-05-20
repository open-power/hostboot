/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/trace.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
/* [+] Google Inc.                                                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

#ifndef __TARGETING_COMMON_TRACE_H
#define __TARGETING_COMMON_TRACE_H

/**
 *  @file targeting/common/trace.H
 *
 *  @brief Targeting related trace macros.  Callers of these macros must
 *      define TARG_NAMESPACE, TARG_CLASS, and TARG_FN as appropriate
 */

//******************************************************************************
// Includes
//******************************************************************************

// Other includes
#include <targeting/adapters/traceadapter.H>
#ifdef __HOSTBOOT_MODULE
#include <config.h>
#endif

#define TARG_LOC TARG_NAMESPACE TARG_CLASS TARG_FN ": "

#define TARG_ERR_LOC ERR_MRK " " TARG_LOC

#define TARG_TAG "[TARG]"

#ifdef CONFIG_TARG_TRACE_AS_DEBUG
#define TARG_ENTER(args...) \
    TRACDCOMP(TARGETING::g_trac_targeting,TARG_TAG " " \
        ENTER_MRK " " TARG_NAMESPACE \
        TARG_CLASS TARG_FN " " args)
#define TARG_EXIT(args...) \
    TRACDCOMP(TARGETING::g_trac_targeting,TARG_TAG " " \
        EXIT_MRK " " TARG_NAMESPACE \
        TARG_CLASS TARG_FN " " args)
#else
#define TARG_ENTER(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " \
        ENTER_MRK " " TARG_NAMESPACE \
        TARG_CLASS TARG_FN " " args)
#define TARG_EXIT(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " \
        EXIT_MRK " " TARG_NAMESPACE \
        TARG_CLASS TARG_FN " " args)
#endif

#define TARG_ERR(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " ERR_MRK " " args)

#define TARG_INF(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " INFO_MRK " " args)

#define TARG_DBG(args...) \
    TRACDCOMP(TARGETING::g_trac_targeting,TARG_TAG " " INFO_MRK " " args)

#define TARG_BIN(args...) \
    TRACFBIN(TARGETING::g_trac_targeting,TARG_TAG " " args)

#endif // __TARGETING_COMMON_TRACE_H
