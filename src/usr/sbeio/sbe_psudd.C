/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psudd.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
/**
 * @file sbe_psudd.C
 * @brief SBE PSU device driver
 */

#include <sys/time.h>
#include <sys/task.h>
#include <trace/interface.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/target.H>
#include <errl/errlreasoncodes.H>
#include <sbeio/sbeioreasoncodes.H>
#include <sbeio/sbe_ffdc_package_parser.H>
#include <sbeio/sbe_psudd.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <arch/magic.H>
#include <kernel/pagemgr.H>
#include <sbeio/sbeioif.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <p10_extract_sbe_rc.H>
#include <errl/errludlogregister.H>
#include <sbeio/sbe_retry_handler.H>
#include <initservice/initserviceif.H>
#include <intr/interrupt.H>
#include <errno.h>
#include <sys/time.h>
#include <errl/errludprintk.H>
#include <vfs/vfs.H> // module_is_loaded
#include <util/misc.H>

trace_desc_t* g_trac_sbeio;
TRAC_INIT(&g_trac_sbeio, SBEIO_COMP_NAME, 6*KILOBYTE, TRACE::BUFFER_SLOW);

// used to uniquely identify the SBE PSU message queue
const char* SBE_PSU_MSG_Q = "sbepsuq";

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"psudd: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"psudd: " printf_string,##args)
#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio,"psudd: " printf_string,##args)


using namespace ERRORLOG;

