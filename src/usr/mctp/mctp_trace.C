/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/mctp_trace.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#include "mctp_trace.H"
#include <string.h>
#include <libmctp.h>

/**
 * @file  mctp_trace.C
 * @brief Source code for the function to be supplied for the libmctp core
 *        code's trace logic.
 */

void mctp_log_fn(int level, const char * fmt, va_list args)
{
    if (level <= MCTP_LOG_WARNING)
    {
        const size_t msg_buf_len = 180;
        char msg_buf[msg_buf_len];
        // vsnprintf will fill up to msg_buf_len-1 bytes of trace data followed
        // by a single '\0' null-terminator byte. Any excess characters whose
        // index is beyond msg_buf_len-1 will be ignored.
        vsnprintf( &msg_buf[0], msg_buf_len, fmt, args);
        TRACFCOMP(g_trac_mctp, "mctp_trace > %s", msg_buf);
    }
}