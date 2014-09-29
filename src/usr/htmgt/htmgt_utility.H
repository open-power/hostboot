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
#include "htmgt_occcmd.H"


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

    // Debug flags
    extern uint32_t G_debug_data;
    enum debugTraceTypes
    {
        // Types are bit flags so can enable multiple at once
        DEBUG_TRACE_OFF             = 0x00,
        DEBUG_TRACE_OCCCMD          = 0x01, // OCC command tracing
        DEBUG_TRACE_OCCCMD_FULL     = 0x02, // full OCC command tracing
        DEBUG_TRACE_FULL_NONVERBOSE = 0x7FFFFFFF,
        DEBUG_TRACE_VERBOSE         = 0x80000000, // verbose tracing
        DEBUG_TRACE_FULL            = 0xFFFFFFFF
    };
    extern uint32_t G_debug_trace;


    enum tmgtElogSubsecTypes
    {
        // Values selected to be common with FSP from tmgt_elog_parser.H
        //SUBSEC_MSG_DATA_TYPE          = 0x01,
        //SUBSEC_ERROR_DATA_TYPE        = 0x06,
        //SUBSEC_ENERGYSCALE_DATA_TYPE  = 0x08,
        //SUBSEC_OCC_ELOG_DATA_TYPE     = 0x0A,
        //SUBSEC_OCC_FFDC_DATA_TYPE     = 0x0B,
        //SUBSEC_MSG_DATA_TRUNCATED     = 0x0C,
        SUBSEC_OCC_CMD_DATA           = 0x0D,
        SUBSEC_OCC_RSP_DATA           = 0x0E,
        //SUBSEC_ELOG_TYPE_TOIF_RESET   = 0x10,
        //SUBSEC_ELOG_TYPE_OCC_RESET    = 0x11,
        //SUBSEC_ELOG_TYPE_PCAP_DATA    = 0x12,
        //SUBSEC_ELOG_TYPE_THERMAL_DATA = 0x13,
        //SUBSEC_PROC_SCOM_REGISTERS    = 0x14,
        // 0xE0-0xEF are reserved for OCC Exceptions
    };


    /**
     * @brief Create/Build an Error log and add HTMGT component trace
     *
     * @param[in,out] io_err    Error handle to use or NULL to create new handle
     * @param[in]     i_modid   Module ID
     * @param[in]     i_rc      Return Code
     * @param[in]     i_data1   User data word 1
     * @param[in]     i_data2   User data word 2
     * @param[in]     i_data3   User data word 3
     * @param[in]     i_data4   User data word 4
     * @param[in]     i_sev     Error severity
     * @param[in]     i_addFwCallout  true if a FW Callout should be added
     */
    void     bldErrLog(errlHndl_t &   io_err,
                       const uint8_t  i_modid,
                       const uint16_t i_rc,
                       const uint32_t i_data1 = 0,
                       const uint32_t i_data2 = 0,
                       const uint32_t i_data3 = 0,
                       const uint32_t i_data4 = 0,
                       const ERRORLOG::errlSeverity_t i_sev =
                       ERRORLOG::ERRL_SEV_INFORMATIONAL,
                       const bool i_addFwCallout = false);


    /**
     * @brief Internal utility to convert OCC command type to a string
     *
     * @param[in]  i_cmd  OCC command type
     *
     * @return text string description of command
     */
    const char *command_string(const uint8_t i_cmd);


} // end namespace
#endif
