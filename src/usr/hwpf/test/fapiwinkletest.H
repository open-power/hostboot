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

            TS_TRACE( "fapiGetMvpdField: size or #R record = 0x%x",
                      l_pdRLen );

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
        uint32_t            l_ringId        =   0;
        uint32_t            l_chipletId     =   0;
        struct _testRRstr {
            uint32_t ringIdval;
            uint32_t chipletIdval;
            uint32_t size;
        }  l_ringModifiers[] = {
            { 0xe0, 0x8  , 0x20 },
            { 0xe1, 0x11 , 0x20 },
            { 0xe1, 0x12 , 0x20 },
            { 0xe1, 0x13 , 0x20 },
            { 0xe1, 0x14 , 0x20 },
            { 0xe1, 0x15 , 0x20 },
            { 0xe1, 0x18 , 0x20 },
            { 0xe2, 0x11 , 0x20 },
            { 0xe2, 0x12 , 0x20 },
            { 0xe2, 0x13 , 0x20 },
            { 0xe2, 0x14 , 0x20 },
            { 0xe2, 0x15 , 0x20 },
            { 0xe2, 0x18 , 0x20 },
            { 0xe3, 0x2  , 0x20 },
            { 0xe5, 0x2  , 0x20 },
            { 0xe6, 0x2  , 0x20 },
            { 0xe7, 0x9  , 0x20 },
            { 0xe8, 0x1  , 0x20 },
            { 0xe9, 0x1  , 0x20 },
            { 0xea, 0x1  , 0x20 },
            { 0xeb, 0x4  , 0x20 },
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
            l_ringId        =   0;
            l_chipletId     =   0;
            l_fapirc    =   getRepairRing(  l_fapi_cpu_target,
                                            l_chipletId,
                                            l_ringId,
                                            NULL,
                                            l_ringBufsize );
            TS_TRACE( "testRepairRings: ringId=0x%x, chipletId=0x%x: l_ringBufsize=0x%x",
                      l_ringId, l_chipletId, l_ringBufsize );
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
            TS_TRACE( "testRepairRings: pass in invalid ringId" );
            l_ringBufsize   =   0x100;
            l_ringId        =   0;     // ringId
            l_chipletId     =   0;     // chipletId
            l_fapirc    =   getRepairRing(  l_fapi_cpu_target,
                                            l_chipletId,
                                            l_ringId,
                                            l_pRingBuf,
                                            l_ringBufsize );
            TS_TRACE( "testRepairRings: ringId=0x%x, chipletId=0x%x: l_ringBufsize=0x%x",
                      l_ringId,
                      l_chipletId,
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
            //  Pass in 0 length with a valid ringId/chipletId, should return
            //  with correct length and no buffer.
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: get size of ring %d ", i );
            l_ringBufsize   =   0x0;
            l_ringId        =   l_ringModifiers[i].ringIdval;
            l_chipletId     =   l_ringModifiers[i].chipletIdval;
            l_fapirc        =   getRepairRing(  l_fapi_cpu_target,
                                                l_chipletId,
                                                l_ringId,
                                                l_pRingBuf,
                                                l_ringBufsize );
            TS_TRACE( "testRepairRings: ringId=0x%x, chipletId=0x%x: l_ringBufsize=0x%x",
                      l_ringId,
                      l_chipletId,
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
            l_ringId    =   l_ringModifiers[i].ringIdval;
            l_chipletId =   l_ringModifiers[i].chipletIdval;
            l_fapirc    =   getRepairRing(  l_fapi_cpu_target,
                                            l_chipletId,
                                            l_ringId,
                                            l_pRingBuf,
                                            l_ringBufsize );
            TS_TRACE( "testRepairRings: ringId=0x%x, chipletId=0x%x: l_ringBufsize=0x%x",
                      l_ringId, l_chipletId, l_ringBufsize );

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

};  // end class FapiWinkleTest

#endif
