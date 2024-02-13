/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_fifodd.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
 * @brief SBE FIFO device driver (common between IPL and RUNTIME)
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
#include <sbeio/errlud_sbeio.H>
#include <sbeio/sbe_ffdc_package_parser.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <fapi2.H>
#include <set_sbe_error.H>
#include <sbeio/sbe_sp_intf.H>
#include <xscom/piberror.H>
#include <sbeio/sbe_retry_handler.H>
#include <initservice/initserviceif.H>
#include <targeting/odyutil.H>
#include <util/misc.H>
#include <errl/errludlogregister.H>
#include <cxxtest/TestInject.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"fifodd: " printf_string,##args)
#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio,"fifodd: " printf_string,##args)

#define UNIT_TEST_TRACES 0
#define DEBUG_TRACES     0

#if UNIT_TEST_TRACES
#define SBE_TRACU(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"fifodd: " printf_string,##args)
#else
#define SBE_TRACU(args...)
#endif

#if DEBUG_TRACES
#define SBE_TRACD(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"fifodd: " printf_string,##args)
#define SBE_TRACDBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio,"fifodd: " printf_string,##args)
#else
#define SBE_TRACD(args...)
#define SBE_TRACDBIN(args...)
#endif

using namespace ERRORLOG;
using namespace TARGETING;

