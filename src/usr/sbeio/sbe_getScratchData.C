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

        SBE_TRACF(ENTER_MRK "sendPurgeScratchDataRequest for Target 0x%08X", get_huid(i_chipTarget));

        SbeFifo::fifoGetSbeScratchDataRequest l_fifoRequest;
        uint32_t                             *l_req{reinterpret_cast<uint32_t*>(&l_fifoRequest)};

        l_fifoRequest.operation = SbeFifo::FIFO_PURGE_SCRATCH_DATA;

        errl = SbeFifo::getTheInstance().performFifoChipOp(i_chipTarget,
                                                           l_req,
                                                           o_pFifoResponse,
                                                           i_responseSize);

        // Regardless if there is an error, set the attribute to prevent getting the scratch
        // data again.  The data gets purged on any read, so any subsequent read/purge will fail
        i_chipTarget->setAttr<ATTR_COLLECT_SBE_SCRATCH_DATA>(0);

        } while(0);

        SBE_TRACF(EXIT_MRK "sendPurgeScratchDataRequest for Target 0x%08X", get_huid(i_chipTarget));
        return errl;
    };

    errlHndl_t purgeAllSbeScratchData()
    {
        ISTEP_ERROR::IStepError l_istepError;

#ifndef __HOSTBOOT_RUNTIME
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

            // If the scratch data was already read or purged, a subsequent purge will fail as the
            // initial scratch data read or purge will have already purged the data.
            uint8_t l_collect_sbe_scratch_data = i_ocmb->getAttr<ATTR_COLLECT_SBE_SCRATCH_DATA>();
            if (l_collect_sbe_scratch_data == 0)
            {
                SBE_TRACF(INFO_MRK "purgeAllSbeScratchData: skipped purge for Target 0x%08X since data already collected (0x%X)",
                          get_huid(i_ocmb), l_collect_sbe_scratch_data);
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
                SBE_TRACF(ERR_MRK"purgeAllSbeScratchData: sendPurgeScratchDataRequest failed for Target 0X%X",
                          get_huid(i_ocmb));
                errlCommit(l_errl, SBEIO_COMP_ID);
            }

            return l_errl;
        });
