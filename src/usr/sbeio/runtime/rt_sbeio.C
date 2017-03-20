/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/rt_sbeio.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include <sbeio/sbeioreasoncodes.H>
#include <util/singleton.H>
#include <errno.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errlreasoncodes.H>

//  targeting support
#include    <targeting/common/target.H>
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <runtime/rt_targeting.H>


using namespace TARGETING;
using namespace ERRORLOG;
using namespace SBE_MSG;

// Trace
trace_desc_t* g_trac_sbeio;
TRAC_INIT(&g_trac_sbeio, SBEIO_COMP_NAME, 6*KILOBYTE, TRACE::BUFFER_SLOW);


namespace RT_SBEIO
{
    // Map of process command functions for the pass-through commands
    ProcessCmdMap_t g_processCmdMap;

    //------------------------------------------------------------------------

    //------------------------------------------------------------------------

    int process_sbe_msg_cmd_processor(TargetHandle_t i_proc,
                                      sbeMessage_t& i_request,
                                      sbeMessage_t& o_response)
    {
        errlHndl_t errl = nullptr;
        int rc = 0;
        uint32_t l_command = i_request.cmdHdr.command;

        if(g_processCmdMap.find(l_command) == g_processCmdMap.end())
        {
            TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: process "
                      "command, function pointer not found for command 0x%08x",
                      l_command);

            rc = -201;

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
            errlCommit(errl, SBE_COMP_ID);
        }
        else
        {
            // Trace command to be processed
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: process "
                      "command, process command 0x%08x with sequence ID 0x%08x",
                      l_command,
                      i_request.sbeHdr.seqId);

            // Call function to process command
            errl = g_processCmdMap[l_command](i_proc,
                                              i_request.cmdHdr.dataSize,
                                              i_request.data,
                                              &o_response.cmdHdr.status,
                                              &o_response.cmdHdr.dataSize,
                                              o_response.data);

            if(o_response.cmdHdr.dataSize > SBE_MSG_MAX_DATA)
            {
                TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: process "
                          "command, response data size 0x%08x too large",
                          o_response.cmdHdr.dataSize);

                rc = -202;

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
                errlCommit(errl, SBE_COMP_ID);

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

        return rc;
     }

    //------------------------------------------------------------------------

    //------------------------------------------------------------------------

    int process_sbe_msg(uint32_t i_procChipId)
    {
        int rc = 0;
        errlHndl_t errl = nullptr;

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
                rc = errl->reasonCode();
                if (0 == rc)
                {
                    // If there was a failure, be sure to return non-zero status
                    rc = -1;
                }

                TRACFCOMP(g_trac_sbeio, ERR_MRK"process_sbe_msg: getHbTarget "
                         "returned rc=0x%04X for procChipId: %llx",
                          rc, i_procChipId);

                errlCommit (errl, SBE_COMP_ID);

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

                rc = -2;

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
                errlCommit(errl, SBE_COMP_ID);

                break;
            }

            // Provide access to SBE Communication Buffer as an SBE Message
            sbeMessage_t *l_sbeMessage =
                reinterpret_cast<sbeMessage_t*>(l_sbeCommAddr);

            /* TODO RTC 170760 process SBE message read command */
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: read command");

            // Call appropriate command processor
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: call command processor");
            rc = process_sbe_msg_cmd_processor(l_proc,
                                               l_request,
                                               *l_sbeMessage);
            if(rc != 0)
            {
                break;
            }

            /* TODO RTC 170762 process SBE message write response */
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: write response");

            /* TODO RTC 170763 assert CFAM register ??? */
            TRACFCOMP(g_trac_sbeio, "process_sbe_msg: assert CFAM register");
        } while(0);

        return rc;
    }

    //------------------------------------------------------------------------

    //------------------------------------------------------------------------

    //------------------------------------------------------------------------

    struct registerSbeio
    {
        registerSbeio()
        {
            runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
            rt_intf->sbe_message_passing = &process_sbe_msg;

            TargetHandleList procChips;
            getAllChips(procChips, TYPE_PROC, true);
            for (const auto & l_procChip: procChips)
            {
                uint64_t l_instance = l_procChip->getAttr<ATTR_POSITION>();
                uint64_t l_sbeCommAddr =
                         g_hostInterfaces->get_reserved_mem("ibm,sbe-comm",
                                                            l_instance);
                l_procChip->setAttr<ATTR_SBE_COMM_ADDR>(l_sbeCommAddr);
            }
        }
    };

    registerSbeio g_registerSbeio;
} // namespace RT_SBEIO


namespace SBE_MSG
{
    // Set an entry in list of process command functions
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
} // namespace SBE_MSG