namespace SBEIO
{
#if defined(CONFIG_COMPILE_CXXTEST_HOOKS)
#define CI_INJECT_FIFO_HANG(_g_inject, _i_target, _enum, _msg, _l_errl)         \
            if (_g_inject.isSet(_enum))                                         \
            {                                                                   \
                _g_inject.clear(_enum);                                         \
                SBE_TRACF(_msg                                                  \
                          " OCMB 0x%08x", TARGETING::get_huid(_i_target));      \
                _l_errl = dnFifoTimeout(_i_target, 0xFFFF);                     \
            }

#define CI_INJECT_FIFO_BREAKAGE(_g_inject, _i_target, _enum, _timeout, _msg)    \
            if (_g_inject.isSet(_enum))                                         \
            {                                                                   \
                _g_inject.clear(_enum);                                         \
                SBE_TRACF(_msg " OCMB 0x%08x", TARGETING::get_huid(_i_target)); \
                _timeout = true;                                                \
            }
#else
#define CI_INJECT_FIFO_HANG(_g_inject, _i_target, _enum, _msg, _l_errl)
#define CI_INJECT_FIFO_BREAKAGE(_g_inject, _i_target, _enum, _timeout, _msg)
#endif


SbeFifo & SbeFifo::getTheInstance()
{
    return Singleton<SbeFifo>::instance();
}

/**
 * @brief  Constructor
 */
SbeFifo::SbeFifo()
{
}

/**
 * @brief  Destructor
 */
SbeFifo::~SbeFifo()
{
}

errlHndl_t SbeFifo::performFifoChipOp(TARGETING::Target   * i_target,
                                                 uint32_t * i_pFifoRequest,
                                                 uint32_t * i_pFifoResponse,
                                                 uint32_t   i_responseSize)
{
    memory_stream stream { i_pFifoRequest, *i_pFifoRequest * sizeof(uint32_t) };

    return performFifoChipOp(i_target, std::move(stream), i_pFifoResponse, i_responseSize);
}

errlHndl_t SbeFifo::performFifoChipOp(TARGETING::Target   * i_target,
                                                 uint32_t * i_pFifoRequest,
                                                 uint32_t * i_pFifoResponse,
                                                 uint32_t   i_responseSize,
                                                 uint32_t & o_actualResponseSize)
{
    memory_stream stream { i_pFifoRequest, *i_pFifoRequest * sizeof(uint32_t) };

    return performFifoChipOp(i_target, std::move(stream), i_pFifoResponse, i_responseSize, o_actualResponseSize);
}

errlHndl_t SbeFifo::performFifoChipOp(TARGETING::Target   *i_target,
                                 fifo_chipop_data_stream&& i_requestStream,
                                                 uint32_t *i_pFifoResponse,
                                                 uint32_t  i_responseSize)
{
    uint32_t actual_response_size = 0;
    return performFifoChipOp(i_target,
                             std::move(i_requestStream),
                             i_pFifoResponse,
                             i_responseSize,
                             actual_response_size);
}

errlHndl_t SbeFifo::performFifoChipOp(TARGETING::Target   *i_target,
                                 fifo_chipop_data_stream&& i_requestStream,
                                                 uint32_t *i_pFifoResponse,
                                                 uint32_t  i_responseSize,
                                                 uint32_t &o_actualResponseSize)
{
    errlHndl_t errl = nullptr;

    SBE_TRACD(ENTER_MRK "performFifoChipOp HUID=0x%X", get_huid(i_target));

    // Serialize access to the FIFO for i_target
    mutex_t *l_mutex = i_target->getHbMutexAttr<TARGETING::ATTR_SBE_FIFO_MUTEX>();
    const auto lock  = scoped_recursive_mutex_lock(*l_mutex);

    std::array<uint32_t, 2> request_header = { };
    errl = writeRequest(i_target, i_requestStream, request_header);
    if (errl) {goto ERROR_EXIT;}

    // skip reading a response for commands that don't have one
    if ((i_pFifoResponse != nullptr) && (i_responseSize > 0))
    {
        errl = readResponse(i_target,
                            &request_header[0],
                            i_pFifoResponse,
                            i_responseSize);
        if (errl) {goto ERROR_EXIT;}
        o_actualResponseSize = i_responseSize; // i_responseSize was modified by readResponse
    }
    else
    {
        SBE_TRACD("performFifoChipOp: skipping readResponse()");
    }

 ERROR_EXIT:
    if (errl)
    {
        SBE_TRACF(ERR_MRK"performFifoChipOp: PIPE Fifo HUID=0x%X", get_huid(i_target));
        if (TARGETING::UTIL::isOdysseyChip(i_target))
        {
            UdSPPECodeLevels(i_target).addToLog(errl);
        }
    }

    SBE_TRACD(EXIT_MRK "performFifoChipOp");

    return errl;
}

/**
 * @brief perform SBE FIFO Reset
 */
errlHndl_t SbeFifo::performFifoReset(TARGETING::Target * i_target)
{
    errlHndl_t errl = nullptr;

    SBE_TRACF(ENTER_MRK "performFifoReset: to HUID 0x%08X",
              TARGETING::get_huid(i_target));

    //Serialize access to the FIFO
    mutex_t *l_mutex = i_target->getHbMutexAttr<TARGETING::ATTR_SBE_FIFO_MUTEX>();
    const auto lock  = scoped_recursive_mutex_lock(*l_mutex);

    // Perform a write to the DNFIFO Reset to cleanup the fifo
    uint32_t l_dummy = 0xDEAD;

    if (TARGETING::UTIL::isOdysseyChip(i_target))
    {
        // specialized handling to reset both FIFO's for Odyssey
        errl = OdyResetWriteFifoReg(i_target, FIFO_DNFIFO_RESET, &l_dummy);
    }
    else
    {
        errl = writeFifoReg(i_target, FIFO_DNFIFO_RESET, &l_dummy);
    }

    if (errl) {SBE_TRACF(ERR_MRK "performFifoReset");}
    SBE_TRACF(EXIT_MRK "performFifoReset: HUID 0x%08X", TARGETING::get_huid(i_target));
    return errl;
}

bool read_at_least(SbeFifo::fifo_chipop_data_stream& stream,
                   void* const buffer,
                   const size_t amt)
{
    auto ptr = reinterpret_cast<uint8_t*>(buffer);
    size_t read = 0;

    while (read < amt)
    {
        const auto this_pass = stream.read(ptr + read, amt - read);

        if (this_pass == 0)
        {
            break;
        }

        read += this_pass;
    }

    return read == amt;
}

/**
 * @brief write FIFO request message
 */
errlHndl_t SbeFifo::writeRequest(TARGETING::Target *i_target,
                           fifo_chipop_data_stream& i_stream,
                           std::array<uint32_t, 2>& o_request_header)
{
    errlHndl_t l_errl = NULL;
    uint32_t   l_data{};          // register value to write
    uint32_t   l_word{};          // word value read from the i_stream or fifo
    int        l_i{};             // counter to fill the o_request_header
    bool       l_go       = true; // true if more data from the i_stream exists
    bool       l_max_tsfr = true; // false if i_target is an odyssey PIPE

    SBE_TRACD(ENTER_MRK "writeRequest");

    if (TARGETING::UTIL::isOdysseyChip(i_target) &&
        i_target->getAttr<TARGETING::ATTR_USE_PIPE_FIFO>())
    {
        // do not set MAX_TSFR for an odyssey PIPE, it does not exist for a PIPE
        l_max_tsfr = false;
    }

    if (l_max_tsfr)
    {
        // Ensure Downstream Max Transfer Counter is 0 since
        // hostboot has no need for it (non-0 can cause
        // protocol issues)
        l_errl = writeFifoReg(i_target, FIFO_DNFIFO_MAX_TSFR, &l_data);
        if (l_errl) {goto ERROR_EXIT;}
    }

    l_go = read_at_least(i_stream, &l_word, sizeof(l_word));
    l_i  = 0;

    while (l_go)
    {
        if (l_i < 2)
        {
            o_request_header[l_i] = l_word;
        }

        // Wait for room to write into fifo
        l_errl = waitUpFifoReady(i_target);
        if (l_errl) {goto ERROR_EXIT;}

        // Send data into fifo
        l_errl = writeFifoReg(i_target, FIFO_UPFIFO_DATA_IN, &l_word);
        if (l_errl) {goto ERROR_EXIT;}

        ++l_i;
        l_go = read_at_least(i_stream, &l_word, sizeof(l_word));
    }

    // notify SBE that last word has been sent
    l_errl = waitUpFifoReady(i_target);
    if (l_errl) {goto ERROR_EXIT;}

    l_data = FSB_UPFIFO_SIG_EOT;
    l_errl = writeFifoReg(i_target, FIFO_UPFIFO_SIG_EOT, &l_data);
    if (l_errl) {goto ERROR_EXIT;}

    ERROR_EXIT:
    if (l_errl) {SBE_TRACF(ERR_MRK  "writeRequest");}

    SBE_TRACD(EXIT_MRK "writeRequest");

    return l_errl;
}

/**
 * @brief handle the timeout, waiting for room in upstream fifo
 */
errlHndl_t SbeFifo::upFifoTimeout(TARGETING::Target * i_target, uint32_t l_data)
{
    errlHndl_t errl = NULL;

        /*@
         * @errortype
         * @moduleid     SBEIO_FIFO
         * @reasoncode   SBEIO_FIFO_UPSTREAM_TIMEOUT
         * @userdata1    Timeout in NS
         * @userdata2[00:31]  Failing Target
         * @userdata2[32:63]  FIFO Status
         * @devdesc      Timeout waiting for upstream FIFO to have
         *               room to write
         * @custdesc     Firmware error communicating with a chip
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             SBEIO_FIFO,
                             SBEIO_FIFO_UPSTREAM_TIMEOUT,
                             MAX_UP_FIFO_TIMEOUT_NS,
                             TWO_UINT32_TO_UINT64(
                                                  TARGETING::get_huid(i_target),
                                                  l_data));

        errl->setErrorType(SBEIO_ERROR_TYPE_HRESET_PERFORMED);
        errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                  HWAS::SRCI_PRIORITY_HIGH);

        errl->collectTrace(SBEIO_COMP_NAME);
        collectRegFFDC(i_target,errl);

        // Commit error log now if this is a FSP system because
        // we will not return from retry handler (for processor chips)
        if (i_target->getAttr<ATTR_TYPE>() == TYPE_PROC
            && INITSERVICE::spBaseServicesEnabled())
        {
            errl->addHwCallout(i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::NO_DECONFIG,
                               HWAS::GARD_NULL );
            ERRORLOG::errlCommit( errl, SBEIO_COMP_ID );
        }
        //On BMC systems we want to deconfigure the chip
        else
        {
            errl->addHwCallout(i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::DELAYED_DECONFIG,
                               HWAS::GARD_NULL );
        }

        const auto l_SBEobj
            = make_sbe_retry_handler(i_target,
                                     SbeRetryHandler::SBE_MODE_OF_OPERATION::INFORMATIONAL_ONLY,
                                     SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                                     ERRL_GETPLID_SAFE(errl),
                                     NOT_INITIAL_POWERON);

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
            ATTR_FSI_MASTER_TYPE_type fsi_type = { };
            if (i_target->tryGetAttr<ATTR_FSI_MASTER_TYPE>(fsi_type)
                && fsi_type != FSI_MASTER_TYPE_NO_MASTER)
            {
                l_switches.useSbeScom = 0;
                l_switches.useFsiScom = 1;
            }

            i_target->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
        }

        // Since the retry handler's mode was set to "informational"
        // in the constructor above, this will run *_extract_sbe_rc
        // then, for proc chips, TI the system on fsp-systems. It may
        // collect a dump and/or do an HRESET where applicable.
        l_SBEobj->main_sbe_handler(errl);

        return errl;
    }

/**
 * @brief wait for room in upstream fifo to send data
 */
errlHndl_t SbeFifo::waitUpFifoReady(TARGETING::Target * i_target)
{
    errlHndl_t errl = NULL;

    SBE_TRACU(ENTER_MRK "waitUpFifoReady");

    uint32_t l_data = 0;

    const bool timeout = hbstd::with_timeout(0, MAX_UP_FIFO_TIMEOUT_NS, 0, 10000, [&]()
    {
        // read upstream status to see if room for more data
        errl = readFifoReg(i_target, FIFO_UPFIFO_STATUS, &l_data);
        if (errl) {return hbstd::timeout_t::STOP;}

        if (! (l_data & UPFIFO_STATUS_FIFO_FULL)) {return hbstd::timeout_t::STOP;}

        return hbstd::timeout_t::CONTINUE;
    });

    if (timeout && !errl) // timeout already implies !l_errl, but we check anyway
    {
        SBE_TRACF(ERR_MRK "waitUpFifoReady: "
                  "timeout waiting for upstream FIFO to be not full on %.8X",
                  TARGETING::get_huid(i_target));
        errl = upFifoTimeout(i_target, l_data);
    }

    SBE_TRACD(EXIT_MRK "waitUpFifoReady(0x%08X) = 0x%08X",
              get_huid(i_target),
              ERRL_GETEID_SAFE(errl));

    return errl;
}

/**
 * @brief Read FIFO response messages
 */
errlHndl_t SbeFifo::readResponse(TARGETING::Target   *i_target,
                                            uint32_t *i_pFifoRequest,
                                            uint32_t *o_pFifoResponse,
                                            uint32_t &io_responseSize)
{
    errlHndl_t errl = NULL;
    SbeFifo::fifoGetSbeFfdcRequest *l_pFifoRequest =
        reinterpret_cast<SbeFifo::fifoGetSbeFfdcRequest *>(i_pFifoRequest);
    bool l_getSbeFfdcReq =
        ((l_pFifoRequest->commandClass == SBE_FIFO_CLASS_GENERIC_MESSAGE) &&
         (l_pFifoRequest->command == SBE_FIFO_CMD_GET_SBE_FFDC))
        ? true : false;
    SbeFifoRespBuffer l_fifoBuffer{o_pFifoResponse,
                                   io_responseSize/sizeof(uint32_t),
                                   l_getSbeFfdcReq};

    SBE_TRACD(ENTER_MRK "readResponse");

    using namespace errl_util;

    do
    {
        // EOT is expected before the response buffer is full. Room for
        // the PCBPIB status or FFDC is included, but is only returned
        // if there is an error. The last received word has the distance
        // to the status, which is placed at the end of the returned data
        // in order to reflect errors during transfer.

        bool l_EOT = false;

        while(l_fifoBuffer) //keep reading data until an error or until the
                            //message is completely read.
        {
            errl = waitDnFifoReady(i_target, l_fifoBuffer, l_EOT);
            if (errl) {break;}
        }

        if (errl) {break;}

        // EOT is expected before running out of response buffer
        if (!l_EOT)
        {
            SBE_TRACF(ERR_MRK "readResponse: no EOT cmd=0x%08x size=%d",
                      i_pFifoRequest[1],io_responseSize);

            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_NO_DOWNSTREAM_EOT
             * @userdata1[00:31]  HUID of SBE that failed
             * @userdata1[32:63]  FIFO command class and command
             * @userdata2    Response buffer size
             * @devdesc      EOT not received before downstream buffer full.
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_FIFO,
                                 SBEIO_FIFO_NO_DOWNSTREAM_EOT,
                                 SrcUserData(
                                   bits{0,31},TARGETING::get_huid(i_target),
                                   bits{32,63},i_pFifoRequest[1]),
                                 io_responseSize);


            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->addHwCallout(  i_target,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );
            errl->collectTrace(SBEIO_COMP_NAME);

            // Log the response buffer that we have
            errl->addFFDC( SBEIO_COMP_ID,
                           o_pFifoResponse,
                           io_responseSize,
                           1,
                           ERRL_UDT_NOFORMAT,//raw data
                           false );
            // Log the beginning the data buffer that we have
            //  16 words fits most normal responses
            size_t l_numwords = std::min( (size_t)16,
                                          l_fifoBuffer.index() );
            errl->addFFDC( SBEIO_COMP_ID,
                           l_fifoBuffer.localBuffer(),
                           l_numwords*sizeof(uint32_t),
                           2,
                           ERRL_UDT_NOFORMAT,//raw data
                           false );
            // Log the end of the data buffer that we have
            l_numwords = std::min( (size_t)16, //last 16 words
                                   l_fifoBuffer.index() );

            if( l_numwords )
            {
                errl->addFFDC( SBEIO_COMP_ID,
                               l_fifoBuffer.localBuffer()
                               + (l_fifoBuffer.index() - l_numwords),
                               l_numwords*sizeof(uint32_t),
                               3,
                               ERRL_UDT_NOFORMAT,//raw data
                               false );
            }

            collectRegFFDC(i_target,errl);

            break;
        }

        //notify that EOT has been received
        uint32_t l_eotSig = FSB_UPFIFO_SIG_EOT;
        errl = writeFifoReg(i_target, FIFO_DNFIFO_ACK_EOT, &l_eotSig);

        // if the hang inject is on, create the timeout errl
        CI_INJECT_FIFO_HANG(CxxTest::g_cxxTestInject,
                            i_target,
                            CxxTest::SBEIO_INJECT_FIFO_HANG,
                            "readResponse: INJECT_FIFO_HANG",
                            errl);
        if (errl) {break;}

        //Determine if successful.
        if (!l_fifoBuffer.getStatus())
        {
            // DO NOT USE l_fifoBuffer.offset() may be invalid, i.e. MSG_SHORT_READ
            SBE_TRACF(ERR_MRK "readResponse: invalid data "
                      "cmd=0x%08x allocated response size=%d "
                      "received word size=%d" ,
                      i_pFifoRequest[1],
                      io_responseSize,
                      l_fifoBuffer.index());

            SBE_TRACFBIN("Invalid Response from SBE",
                         l_fifoBuffer.localBuffer(),
                         l_fifoBuffer.index()*sizeof(uint32_t));

            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_INVALID_STATUS_DISTANCE
             * @userdata1[00:31]  HUID of SBE that failed
             * @userdata1[32:63]  FIFO command class and command
             * @userdata2[00:15]  l_fifoBuffer.getState() indicates unexpected condition
             * @userdata2[16:31]  Bytes received
             * @userdata2[32:63]  Response buffer size
             * @devdesc      Invalid data, may be short read, etc.
             * @custdesc     Firmware error communicating with a chip
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_FIFO,
                                 SBEIO_FIFO_INVALID_STATUS_DISTANCE,
                                 SrcUserData(
                                   bits{0,31},TARGETING::get_huid(i_target),
                                   bits{32,63},i_pFifoRequest[1]),
                                 SrcUserData(
                                   bits{0,15},l_fifoBuffer.getState(),
                                   bits{16,31},l_fifoBuffer.index()*sizeof(uint32_t),
                                   bits{32,63},io_responseSize));

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->addHwCallout(  i_target,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );
            errl->collectTrace(SBEIO_COMP_NAME);
            collectRegFFDC(i_target,errl);
            break;
        }

        // Check status for success.
        const statusHeader * l_pStatusHeader = l_fifoBuffer.getStatusHeader();

        if ((FIFO_STATUS_MAGIC != l_pStatusHeader->magic) ||
            (SBE_PRI_OPERATION_SUCCESSFUL != l_pStatusHeader->primaryStatus) ||
            (SBE_SEC_OPERATION_SUCCESSFUL != l_pStatusHeader->secondaryStatus))
        {
            SBE_TRACF(ERR_MRK "readResponse: failing downstream status "
                      " cmd=0x%08x magic=0x%08x prim=0x%08x secondary=0x%08x on %.8X",
                      i_pFifoRequest[1],
                      l_pStatusHeader->magic,
                      l_pStatusHeader->primaryStatus,
                      l_pStatusHeader->secondaryStatus,
                      TARGETING::get_huid(i_target));

            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_RESPONSE_ERROR
             * @userdata1[00:31]  HUID of SBE that failed
             * @userdata1[32:63]  FIFO command class and command
             * @userdata2[00:15]  <unused>
             * @userdata2[16:31]  Should be magic value 0xC0DE
             * @userdata2[32:47]  Primary Status
             * @userdata2[48:63]  Secondary Status
             *
             * @devdesc  Status header does not start with magic number or
             *           non-zero primary or secondary status
             * @custdesc An internal firmware error occurred.
             */

            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_FIFO,
                                 SBEIO_FIFO_RESPONSE_ERROR,
                                 SrcUserData(
                                   bits{0,31},TARGETING::get_huid(i_target),
                                   bits{32,63},i_pFifoRequest[1]),
                                 SrcUserData(
                                   bits{0,15},0,
                                   bits{16,31},l_pStatusHeader->magic,
                                   bits{32,47},l_pStatusHeader->primaryStatus,
                                   bits{48,63},l_pStatusHeader->secondaryStatus));

            collectRegFFDC(i_target,errl);

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);

