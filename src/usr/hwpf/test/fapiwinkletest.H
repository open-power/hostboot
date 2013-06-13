/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/fapiwinkletest.H $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef __FAPIWINKLETEST_H
#define __FAPIWINKLETEST_H

// set to 1 for doing unit tests, set to 0 for production
#define UNITTESTfwt 0
// TODO: RTC 69935 complete Phase Rotator Data and Termination Data.
// Use the code in the 1 path until CDIMM vpd has proper values.
// Then the 1 path code can be removed and keep the 0 path code.
#define RTC69935fwt 1
/**
 *  @file fapiwinkletest.H
 *
 *  @brief Test cases for winkle HWP utilities.
*/

#include <cxxtest/TestSuite.H>

#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

#include    <getMvpdRing.H>
#include    <setMvpdRing.H>
#include    <mvpd_accessors/getMBvpdPhaseRotatorData.H>
#include    <mvpd_accessors/getMBvpdAddrMirrorData.H>
#include    <mvpd_accessors/getMBvpdTermData.H>
#include    <mvpd_accessors/getMBvpdSlopeInterceptData.H>

#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <trace/interface.H>

//      pull in CompressedScanData def from proc_slw_build HWP
#include <p8_scan_compression.H>

using namespace     fapi;
using   namespace   TARGETING;

class FapiWinkleTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief   call fapiGetMvpdField to fetch a mvpd records.
     *
     */
    void    testGetMvpd()
    {
        fapi::ReturnCode    l_fapirc( fapi::FAPI_RC_SUCCESS );
        uint8_t             *l_pdRRecord            =   NULL;
        uint32_t            l_pdRLen                =   0;

        // list of MVPD records to test. Need to be in PNOR or procmvpd.dat
        // when g_usePNOR is false.
        struct _testMvpdRecords {
            fapi::MvpdRecord record;
            fapi::MvpdKeyword keyword;
        }  l_mvpdRecords[] = {
            { MVPD_RECORD_CP00, MVPD_KEYWORD_PDG},
            { MVPD_RECORD_MER0, MVPD_KEYWORD_PDI},
//          { MVPD_RECORD_VER0, MVPD_KEYWORD_PDI}, //VER0 in spec,not supported
            { MVPD_RECORD_VWML, MVPD_KEYWORD_PDI},
        };

        TS_TRACE( "testGetMvpd entry" );

        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);
        
        TS_TRACE( "testGetMvpd l_cpuTargetList.size()= 0x%x ",
                                      l_cpuTargetList.size() );


        // loop thru all the cpu's
        for (TargetHandleList::iterator l_cpu_iter = l_cpuTargetList.begin();
                l_cpu_iter != l_cpuTargetList.end();
                ++l_cpu_iter)
        {
            //  make a local copy of the CPU target
            TARGETING::Target* l_cpu_target = *l_cpu_iter;

            TS_TRACE( "target HUID %.8X", TARGETING::get_huid(l_cpu_target));

            // cast OUR type of target to a FAPI type of target.
            fapi::Target l_fapi_cpu_target(
                                          TARGET_TYPE_PROC_CHIP,
                   (const_cast<TARGETING::Target*>(l_cpu_target)) );

            // loop through mvpd records of interest
            const uint32_t numRecords =
                    sizeof(l_mvpdRecords)/sizeof(l_mvpdRecords[0]);
            for (uint8_t i=0;i<numRecords;i++) {

                TS_TRACE( "record = 0x%x keyword = 0x%x",
                   l_mvpdRecords[i].record,
                   l_mvpdRecords[i].keyword);

                TS_TRACE( "call fapiGetMvpdField with NULL pointer" );

                //  call fapiGetMvpdField once with a NULL pointer to get the 
                //  buffer size should return no error now.
                l_fapirc = fapiGetMvpdField(l_mvpdRecords[i].record,
                                        l_mvpdRecords[i].keyword,
                                        l_fapi_cpu_target,
                                        NULL,
                                        l_pdRLen );
                if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
                {
                    TS_FAIL( "fapiGetMvpdField:  expected FAPI_RC_SUCCESS" );
                    fapiLogError(l_fapirc);
                    return;
                }

                TS_TRACE( "fapiGetMvpdField: size of record = 0x%x",
                      l_pdRLen );

                //  do a malloc instead of a new just for variety
                l_pdRRecord =   reinterpret_cast<uint8_t *>(malloc(l_pdRLen) );

                //  call fapiGetMvpdField once with a valid pointer
                l_fapirc = fapiGetMvpdField(l_mvpdRecords[i].record,
                                        l_mvpdRecords[i].keyword,
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
        }

        TS_TRACE( "testGetMvpd exit" );
    }

    /**
     * @brief  call fapiGetMBvpdField to fetch memory buffer vpd records.
     *
     */
    void    testGetMBvpd()
    {
        fapi::ReturnCode    l_fapirc( fapi::FAPI_RC_SUCCESS );
        uint8_t             *l_pRecord            =   NULL;
        uint32_t            l_len                =   0;

        // list of MBVPD records to test
        struct _testMBvpdRecords {
            fapi::MBvpdRecord record;
            fapi::MBvpdKeyword keyword;
        }  l_mbvpdRecords[] = {
            { MBVPD_RECORD_VEIR, MBVPD_KEYWORD_PDI},
//          { MBVPD_RECORD_VER0, MBVPD_KEYWORD_PDI},//in spec, not supported
            { MBVPD_RECORD_MER0, MBVPD_KEYWORD_PDI},
            { MBVPD_RECORD_VSPD, MBVPD_KEYWORD_PDI},
            { MBVPD_RECORD_VSPD, MBVPD_KEYWORD_MT},
            { MBVPD_RECORD_VSPD, MBVPD_KEYWORD_MR},
            { MBVPD_RECORD_VSPD, MBVPD_KEYWORD_PDA},
            { MBVPD_RECORD_VSPD, MBVPD_KEYWORD_EL},
            { MBVPD_RECORD_VSPD, MBVPD_KEYWORD_LM},
            { MBVPD_RECORD_VSPD, MBVPD_KEYWORD_MW},
            { MBVPD_RECORD_VSPD, MBVPD_KEYWORD_MV},
            { MBVPD_RECORD_VSPD, MBVPD_KEYWORD_AM},
        };

        TS_TRACE( "testGetMBvpd entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetMBvpd l_memBufList.size()= 0x%x ",
                                      l_memBufList.size() );

        // loop thru all the memory buffers
        for (uint8_t l_mbNum=0; l_mbNum < l_memBufList.size(); l_mbNum++ )
        {
            //  make a local copy of the memory buffer target
            TARGETING::Target*  l_mb_target = l_memBufList[l_mbNum];

            //  dump physical path to target
            EntityPath l_path;
            l_path  =   l_mb_target->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            // cast OUR type of target to a FAPI type of target.
            fapi::Target l_fapi_mb_target(
                                          TARGET_TYPE_MEMBUF_CHIP,
                   (const_cast<TARGETING::Target*>(l_mb_target)) );

            // loop through mvpd records of interest
            const uint32_t numRecords =
                    sizeof(l_mbvpdRecords)/sizeof(l_mbvpdRecords[0]);
            for (uint8_t i=0;i<numRecords;i++) {

                TS_TRACE( "record = 0x%x keyword = 0x%x",
                   l_mbvpdRecords[i].record,
                   l_mbvpdRecords[i].keyword);

                TS_TRACE( "call fapiGetMBvpdField with NULL pointer" );

                //  call fapiGetMvpdField once with a NULL pointer to get the 
                //  buffer size should return no error now.
                l_fapirc = fapiGetMBvpdField(l_mbvpdRecords[i].record,
                                        l_mbvpdRecords[i].keyword,
                                        l_fapi_mb_target,
                                        NULL,
                                        l_len );
                if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
                {
                    TS_FAIL( "fapiGetMBvpdField:  expected FAPI_RC_SUCCESS" );
                    fapiLogError(l_fapirc);
                    return;
                }

                TS_TRACE( "fapiGetMBvpdField: size of record = 0x%x",
                      l_len );

                //  do a malloc instead of a new just for variety
                l_pRecord =   reinterpret_cast<uint8_t *>(malloc(l_len) );

                //  call fapiGetMvpdField once with a valid pointer
                l_fapirc = fapiGetMBvpdField(l_mbvpdRecords[i].record,
                                        l_mbvpdRecords[i].keyword,
                                        l_fapi_mb_target,
                                        l_pRecord,
                                        l_len );
                if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
                {
                    TS_FAIL( "fapiGetMBvpdField:  expected FAPI_RC_SUCCESS" );
                    fapiLogError(l_fapirc);
                    free( l_pRecord );
                    return;
                }
#if UNITTESTfwt
                TRACFCOMP(g_trac_test,"testMBvpd:Record=%d,Keyword=%d",
                                        l_mbvpdRecords[i].record,
                                        l_mbvpdRecords[i].keyword);
                TRACFBIN(g_trac_test,"testMBvpd:DumpRecord:",
                      l_pRecord,
                      l_len );
#endif
                //  call fapiSetMvpdField
                l_fapirc = fapiSetMBvpdField(l_mbvpdRecords[i].record,
                                        l_mbvpdRecords[i].keyword,
                                        l_fapi_mb_target,
                                        l_pRecord,
                                        l_len );
                if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
                {
                    TS_FAIL( "fapiSetMBvpdField:  expected FAPI_RC_SUCCESS" );
                    fapiLogError(l_fapirc);
                    free( l_pRecord );
                    return;
                }

                //  clean up memory
                free( l_pRecord );
            }
        }

        TS_TRACE( "testGetMBvpd exit" );

    }

    /**
     * @brief call getMBvpdSlopeInterceptData to fetch power slope and intercept
     *        attributes from the MW and MV keywords
     *
     */
    void    testGetSlopeInterceptData()
    {
        fapi::ReturnCode    l_fapirc( fapi::FAPI_RC_SUCCESS );
        getMBvpdSlopeInterceptData_FP_t (l_getMBvpdSlopeInterceptData)
                              = &getMBvpdSlopeInterceptData;
        uint32_t l_val = 0xFFFFFFFF;

        TS_TRACE( "testGetSlopeInterceptData entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetSlopeInterceptData l_memBufList.size()=%d",
                                      l_memBufList.size() );
        // loop thru memory buffers
#if UNITTESTfwt
        uint8_t l_mbNum = 0;    // check them all in unit test
#else
        uint8_t l_mbNum = (l_memBufList.size() > 0) ? l_memBufList.size()-1 : 0;
#endif
        for (; l_mbNum < l_memBufList.size(); l_mbNum++ )
        {
            //  make a local copy of the memory buffer target
            TARGETING::Target*  l_mb_target = l_memBufList[l_mbNum];

            //  dump physical path to target
            EntityPath l_path;
            l_path  =   l_mb_target->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            // cast OUR type of target to a FAPI type of target.
            fapi::Target l_fapi_mb_target(
                                          TARGET_TYPE_MEMBUF_CHIP,
                   (const_cast<TARGETING::Target*>(l_mb_target)) );

            // MASTER_POWER_SLOPE
            l_fapirc = (*l_getMBvpdSlopeInterceptData)(l_fapi_mb_target,
                fapi::MASTER_POWER_SLOPE, l_val);
            if (l_fapirc) break;
                TS_TRACE( "testSlopeInterceptData accessor "
                "MASTER_POWER_SLOPE=0x%08x", l_val);
#if UNITTESTfwt

            // MASTER_POWER_INTERCEPT
            l_fapirc = (*l_getMBvpdSlopeInterceptData)(l_fapi_mb_target,
                fapi::MASTER_POWER_INTERCEPT, l_val);
            if (l_fapirc) break;
                TS_TRACE( "testSlopeInterceptData accessor "
                "MASTER_POWER_INTERCEPT=0x%08x", l_val);

            // SUPPLIER_POWER_SLOPE
            l_fapirc = (*l_getMBvpdSlopeInterceptData)(l_fapi_mb_target,
                fapi::SUPPLIER_POWER_SLOPE, l_val);
            if (l_fapirc) break;
                TS_TRACE( "testSlopeInterceptData accessor "
                "SUPPLIER_POWER_SLOPE=0x%08x", l_val);
#endif
            // SUPPLIER_POWER_INTERCEPT
            l_fapirc = (*l_getMBvpdSlopeInterceptData)(l_fapi_mb_target,
                fapi::SUPPLIER_POWER_INTERCEPT, l_val);
            if (l_fapirc) break;
                TS_TRACE( "testSlopeInterceptData accessor "
                "SUPPLIER_POWER_INTERCEPT=0x%08x", l_val);

            // MASTER_POWER_SLOPE
            l_fapirc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_MASTER_POWER_SLOPE,
                &l_fapi_mb_target, l_val);
            if (l_fapirc) break;
            TS_TRACE( "testSlopeInterceptData attr "
                "MASTER_POWER_SLOPE=0x%08x", l_val);
#if UNITTESTfwt
            // MASTER_POWER_INTERCEPT
            l_fapirc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_MASTER_POWER_INTERCEPT,
                &l_fapi_mb_target, l_val);
            if (l_fapirc) break;
            TS_TRACE( "testSlopeInterceptData attr "
                "MASTER_POWER_INTERCEPT=0x%08x", l_val);

            // SUPPLIER_POWER_SLOPE
            l_fapirc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_SUPPLIER_POWER_SLOPE,
                &l_fapi_mb_target, l_val);
            if (l_fapirc) break;
            TS_TRACE( "testSlopeInterceptData attr "
                "SUPPLIER_POWER_SLOPE=0x%08x", l_val);

