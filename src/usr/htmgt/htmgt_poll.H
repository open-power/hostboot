/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_poll.H $                                  */
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

#ifndef HTMGT_POLL_H
#define HTMGT_POLL_H

#include <stdint.h>
#include <htmgt/htmgt.H>
#include "htmgt_activate.H"
#include "htmgt_occ.H"

namespace HTMGT
{
    struct occPollRspStruct_t
    {
        uint8_t   status;
        uint8_t   extStatus;
        uint8_t   occsPresent;
        uint8_t   requestedCfg;
        uint8_t   state;
        uint16_t  reserved;
        uint8_t   errorId;
        uint32_t  errorAddress;
        uint16_t  errorLength;
        uint16_t  reserved2;
        uint8_t   codeLevel[16];
        uint8_t   sensor[6];
        uint8_t   numBlocks;
        uint8_t   version;
        uint8_t   sensorData[4049];
    }  __attribute__((packed));

    const uint32_t HTMGT_OCC_POLL_DATA_SIZE = sizeof(occPollRspStruct_t);


    /**
     * @brief Send a poll command to each OCC
     *
     * @return NULL on success, else error handle
     */
    errlHndl_t sendOccPoll();


    /**
     * @brief Handle OCC poll response
     *
     * @param[in] i_occ               pointer to the OCC
     * @param[in] i_pollResponse      pointer to the response
     * @param[in] i_pollResponseSize  length of the poll response
     */
    void poll_rsp_handler(Occ * i_occ,
                          const uint8_t * i_pollResponse,
                          const uint16_t i_pollResponseSize);

} // end namespace
#endif
