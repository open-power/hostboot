/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/test/pnorutilsTest.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#ifndef PNORUTILSTEST_H
#define PNORUTILSTEST_H

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include "pnorUtilsTestResources.H"
#include <usr/vmmconst.h>
#include <pnor/pnor_const.H>
#include <pnor/pnorif.H>
#include <pnor_utils.H>

/**
 *  @file pnorutilsTest.H
 *
 *  @brief unit tests for pnor utils
*/
extern const char* cv_EYECATCHER[];
extern trace_desc_t* g_trac_pnor;
class pnorutilsTest : public CxxTest::TestSuite
{
  public:


    void test_invalidMagicWord(void)
    {
        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidMagicWord: starting");

        uint8_t l_tocBuffer[PNOR::TOC_SIZE];
        uint32_t l_errCode = 0;
        bool l_failed = false;
        memcpy(l_tocBuffer, testTOC, sizeof(testTOC));

        //mess up the magic word while maintaining checksum
        l_tocBuffer[0] = 0;
        l_tocBuffer[1] = 0;
        l_tocBuffer[16] = 0x50;
        l_tocBuffer[17] = 0x41;

        ffs_hdr* l_ffs_hdr = NULL;
        PNOR::checkForNullBuffer(l_tocBuffer, l_errCode, l_ffs_hdr);
        PNOR::checkHeader(l_ffs_hdr, l_errCode);

        if((l_errCode & PNOR::INVALID_MAGIC) == PNOR::INVALID_MAGIC)
        {
            TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidMagicWord: Successfully found error with magic number");
        }
        else
        {
            TS_FAIL("pnorutilsTest::test_invalidMagicWord: Failed to find error with magic word ERR CODE: 0x%x", l_errCode);
            l_failed = true;
        }

        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidMagicWord: complete, Failed = %d", l_failed);
    }

    void test_invalidFFSVersion(void)
    {
        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidFFSVersion: starting");
        uint8_t l_tocBuffer[PNOR::TOC_SIZE];
        uint32_t l_errCode = 0;
        bool l_failed = false;

        memcpy(l_tocBuffer, testTOC, sizeof(testTOC));

        //mess up the FFS version while maintaining checksum
        l_tocBuffer[23] = 0x1;
        l_tocBuffer[7] = 0x0;

        ffs_hdr* l_ffs_hdr = NULL;
        PNOR::checkForNullBuffer(l_tocBuffer, l_errCode, l_ffs_hdr);
        PNOR::checkHeader(l_ffs_hdr, l_errCode);


        if((l_errCode & PNOR::UNSUPPORTED_FFS) == PNOR::UNSUPPORTED_FFS)
        {
            TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidFFSVersion: Successfully found error with version");
        }
        else
        {
            TS_FAIL("pnorutilsTest::test_invalidFFSVersion: failed to find error with version. ERR CODE: 0x%x", l_errCode);
            l_failed = true;
        }

        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidFFSVersion: complete, Failed = %d", l_failed);
    }

    void test_invalidEntrySize(void)
    {
        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidEntrySize: starting");
        uint8_t l_tocBuffer[PNOR::TOC_SIZE];
        uint32_t l_errCode = 0;
        bool l_failed = false;
        memcpy(l_tocBuffer, testTOC, sizeof(testTOC));

        //Make the entry size 0 while maintaining checksum
        l_tocBuffer[15] = 0x0;
        l_tocBuffer[31] = 0x80;

        ffs_hdr* l_ffs_hdr = NULL;
        PNOR::checkForNullBuffer(l_tocBuffer, l_errCode, l_ffs_hdr);
        PNOR::checkHeader(l_ffs_hdr, l_errCode);


        if((l_errCode & PNOR::INVALID_ENTRY_SIZE)
              == PNOR::INVALID_ENTRY_SIZE)
        {
            TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidEntrySize: Successfully found error with entry size");
        }
        else
        {
            TS_FAIL("pnorutilsTest::test_invalidEntrySize: failed to find error with entry size.  ERR CODE: 0x%x", l_errCode);
            l_failed = true;
        }

        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidEntrySize: complete, Failed = %d", l_failed);
    }

