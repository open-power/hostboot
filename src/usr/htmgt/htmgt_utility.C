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
    TRAC_INIT(&g_trac_htmgt, HTMGT_COMP_NAME, 2*KILOBYTE);

    // Create/Build an Error log and add HTMGT component trace
    void bldErrLog(errlHndl_t &   io_err,
                   const uint8_t  i_modid,
                   const uint16_t i_rc,
                   const uint32_t i_data1,
                   const uint32_t i_data2,
                   const uint32_t i_data3,
                   const uint32_t i_data4,
                   const ERRORLOG::errlSeverity_t i_sev)
    {
        TMGT_INF("bldErrLog(mod: 0x%02X, rc: 0x%02X, data: 0x%08X %08X %08X %08X, sev: 0x%02X",
                 i_modid, i_rc, i_data1, i_data2, i_data3, i_data4, i_sev);

        if (NULL == io_err)
        {
            io_err = new ERRORLOG::ErrlEntry
                (i_sev,
                 i_modid,
                 i_rc,
                 ((uint64_t)i_data1 << 32) | i_data2,
                 ((uint64_t)i_data3 << 32) | i_data4,
                 true /*Add HB Software Callout TODO RTC 115422 RAS review*/);

            io_err->collectTrace("HTMGT");
        }
        else
        {
            io_err->collectTrace("HTMGT");
        }
    }

} // end namespace
