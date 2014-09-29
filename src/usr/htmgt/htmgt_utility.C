/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/tmgtutility.C $                                 */
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
#include "htmgt_utility.H"


namespace HTMGT
{
    // Trace definition
    trace_desc_t* g_trac_htmgt = NULL;
    TRAC_INIT(&g_trac_htmgt, HTMGT_COMP_NAME, 4*KILOBYTE);

    // Debug flags
    uint32_t G_debug_data = 0;
    uint32_t G_debug_trace = DEBUG_TRACE_FULL_NONVERBOSE; // TODO RTC 115922


    // Create/Build an Error log and add HTMGT component trace
    void bldErrLog(errlHndl_t &   io_err,
                   const uint8_t  i_modid,
                   const uint16_t i_rc,
                   const uint32_t i_data1,
                   const uint32_t i_data2,
                   const uint32_t i_data3,
                   const uint32_t i_data4,
                   const ERRORLOG::errlSeverity_t i_sev,
                   const bool i_addFwCallout)
    {
        TMGT_INF("bldErrLog(mod: 0x%02X, rc: 0x%02X, data: 0x%08X %08X %08X"
                 " %08X, sev: 0x%02X, fw:%c",
                 i_modid, i_rc, i_data1, i_data2, i_data3, i_data4,
                 i_sev, i_addFwCallout?'y':'n');
        // TODO RTC 109224 - RAS review what logs need fw callout

        if (NULL == io_err)
        {
            io_err = new ERRORLOG::ErrlEntry(i_sev,
                                             i_modid,
                                             i_rc,
                                             ((uint64_t)i_data1 << 32) |
                                             i_data2,
                                             ((uint64_t)i_data3 << 32) |
                                             i_data4,
                                             i_addFwCallout);
            io_err->collectTrace("HTMGT");
        }
        else
        {
            io_err->collectTrace("HTMGT");
        }
    }



    // Internal utility to convert OCC command type to a string
    const char *command_string(const uint8_t i_cmd)
    {
        struct string_data_t
        {
            uint8_t       str_num;
            const char    *str_data;
        };

        const static struct string_data_t L_cmd_string[] = {
            {OCC_CMD_POLL, "POLL"},
            {OCC_CMD_CLEAR_ERROR_LOG, "CLEAR_ELOG"},
            {OCC_CMD_SET_STATE, "SET_STATE"},
            {OCC_CMD_SETUP_CFG_DATA, "SET_CFG_DATA"},
            {OCC_CMD_RESET_PREP, "RESET_PREP"},
            {OCC_CMD_GET_FIELD_DEBUG_DATA, "GET_FIELD_DEBUG_DATA"},
            // OCC_CMD_END_OF_TABLE should be the last entry
            {OCC_CMD_END_OF_TABLE, "Unknown Command"}
        };
        const uint8_t l_total =
            sizeof(L_cmd_string) / sizeof(struct string_data_t);

        // TODO RTC 109066
        uint8_t l_idx = 0;
        for (l_idx=0; l_idx<l_total; l_idx++)
        {
            if (i_cmd == L_cmd_string[l_idx].str_num)
            {
                // Return Code found
                break;
            }
        }

        if (l_total == l_idx)
        {
            // Set index to last entry record
            l_idx = l_total - 1;
        }

        return L_cmd_string[l_idx].str_data;
    } // end command_string()



} // end namespace
