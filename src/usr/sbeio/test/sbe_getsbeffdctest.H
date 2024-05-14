/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_getsbeffdctest.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2024                        */
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

        SbeFifoRespBuffer l_pFifoResponse(true);
        errlHndl_t        l_errl = nullptr;

        //  get a list of all functional procs in the system
        //
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList,
                    TARGETING::TYPE_PROC);

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
            return;
        }

        // loop thru all the cpu's
        for (const auto & l_cpu_target: l_cpuTargetList)
        {
            // Can't do FSI with SBE for master proc
            if(l_cpu_target == masterProcChipTargetHandle)
            {
                continue;
            }

            TS_TRACE("getSBEFFDCTest: testing proc 0x%.8X",
                     TARGETING::get_huid(l_cpu_target));

            l_errl = getFifoSBEFFDC(l_cpu_target,
                                    l_pFifoResponse);

            // Check that no error log was returned
            if (l_errl)
            {
                TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X, RC 0x%.8X",
                        TARGETING::get_huid(l_cpu_target),
                        l_errl->reasonCode());
                errlCommit( l_errl, CXXTEST_COMP_ID );
                continue;
            }

            if (!l_pFifoResponse.msgContainsFFDC())
            {
                TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X contains no FFDC",
                        TARGETING::get_huid(l_cpu_target));
                continue;
            }

            uint32_t l_ffdcSize = l_pFifoResponse.getFFDCByteSize();

            if (!l_ffdcSize)
            {
                TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X l_ffdcSize is zero",
                        TARGETING::get_huid(l_cpu_target));
                continue;
            }

            std::vector<uint8_t> l_ffdc;
            l_pFifoResponse.getFFDCData(l_ffdc);

            SbeFifo::ffdcHeader *l_pFfdcHeader =
                reinterpret_cast<SbeFifo::ffdcHeader *>(l_ffdc.data());

            if (l_pFfdcHeader->magic != SbeFifo::FIFO_FFDC_MAGIC)
            {
                TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X no FIFO_FFDC_MAGIC found",
                        TARGETING::get_huid(l_cpu_target));
            }

            SbeFifo::statusHeader l_pStatusHeader = l_pFifoResponse.getStatusHeader();

            // Check that status header has expected magic value
            if(l_pStatusHeader.magic != SbeFifo::FIFO_STATUS_MAGIC)
            {
                TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X with status "
                        "magic 0x%.4X, but expected 0x%.4X",
                        TARGETING::get_huid(l_cpu_target),
                        l_pStatusHeader.magic,
                        SbeFifo::FIFO_STATUS_MAGIC);
                continue;
            }

            // Check status header has expected command class and command
            if((l_pStatusHeader.commandClass !=
                SbeFifo::SBE_FIFO_CLASS_GENERIC_MESSAGE) ||
               (l_pStatusHeader.command !=
                SbeFifo::SBE_FIFO_CMD_GET_SBE_FFDC))
            {
                TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X with status "
                        "command 0x%.2x%.2x, but expected 0x%.2x%.2x",
                        TARGETING::get_huid(l_cpu_target),
                        l_pStatusHeader.commandClass,
                        l_pStatusHeader.command,
                        SbeFifo::SBE_FIFO_CLASS_GENERIC_MESSAGE,
                        SbeFifo::SBE_FIFO_CMD_GET_SBE_FFDC);
                continue;
            }

            // Check if status header has allowed unsupported status
            if((l_pStatusHeader.primaryStatus == SBE_PRI_INVALID_COMMAND)
               && (l_pStatusHeader.secondaryStatus ==
                SBE_SEC_COMMAND_NOT_SUPPORTED))
            {
                TS_TRACE("getSBEFFDCTest: proc 0x%.8X got response with "
                         "not supported status 0x%.4x / 0x%.4x",
                         TARGETING::get_huid(l_cpu_target),
                         l_pStatusHeader.primaryStatus,
                         l_pStatusHeader.secondaryStatus);
                continue;
            }

            // Check that status header has expected successful status
            if((l_pStatusHeader.primaryStatus !=
                SBE_PRI_OPERATION_SUCCESSFUL) ||
               (l_pStatusHeader.secondaryStatus !=
                SBE_SEC_OPERATION_SUCCESSFUL))
            {
                TS_FAIL("getSBEFFDCTest FAILED: proc 0x%.8X with status "
                        "0x%.4x / 0x%.4x, but expected 0x%.4x / 0x%.4x",
                        TARGETING::get_huid(l_cpu_target),
                        l_pStatusHeader.primaryStatus,
                        l_pStatusHeader.secondaryStatus,
                        SBE_PRI_OPERATION_SUCCESSFUL,
                        SBE_SEC_OPERATION_SUCCESSFUL);
                continue;
            }
        }

        TS_TRACE("getSBEFFDCTest exit");
    }
};

#endif
