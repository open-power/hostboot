/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/serial/fapi2WOFTest.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#ifndef __WOFTEST_H__
#define __WOFTEST_H__

/**
 *  @file fapi2WOFTest.H
 *
 *  @brief Test case for WOF access code
 */

#include <stdio.h>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <eeprom/eeprom_const.H>

using namespace TARGETING;

namespace fapi2
{
namespace platAttrSvc
{
    // Functionality entry points being brought in to be tested
    errlHndl_t getSeepromWofTable(TARGETING::Target* i_target, uint8_t* o_wofData);
    errlHndl_t getOverrideWofTable(TARGETING::Target* i_procTarg, uint8_t* o_wofData, bool& o_didFindTable);

    errlHndl_t getSeepromEccLessWofData(TARGETING::Target* i_procTarg,
                                        const size_t i_buflen,
                                        const size_t i_offset,
                                        void* o_buffer);
}
}

namespace PNOR
{
    namespace ECC
    {
        uint8_t generateECC(uint64_t i_data);
    }
}

class WOFTest: public CxxTest::TestSuite
{

public:

    /**
      * @brief Test coverage of getting WOF table from SEEPROM of every functional processor
      */
    void testGetWofFromSeepromCoverage()
    {

        FAPI_INF("testGetWofFromSeepromCoverage: ENTER");

        errlHndl_t l_errl = nullptr;

        // Allocating large chunk of memory in the heap
        // typedef uint8_t ATTR_WOF_TABLE_DATA_Type[40064];
        fapi2::ATTR_WOF_TABLE_DATA_Type* l_wofTableData =
            reinterpret_cast<fapi2::ATTR_WOF_TABLE_DATA_Type*>(new fapi2::ATTR_WOF_TABLE_DATA_Type());

        TargetHandleList l_procsList;
        getAllChips(l_procsList, TYPE_PROC, true);

        FAPI_INF("testGetWofFromSeepromCoverage: Will be tested on %d functional procs",
                 l_procsList.size());

        size_t l_countProcsTested = 0;

        for (const auto & l_proc : l_procsList)
        {
            // Get WOF data from SEEPROM
            l_errl = fapi2::platAttrSvc::getSeepromWofTable(l_proc, *l_wofTableData);

            if (l_errl)
            {
                TS_FAIL("testGetWofFromSeepromCoverage: Failed to get WOF table from SEEPROM for "
                        "proc: 0x%08x", get_huid(l_proc));
                continue; // continue trying to test all functional procs
            }
            else
            {
                FAPI_INF("testGetWofFromSeepromCoverage: WOF table data successfully retrieved "
                         "from SEEPROM for proc: 0x%08x", get_huid(l_proc));
                l_countProcsTested++;
            }
        }

        // Clean up
        if (l_wofTableData)
        {
            delete[] l_wofTableData;
            l_wofTableData = nullptr;
        }

        // Commit error if any
        if (l_errl)
        {
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }

        FAPI_INF("testGetWofFromSeepromCoverage: Successfully tested %d out of %d procs",
                 l_countProcsTested, l_procsList.size());

        FAPI_INF("testGetWofFromSeepromCoverage: EXIT");

    } // testGetWofFromSeepromCoverage


