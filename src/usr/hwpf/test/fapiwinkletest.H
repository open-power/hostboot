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

// set to 1 for doing unit tests, set to 0 for production
#define RTC51716 0
#define RTC39177 0
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

#include    <getMvpdRing.H>
#include    <setMvpdRing.H>

//      pull in CompressedScanData def from proc_slw_build HWP
#include <p8_scan_compression.H>

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
        
        TS_TRACE( "testGetMvpdPdr l_cpuTargetList.size()= 0x%x ",
                                      l_cpuTargetList.size() );


        // loop thru all the cpu's
        for (uint8_t l_cpuNum=0; l_cpuNum < l_cpuTargetList.size(); l_cpuNum++ )
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

            //  call fapiGetMvpdField once with a NULL pointer to get the 
            //  buffer size should return no error now.
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
        uint32_t            l_bufsize       =   0x200;
#if RTC51716  // TODO comment out until mvpd test data is fixed.  RTC 51716
        // This data needs to be in sync with the procmvpd.dat file
        // the setMvpdFunc tests use the last row, index = 3. The test
        //  expects it to be a mid x20 byte ring in the #G keyword
        struct _testRRstr {
            fapi::MvpdRecord record;
            fapi::MvpdKeyword keyword;
            uint32_t ringIdval;
            uint32_t chipletIdval;
            uint32_t size;
        }  l_ringModifiers[] = {
            { MVPD_RECORD_CP00, MVPD_KEYWORD_PDG,0xa4, 0xFF , 0x20 }, //last #G
            { MVPD_RECORD_CP00, MVPD_KEYWORD_PDR,0xe0, 0x8 , 0x20 },//first #R
            { MVPD_RECORD_CP00, MVPD_KEYWORD_PDR,0xe2, 0x16 ,0x138 },//big #R
            { MVPD_RECORD_CP00, MVPD_KEYWORD_PDG,0xa2, 0x8 , 0x20 }, //mid #G
        };
#endif // RTC 51716
        TS_TRACE( "testRepairRings entry" );

        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        // loop thru all the cpu's
        for (uint8_t l_cpuNum=0; l_cpuNum < l_cpuTargetList.size(); l_cpuNum++ )
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
            l_pRingBuf      =    new uint8_t[ l_bufsize];

            //  ----------------------------------------------------------------
            //  Pass in 0 for the ring modifier, should return with "not found"
            //  error
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: pass in invalid ringId" );
            l_ringBufsize   =   l_bufsize;
            l_ringId        =   0;     // ringId 
            l_chipletId     =   0;     // chipletId
            l_fapirc    =   getMvpdRing(  MVPD_RECORD_CP00,
                                          MVPD_KEYWORD_PDR,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );
            TS_TRACE("testRepairRings:ringId=0x%x chipletId=0x%x Bufsize=0x%x",
                      l_ringId,
                      l_chipletId,
                      l_ringBufsize );
            if ( l_fapirc != fapi::RC_REPAIR_RING_NOT_FOUND )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL("testRepairRings: expect not found rc FAIL: 0x%x, 0x%x",
                         fapi::RC_REPAIR_RING_NOT_FOUND,
                         static_cast<uint32_t>(l_fapirc) );
                fapiLogError(l_fapirc);
                return;
            }

