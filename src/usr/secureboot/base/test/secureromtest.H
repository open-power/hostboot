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
                           size_t & o_signedFile_size     );

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

        // Call utility function
        l_errl = loadSignedFile( signedFile_name,
                                 signedFile_pageAddr,
                                 signedFile_size);

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
        /* Unload "secureboot_signed_container" from memory                      */
        /*******************************************************************/
        if ( signedFile_pageAddr != NULL   )
        {
            unloadSignedFile( signedFile_pageAddr, signedFile_size);
        }

        TRACFCOMP(g_trac_secure,EXIT_MRK"SecureROMTest::test_verify");
    };
};

/**********************************************************************/
/*  UTILITY FUNCTIONS                                                 */
/**********************************************************************/

// Moved secureboot_signed_container from PNOR to paged-in memory
errlHndl_t loadSignedFile( const char * i_signedFile_name,
                                void * & o_signedFile_pageAddr,
                                size_t & o_signedFile_size     )
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