    /**
      * @brief Test bad path when no WOF image is included in SEEPROM.
      *
      * Test runs for SEEPROM of primary proc only.
      *
      * Bad path will be faked by putting an incorrect magic value in the header of the WOF image.
      * In getSeepromWofTable(...), the magic value is used to verify the image. Having an incorrect
      * value is like not having a WOF image at all.
      * The magic value is the first 4 bytes of the WOF image. Because the image has an ECC byte
      * following every 8-byte, we're going to be replacing the first 8-bytes of the image (which
      * will include the magic value) along with the ECC value.
      */
    void testNoWofInSeeprom()
    {

        FAPI_INF("testNoWofInSeeprom: ENTER");

        errlHndl_t l_errl = nullptr;
        TARGETING::Target * l_proc = nullptr;

        // Allocating large chunk of memory in the heap for WOF table
        // typedef uint8_t ATTR_WOF_TABLE_DATA_Type[40064];
        fapi2::ATTR_WOF_TABLE_DATA_Type* l_wofTableData =
            reinterpret_cast<fapi2::ATTR_WOF_TABLE_DATA_Type*>(new fapi2::ATTR_WOF_TABLE_DATA_Type());

        // Will be used to store 8-bytes of data and its corresponding ECC
        size_t l_eccBlockSize = 9;
        // Will store the original
        uint8_t l_origBlock[l_eccBlockSize] = {};
        // Will store fake
        // since the ECC value of all zeros is zero, this block has the correct ECC
        uint8_t l_fakeBlock[l_eccBlockSize] = {};

        do
        {
            // Get primary proc
            l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
            if (l_errl)
            {
                TS_FAIL("testNoWofInSeeprom: Failed to get primary proc "
                        "when calling queryMasterProcChipTargetHandle");
                break;
            }

            FAPI_INF("testNoWofInSeeprom: testing with SEEPROM of proc: 0x%08x", get_huid(l_proc));

            // Copy original first 8-bytes with ecc (which includes magic value)
            // The magic value is the first 4-bytes of the image, see:
            // src/usr/fapi2/plat_wof_access.C line 101
            l_errl = deviceRead(l_proc, &l_origBlock, l_eccBlockSize,
                DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, 0, EEPROM::AUTOSELECT));

            if (l_errl)
            {
                TS_FAIL("testNoWofInSeeprom: Failed to get original WOF image magic value");
                break;
            }

            l_errl = deviceWrite(l_proc, &l_fakeBlock, l_eccBlockSize,
                DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, 0, EEPROM::AUTOSELECT));

            if (l_errl)
            {
                TS_FAIL("testNoWofInSeeprom: Failed to write fake WOF image magic value");
                break;
            }

            // Get WOF data from SEEPROM, error is expected
            l_errl = fapi2::platAttrSvc::getSeepromWofTable(l_proc, *l_wofTableData);

