/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_secureHwp.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>

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
                SBE_TRACF("ERR_MRK: SBE Putmem chip-op call returns an error.");
            }

            free(l_fifoRequest.dataPtr);

        } while(0);

        SBE_TRACD(EXIT_MRK "putMemChipOpRequest");

        return l_errl;
    }

    /**
    * @brief Request the SBE to do a specific chip op
    *
    * @param[in] i_target       The target of which the HWP is intended to be called on,
    *                           this must be the first param of the request HWP
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
    errlHndl_t sendSecureHwpRequest(TARGETING::Target * i_target,
                                    uint8_t * i_argPtr,
                                    size_t i_argSize,
                                    const char * i_hwpName)
    {
        errlHndl_t errl = nullptr;
        do
        {
            SBE_TRACF(ENTER_MRK "sendSecureHwpRequest: HWP %s, Target 0x%.8X",
                      i_hwpName, TARGETING::get_huid(i_target));

            // First we need to figure out if this is a proc, if it isn't
            // then we need to find its parent proccessor chip
            auto l_targType =  i_target->getAttr<TARGETING::ATTR_TYPE>();
            TARGETING::Target * l_proc;
            if(l_targType == TARGETING::TYPE_PROC)
            {
                l_proc = i_target;
            }
            else
            {
                l_proc = const_cast<TARGETING::Target *>(getParentChip(i_target));
            }

            // -----------------------------------------------
            // Identify HWP and call appropriate chip-op setup
            // -----------------------------------------------
            // HWP = p9_putmemproc
            if (strcmp(i_hwpName,"p9_putmemproc") == 0)
            {
                // Perform PutMem chip-op
                errl = putMemChipOpRequest(l_proc, i_argPtr, i_argSize);
                if (errl)
                {
                    break;
                }
            }

            // HWP = test_hwp
            else if (strcmp(i_hwpName, "test_hwp") == 0)
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
