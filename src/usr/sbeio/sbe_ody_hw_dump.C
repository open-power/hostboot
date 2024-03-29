/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_ody_hw_dump.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioif.H>
#include <targeting/common/targetservice.H>

using namespace SBEIO;
using namespace TARGETING;

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"getFifoSBEFFDC: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"getFifoSBEFFDC: " printf_string,##args)

enum fifoGetDumpClockState : uint8_t {
    CLOCKS_ON = 1,
    CLOCKS_OFF = 2
};

enum fifoGetDumpType : uint8_t {
    SYSTEM_CHECK_STOP_DUMP = 1,
    MPIPL_DUMP = 2,
    SYSTEM_PERFORMANCE_DUMP = 3,
    CORE_CHECKSTOP_DUMP = 4,
    HOSTBOOT_DUMP = 5
};

errlOwner SBEIO::getOdysseyHardwareDump(Target* const i_ocmb,
                                        uint8_t* const i_buffer,
                                        uint32_t& io_buffer_size)
{
    SBE_TRACF(ENTER_MRK"getOdysseyHardwareDump(0x%08X)",
              get_huid(i_ocmb));

    uint32_t buffer_size = io_buffer_size;
    io_buffer_size = 0;

    SbeFifo::fifoGetDumpRequest req;
    req.collectFastArray = 0;
    req.clockState = fifoGetDumpClockState::CLOCKS_ON;
    req.dumpType = fifoGetDumpType::MPIPL_DUMP;

    errlHndl_t errl
        = SbeFifo::getTheInstance()
            .performFifoChipOp(i_ocmb,
                               reinterpret_cast<uint32_t*>(&req),
                               reinterpret_cast<uint32_t*>(i_buffer),
                               buffer_size,
                               io_buffer_size);


    SBE_TRACF(EXIT_MRK"getOdysseyHardwareDump(0x%08X) = 0x%08X",
              get_huid(i_ocmb),
              ERRL_GETEID_SAFE(errl));

    return errlOwner { errl };
}
