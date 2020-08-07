/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/test/testspi.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef __TEST_SPI_H
#define __TEST_SPI_H

#include <map>

#include <cxxtest/TestSuite.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <trace/interface.H>

#include <spi/spi.H>

#define SPI_TEST_IGNORE_DATA_COMPARE 0xFFFFFFFFFFFFFFFF

class SpiTestSuite : public CxxTest::TestSuite
{
public:
    void testSpiRead() const
    {
        TS_INFO(ENTER_MRK"testSpiRead");

        // Grab master proc
        TARGETING::Target* masterProc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(masterProc);

        struct TestData
        {
            TARGETING::Target* spiMaster;
            uint8_t engine;

            // Data to compare to.
            uint64_t data;
            // Length of read.
            size_t dataLength;
            // Offset to read from.
            uint64_t read_offset;

        };

        // Tests that are expected to not return errors.
        TestData testDataGood[] =
        {
            // Read from offset 0
            {masterProc, 0, 0x584950205345504d, 8, 0},

            // Read from offset 16
            {masterProc, 0, 0x44FC00000000ffff, 8, 16},

            // Read from offset 4
            {masterProc, 0, 0x5345504de7000000, 8, 4},

        };

        const uint32_t NUM_TESTS_GOOD = sizeof(testDataGood)
                                      / sizeof(testDataGood[0]);


        // Check Good tests
        for (size_t i = 0; i < NUM_TESTS_GOOD; i++)
        {
            const size_t TEST_NUMBER = i + 1;
            uint64_t buffer = 0;
            // Make sure the read size is 8 bytes so that it fits the buffer.
            if (testDataGood[i].dataLength != 8)
            {
                TS_TRACE("testSpiRead: data length (%d) is not 8 bytes. "
                         "Skipping good test %d",
                         testDataGood[i].dataLength,
                         TEST_NUMBER);
                continue;
            }

            // Perform a read and compare the data.
            errlHndl_t errl = deviceOp(
                                 DeviceFW::READ,
                                 testDataGood[i].spiMaster,
                                 &buffer,
                                 testDataGood[i].dataLength,
                                 DEVICE_SPI_EEPROM_ADDRESS(testDataGood[i].engine,
                                                    testDataGood[i].read_offset));

            if (errl)
            {
                TS_FAIL("testSpiRead: Failed on good test %d of %d with error.",
                        TEST_NUMBER,
                        NUM_TESTS_GOOD);
                errlCommit(errl,
                           SPI_COMP_ID);
                continue;
            }

            if (buffer != testDataGood[i].data)
            {
                TS_FAIL("testSpiRead: Good test %d/%d, Data read: "
                        "0x%016llx, expected 0x%016llx",
                        TEST_NUMBER,
                        NUM_TESTS_GOOD,
                        buffer,
                        testDataGood[i].data);
                continue;
            }
        }

        // =====================================================================
        // Test alignment adjusting
        // =====================================================================
        uint8_t engine = 0, cmds = 0, fails = 0;

        // Do a 1 byte read from offset 0. This will have the spi driver create
        // an expanded buffer of 8 bytes, do the read, and return the single
        // byte.
        do {
            // Data to compare to.
            uint8_t data = 0x58;
            // Length of read.
            size_t dataLength = 1;
            // Offset to read from.
            uint64_t read_offset = 0;

            uint8_t buffer = 0;

            // Perform a read and compare the data.
            ++cmds;
            errlHndl_t errl = deviceOp(
                                 DeviceFW::READ,
                                 masterProc,
                                 &buffer,
                                 dataLength,
                                 DEVICE_SPI_EEPROM_ADDRESS(engine,
                                                           read_offset));

            if (errl)
            {
                TS_FAIL("testSpiRead: unexpected deviceOp error occurred "
                        "during Alignment Adjustment Test %d.", cmds);
                errlCommit(errl,
                           SPI_COMP_ID);
                ++fails;
                break;
            }

            if (buffer != data)
            {
                TS_FAIL("testSpiRead: Alignment Adjustment Test %d. Read: "
                        "0x%016llx, Expected: 0x%016llx.",
                        cmds,
                        buffer,
                        data);
                ++fails;
            }
        } while(0);

        // Do a 4 byte read from offset 6. This crosses the alignment boundary
        // so the driver will have to create a 16 byte buffer, read the full 16,
        // and pass back the requested 4.
        do {

            // Data to compare to.
            uint8_t data[] = { 0x50, 0x4d,  0xe7, 0x00 };

            // Length of read.
            size_t dataLength = 4;

            // Offset to read from.
            uint64_t read_offset = 6;

            uint8_t* buffer = new uint8_t[dataLength];

            // Perform a read and compare the data.
            ++cmds;
            errlHndl_t errl = deviceOp(
                                 DeviceFW::READ,
                                 masterProc,
                                 buffer,
                                 dataLength,
                                 DEVICE_SPI_EEPROM_ADDRESS(engine,
                                                           read_offset));

            if (errl)
            {
                TS_FAIL("testSpiRead: unexpected deviceOp error occurred "
                        "during Alignment Adjustment Test %d.", cmds);
                errlCommit(errl,
                           SPI_COMP_ID);
                ++fails;
                delete[] buffer;
                break;
            }

            if (memcmp(buffer, data, dataLength) != 0)
            {
                TS_FAIL("testSpiRead: Alignment Adjustment Test %d: data read "
                        "didn't match expected data", cmds);
                TRACFBIN(g_trac_test, "Data Read", buffer, dataLength);
                TRACFBIN(g_trac_test, "Expected Data", data, dataLength);
                ++fails;
            }

            delete[] buffer;

        } while(0);

        // Do a 5 byte read from offset 3. This request is aligned to the upper
        // bounds of the 8 byte alignment window. The driver will expand the
        // buffer to be 8 bytes and read without crossing the alignment boundary
        do {
            // Data to compare to.
            uint8_t data[] = { 0x20, 0x53, 0x45, 0x50, 0x4d };
            // Length of read.
            size_t dataLength = 5;
            // Offset to read from.
            uint64_t read_offset = 3;

            uint8_t* buffer = new uint8_t[dataLength];

            // Perform a read and compare the data.
            ++cmds;
            errlHndl_t errl = deviceOp(
                                 DeviceFW::READ,
                                 masterProc,
                                 buffer,
                                 dataLength,
                                 DEVICE_SPI_EEPROM_ADDRESS(engine,
                                                           read_offset));

            if (errl)
            {
                TS_FAIL("testSpiRead: unexpected deviceOp error occurred "
                        "during Alignment Adjustment Test %d.", cmds);
                errlCommit(errl,
                           SPI_COMP_ID);
                ++fails;
                delete[] buffer;
                break;
            }

            if (memcmp(buffer, data, dataLength) != 0)
            {
                TS_FAIL("testSpiRead: Alignment Adjustment Test %d: data read "
                        "didn't match expected data", cmds);
                TRACFBIN(g_trac_test, "Data Read", buffer, dataLength);
                TRACFBIN(g_trac_test, "Expected Data", data, dataLength);
            }

            delete[] buffer;

        } while(0);

        TS_TRACE("testSpiRead: Alignment Adjustment Tests Failures %d/%d",
                 fails,
                 cmds);

    }

