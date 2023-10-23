/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_getSBEFFDC.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2023                        */
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

        SBE_TRACF(ENTER_MRK "sending get SBE FFDC for chip %d, HUID 0x%.8X",
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

        SBE_TRACD(EXIT_MRK "sendGetSBEFFDC");

        return l_errl;
    };

    std::vector<errlHndl_t> genFifoSBEFFDCErrls(TARGETING::Target* i_chipTarget)
    {
        std::vector<errlHndl_t> l_errls;
        uint32_t l_responseSize = SbeFifoRespBuffer::MSG_BUFFER_SIZE_WORDS;
        uint32_t *l_pFifoResponse = reinterpret_cast<uint32_t *>(malloc(l_responseSize));

        do {

        errlHndl_t l_errl = getFifoSBEFFDC(i_chipTarget,
                                           l_pFifoResponse,
                                           l_responseSize);
        if(l_errl)
        {
            SBE_TRACF(ERR_MRK"genFifoSBEFFDCErrl: Error returned from SBE FFDC chip op");
            l_errls.push_back(l_errl);
            break;
        }

        auto l_ffdcParser = std::make_shared<SbeFFDCParser>();
        l_ffdcParser->parseFFDCData(l_pFifoResponse);
        l_errls = l_ffdcParser->generateSbeErrors(SBEIO_FIFO_SBE_FFDC,
                                                  SBEIO_FIFO_SBE_FFDC_INFORMATIONAL,
                                                  get_huid(i_chipTarget), // userdata1
                                                  0);                     // userdata2
        }while(0);

        free(l_pFifoResponse);
        l_pFifoResponse = nullptr;

        return l_errls;
    }

    void handleGenFifoSBEFFDCErrlRequest()
    {
        using namespace TARGETING;
        std::vector<errlHndl_t> l_errls;

        TargetHandleList l_ocmbs;
        getAllChips(l_ocmbs, TYPE_OCMB_CHIP); // Functional and non-functional

        for(auto l_ocmb : l_ocmbs)
        {
            if(!UTIL::isOdysseyChip(l_ocmb))
            {
                continue;
            }

            l_errls = SBEIO::genFifoSBEFFDCErrls(l_ocmb);
            for(auto l_errl : l_errls)
            {
                SBE_TRACF(INFO_MRK"handleGenFifoSBEFFDCErrlRequest: Committing errl PLID 0x%x for OCMB 0x%x", l_errl->plid(), get_huid(l_ocmb));

                // Force these to be informational so there is no potential
                // callouts logged/parts deconfigured.
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit(l_errl, SBEIO_COMP_ID);
            }
        }
    }

    void processOdyAsyncFFDC(TARGETING::Target* i_chipTarget)
    {
        using namespace TARGETING;
        std::vector<errlHndl_t> l_errls = genFifoSBEFFDCErrls(i_chipTarget);

        for(auto l_errl : l_errls)
        {
            if(i_chipTarget->getAttr<ATTR_OCMB_FW_STATE>() != OCMB_FW_STATE_UP_TO_DATE)
            {
                // Set the severities to informational, since code update could
                // fix the issues SBE is complaining about, and we don't want to
                // have valid callouts in the error logs for resolved issues.
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            }
            SBE_TRACF(INFO_MRK"processOdyAsyncFFDC: Committing error log PLID 0x%x for OCMB 0x%x", l_errl->plid(), get_huid(i_chipTarget));
            errlCommit(l_errl, SBEIO_COMP_ID);
        }
    }

} //end namespace SBEIO
