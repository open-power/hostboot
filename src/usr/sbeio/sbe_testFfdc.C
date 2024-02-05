/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_testFfdc.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2024                        */
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
* @file sbe_testFfdc.C
* @brief Send request to cause SBE to return some FFDC
*/

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <targeting/odyutil.H>

extern trace_desc_t* g_trac_sbeio;


#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"testFfdc: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"testFfdc: " printf_string,##args)

namespace SBEIO
{

    /**
    * @brief  Sends the test FFDC request to the Odyssey SBE which will return FFDC packages mimicking a real error
    *         scenario. The caller specifies the kind of errors they would like to have returned. There is a limited
    *         number of implemented test return codes so the caller can only specify from that list. Anything else will
    *         not work. See generic/procedures/xml/error_info/test_sbe_ffdc.xml for the list of valid error return
    *         codes and sbe_fifodd.H for the various formats and other details the caller can supply to this chip-op.
    *
    * @param[in]  i_target   TARGETING::Target which the HWP is being called on. Must be an Odyssey chip
    * @param[in]  i_format   The response format the request should have.
    * @param[in]  i_numRecords  The number of error records the record pointer points to.
    * @param[in]  i_recordsPtr  The error records to send with the request.
    *
    * @return errlHndl_t Error log for SYNC test formats or an error on failure of chip-op execution
    */
    errlHndl_t sendTestFfdcRequest(TARGETING::Target * i_target,
                                   const SbeFifo::fifoTestFfdcResponseFormat i_format,
                                   const uint16_t i_numRecords,
                                   uint64_t * i_recordsPtr)
    {
        SBE_TRACD(ENTER_MRK "sendTestFfdcRequest");
        errlHndl_t l_errl = nullptr;

        do
        {
            if (not TARGETING::UTIL::isOdysseyChip(i_target))
            {
                SBE_TRACF("Unsupported target[0x%X], not executing chip-op!", TARGETING::get_huid(i_target));
                break;
            }

            // Setup command. The fifo response won't be returned to the caller since the response won't contain
            // any data the caller wouldn't already get back in the error log(s), if existing.
            SbeFifo::fifoTestFfdcRequest l_fifoRequest;
            SbeFifo::fifoStandardResponse l_fifoResponse;

            // Set number of error records
            l_fifoRequest.numErrorRecords = i_numRecords;

            // Full command length including the error records.
            l_fifoRequest.wordCnt = (sizeof(SbeFifo::fifoTestFfdcRequest)
                                  + (l_fifoRequest.numErrorRecords * sizeof(SbeFifo::fifoTestFfdcErrorRecord)))
                                      / SbeFifo::BYTES_PER_WORD;

            l_fifoRequest.responseFormat = i_format;

            uint8_t * l_request = reinterpret_cast<uint8_t *>(
                    malloc(l_fifoRequest.wordCnt * SbeFifo::BYTES_PER_WORD));

            // Copy data into allocated memory
            memcpy(l_request, &l_fifoRequest, sizeof(SbeFifo::fifoTestFfdcRequest));
            memcpy(l_request + sizeof(SbeFifo::fifoTestFfdcRequest),
                    i_recordsPtr,
                    i_numRecords * sizeof(SbeFifo::fifoTestFfdcErrorRecord));

            // The result of this chip-op varies depending on the given fifoTestFfdcResponseFormat. An error returned
            // from the operation should be expected in SYNC format types. Otherwise, the log could indicate the chip-op
            // itself failed. In any case, the caller is responsible for handling the potential log(s) returned from
            // this chip-op since this chip-op should only ever be called during unit tests and they would know what
            // they'd expect to get back.
            l_errl = SbeFifo::getTheInstance().performFifoChipOp(i_target,
                                                                 reinterpret_cast<uint32_t *>(l_request),
                                                                 reinterpret_cast<uint32_t *>(&l_fifoResponse),
                                                                 sizeof(l_fifoResponse));

            free(l_request);

        } while(0);

        SBE_TRACD(EXIT_MRK "sendTestFfdcRequest");

        return l_errl;
    }

} //end namespace SBEIO
