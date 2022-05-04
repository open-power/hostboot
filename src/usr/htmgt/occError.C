/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/occError.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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

#include <htmgt/htmgt.H>
#include <htmgt/htmgt_reasoncodes.H>
#include "htmgt_utility.H"
#include "occError.H"
#include "htmgt_occcmd.H"
#include "htmgt_occmanager.H"

#include <isteps/pm/occAccess.H>
#include <console/consoleif.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <variable_buffer.H>
#include <targeting/targplatutil.H>
#include <targeting/common/mfgFlagAccessors.H>


namespace HTMGT
{

    // Translate OCC priorty
    bool elogXlateSrciPriority(const uint8_t i_priority,
                               HWAS::callOutPriority & o_priority)
    {
        bool l_found = false;
        uint8_t l_index = 0x00;

        // Loop through the occPriorityXlate until we find a priority or
        // reach the end of the struct.
        while (l_index < OCC_SRCI_PRIORITY_XLATE_SIZE)
        {
            //If the priority matches then return the SRC.
            if (i_priority == occPriorityXlateTbl[l_index].occPriority)
            {
                o_priority = occPriorityXlateTbl[l_index].errlPriority;
                l_found = true;
                break;
            }
            l_index++;
        }
        return l_found;
    }


    // Translate component id
    bool elogGetTranslationData(const uint8_t i_compId,
                                tmgtCompxlateType &o_dataType,
                                uint32_t &o_compData)
    {
        bool l_found = false;

        for (uint16_t l_index = 0 ; l_index < TMGT_MAX_COMP_IDS ; l_index++)
        {
            if (i_compId == tmgt_compXlateTable[l_index].compId)
            {
                o_dataType = tmgt_compXlateTable[l_index].dataType;
                o_compData = tmgt_compXlateTable[l_index].data;
                l_found    = true;
                break;
            }
        }
        return l_found;
    }


