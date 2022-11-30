/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_utility.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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
#include <console/consoleif.H>
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

#if defined(CONFIG_CONSOLE) && !defined(__HOSTBOOT_RUNTIME)
#define TMGT_CONSOLE( _fmt_, _args_...) \
    CONSOLE::displayf(CONSOLE::DEFAULT,  HTMGT_COMP_NAME, _fmt_, ##_args_ )
#else
#define TMGT_CONSOLE(_fmt_, _args_...)
#endif


// Enable this to force all HTMGT traces to console (for debug)
#if 0
#if defined(CONFIG_CONSOLE) && !defined(__HOSTBOOT_RUNTIME)
#undef TMGT_INF
#define    TMGT_INF( _fmt_, _args_...) \
               CONSOLE::displayf(CONSOLE::DEFAULT,  HTMGT_COMP_NAME, _fmt_, ##_args_ )
#undef TMGT_ERR
#define    TMGT_ERR( _fmt_, _args_...) \
               CONSOLE::displayf(CONSOLE::DEFAULT,  HTMGT_COMP_NAME, "E>" _fmt_, ##_args_ )
#endif
#endif


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

inline void INT32_PUT(uint8_t * i_ptr, int32_t i_value)
{
    *i_ptr       = (int8_t)(i_value >> 24);
    *(i_ptr + 1) = (int8_t)(i_value >> 16);
    *(i_ptr + 2) = (int8_t)(i_value >> 8);
    *(i_ptr + 3) = (int8_t)(i_value);
}


namespace HTMGT
{
    // Trace definition
    extern trace_desc_t* g_trac_htmgt;

    // Debug flags
    extern uint32_t G_debug_data;

    // Global to set OCC into OpalVM or PowerVM mode
    extern uint8_t G_system_type;  //defined in htmgt_cfgdata.C


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

    enum internalFlagTypes
    {
        FLAG_HALT_ON_OCC_SRC       = 0x00800000, // Prevent resets after SRC
        FLAG_WOF_RESET_DISABLED    = 0x00001000, // Disable ONLY WOF resets
        FLAG_DISABLE_MEM_CONFIG    = 0x00000800, // Disable sending mem config
        FLAG_HALT_ON_RESET_FAIL    = 0x00000100, // Stop additional resets
        FLAG_EXT_RESET_DISABLED    = 0x00000080, // Ignore opal-prd/BMC resets
        FLAG_DISABLE_MEM_THROTTLE  = 0x00000040,
        FLAG_IGNORE_OCC_STATE      = 0x00000020,
        FLAG_HOLD_OCCS_IN_RESET    = 0x00000010, // Ignore load/start status
        FLAG_LOAD_REQUEST_DISABLED = 0x00000008,
        FLAG_TERMINATE_ON_ERROR    = 0x00000004,
        FLAG_RESET_DISABLED        = 0x00000002, // Ignore any OCC reset
        FLAG_EXTERNAL_OVERRIDE     = 0x00000001
    };

    enum tmgtElogSubsecTypes
    {
        // Values selected to be common with FSP from tmgt_elog_parser.H
        //SUBSEC_MSG_DATA_TYPE          = 0x01,
        //SUBSEC_ERROR_DATA_TYPE        = 0x06,
        //SUBSEC_ENERGYSCALE_DATA_TYPE  = 0x08,
        //SUBSEC_OCC_ELOG_DATA_TYPE     = 0x0A,
        //SUBSEC_OCC_FFDC_DATA_TYPE     = 0x0B,
        SUBSEC_ADDITIONAL_SRC         = 0x0C,
        SUBSEC_OCC_CMD_DATA           = 0x0D,
        SUBSEC_OCC_RSP_DATA           = 0x0E,
        SUBSEC_ELOG_TYPE_HTMGT_DATA   = 0x10,
        //SUBSEC_ELOG_TYPE_OCC_RESET    = 0x11,
        //SUBSEC_ELOG_TYPE_PCAP_DATA    = 0x12,
        //SUBSEC_ELOG_TYPE_THERMAL_DATA = 0x13,
        //SUBSEC_PROC_SCOM_REGISTERS    = 0x14,
        //SUBSEC_ELOG_TYPE_OCC_TRACE    = 0x15,
        SUBSEC_OCC_BOOTLOADER_CHECKPOINT = 0x16,
        // 0xE0-0xEF are reserved for OCC Exceptions
    };

    enum htmgtPassThruCmds
    {
        PASSTHRU_OCC_STATUS             = 0x01,
        PASSTHRU_INTERNAL_FLAG          = 0x02, // get or set internal flags
        PASSTHRU_SEND_OCC_COMMAND       = 0x03, // send raw OCC command
        PASSTHRU_CLEAR_RESET_COUNTS     = 0x04,
        PASSTHRU_EXIT_SAFE_MODE         = 0x05,
        PASSTHRU_RESET_PM_COMPLEX       = 0x06,
        PASSTHRU_QUERY_MODE_FUNCTION    = 0x07,
        PASSTHRU_ENA_DIS_OPAL_STATE     = 0x08,
        PASSTHRU_SET_OCC_STATE          = 0x09,
        PASSTHRU_WOF_RESET_REASONS      = 0x0A,
        PASSTHRU_OCC_CFG_DATA           = 0x0C,
        PASSTHRU_SET_MODE               = 0x0D,
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


    /**
     * Helper function to return the DIMM number as the OCC sees it.
     * There can be 8 DIMMs per Centaur.
     *
     * @param i_mba - the MBA the DIMM is on
     * @param i_dimm - the DIMM
     * @return - a number 0-7
     */
    uint8_t getOCCDIMMPos(const TARGETING::TargetHandle_t i_mba,
                          const TARGETING::TargetHandle_t i_dimm);


    /**
     * @brief Internal utility function to convert the OCC state to a string
     *
     * @param[in] i_state - OCC state
     *
     * @return text string description of state
     */
    const char *state_string(const uint8_t i_state);


    /**
     * @brief Retrieve the internal flag (attribute) value
     *
     * @return the flag value (on error will return 0)
     */
     uint32_t get_int_flags();


     /**
      * @brief Update internal flags to specified value
      *
      * @param[in] i_value - new value for internal flags
      */
     void set_int_flags(const uint32_t i_value);


     /**
      * @brief Query if specified internal flag(s) are set
      *
      * @param[in] i_mask - bits to query the internalFlags
      *
      * @return true if all of the bits of i_mask are set in internalFlags
      */
     bool int_flags_set(const uint32_t i_mask);

     /**
      * @brief Check if OCC reset counters need to be cleared.
      *        Function is called periodically (OCC_RCOUNT_RESET_TIME)
      *
      */
     void check_reset_count();

     /**
      * @brief Add OCC Bootloader Checkpoint data to specified error log
      *
      * @param[in] i_err    - error log
      * @param[in] i_target - OCC or proc target
      */
     void addBootloaderCheckpointData(errlHndl_t i_err, TARGETING::TargetHandle_t i_target);

} // end namespace
#endif