            errl->addHwCallout(i_target,
                               HWAS::SRCI_PRIORITY_LOW,
                               HWAS::NO_DECONFIG,
                               HWAS::GARD_NULL);
            errl->collectTrace(SBEIO_COMP_NAME);

        }

        // Only parse FFDC from the fifo buffer if the message contains FFDC and this is not a get FFDC chip-op request,
        // unless the chip-op request failed. This way, the caller can distinguish between the getFFDC chip-op request
        // failing and it returning the expected data.
        if ( l_fifoBuffer.msgContainsFFDC() && (!l_getSbeFfdcReq || errl))
        {
            SbeFFDCParser l_ffdc_parser;
            l_ffdc_parser.parseFFDCData(const_cast<void*>(l_fifoBuffer.getFFDCPtr()));

            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_PLATFORM_ERROR
             * @userdata1[00:31]  HUID of SBE which FFDC originates from
             * @userdata1[32:63]  FIFO command class and command
             * @userdata2[00:15]  <unused>
             * @userdata2[16:31]  Should be magic value 0xC0DE
             * @userdata2[32:47]  Primary Status
             * @userdata2[48:63]  Secondary Status
             *
             * @devdesc  An SBE returned FFDC as part of a FIFO message response.
             * @custdesc An internal firmware error occurred.
             */
            errlHndl_t sbeErrors = l_ffdc_parser.generateSbeErrors(i_target,
                                                                   SBEIO_FIFO,
                                                                   SBEIO_FIFO_PLATFORM_ERROR,
                                                                   SrcUserData(
                                                                     bits{0,31},TARGETING::get_huid(i_target),
                                                                     bits{32,63},i_pFifoRequest[1]),
                                                                   SrcUserData(
                                                                     bits{0,15},0,
                                                                     bits{16,31},l_pStatusHeader->magic,
                                                                     bits{32,47},l_pStatusHeader->primaryStatus,
                                                                     bits{48,63},l_pStatusHeader->secondaryStatus));
            if (uint32_t plid = ERRL_GETPLID_SAFE(errl))
            {
                sbeErrors->plid(plid);
            }

            ERRORLOG::aggregate(errl, sbeErrors);

            io_responseSize
                = (reinterpret_cast<const char*>(l_fifoBuffer.getFFDCPtr())
                   - reinterpret_cast<const char*>(l_fifoBuffer.localBuffer()));
        }
        else
        {
            io_responseSize = l_fifoBuffer.index() * sizeof(uint32_t);
        }
    }
    while (0);

    if (errl) {SBE_TRACF(ERR_MRK  "readResponse");}

    SBE_TRACD(EXIT_MRK "readResponse");
    return errl;
}

