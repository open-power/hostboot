/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/test/mmiotest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2018                        */
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
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <limits.h>
#include <devicefw/driverif.H>
#include <mmio/mmio.H>

extern trace_desc_t* g_trac_mmio;

class MmioTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief Test valid MMIO calls
     */
    void test_Valid(void)
    {
        TRACFCOMP( g_trac_mmio, "MmioTest::test_Valid> Start" );

        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t l_err = nullptr;
        uint64_t regdata = 0;
        size_t op_size = sizeof(uint64_t);

// TODO RTC 202533 - enable this test once the Axone model is IPLing
// successfully in Simics.
#if 0
        // Get OCMB target, return if there is no OCMB
        TARGETING::TargetHandle_t   ocmb_target = nullptr;
        TARGETING::TargetHandleList ocmb_target_list;
        getAllChips(ocmb_target_list, TARGETING::TYPE_OCMB_CHIP);
        if (ocmb_target_list.size() == 0)
        {
            TRACFCOMP(g_trac_fsiscom, "MmioTest::test_Valid> Target is NULL");
            TS_INFO("MmioTest::test_Valid> Target is NULL");
            return;
        }
        ocmb_target = ocmb_target_list[0];

        // read
        ++total;
        l_err = MMIO::mmioPerformOp(
                          DeviceFW::READ,
                          ocmb_target,
                          &regdata,
                          op_size,
                          0x0,
                          op_size);
        if(l_err != nullptr)
        {
            TRACFCOMP(g_trac_mmio,
                      "MmioTest::test_Valid> Error for read, RC=0x%04X",
                      ERRL_GETRC_SAFE(l_err));
            TS_FAIL("MmioTest::test_Valid> Error for read, RC=0x%04X",
                    ERRL_GETRC_SAFE(l_err));
            ++fails;
            errlCommit(l_err, MMIO_COMP_ID);
        }

        // write
        ++total;
        l_err = MMIO::mmioPerformOp(
                          DeviceFW::WRITE,
                          ocmb_target,
                          &regdata,
                          op_size,
                          0x08,
                          op_size);
        if(l_err != nullptr)
        {
            TRACFCOMP(g_trac_mmio,
                      "MmioTest::test_Valid> Error for write, RC=0x%04X",
                      ERRL_GETRC_SAFE(l_err));
            TS_FAIL("MmioTest::test_Valid> Error for write, RC=0x%04X",
                    ERRL_GETRC_SAFE(l_err));
            ++fails;
            errlCommit(l_err, MMIO_COMP_ID);
        }
#endif

        TRACFCOMP(g_trac_mmio, "Mmio::test_Valid> %d/%d fails", fails, total);
    };
};