#endif
            // SUPPLIER_POWER_INTERCEPT
            l_fapirc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_SUPPLIER_POWER_INTERCEPT,
                &l_fapi_mb_target, l_val);
            if (l_fapirc) break;
            TS_TRACE( "testSlopeInterceptData attr "
                "SUPPLIER_POWER_INTERCEPT=0x%08x", l_val);
        }

        if (l_fapirc)
        {
           TS_FAIL( "fapiGetSlopeInterceptData: FAPI_ATTR_GET fail rc=0x%x",
                 static_cast<uint32_t>(l_fapirc) );
           fapiLogError(l_fapirc);
        }

        TS_TRACE( "testGetSlopeInterceptData exit" );

    }

    /**
     * @brief call getMBvpdAddrMirrorData to fetch memory buffer AM attributes
     *
     */
    void    testGetAddrMirrorData()
    {
        fapi::ReturnCode    l_fapirc( fapi::FAPI_RC_SUCCESS );
        getMBvpdAddrMirrorData_FP_t (l_getMBvpdAddrMirrorData)
                              = &getMBvpdAddrMirrorData;

        TS_TRACE( "testGetAddrMirrorData entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetAddrMirrorData l_memBufList.size()=%d",
                                      l_memBufList.size() );
        // loop thru memory buffers
#if UNITTESTfwt
        uint8_t l_mbNum = 0;    // check them all in unit test
#else
        uint8_t l_mbNum = (l_memBufList.size() > 0) ? l_memBufList.size()-1 : 0;
#endif
        for (; l_mbNum < l_memBufList.size(); l_mbNum++ )
        {
            TARGETING::TargetHandleList l_mbaList;
            getChildAffinityTargets(l_mbaList,l_memBufList[l_mbNum],
                            CLASS_UNIT,TYPE_MBA,false);

            TS_TRACE( "testGetAddrMirrorData l_mbaBufList.size()=%d",
                    l_mbaList.size());

            // loop thru all the mbas (should be 2)
#if UNITTESTfwt
            uint8_t l_mbaNum = 0;  // check them all in unit test
#else
            uint8_t l_mbaNum = (l_mbaList.size() > 0) ? l_mbaList.size()-1:0 ;
#endif
            for (; l_mbaNum < l_mbaList.size(); l_mbaNum++ )
            {
                TARGETING::TargetHandleList l_dimmList;

                getChildAffinityTargets(l_dimmList,l_mbaList[l_mbaNum],
                            CLASS_LOGICAL_CARD,TYPE_DIMM,false);
                TS_TRACE( "testGetAddrMirrorData l_dimmList.size()=%d",
                    l_dimmList.size());

                // cast OUR type of target to a FAPI type of target.
                fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                      (const_cast<TARGETING::Target*>(l_mbaList[l_mbaNum])));

                // verify HWP accessor
                uint8_t l_val[2][2] = {{0xFF,0xFF},{0xFF,0xFF}};

                l_fapirc = (*l_getMBvpdAddrMirrorData)(l_fapi_mba_target,l_val);
                if (l_fapirc)
                {
                   TS_FAIL( "fapiGetAddrMirrorData: HWP accessor fail rc=0x%x",
                         static_cast<uint32_t>(l_fapirc) );
                   fapiLogError(l_fapirc);
                }
                else
                {
                    TS_TRACE( "testGetAddrMirrorData accessor "
                           "(0x%02x,0x%02x),(0x%02x,0x%02x)",
                           l_val[0][0], l_val[0][1], l_val[1][0], l_val[1][1]);
                }

                // loop thru all the DIMMs (should be 4)
#if UNITTESTfwt
                uint8_t l_dimmNum = 0;  // check them all in unit test
#else
                uint8_t l_dimmNum =
                             (l_dimmList.size() > 0) ? l_dimmList.size()-1:0 ;
#endif
                for (; l_dimmNum < l_dimmList.size(); l_dimmNum++ )
                {
                    uint8_t l_val = 0xFF;

                    //  dump physical path to target
                    EntityPath l_path;
                    l_path = l_dimmList[l_dimmNum]->getAttr<ATTR_PHYS_PATH>();
                    l_path.dump();

                    // cast OUR type of target to a FAPI type of target.
                    fapi::Target l_fapi_dimm_target(
                                          TARGET_TYPE_DIMM,
                      (const_cast<TARGETING::Target*>(l_dimmList[l_dimmNum])));

                    // verify getting all attributes
                    l_fapirc = FAPI_ATTR_GET(ATTR_VPD_DRAM_ADDRESS_MIRRORING,
                           &l_fapi_dimm_target,
                           l_val);
                    TS_TRACE( "testGetAddrMirrorData attribute %d 0x%02x",
                                   l_dimmNum,l_val);
                }
                if (l_fapirc)
                {
                   TS_FAIL( "fapiGetAddrMirrorData: FAPI_ATTR_GET fail rc=0x%x",
                         static_cast<uint32_t>(l_fapirc) );
                   fapiLogError(l_fapirc);
                }
            }
        }

        TS_TRACE( "testGetAddrMirrorData exit" );

    }

    /**
     * @brief call getMBvpdTermData to fetch memory buffer MT attributes
     *
     */
    void    testGetTermData()
    {
        fapi::ReturnCode    l_fapirc( fapi::FAPI_RC_SUCCESS );
        uint8_t val1[2][2] = {{0xFF,0xFF},{0xFF,0xFF}};
#if UNITTESTfwt
        uint8_t val2[2][2][4]={
                              {{0xFF,0xFF,0xFF,0xFF},{0xFF,0xFF,0xFF,0xFF}},
                              {{0xFF,0xFF,0xFF,0xFF},{0xFF,0xFF,0xFF,0xFF}}};
        uint32_t val3[2] = {0xFFFFFFFF,0xFFFFFFFF};
        uint8_t val4[2] = {0xFF,0xFF};
        uint8_t l_errorChk = 1; //do error checks just once
#endif
#if RTC69935fwt
        getMBvpdTermData_FP_t (l_getMBvpdTermData)
                              = &getMBvpdTermData;
#endif

        TS_TRACE( "testGetTermData entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetTermData l_memBufList.size()=%d",
                                      l_memBufList.size() );

        // loop thru memory buffers
#if UNITTESTfwt
        uint8_t l_mbNum = 0;    // check them all in unit test
#else
        uint8_t l_mbNum = (l_memBufList.size() > 0) ? l_memBufList.size()-1 : 0;
#endif
        for (; l_mbNum < l_memBufList.size(); l_mbNum++ )
        {
            TARGETING::TargetHandleList l_mbaList;
            getChildAffinityTargets(l_mbaList,l_memBufList[l_mbNum],
                            CLASS_UNIT,TYPE_MBA,false);

            TS_TRACE( "testGetTermData l_mbaBufList.size()=%d",
                    l_mbaList.size());

            // loop thru all the mbas (should be 2)
#if UNITTESTfwt
            uint8_t l_mbaNum = 0;  // check them all in unit test
#else
            uint8_t l_mbaNum = (l_mbaList.size() > 0) ? l_mbaList.size()-1:0 ;
#endif
            for (; l_mbaNum < l_mbaList.size(); l_mbaNum++ )
            {
                //  dump physical path to target
                EntityPath l_path;
                l_path  =   l_mbaList[l_mbaNum]->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();

                // cast OUR type of target to a FAPI type of target.
                fapi::Target l_fapi_mba_target(
                                          TARGET_TYPE_MBA_CHIPLET,
                   (const_cast<TARGETING::Target*>(l_mbaList[l_mbaNum])) );

#if UNITTESTfwt
            // check for interface errors being caught. Just once.
            if (l_errorChk) {
               // check size matches type for each of the 4 types
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_DRAM_RON,
                           &val1, sizeof(val1)+1); //invalid size
               if (l_fapirc != fapi::RC_MBVPD_INVALID_OUTPUT_VARIABLE_SIZE)
               {
                  TS_FAIL("testGetTermData: expect invalid size RC:"
                         " 0x%08x,0x%08x",
                         fapi::RC_MBVPD_INVALID_OUTPUT_VARIABLE_SIZE,
                         static_cast<uint32_t>(l_fapirc));
               }
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_DRAM_RTT_NOM,
                           &val2, sizeof(val2)-1); //invalid size
               if (l_fapirc != fapi::RC_MBVPD_INVALID_OUTPUT_VARIABLE_SIZE)
               {
                  TS_FAIL("testGetTermData: expect invalid size RC:"
                         " 0x%08x,0x%08x",
                         fapi::RC_MBVPD_INVALID_OUTPUT_VARIABLE_SIZE,
                         static_cast<uint32_t>(l_fapirc));
               }
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_RD_VREF,
                           &val3, sizeof(val3)+2); //invalid size
               if (l_fapirc != fapi::RC_MBVPD_INVALID_OUTPUT_VARIABLE_SIZE)
               {
                  TS_FAIL("testGetTermData: expect invalid size RC:"
                         " 0x%08x,0x%08x",
                         fapi::RC_MBVPD_INVALID_OUTPUT_VARIABLE_SIZE,
                         static_cast<uint32_t>(l_fapirc));
               }
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_DRAM_WRDDR4_VREF,
                           &val4, 0); //invalid size
               if (l_fapirc != fapi::RC_MBVPD_INVALID_OUTPUT_VARIABLE_SIZE)
               {
                  TS_FAIL("testGetTermData: expect invalid size RC:"
                         " 0x%08x,0x%08x",
                         fapi::RC_MBVPD_INVALID_OUTPUT_VARIABLE_SIZE,
                         static_cast<uint32_t>(l_fapirc));
               }
               // check for catching an invalid ID
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           (fapi::MBvpdTermData)99, //invalid ID
                           &val1, sizeof(val1));
               if (l_fapirc != fapi::RC_MBVPD_INVALID_ATTRIBUTE_ID)
               {
                  TS_FAIL("testGetTermData: expect invalid size RC:"
                         " 0x%08x,0x%08x",
                         fapi::RC_MBVPD_INVALID_ATTRIBUTE_ID,
                         static_cast<uint32_t>(l_fapirc));
               }
               l_errorChk =0;
           }