/**
 * @brief Read and parse the downstream fifo register(s)
 *
 *  if PIPE FIFO
 *    read64 FIFO_DNFIFO_DATA_OUT and parse
 *  else
 *    read FIFO_DNFIFO_STATUS/FIFO_DNFIFO_DATA_OUT and parse
 */
errlHndl_t SbeFifo::parseDataOutReg(TARGETING::Target   *i_target,
                                               uint32_t &o_data,
                                               uint32_t &o_status,
                                               bool     &o_EMPTY,
                                               bool     &o_EOT)
{
    errlHndl_t l_errl = NULL;
    bool       l_usePipe64 = (TARGETING::UTIL::isOdysseyChip(i_target) &&
                            i_target->getAttr<TARGETING::ATTR_USE_PIPE_FIFO>());

    if (l_usePipe64)
    {
        uint64_t l_data{};

        l_errl = readFifoReg64(i_target, FIFO_DNFIFO_DATA_OUT, &l_data);
        if (l_errl) {goto ERROR_EXIT;}

        o_data   = l_data >> 32;
        o_status = l_data & 0xFFFFFFFF;
        o_EOT    = o_status & DNFIFO_STATUS_EOT;

        if (o_EOT)
        {
            // when a 64-bit DATA_OUT register is used, we must use the data
            // included with the EOT status, so mark the entry VALID
            o_status |= DNFIFO_STATUS_VALID;
        }

        o_EMPTY = !(o_status & DNFIFO_STATUS_VALID);
    }
    else
    {
        l_errl = readFifoReg(i_target, FIFO_DNFIFO_STATUS, &o_status);
        if (l_errl) {goto ERROR_EXIT;}

        o_EMPTY = o_status & DNFIFO_STATUS_FIFO_EMPTY;
        o_EOT   = o_EMPTY && (o_status & DNFIFO_STATUS_DEQUEUED_EOT_FLAG);
        if (!o_EMPTY)
        {
            // an entry exists, read it
            l_errl = readFifoReg(i_target, FIFO_DNFIFO_DATA_OUT, &o_data);
            if (l_errl) {goto ERROR_EXIT;}
        }
    }

    if (!o_EMPTY)
    {
        SBE_TRACD("  parseDataOutReg: ENTRY, status:%08lX data:%08lX",o_status,o_data);
    }

    if (o_EOT)
    {
        SBE_TRACD("  parseDataOutReg: EOT,   status:%08lX",o_status);
    }
    else
    {
        SBE_TRACU("  parseDataOutReg: WAIT,  status:%08lX",o_status);
    }

    ERROR_EXIT:
    if (l_errl) {SBE_TRACF(ERR_MRK  "parseDataOutReg");}

    return l_errl;
}

