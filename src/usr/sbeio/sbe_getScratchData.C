/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_getScratchData.C $                          */
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
  * @file  sbe_getScratchData.C
  * @brief Contains the get SBE Scratch Data chipop for SBE FIFO
  *
  */

#include "sbe_fifodd.H"

#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include <sbeio/sbeioreasoncodes.H>
#include "sbe_fifo_buffer.H"

#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/odyutil.H>
#include <trace/interface.H>
#include <util/misc.H>
#include <algorithm>
#include <isteps/hwpisteperror.H>
#include <isteps/hwpThreadHelper.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"GenericMsg: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"GenericMsg: " printf_string,##args)

using namespace TARGETING;
using namespace ERRORLOG;

namespace SBEIO
{

    errlHndl_t sendPurgeScratchDataRequest(Target           * i_chipTarget,
                                           uint32_t         * o_pFifoResponse,
                                           const uint32_t   i_responseSize)
    {
        errlHndl_t errl = nullptr;

        do
        {
            if(Util::isSimicsRunning())
            {
                // The scratch data doesn't get logged in simics, so no need to clear it.
                break;
            }

            // Only support Odyssey OCMB targets.
            errl = sbeioOdysseyCheck(i_chipTarget,
                                     SbeFifo::SBE_FIFO_CLASS_GENERIC_MESSAGE,
                                     SbeFifo::SBE_FIFO_CMD_GET_SCRATCH_DATA);
            if(errl)
            {
                break;
            }

            SbeFifo::fifoGetSbeScratchDataRequest l_fifoRequest;
            l_fifoRequest.operation = SbeFifo::FIFO_PURGE_SCRATCH_DATA;

            errl = SbeFifo::getTheInstance().performFifoChipOp(i_chipTarget,
                                                               reinterpret_cast<uint32_t *>(&l_fifoRequest),
                                                               o_pFifoResponse,
                                                               i_responseSize);

        } while(0);

        SBE_TRACD(EXIT_MRK "sendPurgeScratchDataRequest");
        return errl;
    };

    errlHndl_t purgeAllSbeScratchData()
    {
        ISTEP_ERROR::IStepError l_istepError;

        ISTEP::parallel_for_each(composable(getAllChips)(TYPE_OCMB_CHIP, true/*functional*/),
                                 l_istepError,
                                 "purgeAllSbeScratchData",
                                 [&](Target* const i_ocmb) -> errlHndl_t
        {
            errlHndl_t l_errl = nullptr;
            if(!UTIL::isOdysseyChip(i_ocmb))
            {
                return l_errl;
            }

            // No scratch data is returned by the SBE if we request to purge, so
            // the standard response will work here.
            SBEIO::SbeFifo::fifoStandardResponse l_resp;
            uint32_t l_responseSize = sizeof(l_resp);
            l_errl = sendPurgeScratchDataRequest(i_ocmb,
                                                 reinterpret_cast<uint32_t*>(&l_resp),
                                                 l_responseSize);
            if(l_errl)
            {
                SBE_TRACF(ERR_MRK"sendPurgeScratchDataRequest failed");
                errlCommit(l_errl, SBEIO_COMP_ID);
            }

            return l_errl;
        });

        return l_istepError.getErrorHandle();
    }

