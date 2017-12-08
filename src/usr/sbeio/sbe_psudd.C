/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psudd.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
#include <initservice/initserviceif.H> //@todo-RTC:149454-Remove
#include <sbeio/sbe_ffdc_package_parser.H>
#include <sbeio/sbe_psudd.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <arch/ppc.H>
#include <kernel/pagemgr.H>
#include <sbeio/sbeioif.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <p9_extract_sbe_rc.H>
#include <errl/errludlogregister.H>
#include <sbeio/sbe_retry_handler.H>

trace_desc_t* g_trac_sbeio;
TRAC_INIT(&g_trac_sbeio, SBEIO_COMP_NAME, 6*KILOBYTE, TRACE::BUFFER_SLOW);

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
 * @brief  Constructor
 **/
SbePsu::SbePsu()
{
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

/**
 * @brief perform SBE PSU chip-op
 *
 * @param[in]  i_target       Proc target to use for PSU Request
 * @param[in]  i_pPsuRequest  Pointer to PSU request commands
 * @param[out] o_pPsuResponse Pointer to PSU response
 * @param[in]  i_timeout      Time out for response
 * @param[in]  i_reqMsgs      4 bit mask telling which regs to write
 * @param[in]  i_rspMsgs      4 bit mask telling which regs to read
 */
errlHndl_t SbePsu::performPsuChipOp(TARGETING::Target * i_target,
                                    psuCommand     * i_pPsuRequest,
                                    psuResponse    * o_pPsuResponse,
                                    const uint64_t   i_timeout,
                                    uint8_t          i_reqMsgs,
                                    uint8_t          i_rspMsgs)

{
    errlHndl_t errl = NULL;
    static mutex_t l_psuOpMux = MUTEX_INITIALIZER;

    SBE_TRACD(ENTER_MRK "performPsuChipOp");

    // If not a SBE_PSU_SET_FFDC_ADDRESS command, we allocate an FFDC buffer
    // and set FFDC adress
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

    // Check that target is not NULL
    assert(i_target != nullptr,"performPsuChipOp: proc target is NULL");

    do
    {
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
        errl = readResponse(i_target,
                             i_pPsuRequest,
                             o_pPsuResponse,
                             i_timeout,
                             i_rspMsgs);
        if (errl){
            SBE_TRACF(ERR_MRK"performPsuChipOp::"
                    " readResponse returned an error");
            break;  // return with error
        }
    }
    while (0);

    mutex_unlock(&l_psuOpMux);

    if( errl && (SBEIO_PSU == errl->moduleId())
        // For this special case pass back errl without commiting or
        // collecting FFDC/shutting down
        && (SBE_PSU_SET_UNSECURE_MEMORY_REGION_CMD != i_pPsuRequest->command)
      )
    {
        SBE_TRACF( "Forcing shutdown for FSP to collect FFDC" );

        //commit the original error after pulling some data out
        uint32_t orig_plid = errl->plid();
        uint32_t orig_rc = errl->reasonCode();
        uint32_t orig_mod = errl->moduleId();
        ERRORLOG::errlCommit( errl, SBEIO_COMP_ID );
        /*@
         * @errortype
         * @moduleid     SBEIO_PSU
         * @reasoncode   SBEIO_HWSV_COLLECT_SBE_RC
         * @userdata1    PLID of original error log
         * @userdata2[00:31]    Original RC
         * @userdata2[32:63]    Original Module Id
         *
         * @devdesc      SBE error, force HWSV to collect FFDC
         * @custdesc     Firmware error communicating with boot device
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             SBEIO_PSU,
                             SBEIO_HWSV_COLLECT_SBE_RC,
                             orig_plid,
                             TWO_UINT32_TO_UINT64(orig_rc,orig_mod));
        MAGIC_INST_GET_SBE_TRACES(
              i_target->getAttr<TARGETING::ATTR_POSITION>(),
              SBEIO_HWSV_COLLECT_SBE_RC);
        INITSERVICE::doShutdownWithError( SBEIO_HWSV_COLLECT_SBE_RC,
                                          TARGETING::get_huid(i_target) );
    }

    SBE_TRACD(EXIT_MRK "performPsuChipOp");

    return errl;
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
        SBE_TRACF("Sending Req = %.16X %.16X %.16X %.16X",
                  i_pPsuRequest->mbxReg0,
                  i_pPsuRequest->mbxReg1,
                  i_pPsuRequest->mbxReg2,
                  i_pPsuRequest->mbxReg3);

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

/**
 * @brief Read PSU response messages
 */
errlHndl_t SbePsu::readResponse(TARGETING::Target  * i_target,
                                psuCommand         * i_pPsuRequest,
                                psuResponse        * o_pPsuResponse,
                                const uint64_t       i_timeout,
                                uint8_t              i_rspMsgs)
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "readResponse");

    do
    {
        //wait for request to be completed
        errl = pollForPsuComplete(i_target,i_timeout,i_pPsuRequest);
        if (errl) break;  // return with error

        //read the response registers
        uint64_t * l_pMessage = (uint64_t *)o_pPsuResponse;
        uint64_t   l_addr     = PSU_HOST_SBE_MBOX4_REG;
        for (uint8_t i=0;i<4;i++)
        {
            errl = readScom(i_target,l_addr,l_pMessage);
            if (errl) break;
            l_addr++;
            l_pMessage++;
        }
        if (errl) break;

        //notify PSU response has been read
        uint64_t l_data = HOST_CLEAR_RESPONSE_WAITING;
        errl = writeScom(i_target,PSU_HOST_DOORBELL_REG_AND,&l_data);
        if (errl) break;


        //If the command is not supported, then print a statement and break out
        if(o_pPsuResponse->primaryStatus == SBE_PRI_INVALID_COMMAND &&
           o_pPsuResponse->secondaryStatus == SBE_SEC_COMMAND_NOT_SUPPORTED)
        {
            SBE_TRACF("sbe_psudd.C :: readResponse: COMMAND NOT SUPPORTED "
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

            SBE_TRACF(ERR_MRK "sbe_psudd.C :: readResponse: "
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
                    SBE_TRACF(ERR_MRK, "sbe_psudd.C: readResponse: "
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

    SBE_TRACD(EXIT_MRK "readResponse");

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
    uint64_t l_data = 0;
    bool     l_trace = true; //initialize so first call is traced

    do
    {
        // read response doorbell to see if ready
        l_errl = readScom(i_target,PSU_HOST_DOORBELL_REG_RW,&l_data,l_trace);
        if (l_errl) break; // return with error

        // check if response is now ready to be read
        if (l_data & HOST_RESPONSE_WAITING)
        {
            break; // return with success
        }

        // time out if wait too long
        if (l_elapsed_time_ns > i_timeout )
        {
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

            if(!(l_resp->primaryStatus & SBE_PRI_FFDC_ERROR))
            {
                // Create an informational error

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

                // If the FFDC is empty, we need to check the state of the SBE
                // and then, handle the SBE value, and potentionally try
                // to restart the SBE
                SbeRetryHandler l_SBEobj = SbeRetryHandler(
                            SbeRetryHandler::SBE_MODE_OF_OPERATION::
                            INFORMATIONAL_ONLY);

                l_SBEobj.main_sbe_handler(i_target);

                if(l_SBEobj.getPLID() != NULL)
                {
                    // If there is not an unrecovered error, we want to tie
                    // the error from the sbe retry handler to this error.
                    l_errl->plid(l_SBEobj.getPLID());
                    l_errl->setSev(ERRL_SEV_UNRECOVERABLE);
                }

                // log the failing proc as FFDC
                ErrlUserDetailsTarget(i_target).addToLog(l_errl);
                l_respRegsFFDC.addToLog(l_errl);
                l_errl->collectTrace(SBEIO_COMP_NAME);
            }

            MAGIC_INST_GET_SBE_TRACES(
                  i_target->getAttr<TARGETING::ATTR_POSITION>(),
                  SBEIO_PSU_RESPONSE_TIMEOUT);

            break;
        }

        // try later
        task_yield();
        l_elapsed_time_ns += 100;

        // There will be many polls to check for the complete. If there
        // is a problem, then there will be hundreds before timing out
        // and giving up. Having one trace entry showing the poll request
        // parameters is useful. Hundreds of identical entries is not. Hundreds
        // with a non-continuous trace overruns the initial interaction.
        l_trace = false; //only trace once to avoid flooding the trace
    }
    while (1);

    task_yield(); //let INTR in

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

        errl = sendSetFFDCAddr(l_bufSize,
                          0,
                          mm_virt_to_phys(l_ffdcPtr),
                          0,
                          i_target);

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