namespace SBEIO
{

sbeAllocationHandle_t sbeMalloc(const size_t i_bytes, void*& o_allocation)
{
    // The buffer must be a multiple of SBE_ALIGNMENT_SIZE_IN_BYTES
    // bytes in size, and it must be aligned to a
    // SBE_ALIGNMENT_SIZE_IN_BYTES byte boundary.
    const size_t l_totalAlignedSize =
        (ALIGN_X(i_bytes, SbePsu::SBE_ALIGNMENT_SIZE_IN_BYTES)
         + (SbePsu::SBE_ALIGNMENT_SIZE_IN_BYTES - 1));

    // Create buffer with enough size to be properly aligned
    void* const l_sbeBuffer = malloc(l_totalAlignedSize);

    // Align the buffer
    const uint64_t l_sbeBufferAligned =
        ALIGN_X(reinterpret_cast<uint64_t>(l_sbeBuffer),
                SbePsu::SBE_ALIGNMENT_SIZE_IN_BYTES);

    o_allocation = reinterpret_cast<void*>(l_sbeBufferAligned);

    // Return a pointer to the original buffer, so we can free() it later
    return { l_sbeBuffer };
}

SbePsu & SbePsu::getTheInstance()
{
    return Singleton<SbePsu>::instance();
}

void * SbePsu::msg_handler(void *unused)
{
    Singleton<SbePsu>::instance().msgHandler();
    return nullptr;
}

/**
 * @brief  Constructor
 **/
SbePsu::SbePsu()
    :
        iv_earlyErrorOccurred(false),
        iv_psuResponse(nullptr),
        iv_responseReady(false),
        iv_shutdownInProgress(false)
{
    errlHndl_t l_err = nullptr;
    size_t rc = 0;

    //Create message queue
    iv_msgQ = msg_q_create();

    //Register message queue with unique identifier
    rc = msg_q_register(iv_msgQ, SBE_PSU_MSG_Q);

    if(rc)   // could not register msgQ with kernel
    {
        SBE_TRACF(ERR_MRK "SbePsu() Could not register"
                   "message queue with kernel");

        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        SBEIO_PSU
         * @reasoncode      SBEIO_RC_KERNEL_REG_FAILED
         * @userdata1       rc from msq_q_register
         * @devdesc         Could not register mailbox message queue
         */
        l_err = new ErrlEntry
             (
              ERRL_SEV_CRITICAL_SYS_TERM,
              SBEIO_PSU,
              SBEIO_RC_KERNEL_REG_FAILED,    //  reason Code
              rc,                        // rc from msg_send
              0,
              true //Add HB Software Callout
             );
    }

    if (!l_err)
    {

        // create task before registering the msgQ so any waiting interrupts get
        // handled as soon as the msgQ is registered with the interrupt service
        // provider
        task_create(SbePsu::msg_handler, NULL);

        //Register message queue with INTRP for Interrupts
        //   of type LSI_PSU. The INTRP will route messages
        //   to this queue when interrupts of that type are
        //   detected
        l_err = INTR::registerMsgQ(iv_msgQ,
                                   MSG_INTR,
                                   INTR::ISN_PSU);
    }

    if (l_err)
    {
        SBE_TRACF(ERR_MRK"Error in SbePsu Constructor");
        l_err->collectTrace(INTR_COMP_NAME, 256);
        // save off reason code before committing
        auto l_reason = l_err->reasonCode();
        errlCommit(l_err, SBEIO_COMP_ID);
        INITSERVICE::doShutdown(l_reason);
    }
}

/**
 * @brief  Destructor
 **/
SbePsu::~SbePsu()
{
    std::map<TARGETING::Target *, void *>::iterator l_iter;
    for(l_iter = iv_ffdcPackageBuffer.begin();
        l_iter != iv_ffdcPackageBuffer.end(); l_iter++)
    {
        if(l_iter->second != NULL)
        {
            PageManager::freePage(l_iter->second);
        }
    }
}

void SbePsu::msgHandler()
{
    // Mark as an independent daemon so if it crashes we terminate.
    task_detach();

    errlHndl_t l_err = nullptr;

    while(1)
    {
        msg_t* msg = msg_wait(iv_msgQ);

        //Message should never be nullptr
        assert(msg != nullptr,"SbePsu::msgHandle: msg is nullptr");

        switch(msg->type)
        {
            case MSG_INTR:
                {
                    if (msg->data[0] == INTR::SHUT_DOWN)
                    {
                        iv_shutdownInProgress = true;
                        SBE_TRACF("SbePsu::msgHandler Handle Shutdown");
                        //respond so INTRP can continue
                        // with shutdown procedure
                        msg_respond(iv_msgQ,msg);
                    }
                    else
                    {
                        //Handle the interrupt message -- pass the PIR of the
                        // proc causing the interrupt
                        SBE_TRACF("SbePsu::msgHandler got MSG_INTR message");
                        l_err = handleInterrupt(msg->data[1]);

                        if (l_err)
                        {
                            SBE_TRACF("SbePsu::msgHandler handleInterrupt returned an error");
                            l_err->collectTrace(SBEIO_COMP_NAME);
                            l_err->collectTrace(INTR_COMP_NAME, 256);
                            errlCommit(l_err, SBEIO_COMP_ID);
                        }

                        // Respond to the interrupt handler regardless of error
                        INTR::sendEOI(iv_msgQ,msg);
                    }
                }
                break;
            default:
                msg->data[1] = -EINVAL;
                msg_respond(iv_msgQ, msg);
        }
    }

}

const SbePsu::unsupported_command_error_severity SbePsu::COMMAND_SUPPORT_OPTIONAL { ERRORLOG::ERRL_SEV_UNKNOWN };

errlHndl_t SbePsu::performPsuChipOp(TARGETING::Target *    i_target,
                                    psuCommand     *       i_pPsuRequest,
                                    psuResponse    *       o_pPsuResponse,
                                    const uint64_t         i_timeout,
                                    uint8_t                i_reqMsgs,
                                    uint8_t                i_rspMsgs,
                                    const unsupported_command_error_severity i_supportErrSev,
                                    bool* const            o_unsupportedOp)

{
    errlHndl_t errl = NULL;
    static mutex_t l_psuOpMux = MUTEX_INITIALIZER;

    SBE_TRACD(ENTER_MRK "performPsuChipOp");

    if (o_unsupportedOp)
    {
        *o_unsupportedOp = false;
    }

    //Only perform new chip-ops if we aren't shutting down
    if (!iv_shutdownInProgress)
    {
        // If not an SBE_PSU_SET_FFDC_ADDRESS command,
        // we allocate an FFDC buffer and set FFDC adress
        if(i_pPsuRequest->command != SBE_PSU_SET_FFDC_ADDRESS)
        {
            errl = allocateFFDCBuffer(i_target);
        }
        if (errl)
        {
            SBE_TRACF(ERR_MRK"performPsuChipOp::"
                " setFFDC address returned an error");
            return errl;
        }

        //Serialize access to PSU
        mutex_lock(&l_psuOpMux);

        if (iv_psuResponse != nullptr)
        {
            //There should already be a timeout errorlog for this condition,
            // simply log a message and continue as the previous timeout was
            // not deemed fatal.
            SBE_TRACF(ERR_MRK "performPsuChipOp Previous PSU response never completed.");
        }

        iv_psuResponse = o_pPsuResponse;
        iv_responseReady = false;

        // Check that target is not NULL
        assert(i_target != nullptr,"performPsuChipOp: proc target is NULL");

        do
        {
            MAGIC_INST_TOGGLE_OUTPUT(ENABLE_OUTPUT);
            MAGIC_INST_SET_LOG_LEVEL(PIB_PSU, LOG_LEVEL_MAX);
            MAGIC_INST_SET_LOG_LEVEL(SBE_INT_BO, LOG_LEVEL_MAX);

            // write PSU Request
            errl = writeRequest(i_target,
                                i_pPsuRequest,
                                i_reqMsgs);
            if (errl)//error has been generated
            {
                SBE_TRACF(ERR_MRK"performPsuChipOp::"
                        " writeRequest returned an error");
                break;
            }

            // read PSU response and check results
            errl = checkResponse(i_target,
                                 i_pPsuRequest,
                                 iv_psuResponse,
                                 i_timeout,
                                 i_rspMsgs);
            if (errl){
                SBE_TRACF(ERR_MRK"performPsuChipOp::"
                        " checkResponse returned an error");
                break;  // return with error
            }

            if (    SBE_PRI_INVALID_COMMAND       == o_pPsuResponse->primaryStatus
                && (SBE_SEC_COMMAND_NOT_SUPPORTED == o_pPsuResponse->secondaryStatus
                    || SBE_SEC_COMMAND_CLASS_NOT_SUPPORTED == o_pPsuResponse->secondaryStatus))
            {
                if (o_unsupportedOp)
                {
                    *o_unsupportedOp = true;
                }

                if (i_supportErrSev.error_sev != ERRL_SEV_UNKNOWN)
                {
                    SBE_TRACF("The SBE does not support command class %d/command %d on target 0x%08x",
                              i_pPsuRequest->commandClass,
                              i_pPsuRequest->command,
                              get_huid(i_target));

                    /*@
                     * @errortype
                     * @moduleid        SBEIO_PSU
                     * @reasoncode      SBEIO_COMMAND_NOT_SUPPORTED
                     * @userdata1       PSU command class
                     * @userdata2       PSU command
                     * @devdesc         Current SBE version does not support the attempted PSU command
                     * @custdesc        SBE version too old
                     */
                    errl = new ErrlEntry(i_supportErrSev.error_sev,
                                         SBEIO_PSU,
                                         SBEIO_COMMAND_NOT_SUPPORTED,
                                         i_pPsuRequest->commandClass,
                                         i_pPsuRequest->command,
                                         ErrlEntry::ADD_SW_CALLOUT);

                    errl->collectTrace(SBEIO_COMP_NAME);
                }
            }
        }
        while (0);

        MAGIC_INST_SET_LOG_LEVEL(PIB_PSU, LOG_LEVEL_OFF);
        MAGIC_INST_SET_LOG_LEVEL(SBE_INT_BO, LOG_LEVEL_OFF);
        MAGIC_INST_TOGGLE_OUTPUT(DISABLE_OUTPUT);

        iv_psuResponse = nullptr;
        mutex_unlock(&l_psuOpMux);
    }
    else
    {
        SBE_TRACF(ERR_MRK"performPsuChipOp::"
                  "Skipping operation because of Shutdown operation");
    }

    SBE_TRACD(EXIT_MRK "performPsuChipOp");

    return errl;
}

/**
 * @brief record info from an "early" error so it can be reported later
 */
void SbePsu::saveEarlyError(uint32_t i_plid, TARGETING::TargetHandle_t i_target)
{
    SBE_TRACD(ENTER_MRK "saveEarlyError");

    iv_earlyErrorOccurred = true;
    iv_earlyErrorPlid     = i_plid;
    iv_earlyErrorTarget   = i_target;

    SBE_TRACD(EXIT_MRK "saveEarlyError");
}

/**
 * @brief If an "early" error was detected, then record and process it.
 */
errlHndl_t SbePsu::processEarlyError()
{
    errlHndl_t l_err = nullptr;
    SBE_TRACD(ENTER_MRK "processEarlyError");

    if (earlyError())
    {
        SBE_TRACF(ERR_MRK"processEarlyError: early error occurred"
                  ", plid=0x%X, target huid=0x%X",
                  iv_earlyErrorPlid, TARGETING::get_huid(iv_earlyErrorTarget));
        SbeRetryHandler l_SBEobj = SbeRetryHandler(
            SbeRetryHandler::SBE_MODE_OF_OPERATION::INFORMATIONAL_ONLY,
            iv_earlyErrorPlid);

        l_SBEobj.main_sbe_handler(iv_earlyErrorTarget);

        iv_earlyErrorOccurred = false;
        SBE_TRACF(ERR_MRK"processEarlyError: early error processed");
    }

    SBE_TRACD(EXIT_MRK "processEarlyError");
    return l_err;
}

/**
 * @brief write PSU Request message
 */
errlHndl_t SbePsu::writeRequest(TARGETING::Target * i_target,
                                psuCommand        * i_pPsuRequest,
                                uint8_t             i_reqMsgs)
{
    errlHndl_t errl = NULL;
    static uint16_t l_seqID = 0;

    SBE_TRACD(ENTER_MRK "writeRequest");

    do
    {
        // assign sequence ID and save to check that response matches
        i_pPsuRequest->seqID = ++l_seqID;
        SBE_TRACF("Sending Req = %.16X %.16X %.16X %.16X to %.8X",
                  i_pPsuRequest->mbxReg0,
                  i_pPsuRequest->mbxReg1,
                  i_pPsuRequest->mbxReg2,
                  i_pPsuRequest->mbxReg3,
                  get_huid(i_target));

        // Read SBE doorbell to confirm ready to accept command.
        // Since the device driver single threads the requests, we should
        // never see not being ready to send a request.
        uint64_t l_data = 0;
        errl = readScom(i_target,PSU_SBE_DOORBELL_REG_RW,&l_data);
        if (errl) break;

        if (l_data & SBE_DOORBELL)
        {
            SBE_TRACF(ERR_MRK "writeRequest: SBE not ready to accept cmd");
            SBE_TRACF(ERR_MRK " Control Flags,SeqID,Cmd,SubCmd=0x%016lx",
                      i_pPsuRequest->mbxReg0);
            SBE_TRACF(ERR_MRK " Host to PSU door bell=0x%016lx",
                      l_data);
            /*@
             * @errortype
             * @moduleid     SBEIO_PSU
             * @reasoncode   SBEIO_PSU_NOT_READY
             * @userdata1[0:15]   Reserved
             * @userdata1[16:31]  Request Control Flags
             * @userdata1[32:47]  Request Sequence ID
             * @userdata1[48:55]  Request Command Class
             * @userdata1[56:63]  Request Command
             * @userdata2         Host to SBE door bell register
             *
             * @devdesc      SBE PSU device driver not ready
             *               to receive next command.
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_PSU,
                                 SBEIO_PSU_NOT_READY,
                                 i_pPsuRequest->mbxReg0,
                                 l_data);

            void * l_ffdcPkg = findFFDCBufferByTarget(i_target);
            if(l_ffdcPkg != NULL)
            {
                SbeFFDCParser * l_ffdc_parser = new SbeFFDCParser();
                l_ffdc_parser->parseFFDCData(l_ffdcPkg);
                uint8_t l_pkgs = l_ffdc_parser->getTotalPackages();
                uint8_t i;
                for(i = 0; i < l_pkgs; i++)
                {
                    errl->addFFDC( SBEIO_COMP_ID,
                               l_ffdc_parser->getFFDCPackage(i),
                               l_ffdc_parser->getPackageLength(i),
                               0,
                               SBEIO_UDT_PARAMETERS,
                               false );
                }
                delete l_ffdc_parser;
                l_ffdc_parser = nullptr;
            }

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
            MAGIC_INST_GET_SBE_TRACES(
                  i_target->getAttr<TARGETING::ATTR_POSITION>(),
                  SBEIO_PSU_NOT_READY);

            break; // return with error
        }

        //write the command registers
        uint64_t * l_pMessage = (uint64_t *)i_pPsuRequest;
        uint64_t l_addr = PSU_HOST_SBE_MBOX0_REG;
        for (uint8_t i=0;i<4;i++)
        {
            if (0x01 & i_reqMsgs) // write register if non-reserved
            {
                errl = writeScom(i_target,l_addr,l_pMessage);
                if (errl) break;
            }
            i_reqMsgs>>=1;
            l_addr++;
            l_pMessage++;
        }
        if (errl) break;

        //notify PSU command is ready
        l_data = SBE_DOORBELL;
        errl = writeScom(i_target,PSU_SBE_DOORBELL_REG_OR,&l_data);
        if (errl) break;

    }
    while (0);

    SBE_TRACD(EXIT_MRK "writeRequest");

    return errl;
}


errlHndl_t SbePsu::handleInterrupt(PIR_t i_pir)
{
    errlHndl_t errl = nullptr;
    SBE_TRACD(ENTER_MRK "SbePsu::handleInterrupt");
    bool l_responseAvailable = false;
    bool l_simicsRunning = Util::isSimicsRunning();

    do
    {
        uint64_t l_intrTopoID = PIR_t::topologyIdFromPir(i_pir.word);
        // Find the chip that presented the interrupt
        TARGETING::Target* l_intrChip = nullptr;
        TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TARGETING::TYPE_PROC, false);
        for (auto & l_chip: l_procTargetList)
        {
            auto l_topoId =
                (l_chip)->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();
            if(l_topoId == l_intrTopoID)
            {
                l_intrChip = (l_chip);
                break;
            }
        }
        assert(l_intrChip != nullptr,
                   "SbePsu::handleInterrupt: l_intrChip is nullptr");

        //Occasionally, there is a PSU interrupt that is not associated
        // with a PSU response. The HOST_DOORBELL reg will indicate if
        // there is a response available. If there is, it will be read.
        // If not the interrupt condition simply needs to be cleared.
        uint64_t l_doorbellVal = 0x0;
        errl = readScom(l_intrChip,PSU_HOST_DOORBELL_REG_RW,&l_doorbellVal);
        if (errl)
        { break; }

        if ( l_simicsRunning &&
             HOST_RESPONSE_WAITING != (l_doorbellVal & HOST_RESPONSE_WAITING) )
        {
            // wait a second and try again
            nanosleep(1,0);

            //read the door bell again to see if the simics model caught up
            errl = readScom(l_intrChip,PSU_HOST_DOORBELL_REG_RW,&l_doorbellVal);
            if (errl)
            { break; }

        }

        if (l_doorbellVal & HOST_RESPONSE_WAITING)
        {
            //In this case the doorbell reg indicated a response is
            //available
            l_responseAvailable = true;
            //read the response registers
            uint64_t * l_pMessage =
                        reinterpret_cast<uint64_t *>(iv_psuResponse);
            uint64_t   l_addr     = PSU_HOST_SBE_MBOX4_REG;

            for (uint8_t i=0; i<(sizeof(psuResponse)/sizeof(uint64_t)); i++)
            {
                errl = readScom(l_intrChip,l_addr,l_pMessage);
                if (errl)
                { break; }
                l_addr++;
                l_pMessage++;
            }

            if (errl)
            { break; }

            //Notify PSU response has been read
            uint64_t l_data = HOST_CLEAR_RESPONSE_WAITING;
            errl = writeScom(l_intrChip,PSU_HOST_DOORBELL_REG_AND,&l_data);
            if (errl)
            { break; }
        }
        else if(l_simicsRunning)
        {
            SBE_TRACF(ENTER_MRK "SbePsu::handleInterrupt interrupt found but no Doorbell is set 0x%llx", l_doorbellVal);
            // If we are in simics we want to break out here
            MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
        }

        //Clear the rest of the PSU Scom Reg Interrupt Status register
        //  This clears the PSU interrupt condition so the PSU interrupt
        //  won't be re-presented
        uint64_t l_data = HOST_RESPONSE_WAITING;
        errl = writeScom(l_intrChip,PSU_HOST_DOORBELL_REG_AND,&l_data);
        if (errl) break;

    } while (0);

    // Only indicate a response is ready if we found legitimate
    //   PSU message data.
    if (l_responseAvailable)
    {
        iv_responseReady = true;
    }

    SBE_TRACD(EXIT_MRK "SbePsu::handleInterrupt");

    return errl;
}

/**
 * @brief Read PSU response messages
 */
errlHndl_t SbePsu::checkResponse(TARGETING::Target  * i_target,
                                 psuCommand         * i_pPsuRequest,
                                 psuResponse        * o_pPsuResponse,
                                 const uint64_t       i_timeout,
                                 uint8_t              i_rspMsgs)
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "checkResponse");

    do
    {
        //wait for request to be completed
        errl = pollForPsuComplete(i_target,i_timeout,i_pPsuRequest);
        if (errl)
        { break; }  // return with error

        //At this point we will have valid data in iv_psuResponse
        //If the command is not supported, then print a statement and break out
        if(o_pPsuResponse->primaryStatus == SBE_PRI_INVALID_COMMAND &&
           (o_pPsuResponse->secondaryStatus == SBE_SEC_COMMAND_NOT_SUPPORTED
            || o_pPsuResponse->secondaryStatus == SBE_SEC_COMMAND_CLASS_NOT_SUPPORTED))
        {
            SBE_TRACF("sbe_psudd.C :: checkResponse: COMMAND NOT SUPPORTED "
                      " cmd=0x%02x%02x prim=0x%08x secondary=0x%08x"
                      " expected seqID=%d actual seqID=%d",
                      i_pPsuRequest->commandClass,
                      i_pPsuRequest->command,
                      o_pPsuResponse->primaryStatus,
                      o_pPsuResponse->secondaryStatus,
                      i_pPsuRequest->seqID,
                      o_pPsuResponse->seqID);
            SBE_TRACFBIN( "Full response:",
                           o_pPsuResponse,
                           sizeof(psuResponse));
            break;
        }

        //check status and seq ID in response messages
        else if ((SBE_PRI_OPERATION_SUCCESSFUL !=
                                              o_pPsuResponse->primaryStatus) ||
           (SBE_SEC_OPERATION_SUCCESSFUL != o_pPsuResponse->secondaryStatus) ||
           (i_pPsuRequest->seqID != o_pPsuResponse->seqID))
        {

            SBE_TRACF(ERR_MRK "sbe_psudd.C :: checkResponse: "
                      "failing response status "
                      " cmd=0x%02x%02x prim=0x%08x secondary=0x%08x"
                      " expected seqID=%d actual seqID=%d",
                      i_pPsuRequest->commandClass,
                      i_pPsuRequest->command,
                      o_pPsuResponse->primaryStatus,
                      o_pPsuResponse->secondaryStatus,
                      i_pPsuRequest->seqID,
                      o_pPsuResponse->seqID);
            SBE_TRACFBIN("Full response:", o_pPsuResponse, sizeof(psuResponse));

            /*@
             * @errortype
             * @moduleid     SBEIO_PSU
             * @reasoncode   SBEIO_PSU_RESPONSE_ERROR
             * @userdata1[0:31]   Indirect size or 9 for direct command
             * @userdata1[32:47]  Request Sequence ID
             * @userdata1[48:55]  Request Command Class
             * @userdata1[56:63]  Request Command
             * @userdata2[0:15]   Response Primary Status
             * @userdata2[16:31]  Response Secondary Status
             * @userdata2[32:47]  Response Sequence ID
             * @userdata2[48:55]  Response Command Class
             * @userdata2[56:63]  Response Command
             *
             * @devdesc      Unexpected sequence number or non zero
             *               primary or secondary status
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_PSU,
                                 SBEIO_PSU_RESPONSE_ERROR,
                                 i_pPsuRequest->mbxReg0,
                                 o_pPsuResponse->mbxReg4);

            void * l_ffdcPkg = findFFDCBufferByTarget(i_target);

            if(l_ffdcPkg != NULL)
            {
                //If this is a result of setFFDCAddress command, it fails.
                //Deallocate FFDC buffer
                if(i_pPsuRequest->command == SBE_PSU_SET_FFDC_ADDRESS)
                {
                    SBE_TRACF(ERR_MRK, "sbe_psudd.C: checkResponse: "
                        "Set FFDC Address failed.");
                    PageManager::freePage(l_ffdcPkg);
                    iv_ffdcPackageBuffer.erase(i_target);
                }
                else
                {
                    SbeFFDCParser * l_ffdc_parser = new SbeFFDCParser();
                    l_ffdc_parser->parseFFDCData(l_ffdcPkg);
                    uint8_t l_pkgs = l_ffdc_parser->getTotalPackages();
                    uint8_t i;
                    for(i = 0; i < l_pkgs; i++)
                    {
                        ffdc_package l_package = {nullptr, 0, 0};
                        if(!l_ffdc_parser->getFFDCPackage(i, l_package))
                        {
                            continue;
                        }

                        errl->addFFDC( SBEIO_COMP_ID,
                                   l_package.ffdcPtr,
                                   l_package.size,
                                   0,
                                   SBEIO_UDT_PARAMETERS,
                                   false );

                         //If FFDC schema is known and a processing routine
                         //is defined then perform the processing.
                         //For scom PIB errors, addFruCallputs is invoked.
                         //Only processing known FFDC schemas protects us
                         //from trying to process FFDC formats we do not
                         //anticipate. For example, the SBE can send
                         //user and attribute FFDC information after the
                         //Scom Error FFDC. We do not want to process that
                         //type of data here.
                         FfdcParsedPackage::doDefaultProcessing(l_package,
                                                                i_target,
                                                                errl);
                    }
                    delete l_ffdc_parser;
                }
            }

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
            MAGIC_INST_GET_SBE_TRACES(
                  i_target->getAttr<TARGETING::ATTR_POSITION>(),
                  SBEIO_PSU_RESPONSE_ERROR);

            break;
        }

    }
    while (0);

    SBE_TRACD(EXIT_MRK "checkResponse");

    return errl;
}

/**
 * @brief poll for PSU to complete command
 */
errlHndl_t SbePsu::pollForPsuComplete(TARGETING::Target * i_target,
                                      const uint64_t i_timeout,
                                      psuCommand* i_pPsuRequest)
{
    errlHndl_t l_errl = NULL;
    SBE_TRACD(ENTER_MRK "pollForPsuComplete");
    uint64_t l_elapsed_time_ns = 0;

    do
    {
        //The handling of the interrupt will set the
        // iv_psuResponse variable with the incoming message data
        if (iv_responseReady)
        {
            break; // return with success
        }

        // time out if wait too long
        if (l_elapsed_time_ns > i_timeout )
        {
            l_errl = INTR::printInterruptInfo();

            // If there was an error dumping interrupt state info just commit
            // errorlog and continue with the failure path.
            if(l_errl)
            {
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                l_errl->collectTrace(SBEIO_COMP_NAME);
                errlCommit(l_errl, SBEIO_COMP_ID);
            }

            //read the response registers for FFDC
            uint64_t l_respRegs[4];
            ERRORLOG::ErrlUserDetailsLogRegister l_respRegsFFDC(i_target);
            uint64_t l_addr = PSU_HOST_SBE_MBOX4_REG;
            for (uint8_t i=0;i<4;i++)
            {
                l_errl = readScom(i_target,l_addr,&l_respRegs[i]);
                if (l_errl)
                {
                    l_respRegs[i] = 0;
                    delete l_errl;
                    l_errl = nullptr;
                }

                l_respRegsFFDC.addData(DEVICE_XSCOM_ADDRESS(l_addr));

                l_addr++;
            }
            psuResponse* l_resp = reinterpret_cast<psuResponse*>(l_respRegs);

            // Collect SBE traces in simics
            MAGIC_INST_GET_SBE_TRACES(i_target->getAttr<TARGETING::ATTR_POSITION>(),
                                      SBEIO_PSU_RESPONSE_TIMEOUT);

            if(!(l_resp->primaryStatus & SBE_PRI_FFDC_ERROR))
            {
                SBE_TRACF("Error: PSU Timeout and no FFDC present");
                /*@
                 * @errortype
                 * @moduleid    SBEIO_PSU
                 * @reasoncode  SBEIO_PSU_FFDC_MISSING
                 * @userdata1[00:15]    Primary Status in mbox4
                 * @userdata1[16:31]    Sequence Id in mbox4
                 * @userdata1[32:63]    Processor Target
                 * @userdata2   Failing Request
                 * @devdesc     Timeout waiting for PSU command to complete
                 * @custdesc    Firmware error communicating with boot device
                 */
                l_errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                SBEIO_PSU,
                                SBEIO_PSU_FFDC_MISSING,
                                TWO_UINT32_TO_UINT64(
                                  TWO_UINT16_TO_UINT32(
                                    l_resp->primaryStatus,
                                    l_resp->secondaryStatus),
                                  TARGETING::get_huid(i_target)),
                                i_pPsuRequest->mbxReg0);

                // log the failing proc as FFDC
                ErrlUserDetailsTarget(i_target).addToLog(l_errl);
                l_respRegsFFDC.addToLog(l_errl);
                l_errl->collectTrace(SBEIO_COMP_NAME);

                // Keep a copy of the plid so we can pass it to the retry_handler
                // so the error logs it creates will be linked
                uint32_t l_errPlid = l_errl->plid();

                // Commit error log now if this is a FSP system because
                // we will not return from retry handler
                if(INITSERVICE::spBaseServicesEnabled())
                {
                    l_errl->addHwCallout( i_target,
                                          HWAS::SRCI_PRIORITY_HIGH,
                                          HWAS::NO_DECONFIG,
                                          HWAS::GARD_NULL );
                    ERRORLOG::errlCommit( l_errl, SBEIO_COMP_ID );
                }
                //On open power systems we want to deconfigure the processor
                else
                {
                    l_errl->addHwCallout( i_target,
                                          HWAS::SRCI_PRIORITY_HIGH,
                                          HWAS::DELAYED_DECONFIG,
                                          HWAS::GARD_NULL );
                }

                if (!VFS::module_is_loaded("libfapi2.so"))
                {
                    // If the fapi library hasn't been loaded, we need to save
                    // the details of this error until it has, so the error can
                    // be logged.
                    SBE_TRACF("Timeout error saved until fapi is loaded.");
                    saveEarlyError(l_errPlid, i_target);
                }
                else
                {
                    // If the FFDC is empty, this error could be because the SBE
                    // isn't booted correctly. We need to check the state of the
                    // SBE.
                    // If we are on a FSP based system we expect this to result
                    // in a TI
                    // If we are on a BMC based system we expect to return from
                    // this fail
                    SbeRetryHandler l_SBEobj = SbeRetryHandler(
                     SbeRetryHandler::SBE_MODE_OF_OPERATION::INFORMATIONAL_ONLY,
                     l_errPlid);

                    l_SBEobj.main_sbe_handler(i_target);
                }
            }
            else
            {
                // If the FFDC is not empty, then this is correctly identified
                // as a PSU error, and isn't related to the SBE.
                SBE_TRACF("Error: Timeout waiting for PSU command");
                /*@
                 * @errortype
                 * @moduleid    SBEIO_PSU
                 * @reasoncode  SBEIO_PSU_RESPONSE_TIMEOUT
                 * @userdata1[00:15]    Primary Status in mbox4
                 * @userdata1[16:31]    Secondary Status
                 * @userdata1[32:63]    Processor Target
                 * @userdata2   Failing Request
                 * @devdesc     Timeout waiting for PSU command to complete
                 * @custdesc    Firmware error communicating with boot device
                 */
                l_errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                SBEIO_PSU,
                                SBEIO_PSU_RESPONSE_TIMEOUT,
                                TWO_UINT32_TO_UINT64(
                                  TWO_UINT16_TO_UINT32(
                                    l_resp->primaryStatus,
                                    l_resp->secondaryStatus),
                                  TARGETING::get_huid(i_target)),
                                i_pPsuRequest->mbxReg0);

                void * l_ffdcPkg = findFFDCBufferByTarget(i_target);
                if(l_ffdcPkg != NULL)
                {
                    SbeFFDCParser * l_ffdc_parser = new SbeFFDCParser();
                    l_ffdc_parser->parseFFDCData(l_ffdcPkg);
                    uint8_t l_pkgs = l_ffdc_parser->getTotalPackages();
                    for(uint8_t i=0; i < l_pkgs; i++)
                    {
                        l_errl->addFFDC( SBEIO_COMP_ID,
                                         l_ffdc_parser->getFFDCPackage(i),
                                         l_ffdc_parser->getPackageLength(i),
                                         0,
                                         SBEIO_UDT_PARAMETERS,
                                         false );
                    }
                    delete l_ffdc_parser;
                    l_ffdc_parser = nullptr;
                }

                l_errl->addHwCallout( i_target,
                                HWAS::SRCI_PRIORITY_HIGH,
                                HWAS::NO_DECONFIG,
                                HWAS::GARD_NULL );

                // log the failing proc as FFDC
                ErrlUserDetailsTarget(i_target).addToLog(l_errl);
                l_respRegsFFDC.addToLog(l_errl);
                l_errl->collectTrace(SBEIO_COMP_NAME);
            }

            break;
        }

        // try later
        nanosleep( 0, 10000 ); //sleep for 10us
        l_elapsed_time_ns += 10000;
    }
    while (1);

    SBE_TRACD(EXIT_MRK "pollForPsuComplete");

    return l_errl;
}

/**
 * @brief read Scom
 */
errlHndl_t SbePsu::readScom(TARGETING::Target * i_target,
                             uint64_t   i_addr,
                             uint64_t * o_pData,
                             bool       i_trace)
{
    errlHndl_t errl = NULL;

    size_t l_64bitSize = sizeof(uint64_t);
    errl = deviceOp(DeviceFW::READ,
                    i_target,
                    o_pData,
                    l_64bitSize,
                    DEVICE_SCOM_ADDRESS(i_addr));

    if (i_trace)
    {
        SBE_TRACD("  readScom addr=0x%08lx data=0x%016lx",
                         i_addr,*o_pData);
    }

    return errl;
}

/**
 * @brief write Scom
 */
errlHndl_t SbePsu::writeScom(TARGETING::Target * i_target,
                             uint64_t   i_addr,
                             uint64_t * i_pData)
{
    errlHndl_t errl = NULL;

    SBE_TRACD("  writeScom addr=0x%08lx data=0x%016lx",
              i_addr,*i_pData);
    size_t l_64bitSize = sizeof(uint64_t);
    errl = deviceOp(DeviceFW::WRITE,
                    i_target,
                    i_pData,
                    l_64bitSize,
                    DEVICE_SCOM_ADDRESS(i_addr));

    return errl;
}

/**
 * @brief allocates buffer and sets ffdc address for the proc
 */

errlHndl_t SbePsu::allocateFFDCBuffer(TARGETING::Target * i_target)
{
    static mutex_t l_alloMux = MUTEX_INITIALIZER;

    uint32_t l_bufSize = getSbeFFDCBufferSize();
    errlHndl_t errl = NULL;

    uint32_t l_huid = TARGETING::get_huid(i_target);

    // Check to see if the buffer has been allocated before allocating
    // and setting FFDC address
    mutex_lock(&l_alloMux);

    if(iv_ffdcPackageBuffer.find(i_target) == iv_ffdcPackageBuffer.end())
    {
        void * l_ffdcPtr = PageManager::allocatePage(ffdcPackageSize, true);
        memset(l_ffdcPtr, 0x00, l_bufSize);
        uint64_t l_phyAddr_ffdcPtr = mm_virt_to_phys(l_ffdcPtr);

        errl = sendSetFFDCAddr(l_bufSize,
                          0,
                          l_phyAddr_ffdcPtr,
                          0,
                          i_target);

        //Make the corresponding platform attribute match what we sent to SBE
        //Things will work without setting these attributes, just to reduce
        //confusion during debug in the future we will set them here.
        i_target->setAttr<TARGETING::ATTR_SBE_FFDC_ADDR>(l_phyAddr_ffdcPtr);
        i_target->setAttr<TARGETING::ATTR_SBE_COMM_ADDR>(0);

        if(errl)
        {
            PageManager::freePage(l_ffdcPtr);
            SBE_TRACF(ERR_MRK"Error setting FFDC address for "
                      "proc huid=0x%08lx", l_huid);
        }
        else
        {
            iv_ffdcPackageBuffer.insert(std::pair<TARGETING::Target *, void *>
                          (i_target, l_ffdcPtr));
            SBE_TRACD("Allocated FFDC buffer for proc huid=0x%08lx", l_huid);
        }
    }

    mutex_unlock(&l_alloMux);
    return errl;
}

/**
 * @brief find allocated FFDC buffer by the target
 */
void * SbePsu::findFFDCBufferByTarget(TARGETING::Target * i_target)
{
    void * ffdcBuffer = NULL;

    std::map<TARGETING::Target *, void *>::iterator l_iter =
        iv_ffdcPackageBuffer.find(i_target);

    if(l_iter != iv_ffdcPackageBuffer.end())
    {
         ffdcBuffer = l_iter->second;
    }

    return ffdcBuffer;
}

} //end of namespace SBEIO