/**
 * @brief handle the timeout, waiting for data in downstream fifo
 */
errlHndl_t SbeFifo::dnFifoTimeout(TARGETING::Target * i_target, uint32_t l_status)
{
    errlHndl_t l_errl            = NULL;

        /*@
         * @errortype
         * @moduleid     SBEIO_FIFO
         * @reasoncode   SBEIO_FIFO_DOWNSTREAM_TIMEOUT
         * @userdata1    Timeout in NS
         * @userdata2[00:31]  Failing Target
         * @userdata2[32:63]  FIFO Status
         * @devdesc      Timeout waiting for downstream FIFO to have
         *               data to receive
         * @custdesc     Firmware error communicating with a chip
         */

        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               SBEIO_FIFO,
                               SBEIO_FIFO_DOWNSTREAM_TIMEOUT,
                               MAX_UP_FIFO_TIMEOUT_NS,
                               TWO_UINT32_TO_UINT64(TARGETING::get_huid(i_target),
                                                    l_status));

        l_errl->setErrorType(SBEIO_ERROR_TYPE_HRESET_PERFORMED);
        l_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);

        // Keep a copy of the plid so we can pass it to the retry_handler
        // so the error logs it creates will be linked
        const uint32_t l_errPlid = ERRL_GETPLID_SAFE(l_errl);

        l_errl->collectTrace(SBEIO_COMP_NAME);
        collectRegFFDC(i_target,l_errl);

        // Commit error log now if this is a FSP system because
        // we will not return from retry handler (for processor chips)
        if (i_target->getAttr<ATTR_TYPE>() == TYPE_PROC
            && INITSERVICE::spBaseServicesEnabled())
        {
            l_errl->addHwCallout(i_target,
                                 HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );
            ERRORLOG::errlCommit( l_errl, SBEIO_COMP_ID );
        }
        //On BMC systems we want to deconfigure the chip
        else
        {
            l_errl->addHwCallout(i_target,
                                 HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::DELAYED_DECONFIG,
                                 HWAS::GARD_NULL );
        }

        const auto l_SBEobj
            = make_sbe_retry_handler(i_target,
                                     SbeRetryHandler::SBE_MODE_OF_OPERATION::INFORMATIONAL_ONLY,
                                     SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                                     l_errPlid,
                                     NOT_INITIAL_POWERON);

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
            ATTR_FSI_MASTER_TYPE_type fsi_type = { };
            if (i_target->tryGetAttr<ATTR_FSI_MASTER_TYPE>(fsi_type)
                && fsi_type != FSI_MASTER_TYPE_NO_MASTER)
            {
                l_switches.useSbeScom = 0;
                l_switches.useFsiScom = 1;
            }

            i_target->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
        }

        // Since the retry handler's mode was set to "informational"
        // in the constructor above, this will run *_extract_sbe_rc
        // then, for proc chips, TI the system on fsp-systems. It may
        // collect a dump and/or do an HRESET where applicable.
        l_SBEobj->main_sbe_handler(l_errl);

    return l_errl;
}

