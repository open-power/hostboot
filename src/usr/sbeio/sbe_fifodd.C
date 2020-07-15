/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_fifodd.C $                                  */
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
 * @file sbe_fifodd.C
 * @brief SBE FIFO device driver
 */

#include <sys/time.h>
#include <trace/interface.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <sbeio/sbeioreasoncodes.H>
#include <errl/errlreasoncodes.H>
#include "sbe_fifo_buffer.H"
#include "sbe_fifodd.H"
#include <sbeio/sbe_ffdc_package_parser.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <kernel/pagemgr.H>
// FIXME RTC: 254961
//#include <fapi2.H>
//#include <set_sbe_error.H>
#include <sbeio/sbe_sp_intf.H>
#include <xscom/piberror.H>
#include <sbeio/sbe_retry_handler.H>
#include <initservice/initserviceif.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"fifodd: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"fifodd: " printf_string,##args)
#define SBE_TRACU(args...)
#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio,"fifodd: " printf_string,##args)
#define SBE_TRACDBIN(printf_string,args...) \
    TRACDBIN(g_trac_sbeio,"fifodd: " printf_string,##args)
/* replace for unit testing
#define SBE_TRACU(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"fifodd: " printf_string,##args)
*/
#define READ_BUFFER_SIZE 2048

#define TOLERATE_BLACKLIST_ERRS 0

using namespace ERRORLOG;

namespace SBEIO
{

SbeFifo & SbeFifo::getTheInstance()
{
    return Singleton<SbeFifo>::instance();
}

/**
 * @brief  Constructor
 */
SbeFifo::SbeFifo()
{
    iv_ffdcPackageBuffer = PageManager::allocatePage(ffdcPackageSize, true);
    initFFDCPackageBuffer();
}

/**
 * @brief  Destructor
 */
SbeFifo::~SbeFifo()
{
    if(iv_ffdcPackageBuffer != NULL)
    {
        PageManager::freePage(iv_ffdcPackageBuffer);
    }
}

/**
 * @brief perform SBE FIFO chip-op
 */
errlHndl_t SbeFifo::performFifoChipOp(TARGETING::Target * i_target,
                             uint32_t          * i_pFifoRequest,
                             uint32_t          * i_pFifoResponse,
                             uint32_t            i_responseSize)
{
    errlHndl_t errl = NULL;
    static mutex_t l_fifoOpMux = MUTEX_INITIALIZER;

    SBE_TRACD(ENTER_MRK "performFifoChipOp");

    //Serialize access to PSU
    mutex_lock(&l_fifoOpMux);

    do
    {
        errl = writeRequest(i_target,
                            i_pFifoRequest);
        if (errl) break;  // return with error

        errl = readResponse(i_target,
                            i_pFifoRequest,
                            i_pFifoResponse,
                            i_responseSize);
        if (errl) break;  // return with error

    }
    while (0);

    mutex_unlock(&l_fifoOpMux);

    SBE_TRACD(EXIT_MRK "performFifoChipOp");

    return errl;
}


/**
 * @brief perform SBE FIFO Reset
 */
errlHndl_t SbeFifo::performFifoReset(TARGETING::Target * i_target)
{
    errlHndl_t errl = NULL;
    static mutex_t l_fifoOpMux = MUTEX_INITIALIZER;

    SBE_TRACF(ENTER_MRK "sending FSI SBEFIFO Reset to HUID 0x%x",
              TARGETING::get_huid(i_target));

    //Serialize access to the FIFO
    mutex_lock(&l_fifoOpMux);

    // Perform a write to the DNFIFO Reset to cleanup the fifo
    uint32_t l_dummy = 0xDEAD;
    errl = writeFsi(i_target,SBE_FIFO_DNFIFO_RESET,&l_dummy);

    mutex_unlock(&l_fifoOpMux);

    return errl;
}


/**
 * @brief write FIFO request message
 */
errlHndl_t SbeFifo::writeRequest(TARGETING::Target * i_target,
                        uint32_t * i_pFifoRequest)
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "writeRequest");

    do
    {
        // Ensure Downstream Max Transfer Counter is 0 since
        // hostboot has no need for it (non-0 can cause
        // protocol issues)
        uint64_t l_addr       = SBE_FIFO_DNFIFO_MAX_TSFR;
        uint32_t l_data       = 0;
        errl = writeFsi(i_target,l_addr,&l_data);
        if (errl) break;

        //The first uint32_t has the number of uint32_t words in the request
        l_addr                = SBE_FIFO_UPFIFO_DATA_IN;
        uint32_t * l_pSent    = i_pFifoRequest; //advance as words sent
        uint32_t   l_cnt      = *l_pSent;
        SBE_TRACDBIN("Write Request in SBEIO",i_pFifoRequest,
                     l_cnt*sizeof(*l_pSent));
        for (uint32_t i=0;i<l_cnt;i++)
        {
            // Wait for room to write into fifo
            errl = waitUpFifoReady(i_target);
            if (errl) break;

            // Send data into fifo
            errl = writeFsi(i_target,l_addr,l_pSent);
            if (errl) break;

            l_pSent++;
        }
        if (errl) break;

        //notify SBE that last word has been sent
        errl = waitUpFifoReady(i_target);
        if (errl) break;

        l_addr = SBE_FIFO_UPFIFO_SIG_EOT;
        l_data = FSB_UPFIFO_SIG_EOT;
        errl = writeFsi(i_target,l_addr,&l_data);
        if (errl) break;

    }
    while (0);

    SBE_TRACD(EXIT_MRK "writeRequest");

    return errl;
}

