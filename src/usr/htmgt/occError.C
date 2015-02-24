/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/occError.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#include <ecmdDataBufferBase.H>
#include <hwpf/hwp/occ/occAccess.H>
#include <console/consoleif.H>
#include <targeting/targplatutil.H>


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
        // TODO RTC 124739 - convert to use lower_bound
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

        // TODO RTC 124739 - convert to use lower_bound
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
                             const uint16_t i_length)
    {
        errlHndl_t  l_errlHndl = NULL;

        // Read data from SRAM (length must be multiple of 8 bytes)
        const uint16_t l_length = (i_length + 8) & 0xFFF8;
        uint8_t l_sram_data[8 + l_length];
        ecmdDataBufferBase l_buffer(l_length*8); // convert to bits
// HBOCC is only defined for HTMGT
#ifdef CONFIG_HTMGT
        l_errlHndl = HBOCC::readSRAM(iv_target, i_address, l_buffer);
#endif
        if (NULL == l_errlHndl)
        {
            const uint32_t l_flatSize = l_buffer.flattenSize();
            l_buffer.flatten(l_sram_data, l_flatSize);
            // Skip 8 byte ecmd header
            const occErrlEntry_t *l_occElog=(occErrlEntry_t *)&l_sram_data[8];

            TMGT_BIN("OCC ELOG", l_occElog, 256);

            const uint32_t l_occSrc = OCCC_COMP_ID | l_occElog->reasonCode;
            ERRORLOG::errlSeverity_t severity =
                ERRORLOG::ERRL_SEV_INFORMATIONAL;

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
            bool l_occReset = false;
            elogProcessActions(l_occElog->actions, l_occReset, severity);
            if (l_occReset == true)
            {
                iv_needsReset = true;
                OccManager::updateSafeModeReason(l_occSrc, iv_instance);
            }

            // Create OCC error log
            // NOTE: word 4 (used by extended reason code) to save off OCC
            //       sub component value which is needed to correctly parse
            //       srcs which have similar uniqueness
            // NOTE: SRC tags are NOT required here as these logs will get
            //       parsed with the OCC src tags
            const occErrlUsrDtls_t *l_usrDtls_ptr = (occErrlUsrDtls_t *)
                ((uint8_t*)l_occElog+sizeof(occErrlEntry_t)+
                 (l_occElog->maxCallouts * sizeof(occErrlCallout_t)) );
            bldErrLog(l_errlHndl,
                      (htmgtModuleId)(l_usrDtls_ptr->modId & 0x00FF),
                      (htmgtReasonCode)l_occSrc, // occ reason code
                      l_usrDtls_ptr->userData1,
                      l_usrDtls_ptr->userData2,
                      l_usrDtls_ptr->userData3,
                      ((l_usrDtls_ptr->modId & 0xFF00) << 16 ) |
                      l_occElog->reserved, // extended reason code
                      severity);

            // Add callout information
            const uint8_t l_max_callouts = l_occElog->maxCallouts;
            bool l_bad_fru_data = false;
            uint8_t numCallouts = 0;
            uint8_t calloutIndex = 0;
            while (calloutIndex < l_max_callouts)
            {
                const occErrlCallout_t callout =
                    l_occElog->callout[calloutIndex];
                if (callout.type != 0)
                {
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
                        if (l_success == false)
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
            errlHndl_t err2 = NULL;
            if (l_bad_fru_data == true)
            {
                TMGT_BIN("Callout Data", &l_occElog->callout[0],
                         sizeof(occErrlCallout)*ERRL_MAX_CALLOUTS);
                /*@
                 * @errortype
                 * @refcode LIC_REFCODE
                 * @subsys EPUB_FIRMWARE_SP
                 * @reasoncode HTMGT_RC_OCC_ERROR_LOG
                 * @moduleid HTMGT_MOD_BAD_FRU_CALLOUTS
                 * @userdata1[0-15]  OCC elog id
                 * @userdata1[16-31] Bad callout index
                 * @devdesc Bad FRU data received in OCC error log
                 */
                bldErrLog(err2, HTMGT_MOD_BAD_FRU_CALLOUTS,
                          HTMGT_RC_OCC_ERROR_LOG,
                          i_id, calloutIndex, 0, 0,
                          ERRORLOG::ERRL_SEV_INFORMATIONAL);
                ERRORLOG::errlCommit(err2, HTMGT_COMP_ID);
            }
            // Check callout number and severity
            if ((numCallouts == 0) &&
                (severity != ERRORLOG::ERRL_SEV_INFORMATIONAL))
            {
                TMGT_ERR("occProcessElog: No FRU callouts found for OCC%d"
                         " elog_id:0x%02X, severity:0x%0X",
                         iv_instance, i_id, severity);
                /*@
                 * @errortype
                 * @refcode LIC_REFCODE
                 * @subsys EPUB_FIRMWARE_SP
                 * @reasoncode HTMGT_RC_OCC_ERROR_LOG
                 * @moduleid HTMGT_MOD_MISMATCHING_SEVERITY
                 * @userdata1[0-15]  OCC elog id
                 * @userdata1[16-31] OCC severity
                 * @devdesc No FRU callouts found for non-info OCC Error Log
                 */
                bldErrLog(err2, HTMGT_MOD_MISMATCHING_SEVERITY,
                          HTMGT_RC_OCC_ERROR_LOG,
                          i_id, severity, 0, 0,
                          ERRORLOG::ERRL_SEV_INFORMATIONAL);
                ERRORLOG::errlCommit(err2, HTMGT_COMP_ID);
            }

            // Add full OCC error log data as a User Details section
            l_errlHndl->addFFDC(OCCC_COMP_ID,
                                l_occElog,
                                i_length,
                                1,  // version
                                0); // subsection
            ERRORLOG::errlCommit(l_errlHndl, HTMGT_COMP_ID);

            // Clear elog
            const uint8_t l_cmdData[1] = {i_id};
            OccCmd l_cmd(this, OCC_CMD_CLEAR_ERROR_LOG,
                         sizeof(l_cmdData), l_cmdData);
            l_errlHndl = l_cmd.sendOccCmd();
            if (l_errlHndl != NULL)
            {
                TMGT_ERR("occProcessElog: Failed to clear elog id %d to"
                         " OCC%d (rc=0x%04X)",
                         i_id, iv_instance, l_errlHndl->reasonCode());
                ERRORLOG::errlCommit(l_errlHndl, HTMGT_COMP_ID);
            }
        }
        else
        {
            TMGT_ERR("occProcessElog: Unable to read elog %d from SRAM"
                     " address (0x%08X) length (0x%04X), rc=0x%04X",
                     i_id, i_address, i_length, l_errlHndl->reasonCode());
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
                TARGETING::UTIL::getSensorTarget(sensor);
            if (NULL != target)
            {
                io_errlHndl->addHwCallout(target, i_priority,
                                          HWAS::NO_DECONFIG,
                                          HWAS::GARD_NULL);
                io_callout_num++;
            }
            else
            {
                TMGT_ERR("elogAddCallout: Unable to find target for "
                         "sensor 0x%04X", sensor);
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
        else
        {
            TMGT_ERR("elogAddCallout: Invalid callout type (type=%d)",
                     i_callout.type);
            l_success = false;
        }

        return l_success;;

    } // end Occ::elogAddCallout()


    void Occ::elogProcessActions(const uint8_t i_actions,
                                 bool        & o_occReset,
                                 ERRORLOG::errlSeverity_t & o_errlSeverity)
    {
        if (i_actions & TMGT_ERRL_ACTIONS_RESET_REQUIRED)
        {
            o_occReset = true;
            iv_failed = true;
            iv_resetReason = OCC_RESET_REASON_OCC_REQUEST;

            TMGT_INF("elogProcessActions: OCC%d requested reset",
                             iv_instance);
        }

        if (i_actions & TMGT_ERRL_ACTIONS_SAFE_MODE_REQUIRED)
        {
            o_occReset = true;
            iv_failed = true;
            iv_resetReason = OCC_RESET_REASON_CRIT_FAILURE;
            iv_resetCount = OCC_RESET_COUNT_THRESHOLD;

            TMGT_INF("elogProcessActions: OCC%d requested safe mode",
                     iv_instance);
            TMGT_CONSOLE("OCC%d requested system enter safe mode",
                             iv_instance);
        }

    } // end Occ::elogProcessActions()



} // end namespace