    void testSpiWrite() const
    {
        TS_INFO(ENTER_MRK"testSpiWrite");

        // Grab master proc
        TARGETING::Target* masterProc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(masterProc);

        struct TestData
        {
            TARGETING::Target* spiMaster;
            uint8_t engine;

            // Data to write to the device.
            uint64_t data;
            // Length of data to write.
            size_t dataLength;
            // Offset to write to.
            uint64_t write_offset;

        };

        // Tests that are expected to not return errors.
        TestData testDataGood[] =
        {
            // Write to offset 0
            {masterProc, 0, 0x1234567890ABCDEF, 8, 0},

            // Write to offset 16
            {masterProc, 0, 0x1234567890ABCDEF, 8, 16},

            // Write 8 bytes starting at offset 5
            {masterProc, 0, 0x1234567890ABCDEF, 8, 5},

            // Write 7 bytes starting at offset 0
            {masterProc, 0, 0x1234567890ABCD4D, 7, 0},
        };

        // Tests that are expected to return errors.
        TestData testDataBad[] =
        {

            // Write 0 bytes starting at offset 0. Bad Request Size.
            {masterProc, 0, SPI_TEST_IGNORE_DATA_COMPARE, 0, 0},

            // Write 7 bytes starting at offset 0. Bad Engine.
            {masterProc, 9, SPI_TEST_IGNORE_DATA_COMPARE, 7, 0},

        };

        const uint32_t NUM_TESTS_GOOD = sizeof(testDataGood)
                                      / sizeof(testDataGood[0]);

        const uint32_t NUM_TESTS_BAD = sizeof(testDataBad)
                                     / sizeof(testDataBad[0]);

        for (size_t i = 0; i < NUM_TESTS_GOOD; i++)
        {
            uint64_t original_data = 0, buffer = 0;
            const size_t TEST_NUMBER = i + 1;

            // Make sure the write size is 8 bytes so that it fits the buffer.
            if (testDataGood[i].dataLength != 8)
            {
                TS_TRACE("testSpiWrite: data length (%d) is not 8 bytes. "
                         "Skipping test %d",
                         testDataGood[i].dataLength,
                         TEST_NUMBER);
                continue;
            }

            // First read out the original data to restore to later on.
            errlHndl_t errl = deviceOp(
                                DeviceFW::READ,
                                testDataGood[i].spiMaster,
                                &original_data,
                                testDataGood[i].dataLength,
                                DEVICE_SPI_EEPROM_ADDRESS(testDataGood[i].engine,
                                                   testDataGood[i].write_offset));

            if (errl)
            {
                TS_FAIL("testSpiWrite: Unexpected error when saving original "
                        "data from SPI device during test %d of %d. "
                        "Moving on to the next test.",
                        TEST_NUMBER,
                        NUM_TESTS_GOOD);
                errlCommit(errl, SPI_COMP_ID);
                continue;
            }

            // Write the new data to the device.
            errl = deviceOp(
                     DeviceFW::WRITE,
                     testDataGood[i].spiMaster,
                     &testDataGood[i].data,
                     testDataGood[i].dataLength,
                     DEVICE_SPI_EEPROM_ADDRESS(testDataGood[i].engine,
                                        testDataGood[i].write_offset));

            if (errl)
            {
                TS_FAIL("testSpiWrite: Unexpected error when writing data to "
                        "the SPI device during test %d of %d. "
                        "Moving on to the next test.",
                        TEST_NUMBER,
                        NUM_TESTS_GOOD);
                errlCommit(errl, SPI_COMP_ID);
                continue;
            }

            // Read back the data that was written and compare.
            errl = deviceOp(
                     DeviceFW::READ,
                     testDataGood[i].spiMaster,
                     &buffer,
                     testDataGood[i].dataLength,
                     DEVICE_SPI_EEPROM_ADDRESS(testDataGood[i].engine,
                                        testDataGood[i].write_offset));

            if (errl)
            {
                TS_FAIL("testSpiWrite: Unexpected error when reading back "
                        "data written to SPI device during test %d of %d. "
                        "Moving on to the next test.",
                        TEST_NUMBER,
                        NUM_TESTS_GOOD);
                errlCommit(errl, SPI_COMP_ID);
                continue;
            }

            // Check that the data read was the data written.
            if (buffer != testDataGood[i].data)
            {
                TS_FAIL("testSpiWrite: Test %d/%d, Written data read back: "
                        "0x%016llx, expected data 0x%016llx",
                        TEST_NUMBER,
                        NUM_TESTS_GOOD,
                        buffer,
                        testDataGood[i].data);
                continue;
            }

            // Write back the original data
            errl = deviceOp(
                     DeviceFW::WRITE,
                     testDataGood[i].spiMaster,
                     &original_data,
                     testDataGood[i].dataLength,
                     DEVICE_SPI_EEPROM_ADDRESS(testDataGood[i].engine,
                                        testDataGood[i].write_offset));

            if (errl)
            {
                TS_FAIL("testSpiWrite: Unexpected error when restoring original"
                        " data from SPI device during test %d of %d. "
                        "Moving on to the next test.",
                        TEST_NUMBER,
                        NUM_TESTS_GOOD);
                errlCommit(errl, SPI_COMP_ID);
                continue;
            }

            // Verify that the original data has been written.
            errl = deviceOp(
                     DeviceFW::READ,
                     testDataGood[i].spiMaster,
                     &buffer,
                     testDataGood[i].dataLength,
                     DEVICE_SPI_EEPROM_ADDRESS(testDataGood[i].engine,
                                               testDataGood[i].write_offset));

            if (errl)
            {
                TS_FAIL("testSpiWrite: Unexpected error when reading "
                        "data from SPI device during test %d of %d. "
                        "Moving on to the next test.",
                        TEST_NUMBER,
                        NUM_TESTS_GOOD);
                errlCommit(errl, SPI_COMP_ID);
                continue;
            }

            // Verify that the original data is back.
            if (buffer != original_data)
            {
                TS_FAIL("testSpiWrite: Test %d/%d, Data read: "
                        "0x%016llx, expected 0x%016llx",
                        TEST_NUMBER,
                        NUM_TESTS_GOOD,
                        buffer,
                        original_data);
                continue;
            }
        }

        for (size_t i = 0; i < NUM_TESTS_BAD; i++)
        {
            // Test bad paths. Errors are expected for success.
            const size_t TEST_NUMBER = i + 1;
            // Make sure the write size is 8 bytes so that it fits the buffer.
            if (testDataBad[i].dataLength > 8)
            {
                TS_TRACE("testSpiWrite: data length (%d) is greater than 8 "
                         "bytes. Skipping test %d",
                         testDataBad[i].dataLength,
                         TEST_NUMBER);
                continue;
            }

            // For these tests reading the original data first would cause
            // errors before we are able to test doing bad writes. So, for these
            // tests we'll perform the writes without reading.
            errlHndl_t errl = deviceOp(
                                DeviceFW::WRITE,
                                testDataBad[i].spiMaster,
                                &testDataBad[i].data,
                                testDataBad[i].dataLength,
                                DEVICE_SPI_EEPROM_ADDRESS(testDataBad[i].engine,
                                                  testDataBad[i].write_offset));

            if (errl)
            {
                // Error was expected. Delete and continue
                delete errl;
                errl = nullptr;
                continue;
            }
            else if (errl == nullptr)
            {
                TS_FAIL("testSpiWrite: Expected an error for bad test %d of %d",
                        TEST_NUMBER,
                        NUM_TESTS_BAD);
                continue;
            }
        }
    }

