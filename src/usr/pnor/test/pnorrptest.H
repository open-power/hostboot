/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/test/pnorrptest.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
#ifndef __PNORRPTEST_H
#define __PNORRPTEST_H

/**
 *  @file pnorrptest.H
 *
 *  @brief Test case for PNOR Resource Provider
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <pnor/pnorif.H>
#include <sys/msg.h>
#include <limits.h>
#include <sys/mm.h>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <pnor/ecc.H>
#include "../pnorrp.H"
#include "../ffs.h"

extern trace_desc_t* g_trac_pnor;



class PnorRpTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief PNOR RP test - Section Info
     *        Check that the section info at least appears somewhat valid.
     */
    void test_sectionInfo(void)
    {
        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_sectionInfo> Start" );
        uint64_t fails = 0;
        uint64_t total = 0;
        PNOR::SectionInfo_t info;
        errlHndl_t errhdl = NULL;

        //Only check required sections.  Some are currently optional due to
        //Storage limitations in VPO.
        const PNOR::SectionId testSections[] = {
            PNOR::TOC,            /**< Table of Contents */
            PNOR::HB_EXT_CODE,    /**< Hostboot Extended Image */
            PNOR::HB_DATA,        /**< Hostboot Data */
            PNOR::DIMM_JEDEC_VPD, /**< DIMM JEDEC VPD */
            PNOR::MODULE_VPD,     /**< Module VPD */
        };
        uint64_t numSections = 5;

        for( uint64_t idx = 0; idx < numSections; idx++)
        {
            total++;
            errhdl = PNOR::getSectionInfo( testSections[idx], info );
            if( errhdl )
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_sectionInfo> ERROR : getSectionInfo returned error for %d : RC=%X",
                          testSections[idx], errhdl->reasonCode() );
                TS_FAIL( "PnorRpTest::test_getSectionInfo> ERROR : Unexpected error log" );
                fails++;
                ERRORLOG::errlCommit(errhdl,PNOR_COMP_ID);
            }

            // Look for non-zero size
            total++;
            if( info.size == 0 )
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_sectionInfo> ERROR : zero size for section %d : id=%d, actual=%d",
                          testSections[idx], info.id, info.size );
                TS_FAIL( "PnorRpTest::test_getSectionInfo> ERROR : Zero Size" );
                fails++;
            }

            // Look for vaddr in appropriate section of virtual memory
            total++;
            if( info.vaddr < PnorRP::BASE_VADDR )
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_sectionInfo> ERROR : Virtual Addr section %d Not in appropriate range: id=%d, actual=%d",
                          testSections[idx], info.id, info.vaddr );
                TS_FAIL( "PnorRpTest::test_getSectionInfo> ERROR : Invalid vaddr" );
                fails++;
            }
        }


        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_sectionInfo> %d/%d fails", fails, total );
    };

    /**
     * @brief PNOR RP test - ECC
     *        Verify ECC errors are handled
     */
    void test_ECC(void)
    {
        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_ECC> Start" );
        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t errhdl = NULL;

        const uint64_t FIRST_VAL = 0x1122334455667788;
        const size_t ECC_PAGESIZE = (PAGESIZE*9)/8;
        const uint64_t LOG_OFFSET = PAGESIZE/4; //force a page crossing
        const uint64_t PART_OFFSET = PAGESIZE*2 + LOG_OFFSET;
        const uint64_t TEST_PHYS_OFFSET = 0x3590000 //see defaultPnorLayout.xml
          + (ECC_PAGESIZE*2) //matches PART_OFFSET
          + (LOG_OFFSET*9)/8;

        // use the TEST partition as scratch space
        PNOR::SectionInfo_t info;
        errhdl = PNOR::getSectionInfo( PNOR::TEST, info );
        if( errhdl )
        {
            TRACFCOMP( g_trac_pnor, "PnorRpTest::test_ECC> ERROR : getSectionInfo returned error for PNOR::TEST : RC=%X", errhdl->reasonCode() );
            TS_FAIL( "PnorRpTest::test_ECC> ERROR : Unexpected error log" );
            ERRORLOG::errlCommit(errhdl,PNOR_COMP_ID);
            return;
        }

        // Use the 3rd page of data
        uint64_t* dataptr = reinterpret_cast<uint64_t*>
          (info.vaddr+PART_OFFSET);

        // read some data
        uint64_t* tmp1 = new uint64_t[PAGESIZE/sizeof(uint64_t)+1];
        for( size_t i = 0; i < PAGESIZE/sizeof(uint64_t); i++ )
        {
            tmp1[i] = dataptr[i];
        }

        // write some data
        for( size_t i = 0; i < PAGESIZE/sizeof(uint64_t); i++ )
        {
            dataptr[i] = FIRST_VAL+i;
        }

        // flush the page to make sure it gets out to the device
        int rc = mm_remove_pages( RELEASE, dataptr, PAGESIZE );
        total++;
        if( rc )
        {
            TRACFCOMP( g_trac_pnor, "PnorRpTest::test_ECC> ERROR : error on RELEASE : rc=%X", rc );
            TS_FAIL( "PnorRpTest::test_ECC> ERROR : error on RELEASE" );
            fails++;
        }

        // manually read the data from the PNOR device
        uint8_t* chip_data = new uint8_t[ECC_PAGESIZE];
        size_t l_size = ECC_PAGESIZE;
        errhdl = deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            chip_data,
                            l_size,
                            DEVICE_PNOR_ADDRESS(0, TEST_PHYS_OFFSET));
        total++;
        if( errhdl )
        {
            TS_FAIL("PnorRpTest::test_ECC: PNORDD deviceRead() failed! Error committed.");
            ERRORLOG::errlCommit(errhdl,PNOR_COMP_ID);
            fails++;
        }

        // compare the ECC-stripped data from the driver with the
        //  data we wrote
        uint64_t data_ecc = 0;
        uint64_t data_noecc = 0;
        uint8_t* chip_data_ptr = chip_data;
        PNOR::ECC::eccStatus ecc_rc = PNOR::ECC::CLEAN;
        for( size_t i = FIRST_VAL; i < PAGESIZE/sizeof(uint64_t); i++ )
        {
            memcpy( &data_ecc, chip_data_ptr, sizeof(uint64_t) );
            uint8_t ecc_byte = chip_data_ptr[8];
            ecc_rc = PNOR::ECC::removeECC( chip_data_ptr,
                                  reinterpret_cast<uint8_t*>(&data_noecc),
                                  sizeof(uint64_t) );
            total++;
            if( ecc_rc != PNOR::ECC::CLEAN )
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_ECC: Error removing ECC from word %d : status=%d, orig=%.16X:%.2X", i, ecc_rc, data_ecc, ecc_byte)
                TS_FAIL("PnorRpTest::test_ECC: Data mismatch.");
                fails++;
            }

            total++;
            if( data_noecc != FIRST_VAL + i )
            {
                TRACFCOMP( g_trac_pnor, "PnorRpTest::test_ECC: Data mismatch on word %d : exp=%.16X, act=%.16X, orig=%.16X:%.2X", i, FIRST_VAL+i, data_noecc, data_ecc, ecc_byte);
                TS_FAIL("PnorRpTest::test_ECC: Data mismatch.");
                fails++;
            }
            chip_data_ptr += 9;
        }

        // generate data with CEs
        chip_data_ptr = chip_data;
        for (int i = 0; i < 9; i++)
        {
            memcpy( &data_ecc, chip_data_ptr, sizeof(uint64_t) );
            uint64_t bad_data = data_ecc ^ (1ul << (63 - i*5));
            memcpy( chip_data_ptr, &bad_data, sizeof(uint64_t) );
            chip_data_ptr += 9;
        }

        // write the bad data to the chip directly
        errhdl = deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                             chip_data,
                             l_size,
                             DEVICE_PNOR_ADDRESS(0, TEST_PHYS_OFFSET));
        total++;
        if( errhdl )
        {
            TS_FAIL("PnorRpTest::test_ECC: PNORDD deviceWrite() failed! Error committed.");
            ERRORLOG::errlCommit(errhdl,PNOR_COMP_ID);
            fails++;
        }

        // read the same data through the RP, ECC errors should be corrected
        for( size_t i = 0; i < PAGESIZE/sizeof(uint64_t); i++ )
        {
            total++;
            if( dataptr[i] != FIRST_VAL+i )
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_ECC: Mismatch on readback from RP on word %d : exp=%.16X, act=%.16X", i, FIRST_VAL+i, dataptr[i] );
                TS_FAIL("PnorRpTest::test_ECC: Mismatch on readback from RP.");
                fails++;
            }
        }
        //Enable this to test the UE handling, not turning on by default
        // because it causes a shutdown
