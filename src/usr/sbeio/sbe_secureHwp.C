/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_secureHwp.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
* @file sbe_secureHwp.C
* @brief Send request to perform a HWP securely on SBE
*/

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <util/align.H>

#define  DEBUG_TRACE  0   // 0 = disable
extern trace_desc_t* g_trac_sbeio;

// -------------------------
// Structure definitions
// -------------------------

// Argument pointer lay-out
//   uint64_t i_address
//   uint32_t i_bytes,
//   uint8_t* i_data,
//   uint32_t i_mem_flags
struct argData_t
{
    uint32_t address_0;
    uint32_t address_1;
    uint32_t dataLen;
    uint64_t dataLoc;
    uint32_t flags;
} PACKED;

struct putSramData_t
{
    // Byte array has to be used here because compiler cannot properly
    // pack a fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
    uint8_t targ[sizeof(fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>)];
    uint32_t pervChipletId;
    bool     mcast;
    uint8_t  mode;
    uint64_t address;
    uint32_t dataLenBytes;
    uint64_t dataLoc;
} PACKED;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"secureHwp: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"secureHwp: " printf_string,##args)

namespace SBEIO
{
    /**
    * @brief Perform an SBE PutMem chip-op with arguments given from a
    *        "p9_putmemproc" secured function call.
    *
    * @param[in]  i_target   TARGETING::Target which the HWP is being called on
    * @param[in]  i_argPtr   Pointer to arguments of the HWP
    * @param[in]  i_argSize  Argument size in bytes
    *
    * @return errlHndl_t Error log handle on failure.
    */
    errlHndl_t putMemChipOpRequest(TARGETING::Target *i_target,
                                   const uint8_t* i_argPtr,
                                   const size_t i_argSize)
    {
        SBE_TRACD(ENTER_MRK "putMemChipOpRequest");
        errlHndl_t l_errl = nullptr;

        do
        {

#if DEBUG_TRACE
            for (uint32_t ii = 0; ii < i_argSize; ii++)
            {
               SBE_TRACF("putMemChipOpRequest - i_argPtr[%d] = 0x%.2X", ii, i_argPtr[ii]);
            }
#endif

            // Setup command
            SbeFifo::fifoPutMemRequest  l_fifoRequest;
            SbeFifo::fifoPutMemResponse l_fifoResponse;

            // Map input arg pointer into structure
            argData_t* l_argPtr = (argData_t*)i_argPtr;

            // Address bits 0:31
            l_fifoRequest.address[0] = l_argPtr->address_0;

            // Address bits 32:63
            l_fifoRequest.address[1] = l_argPtr->address_1;

            // Data length
            l_fifoRequest.dataLen = l_argPtr->dataLen;

            // Allocate memory for data
            l_fifoRequest.dataPtr =
                 reinterpret_cast<uint32_t *>(malloc(l_fifoRequest.dataLen));

            // Copy data from memory into allocated memory
            memcpy(l_fifoRequest.dataPtr,
                      reinterpret_cast<uint32_t *>(l_argPtr->dataLoc),
                      l_fifoRequest.dataLen);

            // Flag
            l_fifoRequest.flags = l_argPtr->flags;

            // Command length
            l_fifoRequest.wordCnt = SbeFifo::PUTMEM_CMD_BUF_LEN_IN_WORDS +
                                    (l_fifoRequest.dataLen / SbeFifo::BYTES_PER_WORD);
            if (l_fifoRequest.dataLen % SbeFifo::BYTES_PER_WORD)
            {
                l_fifoRequest.wordCnt += 1;
            }

            SBE_TRACF("INFO_MRK: Target: 0x%.8X, Address: 0x%.16llX, Datalen: %d, "
                      "Data[0]: 0x%.8X, Flags 0x%.4x, WordCnt: %d",
                      TARGETING::get_huid(i_target),
                      ((uint64_t)(l_fifoRequest.address[0]) << 32) | l_fifoRequest.address[1],
                      l_fifoRequest.dataLen,
                      *l_fifoRequest.dataPtr,
                      l_fifoRequest.flags,
                      l_fifoRequest.wordCnt);

            l_errl = SbeFifo::getTheInstance().performFifoChipOp(
                               i_target,
                               (uint32_t *)&l_fifoRequest,
                               (uint32_t *)&l_fifoResponse,
                               sizeof(l_fifoResponse));
            if (l_errl)
            {
                TRACFCOMP(g_trac_sbeio,
                        ERR_MRK"SBE Putmem chip-op ERROR : errorlog "
                        TRACE_ERR_FMT,
                        TRACE_ERR_ARGS(l_errl));
            }

            free(l_fifoRequest.dataPtr);

        } while(0);

        SBE_TRACD(EXIT_MRK "putMemChipOpRequest");

        return l_errl;
    }

