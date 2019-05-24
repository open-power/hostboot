/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/test/mmiotest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#include "../mmio.H"
#include <targeting/common/utilFilter.H>
#include <explorer_scom_addresses.H>
#include <exp_oc_regs.H>

static const uint64_t EXPLR_IB_CONFIG_OFFSET = 0x0000000000000000ull;
static const uint64_t EXPLR_IB_MMIO_OFFSET   = 0x0000000100000000ull; // 4GB

class MmioTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief Test valid MMIO calls
     */
    void test_Valid(void)
    {
        TS_TRACE("MmioTest::test_Valid> Start" );

        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t l_err = nullptr;
        uint32_t regdata4 = 0;
        size_t op_size = 0;

        // Get OCMB target, return if there is no OCMB
        TARGETING::TargetHandle_t   ocmb_target = nullptr;
        TARGETING::TargetHandleList ocmb_target_list;
        TARGETING::getAllChips(ocmb_target_list, TARGETING::TYPE_OCMB_CHIP);
        if (ocmb_target_list.size() == 0)
        {
            TS_TRACE("MmioTest::test_Valid> Target is NULL");
            TS_INFO("MmioTest::test_Valid> Target is NULL");
            return;
        }
        ocmb_target = ocmb_target_list[0];

        // valid read from config space register
        ++total;
        op_size = sizeof(regdata4);
        l_err = DeviceFW::deviceRead(
                          ocmb_target,
                          &regdata4,
                          op_size,
                          DEVICE_MMIO_ADDRESS((EXPLR_IB_CONFIG_OFFSET |
                                               EXPLR_OC_O0MBIT_O0DID_LSB),
                                               op_size));
        if(l_err != nullptr)
        {
            TS_TRACE("MmioTest::test_Valid> Error for read, RC=0x%04X",
                      ERRL_GETRC_SAFE(l_err));
            TS_FAIL("MmioTest::test_Valid> Error for read, RC=0x%04X",
                    ERRL_GETRC_SAFE(l_err));
            ++fails;
            errlCommit(l_err, CXXTEST_COMP_ID);
        }

        // valid write to config space register
        ++total;
        op_size = sizeof(regdata4);
        l_err = DeviceFW::deviceWrite(
                          ocmb_target,
                          &regdata4,
                          op_size,
                          DEVICE_MMIO_ADDRESS((EXPLR_IB_CONFIG_OFFSET |
                                               EXPLR_OC_O0CCD_LSB),
                                               op_size));
        if(l_err != nullptr)
        {
            TS_TRACE("MmioTest::test_Valid> Error for write, RC=0x%04X",
                     ERRL_GETRC_SAFE(l_err));
            TS_FAIL("MmioTest::test_Valid> Error for write, RC=0x%04X",
                    ERRL_GETRC_SAFE(l_err));
            ++fails;
            errlCommit(l_err, CXXTEST_COMP_ID);
        }

        TS_TRACE("Mmio::test_Valid> %d/%d fails", fails, total);
    };
};
