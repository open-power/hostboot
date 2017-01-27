/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/test/securerommgrtest.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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


#include <sys/mm.h>
#include <sys/mmio.h>
#include <vfs/vfs.H>
#include <kernel/pagemgr.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <secureboot/service.H>
#include <secureboot/secure_reasoncodes.H>
#include <kernel/bltohbdatamgr.H>

#include "../securerommgr.H"

#include "../../common/securetrace.H"

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
const sha2_hash_t hw_key_hash =
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
        if ( signedFile_pageAddr != NULL   )
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
        io_signedFile_pageAddr = NULL;

        TRACUCOMP(g_trac_secure, "unloadSignedFile()> "
                  "Info: sF_pA=%p, size=0x%x (pages=%d)",
                  io_signedFile_pageAddr, io_signedFile_size, l_num_pages);
}

#endif
