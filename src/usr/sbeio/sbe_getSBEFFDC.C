/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_getSBEFFDC.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>

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
    * @param[in]     i_procChip      The proc from which to get the SBE FFDC
    * @param[out]    o_pFifoResponse Pointer to response
    * @param[in]     i_responseSize  Size of response in bytes
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t getFifoSBEFFDC(TARGETING::Target *i_procChip,
                              uint32_t *o_pFifoResponse,
                              uint32_t &i_responseSize)
    {
        errlHndl_t l_errl = NULL;

        SBE_TRACF(ENTER_MRK "sending get SBE FFDC for Proc %d, HUID 0x%.8X",
                  i_procChip->getAttr<TARGETING::ATTR_POSITION>(),
                  TARGETING::get_huid(i_procChip));

        // Create FIFO request structure
        SbeFifo::fifoGetSbeFfdcRequest l_fifoRequest;

        // Fill in FIFO Request with Get SBE FFDC information
        l_fifoRequest.commandClass = SbeFifo::SBE_FIFO_CLASS_GENERIC_MESSAGE;
        l_fifoRequest.command = SbeFifo::SBE_FIFO_CMD_GET_SBE_FFDC;

        // Call performFifoChipOp, tell SBE where to write FFDC and messages
        l_errl =
            SbeFifo::getTheInstance().performFifoChipOp(i_procChip,
                                   reinterpret_cast<uint32_t *>(&l_fifoRequest),
                                   o_pFifoResponse,
                                   i_responseSize);

        SBE_TRACD(EXIT_MRK "sendGetSBEFFDC");

        return l_errl;
    };

} //end namespace SBEIO
