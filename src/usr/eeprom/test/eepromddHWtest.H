/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/test/eepromddHWtest.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
*  @file eepromddHWtest.H
*
*  @brief Test cases for the eeprom dd hardware code
*/

#include <cxxtest/TestSuite.H>
#include "../eepromdd_hardware.H"
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <spi/spireasoncodes.H>

using namespace TARGETING;
using namespace EEPROM;

class EEPROMHWTest: public CxxTest::TestSuite
{
    public:
        /**
        * @brief testing eepromPerformOpHW()
        */
        void test_eepromPerformOpHW( void )
        {
            errlHndl_t l_err = nullptr;
            TS_INFO(ENTER_MRK"test_eepromPerformOpHW - Start");

            do
            {
                //Get a processor Target
                TARGETING::Target* l_testTarget = nullptr;
                l_err = TARGETING::targetService().queryMasterProcChipTargetHandle(l_testTarget);
                if (l_err)
                {
                    TS_FAIL("test_eepromPerformOpHW - Failed to find master processor");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }

                //Create dummy eeprom info w/ VPD_PRIMARY set
                const EEPROM_ROLE l_eepromRole = EEPROM::VPD_PRIMARY;
                eeprom_addr_t l_primaryVpdEeprom;
                l_primaryVpdEeprom.eepromRole = l_eepromRole;

                size_t l_buflen = 0;
                uint8_t l_buff[MAX_BYTE_ADDR] = {0};
                DeviceFW::OperationType l_opType = DeviceFW::LAST_OP_TYPE;
                //Set to INVALID_CHIP_TYPE to cause error from eepromReadAttributes()
                l_primaryVpdEeprom.eepromRole = EEPROM::INVALID_CHIP_TYPE;
                l_err = eepromPerformOpHW(l_opType, l_testTarget, l_buff, l_buflen, l_primaryVpdEeprom);
                if (l_err)
                {
                    if (l_err->reasonCode() == EEPROM_INVALID_CHIP)
                    {
                        TS_INFO("test_eepromPerformOpHW - eepromPerformOpHW()::eepromReadAttributes() "
                                "error created as expected (invalid eeprom role)");
                        delete l_err;
                        l_err = nullptr;
                    }
                    else
                    {
                        TS_FAIL("test_eepromPerformOpHW - eepromPerformOpHW()::eepromReadAttributes() "
                                "unexpected error created rc=0x%04X", l_err->reasonCode());
                        errlCommit( l_err, CXXTEST_COMP_ID );
                    }
                }
                else
                {
                    TS_FAIL("test_eepromPerformOpHW - eepromPerformOpHW()::eepromReadAttributes() "
                            "did not fail as expected");
                }
            }
            while(0);

            TS_INFO(EXIT_MRK"test_eepromPerformOpHW - End");
        }

        /**
        * @brief testing crossesEepromI2cPageBoundary()
        */
        void test_crossesBoundary( void )
        {
            errlHndl_t l_err = nullptr;
            TS_INFO(ENTER_MRK"test_crossesBoundary - Start");

            do
            {
                //Get a processor Target
                TARGETING::Target* l_testTarget = nullptr;
                l_err = TARGETING::targetService().queryMasterProcChipTargetHandle(l_testTarget);
                if (l_err)
                {
                    TS_FAIL("test_crossesBoundary - Failed to find master processor");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }

                //Create dummy eeprom info w/ VPD_PRIMARY set
                const EEPROM_ROLE l_eepromRole = EEPROM::VPD_PRIMARY;
                eeprom_addr_t l_primaryVpdEeprom;
                l_primaryVpdEeprom.eepromRole = l_eepromRole;

                //Set values to return true in crossesEepromI2cPageBoundary()
                l_primaryVpdEeprom.accessAddr.i2c_addr.addrSize = ONE_BYTE_ADDR_PAGESELECT;
                uint64_t l_offset = EEPROM_PAGE_SIZE - 2; //Set to value less than EEPROM_PAGE_SIZE
                size_t l_len = 10; //l_offset + l_len must be greater than EEPROM_PAGE_SIZE
                size_t l_newLen = 0;
                size_t l_buflen = 0;
                bool crosses = crossesEepromI2cPageBoundary(l_offset,
                                                            l_len,
                                                            l_newLen,
                                                            l_buflen,
                                                            l_primaryVpdEeprom);

                TS_INFO("test_crossesBoundary - crossesEepromI2cPageBoundary() - "
                        "new length: %d", l_newLen);

                if (!crosses)
                {
                    TS_FAIL("test_crossesBoundary - Error crossesEepromI2cPageBoundary() "
                            "should have returned True");
                }
            }
            while(0);

            TS_INFO(EXIT_MRK"test_crossesBoundary - End");
        }

        /**
        * @brief testing eepromSpiRead()
        */
        void test_eepromSpiRead( void )
        {
            errlHndl_t l_err = nullptr;
            TS_INFO(ENTER_MRK"test_eepromSpiRead - Start");

            do
            {
                //Get a processor Target
                TARGETING::Target* l_testTarget = nullptr;
                l_err = TARGETING::targetService().queryMasterProcChipTargetHandle(l_testTarget);
                if (l_err)
                {
                    TS_FAIL("test_eepromSpiRead - Failed to find master processor");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }

                //Create dummy eeprom info w/ VPD_PRIMARY set
                const EEPROM_ROLE l_eepromRole = EEPROM::VPD_PRIMARY;
                eeprom_addr_t l_primaryVpdEeprom;
                l_primaryVpdEeprom.eepromRole = l_eepromRole;

                eepromRecordHeader l_recordHeader;
                l_err = buildEepromRecordHeader(l_testTarget, l_primaryVpdEeprom, l_recordHeader);
                if (l_err)
                {
                    TS_FAIL("test_eepromSpiRead - Failed building eeprom record header");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                }

                uint8_t l_buffer[MAX_BYTE_ADDR] = {0};
                //Set buffer length to 0 to cause a failed read
                size_t l_buflen = 0;
                l_err = eepromSpiRead(l_testTarget, l_buffer, l_buflen, l_primaryVpdEeprom);

                if (l_err)
                {
                    if (l_err->reasonCode() == SPI::SPI_INVALID_BUFFER_SIZE)
                    {
                        TS_INFO("test_eepromSpiRead - eepromSpiRead() Error created as expected");
                        delete l_err;
                        l_err = nullptr;
                    }
                    else
                    {
                        TS_FAIL("test_eepromSpiRead - eepromSpiRead() Unexpected error created "
                                "rc=0x%04X", l_err->reasonCode());
                        errlCommit( l_err, CXXTEST_COMP_ID );
                    }
                }
                else
                {
                    TS_FAIL("test_eepromSpiRead - eepromSpiRead() did not fail as expected");
                }
            }
            while(0);

            TS_INFO(EXIT_MRK"test_eepromSpiRead - End");
        }
};