    static void printSpiDeviceList(const std::vector<SPI::spiSlaveDevice>& i_deviceInfo)
    {
        using namespace SPI;

        TS_INFO("HDAT SPI device list:");

        for (const auto& device : i_deviceInfo)
        {
            TS_INFO("Device: me=%u mp=%u khz=%u type=%u purp=%u",
                    device.masterEngine,
                    device.masterPort,
                    device.busSpeedKhz,
                    device.deviceType,
                    device.devicePurpose);

            TS_INFO("        id=(%u,%u,%u) slca=%u",
                    device.deviceId.nodeOrdinal,
                    device.deviceId.procId,
                    device.deviceId.uniqueId,
                    device.residentFruSlcaIndex);

            TS_INFO("        description: %s,%s,%s,%s",
                    device.description.vendor,
                    device.description.deviceType,
                    device.description.dataTypeOrPurpose,
                    device.description.hwSubsystemOrScope);

            for (const auto& part : device.partitions)
            {
                TS_INFO("  Partition: offset=%u size=%u purp=%u",
                        part.offsetBytes,
                        part.sizeBytes,
                        part.partitionPurpose);

                TS_INFO("             writescom: addr=0x%x bitpos=%u pol=%u sticky=%u",
                        static_cast<unsigned>(part.writeAccessControl.scomAddress),
                        part.writeAccessControl.secureBitPosition,
                        part.writeAccessControl.bitPolarity,
                        part.writeAccessControl.sticky);

                TS_INFO("             readscom: addr=0x%x bitpos=%u pol=%u sticky=%u",
                        static_cast<unsigned>(part.readAccessControl.scomAddress),
                        part.readAccessControl.secureBitPosition,
                        part.readAccessControl.bitPolarity,
                        part.readAccessControl.sticky);
            }
        }
    }

