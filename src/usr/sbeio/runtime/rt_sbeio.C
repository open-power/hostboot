/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/rt_sbeio.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2023                        */
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
#include <runtime/interface.h>
#include <kernel/console.H>

#include <vmmconst.h>
#include <sys/misc.h>
#include <sbeio/runtime/sbe_msg_passing.H>
#include <sbeio/runtime/sbeio_vpd_override.H>
#include <sbeio/runtime/sbeio_attr_override.H>
#include <sbeio/sbeioreasoncodes.H>
#include <sbeio/sbeioif.H>                 // getAllPmicHealthCheckData
#include <errno.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errlreasoncodes.H>
#include <devicefw/userif.H>
#include <util/runtime/rt_fwreq_helper.H>

//  targeting support
#include    <targeting/translateTarget.H>
#include    <targeting/common/target.H>
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  mailbox register definitions
#include <initservice/mboxRegs.H>

namespace HTMGT
{
    int htmgt_pass_thru (uint16_t   i_cmdLength,
                         uint8_t *  i_cmdData,
                         uint16_t * o_rspLength,
                         uint8_t *  o_rspData);
}

using namespace TARGETING;
using namespace ERRORLOG;
using namespace SBE_MSG;
extern trace_desc_t* g_trac_hbrt;

// Trace
trace_desc_t* g_trac_sbeio;
TRAC_INIT(&g_trac_sbeio, SBEIO_COMP_NAME, 6*KILOBYTE, TRACE::BUFFER_SLOW);


namespace RT_SBEIO
{
    // Map of process command functions for the pass-through commands
    ProcessCmdMap_t g_processCmdMap;

    //------------------------------------------------------------------------