/**
 * @brief wait for room in upstream fifo to send data
 */
errlHndl_t SbeFifo::waitUpFifoReady(TARGETING::Target * i_target)
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "waitUpFifoReady");

    uint64_t l_elapsed_time_ns = 0;
    uint64_t l_addr = SBE_FIFO_UPFIFO_STATUS;
    uint32_t l_data = 0;

    do
    {
        // read upstream status to see if room for more data
        errl = readFsi(i_target,l_addr,&l_data);
        if (errl) break;

        if ( !(l_data & UPFIFO_STATUS_FIFO_FULL) )
        {
            break;
        }

        // time out if wait too long
        if (l_elapsed_time_ns >= MAX_UP_FIFO_TIMEOUT_NS )
        {
            SBE_TRACF(ERR_MRK "waitUpFifoReady: "
                      "timeout waiting for upstream FIFO to be not full");

            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_UPSTREAM_TIMEOUT
             * @userdata1    Timeout in NS
             * @devdesc      Timeout waiting for upstream FIFO to have
             *               room to write
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_FIFO,
                                 SBEIO_FIFO_UPSTREAM_TIMEOUT,
                                 MAX_UP_FIFO_TIMEOUT_NS,
                                 0);

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->addHwCallout(  i_target,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );
            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }

        // try later
        nanosleep( 0, 10000 ); //sleep for 10,000 ns
        l_elapsed_time_ns += 10000;
    }
    while (1);

    SBE_TRACD(EXIT_MRK "waitUpFifoReady");

    return errl;
}

/**
 * @brief Read FIFO response messages
 */