#if RTC51716  // TODO comment out until mvpd test data is fixed.  RTC 51716
            uint8_t i   =   2;
            //  ----------------------------------------------------------------
            //  Pass in a buffer size that is too small with a valid 
            //  ringId/chipletId, should  return with correct length
            //  and invalid size return code.
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: pass buffer too small %d ", i );
            l_ringBufsize   =   0x0;
            l_ringId        =   l_ringModifiers[i].ringIdval;
            l_chipletId     =   l_ringModifiers[i].chipletIdval;
            l_fapirc    =   getMvpdRing(  MVPD_RECORD_CP00,
                                          MVPD_KEYWORD_PDR,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );
            TS_TRACE("testRepairRings:ringId=0x%x chipletId=0x%x: Bufsize=0x%x",
                      l_ringId,
                      l_chipletId,
                      l_ringBufsize );
            if ( l_fapirc != fapi::RC_REPAIR_RING_INVALID_SIZE )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL("testRepairRings: expect invalid size FAIL: 0x%x, 0x%x",
                         fapi::RC_REPAIR_RING_INVALID_SIZE,
                         static_cast<uint32_t>(l_fapirc));

                fapiLogError(l_fapirc);
                return;
            }
            if ( l_ringBufsize != l_ringModifiers[i].size )
            {
                TS_FAIL( "testRepairRings: size mismatch FAIL: 0x%x, 0x%x",
                         l_ringModifiers[i].size,
                         l_ringBufsize  );
                return;
            }
            //  ----------------------------------------------------------------
            //  Pass in a NULL pointer with a valid ringId/chipletId, should 
            //  return with correct length and successful return code.
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: get size of ring %d ", i );
            l_ringBufsize   =   0x0;
            l_ringId        =   l_ringModifiers[i].ringIdval;
            l_chipletId     =   l_ringModifiers[i].chipletIdval;
            l_fapirc    =   getMvpdRing(  MVPD_RECORD_CP00,
                                          MVPD_KEYWORD_PDR,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          NULL,
                                          l_ringBufsize );
            TS_TRACE("testRepairRings:ringId=0x%x chipletId=0x%x: Bufsize=0x%x",
                      l_ringId,
                      l_chipletId,
                      l_ringBufsize );
            if ( l_fapirc )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: expect success rc FAIL: 0x%x, 0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc));

                fapiLogError(l_fapirc);
                return;
            }
            if ( l_ringBufsize != l_ringModifiers[i].size )
            {
                TS_FAIL( "testRepairRings: size mismatch  FAIL: 0x%x, 0x%x",
                         l_ringModifiers[i].size,
                         l_ringBufsize  );
                return;
            }

            //  ----------------------------------------------------------------
            //  Fetch rings
            //  ----------------------------------------------------------------
            const uint32_t numRings = 
                        sizeof(l_ringModifiers)/sizeof(l_ringModifiers[0]);
            for (i=0;i<numRings;i++) {
                TS_TRACE( "testRepairRings: get ring %d", i );
                l_ringBufsize   =   l_bufsize;
                l_ringId    =   l_ringModifiers[i].ringIdval;
                l_chipletId =   l_ringModifiers[i].chipletIdval;
                l_fapirc    =   getMvpdRing(  l_ringModifiers[i].record,
                                          l_ringModifiers[i].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );
                TS_TRACE("testRepairRings ringId=0x%x chipletId=0x%x size=0x%x",
                      l_ringId, l_chipletId, l_ringBufsize );

                if ( l_fapirc )
                {
                    // note: uint32_t below is an _operator_ of fapi::ReturnCode
                    TS_FAIL( "testRepairRings: getMvpdRing rc FAIL: 0x%x, 0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
                    fapiLogError(l_fapirc);
                    return;
                }
                if ( l_ringBufsize != l_ringModifiers[i].size )
                {
                    TS_FAIL( "testRepairRings: size mismatch FAIL: 0x%x, 0x%x",
                         l_ringModifiers[i].size,
                         l_ringBufsize  );
                    return;
                }

                // Dump ring buffer here.
                TRACDBIN(g_trac_test,"testRepairRings:Dump Repair Ring Buffer:",
                      l_pRingBuf,
                      l_ringBufsize );
           }    
#endif // RTC 51716

#if RTC39177  // TODO comment out til mvpd dd supports write. RTC 39177 
            //  ----------------------------------------------------------------
            // update the data. 
            // TODO write different data, once the DD is written(story 39177)
            //     read it back to verify, then put the original data back.
            //     for now, there is a debug byte dump in mvpdRingFunc to 
            //     manually verify in unit test
            //  ----------------------------------------------------------------
            uint32_t  l_offset =0;       
            uint8_t   l_data = 0;
            uint8_t  *l_pData = NULL;

            i   =   3;  // use data from last fetch test case.
            TS_TRACE( "testRepairRings: update in place  ring %d", i );
            l_ringId    =   l_ringModifiers[i].ringIdval;
            l_chipletId =   l_ringModifiers[i].chipletIdval;
            l_ringBufsize = l_ringModifiers[i].size; 

            // put in recognizable data for the debug data dump 
            l_pData = l_pRingBuf+sizeof(CompressedScanData);
            for (l_offset = 0,l_data=0x10; l_offset < 
                 l_ringBufsize-sizeof(CompressedScanData); l_offset++) 
            {
               *l_pData++ = l_data++;
            }
            TRACDBIN( g_trac_test, "testRepairRings: updated ring data:",
                      l_pRingBuf,
                      l_ringBufsize );
            l_fapirc    =   setMvpdRing(  l_ringModifiers[i].record,
                                          l_ringModifiers[i].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: setMvpdRing rc FAIL: 0x%x, 0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
            
                fapiLogError(l_fapirc);
                return;
            }

            //  ----------------------------------------------------------------
            //  write back a smaller ring to cause a shift left in the record
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: shrink a  ring %d", i );
            l_ringBufsize = l_ringModifiers[i].size-4; 
            reinterpret_cast<CompressedScanData *>(l_pRingBuf)->
                                                   iv_size = l_ringBufsize;

            // put in recognizable data for the debug data dump 
            l_pData = l_pRingBuf+sizeof(CompressedScanData);
            for (l_offset = 0,l_data=0x20; l_offset <
                 l_ringBufsize-sizeof(CompressedScanData); l_offset++) 
            {
               *l_pData++ = l_data++;
            }
            TRACDBIN( g_trac_test, "testRepairRings: updated ring data:",
                      l_pRingBuf,
                      l_ringBufsize );
            l_fapirc    =   setMvpdRing(  l_ringModifiers[i].record,
                                          l_ringModifiers[i].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: setMvpdRing rc FAIL: 0x%x, 0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
            
                fapiLogError(l_fapirc);
                return;
            }

            //  ----------------------------------------------------------------
            //  write back a larger  ring to cause a shift right in the record
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: grow a ring %d", i );
            l_ringBufsize = l_ringModifiers[i].size+16; 
            reinterpret_cast<CompressedScanData *>(l_pRingBuf)->
                                                 iv_size = l_ringBufsize;

            // put in recognizable data for the debug data dump 
            l_pData = l_pRingBuf+sizeof(CompressedScanData);
            for (l_offset = 0,l_data=0x30; l_offset < 
                         l_ringBufsize-sizeof(CompressedScanData); l_offset++) 
            {
               *l_pData++ = l_data++;
            }
            TRACDBIN( g_trac_test, "testRepairRings: updated ring data:",
                      l_pRingBuf,
                      l_ringBufsize );
            l_fapirc    =   setMvpdRing(  l_ringModifiers[i].record,
                                          l_ringModifiers[i].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: setMvpdRing rc FAIL: 0x%x, 0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
            
                fapiLogError(l_fapirc);
                return;
            }

            //  ----------------------------------------------------------------
            //  append a ring that is not already there to the end
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: append a ring" );
            l_ringId    =   0x77;
            l_chipletId =   0x88;
            l_ringBufsize = l_ringModifiers[i].size; 
            reinterpret_cast<CompressedScanData *>(l_pRingBuf)->
                                                   iv_size = l_ringBufsize;
            reinterpret_cast<CompressedScanData *>(l_pRingBuf)->
                                                   iv_ringId = l_ringId;
            reinterpret_cast<CompressedScanData *>(l_pRingBuf)->
                                                   iv_chipletId = l_chipletId;

            // put in recognizable data for the debug data dump 
            l_pData = l_pRingBuf+sizeof(CompressedScanData);
            for (l_offset = 0,l_data=0x50; l_offset < 
                        l_ringBufsize-sizeof(CompressedScanData); l_offset++) 
            {
               *l_pData++ = l_data++;
            }
            TRACDBIN( g_trac_test, "testRepairRings: updated ring data:",
                      l_pRingBuf,
                      l_ringBufsize );
            l_fapirc    =   setMvpdRing(  l_ringModifiers[i].record,
                                          l_ringModifiers[i].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: setMvpdRing rc FAIL: 0x%x, 0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
            
                fapiLogError(l_fapirc);
                return;
            }

            //  ----------------------------------------------------------------
            //  Pass in a buffer size that does not match the exact size
            //  of the ringId/chipletId, should  return with correct length
            //  and invalid size return code.
            //  ----------------------------------------------------------------
            TS_TRACE("testRepairRing:bad size ring=0x%x chiplet=0x%x size=0x%x",
                      l_ringId,
                      l_chipletId,
                      l_ringBufsize );
            l_ringBufsize   =   l_bufsize;
            l_ringId        =   l_ringModifiers[i].ringIdval;
            l_chipletId     =   l_ringModifiers[i].chipletIdval;
            l_fapirc    =   setMvpdRing(  MVPD_RECORD_CP00,
                                          MVPD_KEYWORD_PDR,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::RC_MVPD_RING_FUNC_INVALID_PARAMETER )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL("testRepairRings:invalid ring size rc FAIL: 0x%x, 0x%x",
                         fapi::RC_REPAIR_RING_INVALID_SIZE,
                         static_cast<uint32_t>(l_fapirc));

                fapiLogError(l_fapirc);
                return;
            }
            //  ----------------------------------------------------------------
            //  Pass in 0 for the ring modifier, should return with "not found"
            //  error
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: pass in invalid ringId" );
            l_ringBufsize   =   l_ringModifiers[i].size;
            l_ringId        =   0;     // ringId 
            l_chipletId     =   0;     // chipletId
            l_fapirc    =   setMvpdRing(  MVPD_RECORD_CP00,
                                          MVPD_KEYWORD_PDR,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            TS_TRACE("testRepairRings:ringId=0x%x chipletId=0x%x size=0x%x",
                      l_ringId,
                      l_chipletId,
                      l_ringBufsize );
            if ( l_fapirc != fapi::RC_MVPD_RING_FUNC_INVALID_PARAMETER )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings:  rc FAIL: 0x%x, 0x%x",
                         fapi::RC_REPAIR_RING_NOT_FOUND,
                         static_cast<uint32_t>(l_fapirc) );
                fapiLogError(l_fapirc);
                return;
            }
            //  ----------------------------------------------------------------
            //  Pass in a NULL pointer with a valid ringId/chipletId, should 
            //  return with correct length and successful return code.
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: get size of ring(from set) %d ", i );
            l_ringBufsize   =   0x0;
            l_ringId        =   l_ringModifiers[i].ringIdval;
            l_chipletId     =   l_ringModifiers[i].chipletIdval;
            l_fapirc    =   setMvpdRing(  MVPD_RECORD_CP00,
                                          MVPD_KEYWORD_PDR,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          NULL,
                                          l_ringBufsize );

            TS_TRACE("testRepairRings:ringId=0x%x chipletId=0x%x size=0x%x",
                      l_ringId,
                      l_chipletId,
                      l_ringBufsize );
            if ( l_fapirc != fapi::RC_MVPD_RING_FUNC_INVALID_PARAMETER )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: setMvpdRing rc FAIL: 0x%x, 0x%x",
                         fapi::RC_MVPD_RING_FUNC_INVALID_PARAMETER,
                         static_cast<uint32_t>(l_fapirc));

                fapiLogError(l_fapirc);
                return;
            }
#endif // RTC 39177
            //  delete allocated space
            delete[]    l_pRingBuf;
        }

        TS_TRACE( "testRepairRings exit" );
    }

};  // end class FapiWinkleTest

#endif