/**
 * @brief  Wait for data in downstream fifo to receive, hit EOT, or timeout.
 *         Add each entry to the RespBuffer and do the RespBuffer
 *         completeMessage upon receiving EOT.
 *
 */
errlHndl_t SbeFifo::waitDnFifoReady(TARGETING::Target   *i_target,
                               SBEIO::SbeFifoRespBuffer &o_fifoBuffer,
                                               bool     &o_EOT)
{
    errlHndl_t l_errl = NULL;
    bool       l_EMPTY{};
    uint32_t   l_data{};
    uint32_t   l_status{};

    SBE_TRACU(ENTER_MRK "waitDnFifoReady");

    bool timeout = hbstd::with_timeout(0, MAX_DWN_FIFO_TIMEOUT_NS, 0, 10000, [&]()
    {
        // read and parse the FIFO data
        l_errl = parseDataOutReg(i_target, l_data, l_status, l_EMPTY, o_EOT);
        if (l_errl) {return hbstd::timeout_t::STOP;}

        if (!l_EMPTY) {o_fifoBuffer.append(l_data);}
        if (o_EOT)    {o_fifoBuffer.completeMessage();}

        // if we received a new entry or an EOT, stop the FIFO receive loop
        if ((!l_EMPTY || o_EOT)) {return hbstd::timeout_t::STOP;}

        // else, continue waiting to receive data
        return hbstd::timeout_t::CONTINUE;
    });

    CI_INJECT_FIFO_BREAKAGE(CxxTest::g_cxxTestInject,
                            i_target,
                            CxxTest::SBEIO_INJECT_FIFO_BREAKAGE,
                            timeout,
                            "waitDnFifoReady: INJECT_FIFO_BREAKAGE");

    if (timeout && !l_errl) // timeout already implies !l_errl, but we check anyway
    {
        SBE_TRACF(ERR_MRK "waitDnFifoReady: "
                  "timeout waiting for downstream FIFO ENTRY or EOT");

        l_errl = dnFifoTimeout(i_target, l_status);
    }

    SBE_TRACU(EXIT_MRK "waitDnFifoReady(0x%08X) = 0x%08X",
              get_huid(i_target),
              ERRL_GETEID_SAFE(l_errl));

    return l_errl;
}

/**
 * @brief get the register addr from the enum index
 */
uint32_t SbeFifo::getSbeFifoRegValue(fifoRegAddr i_reg)
{
    uint32_t l_addr{};

    switch(i_reg)
    {
        case FIFO_UPFIFO_DATA_IN:   l_addr = 0x00002420; break;
        case FIFO_UPFIFO_STATUS:    l_addr = 0x00002421; break;
        case FIFO_UPFIFO_SIG_EOT:   l_addr = 0x00002422; break;
        case FIFO_UPFIFO_REQ_RESET: l_addr = 0x00002423; break;
        case FIFO_DNFIFO_DATA_OUT:  l_addr = 0x00002430; break;
        case FIFO_DNFIFO_STATUS:    l_addr = 0x00002431; break;
        case FIFO_DNFIFO_RESET:     l_addr = 0x00002434; break;
        case FIFO_DNFIFO_ACK_EOT:   l_addr = 0x00002435; break;
        case FIFO_DNFIFO_MAX_TSFR:  l_addr = 0x00002436; break;
    }
    return l_addr;
}

/**
 * @brief get the register addr from the enum index
 */
uint32_t SbeFifo::getSppeFifoRegValue(fifoRegAddr i_reg)
{
    uint32_t l_addr{};

    switch(i_reg)
    {
        case FIFO_UPFIFO_DATA_IN:   l_addr = 0x00002400; break;
        case FIFO_UPFIFO_STATUS:    l_addr = 0x00002401; break;
        case FIFO_UPFIFO_SIG_EOT:   l_addr = 0x00002402; break;
        case FIFO_UPFIFO_REQ_RESET: l_addr = 0x00002403; break;
        case FIFO_DNFIFO_DATA_OUT:  l_addr = 0x00002410; break;
        case FIFO_DNFIFO_STATUS:    l_addr = 0x00002411; break;
        case FIFO_DNFIFO_RESET:     l_addr = 0x00002414; break;
        case FIFO_DNFIFO_ACK_EOT:   l_addr = 0x00002415; break;
        case FIFO_DNFIFO_MAX_TSFR:  l_addr = 0x00002416; break;
    }
    return l_addr;
}

/**
 * @brief get the register addr from the enum index
 */
uint32_t SbeFifo::getPipeFifoRegValue(fifoRegAddr i_reg)
{
    uint32_t l_addr{};

    switch(i_reg)
    {
        case FIFO_UPFIFO_DATA_IN:   l_addr = 0x000B0110; break;
        case FIFO_UPFIFO_STATUS:    l_addr = 0x000B0101; break;
        case FIFO_UPFIFO_SIG_EOT:   l_addr = 0x000B0112; break;
        case FIFO_UPFIFO_REQ_RESET: l_addr = 0x000B0113; break;
        case FIFO_DNFIFO_DATA_OUT:  l_addr = 0x000B0200; break;
        case FIFO_DNFIFO_STATUS:    l_addr = 0x000B0201; break;
        case FIFO_DNFIFO_RESET:     l_addr = 0x000B0204; break;
        case FIFO_DNFIFO_ACK_EOT:   l_addr = 0x000B0204; break;
        case FIFO_DNFIFO_MAX_TSFR:  assert(0);           break;
    }
    return l_addr;
}

