/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/test/mmiotest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
 *  @file mmiotest.H
 *
 *  @brief Test cases for MMIO code
 */

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <limits.h>
#include <devicefw/driverif.H>
#include "../mmio.H"
#include <targeting/common/utilFilter.H>
#include <explorer_scom_addresses.H>
#include <exp_oc_regs.H>
#include <sys/mmio.h>
#include <utils/chipids.H>
#include <test/exptest_utils.H>

#define SCOM2MMIO_ADDR(_ADDR) (EXPLR_IB_MMIO_OFFSET | (_ADDR << 3))
#define CNFG2MMIO_ADDR(_ADDR) (EXPLR_IB_CONFIG_OFFSET | _ADDR)
#define BYTESWAP64(_DATA) (__builtin_bswap64(_DATA))

static const uint64_t EXPLR_IB_CONFIG_OFFSET = 0x0000000000000000ull;
static const uint64_t EXPLR_IB_MMIO_OFFSET   = 0x0000000100000000ull; // 4GB

// NOTE: changing this address requires changes
//       to src/build/simics/standalone.simics
static const uint64_t EXPLR_INVALID_SCOM_ADDR =
                            EXPLR_TP_MB_UNIT_TOP_TRACE_TRDATA_CONFIG_0;

using namespace TARGETING;

class MmioTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief Test MMIO calls
     */
    void testExplrMMIO(void)
    {
        TS_INFO("testExplrMMIO> Start" );

        errlHndl_t l_err = nullptr;
        uint32_t regdata4 = 0;
        size_t op_size = 0;

        // Needed since the device operations could be using inband communication in error path
        HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR l_mutex = exptest::getTestMutex();
        if (l_mutex == nullptr)
        {
            TS_FAIL("testExplrMMIO: unable to get test mutex");
            return;
        }

        // >> atomic section
        mutex_lock(l_mutex);

        TargetHandle_t   explr_target = nullptr;

        do {

            // Get OCMB target, return if there is no OCMB
            TargetHandleList ocmb_target_list;
            getAllChips(ocmb_target_list, TYPE_OCMB_CHIP);
            if (ocmb_target_list.size() == 0)
            {
                TS_INFO("testExplrMMIO> No OCMB targets found.  Exiting.");
                break;
            }
            explr_target = ocmb_target_list[0];
            if(explr_target->getAttr<ATTR_CHIP_ID>() !=
                                                     POWER_CHIPID::EXPLORER_16)
            {
                TS_INFO("testExplrMMIO> No explorer targets found.  Exiting.");
                break;
            }

            // Make sure we're using MMIO to this explorer chip
            exptest::enableInbandScomsOcmb(explr_target);

            // valid read from config space register
            op_size = sizeof(regdata4);
            l_err = DeviceFW::deviceRead(
                              explr_target,
                              &regdata4,
                              op_size,
                              DEVICE_MMIO_ADDRESS(
                                  CNFG2MMIO_ADDR(EXPLR_OC_O0MBIT_O0DID_LSB),
                                  op_size));

            if(l_err != nullptr)
            {
                errlCommit(l_err, CXXTEST_COMP_ID);
                TS_FAIL("testExplrMMIO> Error for config read, RC=0x%04X",
                        ERRL_GETRC_SAFE(l_err));
            }

            // valid write to config space register
            op_size = sizeof(regdata4);
            l_err = DeviceFW::deviceWrite(
                              explr_target,
                              &regdata4,
                              op_size,
                              DEVICE_MMIO_ADDRESS(
                                  CNFG2MMIO_ADDR(EXPLR_OC_O0CCD_LSB),
                                  op_size));
            if(l_err != nullptr)
            {
                errlCommit(l_err, CXXTEST_COMP_ID);
                TS_FAIL("testExplrMMIO> Error for config write, RC=0x%04X",
                        ERRL_GETRC_SAFE(l_err));
            }

            // 1st valid write to SCOM register (also sets up
            // tests for forcing HW read/write failures)
            // EXPLR_TP_MB_UNIT_TOP_GIF2PCB_ERROR_REG = 0x080F0000
            // Set the PCB error bits (8:10) to binary 100, which means
            // 'invalid address'
            // NOTE: must byteswap to little endian before writing
            uint64_t GIF2PCB_INVALID_SCOM_ADDR_ERROR = 0x0080000000000000ull;
            uint64_t l_buffer64 = BYTESWAP64(GIF2PCB_INVALID_SCOM_ADDR_ERROR);
            op_size = sizeof(l_buffer64);
            l_err = DeviceFW::deviceWrite(
                              explr_target,
                              &l_buffer64,
                              op_size,
                              DEVICE_MMIO_ADDRESS(
                                 SCOM2MMIO_ADDR(
                                     EXPLR_TP_MB_UNIT_TOP_GIF2PCB_ERROR_REG),
                                 op_size));

            if(l_err != nullptr)
            {
                errlCommit(l_err, CXXTEST_COMP_ID);
                TS_FAIL("testExplrMMIO> Error for gif2pcb write, RC=0x%04X",
                        ERRL_GETRC_SAFE(l_err));
                break;
            }

            // 2nd valid write to SCOM register (also sets up
            // tests for forcing HW read/write failures)
            // EXPLR_TP_MB_UNIT_TOP_PIB2GIF_ERROR_REG = 0x080E0000
            // This register should contain a copy of the GIF2PCB error register
            // starting at bit 32
            // NOTE: must byteswap to little endian before writing data
            uint64_t PIB2GIF_INVALID_SCOM_ADDR_ERROR =
                            0x0000000000000000ull |
                            ((GIF2PCB_INVALID_SCOM_ADDR_ERROR &
                              0xffffc00000000000ull) >> 32);
            l_buffer64 = BYTESWAP64(PIB2GIF_INVALID_SCOM_ADDR_ERROR);
            op_size = sizeof(l_buffer64);
            l_err = DeviceFW::deviceWrite(
                              explr_target,
                              &l_buffer64,
                              op_size,
                              DEVICE_MMIO_ADDRESS(
                                    SCOM2MMIO_ADDR(
                                        EXPLR_TP_MB_UNIT_TOP_PIB2GIF_ERROR_REG),
                                    op_size));

            if(l_err != nullptr)
            {
                errlCommit(l_err, CXXTEST_COMP_ID);
                TS_FAIL("testExplrMMIO> Error for pib2gif write, RC=0x%04X",
                        ERRL_GETRC_SAFE(l_err));
                break;
            }

            // Write to an "invalid" scom address.  Should
            // return with failure (now that we've set up the error regs).
            // EXPLR_INVALID_SCOM_ADDR =
            //   EXPLR_TP_MB_UNIT_TOP_TRACE_TRDATA_CONFIG_0 = 0x08010403
            // NOTE: Also, writing MMIO_OCMB_UE_DETECTED to this register
            //       sets up the following read to the same register
            //       to fail.
            l_buffer64 = MMIO_OCMB_UE_DETECTED;
            op_size = sizeof(l_buffer64);
            l_err = DeviceFW::deviceWrite(
                              explr_target,
                              &l_buffer64,
                              op_size,
                              DEVICE_MMIO_ADDRESS(
                                  SCOM2MMIO_ADDR(EXPLR_INVALID_SCOM_ADDR),
                                  op_size));
            if(l_err == nullptr)
            {
                ScomSwitches l_switches =
                    explr_target->getAttr<ATTR_SCOM_SWITCHES>();
                TS_INFO("testExplrMMIO: Current SCOM mode: %s",
                        (l_switches.useInbandScom)? "MMIO": "I2C");
                TS_FAIL("testExplrMMIO> "
                        "did not recieve expected failure on mmio write");
                break;
            }
            else
            {
                TS_INFO("testExplrMMIO> "
                        "received expected failure on mmio write");
                delete l_err;
                l_err = nullptr;
            }

            // Re-enable inband scoms after failure disables it
            exptest::enableInbandScomsOcmb(explr_target);

            // Read from an "invalid" scom address.  Should
            // return with failure (now that we've set up the error regs).
            op_size = sizeof(l_buffer64);
            l_err = DeviceFW::deviceRead(
                              explr_target,
                              &l_buffer64,
                              op_size,
                              DEVICE_MMIO_ADDRESS(
                                  SCOM2MMIO_ADDR(EXPLR_INVALID_SCOM_ADDR),
                                  op_size));

            if(l_err == nullptr)
            {
                ScomSwitches l_switches =
                    explr_target->getAttr<ATTR_SCOM_SWITCHES>();
                TS_INFO("testExplrMMIO> "
                        "data read from invalid address: 0x%016llx",
                        l_buffer64);
                TS_INFO("testExplrMMIO: Current SCOM mode: %s",
                        (l_switches.useInbandScom)? "MMIO": "I2C");
                TS_FAIL("testExplrMMIO> "
                        "did not recieve expected failure on mmio read");
            }
            else
            {
                TS_INFO("testExplrMMIO> "
                        "received expected failure on mmio read");
                delete l_err;
                l_err = nullptr;
            }

        } while (0);

        // Re-enable inband scoms after failure disables it
        if(explr_target != nullptr)
        {
            exptest::enableInbandScomsOcmb(explr_target);
        }

        // << atomic section
        mutex_unlock(l_mutex);
        TS_INFO("testExplrMMIO> Done");
    };
};
