/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_poll.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

#include <htmgt/htmgt.H>
#include <htmgt/htmgt_reasoncodes.H>
#include "htmgt_utility.H"
#include "htmgt_activate.H"
#include "htmgt_poll.H"
#include "htmgt_occcmd.H"
#include "htmgt_cfgdata.H"

//  Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>


using namespace HTMGT;


namespace HTMGT
{

    // Send a single poll command to OCC
    errlHndl_t sendOccPoll()
    {
        errlHndl_t l_err = NULL;
        uint8_t * l_poll_rsp = NULL;

        // Loop through all functional OCCs
        std::vector<Occ*> occList = occMgr::instance().getOccArray();
        for (std::vector<Occ*>::iterator itr = occList.begin();
             (itr < occList.end()) && (NULL == l_err);
             ++itr)
        {
            Occ * occ = (*itr);
            const uint8_t occInstance = occ->getInstance();
            TMGT_INF("sendOccPoll: to OCC%d", occInstance);

            // create 1 byte buffer for poll command data
            const uint8_t l_cmdData[1] = { 0x10 /*version*/ };

            OccCmd cmd(occ, OCC_CMD_POLL, sizeof(l_cmdData), l_cmdData);
            l_err = cmd.sendOccCmd();
            if (l_err != NULL)
            {
                // Poll failed
                TMGT_ERR("sendOccPoll: OCC%d poll failed with rc=0x%04X",
                         occInstance, l_err->reasonCode());
            }
            else
            {
                // Poll succeeded, check response
                uint32_t l_poll_rsp_size = cmd.getResponseData(l_poll_rsp);
                if (l_poll_rsp_size >= OCC_POLL_DATA_MIN_SIZE)
                {
                    poll_rsp_handler(occ, l_poll_rsp, l_poll_rsp_size);
                }
                else
                {
                    TMGT_ERR("sendOccPoll: OCC%d poll command response "
                             "failed with invalid data length %d",
                             occInstance, l_poll_rsp_size);
                    /*@
                     * @errortype
                     * @reasoncode HTMGT_RC_INVALID_LENGTH
                     * @moduleid  HTMGT_MOD_OCC_POLL
                     * @userdata1 OCC instance
                     * @devdesc Invalid POLL response length
                     */
                    bldErrLog(l_err, HTMGT_MOD_OCC_POLL,
                              HTMGT_RC_INVALID_LENGTH,
                              occInstance, 0, 0, 0,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                }
            }
        }

        return l_err;

    } // end sendOccPoll()



    // Handle OCC poll response
    void poll_rsp_handler(Occ * i_occ,
                          const uint8_t * i_pollResponse,
                          const uint16_t i_pollResponseSize)
    {
        TMGT_DBG("OCC Poll Response", i_pollResponse, i_pollResponseSize);

        const occPollRspStruct_t *pollRspData =
            (occPollRspStruct_t *) i_pollResponse;

        // Trace if any data changed
        if (memcmp(pollRspData,
                   i_occ->getLastPollRsp(),
                   OCC_POLL_DATA_MIN_SIZE) != 0)
        {
            TMGT_INF("OCC%d Poll change: Status:%04X Occs:%02X Cfg:%02X "
                     "State:%02X Error:%06X/%08X",
                     i_occ->getInstance(),
                     (pollRspData->status << 8) | pollRspData->extStatus,
                     pollRspData->occsPresent,
                     pollRspData->requestedCfg, pollRspData->state,
                     (pollRspData->errorId<<16) | pollRspData->errorLength,
                     pollRspData->errorAddress);
            TMGT_INF("                  Code: \"%s\", NumSensors: 0x%02X",
                     pollRspData->codeLevel, pollRspData->numBlocks);
        }
    }



} // end namespace



