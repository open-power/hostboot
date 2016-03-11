/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_scomAccess.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
#include <sbeio/sbeioreasoncodes.H>
#include "sbe_fifodd.H"

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

// Interface error checks
errlHndl_t fifoScomInterfaceChecks(TARGETING::Target * i_target,
                                   uint64_t            i_addr)
{
    errlHndl_t errl = NULL;
    SBE_TRACD(ENTER_MRK"fifoScomInterfaceChecks");

    do
    {
        // look for NULL
        if( NULL == i_target )
        {
            SBE_TRACF(ERR_MRK "fifoScomInterfaceChecks: Target is NULL" );
            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_NULL_TARGET
             * @userdata1    Request Address
             * @devdesc      Null target passed
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SBEIO_FIFO,
                                           SBEIO_FIFO_NULL_TARGET,
                                           i_addr,
                                           0,
                                           true /*SW error*/);
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }

        // check target for sentinel
        if( TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target )
        {
            SBE_TRACF(ERR_MRK "fifoScomInterfaceChecks: "
                              "Target is Master Sentinel" );
            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_SENTINEL_TARGET
             * @userdata1    Request Address
             * @devdesc      Master Sentinel target is not supported
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SBEIO_FIFO,
                                           SBEIO_FIFO_SENTINEL_TARGET,
                                           i_addr,
                                           0,
                                           true /*SW error*/);
            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }

        // check for master proc
        TARGETING::Target * l_master = NULL;
        (void)TARGETING::targetService().masterProcChipTargetHandle(l_master);
        if( l_master == i_target )
        {
            SBE_TRACF(ERR_MRK "fifoScomInterfaceChecks: "
                              "Target is Master Proc" );
            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_MASTER_TARGET
             * @userdata1    Request Address
             * @userdata2    HUID of master proc
             * @devdesc      Master Proc is not supported
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SBEIO_FIFO,
                                           SBEIO_FIFO_MASTER_TARGET,
                                           i_addr,
                                           TARGETING::get_huid(i_target),
                                           true /*SW error*/);
            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }
    }
    while (0);

    SBE_TRACD(EXIT_MRK "fifoScomInterfaceChecks");

    return errl;
};
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
        errl = fifoScomInterfaceChecks(i_target,i_addr);
        if (errl) break;

        // set up FIFO request message
        fifoGetScomRequest  l_fifoRequest;
        fifoGetScomResponse l_fifoResponse;
        l_fifoRequest.commandClass = SBE_FIFO_CLASS_SCOM_ACCESS;
        l_fifoRequest.command = SBE_FIFO_CMD_GET_SCOM;
        l_fifoRequest.address = i_addr;

        SBE_TRACU("getFifoScom: i_addr=%llX, target=%.8X",
                  i_addr, TARGETING::get_huid(i_target));

        errl = performFifoChipOp(i_target,
                                 (uint32_t *)&l_fifoRequest,
                                 (uint32_t *)&l_fifoResponse,
                                 sizeof(fifoGetScomResponse));
        // return data if no error
        if (!errl)
        {
            o_data = l_fifoResponse.data;
        }
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
        errl = fifoScomInterfaceChecks(i_target,i_addr);
        if (errl) break;

        // set up FIFO request message
        fifoPutScomRequest  l_fifoRequest;
        fifoPutScomResponse l_fifoResponse;
        l_fifoRequest.commandClass = SBE_FIFO_CLASS_SCOM_ACCESS;
        l_fifoRequest.command = SBE_FIFO_CMD_PUT_SCOM;
        l_fifoRequest.address = i_addr;
        l_fifoRequest.data    = i_data;

        SBE_TRACU("putFifoScom: i_addr=%llX, target=%.8X",
                  i_addr, TARGETING::get_huid(i_target));

        errl = performFifoChipOp(i_target,
                                 (uint32_t *)&l_fifoRequest,
                                 (uint32_t *)&l_fifoResponse,
                                 sizeof(fifoPutScomResponse));
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
        errl = fifoScomInterfaceChecks(i_target,i_addr);
        if (errl) break;

        // set up FIFO request message
        fifoPutScomUnderMaskRequest  l_fifoRequest;
        fifoPutScomResponse          l_fifoResponse;
        l_fifoRequest.commandClass = SBE_FIFO_CLASS_SCOM_ACCESS;
        l_fifoRequest.command = SBE_FIFO_CMD_PUT_SCOM_UNDER_MASK;
        l_fifoRequest.address = i_addr;
        l_fifoRequest.data    = i_data;
        l_fifoRequest.mask    = i_mask;

        SBE_TRACU("putFifoUnderMaskScom: "
                  "i_addr=%llX, target=%.8X, mask=%llX",
                  i_addr, TARGETING::get_huid(i_target),i_mask);

        errl = performFifoChipOp(i_target,
                                 (uint32_t *)&l_fifoRequest,
                                 (uint32_t *)&l_fifoResponse,
                                 sizeof(fifoPutScomResponse));
    }
    while (0);

    SBE_TRACD(EXIT_MRK "putFifoScomUnderMask");

    return errl;
};

} //end namespace SBEIO