    static void verifySpiSlaveIdUniqueness(const std::vector<SPI::spiSlaveDevice>& i_devices)
    {
        using namespace SPI;

        TS_INFO(ENTER_MRK"verifySpiSlaveIdUniqueness");

        union uniqueDeviceIdentifier
        {
            struct
            {
                uint8_t nodeId, procId, engine, zero;
            };

            uint32_t word = 0;
        };

        // A map from a unique nodeId+procId+engine value to a boolean
        // (functionally a "set" datatype) to keep track of what devices we've
        // already seen
        std::map<uint32_t, bool> deviceNodeProcEngine;
        std::map<uint32_t, bool> linkIds;

        for (const spiSlaveDevice& device : i_devices)
        {
            const uniqueDeviceIdentifier devid { { device.deviceId.nodeOrdinal,
                                                   device.deviceId.procId,
                                                   device.masterEngine,
                                                   0 } };

            // If we see a duplicate device with these markers, error out
            if (deviceNodeProcEngine.find(devid.word) != end(deviceNodeProcEngine))
            {
                TS_FAIL("Duplicate device node/proc/engine: "
                        "nodeId=%d, procId=%d, engine=%d",
                        devid.nodeId, devid.procId, devid.engine);
            }

            deviceNodeProcEngine[devid.word] = true;

            if (linkIds.find(device.deviceId.word) != end(linkIds))
            {
                TS_FAIL("Duplicate link ID: "
                        "nodeId=%d, procId=%d, linkId=%d",
                        devid.nodeId, devid.procId, device.deviceId.uniqueId);
            }

            linkIds[device.deviceId.word] = true;
        }

        TS_INFO(EXIT_MRK"verifySpiSlaveIdUniqueness");
    }

    void testSpiHdatInterface() const
    {
        TS_INFO(ENTER_MRK"testSpiHdatInterface");

        using namespace SPI;

        std::vector<spiSlaveDevice> deviceInfo;

        getSpiDeviceInfo(deviceInfo);

        if (deviceInfo.empty())
        {
            TS_FAIL("spi device info list is empty");
            return;
        }

        printSpiDeviceList(deviceInfo);

        verifySpiSlaveIdUniqueness(deviceInfo);

        TS_INFO(EXIT_MRK"testSpiHdatInterface");
    }

};

#endif
