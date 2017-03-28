/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_continueMpipl.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
* @file sbe_systemConfig.C
* @brief System Configuartion Setup Messages to inform the SBE of other
         procs in the system.
*/

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"continueMPIPL: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"continueMPIPL: " printf_string,##args)


namespace SBEIO
{

    /**
    * @brief Set the system configuration on the SBE so it is aware of
    *        the other procs in the system
    *
    * @param[in] i_procChip The proc you would like to request continueMPIPL to
    *                       NOTE: HB should only be sending this to slave procs
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */

    errlHndl_t sendContinueMpiplRequest(TARGETING::Target * i_procChip)
    {
        errlHndl_t errl = nullptr;
        // check for master proc
        TARGETING::Target * l_master = nullptr;
        (void)TARGETING::targetService().masterProcChipTargetHandle(l_master);

        do
        {
            // look for NULL
            if( nullptr == i_procChip ||
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_procChip ||
                i_procChip == l_master)
            {
                /*@
                * @errortype
                * @moduleid     SBEIO_FIFO_CONTINUE_MPIPL
                * @reasoncode   SBEIO_FIFO_SENTINEL_TARGET
                * @devdesc      Attempted FIFO chip op on Master Proc
                * @custdesc     Firmware error communicating with boot device
                */
                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SBEIO_FIFO_CONTINUE_MPIPL,
                                            SBEIO_FIFO_MASTER_TARGET,
                                            0,
                                            0,
                                            true /*SW error*/);
                errl->collectTrace(SBEIO_COMP_NAME);
                break;
            }

            SBE_TRACD(ENTER_MRK "requesting continueMPIPL on proc %d HB -> SBE  ",
                        i_procChip->getAttr<TARGETING::ATTR_POSITION>());

            SbeFifo::fifoContinueMpiplRequest   l_fifoRequest;
            SbeFifo::fifoContinueMpiplResponse  l_fifoResponse;

            l_fifoRequest.commandClass = SbeFifo::SBE_FIFO_CLASS_MPIPL_COMMANDS;
            l_fifoRequest.command = SbeFifo::SBE_FIFO_CMD_CONTINUE_MPIPL;


            errl = SbeFifo::getTheInstance().performFifoChipOp(i_procChip,
                                    (uint32_t *)&l_fifoRequest,
                                    (uint32_t *)&l_fifoResponse,
                                    sizeof(SbeFifo::fifoContinueMpiplResponse));

            SBE_TRACD(EXIT_MRK "sendContinueMpiplRequest");

        }while(0);

        return errl;
    };

} //end namespace SBEIO