    errlHndl_t sendPutSramOp(const uint8_t * i_argPtr,
                             const size_t i_argSize)
    {
        errlHndl_t l_errl = nullptr;

        SBE_TRACF(ENTER_MRK "sendPutSramOp");

        do
        {
#if DEBUG_TRACE
            for (uint32_t ii = 0; ii < i_argSize; ii++)
            {
                TRACFCOMP(g_trac_sbeio, "sendPutSramOp - i_argPtr[%d] = 0x%.2X", ii, i_argPtr[ii]);
            }
#endif

            // Map input arg pointer into structure
            const putSramData_t* l_argPtr =
                reinterpret_cast<const putSramData_t*>(i_argPtr);

            // Data length
            if (l_argPtr->dataLenBytes % 8 != 0)
            {
                TRACFCOMP(g_trac_sbeio, "sendPutSramOp - dataLenBytes needs to be multiple of 8 bytes");
            }
            const uint32_t originalDataSizeBytes = l_argPtr->dataLenBytes;
            const uint32_t alignedDataSizeBytes = ALIGN_8(l_argPtr->dataLenBytes);

            // Setup command
            SbeFifo::fifoPutSramRequest* l_fifoRequest =
                reinterpret_cast<SbeFifo::fifoPutSramRequest*>
                (malloc(sizeof(SbeFifo::fifoPutSramRequest) +
                        alignedDataSizeBytes));
            SbeFifo::fifoPutSramResponse l_fifoResponse;

            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapiTarget =
                *reinterpret_cast<const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>*>(&l_argPtr->targ[0]);
            TARGETING::Target * l_target = l_fapiTarget.get();

            // SBE chip-op interface requires address to be in lower 32 bits
            // Address bits 0:31
            l_fifoRequest->address[0] = 0;

            // Address bits 32:63
            l_fifoRequest->address[1] = l_argPtr->address >> 32;

            // Data size in bytes
            l_fifoRequest->dataLenBytes = alignedDataSizeBytes;

            // Mode
            l_fifoRequest->mode = l_argPtr->mode;

            // Perv chiplet ID
            l_fifoRequest->pervChipletId = l_argPtr->pervChipletId;

            // Multicast bit
            l_fifoRequest->mcast = l_argPtr->mcast;

            // Command
            l_fifoRequest->command = SbeFifo::SBE_FIFO_CMD_PUTSRAM;

            // Command Class
            l_fifoRequest->commandClass = SbeFifo::SBE_FIFO_CLASS_MEMORY_ACCESS;

            // Command length
            l_fifoRequest->wordCnt = SbeFifo::PUTSRAM_CMD_BUF_LEN_IN_WORDS +
                (alignedDataSizeBytes / SbeFifo::BYTES_PER_WORD);
            if (alignedDataSizeBytes % SbeFifo::BYTES_PER_WORD)
            {
                l_fifoRequest->wordCnt += 1;
            }

            // Copy over the SRAM data
            memcpy(l_fifoRequest->data,
                    reinterpret_cast<uint8_t*>(l_argPtr->dataLoc),
                    originalDataSizeBytes);

            // Clear out unused space after alignment
            if (alignedDataSizeBytes > originalDataSizeBytes)
            {
                memset(reinterpret_cast<uint8_t*>(l_fifoRequest->data) + originalDataSizeBytes,
                        0x00,
                        alignedDataSizeBytes - originalDataSizeBytes);
            }

            SBE_TRACF("INFO_MRK: Target: 0x%.8X, Address: 0x%.16llX, Datalen: %d, "
                    "Data[0]: 0x%.8X, Mode 0x%.4x, WordCnt: %d,"
                    "PervChipletId: %d, Mcast: %d",
                    TARGETING::get_huid(l_target),
                    (static_cast<uint64_t>(l_fifoRequest->address[0]) << 32) | l_fifoRequest->address[1],
                     l_fifoRequest->dataLenBytes,
                     *l_fifoRequest->data,
                     l_fifoRequest->mode,
                     l_fifoRequest->wordCnt,
                     l_fifoRequest->pervChipletId,
                     l_fifoRequest->mcast);

            l_errl = SbeFifo::getTheInstance().performFifoChipOp(
                l_target,
                reinterpret_cast<uint32_t *>(l_fifoRequest),
                reinterpret_cast<uint32_t *>(&l_fifoResponse),
                sizeof(l_fifoResponse));

            if (l_errl)
            {
                SBE_TRACF(ERR_MRK "sendPutSramOp returned error from performFifoChipOp");
            }

            free(l_fifoRequest);
            l_fifoRequest = nullptr;
        } while(0);

        SBE_TRACF(EXIT_MRK "sendPutSramOp");

        return l_errl;
    }