    /**
     *  @brief SBE message passing read pass-through command
     *
     *  @details  This is a call that will read a pass-through command
     *            from the SBE Communication buffer and copy it to a
     *            local buffer so its information is preserved during
     *            processing of the command and creation of the response
     *            in the same SBE Communication buffer.
     *
     *  @param[in]  i_proc        HB processor target
     *  @param[in]  i_sbeMessage  Pass-through command request in sbe-comm
     *  @param[out] o_request     Copied pass-through command request
     *
     *  @returns  errlHndl_t  NULL on success
     */
    errlHndl_t process_sbe_msg_read_command(TargetHandle_t i_proc,
                                            sbeMessage_t& i_sbeMessage,
                                            sbeMessage_t& o_request)
    {
        errlHndl_t errl = nullptr;

        if((!ENUM_SBEHDRVER_CHECK(i_sbeMessage.sbeHdr.version)) ||
           (!ENUM_CMDHDRVER_CHECK(i_sbeMessage.cmdHdr.version)))
        {
           TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: read "
                      "command SBE Header version 0x%08x %s, Command Header "
                      "version 0x%08x %s",
                      i_sbeMessage.sbeHdr.version,
                      (ENUM_SBEHDRVER_CHECK(i_sbeMessage.sbeHdr.version))
                          ? "valid" : "invalid",
                      i_sbeMessage.cmdHdr.version,
                      (ENUM_CMDHDRVER_CHECK(i_sbeMessage.cmdHdr.version))
                          ? "valid" : "invalid");

            /*@
             * @errortype
             * @moduleid     SBEIO::SBEIO_RUNTIME
             * @reasoncode   SBEIO::SBEIO_RT_INVALID_VERSION
             * @userdata1[0:31]   SBE Header version
             * @userdata1[32:63]  Command Header version
             * @userdata2    Processor HUID
             *
             * @devdesc      SBEIO RT Read Pass-through command invalid version.
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO::SBEIO_RUNTIME,
                                 SBEIO::SBEIO_RT_INVALID_VERSION,
                                 TWO_UINT32_TO_UINT64(
                                     i_sbeMessage.sbeHdr.version,
                                     i_sbeMessage.cmdHdr.version),
                                 get_huid(i_proc));

            errl->addFFDC( SBE_COMP_ID,
                           &(i_sbeMessage),
                           sizeof(sbeHeader_t) + sizeof(cmdHeader_t),
                           0,                 // Version
                           ERRL_UDT_NOFORMAT, // parser ignores data
                           false );           // merge
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
        }
        else if(i_sbeMessage.sbeHdr.msgSize > SBE_MSG_SIZE)
        {
            TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: read "
                      "command message size too large 0x%08x",
                      i_sbeMessage.sbeHdr.msgSize);

            /*@
             * @errortype
             * @moduleid     SBEIO::SBEIO_RUNTIME
             * @reasoncode   SBEIO::SBEIO_RT_MSG_SIZE_TOO_LARGE
             * @userdata1[0:31]   Processor HUID
             * @userdata1[32:63]  Message Size
             * @userdata2    Reserved
             *
             * @devdesc      SBEIO RT Read Pass-through command message size
             *                is too large.
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO::SBEIO_RUNTIME,
                                 SBEIO::SBEIO_RT_MSG_SIZE_TOO_LARGE,
                                 TWO_UINT32_TO_UINT64(
                                     get_huid(i_proc),
                                     i_sbeMessage.sbeHdr.msgSize),
                                 0);

            errl->addFFDC( SBE_COMP_ID,
                           &(i_sbeMessage),
                           sizeof(sbeHeader_t) + sizeof(cmdHeader_t),
                           0,                 // Version
                           ERRL_UDT_NOFORMAT, // parser ignores data
                           false );           // merge
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
        }
        else if(i_sbeMessage.cmdHdr.dataOffset < sizeof(cmdHeader_t))
        {
            TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: read "
                      "command data offset too small 0x%08x",
                      i_sbeMessage.cmdHdr.dataOffset);

            /*@
             * @errortype
             * @moduleid     SBEIO::SBEIO_RUNTIME
             * @reasoncode   SBEIO::SBEIO_RT_DATA_OFFSET_TOO_SMALL
             * @userdata1[0:31]   Processor HUID
             * @userdata1[32:63]  Data Offset
             * @userdata2    Minimum Data Offset
             *
             * @devdesc      SBEIO RT Read Pass-through command data offset
             *                is too small.
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO::SBEIO_RUNTIME,
                                 SBEIO::SBEIO_RT_DATA_OFFSET_TOO_SMALL,
                                 TWO_UINT32_TO_UINT64(
                                     get_huid(i_proc),
                                     i_sbeMessage.cmdHdr.dataOffset),
                                 sizeof(cmdHeader_t));

            errl->addFFDC( SBE_COMP_ID,
                           &(i_sbeMessage),
                           sizeof(sbeHeader_t) + sizeof(cmdHeader_t),
                           0,                 // Version
                           ERRL_UDT_NOFORMAT, // parser ignores data
                           false );           // merge
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
        }
        else if(i_sbeMessage.cmdHdr.dataOffset + i_sbeMessage.cmdHdr.dataSize >
                i_sbeMessage.sbeHdr.msgSize - sizeof(sbeHeader_t))
        {
            TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: read "
                      "command, data offset 0x%08x and data size 0x%08x "
                      "larger than msg size 0x%08x minus SBE hdr size 0x%08x",
                      i_sbeMessage.cmdHdr.dataOffset,
                      i_sbeMessage.cmdHdr.dataSize,
                      i_sbeMessage.sbeHdr.msgSize,
                      sizeof(sbeHeader_t));

            /*@
             * @errortype
             * @moduleid     SBEIO::SBEIO_RUNTIME
             * @reasoncode   SBEIO::SBEIO_RT_DATA_TOO_LARGE
             * @userdata1[0:31]   Processor HUID
             * @userdata1[32:63]  Data Offset
             * @userdata2[0:31]   Message Size
             * @userdata2[32:63]  Data Size
             *
             * @devdesc      SBEIO RT Read Pass-through command data offset
             *                is too large.
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO::SBEIO_RUNTIME,
                                 SBEIO::SBEIO_RT_DATA_TOO_LARGE,
                                 TWO_UINT32_TO_UINT64(
                                     get_huid(i_proc),
                                     i_sbeMessage.cmdHdr.dataOffset),
                                 TWO_UINT32_TO_UINT64(
                                     i_sbeMessage.sbeHdr.msgSize,
                                     i_sbeMessage.cmdHdr.dataSize));

            errl->addFFDC( SBE_COMP_ID,
                           &(i_sbeMessage),
                           sizeof(sbeHeader_t) + sizeof(cmdHeader_t),
                           0,                 // Version
                           ERRL_UDT_NOFORMAT, // parser ignores data
                           false );           // merge
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
        }
        else
        {
            // Copy command from SBE Communication area
            memcpy(reinterpret_cast<void*>(&o_request),
                   reinterpret_cast<void*>(&i_sbeMessage),
                   i_sbeMessage.sbeHdr.msgSize);
        }

        return errl;
    }

    //------------------------------------------------------------------------

    /**
     *  @brief SBE message passing call pass-through command processor
     *
     *  @details  This is a call that will call the appropriate command
     *            processor for a pass-through command.
     *
     *  @param[in]  i_proc      HB processor target
     *  @param[in]  i_request   Pass-through command request
     *  @param[out] o_response  Pass-through command response
     *
     *  @returns  errlHndl_t  NULL on success
     */
    errlHndl_t process_sbe_msg_cmd_processor(TargetHandle_t i_proc,
                                             sbeMessage_t& i_request,
                                             sbeMessage_t& o_response)
    {
        errlHndl_t errl = nullptr;

        uint32_t l_command = i_request.cmdHdr.command;

        if(g_processCmdMap.find(l_command) == g_processCmdMap.end())
        {
            TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: process "
                      "command, function pointer not found for command 0x%08x",
                      l_command);

            /*@
             * @errortype
             * @moduleid     SBEIO::SBEIO_RUNTIME
             * @reasoncode   SBEIO::SBEIO_RT_FUNCTION_NOT_FOUND
             * @userdata1[0:31]   Processor HUID
             * @userdata1[32:63]  Request Command
             * @userdata2    Sequence ID
             *
             * @devdesc      SBEIO RT Process Pass-through command function not
             *                found.
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO::SBEIO_RUNTIME,
                                 SBEIO::SBEIO_RT_FUNCTION_NOT_FOUND,
                                 TWO_UINT32_TO_UINT64(
                                     get_huid(i_proc),
                                     l_command),
                                 i_request.sbeHdr.seqId);

            errl->addFFDC( SBE_COMP_ID,
                           &(i_request),
                           sizeof(sbeHeader_t) + sizeof(cmdHeader_t),
                           0,                 // Version
                           ERRL_UDT_NOFORMAT, // parser ignores data
                                              // ^^^ @TODO RTC:172362
                           false );           // merge
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
        }
        else if(g_processCmdMap[l_command] == nullptr)
        {
            TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: process "
                      "command, function pointer not set for command 0x%08x",
                      l_command);

            /*@
             * @errortype
             * @moduleid     SBEIO::SBEIO_RUNTIME
             * @reasoncode   SBEIO::SBEIO_RT_FUNCTION_NOT_SET
             * @userdata1[0:31]   Processor HUID
             * @userdata1[32:63]  Request Command
             * @userdata2    Sequence ID
             *
             * @devdesc      SBEIO RT Process Pass-through command function not
             *                set.
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO::SBEIO_RUNTIME,
                                 SBEIO::SBEIO_RT_FUNCTION_NOT_SET,
                                 TWO_UINT32_TO_UINT64(
                                     get_huid(i_proc),
                                     l_command),
                                 i_request.sbeHdr.seqId);

            errl->addFFDC( SBE_COMP_ID,
                           &(i_request),
                           sizeof(sbeHeader_t) + sizeof(cmdHeader_t),
                           0,                 // Version
                           ERRL_UDT_NOFORMAT, // parser ignores data
                                              // ^^^ @TODO RTC:172362
                           false );           // merge
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
        }
        else
        {
            // Trace command to be processed
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: process "
                      "command, process command 0x%08x with sequence ID 0x%08x",
                      l_command,
                      i_request.sbeHdr.seqId);

            // Check data offset
            if(o_response.cmdHdr.dataOffset > sizeof(cmdHeader_t))
            {
                TRACFCOMP(g_trac_sbeio, "process_sbe_msg: process command "
                          "adjusting response data offset");

                // Change offset to show response payload is being put
                // immediately after command header
                o_response.cmdHdr.dataOffset = sizeof(cmdHeader_t);
            }

            // Call function to process command
            errl = g_processCmdMap[l_command](i_proc,
                                              i_request.cmdHdr.dataSize,
                                              i_request.data,
                                              &o_response.cmdHdr.status,
                                              &o_response.cmdHdr.dataSize,
                                              o_response.data);

            if(errl)
            {
                TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: process "
                          "command returned error log",
                          o_response.cmdHdr.dataSize);

                errl->addFFDC( SBE_COMP_ID,
                               &(i_request),
                               sizeof(sbeHeader_t) + sizeof(cmdHeader_t),
                               0,                 // Version
                               ERRL_UDT_NOFORMAT, // parser ignores data
                               false );           // merge
                errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH);
                errl->collectTrace(SBEIO_COMP_NAME);
            }
            else if(o_response.cmdHdr.dataSize > SBE_MSG_MAX_DATA)
            {
                TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: process "
                          "command, response data size 0x%08x too large",
                          o_response.cmdHdr.dataSize);

                /*@
                 * @errortype
                 * @moduleid     SBEIO::SBEIO_RUNTIME
                 * @reasoncode   SBEIO::SBEIO_RT_RSP_DATA_TOO_LARGE
                 * @userdata1[0:31]   Processor HUID
                 * @userdata1[32:63]  Request Command
                 * @userdata2[0:31]   Sequence ID
                 * @userdata2[32:63]  Response Data Size
                 *
                 * @devdesc      SBEIO RT Process Pass-through command response
                 *                data size too large.
                 * @custdesc     Firmware error communicating with boot device
                 */
                errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                     SBEIO::SBEIO_RUNTIME,
                                     SBEIO::SBEIO_RT_RSP_DATA_TOO_LARGE,
                                     TWO_UINT32_TO_UINT64(
                                         get_huid(i_proc),
                                         l_command),
                                     TWO_UINT32_TO_UINT64(
                                         i_request.sbeHdr.seqId,
                                         o_response.cmdHdr.dataSize));

                errl->addFFDC( SBE_COMP_ID,
                               &(i_request),
                               sizeof(sbeHeader_t) + sizeof(cmdHeader_t),
                               0,                 // Version
                               ERRL_UDT_NOFORMAT, // parser ignores data
                                                  // ^^^ @TODO RTC:172362
                               false );           // merge
                errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH);
                errl->collectTrace(SBEIO_COMP_NAME);