    void test_invalidEntryCount(void)
    {
        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidEntryCount: starting");
        uint8_t l_tocBuffer[PNOR::TOC_SIZE];
        uint32_t l_errCode = 0;
        bool l_failed = false;
        memcpy(l_tocBuffer, testTOC, sizeof(testTOC));

        //make the entry count 0 while maintaining checksum
        l_tocBuffer[19] = 0x00;
        l_tocBuffer[35] = 0x12;

        ffs_hdr* l_ffs_hdr = NULL;
        PNOR::checkForNullBuffer(l_tocBuffer, l_errCode, l_ffs_hdr);
        PNOR::checkHeader(l_ffs_hdr, l_errCode);


        if((l_errCode & PNOR::NO_ENTRIES)== PNOR::NO_ENTRIES)
        {
            TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidEntryCount: Successfully found error with entry count");
        }
        else
        {
            TS_FAIL("pnorutilsTest::test_invalidEntryCount: Failed to find error with entry count. ERR CODE: 0x%x", l_errCode);
            l_failed = true;
        }

        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidEntryCount: complete, Failed = %d", l_failed);
    }

    void test_invalidBlockSize(void)
    {
        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidBlockSize: starting");
        uint8_t l_tocBuffer[PNOR::TOC_SIZE];
        uint32_t l_errCode = 0;
        bool l_failed = false;
        memcpy(l_tocBuffer, testTOC, sizeof(testTOC));

        //make the block size 0 while maintaining checksum
        l_tocBuffer[22] = 0x00;
        l_tocBuffer[38] = 0x10;

        ffs_hdr* l_ffs_hdr = NULL;
        PNOR::checkForNullBuffer(l_tocBuffer, l_errCode, l_ffs_hdr);
        PNOR::checkHeader(l_ffs_hdr, l_errCode);


        if((l_errCode & PNOR::INVALID_BLOCK_SIZE) == PNOR::INVALID_BLOCK_SIZE)
        {
            TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidBlockSize: Successfully found error with block size");
        }
        else
        {
            TS_FAIL("pnorutilsTest::test_invalidBlockSize: Failed to find error with the block size. ERR CODE: 0x%x", l_errCode);
            l_failed = true;
        }

        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidBlockSize: complete, Failed = %d", l_failed);
    }

    void test_invalidBlockCount(void)
    {
        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidBlockCount: starting");
        uint8_t l_tocBuffer[PNOR::TOC_SIZE];
        uint32_t l_errCode = 0;
        bool l_failed = false;
        memcpy(l_tocBuffer, testTOC, sizeof(testTOC));

        //make the block count 0 while maintaining checksum
        l_tocBuffer[26] = 0x00;
        l_tocBuffer[42] = 0x40;

        ffs_hdr* l_ffs_hdr = NULL;
        PNOR::checkForNullBuffer(l_tocBuffer, l_errCode, l_ffs_hdr);
        PNOR::checkHeader(l_ffs_hdr, l_errCode);


        if((l_errCode & PNOR::INVALID_BLOCK_COUNT)
              == PNOR::INVALID_BLOCK_COUNT)
        {
            TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidBlockCount: Successfully found error with block count");
        }
        else
        {
            TS_FAIL("pnorutilsTest::test_invalidBlockCount: Failed to find error with block count. ERR CODE: 0x%x", l_errCode);
            l_failed = true;
        }

        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidBlockCount: complete, Failed = %d", l_failed);
    }

