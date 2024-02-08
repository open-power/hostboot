/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_getSBEFFDC.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2024                        */
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
* @file sbe_getSBEFFDC.C
* @brief Get SBE FFDC.
*/

#include <util/align.H>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>
#include "sbe_fifo_buffer.H"
#include <sbeio/sbe_ffdc_parser.H>
#include <targeting/odyutil.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"getFifoSBEFFDC: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"getFifoSBEFFDC: " printf_string,##args)

namespace SBEIO
{

    /**
    * @brief Get the SBE FFDC.  Request that SBE retrieve the SBE FFDC
    *
    * @param[in]     i_chipTarget    The chip from which to get the SBE FFDC
    * @param[out]    o_pFifoResponse Pointer to response
    * @param[in]     i_responseSize  Size of response in bytes
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t getFifoSBEFFDC(TARGETING::Target *i_chipTarget,
                              uint32_t *o_pFifoResponse,
                              uint32_t &i_responseSize)
    {
        errlHndl_t l_errl = NULL;

        SBE_TRACF(ENTER_MRK "getFifoSBEFFDC sending get SBE FFDC for chip %d, HUID 0x%.8X",
                  i_chipTarget->getAttr<TARGETING::ATTR_POSITION>(),
                  TARGETING::get_huid(i_chipTarget));

        // Create FIFO request structure
        SbeFifo::fifoGetSbeFfdcRequest l_fifoRequest;

        // Fill in FIFO Request with Get SBE FFDC information
        l_fifoRequest.commandClass = SbeFifo::SBE_FIFO_CLASS_GENERIC_MESSAGE;
        l_fifoRequest.command = SbeFifo::SBE_FIFO_CMD_GET_SBE_FFDC;

        // Call performFifoChipOp, tell SBE where to write FFDC and messages
        l_errl =
            SbeFifo::getTheInstance().performFifoChipOp(i_chipTarget,
                                   reinterpret_cast<uint32_t *>(&l_fifoRequest),
                                   o_pFifoResponse,
                                   i_responseSize);

        SBE_TRACD(EXIT_MRK "getFifoSBEFFDC");

        return l_errl;
    };

    errlOwner genFifoSBEFFDCErrls(TARGETING::Target* i_chipTarget, errlHndl_t & o_errs)
    {
        errlOwner errl { nullptr };

        // Use the appropriate MSG_BUFFER_SIZE_WORDS_* depending on the target
        uint32_t l_responseSize = 0;
        if (i_chipTarget->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC)
        {
            l_responseSize = SbeFifoRespBuffer::MSG_BUFFER_SIZE_WORDS_POZ;
        }
        else if (i_chipTarget->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_OCMB_CHIP)
        {
            l_responseSize = SbeFifoRespBuffer::MSG_BUFFER_SIZE_WORDS_POZ;
        }
        else
        {
            assert(false,"genFifoSBEFFDCErrls: Unknown tgt 0x%X of type 0x%X",
                   TARGETING::get_huid(i_chipTarget),
                   i_chipTarget->getAttr<TARGETING::ATTR_TYPE>());
        }

        std::vector<uint32_t> l_fifoResponse(l_responseSize);

        do {

        errl = getFifoSBEFFDC(i_chipTarget,
                              l_fifoResponse.data(),
                              l_responseSize);

        if (errl)
        {
            SBE_TRACF(ERR_MRK"genFifoSBEFFDCErrl: Error returned from SBE FFDC "
                             "chip op ERRL=0x%X", ERRL_GETEID_SAFE(errl));
            break;
        }

        auto l_ffdcParser = std::make_shared<SbeFFDCParser>();
        l_ffdcParser->parseFFDCData(l_fifoResponse.data());
        o_errs = l_ffdcParser->generateSbeErrors(i_chipTarget,
                                                 SBEIO_FIFO_SBE_FFDC,
                                                 SBEIO_FIFO_SBE_FFDC_INFORMATIONAL,
                                                 get_huid(i_chipTarget), // userdata1
                                                 0);                     // userdata2

        }while(0);

        return errl;
    }

    void handleGenFifoSBEFFDCErrlRequest()
    {
        using namespace TARGETING;

        TargetHandleList l_ocmbs;
        getAllChips(l_ocmbs, TYPE_OCMB_CHIP, true /* only functional */);

        for(auto l_ocmb : l_ocmbs)
        {
            if(!UTIL::isOdysseyChip(l_ocmb))
            {
                continue;
            }

            errlHndl_t async_errls;
            errlOwner request_errl = SBEIO::genFifoSBEFFDCErrls(l_ocmb, async_errls);

            if(request_errl)
            {
                SBE_TRACF(INFO_MRK"handleGenFifoSBEFFDCErrlRequest: "
                          "genFifoSBEFFDCErrls failed for OCMB 0x%x."
                          TRACE_ERR_FMT,
                          get_huid(l_ocmb),
                          TRACE_ERR_ARGS(request_errl));

                request_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit(request_errl, SBEIO_COMP_ID);
            }

            SBE_TRACF(INFO_MRK"handleGenFifoSBEFFDCErrlRequest: Committing "
                    "FFDC errl for OCMB 0x%x."
                    TRACE_ERR_FMT,
                    get_huid(l_ocmb),
                    TRACE_ERR_ARGS(async_errls));

            // Force these to be informational so there is no potential
            // callouts logged/parts deconfigured.
            async_errls->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            errlCommit(async_errls, SBEIO_COMP_ID);
        }
    }

    bool checkOdyFFDC(TARGETING::Target* i_chipTarget)
    {
        using namespace TARGETING;
        errlHndl_t l_errl         = nullptr;
        bool       l_hasAsyncFfdc = false;
        bool       hreset_already_performed = false;

        typedef union // See mbxscratch.H for this definition
        {
            struct
            {
                uint64_t iv_sbeBooted : 1;
                uint64_t iv_asyncFFDC : 1;
                uint64_t iv_reserved1 : 1;
                uint64_t iv_currImage : 1; // If 0->SROM , 1->Boot Loader/Runtime
                uint64_t iv_prevState : 4;
                uint64_t iv_currState : 4;
                uint64_t iv_majorStep : 4;
                uint64_t iv_minorStep : 6;
                uint64_t iv_reserved2 : 4;
                uint64_t iv_progressCode : 6;
                uint64_t iv_unused : 32;
            };
            uint64_t iv_messagingReg;
        } messagingReg_t;

        uint32_t l_data     = 0;
        size_t   l_dataSize = sizeof(l_data);

        l_errl = deviceRead(i_chipTarget,
                            &l_data,
                            l_dataSize,
                            DEVICE_CFAM_ADDRESS(0x2809));
        SBE_TRACF(INFO_MRK"checkOdyFFDC: SBE MSG register for OCMB 0x%x l_data=%llx",
                  get_huid(i_chipTarget), l_data);
        if(l_errl)
        {
            SBE_TRACF(INFO_MRK"checkOdyFFDC: Could not read SBE MSG register "
                              "for OCMB 0x%x ERRL=0x%X (committing)",
                              get_huid(i_chipTarget), ERRL_GETEID_SAFE(l_errl));
            errlCommit(l_errl, SBEIO_COMP_ID);
        }
        else
        {
            messagingReg_t l_msgReg;
            l_msgReg.iv_messagingReg = l_data;
            l_hasAsyncFfdc           = l_msgReg.iv_asyncFFDC;
        }

        errlHndl_t async_errls;
        errlOwner err = genFifoSBEFFDCErrls(i_chipTarget, async_errls);

        if (err)
        {
            SBE_TRACF(INFO_MRK"checkOdyFFDC: gathered FFDC failed " TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            if (err->hasErrorType(SBEIO::SBEIO_ERROR_TYPE_HRESET_PERFORMED))
            {
                hreset_already_performed = true;
                err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                SBE_TRACF("checkOdyFFDC: hreset_already_performed ERRL=0x%X", ERRL_GETEID_SAFE(err))
            }
            errlCommit(err, SBEIO_COMP_ID);
        }
        else
        {
            SBE_TRACF(INFO_MRK"checkOdyFFDC: gathered FFDC for OCMB 0x%x "
                      "l_hasAsyncFfdc=0x%X",
                      get_huid(i_chipTarget), l_hasAsyncFfdc);

                // Set the severity to informational
                async_errls->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                SBE_TRACF(INFO_MRK"checkOdyFFDC: Committing error log PLID 0x%x for OCMB 0x%x",
                          async_errls->plid(), get_huid(i_chipTarget));
                errlCommit(async_errls, SBEIO_COMP_ID);
        }

    return hreset_already_performed;
    }

} //end namespace SBEIO
