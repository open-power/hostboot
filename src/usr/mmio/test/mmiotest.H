/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/test/mmiotest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2023                        */
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
#ifndef __MMIOTEST_H
#define __MMIOTEST_H

#include <cxxtest/TestSuite.H>
#include <cxxtest/TestInject.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <limits.h>
#include <devicefw/driverif.H>
#include <mmio/mmio.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/attributes.H>
#include <targeting/common/utilFilter.H>
#include <targeting/odyutil.H>
#include <explorer_scom_addresses.H>
#include <exp_oc_regs.H>
#include <ody_oc_regs.H>
#include <sys/mmio.h>
#include <utils/chipids.H>
#include <test/exptest_utils.H>
#include <arch/magic.H>
#include <console/consoleif.H>

#include <initservice/isteps_trace.H>
#include <sbeio/sbe_getCodeLevels.H>
#include <ody_code_getlevels.H>

#include <mmio/test/mmiotest_common.H>

#ifndef __HOSTBOOT_RUNTIME
#include <sbeio/sbe_fifodd.H>
#endif

#define SCOM2MMIO_ADDR(_ADDR) (EXPLR_IB_MMIO_OFFSET | (_ADDR << 3))
#define CNFG2MMIO_ADDR(_ADDR) (EXPLR_IB_CONFIG_OFFSET | _ADDR)
#define BYTESWAP64(_DATA) (__builtin_bswap64(_DATA))

static const uint64_t EXPLR_IB_CONFIG_OFFSET = 0x0000000000000000ull;
static const uint64_t EXPLR_IB_MMIO_OFFSET   = 0x0000000100000000ull; // 4GB

// NOTE: changing this address requires changes
//       to src/build/simics/standalone.simics
// @TODO PFHB-530 Fix Explorer MMIO Error Path Testcases
static const uint64_t EXPLR_INVALID_SCOM_ADDR = 0x80109999;


using namespace ISTEPS_TRACE;
using namespace TARGETING;
using namespace ERRORLOG;
using namespace CxxTest;