    void test_invalidHdrSize(void)
    {
        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidHdrSize: starting");
        uint8_t l_tocBuffer[PNOR::TOC_SIZE];
        uint32_t l_errCode = 0;
        bool l_failed = false;
        memcpy(l_tocBuffer, testTOC, sizeof(testTOC));

        //Shrink block size to 51 while maintaining checksum
        l_tocBuffer[22] = 0x00;
        l_tocBuffer[38] = 0x10;
        l_tocBuffer[23] = 0x33;
        l_tocBuffer[39] = 0x33;

        ffs_hdr* l_ffs_hdr = NULL;
        PNOR::checkForNullBuffer(l_tocBuffer, l_errCode, l_ffs_hdr);
        PNOR::checkHeader(l_ffs_hdr, l_errCode);


        if((l_errCode & PNOR::INVALID_HEADER_SIZE)
              == PNOR::INVALID_HEADER_SIZE)
        {
            TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidHdrSize: Successfully found error with hdr size");
        }
        else
        {
            TS_FAIL("pnorutilsTest::test_invalidHdrSize: Failed to find error with hdr size. ERR CODE: 0x%x", l_errCode);
            l_failed = true;
        }

        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidHdrSize: complete, Failed = %d", l_failed);
    }

    void test_invalidEntryChecksum(void)
    {
        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidEntryChecksum: starting");
        uint8_t l_tocBuffer[PNOR::TOC_SIZE];
        uint32_t l_errCode = 0;
        bool l_failed = false;
        memcpy(l_tocBuffer, testTOC, sizeof(testTOC));

        //Mess up the checksum of an entry
        l_tocBuffer[208] = 0xFF;
        PNOR::SectionData_t l_TOC[PNOR::NUM_SECTIONS];
        ffs_hdr* l_ffs_hdr = NULL;
        PNOR::checkForNullBuffer(l_tocBuffer, l_errCode, l_ffs_hdr);
        PNOR::checkHeader(l_ffs_hdr, l_errCode);
        //parse through the entries and check for any errors
        ffs_entry* l_err_entry = NULL;
        PNOR::parseEntries(l_ffs_hdr, l_errCode, l_TOC, l_err_entry);

        if((l_errCode & PNOR::ENTRY_CHECKSUM_ERR)
              == PNOR::ENTRY_CHECKSUM_ERR)
        {
            TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidEntryChecksum: Successfully found error with entry checksum");
        }
        else
        {
            TS_FAIL("pnorutilsTest::test_invalidEntryChecksum: Failed to find error the checksum for an entry. ERR CODE: 0x%x", l_errCode);
            l_failed = true;
        }

        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_invalidEntryChecksum: complete, Failed = %d", l_failed);
    }

    void test_entryExtendsBeyondFlash(void)
    {
        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_entryExtendsBeyondFlash: starting");
        uint8_t l_tocBuffer[PNOR::TOC_SIZE];
        uint32_t l_errCode = 0;
        bool l_failed = false;
        memcpy(l_tocBuffer, testTOC, sizeof(testTOC));

        //make the block count 1
        l_tocBuffer[26] = 0x01;
        //make the size of the entry 0xFFFFFF24 (the 24 is in there)
        l_tocBuffer[196] = 0xFF;
        l_tocBuffer[197] = 0xFF;
        l_tocBuffer[198] = 0xFF;
        //Make sure you don't mess up the checksum
        l_tocBuffer[212] = 0xFF;
        l_tocBuffer[213] = 0xFF;
        l_tocBuffer[214] = 0xFF;

        PNOR::SectionData_t l_TOC[PNOR::NUM_SECTIONS];
        ffs_hdr* l_ffs_hdr = NULL;
        PNOR::checkForNullBuffer(l_tocBuffer, l_errCode, l_ffs_hdr);
        PNOR::checkHeader(l_ffs_hdr, l_errCode);
        //parse through the entries and check for any errors
        ffs_entry* l_err_entry = NULL;
        PNOR::parseEntries(l_ffs_hdr, l_errCode, l_TOC, l_err_entry);

        if((l_errCode & PNOR::ENTRY_EXTENDS_BEYOND_FLASH)
              == PNOR::ENTRY_EXTENDS_BEYOND_FLASH)
        {
            TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_entryExtendsBeyondFlash: Successfully found error with size of all entries");
        }
        else
        {
            TS_FAIL("pnorutilsTest::test_entryExtendsBeyondFlash: Failed to find error about entries extending beyond flash. ERR CODE: 0x%x", l_errCode);
            l_failed = true;
        }

        TRACFCOMP(g_trac_pnor, "pnorutilsTest::test_entryExtendsBeyondFlash: complete, Failed = %d", l_failed);
    }
};

#endif
