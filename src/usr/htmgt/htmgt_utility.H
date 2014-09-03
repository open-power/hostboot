/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/tmgtutility.H $                                 */
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
#ifndef HTMGT_UTILITY_H
#define HTMGT_UTILITY_H

#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>


#define    TMGT_DBG( _fmt_, _args_...) \
               TRACDCOMP( g_trac_htmgt, "D>" _fmt_, ##_args_ )

#define    TMGT_INF( _fmt_, _args_...) \
               TRACFCOMP( g_trac_htmgt,  _fmt_, ##_args_ )

#define    TMGT_WRN( _fmt_, _args_...) \
               TRACFCOMP( g_trac_htmgt, "W>" _fmt_, ##_args_ )

#define    TMGT_ERR( _fmt_, _args_...) \
               TRACFCOMP( g_trac_htmgt, "E>" _fmt_, ##_args_ )

#define    TMGT_DBG_BIN( _fmt_, _args_...) \
               TRACDBIN(  g_trac_htmgt, "D>" _fmt_, ##_args_ )

#define    TMGT_BIN( _fmt_, _args_...) \
               TRACFBIN(  g_trac_htmgt, _fmt_, ##_args_ )

inline uint16_t UINT16_GET(const uint8_t * i_ptr)
{
    return (*i_ptr) << 8 | *(i_ptr+1);
}

inline uint32_t UINT32_GET(const uint8_t * i_ptr)
{
    return (UINT16_GET(i_ptr) << 16) | UINT16_GET(i_ptr + 2);
}

inline void UINT16_PUT(uint8_t * i_ptr, uint16_t i_value)
{
    *i_ptr       = (uint8_t) (i_value >> 8);
    *(i_ptr + 1) = (uint8_t) (i_value);
}

inline void UINT32_PUT(uint8_t * i_ptr, uint32_t i_value)
{
    *i_ptr       = (uint8_t)(i_value >> 24);
    *(i_ptr + 1) = (uint8_t)(i_value >> 16);
    *(i_ptr + 2) = (uint8_t)(i_value >> 8);
    *(i_ptr + 3) = (uint8_t)(i_value);
}


namespace HTMGT
{
    // Trace definition
    extern trace_desc_t* g_trac_htmgt;

    // Create/Build an Error log and add HTMGT component trace
    void     bldErrLog(errlHndl_t &   io_err,
                       const uint8_t  i_modid,
                       const uint16_t i_rc,
                       const uint32_t i_data1 = 0,
                       const uint32_t i_data2 = 0,
                       const uint32_t i_data3 = 0,
                       const uint32_t i_data4 = 0,
                       const ERRORLOG::errlSeverity_t i_sev = ERRORLOG::ERRL_SEV_INFORMATIONAL);



} // end namespace
#endif
