/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/test/fapiwinkletest.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */

#ifndef __FAPIWINKLETEST_H
#define __FAPIWINKLETEST_H

/**
 *  @file fapiwinkletest.H
 *
 *  @brief Test cases for winkle HWP utilities.
*/

#include <cxxtest/TestSuite.H>

#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/fapi/fapiMvpdAccess.H>

#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

#include    <RepairRingFunc.H>

using namespace     fapi;
using   namespace   TARGETING;

class FapiWinkleTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief   call fapiGetMvpdField to fetch a #R record.
     *
     */
    void    testGetMvpdPdr()
    {
        fapi::ReturnCode    l_fapirc( fapi::FAPI_RC_SUCCESS );
        uint8_t             *l_pdRRecord            =   NULL;
        uint32_t            l_pdRLen                =   0;

        // test value, coreesponds to procmvpd.dat:e23067dae839f5b434ec12b5c86d2ae4fbb51259
        //  @todo change test when we get valid data in procpore.dat
        const   uint32_t    MVPD_PDR_TEST_SIZE      =   0x5f74;


        TS_TRACE( "testGetMvpdPdr entry" );

        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        // loop thru all the cpu's
        for ( uint8_t l_cpuNum=0; l_cpuNum < l_cpuTargetList.size(); l_cpuNum++ )
        {
            //  make a local copy of the CPU target
            TARGETING::Target*  l_cpu_target = l_cpuTargetList[l_cpuNum];

            //  dump physical path to target
            EntityPath l_path;
            l_path  =   l_cpu_target->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            // cast OUR type of target to a FAPI type of target.
            fapi::Target l_fapi_cpu_target(
                                          TARGET_TYPE_PROC_CHIP,
                                          reinterpret_cast<void *>
                                          (const_cast<TARGETING::Target*>(l_cpu_target)) );

            TS_TRACE( "call fapiGetMvpdField with NULL pointer" );

            //  call fapiGetMvpdField once with a NULL pointer to get the buffer size
            //  should return no error now.
            l_fapirc = fapiGetMvpdField(fapi::MVPD_RECORD_CP00,
                                        fapi::MVPD_KEYWORD_PDR,
                                        l_fapi_cpu_target,
                                        NULL,
                                        l_pdRLen );
            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                TS_FAIL( "fapiGetMvpdField:  expected FAPI_RC_SUCCESS" );
                fapiLogError(l_fapirc);
                return;
            }

            //  this will change when MVPD is changed, and will need to be changed
            //  above.
            if ( l_pdRLen   !=  MVPD_PDR_TEST_SIZE )
            {
                TS_FAIL( "fapiGetMvpdField: expected size = 0x%x, received 0x%x",
                         MVPD_PDR_TEST_SIZE,
                         l_pdRLen );
                fapiLogError(l_fapirc);
                return;
            }

            //  do a malloc instead of a new just for variety
            l_pdRRecord =   reinterpret_cast<uint8_t *>(malloc(l_pdRLen) );

            //  call fapiGetMvpdField once with a valid pointer
            l_fapirc = fapiGetMvpdField(fapi::MVPD_RECORD_CP00,
                                        fapi::MVPD_KEYWORD_PDR,
                                        l_fapi_cpu_target,
                                        l_pdRRecord,
                                        l_pdRLen );
            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                TS_FAIL( "fapiGetMvpdField:  expected FAPI_RC_SUCCESS" );
                fapiLogError(l_fapirc);
                free( l_pdRRecord );
                return;
            }


            //  clean up memory
            free( l_pdRRecord );
        }

        TS_TRACE( "testGetMvpdPdr exit" );
    }


    //  @note:
    //  ring modifiers are from  MVPD #R record, 2012-05-22.
    //  This will change and the unit test will need to be changed...

    /**
     * @brief Fetch Repair Rings
     */
    void testRepairRings()
    {
        fapi::ReturnCode    l_fapirc        =   fapi::FAPI_RC_SUCCESS;
        uint8_t             *l_pRingBuf     =   NULL;
        uint32_t            l_ringBufsize   =   0;
        uint32_t            l_ringModifier  =   0;
        struct _testRRstr {
            uint32_t val;
            uint32_t size;
        }  l_ringModifiers[] = {
            { 0x8036006, 0x20,  },
            { 0x11033006, 0x20, },
            { 0x12033006, 0x20, },
            { 0x13033006, 0x20, },
            { 0x14033006, 0x20, },
            { 0x15033006, 0x20, },
            { 0x18033006, 0x20, },
            { 0x19033006, 0x20, },
            { 0x1a033006, 0x20, },
            { 0x1b033006, 0x20, },
            { 0x1c033006, 0x20, },
            { 0x1d033006, 0x20, },
            { 0x1e033006, 0x20, },
            { 0x11034f86, 0x20, },
            { 0x12034f86, 0x20, },
            { 0x13034f86, 0x20, },
            { 0x14034f86, 0x20, },
            { 0x15034f86, 0x20, },
            { 0x18034f86, 0x20, },
            { 0x19034f86, 0x20, },
            { 0x1a034f86, 0x20, },
            { 0x1b034f86, 0x20, },
            { 0x1c034f86, 0x20, },
            { 0x1d034f86, 0x20, },
            { 0x1e034f86, 0x20, },
            { 0x2036e06,  0x20, },
            { 0x2031006,  0x20, },
            { 0x9037d06,  0x20, },
            { 0x1034806,  0x20, },
            { 0x3034806,  0x20, },
        };

        TS_TRACE( "testRepairRings entry" );

        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        // loop thru all the cpu's
        for ( uint8_t l_cpuNum=0; l_cpuNum < l_cpuTargetList.size(); l_cpuNum++ )
        {
            //  make a local copy of the CPU target
            TARGETING::Target*  l_cpu_target = l_cpuTargetList[l_cpuNum];

            TS_TRACE( "testRepairRings: cpuNum = 0x%x ", l_cpuNum );

            //  dump physical path to target
            EntityPath l_path;
            l_path  =   l_cpu_target->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            // cast OUR type of target to a FAPI type of target.
            fapi::Target l_fapi_cpu_target(
                                TARGET_TYPE_PROC_CHIP,
                                reinterpret_cast<void *>
                                (const_cast<TARGETING::Target*>(l_cpu_target)) );

            //  allocate some space to put the record(s)
            l_pRingBuf      =    new uint8_t[ 0x200];

            //  ----------------------------------------------------------------
            //  Pass in a NULL pointer for the ring buffer, should get an error.
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: pass in NULL ptr" );
            l_ringBufsize   =   0x0;
            l_ringModifier  =   0;
            l_fapirc    =   getRepairRing(  l_fapi_cpu_target,
                                            l_ringModifier,
                                            NULL,
                                            l_ringBufsize );
            TS_TRACE( "testRepairRings: ring modifier=0x%x: l_ringBufsize=0x%x",
                      l_ringModifier, l_ringBufsize );
            if ( l_fapirc != fapi::RC_REPAIR_RING_INVALID_RINGBUF_PTR )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: rc FAIL: 0x%x, 0x%x",
                         fapi::RC_REPAIR_RING_INVALID_RINGBUF_PTR,
                         static_cast<uint32_t>(l_fapirc) );
                fapiLogError(l_fapirc);
                return;
            }
            //  ----------------------------------------------------------------
            //  Pass in 0 for the ring modifier, should return with "not found"
            //  error
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: pass in invalid ringModifier" );
            l_ringBufsize   =   0x100;
            l_ringModifier  =   0;     // ringModifier picked at random
            l_fapirc    =   getRepairRing(  l_fapi_cpu_target,
                                            l_ringModifier,
                                            l_pRingBuf,
                                            l_ringBufsize );
            TS_TRACE( "testRepairRings: ring modifier=0x%x: l_ringBufsize=0x%x",
                      l_ringModifier,
                      l_ringBufsize );
            if ( l_fapirc != fapi::RC_REPAIR_RING_NOT_FOUND )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings:  rc FAIL: 0x%x, 0x%x",
                         fapi::RC_REPAIR_RING_NOT_FOUND,
                         static_cast<uint32_t>(l_fapirc) );
                fapiLogError(l_fapirc);
                return;
            }

            //  loop takes too long, test ring 5
            uint8_t i   =   5;
            //  ----------------------------------------------------------------
            //  Pass in 0 length with a valid ringModifier, should return with
            //  correct length and no buffer.
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: get size of ring %d ", i );
            l_ringBufsize   =   0x0;
            l_ringModifier  =   l_ringModifiers[i].val;
            l_fapirc    =   getRepairRing(  l_fapi_cpu_target,
                                            l_ringModifier,
                                            l_pRingBuf,
                                            l_ringBufsize );
            TS_TRACE( "testRepairRings: ring modifier=0x%x: l_ringBufsize=0x%x",
                      l_ringModifier,
                      l_ringBufsize );
            if ( l_fapirc != fapi::RC_REPAIR_RING_INVALID_SIZE )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: rc FAIL: 0x%x, 0x%x",
                         fapi::RC_REPAIR_RING_INVALID_SIZE,
                         static_cast<uint32_t>(l_fapirc));

                fapiLogError(l_fapirc);
                return;
            }
            if ( l_ringBufsize != l_ringModifiers[i].size )
            {
                TS_FAIL( "testRepairRings:  size FAIL: 0x%x, 0x%x",
                         l_ringModifiers[i].size,
                         l_ringBufsize  );
                return;
            }


            //  ----------------------------------------------------------------
            //  RingBufsize should now have the correct size, fetch ring 5.
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: get ring %d", i );

            // l_ringBufsize set from above...
            l_ringModifier  =   l_ringModifiers[i].val;
            l_fapirc    =   getRepairRing(  l_fapi_cpu_target,
                                            l_ringModifier,
                                            l_pRingBuf,
                                            l_ringBufsize );
            TS_TRACE( "testRepairRings: ring modifier=0x%x: l_ringBufsize=0x%x",
                      l_ringModifier, l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings:  rc FAIL: 0x%x, 0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
                fapiLogError(l_fapirc);
                return;
            }
            if ( l_ringBufsize != l_ringModifiers[i].size )
            {
                TS_FAIL( "testRepairRings:  size FAIL: 0x%x, 0x%x",
                         l_ringModifiers[i].size,
                         l_ringBufsize  );
                return;
            }

            // @todo dump ring buffer here.
            TRACDBIN( g_trac_test, "testRepairRings: Dump Repair Ring Buffer:",
                      l_pRingBuf,
                      l_ringBufsize );

            //  delete allocated space
            delete[]    l_pRingBuf;
        }

        TS_TRACE( "testRepairRings exit" );
    }

};

#endif