errlHndl_t SbeFifo::readResponse(TARGETING::Target * i_target,
                        uint32_t * i_pFifoRequest,
                        uint32_t * o_pFifoResponse,
                        uint32_t   i_responseSize)
{
    errlHndl_t errl = NULL;
    SbeFifo::fifoGetSbeFfdcRequest *l_pFifoRequest =
        reinterpret_cast<SbeFifo::fifoGetSbeFfdcRequest *>(i_pFifoRequest);
    bool l_getSbeFfdcReq =
        ((l_pFifoRequest->commandClass == SBE_FIFO_CLASS_GENERIC_MESSAGE) &&
         (l_pFifoRequest->command == SBE_FIFO_CMD_GET_SBE_FFDC))
        ? true : false;
    SbeFifoRespBuffer l_fifoBuffer{o_pFifoResponse,
                                   i_responseSize/sizeof(uint32_t),
                                   l_getSbeFfdcReq};

    SBE_TRACD(ENTER_MRK "readResponse");

#ifdef TOLERATE_BLACKLIST_ERRS
    auto blacklisted = false;
#endif

    do
    {
        // EOT is expected before the response buffer is full. Room for
        // the PCBPIB status or FFDC is included, but is only returned
        // if there is an error. The last received word has the distance
        // to the status, which is placed at the end of the returned data
        // in order to reflect errors during transfer.

        bool       l_EOT      = false;

        while(l_fifoBuffer) //keep reading data until an error or until the
                            //message is completely read.
        {
            // Wait for data to be ready to receive (download) or if the EOT
            // has been sent. If not EOT, then data ready to receive.
            uint32_t l_status = 0;
            errl = waitDnFifoReady(i_target,l_status);
            if (errl)
            {
                SBE_TRACF("readResponse: waitDnFifoReady returned an error");
                break;
            }

            if (l_status & DNFIFO_STATUS_DEQUEUED_EOT_FLAG)
            {
                l_EOT = true;
                l_fifoBuffer.completeMessage();
            }
            else
            {
                uint32_t l_data{};
                // read next word
                errl = readFsi(i_target,SBE_FIFO_DNFIFO_DATA_OUT,&l_data);
                if (errl) break;

                l_fifoBuffer.append(l_data);
            }
        }
        if (errl) break;


        // EOT is expected before running out of response buffer
        if (!l_EOT)
        {
            SBE_TRACF(ERR_MRK "readResponse: no EOT cmd=0x%08x size=%d",
                      i_pFifoRequest[1],i_responseSize);

            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_NO_DOWNSTREAM_EOT
             * @userdata1    FIFO command class and command
             * @userdata2    Response buffer size
             * @devdesc      EOT not received before downstream buffer full.
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_FIFO,
                                 SBEIO_FIFO_NO_DOWNSTREAM_EOT,
                                 i_pFifoRequest[1],
                                 i_responseSize);


            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->addHwCallout(  i_target,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );
            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }

        //notify that EOT has been received
        uint32_t l_eotSig = FSB_UPFIFO_SIG_EOT;
        errl = writeFsi(i_target,SBE_FIFO_DNFIFO_ACK_EOT,&l_eotSig);
        if (errl) break;

        //Determine if successful.
        if (!l_fifoBuffer.getStatus())
        {
            SBE_TRACF(ERR_MRK "readResponse: invalid status distance "
                      "cmd=0x%08x distance=%d allocated response size=%d "
                      "received word size=%d" ,
                      i_pFifoRequest[1],
                      l_fifoBuffer.offset(),
                      i_responseSize,
                      l_fifoBuffer.index());

            SBE_TRACFBIN("Invalid Response from SBE",
                         l_fifoBuffer.localBuffer(),
                         l_fifoBuffer.index()*sizeof(uint32_t));

            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_INVALID_STATUS_DISTANCE
             * @userdata1    FIFO command class and command
             * @userdata2[0:15]   Distance to status in words
             * @userdata2[16:31]  Bytes received
             * @userdata2[32:63]  Response buffer size
             * @devdesc      The distance to the status header is not
             *               within the response buffer.
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_FIFO,
                                 SBEIO_FIFO_INVALID_STATUS_DISTANCE,
                                 i_pFifoRequest[1],
                                 TWO_UINT32_TO_UINT64(
                                    TWO_UINT16_TO_UINT32(l_fifoBuffer.offset(),
                                        l_fifoBuffer.index()*sizeof(uint32_t)),
                                    i_responseSize));

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->addHwCallout(  i_target,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );
            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }

        // Check status for success.
        const statusHeader * l_pStatusHeader = l_fifoBuffer.getStatusHeader();
        if ((FIFO_STATUS_MAGIC != l_pStatusHeader->magic) ||
            (SBE_PRI_OPERATION_SUCCESSFUL != l_pStatusHeader->primaryStatus) ||
            (SBE_SEC_OPERATION_SUCCESSFUL != l_pStatusHeader->secondaryStatus))
        {
            SBE_TRACF(ERR_MRK "readResponse: failing downstream status "
                      " cmd=0x%08x magic=0x%08x prim=0x%08x secondary=0x%08x",
                      i_pFifoRequest[1],
                      l_pStatusHeader->magic,
                      l_pStatusHeader->primaryStatus,
                      l_pStatusHeader->secondaryStatus);

            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_RESPONSE_ERROR
             * @userdata1    FIFO command class and command
             * @userdata2[0:31]   Should be magic value 0xC0DE
             * @userdata1[32:47]  Primary Status
             * @userdata1[48:63]  Secondary Status
             *
             * @devdesc  Status header does not start with magic number or
             *           non-zero primary or secondary status
             */

            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_FIFO,
                                 SBEIO_FIFO_RESPONSE_ERROR,
                                 i_pFifoRequest[1],
                                 FOUR_UINT16_TO_UINT64(
                                         0,
                                         l_pStatusHeader->magic,
                                         l_pStatusHeader->primaryStatus,
                                         l_pStatusHeader->secondaryStatus));

            #ifdef TOLERATE_BLACKLIST_ERRS
            if(   (FIFO_STATUS_MAGIC == l_pStatusHeader->magic)
               && (SBE_PRI_UNSECURE_ACCESS_DENIED == l_pStatusHeader->primaryStatus)
               && (SBE_SEC_BLACKLISTED_REG_ACCESS == l_pStatusHeader->secondaryStatus))
            {
                blacklisted = true;

                const SbeFifo::fifoPutScomRequest* pScomRequest =
                    reinterpret_cast<const SbeFifo::fifoPutScomRequest*>(
                        i_pFifoRequest);

                SBE_TRACF(ERR_MRK "SbeFifo::readResponse: Secure Boot "
                    "violation; request blacklisted by SBE.  Reference EID "
                    "0x%08X, PLID 0x%08X, reason code 0x%04X, "
                    "class 0x%02X, command 0x%02X, address 0x%016llX, "
                    "data 0x%016llX",
                    errl->eid(),errl->plid(),errl->reasonCode(),
                    pScomRequest->commandClass, pScomRequest->command,
                    pScomRequest->address, pScomRequest->data);

                errl->collectTrace(SBEIO_COMP_NAME);
            }
            #endif

            if(!l_fifoBuffer.msgContainsFFDC())
            {
                break;
            }

            writeFFDCBuffer(l_fifoBuffer.getFFDCPtr(),
                            l_fifoBuffer.getFFDCByteSize());

            SbeFFDCParser * l_ffdc_parser = new SbeFFDCParser();
            l_ffdc_parser->parseFFDCData(iv_ffdcPackageBuffer);

            // Go through the buffer, get the RC
            uint8_t l_pkgs = l_ffdc_parser->getTotalPackages();
            for(uint8_t i = 0; i < l_pkgs; i++)
            {
                 ffdc_package l_package = {nullptr, 0, 0};
                 if(!l_ffdc_parser->getFFDCPackage(i, l_package))
                 {
                     continue;
                 }

// FIXME RTC: 254961
#if 0
                 uint32_t l_rc = l_package.rc;
                 // If fapiRC, add data to errorlog
                 if(l_rc ==  fapi2::FAPI2_RC_PLAT_ERR_SEE_DATA)
                 {
                     errl->addFFDC( SBEIO_COMP_ID,
                                    l_package.ffdcPtr,
                                    l_package.size,
                                    0,
                                    SBEIO_UDT_PARAMETERS,
                                    false );
                 }
                 else
                 {
                     using namespace fapi2;

                     fapi2::ReturnCode l_fapiRC;

                     /*
                      * Put FFDC into sbeFfdc_t struct and
                      * call FAPI_SET_SBE_ERROR
                      */
                     sbeFfdc_t * l_ffdcBuf = new sbeFfdc_t();
                     l_ffdcBuf->size = l_package.size;
                     l_ffdcBuf->data = reinterpret_cast<uint64_t>(
                                                           l_package.ffdcPtr);

                     FAPI_SET_SBE_ERROR(l_fapiRC,
                                l_rc,
                                l_ffdcBuf,
                                i_target->getAttr<TARGETING::ATTR_FAPI_POS>());

                     errlHndl_t sbe_errl = fapi2::rcToErrl(l_fapiRC);
                     if( sbe_errl )
                     {
                         ERRORLOG::errlCommit( sbe_errl, SBEIO_COMP_ID );
                     }
                 }
#endif

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

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->addHwCallout(  i_target,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );
            errl->collectTrace(SBEIO_COMP_NAME);

            delete  l_ffdc_parser;
            break;
        }
    }
    while (0);

    SBE_TRACD(EXIT_MRK "readResponse");

