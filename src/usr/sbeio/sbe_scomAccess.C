/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_scomAccess.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
 * @file sbe_scomAccess.C
 * @brief SCOM Access client interface
 */

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <devicefw/driverif.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include <sbeio/sbeioreasoncodes.H>
#include "sbe_fifodd.H"
#include <targeting/odyutil.H>


extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"ScomAccess: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"ScomAccess: " printf_string,##args)
#define SBE_TRACU(args...)
/* replace for unit testing
#define SBE_TRACU(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"ScomAccess: " printf_string,##args)
*/

namespace SBEIO
{

// Get SCOM via SBE FIFO
errlHndl_t getFifoScom(TARGETING::Target * i_target,
                       uint64_t            i_addr,
                       uint64_t          & o_data)

{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "getFifoScom");
    do
    {
        // error check input parameters
        errl = sbeioInterfaceChecks(i_target,
                                    SbeFifo::SBE_FIFO_CLASS_SCOM_ACCESS,
                                    SbeFifo::SBE_FIFO_CMD_GET_SCOM,
                                    i_addr);
        if (errl)
        {
            break;
        }

        // set up FIFO request message
        SbeFifo::fifoGetScomRequest  l_fifoRequest;
        SbeFifo::fifoGetScomResponse l_fifoResponse;
        l_fifoRequest.commandClass = SbeFifo::SBE_FIFO_CLASS_SCOM_ACCESS;
        l_fifoRequest.command = SbeFifo::SBE_FIFO_CMD_GET_SCOM;
        l_fifoRequest.address = i_addr;

        if(TARGETING::UTIL::isOdysseyChip(i_target))
        {
            // The Chip IDs that we care about are:
            // 0x01 (Memory Buffer 0) ... 0x20 (Memory Buffer 31)
            // Add 1 to the POSITION attribute to get the right Chip ID
            l_fifoRequest.chipId = i_target->getAttr<TARGETING::ATTR_POSITION>()+1;
        }

        SBE_TRACU("getFifoScom: i_addr=%llX, target=%.8X",
                  i_addr, TARGETING::get_huid(i_target));

        errl = SbeFifo::getTheInstance().performFifoChipOp(i_target,
                                 (uint32_t *)&l_fifoRequest,
                                 (uint32_t *)&l_fifoResponse,
                                 sizeof(SbeFifo::fifoGetScomResponse));
        //always return data even if there is an error
        o_data = l_fifoResponse.data;
    }
    while (0);

    SBE_TRACD(EXIT_MRK "getFifoScom");

    return errl;
};

// Put SCOM via SBE FIFO
errlHndl_t putFifoScom(TARGETING::Target * i_target,
                       uint64_t            i_addr,
                       uint64_t            i_data)
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "putFifoScom");
    do
    {
        // error check input parameters
        errl = sbeioInterfaceChecks(i_target,
                                    SbeFifo::SBE_FIFO_CLASS_SCOM_ACCESS,
                                    SbeFifo::SBE_FIFO_CMD_PUT_SCOM,
                                    i_addr);
        if (errl)
        {
            break;
        }

        // set up FIFO request message
        SbeFifo::fifoPutScomRequest  l_fifoRequest;
        SbeFifo::fifoPutScomResponse l_fifoResponse;
        l_fifoRequest.commandClass = SbeFifo::SBE_FIFO_CLASS_SCOM_ACCESS;
        l_fifoRequest.command = SbeFifo::SBE_FIFO_CMD_PUT_SCOM;
        l_fifoRequest.address = i_addr;
        l_fifoRequest.data    = i_data;

         if(TARGETING::UTIL::isOdysseyChip(i_target))
         {
             // The Chip IDs that we care about are:
             // 0x01 (Memory Buffer 0) ... 0x20 (Memory Buffer 31)
             // Add 1 to the POSITION attribute to get the right Chip ID
             l_fifoRequest.chipId = i_target->getAttr<TARGETING::ATTR_POSITION>()+1;
         }

        SBE_TRACU("putFifoScom: i_addr=%llX, target=%.8X",
                  i_addr, TARGETING::get_huid(i_target));

        errl = SbeFifo::getTheInstance().performFifoChipOp(i_target,
                                 (uint32_t *)&l_fifoRequest,
                                 (uint32_t *)&l_fifoResponse,
                                 sizeof(SbeFifo::fifoPutScomResponse));
    }
    while (0);

    SBE_TRACD(EXIT_MRK "putFifoScom");

    return errl;
};

// Put SCOM under mask via SBE FIFO
errlHndl_t putFifoScomUnderMask(TARGETING::Target * i_target,
                                uint64_t            i_addr,
                                uint64_t            i_data,
                                uint64_t            i_mask)
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "putFifoScomUnderMask");

    do
    {
        // error check input parameters
        errl = sbeioInterfaceChecks(i_target,
                                    SbeFifo::SBE_FIFO_CLASS_SCOM_ACCESS,
                                    SbeFifo::SBE_FIFO_CMD_PUT_SCOM_UNDER_MASK,
                                    i_addr);
        if (errl)
        {
            break;
        }

        // set up FIFO request message
        SbeFifo::fifoPutScomUnderMaskRequest  l_fifoRequest;
        SbeFifo::fifoPutScomResponse          l_fifoResponse;
        l_fifoRequest.commandClass = SbeFifo::SBE_FIFO_CLASS_SCOM_ACCESS;
        l_fifoRequest.command = SbeFifo::SBE_FIFO_CMD_PUT_SCOM_UNDER_MASK;
        l_fifoRequest.address = i_addr;
        l_fifoRequest.data    = i_data;
        l_fifoRequest.mask    = i_mask;

        SBE_TRACU("putFifoUnderMaskScom: "
                  "i_addr=%llX, target=%.8X, mask=%llX",
                  i_addr, TARGETING::get_huid(i_target),i_mask);

        errl = SbeFifo::getTheInstance().performFifoChipOp(i_target,
                                 (uint32_t *)&l_fifoRequest,
                                 (uint32_t *)&l_fifoResponse,
                                 sizeof(SbeFifo::fifoPutScomResponse));
    }
    while (0);

    SBE_TRACD(EXIT_MRK "putFifoScomUnderMask");

    return errl;
};

// Reset FSI SBE FIFO
errlHndl_t sendFifoReset(TARGETING::Target * i_target)
{
    errlHndl_t errl = NULL;
    uint32_t l_addr{};

    SBE_TRACD(ENTER_MRK "sendFifoReset");

    SbeFifo::fifoRegType l_type = TARGETING::UTIL::isOdysseyChip(i_target) ?
                                                        SbeFifo::FIFO_SPPE :
                                                        SbeFifo::FIFO_SBE;
    l_addr = SbeFifo::getTheInstance().getFifoRegValue(l_type, SbeFifo::FIFO_DNFIFO_RESET);

    // error check input parameters
    errl = sbeioInterfaceChecks(i_target,
                                SbeFifo::SBE_FIFO_CLASS_SCOM_ACCESS,
                                SbeFifo::SBE_FIFO_CMD_PUT_SCOM,
                                l_addr);
    if (errl) {goto ERROR_EXIT;}

    errl = SbeFifo::getTheInstance().performFifoReset(i_target);

    ERROR_EXIT:
    SBE_TRACD(EXIT_MRK "sendFifoReset");
    return errl;
};

} //end namespace SBEIO