    /**
     * @brief Retrieves data stored in the SBE Scratch area. Due to tight memory constraints, the SBE scratch area will
     *        always be cleared on successful execution of this command. The data in the scratch area is typically
     *        generated by hardware procedures running on the SBE.
     *
     * @param[in] i_chipTarget The chip you would like to perform the chipop on
     *                       NOTE: HB should only be sending this to Odyssey chips
     * @param[out]    o_pFifoResponse Pointer to response
     * @param[out]    o_actualSize the actual size of returned data
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t sendGetScratchDataRequest(Target                   * i_chipTarget,
                                         sbeScratchDataResponse_t & o_pFifoResponse,
                                         uint32_t                 & o_actualSize)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Only support Odyssey OCMB targets.
            errl = sbeioOdysseyCheck(i_chipTarget,
                                     SbeFifo::SBE_FIFO_CLASS_GENERIC_MESSAGE,
                                     SbeFifo::SBE_FIFO_CMD_GET_SCRATCH_DATA);
            if(errl)
            {
                break;
            }

            SbeFifo::fifoGetSbeScratchDataRequest l_fifoRequest;

            // The response from the chip-op is larger than Hostboot's stack size so the buffer needs to be allocated on
            // the heap. To ease the caller's responsibility we allocate a shared_ptr of the correct size and return it
            // to the caller.
            o_pFifoResponse = std::make_shared<std::array<uint32_t, MAX_SBE_SCRATCH_DATA_WORDS>>();
            // Use larger MSG_BUFFER_SIZE_WORDS_POZ for the check since this should only be called on Ody chips
            static_assert(MAX_SBE_SCRATCH_DATA_WORDS < SbeFifoRespBuffer::MSG_BUFFER_SIZE_WORDS_POZ,
                          "Not enough space return all SBE scratch data");
            static_assert((MAX_SBE_SCRATCH_DATA_WORDS * sizeof(uint32_t)) == (64 * KILOBYTE),
                          "Expected MAX_SBE_SCRATCH_DATA_WORDS to be 64k, consider current design.");
            errl = SbeFifo::getTheInstance().performFifoChipOp(i_chipTarget,
                                                               reinterpret_cast<uint32_t *>(&l_fifoRequest),
                                                               &(o_pFifoResponse->at(0)),
                                                               MAX_SBE_SCRATCH_DATA_WORDS,
                                                               o_actualSize);

        }while(0);

        SBE_TRACD(EXIT_MRK "sendGetScratchDataRequest");
        return errl;
    };

    void makeScratchDataErrls(Target* i_chipTarget,
                              std::vector<uint8_t>& i_scratchData,
                              errlHndl_t& o_errls)
    {
        /*@
         * @errortype
         * @moduleid SBEIO_ODY_READ_SCRATCH_DATA
         * @reasoncode SBEIO_ODY_SCRATCH_DATA
         * @userdata1 The Odyssey chip HUID
         * @userdata2 The total size of scratch data
         * @devdesc This error log (and those that are linked to
         *          this log) contains the Odyssey scratch data
         *          in its FFDC fields.
         * @custdesc Informational event
         */
        o_errls = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                SBEIO_ODY_READ_SCRATCH_DATA,
                                SBEIO_ODY_SCRATCH_DATA,
                                get_huid(i_chipTarget),
                                i_scratchData.size(),
                                ErrlEntry::NO_SW_CALLOUT);

        uint32_t l_maxErrlSize = 0;
        uint32_t l_currentErrlSize = 0;
        o_errls->getErrlSize(l_currentErrlSize, l_maxErrlSize);

        uint32_t l_scratchDataSize = i_scratchData.size();
        uint32_t l_sizeAddedToErrl = std::min(l_scratchDataSize, l_maxErrlSize - l_currentErrlSize);

        o_errls->addFFDC(SBEIO_COMP_ID,
                         i_scratchData.data(),
                         l_sizeAddedToErrl,
                         1, // Version
                         SBEIO_UDT_NO_FORMAT,
                         false, // Do not merge
                         // Do not propagate; the FFDC data needs to be unique per error log created here
                         propagation_t::NO_PROPAGATE);

        // Split the remaining data up between logs. We will put the max amount of
        // scratch data into each before creating more. The logs are linked via PLID
        // to the original log.
        if(l_sizeAddedToErrl < i_scratchData.size())
        {
            uint32_t l_remainingSizeToAdd = i_scratchData.size() - l_sizeAddedToErrl;
            uint8_t* l_dataToAddPtr = i_scratchData.data();
            while(l_remainingSizeToAdd > 0)
            {
                l_dataToAddPtr += l_sizeAddedToErrl;
                errlHndl_t l_secondaryErrl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                                           SBEIO_ODY_READ_SCRATCH_DATA,
                                                           SBEIO_ODY_SCRATCH_DATA,
                                                           get_huid(i_chipTarget),
                                                           i_scratchData.size(),
                                                           ErrlEntry::NO_SW_CALLOUT);

                l_secondaryErrl->getErrlSize(l_currentErrlSize, l_maxErrlSize);
                l_sizeAddedToErrl = std::min(l_remainingSizeToAdd, l_maxErrlSize - l_currentErrlSize);
                l_secondaryErrl->addFFDC(SBEIO_COMP_ID,
                                         l_dataToAddPtr,
                                         l_sizeAddedToErrl,
                                         1, // version
                                         SBEIO_UDT_NO_FORMAT,
                                         false, // Do not merge
                                         // Do not propagate; the FFDC data needs to be unique per error log created here
                                         propagation_t::NO_PROPAGATE);
                aggregate(o_errls, l_secondaryErrl, true /*update the PLID*/);
                l_remainingSizeToAdd -= l_sizeAddedToErrl;
            }
        }
    }

    errlHndl_t getAndProcessScratchData(Target* i_chipTarget, errlHndl_t& o_errls)
    {
        SBE_TRACF(ENTER_MRK"getAndProcessScratchData");
        errlHndl_t l_returnErrl = nullptr;
        std::vector<uint8_t>l_scratchData;
        uint32_t l_returnedDataSize = 0;

        sbeScratchDataResponse_t l_scratchDataResponse;

        if(Util::isSimicsRunning() ||
           !UTIL::isOdysseyChip(i_chipTarget))
        {
            // This is technically not an error; the Synopsys data doesn't get logged
            // in simics or on non-Odyssey chips.
            goto ERROR_EXIT;
        }

        l_returnErrl = sendGetScratchDataRequest(i_chipTarget,
                                                 l_scratchDataResponse,
                                                 l_returnedDataSize);
        if(l_returnErrl)
        {
            goto ERROR_EXIT;
        }

        // Grab only the relevant data out of the respose;
        // Skip the standard response header, the distance to 0xC0DE,
        // and the EOT flag that are attached at the end of the data we're
        // interested in.
        l_returnedDataSize = l_returnedDataSize -
                             sizeof(SbeFifo::statusHeader) -
                             sizeof(uint32_t) - // distance to 0xC0DE magic word
                             sizeof(uint32_t);  // EOT flag
        l_scratchData.resize(l_returnedDataSize);
        memcpy(l_scratchData.data(), l_scratchDataResponse.get(), l_returnedDataSize);
        makeScratchDataErrls(i_chipTarget, l_scratchData, o_errls);

        ERROR_EXIT:
        SBE_TRACF(EXIT_MRK"getAndProcessScratchData");
        return l_returnErrl;
    }

};
