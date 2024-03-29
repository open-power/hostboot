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
#include <devicefw/devfwreasoncodes.H>
#include <i2c/i2creasoncodes.H>

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

        /**
        * @brief testing eepromPrepareI2cAddress()
        */
        void test_eepromPrepareI2cAddress( void )
        {
            errlHndl_t l_err = nullptr;
            TS_INFO(ENTER_MRK"test_eepromPrepareI2cAddress - Start");

            do
            {
                //Get a processor Target
                TARGETING::Target* l_testTarget = nullptr;
                l_err = TARGETING::targetService().queryMasterProcChipTargetHandle(l_testTarget);
                if (l_err)
                {
                    TS_FAIL("test_eepromPrepareI2cAddress - Failed to find master processor");
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
                    TS_FAIL("test_eepromPrepareI2cAddress - Failed building eeprom record header");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }

                uint8_t l_buf[MAX_BYTE_ADDR] = {0};
                size_t l_buflen = 0;
                uint8_t l_desiredPage = 0;

                //Set address offset to ZERO_BYTE_ADDR
                l_primaryVpdEeprom.accessAddr.i2c_addr.addrSize = ZERO_BYTE_ADDR;
                l_err = eepromPrepareI2cAddress(l_testTarget,
                                                &l_buf,
                                                l_buflen,
                                                l_desiredPage,
                                                l_primaryVpdEeprom);
                if (l_err)
                {
                    TS_FAIL("test_eepromPrepareI2cAddress - Error preparing address with "
                            "addrSize = ZERO_BYTE_ADDR");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }
                //Clear data buffer
                memset(l_buf, 0x0, MAX_BYTE_ADDR);
                l_buflen = 0;
                l_desiredPage = 0;

                //Set addrSize to ONE_BYTE_ADDR_PAGESELECT
                l_primaryVpdEeprom.accessAddr.i2c_addr.addrSize = ONE_BYTE_ADDR_PAGESELECT;
                //Set offset to EEPROM_PAGE_SIZE bytes to report page 1
                l_primaryVpdEeprom.offset = EEPROM_PAGE_SIZE;
                l_err = eepromPrepareI2cAddress(l_testTarget,
                                                &l_buf,
                                                l_buflen,
                                                l_desiredPage,
                                                l_primaryVpdEeprom);
                if (l_err)
                {
                    TS_FAIL("test_eepromPrepareI2cAddress - Error preparing address when "
                            "addrSize = ONE_BYTE_ADDR_PAGESELECT with offset = EEPROM_PAGE_SIZE");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                }
                //Clear data buffers
                memset(l_buf, 0x0, MAX_BYTE_ADDR);
                l_buflen = 0;
                l_desiredPage = 0;

                //Set addrSize to ONE_BYTE_ADDR
                l_primaryVpdEeprom.accessAddr.i2c_addr.addrSize = ONE_BYTE_ADDR;
                l_desiredPage = 0;
                l_buflen = 0;
                l_err = eepromPrepareI2cAddress(l_testTarget,
                                                &l_buf,
                                                l_buflen,
                                                l_desiredPage,
                                                l_primaryVpdEeprom);
                if (l_err)
                {
                    TS_FAIL("test_eepromPrepareI2cAddress - Error preparing address when "
                            "addrSize = ONE_BYTE_ADDR with offset = EEPROM_PAGE_SIZE");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                }
            }
            while(0);

            TS_INFO(EXIT_MRK"test_eepromPrepareI2cAddress - End");
        }

        /**
        * @brief testing eepromI2cPageOp() - locking and unlocking page
        */
        void test_eepromI2cPageOp( void )
        {
            errlHndl_t l_err = nullptr;
            TS_INFO(ENTER_MRK"test_eepromI2cPageOp - Start");

            do
            {
                //Get a processor Target to test locking and switching pages
                TARGETING::Target* l_testTarget = nullptr;
                l_err = TARGETING::targetService().queryMasterProcChipTargetHandle(l_testTarget);

                //If unable to get Target, exit without executing tests
                if (l_err)
                {
                    TS_FAIL("test_eepromI2cPageOp - failed to find master processor "
                            "- exiting without running tests");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }

                //Create dummy eeprom info w/ VPD_PRIMARY set
                const EEPROM_ROLE l_eepromRole = EEPROM::VPD_PRIMARY;
                eeprom_addr_t l_primaryVpdEeprom;
                l_primaryVpdEeprom.eepromRole = l_eepromRole;

                eepromRecordHeader l_recordHeader;
                l_err = buildEepromRecordHeader(l_testTarget, l_primaryVpdEeprom, l_recordHeader);

                //if unable to build record header, exit without executing tests
                if (l_err)
                {
                    TS_FAIL("test_eepromSpiRead - Failed building eeprom record header "
                            "- exiting without running tests");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }

                l_primaryVpdEeprom.accessAddr.i2c_addr.addrSize = ONE_BYTE_ADDR_PAGESELECT;
                bool l_lockMutex = true;
                uint8_t l_desiredPage = 0;

                //Set variables to lock and switch page
                bool l_switchPage = true;
                bool l_pageLocked = false;
                l_err = eepromI2cPageOp(l_testTarget,
                                        l_switchPage,
                                        l_lockMutex,
                                        l_pageLocked,
                                        l_desiredPage,
                                        l_primaryVpdEeprom);

                //If unable to lock page, exit without executing test to unlock page
                if (l_err)
                {
                    TS_FAIL("test_eepromI2cPageOp - eepromI2cPageOp() Failed locking EEPROM page "
                            "- exiting without running test to unlock page");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }
                if (l_pageLocked != true)
                {
                    TS_FAIL("test_eepromI2cPageOp - l_pageLocked should have been set to true"
                            "- exiting without running test to unlock page");
                    break;
                }

                //Set variables to only unlock page
                l_switchPage = false;
                l_pageLocked = true;
                l_err = eepromI2cPageOp(l_testTarget,
                                      l_switchPage,
                                      l_lockMutex,
                                      l_pageLocked,
                                      l_desiredPage,
                                      l_primaryVpdEeprom);
                if (l_err)
                {
                    TS_FAIL("test_eepromI2cPageOp - eepromI2cPageOp() Failed unlocking EEPROM page");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                }
                if(l_pageLocked != false)
                {
                    TS_FAIL("test_eepromI2cPageOp - l_pageLocked should have been set to false");
                }
            }
            while(0);

            TS_INFO(EXIT_MRK"test_eepromI2cPageOp - End" );
        }

        /**
        * @brief testing eepromI2cPageOp() - forcing an error when performing operations to
        *                                    lock and unlock page
        */
        void test_eepromI2cPageOpError( void )
        {
            errlHndl_t l_err = nullptr;
            TS_INFO(ENTER_MRK"test_eepromI2cPageOpError - Start");

            //Leave Target Null to force error
            TARGETING::Target* l_nullTestTarget = nullptr;

            //Create dummy eeprom info w/ VPD_PRIMARY set
            const EEPROM_ROLE l_eepromRole = EEPROM::VPD_PRIMARY;
            eeprom_addr_t l_primaryVpdEeprom;
            l_primaryVpdEeprom.eepromRole = l_eepromRole;

            l_primaryVpdEeprom.accessAddr.i2c_addr.addrSize = ONE_BYTE_ADDR_PAGESELECT;
            bool l_lockMutex = true;
            uint8_t l_desiredPage = 0;

            //Set variables for case to lock and switch page
            bool l_switchPage = true;
            bool l_pageLocked = false;
            l_err = eepromI2cPageOp(l_nullTestTarget,
                                    l_switchPage,
                                    l_lockMutex,
                                    l_pageLocked,
                                    l_desiredPage,
                                    l_primaryVpdEeprom);
            if (l_err)
            {
                if (l_err->reasonCode() == DeviceFW::DEVFW_RC_NULL_TARGET)
                {
                    TS_INFO("test_eepromI2cPageOpError - Failed as expected (locking page)");
                    delete l_err;
                    l_err = nullptr;
                }
                else
                {
                    TS_FAIL("test_eepromI2cPageOpError - Unexpected error created "
                            "rc=0x%04X", l_err->reasonCode());
                    errlCommit( l_err, CXXTEST_COMP_ID );
                }
            }
            else
            {
                TS_FAIL("test_eepromI2cPageOpError - Should have failed to lock page with null target");
            }

            //Set variables for case to only unlock page
            l_switchPage = false;
            l_pageLocked = true;
            l_err = eepromI2cPageOp(l_nullTestTarget,
                                    l_switchPage,
                                    l_lockMutex,
                                    l_pageLocked,
                                    l_desiredPage,
                                    l_primaryVpdEeprom);
            if (l_err)
            {
                if (l_err->reasonCode() == DeviceFW::DEVFW_RC_NULL_TARGET)
                {
                    TS_INFO("test_eepromI2cPageOpError - Failed as expected (unlocking page)");
                    delete l_err;
                    l_err = nullptr;
                }
                else
                {
                    TS_FAIL("test_eepromI2cPageOpError - Unexpected error created "
                            "rc=0x%04X", l_err->reasonCode());
                    errlCommit( l_err, CXXTEST_COMP_ID );
                }
            }
            else
            {
                TS_FAIL("test_eepromI2cPageOpError - Should have failed to unlock page with null target");
            }

            TS_INFO(EXIT_MRK"test_eepromI2cPageOpError - End");
        }

        /**
        * @brief testing eepromI2cRead() and eepromI2cWrite() by forcing errors
        *        throughout the functions
        */
        void test_eepromI2cReadWrite( void )
        {
            errlHndl_t l_err = nullptr;
            TS_INFO(ENTER_MRK"test_eepromI2cReadWrite - Start");

            //Keep Target null to force error from eepromI2cPageOp()
            TARGETING::Target* l_nullTestTarget = nullptr;

            //Create dummy eeprom info w/ VPD_PRIMARY set
            const EEPROM_ROLE l_eepromRole = EEPROM::VPD_PRIMARY;
            eeprom_addr_t l_primaryVpdEeprom;
            l_primaryVpdEeprom.eepromRole = l_eepromRole;

            //Set addrSize = ONE_BYTE_ADDR_PAGESELECT to cause error in eepromI2cPageOp()
            l_primaryVpdEeprom.accessAddr.i2c_addr.addrSize = ONE_BYTE_ADDR_PAGESELECT;
            l_primaryVpdEeprom.offset = EEPROM_PAGE_SIZE - 1;
            uint8_t l_buf[MAX_BYTE_ADDR] = {0};
            size_t l_buflen = 0x1;

            l_err = eepromI2cRead(l_nullTestTarget, l_buf, l_buflen, l_primaryVpdEeprom);
            if (l_err)
            {
                if (l_err->reasonCode() == DeviceFW::DEVFW_RC_NULL_TARGET)
                {
                    TS_INFO("test_eepromI2cReadWrite - "
                            "eepromI2cRead()::eepromI2cPageOp() Error created as expected");
                    delete l_err;
                    l_err = nullptr;
                }
                else
                {
                    TS_FAIL("test_eepromI2cReadWrite - eepromI2cRead()::eepromI2cPageOp() "
                            "Unexpected error created rc=0x%04X", l_err->reasonCode());
                    errlCommit( l_err, CXXTEST_COMP_ID );
                }
            }
            else
            {
                TS_FAIL("test_eepromI2cReadWrite - "
                        "eepromI2cRead()::eepromI2cPageOp() did not fail as expected");
            }
            //Clear data buffer
            memset(l_buf, 0x0, MAX_BYTE_ADDR);
            l_buflen = 0;

            l_err = eepromI2cWrite(l_nullTestTarget, l_buf, l_buflen, l_primaryVpdEeprom);
            if (l_err)
            {
                if (l_err->reasonCode() == DeviceFW::DEVFW_RC_NULL_TARGET)
                {
                    TS_INFO("test_eepromI2cReadWrite - "
                            "eepromI2cWrite()::eepromI2cPageOp() Error created as expected");
                    delete l_err;
                    l_err = nullptr;
                }
                else
                {
                    TS_FAIL("test_eepromI2cReadWrite - eepromI2cWrite()::eepromI2cPageOp() "
                            "Unexpected error created rc=0x%04X", l_err->reasonCode());
                    errlCommit( l_err, CXXTEST_COMP_ID);
                }
            }
            else
            {
                TS_FAIL("test_eepromI2cReadWrite - "
                        "eepromI2cWrite()::eepromI2cPageOp() did not fail as expected");
            }
            //Clear data buffer
            memset(l_buf, 0x0, MAX_BYTE_ADDR);
            l_buflen = 0;

            do
            {
                // Get a processor Target
                TARGETING::Target* l_testTarget = nullptr;
                l_err = TARGETING::targetService().queryMasterProcChipTargetHandle(l_testTarget);
                if (l_err)
                {
                    TS_FAIL("test_dumpEepromData - failed to find master processor");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }

                eepromRecordHeader l_recordHeader;
                l_err = buildEepromRecordHeader(l_testTarget, l_primaryVpdEeprom, l_recordHeader);
                if (l_err)
                {
                    TS_FAIL("test_eepromPrepareI2cAddress - Failed building eeprom record header");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }

                //set write page size to 0 to cause error in eepromI2cWrite()
                l_primaryVpdEeprom.accessAddr.i2c_addr.writePageSize = 0;
                l_err = eepromI2cWrite(l_testTarget, l_buf, l_buflen, l_primaryVpdEeprom);
                if (l_err)
                {
                    if (l_err->reasonCode() == EEPROM_I2C_WRITE_PAGE_SIZE_ZERO)
                    {
                        TS_INFO("test_eepromI2cReadWrite - eepromI2cWrite() Error Created as "
                                "expected with writePageSize = 0");
                        delete l_err;
                        l_err = nullptr;
                    }
                    else
                    {
                        TS_FAIL("test_eepromI2cReadWrite - eepromI2cWrite() Unexpected error "
                                " created rc=0x%04X", l_err->reasonCode());
                        errlCommit( l_err, CXXTEST_COMP_ID );
                    }
                }
                else
                {
                    TS_FAIL("test_eepromI2cReadWrite - eepromI2cWrite() did not fail as expected");
                }
                //Clear data buffer
                memset(l_buf, 0x0, MAX_BYTE_ADDR);

                //Set to LAST_DEVICE_TYPE to cause error in eepromPrepareI2cAddress()
                l_primaryVpdEeprom.accessAddr.i2c_addr.addrSize = LAST_DEVICE_TYPE;

                l_buflen = 0x1;
                l_err = eepromI2cRead(l_testTarget, l_buf, l_buflen, l_primaryVpdEeprom);
                if (l_err)
                {
                    if (l_err->reasonCode() == EEPROM_INVALID_DEVICE_TYPE)
                    {
                        TS_INFO("test_eepromI2cReadWrite - eepromI2cRead()::eepromPrepareI2cAddress() "
                                " Error created as expected");
                        delete l_err;
                        l_err = nullptr;
                    }
                    else
                    {
                        TS_FAIL("test_eepromI2cReadWrite - eepromI2cRead()::eepromPrepareI2cAddress() "
                                "Unexpected error created rc=0x%04X", l_err->reasonCode());
                        errlCommit( l_err, CXXTEST_COMP_ID );
                    }
                }
                else
                {
                    TS_FAIL("test_eepromI2cReadWrite - eepromI2cRead()::eepromPrepareI2cAddress() "
                            " did not fail as expected");
                }
                //Clear data buffer
                memset(l_buf, 0x0, MAX_BYTE_ADDR);
                l_buflen = 0;

                l_err = eepromI2cWrite(l_testTarget, l_buf, l_buflen, l_primaryVpdEeprom);
                if (l_err)
                {
                    if (l_err->reasonCode() == EEPROM_INVALID_DEVICE_TYPE)
                    {
                        TS_INFO("test_eepromI2cReadWrite - eepromI2cWrite()::eepromPrepareI2cAddress() "
                                "Error created as expected");
                        delete l_err;
                        l_err = nullptr;
                    }
                    else
                    {
                        TS_FAIL("test_eepromI2cReadWrite - eepromI2cWrite()::eepromPrepareI2cAddress() "
                                "Unexpected error created rc=0x%04X", l_err->reasonCode());
                        errlCommit( l_err, CXXTEST_COMP_ID );
                    }
                }
                else
                {
                    TS_FAIL("test_eepromI2cReadWrite - eepromI2cWrite()::eepromPrepareI2cAddress() "
                            " did not fail as expected");
                }

            }
            while(0);

            TS_INFO(EXIT_MRK"test_eepromI2cReadWrite - End");
        }

        /**
        * @brief testing eepromI2cReadData() and eepromI2cWriteData()
        */
        void test_eepromI2cReadWriteData( void )
        {
            errlHndl_t l_err = nullptr;
            TS_INFO(ENTER_MRK"test_eepromI2cReadWriteData - Start");

            do
            {
                //Get a processor Target
                TARGETING::Target* l_testTarget = nullptr;
                l_err = TARGETING::targetService().queryMasterProcChipTargetHandle(l_testTarget);
                if (l_err)
                {
                    TS_FAIL("test_eepromI2cReadWriteData - failed to find master processor");
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
                    TS_FAIL("test_eepromI2cReadWriteData - Failed building eeprom record header");
                    errlCommit( l_err, CXXTEST_COMP_ID );
                    break;
                }

                //Test Read Data
                uint8_t l_byteAddr[MAX_BYTE_ADDR] = {0};
                size_t l_byteAddrSize = 0x1;
                uint8_t l_buffer[MAX_BYTE_ADDR] = {0};
                size_t l_buflen = 0;
                size_t l_readLenRemaining = l_buflen;
                size_t l_readBuflen = 0;
                l_err = eepromI2cReadData(l_testTarget,
                                          &(reinterpret_cast<uint8_t*>(l_buffer)[l_buflen - l_readLenRemaining]),
                                          l_readBuflen,
                                          &l_byteAddr,
                                          l_byteAddrSize,
                                          l_primaryVpdEeprom );

                if (l_err)
                {
                    if (l_err->reasonCode() == I2C::I2C_MUX_TARGET_NOT_FOUND)
                    {
                        TS_INFO("test_eepromI2cReadWriteData - eepromI2cReadData() - "
                                "error created as expected");
                        delete l_err;
                        l_err = nullptr;
                    }
                    else
                    {
                        TS_FAIL("test_eepromI2cReadWriteData - eepromI2cReadData() - "
                                "Unexpected error created rc=0x%04X", l_err->reasonCode());
                        errlCommit( l_err, CXXTEST_COMP_ID );
                    }
                }
                else
                {
                    TS_FAIL("test_eepromI2cReadWriteData - eepromI2cWriteData() - "
                            "Did not fail as expected");
                }

                //Test Write Data
                l_byteAddrSize = 0;
                l_err = eepromI2cWriteData(l_testTarget,
                                           &(reinterpret_cast<uint8_t*>(l_buffer)[l_buflen - l_readLenRemaining]),
                                           l_readBuflen,
                                           &l_byteAddr,
                                           l_byteAddrSize,
                                           l_primaryVpdEeprom);

                if (l_err)
                {
                    if (l_err->reasonCode() == I2C::I2C_MUX_TARGET_NOT_FOUND)
                    {
                        TS_INFO("test_eepromI2cReadWriteData - eepromI2cWriteData() error "
                                "created as expected");
                        delete l_err;
                        l_err = nullptr;
                    }
                    else
                    {
                        TS_FAIL("test_eepromI2cReadWriteData - eepromI2cWriteData() Unexpected "
                                "error created rc=0x%04X", l_err->reasonCode());
                    }
                }
                else
                {
                    TS_FAIL("test_eepromI2cReadWriteData - eepromI2cWriteData() Did not "
                            "fail as expected");
                }

            }
            while(0);

            TS_INFO(EXIT_MRK"test_eepromI2cReadWriteData - End");
        }
};
