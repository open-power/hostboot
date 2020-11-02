/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2WOFTest.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include <devicefw/userif.H>
#include <utilFilter.H>
#include <pstates_common.H>
#include <eeprom/eeprom_const.H>

using namespace TARGETING;

namespace fapi2
{
namespace platAttrSvc
{
    // Function definition being brought in to be tested
    errlHndl_t getSeepromWofTable(TARGETING::Target* i_target, uint8_t* o_wofData);
}
}

class WOFTest: public CxxTest::TestSuite
{

public:

    /**
      * @brief Test WOF table access attribute
      *
      */
    void testWOFTableAccess (void)
    {
        //fapi2::ReturnCode l_rc;
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sysParent;

        FAPI_INF("testWOFTableAccess: ENTER");

        // TODO RTC 172778 Enable WOF test and check for correct table data
        /*
        //Set up a char array to hold the data from an attr read
        fapi2::ATTR_WOF_TABLE_DATA_Type l_wofAttrData;

        //Perform an ATTR_GET on sys target
        FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_DATA,
                      l_sysParent,
                      l_wofAttrData);
        */
        FAPI_INF("testWOFTableAccess: EXIT");
    } // testWOFTableAccess


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
            reinterpret_cast<fapi2::ATTR_WOF_TABLE_DATA_Type*>(new fapi2::ATTR_WOF_TABLE_DATA_Type);

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
                break;
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

        FAPI_INF("testGetWofFromSeepromCoverage: Finished testing %d out of %d procs",
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
            reinterpret_cast<fapi2::ATTR_WOF_TABLE_DATA_Type*>(new fapi2::ATTR_WOF_TABLE_DATA_Type);

        // Will be use to store 8-bytes of data and its corresponding ECC
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
            reinterpret_cast<fapi2::ATTR_WOF_TABLE_DATA_Type*>(new fapi2::ATTR_WOF_TABLE_DATA_Type);

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

};

#endif // __WOFTEST_H__
