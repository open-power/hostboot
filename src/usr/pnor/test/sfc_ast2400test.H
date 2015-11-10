/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/test/sfc_ast2400test.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
/* [+] Google Inc.                                                        */
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
#ifndef __SFC_AST2400TEST_H
#define __SFC_AST2400TEST_H

/**
 *  @file sfc_ast2400test.H
 *
 *  @brief Test case for AST2400 Flash Controller
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <sys/time.h>
#include "../pnordd.H"
#include <list>
#include <targeting/common/attributes.H>
#include <lpc/lpcif.H>
#include "../sfc_ast2400.H"
#include <sio/sio.H>

extern trace_desc_t* g_trac_pnor;

class SfcAST2400Test : public CxxTest::TestSuite
{
  public:

    bool getTestSection(uint64_t &o_physAddr, uint64_t &o_size)
    {
        errlHndl_t l_err = NULL;
        PNOR::SectionInfo_t info;
        uint64_t chip_select = 0xF;
        bool needs_ecc = false;
        bool section_found = false;

        do{

            // Get TEST PNOR section info from PNOR RP
            l_err = PNOR::getSectionInfo( PNOR::TEST,
                                          info );
            if(l_err)
            {
                if(l_err->reasonCode() == PNOR::RC_INVALID_SECTION)
                {
                    //This is expected in some configurations,
                    // so just delete it.
                    delete l_err;
                }
                else
                {
                    //Any other type of error is not expected, so commit it.
                    errlCommit(l_err,PNOR_COMP_ID);
                }
                break;
            }

            l_err = PnorRP::getInstance().computeDeviceAddr((void*)info.vaddr,
                                                            o_physAddr,
                                                            chip_select,
                                                            needs_ecc);
            if(l_err)
            {
                errlCommit(l_err,PNOR_COMP_ID);
                break;
            }

            o_size = info.size;
            section_found = true;

        }while(0);
        return section_found;

    }

    /**
     * @brief Test Flash Reads
     *        Verify that reads work in normal mode and then do
     *        not work in command mode
     */
    void test_FlashReads( void )
    {
        PnorDD& pnordd = Singleton<PnorDD>::instance();

      //todo RTC:133649 -- enable once LPC error handling is in place
      //  SfcAST2400* sfc = reinterpret_cast<SfcAST2400*>(pnordd.iv_sfc );
        mutex_t* l_mutex = pnordd.iv_mutex_ptr;
        errlHndl_t l_err = NULL;

        //Find some pnor to read
        uint64_t base_address;
        uint64_t sect_size;
        if(!getTestSection(base_address, sect_size))
        {
            TRACFCOMP(g_trac_pnor, "SfcAST2400Test::test_FlashReads> Skipped due to not finding test section in PNOR" );
            TS_FAIL("SfcAST2400Test::test_FlashReads> Skipped due to not finding test section in PNOR");
            return;
        }

        mutex_lock(l_mutex);

        //Prove reads work by default and that they fail in command mode
        uint64_t l_readData = 0;
        size_t l_size = sizeof(uint64_t);
        l_err = pnordd._readFlash(base_address,
                                  l_size,
                                  &l_readData);
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_FlashReads> Basic read failed");
            mutex_unlock(l_mutex);//unlock before commit
            errlCommit(l_err,PNOR_COMP_ID);
            return; //just give up if basic reads don't work
        }

        mutex_unlock(l_mutex);
//         *****************************************************
//         Skipping test where we try to read in command mode
//         We know this will fail, currently no solution in place
//         to relay error from BMC to HB
//         todo RTC:133649 -- enable once LPC error handling is in place
//         ********************************
//         // Put controller into command mode (instead of read mode)
//         l_err = sfc->commandMode( true );
//         if( l_err )
//         {
//             TS_FAIL("SfcAST2400Test::test_FlashReads> Error entering command mode");
//             mutex_unlock(l_mutex);//unlock before commit
//             errlCommit(l_err,PNOR_COMP_ID);
//             mutex_lock(l_mutex);//lock again for next op
//         }
//
//         // Reads should fail
//         l_err = pnordd._readFlash(base_address,
//                                   l_size,
//                                   &l_readData);
//         if( !l_err )
//         {
//             TS_FAIL("SfcAST2400Test::test_FlashReads> Read did not fail in command mode");
//         }
//         else
//         {
//             delete l_err;
//         }
//
//         // Put controller back into read mode
//         l_err = sfc->commandMode( false );
//         mutex_unlock(l_mutex);
//         if( l_err )
//         {
//             TS_FAIL("SfcAST2400Test::test_FlashReads> Error exiting command mode");
//             errlCommit(l_err,PNOR_COMP_ID);
//         }
    }

};

#endif
