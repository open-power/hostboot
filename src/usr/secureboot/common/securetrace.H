/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/common/securetrace.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
 *  @file securetrace.H
 *  @brief Provides trace interface for secureboot
 */

#ifndef __SECURETRACE_H
#define __SECURETRACE_H

#include <trace/interface.H>

namespace SECUREBOOT
{

extern trace_desc_t* g_trac_secure;

}

#define SB_ENTER(args...) \
    TRACFCOMP(SECUREBOOT::g_trac_secure,ENTER_MRK " " args)

#define SB_EXIT(args...) \
    TRACFCOMP(SECUREBOOT::g_trac_secure,EXIT_MRK " " args)

#define SB_ERR(args...) \
    TRACFCOMP(SECUREBOOT::g_trac_secure,ERR_MRK " " args)

#define SB_INF(args...) \
    TRACFCOMP(SECUREBOOT::g_trac_secure,INFO_MRK " " args)

#define SB_DBG(args...) \
    TRACDCOMP(SECUREBOOT::g_trac_secure,INFO_MRK " " args)

#define SB_INF_BIN(args...) \
    TRACFBIN(SECUREBOOT::g_trac_secure,args)

#define SB_DBG_BIN(args...) \
    TRACDBIN(SECUREBOOT::g_trac_secure,args)

#define SB_UNIT(args...) \
    TRACUCOMP(SECUREBOOT::g_trac_secure,"U> " args)

#define SB_UNIT_BIN(args...) \
    TRACUBIN(SECUREBOOT::g_trac_secure,args)

#endif
