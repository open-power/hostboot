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
#include <errl/errltypes.H>
#include <pnor/pnorif.H>
#include <sys/rp.h>
#include <sys/msg.h>
#include <limits.h>
#include "../pnorrp.H"

extern trace_desc_t* g_trac_pnor;


class PnorRpTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief PNOR RP test - Section Info
     *        Look for mismatches in section information from expected
     */
    void test_getSectionInfo(void)
    {
        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_getSectionInfo> Start" );
        uint64_t fails = 0;
        uint64_t total = 0;
        PNOR::SectionInfo_t info;
        errlHndl_t errhdl = NULL;

        struct ExpVals_t {
            uint64_t size;
            uint64_t vaddr;
        };
        const ExpVals_t exp_data[] = {
            /* TOC */ { 0x690, 0x80000000 },
            /* GLOBAL_DATA */ { PAGESIZE, 0x8007D690 },
            /* SBE_IPL */ { 0, 0 },
            /* HB_BASE_CODE */ { 0, 0 },
            /* HB_DATA */ { 2*PAGESIZE, 0x8007E690 },
            /* HB_ERRLOGS */ { 0, 0 },
            /* HB_EXT_CODE */ { 0x7D000, 0x80000690 },
            /* HB_RUNTIME */ { 0, 0 }, 
            /* PAYLOAD */ { 0, 0 },
            /* PFW_LITE_CODE */ { 0, 0 },
            /* OCC_CODE */ { 0, 0 },
            /* KVM_PART_INFO */ { 0, 0 },
            /* CODE_UPDATE */ { 0, 0 },
        };

        for( PNOR::SectionId id = PNOR::FIRST_SECTION;
             id < PNOR::NUM_SECTIONS;
             id = (PNOR::SectionId) (id + 1) )
        {
            total++;
            errhdl = PNOR::getSectionInfo( id, PNOR::SIDE_A, info );
            if( errhdl )
            {
                if( exp_data[id].size != 0 )
                {
                    TRACFCOMP(g_trac_pnor, "PnorRpTest::test_getSectionInfo> ERROR : getSectionInfo returned error for %d : RC=%X", id, errhdl->reasonCode() );
                    TS_FAIL( "PnorRpTest::test_getSectionInfo> ERROR : Unexpected error log" );
                    fails++;
                    errlCommit(errhdl);
                }
                else
                {
                    delete errhdl;
                }
            }

            // Look for expected size
            total++;
            if( info.size != exp_data[id].size )
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_getSectionInfo> ERROR : Mismatched size for section %d : id=%d, exp=%d, actual=%d", id, info.id, exp_data[id].size, info.size );
                TS_FAIL( "PnorRpTest::test_getSectionInfo> ERROR : Mismatched Size" );
                fails++;
            }
           
            // Look for expected vaddr
            total++;
            if( info.vaddr != exp_data[id].vaddr )
            {
                TRACFCOMP(g_trac_pnor, "PnorRpTest::test_getSectionInfo> ERROR : Mismatched vaddr for section %d : id=%d, exp=%d, actual=%d", id, info.id, exp_data[id].vaddr, info.vaddr );
                TS_FAIL( "PnorRpTest::test_getSectionInfo> ERROR : Mismatched vaddr" );
                fails++;
            }
        }

        
        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_getSectionInfo> %d/%d fails", fails, total );
    };

    /**
     * @brief PNOR RP test - Read/Write Page
     *        Use message interface to read and write individual pages
     */
    void test_messageReadWrite(void)
    {
        TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> Start" );
        uint64_t fails = 0;
        uint64_t total = 0;
        int rc = 0;

        msg_q_t mq = PnorRP::getInstance().iv_msgQ;
        

        // allocate some space to play with
        uint64_t data1_r[PAGESIZE/sizeof(uint64_t)];
        uint64_t data2_r[PAGESIZE/sizeof(uint64_t)];
        uint64_t data_tmp[PAGESIZE/sizeof(uint64_t)];

        // use the HB_DATA as scratch space
        PNOR::SectionInfo_t info;
        PNOR::getSectionInfo( PNOR::HB_DATA, PNOR::SIDE_A, info );

        msg_t* msg = msg_allocate();

        // read the first page        
        total++;
        msg->type = RP::READ_PAGE;
        msg->data[0] = (uint64_t)data1_r; //data[0] = address to copy into (user buffer)
        msg->data[1] = info.vaddr; //data[1] = address to copy from (effective address)
        rc = msg_sendrecv( mq, msg );
        if( rc )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ_PAGE):1" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ_PAGE):1, rc=%d", rc );
            fails++;            
        }

        // read the second page
        total++;
        msg->type = RP::READ_PAGE;
        msg->data[0] = (uint64_t)data2_r; //data[0] = address to copy into (user buffer)
        msg->data[1] = info.vaddr + PAGESIZE; //data[1] = address to copy from (effective address)
        rc = msg_sendrecv( mq, msg );
        if( rc )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ_PAGE):2" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ_PAGE):2, rc=%d", rc );
            fails++;            
        }

        // put some data into the first page
        for( uint64_t x = 0; x < (PAGESIZE/sizeof(uint64_t)); x++ )
        {
            data_tmp[x] = x;
        }

        // write the changed page back out
        total++;
        msg->type = RP::WRITE_PAGE;
        msg->data[0] = (uint64_t)data_tmp; //data[0] = address to copy from (user buffer)
        msg->data[1] = info.vaddr; //data[1] = address to copy into (effective address)
        rc = msg_sendrecv( mq, msg );
        if( rc )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(WRITE_PAGE):1" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(WRITE_PAGE):1, rc=%d", rc );
            fails++;            
        }

        // read the first page again
        total++;
        msg->type = RP::READ_PAGE;
        msg->data[0] = (uint64_t)data1_r; //data[0] = address to copy into (user buffer)
        msg->data[1] = info.vaddr; //data[1] = address to copy from (effective address)
        rc = msg_sendrecv( mq, msg );
        if( rc )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ_PAGE):3" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ_PAGE):3, rc=%d", rc );
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
        msg->type = RP::READ_PAGE;
        msg->data[0] = (uint64_t)data_tmp; //data[0] = address to copy into (user buffer)
        msg->data[1] = info.vaddr + PAGESIZE; //data[1] = address to copy from (effective address)
        rc = msg_sendrecv( mq, msg );
        if( rc )
        {
            TRACFCOMP(g_trac_pnor, "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ_PAGE):4" );
            TS_FAIL( "PnorRpTest::test_messageReadWrite> ERROR : error from msg_sendrecv(READ_PAGE):4, rc=%d", rc );
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
    void test_AddrReadWrite(void)
    {
        return; //@todo - enable this after Task 3445 
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

    //@todo - import config data from build and compare to section info


};     


#endif