#endif
#if RTC69935fwt
           // Verify fetching attributes by calling the HWP directly

           // TERM_DATA_DRAM_RON
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_DRAM_RON,
                           &val1, sizeof(val1));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_DRAM_RON=(0x%02x,0x%02x),(0x%02x,0x%02x)",
                   val1[0][0], val1[0][1], val1[1][0], val1[1][1]);

#if UNITTESTfwt
           // TERM_DATA_DRAM_RTT_NOM
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_DRAM_RTT_NOM,
                           &val2, sizeof(val2));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_DRAM_RTT_NOM");
               TS_TRACE("testGetTermData[0][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][0][0], val2[0][0][1], val2[0][0][2], val2[0][0][3]);
               TS_TRACE("testGetTermData[0][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][1][0], val2[0][1][1], val2[0][1][2], val2[0][1][3]);
               TS_TRACE("testGetTermData[1][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][0][0], val2[1][0][1], val2[1][0][2], val2[1][0][3]);
               TS_TRACE("testGetTermData[1][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][1][0], val2[1][1][1], val2[1][1][2], val2[1][1][3]);

           // TERM_DATA_DRAM_RTT_WR
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_DRAM_RTT_WR,
                           &val2, sizeof(val2));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_DRAM_RTT_WR");
               TS_TRACE("testGetTermData[0][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][0][0], val2[0][0][1], val2[0][0][2], val2[0][0][3]);
               TS_TRACE("testGetTermData[0][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][1][0], val2[0][1][1], val2[0][1][2], val2[0][1][3]);
               TS_TRACE("testGetTermData[1][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][0][0], val2[1][0][1], val2[1][0][2], val2[1][0][3]);
               TS_TRACE("testGetTermData[1][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][1][0], val2[1][1][1], val2[1][1][2], val2[1][1][3]);

           // TERM_DATA_ODT_RD
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_ODT_RD,
                           &val2, sizeof(val2));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_ODT_RD");
               TS_TRACE("testGetTermData[0][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][0][0], val2[0][0][1], val2[0][0][2], val2[0][0][3]);
               TS_TRACE("testGetTermData[0][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][1][0], val2[0][1][1], val2[0][1][2], val2[0][1][3]);
               TS_TRACE("testGetTermData[1][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][0][0], val2[1][0][1], val2[1][0][2], val2[1][0][3]);
               TS_TRACE("testGetTermData[1][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][1][0], val2[1][1][1], val2[1][1][2], val2[1][1][3]);

           // TERM_DATA_ODT_WR
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_ODT_WR,
                           &val2, sizeof(val2));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_ODT_WR");
               TS_TRACE("testGetTermData[0][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][0][0], val2[0][0][1], val2[0][0][2], val2[0][0][3]);
               TS_TRACE("testGetTermData[0][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][1][0], val2[0][1][1], val2[0][1][2], val2[0][1][3]);
               TS_TRACE("testGetTermData[1][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][0][0], val2[1][0][1], val2[1][0][2], val2[1][0][3]);
               TS_TRACE("testGetTermData[1][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][1][0], val2[1][1][1], val2[1][1][2], val2[1][1][3]);

           // TERM_DATA_CEN_RD_VREF
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_RD_VREF,
                           &val3, sizeof(val3));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_RD_VREF=0x%08x,0x%08x",
                   val3[0], val3[1]);

           // TERM_DATA_DRAM_WR_VREF
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_DRAM_WR_VREF,
                           &val3, sizeof(val3));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_DRAM_WR_VREF=0x%08x,0x%08x",
                   val3[0], val3[1]);

           // TERM_DATA_DRAM_WRDDR4_VREF
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_DRAM_WRDDR4_VREF,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_DRAM_WRDDR4_VREF=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_RCV_IMP_DQ_DQS
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_RCV_IMP_DQ_DQS,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_RCV_IMP_DQ_DQS=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_DQ_DQS
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_DRV_IMP_DQ_DQS,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_DRV_IMP_DQ_DQS=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_CNTL
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_DRV_IMP_CNTL,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_DRV_IMP_CNTL=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_ADDR
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_DRV_IMP_ADDR,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_DRV_IMP_ADDR=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_CLK
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_DRV_IMP_CLK,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_DRV_IMP_CLK=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_SPCKE
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_DRV_IMP_SPCKE,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_DRV_IMP_SPCKE=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_DQ_DQS
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_SLEW_RATE_DQ_DQS,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_SLEW_RATE_DQ_DQS=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_CNTL
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_SLEW_RATE_CNTL,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_SLEW_RATE_CNTL=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_ADDR
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_SLEW_RATE_ADDR,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_SLEW_RATE_ADDR=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_CLK
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_SLEW_RATE_CLK,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_SLEW_RATE_CLK=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_SPCKE
               l_fapirc = (*l_getMBvpdTermData)(l_fapi_mba_target,
                           fapi::TERM_DATA_CEN_SLEW_RATE_SPCKE,
                           &val4, sizeof(val4));
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData accessor "
                   "TERM_DATA_CEN_SLEW_RATE_SPCKE=0x%02x,0x%02x",
                   val4[0], val4[1]);
#endif
#else
           // Verify fetching attributes using FAPI_ATTR_GET
           // TERM_DATA_DRAM_RON
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RON,
                   &l_fapi_mba_target, val1);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_DRAM_RON=(0x%02x,0x%02x),(0x%02x,0x%02x)",
                   val1[0][0], val1[0][1], val1[1][0], val1[1][1]);

#if UNITTESTfwt
           // TERM_DATA_DRAM_RTT_NOM
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RTT_NOM,
                   &l_fapi_mba_target, val2);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_DRAM_RTT_NOM");
               TS_TRACE("testGetTermData[0][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][0][0], val2[0][0][1], val2[0][0][2], val2[0][0][3]);
               TS_TRACE("testGetTermData[0][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][1][0], val2[0][1][1], val2[0][1][2], val2[0][1][3]);
               TS_TRACE("testGetTermData[1][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][0][0], val2[1][0][1], val2[1][0][2], val2[1][0][3]);
               TS_TRACE("testGetTermData[1][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][1][0], val2[1][1][1], val2[1][1][2], val2[1][1][3]);

           // TERM_DATA_DRAM_RTT_WR
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RTT_WR,
                   &l_fapi_mba_target, val2);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_DRAM_RTT_WR");
               TS_TRACE("testGetTermData[0][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][0][0], val2[0][0][1], val2[0][0][2], val2[0][0][3]);
               TS_TRACE("testGetTermData[0][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][1][0], val2[0][1][1], val2[0][1][2], val2[0][1][3]);
               TS_TRACE("testGetTermData[1][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][0][0], val2[1][0][1], val2[1][0][2], val2[1][0][3]);
               TS_TRACE("testGetTermData[1][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][1][0], val2[1][1][1], val2[1][1][2], val2[1][1][3]);

           // TERM_DATA_ODT_RD
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_ODT_RD,
                   &l_fapi_mba_target, val2);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_ODT_RD");
               TS_TRACE("testGetTermData[0][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][0][0], val2[0][0][1], val2[0][0][2], val2[0][0][3]);
               TS_TRACE("testGetTermData[0][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][1][0], val2[0][1][1], val2[0][1][2], val2[0][1][3]);
               TS_TRACE("testGetTermData[1][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][0][0], val2[1][0][1], val2[1][0][2], val2[1][0][3]);
               TS_TRACE("testGetTermData[1][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][1][0], val2[1][1][1], val2[1][1][2], val2[1][1][3]);

           // TERM_DATA_ODT_WR
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_ODT_WR,
                   &l_fapi_mba_target, val2);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_ODT_WR");
               TS_TRACE("testGetTermData[0][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][0][0], val2[0][0][1], val2[0][0][2], val2[0][0][3]);
               TS_TRACE("testGetTermData[0][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[0][1][0], val2[0][1][1], val2[0][1][2], val2[0][1][3]);
               TS_TRACE("testGetTermData[1][0]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][0][0], val2[1][0][1], val2[1][0][2], val2[1][0][3]);
               TS_TRACE("testGetTermData[1][1]=0x%02x,0x%02x,0x%02x,0x%02x",
                   val2[1][1][0], val2[1][1][1], val2[1][1][2], val2[1][1][3]);

           // TERM_DATA_CEN_RD_VREF
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_RD_VREF,
                   &l_fapi_mba_target, val3);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_RD_VREF=0x%08x,0x%08x",
                   val3[0], val3[1]);

           // TERM_DATA_DRAM_WR_VREF
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WR_VREF,
                   &l_fapi_mba_target, val3);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_DRAM_WR_VREF=0x%08x,0x%08x",
                   val3[0], val3[1]);

           // TERM_DATA_DRAM_WRDDR4_VREF
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WRDDR4_VREF,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_DRAM_WRDDR4_VREF=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_RCV_IMP_DQ_DQS
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_RCV_IMP_DQ_DQS=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_DQ_DQS
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_DRV_IMP_DQ_DQS=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_CNTL
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_CNTL,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_DRV_IMP_CNTL=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_ADDR
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_ADDR,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_DRV_IMP_ADDR=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_CLK
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_CLK,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_DRV_IMP_CLK=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_SPCKE
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_SPCKE,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_DRV_IMP_SPCKE=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_DQ_DQS
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_SLEW_RATE_DQ_DQS=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_CNTL
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_CNTL,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_SLEW_RATE_CNTL=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_ADDR
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_ADDR,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_SLEW_RATE_ADDR=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_CLK
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_CLK,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_SLEW_RATE_CLK=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_SPCKE
               l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_SLEW_RATE_SPCKE,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_SLEW_RATE_SPCKE=0x%02x,0x%02x",
                   val4[0], val4[1]);
#endif
#endif
            }
            if (l_fapirc)
            {
               TS_FAIL( "fapiGetTermData: FAPI_ATTR_GET fail rc=0x%x",
                         static_cast<uint32_t>(l_fapirc) );
               fapiLogError(l_fapirc);
            }
        }


        TS_TRACE( "testGetTermData exit" );

    }


    /**
     * @brief  call fapiGetMBvpdField to fetch memory buffer vpd records.
     *
     */
    void    testGetPhaseRotatorData()
    {
        fapi::ReturnCode    l_fapirc( fapi::FAPI_RC_SUCCESS );
        const uint8_t PORT_SIZE = 2;
        uint8_t l_attr_eff_cen_phase_rot[PORT_SIZE];
#if RTC69935fwt
        getMBvpdPhaseRotatorData_FP_t (l_getMBvpdPhaseRotatorData)
                              = &getMBvpdPhaseRotatorData;
#endif

        TS_TRACE( "testGetPhaseRotatorData entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetPhaseRotatorData l_memBufList.size()=%d",
                                      l_memBufList.size() );

        // loop thru memory buffers
#if UNITTESTfwt
        uint8_t l_mbNum = 0;    // check them all in unit test
#else
        uint8_t l_mbNum = (l_memBufList.size() > 0) ? l_memBufList.size()-1 : 0;
#endif
        for (; l_mbNum < l_memBufList.size(); l_mbNum++ )
        {
            TARGETING::TargetHandleList l_mbaList;
            getChildAffinityTargets(l_mbaList,l_memBufList[l_mbNum],
                            CLASS_UNIT,TYPE_MBA,false);

            TS_TRACE( "testGetPhaseRotatorData l_mbaBufList.size()=%d",
                    l_mbaList.size());

            // loop thru all the mbas (should be 2)
#if UNITTESTfwt
            uint8_t l_mbaNum = 0;  // check them all in unit test
#else
            uint8_t l_mbaNum = (l_mbaList.size() > 0) ? l_mbaList.size()-1:0 ;
#endif
            for (; l_mbaNum < l_mbaList.size(); l_mbaNum++ )
            {
                //  dump physical path to target
                EntityPath l_path;
                l_path  =   l_mbaList[l_mbaNum]->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();

                // cast OUR type of target to a FAPI type of target.
                fapi::Target l_fapi_mba_target(
                                          TARGET_TYPE_MBA_CHIPLET,
                   (const_cast<TARGETING::Target*>(l_mbaList[l_mbaNum])) );

               // verify getting all attributes
#if RTC69935fwt
               // getting all the attributes is a bit of over kill.
               // cen_ddrphy.initfile accesses all the values
               // the exhaustive test is good for unit test
                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CLK_P0,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);
#if UNITTESTfwt
                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CLK_P1,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CLK_P0,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CLK_P1,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A0,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A1,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A2,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A3,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A4,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A4=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A5,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A5=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A6,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A6=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A7,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A7=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A8,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A8=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A9,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A9=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A10,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A10=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A11,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A11=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A12,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A12=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A13,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A13=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A14,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A14=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_A15,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A15=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_BA0,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_BA1,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_BA2,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_CASN,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_CASN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_RASN,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_RASN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_CMD_WEN,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_WEN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_PAR,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_PAR=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M_ACTN,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M_ACTN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CNTL_CKE0,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CNTL_CKE1,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CNTL_CKE2,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CNTL_CKE3,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CNTL_CSN0,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CNTL_CSN1,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CNTL_CSN2,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CNTL_CSN3,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CNTL_ODT0,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M0_CNTL_ODT1,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CNTL_CKE0,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CNTL_CKE1,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CNTL_CKE2,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CNTL_CKE3,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CNTL_CSN0,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CNTL_CSN1,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CNTL_CSN2,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CNTL_CSN3,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CNTL_ODT0,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = (*l_getMBvpdPhaseRotatorData)(l_fapi_mba_target,
                           fapi::PHASE_ROT_M1_CNTL_ODT1,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData accessor"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);
#endif
#else
               // getting all the attributes is a bit of over kill.
               // cen_ddrphy.initfile accesses all the values
               // the exhaustive test is good for unit test
                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);
#if UNITTESTfwt
                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A3,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A4,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A4=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A5,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A5=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A6,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A6=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A7,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A7=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A8,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A8=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A9,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A9=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A10,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A10=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A11,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A11=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A12,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A12=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A13,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A13=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A14,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A14=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A15,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_A15=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_CASN,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_CASN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_RASN,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_RASN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_WEN,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_CMD_WEN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_PAR,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_PAR=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M_ACTN,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M_ACTN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE3,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN3,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE3,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN3,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);
#endif
#endif
            }
            if (l_fapirc)
            {
               TS_FAIL( "fapiGetPhaseRotatorData: FAPI_ATTR_GET fail rc=0x%x",
                         static_cast<uint32_t>(l_fapirc) );
               fapiLogError(l_fapirc);
            }
        }


        TS_TRACE( "testGetPhaseRotatorData exit" );

    }


    // Structure used to save/restore the VPD
    typedef struct saveRestoreData_t {
        TARGETING::Target* target;
        uint8_t* CP00_pdG;
        size_t CP00_pdG_size;
        uint8_t* CP00_pdR;
        size_t CP00_pdR_size;
    } saveRestoreData_t;

    /**
     * @brief Test get and set of Repair Rings
     */
    void testRepairRings()
    {
        fapi::ReturnCode    l_fapirc        =   fapi::FAPI_RC_SUCCESS;
        uint8_t             *l_pRingBuf     =   NULL;
        uint32_t            l_ringBufsize   =   0;
        uint32_t            l_ringId        =   0;
        uint32_t            l_chipletId     =   0;
        uint32_t            l_bufsize       =   0x200;
        errlHndl_t l_errhdl = NULL;

        // This data needs to be in sync with the procmvpd.dat file
        // the setMvpdFunc tests use the last row. The test
        //  expects it to be a mid x20 byte ring in the #G keyword
        struct _testRRstr {
            fapi::MvpdKeyword keyword;
            uint32_t ringIdval;
            uint32_t chipletIdval;
            uint32_t size;
            uint32_t rc;
        }  l_ringModifiers[] = {
            { MVPD_KEYWORD_PDG, 0xa4, 0xFF, 0x20,  //last #G
                                fapi::RC_REPAIR_RING_NOT_FOUND },
            { MVPD_KEYWORD_PDR, 0xe0, 0x08, 0x20, //first #R
                                FAPI_RC_SUCCESS },
            { MVPD_KEYWORD_PDR, 0xe2, 0x16, 0x20, //big #R
                                FAPI_RC_SUCCESS },
            { MVPD_KEYWORD_PDG, 0xa2, 0x08, 0x20, //mid #G
                                FAPI_RC_SUCCESS },
            { MVPD_KEYWORD_PDR, 0xe1, 0x16, 0x20,//big #R
                                FAPI_RC_SUCCESS },
        };
        const size_t VALID_INDEX = 2;
        const size_t TEST_INDEX = 4;

        TS_TRACE( "testRepairRings entry" );

        std::list<saveRestoreData_t> l_srData;

        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        // loop thru all the cpu's
        for (TargetHandleList::iterator l_cpu_iter = l_cpuTargetList.begin();
                l_cpu_iter != l_cpuTargetList.end();
                ++l_cpu_iter)
        {
            //  make a local copy of the CPU target
            TARGETING::Target* l_cpu_target = *l_cpu_iter;

            TS_TRACE( "testRepairRings: "
                "target HUID %.8X",
                TARGETING::get_huid(l_cpu_target));

            //--  Save the entire VPD record to restore later
            saveRestoreData_t tmpsave;
            tmpsave.target = l_cpu_target;

            // do a read with NULL buffer to get the record size
            l_errhdl = deviceRead( l_cpu_target,
                                   NULL,
                                   tmpsave.CP00_pdG_size,
                                   DEVICE_MVPD_ADDRESS( MVPD_RECORD_CP00,
                                                        MVPD_KEYWORD_PDG ) );
            if( l_errhdl )
            {
                TS_FAIL("Error finding size of CP00/#G for %.8X",
                        TARGETING::get_huid(l_cpu_target));
                errlCommit( l_errhdl, VPD_COMP_ID );
                continue;
            }

            // now go get the data
            tmpsave.CP00_pdG = new uint8_t[tmpsave.CP00_pdG_size];
            l_errhdl = deviceRead( l_cpu_target,
                                   tmpsave.CP00_pdG,
                                   tmpsave.CP00_pdG_size,
                                   DEVICE_MVPD_ADDRESS( MVPD_RECORD_CP00,
                                                        MVPD_KEYWORD_PDG ) );
            if( l_errhdl )
            {
                TS_FAIL("Error reading CP00/#G from %.8X",
                        TARGETING::get_huid(l_cpu_target));
                errlCommit( l_errhdl, VPD_COMP_ID );
                delete[] tmpsave.CP00_pdG;
                continue;
            }

            // do a read with NULL buffer to get the record size
            l_errhdl = deviceRead( l_cpu_target,
                                   NULL,
                                   tmpsave.CP00_pdR_size,
                                   DEVICE_MVPD_ADDRESS( MVPD_RECORD_CP00,
                                                        MVPD_KEYWORD_PDR ) );
            if( l_errhdl )
            {
                TS_FAIL("Error finding size of CP00/#R for %.8X",
                        TARGETING::get_huid(l_cpu_target));
                errlCommit( l_errhdl, VPD_COMP_ID );
                continue;
            }

            // now go get the data
            tmpsave.CP00_pdR = new uint8_t[tmpsave.CP00_pdR_size];
            l_errhdl = deviceRead( l_cpu_target,
                                   tmpsave.CP00_pdR,
                                   tmpsave.CP00_pdR_size,
                                   DEVICE_MVPD_ADDRESS( MVPD_RECORD_CP00,
                                                        MVPD_KEYWORD_PDR ) );
            if( l_errhdl )
            {
                TS_FAIL("Error reading CP00/#R from %.8X",
                        TARGETING::get_huid(l_cpu_target));
                errlCommit( l_errhdl, VPD_COMP_ID );
                delete[] tmpsave.CP00_pdR;
                continue;
            }

            // add to the master list
            l_srData.push_back(tmpsave);
            
            // cast OUR type of target to a FAPI type of target.
            fapi::Target l_fapi_cpu_target(
                              TARGET_TYPE_PROC_CHIP,
                              (const_cast<TARGETING::Target*>(l_cpu_target)) );

            //  allocate some space to put the record(s)
            if( l_pRingBuf != NULL )
            {
                delete[] l_pRingBuf;
            }
            l_pRingBuf      =    new uint8_t[l_bufsize];

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
            }

            //  ----------------------------------------------------------------
            //  Pass in a buffer size that is too small with a valid 
            //  ringId/chipletId, should return error with correct length
            //  and invalid size return code..
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: pass buffer too small %d ", 
                    VALID_INDEX );
            l_ringBufsize   =   0x0;
            l_ringId        =   l_ringModifiers[VALID_INDEX].ringIdval;
            l_chipletId     =   l_ringModifiers[VALID_INDEX].chipletIdval;
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
                TS_FAIL("testRepairRings: expect invalid size FAIL: exp=0x%x,"
                         " act=0x%x, ring=0x%X",
                         fapi::RC_REPAIR_RING_INVALID_SIZE,
                         static_cast<uint32_t>(l_fapirc),
                         l_ringId);

                fapiLogError(l_fapirc);
            }
            else if ( l_ringBufsize != l_ringModifiers[VALID_INDEX].size )
            {
                TS_FAIL( "testRepairRings: size mismatch FAIL1 on ring 0x%X:"
                         " exp=0x%x, act=0x%x",
                         l_ringId,
                         l_ringModifiers[VALID_INDEX].size,
                         l_ringBufsize  );
            }

            //  ----------------------------------------------------------------
            //  Pass in a NULL pointer with a valid ringId/chipletId, should 
            //  return with correct length and successful return code.
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: get size of ring %d ", VALID_INDEX );
            l_ringBufsize   =   0x0;
            l_ringId        =   l_ringModifiers[VALID_INDEX].ringIdval;
            l_chipletId     =   l_ringModifiers[VALID_INDEX].chipletIdval;
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
            }
            else if ( l_ringBufsize != l_ringModifiers[VALID_INDEX].size )
            {
                TS_FAIL( "testRepairRings: size mismatch FAIL2 on ring 0x%X:"
                         " exp=0x%x, act=0x%x",
                         l_ringId,
                         l_ringModifiers[VALID_INDEX].size,
                         l_ringBufsize  );
            }

            //  ----------------------------------------------------------------
            //  Fetch rings
            //  ----------------------------------------------------------------
            const uint32_t numRings = 
                        sizeof(l_ringModifiers)/sizeof(l_ringModifiers[0]);
            for (size_t i=0;i<numRings;i++)
            {
                TS_TRACE( "testRepairRings: get ring %d", i );
                l_ringBufsize   =   l_bufsize;
                l_ringId    =   l_ringModifiers[i].ringIdval;
                l_chipletId =   l_ringModifiers[i].chipletIdval;
                l_fapirc    =   getMvpdRing(  MVPD_RECORD_CP00,
                                          l_ringModifiers[i].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );
                TS_TRACE("testRepairRings ringId=0x%x chipletId=0x%x size=0x%x",
                      l_ringId, l_chipletId, l_ringBufsize );

                if ( l_fapirc != l_ringModifiers[i].rc )
                {
                    // note: uint32_t below is an _operator_ of fapi::ReturnCode
                    TS_FAIL( "testRepairRings: getMvpdRing rc FAIL 1: rc=0x%x,"
                             " ring=0x%X, chiplet=0x%X, i=%d",
                             static_cast<uint32_t>(l_fapirc),
                             l_ringId,
                             l_chipletId,
                             i );
                    fapiLogError(l_fapirc);
                    continue;
                }
                else if( l_fapirc != fapi::FAPI_RC_SUCCESS )
                {
                    // not an error, but the next check isn't valid
                    continue;
                }

                if ( l_ringBufsize != l_ringModifiers[i].size )
                {
                    TS_FAIL( "testRepairRings: size mismatch FAIL3 on ring %X:"
                             " exp=0x%x, act=0x%x",
                             l_ringId,
                             l_ringModifiers[i].size,
                             l_ringBufsize  );
                }

                // Dump ring buffer here.
                TRACDBIN(g_trac_test,"testRepairRings:Dump Repair Ring Buffer:",
                      l_pRingBuf,
                      l_ringBufsize );
           }    

            //  ----------------------------------------------------------------
            //  write different data, read it back to verify, then put the
            //     original data back.
            //  ----------------------------------------------------------------
            uint32_t  l_offset =0;       
            uint8_t   l_data = 0;
            uint8_t  *l_pData = NULL;

            // use data from last fetch test case.
            TS_TRACE( "testRepairRings: update in place  ring %d", TEST_INDEX );
            l_ringId    =   l_ringModifiers[TEST_INDEX].ringIdval;
            l_chipletId =   l_ringModifiers[TEST_INDEX].chipletIdval;
            l_ringBufsize = l_ringModifiers[TEST_INDEX].size; 

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
            setMvpdRing_FP_t (l_setMvpdRing) = &setMvpdRing; //verify typedef
            l_fapirc    =   (*l_setMvpdRing)(  MVPD_RECORD_CP00,
                                          l_ringModifiers[TEST_INDEX].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: setMvpdRing rc FAIL 1: exp=0x%x,"
                         " rc=0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );            
                fapiLogError(l_fapirc);
            }

            //  ----------------------------------------------------------------
            //  write back a smaller ring to cause a shift left in the record
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: shrink a  ring %d", TEST_INDEX );
            l_ringBufsize = l_ringModifiers[TEST_INDEX].size-4; 
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
            l_fapirc    =   setMvpdRing(  MVPD_RECORD_CP00,
                                          l_ringModifiers[TEST_INDEX].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: setMvpdRing rc FAIL 2:"
                         " exp=0x%x, rc=0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
            
                fapiLogError(l_fapirc);
            }

            //  ----------------------------------------------------------------
            //  write back a larger  ring to cause a shift right in the record
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: grow a ring %d", TEST_INDEX );
            l_ringBufsize = l_ringModifiers[TEST_INDEX].size+16; 
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
            l_fapirc    =   setMvpdRing(  MVPD_RECORD_CP00,
                                          l_ringModifiers[TEST_INDEX].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: setMvpdRing rc FAIL 3: exp=0x%x,"
                         " rc=0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
            
                fapiLogError(l_fapirc);
            }

            //  ----------------------------------------------------------------
            //  append a ring that is not already there to the end
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: append a ring" );
            l_ringId    =   0x77;
            l_chipletId =   0x88;
            l_ringBufsize = l_ringModifiers[TEST_INDEX].size; 
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
            l_fapirc    =   setMvpdRing(  MVPD_RECORD_CP00,
                                          l_ringModifiers[TEST_INDEX].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL( "testRepairRings: setMvpdRing rc FAIL 4: exp=0x%x,"
                         " rc=0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
            
                fapiLogError(l_fapirc);
            }

            // read back data to prove the writes worked
            l_ringId    =   l_ringModifiers[TEST_INDEX].ringIdval;
            l_chipletId =   l_ringModifiers[TEST_INDEX].chipletIdval;
            l_ringBufsize = l_ringModifiers[TEST_INDEX].size+16; 
            l_fapirc    =   getMvpdRing(  MVPD_RECORD_CP00,
                                          l_ringModifiers[TEST_INDEX].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                TS_FAIL( "testRepairRings: getMvpdRing rc FAIL 2: 0x%x, 0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
                fapiLogError(l_fapirc);
            }
            else
            {
                l_pData = l_pRingBuf+sizeof(CompressedScanData);
                for( l_offset = 0,l_data=0x30;
                     l_offset < l_ringBufsize-sizeof(CompressedScanData);
                     l_offset++) 
                {
                    if( l_pData[l_offset] != l_data++ )
                    {
                        TS_FAIL("Mismatch after write on ring %X",
                                l_ringId);
                        TRACFBIN(g_trac_test,
                                 "ringdata=",
                                 l_pRingBuf,l_ringBufsize);
                    }
                }
            }

            // read back data to prove the writes worked
            l_ringId    =   0x77;
            l_chipletId =   0x88;
            l_ringBufsize = l_ringModifiers[TEST_INDEX].size; 
            l_fapirc    =   getMvpdRing(  MVPD_RECORD_CP00,
                                          l_ringModifiers[TEST_INDEX].keyword,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::FAPI_RC_SUCCESS )
            {
                TS_FAIL( "testRepairRings: getMvpdRing rc FAIL 3: 0x%x, 0x%x",
                         fapi::FAPI_RC_SUCCESS,
                         static_cast<uint32_t>(l_fapirc) );
                fapiLogError(l_fapirc);
            }
            else
            {
                l_pData = l_pRingBuf+sizeof(CompressedScanData);
                for (l_offset = 0,l_data=0x50;
                     l_offset < l_ringBufsize-sizeof(CompressedScanData);
                     l_offset++) 
                {
                    if( l_pData[l_offset] != l_data++ )
                    {
                        TS_FAIL("Mismatch after write on ring %X",
                                l_ringId);
                        TRACFBIN(g_trac_test,
                                 "ringdata=",
                                 l_pRingBuf,l_ringBufsize);
                    }
                }
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
            l_ringId        =   l_ringModifiers[TEST_INDEX].ringIdval;
            l_chipletId     =   l_ringModifiers[TEST_INDEX].chipletIdval;
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
                TS_FAIL("testRepairRings:invalid ring size rc FAIL:"
                         " exp=0x%x, act=0x%x",
                         fapi::RC_REPAIR_RING_INVALID_SIZE,
                         static_cast<uint32_t>(l_fapirc));

                fapiLogError(l_fapirc);
            }

            //  ----------------------------------------------------------------
            //  Pass in 0 for the ring modifier, should return with "not found"
            //  error
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: pass in invalid ringId" );
            l_ringBufsize   =   l_ringModifiers[TEST_INDEX].size;
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
                TS_FAIL( "testRepairRings:  rc FAIL: exp=0x%x, act=0x%x",
                         fapi::RC_REPAIR_RING_NOT_FOUND,
                         static_cast<uint32_t>(l_fapirc) );
                fapiLogError(l_fapirc);
            }
            //  ----------------------------------------------------------------
            //  Pass in a NULL pointer with a valid ringId/chipletId, should 
            //  return with correct length and successful return code.
            //  ----------------------------------------------------------------
            TS_TRACE( "testRepairRings: get size of ring(from set) %d ",
                     TEST_INDEX );
            l_ringBufsize   =   0x0;
            l_ringId        =   l_ringModifiers[TEST_INDEX].ringIdval;
            l_chipletId     =   l_ringModifiers[TEST_INDEX].chipletIdval;
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
                TS_FAIL( "testRepairRings: setMvpdRing rc FAIL 5:"
                         " exp=0x%x, act=0x%x",
                         fapi::RC_MVPD_RING_FUNC_INVALID_PARAMETER,
                         static_cast<uint32_t>(l_fapirc));

                fapiLogError(l_fapirc);
            }

            //  ----------------------------------------------------------------
            //  Pass in an invalid chiplet id with a valid ring, should fail
            //  ----------------------------------------------------------------
            l_ringBufsize   =   l_bufsize;
            l_ringId        =   l_ringModifiers[TEST_INDEX].ringIdval;
            l_chipletId     =   0x22;
            TS_TRACE("testRepairRing:invalid chiplet ring=0x%X chiplet=0x%X"
                      " size=0x%x",
                      l_ringId,
                      l_chipletId,
                      l_ringBufsize );
            l_fapirc    =   getMvpdRing(  MVPD_RECORD_CP00,
                                          MVPD_KEYWORD_PDR,
                                          l_fapi_cpu_target,
                                          l_chipletId,
                                          l_ringId,
                                          l_pRingBuf,
                                          l_ringBufsize );

            if ( l_fapirc != fapi::RC_REPAIR_RING_NOT_FOUND )
            {
                //  note:  "uint32_t" below is an _operator_ of fapi::ReturnCode
                TS_FAIL("testRepairRings:invalid chipletid rc FAIL:"
                         " exp=0x%x, act=0x%x",
                         fapi::RC_REPAIR_RING_NOT_FOUND,
                         static_cast<uint32_t>(l_fapirc));

                fapiLogError(l_fapirc);
            }

        }

        //-- Put the original data back into the vpd
        for( std::list<saveRestoreData_t>::iterator sv = l_srData.begin();
             sv != l_srData.end();
             ++sv )
        {
            if( sv->target == NULL )
            {
                continue;
            }

            if( sv->CP00_pdG != NULL )
            {
                l_errhdl = deviceWrite( sv->target,
                                        sv->CP00_pdG,
                                        sv->CP00_pdG_size,
                                        DEVICE_MVPD_ADDRESS( MVPD_RECORD_CP00,
                                                          MVPD_KEYWORD_PDG ) );
                if( l_errhdl )
                {
                    TS_FAIL("Error restoring CP00/#G to %.8X",
                            TARGETING::get_huid(sv->target));
                    errlCommit( l_errhdl, VPD_COMP_ID );                    
                }
                delete[] sv->CP00_pdG;
                sv->CP00_pdG = NULL;
            }

            if( sv->CP00_pdR != NULL )
            {
                l_errhdl = deviceWrite( sv->target,
                                        sv->CP00_pdR,
                                        sv->CP00_pdR_size,
                                        DEVICE_MVPD_ADDRESS( MVPD_RECORD_CP00,
                                                          MVPD_KEYWORD_PDR ) );
                if( l_errhdl )
                {
                    TS_FAIL("Error restoring CP00/#R to %.8X",
                            TARGETING::get_huid(sv->target));
                    errlCommit( l_errhdl, VPD_COMP_ID );
                }
                delete[] sv->CP00_pdR;
                sv->CP00_pdR = NULL;
            }
        }
        //--

        //  delete allocated space
        if( l_pRingBuf )
        {
            delete[]    l_pRingBuf;
        }
        for( std::list<saveRestoreData_t>::iterator sv = l_srData.begin();
             sv != l_srData.end();
             ++sv )
        {
            if( sv->CP00_pdG != NULL )
            {
                delete[] sv->CP00_pdG;
                sv->CP00_pdG = NULL;
            }
            if( sv->CP00_pdR != NULL )
            {
                delete[] sv->CP00_pdR;
                sv->CP00_pdR = NULL;
            }
        }


        TS_TRACE( "testRepairRings exit" );
    }

};  // end class FapiWinkleTest

#endif
