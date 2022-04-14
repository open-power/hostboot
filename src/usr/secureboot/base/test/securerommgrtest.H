/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/test/securerommgrtest.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#ifndef __SECUREROMMANAGERTEST_H
#define __SECUREROMMANAGERTEST_H

#include <array>
#include <sys/mm.h>
#include <sys/mmio.h>
#include <vfs/vfs.H>
#include <kernel/pagemgr.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <secureboot/service.H>
#include <secureboot/secure_reasoncodes.H>
#include <kernel/bltohbdatamgr.H>
#include <stddef.h>

#include "../securerommgr.H"

#include "../../common/securetrace.H"

#include <secureboot/containerheader.H>
#include "../../../vfs/vfsrp.H"
#include <sys/vfs.h>
#include <kernel/console.H>
#include <pnor/pnorif.H>

// Quick change for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// simply the syntax of accessing g_trac_secure
using namespace SECUREBOOT;

/**********************************************************************/
/*  UTILITY FUNCTIONS                                                 */
/*  -- note: these functions do not commit error logs                 */
/**********************************************************************/

// Moves signed files from PNOR to paged-in memory
errlHndl_t loadSignedFile( const char * i_signedFile_name,
                           void * & o_signedFile_pageAddr,
                           size_t & o_signedFile_size,
                           uint64_t & o_signedFile_virtAddr);

// Safely removes signed files from memory
void unloadSignedFile( void * & io_signedFile_pageAddr,
                       size_t & io_signedFile_size     );

// secureboot_signed_container was generated using this hw hash key. If another
// key is in the HBBL, this test will always fail.
const SHA512_t hw_key_hash =
{
    0x40,0xd4,0x87,0xff,0x73,0x80,0xed,0x6a,
    0xd5,0x47,0x75,0xd5,0x79,0x5f,0xea,0x0d,
    0xe2,0xf5,0x41,0xfe,0xa9,0xdb,0x06,0xb8,
    0x46,0x6a,0x42,0xa3,0x20,0xe6,0x5f,0x75,
    0xb4,0x86,0x65,0x46,0x00,0x17,0xd9,0x07,
    0x51,0x5d,0xc2,0xa5,0xf9,0xfc,0x50,0x95,
    0x4d,0x6e,0xe0,0xc9,0xb6,0x7d,0x21,0x9d,
    0xfb,0x70,0x85,0x35,0x1d,0x01,0xd6,0xd1
};


// secureboot_signed_container payload text size
size_t payload_text_size = 0x200;

// secureboot_signed_container payload text hash
const SHA512_t payload_text_hash =
{
    0xff,0xc3,0x93,0xb7,0x71,0xc4,0x09,0xd4,
    0x4d,0x8f,0xef,0xfa,0xcf,0xeb,0x7a,0x09,
    0x11,0x7c,0x75,0x3f,0x62,0x27,0x34,0x70,
    0xc2,0x93,0x24,0x04,0xea,0xd1,0x51,0xd5,
    0xba,0xe5,0x2e,0xbd,0x49,0x30,0x10,0x61,
    0xee,0x53,0x7b,0x7f,0xd9,0x64,0xac,0x84,
    0x97,0x21,0x64,0xa3,0x09,0x6c,0x87,0xc4,
    0x65,0x3e,0x8e,0xcb,0xfe,0x8f,0x4a,0xc5
};

/**********************************************************************/
/*  End of UTILITY FUNCTIONS                                          */
/**********************************************************************/

class SecureRomManagerTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief Secure ROM Test - Verify a Signed Container
     */
    void test_verify(void)
    {
        TRACUCOMP(g_trac_secure,ENTER_MRK"SecureRomManagerTest::test_verify>");

        errlHndl_t  l_errl  =   nullptr;

        /*******************************************************************/
        /* Load "secureboot_signed_container" from PNOR to use for verification  */
        /*******************************************************************/

        // Signed file variables
        const char * signedFile_name =   "secureboot_signed_container";
        void *  signedFile_pageAddr  =   nullptr;
        size_t  signedFile_size      =   0;
        uint64_t signedFile_vaddr    =   0;

        // Call utility function
        l_errl = loadSignedFile( signedFile_name,
                                 signedFile_pageAddr,
                                 signedFile_size,
                                 signedFile_vaddr);
        if (l_errl)
        {
            TS_FAIL("SecureRomManagerTest::test_verify: loadSignedFile() Failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        /*******************************************************************/
        /* Call verify function                                            */
        /*******************************************************************/

        // Warn about the exception being handled during verification
        printkd("test_verify(): expect to see 'mfsr r2 to CFAR handled': ");

        l_errl = SECUREBOOT::verifyContainer(signedFile_pageAddr,
                                             {},
                                             &hw_key_hash);
        if (l_errl)
        {
            TS_FAIL("SecureRomManagerTest::test_verify: verifyContainer() Failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        /*******************************************************************/
        /* Unload "secureboot_signed_container" from memory                */
        /*******************************************************************/
        if ( signedFile_pageAddr != nullptr   )
        {
            unloadSignedFile( signedFile_pageAddr, signedFile_size);
        }

        TRACUCOMP(g_trac_secure,EXIT_MRK"SecureRomManagerTest::test_verify");
    }

    /**
     * @brief Secure ROM Test - Test sha512 hash
     */
    void test_sha512(void)
    {
        TRACUCOMP(g_trac_secure,ENTER_MRK"SecureRomManagerTest::test_sha512>");

        // Constants for sha512 test
        const sha2_byte l_text[]={"The quick brown fox jumps over the lazy dog"};
        // Do not include NULL character in sha512 test
        size_t l_textSize = 43;
        const uint64_t l_textHash[] =
        {
            0x07E547D9586F6A73,
            0xF73FBAC0435ED769,
            0x51218FB7D0C8D788,
            0xA309D785436BBB64,
            0x2E93A252A954F239,
            0x12547D1E8A3B5ED6,
            0xE1BFD7097821233F,
            0xA0538F3DB854FEE6
        };

        // Result hash
        SHA512_t l_resultHash = {0};
        SECUREBOOT::hashBlob(&l_text, l_textSize, l_resultHash);

        // Ensure calculated result matches expected result
        if (memcmp(l_textHash, l_resultHash, SHA512_DIGEST_LENGTH) != 0)
        {
            TS_FAIL("SecureRomManagerTest::test_sha512: hashBlob() Failed");
        }

        TRACUCOMP(g_trac_secure,EXIT_MRK"SecureRomManagerTest::test_sha512");
    }

    /**
     * @brief Secure ROM Test - Parse a Signed Container and check if the values
     *                     match what's expected for secureboot_signed_container
     */
    void test_parse_container_header(void)
    {
        TRACFCOMP(g_trac_secure,ENTER_MRK"SecureRomManagerTest::test_parse_container_header>");

        errlHndl_t  l_errl  =   nullptr;

        /*******************************************************************/
        /* Load "secureboot_signed_container" from PNOR to use for verification  */
        /*******************************************************************/

        // Signed file variables
        const char * signedFile_name =   "secureboot_signed_container";
        void *  signedFile_pageAddr  =   nullptr;
        size_t  signedFile_size      =   0;
        uint64_t signedFile_vaddr    =   0;

        do{

        // Call utility function
        l_errl = loadSignedFile( signedFile_name,
                                 signedFile_pageAddr,
                                 signedFile_size,
                                 signedFile_vaddr);

        if (l_errl)
        {
            TS_FAIL("SecureRomManagerTest::test_parse_container_header: loadSignedFile() Failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }

        TRACUCOMP(g_trac_secure, "SecureRomManagerTest::test_parse_container_header: "
                  "signedFile info: addr = %p, size=0x%x",
                  signedFile_pageAddr, signedFile_size);

        /*******************************************************************/
        /* Parse Secure Container Header                                   */
        /*******************************************************************/
        SECUREBOOT::ContainerHeader l_conHdr;
        l_errl = l_conHdr.setHeader(signedFile_pageAddr);
        if (l_errl)
        {
            TS_FAIL("SecureRomManagerTest::test_parse_container_header: failed to parse Container Header");
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }

        // Check if container header seems valid
        if (!l_conHdr.iv_isValid)
        {
            TS_FAIL("SecureRomManagerTest::test_parse_container_header: Header is not valid");
            break;
        }
        // Check a few of the values that are parsed out.
        if(l_conHdr.payloadTextSize() != payload_text_size)
        {
            TS_FAIL("SecureRomManagerTest::test_parse_container_header: Incorrect payload text size");
            break;
        }

        if (memcmp(l_conHdr.payloadTextHash(), payload_text_hash,
                   sizeof(SHA512_t) != 0))
        {
            TS_FAIL("SecureRomManagerTest::test_parse_container_header: Incorrect payload text hash");
            break;
        }

        } while(0);
        /*******************************************************************/
        /* Unload "secureboot_signed_container" from memory                */
        /*******************************************************************/
        if ( signedFile_pageAddr != nullptr   )
        {
            unloadSignedFile( signedFile_pageAddr, signedFile_size);
        }

        TRACFCOMP(g_trac_secure,EXIT_MRK"SecureRomManagerTest::test_parse_container_header");
    }

    /**
     * @brief Secure ROM Test - Verification of pages via a hash page table at
     *                          the beginning of a payload text section.
     */
    void test_hash_page_table_verify(void)
    {
        TRACFCOMP(g_trac_secure,ENTER_MRK"SecureRomManagerTest::test_hash_page_table_verify>");

        errlHndl_t  l_errl  =   nullptr;
        // secureboot_hash_page_table_container has 5 pages of data
        const uint64_t TEST_PAGE_NUM = 2;

        // Signed file variables
        const char * signedFile_name =   "secureboot_hash_page_table_container";
        void *  signedFile_pageAddr  =   nullptr;
        size_t  signedFile_size      =   0;
        uint64_t signedFile_vaddr    =   0;

        uint8_t* l_originPage = new uint8_t[PAGESIZE]();

        do{

        // Call utility function
        l_errl = loadSignedFile( signedFile_name,
                                 signedFile_pageAddr,
                                 signedFile_size,
                                 signedFile_vaddr);

        if (l_errl)
        {
            TS_FAIL("SecureRomManagerTest::test_hash_page_table_verify: loadSignedFile() Failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }

        TRACUCOMP(g_trac_secure, "SecureRomManagerTest::test_hash_page_table_verify: "
                  "signedFile info: addr = %p, size=0x%x",
                  signedFile_pageAddr, signedFile_size);

        /*******************************************************************/
        /* Parse Secure Container Header                                   */
        /*******************************************************************/

        SECUREBOOT::ContainerHeader l_conHdr;
        l_errl = l_conHdr.setHeader(signedFile_pageAddr);
        if (l_errl)
        {
            TS_FAIL("SecureRomManagerTest::test_hash_page_table_verify: failed to parse Container Header");
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }
        size_t l_payloadTextSize = l_conHdr.payloadTextSize();
        TRACUCOMP(g_trac_secure, "SecureRomManagerTest::test_hash_page_table_verify ContainerHeader payload_size = 0x%X",
                  l_payloadTextSize);

        /*******************************************************************/
        /* Test Verifying a correct page                                   */
        /*******************************************************************/

        // Get base offset of test container with respect to the HBI section
        signedFile_vaddr-=VFS_EXTENDED_MODULE_VADDR;
        uint64_t l_hashPageTableOffset = signedFile_vaddr + PAGE_SIZE;
        uint64_t l_baseOffset = signedFile_vaddr
                                + PAGE_SIZE
                                + l_payloadTextSize;

        // Get offset of TEST_PAGE_NUM
        uint64_t l_vaddr = l_baseOffset
                           + (TEST_PAGE_NUM * PAGESIZE);

        // Verify a page
        TRACUCOMP(g_trac_secure, "SecureRomManagerTest::test_hash_page_table_verify vaddr = 0x%X, base offset = 0x%X, hash page table offset = 0x%X",
                  l_vaddr, l_baseOffset, l_hashPageTableOffset);
        l_errl = VFS::VfsRp::getInstance().verify_page(l_vaddr,
                                                       l_baseOffset,
                                                       l_hashPageTableOffset);
        // Failed to pass secureboot verification
        if (l_errl)
        {
            TS_FAIL("SecureRomManagerTest::test_hash_page_table_verify failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }

        /*******************************************************************/
        /* Test verifying a corrupt page                                  */
        /*******************************************************************/

        // Calculate pnor vaddr and read original page so we can run test case
        // in both secure and unsecure mode.
        uint64_t l_pnorVaddr = VFS::VfsRp::getInstance().iv_pnor_vaddr
                               - VFS::VfsRp::getInstance().iv_unprotectedOffset
                               + l_vaddr;
        memcpy(l_originPage, reinterpret_cast<uint8_t*>(l_pnorVaddr), PAGESIZE);
        // Open the write permissions to allow the test to temporarily corrupt
        // the partition.
        int l_rc = mm_set_permission(reinterpret_cast<void*>(l_pnorVaddr),
                                     2*PAGESIZE,
                                     WRITABLE);
        if(l_rc)
        {
            TS_FAIL("mm_set_permission: Cannot set permissions to write");
            break;
        }

        // Corrupt page
        uint8_t l_corruptByte = 0xFF;
        memcpy(reinterpret_cast<uint8_t*>(l_pnorVaddr), &l_corruptByte, sizeof(uint8_t));
        l_errl =  VFS::VfsRp::getInstance().verify_page(l_vaddr,
                                                        l_baseOffset,
                                                        l_hashPageTableOffset);

        // Fix page back up
        memcpy(reinterpret_cast<uint8_t*>(l_pnorVaddr), l_originPage, PAGESIZE);

        // Failed to catch secureboot verification failure
        if (!l_errl)
        {
            TS_FAIL("SecureRomManagerTest::test_hash_page_table_verify did not catch verification error");
            break;
        }
        delete l_errl;
        l_errl = nullptr;

        // Reset to read-only permissions.
        l_rc = mm_set_permission(reinterpret_cast<void*>(l_pnorVaddr),
                                     2*PAGESIZE,
                                     READ_ONLY);
        if(l_rc)
        {
            TS_FAIL("mm_set_permission: Cannot reset permissions to read only");
            break;
        }

        } while(0);

        if ( signedFile_pageAddr != nullptr   )
        {
            unloadSignedFile( signedFile_pageAddr, signedFile_size);
        }
        if (l_originPage != nullptr)
        {
            delete [] l_originPage;
            l_originPage = nullptr;
        }

        TRACFCOMP(g_trac_secure,EXIT_MRK"SecureRomManagerTest::test_hash_page_table_verify");
    }

    void test_verifyComponentId(void)
    {
        errlHndl_t pError = nullptr;

        // Signed file variables
        const char* signedFile_name = "secureboot_signed_container";
        void*  signedFile_pageAddr  = nullptr;
        size_t  signedFile_size     = 0;
        uint64_t signedFile_vaddr   = 0;

        do {

        struct verifyComponentIdTest
        {
            const char* pActualCompId;
            const char* pRefCompId;
            bool shouldPass;
        };

        const std::vector<verifyComponentIdTest> tests =
            { {"ABCD1234","ABCD12345", true },
              {"ABCD1234","ABCD1234" , true },
              {"ABCD1234","ABCD123"  , false},
              {"ABCD123" ,"ABCD12345", false},
              {"ABCD123" ,"ABCD1234" , false},
              {"ABCD123" ,"ABCD123"  , true },
              {"A"       ,"A"        , true },
              {"A"       ,"B"        , false},
              {"A"       ,"AB"       , false},
              {"A"       ,""         , false},
              {""        ,"A"        , false},
              {""        ,""         , true } };

        // Call utility function
        pError = loadSignedFile( signedFile_name,
                                 signedFile_pageAddr,
                                 signedFile_size,
                                 signedFile_vaddr);

        if (pError)
        {
            TS_FAIL("SecureRomManagerTest::test_verifyComponentId: "
                "loadSignedFile() Failed");
            errlCommit(pError, SECURE_COMP_ID);
            break;
        }

        // Could replace with SECUREBOOT::ContainerHeader ability to generate
        // fake headers
        char pHeader[MAX_SECURE_HEADER_SIZE]={0};
        memcpy(pHeader,signedFile_pageAddr,sizeof(pHeader));

        char* const pCompIdInContainer = pHeader
            + offsetof(ROM_container_raw,prefix)
            + offsetof(ROM_prefix_header_raw,ecid)
            + offsetof(ROM_prefix_data_raw,sw_pkey_q)
            + offsetof(ROM_sw_header_raw,component_id);

        const size_t compIdSize = sizeof(ROM_sw_header_raw::component_id);

        for(const auto& test : tests)
        {
            memset(pCompIdInContainer,0x00,compIdSize);
            strncpy(pCompIdInContainer,test.pActualCompId,compIdSize);
            SECUREBOOT::ContainerHeader containerHeader;
            pError = containerHeader.setHeader(pHeader);
            if (pError)
            {
                errlCommit(pError, SECURE_COMP_ID);
                TS_FAIL("SecureRomManagerTest::test_verifyContainer: failed to parse Container Header");
                break;
            }


            pError = SECUREBOOT::verifyComponentId(
                containerHeader,
                test.pRefCompId);
            if(pError)
            {
                if(test.shouldPass)
                {
                    TS_FAIL("SecureRomManagerTest::test_verifyContainer: "
                        "Expected SECUREBOOT::verifyComponentId to pass, but it "
                        "failed.  Actual component ID was [%s], reference "
                        "component ID was [%s]",
                        test.pActualCompId,
                        test.pRefCompId);
                    errlCommit(pError, SECURE_COMP_ID);
                }
                else // Should fail
                {
                    // But verify it's the right fail
                    if(   (   pError->reasonCode()
                           != SECUREBOOT::RC_ROM_VERIFY)
                       || (   pError->moduleId()
                           !=  SECUREBOOT::MOD_SECURE_VERIFY_COMPONENT))
                    {
                        TS_FAIL("SecureRomManagerTest::test_verifyContainer: "
                            "Expected SECUREBOOT::verifyComponentId to fail with "
                            "reason code of 0x%04X and module ID of 0x%02X, but "
                            "failed with reason code of 0x%04X and module ID "
                            "of 0x%02X.  Actual component ID was [%s], "
                            "reference component ID was [%s]",
                            SECUREBOOT::RC_ROM_VERIFY,
                            SECUREBOOT::MOD_SECURE_VERIFY_COMPONENT,
                            pError->reasonCode(),
                            pError->moduleId(),
                            test.pActualCompId,
                            test.pRefCompId);
                        errlCommit(pError, SECURE_COMP_ID);
                    }
                    else
                    {
                        delete pError;
                        pError = nullptr;
                    }
                }
            }
            else if(!test.shouldPass)
            {
                TS_FAIL("SecureRomManagerTest::test_verifyContainer: "
                    "Expected SECUREBOOT::verifyComponentId to fail, but it "
                    "passed.  Actual component ID was [%s], reference "
                    "component ID was [%s]",
                    test.pActualCompId,
                    test.pRefCompId);
            }
        }

        } while(0);

        if ( signedFile_pageAddr != nullptr   )
        {
            unloadSignedFile( signedFile_pageAddr, signedFile_size);
        }
    }

    void test_fakeHeader(void)
    {
        TRACFCOMP(g_trac_secure,"SecureRomManagerTest::test_fakeHeader");

        const size_t l_payloadSize = 0x10000;
        // Purposely make a comp id larger than SW_HDR_COMP_ID_SIZE_BYTES
        // otherwise strncmp below needs a different size
        const char* l_compId = "FAKEHEADERTEST";

        do {
        // Simple call constructor to create fake header and make sure it
        // does not cause an error
        SECUREBOOT::ContainerHeader l_fakeHdr;
        errlHndl_t l_errl = l_fakeHdr.setFakeHeader(l_payloadSize,
                                                    l_compId);
        if (l_errl)
        {
            TS_FAIL("SecureRomManagerTest::test_fakeHeader: failed to parse Container Header");
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }

        // Total Container size should be payload size + PAGE_SIZE(header size)
        if(l_fakeHdr.totalContainerSize() != (l_payloadSize + PAGE_SIZE))
        {
            TS_FAIL("SecureRomManagerTest::test_fakeHeader: total container size was not parsed correctly");
        }

        // Check that payload text size was assigned correctly.
        if(l_fakeHdr.payloadTextSize() != (l_payloadSize))
        {
            TS_FAIL("SecureRomManagerTest::test_fakeHeader: payload text size was not parsed correctly");
            break;
        }

        // Ensure the parsed component ID matches what was passed in through
        // SW_HDR_COMP_ID_SIZE_BYTES
        if(strncmp(l_fakeHdr.componentId(), l_compId,
                   SW_HDR_COMP_ID_SIZE_BYTES) != 0)
        {
            TS_FAIL("SecureRomManagerTest::test_fakeHeader: component ID was not parsed correctly");
            break;
        }
        } while(0);
    }
};

/**********************************************************************/
/*  UTILITY FUNCTIONS                                                 */
/**********************************************************************/

// Moved secureboot_signed_container from PNOR to paged-in memory
errlHndl_t loadSignedFile( const char * i_signedFile_name,
                                void * & o_signedFile_pageAddr,
                                size_t & o_signedFile_size,
                                uint64_t & o_signedFile_virtAddr)
{

        errlHndl_t  l_errl  =   nullptr;
        const char * l_signedFile_virtAddr  =   nullptr;

        /*******************************************************************/
        /* Load file from PNOR to use for verification                     */
        /*******************************************************************/

        // Load file into virtual memory
        l_errl = VFS::module_load( i_signedFile_name );
        if (l_errl)
        {
            TRACFCOMP(g_trac_secure, "loadSignedFile(): Module "
                                     "Load FAILED: %s", i_signedFile_name);

            return l_errl;
        }

        // Get memory address of file
        l_errl = VFS::module_address ( i_signedFile_name,
                                       l_signedFile_virtAddr,
                                       o_signedFile_size);
        if (l_errl)
        {
            TRACFCOMP(g_trac_secure, "loadSignedFile()> Module "
                                     "Address FAILED: %s", i_signedFile_name);

            return l_errl;
        }

        // Get the VFS virtual address
        o_signedFile_virtAddr = reinterpret_cast<uint64_t>(l_signedFile_virtAddr);

        // Request contiguous memory block to copy in file
        size_t l_num_pages = ALIGN_PAGE(o_signedFile_size)/PAGESIZE;
        bool l_isUserspace = true;
        o_signedFile_pageAddr = PageManager::allocatePage(l_num_pages,
                                                          l_isUserspace);

        //  memcpy the file to allocated pages
        memcpy( o_signedFile_pageAddr, l_signedFile_virtAddr,
                o_signedFile_size );

        TRACUCOMP(g_trac_secure, "loadSignedFile()> signedFile '%s' "
                  "Info: sF_pA=%p, sF_vA=%p, size=0x%x (pages=%d)",
                  i_signedFile_name, o_signedFile_pageAddr,
                  l_signedFile_virtAddr, o_signedFile_size, l_num_pages);

    return l_errl;
}

// Safely removes signed files from memory
void unloadSignedFile( void * & io_signedFile_pageAddr,
                       size_t & io_signedFile_size     )
{
        // Determine number of pages to be freed
        size_t l_num_pages = ALIGN_PAGE(io_signedFile_size)/PAGESIZE;

        // Free page(s)
        PageManager::freePage(io_signedFile_pageAddr, l_num_pages);

        // Reset pageAddr pointer
        io_signedFile_pageAddr = nullptr;

        TRACUCOMP(g_trac_secure, "unloadSignedFile()> "
                  "Info: sF_pA=%p, size=0x%x (pages=%d)",
                  io_signedFile_pageAddr, io_signedFile_size, l_num_pages);
}

#endif
