/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_getsbeffdctest.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
#ifndef __SBE_GETSBEFFDCTEST_H
#define __SBE_GETSBEFFDCTEST_H

/**
 *  @file sbe_getsbeffdctest.H
 *
 *  @brief Test cases for get sbe ffdc fifo request
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_sp_intf.H>
#include <sbe_fifodd.H>
#include <sbe_fifo_buffer.H>
#include <arch/magic.H>
#include <algorithm>

using namespace SBEIO;

#define SBEFFDC_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"getSBEFFDCTest: " printf_string,##args)

extern trace_desc_t* g_trac_sbeio;

class GetSBEFFDCTest : public CxxTest::TestSuite
{
    public:

    /**
     *  @brief Test with zero data
     */
    void testgetSBEFFDC1(void)
    {
        TS_TRACE("getSBEFFDCTest entry");

        errlHndl_t l_errl = nullptr;
        uint32_t l_responseSize = SbeFifoRespBuffer::MSG_BUFFER_SIZE_WORDS * sizeof(uint32_t);
        uint32_t *l_pFifoResponse =
            reinterpret_cast<uint32_t *>(malloc(l_responseSize));

        //
        //  get a list of all functional procs in the system
        //
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList,
                    TARGETING::TYPE_PROC);

        SBEFFDC_TRACF("%d proc(s) in the system.",
                      l_cpuTargetList.size() );

        //
        //  get the master procs for the system
        //
        TARGETING::Target* masterProcChipTargetHandle = NULL;
        l_errl = TARGETING::targetService().
            queryMasterProcChipTargetHandle(masterProcChipTargetHandle);
        if(l_errl)
        {
            TS_FAIL("getSBEFFDCTest FAILED: query master proc, RC 0x%.8X",
                    l_errl->reasonCode());

            errlCommit( l_errl, CXXTEST_COMP_ID );

        }
        else
        {
            // loop thru all the cpu's
            for (const auto & l_cpu_target: l_cpuTargetList)
            {
                // Can't do FSI with SBE for master proc
                if(l_cpu_target == masterProcChipTargetHandle)
                {
                    TS_TRACE("getSBEFFDCTest: Skipping testing for master "
                             "proc 0x%.8X",
                             TARGETING::get_huid(l_cpu_target));

                    continue;
                }

                l_errl = getFifoSBEFFDC(l_cpu_target,
                                        l_pFifoResponse,
                                        l_responseSize);

                // Check that no error log was returned
                if(l_errl != nullptr)
                {
                    TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X, RC 0x%.8X",
                            TARGETING::get_huid(l_cpu_target),
                            l_errl->reasonCode());
                    errlCommit( l_errl, CXXTEST_COMP_ID );
                    break;
                }

                uint32_t dumpsize = std::min( l_responseSize, (uint32_t)256 );
                TRACFCOMP(g_trac_sbeio,"response size=%d bytes long",l_responseSize);
                TRACFBIN(g_trac_sbeio,"response",l_pFifoResponse, dumpsize);

                // Find the status header after the return data, ie, FFDC
                uint32_t l_size = 0;
                SbeFifo::ffdcHeader *l_pFfdcHeader =
                    reinterpret_cast<SbeFifo::ffdcHeader *>(l_pFifoResponse);
                uint64_t l_firstFfdcHeaderAddr =
                        reinterpret_cast<uint64_t>(l_pFfdcHeader);

                while(l_pFfdcHeader->magic == SbeFifo::FIFO_FFDC_MAGIC)
                {
                    l_size += l_pFfdcHeader->lengthWords * sizeof(uint32_t);
                    l_pFfdcHeader = reinterpret_cast<SbeFifo::ffdcHeader *>
                        (l_firstFfdcHeaderAddr + l_size);
                };

                SbeFifo::statusHeader *l_pStatusHeader = reinterpret_cast<
                    SbeFifo::statusHeader *>(l_firstFfdcHeaderAddr + l_size);

                // Check that status header has expected magic value
                if(l_pStatusHeader->magic != SbeFifo::FIFO_STATUS_MAGIC)
                {
                    TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X with status "
                            "magic 0x%.4X, but expected 0x%.4X",
                            TARGETING::get_huid(l_cpu_target),
                            l_pStatusHeader->magic,
                            SbeFifo::FIFO_STATUS_MAGIC);
                    break;
                }

                // Check status header has expected command class and command
                if((l_pStatusHeader->commandClass !=
                    SbeFifo::SBE_FIFO_CLASS_GENERIC_MESSAGE) ||
                   (l_pStatusHeader->command !=
                    SbeFifo::SBE_FIFO_CMD_GET_SBE_FFDC))
                {
                    TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X with status "
                            "command 0x%.2x%.2x, but expected 0x%.2x%.2x",
                            TARGETING::get_huid(l_cpu_target),
                            l_pStatusHeader->commandClass,
                            l_pStatusHeader->command,
                            SbeFifo::SBE_FIFO_CLASS_GENERIC_MESSAGE,
                            SbeFifo::SBE_FIFO_CMD_GET_SBE_FFDC);

                    break;
                }

                // Check if status header has allowed unsupported status
                if((l_pStatusHeader->primaryStatus == SBE_PRI_INVALID_COMMAND)
                   && (l_pStatusHeader->secondaryStatus ==
                    SBE_SEC_COMMAND_NOT_SUPPORTED))
                {
                    TS_TRACE("getSBEFFDCTest: proc 0x%.8X got response with "
                             "not supported status 0x%.4x / 0x%.4x",
                             TARGETING::get_huid(l_cpu_target),
                             l_pStatusHeader->primaryStatus,
                             l_pStatusHeader->secondaryStatus);

                    break;
                }

                // Check that status header has expected successful status
                if((l_pStatusHeader->primaryStatus !=
                    SBE_PRI_OPERATION_SUCCESSFUL) ||
                   (l_pStatusHeader->secondaryStatus !=
                    SBE_SEC_OPERATION_SUCCESSFUL))
                {
                    TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X with status "
                            "0x%.4x / 0x%.4x, but expected 0x%.4x / 0x%.4x",
                            TARGETING::get_huid(l_cpu_target),
                            l_pStatusHeader->primaryStatus,
                            l_pStatusHeader->secondaryStatus,
                            SBE_PRI_OPERATION_SUCCESSFUL,
                            SBE_SEC_OPERATION_SUCCESSFUL);

                    break;
                }
            }
        }

        free(l_pFifoResponse);
        l_pFifoResponse = nullptr;

        TS_TRACE("getSBEFFDCTest exit");
    }
};

#endif