    /**
    * @brief Request the SBE to do a specific chip op
    *
    * @param[in] i_argPtr       Pointer to argument data for the request HWP
    *                           arguments for the requests HWP
    *
    * @param[in] i_argSize      Size of argument data for the requests HWP, in bytes
    *
    * @param[in] i_hwpName      Pointer to string of chars representing hwp name
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendSecureHwpRequest(uint8_t * i_argPtr,
                                    size_t i_argSize,
                                    const char * i_hwpName)
    {
        errlHndl_t errl = nullptr;
        do
        {
            SBE_TRACF(ENTER_MRK "sendSecureHwpRequest: HWP %s",
                      i_hwpName);

            // -----------------------------------------------
            // Identify HWP and call appropriate chip-op setup
            // -----------------------------------------------
            // HWP = test_hwp
            if (strcmp(i_hwpName, "test_hwp") == 0)
            {
            }

            // HWP = procedure_to_call
            // This procedure is called via error path test case.
            // Return an error so FAPI_PLAT_CALL_SUBROUTINE invokes
            // a local copy written for the test case.
            else if (strcmp(i_hwpName, "procedure_to_call") == 0)
            {
                SBE_TRACF(ERR_MRK "sendSecureHwpRequest: HWP %s not supported in SBE.", i_hwpName);
                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                SBEIO_FIFO,
                                                SBEIO_FIFO_INVALID_OPERATION,
                                                0,
                                                0,
                                                true /*SW error*/);
                errl->collectTrace(SBEIO_COMP_NAME);
                break;
            }
            // There is a special step for the p10_sbe_cache_contained hwp to
            // send a specific exit cache contained chip op
            else if (strcmp(i_hwpName, "p10_sbe_exit_cache_contained") == 0)
            {
                SBE_TRACF(INFO_MRK "sendSecureHwpRequest: HWP %s was called.", i_hwpName);
                //Send Exit Cache Containted Chip Op to the SBE
                errl = sendExitCacheContainedOp(i_argPtr, i_argSize);
                if (errl)
                {
                    SBE_TRACF(ERR_MRK "sendSecureHwpRequest: Error running %s.", i_hwpName);
                    break;
                }
            }
            else if (strcmp(i_hwpName, "p10_putsram") == 0)
            {
                SBE_TRACF(INFO_MRK "sendSecureHwpRequest: HWP %s was called.", i_hwpName);
                // Send putSram chip op to the SBE
                errl = sendPutSramOp(i_argPtr, i_argSize);
                if (errl)
                {
                    SBE_TRACF(ERR_MRK "sendSecureHwpRequest: Error running %s.", i_hwpName);
                    break;
                }
            }
            // HWP = unknown
            // Assert if HWP is not recognized, either a code bug or HWP needs
            // to be supported
            else
            {
                assert(false,"sendSecureHwpRequest: HWP name is not recognized: %s", i_hwpName);
            }

        }while(0);

        SBE_TRACD(EXIT_MRK "sendSecureHwpRequest");
        return errl;
    };

} //end namespace SBEIO