                // Calculate message size for response using max data
                o_response.sbeHdr.msgSize = sizeof(sbeHeader_t) +
                    sizeof(cmdHeader_t) + SBE_MSG_MAX_DATA;
            }
            else
            {
                // Calculate message size for response
                o_response.sbeHdr.msgSize = sizeof(sbeHeader_t) +
                    sizeof(cmdHeader_t) + o_response.cmdHdr.dataSize;
            }

            // Trace response to command that was processed
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: process "
                      "command, response to command 0x%08x with sequence ID "
                      "0x%08x was status 0x%08x",
                      o_response.cmdHdr.command,
                      o_response.sbeHdr.seqId,
                      o_response.cmdHdr.status);
        }

        return errl;
    }

    //------------------------------------------------------------------------

    /**
     *  @brief SBE message passing check pass-through command response
     *
     *  @details  This is a call that will check a pass-through command
     *            response that was written to the SBE Communication buffer
     *            against certain fields from the local copy of the command.
     *
     *  @param[in]  i_proc        HB processor target
     *  @param[in]  i_sbeMessage  Pass-through command response in sbe-comm
     *  @param[in]  i_request     Copied pass-through command request
     *
     *  @returns  errlHndl_t  NULL on success
     */
    errlHndl_t process_sbe_msg_check_response(TargetHandle_t i_proc,
                                              sbeMessage_t& i_sbeMessage,
                                              sbeMessage_t& i_request)
    {
        errlHndl_t errl = nullptr;

        if((i_sbeMessage.sbeHdr.version != i_request.sbeHdr.version) ||
           (i_sbeMessage.sbeHdr.seqId != i_request.sbeHdr.seqId) ||
           (i_sbeMessage.cmdHdr.version != i_request.cmdHdr.version) ||
           (i_sbeMessage.cmdHdr.command != i_request.cmdHdr.command))
        {
            TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: check "
                      "response, response field was altered");

            /*@
             * @errortype
             * @moduleid     SBEIO::SBEIO_RUNTIME
             * @reasoncode   SBEIO::SBEIO_RT_RSP_FIELD_ALTERED
             * @userdata1[0:31]   Processor HUID
             * @userdata1[32:63]  Request Command
             * @userdata2    Sequence ID
             *
             * @devdesc      SBEIO RT Check Pass-through command response field
             *                was altered.
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO::SBEIO_RUNTIME,
                                 SBEIO::SBEIO_RT_RSP_FIELD_ALTERED,
                                 TWO_UINT32_TO_UINT64(
                                     get_huid(i_proc),
                                     i_request.cmdHdr.command),
                                 i_request.sbeHdr.seqId);

            errl->addFFDC( SBE_COMP_ID,
                           &(i_request),
                           sizeof(sbeHeader_t) + sizeof(cmdHeader_t),
                           0,                 // Version
                           ERRL_UDT_NOFORMAT, // parser ignores data
                           false );           // merge
            errl->addFFDC( SBE_COMP_ID,
                           &(i_sbeMessage),
                           sizeof(sbeHeader_t) + sizeof(cmdHeader_t),
                           0,                 // Version
                           ERRL_UDT_NOFORMAT, // parser ignores data
                           false );           // merge
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
        }

        return errl;
    }

    //------------------------------------------------------------------------

    int process_sbe_msg(uint32_t i_procChipId)
    {
        TRACFCOMP(g_trac_hbrt, ENTER_MRK" sbe_message_passing: i_procChipId=%d", i_procChipId );
        int rc = 0;
        errlHndl_t errl = nullptr;

        TRACFCOMP(g_trac_sbeio, ENTER_MRK" process_sbe_msg: on proc %d", i_procChipId );

        // Used to store a local copy of the Pass-through command and preserve
        // it during processing (response overlays SBE Communication buffer)
        sbeMessage_t l_request;

        do
        {
            // Convert chipId to HB target
            TargetHandle_t l_proc = nullptr;
            errl = RT_TARG::getHbTarget(i_procChipId, l_proc);
            if(errl)
            {
                TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: getHbTarget "
                         "returned rc=0x%04X for procChipId: %llx",
                          rc, i_procChipId);

                break;
            }

            // Set CFAM register - processing in progress
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: set CFAM register - "
                                    "processing in progress");
            errl = process_sbe_msg_update_cfam(l_proc, SBE_MSG_IN_PROGRESS);

            if(errl)
            {
                break;
            }

            // Get SBE Communication Buffer for target processor
            uint64_t l_sbeCommAddr =
                l_proc->getAttr<TARGETING::ATTR_SBE_COMM_ADDR>();

            // Make sure SBE Communication Buffer is set
            if(l_sbeCommAddr == NULL)
            {
                TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: getAttr "
                          "did not get SBE Communication buffer address");

                /*@
                 * @errortype
                 * @moduleid     SBEIO::SBEIO_RUNTIME
                 * @reasoncode   SBEIO::SBEIO_RT_NO_SBE_COMM_BUFFER
                 * @userdata1    Processor HUID
                 * @userdata2    Reserved
                 *
                 * @devdesc      SBEIO RT Process Pass-through command SBE
                 *                Communication buffer not set.
                 * @custdesc     Firmware error communicating with boot device
                 */
                errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                     SBEIO::SBEIO_RUNTIME,
                                     SBEIO::SBEIO_RT_NO_SBE_COMM_BUFFER,
                                     get_huid(l_proc),
                                     0);

                errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH);
                errl->collectTrace(SBEIO_COMP_NAME);

                break;
            }

            // Provide access to SBE Communication Buffer as an SBE Message
            sbeMessage_t *l_sbeMessage =
                reinterpret_cast<sbeMessage_t*>(l_sbeCommAddr);

            // Process SBE message read command
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: read command");
            errl = process_sbe_msg_read_command(l_proc,
                                                *l_sbeMessage,
                                                l_request);
            if (errl)
            {
                break;
            }

            // Call appropriate command processor
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: call command processor");
            errl = process_sbe_msg_cmd_processor(l_proc,
                                                 l_request,
                                                 *l_sbeMessage);
            if(errl)
            {
                break;
            }

            // Process SBE message check response
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: check response");
            errl = process_sbe_msg_check_response(l_proc,
                                                  *l_sbeMessage,
                                                  l_request);
            if(errl)
            {
                break;
            }

            // Set CFAM register - processing complete
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: set CFAM register - "
                                    "processing complete");
            errl = process_sbe_msg_update_cfam(l_proc, SBE_MSG_COMPLETE);

            if(errl)
            {
                break;
            }
        } while(0);

        if(errl)
        {
            rc = errl->reasonCode();
            if (0 == rc)
            {
                // If there was a failure, be sure to return non-zero status
                rc = -1;
            }
            errlCommit (errl, SBE_COMP_ID);
        }

        TRACFCOMP(g_trac_sbeio, EXIT_MRK" process_sbe_msg: rc=0x%X", rc );
        TRACFCOMP(g_trac_hbrt, EXIT_MRK" sbe_message_passing: rc=0x%X", rc );
        return rc;
    }

    //------------------------------------------------------------------------