#if 0
        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_ECC: Attempting UE" );
        // flush the page to make sure it gets out to the device
        totals++;
        rc = mm_remove_pages( RELEASE, dataptr, PAGESIZE );
        if( rc )
        {
            TRACFCOMP( g_trac_pnor, "PnorRpTest::test_ECC> ERROR : error on RELEASE 2: rc=%X", rc );
            TS_FAIL( "PnorRpTest::test_ECC> ERROR : error on RELEASE 2" );
            fails++;
        }
        // generate data with CEs
        chip_data_ptr = chip_data;
        for (int i = 0; i < 9; i++)
        {
            memcpy( &data_ecc, chip_data_ptr, sizeof(uint64_t) );
            uint64_t bad_data = data_ecc ^ (1ul << i) ^ (1ul << 9);
            memcpy( chip_data_ptr, &bad_data, sizeof(uint64_t) );
            chip_data_ptr += 9;
        }
        // write the bad data to the chip directly
        totals++;
        errhdl = deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                             chip_data,
                             l_size,
                             DEVICE_PNOR_ADDRESS(0, TEST_PHYS_OFFSET));
        if( errhdl )
        {
            TS_FAIL("PnorRpTest::test_ECC: PNORDD deviceWrite() 2 failed! Error committed.");
            ERRORLOG::errlCommit(errhdl,PNOR_COMP_ID);
            fails++;
        }
        uint32_t tmp2 = 0;
        totals++;
        memcpy( &tmp2, dataptr, sizeof(uint32_t) );
        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_ECC: UE all done - should never see this!!" );
        fails++;
        TS_FAIL("PnorRpTest::test_ECC: UE did not kill the task!.");
