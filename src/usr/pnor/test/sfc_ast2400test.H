/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/test/sfc_ast2400test.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
        SfcAST2400* sfc = reinterpret_cast<SfcAST2400*>(pnordd.iv_sfc );
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

        // Put controller into command mode (instead of read mode)
        l_err = sfc->commandMode( true );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_FlashReads> Error entering command mode");
            mutex_unlock(l_mutex);//unlock before commit
            errlCommit(l_err,PNOR_COMP_ID);
            mutex_lock(l_mutex);//lock again for next op
        }

        // Reads should fail
        l_err = pnordd._readFlash(base_address,
                                  l_size,
                                  &l_readData);
        if( !l_err )
        {
            TS_FAIL("SfcAST2400Test::test_FlashReads> Read did not fail in command mode");
        }
        else
        {
            delete l_err;
        }

        // Put controller back into read mode
        l_err = sfc->commandMode( false );
        mutex_unlock(l_mutex);
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_FlashReads> Error exiting command mode");
            errlCommit(l_err,PNOR_COMP_ID);
        }
    }

    /**
     * @brief Test SIO access
     *        Use a SIO scratch register to verify reads and writes
     */
    void test_SIO(void)
    {
        SfcAST2400* sfc = reinterpret_cast<SfcAST2400*>(
                            Singleton<PnorDD>::instance().iv_sfc );
        errlHndl_t l_err = NULL;

        // Read SIO to BMC scratch reg 1,2 and save off values
        uint8_t scratch1 = 0;
        l_err = sfc->readRegSIO( 0x21, scratch1 );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SIO> readRegSIO failed");
            errlCommit(l_err,PNOR_COMP_ID);
        }
        uint8_t scratch2 = 0;
        l_err = sfc->readRegSIO( 0x22, scratch2 );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SIO> readRegSIO failed");
            errlCommit(l_err,PNOR_COMP_ID);
        }

        // Write test patterns into registers
        uint8_t testdata = 0xA5;
        l_err = sfc->writeRegSIO( 0x21, testdata );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SIO> writeRegSIO failed");
            errlCommit(l_err,PNOR_COMP_ID);
        }
        testdata = 0x12;
        l_err = sfc->writeRegSIO( 0x22, testdata );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SIO> writeRegSIO failed");
            errlCommit(l_err,PNOR_COMP_ID);
        }

        // Read the data back and compare to expected results
        l_err = sfc->readRegSIO( 0x21, testdata );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SIO> readRegSIO failed");
            errlCommit(l_err,PNOR_COMP_ID);
        }
        if( testdata != 0xA5 )
        {
            TS_FAIL("SfcAST2400Test::test_SIO> Data mismatch on SIO 0x21 : Exp=0xA5, Act=%.2X", testdata);
        }
        l_err = sfc->readRegSIO( 0x22, testdata );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SIO> readRegSIO failed");
            errlCommit(l_err,PNOR_COMP_ID);
        }
        if( testdata != 0x12 )
        {
            TS_FAIL("SfcAST2400Test::test_SIO> Data mismatch on SIO 0x22 : Exp=0x12, Act=%.2X", testdata);
        }

        // Restore the original data
        l_err = sfc->writeRegSIO( 0x21, scratch1 );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SIO> writeRegSIO failed");
            errlCommit(l_err,PNOR_COMP_ID);
        }
        l_err = sfc->writeRegSIO( 0x22, scratch2 );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SIO> writeRegSIO failed");
            errlCommit(l_err,PNOR_COMP_ID);
        }
    }

    /**
     * @brief Test SPIC access
     *        Read and write data to the SPI Control register
     */
    void test_SPIC( void )
    {
        SfcAST2400* sfc = reinterpret_cast<SfcAST2400*>(
                            Singleton<PnorDD>::instance().iv_sfc );
        mutex_t* l_mutex = Singleton<PnorDD>::instance().iv_mutex_ptr;
        errlHndl_t l_err = NULL;

        mutex_lock(l_mutex);

        uint32_t first = 0;
        l_err = sfc->readRegSPIC( SfcAST2400::CTLREG_04, first );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SPIC> readRegSIO failed");
            mutex_unlock(l_mutex);//unlock before commit
            errlCommit(l_err,PNOR_COMP_ID);
            mutex_lock(l_mutex);//lock again for next op
        }
        uint32_t data1 = 0x12345678;
        l_err = sfc->writeRegSPIC( SfcAST2400::CTLREG_04, data1 );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SPIC> readRegSIO failed");
            mutex_unlock(l_mutex);//unlock before commit
            errlCommit(l_err,PNOR_COMP_ID);
            mutex_lock(l_mutex);//lock again for next op
        }
        l_err = sfc->readRegSPIC( SfcAST2400::CTLREG_04, data1 );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SPIC> readRegSIO failed");
            mutex_unlock(l_mutex);//unlock before commit
            errlCommit(l_err,PNOR_COMP_ID);
            mutex_lock(l_mutex);//lock again for next op
        }
        if( data1 != 0x12345678 )
        {
            TS_FAIL("SfcAST2400Test::test_SPIC> Unexpected result of %.8X (exp 0x12345678)",data1);
        }
        //put back the original
        l_err = sfc->writeRegSPIC( SfcAST2400::CTLREG_04, first );
        if( l_err )
        {
            TS_FAIL("SfcAST2400Test::test_SPIC> readRegSIO failed");
            mutex_unlock(l_mutex);//unlock before commit
            errlCommit(l_err,PNOR_COMP_ID);
        }

        mutex_unlock(l_mutex);
    }
};

#endif
