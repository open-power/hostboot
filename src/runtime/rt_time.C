/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/runtime/rt_time.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#include <sys/time.h>
#include <runtime/interface.h>

#define BITS_32_TO_63_MASK 0x00000000FFFFFFFF

void nanosleep(uint64_t sec, uint64_t nsec)
{
    if (g_hostInterfaces && g_hostInterfaces->nanosleep)
    {
        g_hostInterfaces->nanosleep(sec, nsec);
    }
}

int clock_gettime(clockid_t i_clkId, timespec_t* o_tp)
{
    int l_rc = -1;

    if (g_hostInterfaces && g_hostInterfaces->clock_gettime)
    {
        l_rc = g_hostInterfaces->clock_gettime(i_clkId, o_tp);

        // If the back-half (bits 32:63) are all 0's then the
        // nanoseconds are stored in the first 32 bits of the tv_nsec
        // member of the timespec_t struct. We must shift over so later
        // hostboot code interprets this correctly
        if( (o_tp->tv_nsec & BITS_32_TO_63_MASK) == 0x0)
        {
            o_tp->tv_nsec = o_tp->tv_nsec >> 32;
        }
    }
    return l_rc;
}
