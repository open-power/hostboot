/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/nvram/import/skiboot.h $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __SKIBOOT_H
#define __SKIBOOT_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <tracinterface.H>
#include <trace/trace.H>
#include <nvram/nvram_interface.H>

typedef uint16_t beint16_t;
typedef beint16_t be16;

#define BE16_TO_CPU(le_val) ((uint16_t)(le_val))

static inline uint16_t be16_to_cpu(beint16_t be_val)
{
    return BE16_TO_CPU(be_val);
}

// For console logging
#define PR_EMERG    0
#define PR_ALERT    1
#define PR_CRIT     2
#define PR_ERR      3
#define PR_WARNING  4
#define PR_NOTICE   5
#define PR_PRINTF   PR_NOTICE
#define PR_INFO     6
#define PR_DEBUG    7
#define PR_TRACE    8
#define PR_INSANE   9

// Skiboot-specific trace plug-in
#define prlog(l, f, args...) \
    do { \
        if(l == PR_TRACE || \
           l <= PR_ERR) \
        { \
            TRACFCOMP(NVRAM_TRACE::g_trac_nvram, f, ##args); \
        } \
        else \
        { \
            TRACDCOMP(NVRAM_TRACE::g_trac_nvram, f, ##args); \
        } \
    } while(0)

#define prerror(fmt...) do { prlog(PR_ERR, fmt); } while(0)

#define prlog_once(arg, ...)            \
({                      \
    static bool __prlog_once = false;   \
    if (!__prlog_once) {            \
        __prlog_once = true;        \
        prlog(arg, ##__VA_ARGS__);  \
    }                   \
})

extern "C"
{
// Various stubs for NVRAM checking/manipulation. Note that on hostboot
// side we rely on getSectionInfo to carry out most of these tasks.
bool nvram_has_loaded(void)
{
    return true;
}

bool nvram_wait_for_load(void)
{
    return true;
}

bool nvram_validate(void)
{
    return true;
}
}

#endif
