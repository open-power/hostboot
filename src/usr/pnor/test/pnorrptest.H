/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/test/pnorrptest.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#include <sys/task.h>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <pnor/ecc.H>
#include "../pnorrp.H"
#include "../pnor_common.H"
#include "../ffs.h"
#include <vmmconst.h>

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

        //Only check required sections.
        const PNOR::SectionId testSections[] = {
            PNOR::TOC,            /**< Table of Contents */
            PNOR::HB_EXT_CODE,    /**< Hostboot Extended Image */
            PNOR::HB_DATA,        /**< Hostboot Data */
            // Intentionally leaving HB_DATA_RW out of the tests
            // since its conditionally produced
            // PNOR::HB_DATA_RW,     /**< Hostboot Data RW */
            PNOR::MODULE_VPD,     /**< Module VPD */
            PNOR::RINGOVD,        /**< Ring override data */
            PNOR::WOFDATA,        /**< WOF data */
        };
        uint64_t numSections = sizeof(testSections)/sizeof(testSections[0]);

        for( uint64_t idx = 0; idx < numSections; idx++)
        {
            // RINGOVD is not supported when secureboot is enabled, but rather
            // than looking for the expected fail like non-test code does, just
            // skip testing RINGOVD in this scenario
            if ( ( testSections[idx] == PNOR::RINGOVD ) &&
                 ( SECUREBOOT::enabled() ) )
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_sectionInfo> Skipping RINGOVD since Security is enabled");
                continue;
            }

            if(( testSections[idx] == PNOR::DIMM_JEDEC_VPD ||
                 testSections[idx] == PNOR::MODULE_VPD) &&
               ( TARGETING::MODEL_AXONE ==
                 TARGETING::targetService().getProcessorModel() ))
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_sectionInfo> "
                          "Skipping non-existent MODULE_VPD and DIMM_JEDEC_VPD section for Axone");
                continue;
            }

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

        // PNOR device addresses start at non-secure PNOR virtual address
        // of 2GB, so subtract that virtual address offset out to get to the
        // PNOR device address of the TEST partition
        const uint64_t TEST_PHYS_OFFSET = (info.vaddr - VMM_VADDR_PNOR_RP)
          + (ECC_PAGESIZE*2) //matches PART_OFFSET
          + (LOG_OFFSET*9)/8;

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
    //TODO RTC:146146 Re-enable test_TOC testcase in pnorrptest.H
    void _test_TOC(void)
    {
        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_TOC Start" );

        uint64_t fatal_error = 0;
        uint64_t offset = 0;
        uint8_t* tocHeader = new uint8_t[PAGESIZE];
        uint8_t* tocEntry = new uint8_t[PAGESIZE];
        uint8_t* corruptBuffer = new uint8_t[PAGESIZE];

        // Corrupt both ffs header and first entry for each TOC
        for (PNOR::TOCS cur_TOC = PNOR::TOC_0; cur_TOC < PNOR::NUM_TOCS;
             cur_TOC = (PNOR::TOCS)(cur_TOC+1))
        {
            PNOR::TOCS TOC_used = cur_TOC;

            if (cur_TOC == 0)
            {
              offset =  PnorRP::getInstance().getTocOffset(PNOR::TOC_0);
            }
            else
            {
              offset =  PnorRP::getInstance().getTocOffset(PNOR::TOC_1);
            }

            // Read cur_TOC header data
            PnorRP::getInstance().readFromDevice( offset, 0, false,
                                                  tocHeader, fatal_error );
            if (fatal_error)
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_TOC> ERROR : Could not read TOC header data at offset 0x%X RC=%X",
                          offset, fatal_error);
                TS_FAIL("PnorRpTest::test_TOC> ERROR : Could not read TOC header data at offset 0x%X RC=%X",
                          offset, fatal_error);
            }

            // Corrupt cur_TOC header data
            memcpy(corruptBuffer, tocHeader, PAGESIZE);
            corruptBuffer[0] = 0xFF;
            corruptBuffer[1] = 0xFF;
            PnorRP::getInstance().writeToDevice( offset, 0, false,
                                                 corruptBuffer );

            size_t tocSize = PAGESIZE;
            // Check if cur_TOC failed that other TOC is used
            PnorRP::getInstance().readTOC(tocSize);
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
            if (fatal_error)
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_TOC> ERROR : Could not read first TOC entry data at offset 0x%X RC=%X",
                          offset, fatal_error);
                TS_FAIL("PnorRpTest::test_TOC> ERROR : Could not read first TOC entry data at offset 0x%X RC=%X",
                          offset, fatal_error);
            }

            // Corrupt cur_TOC header data
            memcpy(corruptBuffer, tocEntry, PAGESIZE);
            corruptBuffer[0] = 0xFF;
            corruptBuffer[1] = 0xFF;
            PnorRP::getInstance().writeToDevice( offset + FFS_HDR_SIZE, 0,
                                                 false, corruptBuffer );

            // Check if cur_TOC failed that other TOC is used
            TOC_used = cur_TOC;
            PnorRP::getInstance().readTOC(tocSize);
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
            //Read the corrected entry into iv_TOC
            PnorRP::getInstance().readTOC(tocSize);

        }

        delete tocHeader;
        delete tocEntry;
        delete corruptBuffer;

        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_TOC End");
    }

    /**
     * @brief PNOR RP test - read_ReadOnly_partition
     *        Tests if we can read a readOnly partition
     *
     */
    void test_read_ReadOnly_partition(void)
    {
        TRACFCOMP(g_trac_pnor,"PnorRpTest::test_read_ReadOnly_partition Start");

        int l_status = TASK_STATUS_EXITED_CLEAN;
        PNOR::SectionId l_testroSecId = PNOR::TESTRO;
        tid_t l_childTask =
                         task_create(readFromReadOnlyPartition, &l_testroSecId);

        if((l_childTask != task_wait_tid(l_childTask, &l_status, nullptr)) ||
           (l_status != TASK_STATUS_EXITED_CLEAN))
        {
            TS_FAIL("Could not read from readOnly partition.");
        }
        TRACFCOMP(g_trac_pnor,"PnorRpTest::test_read_ReadOnly_partition End");
    }

    /**
     * @brief PNOR RP test - write_ReadOnly_partition
     *        Tests if we can write to a readOnly partition (fail expected)
     *
     */
    void test_write_ReadOnly_partition(void)
    {
        TRACFCOMP(g_trac_pnor,
                             "PnorRpTest::test_write_ReadOnly_partition Start");

        int l_status = TASK_STATUS_EXITED_CLEAN;
        PNOR::SectionId l_testroSecId = PNOR::TESTRO;

        printk("Test case: Expect to see uncaught exception! ");
        tid_t l_childTask =
                          task_create(writeToReadOnlyPartition, &l_testroSecId);

        if((l_childTask != task_wait_tid(l_childTask, &l_status, nullptr)) ||
           (l_status != TASK_STATUS_CRASHED))
        {
            TS_FAIL("Write to readOnly partition exception not caught.");
        }

        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_write_ReadOnly_partition End");
    }

    //@todo - import config data from build and compare to section info

    /**
     * @brief PNOR RP test - fixECC
     *        Verify that we can detect and correct ECC for a
     *        given section of PNOR
     */
    void test_fixECC(void)
    {
        errlHndl_t l_err     = NULL;
        size_t l_size        = PNOR::PAGESIZE_PLUS_ECC;
        uint8_t* l_chip_data = new uint8_t[l_size];
        uint8_t* l_goodData  = new uint8_t [l_size];
        uint8_t* l_readData  = new uint8_t [l_size];
        do {
            TRACFCOMP(g_trac_pnor, ENTER_MRK"test_fixECC...");

            //write ecc good data
            TRACFCOMP(g_trac_pnor,"test_fixECC: write ecc good data to pnor");
            l_err  = PnorRP::getInstance().clearSection(PNOR::TEST);
            if (l_err)
            {
                TS_FAIL("PnorRpTest::test_fixECC: clearSection failed");
                ERRORLOG::errlCommit(l_err,PNOR_COMP_ID);
                break;
            }

            //getSectionInfo
            PNOR::SectionInfo_t l_info;
            l_err = PNOR::getSectionInfo(PNOR::TEST, l_info);
            if (l_err)
            {
                TS_FAIL("PnorRpTest::test_fixECC: getSectionInfo errored");
                ERRORLOG::errlCommit(l_err,PNOR_COMP_ID);
                break;
            }

            // manually read the data from the PNOR device
            const uint64_t l_flashAddr = l_info.flashAddr + l_size;

            l_err = deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            l_chip_data,
                            l_size,
                            DEVICE_PNOR_ADDRESS(0, l_flashAddr));
            if(l_err)
            {
                TS_FAIL("PnorRpTest::test_fixECC: PNORDD"
                    " deviceRead() failed! Error committed.");
                ERRORLOG::errlCommit(l_err,PNOR_COMP_ID);
                break;
            }

            //save a copy of the good data
            TRACFCOMP(g_trac_pnor, "test_fixECC: making a copy of good data");
            memcpy(l_goodData, l_chip_data,l_size);

            // generate data with CEs
            uint64_t l_data_ecc = 0;
            uint8_t* l_chip_data_ptr = l_chip_data;
            for (int i = 0; i < 9; i++)
            {
                memcpy( &l_data_ecc, l_chip_data_ptr, sizeof(uint64_t) );
                uint64_t l_bad_data = l_data_ecc ^ (1ul << (63 - i*5));
                memcpy( l_chip_data_ptr, &l_bad_data, sizeof(uint64_t) );
                l_chip_data_ptr += 9;
            }

            // write the bad data to the chip directly
            l_err = deviceWrite(
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        l_chip_data,l_size,
                        DEVICE_PNOR_ADDRESS(0, l_flashAddr));
            if(l_err)
            {
                TS_FAIL("PnorRpTest::test_fixECC: PNORDD"
                    " deviceWrite() failed! Error committed.");
                ERRORLOG::errlCommit(l_err,PNOR_COMP_ID);
                break;
            }

            //fixECC of the section
            l_err = PNOR::fixECC(PNOR::TEST);
            if (l_err)
            {
                TS_FAIL("PnorRpTest::test_fixECC fixECC errored");
                ERRORLOG::errlCommit(l_err,PNOR_COMP_ID);
                break;
            }

            //call deviceRead to make sure ecc is corrected
            l_err = deviceRead(
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        l_readData,l_size,
                        DEVICE_PNOR_ADDRESS(0, l_flashAddr));
            if(l_err)
            {
                TS_FAIL("PnorRpTest::test_fixECC: PNORDD"
                    " deviceRead() failed! Error committed.");
                ERRORLOG::errlCommit(l_err,PNOR_COMP_ID);
                break;
            }

            //compare l_readData
            if (0 != memcmp(l_readData, l_goodData, l_size))
            {
                TS_FAIL("PnorRpTest::test_fixECC: fixECC didn't correct CE");
                break;
            }

            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_fixECC finished");
        } while (0);

        delete [] l_chip_data;
        delete [] l_goodData;
        delete [] l_readData;
    };

    /**
     *  @brief Tests loading and unloading a secure section
     */
    void test_loadUnloadSecureSection()
    {
#ifdef CONFIG_SECUREBOOT
        errlHndl_t pError=NULL;
        do {

        if (!PNOR::isEnforcedSecureSection(PNOR::TESTLOAD))
        {
            break;
        }

        pError = PNOR::loadSecureSection(PNOR::TESTLOAD);
        if(pError != NULL)
        {
            TS_FAIL("PnorRpTest::test_loadUnloadSecureSection: "
                "loadSecureSection returned an error");
            ERRORLOG::errlCommit(pError,PNOR_COMP_ID);
            break;
        }

        pError = PNOR::unloadSecureSection(PNOR::TESTLOAD);
        if(pError != NULL)
        {
            TS_FAIL("PnorRpTest::test_loadUnloadSecureSection: "
                "unloadSecureSection returned an error");
            ERRORLOG::errlCommit(pError,PNOR_COMP_ID);
            break;
        }

        // try loading the TESTLOAD section a few times
        for (int i=0; i<10; i++)
        {
            pError = PNOR::loadSecureSection(PNOR::TESTLOAD);
            if(pError != nullptr)
            {
                TS_FAIL("PnorRpTest::test_loadUnloadSecureSection: "
                    "loadSecureSection returned an error on TESTLOAD section load attempt %i",i);
                break;
            }
        }
        if (pError != nullptr)
        {
            ERRORLOG::errlCommit(pError,PNOR_COMP_ID);
            break;
        }

        // try unloading TESTLOAD the exact same number of times we loaded it
        for (int i=0; i<10; i++)
        {
            pError = PNOR::unloadSecureSection(PNOR::TESTLOAD);
            if(pError != nullptr)
            {
                TS_FAIL("PnorRpTest::test_loadUnloadSecureSection: "
                    "loadSecureSection returned an error on TESTLOAD section unload attempt %i", i);
                break;
            }
        }
        if (pError != nullptr)
        {
            ERRORLOG::errlCommit(pError,PNOR_COMP_ID);
            break;
        }

        // Try to unload the secure section one extra time
        // We expect to see an error log
        pError = PNOR::unloadSecureSection(PNOR::TESTLOAD);
        if(pError == nullptr)
        {
            TS_FAIL("PnorRpTest::test_loadUnloadSecureSection: "
                "unloadSecureSection failed to return error on extra invoke");
            break;
        }
        else
        {
            if(pError->reasonCode() != PNOR::RC_EXTERNAL_ERROR ||
               pError->moduleId() != PNOR::MOD_PNORRP_LOADUNLOADSECURESECTION)
            {
                ERRORLOG::errlCommit(pError, PNOR_COMP_ID);
                TS_FAIL("PnorRpTest::test_loadUnloadSecureSection: "
                    "unloadSecureSection return an unexpected error");
                break;
            }
            else
            {
                // passed the test
                delete pError;
                pError = nullptr;
            }
        }

        } while (0);
#endif
    }

    private:
    static void* readFromReadOnlyPartition(void* i_section)
    {
        TRACFCOMP(g_trac_pnor, "readFromReadOnlyPartition Start");
        PNOR::SectionId* l_section =
                                reinterpret_cast<PNOR::SectionId*>(i_section);
        PNOR::SectionInfo_t l_info;
        errlHndl_t l_errhdl = nullptr;

        do {

        if(isEnforcedSecureSection(*l_section))
        {
            TS_FAIL("readFromReadOnlyPartition: section %d is secure."
                    " readFromReadOnlyPartition does not support testing"
                    " secure sections.", *l_section);
            break;
        }

        l_errhdl = PNOR::getSectionInfo(*l_section, l_info);
        if(l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, "readFromReadOnlyPartition: getSectionInfo "
                      " returned an error for section %d : RC = 0x%.04x",
                      *l_section, l_errhdl->reasonCode());
            ERRORLOG::errlCommit(l_errhdl, PNOR_COMP_ID);
            TS_FAIL("readFromReadOnlyPartition: failed to getSectionInfo"
                    " for section %d", *l_section);
            break;
        }

        uint64_t l_data = 0;
        memcpy(&l_data, (void*)l_info.vaddr, sizeof(l_data));
        // For this testing purpose, it doesn't actually matter what the data is
        } while(0);
        TRACFCOMP(g_trac_pnor, "readFromReadOnlyPartition End");
        return nullptr;
    }

    static void* writeToReadOnlyPartition(void* i_section)
    {
        TRACFCOMP(g_trac_pnor, "writeToReadOnlyPartition Start");
        PNOR::SectionId* l_section =
                                reinterpret_cast<PNOR::SectionId*>(i_section);
        PNOR::SectionInfo_t l_info;
        errlHndl_t l_errhdl = nullptr;

        do {

        if(isEnforcedSecureSection(*l_section))
        {
            TS_FAIL("writeToReadOnlyPartition: section %d is secure."
                    " writeToReadOnlyPartition does not support testing secure"
                    " sections.", *l_section);
            break;
        }

        l_errhdl = PNOR::getSectionInfo(*l_section, l_info);
        if(l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, "writeToReadOnlyPartition:"
                      " getSectionInfo returned"
                      " an error for section %d : RC=0x%.04x",
                      *l_section, l_errhdl->reasonCode());
            ERRORLOG::errlCommit(l_errhdl, PNOR_COMP_ID);
            TS_FAIL("writeToReadOnlyPartition: could not read pnor section %d",
                                                                    *l_section);
            break;
        }

        // Write some data; should cause a task crash
        const uint64_t l_writeData = 0x1122334455667788;
        uint64_t* l_dataptr = reinterpret_cast<uint64_t*> (l_info.vaddr);
        l_dataptr[0] = l_writeData;

        int rc = mm_remove_pages(RELEASE, l_dataptr, PAGESIZE);
        if(!rc)
        {
            TRACFCOMP(g_trac_pnor, "writeToReadOnlyPartition : uncaught "
                      "exception - write to a readOnly partition succeeded");
            TS_FAIL("writeToReadOnlyPartition : no error returned on writing to"
                    " a readOnly partition");
            break;
        }

        } while(0);
        TRACFCOMP(g_trac_pnor, "writeToReadOnlyPartition End");
        return nullptr;
    }
};


#endif
