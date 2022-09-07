/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/common/sbe_psudd_common.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
 * @file sbe_psudd_common.C
 * @brief Shared code between IPL and Runtime SBE PSU Drivers
 */

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
#include <sbeio/sbeioif.H>
#include <errl/errludlogregister.H>
#include <sbeio/sbe_retry_handler.H>
#include <initservice/initserviceif.H>
#include <intr/interrupt.H>
#include <errno.h>
#include <sys/time.h>
#include <sys/sync.h>
#include <errl/errludprintk.H>
#include <util/misc.H>
#include <sbe/sbeif.H>
#include <isteps/istep_reasoncodes.H>
#include <console/consoleif.H>

#ifndef __HOSTBOOT_RUNTIME
#include <vfs/vfs.H> // module_is_loaded
#endif


extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"psudd: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"psudd: " printf_string,##args)
#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio,"psudd: " printf_string,##args)


using namespace ERRORLOG;

namespace SBEIO
{

SbePsu & SbePsu::getTheInstance()
{
    return Singleton<SbePsu>::instance();
}

/**
 * @brief  Destructor
 **/
void SbePsu::commonDestructor( void )
{
    //nothing to do yet
}

const SbePsu::unsupported_command_error_severity
   SbePsu::COMMAND_SUPPORT_OPTIONAL { ERRORLOG::ERRL_SEV_UNKNOWN };

errlHndl_t SbePsu::performPsuChipOp(TARGETING::Target *    i_target,
                                    psuCommand     *       i_pPsuRequest,
                                    psuResponse    *       o_pPsuResponse,
                                    const uint64_t         i_timeout,
                                    uint8_t                i_reqMsgs,
                                    uint8_t                i_rspMsgs,
                                    const unsupported_command_error_severity i_supportErrSev,
                                    bool* const            o_unsupportedOp)

{
    errlHndl_t errl = nullptr;
    errlHndl_t initialErrl = nullptr;

    static mutex_t l_psuOpMux = MUTEX_INITIALIZER;
    bool l_needUnlock = false;
    bool l_retryCmd = false;

    SBE_TRACD(ENTER_MRK "performPsuChipOp");

    o_unsupportedOp && (*o_unsupportedOp = false);

    // Retry MPIPL SBE response failure
    TARGETING::Target* l_sys = TARGETING::UTIL::assertGetToplevelTarget();
    if (l_sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
    {
        l_retryCmd = true;
    }

    do
    {
        //Only perform new chip-ops if we aren't shutting down
        if (iv_shutdownInProgress)
        {
            SBE_TRACF(ERR_MRK"performPsuChipOp::"
                      "Skipping operation because of Shutdown operation");
            break;
        }

        //Do not send a command if we had an early fatal error of some kind
        if( earlyError() )
        {
            SBE_TRACF(ERR_MRK"performPsuChipOp> Skipping operation because of early failure : eid=%.8X",
                      iv_earlyErrorEid);

            /*@
             * @moduleid        SBEIO_PSU
             * @reasoncode      SBEIO_EARLY_ERROR
             * @userdata1[00:31]       PSU command class
             * @userdata1[32:63]       PSU command
             * @devdesc         Blocking attempt to send a PSU chipop due to a
             *                  previous fatal error.
             * @custdesc        Firmware error
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_PSU,
                                 SBEIO_EARLY_ERROR,
                                 TWO_UINT32_TO_UINT64(
                                     i_pPsuRequest->commandClass,
                                     i_pPsuRequest->command),
                                 TWO_UINT32_TO_UINT64(
                                     TARGETING::get_huid(i_target),
                                     iv_earlyErrorEid));
            errl->addProcedureCallout( HWAS::EPUB_PRC_SUE_PREVERROR,
                                       HWAS::SRCI_PRIORITY_HIGH );
            break;
        }

        // If not an SBE_PSU_SET_FFDC_ADDRESS command,
        // we allocate an FFDC buffer and set FFDC adress
        if(i_pPsuRequest->command != SBE_PSU_SET_FFDC_ADDRESS)
        {
            errl = allocateFFDCBuffer(i_target);
            if (errl)
            {
                SBE_TRACF(ERR_MRK"performPsuChipOp::"
                          " setFFDC address returned an error");
                break;
            }
        }

        //Serialize access to PSU
        mutex_lock(&l_psuOpMux);
        l_needUnlock = true;

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

        // If retrying the command is an option, then just
        // return an error log without any actions
        bool l_justErrl = l_retryCmd;

        // read PSU response and check results
        errl = checkResponse(i_target,
                             i_pPsuRequest,
                             iv_psuResponse,
                             i_timeout,
                             i_rspMsgs,
                             l_justErrl);
        if (errl)
        {
            SBE_TRACF(ERR_MRK"performPsuChipOp::checkResponse returned an error");
            if (l_retryCmd && (initialErrl == nullptr))
            {
#ifndef __HOSTBOOT_RUNTIME
                if (VFS::module_is_loaded("libfapi2.so"))
                {
                    SBE_TRACF("performPsuChipOp:: Attempting an HRESET to recover from error");

                    SbeRetryHandler l_SBEobj = SbeRetryHandler(
                        i_target,
                        SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                        SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                        errl->plid(),
                        NOT_INITIAL_POWERON);

                    l_SBEobj.main_sbe_handler();

                    initialErrl = errl;
                    errl = nullptr; // allows the continue to work
                    initialErrl->collectTrace(SBEIO_COMP_NAME);

                    l_retryCmd = false;
                    if( l_needUnlock )
                    {
                        mutex_unlock(&l_psuOpMux);
                        l_needUnlock = false;
                    }
                    SBE_TRACF("performPsuChipOp:: now retry the failed command (0x%X)",
                        i_pPsuRequest->command);
                    continue;
                }
#endif
            }
            break;  // return with error
        }

        if (   SBE_PRI_INVALID_COMMAND       == o_pPsuResponse->primaryStatus
           && (SBE_SEC_COMMAND_NOT_SUPPORTED == o_pPsuResponse->secondaryStatus
            || SBE_SEC_COMMAND_CLASS_NOT_SUPPORTED == o_pPsuResponse->secondaryStatus))
        {
            o_unsupportedOp && (*o_unsupportedOp = true);

            SBE_TRACF("The SBE does not support command class %d/command %d on target 0x%08x",
                      i_pPsuRequest->commandClass,
                      i_pPsuRequest->command,
                      get_huid(i_target));

#ifndef __HOSTBOOT_RUNTIME
            // If support for an operation on the master processor's SBE
            // is not optional, then update the SBE now and reboot.
            if (i_supportErrSev.error_sev >= ERRL_SEV_UNRECOVERABLE
                && i_target->getAttr<ATTR_PROC_MASTER_TYPE>() == PROC_MASTER_TYPE_ACTING_MASTER)
            {
                // Some callers may ignore errors if they see that the
                // operation was unsupported, but SBE update error are
                // not ignorable
                o_unsupportedOp && (*o_unsupportedOp = false);

                // Update the SBE and reboot
                errl = forceSbeUpdate(i_target);
                if( errl )
                {
                    break;
                }
                // the call above should never return without an error,
                // if it does, keep going so that we log an error and
                // do what we need to do
            }
#endif //#ifndef __HOSTBOOT_RUNTIME

            // ERRL_SEV_UNKNOWN (passed via the COMMAND_SUPPORT_OPTIONAL
            // parameter) is our marker to say we should create a predictive error
            // and possibly log it later.
            const bool command_support_optional = i_supportErrSev.error_sev == ERRL_SEV_UNKNOWN;

            const auto unsupported_cmd_error_sev = (command_support_optional
                                                    ? ERRL_SEV_PREDICTIVE
                                                    : i_supportErrSev.error_sev);

            /*@
             * @moduleid        SBEIO_PSU
             * @reasoncode      SBEIO_COMMAND_NOT_SUPPORTED
             * @userdata1       PSU command class
             * @userdata2       PSU command
             * @devdesc         Current SBE version does not support the attempted PSU command
             * @custdesc        SBE version too old
             */
            errl = new ErrlEntry(unsupported_cmd_error_sev,
                                 SBEIO_PSU,
                                 SBEIO_COMMAND_NOT_SUPPORTED,
                                 i_pPsuRequest->commandClass,
                                 i_pPsuRequest->command,
                                 ErrlEntry::ADD_SW_CALLOUT);

            // For subsidiary processors, either the error happens
            // before the SMP fabric is up, in which case we can't fix
            // the problem by updating the SBE (because SBE SEEPROM
            // accesses are blocked over FSI for being insecure), or
            // else the error happens after the SMP fabric is up, in
            // which case we have already updated the SBE (there are no
            // isteps between fabric setup and the SBE update istep for
            // subsidiary processors) and there's some serious problem
            // on the latest version of the SBE that we possess. Either
            // way, we have to deconfigure the processor.
            if (i_supportErrSev.error_sev >= ERRL_SEV_UNRECOVERABLE
                && i_target->getAttr<ATTR_PROC_MASTER_TYPE>() != PROC_MASTER_TYPE_ACTING_MASTER)
            {
                SBE_TRACF(ERR_MRK"performPsuChipOp: Deconfiguring subsidiary processor 0x%08x "
                          " because of an unsupported SBE PSU operation on a subsidiary processor",
                          get_huid(i_target));

                errl->addHwCallout(i_target,
                                   HWAS::SRCI_PRIORITY_MED,
                                   HWAS::DELAYED_DECONFIG,
                                   HWAS::GARD_NULL);
            }

            errl->addProcedureCallout(HWAS::EPUB_PRC_SBE_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);

            if (command_support_optional)
            {
                errl->collectTrace(SBEIO_COMP_NAME);

                const auto lock = scoped_mutex_lock(iv_unsupportedCmdErrorsMutex);

                iv_unsupportedCmdErrors.push_back(errl);
                errl = nullptr;
            }
        }
        // made it to the end without an error
        break; // exit do-while loop
    }
    while (errl == nullptr); // necessary for continue to work

    if( errl )
    {
        errl->collectTrace(SBEIO_COMP_NAME);
    }

    if( initialErrl && errl)
    {
        // commit last error and return initial one
        errl->plid(initialErrl->plid());
        errlCommit(errl, SBEIO_COMP_ID);
        errl = initialErrl;
        initialErrl = nullptr;
    }
    else if( initialErrl)
    {
        SBE_TRACF("performPsuChipOp: successfully recovered from RC %X",
            ERRL_GETRC_SAFE(initialErrl));
        // set recovered error
        initialErrl->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
        errlCommit(initialErrl, SBEIO_COMP_ID);
    }


    MAGIC_INST_SET_LOG_LEVEL(PIB_PSU, LOG_LEVEL_OFF);
    MAGIC_INST_SET_LOG_LEVEL(SBE_INT_BO, LOG_LEVEL_OFF);
    MAGIC_INST_TOGGLE_OUTPUT(DISABLE_OUTPUT);

    iv_psuResponse = nullptr;
    if( l_needUnlock )
    {
        mutex_unlock(&l_psuOpMux);
    }

    SBE_TRACD(EXIT_MRK "performPsuChipOp");

    return errl;
}

/**
 * @brief  Commit any "unsupported command" errors that have accumulated
 *         up to this point.
 */
void SbePsu::commitUnsupportedCmdErrors()
{
    SBE_TRACF(ENTER_MRK"commitUnsupportedCmdErrors");

    const auto lock = scoped_mutex_lock(iv_unsupportedCmdErrorsMutex);

    for (auto& errl : iv_unsupportedCmdErrors)
    {
        SBE_TRACF(INFO_MRK"commitUnsupportedCmdErrors: Committing error PLID=0x%08x (RC=0x%08x) "
                  "caused by an unsupported SBE PSU Chip Operation which happened earlier in the IPL",
                  ERRL_GETPLID_SAFE(errl),
                  ERRL_GETRC_SAFE(errl));

        errlCommit(errl, SBEIO_COMP_ID);
    }

    iv_unsupportedCmdErrors.clear();

    SBE_TRACF(EXIT_MRK"commitUnsupportedCmdErrors");
}

/**
 * @brief record info from an "early" error so it can be reported later
 */
void SbePsu::saveEarlyError(uint32_t i_eid, TARGETING::TargetHandle_t i_target)
{
    SBE_TRACD(ENTER_MRK "saveEarlyError");

    iv_earlyErrorOccurred = true;
    iv_earlyErrorEid     = i_eid;
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
        SBE_TRACF(ERR_MRK"processEarlyError: early error occurred, "
                  "plid=0x%08X, target huid=0x%08X",
                  iv_earlyErrorEid, TARGETING::get_huid(iv_earlyErrorTarget));
        SbeRetryHandler l_SBEobj = SbeRetryHandler(
            iv_earlyErrorTarget,
            SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
            SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
            iv_earlyErrorEid,
            NOT_INITIAL_POWERON);

        l_SBEobj.main_sbe_handler();

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

#ifdef __HOSTBOOT_RUNTIME
        // Set all the interrupt mask bits at runtime
        // else PHYP may see the interrupt and clear the register
        l_data = HOST_MASK_BITS;
        errl = writeScom(i_target,PSU_HOST_DOORBELL_REG_OR,&l_data);
        if (errl) break;
#endif

        //notify PSU command is ready
        l_data = SBE_DOORBELL;
        errl = writeScom(i_target,PSU_SBE_DOORBELL_REG_OR,&l_data);
        if (errl) break;

    }
    while (0);

    SBE_TRACD(EXIT_MRK "writeRequest");

    return errl;
}


errlHndl_t SbePsu::handleMessage(TARGETING::Target* i_proc)
{
    errlHndl_t errl = nullptr;
    SBE_TRACD(ENTER_MRK "SbePsu::handleMessage");
    bool l_responseAvailable = false;
    bool l_simicsRunning = Util::isSimicsRunning();

    do
    {
        //Occasionally, there is a PSU interrupt that is not associated
        // with a PSU response. The HOST_DOORBELL reg will indicate if
        // there is a response available. If there is, it will be read.
        // If not the interrupt condition simply needs to be cleared.
        uint64_t l_doorbellVal = 0x0;
        errl = readScom(i_proc,PSU_HOST_DOORBELL_REG_RW,&l_doorbellVal);
        if (errl)
        {
            break;
        }

        if ( l_simicsRunning &&
             HOST_RESPONSE_WAITING != (l_doorbellVal & HOST_RESPONSE_WAITING) )
        {
            // wait a second and try again
            nanosleep(1,0);

            //read the door bell again to see if the simics model caught up
            errl = readScom(i_proc,PSU_HOST_DOORBELL_REG_RW,&l_doorbellVal);
            if (errl)
            {
                SBE_TRACF("SbePsu::handleMessage: Could not read PSU_HOST_DOORBELL_REG_RW (%X) on %.8X",
                          PSU_HOST_DOORBELL_REG_RW,
                          TARGETING::get_huid(i_proc));
                break;
            }

        }

        if (l_doorbellVal & HOST_RESPONSE_WAITING)
        {
            //In this case the doorbell reg indicated a response is
            //available
            l_responseAvailable = true;
            //read the response registers
            uint64_t * l_pMessage =
                        reinterpret_cast<uint64_t *>(iv_psuResponse);

            //Make sure we are expecting a response, if not we need to use
            // a local buffer for these reads
            bool l_noResponse = false;
            uint64_t l_localMessage[sizeof(psuResponse)/sizeof(uint64_t)];
            if( iv_psuResponse == nullptr )
            {
                SBE_TRACF("SbePsu::handleMessage: iv_psuResponse is null for %.8X",
                          TARGETING::get_huid(i_proc));
                l_noResponse = true;
                l_pMessage = l_localMessage;
            }

            uint64_t   l_addr     = PSU_HOST_SBE_MBOX4_REG;
            for (uint8_t i=0; i<(sizeof(psuResponse)/sizeof(uint64_t)); i++)
            {
                errl = readScom(i_proc,l_addr,l_pMessage);
                if (errl)
                {
                    SBE_TRACF("SbePsu::handleMessage: Could not read PSU_HOST_SBE_MBOX%d_REG (%X) on %.8X",
                              i+4,
                              l_addr,
                              TARGETING::get_huid(i_proc));
                    break;
                }

                // Nobody is waiting for this data, print out what we saw
                if( l_noResponse )
                {
                    SBE_TRACF("Reg %X = %.16X", l_addr, *l_pMessage );
                }

                l_addr++;
                l_pMessage++;
            }

            if (errl)
            { break; }

            // Notify PSU response has been read
            uint64_t l_data = HOST_CLEAR_RESPONSE_WAITING;
#ifdef __HOSTBOOT_RUNTIME
            // Also clear all the mask bits
            l_data &= HOST_CLEAR_MASK_BITS;
#endif
            errl = writeScom(i_proc,PSU_HOST_DOORBELL_REG_AND,&l_data);
            if (errl)
            { break; }
        }
#ifndef __HOSTBOOT_RUNTIME
        // At runtime we don't use interrupts, but otherwise this is a bug
        else if(l_simicsRunning)
        {
            SBE_TRACF(ENTER_MRK "SbePsu::handleMessage interrupt found but no Doorbell is set 0x%llx", l_doorbellVal);
            // If we are in simics we want to break out here
            MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
        }
#endif //#ifndef __HOSTBOOT_RUNTIME

    } while (0);

    // Only indicate a response is ready if we found legitimate
    //   PSU message data.
    if (l_responseAvailable)
    {
        iv_responseReady = true;
    }

    SBE_TRACD(EXIT_MRK "SbePsu::handleMessage");

    return errl;
}

/**
 * @brief Read PSU response messages
 */
errlHndl_t SbePsu::checkResponse(TARGETING::Target  * i_target,
                                 psuCommand         * i_pPsuRequest,
                                 psuResponse        * o_pPsuResponse,
                                 const uint64_t       i_timeout,
                                 uint8_t              i_rspMsgs,
                                 bool                 i_justReturnError)
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "checkResponse");

    do
    {
        //wait for request to be completed
        errl = pollForPsuComplete(i_target,i_timeout,i_pPsuRequest, i_justReturnError);
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
                    freePage(l_ffdcPkg);
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
                                      psuCommand* i_pPsuRequest,
                                      bool i_justErrl)
{
    errlHndl_t l_errl = nullptr;
    SBE_TRACD(ENTER_MRK "pollForPsuComplete");
    uint64_t l_elapsed_time_ns = 0;

    do
    {
#ifdef __HOSTBOOT_RUNTIME
        // No interrupt handling at runtime so need to check
        //  the regs manually
        l_errl = handleMessage(i_target);
        if(l_errl)
        {
            SBE_TRACF("Error from handleMessage(%.8X)",
                      TARGETING::get_huid(i_target));
            break;
        }
#endif //#ifdef __HOSTBOOT_RUNTIME

        //The handling of the interrupt will set the
        // iv_psuResponse variable with the incoming message data
        if (iv_responseReady)
        {
            break; // return with success
        }

        // time out if wait too long
        if (l_elapsed_time_ns > i_timeout )
        {
#ifndef __HOSTBOOT_RUNTIME
            l_errl = INTR::printInterruptInfo();

            // If there was an error dumping interrupt state info just commit
            // errorlog and continue with the failure path.
            if(l_errl)
            {
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                l_errl->collectTrace(SBEIO_COMP_NAME);
                errlCommit(l_errl, SBEIO_COMP_ID);
            }
#endif //#ifndef __HOSTBOOT_RUNTIME

            //read all the MBOX registers for FFDC
            uint64_t l_mboxRegs[8];
            ERRORLOG::ErrlUserDetailsLogRegister l_regsFFDC(i_target);
            uint64_t l_addr = PSU_HOST_SBE_MBOX0_REG;
            for (uint8_t i=0;i<8;i++)
            {
                l_errl = readScom(i_target,l_addr,&l_mboxRegs[i]);
                if (l_errl)
                {
                    l_mboxRegs[i] = 0;
                    delete l_errl;
                    l_errl = nullptr;
                }

                l_regsFFDC.addDataBuffer(&l_mboxRegs[i], 8,
                                         DEVICE_SCOM_ADDRESS(l_addr));

                l_addr++;
            }

            // Add the SBE doorbell reg
            l_regsFFDC.addData(DEVICE_SCOM_ADDRESS(PSU_SBE_DOORBELL_REG_RW));

            // Add the host doorbell reg
            l_regsFFDC.addData(DEVICE_SCOM_ADDRESS(PSU_HOST_DOORBELL_REG_RW));

            // Add the TP LOCAL FIR (includes SBE vital attentions)
            l_regsFFDC.addData(DEVICE_SCOM_ADDRESS(0x01040100));

            // Collect SBE traces in simics
            MAGIC_INST_GET_SBE_TRACES(i_target->getAttr<TARGETING::ATTR_POSITION>(),
                                      SBEIO_PSU_RESPONSE_TIMEOUT);

            // Response regs start at MBOX4, check for an error
            psuResponse* l_resp = reinterpret_cast<psuResponse*>(&(l_mboxRegs[4]));
            if(!(l_resp->primaryStatus & SBE_PRI_FFDC_ERROR))
            {
                SBE_TRACF("Error: PSU Timeout and no FFDC present");
                /*@
                 * @moduleid    SBEIO_PSU
                 * @reasoncode  SBEIO_PSU_RESPONSE_SBE_NOT_RESPONDING
                 * @userdata1[00:15]    Primary Status in mbox4
                 * @userdata1[16:31]    Sequence Id in mbox4
                 * @userdata1[32:63]    Processor Target
                 * @userdata2   Failing Request
                 * @devdesc     Timeout waiting for PSU command to complete,
                 *              SBE not responding
                 * @custdesc    Firmware error communicating with boot device
                 */
                l_errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                SBEIO_PSU,
                                SBEIO_PSU_RESPONSE_SBE_NOT_RESPONDING,
                                TWO_UINT32_TO_UINT64(
                                  TWO_UINT16_TO_UINT32(
                                    l_resp->primaryStatus,
                                    l_resp->secondaryStatus),
                                  TARGETING::get_huid(i_target)),
                                i_pPsuRequest->mbxReg0);

                // log the failing proc as FFDC
                ErrlUserDetailsTarget(i_target).addToLog(l_errl);
                l_regsFFDC.addToLog(l_errl);
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
                //On open power systems we want to deconfigure the processor (if not MPIPL state)
                else
                {
                    TARGETING::Target* l_sys = TARGETING::UTIL::assertGetToplevelTarget();
                    if (l_sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
                    {
                        SBE_TRACF("MPIPL mode, so no deconfig of processor");
                        l_errl->addHwCallout( i_target,
                                              HWAS::SRCI_PRIORITY_HIGH,
                                              HWAS::NO_DECONFIG,
                                              HWAS::GARD_NULL );

                    }
                    else
                    {
                        l_errl->addHwCallout( i_target,
                                              HWAS::SRCI_PRIORITY_HIGH,
                                              HWAS::DELAYED_DECONFIG,
                                              HWAS::GARD_NULL );
                    }
                }

#ifndef __HOSTBOOT_RUNTIME
                if (!VFS::module_is_loaded("libfapi2.so"))
                {
                    // If the fapi library hasn't been loaded, we need to save
                    // the details of this error until it has, so the error can
                    // be logged.
                    SBE_TRACF("Timeout error saved until fapi is loaded.");
                    saveEarlyError(l_errPlid, i_target);
                }
                else if (i_justErrl)
                {
                    // don't do any recovery here, just return the error
                    SBE_TRACF("pollForPsuComplete - just returning error PLID %X, RC %X",
                        ERRL_GETPLID_SAFE(l_errl), ERRL_GETRC_SAFE(l_errl));
                }
                else
#endif //__HOSTBOOT_RUNTIME
                {
                    // If the FFDC is empty, this error could be because the SBE
                    // isn't booted correctly. We need to check the state of the
                    // SBE.
                    // If we are on a FSP based system we expect this to result
                    // in a TI
                    // If we are on a BMC based system we expect to return from
                    // this fail
                    SbeRetryHandler l_SBEobj = SbeRetryHandler(
                        i_target,
                        SbeRetryHandler::SBE_MODE_OF_OPERATION::INFORMATIONAL_ONLY,
                        SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                        l_errPlid,
                        NOT_INITIAL_POWERON);

                    l_SBEobj.main_sbe_handler();
                }
            }
            else
            {
                // If the FFDC is not empty, then this is correctly identified
                // as a PSU error, and isn't related to the SBE.
                SBE_TRACF("Error: Timeout waiting for PSU command on %.8X",
                          TARGETING::get_huid(i_target));
                /*@
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
                l_regsFFDC.addToLog(l_errl);
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