/**
 * @brief get the register addr from the enum index
 */
uint32_t SbeFifo::getFifoRegValue(fifoRegType i_type, fifoRegAddr i_reg)
{
    uint32_t l_addr{};

    switch (i_type)
    {
        case FIFO_SBE:  l_addr = getSbeFifoRegValue(i_reg);  break;
        case FIFO_SPPE: l_addr = getSppeFifoRegValue(i_reg); break;
        case FIFO_PIPE: l_addr = getPipeFifoRegValue(i_reg); break;
    }
    return l_addr;
}

/**
 * @brief read FIFO register
 */
errlHndl_t SbeFifo::readFifoReg64(TARGETING::Target   *i_target,
                                           fifoRegAddr i_addrIdx,
                                             uint64_t *o_pData)
{
    size_t     l_64bitSize = sizeof(uint64_t);
    errlHndl_t l_errl      = NULL;
    uint32_t   l_addr{};

    l_addr = getFifoRegValue(FIFO_PIPE, i_addrIdx);
    l_errl = deviceOp(DeviceFW::READ,
                      i_target,
                      o_pData,
                      l_64bitSize,
                      DEVICE_SCOM_ADDRESS(l_addr));

    SBE_TRACU("  readFifoReg64 PIPE addr=0x%08lx data=0x%016llx", l_addr, *o_pData);
    if (l_errl) {SBE_TRACD(ERR_MRK "readFifoReg64");}
    return l_errl;
}

/**
 * @brief read FIFO register
 */
errlHndl_t SbeFifo::readFifoReg(TARGETING::Target     *i_target,
                                           fifoRegAddr i_addrIdx,
                                           uint32_t   *o_pData,
                                           ffdcRegMetadata_t* o_meta)
{
    size_t     l_32bitSize = sizeof(uint32_t);
    errlHndl_t l_errl      = NULL;
    uint32_t   l_addr{};

    if (TARGETING::UTIL::isOdysseyChip(i_target))
    {
        // Odyssey

        if (i_target->getAttr<TARGETING::ATTR_USE_PIPE_FIFO>())
        {
            uint64_t l_data;
            l_errl = readFifoReg64(i_target, i_addrIdx, &l_data);
            *o_pData = l_data>>32;
            if( o_meta )
            {
                o_meta->type = DeviceFW::SCOM;
                o_meta->addr = getPipeFifoRegValue(i_addrIdx);
            }
        }
        else
        {
            // SPPE CFAM FIFO
            l_addr = getFifoRegValue(FIFO_SPPE, i_addrIdx);
            l_errl = deviceOp(DeviceFW::READ,
                              i_target,
                              o_pData,
                              l_32bitSize,
                              DEVICE_CFAM_ADDRESS(l_addr));
            SBE_TRACU("  readFifoReg   SPPE addr=0x%08lx data=0x%08x", l_addr,*o_pData);
            if( o_meta )
            {
                o_meta->type = DeviceFW::CFAM;
                o_meta->addr = l_addr;
            }
        }
    }
    else
    {
        // SBE CFAM FIFO
        l_addr = getFifoRegValue(FIFO_SBE, i_addrIdx);
        l_errl = deviceOp(DeviceFW::READ,
                          i_target,
                          o_pData,
                          l_32bitSize,
                          DEVICE_CFAM_ADDRESS(l_addr));
        SBE_TRACU("  readFifoReg   SBE addr=0x%08lx data=0x%08x", l_addr,*o_pData);
        if( o_meta )
        {
            o_meta->type = DeviceFW::CFAM;
            o_meta->addr = l_addr;
        }
    }

    if (l_errl) {SBE_TRACD(ERR_MRK "readFifoReg");}
    return l_errl;
}

/**
 * @brief Odyssey Reset Write FIFO register
 */
