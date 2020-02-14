/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/common/pldmtrace.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
 *  @file pldmtrace.H
 *  @brief Provides trace interface for pldm
 */

#ifndef __PLDMTRACE_H
#define __PLDMTRACE_H

#include <trace/interface.H>

namespace PLDM
{

extern trace_desc_t* g_trac_pldm;

}

#define PLDM_ENTER(args...) \
    TRACFCOMP(PLDM::g_trac_pldm,ENTER_MRK " " args)

#define PLDM_EXIT(args...) \
    TRACFCOMP(PLDM::g_trac_pldm,EXIT_MRK " " args)

#define PLDM_ERR(args...) \
    TRACFCOMP(PLDM::g_trac_pldm,ERR_MRK " " args)

#define PLDM_INF(args...) \
    TRACFCOMP(PLDM::g_trac_pldm,INFO_MRK " " args)

#define PLDM_DBG(args...) \
    TRACDCOMP(PLDM::g_trac_pldm,INFO_MRK " " args)

#define PLDM_INF_BIN(args...) \
    TRACFBIN(PLDM::g_trac_pldm,args)

#define PLDM_DBG_BIN(args...) \
    TRACDBIN(PLDM::g_trac_pldm,args)

#define PLDM_UNIT(args...) \
    TRACUCOMP(PLDM::g_trac_pldm,"U> " args)

#define PLDM_UNIT_BIN(args...) \
    TRACUBIN(PLDM::g_trac_pldm,args)

#endif