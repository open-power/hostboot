/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/test/secureromtest.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#ifndef __SECUREROMTEST_H
#define __SECURETOMTEST_H


#include <sys/mm.h>
#include <sys/mmio.h>
#include <vfs/vfs.H>
#include <kernel/pagemgr.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <secureboot/service.H>
#include <secureboot/secure_reasoncodes.H>

#include "../securerom.H"
#include <secureboot/containerheader.H>
#include "../../../vfs/vfsrp.H"
#include <sys/vfs.h>
#include <kernel/console.H>

extern trace_desc_t* g_trac_secure;

// Quick change for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

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
// key is in pibmem, this test will always fail.
const uint64_t hw_hash_key[] =
{
    0x40d487ff7380ed6a,
    0xd54775d5795fea0d,
    0xe2f541fea9db06b8,
    0x466a42a320e65f75,
    0xb48665460017d907,
    0x515dc2a5f9fc5095,
    0x4d6ee0c9b67d219d,
    0xfb7085351d01d6d1
};

// secureboot_signed_container payload text size
size_t payload_text_size = 0x200;

// secureboot_signed_container payload text hash
const uint64_t payload_text_hash[] =
{
    0xffc393b771c409d4,
    0x4d8feffacfeb7a09,
    0x117c753f62273470,
    0xc2932404ead151d5,
    0xbae52ebd49301061,
    0xee537b7fd964ac84,
    0x972164a3096c87c4,
    0x653e8ecbfe8f4ac5
};

/**********************************************************************/
/*  End of UTILITY FUNCTIONS                                          */
/**********************************************************************/

class SecureROMTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief Secure ROM Test - Verify a Signed Container
     */
    void test_verify(void)
    {
        TRACFCOMP(g_trac_secure,ENTER_MRK"SecureROMTest::test_verify>");

        errlHndl_t  l_errl  =   NULL;

        /*******************************************************************/
        /* Load "secureboot_signed_container" from PNOR to use for verification  */
        /*******************************************************************/

        // Signed file variables
        const char * signedFile_name =   "secureboot_signed_container";
        void *  signedFile_pageAddr  =   NULL;
        size_t  signedFile_size      =   0;
        uint64_t signedFile_vaddr    =   0;

        // Call utility function
        l_errl = loadSignedFile( signedFile_name,
                                 signedFile_pageAddr,
                                 signedFile_size,
                                 signedFile_vaddr);

        if (l_errl)
        {
            TS_FAIL("SecureROMTest::test_verify: loadSignedFile() Failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        TRACUCOMP(g_trac_secure, "SecureROMTest::test_verify: "
                  "signedFile info: addr = %p, size=0x%x",
                  signedFile_pageAddr, signedFile_size);

        SecureROM l_sRom;

        // Call initializeSecureROM()
        l_errl = l_sRom.initialize();

        if (l_errl)
        {
            TS_FAIL("SecureROMTest::test_verify: initializeSecureROM() Failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        // Set hw hash key
        memcpy (& l_sRom.iv_hash_key, &hw_hash_key, sizeof(sha2_hash_t));

        /*******************************************************************/
        /* Call verify function                                            */
        /*******************************************************************/

        // Warn about the exception being handled during verification
        printkd("test_verify(): expect to see 'mfsr r2 to CFAR handled': ");

        l_errl = l_sRom.verifyContainer( signedFile_pageAddr,
                                         signedFile_size     );

        if (l_errl)
        {
            TS_FAIL("SecureROMTest::test_verify: verifyContainer() Failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        /*******************************************************************/
        /* Unload "secureboot_signed_container" from memory                */
        /*******************************************************************/
        if ( signedFile_pageAddr != NULL   )
        {
            unloadSignedFile( signedFile_pageAddr, signedFile_size);
        }

        TRACFCOMP(g_trac_secure,EXIT_MRK"SecureROMTest::test_verify");
    }

    /**
     * @brief Secure ROM Test - Parse a Signed Container and check if the values
     *                     match what's expected for secureboot_signed_container
     */
    void test_parse_container_header(void)
    {
        TRACFCOMP(g_trac_secure,ENTER_MRK"SecureROMTest::test_parse_container_header>");

        errlHndl_t  l_errl  =   NULL;

        /*******************************************************************/
        /* Load "secureboot_signed_container" from PNOR to use for verification  */
        /*******************************************************************/

        // Signed file variables
        const char * signedFile_name =   "secureboot_signed_container";
        void *  signedFile_pageAddr  =   NULL;
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
            TS_FAIL("SecureROMTest::test_parse_container_header: loadSignedFile() Failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }

        TRACUCOMP(g_trac_secure, "SecureROMTest::test_parse_container_header: "
                  "signedFile info: addr = %p, size=0x%x",
                  signedFile_pageAddr, signedFile_size);

        /*******************************************************************/
        /* Parse Secure Container Header                                   */
        /*******************************************************************/
        SECUREBOOT::ContainerHeader l_conHdr(signedFile_pageAddr);

        // Check if container header seems valid
        if (!l_conHdr.iv_isValid)
        {
            TS_FAIL("SecureROMTest::test_parse_container_header: Header is not valid");
            break;
        }
        // Check a few of the values that are parsed out.
        if(l_conHdr.payloadTextSize() != payload_text_size)
        {
            TS_FAIL("SecureROMTest::test_parse_container_header: Incorrect payload text size");
            break;
        }

        if (memcmp(l_conHdr.payloadTextHash(), payload_text_hash,
                   sizeof(SHA512_t) != 0))
        {
            TS_FAIL("SecureROMTest::test_parse_container_header: Incorrect payload text hash");
            break;
        }

        } while(0);
        /*******************************************************************/
        /* Unload "secureboot_signed_container" from memory                */
        /*******************************************************************/
        if ( signedFile_pageAddr != NULL   )
        {
            unloadSignedFile( signedFile_pageAddr, signedFile_size);
        }

        TRACFCOMP(g_trac_secure,EXIT_MRK"SecureROMTest::test_parse_container_header");
    }

    /**
     * @brief Secure ROM Test - Verification of pages via a hash page table at
     *                          the beginning of a payload text section.
     */
    void test_hash_page_table_verify(void)
    {
        TRACFCOMP(g_trac_secure,ENTER_MRK"SecureROMTest::test_hash_page_table_verify>");

        errlHndl_t  l_errl  =   NULL;
        // secureboot_hash_page_table_container has 5 pages of data
        const uint64_t TEST_PAGE_NUM = 2;

        // Signed file variables
        const char * signedFile_name =   "secureboot_hash_page_table_container";
        void *  signedFile_pageAddr  =   NULL;
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
            TS_FAIL("SecureROMTest::test_hash_page_table_verify: loadSignedFile() Failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }

        TRACUCOMP(g_trac_secure, "SecureROMTest::test_hash_page_table_verify: "
                  "signedFile info: addr = %p, size=0x%x",
                  signedFile_pageAddr, signedFile_size);

        /*******************************************************************/
        /* Parse Secure Container Header                                   */
        /*******************************************************************/

        SECUREBOOT::ContainerHeader l_conHdr(signedFile_pageAddr);
        size_t l_payloadTextSize = l_conHdr.payloadTextSize();
        TRACUCOMP(g_trac_secure, "SecureROMTest::test_hash_page_table_verify ContainerHeader payload_size = 0x%X",
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
        TRACUCOMP(g_trac_secure, "SecureROMTest::test_hash_page_table_verify vaddr = 0x%X, base offset = 0x%X, hash page table offset = 0x%X",
                  l_vaddr, l_baseOffset, l_hashPageTableOffset);
        uint64_t l_rc = VFS::VfsRp::getInstance().verify_page(
                                                    l_vaddr,
                                                    l_baseOffset,
                                                    l_hashPageTableOffset);
        // Failed to pass secureboot verification
        if(l_rc)
        {
            TS_FAIL("SecureROMTest::test_hash_page_table_verify failed");
            break;
        }

        /*******************************************************************/
        /* Test verifying a corrupt page                                  */
        /*******************************************************************/

        printk("Test case: Expect to see ");

        // Calculate pnor vaddr and read original page so we can run test case
        // in both secure and unsecure mode.
        uint64_t l_pnorVaddr = VFS::VfsRp::getInstance().iv_pnor_vaddr
                               + l_vaddr;
        memcpy(l_originPage, reinterpret_cast<uint8_t*>(l_pnorVaddr), PAGESIZE);

        // Corrupt page
        uint8_t l_corruptByte = 0xFF;
        memcpy(reinterpret_cast<uint8_t*>(l_pnorVaddr), &l_corruptByte, sizeof(uint8_t));
        l_rc = VFS::VfsRp::getInstance().verify_page(
                                        l_vaddr,
                                        l_baseOffset,
                                        l_hashPageTableOffset);

        // Fix page back up
        memcpy(reinterpret_cast<uint8_t*>(l_pnorVaddr), l_originPage, PAGESIZE);

        // Failed to catch secureboot verification failure
        if(!l_rc)
        {
            TS_FAIL("SecureROMTest::test_hash_page_table_verify did not catch verification error");
            break;
        }

        } while(0);

        if ( signedFile_pageAddr != NULL   )
        {
            unloadSignedFile( signedFile_pageAddr, signedFile_size);
        }
        if (l_originPage != NULL)
        {
            delete [] l_originPage;
            l_originPage = NULL;
        }

        TRACFCOMP(g_trac_secure,EXIT_MRK"SecureROMTest::test_hash_page_table_verify");
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

        errlHndl_t  l_errl  =   NULL;
        const char * l_signedFile_virtAddr  =   NULL;

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
        TRACFCOMP(g_trac_secure, "loadSignedFile() module_load");

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
        TRACFCOMP(g_trac_secure, "loadSignedFile() module_address");

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

        TRACFCOMP(g_trac_secure, "loadSignedFile()> signedFile '%s' "
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
        io_signedFile_pageAddr = NULL;

        TRACFCOMP(g_trac_secure, "unloadSignedFile()> "
                  "Info: sF_pA=%p, size=0x%x (pages=%d)",
                  io_signedFile_pageAddr, io_signedFile_size, l_num_pages);
}

#endif