#ifdef TOLERATE_BLACKLIST_ERRS
    if(blacklisted)
    {
        // Do not terminate the boot when tolerating blacklist errors, just log
        // the error and move on.  Note that until all blacklist violations are
        // fixed, SBE will still execute the request, but will return primary
        // status as access denied and secondary status as blacklist violation,
        // which is how we know there is a theoretical problem to address.
        ERRORLOG::errlCommit(errl, SBEIO_COMP_ID);
    }
#endif

    return errl;
}

/**
 * @brief wait for data in downstream fifo to receive
 *        or hit EOT.
 *
 *        On return, either a valid word is ready to read,
 *        or the EOT will be set in the returned doorbell status.
 */
errlHndl_t SbeFifo::waitDnFifoReady(TARGETING::Target * i_target,
                           uint32_t          & o_status)
{
    errlHndl_t errl = NULL;
    SBE_TRACD(ENTER_MRK "waitDnFifoReady");

    uint64_t l_elapsed_time_ns = 0;
    uint64_t l_addr = SBE_FIFO_DNFIFO_STATUS;

    do
    {
        // read dnstream status to see if data ready to be read
        // or if has hit the EOT
        errl = readFsi(i_target,l_addr,&o_status);
        if (errl) break;

        if (  (!(o_status & DNFIFO_STATUS_FIFO_EMPTY)) ||
              (o_status & DNFIFO_STATUS_DEQUEUED_EOT_FLAG) )
        {
            SBE_TRACD("Read a word from status register: 0x%.8X",o_status);
            break;
        }
        else
        {
            SBE_TRACD("SBE status reg returned fifo empty or "
                      "dequeued eot flag 0x%.8X",
                      o_status);
        }

        // time out if wait too long
        if (l_elapsed_time_ns >= MAX_UP_FIFO_TIMEOUT_NS )
        {
            SBE_TRACF(ERR_MRK "waitDnFifoReady: "
                      "timeout waiting for downstream FIFO to be not full");

            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_DOWNSTREAM_TIMEOUT
             * @userdata1    Timeout in NS
             * @userdata2    FIFO Status
             * @devdesc      Timeout waiting for downstream FIFO to have
             *               data to receive
             */

            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                SBEIO_FIFO,
                                SBEIO_FIFO_DOWNSTREAM_TIMEOUT,
                                MAX_UP_FIFO_TIMEOUT_NS,
                                o_status);

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);

            // Keep a copy of the plid so we can pass it to the retry_handler
            // so the error logs it creates will be linked
//            uint32_t l_errPlid = errl->plid();

            // Commit error log now if this is a FSP system because
            // we will not return from retry handler
            if(INITSERVICE::spBaseServicesEnabled())
            {
                errl->addHwCallout(  i_target,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::NO_DECONFIG,
                                     HWAS::GARD_NULL );
                ERRORLOG::errlCommit( errl, SBEIO_COMP_ID );
            }
            //On open power systems we want to deconfigure the processor
            else
            {
                errl->addHwCallout(  i_target,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::DELAYED_DECONFIG,
                                     HWAS::GARD_NULL );
            }

// FIXME RTC: 248572 no SbeRetryHandler yet
#if 0
            // Set the retry handler's mode to be informational, this will run
            // p9_extract_rc then TI the system on fsp-systems.
            // On open power systems if mode is set to informational we will run
            // p9_extract_rc then return back to this function
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                SbeRetryHandler::SBE_MODE_OF_OPERATION::INFORMATIONAL_ONLY,
                l_errPlid);

            // Look at the scomSwitch attribute to tell what types
            // of scoms are going to be used. If the SMP is not yet up then we
            // will still be using SbeScoms , this uses the fifo path which
            // is currently blocked by the current hwp invoke we failed on.
            // In this case we need to switch to use the FSI scom path.
            // If SMP is up and xscoms are being used we can skip this step
            TARGETING::ScomSwitches l_switches =
                i_target->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
            if(!l_switches.useXscom)
            {
                l_switches.useSbeScom = 0;
                l_switches.useFsiScom = 1;
                i_target->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
            }

            l_SBEobj.main_sbe_handler(i_target);
