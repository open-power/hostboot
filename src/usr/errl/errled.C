/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errled.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
 *  @file errled.C
 *
 *  @brief  Code to manage the contents of the extended user defined data
 *  section of an error log.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hbotcompid.H>
#include <errl/errlentry.H>

namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;

/***************************************************************************/
// Data Export

uint64_t ErrlED::flatten( void * io_pBuffer, const uint64_t i_cbBuffer )
{
    uint64_t serialsize = 0;

    if( i_cbBuffer >= flatSize() )
    {
        memcpy(io_pBuffer, &iv, flatSize());
        serialsize += flatSize();
    }
    else
    {
         TRACFCOMP( g_trac_errl, "ErrlED::flatten: buffer too small" );
    }
    return serialsize;
}

uint64_t ErrlED::unflatten(const void* const i_buffer)
{
    const auto hdr = static_cast<const pelEDHeaderSection_t*>(i_buffer);

    memcpy(&iv, hdr, SLEN);

    return SLEN;
}

}  // namespace