#endif

        return l_istepError.getErrorHandle();
    }

    errlHndl_t sendGetScratchDataRequest(Target              * i_chipTarget,
                                           SbeFifoRespBuffer & o_pFifoResponse)
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

        SBE_TRACF(ENTER_MRK "sendGetScratchDataRequest for Target 0x%08X", get_huid(i_chipTarget));

        SbeFifo::fifoGetSbeScratchDataRequest l_fifoRequest;
        memory_stream l_stream { &l_fifoRequest,
                                  l_fifoRequest.wordCnt * sizeof(uint32_t) };

        errl = SbeFifo::getTheInstance().performFifoChipOp(i_chipTarget,
                                                           std::move(l_stream),
                                                           o_pFifoResponse,
                                                           true);

        // Regardless if there is an error, set the attribute to prevent getting the scratch
        // data again.  The data gets purged on any read, so any subsequent read/purge will fail
        i_chipTarget->setAttr<ATTR_COLLECT_SBE_SCRATCH_DATA>(0);

        }while(0);

        SBE_TRACF(EXIT_MRK "sendGetScratchDataRequest for Target 0x%08X", get_huid(i_chipTarget));
        return errl;
    };

    void makeScratchDataErrls(Target            * i_target,
                              SbeFifoRespBuffer & i_scratch_buf,
                              errlHndl_t        & o_errls)
    {
        /*@
         * @errortype
         * @moduleid SBEIO_ODY_READ_SCRATCH_DATA
         * @reasoncode SBEIO_ODY_SCRATCH_DATA
         * @userdata1 The Odyssey chip HUID
         * @userdata2 The remaining size of scratch data | total size of scratch data
         * @devdesc This error log (and those that are linked to
         *          this log) contains the Odyssey scratch data
         *          in its FFDC fields.
         * @custdesc Informational event
         */
        o_errls = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                SBEIO_ODY_READ_SCRATCH_DATA,
                                SBEIO_ODY_SCRATCH_DATA,
                                get_huid(i_target),
                                i_scratch_buf.getReturnDataByteSize(),
                                ErrlEntry::NO_SW_CALLOUT);

        std::vector<uint8_t> l_vec;                 // buf for call to addFFDC
        size_t               l_scratch_idx{0};      // indx into i_scratch_buf
        uint32_t             l_max_errl_size{0};    // max size that fits in the errl
        uint32_t             l_cur_errl_size{0};    // current size of data in errl
        uint64_t             l_tot_scratch_size{0}; // size of scratch data
        uint32_t             l_rem_scratch_size{0}; // size of scratch data remaining to add
        uint32_t             l_add_ffdc_size{0};    // size to add for next addFFDC
        uint64_t             l_userdata2{0};

        // fill the remaining space in the primary log with some scratch data

        o_errls->getErrlSize(l_cur_errl_size, l_max_errl_size);
        // add a 1k buffer to the max errl size, to prevent an overflow
        // at errl commit time, which would purge some FFDC data
        l_max_errl_size -= 1024; // leave extra room for commit data

        l_tot_scratch_size = i_scratch_buf.getReturnDataByteSize();
        l_rem_scratch_size = l_tot_scratch_size;
        l_add_ffdc_size    = std::min(l_rem_scratch_size,
                                      l_max_errl_size - l_cur_errl_size);
        l_vec.resize(l_add_ffdc_size);
        i_scratch_buf.memcpy(l_vec.data(), l_scratch_idx, l_add_ffdc_size);
        l_scratch_idx      += l_add_ffdc_size;
        l_rem_scratch_size -= l_add_ffdc_size;

        o_errls->addFFDC(SBEIO_COMP_ID,
                         l_vec.data(),
                         l_add_ffdc_size,
                         1, // Version
                         SBEIO_UDT_SCRATCH_DATA,
                         false, // Do not merge
                         // Do not propagate; the FFDC data needs to be unique per error log created here
                         propagation_t::NO_PROPAGATE);

        l_userdata2 = ((uint64_t)l_rem_scratch_size) << 32 | l_tot_scratch_size;
        o_errls->addUserData2( l_userdata2 );

        // Split the remaining data up between logs. Put the max amount of
        // scratch data into each before creating more. The logs are linked via PLID
        // to the original log.
        while (l_rem_scratch_size)
        {
            errlHndl_t l_secondaryErrl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                                       SBEIO_ODY_READ_SCRATCH_DATA,
                                                       SBEIO_ODY_SCRATCH_DATA,
                                                       get_huid(i_target),
                                                       i_scratch_buf.getReturnDataByteSize(),
                                                       ErrlEntry::NO_SW_CALLOUT);

            l_secondaryErrl->getErrlSize(l_cur_errl_size, l_max_errl_size);
            // add a 1k buffer to the max errl size, to prevent an overflow
            // at errl commit time, which would purge some FFDC data
            l_max_errl_size -= 1024; // leave extra room for commit data

            l_add_ffdc_size = std::min(l_rem_scratch_size,
                                       l_max_errl_size - l_cur_errl_size);
            l_vec.resize(l_add_ffdc_size);
            i_scratch_buf.memcpy(l_vec.data(), l_scratch_idx, l_add_ffdc_size);
            l_scratch_idx      += l_add_ffdc_size;
            l_rem_scratch_size -= l_add_ffdc_size;

            l_secondaryErrl->addFFDC(SBEIO_COMP_ID,
                                     l_vec.data(),
                                     l_add_ffdc_size,
                                     1, // version
                                     SBEIO_UDT_SCRATCH_DATA,
                                     false, // Do not merge
                                     // Do not propagate; the FFDC data needs
                                     // to be unique per error log created here
                                     propagation_t::NO_PROPAGATE);

            l_userdata2 = ((uint64_t)l_rem_scratch_size) << 32 | l_tot_scratch_size;
            l_secondaryErrl->addUserData2( l_userdata2 );

            aggregate(o_errls, l_secondaryErrl, true /*update the PLID*/);
        }
        return;
    }

    errlHndl_t getAndProcessScratchData(Target* i_chipTarget, errlHndl_t& o_errls)
    {
        SBE_TRACF(ENTER_MRK"getAndProcessScratchData: Target 0x%08X", get_huid(i_chipTarget));

        SbeFifoRespBuffer l_scratchDataResponse;
        errlHndl_t        l_returnErrl{nullptr};
        uint8_t           l_collect_sbe_scratch_data{0};

        if (Util::isSimicsRunning() ||
           !UTIL::isOdysseyChip(i_chipTarget))
        {
            // This is technically not an error; the Synopsys data doesn't get logged
            // in simics or on non-Odyssey chips.
            goto EXIT;
        }

        // If the scratch data was already read or purged, a subsequent read will fail as the
        // initial scratch data read or purge will have already purged the data.
        l_collect_sbe_scratch_data = i_chipTarget->getAttr<ATTR_COLLECT_SBE_SCRATCH_DATA>();
        if (l_collect_sbe_scratch_data == 0)
        {
            SBE_TRACF(INFO_MRK "getAndProcessScratchData: skipped for Target 0x%08X since data already collected (0x%X)",
                      get_huid(i_chipTarget), l_collect_sbe_scratch_data);
            goto EXIT;
        }

        if ((l_returnErrl = sendGetScratchDataRequest(i_chipTarget,
                                                      l_scratchDataResponse)))
        {
            goto EXIT;
        }

        makeScratchDataErrls(i_chipTarget, l_scratchDataResponse, o_errls);

      EXIT:
        SBE_TRACF(EXIT_MRK"getAndProcessScratchData: Target 0x%08X", get_huid(i_chipTarget));
        return l_returnErrl;
    }

    void handleGetScratchDataPrdRequest(Target* i_chipTarget, uint32_t i_plid)
    {
        SBE_TRACF(ENTER_MRK"handleGetScratchDataPrdRequest: Target 0x%08X, i_plid = 0x%08X",
                  get_huid(i_chipTarget), i_plid);
        errlHndl_t l_scratchDataErrls = nullptr;

        errlHndl_t l_chipOpErrl = getAndProcessScratchData(i_chipTarget, l_scratchDataErrls);
        if(l_chipOpErrl)
        {
            // We couldn't get the scratch data. This is a "nice-to-have" debug
            // data, so just link the errl to the input PLID and commit.
            if(i_plid)
            {
                l_chipOpErrl->plid(i_plid);
            }
            errlCommit(l_chipOpErrl, SBEIO_COMP_ID);
        }
        else
        {
            if(l_scratchDataErrls)
            {
                if(i_plid)
                {
                    l_scratchDataErrls->plid(i_plid);
                }
                errlCommit(l_scratchDataErrls, SBEIO_COMP_ID);
            }
        }
        SBE_TRACF(EXIT_MRK"handleGetScratchDataPrdRequest: Target 0x%08X", get_huid(i_chipTarget));
    }

};