#ifdef CONFIG_HTMGT
    /**
     * @brief Function to process pass-through command from SBE message
     *
     * @param[in]  i_procTgt      HB processor target
     * @param[in]  i_reqDataSize  Pass-through command request data size
     * @param[in]  i_reqData      Pass-through command request data
     * @param[out] o_rspStatus    Pass-through command response status
     * @param[out] o_rspDataSize  Pass-through command response data size
     * @param[out] o_rspData      Pass-through command response data
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t htmgt_pass_thru_wrapper(TARGETING::TargetHandle_t i_procTgt,
                                       uint32_t i_reqDataSize,
                                       uint8_t* i_reqData,
                                       uint32_t* o_rspStatus,
                                       uint32_t* o_rspDataSize,
                                       uint8_t* o_rspData)
    {
        errlHndl_t errl = nullptr;
        uint16_t l_rspDataSize = 0;

        *o_rspStatus = HTMGT::htmgt_pass_thru(i_reqDataSize,
                                              i_reqData,
                                              &l_rspDataSize,
                                              o_rspData);
        *o_rspDataSize = l_rspDataSize;

        return errl;
    }
#endif

    /**
     * @brief Function to process PMIC health check pass-through command
     *
     * @param[in]  i_procTgt      HB processor target
     * @param[in]  i_reqDataSize  Pass-through command request data size
     * @param[in]  i_reqData      Pass-through command request data
     * @param[out] o_rspStatus    Pass-through command response status
     * @param[out] o_rspDataSize  Pass-through command response data size
     * @param[out] o_rspData      Pass-through command response data
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t pmic_health_check_wrapper(TARGETING::TargetHandle_t i_procTgt,
                                         uint32_t i_reqDataSize,
                                         uint8_t* i_reqData,
                                         uint32_t* o_rspStatus,
                                         uint32_t* o_rspDataSize,
                                         uint8_t* o_rspData)
    {
        errlHndl_t l_err = nullptr;

        *o_rspStatus = 0;
        *o_rspDataSize = 0;
        *o_rspData = 0;

        l_err = SBEIO::getAllPmicHealthCheckData();

        if (l_err)
        {   // if error, return a bad status
            *o_rspStatus = 0xFFFFFFFF; // -1
        }

        return l_err;
    }

    //------------------------------------------------------------------------

    struct registerSbeio
    {
        registerSbeio()
        {
            runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
            rt_intf->sbe_message_passing =
                                    DISABLE_MCTP_WRAPPER(process_sbe_msg);

            TargetHandleList procChips;
            getAllChips(procChips, TYPE_PROC, true);
            for (const auto & l_procChip: procChips)
            {
                // Note: the instance we use to retrieve the data must
                //   match the value we used to populate HDAT originally
                uint64_t l_instance = l_procChip->getAttr<ATTR_HBRT_HYP_ID>();
                uint64_t l_sbeCommAddr = g_hostInterfaces->get_reserved_mem(
                                         HBRT_RSVD_MEM__SBE_COMM,
                                         l_instance);
                l_procChip->setAttr<ATTR_SBE_COMM_ADDR>(l_sbeCommAddr);
                TRACFCOMP( g_trac_sbeio, INFO_MRK" COMM_ADDR=0x%.llX for %.8X",
                           l_sbeCommAddr,
                           TARGETING::get_huid(l_procChip) );
            }

#ifdef CONFIG_HTMGT
            SBE_MSG::setProcessCmdFunction(PASSTHRU_HTMGT_GENERIC,
                                           htmgt_pass_thru_wrapper);
#endif
            SBE_MSG::setProcessCmdFunction(PASSTHRU_HBRT_OVERRIDE_ATTR,
                                           sbeApplyAttrOverrides);
            SBE_MSG::setProcessCmdFunction(PASSTHRU_HBRT_OVERRIDE_VPD,
                                           sbeApplyVpdOverrides);
            // Check if PMIC health check is even available
            if (TARGETING::arePmicsInBlueprint())
            {
                SBE_MSG::setProcessCmdFunction(PASSTHRU_HBRT_PMIC_HLTH_CHK,
                                               pmic_health_check_wrapper);
            }
       }
    };

    registerSbeio g_registerSbeio;
} // namespace RT_SBEIO


namespace SBE_MSG
{
    // Set an entry in map of process command functions
    int setProcessCmdFunction(enum passThruCmds    i_command,
                              processCmdFunction_t i_function)
    {
        int rc = 0;

        do
        {
            RT_SBEIO::g_processCmdMap[i_command] = i_function;

            if(RT_SBEIO::g_processCmdMap[i_command] != i_function)
            {
                TRACFCOMP(g_trac_sbeio, ERR_MRK"setProcessCmdFunction: "
                          "process command function not set for command 0x%08x",
                          i_command);

                rc = -1;

                break;
            }
        } while(0);

        return rc;
    }

    // Erase an entry in map of process command functions
    int eraseProcessCmdFunction(enum passThruCmds i_command)
    {
        int rc = 0;

        do
        {
            RT_SBEIO::g_processCmdMap.erase(i_command);

            if(RT_SBEIO::g_processCmdMap.find(i_command) !=
               RT_SBEIO::g_processCmdMap.end())
            {
                TRACFCOMP(g_trac_sbeio, ERR_MRK"eraseProcessCmdFunction: "
                          "process command function not erased for command "
                          "0x%08x",
                          i_command);

                rc = -1;

                break;
            }
        } while(0);

        return rc;
    }


    /**
     *  @brief SBE message update bit(s) in CFAM register
     *
     *  @details This is a call that will update bit(s) in Mailbox
     *           Scratch register 4.
     *
     *  @param[in]  i_proc        HB processor target
     *  @param[in]  i_state       New state of the SBE message
     *
     *  @returns  errlHndl_t  NULL on success
     */
    errlHndl_t process_sbe_msg_update_cfam(TargetHandle_t i_proc,
                                           const sbe_msg_processing_state_t i_state)
    {
        using namespace INITSERVICE::SPLESS;

        errlHndl_t errl = nullptr;

        do{
            MboxScratch4_t l_mbox4 { };

            size_t l_size = sizeof(uint64_t);

            // Read mailbox scratch reg 4 for target proc
            errl = deviceRead(i_proc,
                              &l_mbox4.data32,
                              l_size,
                              DEVICE_SCOM_ADDRESS(MboxScratch4_t::REG_ADDR));

            if(errl)
            {
                TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg_update_cfam: "
                          "CFAM read failed for target 0x%llX SCOM addr 0x%llX",
                          get_huid(i_proc),
                          MboxScratch4_t::REG_ADDR);

                errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH);
                errl->collectTrace(SBEIO_COMP_NAME);

                break;
            }

            TRACFCOMP(g_trac_sbeio, "process_sbe_msg_update_cfam: CFAM read "
                      "returned 0x%llX for target 0x%llX",
                      l_mbox4.data32, get_huid(i_proc) );

            l_mbox4.sbeMsgProc.sbeMsgProcessingComplete
                = (i_state & SBE_MSG_COMPLETE) != 0;

            l_mbox4.sbeMsgProc.sbeMsgProcessingInProgress
                = (i_state & SBE_MSG_IN_PROGRESS) != 0;

            TRACFCOMP(g_trac_sbeio, "process_sbe_msg_update_cfam: "
                      "CFAM write 0x%llX to SCOM addr 0x%llX for target 0x%llX",
                      l_mbox4.data32,
                      MboxScratch4_t::REG_ADDR,
                      get_huid(i_proc) );

            // Write mailbox scratch reg 4 for target proc
            errl = deviceWrite(i_proc,
                               &l_mbox4.data32,
                               l_size,
                               DEVICE_SCOM_ADDRESS(MboxScratch4_t::REG_ADDR));

            if(errl)
            {
                TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg_update_cfam: "
                          "write CFAM failed for target 0x%llX SCOM addr 0x%llX",
                          get_huid(i_proc),
                          MboxScratch4_t::REG_ADDR);

                errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH);
                errl->collectTrace(SBEIO_COMP_NAME);

                break;
            }
        }while(0);

        return errl;
     }

} // namespace SBE_MSG
