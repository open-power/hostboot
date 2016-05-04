/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_fifodd.C $                                  */
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
#include "sbe_fifodd.H"

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"fifodd: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"fifodd: " printf_string,##args)
#define SBE_TRACU(args...)
/* replace for unit testing
#define SBE_TRACU(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"fifodd: " printf_string,##args)
*/

using namespace ERRORLOG;

//TODO RTC 149454 implement error recovery and ffdc

namespace SBEIO
{

/**
 * @brief perform SBE PSU chip-op
 */
errlHndl_t performFifoChipOp(TARGETING::Target * i_target,
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
 * @brief write FIFO request message
 */
errlHndl_t writeRequest(TARGETING::Target * i_target,
                        uint32_t * i_pFifoRequest)
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "writeRequest");

    do
    {
        //The first uint32_t has the number of uint32_t words in the request
        uint32_t * l_pSent    = i_pFifoRequest; //advance as words sent
        uint64_t   l_addr     = SBE_FIFO_UPFIFO_DATA_IN;
        uint32_t   l_cnt      = *l_pSent;
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
        uint32_t l_data = FSB_UPFIFO_SIG_EOT;
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
errlHndl_t waitUpFifoReady(TARGETING::Target * i_target)
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

            //TODO RTC 149454 implement error recovery and ffdc
            // Consider a new callout for SBE problems.

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
errlHndl_t readResponse(TARGETING::Target * i_target,
                        uint32_t * i_pFifoRequest,
                        uint32_t * o_pFifoResponse,
                        uint32_t   i_responseSize)
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "readResponse");