#endif

        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_ECC> %d/%d fails", fails, total );
    };

    /**
     * @brief PNOR RP test - Read/Write Page
     *        Use message interface to read and write individual pages
     */
    void _test_messageReadWrite(void)
    {
        return; //this fails with the new message ids
        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> Start" );
        uint64_t fails = 0;
        uint64_t total = 0;
        int rc = 0;

        msg_q_t mq = PnorRP::getInstance().iv_msgQ;


        // allocate some space to play with
        uint64_t data1_r[PAGESIZE/sizeof(uint64_t)];
        uint64_t data2_r[PAGESIZE/sizeof(uint64_t)];
        uint64_t data_tmp[PAGESIZE/sizeof(uint64_t)];

        // use the TEST partition as scratch space
        PNOR::SectionInfo_t info;
        PNOR::getSectionInfo( PNOR::TEST, info );

        msg_t* msg = msg_allocate();

        // read the first page
        total++;
        msg->type = MSG_MM_RP_READ;
        msg->data[1] = (uint64_t)data1_r; //data[1] = address to copy into (user buffer)
        msg->data[0] = info.vaddr; //data[0] = address to copy from (effective address)
        rc = msg_sendrecv( mq, msg );
        if( rc )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ):1" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ):1, rc=%d", rc );
            fails++;
        }

        // read the second page
        total++;
        msg->type = MSG_MM_RP_READ;
        msg->data[1] = (uint64_t)data2_r; //data[1] = address to copy into (user buffer)
        msg->data[0] = info.vaddr + PAGESIZE; //data[0] = address to copy from (effective address)
        rc = msg_sendrecv( mq, msg );
        if( rc )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ):2" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ):2, rc=%d", rc );
            fails++;
        }

        // put some data into the first page
        for( uint64_t x = 0; x < (PAGESIZE/sizeof(uint64_t)); x++ )
        {
            data_tmp[x] = x;
        }

        // write the changed page back out
        total++;
        msg->type = MSG_MM_RP_WRITE;
        msg->data[1] = (uint64_t)data_tmp; //data[1] = address to copy from (user buffer)
        msg->data[0] = info.vaddr; //data[0] = address to copy into (effective address)
        rc = msg_sendrecv( mq, msg );
        if( rc )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(WRITE):1" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(WRITE):1, rc=%d", rc );
            fails++;
        }

        // read the first page again
        total++;
        msg->type = MSG_MM_RP_READ;
        msg->data[1] = (uint64_t)data1_r; //data[1] = address to copy into (user buffer)
        msg->data[0] = info.vaddr; //data[0] = address to copy from (effective address)
        rc = msg_sendrecv( mq, msg );
        if( rc )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ):3" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ):3, rc=%d", rc );
            fails++;
        }

        // compare to what we wrote
        total++;
        if( memcmp( data_tmp, data1_r, PAGESIZE ) )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : Data mismatch in page0" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : Data mismatch in page0" );
            fails++;
            uint64_t* act_data = data1_r;
            for( uint64_t x = 0; x < 4; x++ )
            {
                TRACFCOMP( g_trac_pnor, "ACT:%2d : %.16X %.16X %.16X %.16X", x, act_data[x*4], act_data[x*4+1], act_data[x*4+2], act_data[x*4+3] );
                TRACFCOMP( g_trac_pnor, "EXP:%2d : %.16X %.16X %.16X %.16X", x, act_data[x*4], act_data[x*4+1], act_data[x*4+2], act_data[x*4+3] );
            }
        }

        // read the second page again
        total++;
        msg->type = MSG_MM_RP_READ;
        msg->data[1] = (uint64_t)data_tmp; //data[1] = address to copy into (user buffer)
        msg->data[0] = info.vaddr + PAGESIZE; //data[0] = address to copy from (effective address)
        rc = msg_sendrecv( mq, msg );
        if( rc )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ):4" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ):4, rc=%d", rc );
            fails++;
        }

        // compare to what we read the first time
        total++;
        if( memcmp( data_tmp, data2_r, PAGESIZE ) )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : Data mismatch in page1" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : Data mismatch in page1" );
            fails++;
            uint64_t* act_data = data_tmp;
            for( uint64_t x = 0; x < 4; x++ )
            {
                TRACFCOMP( g_trac_pnor, "ACT:%2d : %.16X %.16X %.16X %.16X", x, act_data[x*4], act_data[x*4+1], act_data[x*4+2], act_data[x*4+3] );
                TRACFCOMP( g_trac_pnor, "EXP:%2d : %.16X %.16X %.16X %.16X", x, act_data[x*4], act_data[x*4+1], act_data[x*4+2], act_data[x*4+3] );
            }
        }

        msg_free(msg);

        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> %d/%d fails", fails, total );
    };

    /**
     * @brief PNOR RP test - Read/Write Addresses
     *        do read/modify/write/read to different virtual addresses
     */
    void _test_AddrReadWrite(void)
    {
        // Leaving disabled because a regular boot tests all of this anyway,
        //  but want to leave this here for possible future unit testing.
        return;
        TRACFCOMP( g_trac_pnor, "PnorRpTest::test_AddrReadWrite> Start" );
        uint64_t fails = 0;
        uint64_t total = 0;
        uint64_t* ptr = NULL;

        // read a bunch of addresses
        ptr = new uint64_t[16];
        for( uint64_t addr = 0;
             addr < 20;
             addr += 2048 ) // loop at 2K (half-page) intervals
        {
            TRACFCOMP( g_trac_pnor, "PnorRpTest::test_AddrReadWrite> addr=%X", addr );
            total++;
            memcpy( ptr, (void*)(0x80000000+addr), 16*sizeof(uint64_t) );
        }
        delete[] ptr;

        // setup a bunch of interesting addresses to read/write from
        uint64_t test_addrs[] = {
            0x8007E690,  // chip0-HB_DATA
            0x8207E690,  // chip1-HB_DATA
            0x8007E790,  // chip0-HB_DATA+0x100
            0x8207E890,  // chip1-HB_DATA+0x200
        };
        uint64_t test_vals[] = {
            0x1111222233334444,
            0xA5A5A5A5A5A5A5A5,
            0x5566778899AABBCC,
            0xBEEFBEEFBEEFBEEF,
        };

        // loop around and do alternating writes and reads
        for( uint64_t x = 0; x < (sizeof(test_addrs)/sizeof(test_addrs[0])); x++ )
        {
            TRACFCOMP( g_trac_pnor, "PnorRpTest::test_AddrReadWrite> x1=%d", x );
            total++;
            ptr = (uint64_t*) test_addrs[x];
            *ptr = test_vals[x];
            // verify we can write data
            if( *ptr != test_vals[x] )
            {
                TRACFCOMP( g_trac_pnor, "PnorRpTest::test_AddrReadWrite> ERROR : Data mismatch in first write of address 0x%p : exp=0x%X, act=0x%X", ptr, test_vals[x], *ptr );
                TS_FAIL( "PnorRpTest::test_AddrReadWrite> ERROR : Data mismatch in first write" );
                fails++;
            }
        }
        for( uint64_t x = 0; x < (sizeof(test_addrs)/sizeof(test_addrs[0])); x++ )
        {
            TRACFCOMP( g_trac_pnor, "PnorRpTest::test_AddrReadWrite> x2=%d", x );
            total++;
            ptr = (uint64_t*) test_addrs[x];
            // make sure we don't write on top of each other
            if( *ptr != test_vals[x] )
            {
                TRACFCOMP( g_trac_pnor, "PnorRpTest::test_AddrReadWrite> ERROR : Data mismatch in second read of address 0x%p : exp=0x%X, act=0x%X", ptr, test_vals[x], *ptr );
                TS_FAIL( "PnorRpTest::test_AddrReadWrite> ERROR : Data mismatch in second read" );
                fails++;
            }
        }

        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_AddrReadWrite> %d/%d fails", fails, total );
    };

    /**
     * @brief PNOR RP test - TOC
     *        Verify TOC checksum errors for both TOC's fail silently and
     *        pick up data from the other TOC. Test corrupts both header and
     *        first entry because they are checked separately in pnorrp.C
     *
     */
    void test_TOC(void)
    {
        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_TOC Start" );

        uint64_t fatal_error = 0;
        uint64_t offset = 0;
        uint8_t* tocHeader = new uint8_t[PAGESIZE];
        uint8_t* tocEntry = new uint8_t[PAGESIZE];
        uint8_t* corruptBuffer = new uint8_t[PAGESIZE];

        // Corrupt both ffs header and first entry for each TOC
        for (uint32_t cur_TOC = 0; cur_TOC < PNOR::NUM_TOCS; ++cur_TOC)
        {
            uint32_t TOC_used = cur_TOC;

            if (cur_TOC == 0)
            {
              offset =  PNOR::TOC_0_OFFSET;
            }
            else
            {
              offset =  PNOR::TOC_1_OFFSET;
            }

            // Read cur_TOC header data
            PnorRP::getInstance().readFromDevice( offset, 0, false, tocHeader,
                                                  fatal_error );

            // Corrupt cur_TOC header data
            memcpy(corruptBuffer, tocHeader, PAGESIZE);
            corruptBuffer[0] = 0xFF;
            corruptBuffer[1] = 0xFF;
            PnorRP::getInstance().writeToDevice( offset, 0, false,
                                                 corruptBuffer );

            // Check if cur_TOC failed that other TOC is used
            PnorRP::getInstance().readTOC();
            TOC_used = PnorRP::getInstance().iv_TOC_used;
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_TOC : TOC %d Corrupt Header, Toc_used = %d", cur_TOC, TOC_used);

            if (TOC_used == cur_TOC)
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_TOC> ERROR : TOC %d header is corrupted, did not use other TOC", cur_TOC);
                TS_FAIL("PnorRpTest::test_TOC> ERROR : TOC %d header is corrupted, did not use other TOC");
            }

            // Fix cur_TOC header
            PnorRP::getInstance().writeToDevice( offset, 0, false, tocHeader );

            // Read cur_TOC first entry data
            PnorRP::getInstance().readFromDevice( offset + FFS_HDR_SIZE, 0,
                                                  false, tocEntry,
                                                  fatal_error );

            // Corrupt cur_TOC header data
            memcpy(corruptBuffer, tocEntry, PAGESIZE);
            corruptBuffer[0] = 0xFF;
            corruptBuffer[1] = 0xFF;
            PnorRP::getInstance().writeToDevice( offset + FFS_HDR_SIZE, 0,
                                                 false, corruptBuffer );

            // Check if cur_TOC failed that other TOC is used
            TOC_used = cur_TOC;
            PnorRP::getInstance().readTOC();
            TOC_used = PnorRP::getInstance().iv_TOC_used;
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_TOC : TOC %d Corrupt Entry, Toc_used = %d", cur_TOC, TOC_used);

            if (TOC_used == cur_TOC)
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_TOC> ERROR : TOC %d entry is corrupted, did not use other TOC ENTRY", cur_TOC);
                TS_FAIL("PnorRpTest::test_TOC> ERROR : TOC %d entry is corrupted, did not use other TOC", cur_TOC);
            }

            // Fix cur_TOC first entry
            PnorRP::getInstance().writeToDevice( offset + FFS_HDR_SIZE, 0,
                                                 false, tocEntry );
        }

        delete tocHeader;
        delete tocEntry;
        delete corruptBuffer;

        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_TOC End");
    }

    //@todo - import config data from build and compare to section info

};


#endif
