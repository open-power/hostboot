/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_halt.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
* @file sbe_halt.C
* @brief Halt messages to inform the SBE to stop.
*/

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"halt: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"halt: " printf_string,##args)


namespace SBEIO
{
    errlHndl_t sendSecondarySbeHaltRequest(TARGETING::Target * i_procChip)
    {
        errlHndl_t errl = nullptr;
        // check for boot proc
        TARGETING::Target * l_boot_proc = nullptr;


        do
        {
            errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_boot_proc);
            if (errl)
            {
                SBE_TRACF(ERR_MRK"Unable to find boot processor target");
                break;
            }

            // look for NULL
            if( nullptr == i_procChip ||
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_procChip ||
                i_procChip == l_boot_proc)
            {
                SBE_TRACF(ERR_MRK"Processor passed in (0x%08X) is either the boot processor or nullptr",
                    TARGETING::get_huid(i_procChip));
                /*@
                * @errortype
                * @moduleid     SBEIO_FIFO_HALT
                * @reasoncode   SBEIO_FIFO_MASTER_TARGET
                * @userdata1    The processor chip HUID
                * @devdesc      Attempted FIFO chip op on invalid processor
                * @custdesc     Internal firmware error
                */
                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          SBEIO_FIFO_HALT,
                                          SBEIO_FIFO_MASTER_TARGET,
                                          TARGETING::get_huid(i_procChip),
                                          0,
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                errl->collectTrace(SBEIO_COMP_NAME);
                break;
            }

            SBE_TRACF(ENTER_MRK "requesting halt on proc 0x%08X SBE  ",
                    TARGETING::get_huid(i_procChip));

            SbeFifo::fifoHostCommandsRequest l_fifoRequest;

            l_fifoRequest.commandClass = SbeFifo::SBE_FIFO_CLASS_HOST_COMMANDS;
            l_fifoRequest.command = SbeFifo::SBE_FIFO_CMD_HOST_HALT;

            // Just run the command.  Halt command does not have a response
            errl = SbeFifo::getTheInstance().performFifoChipOp(
                            i_procChip,
                            reinterpret_cast<uint32_t*>(&l_fifoRequest),
                            nullptr,
                            0 );

            SBE_TRACF(EXIT_MRK "sendSecondarySbeHaltRequest");

        } while(0);

        return errl;
    };

} //end namespace SBEIO