#endif

            //break out of continuous loop ( should only get here on openPower systems)
            break;
        }

        // try later
        nanosleep( 0, 10000 ); //sleep for 10,000 ns
        l_elapsed_time_ns += 10000;
    }
    while (1);

    SBE_TRACD(EXIT_MRK "waitDnFifoReady");

    return errl;
}

/**
 * @brief read FSI
 */
errlHndl_t SbeFifo::readFsi(TARGETING::Target * i_target,
                     uint64_t   i_addr,
                     uint32_t * o_pData)
{
    errlHndl_t errl = NULL;

    size_t l_32bitSize = sizeof(uint32_t);
    errl = deviceOp(DeviceFW::READ,
                    i_target,
                    o_pData,
                    l_32bitSize,
                    DEVICE_FSI_ADDRESS(i_addr));

    SBE_TRACU("  readFsi addr=0x%08lx data=0x%08x",
                         i_addr,*o_pData);

    return errl;
}

/**
 * @brief write FSI
 */
errlHndl_t SbeFifo::writeFsi(TARGETING::Target * i_target,
                     uint64_t   i_addr,
                     uint32_t * i_pData)
{
    errlHndl_t errl = NULL;

    SBE_TRACU("  writeFsi addr=0x%08lx data=0x%08x",
                         i_addr,*i_pData);
    size_t l_32bitSize = sizeof(uint32_t);
    errl = deviceOp(DeviceFW::WRITE,
                    i_target,
                    i_pData,
                    l_32bitSize,
                    DEVICE_FSI_ADDRESS(i_addr));

    return errl;
}

/**
 * @brief zero out FFDC Package Buffer
 */

void SbeFifo::initFFDCPackageBuffer()
{
    memset(iv_ffdcPackageBuffer, 0x00, PAGESIZE * ffdcPackageSize);
}

/**
 * @brief populate FFDC package buffer
 * @param[in]  i_data        FFDC error data
 * @param[in]  i_len         data buffer len to copy
 */
void SbeFifo::writeFFDCBuffer(const void * i_data, uint32_t i_len) {
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