    do
    {
        // EOT is expected before the response buffer is full. Room for
        // the PCBPIB status or FFDC is included, but is only returned
        // if there is an error. The last received word has the distance
        // to the status, which is placed at the end of the returned data
        // in order to reflect errors during transfer.

        uint32_t * l_pReceived = o_pFifoResponse; //advance as words received
        uint32_t   l_maxWords  =  i_responseSize / sizeof(uint32_t);
                                    //Number of words in response buffer.
        uint32_t   l_recWords  = 0; //Number of words received.
                                    //Used validate "distance" to status
                                    //and pointer to status.
        bool       l_EOT      = false;
        uint32_t   l_last     = 0; // last word received. The "current" word.
                                   // Final read is "distance" in words to
                                   // status header including the final
                                   // distance word.
        // receive words until EOT, but do not exceed response buffer size
        do
        {
            // Wait for data to be ready to receive (download) or if the EOT
            // has been sent. If not EOT, then data ready to receive.
            uint32_t l_status = 0;
            errl = waitDnFifoReady(i_target,l_status);
            if ( l_status & DNFIFO_STATUS_DEQUEUED_EOT_FLAG)
            {
                l_EOT = true;
                // ignore EOT dummy word
                if (l_recWords >= (sizeof(statusHeader)/sizeof(uint32_t)) )
                {
                    l_pReceived--;
                    l_recWords--;
                    l_last = o_pFifoResponse[l_recWords-1];
                }
                break;
            }

            // Make sure response buffer not over run.
            if (l_recWords >= l_maxWords)
            {
                break; //ran out of receive buffer before EOT
            }

            // read next word
            errl = readFsi(i_target,SBE_FIFO_DNFIFO_DATA_OUT,&l_last);
            if (errl) break;

            *l_pReceived = l_last; //copy to returned output buffer
            l_pReceived++; //advance to next position
            l_recWords++;  //count word received
        }
        while (1); // exit check in middle of loop
        if (errl) break;

        // At this point,
        // l_recWords of words received.
        // l_pReceived points to 1 word past last word received.
        // l_last has last word received, which is "distance" to status

        // EOT is expected before running out of response buffer
        if (!l_EOT)
        {
            SBE_TRACF(ERR_MRK "readResponse: no EOT cmd=0x%08x size=%d",
                      i_pFifoRequest[1],i_responseSize);

            //TODO RTC 149454 implement error recovery and ffdc
            // Consider a new callout for SBE problems.

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
        //Last word received has distance to status in words including itself.
        //l_recWords has number of words received.
        //Need to have received at least status header and distance word.
        if ( (l_last      < (sizeof(statusHeader)/sizeof(uint32_t) + 1)) ||
             (l_recWords  < (sizeof(statusHeader)/sizeof(uint32_t) + 1)) ||
             (l_last      > (l_recWords)) )
        {
            SBE_TRACF(ERR_MRK "readResponse: invalid status distance "
                      " cmd=0x%08x distance=%d response size=%d",
                      i_pFifoRequest[1],
                      l_last,
                      i_responseSize);

            //TODO RTC 149454 implement error recovery and ffdc
            // Consider a new callout for SBE problems.

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
                                    TWO_UINT16_TO_UINT32(l_last,
                                         l_recWords*sizeof(uint32_t)),
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
        // l_pReceived points one word past last word received.
        // l_last has number of words to status header including self.
        uint32_t * l_pStatusTmp = l_pReceived - l_last; //do word ptr math
        statusHeader * l_pStatusHeader = (statusHeader *)l_pStatusTmp;
        if ((FIFO_STATUS_MAGIC != l_pStatusHeader->magic) ||
            (FIFO_PRI_OPERATION_SUCCESSFUL != l_pStatusHeader->primaryStatus) ||
            (FIFO_SEC_OPERATION_SUCCESSFUL != l_pStatusHeader->secondaryStatus))
        {
            SBE_TRACF(ERR_MRK "readResponse: failing downstream status "
                      " cmd=0x%08x magic=0x%08x prim=0x%08x secondary=0x%08x",
                      i_pFifoRequest[1],
                      l_pStatusHeader->magic,
                      l_pStatusHeader->primaryStatus,
                      l_pStatusHeader->secondaryStatus);

            //TODO RTC 149454 implement error recovery and ffdc
            // pibpcb status or ffdc follows the status header
            // Might have different behavior for something messed up
            // like !Magic versus bad status returned by the SBE in which
            // case may be able to parse SBE RCs.

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
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->addHwCallout(  i_target,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );
            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }
    }
    while (0);

    SBE_TRACD(EXIT_MRK "readResponse");

    return errl;
}

/**
 * @brief wait for data in downstream fifo to receive
 *        or hit EOT.
 *
 *        On return, either a valid word is ready to read,
 *        or the EOT will be set in the returned doorbell status.
 */
errlHndl_t waitDnFifoReady(TARGETING::Target * i_target,
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

        if ( !(o_status & DNFIFO_STATUS_FIFO_EMPTY) ||
              (o_status & DNFIFO_STATUS_DEQUEUED_EOT_FLAG) )
        {
            break;
        }

        // time out if wait too long
        if (l_elapsed_time_ns >= MAX_UP_FIFO_TIMEOUT_NS )
        {
            SBE_TRACF(ERR_MRK "waitDnFifoReady: "
                      "timeout waiting for downstream FIFO to be not full");

            //TODO RTC 149454 implement error recovery and ffdc

            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_DOWNSTREAM_TIMEOUT
             * @userdata1    Timeout in NS
             * @devdesc      Timeout waiting for downstream FIFO to have
             *               data to receive
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 SBEIO_FIFO,
                                 SBEIO_FIFO_DOWNSTREAM_TIMEOUT,
                                 MAX_UP_FIFO_TIMEOUT_NS,
                                 0);
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->addHwCallout(  i_target,
                                 HWAS::SRCI_PRIORITY_HIGH,
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

    SBE_TRACD(EXIT_MRK "waitDnFifoReady");

    return errl;
}

/**
 * @brief read FSI
 */
errlHndl_t readFsi(TARGETING::Target * i_target,
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
errlHndl_t writeFsi(TARGETING::Target * i_target,
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

} //end of namespace SBEIO
