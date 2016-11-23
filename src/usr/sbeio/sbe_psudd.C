/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psudd.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
#include <targeting/common/targetservice.H>
#include <errl/errlreasoncodes.H>
#include <sbeio/sbeioreasoncodes.H>
#include <initservice/initserviceif.H> //@todo-RTC:149454-Remove
#include <sbeio/sbe_psudd.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <arch/ppc.H>
#include <kernel/pagemgr.H>

trace_desc_t* g_trac_sbeio;
TRAC_INIT(&g_trac_sbeio, SBEIO_COMP_NAME, 6*KILOBYTE, TRACE::BUFFER_SLOW);

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"psudd: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"psudd: " printf_string,##args)

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
    iv_ffdcPackageBuffer = PageManager::allocatePage(ffdcPackageSize, true);
    initFFDCPackageBuffer();

    /*
    * TODO RTC 164405
    *
    * call performPsuChipOp to tell SBE where to write when SBE is ready
    *
    * psuCommand   l_psuCommand(
    *         SBE_REQUIRE_RESPONSE,
    *         SBE_PSU_GENERIC_MESSAGE,
    *         SBE_CMD_CONTROL_SYSTEM_CONFIG);
    *
    * psuResponse  l_psuResponse;
    *
    * // Create FFDCPackage struct in psuCommand union
    * uint64_t cd4_FFDCPackage_MbxReg2reserved = &iv_ffdcPackageBuffer;
    *
    * performPsuChipOp(&l_psuCommand,
    *        &l_psuResponse,
    *        MAX_PSU_SHORT_TIMEOUT_NS,
    *        SBE_SYSTEM_CONFIG_REQ_USED_REGS,
    *        SBE_SYSTEM_CONFIG_RSP_USED_REGS);
    *
    */
}

/**
 * @brief  Destructor
 **/
SbePsu::~SbePsu()
{
    if(iv_ffdcPackageBuffer != NULL)
    {
        PageManager::freePage(iv_ffdcPackageBuffer);
    }
}

/**
 * @brief perform SBE PSU chip-op
 *
 * @param[in]  i_pPsuRequest  Pointer to PSU request commands
 * @param[out] o_pPsuResponse Pointer to PSU response
 * @param[in]  i_timeout      Time out for response
 * @param[in]  i_reqMsgs      4 bit mask telling which regs to write
 * @param[in]  i_rspMsgs      4 bit mask telling which regs to read
 */
errlHndl_t SbePsu::performPsuChipOp(psuCommand     * i_pPsuRequest,
                            psuResponse    * o_pPsuResponse,
                            const uint64_t   i_timeout,
                            uint8_t          i_reqMsgs,
                            uint8_t          i_rspMsgs)

