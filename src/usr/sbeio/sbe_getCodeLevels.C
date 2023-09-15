/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_getCodeLevels.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
* @file sbe_getCodeLevels.C
* @brief Get the code levels from the SBE
*/

#include <errl/errlmanager.H> // errlHndl_t
#include "sbe_fifodd.H"       // SbeFifo::fifoGetCodeLevelsRequest
#include <sbeio/sbeioreasoncodes.H> // SBEIO_FIFO
#include <targeting/common/commontargeting.H>  // get_huid
#include <targeting/targplatutil.H>  //getCurrentNodeTarget
#include <targeting/odyutil.H>
#include <sbeio/sbeioif.H>
#include "sbe_getCodeLevels.H"

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio, printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio, printf_string,##args)

namespace SBEIO
{
using namespace TARGETING;
using namespace ERRORLOG;


#ifndef __HOSTBOOT_RUNTIME  //no FIFO at runtime

struct getCodeLevelsResponseBuf_t
{
    struct getCodeLevelsResponse_t data;
    SbeFifo::fifoStandardResponse  rspEnd;
};

errlHndl_t getFifoSbeCodeLevels(TargetHandle_t  i_target,
                       getCodeLevelsResponse_t &o_response)
{
    SbeFifo::fifoGetCodeLevelsRequest l_fifoRequest;
    getCodeLevelsResponseBuf_t        l_rspBuf;
    SbeFifo::fifoStandardResponse    *l_fifoResponseEnd = &l_rspBuf.rspEnd;
    errlHndl_t                        l_errl(nullptr);
    uint32_t                          l_huid = get_huid(i_target);

    SBE_TRACD(ENTER_MRK "getFifoSbeCodeLevels: target:0x%08X", l_huid);

    if (! UTIL::isOdysseyChip(i_target))
    {
        SBE_TRACF("getFifoSbeCodeLevels: Chip 0x%08X is not an Odyssey", l_huid);
        goto ERROR_EXIT;
    }

    l_errl = sbeioInterfaceChecks(i_target,
                                  l_fifoRequest.commandClass,
                                  l_fifoRequest.command);
    if (l_errl)
    {
        SBE_TRACF("getFifoSbeCodeLevels: 0x%08X failed sbeioInterfaceChecks",l_huid);
        goto ERROR_EXIT;
    }

    l_errl = SbeFifo::getTheInstance().performFifoChipOp(
                                i_target,
                                reinterpret_cast<uint32_t*>(&l_fifoRequest),
                                reinterpret_cast<uint32_t*>(&l_rspBuf),
                                sizeof(l_rspBuf));
    if (l_errl)
    {
        SBE_TRACF("getFifoSbeCodeLevels: chipop failed, target:0x%08X" TRACE_ERR_FMT,
                l_huid, TRACE_ERR_ARGS(l_errl));
        goto ERROR_EXIT;
    }

    // Sanity check - are HW and HB communications in sync?
    //  *this does a double-check of the response buffer using l_fifoResponseEnd,
    //    which ensures our local variable is correctly pointing at the response data
    if ((SbeFifo::FIFO_STATUS_MAGIC != l_fifoResponseEnd->status.magic)        ||
        (l_fifoRequest.commandClass != l_fifoResponseEnd->status.commandClass) ||
        (l_fifoRequest.command      != l_fifoResponseEnd->status.command))
    {
        SBE_TRACF("getFifoSbeCodeLevels: 0x%08X performFifoChipOp returned unexpected "
                  "message type; "
                  "magic code returned:0x%X, "
                  "expected magic code:0x%X, "
                  "command class returned:0x%X, "
                  "expected command class:0x%X, "
                  "command returned:0x%X, "
                  "expected command:0x%X",
                  l_huid,
                  l_fifoResponseEnd->status.magic,
                  SbeFifo::FIFO_STATUS_MAGIC,
                  l_fifoResponseEnd->status.commandClass,
                  l_fifoRequest.commandClass,
                  l_fifoResponseEnd->status.command,
                  l_fifoRequest.command);
        /*@
         * @errortype
         * @moduleid          SBEIO_FIFO
         * @reasoncode        SBEIO_RECEIVE_CODE_LEVELS_BAD_MSG
         * @userdata1         Target HUID
         * @userdata2[0:15]   Requested command class
         * @userdata2[16:31]  Requested command
         * @userdata2[32:47]  Returned command class
         * @userdata2[48:63]  Returned command
         * @devdesc           Call to FIFO Chip Op returned an
         *                    unexpected message type.
         */
        l_errl = new ErrlEntry(
            ERRL_SEV_INFORMATIONAL,
            SBEIO_FIFO,
            SBEIO_RECEIVE_CODE_LEVELS_BAD_MSG,
            l_huid,
            TWO_UINT32_TO_UINT64(
              TWO_UINT16_TO_UINT32(SbeFifo::SBE_FIFO_CLASS_GENERIC_MESSAGE,
                                   l_fifoRequest.command),
              TWO_UINT16_TO_UINT32(l_fifoResponseEnd->status.commandClass,
                                   l_fifoResponseEnd->status.command) ));

        TRACFBIN(g_trac_sbeio,"getFifoSbeCodeLevels: getCodeLevelsResponseBuf_t",
                 &l_rspBuf,
                 sizeof(l_rspBuf));
        TRACFBIN(g_trac_sbeio,"getFifoSbeCodeLevels: getCodeLevelsResponse_t",
                 &l_rspBuf.data,
                 sizeof(l_rspBuf.data));
        TRACFBIN(g_trac_sbeio,"getFifoSbeCodeLevels: l_fifoResponseEnd",
                &l_rspBuf.rspEnd,
                sizeof(l_rspBuf.rspEnd));

        l_errl->collectTrace(SBEIO_COMP_NAME, 256);
        goto ERROR_EXIT;
    }

    memcpy(&o_response, &l_rspBuf.data, sizeof(o_response));
    i_target->setAttr<ATTR_SBE_NUM_CAPABILITIES>(o_response.num_capabilities);
    i_target->setAttr<ATTR_SBE_NUM_IMAGES>(o_response.num_images);

    SBE_TRACD("getFifoSbeCodeLevels: target:0x%08X num_cap:%d num_images:%d",
            l_huid, o_response.num_capabilities, o_response.num_images);

    ERROR_EXIT:

    SBE_TRACD(EXIT_MRK "getFifoSbeCodeLevels: target:0x%08X", l_huid);

    return l_errl;
}

#endif //#ifdef __HOSTBOOT_RUNTIME

} //end namespace SBEIO