errlHndl_t SbeFifo::OdyResetWriteFifoReg(TARGETING::Target *i_target,
                                                fifoRegAddr i_addrIdx,
                                                uint32_t   *i_pData)
{
    size_t     l_32bitSize = sizeof(uint32_t);
    errlHndl_t l_errl      = NULL;
    uint32_t   l_addr{};

    // Save only the useInbandScom to restore, we do not save the pipe setting since it could
    // have been turned off due to an error, if the useInbandScom switch is on, use it to
    // restore the pipe setting
    TARGETING::ScomSwitches l_switches = i_target->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
    bool l_inband = l_switches.useInbandScom;
    SBE_TRACF(ENTER_MRK"OdyResetWriteFifoReg HUID=0x%X l_switches.useInbandScom=0x%X "
                       "l_switches.useSbeScom=0x%X",
                        get_huid(i_target), l_switches.useInbandScom,
                        l_switches.useSbeScom);

    // Prepare for SPPE CFAM FIFO reset, caller has grabbed appropriate locks
    i_target->setAttr<TARGETING::ATTR_USE_PIPE_FIFO>(0);
    l_switches.useInbandScom = 0;
    i_target->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);

    // Applying reset function to upstream and downstream FIFO
    l_addr = getFifoRegValue(FIFO_SPPE, FIFO_DNFIFO_RESET); // 0x00002414, CFAM addr

    l_errl = deviceOp(DeviceFW::WRITE,
                      i_target,
                      i_pData,
                      l_32bitSize,
                      DEVICE_CFAM_ADDRESS(l_addr));

    if (l_errl)
    {
        SBE_TRACF("OdyResetWriteFifoReg SPPE CFAM FIFO HUID=0x%X ERRL=0x%X (committing)",
                  get_huid(i_target), ERRL_GETEID_SAFE(l_errl));
        ERRORLOG::errlCommit(l_errl, SBEIO_COMP_ID);
    }

    l_switches.useSbeScom = 1;
    i_target->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);

    // scom data and addrs must be 64-bit
    size_t   l_64bitSize = sizeof(uint64_t);
    uint64_t l_data = *i_pData;
    l_data <<= 32;

    // Prepare for SPPE CFAM PIPE FIFO reset, caller has grabbed appropriate locks
    //     0x000B0204, SCOM addr, PIPE2_upfifo_reset
    l_addr = getFifoRegValue(FIFO_PIPE, FIFO_DNFIFO_RESET);
    l_errl = deviceOp(DeviceFW::WRITE,
                      i_target,
                      &l_data,
                      l_64bitSize,
                      DEVICE_SCOM_ADDRESS(l_addr));
    if (l_errl)
    {
        SBE_TRACF("OdyResetWriteFifoReg CFAM PIPE FIFO HUID=0x%X ERRL=0x%X (committing)",
                  get_huid(i_target), ERRL_GETEID_SAFE(l_errl));
        ERRORLOG::errlCommit(l_errl, SBEIO_COMP_ID);
    }

    // Restore based on the saved useInbandScom
    // set to l_inband value, we could have come in with USE_PIPE_FIFO=0
    i_target->setAttr<TARGETING::ATTR_USE_PIPE_FIFO>(l_inband);
    l_switches.useInbandScom = l_inband;
    if (l_inband)
    {
        l_switches.useSbeScom=0;
    }
    i_target->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);

    if (l_errl) {SBE_TRACF(ERR_MRK "OdyResetWriteFifoReg");}
    SBE_TRACF(EXIT_MRK"OdyResetWriteFifoReg HUID=0x%X l_switches.useInbandScom=0x%X "
                      "l_switches.useSbeScom=0x%X USE_PIPE_FIFO=0x%X",
                       get_huid(i_target), l_switches.useInbandScom,
                       l_switches.useSbeScom, l_inband);
    return l_errl;
}

/**
 * @brief write FIFO register
 */
errlHndl_t SbeFifo::writeFifoReg(TARGETING::Target     *i_target,
                                            fifoRegAddr i_addrIdx,
                                            uint32_t   *i_pData)
{
    size_t     l_32bitSize = sizeof(uint32_t);
    errlHndl_t l_errl      = NULL;
    uint32_t   l_addr{};

    if (TARGETING::UTIL::isOdysseyChip(i_target))
    {
        // Odyssey

        if (i_target->getAttr<TARGETING::ATTR_USE_PIPE_FIFO>())
        {
            // scom data and addrs must be 64-bit
            size_t   l_64bitSize = sizeof(uint64_t);
            uint64_t l_data = *i_pData;
            l_data <<= 32;
            l_addr = getFifoRegValue(FIFO_PIPE, i_addrIdx);
            SBE_TRACU("  writeFifoReg  PIPE addr=0x%08lx data=0x%08x", l_addr,*i_pData);
            l_errl = deviceOp(DeviceFW::WRITE,
                              i_target,
                              &l_data,
                              l_64bitSize,
                              DEVICE_SCOM_ADDRESS(l_addr));
        }
        else
        {
            // SPPE CFAM FIFO
            l_addr = getFifoRegValue(FIFO_SPPE, i_addrIdx);
            SBE_TRACU("  writeFifoReg  SPPE addr=0x%08lx data=0x%08x", l_addr,*i_pData);
            l_errl = deviceOp(DeviceFW::WRITE,
                              i_target,
                              i_pData,
                              l_32bitSize,
                              DEVICE_CFAM_ADDRESS(l_addr));
        }
    }
    else
    {
        // SBE CFAM FIFO
        l_addr = getFifoRegValue(FIFO_SBE, i_addrIdx);
        SBE_TRACU("  writeFifoReg  SBE  addr=0x%08lx data=0x%08x", l_addr,*i_pData);
        l_errl = deviceOp(DeviceFW::WRITE,
                          i_target,
                          i_pData,
                          l_32bitSize,
                          DEVICE_CFAM_ADDRESS(l_addr));
    }

    if (l_errl) {SBE_TRACD(ERR_MRK "writeFifoReg");}
    return l_errl;
}

/**
 * @brief Collect appropriate registers for FFDC.
 */
void SbeFifo::collectRegFFDC(TARGETING::Target * i_target,
                             errlHndl_t i_errhdl)
{
    errlHndl_t ignored = nullptr;
    ERRORLOG::ErrlUserDetailsLogRegister l_regs(i_target);

    // Add FIFO-specific regs
    const fifoRegAddr regs_to_read[] = {
        FIFO_UPFIFO_STATUS,
        FIFO_DNFIFO_STATUS,
    };

    for( auto reg : regs_to_read )
    {
        uint32_t l_data = 0;
        ffdcRegMetadata_t l_meta;
        ignored = readFifoReg(i_target, reg, &l_data, &l_meta);
        if( ignored )
        {
            delete ignored;
            ignored = nullptr;
            continue;
        }
        if( DeviceFW::CFAM == l_meta.type )
        {
            l_regs.addDataBuffer(reinterpret_cast<void *>(&l_data),
                                 sizeof(l_data),
                                 DEVICE_CFAM_ADDRESS(l_meta.addr));
        }
        else // SCOM, or unknown which we'll lie and choose scom
        {
            l_regs.addDataBuffer(reinterpret_cast<void *>(&l_data),
                                 sizeof(l_data),
                                 DEVICE_SCOM_ADDRESS(l_meta.addr));
        }
    }


    // Add SBE status regs
    const uint32_t cfam_to_read[] = {
        0x1007, //Status register
        0x2801, //CBS Control/Status register
        0x2808, //Selfboot Control/Status register
        0x2809, //Selfboot Message register
    };

    for( auto reg : cfam_to_read )
    {
        l_regs.addData(DEVICE_CFAM_ADDRESS(reg));
    }


    // Push the reg data into the original error log
    l_regs.addToLog(i_errhdl);
}

}; // namespace SBEIO
