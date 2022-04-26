/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hwasPlatTrace.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
/**
 *  @file hwas/hwasPlatTrace.H
 *
 *  @brief Defines platform interfaces and whatnot needed for trace in the
 *         HWAS common and platform specific functions
 */

#ifndef HWASPLATTRACE_H_
#define HWASPLATTRACE_H_

#include <trace/interface.H>
#include <errl/errlentry.H>

//******************************************************************************
// Trace descriptors that are defined in a C file
//******************************************************************************
namespace HWAS
{
    typedef trace_desc_t* HWAS_TD_t;
    extern HWAS_TD_t g_trac_dbg_hwas; // debug - fast
    extern HWAS_TD_t g_trac_imp_hwas; // important - slow
}

// Debug traces (go into fast trace buffer that can wrap often)
#define HWAS_DBG(_fmt_, _args_...) \
    TRACDCOMP(HWAS::g_trac_dbg_hwas, TRACE_FILENAME _fmt_, ##_args_)

#define HWAS_DBG_BIN(_str_, _addr_, _len_) \
    TRACDBIN(HWAS::g_trac_dbg_hwas, TRACE_FILENAME _str_, _addr_, _len_)

// Information traces (go into slow trace buffer that should not wrap often)
#define HWAS_INF(_fmt_, _args_...) \
    TRACFCOMP(HWAS::g_trac_imp_hwas, INFO_MRK TRACE_FILENAME _fmt_, ##_args_)

#define HWAS_INF_BIN(_str_, _addr_, _len_) \
    TRACFBIN(HWAS::g_trac_imp_hwas, INFO_MRK TRACE_FILENAME _str_, _addr_, _len_)

// Error traces (go into slow trace buffer that should not wrap often)
#define HWAS_ERR(_fmt_, _args_...) \
    TRACFCOMP(HWAS::g_trac_imp_hwas, ERR_MRK TRACE_FILENAME _fmt_, ##_args_)

#define HWAS_ERR_BIN(_str_, _addr_, _len_) \
    TRACFBIN(HWAS::g_trac_imp_hwas, ERR_MRK TRACE_FILENAME _str_, _addr_, _len_)

#endif // HWASPLATTRACE_H_