{
    errlHndl_t errl = NULL;
    TARGETING::Target * l_target = NULL;
    static mutex_t l_psuOpMux = MUTEX_INITIALIZER;

    SBE_TRACD(ENTER_MRK "performPsuChipOp");

    //Serialize access to PSU
    mutex_lock(&l_psuOpMux);

    //Use master proc for SBE PSU access
    (void)TARGETING::targetService().masterProcChipTargetHandle(l_target);
    assert(l_target,"performPsuChipOp: master proc target is NULL");

    do
    {
        // write PSU Request
        errl = writeRequest(l_target,
                            i_pPsuRequest,
                            i_reqMsgs);
        if (errl)//error has been generated
        {
            SBE_TRACF(ERR_MRK"performPsuChipOp::"
                    " writeRequest returned an error");
            break;
        }

        // read PSU response and check results
        errl = readResponse(l_target,
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

    //@todo-RTC:144313-Remove when we have our FFDC in place
    //Temporarily crash with a known RC so that HWSV collects the SBE FFDC
    if( errl && (SBE_COMP_ID == errl->moduleId()) )
    {
        SBE_TRACF( "Forcing shutdown for FSP to collect FFDC" );

        //commit the original error after pulling some data out
        uint32_t orig_plid = errl->plid();
        uint32_t orig_rc = errl->reasonCode();
        uint32_t orig_mod = errl->moduleId();
        ERRORLOG::errlCommit( errl, SBE_COMP_ID );
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
              l_target->getAttr<TARGETING::ATTR_POSITION>(),
              SBEIO_HWSV_COLLECT_SBE_RC);
        INITSERVICE::doShutdown( SBEIO_HWSV_COLLECT_SBE_RC );
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

        // Read SBE doorbell to confirm ready to accept command.
        // Since the device driver single threads the requests, we should
        // never see not being ready to send a request.
        uint64_t l_addr = PSU_SBE_DOORBELL_REG_RW;
        uint64_t l_data = 0;
        errl = readScom(i_target,l_addr,&l_data);
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

            SbeFFDCParser * l_ffdc_parser = new SbeFFDCParser();
            l_ffdc_parser->parseFFDCData(iv_ffdcPackageBuffer);
            uint8_t l_pkgs = l_ffdc_parser->getTotalPackages();
            uint8_t i;
            for(i = 0; i < l_pkgs; i++)
            {
                errl->addFFDC( SBE_COMP_ID,
                           l_ffdc_parser->getFFDCPackage(i),
                           l_ffdc_parser->getPackageLength(i),
                           0,                           // version
                           ERRORLOG::ERRL_UDT_NOFORMAT, // subversion
                           false );
            }

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
            MAGIC_INST_GET_SBE_TRACES(
                  i_target->getAttr<TARGETING::ATTR_POSITION>(),
                  SBEIO_PSU_NOT_READY);

            delete l_ffdc_parser;
            break; // return with error
        }

        //write the command registers
        uint64_t * l_pMessage = (uint64_t *)i_pPsuRequest;
        l_addr     = PSU_HOST_SBE_MBOX0_REG;
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
        l_addr = PSU_SBE_DOORBELL_REG_OR;
        l_data = SBE_DOORBELL;
        errl = writeScom(i_target,l_addr,&l_data);
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
        errl = pollForPsuComplete(i_target,i_timeout);
        if (errl) break;  // return with error

        //read the response registers
        uint64_t * l_pMessage = (uint64_t *)o_pPsuResponse;
        uint64_t   l_addr     = PSU_HOST_SBE_MBOX4_REG;
        for (uint8_t i=0;i<4;i++)
        {
            if (0x01 & i_rspMsgs) // read register if non-reserved
            {
                errl = readScom(i_target,l_addr,l_pMessage);
                break;
            }
            i_rspMsgs>>=1;
            l_addr++;
            l_pMessage++;
        }
        if (errl) break;

        //notify PSU response has been read
        l_addr = PSU_HOST_DOORBELL_REG_AND;
        uint64_t l_data = HOST_CLEAR_RESPONSE_WAITING;
        errl = writeScom(i_target,l_addr,&l_data);
        if (errl) break;

        //check status and seq ID in response messages
        if ((SBE_PRI_OPERATION_SUCCESSFUL != o_pPsuResponse->primaryStatus) ||
            (SBE_SEC_OPERATION_SUCCESSFUL != o_pPsuResponse->secondaryStatus) ||
            (i_pPsuRequest->seqID != o_pPsuResponse->seqID) )
        {

            SBE_TRACF(ERR_MRK "sbe_psudd.C :: readResponse: failing response status "
                      " cmd=0x%08x prim=0x%08x secondary=0x%08x",
                      " expected seqID=%d actual seqID=%d",
                      i_pPsuRequest[1],
                      o_pPsuResponse->primaryStatus,
                      o_pPsuResponse->secondaryStatus,
                      i_pPsuRequest->seqID,
                      o_pPsuResponse->seqID);
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

            SbeFFDCParser * l_ffdc_parser = new SbeFFDCParser();
            l_ffdc_parser->parseFFDCData(iv_ffdcPackageBuffer);
            uint8_t l_pkgs = l_ffdc_parser->getTotalPackages();
            uint8_t i;
            for(i = 0; i < l_pkgs; i++)
            {
                errl->addFFDC( SBE_COMP_ID,
                           l_ffdc_parser->getFFDCPackage(i),
                           l_ffdc_parser->getPackageLength(i),
                           0,                           // version
                           ERRORLOG::ERRL_UDT_NOFORMAT, // subversion
                           false );
            }

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
            MAGIC_INST_GET_SBE_TRACES(
                  i_target->getAttr<TARGETING::ATTR_POSITION>(),
                  SBEIO_PSU_RESPONSE_ERROR);

            delete l_ffdc_parser;
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
                                      const uint64_t i_timeout)
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "pollForPsuComplete");

    uint64_t l_elapsed_time_ns = 0;
    uint64_t l_addr = PSU_HOST_DOORBELL_REG_RW;
    uint64_t l_data = 0;
    bool     l_trace = true; //initialize so first call is traced

    do
    {
        // read response doorbell to see if ready
        errl = readScom(i_target,l_addr,&l_data,l_trace);
        if (errl) break; // return with error

        // check if response is now ready to be read
        if (l_data & HOST_RESPONSE_WAITING)
        {
            break; // return with success
        }

        // time out if wait too long
        if (l_elapsed_time_ns > i_timeout )
        {
            SBE_TRACF(ERR_MRK "pollForPsuComplete: "
                      "timeout waiting for PSU request to complete");

            /*@
             * @errortype
             * @moduleid     SBEIO_PSU
             * @reasoncode   SBEIO_PSU_RESPONSE_TIMEOUT
             * @userdata1    Timeout in NS
             * @devdesc      Timeout waiting for PSU command to complete
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_PSU,
                                 SBEIO_PSU_RESPONSE_TIMEOUT,
                                 i_timeout,
                                 0);

            SbeFFDCParser * l_ffdc_parser = new SbeFFDCParser();
            l_ffdc_parser->parseFFDCData(iv_ffdcPackageBuffer);
            uint8_t l_pkgs = l_ffdc_parser->getTotalPackages();
            uint8_t i;
            for(i = 0; i < l_pkgs; i++)
            {
                errl->addFFDC( SBE_COMP_ID,
                           l_ffdc_parser->getFFDCPackage(i),
                           l_ffdc_parser->getPackageLength(i),
                           0,                           // version
                           ERRORLOG::ERRL_UDT_NOFORMAT, // subversion
                           false );
            }

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
            MAGIC_INST_GET_SBE_TRACES(
                  i_target->getAttr<TARGETING::ATTR_POSITION>(),
                  SBEIO_PSU_RESPONSE_TIMEOUT);

            delete l_ffdc_parser;
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

    return errl;
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
 * @brief zero out FFDC Package Buffer
 */

void SbePsu::initFFDCPackageBuffer()
{
    memset(iv_ffdcPackageBuffer, 0x00, PAGESIZE * ffdcPackageSize);
}

/**
 * @brief populate FFDC package buffer
 * @param[in]  i_data        FFDC error data
 * @param[in]  i_len         data buffer len to copy
 */
void SbePsu::writeFFDCBuffer( void * i_data, uint8_t i_len) {
    if(i_len <= PAGESIZE * ffdcPackageSize)
    {
        initFFDCPackageBuffer();
        memcpy(iv_ffdcPackageBuffer, i_data, i_len);
    }
    else
    {
        SBE_TRACF(ERR_MRK"writeFFDCBuffer: Buffer size too large: %d",
                      i_len);
    }
}

} //end of namespace SBEIO
