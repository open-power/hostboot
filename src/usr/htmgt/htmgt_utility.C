/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_utility.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
#include "htmgt_occmanager.H"
#include <targeting/common/commontargeting.H>
#include <targeting/common/attributes.H>
#include <time.h>

using namespace TARGETING;

namespace HTMGT
{
    // Trace definition
    trace_desc_t* g_trac_htmgt = NULL;
    TRAC_INIT(&g_trac_htmgt, HTMGT_COMP_NAME, 4*KILOBYTE);

    // Debug flags
    uint32_t G_debug_data = 0;
    uint32_t G_debug_trace = DEBUG_TRACE_FULL_NONVERBOSE;

    // Timer for periodically clearing OCC reset counts (seconds)
    const uint64_t OCC_RCOUNT_RESET_TIME = 60 * 60; // 1 hour

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
        // TODO RTC 124739 - RAS review what logs need fw callout

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

            uint32_t additionalSrc[] =
            {
                uint32_t(HTMGT_COMP_ID | i_rc), uint32_t(i_modid),
                uint32_t(i_sev), uint32_t(i_addFwCallout?1:0),
                i_data1, i_data2, i_data3, i_data4
            };
            io_err->addFFDC(HTMGT_COMP_ID,
                            additionalSrc,
                            sizeof(additionalSrc),
                            1,  // version
                            SUBSEC_ADDITIONAL_SRC);
        }

        const uint16_t l_comp_id = i_rc & 0xFF00;
        if ((OCCC_COMP_ID != l_comp_id) &&
            (PGPE_COMP_ID != l_comp_id) &&
            (XGPE_COMP_ID != l_comp_id))
        {
            // Add HB firmware callout
            io_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_MED);
        }

        // Add HTMGT/OCC state data
        uint16_t occ_data_len = 0;
        uint8_t  occ_data[OCC_MAX_DATA_LENGTH];
        OccManager::getHtmgtData(occ_data_len, occ_data);
        if (occ_data_len > 0)
        {
            io_err->addFFDC(HTMGT_COMP_ID,
                            occ_data,
                            occ_data_len,
                            1, //version
                            SUBSEC_ELOG_TYPE_HTMGT_DATA);
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
            {OCC_CMD_SET_POWER_CAP, "SET_POWER_CAP"},
            {OCC_CMD_RESET_PREP, "RESET_PREP"},
            {OCC_CMD_DEBUG_PASS_THROUGH, "DEBUG_PASSTHRU"},
            {OCC_CMD_AME_PASS_THROUGH, "AME_PASSTHRU"},
            {OCC_CMD_GET_FIELD_DEBUG_DATA, "GET_FIELD_DEBUG_DATA"},
            {OCC_CMD_MFG_TEST, "MFG_TEST"},
            // OCC_CMD_END_OF_TABLE should be the last entry
            {OCC_CMD_END_OF_TABLE, "Unknown Command"}
        };
        const uint8_t l_total =
            sizeof(L_cmd_string) / sizeof(struct string_data_t);

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


    // Internal utility function to convert the OCC state to a string
    const char *state_string(const uint8_t i_state)
    {
        switch(i_state)
        {
            case OCC_STATE_NO_CHANGE:     return("NO CHANGE"); break;
            case OCC_STATE_STANDBY:       return("STANDBY"); break;
            case OCC_STATE_OBSERVATION:   return("OBSERVATION"); break;
            case OCC_STATE_ACTIVE:        return("ACTIVE"); break;
            case OCC_STATE_SAFE:          return("SAFE"); break;
            case OCC_STATE_RESET:         return("RESET"); break;
            case OCC_STATE_CHARACTERIZATION:  return("CHARACTERIZATION"); break;
            case OCC_STATE_IN_TRANSITION: return("IN TRANSITION"); break;
            case OCC_STATE_LOADING:       return("LOADING"); break;
            case OCC_STATE_UNKNOWN:       return("UNKNOWN"); break;
            default:                      break;
        }
        return("UNKNOWN");
    }

    uint8_t getOCCDIMMPos(const TargetHandle_t i_mba,
                          const TargetHandle_t i_dimm)
    {
        //To make the OCC DIMM # 0 - 7: 0bABC
        //  A: MBA  ATTR_CHIP_UNIT: 0 or 1
        //  B: DIMM ATTR_MEM_PORT:  0 or 1
        //  C: DIMM ATTR_POS_ON_MEM_PORT:  0 or 1

        //Note: No CDIMM systems in plan.  May need to revisit
        //this if there are any as OCC may not care about logical DIMMs.

        const uint8_t mbaUnit = i_mba->getAttr<ATTR_CHIP_UNIT>();
        const uint8_t mbaPort = i_dimm->getAttr<ATTR_MEM_PORT>();
        const uint8_t mbaDIMM = i_dimm->getAttr<ATTR_POS_ON_MEM_PORT>();

        TMGT_DBG("DIMM 0x%X unit %d port %d pos %d = %d",
                 i_dimm->getAttr<ATTR_HUID>(),
                 mbaUnit, mbaPort, mbaDIMM,
                 ((mbaUnit << 2) | (mbaPort << 1) | mbaDIMM));

        return ((mbaUnit << 2) | (mbaPort << 1) | mbaDIMM);
    }


    // Retrieve the internalFlags
    uint32_t get_int_flags()
    {
        uint32_t flags = 0;
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        if (sys)
        {
            sys->tryGetAttr<TARGETING::ATTR_HTMGT_INTERNAL_FLAGS>(flags);
        }
        return flags;
    }


    // Set the internal flags value
    void set_int_flags(const uint32_t i_value)
    {
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        if (sys)
        {
            sys->trySetAttr<TARGETING::ATTR_HTMGT_INTERNAL_FLAGS>(i_value);
        }
    }


    // Query if specified internal flag(s) are set
    bool int_flags_set(const uint32_t i_mask)
    {
        bool flags_are_set = false;

        const uint32_t flags = get_int_flags();
        if ((flags & i_mask) == i_mask)
        {
            flags_are_set = true;
        }

        return flags_are_set;
    }

    // Check if reset count needs to be cleared due to periodic timer.
    // Should not be called if the system is in safe mode.
    void check_reset_count()
    {
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        if (sys)
        {
            uint8_t safeMode = 0;
            sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
            if (safeMode == 0)
            {
                const uint64_t last_clear =
                    sys->getAttr<ATTR_HTMGT_PMCOMPLEX_RESET_COUNT_TIMER>();
                timespec_t curTime;

                if (clock_gettime(CLOCK_MONOTONIC, &curTime) == 0)
                {
                    bool update_attr = false;
                    if (last_clear == 0)
                    {
                        // First call since boot
                        update_attr = true;
                    }
                    else if ((curTime.tv_sec < last_clear) ||
                             (curTime.tv_sec - last_clear >
                              OCC_RCOUNT_RESET_TIME))
                    {
                        // Clear reset counters (counter wrapped/exceeded time)
                        OccManager::clearResetCounts();
                        update_attr = true;
                    }
                    if (update_attr)
                    {
                        sys->setAttr
                            <TARGETING::ATTR_HTMGT_PMCOMPLEX_RESET_COUNT_TIMER>
                            (curTime.tv_sec);
                    }
                }
            }
        }
    }

} // end namespace