    // Process elog entry from OCC poll response
    void Occ::occProcessElog(const uint8_t  i_id,
                             const uint32_t i_address,
                             const uint16_t i_length,
                             const uint8_t  i_source)
    {
        errlHndl_t  l_errlHndl = nullptr;

        compId_t l_comp_id = OCCC_COMP_ID;
        if (i_source == OCC_ERRSRC_PGPE)
        {
            l_comp_id = PGPE_COMP_ID;
        }
        else if (i_source == OCC_ERRSRC_XGPE)
        {
            l_comp_id = XGPE_COMP_ID;
        }
        else if (i_source == OCC_ERRSRC_QME)
        {
            l_comp_id = QME_COMP_ID;
        }
        else if (i_source != OCC_ERRSRC_405)
        {
            TMGT_ERR("occProcessElog: Invalid elog source specified 0x%02X",
                     i_source);
        }

        // Read data from SRAM (length must be multiple of 8 bytes)
        const uint16_t l_length = (i_length) & 0xFFF8;
        if ((l_length > 0) && (i_address != 0))
        {
            fapi2::variable_buffer l_buffer(l_length*8); //convert to bits
// HBOCC is only defined for HTMGT
#ifdef CONFIG_HTMGT
            l_errlHndl = HBOCC::readSRAM( iv_target,
                                          i_address,
                                          reinterpret_cast<uint64_t*>
                                          (l_buffer.pointer()),
                                          l_length );
#endif
            if (nullptr == l_errlHndl)
            {
                const occErrlEntry_t * l_occElog =
                    reinterpret_cast<occErrlEntry_t*> (l_buffer.pointer());

                TMGT_BIN("OCC ELOG", l_occElog, 256);

                // Get user details section
                const occErrlUsrDtls_t *l_usrDtls_ptr = (occErrlUsrDtls_t *)
                    ((uint8_t*)l_occElog + sizeof(occErrlEntry_t));

                const uint32_t l_occSrc = l_comp_id | l_occElog->reasonCode;
                ERRORLOG::errlSeverity_t severity =
                    ERRORLOG::ERRL_SEV_INFORMATIONAL;

                if (l_occSrc == 0x2A01)
                {
                    // 2A01 is Periodic OCC Telemetry / Call Home data
                    TMGT_INF("OCC is reporting Periodic Telemetry Data (0x2A01)"
                             " - NOT AN ERROR");
                }

                // Translate Severity
                const uint8_t l_occSeverity = l_occElog->severity;
                if (l_occSeverity < OCC_SEV_ACTION_XLATE_SIZE)
                {
                    severity =
                     occSeverityErrorActionXlate[l_occSeverity].occErrlSeverity;
                }
                else
                {
                    TMGT_ERR("occProcessElog: Severity translate failure"
                             " (severity = 0x%02X)", l_occElog->severity);
                }

                // Process Actions
                bool l_call_home_event = false;
                elogProcessActions(l_occElog->actions,
                                   l_occSrc,
                                   l_usrDtls_ptr->userData1,
                                   severity,
                                   l_call_home_event);

                // Create OCC error log
                // NOTE: word 4 (used by extended reason code) to save off OCC
                //       sub component value which is needed to correctly parse
                //       srcs which have similar uniqueness
                // NOTE: SRC tags are NOT required here as these logs will get
                //       parsed with the OCC src tags
                bldErrLog(l_errlHndl,
                          (htmgtModuleId)(l_usrDtls_ptr->modId & 0x00FF),
                          (htmgtReasonCode)l_occSrc, // occ reason code
                          l_usrDtls_ptr->userData1,
                          l_usrDtls_ptr->userData2,
                          l_usrDtls_ptr->userData3,
                          (l_usrDtls_ptr->modId << 16 ) |
                          l_occElog->extendedRC, // extended reason code
                          severity);


                // Add callout information
                const uint8_t l_max_callouts = l_occElog->maxCallouts;
                bool l_bad_fru_data = false;
                bool l_sensor_callout_found = false;
                bool l_sensor_callout_invalid = true;
                uint8_t numCallouts = 0;
                uint8_t calloutIndex = 0;
                while (calloutIndex < l_max_callouts)
                {
                    const occErrlCallout_t callout =
                        l_occElog->callout[calloutIndex];
                    if (callout.type != 0)
                    {
                        if (callout.type == OCC_CALLOUT_TYPE_SENSOR)
                        {
                            l_sensor_callout_found = true;
                        }
                        HWAS::callOutPriority priority;
                        bool l_success = true;
                        l_success = elogXlateSrciPriority(callout.priority,
                                                          priority);
                        if (l_success == true)
                        {
                            l_success = elogAddCallout(l_errlHndl,
                                                       priority,
                                                       callout,
                                                       numCallouts);
                            if (l_success)
                            {
                                if (callout.type == OCC_CALLOUT_TYPE_SENSOR)
                                {
                                    // Got at least one good sensor callout
                                    l_sensor_callout_invalid = false;
                                }
                            }
                            else
                            {
                                l_bad_fru_data = true;
                            }
                        }
                        else
                        {
                            l_bad_fru_data = true;
                            TMGT_ERR("occProcessElog: Priority translate"
                                     " failure (priority = 0x%02X)",
                                     callout.priority);
                        }
                    }
                    else
                    {   // make sure all the remaining callout data are zeros,
                        // otherwise mark bad fru data
                        const occErrlCallout_t zeros = { 0 };
                        while (calloutIndex < l_max_callouts)
                        {
                            if (memcmp(&l_occElog->callout[calloutIndex],
                                       &zeros, sizeof(occErrlCallout_t)))
                            {
                                TMGT_ERR("occProcessElog: The remaining"
                                         " callout data should be all zeros");
                                l_bad_fru_data = true;
                                break;
                            }
                            ++calloutIndex;
                        }
                        break;
                    }
                    ++calloutIndex;
                }

                // Any bad fru data found ?
                errlHndl_t err2 = nullptr;
                if (l_bad_fru_data == true)
                {
                    TMGT_BIN("Callout Data", &l_occElog->callout[0],
                             sizeof(occErrlCallout)*ERRL_MAX_CALLOUTS);
                    /*@
                     * @errortype
                     * @refcode LIC_REFCODE
                     * @subsys EPUB_FIRMWARE_SP
                     * @reasoncode HTMGT_RC_BAD_FRU_CALLOUTS
                     * @moduleid HTMGT_MODID_PROCESS_ELOG
                     * @userdata1[0:15]  OCC elog id
                     * @userdata1[16:31] Bad callout index
                     * @devdesc Bad FRU data received in OCC error log
                     * @custdesc An internal firmware error occurred
                     */
                    bldErrLog(err2, HTMGT_MODID_PROCESS_ELOG,
                              HTMGT_RC_BAD_FRU_CALLOUTS,
                              i_id, calloutIndex, 0, 0,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    ERRORLOG::errlCommit(err2, HTMGT_COMP_ID);
                }

                bool l_addProcCallout = false;
                if (l_sensor_callout_found && l_sensor_callout_invalid)
                {
                    // OCC called out sensor, but no valid sensors found so add proc callout
                    l_addProcCallout = true;
                }

                if ((numCallouts == 0) &&
                    (severity != ERRORLOG::ERRL_SEV_INFORMATIONAL))
                {
                    if (i_source == OCC_ERRSRC_405)
                    {
                        TMGT_ERR("occProcessElog: No FRU callouts found for "
                                 "OCC%d elog_id:0x%02X, severity:0x%0X",
                                 iv_instance, i_id, severity);
                        /*@
                         * @errortype
                         * @refcode LIC_REFCODE
                         * @subsys EPUB_FIRMWARE_SP
                         * @reasoncode HTMGT_RC_MISMATCHING_SEVERITY
                         * @moduleid HTMGT_MODID_PROCESS_ELOG
                         * @userdata1[0:15]  OCC elog id
                         * @userdata1[16:31] OCC severity
                         * @devdesc No FRU callouts found for non-info OCC Error
                         * @custdesc An internal firmware error occurred
                         */
                        bldErrLog(err2, HTMGT_MODID_PROCESS_ELOG,
                                  HTMGT_RC_MISMATCHING_SEVERITY,
                                  i_id, severity, 0, 0,
                                  ERRORLOG::ERRL_SEV_INFORMATIONAL);
                        ERRORLOG::errlCommit(err2, HTMGT_COMP_ID);
                    }
                    else
                    {
                        // Add processor callout for PM code logs with not callout
                        l_addProcCallout = true;
                    }
                }

                if (l_addProcCallout)
                {
                    // Add Processor callout for PGPE/XGPE/QME
                    TMGT_ERR("occProcessElog: Adding processor callout for"
                             " OCC%d", iv_instance);
                    TARGETING::ConstTargetHandle_t l_proc_target =
                        TARGETING::getParentChip(iv_target);
                    l_errlHndl->addHwCallout(l_proc_target,
                                             HWAS::SRCI_PRIORITY_MED,
                                             HWAS::NO_DECONFIG,
                                             HWAS::GARD_NULL);
                }

                if (int_flags_set(FLAG_HALT_ON_OCC_SRC))
                {
                    // Check if OCC SRC matches our trigger SRC
                    if ((l_occSrc & 0xFF) == (get_int_flags() >> 24))
                    {
                        TMGT_ERR("occProcessElog: OCC%d reported 0x%04X and "
                                 "HALT_ON_SRC is set.  Resets will be disabled",
                                 iv_instance, l_occSrc);
                        set_int_flags(get_int_flags() | FLAG_RESET_DISABLED);
                        // Force unrecoverable elog
                        l_errlHndl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                    }
                }

#ifdef CONFIG_CONSOLE_OUTPUT_OCC_COMM
                char header[64];
                sprintf(header, "OCC%d ELOG: (0x%04X bytes)", iv_instance,
                        i_length);
                dumpToConsole(header, (const uint8_t *)l_occElog,
                              std::min(i_length,(uint16_t)512));
#endif

                // Add full OCC error log data as a User Details section
                l_errlHndl->addFFDC(l_comp_id,
                                    l_occElog,
                                    i_length,
                                    1,  // version
                                    0); // subsection
                ERRORLOG::errlCommit(l_errlHndl, HTMGT_COMP_ID);
            }
            else
            {
                TMGT_ERR("occProcessElog: Unable to read elog %d from source "
                         "0x%02X on OCC%d, SRAM address (0x%08X) length "
                         "(0x%04X), rc=0x%04X",
                         i_id, i_source, iv_instance, i_address, i_length,
                         l_errlHndl->reasonCode());
                ERRORLOG::errlCommit(l_errlHndl, HTMGT_COMP_ID);
            }
        }
        else
        {
            TMGT_ERR("occProcessElog: Invalid OCC%d elog data: ID: 0x%02X, "
                     "Source: 0x%02X, Length: 0x%04X, Address: 0x%08X",
                     iv_instance, i_id, i_source, i_length, i_address);

            occErrlEntry_t *l_sram_data = NULL;
            uint16_t l_rc = 0;
            uint8_t l_sev = 0;
            uint8_t l_actions = 0;
            const uint16_t l_length = 2048;
            if (0 != i_address)
            {
                // Try to read some data from SRAM
                fapi2::variable_buffer l_buffer(l_length*8); //convert to bits
                // HBOCC is only defined for HTMGT
#ifdef CONFIG_HTMGT
                l_errlHndl = HBOCC::readSRAM(iv_target,
                                             i_address,
                                             reinterpret_cast<uint64_t*>
                                             (l_buffer.pointer()),
                                             l_length);
#endif
                if (NULL == l_errlHndl)
                {
                    const occErrlEntry_t * l_occElog =
                        reinterpret_cast<occErrlEntry_t*> (l_buffer.pointer());
                    if (l_occElog)
                    {
                        l_rc = l_comp_id | l_occElog->reasonCode;
                        l_sev = l_occElog->severity;
                        l_actions = l_occElog->actions;
                    }
                }
                else
                {
                    TMGT_ERR("occ_process_elog: Failed to read OCC SRAM, "
                             "rc=0x%04X", l_errlHndl->reasonCode());
                    l_errlHndl->collectTrace("HTMGT");
                    ERRORLOG::errlCommit(l_errlHndl, HTMGT_COMP_ID);
                }
            }

            /*@
             * @errortype
             * @refcode LIC_REFCODE
             * @subsys EPUB_FIRMWARE_SP
             * @reasoncode HTMGT_RC_INVALID_OCC_ELOG
             * @moduleid  HTMGT_MODID_PROCESS_ELOG
             * @userdata1 instance
             * @userdata2 error source
             * @userdata3 OCC RC
             * @userdata4 OCC severity / actions
             * @devdesc Invalid OCC error log data
             * @custdesc An internal firmware error occurred
             */
            bldErrLog(l_errlHndl, HTMGT_MODID_PROCESS_ELOG,
                      HTMGT_RC_INVALID_OCC_ELOG,
                      iv_instance, i_source, l_rc, (l_sev<<16) | (l_actions),
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            if (NULL != l_sram_data)
            {
                l_errlHndl->addFFDC(l_comp_id,
                                    l_sram_data,
                                    l_length,
                                    1,  // version
                                    0); // subsection
            }
            ERRORLOG::errlCommit(l_errlHndl, HTMGT_COMP_ID);
        }

        // Clear elog
        const uint8_t l_cmdData[] = {
            0x01/* version*/, i_id, i_source, 0x00/*reserved*/};
        OccCmd l_cmd(this, OCC_CMD_CLEAR_ERROR_LOG,
                     sizeof(l_cmdData), l_cmdData);
        l_errlHndl = l_cmd.sendOccCmd();
        if (l_errlHndl != nullptr)
        {
            TMGT_ERR("occProcessElog: Failed to clear elog id 0x%02X from"
                     " source 0x%02X on OCC%d (rc=0x%04X)",
                     i_id, i_source, iv_instance, l_errlHndl->reasonCode());
            ERRORLOG::errlCommit(l_errlHndl, HTMGT_COMP_ID);
        }

    } // end  Occ::occProcessElog()


    // Add callout to specified elog
    bool Occ::elogAddCallout(errlHndl_t &               io_errlHndl,
                             HWAS::callOutPriority    & i_priority,
                             const occErrlCallout_t     i_callout,
                             uint8_t &                  io_callout_num)
    {
        bool l_success = true;

        TMGT_INF("elogAddCallout: Add callout type:0x%02X, value:0x%016llX,"
                 " priority:0x%02X",
                 i_callout.type,i_callout.calloutValue, i_priority);

        if (i_callout.type == OCC_CALLOUT_TYPE_SENSOR)
        {
            const uint32_t sensor = (uint32_t)i_callout.calloutValue;
            TARGETING::Target * target =
                TARGETING::UTIL::getSensorTarget(sensor, iv_target);
            if (nullptr != target)
            {
                if(sensor == TARGETING::UTIL::occ_sensor_id_t::SENSOR_TYPE_VRM)
                {
                    io_errlHndl->addVrmCallout(target, HWAS::VDD, i_priority);
                }
                else
                {
                    io_errlHndl->addHwCallout(target, i_priority,
                                              HWAS::NO_DECONFIG,
                                              HWAS::GARD_NULL);
                }
                io_callout_num++;
            }
            else
            {
                TMGT_ERR("elogAddCallout: Unable to find target for "
                         "sensor 0x%04X", sensor);
                l_success = false;
            }
        }
        else if (i_callout.type == OCC_CALLOUT_TYPE_COMPONENT_ID)
        {
            tmgtCompxlateType l_compDataType;
            uint32_t l_compData = 0;
            const uint8_t l_compId = (i_callout.calloutValue & 0xFF);

            if (elogGetTranslationData(l_compId, l_compDataType, l_compData))
            {
                switch(l_compDataType)
                {
                    case TMGT_COMP_DATA_SYMBOLIC_FRU:
                        TMGT_INF("elogAddCallout: symbolic callout: 0x%08X",
                                 l_compData);
                        break;
                    case TMGT_COMP_DATA_PROCEDURE:
                        io_errlHndl->addProcedureCallout(
                                      (HWAS::epubProcedureID)l_compData,
                                       i_priority);
                        io_callout_num++;
                        break;
                    case TMGT_COMP_DATA_END_OF_TABLE:
                        break;
                    default:
                        TMGT_ERR("elogAddCallout: Invalid component id 0x%02X",
                                 l_compId);
                        l_success = false;
                }
            }
            else
            {
                TMGT_ERR("elogAddCallout: Component id translate failure"
                         " (id=0x%02X)", l_compId);
                l_success = false;
            }
        }
        else if (i_callout.type == OCC_CALLOUT_TYPE_GPU_SENSOR)
        {
            const uint32_t sensor = (uint32_t)i_callout.calloutValue;
            io_errlHndl->addSensorCallout(sensor, HWAS::GPU_FUNC_SENSOR,
                                          i_priority);
            io_callout_num++;
        }
        else
        {
            TMGT_ERR("elogAddCallout: Invalid callout type (type=%d)",
                     i_callout.type);
            l_success = false;
        }

        return l_success;;

    } // end Occ::elogAddCallout()


    void Occ::elogProcessActions(const uint8_t  i_actions,
                                 const uint32_t i_src,
                                 uint32_t       i_data,
                                 ERRORLOG::errlSeverity_t & io_errlSeverity,
                                 bool         & o_call_home)
    {
        bool l_occReset = false;
        o_call_home = false;

        if (i_actions & TMGT_ERRL_ACTIONS_MANUFACTURING_ERROR)
        {
            if (isMfgFlagSet(TARGETING::
                             MFG_FLAGS_MNFG_ENERGYSCALE_SPECIAL_POLICIES))
            {
                TMGT_INF("elog_process_actions: Mfg policy set, forcing "
                         "severity to Unrecoverable");
                io_errlSeverity = ERRORLOG::ERRL_SEV_UNRECOVERABLE;
            }
        }
        else if (i_actions & TMGT_ERRL_ACTIONS_WOF_RESET_REQUIRED)
        {
            iv_failed = false;
            iv_resetReason = OCC_RESET_REASON_WOF_RESET;
            // Check if WOF resets are disabled
            if(int_flags_set(FLAG_WOF_RESET_DISABLED) == true)
            {
                iv_needsWofReset = false;
                TMGT_INF("elogProcessActions: OCC%d requested a WOF reset "
                         "but WOF resets are DISABLED",
                         iv_instance);
            }
            else // WOF resets are enabled
            {
                l_occReset = true;
                iv_needsWofReset = true;
                TMGT_ERR("elogProcessActions: OCC%d requested a WOF reset",
                         iv_instance);

                // WOF reset count gets incremented after the resetPrep
                if (iv_wofResetCount < WOF_RESET_COUNT_THRESHOLD)
                {
                    if (! isMfgFlagSet(TARGETING::
                                       MFG_FLAGS_MNFG_ENERGYSCALE_SPECIAL_POLICIES))
                    {
                        // Not at WOF reset threshold yet and not MFG, set as INFO
                        io_errlSeverity = ERRORLOG::ERRL_SEV_INFORMATIONAL;
                    }
                }
                else
                {
                    // Set sev to Unrecoverable w/Performance Loss
                    io_errlSeverity = ERRORLOG::ERRL_SEV_UNRECOVERABLE1;
                }
            }

            // Need to add WOF reason code to OCC object regardless of
            // whether WOF resets are disabled.
            iv_wofResetReasons |= i_data;
            TMGT_ERR("elogProcessActions: WOF Reset Reasons for OCC%d = 0x%08x",
                     iv_instance, iv_wofResetReasons);
        }
        else
        {
            if (i_actions & TMGT_ERRL_ACTIONS_RESET_REQUIRED)
            {
                l_occReset = true;
                iv_failed = true;
                iv_resetReason = OCC_RESET_REASON_OCC_REQUEST;

                TMGT_INF("elogProcessActions: OCC%d requested reset",
                         iv_instance);

                // If reset will force safe mode, then make error unrecoverable
                if (OCC_RESET_COUNT_THRESHOLD == iv_resetCount)
                {
                    if (io_errlSeverity != ERRORLOG::ERRL_SEV_UNRECOVERABLE1)
                    {
                        // update severity to UNRECOVERABLE1 (w/degraded preformance)
                        TMGT_ERR("elogProcessActions: changing severity to "
                                 "UNRECOVERABLE/DEGRADED (was sev=0x%02X)",
                                 io_errlSeverity);
                        io_errlSeverity = ERRORLOG::ERRL_SEV_UNRECOVERABLE1;
                    }
                }
                else if ((io_errlSeverity != ERRORLOG::ERRL_SEV_INFORMATIONAL)&&
                         !isMfgFlagSet(TARGETING::
                                   MFG_FLAGS_MNFG_ENERGYSCALE_SPECIAL_POLICIES))
                {
                    // Not INFO and not MFG, update severity to INFO
                    TMGT_INF("elogProcessActions: changing severity to "
                             "INFORMATIONAL (was sev=0x%02X)",
                             io_errlSeverity);
                    io_errlSeverity = ERRORLOG::ERRL_SEV_INFORMATIONAL;
                    // log will be sent to BMC with NO SEL (hardware callouts)
                    o_call_home = true;
                }
            }

            if (i_actions & TMGT_ERRL_ACTIONS_SAFE_MODE_REQUIRED)
            {
                l_occReset = true;
                iv_failed = true;
                iv_resetReason = OCC_RESET_REASON_CRIT_FAILURE;
                iv_resetCount = OCC_RESET_COUNT_THRESHOLD;

                TMGT_INF("elogProcessActions: OCC%d requested safe mode",
                         iv_instance);
                TMGT_CONSOLE("OCC%d requested system enter safe mode",
                             iv_instance);
            }
        }

        // Check if error needs to be forced to the BMC:
        //   1. 2A01 = OCC call home/telemetry data, OR
        //   2. OCC requested force, but error was changed to info by HTMGT
        //   (log will be sent to the BMC with NO SEL (hardware callouts))
        if ( (i_src == (OCCC_COMP_ID | 0x01 )) || // GEN_CALLHOME_LOG
             ( (i_actions & TMGT_ERRL_ACTIONS_FORCE_ERROR_POSTED) &&
               (io_errlSeverity == ERRORLOG::ERRL_SEV_INFORMATIONAL) ) )
        {
            o_call_home = true;
        }

        // If reset required, save the SRC in case it leads to safe mode
        if (l_occReset == true)
        {
            iv_needsReset = true;
            OccManager::updateSafeModeReason(i_src, iv_instance);
        }

    } // end Occ::elogProcessActions()

} // end namespace
