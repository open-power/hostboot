/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/test/eepromUtilstest.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
*  @file eepromUtilstest.H
*
*  @brief Test cases for the eeprom utils code
*/

#include <cxxtest/TestSuite.H>
#include <targeting/common/commontargeting.H>
#include <eeprom/eeprom_const.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include "../eepromCache.H"
#include <eeprom/eepromif.H>

using namespace TARGETING;
using namespace EEPROM;

typedef struct {
    uint32_t spiHuidData;
    uint8_t  spiRsvd; // 0xFF
    uint8_t  engineData;
    uint16_t offsetData;
} PACKED spiUserData_t;

typedef struct {
    uint32_t    i2cHuidData;
    uint8_t     portData;
    uint8_t     engineData;
    uint8_t     devData;
    uint8_t     muxData;
} PACKED i2cUserData_t;

class EEPROMUtilsTest: public CxxTest::TestSuite
{
    public:
        /**
        * @brief test and verify data from getEepromHeaderUserData()
        */
        void test_getEepromHeaderUserData( void )
        {
            errlHndl_t err = nullptr;
            TS_TRACE(ENTER_MRK"test_getEepromHeaderUserData - Start");

            //Get a processor Target
            TARGETING::Target* l_testTarget = nullptr;
            err = TARGETING::targetService().queryMasterProcChipTargetHandle(l_testTarget);
            if (err)
            {
                TS_FAIL("test_getEepromHeaderUserData - failed to find master processor");
                errlCommit( err, CXXTEST_COMP_ID );
            }

            //Create dummy eeprom info w/ SBE_PRIMARY set
            const EEPROM_ROLE l_eepromRole = EEPROM::SBE_PRIMARY;
            eeprom_addr_t l_primarySbeEeprom;
            l_primarySbeEeprom.eepromRole = l_eepromRole;

            eepromRecordHeader l_recordHeader;
            err = buildEepromRecordHeader(l_testTarget, l_primarySbeEeprom, l_recordHeader);
            if (err)
            {
                TS_FAIL("test_getEepromHeaderUserData - failed in buildEepromRecordHeader()");
                errlCommit( err, CXXTEST_COMP_ID );
            }

            //Test function
            uint64_t userData1 = getEepromHeaderUserData(l_recordHeader);
            TS_TRACE("test_getEepromHeaderUserData - user data piece 1: 0x%.8X", userData1);

            //Verify data
            spiUserData_t* l_spiUserData = reinterpret_cast<spiUserData_t*>(&userData1);
            if (l_spiUserData->spiHuidData != l_recordHeader.completeRecord.eepromAccess.spiAccess.spi_master_huid)
            {
                TS_FAIL("test_getEepromHeaderUserData - getEepromHeaderUserData() "
                        "returned incorrect for spi_master_huid: 0x%.8X", l_spiUserData->spiHuidData);
            }
            if (l_spiUserData->engineData != l_recordHeader.completeRecord.eepromAccess.spiAccess.engine)
            {
                TS_FAIL("test_getEepromHeaderUserData - getEepromHeaderUserData() "
                        "returned incorrect for engine: 0x%.4X", l_spiUserData->engineData);
            }
            if (l_spiUserData->offsetData != l_recordHeader.completeRecord.eepromAccess.spiAccess.offset_KB)
            {
                TS_FAIL("test_getEepromHeaderUserData - getEepromHeaderUserData() "
                        "returned incorrect for offset_KB: 0x%.4X", l_spiUserData->offsetData);
            }

            //Test function with I2C access method
            l_recordHeader.completeRecord.accessType = EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C;
            uint64_t userData2 = getEepromHeaderUserData(l_recordHeader);
            TS_TRACE("test_getEepromHeaderUserData - user data piece 2: 0x%.8X", userData2);

            //Verify data
            i2cUserData_t* l_i2cUserData = reinterpret_cast<i2cUserData_t*>(&userData2);
            if (l_i2cUserData->i2cHuidData != l_recordHeader.completeRecord.eepromAccess.i2cAccess.i2c_master_huid)
            {
                TS_FAIL("test_getEepromHeaderUserData - getEepromHeaderUserData() "
                        "returned incorrect for spi_master_huid: 0x%.8X", l_i2cUserData->i2cHuidData);
            }
            if (l_i2cUserData->portData != l_recordHeader.completeRecord.eepromAccess.i2cAccess.port)
            {
                TS_FAIL("test_getEepromHeaderUserData - getEepromHeaderUserData() "
                        "returned incorrect for port: 0x%.4X", l_i2cUserData->portData);
            }
            if (l_i2cUserData->engineData != l_recordHeader.completeRecord.eepromAccess.spiAccess.engine)
            {
                TS_FAIL("test_getEepromHeaderUserData - getEepromHeaderUserData() "
                        "returned incorrect for engine: 0x%.4X", l_i2cUserData->engineData);
            }
            if (l_i2cUserData->devData != l_recordHeader.completeRecord.eepromAccess.i2cAccess.devAddr)
            {
                TS_FAIL("test_getEepromHeaderUserData - getEepromHeaderUserData() "
                        "returned incorrect for devAddr: 0x%.4X", l_i2cUserData->devData);
            }
            if (l_i2cUserData->muxData != l_recordHeader.completeRecord.eepromAccess.i2cAccess.mux_select)
            {
                TS_FAIL("test_getEepromHeaderUserData - getEepromHeaderUserData() "
                        "returned incorrect for mux_select: 0x%.4X", l_i2cUserData->muxData);
            }

            TS_TRACE(EXIT_MRK"test_getEepromHeaderUserData - End");
        }

        /**
        * @brief testing dumpEepromData()
        */
        void test_dumpEepromData( void )
        {
            errlHndl_t err = nullptr;
            TS_TRACE(ENTER_MRK"test_dumpEepromData - Start");

            //Get a processor Target
            TARGETING::Target* l_testTarget = nullptr;
            err = TARGETING::targetService().queryMasterProcChipTargetHandle(l_testTarget);
            if (err)
            {
                TS_FAIL("test_dumpEepromData - failed to find master processor");
                errlCommit( err, CXXTEST_COMP_ID );
            }

            //Create dummy eeprom info w/ SBE_PRIMARY set
            const EEPROM_ROLE l_eepromRole = EEPROM::SBE_PRIMARY;
            eeprom_addr_t l_primarySbeEeprom;
            l_primarySbeEeprom.eepromRole = l_eepromRole;

            eepromRecordHeader l_recordHeader;
            err = buildEepromRecordHeader(l_testTarget, l_primarySbeEeprom, l_recordHeader);
            if (err)
            {
                TS_FAIL("test_dumpEepromData - failed in buildEepromRecordHeader()");
                errlCommit( err, CXXTEST_COMP_ID );
            }

            //Call function with SPI access method
            dumpEepromData(l_primarySbeEeprom);

            //Call function with UNKNOWN access method
            l_primarySbeEeprom.accessMethod = EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_UNKNOWN;
            dumpEepromData(l_primarySbeEeprom);

            //Call function with I2C access method
            l_primarySbeEeprom.accessMethod = EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C;
            dumpEepromData(l_primarySbeEeprom);

            TS_TRACE(EXIT_MRK"test_dumpEepromData - End");
        }
};