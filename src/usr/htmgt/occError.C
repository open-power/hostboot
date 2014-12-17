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

#include <htmgt/htmgt.H>
#include <htmgt/htmgt_reasoncodes.H>
#include "htmgt_utility.H"
#include "occError.H"
#include "htmgt_occcmd.H"

#include <ecmdDataBufferBase.H>
#include <hwpf/hwp/occ/occAccess.H>


namespace HTMGT
{

    // Process elog entry from OCC poll response
    void occProcessElog(Occ * i_occ,
                        const uint8_t  i_id,
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
        l_errlHndl = HBOCC::readSRAM(i_occ->getTarget(), i_address, l_buffer);
#endif
        if (NULL == l_errlHndl)
        {
            const uint32_t l_flatSize = l_buffer.flattenSize();
            l_buffer.flatten(l_sram_data, l_flatSize);
            // Skip 8 byte ecmd header
            const occErrlEntry_t *l_occElog=(occErrlEntry_t *)&l_sram_data[8];

            TMGT_BIN("OCC ELOG", l_occElog, 256);

            const uint32_t l_occSrc = OCCC_COMP_ID | l_occElog->reasonCode;
            ERRORLOG::errlSeverity_t l_errlSeverity =
                ERRORLOG::ERRL_SEV_INFORMATIONAL;
#if 0
            // TODO: RTC 109224 - determine correct severity/actions

            // Process Severity
            const uint8_t l_occSeverity = l_occElog->severity;
            const uint8_t l_occActions = l_occElog->actions;
            if (l_occSeverity < OCC_SEV_ACTION_XLATE_SIZE)
            {
                l_errlSeverity =
                    occSeverityErrorActionXlate[l_occSeverity].occErrlSeverity;
            }
            else
            {
                TMGT_ERR("occProcessElog: Severity translate failure"
                         " (severity = 0x%02X)", l_occElog->severity);
            }

            // Process elog Actions
            bool l_occReset = false;
            elogProcessActions(l_occActions, l_occReset, l_errlSeverity);
            if (l_occReset == true)
            {
                iv_needsReset = true;
                UPDATE_SAFE_MODE_REASON(l_occSrc, iv_huid, true);
            }
#endif

            // Create OCC error log
            // NOTE: word 4 (used by extended reason code) to save off OCC
            //       sub component value which is needed to correctly parse
            //       srcs which have similar uniqueness
            // NOTE: SRC tags are NOT required here as these logs will get
            //       parsed with the OCC src tags
            const occErrlUsrDtls_t *l_usrDtls_ptr = (occErrlUsrDtls_t *)
                ((uint8_t*)l_occElog+sizeof(occErrlEntry_t)+
                 (l_occElog->numCallouts * sizeof(occErrlCallout_t)) );
            bldErrLog(l_errlHndl,
                      (htmgtModuleId)(l_usrDtls_ptr->modId & 0x00FF),
                      (htmgtReasonCode)l_occSrc, // occ reason code
                      l_usrDtls_ptr->userData1,
                      l_usrDtls_ptr->userData2,
                      l_usrDtls_ptr->userData3,
                      ((l_usrDtls_ptr->modId & 0xFF00) << 16 ) |
                      l_occElog->userData4, // extended reason code
                      l_errlSeverity);

#if 0
            // TODO: RTC 109224
            // Add callout information
            bool l_bad_fru_data = false;
            uint8_t l_callout_num = 0;
            if (! ((ERRL_SEV_INFORMATIONAL == l_errlSeverity) &&
                   (TMGT_ERRL_ACTIONS_MANUFACTURING_ERROR & l_occActions)) )
            {
                // Only add callouts if this is MFG error and system not in
                // MFG (in MFG severity would not be Info)
                uint8_t l_index = 0;
                uint8_t l_count = 1;

                const uint8_t l_max_callout = l_occElog->numCallouts;
                // The beginning address of callout data
                l_index = sizeof(occErrlEntry_t);
                do {
                    occErrlCallout_t *l_callout_ptr = NULL;
                    l_callout_ptr = (occErrlCallout_t *)
                        ((uint8_t*)l_occElog+l_index);
                    if (l_callout_ptr->type != 0)
                    {
                        srciPriority l_priority;
                        bool l_success = true;
                        l_success =
                            elogXlateSrciPriority(l_callout_ptr->priority,
                                                    l_priority);
                        if (l_success == true)
                        {
                            l_success = elogAddCallout(l_errlHndl,
                                                         l_errlSeverity,
                                                         l_priority,
                                                         *l_callout_ptr,
                                                         l_callout_num);
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
                                     l_callout_ptr->priority);
                        }
                        l_index += sizeof(occErrlCallout_t);
                    } // if (l_type != 0)
                    else
                    {   // make sure all the remaining callout data are zeros,
                        // otherwise mark bad fru data
                        uint8_t *l_ptr = (uint8_t*)l_occElog+l_index;
                        uint8_t l_len = (l_max_callout-l_count+1)*
                            sizeof(occErrlCallout_t);
                        while (l_len != 0)
                        {
                            if (*l_ptr != 0x00)
                            {
                                TMGT_ERR("occProcessElog: The remaining"
                                         " callout data should be all zeros");
                                l_bad_fru_data = true;
                                break;
                            }
                            l_len--;
                            l_ptr++;
                        }
                        break;
                    }
                    l_count++;
                } while (l_count <= l_max_callout);
            }
            else
            {
                TMGT_ERR("MFG error found outside MFG; callouts will not be"
                         " added to log (OCC severity=0x%02X, actions=0x%02X)",
                         l_occSeverity, l_occActions);
                const uint8_t l_callout_length = l_occElog->numCallouts * 12;
                const char *l_callout_ptr = (char *)((uint8_t*)l_occElog+
                                                     sizeof(occErrlEntry_t));
                // Add raw callout data from the OCC
                l_errlHndl->addUsrDtls(l_callout_ptr,
                                       l_callout_length,
                                       TMGT_COMP_ID,
                                       TMGT_VERSION,
                                       TMGT_ERROR_DATA_TYPE);
            }

            // Any bad fru data found ?
            errlHndl_t l_errlHndl2 = NULL;
            if (l_bad_fru_data == true)
            {
                /*@
                 * @errortype
                 * @refcode LIC_REFCODE
                 * @subsys EPUB_FIRMWARE_SP
                 * @reasoncode HTMGT_RC_OCC_ERROR_LOG
                 * @moduleid HTMGT_MOD_BAD_FRU_CALLOUTS
                 * @userdata1 OCC elog id
                 * @userdata2 Number of good callouts
                 * @devdesc Bad FRU data received in OCC error log
                 */
                bldErrLog(l_errlHndl2, HTMGT_MOD_BAD_FRU_CALLOUTS,
                          HTMGT_RC_OCC_ERROR_LOG,
                          i_id, l_callout_num, 0, 0, ERRL_SEV_INFORMATIONAL);
                ERRORLOG::errlCommit(l_errlHndl2, HTMGT_COMP_ID);
            }

            // Check callout number and severity
            if ((l_callout_num == 0) &&
                (l_errlSeverity != ERRL_SEV_INFORMATIONAL))
            {
                TMGT_ERR("occProcessElog: No FRU callouts found for OCC%d"
                         " elog_id:0x%02X, severity:0x%0X",
                         iv_instance, i_id, l_errlSeverity);
                /*@
                 * @errortype
                 * @refcode LIC_REFCODE
                 * @subsys EPUB_FIRMWARE_SP
                 * @reasoncode HTMGT_RC_OCC_ERROR_LOG
                 * @moduleid HTMGT_MOD_MISMATCHING_SEVERITY
                 * @userdata1 OCC elog id
                 * @userdata2 OCC severity
                 * @userdata3
                 * @userdata4
                 * @devdesc No FRU callouts found for non-info OCC Error Log
                 */
                bldErrLog(l_errlHndl2, HTMGT_MOD_MISMATCHING_SEVERITY,
                          HTMGT_RC_OCC_ERROR_LOG,
                          i_id, l_errlSeverity, 0, 0, ERRL_SEV_INFORMATIONAL);
                ERRORLOG::errlCommit(l_errlHndl2, HTMGT_COMP_ID);
            }
#endif

            // Add full OCC error log data as a User Details section
            l_errlHndl->addFFDC(OCCC_COMP_ID,
                                l_occElog,
                                i_length,
                                1,  // version
                                0); // subsection

#if 0
            // TODO: RTC 109224
            // Add additional data
            addTmgtElogData(l_errlHndl);
            addThermalElogData(l_errlHndl);
#endif

            // Commit Error (or terminate if required)
            ERRORLOG::errlCommit(l_errlHndl, HTMGT_COMP_ID);

            // Clear elog
            const uint8_t l_cmdData[1] = {i_id};
            OccCmd l_cmd(i_occ, OCC_CMD_CLEAR_ERROR_LOG,
                         sizeof(l_cmdData), l_cmdData);
            l_errlHndl = l_cmd.sendOccCmd();
            if (l_errlHndl != NULL)
            {
                TMGT_ERR("occProcessElog: Failed to clear elog id %d to"
                         " OCC%d (rc=0x%04X)",
                         i_id, i_occ, l_errlHndl->reasonCode());
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


} // end namespace