class MmioTest : public TestSuite
{
  public:
    /**
     * @brief  Execute CI for mmio
     */
    void testOdyMMIO(void)
    {
        runOdyMmioCI();
        return;
    }

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
            // EXPLR_INVALID_SCOM_ADDR = 0x80109999
            // NOTE: Also, writing MMIO_OCMB_UE_DETECTED to this register
            //       sets up the following read to the same register
            //       to fail.
            // @TODO PFHB-530 Fix Explorer MMIO Error Path Testcases
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
                        "did not receive expected failure on mmio write");
                break;
            }
            else
            {
                TS_INFO("testExplrMMIO> "
                        "received expected failure on mmio write, Expect to see Error deleted without commit");
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
                        "received expected failure on mmio read, Expect to see Error deleted without commit");
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


    /**
     * @brief test_write: This function writes to the specified address
     */
    errlHndl_t test_write(uint64_t i_regaddr, Target *i_tgt, uint64_t i_data)
    {
        size_t l_numBytes = 8;
        errlHndl_t l_err = nullptr;

        l_err = DeviceFW::deviceOp(DeviceFW::WRITE, i_tgt,
                                   reinterpret_cast<uint8_t *>(&i_data),
                                   l_numBytes,
                                   DEVICE_SCOM_ADDRESS(i_regaddr));
        if (l_err)
        {
            TS_INFO( "Inband_Scom_DBG> Write Error");
        }
        else
        {
            TS_INFO( "Inband_Scom_DBG> %.8X=%.16X", i_regaddr, i_data );
        }
        return (l_err);
    }


    /**
     * @brief test_read: This function reads from a multicast address
     */
    errlHndl_t test_read(uint64_t i_regaddr, Target *i_tgt, uint8_t *io_buffer)
    {
        size_t l_numBytes = 8;
        errlHndl_t l_err = nullptr;

        l_err = DeviceFW::deviceOp(DeviceFW::READ, i_tgt, io_buffer, l_numBytes,
                                   DEVICE_SCOM_ADDRESS(i_regaddr));
        if (l_err)
        {
            TS_INFO( "Inband_Scom_DBG> Read Error" );
        }
        else
        {
            TS_INFO( "Inband_Scom_DBG> %.8X=%.16X",
                     i_regaddr, *(reinterpret_cast<uint64_t *>(io_buffer)) );
        }
        return (l_err);
    }

    /**
     * @brief Test Odyssey Multicast Scom operations
     */
    void testOdyMulticastScom(void)
    {
        errlHndl_t l_err = nullptr;
        uint8_t l_fails = 0;
        uint8_t l_total = 0;

        TS_INFO("testOdyMulticastScom> Start" );
        // Needed since the device operations could be using inband communication in error path
        HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR l_mutex = exptest::getTestMutex();
        if (l_mutex == nullptr)
        {
            TS_FAIL("testOdyMulticastScom: unable to get test mutex");
            return;
        }

        // >> atomic section
        mutex_lock(l_mutex);

        do {
            //Get all OCMB targets
            TargetHandleList l_ocmbTargetList;
            getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

            if (l_ocmbTargetList.empty())
            {
                TS_INFO("testOdyMulticastScom> No OCMB targets found.  Exiting.");
                break;
            }

            for (const auto l_ocmb_target : l_ocmbTargetList)
            {
                uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();

                // Ensure we are dealing with Odyssey Chip and not Explorer
                if (chipId != POWER_CHIPID::ODYSSEY_16)
                {
                    TS_INFO("Skipping non-Odyssey target!");
                    continue;
                }

                // For the Odyssey chips, we emulate the multicast
                // behavior by doing unicast scom operations to the
                // two chiplets associated with the Odyssey chip.
                // The two chiplets have IDs 0x01 & 0x08.
                // Basically the defined MMIO address range for the
                // Odyssey inband scom address does not have enough
                // bits to hold the multicast address. Hence, there
                // is a workaround in place to do the manual scom
                // operations to the two chiplets.
                //
                // Here the tests will do unicast scom writes to the
                // the two chiplets and read back the value as a
                // multicast operation. It will test both the OR
                // and the bit-wise mode.

                constexpr uint64_t CHIPLET1  = 0x010f001e;
                constexpr uint64_t CHIPLET2  = 0x080f001e;
                constexpr uint64_t MC_OR_ADDR      = 0x470f001e;
                constexpr uint64_t MC_BITWISE_ADDR = 0x570f001e;
                constexpr uint64_t DATA1 = 0xA0A0A0A0B0B0B0B0;
                constexpr uint64_t DATA2 = 0x0909090908080808;
                size_t l_numBytes = 8;
                uint8_t l_buf[8] = {0};
                uint64_t l_expected = DATA1 | DATA2;

                l_total++;

                l_err = test_write(CHIPLET1, l_ocmb_target, DATA1);
                if (l_err)
                {
                    TS_FAIL("testOdyMulticastScom: Failed writing 0x%llX to 0x%llX"
                            " target huid= 0x%.8X",
                            DATA1, CHIPLET1, get_huid(l_ocmb_target) );
                    l_fails++;
                    errlCommit (l_err, CXXTEST_COMP_ID);
                    continue;
                }
                l_err = test_write(CHIPLET2, l_ocmb_target, DATA2);

                if (l_err)
                {
                    TS_FAIL("testOdyMulticastScom: Failed writing 0x%llX to 0x%llX"
                            " target huid= 0x%.8X",
                            DATA2, CHIPLET2, get_huid(l_ocmb_target) );
                    l_fails++;
                    errlCommit (l_err, CXXTEST_COMP_ID);
                    continue;
                }

                // Read back from this target and verify the multicast OR mode
                l_err = test_read(MC_OR_ADDR, l_ocmb_target, l_buf);
                if (l_err)
                {
                    TS_FAIL("testOdyMulticastScom: Failed reading from 0x%llX"
                            " target huid= 0x%.8X", MC_OR_ADDR, get_huid(l_ocmb_target));
                    l_fails++;
                    errlCommit (l_err, CXXTEST_COMP_ID);
                    continue;
                }

                if (memcmp(l_buf, &l_expected, l_numBytes))
                {
                    TS_FAIL("testOdyMulticastScom: Read:0x%llX Exp:0x%llX",
                            *reinterpret_cast<uint64_t *>(l_buf), l_expected);
                    l_fails++;
                }
                else
                {
                    TS_INFO("testOdyMulticastScom: Matched Read:0x%llX Exp:0x%llX",
                            *reinterpret_cast<uint64_t *>(l_buf), l_expected);
                }

                // Read back from this target and verify the multicast BITWISE mode
                l_total++;
                memset(l_buf, 0, sizeof(l_buf));
                l_expected = 0x0ULL;
                if ( DATA1 & 0x8000000000000000 )
                {
                    // DATA1 was written to chiplet with ID=0x01
                    l_expected |= (0x8000000000000000 >> 0x01);
                }
                if ( DATA2 & 0x8000000000000000 )
                {
                    // DATA2 was written to chiplet with ID=0x08
                    l_expected |= (0x8000000000000000 >> 0x08);
                }

                l_err = test_read(MC_BITWISE_ADDR, l_ocmb_target, l_buf);
                if (l_err)
                {
                    TS_FAIL("testOdyMulticastScom: Failed reading from 0x%llX"
                            " target huid= 0x%.8X", MC_BITWISE_ADDR, get_huid(l_ocmb_target));
                    l_fails++;
                    errlCommit (l_err, CXXTEST_COMP_ID);
                    continue;
                }

                if (memcmp(l_buf, &l_expected, l_numBytes))
                {
                    TS_FAIL("testOdyMulticastScom: Read:0x%llX Exp:0x%llX",
                            *reinterpret_cast<uint64_t *>(l_buf), l_expected);
                    l_fails++;
                }
                else
                {
                    TS_INFO("testOdyMulticastScom: Matched Read:0x%llX Exp:0x%llX",
                            *reinterpret_cast<uint64_t *>(l_buf), l_expected);
                }
            } // end of for loop
        } while (0);

        // << atomic section
        mutex_unlock(l_mutex);

        TS_INFO("testOdyMulticastScom: End: test total:%d failed:%d", l_total, l_fails);
    }
};

#endif