            if ( l_errl &&
                (l_errl->reasonCode() == fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH) &&
                (l_errl->moduleId() == fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES) )
            {
                FAPI_INF("testNoWofInSeeprom: getSeepromWofTable(...) no WOF img failure path "
                         "failed as expected");
                delete l_errl;
                l_errl = nullptr;
            }
            else
            {
                TS_FAIL("testNoWofInSeeprom: getSeepromWofTable(...) no WOF img failure path did "
                        "not fail as expected. Expected RC: 0x%x ModId: 0x%x. Actual RC: 0x%x "
                        "ModId: 0x%x.",
                        fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH, fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                        l_errl->reasonCode(), l_errl->moduleId());
                break;
            }

        } while (0);

        // Commit error if any from do-while loop
        if (l_errl)
        {
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }

        if (l_origBlock[0]) // the first byte of l_origBlock if copied from WOF img is non-zero
        {
            // In case WOF image is used again in a test, write back original magic value to header
            l_errl = deviceWrite(l_proc, &l_origBlock, l_eccBlockSize,
                DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, 0, EEPROM::AUTOSELECT));
            if (l_errl)
            {
                TS_FAIL("testNoWofInSeeprom: Failed to write back original magic value in header");
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }

        // Clean up
        if (l_wofTableData)
        {
            delete[] l_wofTableData;
            l_wofTableData = nullptr;
        }

        FAPI_INF("testNoWofInSeeprom: EXIT");

    } // testNoWofInSeeprom


    /**
      * @brief Test bad ECC path when fetching WOF image from SEEPROM
      *
      * Test runs for SEEPROM of primary proc only.
      *
      * Bad ECC will be created by replacing the first ECC byte (i.e the ninth byte of the image)
      * with zero.
      * This byte can never be zero as it is the ECC-byte of the magic number WTIH (0x57544948),
      * along with other data.
      */
    void testBadEccInWofFromSeeprom()
    {

        FAPI_INF("testBadEccInWofFromSeeprom: ENTER");

        errlHndl_t l_errl = nullptr;
        TARGETING::Target * l_proc = nullptr;

        // Allocating large chunk of memory in the heap for WOF table
        // typedef uint8_t ATTR_WOF_TABLE_DATA_Type[40064];
        fapi2::ATTR_WOF_TABLE_DATA_Type* l_wofTableData =
            reinterpret_cast<fapi2::ATTR_WOF_TABLE_DATA_Type*>(new fapi2::ATTR_WOF_TABLE_DATA_Type());

        uint8_t l_badEccByte = 0;

        size_t l_eccByteSize = sizeof(l_badEccByte);
        const size_t l_eccByteOffset = 8;
        uint8_t l_originalEccByte = 0;

        do
        {
            // Get primary proc
            l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
            if (l_errl)
            {
                TS_FAIL("testBadEccInWofFromSeeprom: Failed to get primary proc when calling "
                        "queryMasterProcChipTargetHandle");
                break;
            }

            FAPI_INF("testBadEccInWofFromSeeprom: testing with SEEPROM of proc: 0x%08x", get_huid(l_proc));

            // Copy original first ECC byte
            l_errl = deviceRead(l_proc, &l_originalEccByte, l_eccByteSize,
                DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, l_eccByteOffset, EEPROM::AUTOSELECT));

            if (l_errl)
            {
                TS_FAIL("testBadEccInWofFromSeeprom: Failed to get original ECC byte");
                break;
            }

            if (l_badEccByte == l_originalEccByte)
            {
                // This is very unlikely to happen. But if it does happen, it may be that the WOF
                // data in the SEEPROM being tested does not exist (and thus was never cached
                // either) and this random byte we're reading happens to be zero
                TS_FAIL("testBadEccInWofFromSeeprom: Original ECC byte (0x%02x) equals fake ECC "
                        "byte (0x%02x)", l_originalEccByte, l_badEccByte);
                break;
            }

            // Write bad ECC byte
            l_errl = deviceWrite(l_proc, &l_badEccByte, l_eccByteSize,
                DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, l_eccByteOffset, EEPROM::AUTOSELECT));

            if (l_errl)
            {
                TS_FAIL("testBadEccInWofFromSeeprom: Failed to write bad ECC byte");
                break;
            }

            // Get WOF data from SEEPROM, error is expected
            l_errl = fapi2::platAttrSvc::getSeepromWofTable(l_proc, *l_wofTableData);

            if ( l_errl &&
                (l_errl->reasonCode() == fapi2::RC_WOF_READ_UNCORRECTABLE_ECC) &&
                (l_errl->moduleId() == fapi2::MOD_FAPI2_GET_SEEPROM_ECC_LESS_WOF_DATA) )
            {
                FAPI_INF("testBadEccInWofFromSeeprom: getSeepromWofTable(...) bad ECC byte "
                         "failure path hit as expected");
                delete l_errl;
                l_errl = nullptr;
            }
            else
            {
                TS_FAIL("testBadEccInWofFromSeeprom: getSeepromWofTable(...) bad ECC byte failure "
                        "path did not fail as expected. Expected RC: 0x%x ModId: 0x%x. Actual RC: "
                        "0x%x ModId: 0x%x.",
                        fapi2::RC_WOF_IMAGE_MAGIC_MISMATCH, fapi2::MOD_FAPI2_PLAT_PARSE_WOF_TABLES,
                        l_errl->reasonCode(), l_errl->moduleId());
                break;
            }

        } while (0);

        // Commit error if any from do-while loop
        if (l_errl)
        {
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }

        // Replace ECC byte if it was copied out to l_originalEccByte
        if (l_originalEccByte != 0)
        {
            l_errl = deviceWrite(l_proc, &l_originalEccByte, l_eccByteSize,
                DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, l_eccByteOffset, EEPROM::AUTOSELECT));
            if (l_errl)
            {
                TS_FAIL("testBadEccInWofFromSeeprom: Failed to write back original ECC byte");
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }

        // Clean up
        if (l_wofTableData)
        {
            delete[] l_wofTableData;
            l_wofTableData = nullptr;
        }

        FAPI_INF("testBadEccInWofFromSeeprom: EXIT");

    } // testBadEccInWofFromSeeprom


    /**
      * @brief Test coverage of getting WOF table from override image in WOFDATA LID
      * - First, test code path of not finding an override-set entry match
      * - Second, test success path of finding an override WOF Table
      */
    void testGetOverrideWofCoverage()
    {
        /*
        For both test we'll be doing a similar setup
        - Set selection criteria
        - Run getOverrideWofTable(...)
        At the end, we'll write back original selection criteria attrs and delete l_wofTableData
        */

        FAPI_INF("testGetOverrideWofCoverage: ENTER");

        errlHndl_t l_errl = nullptr;
        TARGETING::Target * l_sys = UTIL::assertGetToplevelTarget();
        TARGETING::Target * l_masterProc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(l_masterProc);

        FAPI_INF("testGetOverrideWofCoverage: Testing for master proc HUID 0x%08x",
            get_huid(l_masterProc));

        // Large chunk of memory in the heap for WOF Table
        // typedef uint8_t ATTR_WOF_TABLE_DATA_Type[40064];
        fapi2::ATTR_WOF_TABLE_DATA_Type* l_wofTableData =
            reinterpret_cast<fapi2::ATTR_WOF_TABLE_DATA_Type*>(new fapi2::ATTR_WOF_TABLE_DATA_Type());
        bool l_didFindTable = false;

        // Hard coded values of a WOF Image entry in WOFDATA known to exist
        const uint32_t l_testNominalPowerWatts = 0x190;
        const uint32_t l_testNominalFreqMhz = 0x960;

        // Store original values
        const uint32_t l_origNominalPowerWatts = l_masterProc->getAttr<TARGETING::ATTR_SOCKET_POWER_NOMINAL>();
        const uint32_t l_origNominalFreqMhz = l_sys->getAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>();

        do
        {
break; // Temporary change to skip the test in rchgsa build environment
            /* Test code path of not finding an override-set entry match */

            // Set selection criteria to values that are purposefully incorrect
            l_masterProc->setAttr<TARGETING::ATTR_SOCKET_POWER_NOMINAL>(0xFFFF); // uint_16
            l_sys->setAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>(0xFFFFFFFF); // uint_16
            FAPI_INF("testGetOverrideWofCoverage: Testing code path of not finding an override match.")
            FAPI_INF("testGetOverrideWofCoverage: Set test values ATTR_SOCKET_POWER_NOMINAL = %d, "
                "ATTR_NOMINAL_FREQ_MHZ = %d", 0xFFFF, 0xFFFFFFFF);

            l_didFindTable = true; // this is expected to be set to false in function call below:
            l_errl = fapi2::platAttrSvc::getOverrideWofTable(l_masterProc, *l_wofTableData, l_didFindTable);

            if ( l_errl &&
                (l_didFindTable == false) &&
                (l_errl->reasonCode() == fapi2::RC_WOF_OVERRIDE_TABLE_NOT_FOUND) &&
                (l_errl->moduleId() == fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE) )
            {
                FAPI_INF("testGetOverrideWofCoverage: Tested code path of not finding an override "
                    "match tested successfully.");
                delete l_errl;
                l_errl = nullptr;
            }
            else
            {
                TS_FAIL("testGetOverrideWofCoverage: Failed testing code path of not finding an "
                    "override match. Expected RC: 0x%x ModId: 0x%x. Actual RC: 0x%x ModId: 0x%x. "
                    "l_didFindTable: %s.", fapi2::RC_WOF_OVERRIDE_TABLE_NOT_FOUND,
                    fapi2::MOD_FAPI2_GET_OVERRIDE_WOF_TABLE, l_errl->reasonCode(),
                    l_errl->moduleId(), l_didFindTable ? "true" : "false");
                break;
            }

            /* Test success path of finding an override WOF Table */

            // Set selection criteria to values known to be in the WOFDATA Override image
            l_masterProc->setAttr<TARGETING::ATTR_SOCKET_POWER_NOMINAL>(l_testNominalPowerWatts);
            l_sys->setAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>(l_testNominalFreqMhz);
            FAPI_INF("testGetOverrideWofCoverage: Testing success path of finding an override WOF Table.")
            FAPI_INF("testGetOverrideWofCoverage: Set test values ATTR_SOCKET_POWER_NOMINAL = %d, "
                "ATTR_NOMINAL_FREQ_MHZ = %d", l_testNominalPowerWatts, l_testNominalFreqMhz);

            // Try to get override WOF table
            l_didFindTable = false; // this is expected to be set to true in function call below:
            l_errl = fapi2::platAttrSvc::getOverrideWofTable(l_masterProc, *l_wofTableData, l_didFindTable);

            if (l_errl || (l_didFindTable == false))
            {
                TS_FAIL("testGetOverrideWofCoverage: Failed to get Override WOF table. "
                    "l_didFindTable: %s.", l_didFindTable ? "true" : "false");
                break;
            }
            else
            {
                FAPI_INF("testGetOverrideWofCoverage: Override WOF table successfully retrieved.");
            }

        } while (0);

        // Place back original values
        l_masterProc->setAttr<TARGETING::ATTR_SOCKET_POWER_NOMINAL>(l_origNominalPowerWatts);
        l_sys->setAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>(l_origNominalFreqMhz);

        // Clean up
        if (l_wofTableData)
        {
            delete[] l_wofTableData;
            l_wofTableData = nullptr;
        }

        // Commit error if any
        if (l_errl)
        {
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }

        FAPI_INF("testGetOverrideWofCoverage: EXIT");

    } // testGetOverrideWofCoverage

    void testEccCorrectionForWofData()
    {
        // This test will verify that the logic within getDefaultWofTable is able to correct for 1 bit ECC errors.
        // To do this, we are going to read the first 9 bytes from the start of the WOF header and corrupt it
        // bit by bit and writing back the corrupted data. After, we call the function that will fetch the WOF table
        // and it should correct the error and write back the correction.

        FAPI_INF("testEccCorrectionForWofData: ENTER");

        errlHndl_t l_errl = nullptr;
        TARGETING::Target * l_proc = nullptr;

        const size_t ECC_SIZE = 1;
        const size_t BLOCK_SIZE = 8;
        // Will be used to store 8-bytes of data and its corresponding ECC
        size_t ECC_BLOCK_SIZE = BLOCK_SIZE + ECC_SIZE;
        // Will store the original read from the SEEPROM. This is used to compare to the corrupted data to
        // ensure that ECC correction took place.
        uint8_t l_originalBlock[ECC_BLOCK_SIZE] = {};
        // Used to corrupt 1 bit at a time to be written back to the EECACHE so that WOF retrieval must correct it.
        uint8_t l_corruptBlock[ECC_BLOCK_SIZE] = {};

        do
        {
            // Get primary proc
            l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
            if (l_errl)
            {
                TS_FAIL("testEccCorrectionForWofData: Failed to get primary proc "
                        "when calling queryMasterProcChipTargetHandle");
                break;
            }

            FAPI_INF("testEccCorrectionForWofData: testing with SEEPROM of proc: 0x%08x", get_huid(l_proc));

            // Copy original first 8-bytes with ecc (which includes magic value)
            // The magic value is the first 4-bytes of the image, see:
            // src/usr/fapi2/plat_wof_access.C line 101
            l_errl = deviceRead(l_proc, &l_originalBlock, ECC_BLOCK_SIZE,
                DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, 0, EEPROM::AUTOSELECT));

            if (l_errl)
            {
                TS_FAIL("testEccCorrectionForWofData: Failed to get original WOF image data");
                break;
            }

            // Copy original data to corrupt data block
            memcpy(l_corruptBlock, l_originalBlock, ECC_BLOCK_SIZE);

            FAPI_INF("testEccCorrectionForWofData: Testing correction of 1 bit data corruption...");
            bool l_stopTest = false;
            // Iterate over the first 8 bytes of data, the non-ECC portion, and verify that the API corrects it when
            // corrupted.
            for (int i = 0; i < 64; i++)
            {
                // Corrupt a bit by flipping its value
                uint64_t l_corruptEcclessBlock = *(reinterpret_cast<uint64_t*>(l_corruptBlock)) ^ (1ul << (63 - i));
                memcpy(l_corruptBlock, &l_corruptEcclessBlock, BLOCK_SIZE);

                // Write corrupted data back to the EECACHE
                l_errl = deviceWrite(l_proc, &l_corruptBlock, ECC_BLOCK_SIZE,
                    DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, 0, EEPROM::AUTOSELECT));
                if (l_errl)
                {
                    TS_FAIL("testEccCorrectionForWofData: Failed to write corrupted data to WOF image");
                    l_stopTest = true;
                    break;
                }

                // Read the now corrupted data back and verify it is corrupted
                {
                    uint8_t l_verifyBlock[ECC_BLOCK_SIZE] = {};
                    l_errl = deviceRead(l_proc, &l_verifyBlock, ECC_BLOCK_SIZE,
                        DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, 0, EEPROM::AUTOSELECT));
                    if (l_errl)
                    {
                        TS_FAIL("testEccCorrectionForWofData: Failed to read back WOF image corrupted data");
                        l_stopTest = true;
                        break;
                    }

                    // Compare the data read back is the same as the corrupted data that was attempted to be written
                    if (memcmp(l_corruptBlock, l_verifyBlock, ECC_BLOCK_SIZE) != 0)
                    {
                        TS_FAIL("testEccCorrectionForWofData: Corrupted data wasn't written correctly.")
                        TRACFBIN(g_trac_test, "Corrupted (Expected) Data", l_corruptBlock, ECC_BLOCK_SIZE);
                        TRACFBIN(g_trac_test, "Read back Data", l_verifyBlock, ECC_BLOCK_SIZE);
                        l_stopTest = true;
                        break;
                    }

                } // Done checking corrupt data was successfully written

                // Read WOF table header and check ECC_BLOCK_SIZE.
                // Fetching the WOF via the API should've corrected the data in the process.
                l_errl = fapi2::platAttrSvc::getSeepromEccLessWofData(l_proc, BLOCK_SIZE, 0, &l_corruptBlock);
                if (l_errl)
                {
                    TS_FAIL("testEccCorrectionForWofData: getSeepromEccLessWofData(...) Unexpected Error");
                    l_stopTest = true;
                    break;
                }

                // The data returned is ECCless so calculate a new ECC for comparison.
                l_corruptBlock[BLOCK_SIZE] = PNOR::ECC::generateECC(*reinterpret_cast<uint64_t*>(&l_corruptBlock));

                // Compare the data fetched via the API is the same as the original block
                if (memcmp(l_corruptBlock, l_originalBlock, ECC_BLOCK_SIZE) != 0)
                {
                    TS_FAIL("testEccCorrectionForWofData: Corrupted data was not corrected by WOF API.")
                    TRACFBIN(g_trac_test, "Original (Expected) Data", l_originalBlock, ECC_BLOCK_SIZE);
                    TRACFBIN(g_trac_test, "Corrupted Data", l_corruptBlock, ECC_BLOCK_SIZE);
                    l_stopTest = true;
                    break;
                }
            }
            if (l_stopTest)
            {
                break;
            }

            FAPI_INF("testEccCorrectionForWofData: Testing correction of 1 bit ECC corruption...");
            // Iterate over the last byte of data, the ECC byte, and verify that the API corrects it when
            // corrupted.
            for (int i = 0; i < 8; i++)
            {
                // Corrupt a bit by flipping its value
                l_corruptBlock[BLOCK_SIZE] = l_corruptBlock[BLOCK_SIZE] ^ (1u <<  i);

                // Write corrupted data back to the EECACHE
                l_errl = deviceWrite(l_proc, &l_corruptBlock, ECC_BLOCK_SIZE,
                    DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, 0, EEPROM::AUTOSELECT));
                if (l_errl)
                {
                    TS_FAIL("testEccCorrectionForWofData: Failed to write corrupted ECC data to WOF image");
                    break;
                }

                // Read the now corrupted data back and verify it is corrupted
                {
                    uint8_t l_verifyBlock[ECC_BLOCK_SIZE] = {};
                    l_errl = deviceRead(l_proc, &l_verifyBlock, ECC_BLOCK_SIZE,
                        DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, 0, EEPROM::AUTOSELECT));
                    if (l_errl)
                    {
                        TS_FAIL("testEccCorrectionForWofData: Failed to read back WOF image corrupted data");
                        break;
                    }

                    // Compare the data read back is the same as the corrupted data that was attempted to be written
                    if (memcmp(l_corruptBlock, l_verifyBlock, ECC_BLOCK_SIZE) != 0)
                    {
                        TS_FAIL("testEccCorrectionForWofData: Corrupted data wasn't written correctly.")
                        TRACFBIN(g_trac_test, "Corrupted (Expected) Data", l_corruptBlock, ECC_BLOCK_SIZE);
                        TRACFBIN(g_trac_test, "Read back Data", l_verifyBlock, ECC_BLOCK_SIZE);
                        break;
                    }

                } // Done checking corrupt data was successfully written

                // Read WOF table header and check ECC.
                // Fetching the WOF via the API should've corrected the data in the process.
                l_errl = fapi2::platAttrSvc::getSeepromEccLessWofData(l_proc, BLOCK_SIZE, 0, &l_corruptBlock);
                if (l_errl)
                {
                    TS_FAIL("testEccCorrectionForWofData: getSeepromEccLessWofData(...) Unexpected Error");
                    break;
                }

                // The data returned is ECCless so read the data directly and include the ECC. It should
                // be corrected.
                l_errl = deviceRead(l_proc, &l_corruptBlock, ECC_BLOCK_SIZE,
                    DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, 0, EEPROM::AUTOSELECT));

                if (l_errl)
                {
                    TS_FAIL("testEccCorrectionForWofData: Failed to get WOF image corrected data");
                    break;
                }

                // Compare the data fetched via the API is the same as the original block
                if (memcmp(l_corruptBlock, l_originalBlock, ECC_BLOCK_SIZE) != 0)
                {
                    TS_FAIL("testEccCorrectionForWofData: Corrupted Data was not corrected by WOF API.")
                    TRACFBIN(g_trac_test, "Original (Expected) Data", l_originalBlock, ECC_BLOCK_SIZE);
                    TRACFBIN(g_trac_test, "Corrupted Data", l_corruptBlock, ECC_BLOCK_SIZE);
                    break;
                }
            }


        } while (0);

        // Commit error if any from do-while loop
        if (l_errl)
        {
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }

        // In case WOF image is used again in a test, write back original magic value to header
        l_errl = deviceWrite(l_proc, &l_originalBlock, ECC_BLOCK_SIZE,
            DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, 0, EEPROM::AUTOSELECT));
        if (l_errl)
        {
            TS_FAIL("testEccCorrectionForWofData: Failed to write back original magic value in header");
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }

        FAPI_INF("testEccCorrectionForWofData: EXIT");


    }

};

#endif // __WOFTEST_H__
